#ifndef RENDERPASS_HPP_INCLUDED
#define RENDERPASS_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

namespace vkBasalt
{
    VkRenderPass createRenderPass(VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format);

}


#endif // RENDERPASS_HPP_INCLUDED
