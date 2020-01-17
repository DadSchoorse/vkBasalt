#ifndef BUFFER_HPP_INCLUDED
#define BUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

namespace vkBasalt
{
    void createBuffer(VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkPhysicalDevice physicalDevice, VkDeviceSize size,  VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
}


#endif // BUFFER_HPP_INCLUDED
