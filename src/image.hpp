#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    std::vector<VkImage> createImages(LogicalDevice logicalDevice,
                                      uint32_t count,
                                      VkExtent3D extent,
                                      VkFormat format,
                                      VkImageUsageFlags usage,
                                      VkMemoryPropertyFlags properties,
                                      VkDeviceMemory& imageMemory,
                                      uint32_t mipLevels = 1);
    void uploadToImage(LogicalDevice logicalDevice,
                       VkImage image,
                       VkExtent3D extent,
                       uint32_t size,
                       const unsigned char* writeData);
    
    void changeImageLayout(LogicalDevice logicalDevice, std::vector<VkImage> images, uint32_t mipLevels = 1);
}


#endif // IMAGE_HPP_INCLUDED
