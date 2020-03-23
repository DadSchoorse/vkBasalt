// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See helper_file_generator.py for modifications


/***************************************************************************
 *
 * Copyright (c) 2015-2020 The Khronos Group Inc.
 * Copyright (c) 2015-2020 Valve Corporation
 * Copyright (c) 2015-2020 LunarG, Inc.
 * Copyright (c) 2015-2020 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Mark Lobodzinski <mark@lunarg.com>
 * Author: Courtney Goeltzenleuchter <courtneygo@google.com>
 * Author: Tobin Ehlis <tobine@google.com>
 * Author: Chris Forbes <chrisforbes@google.com>
 * Author: John Zulauf<jzulauf@lunarg.com>
 *
 ****************************************************************************/

#pragma once
#include <vulkan/vulkan.h>

// These empty generic templates are specialized for each type with sType
// members and for each sType -- providing a two way map between structure
// types and sTypes

template <VkStructureType id> struct LvlSTypeMap {};
template <typename T> struct LvlTypeMap {};

// Map type VkApplicationInfo to id VK_STRUCTURE_TYPE_APPLICATION_INFO
template <> struct LvlTypeMap<VkApplicationInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_APPLICATION_INFO> {
    typedef VkApplicationInfo Type;
};

// Map type VkInstanceCreateInfo to id VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO
template <> struct LvlTypeMap<VkInstanceCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO> {
    typedef VkInstanceCreateInfo Type;
};

// Map type VkDeviceQueueCreateInfo to id VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO
template <> struct LvlTypeMap<VkDeviceQueueCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO> {
    typedef VkDeviceQueueCreateInfo Type;
};

// Map type VkDeviceCreateInfo to id VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO
template <> struct LvlTypeMap<VkDeviceCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO> {
    typedef VkDeviceCreateInfo Type;
};

// Map type VkSubmitInfo to id VK_STRUCTURE_TYPE_SUBMIT_INFO
template <> struct LvlTypeMap<VkSubmitInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SUBMIT_INFO> {
    typedef VkSubmitInfo Type;
};

// Map type VkMemoryAllocateInfo to id VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO
template <> struct LvlTypeMap<VkMemoryAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO> {
    typedef VkMemoryAllocateInfo Type;
};

// Map type VkMappedMemoryRange to id VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE
template <> struct LvlTypeMap<VkMappedMemoryRange> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE> {
    typedef VkMappedMemoryRange Type;
};

// Map type VkBindSparseInfo to id VK_STRUCTURE_TYPE_BIND_SPARSE_INFO
template <> struct LvlTypeMap<VkBindSparseInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_SPARSE_INFO> {
    typedef VkBindSparseInfo Type;
};

// Map type VkFenceCreateInfo to id VK_STRUCTURE_TYPE_FENCE_CREATE_INFO
template <> struct LvlTypeMap<VkFenceCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FENCE_CREATE_INFO> {
    typedef VkFenceCreateInfo Type;
};

// Map type VkSemaphoreCreateInfo to id VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO
template <> struct LvlTypeMap<VkSemaphoreCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO> {
    typedef VkSemaphoreCreateInfo Type;
};

// Map type VkEventCreateInfo to id VK_STRUCTURE_TYPE_EVENT_CREATE_INFO
template <> struct LvlTypeMap<VkEventCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EVENT_CREATE_INFO> {
    typedef VkEventCreateInfo Type;
};

// Map type VkQueryPoolCreateInfo to id VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO
template <> struct LvlTypeMap<VkQueryPoolCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO> {
    typedef VkQueryPoolCreateInfo Type;
};

// Map type VkBufferCreateInfo to id VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO
template <> struct LvlTypeMap<VkBufferCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO> {
    typedef VkBufferCreateInfo Type;
};

// Map type VkBufferViewCreateInfo to id VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO
template <> struct LvlTypeMap<VkBufferViewCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO> {
    typedef VkBufferViewCreateInfo Type;
};

// Map type VkImageCreateInfo to id VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO
template <> struct LvlTypeMap<VkImageCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO> {
    typedef VkImageCreateInfo Type;
};

// Map type VkImageViewCreateInfo to id VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO
template <> struct LvlTypeMap<VkImageViewCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO> {
    typedef VkImageViewCreateInfo Type;
};

// Map type VkShaderModuleCreateInfo to id VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO
template <> struct LvlTypeMap<VkShaderModuleCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO> {
    typedef VkShaderModuleCreateInfo Type;
};

// Map type VkPipelineCacheCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineCacheCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO> {
    typedef VkPipelineCacheCreateInfo Type;
};

// Map type VkPipelineShaderStageCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineShaderStageCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO> {
    typedef VkPipelineShaderStageCreateInfo Type;
};

// Map type VkPipelineVertexInputStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineVertexInputStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO> {
    typedef VkPipelineVertexInputStateCreateInfo Type;
};

// Map type VkPipelineInputAssemblyStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineInputAssemblyStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO> {
    typedef VkPipelineInputAssemblyStateCreateInfo Type;
};

// Map type VkPipelineTessellationStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineTessellationStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO> {
    typedef VkPipelineTessellationStateCreateInfo Type;
};

// Map type VkPipelineViewportStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineViewportStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO> {
    typedef VkPipelineViewportStateCreateInfo Type;
};

// Map type VkPipelineRasterizationStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineRasterizationStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO> {
    typedef VkPipelineRasterizationStateCreateInfo Type;
};

// Map type VkPipelineMultisampleStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineMultisampleStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO> {
    typedef VkPipelineMultisampleStateCreateInfo Type;
};

// Map type VkPipelineDepthStencilStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineDepthStencilStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO> {
    typedef VkPipelineDepthStencilStateCreateInfo Type;
};

// Map type VkPipelineColorBlendStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineColorBlendStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO> {
    typedef VkPipelineColorBlendStateCreateInfo Type;
};

// Map type VkPipelineDynamicStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineDynamicStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO> {
    typedef VkPipelineDynamicStateCreateInfo Type;
};

// Map type VkGraphicsPipelineCreateInfo to id VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO
template <> struct LvlTypeMap<VkGraphicsPipelineCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO> {
    typedef VkGraphicsPipelineCreateInfo Type;
};

// Map type VkComputePipelineCreateInfo to id VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO
template <> struct LvlTypeMap<VkComputePipelineCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO> {
    typedef VkComputePipelineCreateInfo Type;
};

// Map type VkPipelineLayoutCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineLayoutCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO> {
    typedef VkPipelineLayoutCreateInfo Type;
};

// Map type VkSamplerCreateInfo to id VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO
template <> struct LvlTypeMap<VkSamplerCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO> {
    typedef VkSamplerCreateInfo Type;
};

// Map type VkDescriptorSetLayoutCreateInfo to id VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO
template <> struct LvlTypeMap<VkDescriptorSetLayoutCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO> {
    typedef VkDescriptorSetLayoutCreateInfo Type;
};

// Map type VkDescriptorPoolCreateInfo to id VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO
template <> struct LvlTypeMap<VkDescriptorPoolCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO> {
    typedef VkDescriptorPoolCreateInfo Type;
};

// Map type VkDescriptorSetAllocateInfo to id VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO
template <> struct LvlTypeMap<VkDescriptorSetAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO> {
    typedef VkDescriptorSetAllocateInfo Type;
};

// Map type VkWriteDescriptorSet to id VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET
template <> struct LvlTypeMap<VkWriteDescriptorSet> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET> {
    typedef VkWriteDescriptorSet Type;
};

// Map type VkCopyDescriptorSet to id VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET
template <> struct LvlTypeMap<VkCopyDescriptorSet> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET> {
    typedef VkCopyDescriptorSet Type;
};

// Map type VkFramebufferCreateInfo to id VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO
template <> struct LvlTypeMap<VkFramebufferCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO> {
    typedef VkFramebufferCreateInfo Type;
};

// Map type VkRenderPassCreateInfo to id VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO
template <> struct LvlTypeMap<VkRenderPassCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO> {
    typedef VkRenderPassCreateInfo Type;
};

// Map type VkCommandPoolCreateInfo to id VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO
template <> struct LvlTypeMap<VkCommandPoolCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO> {
    typedef VkCommandPoolCreateInfo Type;
};

// Map type VkCommandBufferAllocateInfo to id VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO
template <> struct LvlTypeMap<VkCommandBufferAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO> {
    typedef VkCommandBufferAllocateInfo Type;
};

// Map type VkCommandBufferInheritanceInfo to id VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO
template <> struct LvlTypeMap<VkCommandBufferInheritanceInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO> {
    typedef VkCommandBufferInheritanceInfo Type;
};

// Map type VkCommandBufferBeginInfo to id VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO
template <> struct LvlTypeMap<VkCommandBufferBeginInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO> {
    typedef VkCommandBufferBeginInfo Type;
};

// Map type VkMemoryBarrier to id VK_STRUCTURE_TYPE_MEMORY_BARRIER
template <> struct LvlTypeMap<VkMemoryBarrier> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_BARRIER> {
    typedef VkMemoryBarrier Type;
};

// Map type VkBufferMemoryBarrier to id VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER
template <> struct LvlTypeMap<VkBufferMemoryBarrier> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER> {
    typedef VkBufferMemoryBarrier Type;
};

// Map type VkImageMemoryBarrier to id VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER
template <> struct LvlTypeMap<VkImageMemoryBarrier> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER> {
    typedef VkImageMemoryBarrier Type;
};

// Map type VkRenderPassBeginInfo to id VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO
template <> struct LvlTypeMap<VkRenderPassBeginInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO> {
    typedef VkRenderPassBeginInfo Type;
};

// Map type VkPhysicalDeviceSubgroupProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceSubgroupProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES> {
    typedef VkPhysicalDeviceSubgroupProperties Type;
};

// Map type VkBindBufferMemoryInfo to id VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO
template <> struct LvlTypeMap<VkBindBufferMemoryInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO> {
    typedef VkBindBufferMemoryInfo Type;
};

// Map type VkBindImageMemoryInfo to id VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO
template <> struct LvlTypeMap<VkBindImageMemoryInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO> {
    typedef VkBindImageMemoryInfo Type;
};

