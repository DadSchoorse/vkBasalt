#include "fake_swapchain.hpp"
#include "memory.hpp"
#include "format.hpp"

namespace vkBasalt
{
    std::vector<VkImage> createFakeSwapchainImages(LogicalDevice*           pLogicalDevice,
                                                   VkSwapchainCreateInfoKHR swapchainCreateInfo,
                                                   uint32_t                 count,
                                                   VkDeviceMemory&          deviceMemory)
    {
        std::vector<VkImage> fakeImages(count);

        VkFormat srgbFormat =
            isSRGB(swapchainCreateInfo.imageFormat) ? swapchainCreateInfo.imageFormat : convertToSRGB(swapchainCreateInfo.imageFormat);
        VkFormat unormFormat =
            isSRGB(swapchainCreateInfo.imageFormat) ? convertToUNORM(swapchainCreateInfo.imageFormat) : swapchainCreateInfo.imageFormat;

        VkFormat formats[] = {unormFormat, srgbFormat};

        VkImageFormatListCreateInfoKHR imageFormatListCreateInfo;
        imageFormatListCreateInfo.sType           = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR;
        imageFormatListCreateInfo.pNext           = nullptr;
        imageFormatListCreateInfo.viewFormatCount = 2;
        imageFormatListCreateInfo.pViewFormats    = formats;

        VkImageCreateInfo imageCreateInfo;
        imageCreateInfo.sType         = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        imageCreateInfo.pNext         = (unormFormat == srgbFormat) ? nullptr : &imageFormatListCreateInfo;
        imageCreateInfo.flags         = (unormFormat == srgbFormat) ? 0 : VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
        imageCreateInfo.imageType     = VK_IMAGE_TYPE_2D;
        imageCreateInfo.format        = swapchainCreateInfo.imageFormat;
        imageCreateInfo.extent.width  = swapchainCreateInfo.imageExtent.width;
        imageCreateInfo.extent.height = swapchainCreateInfo.imageExtent.height;
        imageCreateInfo.extent.depth  = 1;
        imageCreateInfo.mipLevels     = 1;
        imageCreateInfo.arrayLayers   = swapchainCreateInfo.imageArrayLayers;
        imageCreateInfo.samples       = VK_SAMPLE_COUNT_1_BIT;
        imageCreateInfo.tiling        = VK_IMAGE_TILING_OPTIMAL;
        imageCreateInfo.usage         = swapchainCreateInfo.imageUsage | VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT
                                | VK_IMAGE_USAGE_TRANSFER_SRC_BIT; // TODO what usage do we need?
        imageCreateInfo.sharingMode           = swapchainCreateInfo.imageSharingMode;
        imageCreateInfo.queueFamilyIndexCount = swapchainCreateInfo.queueFamilyIndexCount;
        imageCreateInfo.pQueueFamilyIndices   = swapchainCreateInfo.pQueueFamilyIndices;
        imageCreateInfo.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

        VkResult result;
        for (uint32_t i = 0; i < count; i++)
        {
            result = pLogicalDevice->vkd.CreateImage(pLogicalDevice->device, &imageCreateInfo, nullptr, &(fakeImages[i]));
            ASSERT_VULKAN(result);
        }

        // Allocate a bunch of memory for all images at one
        VkMemoryRequirements memoryRequirements;
        pLogicalDevice->vkd.GetImageMemoryRequirements(pLogicalDevice->device, fakeImages[0], &memoryRequirements);

        Logger::debug("fake image size: " + std::to_string(memoryRequirements.size));
        Logger::debug("fake image alignment: " + std::to_string(memoryRequirements.alignment));

        if (memoryRequirements.size % memoryRequirements.alignment != 0)
        {
            memoryRequirements.size = (memoryRequirements.size / memoryRequirements.alignment + 1) * memoryRequirements.alignment;
        }

        VkMemoryAllocateInfo memoryAllocateInfo;
        memoryAllocateInfo.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        memoryAllocateInfo.pNext          = nullptr;
        memoryAllocateInfo.allocationSize = memoryRequirements.size * count;
        memoryAllocateInfo.memoryTypeIndex =
            findMemoryTypeIndex(pLogicalDevice, memoryRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

        result = pLogicalDevice->vkd.AllocateMemory(pLogicalDevice->device, &memoryAllocateInfo, nullptr, &deviceMemory);
        ASSERT_VULKAN(result);

        for (uint32_t i = 0; i < count; i++)
        {
            result = pLogicalDevice->vkd.BindImageMemory(pLogicalDevice->device, fakeImages[i], deviceMemory, memoryRequirements.size * i);
            ASSERT_VULKAN(result);
        }
        return fakeImages;
    }
} // namespace vkBasalt
