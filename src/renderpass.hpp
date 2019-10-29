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
    void createRenderPass(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkFormat& format, VkRenderPass& renderPass);

}


#endif // RENDERPASS_HPP_INCLUDED
