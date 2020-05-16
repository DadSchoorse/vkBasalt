#include "effect_smaa.hpp"

#include <cstring>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"
#include "image.hpp"
#include "util.hpp"

#include "AreaTex.h"
#include "SearchTex.h"
#include "shader_sources.hpp"

namespace vkBasalt
{
    SmaaEffect::SmaaEffect(LogicalDevice*       pLogicalDevice,
                           VkFormat             format,
                           VkExtent2D           imageExtent,
                           std::vector<VkImage> inputImages,
                           std::vector<VkImage> outputImages,
                           Config*              pConfig)
    {
        Logger::debug("in creating SmaaEffect");

        this->pLogicalDevice = pLogicalDevice;
        this->format         = format;
        this->imageExtent    = imageExtent;
        this->inputImages    = inputImages;
        this->outputImages   = outputImages;
        this->pConfig        = pConfig;

        // create Images for the first and second pass at once -> less memory fragmentation
        std::vector<VkImage> edgeAndBlendImages = createImages(pLogicalDevice,
                                                               inputImages.size() * 2,
                                                               {imageExtent.width, imageExtent.height, 1},
                                                               VK_FORMAT_B8G8R8A8_UNORM, // TODO search for format and save it
                                                               VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                                               VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                                               imageMemory);

        edgeImages  = std::vector<VkImage>(edgeAndBlendImages.begin(), edgeAndBlendImages.begin() + edgeAndBlendImages.size() / 2);
        blendImages = std::vector<VkImage>(edgeAndBlendImages.begin() + edgeAndBlendImages.size() / 2, edgeAndBlendImages.end());

        inputImageViews = createImageViews(pLogicalDevice, format, inputImages);
        Logger::debug("created input ImageViews");
        edgeImageViews = createImageViews(pLogicalDevice, VK_FORMAT_B8G8R8A8_UNORM, edgeImages);
        Logger::debug("created edge  ImageViews");
        blendImageViews = createImageViews(pLogicalDevice, VK_FORMAT_B8G8R8A8_UNORM, blendImages);
        Logger::debug("created blend ImageViews");
        outputImageViews = createImageViews(pLogicalDevice, format, outputImages);
        Logger::debug("created output ImageViews");
        sampler = createSampler(pLogicalDevice);
        Logger::debug("created sampler");

        VkExtent3D areaImageExtent = {AREATEX_WIDTH, AREATEX_HEIGHT, 1};

        areaImage = createImages(pLogicalDevice,
                                 1,
                                 areaImageExtent,
                                 VK_FORMAT_R8G8_UNORM, // TODO search for format and save it
                                 VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                 VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                 areaMemory)[0];

        VkExtent3D searchImageExtent = {SEARCHTEX_WIDTH, SEARCHTEX_HEIGHT, 1};

        searchImage = createImages(pLogicalDevice,
                                   1,
                                   searchImageExtent,
                                   VK_FORMAT_R8_UNORM, // TODO search for format and save it
                                   VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   searchMemory)[0];

        uploadToImage(pLogicalDevice, areaImage, areaImageExtent, AREATEX_SIZE, areaTexBytes);

        uploadToImage(pLogicalDevice, searchImage, searchImageExtent, SEARCHTEX_SIZE, searchTexBytes);

        areaImageView = createImageViews(pLogicalDevice, VK_FORMAT_R8G8_UNORM, std::vector<VkImage>(1, areaImage))[0];
        Logger::debug("after creating area ImageView");
        searchImageView = createImageViews(pLogicalDevice, VK_FORMAT_R8_UNORM, std::vector<VkImage>(1, searchImage))[0];
        Logger::debug("created search ImageView");

        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(pLogicalDevice, 5);
        Logger::debug("created descriptorSetLayouts");

        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type            = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size() * 5;

        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};

        descriptorPool = createDescriptorPool(pLogicalDevice, poolSizes);
        Logger::debug("created descriptorPool");

        // get config options
        struct SmaaOptions
        {
            float   screenWidth;
            float   screenHeight;
            float   reverseScreenWidth;
            float   reverseScreenHeight;
            float   threshold;
            int32_t maxSearchSteps;
            int32_t maxSearchStepsDiag;
            int32_t cornerRounding;
        };

