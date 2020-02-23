#ifndef LOGICAL_DEVICE_HPP_INCLUDED
#define LOGICAL_DEVICE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

namespace vkBasalt
{
    struct LogicalDevice
    {
        VkLayerDispatchTable         vkd;
        VkLayerInstanceDispatchTable vki;
        VkDevice                     device;
        VkPhysicalDevice             physicalDevice;
        VkInstance                   instance;
        VkQueue                      queue;
        uint32_t                     queueFamilyIndex;
        VkCommandPool                commandPool;
        bool                         supportsMutableFormat;
        std::vector<VkImage>         depthImages;
        std::vector<VkFormat>        depthFormats;
        std::vector<VkImageView>     depthImageViews;
    };
} // namespace vkBasalt

#endif // LOGICAL_DEVICE_HPP_INCLUDED
