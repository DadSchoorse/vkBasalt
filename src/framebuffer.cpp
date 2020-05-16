#include "framebuffer.hpp"

namespace vkBasalt
{
    std::vector<VkFramebuffer>
    createFramebuffers(LogicalDevice* pLogicalDevice, VkRenderPass renderPass, VkExtent2D& extent, std::vector<std::vector<VkImageView>> imageViews)
    {
        std::vector<VkFramebuffer> framebuffers(imageViews[0].size());
        std::vector<VkImageView>   perFrameImageViews;
        for (uint32_t i = 0; i < imageViews[0].size(); i++)
        {
            for (auto& iv : imageViews)
            {
                perFrameImageViews.push_back(iv[i]);
            }

            VkFramebufferCreateInfo framebufferCreateInfo;
            framebufferCreateInfo.sType           = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
            framebufferCreateInfo.pNext           = nullptr;
            framebufferCreateInfo.flags           = 0;
            framebufferCreateInfo.renderPass      = renderPass;
            framebufferCreateInfo.attachmentCount = perFrameImageViews.size();
            framebufferCreateInfo.pAttachments    = perFrameImageViews.data();
            framebufferCreateInfo.width           = extent.width;
            framebufferCreateInfo.height          = extent.height;
            framebufferCreateInfo.layers          = 1;

            VkResult result = pLogicalDevice->vkd.CreateFramebuffer(pLogicalDevice->device, &framebufferCreateInfo, nullptr, &(framebuffers[i]));
            ASSERT_VULKAN(result);
            perFrameImageViews.clear();
        }
        return framebuffers;
    }
} // namespace vkBasalt
