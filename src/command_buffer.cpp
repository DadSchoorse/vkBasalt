#include "command_buffer.hpp"

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
    void writeCommandBuffers(LogicalDevice logicalDevice, std::vector<std::shared_ptr<vkBasalt::Effect>> effects, std::vector<VkCommandBuffer> commandBuffers)
    {
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.pNext = nullptr;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
        beginInfo.pInheritanceInfo = nullptr;
        
        for(uint32_t i=0;i<commandBuffers.size();i++)
        {
            
            VkResult result = logicalDevice.vkd.BeginCommandBuffer(commandBuffers[i],&beginInfo);
            ASSERT_VULKAN(result);
            
            for(uint32_t j=0;j<effects.size();j++)
            {
                std::cout << "before applying effect " << effects[j] << std::endl; 
                effects[j]->applyEffect(i,commandBuffers[i]);
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
