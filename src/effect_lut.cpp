#include "effect_lut.hpp"

#include <cstring>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"
#include "image.hpp"

#include "stb_image.h"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    LutEffect::LutEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, VkQueue queue, VkCommandPool commandPool)
    {
        std::string fullScreenRectFile = "full_screen_triangle.vert.spv";
        std::string lutFragmentFile = "lut.frag.spv";

        vertexCode = readFile(fullScreenRectFile);
        fragmentCode = readFile(lutFragmentFile);
        
        int channels, width, height;
        stbi_uc* pixels = stbi_load(pConfig->getOption("lutFile").c_str(), &width, &height, &channels, STBI_rgb_alpha);
        if(width != height * height)
        {
            throw std::runtime_error("bad lut");
        }
        
        int32_t size = width;

        VkSpecializationMapEntry specMapEntry;
        specMapEntry.constantID = 0;
        specMapEntry.offset = 0;
        specMapEntry.size = sizeof(int32_t);

        VkSpecializationInfo fragmentSpecializationInfo;
        fragmentSpecializationInfo.mapEntryCount = 1;
        fragmentSpecializationInfo.pMapEntries = &specMapEntry;
        fragmentSpecializationInfo.dataSize = sizeof(int32_t);
        fragmentSpecializationInfo.pData = &size;

        pVertexSpecInfo = nullptr;
        pFragmentSpecInfo = &fragmentSpecializationInfo;
        
        VkExtent3D lutImageExtent = {(uint32_t) height, (uint32_t) height, (uint32_t) height};
        lutImage = createImages(instanceDispatchTable,
                                 device,
                                 dispatchTable,
                                 physicalDevice,
                                 1,
                                 lutImageExtent,
                                 VK_FORMAT_R8G8B8A8_UNORM,//TODO search for format and save it
                                 VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                 VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                 lutMemory)[0];
        
        uploadToImage(instanceDispatchTable,
                       device,
                       dispatchTable,
                       physicalDevice,
                       lutImage,
                       lutImageExtent,
                       32*32*32*4,
                       queue,
                       commandPool,
                       pixels);
                       
        lutImageView = createImageViews(device, dispatchTable, VK_FORMAT_R8G8B8A8_UNORM, std::vector<VkImage>(1,lutImage), VK_IMAGE_VIEW_TYPE_3D)[0];
        
        lutDescriptorSetLayout = createImageSamplerDescriptorSetLayout(device, dispatchTable, 1);
        descriptorSetLayouts.push_back(lutDescriptorSetLayout);
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = 1;

        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};
        
        lutDescriptorPool = createDescriptorPool(device, dispatchTable, poolSizes);

        init(physicalDevice, instanceDispatchTable, device, dispatchTable, format,  imageExtent, inputImages, outputImages, pConfig);
        
        lutDescriptorSet = allocateAndWriteImageSamplerDescriptorSets(device,
                                                                         dispatchTable,
                                                                         lutDescriptorPool,
                                                                         lutDescriptorSetLayout,
                                                                         sampler,
                                                                         std::vector<std::vector<VkImageView>>(1,std::vector<VkImageView>(1,lutImageView)))[0];
    }
    LutEffect::~LutEffect()
    {
        dispatchTable.DestroyImageView(device,lutImageView,nullptr);
        dispatchTable.DestroyImage(device,lutImage,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,lutDescriptorSetLayout,nullptr);
        dispatchTable.DestroyDescriptorPool(device,lutDescriptorPool,nullptr);
        dispatchTable.FreeMemory(device,lutMemory,nullptr);
        
    }
    void LutEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&(lutDescriptorSet),0,nullptr);
        SimpleEffect::applyEffect(imageIndex, commandBuffer);
    }
}
