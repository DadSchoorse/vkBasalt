#ifndef RENDERPASS_HPP_INCLUDED
#define RENDERPASS_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    VkRenderPass createRenderPass(LogicalDevice* pLogicalDevice, VkFormat format);
}

#endif // RENDERPASS_HPP_INCLUDED