// Map type VkPhysicalDevice16BitStorageFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES
template <> struct LvlTypeMap<VkPhysicalDevice16BitStorageFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES> {
    typedef VkPhysicalDevice16BitStorageFeatures Type;
};

// Map type VkMemoryDedicatedRequirements to id VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS
template <> struct LvlTypeMap<VkMemoryDedicatedRequirements> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS> {
    typedef VkMemoryDedicatedRequirements Type;
};

// Map type VkMemoryDedicatedAllocateInfo to id VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO
template <> struct LvlTypeMap<VkMemoryDedicatedAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO> {
    typedef VkMemoryDedicatedAllocateInfo Type;
};

// Map type VkMemoryAllocateFlagsInfo to id VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO
template <> struct LvlTypeMap<VkMemoryAllocateFlagsInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO> {
    typedef VkMemoryAllocateFlagsInfo Type;
};

// Map type VkDeviceGroupRenderPassBeginInfo to id VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO
template <> struct LvlTypeMap<VkDeviceGroupRenderPassBeginInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO> {
    typedef VkDeviceGroupRenderPassBeginInfo Type;
};

// Map type VkDeviceGroupCommandBufferBeginInfo to id VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO
template <> struct LvlTypeMap<VkDeviceGroupCommandBufferBeginInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO> {
    typedef VkDeviceGroupCommandBufferBeginInfo Type;
};

// Map type VkDeviceGroupSubmitInfo to id VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO
template <> struct LvlTypeMap<VkDeviceGroupSubmitInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO> {
    typedef VkDeviceGroupSubmitInfo Type;
};

// Map type VkDeviceGroupBindSparseInfo to id VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO
template <> struct LvlTypeMap<VkDeviceGroupBindSparseInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO> {
    typedef VkDeviceGroupBindSparseInfo Type;
};

// Map type VkBindBufferMemoryDeviceGroupInfo to id VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO
template <> struct LvlTypeMap<VkBindBufferMemoryDeviceGroupInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO> {
    typedef VkBindBufferMemoryDeviceGroupInfo Type;
};

// Map type VkBindImageMemoryDeviceGroupInfo to id VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO
template <> struct LvlTypeMap<VkBindImageMemoryDeviceGroupInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO> {
    typedef VkBindImageMemoryDeviceGroupInfo Type;
};

// Map type VkPhysicalDeviceGroupProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceGroupProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES> {
    typedef VkPhysicalDeviceGroupProperties Type;
};

// Map type VkDeviceGroupDeviceCreateInfo to id VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO
template <> struct LvlTypeMap<VkDeviceGroupDeviceCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO> {
    typedef VkDeviceGroupDeviceCreateInfo Type;
};

// Map type VkBufferMemoryRequirementsInfo2 to id VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2
template <> struct LvlTypeMap<VkBufferMemoryRequirementsInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2> {
    typedef VkBufferMemoryRequirementsInfo2 Type;
};

// Map type VkImageMemoryRequirementsInfo2 to id VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2
template <> struct LvlTypeMap<VkImageMemoryRequirementsInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2> {
    typedef VkImageMemoryRequirementsInfo2 Type;
};

// Map type VkImageSparseMemoryRequirementsInfo2 to id VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2
template <> struct LvlTypeMap<VkImageSparseMemoryRequirementsInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2> {
    typedef VkImageSparseMemoryRequirementsInfo2 Type;
};

// Map type VkMemoryRequirements2 to id VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2
template <> struct LvlTypeMap<VkMemoryRequirements2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2> {
    typedef VkMemoryRequirements2 Type;
};

// Map type VkSparseImageMemoryRequirements2 to id VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2
template <> struct LvlTypeMap<VkSparseImageMemoryRequirements2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2> {
    typedef VkSparseImageMemoryRequirements2 Type;
};

// Map type VkPhysicalDeviceFeatures2 to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2
template <> struct LvlTypeMap<VkPhysicalDeviceFeatures2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2> {
    typedef VkPhysicalDeviceFeatures2 Type;
};

// Map type VkPhysicalDeviceProperties2 to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2
template <> struct LvlTypeMap<VkPhysicalDeviceProperties2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2> {
    typedef VkPhysicalDeviceProperties2 Type;
};

// Map type VkFormatProperties2 to id VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2
template <> struct LvlTypeMap<VkFormatProperties2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2> {
    typedef VkFormatProperties2 Type;
};

// Map type VkImageFormatProperties2 to id VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2
template <> struct LvlTypeMap<VkImageFormatProperties2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2> {
    typedef VkImageFormatProperties2 Type;
};

// Map type VkPhysicalDeviceImageFormatInfo2 to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2
template <> struct LvlTypeMap<VkPhysicalDeviceImageFormatInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2> {
    typedef VkPhysicalDeviceImageFormatInfo2 Type;
};

// Map type VkQueueFamilyProperties2 to id VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2
template <> struct LvlTypeMap<VkQueueFamilyProperties2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2> {
    typedef VkQueueFamilyProperties2 Type;
};

// Map type VkPhysicalDeviceMemoryProperties2 to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2
template <> struct LvlTypeMap<VkPhysicalDeviceMemoryProperties2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2> {
    typedef VkPhysicalDeviceMemoryProperties2 Type;
};

// Map type VkSparseImageFormatProperties2 to id VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2
template <> struct LvlTypeMap<VkSparseImageFormatProperties2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2> {
    typedef VkSparseImageFormatProperties2 Type;
};

// Map type VkPhysicalDeviceSparseImageFormatInfo2 to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2
template <> struct LvlTypeMap<VkPhysicalDeviceSparseImageFormatInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2> {
    typedef VkPhysicalDeviceSparseImageFormatInfo2 Type;
};

// Map type VkPhysicalDevicePointClippingProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDevicePointClippingProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES> {
    typedef VkPhysicalDevicePointClippingProperties Type;
};

// Map type VkRenderPassInputAttachmentAspectCreateInfo to id VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO
template <> struct LvlTypeMap<VkRenderPassInputAttachmentAspectCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO> {
    typedef VkRenderPassInputAttachmentAspectCreateInfo Type;
};

// Map type VkImageViewUsageCreateInfo to id VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO
template <> struct LvlTypeMap<VkImageViewUsageCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO> {
    typedef VkImageViewUsageCreateInfo Type;
};

// Map type VkPipelineTessellationDomainOriginStateCreateInfo to id VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO
template <> struct LvlTypeMap<VkPipelineTessellationDomainOriginStateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO> {
    typedef VkPipelineTessellationDomainOriginStateCreateInfo Type;
};

// Map type VkRenderPassMultiviewCreateInfo to id VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO
template <> struct LvlTypeMap<VkRenderPassMultiviewCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO> {
    typedef VkRenderPassMultiviewCreateInfo Type;
};

// Map type VkPhysicalDeviceMultiviewFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceMultiviewFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES> {
    typedef VkPhysicalDeviceMultiviewFeatures Type;
};

// Map type VkPhysicalDeviceMultiviewProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceMultiviewProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES> {
    typedef VkPhysicalDeviceMultiviewProperties Type;
};

// Map type VkPhysicalDeviceVariablePointersFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceVariablePointersFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES> {
    typedef VkPhysicalDeviceVariablePointersFeatures Type;
};

// Map type VkPhysicalDeviceProtectedMemoryFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceProtectedMemoryFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES> {
    typedef VkPhysicalDeviceProtectedMemoryFeatures Type;
};

// Map type VkPhysicalDeviceProtectedMemoryProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceProtectedMemoryProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES> {
    typedef VkPhysicalDeviceProtectedMemoryProperties Type;
};

// Map type VkDeviceQueueInfo2 to id VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2
template <> struct LvlTypeMap<VkDeviceQueueInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2> {
    typedef VkDeviceQueueInfo2 Type;
};

// Map type VkProtectedSubmitInfo to id VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO
template <> struct LvlTypeMap<VkProtectedSubmitInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO> {
    typedef VkProtectedSubmitInfo Type;
};

// Map type VkSamplerYcbcrConversionCreateInfo to id VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO
template <> struct LvlTypeMap<VkSamplerYcbcrConversionCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO> {
    typedef VkSamplerYcbcrConversionCreateInfo Type;
};

// Map type VkSamplerYcbcrConversionInfo to id VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO
template <> struct LvlTypeMap<VkSamplerYcbcrConversionInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO> {
    typedef VkSamplerYcbcrConversionInfo Type;
};

// Map type VkBindImagePlaneMemoryInfo to id VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO
template <> struct LvlTypeMap<VkBindImagePlaneMemoryInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO> {
    typedef VkBindImagePlaneMemoryInfo Type;
};

// Map type VkImagePlaneMemoryRequirementsInfo to id VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO
template <> struct LvlTypeMap<VkImagePlaneMemoryRequirementsInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO> {
    typedef VkImagePlaneMemoryRequirementsInfo Type;
};

// Map type VkPhysicalDeviceSamplerYcbcrConversionFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceSamplerYcbcrConversionFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES> {
    typedef VkPhysicalDeviceSamplerYcbcrConversionFeatures Type;
};

// Map type VkSamplerYcbcrConversionImageFormatProperties to id VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES
template <> struct LvlTypeMap<VkSamplerYcbcrConversionImageFormatProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES> {
    typedef VkSamplerYcbcrConversionImageFormatProperties Type;
};

// Map type VkDescriptorUpdateTemplateCreateInfo to id VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO
template <> struct LvlTypeMap<VkDescriptorUpdateTemplateCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO> {
    typedef VkDescriptorUpdateTemplateCreateInfo Type;
};

// Map type VkPhysicalDeviceExternalImageFormatInfo to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO
template <> struct LvlTypeMap<VkPhysicalDeviceExternalImageFormatInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO> {
    typedef VkPhysicalDeviceExternalImageFormatInfo Type;
};

// Map type VkExternalImageFormatProperties to id VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES
template <> struct LvlTypeMap<VkExternalImageFormatProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES> {
    typedef VkExternalImageFormatProperties Type;
};

