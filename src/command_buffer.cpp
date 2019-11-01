#include "command_buffer.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    void allocateCommandBuffer(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkCommandPool& commandPool, const uint32_t& count, VkCommandBuffer* commandBuffers)
    {
        VkCommandBufferAllocateInfo allocInfo;
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.pNext = nullptr;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = commandPool;
        allocInfo.commandBufferCount = count;
        
        for(unsigned int i=0;i<count;i++)
        {
            std::cout << commandBuffers[i] << std::endl;
        }
        VkResult result = dispatchTable.AllocateCommandBuffers(device,&allocInfo,commandBuffers);
        ASSERT_VULKAN(result);
        for(unsigned int i=0;i<count;i++)
        {
            //initialize dispatch tables for commandBuffers since the are dispatchable objects
            *reinterpret_cast<void**>(commandBuffers[i]) = *reinterpret_cast<void**>(device);
            std::cout << commandBuffers[i] << std::endl;
        }
    
    }
    void writeCASCommandBuffers(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkPipeline& pipeline, const VkPipelineLayout& layout, const VkExtent2D& extent, const uint32_t& count,const VkDescriptorSet& uniformBufferDescriptorSet, const VkRenderPass& renderPass, const VkImage* images, const VkDescriptorSet* descriptorSets, const VkFramebuffer* framebuffers, VkCommandBuffer* commandBuffers)
    {
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.pNext = nullptr;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
        beginInfo.pInheritanceInfo = nullptr;
        
        
        
        //Used to make the Image accessable by the cas shader
        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext = nullptr;
        memoryBarrier.srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
        memoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.image = VK_NULL_HANDLE;
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
        secondBarrier.image = VK_NULL_HANDLE;
        secondBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        secondBarrier.subresourceRange.baseMipLevel = 0;
        secondBarrier.subresourceRange.levelCount = 1;
        secondBarrier.subresourceRange.baseArrayLayer = 0;
        secondBarrier.subresourceRange.layerCount = 1;
        
        for(unsigned int i=0;i<count;i++)
        {
            std::cout << commandBuffers[i] << std::endl;
        }
        
        for(unsigned int i=0;i<count;i++)
        {
            memoryBarrier.image = images[i];
            secondBarrier.image = images[i];
            VkResult result = dispatchTable.BeginCommandBuffer(commandBuffers[i],&beginInfo);
            ASSERT_VULKAN(result);
            
            dispatchTable.CmdPipelineBarrier(commandBuffers[i],VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);

            VkRenderPassBeginInfo renderPassBeginInfo;
            renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassBeginInfo.pNext = nullptr;
            renderPassBeginInfo.renderPass = renderPass;
            renderPassBeginInfo.framebuffer = framebuffers[i];
            renderPassBeginInfo.renderArea.offset = {0,0};
            renderPassBeginInfo.renderArea.extent = extent;
            VkClearValue clearValue = {0.0f, 0.0f, 0.0f, 1.0f};
            renderPassBeginInfo.clearValueCount = 1;
            renderPassBeginInfo.pClearValues = &clearValue;

            dispatchTable.CmdBeginRenderPass(commandBuffers[i],&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
            
            dispatchTable.CmdBindDescriptorSets(commandBuffers[i],VK_PIPELINE_BIND_POINT_GRAPHICS,layout,0,1,&(descriptorSets[i]),0,nullptr);
            dispatchTable.CmdBindDescriptorSets(commandBuffers[i],VK_PIPELINE_BIND_POINT_GRAPHICS,layout,1,1,&uniformBufferDescriptorSet,0,nullptr);
            
            dispatchTable.CmdBindPipeline(commandBuffers[i],VK_PIPELINE_BIND_POINT_GRAPHICS,pipeline);

            dispatchTable.CmdDraw(commandBuffers[i], 6, 1, 0, 0);

            dispatchTable.CmdEndRenderPass(commandBuffers[i]);
            
            dispatchTable.CmdPipelineBarrier(commandBuffers[i],VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);

            result = dispatchTable.EndCommandBuffer(commandBuffers[i]);
            ASSERT_VULKAN(result);
        }
    }


    void createSemaphores(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, uint32_t count, VkSemaphore* semaphores)
    {
        VkSemaphoreCreateInfo info;
        info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        info.pNext = nullptr;
        info.flags = 0;

        for (uint32_t i = 0; i < count; i++)
            dispatchTable.CreateSemaphore(device, &info, nullptr, &semaphores[i]);
    }

}
