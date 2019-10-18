#ifndef IMAGE_VIEW_HPP_INCLUDED
#define IMAGE_VIEW_HPP_INCLUDED
#include <assert.h>
#include <string.h>
#include <unistd.h>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
     void createImageViews(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkFormat& format, const uint32_t& imageCount, const VkImage* images, VkImageView* imageViews);
}


#endif // IMAGE_VIEW_HPP_INCLUDED