        SmaaOptions smaaOptions;
        smaaOptions.threshold          = pConfig->getOption<float>("smaaThreshold", 0.05f);
        smaaOptions.maxSearchSteps     = pConfig->getOption<int32_t>("smaaMaxSearchSteps", 32);
        smaaOptions.maxSearchStepsDiag = pConfig->getOption<int32_t>("smaaMaxSearchStepsDiag", 16);
        smaaOptions.cornerRounding     = pConfig->getOption<int32_t>("smaaCornerRounding", 25);

        createShaderModule(pLogicalDevice, smaa_edge_vert, &edgeVertexModule);

        bool useColor = pConfig->getOption<std::string>("smaaEdgeDetection", "luma") == "color";

        auto shaderCode = useColor ? smaa_edge_color_frag : smaa_edge_luma_frag;
        createShaderModule(pLogicalDevice, shaderCode, &edgeFragmentModule);

        createShaderModule(pLogicalDevice, smaa_blend_vert, &blendVertexModule);

        createShaderModule(pLogicalDevice, smaa_blend_frag, &blendFragmentModule);

        createShaderModule(pLogicalDevice, smaa_neighbor_vert, &neighborVertexModule);

        createShaderModule(pLogicalDevice, smaa_neighbor_frag, &neignborFragmentModule);

        renderPass      = createRenderPass(pLogicalDevice, format);
        unormRenderPass = createRenderPass(pLogicalDevice, VK_FORMAT_B8G8R8A8_UNORM);

        std::vector<VkDescriptorSetLayout> descriptorSetLayouts = {imageSamplerDescriptorSetLayout};
        pipelineLayout                                          = createGraphicsPipelineLayout(pLogicalDevice, descriptorSetLayouts);

        std::vector<VkSpecializationMapEntry> specMapEntrys(8);
        for (uint32_t i = 0; i < specMapEntrys.size(); i++)
        {
            specMapEntrys[i].constantID = i;
            specMapEntrys[i].offset     = sizeof(float) * i; // TODO not clean to assume that sizeof(int32_t) == sizeof(float)
            specMapEntrys[i].size       = sizeof(float);
        }
        smaaOptions.screenWidth = (float) imageExtent.width, smaaOptions.screenHeight = (float) imageExtent.height,
        smaaOptions.reverseScreenWidth  = 1.0f / imageExtent.width;
        smaaOptions.reverseScreenHeight = 1.0f / imageExtent.height;

        VkSpecializationInfo specializationInfo;
        specializationInfo.mapEntryCount = specMapEntrys.size();
        specializationInfo.pMapEntries   = specMapEntrys.data();
        specializationInfo.dataSize      = sizeof(smaaOptions);
        specializationInfo.pData         = &smaaOptions;

        edgePipeline = createGraphicsPipeline(pLogicalDevice,
                                              edgeVertexModule,
                                              &specializationInfo,
                                              "main",
                                              edgeFragmentModule,
                                              &specializationInfo,
                                              "main",
                                              imageExtent,
                                              unormRenderPass,
                                              pipelineLayout);

        blendPipeline = createGraphicsPipeline(pLogicalDevice,
                                               blendVertexModule,
                                               &specializationInfo,
                                               "main",
                                               blendFragmentModule,
                                               &specializationInfo,
                                               "main",
                                               imageExtent,
                                               unormRenderPass,
                                               pipelineLayout);

        neighborPipeline = createGraphicsPipeline(pLogicalDevice,
                                                  neighborVertexModule,
                                                  &specializationInfo,
                                                  "main",
                                                  neignborFragmentModule,
                                                  &specializationInfo,
                                                  "main",
                                                  imageExtent,
                                                  renderPass,
                                                  pipelineLayout);

        std::vector<std::vector<VkImageView>> imageViewsVector = {inputImageViews,
                                                                  edgeImageViews,
                                                                  std::vector<VkImageView>(inputImageViews.size(), areaImageView),
                                                                  std::vector<VkImageView>(inputImageViews.size(), searchImageView),
                                                                  blendImageViews};

        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(pLogicalDevice,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         std::vector<VkSampler>(imageViewsVector.size(), sampler),
                                                                         imageViewsVector);

