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
    void createStorageImageDescriptorSetLayouts(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const uint32_t& count, VkDescriptorSetLayout* descriptorSetLayouts);
    void createStorageImageDescriptorPool(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const uint32_t& setCount, VkDescriptorPool& descriptorPool);
    void allocateAndWriteStorageDescriptorSets(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkDescriptorPool& descriptorPool, const uint32_t& setCount, const VkDescriptorSetLayout* descriptorSetLayouts,const  VkImageView* imageViews, VkDescriptorSet* descriptorSets);

}


#endif // DESCRIPTOR_SET_HPP_INCLUDED
