#include "renderpass.hpp"

namespace vkBasalt
{
    VkRenderPass createRenderPass(LogicalDevice* pLogicalDevice, VkFormat format)
    {
        VkRenderPass renderPass;

        VkAttachmentDescription attachmentDescription;
        attachmentDescription.flags          = 0;
        attachmentDescription.format         = format;
        attachmentDescription.samples        = VK_SAMPLE_COUNT_1_BIT;
        attachmentDescription.loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
        attachmentDescription.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
        attachmentDescription.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        attachmentDescription.initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
        attachmentDescription.finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference attachmentReference;
        attachmentReference.attachment = 0;
        attachmentReference.layout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpassDescription;
        subpassDescription.flags                   = 0;
        subpassDescription.pipelineBindPoint       = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpassDescription.inputAttachmentCount    = 0;
        subpassDescription.pInputAttachments       = nullptr;
        subpassDescription.colorAttachmentCount    = 1;
        subpassDescription.pColorAttachments       = &attachmentReference;
        subpassDescription.pResolveAttachments     = nullptr;
        subpassDescription.pDepthStencilAttachment = nullptr;
        subpassDescription.preserveAttachmentCount = 0;
        subpassDescription.pPreserveAttachments    = nullptr;

        VkSubpassDependency subpassDependency;
        subpassDependency.srcSubpass      = VK_SUBPASS_EXTERNAL;
        subpassDependency.dstSubpass      = 0;
        subpassDependency.srcStageMask    = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        subpassDependency.dstStageMask    = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        subpassDependency.srcAccessMask   = 0;
        subpassDependency.dstAccessMask   = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        subpassDependency.dependencyFlags = 0;

        VkRenderPassCreateInfo renderPassCreateInfo;
        renderPassCreateInfo.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        renderPassCreateInfo.pNext           = nullptr;
        renderPassCreateInfo.flags           = 0;
        renderPassCreateInfo.attachmentCount = 1;
        renderPassCreateInfo.pAttachments    = &attachmentDescription;
        renderPassCreateInfo.subpassCount    = 1;
        renderPassCreateInfo.pSubpasses      = &subpassDescription;
        renderPassCreateInfo.dependencyCount = 1;
        renderPassCreateInfo.pDependencies   = &subpassDependency;

        VkResult result = pLogicalDevice->vkd.CreateRenderPass(pLogicalDevice->device, &renderPassCreateInfo, nullptr, &renderPass);
        ASSERT_VULKAN(result);

        return renderPass;
    }
} // namespace vkBasalt
