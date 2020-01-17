#ifndef FAKE_SWAPCHAIN_HPP_INCLUDED
#define FAKE_SWAPCHAIN_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt{
    std::vector<VkImage> createFakeSwapchainImages(LogicalDevice logicalDevice, VkSwapchainCreateInfoKHR swapchainCreateInfo, uint32_t count, VkDeviceMemory& deviceMemory);
}


#endif // FAKE_SWAPCHAIN_HPP_INCLUDED
