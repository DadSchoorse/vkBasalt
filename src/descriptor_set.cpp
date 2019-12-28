#include "descriptor_set.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
        
    VkDescriptorPool createDescriptorPool(VkDevice device, VkLayerDispatchTable dispatchTable, const std::vector<VkDescriptorPoolSize>& poolSizes)
    {
        uint32_t setCount = 0;
        VkDescriptorPool descriptorPool;
        for(uint32_t i=0;i<poolSizes.size();i++)
        {
            setCount += poolSizes[i].descriptorCount;
        }
        VkDescriptorPoolCreateInfo descriptorPoolCreateInfo;
        descriptorPoolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        descriptorPoolCreateInfo.pNext = nullptr;
        descriptorPoolCreateInfo.flags = 0;
        descriptorPoolCreateInfo.maxSets = setCount;
        descriptorPoolCreateInfo.poolSizeCount = poolSizes.size();
        descriptorPoolCreateInfo.pPoolSizes = poolSizes.data();

        VkResult result =  dispatchTable.CreateDescriptorPool(device,&descriptorPoolCreateInfo,nullptr,&descriptorPool);
        ASSERT_VULKAN(result);
        return descriptorPool;
    }
    
    
    
    VkDescriptorSetLayout createUniformBufferDescriptorSetLayout(VkDevice device, VkLayerDispatchTable dispatchTable)
    {
        VkDescriptorSetLayout descriptorSetLayout;
        
        VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
        descriptorSetLayoutBinding.binding = 0;
        descriptorSetLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorSetLayoutBinding.descriptorCount = 1;
        descriptorSetLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT | VK_SHADER_STAGE_VERTEX_BIT;
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
    
    VkDescriptorSetLayout createImageSamplerDescriptorSetLayout(VkDevice device, VkLayerDispatchTable dispatchTable, uint32_t count)
    {
        VkDescriptorSetLayout descriptorSetLayout;
        
        std::vector<VkDescriptorSetLayoutBinding> bindigs(count);
        for(uint32_t i=0;i<count;i++)
        {
            VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
            descriptorSetLayoutBinding.binding = i;
            descriptorSetLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            descriptorSetLayoutBinding.descriptorCount = 1;
            descriptorSetLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
            descriptorSetLayoutBinding.pImmutableSamplers = nullptr;
            bindigs[i] = descriptorSetLayoutBinding;
        }

        VkDescriptorSetLayoutCreateInfo descriptorSetCreateInfo;
        descriptorSetCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetCreateInfo.pNext = nullptr;
        descriptorSetCreateInfo.flags = 0;
        descriptorSetCreateInfo.bindingCount = count;
        descriptorSetCreateInfo.pBindings = bindigs.data();

        
        VkResult result = dispatchTable.CreateDescriptorSetLayout(device,&descriptorSetCreateInfo,nullptr,&descriptorSetLayout);
        ASSERT_VULKAN(result)
        return descriptorSetLayout;
        
    }

    std::vector<VkDescriptorSet> allocateAndWriteImageSamplerDescriptorSets(VkDevice device, VkLayerDispatchTable dispatchTable, VkDescriptorPool descriptorPool, VkDescriptorSetLayout descriptorSetLayout, std::vector<VkSampler> samplers, std::vector<std::vector<VkImageView>> imageViewsVectors)
    {
        std::vector<VkDescriptorSet> descriptorSets(imageViewsVectors[0].size());
        
        std::vector<VkDescriptorSetLayout> layouts(descriptorSets.size(),descriptorSetLayout);
        VkDescriptorSetAllocateInfo descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext = nullptr;
        descriptorSetAllocateInfo.descriptorPool = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = descriptorSets.size();
        descriptorSetAllocateInfo.pSetLayouts = layouts.data();
        
        std::cout << "before allocating descriptor Sets " << 1 << std::endl;
        VkResult result =  dispatchTable.AllocateDescriptorSets(device,&descriptorSetAllocateInfo,descriptorSets.data());
        ASSERT_VULKAN(result);

        VkDescriptorImageInfo imageInfo;
        imageInfo.sampler = VK_NULL_HANDLE;
        imageInfo.imageView = VK_NULL_HANDLE;
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        std::vector<VkDescriptorImageInfo> imageInfos(imageViewsVectors.size(), imageInfo);

        VkWriteDescriptorSet writeDescriptorSet = {};
        writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writeDescriptorSet.pNext = nullptr;
        writeDescriptorSet.dstSet = VK_NULL_HANDLE;
        writeDescriptorSet.dstBinding = 0;
        writeDescriptorSet.dstArrayElement = 0;
        writeDescriptorSet.descriptorCount = 1;
        writeDescriptorSet.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        writeDescriptorSet.pImageInfo = nullptr;
        writeDescriptorSet.pBufferInfo = nullptr;
        writeDescriptorSet.pTexelBufferView = nullptr;
        
        std::vector<VkWriteDescriptorSet> writeDescriptorSets(imageViewsVectors.size(), writeDescriptorSet);
        
        for(unsigned int i=0;i<descriptorSets.size();i++)
        {
            for(uint32_t j=0;j<imageViewsVectors.size();j++)
            {
                imageInfos[j].sampler = samplers[j];
                imageInfos[j].imageView = imageViewsVectors[j][i];
                writeDescriptorSets[j].dstBinding = j;
                writeDescriptorSets[j].pImageInfo = &imageInfos[j];
                writeDescriptorSets[j].dstSet = descriptorSets[i];
            }
            std::cout << "before writing descriptor Sets " << std::endl;
            dispatchTable.UpdateDescriptorSets(device,writeDescriptorSets.size(),writeDescriptorSets.data(),0,nullptr);
            
        }
        return descriptorSets;
    }
}
