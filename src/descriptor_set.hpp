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
    void createUniformBufferDescriptorSetLayout(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, VkDescriptorSetLayout& descriptorSetLayout);
    void createUniformBufferDescriptorPool(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const uint32_t& setCount, VkDescriptorPool& descriptorPool);
    void writeCasBufferDescriptorSet(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkDescriptorPool& descriptorPool, const VkDescriptorSetLayout& descriptorSetLayout, const VkBuffer& buffer, VkDescriptorSet& descriptorSet);
    void createImageSamplerDescriptorSetLayout(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, VkDescriptorSetLayout& descriptorSetLayout);
    void createImageSamplerDescriptorPool(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const uint32_t& setCount, VkDescriptorPool& descriptorPool);
    void allocateAndWriteImageSamplerDescriptorSets(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkDescriptorPool& descriptorPool, const uint32_t& setCount, const VkDescriptorSetLayout& descriptorSetLayout, const VkSampler& sampler, const  VkImageView* imageViews, VkDescriptorSet* descriptorSets);
}


#endif // DESCRIPTOR_SET_HPP_INCLUDED
