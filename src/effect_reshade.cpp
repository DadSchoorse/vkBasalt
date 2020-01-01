#include "effect_reshade.hpp"

#include <cstring>
#include <climits>
#include <cstdlib>
#include <cassert>

#include <set>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"
#include "image.hpp"

#include "stb_image.h"
#include "stb_image_dds.h"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    ReshadeEffect::ReshadeEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, VkQueue queue, VkCommandPool commandPool, std::string effectName)
    {
        std::cout << "in creating ReshadeEffect " << std::endl;
        
        this->physicalDevice = physicalDevice;
        this->instanceDispatchTable = instanceDispatchTable;
        this->device = device;
        this->dispatchTable = dispatchTable;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        this->effectName = effectName;
        inputOutputFormat = format;
        
        
        std::vector<VkImageView> inputImageViews = createImageViews(device, dispatchTable, format, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        outputImageViews = createImageViews(device, dispatchTable, format, outputImages);
        std::cout << "after creating ImageViews" << std::endl;
        
        createReshadeModule();
        
        
        
        std::vector<std::vector<VkImageView>> imageViewVector;
        
        for(size_t i = 0; i < module.textures.size(); i++)
        {
            if(module.textures[i].semantic == "COLOR")
            {
                textureImageViews[module.textures[i].unique_name] = inputImageViews;
                textureFormats[module.textures[i].unique_name] = format;
                continue;
            }
            if(module.textures[i].semantic == "DEPTH")
            {
                textureImageViews[module.textures[i].unique_name] = inputImageViews;;//TODO Depth buffer access
                textureFormats[module.textures[i].unique_name] = format;
                continue;
            }
            VkExtent3D textureExtent = {module.textures[i].width, module.textures[i].height, 1};
            //TODO handel mip map levels correctly
            if(module.textures[i].annotations.size() == 0)
            {
                textureMemory.push_back(VK_NULL_HANDLE);
                std::vector<VkImage> images = createImages(instanceDispatchTable,
                                   device,
                                   dispatchTable,
                                   physicalDevice,
                                   inputImages.size(),
                                   textureExtent,
                                   convertReshadeFormat(module.textures[i].format),//TODO search for format and save it
                                   VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   textureMemory.back());
               
               textureImages[module.textures[i].unique_name] = images;
               std::vector<VkImageView> imageViews = createImageViews(device, dispatchTable, convertReshadeFormat(module.textures[i].format), images);
               textureImageViews[module.textures[i].unique_name] = imageViews;
               textureFormats[module.textures[i].unique_name] = convertReshadeFormat(module.textures[i].format);
               changeImageLayout(instanceDispatchTable,
                               device,
                               dispatchTable,
                               physicalDevice,
                               images,
                               queue,
                               commandPool);
               continue;
            }
            else
            {
                textureMemory.push_back(VK_NULL_HANDLE);
                std::vector<VkImage> images = createImages(instanceDispatchTable,
                                   device,
                                   dispatchTable,
                                   physicalDevice,
                                   1,
                                   textureExtent,
                                   convertReshadeFormat(module.textures[i].format),//TODO search for format and save it
                                   VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                   textureMemory.back());
                textureImages[module.textures[i].unique_name] = images;
                std::vector<VkImageView> imageViews = createImageViews(device, dispatchTable, convertReshadeFormat(module.textures[i].format), images);
                imageViews = std::vector<VkImageView>(inputImages.size(), imageViews[0]);
                textureImageViews[module.textures[i].unique_name] = imageViews;
                textureFormats[module.textures[i].unique_name] = convertReshadeFormat(module.textures[i].format);
                std::string filePath = pConfig->getOption("reshadeTexturePath") + "/" + module.textures[i].annotations[0].value.string_data;
                stbi_uc* pixels;
                uint32_t size;
                if(filePath.find(".dds") != std::string::npos)
                {
                    int channels, width, height;
                    pixels = stbi_dds_load(filePath.c_str(), &width, &height, &channels, STBI_default);//TODO reshade uses STBI_rgb_alpha
                    size = width * height * 4;
                }
                else
                {
                    int channels, width, height;
                    pixels = stbi_load(filePath.c_str(), &width, &height, &channels, STBI_rgb_alpha);
                    size = width * height * 4;
                }
                //TODO make sure the image has the right size
                uploadToImage(instanceDispatchTable,
                       device,
                       dispatchTable,
                       physicalDevice,
                       images[0],
                       textureExtent,
                       size,
                       queue,
                       commandPool,
                       pixels);
                stbi_image_free(pixels);
            }
        }
        
        
        for(size_t i = 0; i < module.samplers.size(); i++)
        {
            reshadefx::sampler_info info = module.samplers[i];
            VkSampler sampler = createReshadeSampler(device, dispatchTable, info);
            samplers.push_back(sampler);
            imageViewVector.push_back(textureImageViews[info.texture_name]);
        }
        
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(device, dispatchTable, module.samplers.size());
        emptyDescriptorSetLayout = createImageSamplerDescriptorSetLayout(device, dispatchTable, 0);
        std::cout << "after creating descriptorSetLayouts" << std::endl;
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size() * module.samplers.size();
        
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};
        
        descriptorPool = createDescriptorPool(device, dispatchTable, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;
        
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts = {emptyDescriptorSetLayout,imageSamplerDescriptorSetLayout};
        pipelineLayout = createGraphicsPipelineLayout(device, dispatchTable, descriptorSetLayouts);
        
        std::cout << "after creating Pipeline layout" << std::endl;
        
        std::cout << "after creating Pipeline" << std::endl;
        
        
        std::cout << samplers.size() << " | " << imageViewVector.size() << std::endl;
        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(device,
                                                                         dispatchTable,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         samplers,
                                                                         imageViewVector);
        
        std::cout << "after writing ImageSamplerDescriptorSets" << std::endl;
        std::cout << "finished creating Reshade effect" << std::endl;
        
        std::cout << "technique_info annotations" << module.techniques[0].annotations.size() << std::endl;
        
        for(auto& pass: module.techniques[0].passes)
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
                attachmentDescription.format = textureFormats[target];
                attachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
                attachmentDescription.loadOp = pass.clear_render_targets ? VK_ATTACHMENT_LOAD_OP_CLEAR : pass.blend_enable ? VK_ATTACHMENT_LOAD_OP_LOAD : VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                attachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
                attachmentDescription.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
                attachmentDescription.initialLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                attachmentDescription.finalLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                
                if(target == "" && i == 0)
                {
                    attachmentDescription.format = inputOutputFormat;
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
                
                
                
            }
            
            //renderpass

            VkSubpassDescription subpassDescription;
            subpassDescription.flags = 0;
            subpassDescription.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
            subpassDescription.inputAttachmentCount = 0;
            subpassDescription.pInputAttachments = nullptr;
            subpassDescription.colorAttachmentCount = attachmentReferences.size();
            subpassDescription.pColorAttachments = attachmentReferences.data();
            subpassDescription.pResolveAttachments = nullptr;
            subpassDescription.pDepthStencilAttachment = nullptr;
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
            VkResult result = dispatchTable.CreateRenderPass(device,&renderPassCreateInfo,nullptr,&renderPass);
            ASSERT_VULKAN(result);
            renderPasses.push_back(renderPass);
            
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
            
            VkRenderPassBeginInfo renderPassBeginInfo;
            renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassBeginInfo.pNext = nullptr;
            renderPassBeginInfo.renderPass = renderPass;
            renderPassBeginInfo.framebuffer = VK_NULL_HANDLE;//changed at apply time
            renderPassBeginInfo.renderArea = scissor;
            renderPassBeginInfo.clearValueCount = attachmentDescriptions.size();
            VkClearValue clearValues[8] = {};
            renderPassBeginInfo.pClearValues = clearValues;
            
            renderPassBeginInfos.push_back(renderPassBeginInfo);
            
            //framebuffers
            
            if(pass.render_target_names[0] == "")
            {
                framebuffers.push_back(createFramebuffers(device, dispatchTable, renderPass, imageExtent, outputImageViews));
            }
            else
            {
                framebuffers.push_back(createFramebuffers(device, dispatchTable, renderPass, imageExtent, textureImageViews[pass.render_target_names[0]]));
            }
            
            //pipeline
            
            VkPipelineShaderStageCreateInfo shaderStageCreateInfoVert;
            shaderStageCreateInfoVert.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shaderStageCreateInfoVert.pNext = nullptr;
            shaderStageCreateInfoVert.flags = 0;
            shaderStageCreateInfoVert.stage = VK_SHADER_STAGE_VERTEX_BIT;
            shaderStageCreateInfoVert.module = (pConfig->getOption("disableSpirvWorkaround") != "1") ? shaderModules[pass.vs_entry_point] : shaderModule;
            shaderStageCreateInfoVert.pName = (pConfig->getOption("disableSpirvWorkaround") != "1") ? "main" : pass.vs_entry_point.c_str();
            shaderStageCreateInfoVert.pSpecializationInfo = nullptr;

            VkPipelineShaderStageCreateInfo shaderStageCreateInfoFrag;
            shaderStageCreateInfoFrag.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shaderStageCreateInfoFrag.pNext = nullptr;
            shaderStageCreateInfoFrag.flags = 0;
            shaderStageCreateInfoFrag.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
            shaderStageCreateInfoFrag.module = (pConfig->getOption("disableSpirvWorkaround") != "1") ? shaderModules[pass.ps_entry_point] : shaderModule;
            shaderStageCreateInfoFrag.pName =  (pConfig->getOption("disableSpirvWorkaround") != "1") ? "main" : pass.ps_entry_point.c_str();
            shaderStageCreateInfoFrag.pSpecializationInfo = nullptr;

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
            pipelineCreateInfo.pDepthStencilState = nullptr;
            pipelineCreateInfo.pColorBlendState = &colorBlendCreateInfo;
            pipelineCreateInfo.pDynamicState = &dynamicStateCreateInfo;
            pipelineCreateInfo.layout = pipelineLayout;
            pipelineCreateInfo.renderPass = renderPass;
            pipelineCreateInfo.subpass = 0;
            pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
            pipelineCreateInfo.basePipelineIndex = -1;
            
            VkPipeline pipeline;
            result = dispatchTable.CreateGraphicsPipelines(device,VK_NULL_HANDLE,1,&pipelineCreateInfo,nullptr,&pipeline);
            ASSERT_VULKAN(result);
                
                
            graphicsPipelines.push_back(pipeline);
            
            std::cout << pass.vs_entry_point << std::endl;
            std::cout << pass.ps_entry_point << std::endl;
            
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
        
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        memoryBarrier.image = outputImages[imageIndex];
        memoryBarrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &memoryBarrier);
        std::cout << "after the first pipeline barrier" << std::endl;
        
        for(size_t i = 0; i < graphicsPipelines.size(); i++)
        {
            renderPassBeginInfos[i].framebuffer = framebuffers[i][imageIndex];
            
            std::cout << "before beginn renderpass" << std::endl;
            dispatchTable.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfos[i],VK_SUBPASS_CONTENTS_INLINE);
            std::cout << "after beginn renderpass" << std::endl;
            
            dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
            std::cout << "after binding image sampler" << std::endl;
            
            dispatchTable.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipelines[i]);
            std::cout << "after bind pipeliene" << std::endl;
            
            dispatchTable.CmdDraw(commandBuffer, module.techniques[0].passes[i].num_vertices, 1, 0, 0);
            std::cout << "after draw" << std::endl;

            dispatchTable.CmdEndRenderPass(commandBuffer);
            std::cout << "after end renderpass" << std::endl;
        }
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        secondBarrier.image = outputImages[imageIndex];
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    ReshadeEffect::~ReshadeEffect()
    {
        std::cout << "destroying ReshadeEffect" << this << std::endl;
        for(auto& pipeline: graphicsPipelines)
        {
            dispatchTable.DestroyPipeline(device, pipeline, nullptr);
        }
        
        dispatchTable.DestroyPipelineLayout(device,pipelineLayout,nullptr);
        for(auto& renderPass: renderPasses)
        {
            dispatchTable.DestroyRenderPass(device,renderPass,nullptr);
        }
        
        dispatchTable.DestroyDescriptorSetLayout(device,imageSamplerDescriptorSetLayout,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,emptyDescriptorSetLayout,nullptr);
        for(auto& it: shaderModules)
        {
            dispatchTable.DestroyShaderModule(device, it.second, nullptr);
        }
        
        if(pConfig->getOption("disableSpirvWorkaround") == "1")
        {
            dispatchTable.DestroyShaderModule(device, shaderModule, nullptr);
        }
        
        dispatchTable.DestroyDescriptorPool(device,descriptorPool,nullptr);
        for(unsigned int i=0;i<outputImageViews.size();i++)
        {
            dispatchTable.DestroyImageView(device,outputImageViews[i],nullptr);
        }
        
        for(auto& fbs: framebuffers)
        {
            for(auto& fb: fbs)
            {
                dispatchTable.DestroyFramebuffer(device, fb, nullptr);
            }
        }
        
        std::set<VkImageView> imageViewSet;
        
        for(auto& it: textureImageViews)
        {
            for(auto imageView: it.second)
            {
                imageViewSet.insert(imageView);
            }
        }
        
        for(auto imageView: imageViewSet)
        {
            dispatchTable.DestroyImageView(device, imageView, nullptr);
        }
        
        for(auto& it: textureImages)
        {
            for(auto image: it.second)
            {
                dispatchTable.DestroyImage(device, image, nullptr);
            }
        }
        
        for(auto& sampler: samplers)
        {
            dispatchTable.DestroySampler(device,sampler,nullptr);
        }
        
        for(auto& memory: textureMemory)
        {
            dispatchTable.FreeMemory(device,memory,nullptr);
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
        reshadefx::create_codegen_spirv(true /* vulkan semantics */, false /* debug info */, true /* uniforms to spec constants */, true /*flip vertex shader*/));
        if (!parser.parse(std::move(preprocessor.output()), codegen.get()))
        {
            throw std::runtime_error("reshade shader creation failed");
        }
        
        errors = parser.errors();
        if(errors != "")
        {
            std::cout << errors << std::endl;
        }
        codegen->write_result(module);
        
        if(pConfig->getOption("disableSpirvWorkaround") != "1")
        {
            std::ofstream(tempFile, std::ios::binary).write(reinterpret_cast<const char *>(module.spirv.data()), module.spirv.size() * sizeof(uint32_t));
        
            for(size_t i = 0; i < module.entry_points.size(); i++)
            {
                std::string stage = module.entry_points[i].is_pixel_shader ? "frag" : "vert";
                std::string command = "spirv-cross " + tempFile + " --vulkan-semantics --entry " + module.entry_points[i].name;
                command += " | glslangValidator -V --stdin -S " + stage + " -o " + tempFile2 + std::to_string(i);
                assert(!std::system(command.c_str()));
                shaderCode.push_back(readFile(tempFile2 + std::to_string(i)));
                std::cout << shaderCode[i].size() << std::endl;
            
                createShaderModule(device, dispatchTable, shaderCode[i], &shaderModules[module.entry_points[i].name]);
            }
        }
        else
        {
            VkShaderModuleCreateInfo shaderCreateInfo;
            shaderCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            shaderCreateInfo.pNext = nullptr;
            shaderCreateInfo.flags = 0;
            shaderCreateInfo.codeSize = module.spirv.size() * sizeof(uint32_t);
            shaderCreateInfo.pCode = module.spirv.data();

            VkResult result = dispatchTable.CreateShaderModule(device, &shaderCreateInfo, nullptr, &shaderModule);
            ASSERT_VULKAN(result);
        }
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
