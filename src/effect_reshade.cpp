#include "effect_reshade.hpp"

#include <cstring>
#include <climits>
#include <cstdlib>
#include <cassert>

#include <set>
#include <variant>
#include <algorithm>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"
#include "image.hpp"
#include "format.hpp"

#include "stb_image.h"
#include "stb_image_dds.h"
#include "stb_image_resize.h"

namespace vkBasalt
{
    ReshadeEffect::ReshadeEffect(LogicalDevice logicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, std::string effectName)
    {
        std::cout << "in creating ReshadeEffect " << std::endl;
        
        this->logicalDevice = logicalDevice;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        this->effectName = effectName;
        inputOutputFormatUNORM = convertToUNORM(format);
        inputOutputFormatSRGB = convertToSRGB(format);
        
        
        std::vector<VkImageView> inputImageViewsSRGB = createImageViews(logicalDevice, inputOutputFormatSRGB, inputImages);
        std::vector<VkImageView> inputImageViewsUNORM = createImageViews(logicalDevice, inputOutputFormatUNORM, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        outputImageViewsSRGB = createImageViews(logicalDevice, inputOutputFormatSRGB, outputImages);
        outputImageViewsUNORM = createImageViews(logicalDevice, inputOutputFormatUNORM, outputImages);
        std::cout << "after creating ImageViews" << std::endl;
        
        createReshadeModule();
        
        enumerateReshadeUniforms(module);
        
        uniforms = createReshadeUniforms(module);
        
        bufferSize = module.total_uniform_size;
        if(bufferSize)
        {
            createBuffer(logicalDevice.vki, logicalDevice.device, logicalDevice.vkd, logicalDevice.physicalDevice, bufferSize,  VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
                     VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);
        }
        
        stencilFormat = getStencilFormat(logicalDevice);
        std::cout << "Stencil Format: " << stencilFormat << std::endl;
        textureMemory.push_back(VK_NULL_HANDLE);
        stencilImage = createImages(logicalDevice.vki,
                                   logicalDevice.device,
                                   logicalDevice.vkd,
                                   logicalDevice.physicalDevice,
                                   1,
                                   {imageExtent.width, imageExtent.height, 1},
                                   stencilFormat,
                                   VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   textureMemory.back())[0];
        
        stencilImageView = createImageViews(logicalDevice, stencilFormat, {stencilImage}, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT)[0];
        
        
        
        std::vector<std::vector<VkImageView>> imageViewVector;
        
        for(size_t i = 0; i < module.textures.size(); i++)
        {
            if(module.textures[i].semantic == "COLOR")
            {
                textureImageViewsUNORM[module.textures[i].unique_name] = inputImageViewsUNORM;
                textureImageViewsSRGB[module.textures[i].unique_name] = inputImageViewsSRGB;
                textureFormatsUNORM[module.textures[i].unique_name] = inputOutputFormatUNORM;
                textureFormatsSRGB[module.textures[i].unique_name] = inputOutputFormatSRGB;
                continue;
            }
            if(module.textures[i].semantic == "DEPTH")
            {
                textureImageViewsUNORM[module.textures[i].unique_name] = inputImageViewsUNORM;
                textureImageViewsSRGB[module.textures[i].unique_name] = inputImageViewsSRGB;//TODO Depth buffer access
                textureFormatsUNORM[module.textures[i].unique_name] = inputOutputFormatUNORM;
                textureFormatsSRGB[module.textures[i].unique_name] = inputOutputFormatSRGB;
                continue;
            }
            VkExtent3D textureExtent = {module.textures[i].width, module.textures[i].height, 1};
            //TODO handle mip map levels correctly
            //TODO handle pooled textures better
            if(const auto source = std::find_if(module.textures[i].annotations.begin(), module.textures[i].annotations.end(), [](const auto &a) { return a.name == "source"; }); source == module.textures[i].annotations.end())
            {
                textureMemory.push_back(VK_NULL_HANDLE);
                std::vector<VkImage> images = createImages(logicalDevice.vki,
                                   logicalDevice.device,
                                   logicalDevice.vkd,
                                   logicalDevice.physicalDevice,
                                   inputImages.size(),
                                   textureExtent,
                                   convertReshadeFormat(module.textures[i].format),//TODO search for format and save it
                                   VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   textureMemory.back());
               
               textureImages[module.textures[i].unique_name] = images;
               std::vector<VkImageView> imageViewsUNORM = createImageViews(logicalDevice, convertToUNORM(convertReshadeFormat(module.textures[i].format)), images);
               std::vector<VkImageView> imageViewsSRGB = createImageViews(logicalDevice, convertToSRGB(convertReshadeFormat(module.textures[i].format)), images);
               textureImageViewsUNORM[module.textures[i].unique_name] = imageViewsUNORM;
               textureImageViewsSRGB[module.textures[i].unique_name] = imageViewsSRGB;
               textureFormatsUNORM[module.textures[i].unique_name] = convertToUNORM(convertReshadeFormat(module.textures[i].format));
               textureFormatsSRGB[module.textures[i].unique_name] = convertToSRGB(convertReshadeFormat(module.textures[i].format));
               changeImageLayout(logicalDevice.vki,
                               logicalDevice.device,
                               logicalDevice.vkd,
                               logicalDevice.physicalDevice,
                               images,
                               logicalDevice.queue,
                               logicalDevice.commandPool);
               continue;
            }
            else
            {
                textureMemory.push_back(VK_NULL_HANDLE);
                std::vector<VkImage> images = createImages(logicalDevice.vki,
                                   logicalDevice.device,
                                   logicalDevice.vkd,
                                   logicalDevice.physicalDevice,
                                   1,
                                   textureExtent,
                                   convertReshadeFormat(module.textures[i].format),//TODO search for format and save it
                                   VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   textureMemory.back());
                textureImages[module.textures[i].unique_name] = images;
                std::vector<VkImageView> imageViews = createImageViews(logicalDevice, convertToUNORM(convertReshadeFormat(module.textures[i].format)), images);
                std::vector<VkImageView> imageViewsUNORM = std::vector<VkImageView>(inputImages.size(), imageViews[0]);
                imageViews = createImageViews(logicalDevice, convertToSRGB(convertReshadeFormat(module.textures[i].format)), images);
                std::vector<VkImageView> imageViewsSRGB = std::vector<VkImageView>(inputImages.size(), imageViews[0]);
                textureImageViewsUNORM[module.textures[i].unique_name] = imageViewsUNORM;
                textureImageViewsSRGB[module.textures[i].unique_name] = imageViewsSRGB;
                textureFormatsUNORM[module.textures[i].unique_name] = convertToUNORM(convertReshadeFormat(module.textures[i].format));
                textureFormatsSRGB[module.textures[i].unique_name] = convertToSRGB(convertReshadeFormat(module.textures[i].format));
                
                int desiredChannels;
                switch(textureFormatsUNORM[module.textures[i].unique_name])
                {
                    case VK_FORMAT_R8_UNORM:
                        desiredChannels = STBI_grey;
                        break;
                    case VK_FORMAT_R8G8_UNORM:
                        desiredChannels = STBI_rgb_alpha;//TODO why doesn't STBI_grey_alpha work?
                        break;
                    case VK_FORMAT_R8G8B8A8_UNORM:
                        desiredChannels = STBI_rgb_alpha;
                        break;
                    case VK_FORMAT_R8G8B8A8_SRGB:
                        desiredChannels = STBI_rgb_alpha;
                        break;
                    default:
                        throw std::runtime_error(std::string("unsupported texture upload format") + std::to_string(textureFormatsUNORM[module.textures[i].unique_name]));
                }
                
                std::string filePath = pConfig->getOption("reshadeTexturePath") + "/" + source->value.string_data;
                stbi_uc* pixels;
                std::vector<stbi_uc> resizedPixels;
                uint32_t size;
                int width;
                int height;
                size = textureExtent.width * textureExtent.height * desiredChannels;
                FILE *const file = fopen(filePath.c_str(), "rb");
                if(file == nullptr)
                {
                    throw std::runtime_error("couldn't open texture: " + filePath);
                }
                if(stbi_dds_test_file(file))
                {
                    int channels;
                    pixels = stbi_dds_load_from_file(file, &width, &height, &channels, desiredChannels);
                }
                else
                {
                    int channels;
                    pixels = stbi_load_from_file(file, &width, &height, &channels, desiredChannels);
                }
                
                //change RGBA to RG
                if(textureFormatsUNORM[module.textures[i].unique_name] == VK_FORMAT_R8G8_UNORM)
                {
                    uint32_t pos = 0;
                    for(uint32_t j = 0; j < size; j += 4)
                    {
                        pixels[pos] = pixels[j];
                        pos++;
                        pixels[pos] = pixels[j + 1];
                        pos++;
                    }
                    size /= 2;
                    desiredChannels /= 2;
                }
                
                if(static_cast<uint32_t>(width) != textureExtent.width || static_cast<uint32_t>(height) != textureExtent.height)
                {
                    resizedPixels.resize(size);
                    stbir_resize_uint8(pixels, width, height, 0, resizedPixels.data(), textureExtent.width, textureExtent.height, 0, desiredChannels);
                }
                
                uploadToImage(logicalDevice.vki,
                       logicalDevice.device,
                       logicalDevice.vkd,
                       logicalDevice.physicalDevice,
                       images[0],
                       textureExtent,
                       size,
                       logicalDevice.queue,
                       logicalDevice.commandPool,
                       resizedPixels.size() ? resizedPixels.data() : pixels);
                stbi_image_free(pixels);
            }
        }
        
        
        for(size_t i = 0; i < module.samplers.size(); i++)
        {
            reshadefx::sampler_info info = module.samplers[i];
            VkSampler sampler = createReshadeSampler(logicalDevice, info);
            samplers.push_back(sampler);
            imageViewVector.push_back(info.srgb ? textureImageViewsSRGB[info.texture_name] : textureImageViewsUNORM[info.texture_name]);
        }
        
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(logicalDevice, module.samplers.size());
        uniformDescriptorSetLayout = createUniformBufferDescriptorSetLayout(logicalDevice);
        std::cout << "after creating descriptorSetLayouts" << std::endl;
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size() * module.samplers.size() * 3;
        
        VkDescriptorPoolSize bufferPoolSize;
        bufferPoolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        bufferPoolSize.descriptorCount = 3;
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize, bufferPoolSize};
        
        descriptorPool = createDescriptorPool(logicalDevice, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;
        
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts = {uniformDescriptorSetLayout,imageSamplerDescriptorSetLayout};
        pipelineLayout = createGraphicsPipelineLayout(logicalDevice, descriptorSetLayouts);
        
        std::cout << "after creating Pipeline layout" << std::endl;
        
        std::cout << outputWrites << std::endl;
        if(bufferSize)
        {
            bufferDescriptorSet = writeBufferDescriptorSet(logicalDevice, descriptorPool, uniformDescriptorSetLayout, stagingBuffer);
        }
        
        inputDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(logicalDevice,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         samplers,
                                                                         imageViewVector);
        
        //count the back buffer writes
        for(auto& pass: module.techniques[0].passes)
        {
            if(pass.render_target_names[0] == "")
            {
                outputWrites++;
            }
        }
        
        //if there is only one outputWrite, we can directly write to outputImages
        if(outputWrites > 1)
        {
            textureMemory.push_back(VK_NULL_HANDLE);
            backBufferImages = createImages(logicalDevice.vki,
                               logicalDevice.device,
                               logicalDevice.vkd,
                               logicalDevice.physicalDevice,
                               inputImages.size(),
                               {imageExtent.width, imageExtent.height, 1},
                               format,//TODO search for format and save it
                               VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                               VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                               textureMemory.back());
            backBufferImageViewsSRGB = createImageViews(logicalDevice, inputOutputFormatSRGB, backBufferImages);
            backBufferImageViewsUNORM = createImageViews(logicalDevice, inputOutputFormatUNORM, backBufferImages);
            std::replace(imageViewVector.begin(), imageViewVector.end(), inputImageViewsSRGB, backBufferImageViewsSRGB);
            std::replace(imageViewVector.begin(), imageViewVector.end(), inputImageViewsUNORM, backBufferImageViewsUNORM);
            backBufferDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(logicalDevice,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         samplers,
                                                                         imageViewVector);
        }
        if(outputWrites > 2)
        {
            std::replace(imageViewVector.begin(), imageViewVector.end(), backBufferImageViewsSRGB, outputImageViewsSRGB);
            std::replace(imageViewVector.begin(), imageViewVector.end(), backBufferImageViewsUNORM, outputImageViewsUNORM);
            outputDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(logicalDevice,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         samplers,
                                                                         imageViewVector);
        }
        
        
        std::cout << "after writing ImageSamplerDescriptorSets" << std::endl;
        
        bool firstTimeStencilAccess = true;//Used to clear the sttencil attachment on the first time
        
        for(bool outputToBackBuffer = outputWrites % 2 == 0;auto& pass: module.techniques[0].passes)
        {
            std::vector<VkAttachmentReference>               attachmentReferences;
            std::vector<VkAttachmentDescription>             attachmentDescriptions;
            std::vector<VkPipelineColorBlendAttachmentState> attachmentBlendStates;
            std::vector<std::vector<VkImageView>>            attachmentImageViews;
            
            for(int i = 0; i < 8; i++)
            {
                std::string target = pass.render_target_names[i];
                std::cout << target << std::endl;
                
                VkAttachmentDescription attachmentDescription;
                attachmentDescription.flags = 0;
                attachmentDescription.format = pass.srgb_write_enable ? textureFormatsSRGB[target] : textureFormatsUNORM[target];
                attachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
                attachmentDescription.loadOp = pass.clear_render_targets ? VK_ATTACHMENT_LOAD_OP_CLEAR : pass.blend_enable ? VK_ATTACHMENT_LOAD_OP_LOAD : VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                attachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
                attachmentDescription.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
                attachmentDescription.initialLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                attachmentDescription.finalLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                
                if(target == "" && i == 0)
                {
                    attachmentDescription.format = pass.srgb_write_enable ? inputOutputFormatSRGB : inputOutputFormatUNORM;
                    attachmentDescription.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD;
		            attachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
		            attachmentDescription.initialLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		            attachmentDescription.finalLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                }
                else if(target == "")
                {
                    break;
                }
                
                attachmentDescriptions.push_back(attachmentDescription);
                
                VkAttachmentReference attachmentReference;
                attachmentReference.attachment = i;
                attachmentReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
                
                attachmentReferences.push_back(attachmentReference);
                
                VkPipelineColorBlendAttachmentState colorBlendAttachment;
                colorBlendAttachment.blendEnable = pass.blend_enable;
                colorBlendAttachment.srcColorBlendFactor = convertReshadeBlendFactor(pass.src_blend);
                colorBlendAttachment.dstColorBlendFactor = convertReshadeBlendFactor(pass.dest_blend);
                colorBlendAttachment.colorBlendOp = convertReshadeBlendOp(pass.blend_op);
                colorBlendAttachment.srcAlphaBlendFactor = convertReshadeBlendFactor(pass.src_blend_alpha);
                colorBlendAttachment.dstAlphaBlendFactor = convertReshadeBlendFactor(pass.dest_blend_alpha);
                colorBlendAttachment.alphaBlendOp = convertReshadeBlendOp(pass.blend_op_alpha);
                colorBlendAttachment.colorWriteMask = pass.color_write_mask;
                
                attachmentBlendStates.push_back(colorBlendAttachment);
                
                attachmentImageViews.push_back(pass.srgb_write_enable ? textureImageViewsSRGB[target] : textureImageViewsUNORM[target]);
                
                
                
            }
            
            VkRect2D scissor;
            scissor.offset = {0,0};
            scissor.extent.width = pass.viewport_width ? pass.viewport_width : imageExtent.width;
            scissor.extent.height = pass.viewport_height ? pass.viewport_height : imageExtent.height;
            
            std::cout << scissor.extent.width << " x " << scissor.extent.height << std::endl;

            VkViewport viewport;
            viewport.x = 0.0f;
            viewport.y = 0.0f;
            viewport.width = static_cast<float>(scissor.extent.width);
            viewport.height = static_cast<float>(scissor.extent.height);
            viewport.minDepth = 0.0f;
            viewport.maxDepth = 1.0f;
            
            uint32_t depthAttachmentCount = 0;
            
            if(scissor.extent.width == imageExtent.width && scissor.extent.height == imageExtent.height)
            {
                depthAttachmentCount = 1;
                
                attachmentImageViews.push_back(std::vector<VkImageView>(inputImages.size(), stencilImageView));
                
                VkAttachmentReference attachmentReference;
                attachmentReference.attachment = attachmentReferences.size();
                attachmentReference.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
                
                attachmentReferences.push_back(attachmentReference);
                
                VkAttachmentDescription attachmentDescription;
                attachmentDescription.flags = 0;
                attachmentDescription.format = stencilFormat;
                attachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
                attachmentDescription.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                attachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
                attachmentDescription.stencilLoadOp = firstTimeStencilAccess ? VK_ATTACHMENT_LOAD_OP_CLEAR : VK_ATTACHMENT_LOAD_OP_LOAD;
                attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
                attachmentDescription.initialLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
                attachmentDescription.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
                
                firstTimeStencilAccess = false;
                
                attachmentDescriptions.push_back(attachmentDescription);
            }
            
            //renderpass

            VkSubpassDescription subpassDescription;
            subpassDescription.flags = 0;
            subpassDescription.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpassDescription.inputAttachmentCount = 0;
            subpassDescription.pInputAttachments = nullptr;
            subpassDescription.colorAttachmentCount = attachmentReferences.size() - depthAttachmentCount;
            subpassDescription.pColorAttachments = attachmentReferences.data();
            subpassDescription.pResolveAttachments = nullptr;
            subpassDescription.pDepthStencilAttachment = depthAttachmentCount ? &attachmentReferences.back() : nullptr;
            subpassDescription.preserveAttachmentCount = 0;
            subpassDescription.pPreserveAttachments = nullptr;

            VkSubpassDependency subpassDependency;
            subpassDependency.srcSubpass = VK_SUBPASS_EXTERNAL;
            subpassDependency.dstSubpass = 0;
            subpassDependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            subpassDependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
            subpassDependency.srcAccessMask = 0;
            subpassDependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            subpassDependency.dependencyFlags = 0;

            VkRenderPassCreateInfo renderPassCreateInfo;
            renderPassCreateInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
            renderPassCreateInfo.pNext = nullptr;
            renderPassCreateInfo.flags = 0;
            renderPassCreateInfo.attachmentCount = attachmentDescriptions.size();
            renderPassCreateInfo.pAttachments = attachmentDescriptions.data();
            renderPassCreateInfo.subpassCount = 1;
            renderPassCreateInfo.pSubpasses = &subpassDescription;
            renderPassCreateInfo.dependencyCount = 1;
            renderPassCreateInfo.pDependencies = &subpassDependency;
            
            VkRenderPass renderPass;
            VkResult result = logicalDevice.vkd.CreateRenderPass(logicalDevice.device, &renderPassCreateInfo, nullptr, &renderPass);
            ASSERT_VULKAN(result);
            renderPasses.push_back(renderPass);
            
            VkRenderPassBeginInfo renderPassBeginInfo;
            renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassBeginInfo.pNext = nullptr;
            renderPassBeginInfo.renderPass = renderPass;
            renderPassBeginInfo.framebuffer = VK_NULL_HANDLE;//changed at apply time
            renderPassBeginInfo.renderArea = scissor;
            renderPassBeginInfo.clearValueCount = attachmentDescriptions.size();
            VkClearValue clearValues[9] = {};
            renderPassBeginInfo.pClearValues = clearValues;
            
            renderPassBeginInfos.push_back(renderPassBeginInfo);
            
            //framebuffers
            
            if(pass.render_target_names[0] == "")
            {
                std::vector<VkImageView> backBufferImageViews = pass.srgb_write_enable ? backBufferImageViewsSRGB : backBufferImageViewsUNORM;
                std::vector<VkImageView> outputImageViews     = pass.srgb_write_enable ? outputImageViewsSRGB     : outputImageViewsUNORM;
                framebuffers.push_back(createFramebuffers(logicalDevice, renderPass, imageExtent, {outputToBackBuffer ? backBufferImageViews : outputImageViews, std::vector<VkImageView>(inputImages.size(), stencilImageView)}));
                outputToBackBuffer = !outputToBackBuffer;
                switchSamplers.push_back(true);
            }
            else
            {
                framebuffers.push_back(createFramebuffers(logicalDevice, renderPass, scissor.extent, attachmentImageViews));
                switchSamplers.push_back(false);
            }
            
            //pipeline
            
	    // Configure effect
            std::vector<VkSpecializationMapEntry> specMapEntrys;
            std::vector<char> specData;

            for (uint32_t specId = 0, offset = 0; auto& opt : module.spec_constants)
            {
                if (!opt.name.empty())
                {
                    auto val = pConfig->getOption(opt.name);
                    if (!val.empty())
                    {
                        std::variant<int32_t,uint32_t,float> convertedValue;
                        offset = static_cast<uint32_t>(specData.size());
                        switch(opt.type.base)
                        {
                            case reshadefx::type::t_bool:
                                convertedValue = (val == "true" || val == "1") ? 1 : 0;
                                specData.resize(offset + sizeof(VkBool32));
                                std::memcpy(specData.data() + offset, &convertedValue, sizeof(VkBool32));
                                specMapEntrys.push_back({specId, offset, sizeof(VkBool32)});
                                break;
                            case reshadefx::type::t_int:
                                convertedValue = std::stoi(val);
                                specData.resize(offset + sizeof(int32_t));
                                std::memcpy(specData.data() + offset, &convertedValue, sizeof(int32_t));
                                specMapEntrys.push_back({specId, offset, sizeof(int32_t)});
                                break;
                            case reshadefx::type::t_uint:
                                convertedValue = static_cast<uint32_t>(std::stoul(val));
                                specData.resize(offset + sizeof(uint32_t));
                                std::memcpy(specData.data() + offset, &convertedValue, sizeof(uint32_t));
                                specMapEntrys.push_back({specId, offset, sizeof(uint32_t)});
                                break;
                            case reshadefx::type::t_float:
                                convertedValue = std::stof(val);
                                specData.resize(offset + sizeof(float));
                                std::memcpy(specData.data() + offset, &convertedValue, sizeof(float));
                                specMapEntrys.push_back({specId, offset, sizeof(float)});
                                break;
                            default:
                                // do nothing
                                break;
                        }
                    }
                }
                specId++;
            }

            VkSpecializationInfo specializationInfo;
            if (specMapEntrys.size() > 0) {
                specializationInfo = {
                    .mapEntryCount = static_cast<uint32_t>(specMapEntrys.size()),
                    .pMapEntries = specMapEntrys.data(),
                    .dataSize = specData.size(),
                    .pData = specData.data()
                };
            }

            VkPipelineShaderStageCreateInfo shaderStageCreateInfoVert;
            shaderStageCreateInfoVert.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shaderStageCreateInfoVert.pNext = nullptr;
            shaderStageCreateInfoVert.flags = 0;
            shaderStageCreateInfoVert.stage = VK_SHADER_STAGE_VERTEX_BIT;
            shaderStageCreateInfoVert.module = shaderModule;
            shaderStageCreateInfoVert.pName = pass.vs_entry_point.c_str();
            shaderStageCreateInfoVert.pSpecializationInfo = (specMapEntrys.size() > 0) ? &specializationInfo : nullptr;

            VkPipelineShaderStageCreateInfo shaderStageCreateInfoFrag;
            shaderStageCreateInfoFrag.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shaderStageCreateInfoFrag.pNext = nullptr;
            shaderStageCreateInfoFrag.flags = 0;
            shaderStageCreateInfoFrag.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
            shaderStageCreateInfoFrag.module =  shaderModule;
            shaderStageCreateInfoFrag.pName =  pass.ps_entry_point.c_str();
            shaderStageCreateInfoFrag.pSpecializationInfo = (specMapEntrys.size() > 0) ? &specializationInfo : nullptr;

            VkPipelineShaderStageCreateInfo shaderStages[] = {shaderStageCreateInfoVert,shaderStageCreateInfoFrag};

            VkPipelineVertexInputStateCreateInfo vertexInputCreateInfo;
            vertexInputCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
            vertexInputCreateInfo.pNext = nullptr;
            vertexInputCreateInfo.flags = 0;
            vertexInputCreateInfo.vertexBindingDescriptionCount = 0;
            vertexInputCreateInfo.pVertexBindingDescriptions = nullptr;
            vertexInputCreateInfo.vertexAttributeDescriptionCount = 0;
            vertexInputCreateInfo.pVertexAttributeDescriptions = nullptr;

            VkPipelineInputAssemblyStateCreateInfo inputAssemblyCreateInfo;
            inputAssemblyCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
            inputAssemblyCreateInfo.pNext = nullptr;
            inputAssemblyCreateInfo.flags = 0;
            inputAssemblyCreateInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
            inputAssemblyCreateInfo.primitiveRestartEnable = VK_FALSE;

            VkPipelineViewportStateCreateInfo viewportStateCreateInfo;
            viewportStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
            viewportStateCreateInfo.pNext = nullptr;
            viewportStateCreateInfo.flags = 0;
            viewportStateCreateInfo.viewportCount = 1;
            viewportStateCreateInfo.pViewports = &viewport;
            viewportStateCreateInfo.scissorCount = 1;
            viewportStateCreateInfo.pScissors = &scissor;

            VkPipelineRasterizationStateCreateInfo rasterizationCreateInfo;
            rasterizationCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
            rasterizationCreateInfo.pNext = nullptr;
            rasterizationCreateInfo.flags = 0;
            rasterizationCreateInfo.depthClampEnable = VK_FALSE;
            rasterizationCreateInfo.rasterizerDiscardEnable = VK_FALSE;
            rasterizationCreateInfo.polygonMode = VK_POLYGON_MODE_FILL;
            rasterizationCreateInfo.cullMode = VK_CULL_MODE_NONE;
            rasterizationCreateInfo.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
            rasterizationCreateInfo.depthBiasEnable = VK_FALSE;
            rasterizationCreateInfo.depthBiasConstantFactor = 0.0f;
            rasterizationCreateInfo.depthBiasClamp = 0.0f;
            rasterizationCreateInfo.depthBiasSlopeFactor = 0.0f;
            rasterizationCreateInfo.lineWidth = 1.0f;

            VkPipelineMultisampleStateCreateInfo multisampleCreateInfo;
            multisampleCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
            multisampleCreateInfo.pNext = nullptr;
            multisampleCreateInfo.flags = 0;
            multisampleCreateInfo.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
            multisampleCreateInfo.sampleShadingEnable = VK_FALSE;
            multisampleCreateInfo.minSampleShading = 1.0f;
            multisampleCreateInfo.pSampleMask = nullptr;
            multisampleCreateInfo.alphaToCoverageEnable = VK_FALSE;
            multisampleCreateInfo.alphaToOneEnable = VK_FALSE;

            VkPipelineColorBlendStateCreateInfo colorBlendCreateInfo;
            colorBlendCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
            colorBlendCreateInfo.pNext = nullptr;
            colorBlendCreateInfo.flags = 0;
            colorBlendCreateInfo.logicOpEnable = VK_FALSE;
            colorBlendCreateInfo.logicOp = VK_LOGIC_OP_NO_OP;
            colorBlendCreateInfo.attachmentCount = attachmentBlendStates.size();
            colorBlendCreateInfo.pAttachments = attachmentBlendStates.data();
            colorBlendCreateInfo.blendConstants[0] = 0.0f;
            colorBlendCreateInfo.blendConstants[1] = 0.0f;
            colorBlendCreateInfo.blendConstants[2] = 0.0f;
            colorBlendCreateInfo.blendConstants[3] = 0.0f;

            VkPipelineDynamicStateCreateInfo dynamicStateCreateInfo;
            dynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
            dynamicStateCreateInfo.pNext = nullptr;
            dynamicStateCreateInfo.flags = 0;
            dynamicStateCreateInfo.dynamicStateCount = 0;
            dynamicStateCreateInfo.pDynamicStates = nullptr;
            
            VkPipelineDepthStencilStateCreateInfo depthStencilStateCreateInfo = {};
            depthStencilStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
            depthStencilStateCreateInfo.pNext = nullptr;
            depthStencilStateCreateInfo.depthTestEnable = VK_FALSE;
            depthStencilStateCreateInfo.depthWriteEnable = VK_FALSE;
            depthStencilStateCreateInfo.depthCompareOp = VK_COMPARE_OP_ALWAYS;
            depthStencilStateCreateInfo.depthBoundsTestEnable = VK_FALSE;
            depthStencilStateCreateInfo.stencilTestEnable = pass.stencil_enable;
            depthStencilStateCreateInfo.front.failOp = convertReshadeStencilOp(pass.stencil_op_fail);
            depthStencilStateCreateInfo.front.passOp = convertReshadeStencilOp(pass.stencil_op_pass);
            depthStencilStateCreateInfo.front.depthFailOp = convertReshadeStencilOp(pass.stencil_op_depth_fail);
            depthStencilStateCreateInfo.front.compareOp = convertReshadeCompareOp(pass.stencil_comparison_func);
            depthStencilStateCreateInfo.front.compareMask = pass.stencil_read_mask;
            depthStencilStateCreateInfo.front.writeMask = pass.stencil_write_mask;
            depthStencilStateCreateInfo.front.reference = pass.stencil_reference_value;
            depthStencilStateCreateInfo.back = depthStencilStateCreateInfo.front;
            depthStencilStateCreateInfo.minDepthBounds = 0.0f;
            depthStencilStateCreateInfo.maxDepthBounds = 1.0f;

            VkGraphicsPipelineCreateInfo pipelineCreateInfo;
            pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
            pipelineCreateInfo.pNext = nullptr;
            pipelineCreateInfo.flags = 0;
            pipelineCreateInfo.stageCount = 2;
            pipelineCreateInfo.pStages = shaderStages;
            pipelineCreateInfo.pVertexInputState = &vertexInputCreateInfo;
            pipelineCreateInfo.pInputAssemblyState = &inputAssemblyCreateInfo;
            pipelineCreateInfo.pTessellationState = nullptr;
            pipelineCreateInfo.pViewportState = &viewportStateCreateInfo;
            pipelineCreateInfo.pRasterizationState = &rasterizationCreateInfo;
            pipelineCreateInfo.pMultisampleState = &multisampleCreateInfo;
            pipelineCreateInfo.pDepthStencilState = &depthStencilStateCreateInfo;
            pipelineCreateInfo.pColorBlendState = &colorBlendCreateInfo;
            pipelineCreateInfo.pDynamicState = &dynamicStateCreateInfo;
            pipelineCreateInfo.layout = pipelineLayout;
            pipelineCreateInfo.renderPass = renderPass;
            pipelineCreateInfo.subpass = 0;
            pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
            pipelineCreateInfo.basePipelineIndex = -1;
            
            VkPipeline pipeline;
            result = logicalDevice.vkd.CreateGraphicsPipelines(logicalDevice.device, VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &pipeline);
            ASSERT_VULKAN(result);
                
                
            graphicsPipelines.push_back(pipeline);
            
            std::cout << pass.vs_entry_point << std::endl;
            std::cout << pass.ps_entry_point << std::endl;
            
        }
        std::cout << "finished creating Reshade effect" << std::endl;
    }
    
    void ReshadeEffect::updateEffect()
    {
        if(bufferSize)
        {
            void* data;
            VkResult result = logicalDevice.vkd.MapMemory(logicalDevice.device, stagingBufferMemory, 0, bufferSize, 0, &data);
            ASSERT_VULKAN(result);
            for(auto& uniform: uniforms)
            {
                uniform->update(data);
            }
            logicalDevice.vkd.UnmapMemory(logicalDevice.device, stagingBufferMemory);
        }
    }
    
    void ReshadeEffect::applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer)
    {
        std::cout << "applying ReshadeEffect" << commandBuffer << std::endl;
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
        memoryBarrier.image = outputImages[imageIndex];
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        if(outputWrites > 1)
        {
            memoryBarrier.image = backBufferImages[imageIndex];
            logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        }
        
        //stencil image
        memoryBarrier.image = stencilImage;
        memoryBarrier.srcAccessMask = 0;
        memoryBarrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        memoryBarrier.newLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
        memoryBarrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT | VK_IMAGE_ASPECT_DEPTH_BIT;
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        
        std::cout << "after the first pipeline barrier" << std::endl;
        
        logicalDevice.vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&(inputDescriptorSets[imageIndex]),0,nullptr);
        std::cout << "after binding image sampler" << std::endl;
        
