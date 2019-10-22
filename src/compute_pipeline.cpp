#include "compute_pipeline.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    void createComputePipelineLayout(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const uint32_t& descriptorSetLayoutsCount, const VkDescriptorSetLayout* descriptorSetLayouts, VkPipelineLayout& pipelineLayout)
    {   
        VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo;
        pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutCreateInfo.pNext = nullptr;
        pipelineLayoutCreateInfo.flags = 0;
        pipelineLayoutCreateInfo.setLayoutCount = descriptorSetLayoutsCount;
        pipelineLayoutCreateInfo.pSetLayouts = VK_NULL_HANDLE;
        pipelineLayoutCreateInfo.pushConstantRangeCount = 0;
        pipelineLayoutCreateInfo.pPushConstantRanges = nullptr;
        pipelineLayoutCreateInfo.pSetLayouts = descriptorSetLayouts;
        
        VkResult result = dispatchTable.CreatePipelineLayout(device,&pipelineLayoutCreateInfo,nullptr,&pipelineLayout);
        ASSERT_VULKAN(result);
        
    }
    
    
    void createComputePipeline(const VkDevice& device, const VkLayerDispatchTable& dispatchTable,const VkShaderModule& shaderModule,const VkPipelineLayout& pipelineLayout, VkPipeline& pipeline)
    {
        VkPipelineShaderStageCreateInfo computeStageCreateInfo;
        computeStageCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        computeStageCreateInfo.pNext = nullptr;
        computeStageCreateInfo.flags = 0;
        computeStageCreateInfo.stage = VK_SHADER_STAGE_COMPUTE_BIT;
        computeStageCreateInfo.module = shaderModule;
        computeStageCreateInfo.pName = "main";
        computeStageCreateInfo.pSpecializationInfo = nullptr;
        
        
        
        
        VkComputePipelineCreateInfo computePipelineCreateInfo;
        computePipelineCreateInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
        computePipelineCreateInfo.pNext = nullptr;
        computePipelineCreateInfo.flags = 0;
        computePipelineCreateInfo.stage = computeStageCreateInfo;
        computePipelineCreateInfo.layout = VK_NULL_HANDLE;
        computePipelineCreateInfo.basePipelineHandle = 0;//TODO
        computePipelineCreateInfo.basePipelineIndex = 0;//TODO
        
        
        
        computePipelineCreateInfo.layout = pipelineLayout;
        VkResult result = dispatchTable.CreateComputePipelines(device,VK_NULL_HANDLE,1,&computePipelineCreateInfo,nullptr,&pipeline);
        ASSERT_VULKAN(result);
    }
}