        edgeFramebuffers     = createFramebuffers(pLogicalDevice, unormRenderPass, imageExtent, {edgeImageViews});
        blendFramebuffers    = createFramebuffers(pLogicalDevice, unormRenderPass, imageExtent, {blendImageViews});
        neignborFramebuffers = createFramebuffers(pLogicalDevice, renderPass, imageExtent, {outputImageViews});
    }
    void SmaaEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        Logger::debug("applying smaa effect to cb " + convertToString(commandBuffer));
        // Used to make the Image accessable by the shader
        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext               = nullptr;
        memoryBarrier.srcAccessMask       = VK_ACCESS_MEMORY_WRITE_BIT;
        memoryBarrier.dstAccessMask       = VK_ACCESS_SHADER_READ_BIT;
        memoryBarrier.oldLayout           = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        memoryBarrier.newLayout           = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.image               = inputImages[imageIndex];

        memoryBarrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        memoryBarrier.subresourceRange.baseMipLevel   = 0;
        memoryBarrier.subresourceRange.levelCount     = 1;
        memoryBarrier.subresourceRange.baseArrayLayer = 0;
        memoryBarrier.subresourceRange.layerCount     = 1;

        // Reverses the first Barrier
        VkImageMemoryBarrier secondBarrier;
        secondBarrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        secondBarrier.pNext               = nullptr;
        secondBarrier.srcAccessMask       = VK_ACCESS_SHADER_READ_BIT;
        secondBarrier.dstAccessMask       = 0;
        secondBarrier.oldLayout           = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        secondBarrier.newLayout           = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        secondBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.image               = inputImages[imageIndex];

        secondBarrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        secondBarrier.subresourceRange.baseMipLevel   = 0;
        secondBarrier.subresourceRange.levelCount     = 1;
        secondBarrier.subresourceRange.baseArrayLayer = 0;
        secondBarrier.subresourceRange.layerCount     = 1;

        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);
        Logger::debug("after the first pipeline barrier");

        VkRenderPassBeginInfo renderPassBeginInfo;
        renderPassBeginInfo.sType             = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassBeginInfo.pNext             = nullptr;
        renderPassBeginInfo.renderPass        = unormRenderPass;
        renderPassBeginInfo.framebuffer       = edgeFramebuffers[imageIndex];
        renderPassBeginInfo.renderArea.offset = {0, 0};
        renderPassBeginInfo.renderArea.extent = imageExtent;
        VkClearValue clearValue               = {0.0f, 0.0f, 0.0f, 1.0f};
        renderPassBeginInfo.clearValueCount   = 1;
        renderPassBeginInfo.pClearValues      = &clearValue;
        // edge renderPass
        Logger::debug("before beginn edge renderpass");
        pLogicalDevice->vkd.CmdBeginRenderPass(commandBuffer, &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
        Logger::debug("after beginn renderpass");

        pLogicalDevice->vkd.CmdBindDescriptorSets(
            commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout, 0, 1, &(imageDescriptorSets[imageIndex]), 0, nullptr);
        Logger::debug("after binding image sampler");

        pLogicalDevice->vkd.CmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, edgePipeline);
        Logger::debug("after bind pipeliene");

        pLogicalDevice->vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        Logger::debug("after draw");

        pLogicalDevice->vkd.CmdEndRenderPass(commandBuffer);
        Logger::debug("after end renderpass");

        memoryBarrier.image             = edgeImages[imageIndex];
        renderPassBeginInfo.framebuffer = blendFramebuffers[imageIndex];
        // blend renderPass
        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);
        Logger::debug("after the first pipeline barrier");

        Logger::debug("before beginn blend renderpass");
        pLogicalDevice->vkd.CmdBeginRenderPass(commandBuffer, &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
        Logger::debug("after beginn renderpass");

        pLogicalDevice->vkd.CmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, blendPipeline);
        Logger::debug("after bind pipeliene");

        pLogicalDevice->vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        Logger::debug("after draw");

        pLogicalDevice->vkd.CmdEndRenderPass(commandBuffer);
        Logger::debug("after end renderpass");

        memoryBarrier.image             = blendImages[imageIndex];
        renderPassBeginInfo.framebuffer = neignborFramebuffers[imageIndex];
        renderPassBeginInfo.renderPass  = renderPass;
        // neighbor renderPass
        pLogicalDevice->vkd.CmdPipelineBarrier(
            commandBuffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &memoryBarrier);
        Logger::debug("after the first pipeline barrier");

        Logger::debug("before beginn neighbor renderpass");
        pLogicalDevice->vkd.CmdBeginRenderPass(commandBuffer, &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
        Logger::debug("after beginn renderpass");

        pLogicalDevice->vkd.CmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, neighborPipeline);
        Logger::debug("after bind pipeliene");

        pLogicalDevice->vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        Logger::debug("after draw");

        pLogicalDevice->vkd.CmdEndRenderPass(commandBuffer);
        Logger::debug("after end renderpass");

        pLogicalDevice->vkd.CmdPipelineBarrier(commandBuffer,
                                               VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                                               VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                                               0,
                                               0,
                                               nullptr,
                                               0,
                                               nullptr,
                                               1,
                                               &secondBarrier);
        Logger::debug("after the second pipeline barrier");
    }
    SmaaEffect::~SmaaEffect()
    {
        Logger::debug("destroying smaa effect " + convertToString(this));
        pLogicalDevice->vkd.DestroyPipeline(pLogicalDevice->device, edgePipeline, nullptr);
        pLogicalDevice->vkd.DestroyPipeline(pLogicalDevice->device, blendPipeline, nullptr);
        pLogicalDevice->vkd.DestroyPipeline(pLogicalDevice->device, neighborPipeline, nullptr);

        pLogicalDevice->vkd.DestroyPipelineLayout(pLogicalDevice->device, pipelineLayout, nullptr);
        pLogicalDevice->vkd.DestroyRenderPass(pLogicalDevice->device, renderPass, nullptr);
        pLogicalDevice->vkd.DestroyRenderPass(pLogicalDevice->device, unormRenderPass, nullptr);
        pLogicalDevice->vkd.DestroyDescriptorSetLayout(pLogicalDevice->device, imageSamplerDescriptorSetLayout, nullptr);

        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device, edgeVertexModule, nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device, edgeFragmentModule, nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device, blendVertexModule, nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device, blendFragmentModule, nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device, neighborVertexModule, nullptr);
        pLogicalDevice->vkd.DestroyShaderModule(pLogicalDevice->device, neignborFragmentModule, nullptr);

        pLogicalDevice->vkd.DestroyDescriptorPool(pLogicalDevice->device, descriptorPool, nullptr);
        pLogicalDevice->vkd.FreeMemory(pLogicalDevice->device, imageMemory, nullptr);
        pLogicalDevice->vkd.FreeMemory(pLogicalDevice->device, areaMemory, nullptr);
        pLogicalDevice->vkd.FreeMemory(pLogicalDevice->device, searchMemory, nullptr);
        for (unsigned int i = 0; i < edgeFramebuffers.size(); i++)
        {
            pLogicalDevice->vkd.DestroyFramebuffer(pLogicalDevice->device, edgeFramebuffers[i], nullptr);
            pLogicalDevice->vkd.DestroyFramebuffer(pLogicalDevice->device, blendFramebuffers[i], nullptr);
            pLogicalDevice->vkd.DestroyFramebuffer(pLogicalDevice->device, neignborFramebuffers[i], nullptr);
            pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, inputImageViews[i], nullptr);
            pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, edgeImageViews[i], nullptr);
            pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, blendImageViews[i], nullptr);
            pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, outputImageViews[i], nullptr);
            pLogicalDevice->vkd.DestroyImage(pLogicalDevice->device, edgeImages[i], nullptr);
            pLogicalDevice->vkd.DestroyImage(pLogicalDevice->device, blendImages[i], nullptr);
        }
        Logger::debug("after DestroyImageView");
        pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, areaImageView, nullptr);
        pLogicalDevice->vkd.DestroyImage(pLogicalDevice->device, areaImage, nullptr);
        pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, searchImageView, nullptr);
        pLogicalDevice->vkd.DestroyImage(pLogicalDevice->device, searchImage, nullptr);

        pLogicalDevice->vkd.DestroySampler(pLogicalDevice->device, sampler, nullptr);
    }
} // namespace vkBasalt
