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

#include "AreaTex.h"
#include "SearchTex.h"

namespace vkBasalt
{
    SmaaEffect::SmaaEffect(LogicalDevice logicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::string smaaEdgeVertexFile        = "smaa_edge.vert.spv";
        std::string smaaEdgeLumaFragmentFile  = "smaa_edge_luma.frag.spv";
        std::string smaaEdgeColorFragmentFile = "smaa_edge_color.frag.spv";
        std::string smaaBlendVertexFile       = "smaa_blend.vert.spv";
        std::string smaaBlendFragmentFile     = "smaa_blend.frag.spv";
        std::string smaaNeighborVertexFile    = "smaa_neighbor.vert.spv";
        std::string smaaNeighborFragmentFile  = "smaa_neighbor.frag.spv";
        std::cout << "in creating SmaaEffect " << std::endl;

        this->logicalDevice = logicalDevice;
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;

        //create Images for the first and second pass at once -> less memory fragmentation
        std::vector<VkImage> edgeAndBlendImages= createImages(logicalDevice.vki,
                                                               logicalDevice.device,
                                                               logicalDevice.vkd,
                                                               logicalDevice.physicalDevice,
                                                               inputImages.size()*2,
                                                               {imageExtent.width, imageExtent.height, 1},
                                                               VK_FORMAT_B8G8R8A8_UNORM,//TODO search for format and save it
                                                               VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                                               VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                                               imageMemory);

        edgeImages  = std::vector<VkImage>(edgeAndBlendImages.begin(), edgeAndBlendImages.begin() + edgeAndBlendImages.size()/2);
        blendImages = std::vector<VkImage>(edgeAndBlendImages.begin() + edgeAndBlendImages.size()/2, edgeAndBlendImages.end());

        inputImageViews = createImageViews(logicalDevice, format, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        edgeImageViews = createImageViews(logicalDevice, VK_FORMAT_B8G8R8A8_UNORM, edgeImages);
        std::cout << "after creating edge  ImageViews" << std::endl;
        blendImageViews = createImageViews(logicalDevice, VK_FORMAT_B8G8R8A8_UNORM, blendImages);
        std::cout << "after creating blend ImageViews" << std::endl;
        outputImageViews = createImageViews(logicalDevice, format, outputImages);
        std::cout << "after creating output ImageViews" << std::endl;
        sampler = createSampler(logicalDevice);
        std::cout << "after creating sampler" << std::endl;

        VkExtent3D areaImageExtent = {AREATEX_WIDTH, AREATEX_HEIGHT, 1};
        areaImage = createImages(logicalDevice.vki,
                                 logicalDevice.device,
                                 logicalDevice.vkd,
                                 logicalDevice.physicalDevice,
                                 1,
                                 areaImageExtent,
                                 VK_FORMAT_R8G8_UNORM,//TODO search for format and save it
                                 VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                 VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                 areaMemory)[0];
        VkExtent3D searchImageExtent = {SEARCHTEX_WIDTH, SEARCHTEX_HEIGHT, 1};
        searchImage = createImages(logicalDevice.vki,
                                   logicalDevice.device,
                                   logicalDevice.vkd,
                                   logicalDevice.physicalDevice,
                                   1,
                                   searchImageExtent,
                                   VK_FORMAT_R8_UNORM,//TODO search for format and save it
                                   VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   searchMemory)[0];

        uploadToImage(logicalDevice.vki,
                       logicalDevice.device,
                       logicalDevice.vkd,
                       logicalDevice.physicalDevice,
                       areaImage,
                       areaImageExtent,
                       AREATEX_SIZE,
                       logicalDevice.queue,
                       logicalDevice.commandPool,
                       areaTexBytes);

        uploadToImage(logicalDevice.vki,
                       logicalDevice.device,
                       logicalDevice.vkd,
                       logicalDevice.physicalDevice,
                       searchImage,
                       searchImageExtent,
                       SEARCHTEX_SIZE,
                       logicalDevice.queue,
                       logicalDevice.commandPool,
                       searchTexBytes);

        areaImageView = createImageViews(logicalDevice, VK_FORMAT_R8G8_UNORM, std::vector<VkImage>(1,areaImage))[0];
        std::cout << "after creating area ImageView" << std::endl;
        searchImageView = createImageViews(logicalDevice, VK_FORMAT_R8_UNORM, std::vector<VkImage>(1,searchImage))[0];
        std::cout << "after creating search ImageView" << std::endl;

        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(logicalDevice, 5);
        std::cout << "after creating descriptorSetLayouts" << std::endl;

        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size()*5;

        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};

        descriptorPool = createDescriptorPool(logicalDevice, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;

        //get config options
        struct SmaaOptions{
            float screenWidth;
            float screenHeight;
            float reverseScreenWidth;
            float reverseScreenHeight;
            float threshold;
            int32_t maxSearchSteps;
            int32_t maxSearchStepsDiag;
            int32_t cornerRounding;
        };
        
        SmaaOptions smaaOptions;
        smaaOptions.threshold           = std::stod(pConfig->getOption("smaaThreshold", "0.05"));
        smaaOptions.maxSearchSteps      = std::stoi(pConfig->getOption("smaaMaxSearchSteps", "32"));
        smaaOptions.maxSearchStepsDiag  = std::stoi(pConfig->getOption("smaaMaxSearchStepsDiag", "16"));
        smaaOptions.cornerRounding      = std::stoi(pConfig->getOption("smaaCornerRounding", "25"));

        auto shaderCode = readFile(smaaEdgeVertexFile);
        createShaderModule(logicalDevice, shaderCode, &edgeVertexModule);
        shaderCode = pConfig->getOption("smaaEdgeDetection", "luma") == "color"
            ? readFile(smaaEdgeColorFragmentFile)
            : readFile(smaaEdgeLumaFragmentFile);
        createShaderModule(logicalDevice, shaderCode, &edgeFragmentModule);
        shaderCode = readFile(smaaBlendVertexFile);
        createShaderModule(logicalDevice, shaderCode, &blendVertexModule);
        shaderCode = readFile(smaaBlendFragmentFile);
        createShaderModule(logicalDevice, shaderCode, &blendFragmentModule);
        shaderCode = readFile(smaaNeighborVertexFile);
        createShaderModule(logicalDevice, shaderCode, &neighborVertexModule);
        shaderCode = readFile(smaaNeighborFragmentFile);
        createShaderModule(logicalDevice, shaderCode, &neignborFragmentModule);

        renderPass      = createRenderPass(logicalDevice, format);
        unormRenderPass = createRenderPass(logicalDevice, VK_FORMAT_B8G8R8A8_UNORM);

        std::vector<VkDescriptorSetLayout> descriptorSetLayouts = {imageSamplerDescriptorSetLayout};
        pipelineLayout = createGraphicsPipelineLayout(logicalDevice, descriptorSetLayouts);

        std::vector<VkSpecializationMapEntry> specMapEntrys(8);
        for(uint32_t i=0;i<specMapEntrys.size();i++)
        {
            specMapEntrys[i].constantID = i;
            specMapEntrys[i].offset = sizeof(float) * i;//TODO not clean to assume that sizeof(int32_t) == sizeof(float)
            specMapEntrys[i].size = sizeof(float);
        }
        smaaOptions.screenWidth = (float) imageExtent.width,
        smaaOptions.screenHeight = (float) imageExtent.height,
        smaaOptions.reverseScreenWidth = 1.0f/imageExtent.width;
        smaaOptions.reverseScreenHeight = 1.0f/imageExtent.height;

        VkSpecializationInfo specializationInfo;
        specializationInfo.mapEntryCount = specMapEntrys.size();
        specializationInfo.pMapEntries = specMapEntrys.data();
        specializationInfo.dataSize = sizeof(smaaOptions);
        specializationInfo.pData = &smaaOptions;

        edgePipeline     = createGraphicsPipeline(logicalDevice, edgeVertexModule, &specializationInfo, "main", edgeFragmentModule, &specializationInfo, "main", imageExtent, unormRenderPass, pipelineLayout);
        blendPipeline    = createGraphicsPipeline(logicalDevice, blendVertexModule, &specializationInfo, "main", blendFragmentModule, &specializationInfo, "main", imageExtent, unormRenderPass, pipelineLayout);
        neighborPipeline = createGraphicsPipeline(logicalDevice, neighborVertexModule, &specializationInfo, "main", neignborFragmentModule, &specializationInfo, "main", imageExtent, renderPass, pipelineLayout);


        std::vector<std::vector<VkImageView>> imageViewsVector = {inputImageViews,
                                                                  edgeImageViews,
                                                                  std::vector<VkImageView>(inputImageViews.size(), areaImageView),
                                                                  std::vector<VkImageView>(inputImageViews.size(), searchImageView),
                                                                  blendImageViews};
        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(logicalDevice, descriptorPool, imageSamplerDescriptorSetLayout, std::vector<VkSampler>(imageViewsVector.size(),sampler), imageViewsVector);

        edgeFramebuffers     = createFramebuffers(logicalDevice, unormRenderPass, imageExtent,   {edgeImageViews});
        blendFramebuffers    = createFramebuffers(logicalDevice, unormRenderPass, imageExtent,  {blendImageViews});
        neignborFramebuffers = createFramebuffers(logicalDevice, renderPass,      imageExtent, {outputImageViews});
    }
    void SmaaEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        std::cout << "applying smaa effect" << commandBuffer << std::endl;
        //Used to make the Image accessable by the shader
        VkImageMemoryBarrier memoryBarrier;
        memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext = nullptr;
        memoryBarrier.srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
        memoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        memoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        memoryBarrier.image = inputImages[imageIndex];
        memoryBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        memoryBarrier.subresourceRange.baseMipLevel = 0;
        memoryBarrier.subresourceRange.levelCount = 1;
        memoryBarrier.subresourceRange.baseArrayLayer = 0;
        memoryBarrier.subresourceRange.layerCount = 1;

        //Reverses the first Barrier
        VkImageMemoryBarrier secondBarrier;
        secondBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        secondBarrier.pNext = nullptr;
        secondBarrier.srcAccessMask =  VK_ACCESS_SHADER_READ_BIT;
        secondBarrier.dstAccessMask =  0;
        secondBarrier.oldLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        secondBarrier.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        secondBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        secondBarrier.image = inputImages[imageIndex];
        secondBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        secondBarrier.subresourceRange.baseMipLevel = 0;
        secondBarrier.subresourceRange.levelCount = 1;
        secondBarrier.subresourceRange.baseArrayLayer = 0;
        secondBarrier.subresourceRange.layerCount = 1;

        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        std::cout << "after the first pipeline barrier" << std::endl;

        VkRenderPassBeginInfo renderPassBeginInfo;
        renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassBeginInfo.pNext = nullptr;
        renderPassBeginInfo.renderPass = unormRenderPass;
        renderPassBeginInfo.framebuffer = edgeFramebuffers[imageIndex];
        renderPassBeginInfo.renderArea.offset = {0,0};
        renderPassBeginInfo.renderArea.extent = imageExtent;
        VkClearValue clearValue = {0.0f, 0.0f, 0.0f, 1.0f};
        renderPassBeginInfo.clearValueCount = 1;
        renderPassBeginInfo.pClearValues = &clearValue;
        //edge renderPass
        std::cout << "before beginn edge renderpass" << std::endl;
        logicalDevice.vkd.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;

        logicalDevice.vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        std::cout << "after binding image sampler" << std::endl;

        logicalDevice.vkd.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,edgePipeline);
        std::cout << "after bind pipeliene" << std::endl;

