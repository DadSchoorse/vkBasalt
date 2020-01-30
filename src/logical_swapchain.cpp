#include "logical_swapchain.hpp"

namespace vkBasalt
{
    void LogicalSwapchain::destroy()
    {
        if(imageCount > 0)
        {
            effects.clear();
            
            pLogicalDevice->vkd.FreeCommandBuffers(pLogicalDevice->device, pLogicalDevice->commandPool, imageCount, commandBuffers.data());
            std::cout << "after free commandbuffer" << std::endl;
            
            pLogicalDevice->vkd.FreeMemory(pLogicalDevice->device, fakeImageMemory, nullptr);
            
            for(uint32_t i = 0; i < fakeImages.size(); i++)
            {
                pLogicalDevice->vkd.DestroyImage(pLogicalDevice->device, fakeImages[i], nullptr);
            }
            
            for(unsigned int i = 0; i < imageCount; i++)
            {
                pLogicalDevice->vkd.DestroySemaphore(pLogicalDevice->device, semaphores[i], nullptr);
            }
            std::cout << "after DestroySemaphore" << std::endl;
        }
    }
}
