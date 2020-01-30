#ifndef EFFECT_SIMPLE_HPP_INCLUDED
#define EFFECT_SIMPLE_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

#include "vulkan_include.hpp"

#include "effect.hpp"
#include "config.hpp"

#include "logical_device.hpp"

namespace vkBasalt{
    class SimpleEffect : public Effect
    {
    public:
        SimpleEffect();
        void virtual applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override;
        virtual ~SimpleEffect();
    protected:
        std::shared_ptr<LogicalDevice> pLogicalDevice;
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
        std::vector<char> vertexCode;
        std::vector<char> fragmentCode;
        VkSpecializationInfo* pVertexSpecInfo;
        VkSpecializationInfo* pFragmentSpecInfo;
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts;//subclasses can put DescriptorSets in here, but the first one will be the input image descriptorSet
        
        void init(std::shared_ptr<LogicalDevice> pLogicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig);
    };
}


#endif // EFFECT_SIMPLE_HPP_INCLUDED
