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
    
    
    
    FxaaEffect::FxaaEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::string fullScreenRectFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/full_screen_triangle.vert.spv";
        std::string fxaaFragmentFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/fxaa.frag.spv";
        std::cout << "in creating FxaaEffect " << std::endl;
        
        this->physicalDevice = physicalDevice;
        this->instanceDispatchTable = instanceDispatchTable;
        this->device = device;
        this->dispatchTable = dispatchTable;
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        
        inputImageViews = createImageViews(device, dispatchTable, format, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        outputImageViews = createImageViews(device, dispatchTable, format, outputImages);
        std::cout << "after creating ImageViews" << std::endl;
        sampler = createSampler(device, dispatchTable);
        std::cout << "after creating sampler" << std::endl;
        
        uniformBufferDescriptorSetLayout = createUniformBufferDescriptorSetLayout(device, dispatchTable);
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(device, dispatchTable, 1);
        std::cout << "after creating descriptorSetLayouts" << std::endl;
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size()+10;
        
        VkDescriptorPoolSize bufferPoolSize;
        bufferPoolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        bufferPoolSize.descriptorCount = 10;
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize,bufferPoolSize};
        
        descriptorPool = createDescriptorPool(device, dispatchTable, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;
        
        VkDeviceSize bufferSize = sizeof(FxaaBufferObject);
        //TODO make buffer device local
        VkMemoryPropertyFlags memoryFlags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
        createBuffer(instanceDispatchTable,device,dispatchTable,physicalDevice,bufferSize,VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, memoryFlags, uniformBuffer,uniformBufferMemory);
        std::cout << "after creating Fxaa buffer" << std::endl;
        uniformBufferDescriptorSet = writeCasBufferDescriptorSet(device, dispatchTable, descriptorPool, uniformBufferDescriptorSetLayout, uniformBuffer);
        
        
        //get config options
        FxaaBufferObject fbo;
        if(pConfig->getOption("fxaaQualitySubpix")!=std::string(""))
        {
            fbo.fxaaQualitySubpix = std::stod(pConfig->getOption("fxaaQualitySubpix"));
        }
        else
        {
            fbo.fxaaQualitySubpix = 0.75f;
        }
        if(pConfig->getOption("fxaaQualityEdgeThreshold")!=std::string(""))
        {
            fbo.fxaaQualityEdgeThreshold = std::stod(pConfig->getOption("fxaaQualityEdgeThreshold"));
        }
        else
        {
            fbo.fxaaQualityEdgeThreshold = 0.125f;
        }
        if(pConfig->getOption("fxaaQualityEdgeThresholdMin")!=std::string(""))
        {
            fbo.fxaaQualityEdgeThresholdMin = std::stod(pConfig->getOption("fxaaQualityEdgeThresholdMin"));
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
        std::cout << "applying fxaa effect" << commandBuffer << std::endl;
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
        std::cout << "after the first pipeline barrier" << std::endl;
        
        std::cout << "framebuffer " << framebuffers.size() << std::endl;
        
        std::cout << "framebuffer " << framebuffers[imageIndex] << std::endl;

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
        
        std::cout << "before beginn renderpass" << std::endl;
        dispatchTable.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;
        
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        std::cout << "after binding image sampler" << std::endl;
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&uniformBufferDescriptorSet,0,nullptr);
        std::cout << "after binding uniform buffer" << std::endl;
        
        dispatchTable.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipeline);
        std::cout << "after bind pipeliene" << std::endl;
        
        dispatchTable.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        dispatchTable.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;
        
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    FxaaEffect::~FxaaEffect()
    {
        std::cout << "destroying fxaa effect " << this << std::endl;
        dispatchTable.DestroyPipeline(device, graphicsPipeline, nullptr);
        dispatchTable.DestroyPipelineLayout(device,pipelineLayout,nullptr);
        dispatchTable.DestroyRenderPass(device,renderPass,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,imageSamplerDescriptorSetLayout,nullptr);
        dispatchTable.DestroyShaderModule(device,vertexModule,nullptr);
        dispatchTable.DestroyShaderModule(device,fragmentModule,nullptr);
        
        dispatchTable.DestroyDescriptorPool(device,descriptorPool,nullptr);
        dispatchTable.FreeMemory(device,uniformBufferMemory,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,uniformBufferDescriptorSetLayout,nullptr);
        dispatchTable.DestroyBuffer(device,uniformBuffer,nullptr);
        for(unsigned int i=0;i<framebuffers.size();i++)
        {
            dispatchTable.DestroyFramebuffer(device,framebuffers[i],nullptr);
            dispatchTable.DestroyImageView(device,inputImageViews[i],nullptr);
            dispatchTable.DestroyImageView(device,outputImageViews[i],nullptr);
            std::cout << "after DestroyImageView" << std::endl;
        }
        dispatchTable.DestroySampler(device,sampler,nullptr);
    }
}
