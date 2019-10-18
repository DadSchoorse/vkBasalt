#ifndef COMPUTE_PIPELINE_HPP_INCLUDED
#define COMPUTE_PIPELINE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
    void createComputePipelineLayout(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkDescriptorSetLayout& descriptorSetLayout, VkPipelineLayout& pipelineLayout);
    void createComputePipeline(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const VkShaderModule& shaderModule,const VkPipelineLayout& pipelineLayout, VkPipeline& pipeline);

}


#endif // COMPUTE_PIPELINE_HPP_INCLUDED
