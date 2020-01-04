#include "image_view.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    std::vector<VkImageView> createImageViews(VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format, std::vector<VkImage> images, VkImageViewType viewType, VkImageAspectFlags aspectMask)
    {
        std::vector<VkImageView> imageViews(images.size());
        
        VkImageViewCreateInfo imageViewCreateInfo;

        imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        imageViewCreateInfo.pNext = nullptr;
        imageViewCreateInfo.flags = 0;
        imageViewCreateInfo.image = VK_NULL_HANDLE;
        imageViewCreateInfo.viewType = viewType;
        imageViewCreateInfo.format = format;
        imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        imageViewCreateInfo.subresourceRange.aspectMask = aspectMask;
        imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
        imageViewCreateInfo.subresourceRange.levelCount = 1;
        imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
        imageViewCreateInfo.subresourceRange.layerCount = 1;
        
        for(unsigned int i=0;i<images.size();i++)
        {
            imageViewCreateInfo.image = images[i];
            VkResult result = dispatchTable.CreateImageView(device,&imageViewCreateInfo,nullptr,&(imageViews[i]));
            ASSERT_VULKAN(result);
        }
        
        return imageViews;
    }
        
}
