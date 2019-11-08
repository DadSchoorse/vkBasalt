#include "descriptor_set.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

typedef struct {
    float sharpness;
} CasBufferObject;

namespace vkBasalt
{
    VkDescriptorSetLayout createUniformBufferDescriptorSetLayout(VkDevice device, VkLayerDispatchTable dispatchTable)
    {
        VkDescriptorSetLayout descriptorSetLayout;
        
        VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
        descriptorSetLayoutBinding.binding = 0;
        descriptorSetLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorSetLayoutBinding.descriptorCount = 1;
        descriptorSetLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
        descriptorSetLayoutBinding.pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutCreateInfo descriptorSetCreateInfo;
        descriptorSetCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetCreateInfo.pNext = nullptr;
        descriptorSetCreateInfo.flags = 0;
        descriptorSetCreateInfo.bindingCount = 1;
        descriptorSetCreateInfo.pBindings = &descriptorSetLayoutBinding;

        
        VkResult result = dispatchTable.CreateDescriptorSetLayout(device,&descriptorSetCreateInfo,nullptr,&descriptorSetLayout);
        ASSERT_VULKAN(result)
        
        return descriptorSetLayout;
    }
    VkDescriptorPool createUniformBufferDescriptorPool(VkDevice device, VkLayerDispatchTable dispatchTable, uint32_t setCount)
    {
        VkDescriptorPool descriptorPool;
        VkDescriptorPoolSize poolSize;
        poolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        poolSize.descriptorCount = setCount;
        
        std::cout << "set count " << setCount << std::endl;

        VkDescriptorPoolCreateInfo descriptorPoolCreateInfo;
        descriptorPoolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        descriptorPoolCreateInfo.pNext = nullptr;
        descriptorPoolCreateInfo.flags = 0;
        descriptorPoolCreateInfo.maxSets = setCount;
        descriptorPoolCreateInfo.poolSizeCount = 1;
        descriptorPoolCreateInfo.pPoolSizes = &poolSize;

        VkResult result =  dispatchTable.CreateDescriptorPool(device,&descriptorPoolCreateInfo,nullptr,&descriptorPool);
        ASSERT_VULKAN(result);
        return descriptorPool;
    }
    VkDescriptorSet writeCasBufferDescriptorSet(VkDevice device, VkLayerDispatchTable dispatchTable, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, VkBuffer buffer)
    {
        VkDescriptorSet descriptorSet;
        
        VkDescriptorSetAllocateInfo descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext = nullptr;
        descriptorSetAllocateInfo.descriptorPool = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = 1;
        descriptorSetAllocateInfo.pSetLayouts = &descriptorSetLayout;
        
        VkResult result =  dispatchTable.AllocateDescriptorSets(device,&descriptorSetAllocateInfo,&descriptorSet);
        ASSERT_VULKAN(result);
        
        VkDescriptorBufferInfo bufferInfo;
        bufferInfo.buffer = buffer;
        bufferInfo.offset = 0;
        bufferInfo.range = VK_WHOLE_SIZE;
        
        VkWriteDescriptorSet writeDescriptorSet = {};
        writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writeDescriptorSet.pNext = nullptr;
        writeDescriptorSet.dstSet = descriptorSet;
        writeDescriptorSet.dstBinding = 0;
        writeDescriptorSet.dstArrayElement = 0;
        writeDescriptorSet.descriptorCount = 1;
        writeDescriptorSet.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        writeDescriptorSet.pImageInfo =  nullptr;
        writeDescriptorSet.pBufferInfo = &bufferInfo;
        writeDescriptorSet.pTexelBufferView = nullptr;
        
        std::cout << "before writing buffer descriptor Sets " << std::endl;
        dispatchTable.UpdateDescriptorSets(device,1,&writeDescriptorSet,0,nullptr);
        
        return descriptorSet;
    }
    
