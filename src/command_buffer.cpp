#include "command_buffer.hpp"

#include "format.hpp"

namespace vkBasalt
{
    std::vector<VkCommandBuffer> allocateCommandBuffer(LogicalDevice logicalDevice, uint32_t count)
    {
        std::vector<VkCommandBuffer> commandBuffers(count);
        
        VkCommandBufferAllocateInfo allocInfo;
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.pNext = nullptr;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = logicalDevice.commandPool;
        allocInfo.commandBufferCount = count;
        
        VkResult result = logicalDevice.vkd.AllocateCommandBuffers(logicalDevice.device, &allocInfo, commandBuffers.data());
        ASSERT_VULKAN(result);
        for(uint32_t i = 0; i < count; i++)
        {
            //initialize dispatch tables for commandBuffers since the are dispatchable objects
            *reinterpret_cast<void**>(commandBuffers[i]) = *reinterpret_cast<void**>(logicalDevice.device);
        }
        
        return commandBuffers;
    
    }
    void writeCommandBuffers(LogicalDevice logicalDevice, std::vector<std::shared_ptr<vkBasalt::Effect>> effects, VkImage depthImage, VkImageView depthImageView, VkFormat depthFormat, std::vector<VkCommandBuffer> commandBuffers)
    {
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.pNext = nullptr;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
        beginInfo.pInheritanceInfo = nullptr;
        
        for(auto& effect: effects)
        {
            effect->useDepthImage(depthImageView);
        }
        
        for(uint32_t i=0;i<commandBuffers.size();i++)
        {
            
            VkResult result = logicalDevice.vkd.BeginCommandBuffer(commandBuffers[i],&beginInfo);
            ASSERT_VULKAN(result);
            
            VkImageMemoryBarrier memoryBarrier;
            memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            memoryBarrier.pNext = nullptr;
            memoryBarrier.image = depthImage;
            memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
            memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            memoryBarrier.srcAccessMask = 0;
            memoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
            memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            memoryBarrier.subresourceRange.aspectMask = isStencilFormat(depthFormat) ? VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT : VK_IMAGE_ASPECT_DEPTH_BIT;
            memoryBarrier.subresourceRange.baseMipLevel = 0;
            memoryBarrier.subresourceRange.levelCount = 1;
            memoryBarrier.subresourceRange.baseArrayLayer = 0;
            memoryBarrier.subresourceRange.layerCount = 1;
            
            if(depthImageView)
            {
                logicalDevice.vkd.CmdPipelineBarrier(commandBuffers[i], VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);
            }
            
            for(uint32_t j=0;j<effects.size();j++)
            {
                std::cout << "before applying effect " << effects[j] << std::endl; 
                effects[j]->applyEffect(i,commandBuffers[i]);
            }
            
            memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            memoryBarrier.newLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
            memoryBarrier.dstAccessMask = 0;
            if(depthImageView)
            {
                logicalDevice.vkd.CmdPipelineBarrier(commandBuffers[i], VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);
            }
            
            result = logicalDevice.vkd.EndCommandBuffer(commandBuffers[i]);
            ASSERT_VULKAN(result);
        }
    }


    std::vector<VkSemaphore> createSemaphores(LogicalDevice logicalDevice, uint32_t count)
    {
        std::vector<VkSemaphore> semaphores(count);
        VkSemaphoreCreateInfo info;
        info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        info.pNext = nullptr;
        info.flags = 0;

        for (uint32_t i = 0; i < count; i++)
        {
            logicalDevice.vkd.CreateSemaphore(logicalDevice.device, &info, nullptr, &semaphores[i]);
        }
        return semaphores;
    }

}