// Map type VkPhysicalDeviceExternalBufferInfo to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO
template <> struct LvlTypeMap<VkPhysicalDeviceExternalBufferInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO> {
    typedef VkPhysicalDeviceExternalBufferInfo Type;
};

// Map type VkExternalBufferProperties to id VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES
template <> struct LvlTypeMap<VkExternalBufferProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES> {
    typedef VkExternalBufferProperties Type;
};

// Map type VkPhysicalDeviceIDProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceIDProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES> {
    typedef VkPhysicalDeviceIDProperties Type;
};

// Map type VkExternalMemoryImageCreateInfo to id VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO
template <> struct LvlTypeMap<VkExternalMemoryImageCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO> {
    typedef VkExternalMemoryImageCreateInfo Type;
};

// Map type VkExternalMemoryBufferCreateInfo to id VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO
template <> struct LvlTypeMap<VkExternalMemoryBufferCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO> {
    typedef VkExternalMemoryBufferCreateInfo Type;
};

// Map type VkExportMemoryAllocateInfo to id VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO
template <> struct LvlTypeMap<VkExportMemoryAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO> {
    typedef VkExportMemoryAllocateInfo Type;
};

// Map type VkPhysicalDeviceExternalFenceInfo to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO
template <> struct LvlTypeMap<VkPhysicalDeviceExternalFenceInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO> {
    typedef VkPhysicalDeviceExternalFenceInfo Type;
};

// Map type VkExternalFenceProperties to id VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES
template <> struct LvlTypeMap<VkExternalFenceProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES> {
    typedef VkExternalFenceProperties Type;
};

// Map type VkExportFenceCreateInfo to id VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO
template <> struct LvlTypeMap<VkExportFenceCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO> {
    typedef VkExportFenceCreateInfo Type;
};

// Map type VkExportSemaphoreCreateInfo to id VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO
template <> struct LvlTypeMap<VkExportSemaphoreCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO> {
    typedef VkExportSemaphoreCreateInfo Type;
};

// Map type VkPhysicalDeviceExternalSemaphoreInfo to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO
template <> struct LvlTypeMap<VkPhysicalDeviceExternalSemaphoreInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO> {
    typedef VkPhysicalDeviceExternalSemaphoreInfo Type;
};

// Map type VkExternalSemaphoreProperties to id VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES
template <> struct LvlTypeMap<VkExternalSemaphoreProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES> {
    typedef VkExternalSemaphoreProperties Type;
};

// Map type VkPhysicalDeviceMaintenance3Properties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceMaintenance3Properties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES> {
    typedef VkPhysicalDeviceMaintenance3Properties Type;
};

// Map type VkDescriptorSetLayoutSupport to id VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT
template <> struct LvlTypeMap<VkDescriptorSetLayoutSupport> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT> {
    typedef VkDescriptorSetLayoutSupport Type;
};

// Map type VkPhysicalDeviceShaderDrawParametersFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceShaderDrawParametersFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES> {
    typedef VkPhysicalDeviceShaderDrawParametersFeatures Type;
};

// Map type VkPhysicalDeviceVulkan11Features to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceVulkan11Features> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES> {
    typedef VkPhysicalDeviceVulkan11Features Type;
};

// Map type VkPhysicalDeviceVulkan11Properties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceVulkan11Properties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES> {
    typedef VkPhysicalDeviceVulkan11Properties Type;
};

// Map type VkPhysicalDeviceVulkan12Features to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceVulkan12Features> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES> {
    typedef VkPhysicalDeviceVulkan12Features Type;
};

// Map type VkPhysicalDeviceVulkan12Properties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceVulkan12Properties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES> {
    typedef VkPhysicalDeviceVulkan12Properties Type;
};

// Map type VkImageFormatListCreateInfo to id VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO
template <> struct LvlTypeMap<VkImageFormatListCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO> {
    typedef VkImageFormatListCreateInfo Type;
};

// Map type VkAttachmentDescription2 to id VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2
template <> struct LvlTypeMap<VkAttachmentDescription2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2> {
    typedef VkAttachmentDescription2 Type;
};

// Map type VkAttachmentReference2 to id VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2
template <> struct LvlTypeMap<VkAttachmentReference2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2> {
    typedef VkAttachmentReference2 Type;
};

// Map type VkSubpassDescription2 to id VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2
template <> struct LvlTypeMap<VkSubpassDescription2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2> {
    typedef VkSubpassDescription2 Type;
};

// Map type VkSubpassDependency2 to id VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2
template <> struct LvlTypeMap<VkSubpassDependency2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2> {
    typedef VkSubpassDependency2 Type;
};

// Map type VkRenderPassCreateInfo2 to id VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2
template <> struct LvlTypeMap<VkRenderPassCreateInfo2> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2> {
    typedef VkRenderPassCreateInfo2 Type;
};

// Map type VkSubpassBeginInfo to id VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO
template <> struct LvlTypeMap<VkSubpassBeginInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO> {
    typedef VkSubpassBeginInfo Type;
};

// Map type VkSubpassEndInfo to id VK_STRUCTURE_TYPE_SUBPASS_END_INFO
template <> struct LvlTypeMap<VkSubpassEndInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SUBPASS_END_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SUBPASS_END_INFO> {
    typedef VkSubpassEndInfo Type;
};

// Map type VkPhysicalDevice8BitStorageFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES
template <> struct LvlTypeMap<VkPhysicalDevice8BitStorageFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES> {
    typedef VkPhysicalDevice8BitStorageFeatures Type;
};

// Map type VkPhysicalDeviceDriverProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceDriverProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES> {
    typedef VkPhysicalDeviceDriverProperties Type;
};

// Map type VkPhysicalDeviceShaderAtomicInt64Features to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceShaderAtomicInt64Features> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES> {
    typedef VkPhysicalDeviceShaderAtomicInt64Features Type;
};

// Map type VkPhysicalDeviceShaderFloat16Int8Features to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceShaderFloat16Int8Features> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES> {
    typedef VkPhysicalDeviceShaderFloat16Int8Features Type;
};

// Map type VkPhysicalDeviceFloatControlsProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceFloatControlsProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES> {
    typedef VkPhysicalDeviceFloatControlsProperties Type;
};

// Map type VkDescriptorSetLayoutBindingFlagsCreateInfo to id VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO
template <> struct LvlTypeMap<VkDescriptorSetLayoutBindingFlagsCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO> {
    typedef VkDescriptorSetLayoutBindingFlagsCreateInfo Type;
};

// Map type VkPhysicalDeviceDescriptorIndexingFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceDescriptorIndexingFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES> {
    typedef VkPhysicalDeviceDescriptorIndexingFeatures Type;
};

// Map type VkPhysicalDeviceDescriptorIndexingProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceDescriptorIndexingProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES> {
    typedef VkPhysicalDeviceDescriptorIndexingProperties Type;
};

// Map type VkDescriptorSetVariableDescriptorCountAllocateInfo to id VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO
template <> struct LvlTypeMap<VkDescriptorSetVariableDescriptorCountAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO> {
    typedef VkDescriptorSetVariableDescriptorCountAllocateInfo Type;
};

// Map type VkDescriptorSetVariableDescriptorCountLayoutSupport to id VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT
template <> struct LvlTypeMap<VkDescriptorSetVariableDescriptorCountLayoutSupport> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT> {
    typedef VkDescriptorSetVariableDescriptorCountLayoutSupport Type;
};

// Map type VkSubpassDescriptionDepthStencilResolve to id VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE
template <> struct LvlTypeMap<VkSubpassDescriptionDepthStencilResolve> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE> {
    typedef VkSubpassDescriptionDepthStencilResolve Type;
};

// Map type VkPhysicalDeviceDepthStencilResolveProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceDepthStencilResolveProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES> {
    typedef VkPhysicalDeviceDepthStencilResolveProperties Type;
};

// Map type VkPhysicalDeviceScalarBlockLayoutFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceScalarBlockLayoutFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES> {
    typedef VkPhysicalDeviceScalarBlockLayoutFeatures Type;
};

// Map type VkImageStencilUsageCreateInfo to id VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO
template <> struct LvlTypeMap<VkImageStencilUsageCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO> {
    typedef VkImageStencilUsageCreateInfo Type;
};

// Map type VkSamplerReductionModeCreateInfo to id VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO
template <> struct LvlTypeMap<VkSamplerReductionModeCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO> {
    typedef VkSamplerReductionModeCreateInfo Type;
};

// Map type VkPhysicalDeviceSamplerFilterMinmaxProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceSamplerFilterMinmaxProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES> {
    typedef VkPhysicalDeviceSamplerFilterMinmaxProperties Type;
};

// Map type VkPhysicalDeviceVulkanMemoryModelFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceVulkanMemoryModelFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES> {
    typedef VkPhysicalDeviceVulkanMemoryModelFeatures Type;
};

// Map type VkPhysicalDeviceImagelessFramebufferFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceImagelessFramebufferFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES> {
    typedef VkPhysicalDeviceImagelessFramebufferFeatures Type;
};

// Map type VkFramebufferAttachmentImageInfo to id VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO
template <> struct LvlTypeMap<VkFramebufferAttachmentImageInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO> {
    typedef VkFramebufferAttachmentImageInfo Type;
};

// Map type VkFramebufferAttachmentsCreateInfo to id VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO
template <> struct LvlTypeMap<VkFramebufferAttachmentsCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO> {
    typedef VkFramebufferAttachmentsCreateInfo Type;
};

// Map type VkRenderPassAttachmentBeginInfo to id VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO
template <> struct LvlTypeMap<VkRenderPassAttachmentBeginInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO> {
    typedef VkRenderPassAttachmentBeginInfo Type;
};

// Map type VkPhysicalDeviceUniformBufferStandardLayoutFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceUniformBufferStandardLayoutFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES> {
    typedef VkPhysicalDeviceUniformBufferStandardLayoutFeatures Type;
};

// Map type VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES> {
    typedef VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures Type;
};

// Map type VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES> {
    typedef VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures Type;
};

