#ifndef EFFECT_SIMPLE_HPP_INCLUDED
#define EFFECT_SIMPLE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

#include "effect.hpp"
#include "config.hpp"

namespace vkBasalt{
    struct SimpleShaderInfo{
        std::vector<char> vertexCode;
        std::vector<char> fragmentCode;
        VkSpecializationInfo* pVertexSpecInfo;
        VkSpecializationInfo* pFragmentSpecInfo;
    };
    class SimpleEffect : public Effect
    {
    public:
        SimpleEffect();
        void applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override;
        ~SimpleEffect();
    protected:
        VkPhysicalDevice physicalDevice;
        VkLayerInstanceDispatchTable instanceDispatchTable;
        VkDevice device;
        VkLayerDispatchTable dispatchTable;
        std::vector<VkImage> inputImages;
        std::vector<VkImage> outputImages;
        std::vector<VkImageView> inputImageViews;
        std::vector<VkImageView> outputImageViews;
        std::vector<VkDescriptorSet> imageDescriptorSets;
        std::vector<VkFramebuffer> framebuffers;
        VkDescriptorSetLayout imageSamplerDescriptorSetLayout;
        VkDescriptorPool descriptorPool;
        VkShaderModule vertexModule;
        VkShaderModule fragmentModule;
        VkRenderPass renderPass;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
        VkExtent2D imageExtent;
        VkFormat format;
        VkSampler sampler;
        std::shared_ptr<vkBasalt::Config> pConfig;
        SimpleShaderInfo shaderInfo;
        
        void init(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig);
    };
}


#endif // EFFECT_SIMPLE_HPP_INCLUDED
