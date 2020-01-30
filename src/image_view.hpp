#ifndef IMAGE_VIEW_HPP_INCLUDED
#define IMAGE_VIEW_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt{
     std::vector<VkImageView> createImageViews(std::shared_ptr<LogicalDevice> pLogicalDevice, VkFormat format, std::vector<VkImage> images, VkImageViewType viewType = VK_IMAGE_VIEW_TYPE_2D, VkImageAspectFlags aspectMask = VK_IMAGE_ASPECT_COLOR_BIT);
}


#endif // IMAGE_VIEW_HPP_INCLUDED
