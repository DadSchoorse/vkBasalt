#ifndef IMAGE_VIEW_HPP_INCLUDED
#define IMAGE_VIEW_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
     std::vector<VkImageView> createImageViews(VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format, std::vector<VkImage> images, VkImageViewType viewType = VK_IMAGE_VIEW_TYPE_2D, VkImageAspectFlags aspectMask = VK_IMAGE_ASPECT_COLOR_BIT);
}


#endif // IMAGE_VIEW_HPP_INCLUDED
