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
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        this->effectName = effectName;
        
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
                continue;
            }
            if(module.textures[i].semantic == "DEPTH")
            {
                textureImageViews[module.textures[i].unique_name] = inputImageViews;;//TODO Depth buffer access
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
                std::string filePath = pConfig->getOption("reshadeTexturePath") + "/" + module.textures[i].annotations[0].value.string_data;
                stbi_uc* pixels;
                uint32_t size;
                if(filePath.find(".dds") != std::string::npos)
                {
                    int channels, width, height;
                    pixels = stbi_dds_load(filePath.c_str(), &width, &height, &channels, STBI_rgb_alpha);
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
        
        renderPass = createRenderPass(device, dispatchTable, format);
        
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
            for(auto& target: pass.render_target_names)
            {
                std::cout << target << std::endl;
            }
            if(pass.render_target_names[0] == "")
            {
                framebuffers.push_back(createFramebuffers(device, dispatchTable, renderPass, imageExtent, outputImageViews));
            }
            else
            {
                framebuffers.push_back(createFramebuffers(device, dispatchTable, renderPass, imageExtent, textureImageViews[pass.render_target_names[0]]));
            }
            
            graphicsPipelines.push_back(createGraphicsPipeline(device,
                                                               dispatchTable,
                                                               shaderModules[pass.vs_entry_point], nullptr, "main",
                                                               shaderModules[pass.ps_entry_point], nullptr, "main",
                                                               imageExtent, renderPass, pipelineLayout));
            
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
        std::cout << "after the first pipeline barrier" << std::endl;
        
        for(size_t i = 0; i < graphicsPipelines.size(); i++)
        {
            VkRenderPassBeginInfo renderPassBeginInfo;
            renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassBeginInfo.pNext = nullptr;
            renderPassBeginInfo.renderPass = renderPass;
            renderPassBeginInfo.framebuffer = framebuffers[i][imageIndex];
            renderPassBeginInfo.renderArea.offset = {0,0};
            renderPassBeginInfo.renderArea.extent = imageExtent;
            VkClearValue clearValue = {0.0f, 0.0f, 0.0f, 1.0f};
            renderPassBeginInfo.clearValueCount = 1;
            renderPassBeginInfo.pClearValues = &clearValue;
            
            std::cout << "before beginn renderpass" << std::endl;
            dispatchTable.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
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
        dispatchTable.DestroyRenderPass(device,renderPass,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,imageSamplerDescriptorSetLayout,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,emptyDescriptorSetLayout,nullptr);
        for(auto& it: shaderModules)
        {
            dispatchTable.DestroyShaderModule(device, it.second, nullptr);
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
}
