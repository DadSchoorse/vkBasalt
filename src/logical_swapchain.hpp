#ifndef LOGICAL_SWAPCHAIN_HPP_INCLUDED
#define LOGICAL_SWAPCHAIN_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "effect.hpp"

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    //for each swapchain, we have the Images and the other stuff we need to execute the compute shader
    struct LogicalSwapchain
    {
        LogicalDevice                        logicalDevice;
        VkSwapchainCreateInfoKHR             swapchainCreateInfo;
        VkExtent2D                           imageExtent;
        VkFormat                             format;
        uint32_t                             imageCount;
        std::vector<VkImage>                 images;
        std::vector<VkImage>                 fakeImages;
        std::vector<VkCommandBuffer>         commandBuffers;
        std::vector<VkSemaphore>             semaphores;
        std::vector<std::shared_ptr<Effect>> effects;
        VkDeviceMemory                       fakeImageMemory;
        
        void destroy();
    };
}


#endif // LOGICAL_SWAPCHAIN_HPP_INCLUDED
