#ifndef DESCRIPTOR_SET_HPP_INCLUDED
#define DESCRIPTOR_SET_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt{
    VkDescriptorPool createDescriptorPool(LogicalDevice logicalDevice, const std::vector<VkDescriptorPoolSize>& poolSizes);

    VkDescriptorSetLayout createUniformBufferDescriptorSetLayout(LogicalDevice logicalDevice);
    VkDescriptorSet writeBufferDescriptorSet(LogicalDevice logicalDevice, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, VkBuffer buffer);
    VkDescriptorSetLayout createImageSamplerDescriptorSetLayout(LogicalDevice logicalDevice, uint32_t count);
    std::vector<VkDescriptorSet> allocateAndWriteImageSamplerDescriptorSets(LogicalDevice logicalDevice, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, std::vector<VkSampler> samplers, std::vector<std::vector<VkImageView>> imageViewsVectors);
}


#endif // DESCRIPTOR_SET_HPP_INCLUDED
