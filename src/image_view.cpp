#include "image_view.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + val);\
        }
#endif

namespace vkBasalt
{
    void createImageViews(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkFormat& format, const uint32_t& imageCount, const VkImage* images, VkImageView* imageViews)
    {

        VkImageViewCreateInfo imageViewCreateInfo;

        imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        imageViewCreateInfo.pNext = nullptr;
        imageViewCreateInfo.flags = 0;
        imageViewCreateInfo.image = VK_NULL_HANDLE;
        imageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        imageViewCreateInfo.format = format;
        imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
        imageViewCreateInfo.subresourceRange.levelCount = 1;
        imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
        imageViewCreateInfo.subresourceRange.layerCount = 1;
        
        for(int i=0;i<imageCount;i++)
        {
            imageViewCreateInfo.image = images[i];
            VkResult result = dispatchTable.CreateImageView(device,&imageViewCreateInfo,nullptr,&(imageViews[i]));
            ASSERT_VULKAN(result);
        }
        
    }
        
}
