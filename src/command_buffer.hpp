#ifndef COMMAND_BUFFER_HPP_INCLUDED
#define COMMAND_BUFFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"
namespace vkBasalt
{
    
    std::vector<VkCommandBuffer> allocateCommandBuffer(VkDevice device, VkLayerDispatchTable dispatchTable, VkCommandPool commandPool, uint32_t count);
    void writeCASCommandBuffers(VkDevice device, VkLayerDispatchTable dispatchTable, VkPipeline pipeline, VkPipelineLayout layout, VkExtent2D extent, VkDescriptorSet uniformBufferDescriptorSet, VkRenderPass renderPass, std::vector<VkImage> images, std::vector<VkDescriptorSet> descriptorSets, std::vector<VkFramebuffer> framebuffers, std::vector<VkCommandBuffer> commandBuffers);
    std::vector<VkSemaphore> createSemaphores(VkDevice device, VkLayerDispatchTable dispatchTable, uint32_t count);
}

#endif // COMMAND_BUFFER_HPP_INCLUDED
