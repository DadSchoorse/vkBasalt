#ifndef DESCRIPTOR_SET_HPP_INCLUDED
#define DESCRIPTOR_SET_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
    VkDescriptorPool createDescriptorPool(VkDevice device, VkLayerDispatchTable dispatchTable, const std::vector<VkDescriptorPoolSize>& poolSizes);

    VkDescriptorSetLayout createUniformBufferDescriptorSetLayout(VkDevice device, VkLayerDispatchTable dispatchTable);
    VkDescriptorSet writeCasBufferDescriptorSet(VkDevice device, VkLayerDispatchTable dispatchTable, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, VkBuffer buffer);
    VkDescriptorSetLayout createImageSamplerDescriptorSetLayout(VkDevice device, VkLayerDispatchTable dispatchTable, uint32_t count);
    std::vector<VkDescriptorSet> allocateAndWriteImageSamplerDescriptorSets(VkDevice device, VkLayerDispatchTable dispatchTable, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, std::vector<VkSampler> samplers, std::vector<std::vector<VkImageView>> imageViewsVectors);
}


#endif // DESCRIPTOR_SET_HPP_INCLUDED
