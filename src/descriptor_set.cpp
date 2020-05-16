#include "descriptor_set.hpp"

namespace vkBasalt
{

    VkDescriptorPool createDescriptorPool(LogicalDevice* pLogicalDevice, const std::vector<VkDescriptorPoolSize>& poolSizes)
    {
        uint32_t setCount = 0;

        VkDescriptorPool descriptorPool;
        for (uint32_t i = 0; i < poolSizes.size(); i++)
        {
            setCount += poolSizes[i].descriptorCount;
        }
        VkDescriptorPoolCreateInfo descriptorPoolCreateInfo;
        descriptorPoolCreateInfo.sType         = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        descriptorPoolCreateInfo.pNext         = nullptr;
        descriptorPoolCreateInfo.flags         = 0;
        descriptorPoolCreateInfo.maxSets       = setCount;
        descriptorPoolCreateInfo.poolSizeCount = poolSizes.size();
        descriptorPoolCreateInfo.pPoolSizes    = poolSizes.data();

        VkResult result = pLogicalDevice->vkd.CreateDescriptorPool(pLogicalDevice->device, &descriptorPoolCreateInfo, nullptr, &descriptorPool);
        ASSERT_VULKAN(result);
        return descriptorPool;
    }

    VkDescriptorSetLayout createUniformBufferDescriptorSetLayout(LogicalDevice* pLogicalDevice)
    {
        VkDescriptorSetLayout descriptorSetLayout;

        VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
        descriptorSetLayoutBinding.binding            = 0;
        descriptorSetLayoutBinding.descriptorType     = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorSetLayoutBinding.descriptorCount    = 1;
        descriptorSetLayoutBinding.stageFlags         = VK_SHADER_STAGE_FRAGMENT_BIT | VK_SHADER_STAGE_VERTEX_BIT;
        descriptorSetLayoutBinding.pImmutableSamplers = nullptr;

        VkDescriptorSetLayoutCreateInfo descriptorSetCreateInfo;
        descriptorSetCreateInfo.sType        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetCreateInfo.pNext        = nullptr;
        descriptorSetCreateInfo.flags        = 0;
        descriptorSetCreateInfo.bindingCount = 1;
        descriptorSetCreateInfo.pBindings    = &descriptorSetLayoutBinding;

        VkResult result =
            pLogicalDevice->vkd.CreateDescriptorSetLayout(pLogicalDevice->device, &descriptorSetCreateInfo, nullptr, &descriptorSetLayout);
        ASSERT_VULKAN(result)

        return descriptorSetLayout;
    }

    VkDescriptorSet writeBufferDescriptorSet(LogicalDevice*        pLogicalDevice,
                                             VkDescriptorPool      descriptorPool,
                                             VkDescriptorSetLayout descriptorSetLayout,
                                             VkBuffer              buffer)
    {
        VkDescriptorSet descriptorSet;

        VkDescriptorSetAllocateInfo descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType              = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext              = nullptr;
        descriptorSetAllocateInfo.descriptorPool     = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = 1;
        descriptorSetAllocateInfo.pSetLayouts        = &descriptorSetLayout;

        VkResult result = pLogicalDevice->vkd.AllocateDescriptorSets(pLogicalDevice->device, &descriptorSetAllocateInfo, &descriptorSet);
        ASSERT_VULKAN(result);

        VkDescriptorBufferInfo bufferInfo;
        bufferInfo.buffer = buffer;
        bufferInfo.offset = 0;
        bufferInfo.range  = VK_WHOLE_SIZE;

        VkWriteDescriptorSet writeDescriptorSet = {};

        writeDescriptorSet.sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writeDescriptorSet.pNext            = nullptr;
        writeDescriptorSet.dstSet           = descriptorSet;
        writeDescriptorSet.dstBinding       = 0;
        writeDescriptorSet.dstArrayElement  = 0;
        writeDescriptorSet.descriptorCount  = 1;
        writeDescriptorSet.descriptorType   = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        writeDescriptorSet.pImageInfo       = nullptr;
        writeDescriptorSet.pBufferInfo      = &bufferInfo;
        writeDescriptorSet.pTexelBufferView = nullptr;

        Logger::debug("before writing buffer descriptor Sets");
        pLogicalDevice->vkd.UpdateDescriptorSets(pLogicalDevice->device, 1, &writeDescriptorSet, 0, nullptr);

        return descriptorSet;
    }

