#include "effect_simple.hpp"

#include <cstring>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"

namespace vkBasalt
{
    SimpleEffect::SimpleEffect()
    {
    
    }
    void SimpleEffect::init(LogicalDevice logicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::cout << "in creating SimpleEffect " << std::endl;
        
        this->logicalDevice = logicalDevice;
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        
        inputImageViews = createImageViews(logicalDevice.device, logicalDevice.vkd, format, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        outputImageViews = createImageViews(logicalDevice.device, logicalDevice.vkd, format, outputImages);
        std::cout << "after creating ImageViews" << std::endl;
        sampler = createSampler(logicalDevice.device, logicalDevice.vkd);
        std::cout << "after creating sampler" << std::endl;
        
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(logicalDevice, 1);
        std::cout << "after creating descriptorSetLayouts" << std::endl;
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size()+10;
        
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};
        
        descriptorPool = createDescriptorPool(logicalDevice, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;
        
        createShaderModule(logicalDevice.device, logicalDevice.vkd, vertexCode, &vertexModule);
        createShaderModule(logicalDevice.device, logicalDevice.vkd, fragmentCode, &fragmentModule);
        
        renderPass = createRenderPass(logicalDevice.device, logicalDevice.vkd, format);
        
        descriptorSetLayouts.insert(descriptorSetLayouts.begin(),imageSamplerDescriptorSetLayout);
        pipelineLayout = createGraphicsPipelineLayout(logicalDevice.device, logicalDevice.vkd, descriptorSetLayouts);
        
        graphicsPipeline = createGraphicsPipeline(logicalDevice.device, logicalDevice.vkd, vertexModule, pVertexSpecInfo, "main", fragmentModule, pFragmentSpecInfo, "main", imageExtent, renderPass, pipelineLayout);
        
        
        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(logicalDevice,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         {sampler},
                                                                         std::vector<std::vector<VkImageView>>(1,inputImageViews));
        
        framebuffers = createFramebuffers(logicalDevice, renderPass, imageExtent, {outputImageViews});
    }
    void SimpleEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        std::cout << "applying SimpleEffect" << commandBuffer << std::endl;
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
        
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
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
        logicalDevice.vkd.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;
        
        logicalDevice.vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        std::cout << "after binding image sampler" << std::endl;
        
        logicalDevice.vkd.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipeline);
        std::cout << "after bind pipeliene" << std::endl;
        
        logicalDevice.vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        logicalDevice.vkd.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;
        
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    SimpleEffect::~SimpleEffect()
    {
        std::cout << "destroying SimpleEffect" << this << std::endl;
        logicalDevice.vkd.DestroyPipeline(logicalDevice.device, graphicsPipeline, nullptr);
        logicalDevice.vkd.DestroyPipelineLayout(logicalDevice.device,pipelineLayout,nullptr);
        logicalDevice.vkd.DestroyRenderPass(logicalDevice.device,renderPass,nullptr);
        logicalDevice.vkd.DestroyDescriptorSetLayout(logicalDevice.device,imageSamplerDescriptorSetLayout,nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device,vertexModule,nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device,fragmentModule,nullptr);
        
        logicalDevice.vkd.DestroyDescriptorPool(logicalDevice.device,descriptorPool,nullptr);
        for(unsigned int i=0;i<framebuffers.size();i++)
        {
            logicalDevice.vkd.DestroyFramebuffer(logicalDevice.device,framebuffers[i],nullptr);
            logicalDevice.vkd.DestroyImageView(logicalDevice.device,inputImageViews[i],nullptr);
            logicalDevice.vkd.DestroyImageView(logicalDevice.device,outputImageViews[i],nullptr);
        }
        std::cout << "after DestroyImageView" << std::endl;
        logicalDevice.vkd.DestroySampler(logicalDevice.device,sampler,nullptr);
    }
}
