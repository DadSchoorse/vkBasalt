#ifndef EFFECT_RESHADE_HPP_INCLUDED
#define EFFECT_RESHADE_HPP_INCLUDED
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
#include "reshade_uniforms.hpp"

#include "../reshade/source/effect_parser.hpp"
#include "../reshade/source/effect_codegen.hpp"
#include "../reshade/source/effect_preprocessor.hpp"

namespace vkBasalt{
    class ReshadeEffect : public Effect
    {
    public:
        ReshadeEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, VkQueue queue, VkCommandPool commandPool, std::string effectName);
        void virtual applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override;
        void virtual updateEffect() override;
        virtual ~ReshadeEffect();
    private:
        VkPhysicalDevice physicalDevice;
        VkLayerInstanceDispatchTable instanceDispatchTable;
        VkDevice device;
        VkLayerDispatchTable dispatchTable;
        std::vector<VkImage> inputImages;
        std::vector<VkImage> outputImages;
        std::vector<VkImageView> outputImageViewsSRGB;
        std::vector<VkImageView> outputImageViewsUNORM;
        std::unordered_map<std::string, std::vector<VkImage>> textureImages;
        std::unordered_map<std::string, std::vector<VkImageView>> textureImageViewsUNORM;
        std::unordered_map<std::string, std::vector<VkImageView>> textureImageViewsSRGB;
        std::unordered_map<std::string, VkFormat> textureFormatsUNORM;
        std::unordered_map<std::string, VkFormat> textureFormatsSRGB;
        std::vector<VkDescriptorSet> inputDescriptorSets;
        std::vector<VkDescriptorSet> outputDescriptorSets;
        std::vector<VkDescriptorSet> backBufferDescriptorSets;
        std::vector<std::vector<VkFramebuffer>> framebuffers;
        VkDescriptorSetLayout uniformDescriptorSetLayout;
        VkDescriptorSetLayout imageSamplerDescriptorSetLayout;
        VkShaderModule shaderModule;
        VkDescriptorPool descriptorPool;
        std::vector<VkRenderPass> renderPasses;
        std::vector<VkRenderPassBeginInfo> renderPassBeginInfos;
        VkPipelineLayout pipelineLayout;
        std::vector<VkPipeline> graphicsPipelines;
        std::vector<bool> switchSamplers;
        VkExtent2D imageExtent;
        std::vector<VkSampler> samplers;
        std::shared_ptr<vkBasalt::Config> pConfig;
        std::string effectName;
        reshadefx::module module;
        std::vector<VkDeviceMemory> textureMemory;
        VkFormat inputOutputFormatUNORM;
        VkFormat inputOutputFormatSRGB;
        VkFormat stencilFormat;
        VkImage stencilImage;
        VkImageView stencilImageView;
        //how often the shader writes to the reshade back buffer
        //we need to flip the "backbuffer" after each write if there is a next one
        int outputWrites = 0;
        std::vector<VkImage> backBufferImages;
        std::vector<VkImageView> backBufferImageViewsUNORM;
        std::vector<VkImageView> backBufferImageViewsSRGB;
        VkBuffer stagingBuffer;
        VkDeviceMemory stagingBufferMemory;
        uint32_t bufferSize;
        VkDescriptorSet bufferDescriptorSet;
        std::vector<std::shared_ptr<ReshadeUniform>> uniforms;
        
        void createReshadeModule();
        VkFormat      convertReshadeFormat(reshadefx::texture_format texFormat);
        VkCompareOp   convertReshadeCompareOp(uint32_t compareOp);
        VkStencilOp   convertReshadeStencilOp(uint32_t stencilOp);
        VkBlendOp     convertReshadeBlendOp(uint32_t blendOp);
        VkBlendFactor convertReshadeBlendFactor(uint32_t blendFactor);
    };
}


#endif // EFFECT_RESHADE_HPP_INCLUDED
