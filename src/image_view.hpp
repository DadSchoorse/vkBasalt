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
     std::vector<VkImageView> createImageViews(VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format, std::vector<VkImage> images);
}


#endif // IMAGE_VIEW_HPP_INCLUDED
