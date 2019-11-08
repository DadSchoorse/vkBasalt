#ifndef MEMORY_HPP_INCLUDED
#define MEMORY_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
    uint32_t findMemoryTypeIndex(VkLayerInstanceDispatchTable dispatchTable, VkPhysicalDevice physicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties);
}


#endif // MEMORY_HPP_INCLUDED
