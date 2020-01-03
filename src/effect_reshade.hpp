#ifndef EFFECT_RESHADE_HPP_INCLUDED
#define EFFECT_RESHADE_HPP_INCLUDED
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

#include "../reshade/source/effect_parser.hpp"
#include "../reshade/source/effect_codegen.hpp"
#include "../reshade/source/effect_preprocessor.hpp"

namespace vkBasalt{
    class ReshadeEffect : public Effect
    {
    public:
        ReshadeEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, VkQueue queue, VkCommandPool commandPool, std::string effectName);
        void virtual applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override;
        virtual ~ReshadeEffect();
    private:
        VkPhysicalDevice physicalDevice;
        VkLayerInstanceDispatchTable instanceDispatchTable;
        VkDevice device;
        VkLayerDispatchTable dispatchTable;
        std::vector<VkImage> inputImages;
        std::vector<VkImage> outputImages;
        std::vector<VkImageView> outputImageViews;
        std::unordered_map<std::string, std::vector<VkImage>> textureImages;
        std::unordered_map<std::string, std::vector<VkImageView>> textureImageViews;
        std::unordered_map<std::string, VkFormat> textureFormats;
        std::vector<VkDescriptorSet> imageDescriptorSets;
        std::vector<std::vector<VkFramebuffer>> framebuffers;
        VkDescriptorSetLayout emptyDescriptorSetLayout;
        VkDescriptorSetLayout imageSamplerDescriptorSetLayout;
        VkShaderModule shaderModule;
        VkDescriptorPool descriptorPool;
        std::vector<VkRenderPass> renderPasses;
        std::vector<VkRenderPassBeginInfo> renderPassBeginInfos;
        VkPipelineLayout pipelineLayout;
        std::vector<VkPipeline> graphicsPipelines;
        VkExtent2D imageExtent;
        std::vector<VkSampler> samplers;
        std::shared_ptr<vkBasalt::Config> pConfig;
        std::string effectName;
        reshadefx::module module;
        std::vector<VkDeviceMemory> textureMemory;
        VkFormat inputOutputFormat;
        
        void createReshadeModule();
        VkFormat      convertReshadeFormat(reshadefx::texture_format texFormat);
        VkCompareOp   convertReshadeCompareOp(uint32_t compareOp);
        VkStencilOp   convertReshadeStencilOp(uint32_t stencilOp);
        VkBlendOp     convertReshadeBlendOp(uint32_t blendOp);
        VkBlendFactor convertReshadeBlendFactor(uint32_t blendFactor);
    };
}


#endif // EFFECT_RESHADE_HPP_INCLUDED