// Map type VkAttachmentReferenceStencilLayout to id VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT
template <> struct LvlTypeMap<VkAttachmentReferenceStencilLayout> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT> {
    typedef VkAttachmentReferenceStencilLayout Type;
};

// Map type VkAttachmentDescriptionStencilLayout to id VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT
template <> struct LvlTypeMap<VkAttachmentDescriptionStencilLayout> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT> {
    typedef VkAttachmentDescriptionStencilLayout Type;
};

// Map type VkPhysicalDeviceHostQueryResetFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceHostQueryResetFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES> {
    typedef VkPhysicalDeviceHostQueryResetFeatures Type;
};

// Map type VkPhysicalDeviceTimelineSemaphoreFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceTimelineSemaphoreFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES> {
    typedef VkPhysicalDeviceTimelineSemaphoreFeatures Type;
};

// Map type VkPhysicalDeviceTimelineSemaphoreProperties to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES
template <> struct LvlTypeMap<VkPhysicalDeviceTimelineSemaphoreProperties> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES> {
    typedef VkPhysicalDeviceTimelineSemaphoreProperties Type;
};

// Map type VkSemaphoreTypeCreateInfo to id VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO
template <> struct LvlTypeMap<VkSemaphoreTypeCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO> {
    typedef VkSemaphoreTypeCreateInfo Type;
};

// Map type VkTimelineSemaphoreSubmitInfo to id VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO
template <> struct LvlTypeMap<VkTimelineSemaphoreSubmitInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO> {
    typedef VkTimelineSemaphoreSubmitInfo Type;
};

// Map type VkSemaphoreWaitInfo to id VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO
template <> struct LvlTypeMap<VkSemaphoreWaitInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO> {
    typedef VkSemaphoreWaitInfo Type;
};

// Map type VkSemaphoreSignalInfo to id VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO
template <> struct LvlTypeMap<VkSemaphoreSignalInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO> {
    typedef VkSemaphoreSignalInfo Type;
};

// Map type VkPhysicalDeviceBufferDeviceAddressFeatures to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES
template <> struct LvlTypeMap<VkPhysicalDeviceBufferDeviceAddressFeatures> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES> {
    typedef VkPhysicalDeviceBufferDeviceAddressFeatures Type;
};

// Map type VkBufferDeviceAddressInfo to id VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO
template <> struct LvlTypeMap<VkBufferDeviceAddressInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO> {
    typedef VkBufferDeviceAddressInfo Type;
};

// Map type VkBufferOpaqueCaptureAddressCreateInfo to id VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO
template <> struct LvlTypeMap<VkBufferOpaqueCaptureAddressCreateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO> {
    typedef VkBufferOpaqueCaptureAddressCreateInfo Type;
};

// Map type VkMemoryOpaqueCaptureAddressAllocateInfo to id VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO
template <> struct LvlTypeMap<VkMemoryOpaqueCaptureAddressAllocateInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO> {
    typedef VkMemoryOpaqueCaptureAddressAllocateInfo Type;
};

// Map type VkDeviceMemoryOpaqueCaptureAddressInfo to id VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO
template <> struct LvlTypeMap<VkDeviceMemoryOpaqueCaptureAddressInfo> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO> {
    typedef VkDeviceMemoryOpaqueCaptureAddressInfo Type;
};

// Map type VkSwapchainCreateInfoKHR to id VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkSwapchainCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR> {
    typedef VkSwapchainCreateInfoKHR Type;
};

// Map type VkPresentInfoKHR to id VK_STRUCTURE_TYPE_PRESENT_INFO_KHR
template <> struct LvlTypeMap<VkPresentInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PRESENT_INFO_KHR> {
    typedef VkPresentInfoKHR Type;
};

// Map type VkImageSwapchainCreateInfoKHR to id VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkImageSwapchainCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR> {
    typedef VkImageSwapchainCreateInfoKHR Type;
};

// Map type VkBindImageMemorySwapchainInfoKHR to id VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR
template <> struct LvlTypeMap<VkBindImageMemorySwapchainInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR> {
    typedef VkBindImageMemorySwapchainInfoKHR Type;
};

// Map type VkAcquireNextImageInfoKHR to id VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR
template <> struct LvlTypeMap<VkAcquireNextImageInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR> {
    typedef VkAcquireNextImageInfoKHR Type;
};

// Map type VkDeviceGroupPresentCapabilitiesKHR to id VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR
template <> struct LvlTypeMap<VkDeviceGroupPresentCapabilitiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR> {
    typedef VkDeviceGroupPresentCapabilitiesKHR Type;
};

// Map type VkDeviceGroupPresentInfoKHR to id VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR
template <> struct LvlTypeMap<VkDeviceGroupPresentInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR> {
    typedef VkDeviceGroupPresentInfoKHR Type;
};

// Map type VkDeviceGroupSwapchainCreateInfoKHR to id VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkDeviceGroupSwapchainCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR> {
    typedef VkDeviceGroupSwapchainCreateInfoKHR Type;
};

// Map type VkDisplayModeCreateInfoKHR to id VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkDisplayModeCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR> {
    typedef VkDisplayModeCreateInfoKHR Type;
};

// Map type VkDisplaySurfaceCreateInfoKHR to id VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkDisplaySurfaceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR> {
    typedef VkDisplaySurfaceCreateInfoKHR Type;
};

// Map type VkDisplayPresentInfoKHR to id VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR
template <> struct LvlTypeMap<VkDisplayPresentInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR> {
    typedef VkDisplayPresentInfoKHR Type;
};

#ifdef VK_USE_PLATFORM_XLIB_KHR
// Map type VkXlibSurfaceCreateInfoKHR to id VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkXlibSurfaceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR> {
    typedef VkXlibSurfaceCreateInfoKHR Type;
};

#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
// Map type VkXcbSurfaceCreateInfoKHR to id VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkXcbSurfaceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR> {
    typedef VkXcbSurfaceCreateInfoKHR Type;
};

