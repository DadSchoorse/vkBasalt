#include "buffer.hpp"
#include "memory.hpp"

namespace vkBasalt
{
    void createBuffer(LogicalDevice logicalDevice, VkDeviceSize size,  VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory)
    {
        VkBufferCreateInfo bufferInfo = {};
        bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferInfo.size = size;
        bufferInfo.usage = usage;
        bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

        if (logicalDevice.vkd.CreateBuffer(logicalDevice.device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
            throw std::runtime_error("failed to create buffer!");
        }

        VkMemoryRequirements memRequirements;
        logicalDevice.vkd.GetBufferMemoryRequirements(logicalDevice.device, buffer, &memRequirements);

        VkMemoryAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex = findMemoryTypeIndex(logicalDevice, memRequirements.memoryTypeBits, properties);

        if (logicalDevice.vkd.AllocateMemory(logicalDevice.device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
            throw std::runtime_error("failed to allocate buffer memory!");
        }

        logicalDevice.vkd.BindBufferMemory(logicalDevice.device, buffer, bufferMemory, 0);
    }

}
