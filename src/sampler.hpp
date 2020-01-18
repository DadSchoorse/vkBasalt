#ifndef SAMPLER_HPP_INCLUDED
#define SAMPLER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

#include "../reshade/source/effect_module.hpp"
namespace vkBasalt
{
    VkSampler createSampler(LogicalDevice logicalDevice);
    VkSampler createReshadeSampler(LogicalDevice logicalDevice, const reshadefx::sampler_info& samplerInfo);
    VkSamplerAddressMode convertReshadeAddressMode(const reshadefx::texture_address_mode& addressMode);
    void convertReshadeFilter(const reshadefx::texture_filter& textureFilter, VkFilter& minFilter, VkFilter& magFilter, VkSamplerMipmapMode& mipmapMode);
}

#endif // SAMPLER_HPP_INCLUDED
