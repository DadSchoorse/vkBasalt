#ifndef DESCRIPTOR_SET_HPP_INCLUDED
#define DESCRIPTOR_SET_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt{
    VkDescriptorPool createDescriptorPool(std::shared_ptr<LogicalDevice> pLogicalDevice, const std::vector<VkDescriptorPoolSize>& poolSizes);

    VkDescriptorSetLayout createUniformBufferDescriptorSetLayout(std::shared_ptr<LogicalDevice> pLogicalDevice);
    VkDescriptorSet writeBufferDescriptorSet(std::shared_ptr<LogicalDevice> pLogicalDevice, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, VkBuffer buffer);
    VkDescriptorSetLayout createImageSamplerDescriptorSetLayout(std::shared_ptr<LogicalDevice> pLogicalDevice, uint32_t count);
    std::vector<VkDescriptorSet> allocateAndWriteImageSamplerDescriptorSets(std::shared_ptr<LogicalDevice> pLogicalDevice, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, std::vector<VkSampler> samplers, std::vector<std::vector<VkImageView>> imageViewsVectors);
}


#endif // DESCRIPTOR_SET_HPP_INCLUDED