#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
// Map type VkWaylandSurfaceCreateInfoKHR to id VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkWaylandSurfaceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR> {
    typedef VkWaylandSurfaceCreateInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkAndroidSurfaceCreateInfoKHR to id VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkAndroidSurfaceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR> {
    typedef VkAndroidSurfaceCreateInfoKHR Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkWin32SurfaceCreateInfoKHR to id VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkWin32SurfaceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR> {
    typedef VkWin32SurfaceCreateInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportMemoryWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkImportMemoryWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR> {
    typedef VkImportMemoryWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkExportMemoryWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkExportMemoryWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR> {
    typedef VkExportMemoryWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkMemoryWin32HandlePropertiesKHR to id VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR
template <> struct LvlTypeMap<VkMemoryWin32HandlePropertiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR> {
    typedef VkMemoryWin32HandlePropertiesKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkMemoryGetWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkMemoryGetWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR> {
    typedef VkMemoryGetWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportMemoryFdInfoKHR to id VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR
template <> struct LvlTypeMap<VkImportMemoryFdInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR> {
    typedef VkImportMemoryFdInfoKHR Type;
};

// Map type VkMemoryFdPropertiesKHR to id VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR
template <> struct LvlTypeMap<VkMemoryFdPropertiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR> {
    typedef VkMemoryFdPropertiesKHR Type;
};

// Map type VkMemoryGetFdInfoKHR to id VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR
template <> struct LvlTypeMap<VkMemoryGetFdInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR> {
    typedef VkMemoryGetFdInfoKHR Type;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkWin32KeyedMutexAcquireReleaseInfoKHR to id VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR
template <> struct LvlTypeMap<VkWin32KeyedMutexAcquireReleaseInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR> {
    typedef VkWin32KeyedMutexAcquireReleaseInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportSemaphoreWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkImportSemaphoreWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR> {
    typedef VkImportSemaphoreWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkExportSemaphoreWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkExportSemaphoreWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR> {
    typedef VkExportSemaphoreWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkD3D12FenceSubmitInfoKHR to id VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR
template <> struct LvlTypeMap<VkD3D12FenceSubmitInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR> {
    typedef VkD3D12FenceSubmitInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkSemaphoreGetWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkSemaphoreGetWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR> {
    typedef VkSemaphoreGetWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportSemaphoreFdInfoKHR to id VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR
template <> struct LvlTypeMap<VkImportSemaphoreFdInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR> {
    typedef VkImportSemaphoreFdInfoKHR Type;
};

// Map type VkSemaphoreGetFdInfoKHR to id VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR
template <> struct LvlTypeMap<VkSemaphoreGetFdInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR> {
    typedef VkSemaphoreGetFdInfoKHR Type;
};

// Map type VkPhysicalDevicePushDescriptorPropertiesKHR to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR
template <> struct LvlTypeMap<VkPhysicalDevicePushDescriptorPropertiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR> {
    typedef VkPhysicalDevicePushDescriptorPropertiesKHR Type;
};

// Map type VkPresentRegionsKHR to id VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR
template <> struct LvlTypeMap<VkPresentRegionsKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR> {
    typedef VkPresentRegionsKHR Type;
};

// Map type VkSharedPresentSurfaceCapabilitiesKHR to id VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR
template <> struct LvlTypeMap<VkSharedPresentSurfaceCapabilitiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR> {
    typedef VkSharedPresentSurfaceCapabilitiesKHR Type;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportFenceWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkImportFenceWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR> {
    typedef VkImportFenceWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkExportFenceWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkExportFenceWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR> {
    typedef VkExportFenceWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkFenceGetWin32HandleInfoKHR to id VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR
template <> struct LvlTypeMap<VkFenceGetWin32HandleInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR> {
    typedef VkFenceGetWin32HandleInfoKHR Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportFenceFdInfoKHR to id VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR
template <> struct LvlTypeMap<VkImportFenceFdInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR> {
    typedef VkImportFenceFdInfoKHR Type;
};

// Map type VkFenceGetFdInfoKHR to id VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR
template <> struct LvlTypeMap<VkFenceGetFdInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR> {
    typedef VkFenceGetFdInfoKHR Type;
};

// Map type VkPhysicalDevicePerformanceQueryFeaturesKHR to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR
template <> struct LvlTypeMap<VkPhysicalDevicePerformanceQueryFeaturesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR> {
    typedef VkPhysicalDevicePerformanceQueryFeaturesKHR Type;
};

// Map type VkPhysicalDevicePerformanceQueryPropertiesKHR to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR
template <> struct LvlTypeMap<VkPhysicalDevicePerformanceQueryPropertiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR> {
    typedef VkPhysicalDevicePerformanceQueryPropertiesKHR Type;
};

// Map type VkPerformanceCounterKHR to id VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR
template <> struct LvlTypeMap<VkPerformanceCounterKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR> {
    typedef VkPerformanceCounterKHR Type;
};

// Map type VkPerformanceCounterDescriptionKHR to id VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR
template <> struct LvlTypeMap<VkPerformanceCounterDescriptionKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR> {
    typedef VkPerformanceCounterDescriptionKHR Type;
};

// Map type VkQueryPoolPerformanceCreateInfoKHR to id VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR
template <> struct LvlTypeMap<VkQueryPoolPerformanceCreateInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR> {
    typedef VkQueryPoolPerformanceCreateInfoKHR Type;
};

// Map type VkAcquireProfilingLockInfoKHR to id VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR
template <> struct LvlTypeMap<VkAcquireProfilingLockInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR> {
    typedef VkAcquireProfilingLockInfoKHR Type;
};

// Map type VkPerformanceQuerySubmitInfoKHR to id VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR
template <> struct LvlTypeMap<VkPerformanceQuerySubmitInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR> {
    typedef VkPerformanceQuerySubmitInfoKHR Type;
};

// Map type VkPhysicalDeviceSurfaceInfo2KHR to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR
template <> struct LvlTypeMap<VkPhysicalDeviceSurfaceInfo2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR> {
    typedef VkPhysicalDeviceSurfaceInfo2KHR Type;
};

// Map type VkSurfaceCapabilities2KHR to id VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR
template <> struct LvlTypeMap<VkSurfaceCapabilities2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR> {
    typedef VkSurfaceCapabilities2KHR Type;
};

// Map type VkSurfaceFormat2KHR to id VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR
template <> struct LvlTypeMap<VkSurfaceFormat2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR> {
    typedef VkSurfaceFormat2KHR Type;
};

// Map type VkDisplayProperties2KHR to id VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR
template <> struct LvlTypeMap<VkDisplayProperties2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR> {
    typedef VkDisplayProperties2KHR Type;
};

// Map type VkDisplayPlaneProperties2KHR to id VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR
template <> struct LvlTypeMap<VkDisplayPlaneProperties2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR> {
    typedef VkDisplayPlaneProperties2KHR Type;
};

// Map type VkDisplayModeProperties2KHR to id VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR
template <> struct LvlTypeMap<VkDisplayModeProperties2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR> {
    typedef VkDisplayModeProperties2KHR Type;
};

// Map type VkDisplayPlaneInfo2KHR to id VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR
template <> struct LvlTypeMap<VkDisplayPlaneInfo2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR> {
    typedef VkDisplayPlaneInfo2KHR Type;
};

// Map type VkDisplayPlaneCapabilities2KHR to id VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR
template <> struct LvlTypeMap<VkDisplayPlaneCapabilities2KHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR> {
    typedef VkDisplayPlaneCapabilities2KHR Type;
};

// Map type VkPhysicalDeviceShaderClockFeaturesKHR to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR
template <> struct LvlTypeMap<VkPhysicalDeviceShaderClockFeaturesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR> {
    typedef VkPhysicalDeviceShaderClockFeaturesKHR Type;
};

// Map type VkSurfaceProtectedCapabilitiesKHR to id VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR
template <> struct LvlTypeMap<VkSurfaceProtectedCapabilitiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR> {
    typedef VkSurfaceProtectedCapabilitiesKHR Type;
};

// Map type VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR
template <> struct LvlTypeMap<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR> {
    typedef VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR Type;
};

// Map type VkPipelineInfoKHR to id VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR
template <> struct LvlTypeMap<VkPipelineInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR> {
    typedef VkPipelineInfoKHR Type;
};

// Map type VkPipelineExecutablePropertiesKHR to id VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR
template <> struct LvlTypeMap<VkPipelineExecutablePropertiesKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR> {
    typedef VkPipelineExecutablePropertiesKHR Type;
};

// Map type VkPipelineExecutableInfoKHR to id VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR
template <> struct LvlTypeMap<VkPipelineExecutableInfoKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR> {
    typedef VkPipelineExecutableInfoKHR Type;
};

// Map type VkPipelineExecutableStatisticKHR to id VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR
template <> struct LvlTypeMap<VkPipelineExecutableStatisticKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR> {
    typedef VkPipelineExecutableStatisticKHR Type;
};

// Map type VkPipelineExecutableInternalRepresentationKHR to id VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR
template <> struct LvlTypeMap<VkPipelineExecutableInternalRepresentationKHR> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR> {
    typedef VkPipelineExecutableInternalRepresentationKHR Type;
};

// Map type VkDebugReportCallbackCreateInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkDebugReportCallbackCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT> {
    typedef VkDebugReportCallbackCreateInfoEXT Type;
};

// Map type VkPipelineRasterizationStateRasterizationOrderAMD to id VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD
template <> struct LvlTypeMap<VkPipelineRasterizationStateRasterizationOrderAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD> {
    typedef VkPipelineRasterizationStateRasterizationOrderAMD Type;
};

// Map type VkDebugMarkerObjectNameInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT
template <> struct LvlTypeMap<VkDebugMarkerObjectNameInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT> {
    typedef VkDebugMarkerObjectNameInfoEXT Type;
};

// Map type VkDebugMarkerObjectTagInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT
template <> struct LvlTypeMap<VkDebugMarkerObjectTagInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT> {
    typedef VkDebugMarkerObjectTagInfoEXT Type;
};

// Map type VkDebugMarkerMarkerInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT
template <> struct LvlTypeMap<VkDebugMarkerMarkerInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT> {
    typedef VkDebugMarkerMarkerInfoEXT Type;
};

// Map type VkDedicatedAllocationImageCreateInfoNV to id VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkDedicatedAllocationImageCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV> {
    typedef VkDedicatedAllocationImageCreateInfoNV Type;
};

// Map type VkDedicatedAllocationBufferCreateInfoNV to id VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV
template <> struct LvlTypeMap<VkDedicatedAllocationBufferCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV> {
    typedef VkDedicatedAllocationBufferCreateInfoNV Type;
};

// Map type VkDedicatedAllocationMemoryAllocateInfoNV to id VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV
template <> struct LvlTypeMap<VkDedicatedAllocationMemoryAllocateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV> {
    typedef VkDedicatedAllocationMemoryAllocateInfoNV Type;
};

// Map type VkPhysicalDeviceTransformFeedbackFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceTransformFeedbackFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT> {
    typedef VkPhysicalDeviceTransformFeedbackFeaturesEXT Type;
};

// Map type VkPhysicalDeviceTransformFeedbackPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceTransformFeedbackPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceTransformFeedbackPropertiesEXT Type;
};

// Map type VkPipelineRasterizationStateStreamCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineRasterizationStateStreamCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT> {
    typedef VkPipelineRasterizationStateStreamCreateInfoEXT Type;
};

// Map type VkImageViewHandleInfoNVX to id VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX
template <> struct LvlTypeMap<VkImageViewHandleInfoNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX> {
    typedef VkImageViewHandleInfoNVX Type;
};

// Map type VkTextureLODGatherFormatPropertiesAMD to id VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD
template <> struct LvlTypeMap<VkTextureLODGatherFormatPropertiesAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD> {
    typedef VkTextureLODGatherFormatPropertiesAMD Type;
};

#ifdef VK_USE_PLATFORM_GGP
// Map type VkStreamDescriptorSurfaceCreateInfoGGP to id VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP
template <> struct LvlTypeMap<VkStreamDescriptorSurfaceCreateInfoGGP> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP> {
    typedef VkStreamDescriptorSurfaceCreateInfoGGP Type;
};

#endif // VK_USE_PLATFORM_GGP
// Map type VkPhysicalDeviceCornerSampledImageFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceCornerSampledImageFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV> {
    typedef VkPhysicalDeviceCornerSampledImageFeaturesNV Type;
};

// Map type VkExternalMemoryImageCreateInfoNV to id VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkExternalMemoryImageCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV> {
    typedef VkExternalMemoryImageCreateInfoNV Type;
};

// Map type VkExportMemoryAllocateInfoNV to id VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV
template <> struct LvlTypeMap<VkExportMemoryAllocateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV> {
    typedef VkExportMemoryAllocateInfoNV Type;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkImportMemoryWin32HandleInfoNV to id VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV
template <> struct LvlTypeMap<VkImportMemoryWin32HandleInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV> {
    typedef VkImportMemoryWin32HandleInfoNV Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkExportMemoryWin32HandleInfoNV to id VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV
template <> struct LvlTypeMap<VkExportMemoryWin32HandleInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV> {
    typedef VkExportMemoryWin32HandleInfoNV Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkWin32KeyedMutexAcquireReleaseInfoNV to id VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV
template <> struct LvlTypeMap<VkWin32KeyedMutexAcquireReleaseInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV> {
    typedef VkWin32KeyedMutexAcquireReleaseInfoNV Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
// Map type VkValidationFlagsEXT to id VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT
template <> struct LvlTypeMap<VkValidationFlagsEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT> {
    typedef VkValidationFlagsEXT Type;
};

#ifdef VK_USE_PLATFORM_VI_NN
// Map type VkViSurfaceCreateInfoNN to id VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN
template <> struct LvlTypeMap<VkViSurfaceCreateInfoNN> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN> {
    typedef VkViSurfaceCreateInfoNN Type;
};

#endif // VK_USE_PLATFORM_VI_NN
// Map type VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT> {
    typedef VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT Type;
};

// Map type VkImageViewASTCDecodeModeEXT to id VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT
template <> struct LvlTypeMap<VkImageViewASTCDecodeModeEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT> {
    typedef VkImageViewASTCDecodeModeEXT Type;
};

// Map type VkPhysicalDeviceASTCDecodeFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceASTCDecodeFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT> {
    typedef VkPhysicalDeviceASTCDecodeFeaturesEXT Type;
};

// Map type VkConditionalRenderingBeginInfoEXT to id VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT
template <> struct LvlTypeMap<VkConditionalRenderingBeginInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT> {
    typedef VkConditionalRenderingBeginInfoEXT Type;
};

// Map type VkPhysicalDeviceConditionalRenderingFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceConditionalRenderingFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT> {
    typedef VkPhysicalDeviceConditionalRenderingFeaturesEXT Type;
};

// Map type VkCommandBufferInheritanceConditionalRenderingInfoEXT to id VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT
template <> struct LvlTypeMap<VkCommandBufferInheritanceConditionalRenderingInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT> {
    typedef VkCommandBufferInheritanceConditionalRenderingInfoEXT Type;
};

// Map type VkDeviceGeneratedCommandsFeaturesNVX to id VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX
template <> struct LvlTypeMap<VkDeviceGeneratedCommandsFeaturesNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX> {
    typedef VkDeviceGeneratedCommandsFeaturesNVX Type;
};

// Map type VkDeviceGeneratedCommandsLimitsNVX to id VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX
template <> struct LvlTypeMap<VkDeviceGeneratedCommandsLimitsNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX> {
    typedef VkDeviceGeneratedCommandsLimitsNVX Type;
};

// Map type VkIndirectCommandsLayoutCreateInfoNVX to id VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX
template <> struct LvlTypeMap<VkIndirectCommandsLayoutCreateInfoNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX> {
    typedef VkIndirectCommandsLayoutCreateInfoNVX Type;
};

// Map type VkCmdProcessCommandsInfoNVX to id VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX
template <> struct LvlTypeMap<VkCmdProcessCommandsInfoNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX> {
    typedef VkCmdProcessCommandsInfoNVX Type;
};

// Map type VkCmdReserveSpaceForCommandsInfoNVX to id VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX
template <> struct LvlTypeMap<VkCmdReserveSpaceForCommandsInfoNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX> {
    typedef VkCmdReserveSpaceForCommandsInfoNVX Type;
};

// Map type VkObjectTableCreateInfoNVX to id VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX
template <> struct LvlTypeMap<VkObjectTableCreateInfoNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX> {
    typedef VkObjectTableCreateInfoNVX Type;
};

// Map type VkPipelineViewportWScalingStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineViewportWScalingStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV> {
    typedef VkPipelineViewportWScalingStateCreateInfoNV Type;
};

// Map type VkSurfaceCapabilities2EXT to id VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT
template <> struct LvlTypeMap<VkSurfaceCapabilities2EXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT> {
    typedef VkSurfaceCapabilities2EXT Type;
};

// Map type VkDisplayPowerInfoEXT to id VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT
template <> struct LvlTypeMap<VkDisplayPowerInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT> {
    typedef VkDisplayPowerInfoEXT Type;
};

// Map type VkDeviceEventInfoEXT to id VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT
template <> struct LvlTypeMap<VkDeviceEventInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT> {
    typedef VkDeviceEventInfoEXT Type;
};

// Map type VkDisplayEventInfoEXT to id VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT
template <> struct LvlTypeMap<VkDisplayEventInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT> {
    typedef VkDisplayEventInfoEXT Type;
};

// Map type VkSwapchainCounterCreateInfoEXT to id VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkSwapchainCounterCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT> {
    typedef VkSwapchainCounterCreateInfoEXT Type;
};

// Map type VkPresentTimesInfoGOOGLE to id VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE
template <> struct LvlTypeMap<VkPresentTimesInfoGOOGLE> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE> {
    typedef VkPresentTimesInfoGOOGLE Type;
};

// Map type VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX
template <> struct LvlTypeMap<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX> {
    typedef VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX Type;
};

// Map type VkPipelineViewportSwizzleStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineViewportSwizzleStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV> {
    typedef VkPipelineViewportSwizzleStateCreateInfoNV Type;
};

// Map type VkPhysicalDeviceDiscardRectanglePropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceDiscardRectanglePropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceDiscardRectanglePropertiesEXT Type;
};

// Map type VkPipelineDiscardRectangleStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineDiscardRectangleStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineDiscardRectangleStateCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceConservativeRasterizationPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceConservativeRasterizationPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceConservativeRasterizationPropertiesEXT Type;
};

// Map type VkPipelineRasterizationConservativeStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineRasterizationConservativeStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineRasterizationConservativeStateCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceDepthClipEnableFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceDepthClipEnableFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT> {
    typedef VkPhysicalDeviceDepthClipEnableFeaturesEXT Type;
};

// Map type VkPipelineRasterizationDepthClipStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineRasterizationDepthClipStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineRasterizationDepthClipStateCreateInfoEXT Type;
};

// Map type VkHdrMetadataEXT to id VK_STRUCTURE_TYPE_HDR_METADATA_EXT
template <> struct LvlTypeMap<VkHdrMetadataEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_HDR_METADATA_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_HDR_METADATA_EXT> {
    typedef VkHdrMetadataEXT Type;
};

#ifdef VK_USE_PLATFORM_IOS_MVK
// Map type VkIOSSurfaceCreateInfoMVK to id VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK
template <> struct LvlTypeMap<VkIOSSurfaceCreateInfoMVK> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK> {
    typedef VkIOSSurfaceCreateInfoMVK Type;
};

#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
// Map type VkMacOSSurfaceCreateInfoMVK to id VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK
template <> struct LvlTypeMap<VkMacOSSurfaceCreateInfoMVK> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK> {
    typedef VkMacOSSurfaceCreateInfoMVK Type;
};

#endif // VK_USE_PLATFORM_MACOS_MVK
// Map type VkDebugUtilsObjectNameInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT
template <> struct LvlTypeMap<VkDebugUtilsObjectNameInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT> {
    typedef VkDebugUtilsObjectNameInfoEXT Type;
};

// Map type VkDebugUtilsObjectTagInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT
template <> struct LvlTypeMap<VkDebugUtilsObjectTagInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT> {
    typedef VkDebugUtilsObjectTagInfoEXT Type;
};

// Map type VkDebugUtilsLabelEXT to id VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT
template <> struct LvlTypeMap<VkDebugUtilsLabelEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT> {
    typedef VkDebugUtilsLabelEXT Type;
};

// Map type VkDebugUtilsMessengerCallbackDataEXT to id VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT
template <> struct LvlTypeMap<VkDebugUtilsMessengerCallbackDataEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT> {
    typedef VkDebugUtilsMessengerCallbackDataEXT Type;
};

// Map type VkDebugUtilsMessengerCreateInfoEXT to id VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkDebugUtilsMessengerCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT> {
    typedef VkDebugUtilsMessengerCreateInfoEXT Type;
};

#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkAndroidHardwareBufferUsageANDROID to id VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID
template <> struct LvlTypeMap<VkAndroidHardwareBufferUsageANDROID> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID> {
    typedef VkAndroidHardwareBufferUsageANDROID Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkAndroidHardwareBufferPropertiesANDROID to id VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID
template <> struct LvlTypeMap<VkAndroidHardwareBufferPropertiesANDROID> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID> {
    typedef VkAndroidHardwareBufferPropertiesANDROID Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkAndroidHardwareBufferFormatPropertiesANDROID to id VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID
template <> struct LvlTypeMap<VkAndroidHardwareBufferFormatPropertiesANDROID> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID> {
    typedef VkAndroidHardwareBufferFormatPropertiesANDROID Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkImportAndroidHardwareBufferInfoANDROID to id VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID
template <> struct LvlTypeMap<VkImportAndroidHardwareBufferInfoANDROID> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID> {
    typedef VkImportAndroidHardwareBufferInfoANDROID Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkMemoryGetAndroidHardwareBufferInfoANDROID to id VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID
template <> struct LvlTypeMap<VkMemoryGetAndroidHardwareBufferInfoANDROID> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID> {
    typedef VkMemoryGetAndroidHardwareBufferInfoANDROID Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Map type VkExternalFormatANDROID to id VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID
template <> struct LvlTypeMap<VkExternalFormatANDROID> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID> {
    typedef VkExternalFormatANDROID Type;
};

#endif // VK_USE_PLATFORM_ANDROID_KHR
// Map type VkPhysicalDeviceInlineUniformBlockFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceInlineUniformBlockFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT> {
    typedef VkPhysicalDeviceInlineUniformBlockFeaturesEXT Type;
};

// Map type VkPhysicalDeviceInlineUniformBlockPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceInlineUniformBlockPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceInlineUniformBlockPropertiesEXT Type;
};

// Map type VkWriteDescriptorSetInlineUniformBlockEXT to id VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT
template <> struct LvlTypeMap<VkWriteDescriptorSetInlineUniformBlockEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT> {
    typedef VkWriteDescriptorSetInlineUniformBlockEXT Type;
};

// Map type VkDescriptorPoolInlineUniformBlockCreateInfoEXT to id VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkDescriptorPoolInlineUniformBlockCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT> {
    typedef VkDescriptorPoolInlineUniformBlockCreateInfoEXT Type;
};

// Map type VkSampleLocationsInfoEXT to id VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT
template <> struct LvlTypeMap<VkSampleLocationsInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT> {
    typedef VkSampleLocationsInfoEXT Type;
};

// Map type VkRenderPassSampleLocationsBeginInfoEXT to id VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT
template <> struct LvlTypeMap<VkRenderPassSampleLocationsBeginInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT> {
    typedef VkRenderPassSampleLocationsBeginInfoEXT Type;
};

// Map type VkPipelineSampleLocationsStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineSampleLocationsStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineSampleLocationsStateCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceSampleLocationsPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceSampleLocationsPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceSampleLocationsPropertiesEXT Type;
};

// Map type VkMultisamplePropertiesEXT to id VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT
template <> struct LvlTypeMap<VkMultisamplePropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT> {
    typedef VkMultisamplePropertiesEXT Type;
};

// Map type VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT> {
    typedef VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT Type;
};

// Map type VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT Type;
};

// Map type VkPipelineColorBlendAdvancedStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineColorBlendAdvancedStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineColorBlendAdvancedStateCreateInfoEXT Type;
};

// Map type VkPipelineCoverageToColorStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineCoverageToColorStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV> {
    typedef VkPipelineCoverageToColorStateCreateInfoNV Type;
};

// Map type VkPipelineCoverageModulationStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineCoverageModulationStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV> {
    typedef VkPipelineCoverageModulationStateCreateInfoNV Type;
};

// Map type VkPhysicalDeviceShaderSMBuiltinsPropertiesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV> {
    typedef VkPhysicalDeviceShaderSMBuiltinsPropertiesNV Type;
};

// Map type VkPhysicalDeviceShaderSMBuiltinsFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV> {
    typedef VkPhysicalDeviceShaderSMBuiltinsFeaturesNV Type;
};

// Map type VkDrmFormatModifierPropertiesListEXT to id VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT
template <> struct LvlTypeMap<VkDrmFormatModifierPropertiesListEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT> {
    typedef VkDrmFormatModifierPropertiesListEXT Type;
};

// Map type VkPhysicalDeviceImageDrmFormatModifierInfoEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceImageDrmFormatModifierInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT> {
    typedef VkPhysicalDeviceImageDrmFormatModifierInfoEXT Type;
};

// Map type VkImageDrmFormatModifierListCreateInfoEXT to id VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkImageDrmFormatModifierListCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT> {
    typedef VkImageDrmFormatModifierListCreateInfoEXT Type;
};

