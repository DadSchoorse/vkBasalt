#ifndef BUFFER_HPP_INCLUDED
#define BUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"
namespace vkBasalt
{
    void createBuffer(VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkPhysicalDevice physicalDevice, VkDeviceSize size,  VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
}


#endif // BUFFER_HPP_INCLUDED
