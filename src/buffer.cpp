#include "buffer.hpp"
#include "memory.hpp"

namespace vkBasalt
{
    void createBuffer(std::shared_ptr<LogicalDevice> pLogicalDevice, VkDeviceSize size,  VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory)
    {
        VkBufferCreateInfo bufferInfo = {};
        bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferInfo.size = size;
        bufferInfo.usage = usage;
        bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

        if (pLogicalDevice->vkd.CreateBuffer(pLogicalDevice->device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
            throw std::runtime_error("failed to create buffer!");
        }

        VkMemoryRequirements memRequirements;
        pLogicalDevice->vkd.GetBufferMemoryRequirements(pLogicalDevice->device, buffer, &memRequirements);

        VkMemoryAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex = findMemoryTypeIndex(pLogicalDevice, memRequirements.memoryTypeBits, properties);

        if (pLogicalDevice->vkd.AllocateMemory(pLogicalDevice->device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
            throw std::runtime_error("failed to allocate buffer memory!");
        }

        pLogicalDevice->vkd.BindBufferMemory(pLogicalDevice->device, buffer, bufferMemory, 0);
    }

}