// Map type VkImageDrmFormatModifierExplicitCreateInfoEXT to id VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkImageDrmFormatModifierExplicitCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT> {
    typedef VkImageDrmFormatModifierExplicitCreateInfoEXT Type;
};

// Map type VkImageDrmFormatModifierPropertiesEXT to id VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT
template <> struct LvlTypeMap<VkImageDrmFormatModifierPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT> {
    typedef VkImageDrmFormatModifierPropertiesEXT Type;
};

// Map type VkValidationCacheCreateInfoEXT to id VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkValidationCacheCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT> {
    typedef VkValidationCacheCreateInfoEXT Type;
};

// Map type VkShaderModuleValidationCacheCreateInfoEXT to id VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkShaderModuleValidationCacheCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT> {
    typedef VkShaderModuleValidationCacheCreateInfoEXT Type;
};

// Map type VkPipelineViewportShadingRateImageStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineViewportShadingRateImageStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV> {
    typedef VkPipelineViewportShadingRateImageStateCreateInfoNV Type;
};

// Map type VkPhysicalDeviceShadingRateImageFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceShadingRateImageFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV> {
    typedef VkPhysicalDeviceShadingRateImageFeaturesNV Type;
};

// Map type VkPhysicalDeviceShadingRateImagePropertiesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceShadingRateImagePropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV> {
    typedef VkPhysicalDeviceShadingRateImagePropertiesNV Type;
};

// Map type VkPipelineViewportCoarseSampleOrderStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV> {
    typedef VkPipelineViewportCoarseSampleOrderStateCreateInfoNV Type;
};

// Map type VkRayTracingShaderGroupCreateInfoNV to id VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV
template <> struct LvlTypeMap<VkRayTracingShaderGroupCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV> {
    typedef VkRayTracingShaderGroupCreateInfoNV Type;
};

// Map type VkRayTracingPipelineCreateInfoNV to id VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkRayTracingPipelineCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV> {
    typedef VkRayTracingPipelineCreateInfoNV Type;
};

// Map type VkGeometryTrianglesNV to id VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV
template <> struct LvlTypeMap<VkGeometryTrianglesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV> {
    typedef VkGeometryTrianglesNV Type;
};

// Map type VkGeometryAABBNV to id VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV
template <> struct LvlTypeMap<VkGeometryAABBNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV> {
    typedef VkGeometryAABBNV Type;
};

// Map type VkGeometryNV to id VK_STRUCTURE_TYPE_GEOMETRY_NV
template <> struct LvlTypeMap<VkGeometryNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_GEOMETRY_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_GEOMETRY_NV> {
    typedef VkGeometryNV Type;
};

// Map type VkAccelerationStructureInfoNV to id VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV
template <> struct LvlTypeMap<VkAccelerationStructureInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV> {
    typedef VkAccelerationStructureInfoNV Type;
};

// Map type VkAccelerationStructureCreateInfoNV to id VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkAccelerationStructureCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV> {
    typedef VkAccelerationStructureCreateInfoNV Type;
};

// Map type VkBindAccelerationStructureMemoryInfoNV to id VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV
template <> struct LvlTypeMap<VkBindAccelerationStructureMemoryInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV> {
    typedef VkBindAccelerationStructureMemoryInfoNV Type;
};

// Map type VkWriteDescriptorSetAccelerationStructureNV to id VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV
template <> struct LvlTypeMap<VkWriteDescriptorSetAccelerationStructureNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV> {
    typedef VkWriteDescriptorSetAccelerationStructureNV Type;
};

// Map type VkAccelerationStructureMemoryRequirementsInfoNV to id VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV
template <> struct LvlTypeMap<VkAccelerationStructureMemoryRequirementsInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV> {
    typedef VkAccelerationStructureMemoryRequirementsInfoNV Type;
};

// Map type VkPhysicalDeviceRayTracingPropertiesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceRayTracingPropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV> {
    typedef VkPhysicalDeviceRayTracingPropertiesNV Type;
};

// Map type VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV> {
    typedef VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV Type;
};

// Map type VkPipelineRepresentativeFragmentTestStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineRepresentativeFragmentTestStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV> {
    typedef VkPipelineRepresentativeFragmentTestStateCreateInfoNV Type;
};

// Map type VkPhysicalDeviceImageViewImageFormatInfoEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceImageViewImageFormatInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT> {
    typedef VkPhysicalDeviceImageViewImageFormatInfoEXT Type;
};

// Map type VkFilterCubicImageViewImageFormatPropertiesEXT to id VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT
template <> struct LvlTypeMap<VkFilterCubicImageViewImageFormatPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT> {
    typedef VkFilterCubicImageViewImageFormatPropertiesEXT Type;
};

// Map type VkDeviceQueueGlobalPriorityCreateInfoEXT to id VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkDeviceQueueGlobalPriorityCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT> {
    typedef VkDeviceQueueGlobalPriorityCreateInfoEXT Type;
};

// Map type VkImportMemoryHostPointerInfoEXT to id VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT
template <> struct LvlTypeMap<VkImportMemoryHostPointerInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT> {
    typedef VkImportMemoryHostPointerInfoEXT Type;
};

// Map type VkMemoryHostPointerPropertiesEXT to id VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT
template <> struct LvlTypeMap<VkMemoryHostPointerPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT> {
    typedef VkMemoryHostPointerPropertiesEXT Type;
};

// Map type VkPhysicalDeviceExternalMemoryHostPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceExternalMemoryHostPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceExternalMemoryHostPropertiesEXT Type;
};

// Map type VkPipelineCompilerControlCreateInfoAMD to id VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD
template <> struct LvlTypeMap<VkPipelineCompilerControlCreateInfoAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD> {
    typedef VkPipelineCompilerControlCreateInfoAMD Type;
};

// Map type VkCalibratedTimestampInfoEXT to id VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT
template <> struct LvlTypeMap<VkCalibratedTimestampInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT> {
    typedef VkCalibratedTimestampInfoEXT Type;
};

// Map type VkPhysicalDeviceShaderCorePropertiesAMD to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD
template <> struct LvlTypeMap<VkPhysicalDeviceShaderCorePropertiesAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD> {
    typedef VkPhysicalDeviceShaderCorePropertiesAMD Type;
};

// Map type VkDeviceMemoryOverallocationCreateInfoAMD to id VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD
template <> struct LvlTypeMap<VkDeviceMemoryOverallocationCreateInfoAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD> {
    typedef VkDeviceMemoryOverallocationCreateInfoAMD Type;
};

// Map type VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT Type;
};

// Map type VkPipelineVertexInputDivisorStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineVertexInputDivisorStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineVertexInputDivisorStateCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT> {
    typedef VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT Type;
};

#ifdef VK_USE_PLATFORM_GGP
// Map type VkPresentFrameTokenGGP to id VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP
template <> struct LvlTypeMap<VkPresentFrameTokenGGP> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP> {
    typedef VkPresentFrameTokenGGP Type;
};

#endif // VK_USE_PLATFORM_GGP
// Map type VkPipelineCreationFeedbackCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineCreationFeedbackCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT> {
    typedef VkPipelineCreationFeedbackCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceComputeShaderDerivativesFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV> {
    typedef VkPhysicalDeviceComputeShaderDerivativesFeaturesNV Type;
};

// Map type VkPhysicalDeviceMeshShaderFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceMeshShaderFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV> {
    typedef VkPhysicalDeviceMeshShaderFeaturesNV Type;
};

// Map type VkPhysicalDeviceMeshShaderPropertiesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceMeshShaderPropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV> {
    typedef VkPhysicalDeviceMeshShaderPropertiesNV Type;
};

// Map type VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV> {
    typedef VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV Type;
};

// Map type VkPhysicalDeviceShaderImageFootprintFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceShaderImageFootprintFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV> {
    typedef VkPhysicalDeviceShaderImageFootprintFeaturesNV Type;
};

// Map type VkPipelineViewportExclusiveScissorStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineViewportExclusiveScissorStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV> {
    typedef VkPipelineViewportExclusiveScissorStateCreateInfoNV Type;
};

// Map type VkPhysicalDeviceExclusiveScissorFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceExclusiveScissorFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV> {
    typedef VkPhysicalDeviceExclusiveScissorFeaturesNV Type;
};

// Map type VkQueueFamilyCheckpointPropertiesNV to id VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV
template <> struct LvlTypeMap<VkQueueFamilyCheckpointPropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV> {
    typedef VkQueueFamilyCheckpointPropertiesNV Type;
};

// Map type VkCheckpointDataNV to id VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV
template <> struct LvlTypeMap<VkCheckpointDataNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV> {
    typedef VkCheckpointDataNV Type;
};

