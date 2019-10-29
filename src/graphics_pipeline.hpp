#ifndef GRAPHICS_PIPELINE_HPP_INCLUDED
#define GRAPHICS_PIPELINE_HPP_INCLUDED
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
    void createGraphicsPipelineLayout(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const uint32_t& descriptorSetLayoutsCount, const VkDescriptorSetLayout* descriptorSetLayouts, VkPipelineLayout& pipelineLayout);
    void createGraphicsPipeline(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const VkShaderModule& vertexModule,const VkShaderModule& fragmentModule, VkExtent2D extent, VkRenderPass renderPass,const VkPipelineLayout& pipelineLayout, VkPipeline& pipeline);

}


#endif // GRAPHICS_PIPELINE_HPP_INCLUDED
