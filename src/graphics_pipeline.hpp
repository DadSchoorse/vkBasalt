#ifndef GRAPHICS_PIPELINE_HPP_INCLUDED
#define GRAPHICS_PIPELINE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "vulkan_include.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    VkPipelineLayout createGraphicsPipelineLayout(std::shared_ptr<LogicalDevice> pLogicalDevice, std::vector<VkDescriptorSetLayout> descriptorSetLayouts);
    VkPipeline createGraphicsPipeline(std::shared_ptr<LogicalDevice> pLogicalDevice,
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
