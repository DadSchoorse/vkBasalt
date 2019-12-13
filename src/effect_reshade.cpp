#include "effect_reshade.hpp"

#include <cstring>
#include <climits>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    ReshadeEffect::ReshadeEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig, VkQueue queue, VkCommandPool commandPool)
    {
        std::cout << "in creating ReshadeEffect " << std::endl;
        
        std::string shaderFile = "reshade.spv";
        std::string fragmentFile = "reshade2.spv";
        
        this->physicalDevice = physicalDevice;
        this->instanceDispatchTable = instanceDispatchTable;
        this->device = device;
        this->dispatchTable = dispatchTable;
        this->format = format;
        this->imageExtent = imageExtent;
        this->inputImages = inputImages;
        this->outputImages = outputImages;
        this->pConfig = pConfig;
        
        inputImageViews = createImageViews(device, dispatchTable, format, inputImages);
        std::cout << "after creating input ImageViews" << std::endl;
        outputImageViews = createImageViews(device, dispatchTable, format, outputImages);
        std::cout << "after creating ImageViews" << std::endl;
        sampler = createSampler(device, dispatchTable);
        std::cout << "after creating sampler" << std::endl;
        
        imageSamplerDescriptorSetLayout = createImageSamplerDescriptorSetLayout(device, dispatchTable, 2);
        std::cout << "after creating descriptorSetLayouts" << std::endl;
        
        VkDescriptorPoolSize imagePoolSize;
        imagePoolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        imagePoolSize.descriptorCount = inputImages.size()+10;
        
        
        std::vector<VkDescriptorPoolSize> poolSizes = {imagePoolSize};
        
        descriptorPool = createDescriptorPool(device, dispatchTable, poolSizes);
        std::cout << "after creating descriptorPool" << std::endl;
        
        std::vector<char> shaderCode = readFile(shaderFile);
        createShaderModule(device, dispatchTable, shaderCode, &shaderModule);
        shaderCode = readFile(fragmentFile);
        createShaderModule(device, dispatchTable, shaderCode, &fragmentModule);
        
        std::cout << "after creating shaderModule" << std::endl;
        
        renderPass = createRenderPass(device, dispatchTable, format);
        
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts = {imageSamplerDescriptorSetLayout,imageSamplerDescriptorSetLayout};
        pipelineLayout = createGraphicsPipelineLayout(device, dispatchTable, descriptorSetLayouts);
        
        std::cout << "after creating Pipeline layout" << std::endl;
        
        graphicsPipeline = createGraphicsPipeline(device, dispatchTable, shaderModule, nullptr, "F__PostProcessVS", fragmentModule, nullptr, "F__Colourfulness", imageExtent, renderPass, pipelineLayout, true);
        
        std::cout << "after creating Pipeline" << std::endl;
        
        std::vector<std::vector<VkImageView>> imageViewVector = {inputImageViews,inputImageViews};
        imageDescriptorSets = allocateAndWriteImageSamplerDescriptorSets(device,
                                                                         dispatchTable,
                                                                         descriptorPool,
                                                                         imageSamplerDescriptorSetLayout,
                                                                         sampler,
                                                                         imageViewVector);
        
        std::cout << "after writing ImageSamplerDescriptorSets" << std::endl;
        
        framebuffers = createFramebuffers(device, dispatchTable, renderPass, imageExtent, outputImageViews);
        
        std::cout << "finished creating Reshade effect" << std::endl;
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
        
        std::cout << "framebuffer " << framebuffers.size() << std::endl;
        
        std::cout << "framebuffer " << framebuffers[imageIndex] << std::endl;

        VkRenderPassBeginInfo renderPassBeginInfo;
        renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassBeginInfo.pNext = nullptr;
        renderPassBeginInfo.renderPass = renderPass;
        renderPassBeginInfo.framebuffer = framebuffers[imageIndex];
        renderPassBeginInfo.renderArea.offset = {0,0};
        renderPassBeginInfo.renderArea.extent = imageExtent;
        VkClearValue clearValue = {0.0f, 0.0f, 0.0f, 1.0f};
        renderPassBeginInfo.clearValueCount = 1;
        renderPassBeginInfo.pClearValues = &clearValue;
        
        std::cout << "before beginn renderpass" << std::endl;
        dispatchTable.CmdBeginRenderPass(commandBuffer,&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);
        std::cout << "after beginn renderpass" << std::endl;
        
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,1,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        dispatchTable.CmdBindDescriptorSets(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,pipelineLayout,0,1,&(imageDescriptorSets[imageIndex]),0,nullptr);
        std::cout << "after binding image sampler" << std::endl;
        
        dispatchTable.CmdBindPipeline(commandBuffer,VK_PIPELINE_BIND_POINT_GRAPHICS,graphicsPipeline);
        std::cout << "after bind pipeliene" << std::endl;
        
        dispatchTable.CmdDraw(commandBuffer, 3, 1, 0, 0);
        std::cout << "after draw" << std::endl;

        dispatchTable.CmdEndRenderPass(commandBuffer);
        std::cout << "after end renderpass" << std::endl;
        
        dispatchTable.CmdPipelineBarrier(commandBuffer,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0, nullptr,0, nullptr,1, &secondBarrier);
        std::cout << "after the second pipeline barrier" << std::endl;

    }
    ReshadeEffect::~ReshadeEffect()
    {
        std::cout << "destroying ReshadeEffect" << this << std::endl;
        dispatchTable.DestroyPipeline(device, graphicsPipeline, nullptr);
        dispatchTable.DestroyPipelineLayout(device,pipelineLayout,nullptr);
        dispatchTable.DestroyRenderPass(device,renderPass,nullptr);
        dispatchTable.DestroyDescriptorSetLayout(device,imageSamplerDescriptorSetLayout,nullptr);
        dispatchTable.DestroyShaderModule(device,shaderModule,nullptr);
        dispatchTable.DestroyShaderModule(device,fragmentModule,nullptr);
        
        dispatchTable.DestroyDescriptorPool(device,descriptorPool,nullptr);
        for(unsigned int i=0;i<framebuffers.size();i++)
        {
            dispatchTable.DestroyFramebuffer(device,framebuffers[i],nullptr);
            dispatchTable.DestroyImageView(device,inputImageViews[i],nullptr);
            dispatchTable.DestroyImageView(device,outputImageViews[i],nullptr);
            std::cout << "after DestroyImageView" << std::endl;
        }
        dispatchTable.DestroySampler(device,sampler,nullptr);
    }
    
    void ReshadeEffect::createReshadeModule(reshadefx::module& module)
    {
        reshadefx::preprocessor preprocessor;
        preprocessor.add_macro_definition("__RESHADE__", std::to_string(INT_MAX));
        preprocessor.add_macro_definition("__RESHADE_PERFORMANCE_MODE__", "1");
        
        preprocessor.add_macro_definition("BUFFER_WIDTH", std::to_string(imageExtent.width));
        preprocessor.add_macro_definition("BUFFER_HEIGHT", std::to_string(imageExtent.height));
        preprocessor.add_macro_definition("BUFFER_RCP_WIDTH", "(1.0 / BUFFER_WIDTH)");
        preprocessor.add_macro_definition("BUFFER_RCP_HEIGHT", "(1.0 / BUFFER_HEIGHT)");
        preprocessor.add_include_path(includePath);
        preprocessor.append_file(shaderFile);

        reshadefx::parser parser;

        std::string errors = preprocessor.errors();
        if(errors != "")
        {
            std::cout << errors << std::endl;
        }
        
         std::unique_ptr<reshadefx::codegen> codegen(
        reshadefx::create_codegen_spirv(true /* vulkan semantics */, false /* debug info */, true /* uniforms to spec constants */));
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
    }
}
