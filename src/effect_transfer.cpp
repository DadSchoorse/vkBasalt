#include "effect_transfer.hpp"

namespace vkBasalt
{
    TransferEffect::TransferEffect(LogicalDevice*       pLogicalDevice,
                                   VkFormat             format,
                                   VkExtent2D           imageExtent,
                                   std::vector<VkImage> inputImages,
                                   std::vector<VkImage> outputImages,
                                   Config*              pConfig)
    {
        this->pLogicalDevice = pLogicalDevice;
        this->format         = format;
        this->imageExtent    = imageExtent;
        this->inputImages    = inputImages;
        this->outputImages   = outputImages;
        this->pConfig        = pConfig;
    }

    void TransferEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        VkImageCopy imageCopy;
        imageCopy.srcSubresource            = {};
        imageCopy.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        imageCopy.srcSubresource.layerCount = 1;
        imageCopy.srcOffset                 = {};
        imageCopy.dstSubresource            = {};
        imageCopy.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        imageCopy.dstSubresource.layerCount = 1;
        imageCopy.dstOffset                 = {};
        imageCopy.extent                    = {imageExtent.width, imageExtent.height, 1};

        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext               = nullptr;
        memoryBarrier.srcAccessMask       = 0;
        memoryBarrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
        memoryBarrier.oldLayout           = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        memoryBarrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.image               = inputImages[imageIndex];

        memoryBarrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        memoryBarrier.subresourceRange.baseMipLevel   = 0;
        memoryBarrier.subresourceRange.levelCount     = 1;
        memoryBarrier.subresourceRange.baseArrayLayer = 0;
        memoryBarrier.subresourceRange.layerCount     = 1;

        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);

        memoryBarrier.image         = outputImages[imageIndex];
        memoryBarrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        memoryBarrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        memoryBarrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);

        pLogicalDevice->vkd.CmdCopyImage(commandBuffer,
                                         inputImages[imageIndex],
                                         VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                         outputImages[imageIndex],
                                         VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                         1,
                                         &imageCopy);

        memoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        memoryBarrier.dstAccessMask = 0;
        memoryBarrier.image         = outputImages[imageIndex];
        memoryBarrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        memoryBarrier.newLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);

        memoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        memoryBarrier.image         = inputImages[imageIndex];
        memoryBarrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        memoryBarrier.newLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);
    }

    TransferEffect::~TransferEffect()
    {
    }

} // namespace vkBasalt
