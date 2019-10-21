#include "command_buffer.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    void allocateCommandBuffer(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkCommandPool& commandPool, const uint32_t& count, VkCommandBuffer* commandBuffers)
    {
        VkCommandBufferAllocateInfo allocInfo;
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.pNext = nullptr;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = commandPool;
        allocInfo.commandBufferCount = count;
        
        for(unsigned int i=0;i<count;i++)
        {
            std::cout << commandBuffers[i] << std::endl;
        }
        VkResult result = dispatchTable.AllocateCommandBuffers(device,&allocInfo,commandBuffers);
        ASSERT_VULKAN(result);
        for(unsigned int i=0;i<count;i++)
        {
            std::cout << commandBuffers[i] << std::endl;
        }
    
    }
    void writeCASCommandBuffers(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkPipeline& pipeline, const VkPipelineLayout& layout, const VkExtent2D& extent, const uint32_t& count,const VkImage* images, const VkDescriptorSet* descriptorSets, VkCommandBuffer* commandBuffers)
    {
        /*
            general 
            Run the shader:
            1. bind pipeline and descriptor set
            2. change Image Layout to general
            3. dispatch
            4. change image layout to present
        */
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.pNext = nullptr;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
        beginInfo.pInheritanceInfo = nullptr;
        
        
        
        //Used to make the Image accessable by the cas shader
        VkImageMemoryBarrier fistBarrier;
        fistBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        fistBarrier.pNext = nullptr;
        fistBarrier.srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
        fistBarrier.dstAccessMask = VK_ACCESS_SHADER_WRITE_BIT | VK_ACCESS_SHADER_READ_BIT;
        fistBarrier.oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        fistBarrier.newLayout = VK_IMAGE_LAYOUT_GENERAL;
        fistBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        fistBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        fistBarrier.image = VK_NULL_HANDLE;
        fistBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        fistBarrier.subresourceRange.baseMipLevel = 0;
        fistBarrier.subresourceRange.levelCount = 1;
        fistBarrier.subresourceRange.baseArrayLayer = 0;
        fistBarrier.subresourceRange.layerCount = 1;
        
        //Reverses the first Barrier
        VkImageMemoryBarrier secondBarrier;
        secondBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        secondBarrier.pNext = nullptr;
        secondBarrier.srcAccessMask =  VK_ACCESS_SHADER_WRITE_BIT | VK_ACCESS_SHADER_READ_BIT;
        secondBarrier.dstAccessMask =  0;
        secondBarrier.oldLayout = VK_IMAGE_LAYOUT_GENERAL;
        secondBarrier.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        secondBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.image = VK_NULL_HANDLE;
        secondBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        secondBarrier.subresourceRange.baseMipLevel = 0;
        secondBarrier.subresourceRange.levelCount = 1;
        secondBarrier.subresourceRange.baseArrayLayer = 0;
        secondBarrier.subresourceRange.layerCount = 1;
        
        for(unsigned int i=0;i<count;i++)
        {
            std::cout << commandBuffers[i] << std::endl;
        }
        
        for(unsigned int i=0;i<count;i++)
        {
            fistBarrier.image = images[i];
            secondBarrier.image =  images[i];
            std::cout << "before begin commandbuffer " << commandBuffers[i] << std::endl;
            VkResult result = dispatchTable.BeginCommandBuffer(commandBuffers[i], &beginInfo);
            ASSERT_VULKAN(result);
            //1
            std::cout << "before command buffer step 1" << std::endl;
            dispatchTable.CmdBindPipeline(commandBuffers[i], VK_PIPELINE_BIND_POINT_COMPUTE, pipeline);
            dispatchTable.CmdBindDescriptorSets(commandBuffers[i],VK_PIPELINE_BIND_POINT_COMPUTE,layout,0,1,&(descriptorSets[i]),0,nullptr);
            
            std::cout << "before command buffer step 2" << std::endl;
            //2
            dispatchTable.CmdPipelineBarrier(commandBuffers[i],VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,0,0, nullptr,0, nullptr,1, &fistBarrier);
            
            //3
            std::cout << "before command buffer step 3" << std::endl;
            dispatchTable.CmdDispatch(commandBuffers[i],extent.width/8 +1,extent.height/8 +1 ,1);//cas shader has a localgroup size of 8
            
            std::cout << "before command buffer step 4" << std::endl;
            //4
            dispatchTable.CmdPipelineBarrier(commandBuffers[i],VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
            std::cout << "before ending command buffer" << std::endl;
            result = dispatchTable.EndCommandBuffer(commandBuffers[i]);
        }
    }


    void createSemaphores(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, uint32_t count, VkSemaphore* semaphores)
    {
        VkSemaphoreCreateInfo info;
        info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        info.pNext = nullptr;
        info.flags = 0;

        for (uint32_t i = 0; i < count; i++)
            dispatchTable.CreateSemaphore(device, &info, nullptr, &semaphores[i]);
    }

}
