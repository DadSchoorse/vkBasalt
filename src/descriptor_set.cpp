#include "descriptor_set.hpp"

namespace vkBasalt
{
    void createStorageImageDescriptorSetLayout(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, VkDescriptorSetLayout& descriptorSetLayout)
    {
        VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
        descriptorSetLayoutBinding.binding = 0;
        descriptorSetLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
        descriptorSetLayoutBinding.descriptorCount = 1;
        descriptorSetLayoutBinding.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
        descriptorSetLayoutBinding.pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutCreateInfo descriptorSetCreateInfo;
        descriptorSetCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetCreateInfo.pNext = nullptr;
        descriptorSetCreateInfo.flags = 0;
        descriptorSetCreateInfo.bindingCount = 1;
        descriptorSetCreateInfo.pBindings = &descriptorSetLayoutBinding;

        VkResult result = dispatchTable.CreateDescriptorSetLayout(device,&descriptorSetCreateInfo,nullptr,&descriptorSetLayout);
    }
    void createStorageImageDescriptorPool(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const uint32_t& setCount, VkDescriptorPool& descriptorPool)
    {
        VkDescriptorPoolSize poolSize;
        poolSize.type = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
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
    }
    void allocateAndWriteStorageDescriptorSets(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const VkDescriptorPool& descriptorPool, const uint32_t& setCount, const VkDescriptorSetLayout& descriptorSetLayout,const  VkImageView* imageViews, VkDescriptorSet* descriptorSets)
    {
        const std::vector<VkDescriptorSetLayout> descriptorSetLayouts(setCount, descriptorSetLayout);
        VkDescriptorSetAllocateInfo descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext = nullptr;
        descriptorSetAllocateInfo.descriptorPool = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = setCount;
        descriptorSetAllocateInfo.pSetLayouts = descriptorSetLayouts.data();
        
        std::cout << "before allocating descriptor Sets " << 1 << std::endl;
        VkResult result =  dispatchTable.AllocateDescriptorSets(device,&descriptorSetAllocateInfo,descriptorSets);

        VkDescriptorImageInfo imageInfo;
        imageInfo.sampler = VK_NULL_HANDLE;
        imageInfo.imageView = VK_NULL_HANDLE;
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_GENERAL;

        VkWriteDescriptorSet writeDescriptorSet = {};
        writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writeDescriptorSet.pNext = nullptr;
        writeDescriptorSet.dstSet = VK_NULL_HANDLE;
        writeDescriptorSet.dstBinding = 0;
        writeDescriptorSet.dstArrayElement = 0;
        writeDescriptorSet.descriptorCount = 1;
        writeDescriptorSet.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
        writeDescriptorSet.pImageInfo = &imageInfo;
        writeDescriptorSet.pBufferInfo = nullptr;
        writeDescriptorSet.pTexelBufferView = nullptr;
        
        for(int i=0;i<setCount;i++)
        {
            imageInfo.imageView = imageViews[i];
            writeDescriptorSet.dstSet = descriptorSets[i];
            std::cout << "before writing descriptor Sets " << std::endl;
            dispatchTable.UpdateDescriptorSets(device,1,&writeDescriptorSet,0,nullptr);
        }

        
    }
}
