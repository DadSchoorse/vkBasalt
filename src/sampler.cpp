#include "sampler.hpp"

namespace vkBasalt
{
    VkSampler createSampler(LogicalDevice* pLogicalDevice)
    {
        VkSampler sampler;

        VkSamplerCreateInfo samplerCreateInfo;
        samplerCreateInfo.sType                   = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        samplerCreateInfo.pNext                   = nullptr;
        samplerCreateInfo.flags                   = 0;
        samplerCreateInfo.magFilter               = VK_FILTER_LINEAR;
        samplerCreateInfo.minFilter               = VK_FILTER_LINEAR;
        samplerCreateInfo.mipmapMode              = VK_SAMPLER_MIPMAP_MODE_LINEAR;
        samplerCreateInfo.addressModeU            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        samplerCreateInfo.addressModeV            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        samplerCreateInfo.addressModeW            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        samplerCreateInfo.mipLodBias              = 0.0f;
        samplerCreateInfo.anisotropyEnable        = VK_FALSE;
        samplerCreateInfo.maxAnisotropy           = 16;
        samplerCreateInfo.compareEnable           = VK_FALSE;
        samplerCreateInfo.compareOp               = VK_COMPARE_OP_ALWAYS;
        samplerCreateInfo.minLod                  = 0.0f;
        samplerCreateInfo.maxLod                  = 0.0f;
        samplerCreateInfo.borderColor             = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
        samplerCreateInfo.unnormalizedCoordinates = VK_FALSE;

        VkResult result = pLogicalDevice->vkd.CreateSampler(pLogicalDevice->device, &samplerCreateInfo, nullptr, &sampler);
        ASSERT_VULKAN(result);
        return sampler;
    }

    VkSampler createReshadeSampler(LogicalDevice* pLogicalDevice, const reshadefx::sampler_info& samplerInfo)
    {
        VkSampler sampler;

        VkFilter            minFilter;
        VkFilter            magFilter;
        VkSamplerMipmapMode mipmapMode;
        convertReshadeFilter(samplerInfo.filter, minFilter, magFilter, mipmapMode);

        VkSamplerCreateInfo samplerCreateInfo;
        samplerCreateInfo.sType                   = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        samplerCreateInfo.pNext                   = nullptr;
        samplerCreateInfo.flags                   = 0;
        samplerCreateInfo.magFilter               = magFilter;
        samplerCreateInfo.minFilter               = minFilter;
        samplerCreateInfo.mipmapMode              = mipmapMode;
        samplerCreateInfo.addressModeU            = convertReshadeAddressMode(samplerInfo.address_u);
        samplerCreateInfo.addressModeV            = convertReshadeAddressMode(samplerInfo.address_v);
        samplerCreateInfo.addressModeW            = convertReshadeAddressMode(samplerInfo.address_w);
        samplerCreateInfo.mipLodBias              = samplerInfo.lod_bias;
        samplerCreateInfo.anisotropyEnable        = VK_FALSE;
        samplerCreateInfo.maxAnisotropy           = 16;
        samplerCreateInfo.compareEnable           = VK_FALSE;
        samplerCreateInfo.compareOp               = VK_COMPARE_OP_ALWAYS;
        samplerCreateInfo.minLod                  = samplerInfo.min_lod;
        samplerCreateInfo.maxLod                  = samplerInfo.max_lod;
        samplerCreateInfo.borderColor             = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
        samplerCreateInfo.unnormalizedCoordinates = VK_FALSE;

        VkResult result = pLogicalDevice->vkd.CreateSampler(pLogicalDevice->device, &samplerCreateInfo, nullptr, &sampler);
        ASSERT_VULKAN(result);
        return sampler;
    }

    VkSamplerAddressMode convertReshadeAddressMode(const reshadefx::texture_address_mode& addressMode)
    {
        switch (addressMode)
        {
            case reshadefx::texture_address_mode::wrap: return VK_SAMPLER_ADDRESS_MODE_REPEAT;
            case reshadefx::texture_address_mode::mirror: return VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
            case reshadefx::texture_address_mode::clamp: return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
            case reshadefx::texture_address_mode::border: return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
        }
        return VK_SAMPLER_ADDRESS_MODE_REPEAT;
    }

    void
    convertReshadeFilter(const reshadefx::texture_filter& textureFilter, VkFilter& minFilter, VkFilter& magFilter, VkSamplerMipmapMode& mipmapMode)
    {
        switch (textureFilter)
        {
            case reshadefx::texture_filter::min_mag_mip_point:
                minFilter  = VK_FILTER_NEAREST;
                magFilter  = VK_FILTER_NEAREST;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
                return;
            case reshadefx::texture_filter::min_mag_point_mip_linear:
                minFilter  = VK_FILTER_NEAREST;
                magFilter  = VK_FILTER_NEAREST;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
                return;
            case reshadefx::texture_filter::min_point_mag_linear_mip_point:
                minFilter  = VK_FILTER_NEAREST;
                magFilter  = VK_FILTER_LINEAR;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
                return;
            case reshadefx::texture_filter::min_point_mag_mip_linear:
                minFilter  = VK_FILTER_NEAREST;
                magFilter  = VK_FILTER_LINEAR;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
                return;
            case reshadefx::texture_filter::min_linear_mag_mip_point:
                minFilter  = VK_FILTER_LINEAR;
                magFilter  = VK_FILTER_NEAREST;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
                return;
            case reshadefx::texture_filter::min_linear_mag_point_mip_linear:
                minFilter  = VK_FILTER_LINEAR;
                magFilter  = VK_FILTER_NEAREST;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
                return;
            case reshadefx::texture_filter::min_mag_linear_mip_point:
                minFilter  = VK_FILTER_LINEAR;
                magFilter  = VK_FILTER_LINEAR;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
                return;
            case reshadefx::texture_filter::min_mag_mip_linear:
                minFilter  = VK_FILTER_LINEAR;
                magFilter  = VK_FILTER_LINEAR;
                mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
                return;
        }
    }
} // namespace vkBasalt
