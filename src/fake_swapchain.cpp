#include "fake_swapchain.hpp"
#include "memory.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    void createFakeSwapchainImages(const VkLayerInstanceDispatchTable& instanceDispatchTable, const VkPhysicalDevice& physicalDevice, const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkSwapchainCreateInfoKHR& swapchainCreateInfo, const uint32_t& count, VkImage* fakeImages, VkDeviceMemory& deviceMemory)
    {
        VkImageCreateInfo imageCreateInfo;
        imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        imageCreateInfo.pNext = nullptr;
        imageCreateInfo.flags = 0;
        imageCreateInfo.imageType = VK_IMAGE_TYPE_2D;
        imageCreateInfo.format = swapchainCreateInfo.imageFormat;
        imageCreateInfo.extent.width = swapchainCreateInfo.imageExtent.width;
        imageCreateInfo.extent.height = swapchainCreateInfo.imageExtent.height;
        imageCreateInfo.extent.depth = 1;
        imageCreateInfo.mipLevels = 1;
        imageCreateInfo.arrayLayers = swapchainCreateInfo.imageArrayLayers;
        imageCreateInfo.samples = VK_SAMPLE_COUNT_1_BIT;
        imageCreateInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
        imageCreateInfo.usage = swapchainCreateInfo.imageUsage | VK_IMAGE_USAGE_SAMPLED_BIT;//TODO what usage do we need?
        imageCreateInfo.sharingMode = swapchainCreateInfo.imageSharingMode;
        imageCreateInfo.queueFamilyIndexCount = swapchainCreateInfo.queueFamilyIndexCount;
        imageCreateInfo.pQueueFamilyIndices = swapchainCreateInfo.pQueueFamilyIndices;
        imageCreateInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        
        VkResult result;
        for(uint32_t i=0;i<count;i++)
        {
            result = dispatchTable.CreateImage(device, &imageCreateInfo, nullptr, &(fakeImages[i]));
            ASSERT_VULKAN(result);
        }
        
        //Allocate a bunch of memory for all images at one
        VkMemoryRequirements memoryRequirements;
        dispatchTable.GetImageMemoryRequirements(device, fakeImages[0], &memoryRequirements);
        
        std::cout << "fake image size: " << memoryRequirements.size << std::endl;
        std::cout << "fake image alignment: " << memoryRequirements.alignment << std::endl;
        
        //TODO make sure that size is alignment aligned
        
        VkMemoryAllocateInfo memoryAllocateInfo;
        memoryAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        memoryAllocateInfo.pNext = nullptr;
        memoryAllocateInfo.allocationSize = memoryRequirements.size * count;
        memoryAllocateInfo.memoryTypeIndex = findMemoryTypeIndex(instanceDispatchTable,physicalDevice,memoryRequirements.memoryTypeBits,VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
        
        result = dispatchTable.AllocateMemory(device, &memoryAllocateInfo, nullptr, &deviceMemory);
        ASSERT_VULKAN(result);
        
        for(uint32_t i=0;i<count;i++)
        {
            result = dispatchTable.BindImageMemory(device, fakeImages[i], deviceMemory, memoryRequirements.size*i);
            ASSERT_VULKAN(result);
        }
    }
}
