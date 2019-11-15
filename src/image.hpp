#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"
namespace vkBasalt
{
    std::vector<VkImage> createImages(VkLayerInstanceDispatchTable instanceDispatchTable,
                                      VkDevice device,
                                      VkLayerDispatchTable dispatchTable,
                                      VkPhysicalDevice physicalDevice,
                                      uint32_t count,
                                      VkExtent2D extent,
                                      VkFormat format,
                                      VkImageUsageFlags usage,
                                      VkMemoryPropertyFlags properties,
                                      VkDeviceMemory& imageMemory);
    void uploadToImage(VkLayerInstanceDispatchTable instanceDispatchTable,
                       VkDevice device,
                       VkLayerDispatchTable dispatchTable,
                       VkPhysicalDevice physicalDevice,
                       VkImage image,
                       VkExtent2D extent,
                       uint32_t size,
                       VkQueue queue,
                       VkCommandPool commandPool,
                       const unsigned char* writeData);
}


#endif // IMAGE_HPP_INCLUDED
