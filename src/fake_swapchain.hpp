#ifndef FAKE_SWAPCHAIN_HPP_INCLUDED
#define FAKE_SWAPCHAIN_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
    std::vector<VkImage> createFakeSwapchainImages(VkLayerInstanceDispatchTable instanceDispatchTable, VkPhysicalDevice physicalDevice, VkDevice device, VkLayerDispatchTable dispatchTable, VkSwapchainCreateInfoKHR swapchainCreateInfo, uint32_t count, VkDeviceMemory& deviceMemory)
}


#endif // FAKE_SWAPCHAIN_HPP_INCLUDED
