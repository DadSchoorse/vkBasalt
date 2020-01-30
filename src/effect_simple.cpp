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
    void SimpleEffect::init(std::shared_ptr<LogicalDevice> pLogicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::cout << "in creating SimpleEffect " << std::endl;
        
        this->pLogicalDevice = pLogicalDevice;
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        
        inputImageViews = createImageViews(pLogicalDevice, format, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        outputImageViews = createImageViews(pLogicalDevice, format, outputImages);
        std::cout << "after creating ImageViews" << std::endl;
        sampler = createSampler(pLogicalDevice);
        std::cout << "after creating sampler" << std::endl;
        
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(pLogicalDevice, 1);
        std::cout << "after creating descriptorSetLayouts" << std::endl;
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size()+10;
        
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};
        
        descriptorPool = createDescriptorPool(pLogicalDevice, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;
        
        createShaderModule(pLogicalDevice, vertexCode, &vertexModule);
        createShaderModule(pLogicalDevice, fragmentCode, &fragmentModule);
        
        renderPass = createRenderPass(pLogicalDevice, format);
        
        descriptorSetLayouts.insert(descriptorSetLayouts.begin(),imageSamplerDescriptorSetLayout);
        pipelineLayout = createGraphicsPipelineLayout(pLogicalDevice, descriptorSetLayouts);
        
        graphicsPipeline = createGraphicsPipeline(pLogicalDevice, vertexModule, pVertexSpecInfo, "main", fragmentModule, pFragmentSpecInfo, "main", imageExtent, renderPass, pipelineLayout);
        
        
        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(pLogicalDevice,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         {sampler},
                                                                         std::vector<std::vector<VkImageView>>(1,inputImageViews));
        
        framebuffers = createFramebuffers(pLogicalDevice, renderPass, imageExtent, {outputImageViews});
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
        
        pLogicalDevice->vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
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
        pLogicalDevice->vkd.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;
        
        pLogicalDevice->vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        std::cout << "after binding image sampler" << std::endl;
        
        pLogicalDevice->vkd.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipeline);
        std::cout << "after bind pipeliene" << std::endl;
        
        pLogicalDevice->vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        pLogicalDevice->vkd.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;
        
        pLogicalDevice->vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    SimpleEffect::~SimpleEffect()
    {
        std::cout << "destroying SimpleEffect" << this << std::endl;
        pLogicalDevice->vkd.DestroyPipeline(pLogicalDevice->device, graphicsPipeline, nullptr);
        pLogicalDevice->vkd.DestroyPipelineLayout(pLogicalDevice->device,pipelineLayout,nullptr);
        pLogicalDevice->vkd.DestroyRenderPass(pLogicalDevice->device,renderPass,nullptr);
        pLogicalDevice->vkd.DestroyDescriptorSetLayout(pLogicalDevice->device,imageSamplerDescriptorSetLayout,nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device,vertexModule,nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device,fragmentModule,nullptr);
        
        pLogicalDevice->vkd.DestroyDescriptorPool(pLogicalDevice->device,descriptorPool,nullptr);
        for(unsigned int i=0;i<framebuffers.size();i++)
        {
            pLogicalDevice->vkd.DestroyFramebuffer(pLogicalDevice->device,framebuffers[i],nullptr);
            pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device,inputImageViews[i],nullptr);
            pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device,outputImageViews[i],nullptr);
        }
        std::cout << "after DestroyImageView" << std::endl;
        pLogicalDevice->vkd.DestroySampler(pLogicalDevice->device,sampler,nullptr);
    }
}
