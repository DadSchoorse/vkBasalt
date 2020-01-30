#ifndef MEMORY_HPP_INCLUDED
#define MEMORY_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt{
    uint32_t findMemoryTypeIndex(std::shared_ptr<LogicalDevice> pLogicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties);
}


#endif // MEMORY_HPP_INCLUDED