        if(bufferSize)
        {
            logicalDevice.vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&bufferDescriptorSet,0,nullptr);
            std::cout << "after binding uniform buffer" << std::endl;
        }
        
        bool backBufferNext = outputWrites % 2 == 0;
        for(size_t i = 0; i < graphicsPipelines.size(); i++)
        {
            renderPassBeginInfos[i].framebuffer = framebuffers[i][imageIndex];
            
            std::cout << "before beginn renderpass" << std::endl;
            logicalDevice.vkd.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfos[i],VK_SUBPASS_CONTENTS_INLINE);
            std::cout << "after beginn renderpass" << std::endl;
            
            logicalDevice.vkd.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipelines[i]);
            std::cout << "after bind pipeliene" << std::endl;
            
            logicalDevice.vkd.CmdDraw(commandBuffer, module.techniques[0].passes[i].num_vertices, 1, 0, 0);
            std::cout << "after draw" << std::endl;

            logicalDevice.vkd.CmdEndRenderPass(commandBuffer);
            std::cout << "after end renderpass" << std::endl;
            
            if(switchSamplers[i] && outputWrites > 1)
            {
                if(backBufferNext)
                {
                    logicalDevice.vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&(backBufferDescriptorSets[imageIndex]),0,nullptr);
                }
                else if(outputWrites > 2)
                {
                    logicalDevice.vkd.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&(outputDescriptorSets[imageIndex]),0,nullptr);
                }
                backBufferNext = !backBufferNext;
            }
        }
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        secondBarrier.image = outputImages[imageIndex];
        logicalDevice.vkd.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    ReshadeEffect::~ReshadeEffect()
    {
        std::cout << "destroying ReshadeEffect" << this << std::endl;
        for(auto& pipeline: graphicsPipelines)
        {
            logicalDevice.vkd.DestroyPipeline(logicalDevice.device, pipeline, nullptr);
        }
        
        if(bufferSize)
        {
            logicalDevice.vkd.FreeMemory(logicalDevice.device, stagingBufferMemory, nullptr);
            logicalDevice.vkd.DestroyBuffer(logicalDevice.device, stagingBuffer, nullptr);
        }
        
        logicalDevice.vkd.DestroyPipelineLayout(logicalDevice.device, pipelineLayout, nullptr);
        for(auto& renderPass: renderPasses)
        {
            logicalDevice.vkd.DestroyRenderPass(logicalDevice.device, renderPass, nullptr);
        }
        
        logicalDevice.vkd.DestroyDescriptorSetLayout(logicalDevice.device, imageSamplerDescriptorSetLayout, nullptr);
        logicalDevice.vkd.DestroyDescriptorSetLayout(logicalDevice.device, uniformDescriptorSetLayout, nullptr);
        
        logicalDevice.vkd.DestroyShaderModule(logicalDevice.device, shaderModule, nullptr);
        
        logicalDevice.vkd.DestroyDescriptorPool(logicalDevice.device, descriptorPool, nullptr);
        for(auto& imageView: outputImageViewsSRGB)
        {
            logicalDevice.vkd.DestroyImageView(logicalDevice.device,imageView,nullptr);
        }
        for(auto& imageView: outputImageViewsUNORM)
        {
            logicalDevice.vkd.DestroyImageView(logicalDevice.device,imageView,nullptr);
        }
        
        for(auto& imageView: backBufferImageViewsSRGB)
        {
            logicalDevice.vkd.DestroyImageView(logicalDevice.device,imageView,nullptr);
        }
        for(auto& imageView: backBufferImageViewsUNORM)
        {
            logicalDevice.vkd.DestroyImageView(logicalDevice.device,imageView,nullptr);
        }
        
        for(auto& fbs: framebuffers)
        {
            for(auto& fb: fbs)
            {
                logicalDevice.vkd.DestroyFramebuffer(logicalDevice.device, fb, nullptr);
            }
        }
        
        std::set<VkImageView> imageViewSet;
        
        for(auto& it: textureImageViewsSRGB)
        {
            for(auto imageView: it.second)
            {
                imageViewSet.insert(imageView);
            }
        }
        for(auto& it: textureImageViewsUNORM)
        {
            for(auto imageView: it.second)
            {
                imageViewSet.insert(imageView);
            }
        }
        
        for(auto imageView: imageViewSet)
        {
            logicalDevice.vkd.DestroyImageView(logicalDevice.device, imageView, nullptr);
        }
        logicalDevice.vkd.DestroyImageView(logicalDevice.device, stencilImageView, nullptr);
        
        for(auto& it: textureImages)
        {
            for(auto image: it.second)
            {
                logicalDevice.vkd.DestroyImage(logicalDevice.device, image, nullptr);
            }
        }
        
        for(auto& image: backBufferImages)
        {
            logicalDevice.vkd.DestroyImage(logicalDevice.device,image,nullptr);
        }
        
        logicalDevice.vkd.DestroyImage(logicalDevice.device, stencilImage, nullptr);
        
        for(auto& sampler: samplers)
        {
            logicalDevice.vkd.DestroySampler(logicalDevice.device, sampler, nullptr);
        }
        
        for(auto& memory: textureMemory)
        {
            logicalDevice.vkd.FreeMemory(logicalDevice.device, memory, nullptr);
        }
    }
    
    void ReshadeEffect::createReshadeModule()
    {
        std::string tempFile = "/tmp/vkBasalt.spv";
        std::string tempFile2 = "/tmp/vkBasalt.spv";
        
        reshadefx::preprocessor preprocessor;
        preprocessor.add_macro_definition("__RESHADE__", std::to_string(INT_MAX));
        preprocessor.add_macro_definition("__RESHADE_PERFORMANCE_MODE__", "1");
        preprocessor.add_macro_definition("__RENDERER__", "0x20000");
        //TODO add more macros
        
        
        preprocessor.add_macro_definition("BUFFER_WIDTH", std::to_string(imageExtent.width));
        preprocessor.add_macro_definition("BUFFER_HEIGHT", std::to_string(imageExtent.height));
        preprocessor.add_macro_definition("BUFFER_RCP_WIDTH", "(1.0 / BUFFER_WIDTH)");
        preprocessor.add_macro_definition("BUFFER_RCP_HEIGHT", "(1.0 / BUFFER_HEIGHT)");
        preprocessor.add_include_path(pConfig->getOption("reshadeIncludePath"));
        preprocessor.append_file(pConfig->getOption(effectName));

        reshadefx::parser parser;

        std::string errors = preprocessor.errors();
        if(errors != "")
        {
            std::cout << errors << std::endl;
        }
        
        std::unique_ptr<reshadefx::codegen> codegen(
        reshadefx::create_codegen_spirv(true /* vulkan semantics */, true /* debug info */, true /* uniforms to spec constants */, true /*flip vertex shader*/));
        parser.parse(std::move(preprocessor.output()), codegen.get());
        
        errors = parser.errors();
        if(errors != "")
        {
            std::cout << errors << std::endl;
        }
        codegen->write_result(module);
        
        VkShaderModuleCreateInfo shaderCreateInfo;
        shaderCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shaderCreateInfo.pNext = nullptr;
        shaderCreateInfo.flags = 0;
        shaderCreateInfo.codeSize = module.spirv.size() * sizeof(uint32_t);
        shaderCreateInfo.pCode = module.spirv.data();

        VkResult result = logicalDevice.vkd.CreateShaderModule(logicalDevice.device, &shaderCreateInfo, nullptr, &shaderModule);
        ASSERT_VULKAN(result);
            
        std::cout << "after creating shaderModule" << std::endl;
    }
    
    VkFormat ReshadeEffect::convertReshadeFormat(reshadefx::texture_format texFormat)
    {
        switch(texFormat)
        {
            case reshadefx::texture_format::r8:
                return VK_FORMAT_R8_UNORM;
            case reshadefx::texture_format::r16f:
                return VK_FORMAT_R16_SFLOAT;
            case reshadefx::texture_format::r32f:
                return VK_FORMAT_R32_SFLOAT;
            case reshadefx::texture_format::rg8:
                return VK_FORMAT_R8G8_UNORM;
            case reshadefx::texture_format::rg16:
                return VK_FORMAT_R16G16_UNORM;
            case reshadefx::texture_format::rg16f:
                return VK_FORMAT_R16G16_SFLOAT;
            case reshadefx::texture_format::rg32f:
                return VK_FORMAT_R32G32_SFLOAT;
            case reshadefx::texture_format::rgba8:
                return VK_FORMAT_R8G8B8A8_UNORM;
            case reshadefx::texture_format::rgba16:
                return VK_FORMAT_R16G16B16A16_UNORM;
            case reshadefx::texture_format::rgba16f:
                return VK_FORMAT_R16G16B16A16_SFLOAT;
            case reshadefx::texture_format::rgba32f:
                return VK_FORMAT_R32G32B32A32_SFLOAT;
            case reshadefx::texture_format::rgb10a2:
                return VK_FORMAT_A2R10G10B10_UNORM_PACK32;
            default:
                return VK_FORMAT_UNDEFINED;
        }
    }
    
    VkCompareOp ReshadeEffect::convertReshadeCompareOp(uint32_t compareOp)
    {
        switch(compareOp)
		{
		    case 1: return VK_COMPARE_OP_NEVER;
		    case 2: return VK_COMPARE_OP_LESS;
		    case 3: return VK_COMPARE_OP_EQUAL;
		    case 4: return VK_COMPARE_OP_LESS_OR_EQUAL;
		    case 5: return VK_COMPARE_OP_GREATER;
		    case 6: return VK_COMPARE_OP_NOT_EQUAL;
		    case 7: return VK_COMPARE_OP_GREATER_OR_EQUAL;
		    case 8: return VK_COMPARE_OP_ALWAYS;
		    default: return VK_COMPARE_OP_ALWAYS;
		}
    }
    
    VkStencilOp ReshadeEffect::convertReshadeStencilOp(uint32_t stencilOp)
    {
        switch(stencilOp)
        {
	        case 0: return VK_STENCIL_OP_ZERO;
	        case 1: return VK_STENCIL_OP_KEEP;
	        //TODO what is 2?
	        case 3: return VK_STENCIL_OP_REPLACE;
	        case 4: return VK_STENCIL_OP_INCREMENT_AND_CLAMP;
	        case 5: return VK_STENCIL_OP_DECREMENT_AND_CLAMP;
	        case 6: return VK_STENCIL_OP_INVERT;
	        case 7: return VK_STENCIL_OP_INCREMENT_AND_WRAP;
	        case 8: return VK_STENCIL_OP_DECREMENT_AND_WRAP;
	        default: return VK_STENCIL_OP_KEEP;
	    }
    }
    
    VkBlendOp ReshadeEffect::convertReshadeBlendOp(uint32_t blendOp)
    {
        return static_cast<VkBlendOp>(blendOp - 1);
    }
    
    VkBlendFactor ReshadeEffect::convertReshadeBlendFactor(uint32_t blendFactor)
    {
        switch(blendFactor)
		{
		    case 0: return VK_BLEND_FACTOR_ZERO;
		    case 1: return VK_BLEND_FACTOR_ONE;
		    case 2: return VK_BLEND_FACTOR_SRC_COLOR;
		    case 3: return VK_BLEND_FACTOR_SRC_ALPHA;
		    case 4: return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
		    case 5: return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		    case 6: return VK_BLEND_FACTOR_DST_ALPHA;
		    case 7: return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
		    case 8: return VK_BLEND_FACTOR_DST_COLOR;
		    case 9: return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
		    default: return VK_BLEND_FACTOR_ZERO;
		}
    }
}
