#include "image.hpp"
#include "memory.hpp"
#include "buffer.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    std::vector<VkImage> createImages(VkLayerInstanceDispatchTable instanceDispatchTable,
                                      VkDevice device,
                                      VkLayerDispatchTable dispatchTable,
                                      VkPhysicalDevice physicalDevice,
                                      uint32_t count,
                                      VkExtent3D extent,
                                      VkFormat format,
                                      VkImageUsageFlags usage,
                                      VkMemoryPropertyFlags properties,
                                      VkDeviceMemory& imageMemory)
    {
        std::vector<VkImage> images(count);
        VkImageCreateInfo imageCreateInfo;
        imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        imageCreateInfo.pNext = nullptr;
        imageCreateInfo.flags = 0;
        if(extent.depth == 1)
        {
            imageCreateInfo.imageType = VK_IMAGE_TYPE_2D;
        }
        else
        {
            imageCreateInfo.imageType = VK_IMAGE_TYPE_3D;
        }
        imageCreateInfo.format = format;
        imageCreateInfo.extent = extent;
        imageCreateInfo.mipLevels = 1;
        imageCreateInfo.arrayLayers = 1;
        imageCreateInfo.samples = VK_SAMPLE_COUNT_1_BIT;
        imageCreateInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
        imageCreateInfo.usage = usage;
        imageCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        imageCreateInfo.queueFamilyIndexCount = 0;//Don't care
        imageCreateInfo.pQueueFamilyIndices = nullptr;//Don't care
        imageCreateInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        
        VkResult result;
        for(uint32_t i=0;i<count;i++)
        {
            result = dispatchTable.CreateImage(device, &imageCreateInfo, nullptr, &(images[i]));
            ASSERT_VULKAN(result);
        }
        //Allocate a bunch of memory for all images at one
        VkMemoryRequirements memoryRequirements;
        dispatchTable.GetImageMemoryRequirements(device, images[0], &memoryRequirements);
        
        if(memoryRequirements.size%memoryRequirements.alignment!=0)
        {
            memoryRequirements.size = (memoryRequirements.size/memoryRequirements.alignment+1)*memoryRequirements.alignment;
        }
        
        VkMemoryAllocateInfo memoryAllocateInfo;
        memoryAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        memoryAllocateInfo.pNext = nullptr;
        memoryAllocateInfo.allocationSize = memoryRequirements.size * count;
        memoryAllocateInfo.memoryTypeIndex = findMemoryTypeIndex(instanceDispatchTable,physicalDevice,memoryRequirements.memoryTypeBits,properties);
        
        result = dispatchTable.AllocateMemory(device, &memoryAllocateInfo, nullptr, &imageMemory);
        ASSERT_VULKAN(result);
        
        for(uint32_t i=0;i<count;i++)
        {
            result = dispatchTable.BindImageMemory(device, images[i], imageMemory, memoryRequirements.size*i);
            ASSERT_VULKAN(result);
        }
        return images;
    }
    
    void uploadToImage(VkLayerInstanceDispatchTable instanceDispatchTable,
                       VkDevice device,
                       VkLayerDispatchTable dispatchTable,
                       VkPhysicalDevice physicalDevice,
                       VkImage image,
                       VkExtent3D extent,
                       uint32_t size,
                       VkQueue queue,
                       VkCommandPool commandPool,
                       const unsigned char* writeData)
    {
        
        VkBuffer stagingBuffer;
        VkDeviceMemory stagingMemory;
        
        createBuffer(instanceDispatchTable,
                     device,
                     dispatchTable,
                     physicalDevice,
                     size,
                     VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                     VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                     stagingBuffer,
                     stagingMemory);
        void* data;
        VkResult result = dispatchTable.MapMemory(device, stagingMemory, 0, size, 0, &data);
        ASSERT_VULKAN(result);
        std::memcpy(data, writeData, size);
        dispatchTable.UnmapMemory(device, stagingMemory);
        
        VkCommandBufferAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = commandPool;
        allocInfo.commandBufferCount = 1;

        VkCommandBuffer commandBuffer;
        dispatchTable.AllocateCommandBuffers(device, &allocInfo, &commandBuffer);
        //initialize dispatch table for commandBuffer since it is a dispatchable object
        *reinterpret_cast<void**>(commandBuffer) = *reinterpret_cast<void**>(device);

        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

        dispatchTable.BeginCommandBuffer(commandBuffer, &beginInfo);
        
        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext = nullptr;
        memoryBarrier.srcAccessMask = 0;
        memoryBarrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.image = image;
        memoryBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        memoryBarrier.subresourceRange.baseMipLevel = 0;
        memoryBarrier.subresourceRange.levelCount = 1;
        memoryBarrier.subresourceRange.baseArrayLayer = 0;
        memoryBarrier.subresourceRange.layerCount = 1;
        
        dispatchTable.CmdPipelineBarrier(
            commandBuffer,
            VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT,
            0,
            0, nullptr,
            0, nullptr,
            1, &memoryBarrier
        );
        
        VkBufferImageCopy region;
        region.bufferOffset = 0;
        region.bufferRowLength = 0;
        region.bufferImageHeight = 0;
        region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        region.imageSubresource.mipLevel = 0;
        region.imageSubresource.baseArrayLayer = 0;
        region.imageSubresource.layerCount = 1;
        region.imageOffset = {0,0,0};
        region.imageExtent = extent;
        
        dispatchTable.CmdCopyBufferToImage(commandBuffer,stagingBuffer,image,VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,1,&region);
        
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        memoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        memoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        
        dispatchTable.CmdPipelineBarrier(
            commandBuffer,
            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
            0,
            0, nullptr,
            0, nullptr,
            1, &memoryBarrier
        );
        
        dispatchTable.EndCommandBuffer(commandBuffer);

        VkSubmitInfo submitInfo = {};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &commandBuffer;

        dispatchTable.QueueSubmit(queue, 1, &submitInfo, VK_NULL_HANDLE);
        dispatchTable.QueueWaitIdle(queue);

        dispatchTable.FreeCommandBuffers(device, commandPool, 1, &commandBuffer);
        dispatchTable.FreeMemory(device,stagingMemory,nullptr);
        dispatchTable.DestroyBuffer(device,stagingBuffer,nullptr);
    }
    
    void changeImageLayout(VkLayerInstanceDispatchTable instanceDispatchTable,
                       VkDevice device,
                       VkLayerDispatchTable dispatchTable,
                       VkPhysicalDevice physicalDevice,
                       std::vector<VkImage> images,
                       VkQueue queue,
                       VkCommandPool commandPool)
    {
        VkCommandBufferAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = commandPool;
        allocInfo.commandBufferCount = 1;

        VkCommandBuffer commandBuffer;
        dispatchTable.AllocateCommandBuffers(device, &allocInfo, &commandBuffer);
        //initialize dispatch table for commandBuffer since it is a dispatchable object
        *reinterpret_cast<void**>(commandBuffer) = *reinterpret_cast<void**>(device);

        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        
        dispatchTable.BeginCommandBuffer(commandBuffer, &beginInfo);
        
        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext = nullptr;
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        memoryBarrier.srcAccessMask = 0;
        memoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        memoryBarrier.subresourceRange.baseMipLevel = 0;
        memoryBarrier.subresourceRange.levelCount = 1;
        memoryBarrier.subresourceRange.baseArrayLayer = 0;
        memoryBarrier.subresourceRange.layerCount = 1;
        
        for(auto& image : images)
        {
            memoryBarrier.image = image;
            dispatchTable.CmdPipelineBarrier(
                commandBuffer,
                VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                0,
                0, nullptr,
                0, nullptr,
                1, &memoryBarrier);
        }
        
        dispatchTable.EndCommandBuffer(commandBuffer);
        
        VkSubmitInfo submitInfo = {};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &commandBuffer;

        dispatchTable.QueueSubmit(queue, 1, &submitInfo, VK_NULL_HANDLE);
        dispatchTable.QueueWaitIdle(queue);

        dispatchTable.FreeCommandBuffers(device, commandPool, 1, &commandBuffer);
    }
}
