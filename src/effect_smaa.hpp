#ifndef EFFECT_SMAA_HPP_INCLUDED
#define EFFECT_SMAA_HPP_INCLUDED
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

namespace vkBasalt{
    class SmaaEffect : public Effect
    {
    public:
        SmaaEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, VkQueue queue, VkCommandPool commandPool);
        void applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override; 
        ~SmaaEffect();
    private:
        VkPhysicalDevice physicalDevice;
        VkLayerInstanceDispatchTable instanceDispatchTable;
        VkDevice device;
        VkLayerDispatchTable dispatchTable;
        std::vector<VkImage> inputImages;
        std::vector<VkImage> edgeImages;
        std::vector<VkImage> blendImages;
        std::vector<VkImage> outputImages;
        std::vector<VkImageView> inputImageViews;
        std::vector<VkImageView> edgeImageViews;
        std::vector<VkImageView> blendImageViews;
        std::vector<VkImageView> outputImageViews;
        std::vector<VkDescriptorSet> imageDescriptorSets;
        std::vector<VkFramebuffer> edgeFramebuffers;
        std::vector<VkFramebuffer> blendFramebuffers;
        std::vector<VkFramebuffer> neignborFramebuffers;
        VkImage areaImage;
        VkImage searchImage;
        VkImageView areaImageView;
        VkImageView searchImageView;
        VkDescriptorSetLayout imageSamplerDescriptorSetLayout;
        VkDescriptorPool descriptorPool;
        VkShaderModule edgeVertexModule;
        VkShaderModule edgeFragmentModule;
        VkShaderModule blendVertexModule;
        VkShaderModule blendFragmentModule;
        VkShaderModule neighborVertexModule;
        VkShaderModule neignborFragmentModule;
        VkRenderPass renderPass;
        VkRenderPass unormRenderPass;
        VkPipelineLayout pipelineLayout;
        VkPipeline edgePipeline;
        VkPipeline blendPipeline;
        VkPipeline neighborPipeline;
        VkExtent2D imageExtent;
        VkFormat format;
        VkDeviceMemory imageMemory;
        VkDeviceMemory areaMemory;
        VkDeviceMemory searchMemory;
        VkSampler sampler;
        std::shared_ptr<vkBasalt::Config> pConfig;
    };
}


#endif // EFFECT_SMAA_HPP_INCLUDED
