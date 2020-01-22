#ifndef FORMAT_HPP_INCLUDED
#define FORMAT_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    //Returns a matching sRGB format to a UNORM format if it exist, else returns format 
    VkFormat convertToSRGB(VkFormat format);
    //Returns a matching UNORM format to a sRGB format if it exist, else returns format
    VkFormat convertToUNORM(VkFormat format);
    //Returns true if format is SRGB
    bool isSRGB(VkFormat format);
    //Returns true if format is UNORM
    //TODO currently return false if format is UNORM and not matching sRGB format exist
    bool isUNORM(VkFormat format);
    
    VkFormat getSupportedFormat(LogicalDevice logicalDevice, std::vector<VkFormat> formats, VkFormatFeatureFlags features, VkImageTiling tiling = VK_IMAGE_TILING_OPTIMAL);
    
    VkFormat getStencilFormat(LogicalDevice logicalDevice);
    
    bool isDepthFormat(VkFormat format);
}


#endif // FORMAT_HPP_INCLUDED
