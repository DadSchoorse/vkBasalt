#ifndef FRAMEBUFFER_HPP_INCLUDED
#define FRAMEBUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

namespace vkBasalt
{
    std::vector<VkFramebuffer> createFramebuffers(VkDevice device, VkLayerDispatchTable dispatchTable, VkRenderPass renderPass, VkExtent2D& extent, std::vector<std::vector<VkImageView>> imageViews);
}


#endif // FRAMEBUFFER_HPP_INCLUDED