        logicalDevice.vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        logicalDevice.vkd.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;

        memoryBarrier.image = edgeImages[imageIndex];
        renderPassBeginInfo.framebuffer = blendFramebuffers[imageIndex];
        //blend renderPass
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        std::cout << "after the first pipeline barrier" << std::endl;

        std::cout << "before beginn blend renderpass" << std::endl;
        logicalDevice.vkd.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;

        logicalDevice.vkd.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,blendPipeline);
        std::cout << "after bind pipeliene" << std::endl;

        logicalDevice.vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        logicalDevice.vkd.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;

        memoryBarrier.image = blendImages[imageIndex];
        renderPassBeginInfo.framebuffer = neignborFramebuffers[imageIndex];
        renderPassBeginInfo.renderPass = renderPass;
        //neighbor renderPass
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        std::cout << "after the first pipeline barrier" << std::endl;

        std::cout << "before beginn neighbor renderpass" << std::endl;
        logicalDevice.vkd.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;

        logicalDevice.vkd.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,neighborPipeline);
        std::cout << "after bind pipeliene" << std::endl;

        logicalDevice.vkd.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        logicalDevice.vkd.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;

        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    SmaaEffect::~SmaaEffect()
    {
        std::cout << "destroying smaa effect " << this << std::endl;
        logicalDevice.vkd.DestroyPipeline(logicalDevice.device, edgePipeline,     nullptr);
        logicalDevice.vkd.DestroyPipeline(logicalDevice.device, blendPipeline,    nullptr);
        logicalDevice.vkd.DestroyPipeline(logicalDevice.device, neighborPipeline, nullptr);

        logicalDevice.vkd.DestroyPipelineLayout(logicalDevice.device, pipelineLayout, nullptr);
        logicalDevice.vkd.DestroyRenderPass(logicalDevice.device, renderPass, nullptr);
        logicalDevice.vkd.DestroyRenderPass(logicalDevice.device, unormRenderPass, nullptr);
        logicalDevice.vkd.DestroyDescriptorSetLayout(logicalDevice.device, imageSamplerDescriptorSetLayout, nullptr);

        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, edgeVertexModule,       nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, edgeFragmentModule,     nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, blendVertexModule,      nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, blendFragmentModule,    nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, neighborVertexModule,   nullptr);
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, neignborFragmentModule, nullptr);

        logicalDevice.vkd.DestroyDescriptorPool(logicalDevice.device, descriptorPool, nullptr);
        logicalDevice.vkd.FreeMemory(logicalDevice.device, imageMemory, nullptr);
        logicalDevice.vkd.FreeMemory(logicalDevice.device, areaMemory, nullptr);
        logicalDevice.vkd.FreeMemory(logicalDevice.device, searchMemory, nullptr);
        for(unsigned int i=0;i<edgeFramebuffers.size();i++)
        {
            logicalDevice.vkd.DestroyFramebuffer(logicalDevice.device, edgeFramebuffers[i], nullptr);
            logicalDevice.vkd.DestroyFramebuffer(logicalDevice.device, blendFramebuffers[i], nullptr);
            logicalDevice.vkd.DestroyFramebuffer(logicalDevice.device, neignborFramebuffers[i], nullptr);
            logicalDevice.vkd.DestroyImageView(logicalDevice.device, inputImageViews[i], nullptr);
            logicalDevice.vkd.DestroyImageView(logicalDevice.device, edgeImageViews[i], nullptr);
            logicalDevice.vkd.DestroyImageView(logicalDevice.device, blendImageViews[i], nullptr);
            logicalDevice.vkd.DestroyImageView(logicalDevice.device, outputImageViews[i], nullptr);
            logicalDevice.vkd.DestroyImage(logicalDevice.device, edgeImages[i], nullptr);
            logicalDevice.vkd.DestroyImage(logicalDevice.device, blendImages[i], nullptr);
        }
        std::cout << "after DestroyImageView" << std::endl;
        logicalDevice.vkd.DestroyImageView(logicalDevice.device, areaImageView, nullptr);
        logicalDevice.vkd.DestroyImage(logicalDevice.device, areaImage, nullptr);
        logicalDevice.vkd.DestroyImageView(logicalDevice.device, searchImageView, nullptr);
        logicalDevice.vkd.DestroyImage(logicalDevice.device, searchImage, nullptr);

        logicalDevice.vkd.DestroySampler(logicalDevice.device, sampler, nullptr);
    }
}
