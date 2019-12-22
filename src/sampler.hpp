#ifndef SAMPLER_HPP_INCLUDED
#define SAMPLER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

#include "../reshade/source/effect_module.hpp"
namespace vkBasalt
{
    VkSampler createSampler(VkDevice device, VkLayerDispatchTable dispatchTable);
    VkSampler createReshadeSampler(VkDevice device, VkLayerDispatchTable dispatchTable, const reshadefx::sampler_info& samplerInfo);
    VkSamplerAddressMode convertReshadeAddressMode(const reshadefx::texture_address_mode& addressMode);
    void convertReshadeFilter(const reshadefx::texture_filter& textureFilter, VkFilter& minFilter, VkFilter& magFilter, VkSamplerMipmapMode& mipmapMode);
}

#endif // SAMPLER_HPP_INCLUDED
