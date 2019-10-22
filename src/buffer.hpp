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
    void createBuffer(const VkLayerInstanceDispatchTable& instanceDispatchTable, const VkDevice& device,const VkLayerDispatchTable& dispatchTable, const VkPhysicalDevice& physicalDevice,const VkDeviceSize& size,const VkBufferUsageFlags& usage,const VkMemoryPropertyFlags& properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
}


#endif // BUFFER_HPP_INCLUDED
