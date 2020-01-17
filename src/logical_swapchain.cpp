#include "logical_swapchain.hpp"

namespace vkBasalt
{
    void LogicalSwapchain::destroy()
    {
        if(imageCount > 0)
        {
            effects.clear();
            
            logicalDevice.vkd.FreeCommandBuffers(logicalDevice.device, logicalDevice.commandPool, imageCount, commandBuffers.data());
            std::cout << "after free commandbuffer" << std::endl;
            
            logicalDevice.vkd.FreeMemory(logicalDevice.device, fakeImageMemory, nullptr);
            
            for(uint32_t i = 0; i < fakeImages.size(); i++)
            {
                logicalDevice.vkd.DestroyImage(logicalDevice.device, fakeImages[i], nullptr);
            }
            
            for(unsigned int i = 0; i < imageCount; i++)
            {
                logicalDevice.vkd.DestroySemaphore(logicalDevice.device, semaphores[i], nullptr);
            }
            std::cout << "after DestroySemaphore" << std::endl;
        }
    }
}
