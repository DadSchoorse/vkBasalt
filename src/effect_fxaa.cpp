#include "effect_fxaa.hpp"

#include <cstring>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{   
    typedef struct {
        float fxaaQualitySubpix;
        float fxaaQualityEdgeThreshold;
        float fxaaQualityEdgeThresholdMin; 
    } FxaaBufferObject;
    
    std::string fullScreenRectFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/full_screen_rect.vert.spv";
    std::string casFragmentFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/cas.frag.spv";
    std::string fxaaFragmentFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/fxaa.frag.spv";
    
    FxaaEffect::FxaaEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, Config config)
    {
        this->physicalDevice = physicalDevice;
        this->instanceDispatchTable = instanceDispatchTable;
        this->device = device;
        this->dispatchTable = dispatchTable;
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->config = config;
        
        inputImageViews = createImageViews(device, dispatchTable, format, inputImages);
        outputImageViews = createImageViews(device, dispatchTable, format, outputImages);
        sampler = createSampler(device, dispatchTable);
        
        uniformBufferDescriptorSetLayout = createUniformBufferDescriptorSetLayout(device, dispatchTable);
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(device, dispatchTable);
        
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size();
        
        VkDescriptorPoolSize bufferPoolSize;
        bufferPoolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        bufferPoolSize.descriptorCount = 1;
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize,bufferPoolSize};
        
        descriptorPool = createDescriptorPool(device, dispatchTable, poolSizes);
        
        VkDeviceSize bufferSize = sizeof(FxaaBufferObject);
        //TODO make buffer device local
        VkMemoryPropertyFlags memoryFlags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
        createBuffer(instanceDispatchTable,device,dispatchTable,physicalDevice,bufferSize,VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, memoryFlags, uniformBuffer,uniformBufferMemory);
        uniformBufferDescriptorSet = writeCasBufferDescriptorSet(device, dispatchTable, descriptorPool, uniformBufferDescriptorSetLayout, uniformBuffer);
        
        
        //get config options
        FxaaBufferObject fbo;
        if(config.getOption("fxaaQualitySubpix")!=std::string(""))
        {
            fbo.fxaaQualitySubpix = std::stod(config.getOption("fxaaQualitySubpix"));
        }
        else
        {
            fbo.fxaaQualitySubpix = 0.75f;
        }
        if(config.getOption("fxaaQualityEdgeThreshold")!=std::string(""))
        {
            fbo.fxaaQualityEdgeThreshold = std::stod(config.getOption("fxaaQualityEdgeThreshold"));
        }
        else
        {
            fbo.fxaaQualityEdgeThreshold = 0.125f;
        }
        if(config.getOption("fxaaQualityEdgeThresholdMin")!=std::string(""))
        {
            fbo.fxaaQualityEdgeThresholdMin = std::stod(config.getOption("fxaaQualityEdgeThresholdMin"));
        }
        else
        {
            fbo.fxaaQualityEdgeThresholdMin = 0.0312f;
        }
        
        
        void* data;
        VkResult result = dispatchTable.MapMemory(device, uniformBufferMemory, 0, sizeof(FxaaBufferObject), 0, &data);
        ASSERT_VULKAN(result);
        std::memcpy(data, &fbo, sizeof(FxaaBufferObject));
        dispatchTable.UnmapMemory(device, uniformBufferMemory);
        
        auto vertexCode = readFile(fullScreenRectFile.c_str());
        createShaderModule(device, dispatchTable, vertexCode, &vertexModule);
    
        auto fragmentCode = readFile(fxaaFragmentFile.c_str());
        createShaderModule(device, dispatchTable, fragmentCode, &fragmentModule);
        
        renderPass = createRenderPass(device, dispatchTable, format);
        
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts = {imageSamplerDescriptorSetLayout,uniformBufferDescriptorSetLayout};
        pipelineLayout = createGraphicsPipelineLayout(device, dispatchTable, descriptorSetLayouts);
        graphicsPipeline = createGraphicsPipeline(device, dispatchTable, vertexModule, fragmentModule, imageExtent, renderPass, pipelineLayout);
        
        uniformBufferDescriptorSet = writeCasBufferDescriptorSet(device, dispatchTable, descriptorPool, uniformBufferDescriptorSetLayout, uniformBuffer);
        
        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(device, dispatchTable, descriptorPool, imageSamplerDescriptorSetLayout, sampler, inputImageViews);
        
        framebuffers = createFramebuffers(device, dispatchTable, renderPass, imageExtent, outputImageViews);
    }
    void FxaaEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        //Used to make the Image accessable by the shader
        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext = nullptr;
        memoryBarrier.srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
        memoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.image = inputImages[imageIndex];
        memoryBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        memoryBarrier.subresourceRange.baseMipLevel = 0;
        memoryBarrier.subresourceRange.levelCount = 1;
        memoryBarrier.subresourceRange.baseArrayLayer = 0;
        memoryBarrier.subresourceRange.layerCount = 1;
        
        //Reverses the first Barrier
        VkImageMemoryBarrier secondBarrier;
        secondBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        secondBarrier.pNext = nullptr;
        secondBarrier.srcAccessMask =  VK_ACCESS_SHADER_READ_BIT;
        secondBarrier.dstAccessMask =  0;
        secondBarrier.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        secondBarrier.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        secondBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.image = inputImages[imageIndex];
        secondBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        secondBarrier.subresourceRange.baseMipLevel = 0;
        secondBarrier.subresourceRange.levelCount = 1;
        secondBarrier.subresourceRange.baseArrayLayer = 0;
        secondBarrier.subresourceRange.layerCount = 1;
        
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);

        VkRenderPassBeginInfo renderPassBeginInfo;
        renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassBeginInfo.pNext = nullptr;
        renderPassBeginInfo.renderPass = renderPass;
        renderPassBeginInfo.framebuffer = framebuffers[imageIndex];
        renderPassBeginInfo.renderArea.offset = {0,0};
        renderPassBeginInfo.renderArea.extent = imageExtent;
        VkClearValue clearValue = {0.0f, 0.0f, 0.0f, 1.0f};
        renderPassBeginInfo.clearValueCount = 1;
        renderPassBeginInfo.pClearValues = &clearValue;

        dispatchTable.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&uniformBufferDescriptorSet,0,nullptr);
        
        dispatchTable.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipeline);

        dispatchTable.CmdDraw(commandBuffer, 6, 1, 0, 0);

        dispatchTable.CmdEndRenderPass(commandBuffer);
        
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);

    }
}
