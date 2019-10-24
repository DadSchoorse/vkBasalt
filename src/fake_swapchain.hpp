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
    void createFakeSwapchainImages(const VkLayerInstanceDispatchTable& instanceDispatchTable, const VkPhysicalDevice& physicalDevice, const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkSwapchainCreateInfoKHR& swapchainCreateInfo, const uint32_t& count, VkImage* fakeImages, VkDeviceMemory& deviceMemory);
}


#endif // FAKE_SWAPCHAIN_HPP_INCLUDED