// Map type VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL
template <> struct LvlTypeMap<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL> {
    typedef VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL Type;
};

// Map type VkInitializePerformanceApiInfoINTEL to id VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL
template <> struct LvlTypeMap<VkInitializePerformanceApiInfoINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL> {
    typedef VkInitializePerformanceApiInfoINTEL Type;
};

// Map type VkQueryPoolCreateInfoINTEL to id VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL
template <> struct LvlTypeMap<VkQueryPoolCreateInfoINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL> {
    typedef VkQueryPoolCreateInfoINTEL Type;
};

// Map type VkPerformanceMarkerInfoINTEL to id VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL
template <> struct LvlTypeMap<VkPerformanceMarkerInfoINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL> {
    typedef VkPerformanceMarkerInfoINTEL Type;
};

// Map type VkPerformanceStreamMarkerInfoINTEL to id VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL
template <> struct LvlTypeMap<VkPerformanceStreamMarkerInfoINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL> {
    typedef VkPerformanceStreamMarkerInfoINTEL Type;
};

// Map type VkPerformanceOverrideInfoINTEL to id VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL
template <> struct LvlTypeMap<VkPerformanceOverrideInfoINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL> {
    typedef VkPerformanceOverrideInfoINTEL Type;
};

// Map type VkPerformanceConfigurationAcquireInfoINTEL to id VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL
template <> struct LvlTypeMap<VkPerformanceConfigurationAcquireInfoINTEL> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL> {
    typedef VkPerformanceConfigurationAcquireInfoINTEL Type;
};

// Map type VkPhysicalDevicePCIBusInfoPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDevicePCIBusInfoPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT> {
    typedef VkPhysicalDevicePCIBusInfoPropertiesEXT Type;
};

// Map type VkDisplayNativeHdrSurfaceCapabilitiesAMD to id VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD
template <> struct LvlTypeMap<VkDisplayNativeHdrSurfaceCapabilitiesAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD> {
    typedef VkDisplayNativeHdrSurfaceCapabilitiesAMD Type;
};

// Map type VkSwapchainDisplayNativeHdrCreateInfoAMD to id VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD
template <> struct LvlTypeMap<VkSwapchainDisplayNativeHdrCreateInfoAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD> {
    typedef VkSwapchainDisplayNativeHdrCreateInfoAMD Type;
};

#ifdef VK_USE_PLATFORM_FUCHSIA
// Map type VkImagePipeSurfaceCreateInfoFUCHSIA to id VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA
template <> struct LvlTypeMap<VkImagePipeSurfaceCreateInfoFUCHSIA> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA> {
    typedef VkImagePipeSurfaceCreateInfoFUCHSIA Type;
};

#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
// Map type VkMetalSurfaceCreateInfoEXT to id VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkMetalSurfaceCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT> {
    typedef VkMetalSurfaceCreateInfoEXT Type;
};

#endif // VK_USE_PLATFORM_METAL_EXT
// Map type VkPhysicalDeviceFragmentDensityMapFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceFragmentDensityMapFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT> {
    typedef VkPhysicalDeviceFragmentDensityMapFeaturesEXT Type;
};

// Map type VkPhysicalDeviceFragmentDensityMapPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceFragmentDensityMapPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceFragmentDensityMapPropertiesEXT Type;
};

// Map type VkRenderPassFragmentDensityMapCreateInfoEXT to id VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkRenderPassFragmentDensityMapCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT> {
    typedef VkRenderPassFragmentDensityMapCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceSubgroupSizeControlFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT> {
    typedef VkPhysicalDeviceSubgroupSizeControlFeaturesEXT Type;
};

// Map type VkPhysicalDeviceSubgroupSizeControlPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceSubgroupSizeControlPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceSubgroupSizeControlPropertiesEXT Type;
};

// Map type VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT> {
    typedef VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceShaderCoreProperties2AMD to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD
template <> struct LvlTypeMap<VkPhysicalDeviceShaderCoreProperties2AMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD> {
    typedef VkPhysicalDeviceShaderCoreProperties2AMD Type;
};

// Map type VkPhysicalDeviceCoherentMemoryFeaturesAMD to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD
template <> struct LvlTypeMap<VkPhysicalDeviceCoherentMemoryFeaturesAMD> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD> {
    typedef VkPhysicalDeviceCoherentMemoryFeaturesAMD Type;
};

// Map type VkPhysicalDeviceMemoryBudgetPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceMemoryBudgetPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceMemoryBudgetPropertiesEXT Type;
};

// Map type VkPhysicalDeviceMemoryPriorityFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceMemoryPriorityFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT> {
    typedef VkPhysicalDeviceMemoryPriorityFeaturesEXT Type;
};

// Map type VkMemoryPriorityAllocateInfoEXT to id VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT
template <> struct LvlTypeMap<VkMemoryPriorityAllocateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT> {
    typedef VkMemoryPriorityAllocateInfoEXT Type;
};

// Map type VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV> {
    typedef VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV Type;
};

// Map type VkPhysicalDeviceBufferDeviceAddressFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT> {
    typedef VkPhysicalDeviceBufferDeviceAddressFeaturesEXT Type;
};

// Map type VkBufferDeviceAddressCreateInfoEXT to id VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkBufferDeviceAddressCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT> {
    typedef VkBufferDeviceAddressCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceToolPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceToolPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceToolPropertiesEXT Type;
};

// Map type VkValidationFeaturesEXT to id VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT
template <> struct LvlTypeMap<VkValidationFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT> {
    typedef VkValidationFeaturesEXT Type;
};

// Map type VkCooperativeMatrixPropertiesNV to id VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV
template <> struct LvlTypeMap<VkCooperativeMatrixPropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV> {
    typedef VkCooperativeMatrixPropertiesNV Type;
};

// Map type VkPhysicalDeviceCooperativeMatrixFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceCooperativeMatrixFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV> {
    typedef VkPhysicalDeviceCooperativeMatrixFeaturesNV Type;
};

// Map type VkPhysicalDeviceCooperativeMatrixPropertiesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceCooperativeMatrixPropertiesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV> {
    typedef VkPhysicalDeviceCooperativeMatrixPropertiesNV Type;
};

// Map type VkPhysicalDeviceCoverageReductionModeFeaturesNV to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV
template <> struct LvlTypeMap<VkPhysicalDeviceCoverageReductionModeFeaturesNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV> {
    typedef VkPhysicalDeviceCoverageReductionModeFeaturesNV Type;
};

// Map type VkPipelineCoverageReductionStateCreateInfoNV to id VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV
template <> struct LvlTypeMap<VkPipelineCoverageReductionStateCreateInfoNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV> {
    typedef VkPipelineCoverageReductionStateCreateInfoNV Type;
};

// Map type VkFramebufferMixedSamplesCombinationNV to id VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV
template <> struct LvlTypeMap<VkFramebufferMixedSamplesCombinationNV> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV> {
    typedef VkFramebufferMixedSamplesCombinationNV Type;
};

// Map type VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT> {
    typedef VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT Type;
};

// Map type VkPhysicalDeviceYcbcrImageArraysFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT> {
    typedef VkPhysicalDeviceYcbcrImageArraysFeaturesEXT Type;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkSurfaceFullScreenExclusiveInfoEXT to id VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT
template <> struct LvlTypeMap<VkSurfaceFullScreenExclusiveInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT> {
    typedef VkSurfaceFullScreenExclusiveInfoEXT Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkSurfaceCapabilitiesFullScreenExclusiveEXT to id VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT
template <> struct LvlTypeMap<VkSurfaceCapabilitiesFullScreenExclusiveEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT> {
    typedef VkSurfaceCapabilitiesFullScreenExclusiveEXT Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
// Map type VkSurfaceFullScreenExclusiveWin32InfoEXT to id VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT
template <> struct LvlTypeMap<VkSurfaceFullScreenExclusiveWin32InfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT> {
    typedef VkSurfaceFullScreenExclusiveWin32InfoEXT Type;
};

#endif // VK_USE_PLATFORM_WIN32_KHR
// Map type VkHeadlessSurfaceCreateInfoEXT to id VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkHeadlessSurfaceCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT> {
    typedef VkHeadlessSurfaceCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceLineRasterizationFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceLineRasterizationFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT> {
    typedef VkPhysicalDeviceLineRasterizationFeaturesEXT Type;
};

// Map type VkPhysicalDeviceLineRasterizationPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceLineRasterizationPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceLineRasterizationPropertiesEXT Type;
};

// Map type VkPipelineRasterizationLineStateCreateInfoEXT to id VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT
template <> struct LvlTypeMap<VkPipelineRasterizationLineStateCreateInfoEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT> {
    typedef VkPipelineRasterizationLineStateCreateInfoEXT Type;
};

// Map type VkPhysicalDeviceIndexTypeUint8FeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceIndexTypeUint8FeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT> {
    typedef VkPhysicalDeviceIndexTypeUint8FeaturesEXT Type;
};

// Map type VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT> {
    typedef VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT Type;
};

// Map type VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT> {
    typedef VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT Type;
};

// Map type VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT to id VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT
template <> struct LvlTypeMap<VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT> {
    static const VkStructureType kSType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT;
};

template <> struct LvlSTypeMap<VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT> {
    typedef VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT Type;
};

// Find an entry of the given type in the pNext chain
template <typename T> const T *lvl_find_in_chain(const void *next) {
    const VkBaseOutStructure *current = reinterpret_cast<const VkBaseOutStructure *>(next);
    const T *found = nullptr;
    while (current) {
        if (LvlTypeMap<T>::kSType == current->sType) {
            found = reinterpret_cast<const T*>(current);
            current = nullptr;
        } else {
            current = current->pNext;
        }
    }
    return found;
}

// Init the header of an sType struct with pNext
template <typename T> T lvl_init_struct(void *p_next) {
    T out = {};
    out.sType = LvlTypeMap<T>::kSType;
    out.pNext = p_next;
    return out;
}

// Init the header of an sType struct
template <typename T> T lvl_init_struct() {
    T out = {};
    out.sType = LvlTypeMap<T>::kSType;
    return out;
}

