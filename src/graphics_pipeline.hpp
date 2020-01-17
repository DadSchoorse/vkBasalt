#ifndef GRAPHICS_PIPELINE_HPP_INCLUDED
#define GRAPHICS_PIPELINE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan_include.hpp"

namespace vkBasalt
{
    VkPipelineLayout createGraphicsPipelineLayout(VkDevice device, VkLayerDispatchTable dispatchTable, std::vector<VkDescriptorSetLayout> descriptorSetLayouts);
    VkPipeline createGraphicsPipeline(VkDevice device,
                                      VkLayerDispatchTable dispatchTable,
                                      VkShaderModule vertexModule,
                                      VkSpecializationInfo* vertexSpecializationInfo,
                                      std::string vertexEntryPoint,
                                      VkShaderModule fragmentModule,
                                      VkSpecializationInfo* fragmentSpecializationInfo,
                                      std::string fragmentEntryPoint,
                                      VkExtent2D extent,
                                      VkRenderPass renderPass,
                                      VkPipelineLayout pipelineLayout,
                                      bool flip = false);

}


#endif // GRAPHICS_PIPELINE_HPP_INCLUDED
