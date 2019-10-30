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
    void createFramebuffers(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const uint32_t& count, const VkRenderPass& renderPass, const VkExtent2D& extent, const VkImageView* imageViews, VkFramebuffer* framebuffers)
    {
        for(uint32_t i=0;i<count;i++)
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
    }
}