    VkDescriptorSetLayout createImageSamplerDescriptorSetLayout(VkDevice device, VkLayerDispatchTable dispatchTable)
    {
        VkDescriptorSetLayout descriptorSetLayout;
        
        VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
        descriptorSetLayoutBinding.binding = 0;
        descriptorSetLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptorSetLayoutBinding.descriptorCount = 1;
        descriptorSetLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
        descriptorSetLayoutBinding.pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutCreateInfo descriptorSetCreateInfo;
        descriptorSetCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetCreateInfo.pNext = nullptr;
        descriptorSetCreateInfo.flags = 0;
        descriptorSetCreateInfo.bindingCount = 1;
        descriptorSetCreateInfo.pBindings = &descriptorSetLayoutBinding;

        
        VkResult result = dispatchTable.CreateDescriptorSetLayout(device,&descriptorSetCreateInfo,nullptr,&descriptorSetLayout);
        ASSERT_VULKAN(result)
        return descriptorSetLayout;
        
    }
    
    VkDescriptorPool createImageSamplerDescriptorPool(VkDevice device, VkLayerDispatchTable dispatchTable, uint32_t setCount)
    {
        VkDescriptorPool descriptorPool;
        
        VkDescriptorPoolSize poolSize;
        poolSize.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        poolSize.descriptorCount = setCount;
        
        std::cout << "set count " << setCount << std::endl;

        VkDescriptorPoolCreateInfo descriptorPoolCreateInfo;
        descriptorPoolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        descriptorPoolCreateInfo.pNext = nullptr;
        descriptorPoolCreateInfo.flags = 0;
        descriptorPoolCreateInfo.maxSets = setCount;
        descriptorPoolCreateInfo.poolSizeCount = 1;
        descriptorPoolCreateInfo.pPoolSizes = &poolSize;

        VkResult result = dispatchTable.CreateDescriptorPool(device,&descriptorPoolCreateInfo,nullptr,&descriptorPool);
        ASSERT_VULKAN(result);
        
        return descriptorPool;
    }
    
    std::vector<VkDescriptorSet> allocateAndWriteImageSamplerDescriptorSets(VkDevice device, VkLayerDispatchTable dispatchTable, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, VkSampler sampler, std::vector<VkImageView> imageViews)
    {
        std::vector<VkDescriptorSet> descriptorSets(imageViews.size());
        
        std::vector<VkDescriptorSetLayout> layouts(setCount,descriptorSetLayout);
        VkDescriptorSetAllocateInfo descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext = nullptr;
        descriptorSetAllocateInfo.descriptorPool = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = setCount;
        descriptorSetAllocateInfo.pSetLayouts = layouts.data();
        
        std::cout << "before allocating descriptor Sets " << 1 << std::endl;
        VkResult result =  dispatchTable.AllocateDescriptorSets(device,&descriptorSetAllocateInfo,descriptorSets.data());
        ASSERT_VULKAN(result);

        VkDescriptorImageInfo imageInfo;
        imageInfo.sampler = sampler;
        imageInfo.imageView = VK_NULL_HANDLE;
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

        VkWriteDescriptorSet writeDescriptorSet = {};
        writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writeDescriptorSet.pNext = nullptr;
        writeDescriptorSet.dstSet = VK_NULL_HANDLE;
        writeDescriptorSet.dstBinding = 0;
        writeDescriptorSet.dstArrayElement = 0;
        writeDescriptorSet.descriptorCount = 1;
        writeDescriptorSet.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        writeDescriptorSet.pImageInfo = &imageInfo;
        writeDescriptorSet.pBufferInfo = nullptr;
        writeDescriptorSet.pTexelBufferView = nullptr;
        
        for(unsigned int i=0;i<setCount;i++)
        {
            imageInfo.imageView = imageViews[i];
            writeDescriptorSet.dstSet = descriptorSets[i];
            std::cout << "before writing descriptor Sets " << std::endl;
            dispatchTable.UpdateDescriptorSets(device,1,&writeDescriptorSet,0,nullptr);
            
        }
        return descriptorSets;
    }
}
