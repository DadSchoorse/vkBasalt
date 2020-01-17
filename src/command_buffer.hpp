#ifndef COMMAND_BUFFER_HPP_INCLUDED
#define COMMAND_BUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "effect.hpp"
namespace vkBasalt
{
    
    std::vector<VkCommandBuffer> allocateCommandBuffer(VkDevice device, VkLayerDispatchTable dispatchTable, VkCommandPool commandPool, uint32_t count);
    void writeCommandBuffers(VkDevice device, VkLayerDispatchTable dispatchTable, std::vector<std::shared_ptr<vkBasalt::Effect>> effects, std::vector<VkCommandBuffer> commandBuffers);
    std::vector<VkSemaphore> createSemaphores(VkDevice device, VkLayerDispatchTable dispatchTable, uint32_t count);
}

#endif // COMMAND_BUFFER_HPP_INCLUDED
