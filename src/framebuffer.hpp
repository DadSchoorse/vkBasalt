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
    void createFramebuffers(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const uint32_t& count, const VkRenderPass& renderPass, const VkExtent2D& extent, const VkImageView* imageViews, VkFramebuffer* framebuffers);
}


#endif // FRAMEBUFFER_HPP_INCLUDED
