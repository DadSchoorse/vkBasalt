#ifndef FRAMEBUFFER_HPP_INCLUDED
#define FRAMEBUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt
{
    std::vector<VkFramebuffer> createFramebuffers(VkDevice device, VkLayerDispatchTable dispatchTable, VkRenderPass renderPass, VkExtent2D& extent, std::vector<VkImageView> imageViews);
}


#endif // FRAMEBUFFER_HPP_INCLUDED
