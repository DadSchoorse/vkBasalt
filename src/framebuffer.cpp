#include "framebuffer.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    std::vector<VkFramebuffer> createFramebuffers(VkDevice device, VkLayerDispatchTable dispatchTable, VkRenderPass renderPass, VkExtent2D& extent, std::vector<VkImageView> imageViews)
    {
        std::vector<VkFramebuffer> framebuffers(imageViews.size());
        for(uint32_t i=0;i<imageViews.size();i++)
        {
            VkFramebufferCreateInfo framebufferCreateInfo;
            framebufferCreateInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
            framebufferCreateInfo.pNext = nullptr;
            framebufferCreateInfo.flags = 0;
            framebufferCreateInfo.renderPass = renderPass;
            framebufferCreateInfo.attachmentCount = 1;
            framebufferCreateInfo.pAttachments = &(imageViews[i]);
            framebufferCreateInfo.width = extent.width;
            framebufferCreateInfo.height = extent.height;
            framebufferCreateInfo.layers = 1;

            VkResult result = dispatchTable.CreateFramebuffer(device,&framebufferCreateInfo,nullptr,&(framebuffers[i]));
            ASSERT_VULKAN(result);
            
        }
        return framebuffers;
    }
}
