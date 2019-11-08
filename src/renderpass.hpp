#ifndef RENDERPASS_HPP_INCLUDED
#define RENDERPASS_HPP_INCLUDED
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
    VkRenderPass createRenderPass(VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format);

}


#endif // RENDERPASS_HPP_INCLUDED
