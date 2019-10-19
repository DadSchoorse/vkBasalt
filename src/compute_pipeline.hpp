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
    void createComputePipelineLayouts(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const uint32_t& count, const VkDescriptorSetLayout* descriptorSetLayouts, VkPipelineLayout* pipelineLayouts);
    void createComputePipelines(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const VkShaderModule& shaderModule,const uint32_t& count,const VkPipelineLayout* pipelineLayouts, VkPipeline* pipelines);

}


#endif // COMPUTE_PIPELINE_HPP_INCLUDED
