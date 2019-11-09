#ifndef EFFECT_FXAA_HPP_INCLUDED
#define EFFECT_FXAA_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

#include "effect.hpp"
#include "config.hpp"

namespace vkBasalt{
    class FxaaEffect : public Effect
    {
    public:
        FxaaEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, Config config);
        void applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override; 
    private:
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
        VkDescriptorSetLayout uniformBufferDescriptorSetLayout;
        VkDescriptorPool descriptorPool;
        VkDescriptorSet uniformBufferDescriptorSet;
        VkShaderModule vertexModule;
        VkShaderModule fragmentModule;
        VkRenderPass renderPass;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
        VkExtent2D imageExtent;
        VkFormat format;
        VkBuffer uniformBuffer;
        VkDeviceMemory uniformBufferMemory;
        VkSampler sampler;
        Config config;
    };
}


#endif // EFFECT_FXAA_HPP_INCLUDED
