#include "format.hpp"

namespace vkBasalt
{
    VkFormat convertToSRGB(VkFormat format)
    {
        switch(format)
        {
            /*case VK_FORMAT_R8_UNORM:
                return VK_FORMAT_R8_SRGB;
            case VK_FORMAT_R8G8_UNORM:
                return VK_FORMAT_R8G8_SRGB;*/
            case VK_FORMAT_B8G8R8_UNORM:
                return VK_FORMAT_B8G8R8_SRGB;
            case VK_FORMAT_R8G8B8A8_UNORM:
                return VK_FORMAT_R8G8B8A8_SRGB;
            case VK_FORMAT_B8G8R8A8_UNORM:
                return VK_FORMAT_B8G8R8A8_SRGB;
            case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
                return VK_FORMAT_A8B8G8R8_SRGB_PACK32;
            case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
                return VK_FORMAT_BC1_RGB_SRGB_BLOCK;
            case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
                return VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
            case VK_FORMAT_BC2_UNORM_BLOCK:
                return VK_FORMAT_BC2_SRGB_BLOCK;
            case VK_FORMAT_BC3_UNORM_BLOCK:
                return VK_FORMAT_BC3_SRGB_BLOCK;
            case VK_FORMAT_BC7_UNORM_BLOCK:
                return VK_FORMAT_BC7_SRGB_BLOCK;
            case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
                return VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK;
            case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
                return VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK;
            case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
                return VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK;
            case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
                return VK_FORMAT_ASTC_4x4_SRGB_BLOCK;
            case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
                return VK_FORMAT_ASTC_5x4_SRGB_BLOCK;
            case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
                return VK_FORMAT_ASTC_5x5_SRGB_BLOCK;
            case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
                return VK_FORMAT_ASTC_6x5_SRGB_BLOCK;
            case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
                return VK_FORMAT_ASTC_6x6_SRGB_BLOCK;
            case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
                return VK_FORMAT_ASTC_8x5_SRGB_BLOCK;
            case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
                return VK_FORMAT_ASTC_8x6_SRGB_BLOCK;
            case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
                return VK_FORMAT_ASTC_8x8_SRGB_BLOCK;
            case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
                return VK_FORMAT_ASTC_10x5_SRGB_BLOCK;
            case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
                return VK_FORMAT_ASTC_10x6_SRGB_BLOCK;
            case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
                return VK_FORMAT_ASTC_10x8_SRGB_BLOCK;
            case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
                return VK_FORMAT_ASTC_10x10_SRGB_BLOCK;
            case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
                return VK_FORMAT_ASTC_12x10_SRGB_BLOCK;
            case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
                return VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
            case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
                return VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG;
            case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
                return VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG;
            case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
                return VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG;
            case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
                return VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG;
            default:
                return format;
        }
    }
    
    VkFormat convertToUNORM(VkFormat format)
    {
        switch(format)
        {
            case VK_FORMAT_R8_SRGB:
                return VK_FORMAT_R8_UNORM;
            case VK_FORMAT_R8G8_SRGB:
                return VK_FORMAT_R8G8_UNORM;
            case VK_FORMAT_B8G8R8_SRGB:
                return VK_FORMAT_B8G8R8_UNORM;
            case VK_FORMAT_R8G8B8A8_SRGB:
                return VK_FORMAT_R8G8B8A8_UNORM;
            case VK_FORMAT_B8G8R8A8_SRGB:
                return VK_FORMAT_B8G8R8A8_UNORM;
            case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
                return VK_FORMAT_A8B8G8R8_UNORM_PACK32;
            case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
                return VK_FORMAT_BC1_RGB_UNORM_BLOCK;
            case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
                return VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
            case VK_FORMAT_BC2_SRGB_BLOCK:
                return VK_FORMAT_BC2_UNORM_BLOCK;
            case VK_FORMAT_BC3_SRGB_BLOCK:
                return VK_FORMAT_BC3_UNORM_BLOCK;
            case VK_FORMAT_BC7_SRGB_BLOCK:
                return VK_FORMAT_BC7_UNORM_BLOCK;
            case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
                return VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK;
            case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
                return VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK;
            case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
                return VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK;
            case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
                return VK_FORMAT_ASTC_4x4_UNORM_BLOCK;
            case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
                return VK_FORMAT_ASTC_5x4_UNORM_BLOCK;
            case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
                return VK_FORMAT_ASTC_5x5_UNORM_BLOCK;
            case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
                return VK_FORMAT_ASTC_6x5_UNORM_BLOCK;
            case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
                return VK_FORMAT_ASTC_6x6_UNORM_BLOCK;
            case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
                return VK_FORMAT_ASTC_8x5_UNORM_BLOCK;
            case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
                return VK_FORMAT_ASTC_8x6_UNORM_BLOCK;
            case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
                return VK_FORMAT_ASTC_8x8_UNORM_BLOCK;
            case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
                return VK_FORMAT_ASTC_10x5_UNORM_BLOCK;
            case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
                return VK_FORMAT_ASTC_10x6_UNORM_BLOCK;
            case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
                return VK_FORMAT_ASTC_10x8_UNORM_BLOCK;
            case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
                return VK_FORMAT_ASTC_10x10_UNORM_BLOCK;
            case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
                return VK_FORMAT_ASTC_12x10_UNORM_BLOCK;
            case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
                return VK_FORMAT_ASTC_12x12_UNORM_BLOCK;
            case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
                return VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG;
            case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
                return VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG;
            case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
                return VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG;
            case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
                return VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG;
            default:
                return format;
        }
    }
    
    bool isSRGB(VkFormat format)
    {
        return convertToUNORM(format) != format;
    }
    
    bool isUNORM(VkFormat format)
    {
        return convertToSRGB(format) != format;
    }
}