    VkDescriptorSetLayout createImageSamplerDescriptorSetLayout(LogicalDevice* pLogicalDevice, uint32_t count)
    {
        VkDescriptorSetLayout descriptorSetLayout;

        std::vector<VkDescriptorSetLayoutBinding> bindigs(count);
        for (uint32_t i = 0; i < count; i++)
        {
            VkDescriptorSetLayoutBinding descriptorSetLayoutBinding;
            descriptorSetLayoutBinding.binding            = i;
            descriptorSetLayoutBinding.descriptorType     = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
            descriptorSetLayoutBinding.descriptorCount    = 1;
            descriptorSetLayoutBinding.stageFlags         = VK_SHADER_STAGE_FRAGMENT_BIT | VK_SHADER_STAGE_VERTEX_BIT;
            descriptorSetLayoutBinding.pImmutableSamplers = nullptr;
            bindigs[i]                                    = descriptorSetLayoutBinding;
        }

        VkDescriptorSetLayoutCreateInfo descriptorSetCreateInfo;
        descriptorSetCreateInfo.sType        = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        descriptorSetCreateInfo.pNext        = nullptr;
        descriptorSetCreateInfo.flags        = 0;
        descriptorSetCreateInfo.bindingCount = count;
        descriptorSetCreateInfo.pBindings    = bindigs.data();

        VkResult result =
            pLogicalDevice->vkd.CreateDescriptorSetLayout(pLogicalDevice->device, &descriptorSetCreateInfo, nullptr, &descriptorSetLayout);
        ASSERT_VULKAN(result)
        return descriptorSetLayout;
    }

    std::vector<VkDescriptorSet> allocateAndWriteImageSamplerDescriptorSets(LogicalDevice*                        pLogicalDevice,
                                                                            VkDescriptorPool                      descriptorPool,
                                                                            VkDescriptorSetLayout                 descriptorSetLayout,
                                                                            std::vector<VkSampler>                samplers,
                                                                            std::vector<std::vector<VkImageView>> imageViewsVectors)
    {
        std::vector<VkDescriptorSet> descriptorSets(imageViewsVectors[0].size());

        std::vector<VkDescriptorSetLayout> layouts(descriptorSets.size(), descriptorSetLayout);
        VkDescriptorSetAllocateInfo        descriptorSetAllocateInfo;
        descriptorSetAllocateInfo.sType              = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        descriptorSetAllocateInfo.pNext              = nullptr;
        descriptorSetAllocateInfo.descriptorPool     = descriptorPool;
        descriptorSetAllocateInfo.descriptorSetCount = descriptorSets.size();
        descriptorSetAllocateInfo.pSetLayouts        = layouts.data();

        Logger::debug("before allocating descriptor Sets");
        VkResult result = pLogicalDevice->vkd.AllocateDescriptorSets(pLogicalDevice->device, &descriptorSetAllocateInfo, descriptorSets.data());
        ASSERT_VULKAN(result);

        VkDescriptorImageInfo imageInfo;
        imageInfo.sampler     = VK_NULL_HANDLE;
        imageInfo.imageView   = VK_NULL_HANDLE;
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        std::vector<VkDescriptorImageInfo> imageInfos(imageViewsVectors.size(), imageInfo);

        VkWriteDescriptorSet writeDescriptorSet = {};

        writeDescriptorSet.sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writeDescriptorSet.pNext            = nullptr;
        writeDescriptorSet.dstSet           = VK_NULL_HANDLE;
        writeDescriptorSet.dstBinding       = 0;
        writeDescriptorSet.dstArrayElement  = 0;
        writeDescriptorSet.descriptorCount  = 1;
        writeDescriptorSet.descriptorType   = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        writeDescriptorSet.pImageInfo       = nullptr;
        writeDescriptorSet.pBufferInfo      = nullptr;
        writeDescriptorSet.pTexelBufferView = nullptr;

        std::vector<VkWriteDescriptorSet> writeDescriptorSets(imageViewsVectors.size(), writeDescriptorSet);

        for (unsigned int i = 0; i < descriptorSets.size(); i++)
        {
            for (uint32_t j = 0; j < imageViewsVectors.size(); j++)
            {
                imageInfos[j].sampler   = samplers[j];
                imageInfos[j].imageView = imageViewsVectors[j][i];

                writeDescriptorSets[j].dstBinding = j;
                writeDescriptorSets[j].pImageInfo = &imageInfos[j];
                writeDescriptorSets[j].dstSet     = descriptorSets[i];
            }
            Logger::debug("before writing descriptor Sets");
            pLogicalDevice->vkd.UpdateDescriptorSets(pLogicalDevice->device, writeDescriptorSets.size(), writeDescriptorSets.data(), 0, nullptr);
        }
        return descriptorSets;
    }
} // namespace vkBasalt
