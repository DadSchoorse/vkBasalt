#include "graphics_pipeline.hpp"

namespace vkBasalt
{
    VkPipelineLayout createGraphicsPipelineLayout(LogicalDevice* pLogicalDevice, std::vector<VkDescriptorSetLayout> descriptorSetLayouts)
    {
        VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo;
        pipelineLayoutCreateInfo.sType                  = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutCreateInfo.pNext                  = nullptr;
        pipelineLayoutCreateInfo.flags                  = 0;
        pipelineLayoutCreateInfo.setLayoutCount         = descriptorSetLayouts.size();
        pipelineLayoutCreateInfo.pSetLayouts            = descriptorSetLayouts.data();
        pipelineLayoutCreateInfo.pushConstantRangeCount = 0;
        pipelineLayoutCreateInfo.pPushConstantRanges    = nullptr;

        VkPipelineLayout pipelineLayout;
        VkResult result = pLogicalDevice->vkd.CreatePipelineLayout(pLogicalDevice->device, &pipelineLayoutCreateInfo, nullptr, &pipelineLayout);
        ASSERT_VULKAN(result);
        return pipelineLayout;
    }

    VkPipeline createGraphicsPipeline(LogicalDevice*        pLogicalDevice,
                                      VkShaderModule        vertexModule,
                                      VkSpecializationInfo* vertexSpecializationInfo,
                                      std::string           vertexEntryPoint,
                                      VkShaderModule        fragmentModule,
                                      VkSpecializationInfo* fragmentSpecializationInfo,
                                      std::string           fragmentEntryPoint,
                                      VkExtent2D            extent,
                                      VkRenderPass          renderPass,
                                      VkPipelineLayout      pipelineLayout,
                                      bool                  flip)
    {
        VkResult result;

        VkPipeline pipeline;

        VkPipelineShaderStageCreateInfo shaderStageCreateInfoVert;
        shaderStageCreateInfoVert.sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        shaderStageCreateInfoVert.pNext               = nullptr;
        shaderStageCreateInfoVert.flags               = 0;
        shaderStageCreateInfoVert.stage               = VK_SHADER_STAGE_VERTEX_BIT;
        shaderStageCreateInfoVert.module              = vertexModule;
        shaderStageCreateInfoVert.pName               = vertexEntryPoint.c_str();
        shaderStageCreateInfoVert.pSpecializationInfo = vertexSpecializationInfo;

        VkPipelineShaderStageCreateInfo shaderStageCreateInfoFrag;
        shaderStageCreateInfoFrag.sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        shaderStageCreateInfoFrag.pNext               = nullptr;
        shaderStageCreateInfoFrag.flags               = 0;
        shaderStageCreateInfoFrag.stage               = VK_SHADER_STAGE_FRAGMENT_BIT;
        shaderStageCreateInfoFrag.module              = fragmentModule;
        shaderStageCreateInfoFrag.pName               = fragmentEntryPoint.c_str();
        shaderStageCreateInfoFrag.pSpecializationInfo = fragmentSpecializationInfo;

        VkPipelineShaderStageCreateInfo shaderStages[] = {shaderStageCreateInfoVert, shaderStageCreateInfoFrag};

        VkPipelineVertexInputStateCreateInfo vertexInputCreateInfo;
        vertexInputCreateInfo.sType                           = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        vertexInputCreateInfo.pNext                           = nullptr;
        vertexInputCreateInfo.flags                           = 0;
        vertexInputCreateInfo.vertexBindingDescriptionCount   = 0;
        vertexInputCreateInfo.pVertexBindingDescriptions      = nullptr;
        vertexInputCreateInfo.vertexAttributeDescriptionCount = 0;
        vertexInputCreateInfo.pVertexAttributeDescriptions    = nullptr;

        VkPipelineInputAssemblyStateCreateInfo inputAssemblyCreateInfo;
        inputAssemblyCreateInfo.sType                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
        inputAssemblyCreateInfo.pNext                  = nullptr;
        inputAssemblyCreateInfo.flags                  = 0;
        inputAssemblyCreateInfo.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
        inputAssemblyCreateInfo.primitiveRestartEnable = VK_FALSE;

        VkViewport viewport;
        viewport.x        = 0.0f;
        viewport.y        = flip ? static_cast<float>(extent.height) : 0.0f;
        viewport.width    = static_cast<float>(extent.width);
        viewport.height   = flip ? -static_cast<float>(extent.height) : static_cast<float>(extent.height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;

        VkRect2D scissor;
        scissor.offset = {0, 0};
        scissor.extent = {extent.width, extent.height};

        VkPipelineViewportStateCreateInfo viewportStateCreateInfo;
        viewportStateCreateInfo.sType         = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
        viewportStateCreateInfo.pNext         = nullptr;
        viewportStateCreateInfo.flags         = 0;
        viewportStateCreateInfo.viewportCount = 1;
        viewportStateCreateInfo.pViewports    = &viewport;
        viewportStateCreateInfo.scissorCount  = 1;
        viewportStateCreateInfo.pScissors     = &scissor;

        VkPipelineRasterizationStateCreateInfo rasterizationCreateInfo;
        rasterizationCreateInfo.sType                   = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
        rasterizationCreateInfo.pNext                   = nullptr;
        rasterizationCreateInfo.flags                   = 0;
        rasterizationCreateInfo.depthClampEnable        = VK_FALSE;
        rasterizationCreateInfo.rasterizerDiscardEnable = VK_FALSE;
        rasterizationCreateInfo.polygonMode             = VK_POLYGON_MODE_FILL;
        rasterizationCreateInfo.cullMode                = VK_CULL_MODE_NONE;
        rasterizationCreateInfo.frontFace               = VK_FRONT_FACE_COUNTER_CLOCKWISE;
        rasterizationCreateInfo.depthBiasEnable         = VK_FALSE;
        rasterizationCreateInfo.depthBiasConstantFactor = 0.0f;
        rasterizationCreateInfo.depthBiasClamp          = 0.0f;
        rasterizationCreateInfo.depthBiasSlopeFactor    = 0.0f;
        rasterizationCreateInfo.lineWidth               = 1.0f;

        VkPipelineMultisampleStateCreateInfo multisampleCreateInfo;
        multisampleCreateInfo.sType                 = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
        multisampleCreateInfo.pNext                 = nullptr;
        multisampleCreateInfo.flags                 = 0;
        multisampleCreateInfo.rasterizationSamples  = VK_SAMPLE_COUNT_1_BIT;
        multisampleCreateInfo.sampleShadingEnable   = VK_FALSE;
        multisampleCreateInfo.minSampleShading      = 1.0f;
        multisampleCreateInfo.pSampleMask           = nullptr;
        multisampleCreateInfo.alphaToCoverageEnable = VK_FALSE;
        multisampleCreateInfo.alphaToOneEnable      = VK_FALSE;

        // do not use blending, we only have one image and that should not be modified
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        colorBlendAttachment.blendEnable         = VK_FALSE;
        colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
        colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
        colorBlendAttachment.colorBlendOp        = VK_BLEND_OP_ADD;
        colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
        colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
        colorBlendAttachment.alphaBlendOp        = VK_BLEND_OP_ADD;
        colorBlendAttachment.colorWriteMask =
            VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;

        VkPipelineColorBlendStateCreateInfo colorBlendCreateInfo;
        colorBlendCreateInfo.sType             = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
        colorBlendCreateInfo.pNext             = nullptr;
        colorBlendCreateInfo.flags             = 0;
        colorBlendCreateInfo.logicOpEnable     = VK_FALSE;
        colorBlendCreateInfo.logicOp           = VK_LOGIC_OP_NO_OP;
        colorBlendCreateInfo.attachmentCount   = 1;
        colorBlendCreateInfo.pAttachments      = &colorBlendAttachment;
        colorBlendCreateInfo.blendConstants[0] = 0.0f;
        colorBlendCreateInfo.blendConstants[1] = 0.0f;
        colorBlendCreateInfo.blendConstants[2] = 0.0f;
        colorBlendCreateInfo.blendConstants[3] = 0.0f;

        VkDynamicState dynamicStates[] = {};

        VkPipelineDynamicStateCreateInfo dynamicStateCreateInfo;
        dynamicStateCreateInfo.sType             = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
        dynamicStateCreateInfo.pNext             = nullptr;
        dynamicStateCreateInfo.flags             = 0;
        dynamicStateCreateInfo.dynamicStateCount = 0;
        dynamicStateCreateInfo.pDynamicStates    = dynamicStates;

        VkGraphicsPipelineCreateInfo pipelineCreateInfo;
        pipelineCreateInfo.sType               = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
        pipelineCreateInfo.pNext               = nullptr;
        pipelineCreateInfo.flags               = 0;
        pipelineCreateInfo.stageCount          = 2;
        pipelineCreateInfo.pStages             = shaderStages;
        pipelineCreateInfo.pVertexInputState   = &vertexInputCreateInfo;
        pipelineCreateInfo.pInputAssemblyState = &inputAssemblyCreateInfo;
        pipelineCreateInfo.pTessellationState  = nullptr;
        pipelineCreateInfo.pViewportState      = &viewportStateCreateInfo;
        pipelineCreateInfo.pRasterizationState = &rasterizationCreateInfo;
        pipelineCreateInfo.pMultisampleState   = &multisampleCreateInfo;
        pipelineCreateInfo.pDepthStencilState  = nullptr;
        pipelineCreateInfo.pColorBlendState    = &colorBlendCreateInfo;
        pipelineCreateInfo.pDynamicState       = &dynamicStateCreateInfo;
        pipelineCreateInfo.layout              = pipelineLayout;
        pipelineCreateInfo.renderPass          = renderPass;
        pipelineCreateInfo.subpass             = 0;
        pipelineCreateInfo.basePipelineHandle  = VK_NULL_HANDLE;
        pipelineCreateInfo.basePipelineIndex   = -1;

        result = pLogicalDevice->vkd.CreateGraphicsPipelines(pLogicalDevice->device, VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &pipeline);
        ASSERT_VULKAN(result);

        return pipeline;
    }
} // namespace vkBasalt
