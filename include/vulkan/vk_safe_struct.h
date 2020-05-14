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

void *SafePnextCopy(const void *pNext);
void FreePnextChain(const void *pNext);
char *SafeStringCopy(const char *in_string);


struct safe_VkApplicationInfo {
    VkStructureType sType;
    const void* pNext;
    const char* pApplicationName;
    uint32_t applicationVersion;
    const char* pEngineName;
    uint32_t engineVersion;
    uint32_t apiVersion;
    safe_VkApplicationInfo(const VkApplicationInfo* in_struct);
    safe_VkApplicationInfo(const safe_VkApplicationInfo& copy_src);
    safe_VkApplicationInfo& operator=(const safe_VkApplicationInfo& copy_src);
    safe_VkApplicationInfo();
    ~safe_VkApplicationInfo();
    void initialize(const VkApplicationInfo* in_struct);
    void initialize(const safe_VkApplicationInfo* copy_src);
    VkApplicationInfo *ptr() { return reinterpret_cast<VkApplicationInfo *>(this); }
    VkApplicationInfo const *ptr() const { return reinterpret_cast<VkApplicationInfo const *>(this); }
};

struct safe_VkInstanceCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkInstanceCreateFlags flags;
    safe_VkApplicationInfo* pApplicationInfo;
    uint32_t enabledLayerCount;
    const char* const* ppEnabledLayerNames;
    uint32_t enabledExtensionCount;
    const char* const* ppEnabledExtensionNames;
    safe_VkInstanceCreateInfo(const VkInstanceCreateInfo* in_struct);
    safe_VkInstanceCreateInfo(const safe_VkInstanceCreateInfo& copy_src);
    safe_VkInstanceCreateInfo& operator=(const safe_VkInstanceCreateInfo& copy_src);
    safe_VkInstanceCreateInfo();
    ~safe_VkInstanceCreateInfo();
    void initialize(const VkInstanceCreateInfo* in_struct);
    void initialize(const safe_VkInstanceCreateInfo* copy_src);
    VkInstanceCreateInfo *ptr() { return reinterpret_cast<VkInstanceCreateInfo *>(this); }
    VkInstanceCreateInfo const *ptr() const { return reinterpret_cast<VkInstanceCreateInfo const *>(this); }
};

struct safe_VkAllocationCallbacks {
    void* pUserData;
    PFN_vkAllocationFunction pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
    safe_VkAllocationCallbacks(const VkAllocationCallbacks* in_struct);
    safe_VkAllocationCallbacks(const safe_VkAllocationCallbacks& copy_src);
    safe_VkAllocationCallbacks& operator=(const safe_VkAllocationCallbacks& copy_src);
    safe_VkAllocationCallbacks();
    ~safe_VkAllocationCallbacks();
    void initialize(const VkAllocationCallbacks* in_struct);
    void initialize(const safe_VkAllocationCallbacks* copy_src);
    VkAllocationCallbacks *ptr() { return reinterpret_cast<VkAllocationCallbacks *>(this); }
    VkAllocationCallbacks const *ptr() const { return reinterpret_cast<VkAllocationCallbacks const *>(this); }
};

struct safe_VkDeviceQueueCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDeviceQueueCreateFlags flags;
    uint32_t queueFamilyIndex;
    uint32_t queueCount;
    const float* pQueuePriorities;
    safe_VkDeviceQueueCreateInfo(const VkDeviceQueueCreateInfo* in_struct);
    safe_VkDeviceQueueCreateInfo(const safe_VkDeviceQueueCreateInfo& copy_src);
    safe_VkDeviceQueueCreateInfo& operator=(const safe_VkDeviceQueueCreateInfo& copy_src);
    safe_VkDeviceQueueCreateInfo();
    ~safe_VkDeviceQueueCreateInfo();
    void initialize(const VkDeviceQueueCreateInfo* in_struct);
    void initialize(const safe_VkDeviceQueueCreateInfo* copy_src);
    VkDeviceQueueCreateInfo *ptr() { return reinterpret_cast<VkDeviceQueueCreateInfo *>(this); }
    VkDeviceQueueCreateInfo const *ptr() const { return reinterpret_cast<VkDeviceQueueCreateInfo const *>(this); }
};

struct safe_VkDeviceCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDeviceCreateFlags flags;
    uint32_t queueCreateInfoCount;
    safe_VkDeviceQueueCreateInfo* pQueueCreateInfos;
    uint32_t enabledLayerCount;
    const char* const* ppEnabledLayerNames;
    uint32_t enabledExtensionCount;
    const char* const* ppEnabledExtensionNames;
    const VkPhysicalDeviceFeatures* pEnabledFeatures;
    safe_VkDeviceCreateInfo(const VkDeviceCreateInfo* in_struct);
    safe_VkDeviceCreateInfo(const safe_VkDeviceCreateInfo& copy_src);
    safe_VkDeviceCreateInfo& operator=(const safe_VkDeviceCreateInfo& copy_src);
    safe_VkDeviceCreateInfo();
    ~safe_VkDeviceCreateInfo();
    void initialize(const VkDeviceCreateInfo* in_struct);
    void initialize(const safe_VkDeviceCreateInfo* copy_src);
    VkDeviceCreateInfo *ptr() { return reinterpret_cast<VkDeviceCreateInfo *>(this); }
    VkDeviceCreateInfo const *ptr() const { return reinterpret_cast<VkDeviceCreateInfo const *>(this); }
};

struct safe_VkSubmitInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t waitSemaphoreCount;
    VkSemaphore* pWaitSemaphores;
    const VkPipelineStageFlags* pWaitDstStageMask;
    uint32_t commandBufferCount;
    VkCommandBuffer* pCommandBuffers;
    uint32_t signalSemaphoreCount;
    VkSemaphore* pSignalSemaphores;
    safe_VkSubmitInfo(const VkSubmitInfo* in_struct);
    safe_VkSubmitInfo(const safe_VkSubmitInfo& copy_src);
    safe_VkSubmitInfo& operator=(const safe_VkSubmitInfo& copy_src);
    safe_VkSubmitInfo();
    ~safe_VkSubmitInfo();
    void initialize(const VkSubmitInfo* in_struct);
    void initialize(const safe_VkSubmitInfo* copy_src);
    VkSubmitInfo *ptr() { return reinterpret_cast<VkSubmitInfo *>(this); }
    VkSubmitInfo const *ptr() const { return reinterpret_cast<VkSubmitInfo const *>(this); }
};

struct safe_VkMemoryAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDeviceSize allocationSize;
    uint32_t memoryTypeIndex;
    safe_VkMemoryAllocateInfo(const VkMemoryAllocateInfo* in_struct);
    safe_VkMemoryAllocateInfo(const safe_VkMemoryAllocateInfo& copy_src);
    safe_VkMemoryAllocateInfo& operator=(const safe_VkMemoryAllocateInfo& copy_src);
    safe_VkMemoryAllocateInfo();
    ~safe_VkMemoryAllocateInfo();
    void initialize(const VkMemoryAllocateInfo* in_struct);
    void initialize(const safe_VkMemoryAllocateInfo* copy_src);
    VkMemoryAllocateInfo *ptr() { return reinterpret_cast<VkMemoryAllocateInfo *>(this); }
    VkMemoryAllocateInfo const *ptr() const { return reinterpret_cast<VkMemoryAllocateInfo const *>(this); }
};

struct safe_VkMappedMemoryRange {
    VkStructureType sType;
    const void* pNext;
    VkDeviceMemory memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    safe_VkMappedMemoryRange(const VkMappedMemoryRange* in_struct);
    safe_VkMappedMemoryRange(const safe_VkMappedMemoryRange& copy_src);
    safe_VkMappedMemoryRange& operator=(const safe_VkMappedMemoryRange& copy_src);
    safe_VkMappedMemoryRange();
    ~safe_VkMappedMemoryRange();
    void initialize(const VkMappedMemoryRange* in_struct);
    void initialize(const safe_VkMappedMemoryRange* copy_src);
    VkMappedMemoryRange *ptr() { return reinterpret_cast<VkMappedMemoryRange *>(this); }
    VkMappedMemoryRange const *ptr() const { return reinterpret_cast<VkMappedMemoryRange const *>(this); }
};

struct safe_VkSparseBufferMemoryBindInfo {
    VkBuffer buffer;
    uint32_t bindCount;
    VkSparseMemoryBind* pBinds;
    safe_VkSparseBufferMemoryBindInfo(const VkSparseBufferMemoryBindInfo* in_struct);
    safe_VkSparseBufferMemoryBindInfo(const safe_VkSparseBufferMemoryBindInfo& copy_src);
    safe_VkSparseBufferMemoryBindInfo& operator=(const safe_VkSparseBufferMemoryBindInfo& copy_src);
    safe_VkSparseBufferMemoryBindInfo();
    ~safe_VkSparseBufferMemoryBindInfo();
    void initialize(const VkSparseBufferMemoryBindInfo* in_struct);
    void initialize(const safe_VkSparseBufferMemoryBindInfo* copy_src);
    VkSparseBufferMemoryBindInfo *ptr() { return reinterpret_cast<VkSparseBufferMemoryBindInfo *>(this); }
    VkSparseBufferMemoryBindInfo const *ptr() const { return reinterpret_cast<VkSparseBufferMemoryBindInfo const *>(this); }
};

struct safe_VkSparseImageOpaqueMemoryBindInfo {
    VkImage image;
    uint32_t bindCount;
    VkSparseMemoryBind* pBinds;
    safe_VkSparseImageOpaqueMemoryBindInfo(const VkSparseImageOpaqueMemoryBindInfo* in_struct);
    safe_VkSparseImageOpaqueMemoryBindInfo(const safe_VkSparseImageOpaqueMemoryBindInfo& copy_src);
    safe_VkSparseImageOpaqueMemoryBindInfo& operator=(const safe_VkSparseImageOpaqueMemoryBindInfo& copy_src);
    safe_VkSparseImageOpaqueMemoryBindInfo();
    ~safe_VkSparseImageOpaqueMemoryBindInfo();
    void initialize(const VkSparseImageOpaqueMemoryBindInfo* in_struct);
    void initialize(const safe_VkSparseImageOpaqueMemoryBindInfo* copy_src);
    VkSparseImageOpaqueMemoryBindInfo *ptr() { return reinterpret_cast<VkSparseImageOpaqueMemoryBindInfo *>(this); }
    VkSparseImageOpaqueMemoryBindInfo const *ptr() const { return reinterpret_cast<VkSparseImageOpaqueMemoryBindInfo const *>(this); }
};

struct safe_VkSparseImageMemoryBindInfo {
    VkImage image;
    uint32_t bindCount;
    VkSparseImageMemoryBind* pBinds;
    safe_VkSparseImageMemoryBindInfo(const VkSparseImageMemoryBindInfo* in_struct);
    safe_VkSparseImageMemoryBindInfo(const safe_VkSparseImageMemoryBindInfo& copy_src);
    safe_VkSparseImageMemoryBindInfo& operator=(const safe_VkSparseImageMemoryBindInfo& copy_src);
    safe_VkSparseImageMemoryBindInfo();
    ~safe_VkSparseImageMemoryBindInfo();
    void initialize(const VkSparseImageMemoryBindInfo* in_struct);
    void initialize(const safe_VkSparseImageMemoryBindInfo* copy_src);
    VkSparseImageMemoryBindInfo *ptr() { return reinterpret_cast<VkSparseImageMemoryBindInfo *>(this); }
    VkSparseImageMemoryBindInfo const *ptr() const { return reinterpret_cast<VkSparseImageMemoryBindInfo const *>(this); }
};

struct safe_VkBindSparseInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t waitSemaphoreCount;
    VkSemaphore* pWaitSemaphores;
    uint32_t bufferBindCount;
    safe_VkSparseBufferMemoryBindInfo* pBufferBinds;
    uint32_t imageOpaqueBindCount;
    safe_VkSparseImageOpaqueMemoryBindInfo* pImageOpaqueBinds;
    uint32_t imageBindCount;
    safe_VkSparseImageMemoryBindInfo* pImageBinds;
    uint32_t signalSemaphoreCount;
    VkSemaphore* pSignalSemaphores;
    safe_VkBindSparseInfo(const VkBindSparseInfo* in_struct);
    safe_VkBindSparseInfo(const safe_VkBindSparseInfo& copy_src);
    safe_VkBindSparseInfo& operator=(const safe_VkBindSparseInfo& copy_src);
    safe_VkBindSparseInfo();
    ~safe_VkBindSparseInfo();
    void initialize(const VkBindSparseInfo* in_struct);
    void initialize(const safe_VkBindSparseInfo* copy_src);
    VkBindSparseInfo *ptr() { return reinterpret_cast<VkBindSparseInfo *>(this); }
    VkBindSparseInfo const *ptr() const { return reinterpret_cast<VkBindSparseInfo const *>(this); }
};

struct safe_VkFenceCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkFenceCreateFlags flags;
    safe_VkFenceCreateInfo(const VkFenceCreateInfo* in_struct);
    safe_VkFenceCreateInfo(const safe_VkFenceCreateInfo& copy_src);
    safe_VkFenceCreateInfo& operator=(const safe_VkFenceCreateInfo& copy_src);
    safe_VkFenceCreateInfo();
    ~safe_VkFenceCreateInfo();
    void initialize(const VkFenceCreateInfo* in_struct);
    void initialize(const safe_VkFenceCreateInfo* copy_src);
    VkFenceCreateInfo *ptr() { return reinterpret_cast<VkFenceCreateInfo *>(this); }
    VkFenceCreateInfo const *ptr() const { return reinterpret_cast<VkFenceCreateInfo const *>(this); }
};

struct safe_VkSemaphoreCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkSemaphoreCreateFlags flags;
    safe_VkSemaphoreCreateInfo(const VkSemaphoreCreateInfo* in_struct);
    safe_VkSemaphoreCreateInfo(const safe_VkSemaphoreCreateInfo& copy_src);
    safe_VkSemaphoreCreateInfo& operator=(const safe_VkSemaphoreCreateInfo& copy_src);
    safe_VkSemaphoreCreateInfo();
    ~safe_VkSemaphoreCreateInfo();
    void initialize(const VkSemaphoreCreateInfo* in_struct);
    void initialize(const safe_VkSemaphoreCreateInfo* copy_src);
    VkSemaphoreCreateInfo *ptr() { return reinterpret_cast<VkSemaphoreCreateInfo *>(this); }
    VkSemaphoreCreateInfo const *ptr() const { return reinterpret_cast<VkSemaphoreCreateInfo const *>(this); }
};

struct safe_VkEventCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkEventCreateFlags flags;
    safe_VkEventCreateInfo(const VkEventCreateInfo* in_struct);
    safe_VkEventCreateInfo(const safe_VkEventCreateInfo& copy_src);
    safe_VkEventCreateInfo& operator=(const safe_VkEventCreateInfo& copy_src);
    safe_VkEventCreateInfo();
    ~safe_VkEventCreateInfo();
    void initialize(const VkEventCreateInfo* in_struct);
    void initialize(const safe_VkEventCreateInfo* copy_src);
    VkEventCreateInfo *ptr() { return reinterpret_cast<VkEventCreateInfo *>(this); }
    VkEventCreateInfo const *ptr() const { return reinterpret_cast<VkEventCreateInfo const *>(this); }
};

struct safe_VkQueryPoolCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkQueryPoolCreateFlags flags;
    VkQueryType queryType;
    uint32_t queryCount;
    VkQueryPipelineStatisticFlags pipelineStatistics;
    safe_VkQueryPoolCreateInfo(const VkQueryPoolCreateInfo* in_struct);
    safe_VkQueryPoolCreateInfo(const safe_VkQueryPoolCreateInfo& copy_src);
    safe_VkQueryPoolCreateInfo& operator=(const safe_VkQueryPoolCreateInfo& copy_src);
    safe_VkQueryPoolCreateInfo();
    ~safe_VkQueryPoolCreateInfo();
    void initialize(const VkQueryPoolCreateInfo* in_struct);
    void initialize(const safe_VkQueryPoolCreateInfo* copy_src);
    VkQueryPoolCreateInfo *ptr() { return reinterpret_cast<VkQueryPoolCreateInfo *>(this); }
    VkQueryPoolCreateInfo const *ptr() const { return reinterpret_cast<VkQueryPoolCreateInfo const *>(this); }
};

struct safe_VkBufferCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkBufferCreateFlags flags;
    VkDeviceSize size;
    VkBufferUsageFlags usage;
    VkSharingMode sharingMode;
    uint32_t queueFamilyIndexCount;
    const uint32_t* pQueueFamilyIndices;
    safe_VkBufferCreateInfo(const VkBufferCreateInfo* in_struct);
    safe_VkBufferCreateInfo(const safe_VkBufferCreateInfo& copy_src);
    safe_VkBufferCreateInfo& operator=(const safe_VkBufferCreateInfo& copy_src);
    safe_VkBufferCreateInfo();
    ~safe_VkBufferCreateInfo();
    void initialize(const VkBufferCreateInfo* in_struct);
    void initialize(const safe_VkBufferCreateInfo* copy_src);
    VkBufferCreateInfo *ptr() { return reinterpret_cast<VkBufferCreateInfo *>(this); }
    VkBufferCreateInfo const *ptr() const { return reinterpret_cast<VkBufferCreateInfo const *>(this); }
};

struct safe_VkBufferViewCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkBufferViewCreateFlags flags;
    VkBuffer buffer;
    VkFormat format;
    VkDeviceSize offset;
    VkDeviceSize range;
    safe_VkBufferViewCreateInfo(const VkBufferViewCreateInfo* in_struct);
    safe_VkBufferViewCreateInfo(const safe_VkBufferViewCreateInfo& copy_src);
    safe_VkBufferViewCreateInfo& operator=(const safe_VkBufferViewCreateInfo& copy_src);
    safe_VkBufferViewCreateInfo();
    ~safe_VkBufferViewCreateInfo();
    void initialize(const VkBufferViewCreateInfo* in_struct);
    void initialize(const safe_VkBufferViewCreateInfo* copy_src);
    VkBufferViewCreateInfo *ptr() { return reinterpret_cast<VkBufferViewCreateInfo *>(this); }
    VkBufferViewCreateInfo const *ptr() const { return reinterpret_cast<VkBufferViewCreateInfo const *>(this); }
};

struct safe_VkImageCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageCreateFlags flags;
    VkImageType imageType;
    VkFormat format;
    VkExtent3D extent;
    uint32_t mipLevels;
    uint32_t arrayLayers;
    VkSampleCountFlagBits samples;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkSharingMode sharingMode;
    uint32_t queueFamilyIndexCount;
    const uint32_t* pQueueFamilyIndices;
    VkImageLayout initialLayout;
    safe_VkImageCreateInfo(const VkImageCreateInfo* in_struct);
    safe_VkImageCreateInfo(const safe_VkImageCreateInfo& copy_src);
    safe_VkImageCreateInfo& operator=(const safe_VkImageCreateInfo& copy_src);
    safe_VkImageCreateInfo();
    ~safe_VkImageCreateInfo();
    void initialize(const VkImageCreateInfo* in_struct);
    void initialize(const safe_VkImageCreateInfo* copy_src);
    VkImageCreateInfo *ptr() { return reinterpret_cast<VkImageCreateInfo *>(this); }
    VkImageCreateInfo const *ptr() const { return reinterpret_cast<VkImageCreateInfo const *>(this); }
};

struct safe_VkImageViewCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageViewCreateFlags flags;
    VkImage image;
    VkImageViewType viewType;
    VkFormat format;
    VkComponentMapping components;
    VkImageSubresourceRange subresourceRange;
    safe_VkImageViewCreateInfo(const VkImageViewCreateInfo* in_struct);
    safe_VkImageViewCreateInfo(const safe_VkImageViewCreateInfo& copy_src);
    safe_VkImageViewCreateInfo& operator=(const safe_VkImageViewCreateInfo& copy_src);
    safe_VkImageViewCreateInfo();
    ~safe_VkImageViewCreateInfo();
    void initialize(const VkImageViewCreateInfo* in_struct);
    void initialize(const safe_VkImageViewCreateInfo* copy_src);
    VkImageViewCreateInfo *ptr() { return reinterpret_cast<VkImageViewCreateInfo *>(this); }
    VkImageViewCreateInfo const *ptr() const { return reinterpret_cast<VkImageViewCreateInfo const *>(this); }
};

struct safe_VkShaderModuleCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkShaderModuleCreateFlags flags;
    size_t codeSize;
    const uint32_t* pCode;
    safe_VkShaderModuleCreateInfo(const VkShaderModuleCreateInfo* in_struct);
    safe_VkShaderModuleCreateInfo(const safe_VkShaderModuleCreateInfo& copy_src);
    safe_VkShaderModuleCreateInfo& operator=(const safe_VkShaderModuleCreateInfo& copy_src);
    safe_VkShaderModuleCreateInfo();
    ~safe_VkShaderModuleCreateInfo();
    void initialize(const VkShaderModuleCreateInfo* in_struct);
    void initialize(const safe_VkShaderModuleCreateInfo* copy_src);
    VkShaderModuleCreateInfo *ptr() { return reinterpret_cast<VkShaderModuleCreateInfo *>(this); }
    VkShaderModuleCreateInfo const *ptr() const { return reinterpret_cast<VkShaderModuleCreateInfo const *>(this); }
};

struct safe_VkPipelineCacheCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCacheCreateFlags flags;
    size_t initialDataSize;
    const void* pInitialData;
    safe_VkPipelineCacheCreateInfo(const VkPipelineCacheCreateInfo* in_struct);
    safe_VkPipelineCacheCreateInfo(const safe_VkPipelineCacheCreateInfo& copy_src);
    safe_VkPipelineCacheCreateInfo& operator=(const safe_VkPipelineCacheCreateInfo& copy_src);
    safe_VkPipelineCacheCreateInfo();
    ~safe_VkPipelineCacheCreateInfo();
    void initialize(const VkPipelineCacheCreateInfo* in_struct);
    void initialize(const safe_VkPipelineCacheCreateInfo* copy_src);
    VkPipelineCacheCreateInfo *ptr() { return reinterpret_cast<VkPipelineCacheCreateInfo *>(this); }
    VkPipelineCacheCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineCacheCreateInfo const *>(this); }
};

struct safe_VkSpecializationInfo {
    uint32_t mapEntryCount;
    const VkSpecializationMapEntry* pMapEntries;
    size_t dataSize;
    const void* pData;
    safe_VkSpecializationInfo(const VkSpecializationInfo* in_struct);
    safe_VkSpecializationInfo(const safe_VkSpecializationInfo& copy_src);
    safe_VkSpecializationInfo& operator=(const safe_VkSpecializationInfo& copy_src);
    safe_VkSpecializationInfo();
    ~safe_VkSpecializationInfo();
    void initialize(const VkSpecializationInfo* in_struct);
    void initialize(const safe_VkSpecializationInfo* copy_src);
    VkSpecializationInfo *ptr() { return reinterpret_cast<VkSpecializationInfo *>(this); }
    VkSpecializationInfo const *ptr() const { return reinterpret_cast<VkSpecializationInfo const *>(this); }
};

struct safe_VkPipelineShaderStageCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineShaderStageCreateFlags flags;
    VkShaderStageFlagBits stage;
    VkShaderModule module;
    const char* pName;
    safe_VkSpecializationInfo* pSpecializationInfo;
    safe_VkPipelineShaderStageCreateInfo(const VkPipelineShaderStageCreateInfo* in_struct);
    safe_VkPipelineShaderStageCreateInfo(const safe_VkPipelineShaderStageCreateInfo& copy_src);
    safe_VkPipelineShaderStageCreateInfo& operator=(const safe_VkPipelineShaderStageCreateInfo& copy_src);
    safe_VkPipelineShaderStageCreateInfo();
    ~safe_VkPipelineShaderStageCreateInfo();
    void initialize(const VkPipelineShaderStageCreateInfo* in_struct);
    void initialize(const safe_VkPipelineShaderStageCreateInfo* copy_src);
    VkPipelineShaderStageCreateInfo *ptr() { return reinterpret_cast<VkPipelineShaderStageCreateInfo *>(this); }
    VkPipelineShaderStageCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineShaderStageCreateInfo const *>(this); }
};

struct safe_VkPipelineVertexInputStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineVertexInputStateCreateFlags flags;
    uint32_t vertexBindingDescriptionCount;
    const VkVertexInputBindingDescription* pVertexBindingDescriptions;
    uint32_t vertexAttributeDescriptionCount;
    const VkVertexInputAttributeDescription* pVertexAttributeDescriptions;
    safe_VkPipelineVertexInputStateCreateInfo(const VkPipelineVertexInputStateCreateInfo* in_struct);
    safe_VkPipelineVertexInputStateCreateInfo(const safe_VkPipelineVertexInputStateCreateInfo& copy_src);
    safe_VkPipelineVertexInputStateCreateInfo& operator=(const safe_VkPipelineVertexInputStateCreateInfo& copy_src);
    safe_VkPipelineVertexInputStateCreateInfo();
    ~safe_VkPipelineVertexInputStateCreateInfo();
    void initialize(const VkPipelineVertexInputStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineVertexInputStateCreateInfo* copy_src);
    VkPipelineVertexInputStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineVertexInputStateCreateInfo *>(this); }
    VkPipelineVertexInputStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineVertexInputStateCreateInfo const *>(this); }
};

struct safe_VkPipelineInputAssemblyStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineInputAssemblyStateCreateFlags flags;
    VkPrimitiveTopology topology;
    VkBool32 primitiveRestartEnable;
    safe_VkPipelineInputAssemblyStateCreateInfo(const VkPipelineInputAssemblyStateCreateInfo* in_struct);
    safe_VkPipelineInputAssemblyStateCreateInfo(const safe_VkPipelineInputAssemblyStateCreateInfo& copy_src);
    safe_VkPipelineInputAssemblyStateCreateInfo& operator=(const safe_VkPipelineInputAssemblyStateCreateInfo& copy_src);
    safe_VkPipelineInputAssemblyStateCreateInfo();
    ~safe_VkPipelineInputAssemblyStateCreateInfo();
    void initialize(const VkPipelineInputAssemblyStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineInputAssemblyStateCreateInfo* copy_src);
    VkPipelineInputAssemblyStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineInputAssemblyStateCreateInfo *>(this); }
    VkPipelineInputAssemblyStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineInputAssemblyStateCreateInfo const *>(this); }
};

struct safe_VkPipelineTessellationStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineTessellationStateCreateFlags flags;
    uint32_t patchControlPoints;
    safe_VkPipelineTessellationStateCreateInfo(const VkPipelineTessellationStateCreateInfo* in_struct);
    safe_VkPipelineTessellationStateCreateInfo(const safe_VkPipelineTessellationStateCreateInfo& copy_src);
    safe_VkPipelineTessellationStateCreateInfo& operator=(const safe_VkPipelineTessellationStateCreateInfo& copy_src);
    safe_VkPipelineTessellationStateCreateInfo();
    ~safe_VkPipelineTessellationStateCreateInfo();
    void initialize(const VkPipelineTessellationStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineTessellationStateCreateInfo* copy_src);
    VkPipelineTessellationStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineTessellationStateCreateInfo *>(this); }
    VkPipelineTessellationStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineTessellationStateCreateInfo const *>(this); }
};

struct safe_VkPipelineViewportStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineViewportStateCreateFlags flags;
    uint32_t viewportCount;
    const VkViewport* pViewports;
    uint32_t scissorCount;
    const VkRect2D* pScissors;
    safe_VkPipelineViewportStateCreateInfo(const VkPipelineViewportStateCreateInfo* in_struct, const bool is_dynamic_viewports, const bool is_dynamic_scissors);
    safe_VkPipelineViewportStateCreateInfo(const safe_VkPipelineViewportStateCreateInfo& copy_src);
    safe_VkPipelineViewportStateCreateInfo& operator=(const safe_VkPipelineViewportStateCreateInfo& copy_src);
    safe_VkPipelineViewportStateCreateInfo();
    ~safe_VkPipelineViewportStateCreateInfo();
    void initialize(const VkPipelineViewportStateCreateInfo* in_struct, const bool is_dynamic_viewports, const bool is_dynamic_scissors);
    void initialize(const safe_VkPipelineViewportStateCreateInfo* copy_src);
    VkPipelineViewportStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineViewportStateCreateInfo *>(this); }
    VkPipelineViewportStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineViewportStateCreateInfo const *>(this); }
};

struct safe_VkPipelineRasterizationStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineRasterizationStateCreateFlags flags;
    VkBool32 depthClampEnable;
    VkBool32 rasterizerDiscardEnable;
    VkPolygonMode polygonMode;
    VkCullModeFlags cullMode;
    VkFrontFace frontFace;
    VkBool32 depthBiasEnable;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;
    float lineWidth;
    safe_VkPipelineRasterizationStateCreateInfo(const VkPipelineRasterizationStateCreateInfo* in_struct);
    safe_VkPipelineRasterizationStateCreateInfo(const safe_VkPipelineRasterizationStateCreateInfo& copy_src);
    safe_VkPipelineRasterizationStateCreateInfo& operator=(const safe_VkPipelineRasterizationStateCreateInfo& copy_src);
    safe_VkPipelineRasterizationStateCreateInfo();
    ~safe_VkPipelineRasterizationStateCreateInfo();
    void initialize(const VkPipelineRasterizationStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineRasterizationStateCreateInfo* copy_src);
    VkPipelineRasterizationStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineRasterizationStateCreateInfo *>(this); }
    VkPipelineRasterizationStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineRasterizationStateCreateInfo const *>(this); }
};

struct safe_VkPipelineMultisampleStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineMultisampleStateCreateFlags flags;
    VkSampleCountFlagBits rasterizationSamples;
    VkBool32 sampleShadingEnable;
    float minSampleShading;
    const VkSampleMask* pSampleMask;
    VkBool32 alphaToCoverageEnable;
    VkBool32 alphaToOneEnable;
    safe_VkPipelineMultisampleStateCreateInfo(const VkPipelineMultisampleStateCreateInfo* in_struct);
    safe_VkPipelineMultisampleStateCreateInfo(const safe_VkPipelineMultisampleStateCreateInfo& copy_src);
    safe_VkPipelineMultisampleStateCreateInfo& operator=(const safe_VkPipelineMultisampleStateCreateInfo& copy_src);
    safe_VkPipelineMultisampleStateCreateInfo();
    ~safe_VkPipelineMultisampleStateCreateInfo();
    void initialize(const VkPipelineMultisampleStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineMultisampleStateCreateInfo* copy_src);
    VkPipelineMultisampleStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineMultisampleStateCreateInfo *>(this); }
    VkPipelineMultisampleStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineMultisampleStateCreateInfo const *>(this); }
};

struct safe_VkPipelineDepthStencilStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineDepthStencilStateCreateFlags flags;
    VkBool32 depthTestEnable;
    VkBool32 depthWriteEnable;
    VkCompareOp depthCompareOp;
    VkBool32 depthBoundsTestEnable;
    VkBool32 stencilTestEnable;
    VkStencilOpState front;
    VkStencilOpState back;
    float minDepthBounds;
    float maxDepthBounds;
    safe_VkPipelineDepthStencilStateCreateInfo(const VkPipelineDepthStencilStateCreateInfo* in_struct);
    safe_VkPipelineDepthStencilStateCreateInfo(const safe_VkPipelineDepthStencilStateCreateInfo& copy_src);
    safe_VkPipelineDepthStencilStateCreateInfo& operator=(const safe_VkPipelineDepthStencilStateCreateInfo& copy_src);
    safe_VkPipelineDepthStencilStateCreateInfo();
    ~safe_VkPipelineDepthStencilStateCreateInfo();
    void initialize(const VkPipelineDepthStencilStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineDepthStencilStateCreateInfo* copy_src);
    VkPipelineDepthStencilStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineDepthStencilStateCreateInfo *>(this); }
    VkPipelineDepthStencilStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineDepthStencilStateCreateInfo const *>(this); }
};

struct safe_VkPipelineColorBlendStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineColorBlendStateCreateFlags flags;
    VkBool32 logicOpEnable;
    VkLogicOp logicOp;
    uint32_t attachmentCount;
    const VkPipelineColorBlendAttachmentState* pAttachments;
    float blendConstants[4];
    safe_VkPipelineColorBlendStateCreateInfo(const VkPipelineColorBlendStateCreateInfo* in_struct);
    safe_VkPipelineColorBlendStateCreateInfo(const safe_VkPipelineColorBlendStateCreateInfo& copy_src);
    safe_VkPipelineColorBlendStateCreateInfo& operator=(const safe_VkPipelineColorBlendStateCreateInfo& copy_src);
    safe_VkPipelineColorBlendStateCreateInfo();
    ~safe_VkPipelineColorBlendStateCreateInfo();
    void initialize(const VkPipelineColorBlendStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineColorBlendStateCreateInfo* copy_src);
    VkPipelineColorBlendStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineColorBlendStateCreateInfo *>(this); }
    VkPipelineColorBlendStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineColorBlendStateCreateInfo const *>(this); }
};

struct safe_VkPipelineDynamicStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineDynamicStateCreateFlags flags;
    uint32_t dynamicStateCount;
    const VkDynamicState* pDynamicStates;
    safe_VkPipelineDynamicStateCreateInfo(const VkPipelineDynamicStateCreateInfo* in_struct);
    safe_VkPipelineDynamicStateCreateInfo(const safe_VkPipelineDynamicStateCreateInfo& copy_src);
    safe_VkPipelineDynamicStateCreateInfo& operator=(const safe_VkPipelineDynamicStateCreateInfo& copy_src);
    safe_VkPipelineDynamicStateCreateInfo();
    ~safe_VkPipelineDynamicStateCreateInfo();
    void initialize(const VkPipelineDynamicStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineDynamicStateCreateInfo* copy_src);
    VkPipelineDynamicStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineDynamicStateCreateInfo *>(this); }
    VkPipelineDynamicStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineDynamicStateCreateInfo const *>(this); }
};

struct safe_VkGraphicsPipelineCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCreateFlags flags;
    uint32_t stageCount;
    safe_VkPipelineShaderStageCreateInfo* pStages;
    safe_VkPipelineVertexInputStateCreateInfo* pVertexInputState;
    safe_VkPipelineInputAssemblyStateCreateInfo* pInputAssemblyState;
    safe_VkPipelineTessellationStateCreateInfo* pTessellationState;
    safe_VkPipelineViewportStateCreateInfo* pViewportState;
    safe_VkPipelineRasterizationStateCreateInfo* pRasterizationState;
    safe_VkPipelineMultisampleStateCreateInfo* pMultisampleState;
    safe_VkPipelineDepthStencilStateCreateInfo* pDepthStencilState;
    safe_VkPipelineColorBlendStateCreateInfo* pColorBlendState;
    safe_VkPipelineDynamicStateCreateInfo* pDynamicState;
    VkPipelineLayout layout;
    VkRenderPass renderPass;
    uint32_t subpass;
    VkPipeline basePipelineHandle;
    int32_t basePipelineIndex;
    safe_VkGraphicsPipelineCreateInfo(const VkGraphicsPipelineCreateInfo* in_struct, const bool uses_color_attachment, const bool uses_depthstencil_attachment);
    safe_VkGraphicsPipelineCreateInfo(const safe_VkGraphicsPipelineCreateInfo& copy_src);
    safe_VkGraphicsPipelineCreateInfo& operator=(const safe_VkGraphicsPipelineCreateInfo& copy_src);
    safe_VkGraphicsPipelineCreateInfo();
    ~safe_VkGraphicsPipelineCreateInfo();
    void initialize(const VkGraphicsPipelineCreateInfo* in_struct, const bool uses_color_attachment, const bool uses_depthstencil_attachment);
    void initialize(const safe_VkGraphicsPipelineCreateInfo* copy_src);
    VkGraphicsPipelineCreateInfo *ptr() { return reinterpret_cast<VkGraphicsPipelineCreateInfo *>(this); }
    VkGraphicsPipelineCreateInfo const *ptr() const { return reinterpret_cast<VkGraphicsPipelineCreateInfo const *>(this); }
};

struct safe_VkComputePipelineCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCreateFlags flags;
    safe_VkPipelineShaderStageCreateInfo stage;
    VkPipelineLayout layout;
    VkPipeline basePipelineHandle;
    int32_t basePipelineIndex;
    safe_VkComputePipelineCreateInfo(const VkComputePipelineCreateInfo* in_struct);
    safe_VkComputePipelineCreateInfo(const safe_VkComputePipelineCreateInfo& copy_src);
    safe_VkComputePipelineCreateInfo& operator=(const safe_VkComputePipelineCreateInfo& copy_src);
    safe_VkComputePipelineCreateInfo();
    ~safe_VkComputePipelineCreateInfo();
    void initialize(const VkComputePipelineCreateInfo* in_struct);
    void initialize(const safe_VkComputePipelineCreateInfo* copy_src);
    VkComputePipelineCreateInfo *ptr() { return reinterpret_cast<VkComputePipelineCreateInfo *>(this); }
    VkComputePipelineCreateInfo const *ptr() const { return reinterpret_cast<VkComputePipelineCreateInfo const *>(this); }
};

struct safe_VkPipelineLayoutCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkPipelineLayoutCreateFlags flags;
    uint32_t setLayoutCount;
    VkDescriptorSetLayout* pSetLayouts;
    uint32_t pushConstantRangeCount;
    const VkPushConstantRange* pPushConstantRanges;
    safe_VkPipelineLayoutCreateInfo(const VkPipelineLayoutCreateInfo* in_struct);
    safe_VkPipelineLayoutCreateInfo(const safe_VkPipelineLayoutCreateInfo& copy_src);
    safe_VkPipelineLayoutCreateInfo& operator=(const safe_VkPipelineLayoutCreateInfo& copy_src);
    safe_VkPipelineLayoutCreateInfo();
    ~safe_VkPipelineLayoutCreateInfo();
    void initialize(const VkPipelineLayoutCreateInfo* in_struct);
    void initialize(const safe_VkPipelineLayoutCreateInfo* copy_src);
    VkPipelineLayoutCreateInfo *ptr() { return reinterpret_cast<VkPipelineLayoutCreateInfo *>(this); }
    VkPipelineLayoutCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineLayoutCreateInfo const *>(this); }
};

struct safe_VkSamplerCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkSamplerCreateFlags flags;
    VkFilter magFilter;
    VkFilter minFilter;
    VkSamplerMipmapMode mipmapMode;
    VkSamplerAddressMode addressModeU;
    VkSamplerAddressMode addressModeV;
    VkSamplerAddressMode addressModeW;
    float mipLodBias;
    VkBool32 anisotropyEnable;
    float maxAnisotropy;
    VkBool32 compareEnable;
    VkCompareOp compareOp;
    float minLod;
    float maxLod;
    VkBorderColor borderColor;
    VkBool32 unnormalizedCoordinates;
    safe_VkSamplerCreateInfo(const VkSamplerCreateInfo* in_struct);
    safe_VkSamplerCreateInfo(const safe_VkSamplerCreateInfo& copy_src);
    safe_VkSamplerCreateInfo& operator=(const safe_VkSamplerCreateInfo& copy_src);
    safe_VkSamplerCreateInfo();
    ~safe_VkSamplerCreateInfo();
    void initialize(const VkSamplerCreateInfo* in_struct);
    void initialize(const safe_VkSamplerCreateInfo* copy_src);
    VkSamplerCreateInfo *ptr() { return reinterpret_cast<VkSamplerCreateInfo *>(this); }
    VkSamplerCreateInfo const *ptr() const { return reinterpret_cast<VkSamplerCreateInfo const *>(this); }
};

struct safe_VkDescriptorSetLayoutBinding {
    uint32_t binding;
    VkDescriptorType descriptorType;
    uint32_t descriptorCount;
    VkShaderStageFlags stageFlags;
    VkSampler* pImmutableSamplers;
    safe_VkDescriptorSetLayoutBinding(const VkDescriptorSetLayoutBinding* in_struct);
    safe_VkDescriptorSetLayoutBinding(const safe_VkDescriptorSetLayoutBinding& copy_src);
    safe_VkDescriptorSetLayoutBinding& operator=(const safe_VkDescriptorSetLayoutBinding& copy_src);
    safe_VkDescriptorSetLayoutBinding();
    ~safe_VkDescriptorSetLayoutBinding();
    void initialize(const VkDescriptorSetLayoutBinding* in_struct);
    void initialize(const safe_VkDescriptorSetLayoutBinding* copy_src);
    VkDescriptorSetLayoutBinding *ptr() { return reinterpret_cast<VkDescriptorSetLayoutBinding *>(this); }
    VkDescriptorSetLayoutBinding const *ptr() const { return reinterpret_cast<VkDescriptorSetLayoutBinding const *>(this); }
};

struct safe_VkDescriptorSetLayoutCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDescriptorSetLayoutCreateFlags flags;
    uint32_t bindingCount;
    safe_VkDescriptorSetLayoutBinding* pBindings;
    safe_VkDescriptorSetLayoutCreateInfo(const VkDescriptorSetLayoutCreateInfo* in_struct);
    safe_VkDescriptorSetLayoutCreateInfo(const safe_VkDescriptorSetLayoutCreateInfo& copy_src);
    safe_VkDescriptorSetLayoutCreateInfo& operator=(const safe_VkDescriptorSetLayoutCreateInfo& copy_src);
    safe_VkDescriptorSetLayoutCreateInfo();
    ~safe_VkDescriptorSetLayoutCreateInfo();
    void initialize(const VkDescriptorSetLayoutCreateInfo* in_struct);
    void initialize(const safe_VkDescriptorSetLayoutCreateInfo* copy_src);
    VkDescriptorSetLayoutCreateInfo *ptr() { return reinterpret_cast<VkDescriptorSetLayoutCreateInfo *>(this); }
    VkDescriptorSetLayoutCreateInfo const *ptr() const { return reinterpret_cast<VkDescriptorSetLayoutCreateInfo const *>(this); }
};

struct safe_VkDescriptorPoolCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDescriptorPoolCreateFlags flags;
    uint32_t maxSets;
    uint32_t poolSizeCount;
    const VkDescriptorPoolSize* pPoolSizes;
    safe_VkDescriptorPoolCreateInfo(const VkDescriptorPoolCreateInfo* in_struct);
    safe_VkDescriptorPoolCreateInfo(const safe_VkDescriptorPoolCreateInfo& copy_src);
    safe_VkDescriptorPoolCreateInfo& operator=(const safe_VkDescriptorPoolCreateInfo& copy_src);
    safe_VkDescriptorPoolCreateInfo();
    ~safe_VkDescriptorPoolCreateInfo();
    void initialize(const VkDescriptorPoolCreateInfo* in_struct);
    void initialize(const safe_VkDescriptorPoolCreateInfo* copy_src);
    VkDescriptorPoolCreateInfo *ptr() { return reinterpret_cast<VkDescriptorPoolCreateInfo *>(this); }
    VkDescriptorPoolCreateInfo const *ptr() const { return reinterpret_cast<VkDescriptorPoolCreateInfo const *>(this); }
};

struct safe_VkDescriptorSetAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDescriptorPool descriptorPool;
    uint32_t descriptorSetCount;
    VkDescriptorSetLayout* pSetLayouts;
    safe_VkDescriptorSetAllocateInfo(const VkDescriptorSetAllocateInfo* in_struct);
    safe_VkDescriptorSetAllocateInfo(const safe_VkDescriptorSetAllocateInfo& copy_src);
    safe_VkDescriptorSetAllocateInfo& operator=(const safe_VkDescriptorSetAllocateInfo& copy_src);
    safe_VkDescriptorSetAllocateInfo();
    ~safe_VkDescriptorSetAllocateInfo();
    void initialize(const VkDescriptorSetAllocateInfo* in_struct);
    void initialize(const safe_VkDescriptorSetAllocateInfo* copy_src);
    VkDescriptorSetAllocateInfo *ptr() { return reinterpret_cast<VkDescriptorSetAllocateInfo *>(this); }
    VkDescriptorSetAllocateInfo const *ptr() const { return reinterpret_cast<VkDescriptorSetAllocateInfo const *>(this); }
};

struct safe_VkWriteDescriptorSet {
    VkStructureType sType;
    const void* pNext;
    VkDescriptorSet dstSet;
    uint32_t dstBinding;
    uint32_t dstArrayElement;
    uint32_t descriptorCount;
    VkDescriptorType descriptorType;
    VkDescriptorImageInfo* pImageInfo;
    VkDescriptorBufferInfo* pBufferInfo;
    VkBufferView* pTexelBufferView;
    safe_VkWriteDescriptorSet(const VkWriteDescriptorSet* in_struct);
    safe_VkWriteDescriptorSet(const safe_VkWriteDescriptorSet& copy_src);
    safe_VkWriteDescriptorSet& operator=(const safe_VkWriteDescriptorSet& copy_src);
    safe_VkWriteDescriptorSet();
    ~safe_VkWriteDescriptorSet();
    void initialize(const VkWriteDescriptorSet* in_struct);
    void initialize(const safe_VkWriteDescriptorSet* copy_src);
    VkWriteDescriptorSet *ptr() { return reinterpret_cast<VkWriteDescriptorSet *>(this); }
    VkWriteDescriptorSet const *ptr() const { return reinterpret_cast<VkWriteDescriptorSet const *>(this); }
};

struct safe_VkCopyDescriptorSet {
    VkStructureType sType;
    const void* pNext;
    VkDescriptorSet srcSet;
    uint32_t srcBinding;
    uint32_t srcArrayElement;
    VkDescriptorSet dstSet;
    uint32_t dstBinding;
    uint32_t dstArrayElement;
    uint32_t descriptorCount;
    safe_VkCopyDescriptorSet(const VkCopyDescriptorSet* in_struct);
    safe_VkCopyDescriptorSet(const safe_VkCopyDescriptorSet& copy_src);
    safe_VkCopyDescriptorSet& operator=(const safe_VkCopyDescriptorSet& copy_src);
    safe_VkCopyDescriptorSet();
    ~safe_VkCopyDescriptorSet();
    void initialize(const VkCopyDescriptorSet* in_struct);
    void initialize(const safe_VkCopyDescriptorSet* copy_src);
    VkCopyDescriptorSet *ptr() { return reinterpret_cast<VkCopyDescriptorSet *>(this); }
    VkCopyDescriptorSet const *ptr() const { return reinterpret_cast<VkCopyDescriptorSet const *>(this); }
};

struct safe_VkFramebufferCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkFramebufferCreateFlags flags;
    VkRenderPass renderPass;
    uint32_t attachmentCount;
    VkImageView* pAttachments;
    uint32_t width;
    uint32_t height;
    uint32_t layers;
    safe_VkFramebufferCreateInfo(const VkFramebufferCreateInfo* in_struct);
    safe_VkFramebufferCreateInfo(const safe_VkFramebufferCreateInfo& copy_src);
    safe_VkFramebufferCreateInfo& operator=(const safe_VkFramebufferCreateInfo& copy_src);
    safe_VkFramebufferCreateInfo();
    ~safe_VkFramebufferCreateInfo();
    void initialize(const VkFramebufferCreateInfo* in_struct);
    void initialize(const safe_VkFramebufferCreateInfo* copy_src);
    VkFramebufferCreateInfo *ptr() { return reinterpret_cast<VkFramebufferCreateInfo *>(this); }
    VkFramebufferCreateInfo const *ptr() const { return reinterpret_cast<VkFramebufferCreateInfo const *>(this); }
};

struct safe_VkSubpassDescription {
    VkSubpassDescriptionFlags flags;
    VkPipelineBindPoint pipelineBindPoint;
    uint32_t inputAttachmentCount;
    const VkAttachmentReference* pInputAttachments;
    uint32_t colorAttachmentCount;
    const VkAttachmentReference* pColorAttachments;
    const VkAttachmentReference* pResolveAttachments;
    const VkAttachmentReference* pDepthStencilAttachment;
    uint32_t preserveAttachmentCount;
    const uint32_t* pPreserveAttachments;
    safe_VkSubpassDescription(const VkSubpassDescription* in_struct);
    safe_VkSubpassDescription(const safe_VkSubpassDescription& copy_src);
    safe_VkSubpassDescription& operator=(const safe_VkSubpassDescription& copy_src);
    safe_VkSubpassDescription();
    ~safe_VkSubpassDescription();
    void initialize(const VkSubpassDescription* in_struct);
    void initialize(const safe_VkSubpassDescription* copy_src);
    VkSubpassDescription *ptr() { return reinterpret_cast<VkSubpassDescription *>(this); }
    VkSubpassDescription const *ptr() const { return reinterpret_cast<VkSubpassDescription const *>(this); }
};

struct safe_VkRenderPassCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkRenderPassCreateFlags flags;
    uint32_t attachmentCount;
    const VkAttachmentDescription* pAttachments;
    uint32_t subpassCount;
    safe_VkSubpassDescription* pSubpasses;
    uint32_t dependencyCount;
    const VkSubpassDependency* pDependencies;
    safe_VkRenderPassCreateInfo(const VkRenderPassCreateInfo* in_struct);
    safe_VkRenderPassCreateInfo(const safe_VkRenderPassCreateInfo& copy_src);
    safe_VkRenderPassCreateInfo& operator=(const safe_VkRenderPassCreateInfo& copy_src);
    safe_VkRenderPassCreateInfo();
    ~safe_VkRenderPassCreateInfo();
    void initialize(const VkRenderPassCreateInfo* in_struct);
    void initialize(const safe_VkRenderPassCreateInfo* copy_src);
    VkRenderPassCreateInfo *ptr() { return reinterpret_cast<VkRenderPassCreateInfo *>(this); }
    VkRenderPassCreateInfo const *ptr() const { return reinterpret_cast<VkRenderPassCreateInfo const *>(this); }
};

struct safe_VkCommandPoolCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkCommandPoolCreateFlags flags;
    uint32_t queueFamilyIndex;
    safe_VkCommandPoolCreateInfo(const VkCommandPoolCreateInfo* in_struct);
    safe_VkCommandPoolCreateInfo(const safe_VkCommandPoolCreateInfo& copy_src);
    safe_VkCommandPoolCreateInfo& operator=(const safe_VkCommandPoolCreateInfo& copy_src);
    safe_VkCommandPoolCreateInfo();
    ~safe_VkCommandPoolCreateInfo();
    void initialize(const VkCommandPoolCreateInfo* in_struct);
    void initialize(const safe_VkCommandPoolCreateInfo* copy_src);
    VkCommandPoolCreateInfo *ptr() { return reinterpret_cast<VkCommandPoolCreateInfo *>(this); }
    VkCommandPoolCreateInfo const *ptr() const { return reinterpret_cast<VkCommandPoolCreateInfo const *>(this); }
};

struct safe_VkCommandBufferAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    VkCommandPool commandPool;
    VkCommandBufferLevel level;
    uint32_t commandBufferCount;
    safe_VkCommandBufferAllocateInfo(const VkCommandBufferAllocateInfo* in_struct);
    safe_VkCommandBufferAllocateInfo(const safe_VkCommandBufferAllocateInfo& copy_src);
    safe_VkCommandBufferAllocateInfo& operator=(const safe_VkCommandBufferAllocateInfo& copy_src);
    safe_VkCommandBufferAllocateInfo();
    ~safe_VkCommandBufferAllocateInfo();
    void initialize(const VkCommandBufferAllocateInfo* in_struct);
    void initialize(const safe_VkCommandBufferAllocateInfo* copy_src);
    VkCommandBufferAllocateInfo *ptr() { return reinterpret_cast<VkCommandBufferAllocateInfo *>(this); }
    VkCommandBufferAllocateInfo const *ptr() const { return reinterpret_cast<VkCommandBufferAllocateInfo const *>(this); }
};

struct safe_VkCommandBufferInheritanceInfo {
    VkStructureType sType;
    const void* pNext;
    VkRenderPass renderPass;
    uint32_t subpass;
    VkFramebuffer framebuffer;
    VkBool32 occlusionQueryEnable;
    VkQueryControlFlags queryFlags;
    VkQueryPipelineStatisticFlags pipelineStatistics;
    safe_VkCommandBufferInheritanceInfo(const VkCommandBufferInheritanceInfo* in_struct);
    safe_VkCommandBufferInheritanceInfo(const safe_VkCommandBufferInheritanceInfo& copy_src);
    safe_VkCommandBufferInheritanceInfo& operator=(const safe_VkCommandBufferInheritanceInfo& copy_src);
    safe_VkCommandBufferInheritanceInfo();
    ~safe_VkCommandBufferInheritanceInfo();
    void initialize(const VkCommandBufferInheritanceInfo* in_struct);
    void initialize(const safe_VkCommandBufferInheritanceInfo* copy_src);
    VkCommandBufferInheritanceInfo *ptr() { return reinterpret_cast<VkCommandBufferInheritanceInfo *>(this); }
    VkCommandBufferInheritanceInfo const *ptr() const { return reinterpret_cast<VkCommandBufferInheritanceInfo const *>(this); }
};

struct safe_VkCommandBufferBeginInfo {
    VkStructureType sType;
    const void* pNext;
    VkCommandBufferUsageFlags flags;
    safe_VkCommandBufferInheritanceInfo* pInheritanceInfo;
    safe_VkCommandBufferBeginInfo(const VkCommandBufferBeginInfo* in_struct);
    safe_VkCommandBufferBeginInfo(const safe_VkCommandBufferBeginInfo& copy_src);
    safe_VkCommandBufferBeginInfo& operator=(const safe_VkCommandBufferBeginInfo& copy_src);
    safe_VkCommandBufferBeginInfo();
    ~safe_VkCommandBufferBeginInfo();
    void initialize(const VkCommandBufferBeginInfo* in_struct);
    void initialize(const safe_VkCommandBufferBeginInfo* copy_src);
    VkCommandBufferBeginInfo *ptr() { return reinterpret_cast<VkCommandBufferBeginInfo *>(this); }
    VkCommandBufferBeginInfo const *ptr() const { return reinterpret_cast<VkCommandBufferBeginInfo const *>(this); }
};

struct safe_VkMemoryBarrier {
    VkStructureType sType;
    const void* pNext;
    VkAccessFlags srcAccessMask;
    VkAccessFlags dstAccessMask;
    safe_VkMemoryBarrier(const VkMemoryBarrier* in_struct);
    safe_VkMemoryBarrier(const safe_VkMemoryBarrier& copy_src);
    safe_VkMemoryBarrier& operator=(const safe_VkMemoryBarrier& copy_src);
    safe_VkMemoryBarrier();
    ~safe_VkMemoryBarrier();
    void initialize(const VkMemoryBarrier* in_struct);
    void initialize(const safe_VkMemoryBarrier* copy_src);
    VkMemoryBarrier *ptr() { return reinterpret_cast<VkMemoryBarrier *>(this); }
    VkMemoryBarrier const *ptr() const { return reinterpret_cast<VkMemoryBarrier const *>(this); }
};

struct safe_VkBufferMemoryBarrier {
    VkStructureType sType;
    const void* pNext;
    VkAccessFlags srcAccessMask;
    VkAccessFlags dstAccessMask;
    uint32_t srcQueueFamilyIndex;
    uint32_t dstQueueFamilyIndex;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    safe_VkBufferMemoryBarrier(const VkBufferMemoryBarrier* in_struct);
    safe_VkBufferMemoryBarrier(const safe_VkBufferMemoryBarrier& copy_src);
    safe_VkBufferMemoryBarrier& operator=(const safe_VkBufferMemoryBarrier& copy_src);
    safe_VkBufferMemoryBarrier();
    ~safe_VkBufferMemoryBarrier();
    void initialize(const VkBufferMemoryBarrier* in_struct);
    void initialize(const safe_VkBufferMemoryBarrier* copy_src);
    VkBufferMemoryBarrier *ptr() { return reinterpret_cast<VkBufferMemoryBarrier *>(this); }
    VkBufferMemoryBarrier const *ptr() const { return reinterpret_cast<VkBufferMemoryBarrier const *>(this); }
};

struct safe_VkImageMemoryBarrier {
    VkStructureType sType;
    const void* pNext;
    VkAccessFlags srcAccessMask;
    VkAccessFlags dstAccessMask;
    VkImageLayout oldLayout;
    VkImageLayout newLayout;
    uint32_t srcQueueFamilyIndex;
    uint32_t dstQueueFamilyIndex;
    VkImage image;
    VkImageSubresourceRange subresourceRange;
    safe_VkImageMemoryBarrier(const VkImageMemoryBarrier* in_struct);
    safe_VkImageMemoryBarrier(const safe_VkImageMemoryBarrier& copy_src);
    safe_VkImageMemoryBarrier& operator=(const safe_VkImageMemoryBarrier& copy_src);
    safe_VkImageMemoryBarrier();
    ~safe_VkImageMemoryBarrier();
    void initialize(const VkImageMemoryBarrier* in_struct);
    void initialize(const safe_VkImageMemoryBarrier* copy_src);
    VkImageMemoryBarrier *ptr() { return reinterpret_cast<VkImageMemoryBarrier *>(this); }
    VkImageMemoryBarrier const *ptr() const { return reinterpret_cast<VkImageMemoryBarrier const *>(this); }
};

struct safe_VkRenderPassBeginInfo {
    VkStructureType sType;
    const void* pNext;
    VkRenderPass renderPass;
    VkFramebuffer framebuffer;
    VkRect2D renderArea;
    uint32_t clearValueCount;
    const VkClearValue* pClearValues;
    safe_VkRenderPassBeginInfo(const VkRenderPassBeginInfo* in_struct);
    safe_VkRenderPassBeginInfo(const safe_VkRenderPassBeginInfo& copy_src);
    safe_VkRenderPassBeginInfo& operator=(const safe_VkRenderPassBeginInfo& copy_src);
    safe_VkRenderPassBeginInfo();
    ~safe_VkRenderPassBeginInfo();
    void initialize(const VkRenderPassBeginInfo* in_struct);
    void initialize(const safe_VkRenderPassBeginInfo* copy_src);
    VkRenderPassBeginInfo *ptr() { return reinterpret_cast<VkRenderPassBeginInfo *>(this); }
    VkRenderPassBeginInfo const *ptr() const { return reinterpret_cast<VkRenderPassBeginInfo const *>(this); }
};

struct safe_VkPhysicalDeviceSubgroupProperties {
    VkStructureType sType;
    void* pNext;
    uint32_t subgroupSize;
    VkShaderStageFlags supportedStages;
    VkSubgroupFeatureFlags supportedOperations;
    VkBool32 quadOperationsInAllStages;
    safe_VkPhysicalDeviceSubgroupProperties(const VkPhysicalDeviceSubgroupProperties* in_struct);
    safe_VkPhysicalDeviceSubgroupProperties(const safe_VkPhysicalDeviceSubgroupProperties& copy_src);
    safe_VkPhysicalDeviceSubgroupProperties& operator=(const safe_VkPhysicalDeviceSubgroupProperties& copy_src);
    safe_VkPhysicalDeviceSubgroupProperties();
    ~safe_VkPhysicalDeviceSubgroupProperties();
    void initialize(const VkPhysicalDeviceSubgroupProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceSubgroupProperties* copy_src);
    VkPhysicalDeviceSubgroupProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceSubgroupProperties *>(this); }
    VkPhysicalDeviceSubgroupProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSubgroupProperties const *>(this); }
};

struct safe_VkBindBufferMemoryInfo {
    VkStructureType sType;
    const void* pNext;
    VkBuffer buffer;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    safe_VkBindBufferMemoryInfo(const VkBindBufferMemoryInfo* in_struct);
    safe_VkBindBufferMemoryInfo(const safe_VkBindBufferMemoryInfo& copy_src);
    safe_VkBindBufferMemoryInfo& operator=(const safe_VkBindBufferMemoryInfo& copy_src);
    safe_VkBindBufferMemoryInfo();
    ~safe_VkBindBufferMemoryInfo();
    void initialize(const VkBindBufferMemoryInfo* in_struct);
    void initialize(const safe_VkBindBufferMemoryInfo* copy_src);
    VkBindBufferMemoryInfo *ptr() { return reinterpret_cast<VkBindBufferMemoryInfo *>(this); }
    VkBindBufferMemoryInfo const *ptr() const { return reinterpret_cast<VkBindBufferMemoryInfo const *>(this); }
};

struct safe_VkBindImageMemoryInfo {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    safe_VkBindImageMemoryInfo(const VkBindImageMemoryInfo* in_struct);
    safe_VkBindImageMemoryInfo(const safe_VkBindImageMemoryInfo& copy_src);
    safe_VkBindImageMemoryInfo& operator=(const safe_VkBindImageMemoryInfo& copy_src);
    safe_VkBindImageMemoryInfo();
    ~safe_VkBindImageMemoryInfo();
    void initialize(const VkBindImageMemoryInfo* in_struct);
    void initialize(const safe_VkBindImageMemoryInfo* copy_src);
    VkBindImageMemoryInfo *ptr() { return reinterpret_cast<VkBindImageMemoryInfo *>(this); }
    VkBindImageMemoryInfo const *ptr() const { return reinterpret_cast<VkBindImageMemoryInfo const *>(this); }
};

struct safe_VkPhysicalDevice16BitStorageFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 storageBuffer16BitAccess;
    VkBool32 uniformAndStorageBuffer16BitAccess;
    VkBool32 storagePushConstant16;
    VkBool32 storageInputOutput16;
    safe_VkPhysicalDevice16BitStorageFeatures(const VkPhysicalDevice16BitStorageFeatures* in_struct);
    safe_VkPhysicalDevice16BitStorageFeatures(const safe_VkPhysicalDevice16BitStorageFeatures& copy_src);
    safe_VkPhysicalDevice16BitStorageFeatures& operator=(const safe_VkPhysicalDevice16BitStorageFeatures& copy_src);
    safe_VkPhysicalDevice16BitStorageFeatures();
    ~safe_VkPhysicalDevice16BitStorageFeatures();
    void initialize(const VkPhysicalDevice16BitStorageFeatures* in_struct);
    void initialize(const safe_VkPhysicalDevice16BitStorageFeatures* copy_src);
    VkPhysicalDevice16BitStorageFeatures *ptr() { return reinterpret_cast<VkPhysicalDevice16BitStorageFeatures *>(this); }
    VkPhysicalDevice16BitStorageFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDevice16BitStorageFeatures const *>(this); }
};

struct safe_VkMemoryDedicatedRequirements {
    VkStructureType sType;
    void* pNext;
    VkBool32 prefersDedicatedAllocation;
    VkBool32 requiresDedicatedAllocation;
    safe_VkMemoryDedicatedRequirements(const VkMemoryDedicatedRequirements* in_struct);
    safe_VkMemoryDedicatedRequirements(const safe_VkMemoryDedicatedRequirements& copy_src);
    safe_VkMemoryDedicatedRequirements& operator=(const safe_VkMemoryDedicatedRequirements& copy_src);
    safe_VkMemoryDedicatedRequirements();
    ~safe_VkMemoryDedicatedRequirements();
    void initialize(const VkMemoryDedicatedRequirements* in_struct);
    void initialize(const safe_VkMemoryDedicatedRequirements* copy_src);
    VkMemoryDedicatedRequirements *ptr() { return reinterpret_cast<VkMemoryDedicatedRequirements *>(this); }
    VkMemoryDedicatedRequirements const *ptr() const { return reinterpret_cast<VkMemoryDedicatedRequirements const *>(this); }
};

struct safe_VkMemoryDedicatedAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    VkBuffer buffer;
    safe_VkMemoryDedicatedAllocateInfo(const VkMemoryDedicatedAllocateInfo* in_struct);
    safe_VkMemoryDedicatedAllocateInfo(const safe_VkMemoryDedicatedAllocateInfo& copy_src);
    safe_VkMemoryDedicatedAllocateInfo& operator=(const safe_VkMemoryDedicatedAllocateInfo& copy_src);
    safe_VkMemoryDedicatedAllocateInfo();
    ~safe_VkMemoryDedicatedAllocateInfo();
    void initialize(const VkMemoryDedicatedAllocateInfo* in_struct);
    void initialize(const safe_VkMemoryDedicatedAllocateInfo* copy_src);
    VkMemoryDedicatedAllocateInfo *ptr() { return reinterpret_cast<VkMemoryDedicatedAllocateInfo *>(this); }
    VkMemoryDedicatedAllocateInfo const *ptr() const { return reinterpret_cast<VkMemoryDedicatedAllocateInfo const *>(this); }
};

struct safe_VkMemoryAllocateFlagsInfo {
    VkStructureType sType;
    const void* pNext;
    VkMemoryAllocateFlags flags;
    uint32_t deviceMask;
    safe_VkMemoryAllocateFlagsInfo(const VkMemoryAllocateFlagsInfo* in_struct);
    safe_VkMemoryAllocateFlagsInfo(const safe_VkMemoryAllocateFlagsInfo& copy_src);
    safe_VkMemoryAllocateFlagsInfo& operator=(const safe_VkMemoryAllocateFlagsInfo& copy_src);
    safe_VkMemoryAllocateFlagsInfo();
    ~safe_VkMemoryAllocateFlagsInfo();
    void initialize(const VkMemoryAllocateFlagsInfo* in_struct);
    void initialize(const safe_VkMemoryAllocateFlagsInfo* copy_src);
    VkMemoryAllocateFlagsInfo *ptr() { return reinterpret_cast<VkMemoryAllocateFlagsInfo *>(this); }
    VkMemoryAllocateFlagsInfo const *ptr() const { return reinterpret_cast<VkMemoryAllocateFlagsInfo const *>(this); }
};

struct safe_VkDeviceGroupRenderPassBeginInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t deviceMask;
    uint32_t deviceRenderAreaCount;
    const VkRect2D* pDeviceRenderAreas;
    safe_VkDeviceGroupRenderPassBeginInfo(const VkDeviceGroupRenderPassBeginInfo* in_struct);
    safe_VkDeviceGroupRenderPassBeginInfo(const safe_VkDeviceGroupRenderPassBeginInfo& copy_src);
    safe_VkDeviceGroupRenderPassBeginInfo& operator=(const safe_VkDeviceGroupRenderPassBeginInfo& copy_src);
    safe_VkDeviceGroupRenderPassBeginInfo();
    ~safe_VkDeviceGroupRenderPassBeginInfo();
    void initialize(const VkDeviceGroupRenderPassBeginInfo* in_struct);
    void initialize(const safe_VkDeviceGroupRenderPassBeginInfo* copy_src);
    VkDeviceGroupRenderPassBeginInfo *ptr() { return reinterpret_cast<VkDeviceGroupRenderPassBeginInfo *>(this); }
    VkDeviceGroupRenderPassBeginInfo const *ptr() const { return reinterpret_cast<VkDeviceGroupRenderPassBeginInfo const *>(this); }
};

struct safe_VkDeviceGroupCommandBufferBeginInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t deviceMask;
    safe_VkDeviceGroupCommandBufferBeginInfo(const VkDeviceGroupCommandBufferBeginInfo* in_struct);
    safe_VkDeviceGroupCommandBufferBeginInfo(const safe_VkDeviceGroupCommandBufferBeginInfo& copy_src);
    safe_VkDeviceGroupCommandBufferBeginInfo& operator=(const safe_VkDeviceGroupCommandBufferBeginInfo& copy_src);
    safe_VkDeviceGroupCommandBufferBeginInfo();
    ~safe_VkDeviceGroupCommandBufferBeginInfo();
    void initialize(const VkDeviceGroupCommandBufferBeginInfo* in_struct);
    void initialize(const safe_VkDeviceGroupCommandBufferBeginInfo* copy_src);
    VkDeviceGroupCommandBufferBeginInfo *ptr() { return reinterpret_cast<VkDeviceGroupCommandBufferBeginInfo *>(this); }
    VkDeviceGroupCommandBufferBeginInfo const *ptr() const { return reinterpret_cast<VkDeviceGroupCommandBufferBeginInfo const *>(this); }
};

struct safe_VkDeviceGroupSubmitInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t waitSemaphoreCount;
    const uint32_t* pWaitSemaphoreDeviceIndices;
    uint32_t commandBufferCount;
    const uint32_t* pCommandBufferDeviceMasks;
    uint32_t signalSemaphoreCount;
    const uint32_t* pSignalSemaphoreDeviceIndices;
    safe_VkDeviceGroupSubmitInfo(const VkDeviceGroupSubmitInfo* in_struct);
    safe_VkDeviceGroupSubmitInfo(const safe_VkDeviceGroupSubmitInfo& copy_src);
    safe_VkDeviceGroupSubmitInfo& operator=(const safe_VkDeviceGroupSubmitInfo& copy_src);
    safe_VkDeviceGroupSubmitInfo();
    ~safe_VkDeviceGroupSubmitInfo();
    void initialize(const VkDeviceGroupSubmitInfo* in_struct);
    void initialize(const safe_VkDeviceGroupSubmitInfo* copy_src);
    VkDeviceGroupSubmitInfo *ptr() { return reinterpret_cast<VkDeviceGroupSubmitInfo *>(this); }
    VkDeviceGroupSubmitInfo const *ptr() const { return reinterpret_cast<VkDeviceGroupSubmitInfo const *>(this); }
};

struct safe_VkDeviceGroupBindSparseInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t resourceDeviceIndex;
    uint32_t memoryDeviceIndex;
    safe_VkDeviceGroupBindSparseInfo(const VkDeviceGroupBindSparseInfo* in_struct);
    safe_VkDeviceGroupBindSparseInfo(const safe_VkDeviceGroupBindSparseInfo& copy_src);
    safe_VkDeviceGroupBindSparseInfo& operator=(const safe_VkDeviceGroupBindSparseInfo& copy_src);
    safe_VkDeviceGroupBindSparseInfo();
    ~safe_VkDeviceGroupBindSparseInfo();
    void initialize(const VkDeviceGroupBindSparseInfo* in_struct);
    void initialize(const safe_VkDeviceGroupBindSparseInfo* copy_src);
    VkDeviceGroupBindSparseInfo *ptr() { return reinterpret_cast<VkDeviceGroupBindSparseInfo *>(this); }
    VkDeviceGroupBindSparseInfo const *ptr() const { return reinterpret_cast<VkDeviceGroupBindSparseInfo const *>(this); }
};

struct safe_VkBindBufferMemoryDeviceGroupInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t deviceIndexCount;
    const uint32_t* pDeviceIndices;
    safe_VkBindBufferMemoryDeviceGroupInfo(const VkBindBufferMemoryDeviceGroupInfo* in_struct);
    safe_VkBindBufferMemoryDeviceGroupInfo(const safe_VkBindBufferMemoryDeviceGroupInfo& copy_src);
    safe_VkBindBufferMemoryDeviceGroupInfo& operator=(const safe_VkBindBufferMemoryDeviceGroupInfo& copy_src);
    safe_VkBindBufferMemoryDeviceGroupInfo();
    ~safe_VkBindBufferMemoryDeviceGroupInfo();
    void initialize(const VkBindBufferMemoryDeviceGroupInfo* in_struct);
    void initialize(const safe_VkBindBufferMemoryDeviceGroupInfo* copy_src);
    VkBindBufferMemoryDeviceGroupInfo *ptr() { return reinterpret_cast<VkBindBufferMemoryDeviceGroupInfo *>(this); }
    VkBindBufferMemoryDeviceGroupInfo const *ptr() const { return reinterpret_cast<VkBindBufferMemoryDeviceGroupInfo const *>(this); }
};

struct safe_VkBindImageMemoryDeviceGroupInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t deviceIndexCount;
    const uint32_t* pDeviceIndices;
    uint32_t splitInstanceBindRegionCount;
    const VkRect2D* pSplitInstanceBindRegions;
    safe_VkBindImageMemoryDeviceGroupInfo(const VkBindImageMemoryDeviceGroupInfo* in_struct);
    safe_VkBindImageMemoryDeviceGroupInfo(const safe_VkBindImageMemoryDeviceGroupInfo& copy_src);
    safe_VkBindImageMemoryDeviceGroupInfo& operator=(const safe_VkBindImageMemoryDeviceGroupInfo& copy_src);
    safe_VkBindImageMemoryDeviceGroupInfo();
    ~safe_VkBindImageMemoryDeviceGroupInfo();
    void initialize(const VkBindImageMemoryDeviceGroupInfo* in_struct);
    void initialize(const safe_VkBindImageMemoryDeviceGroupInfo* copy_src);
    VkBindImageMemoryDeviceGroupInfo *ptr() { return reinterpret_cast<VkBindImageMemoryDeviceGroupInfo *>(this); }
    VkBindImageMemoryDeviceGroupInfo const *ptr() const { return reinterpret_cast<VkBindImageMemoryDeviceGroupInfo const *>(this); }
};

struct safe_VkPhysicalDeviceGroupProperties {
    VkStructureType sType;
    void* pNext;
    uint32_t physicalDeviceCount;
    VkPhysicalDevice physicalDevices[VK_MAX_DEVICE_GROUP_SIZE];
    VkBool32 subsetAllocation;
    safe_VkPhysicalDeviceGroupProperties(const VkPhysicalDeviceGroupProperties* in_struct);
    safe_VkPhysicalDeviceGroupProperties(const safe_VkPhysicalDeviceGroupProperties& copy_src);
    safe_VkPhysicalDeviceGroupProperties& operator=(const safe_VkPhysicalDeviceGroupProperties& copy_src);
    safe_VkPhysicalDeviceGroupProperties();
    ~safe_VkPhysicalDeviceGroupProperties();
    void initialize(const VkPhysicalDeviceGroupProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceGroupProperties* copy_src);
    VkPhysicalDeviceGroupProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceGroupProperties *>(this); }
    VkPhysicalDeviceGroupProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceGroupProperties const *>(this); }
};

struct safe_VkDeviceGroupDeviceCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t physicalDeviceCount;
    VkPhysicalDevice* pPhysicalDevices;
    safe_VkDeviceGroupDeviceCreateInfo(const VkDeviceGroupDeviceCreateInfo* in_struct);
    safe_VkDeviceGroupDeviceCreateInfo(const safe_VkDeviceGroupDeviceCreateInfo& copy_src);
    safe_VkDeviceGroupDeviceCreateInfo& operator=(const safe_VkDeviceGroupDeviceCreateInfo& copy_src);
    safe_VkDeviceGroupDeviceCreateInfo();
    ~safe_VkDeviceGroupDeviceCreateInfo();
    void initialize(const VkDeviceGroupDeviceCreateInfo* in_struct);
    void initialize(const safe_VkDeviceGroupDeviceCreateInfo* copy_src);
    VkDeviceGroupDeviceCreateInfo *ptr() { return reinterpret_cast<VkDeviceGroupDeviceCreateInfo *>(this); }
    VkDeviceGroupDeviceCreateInfo const *ptr() const { return reinterpret_cast<VkDeviceGroupDeviceCreateInfo const *>(this); }
};

struct safe_VkBufferMemoryRequirementsInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkBuffer buffer;
    safe_VkBufferMemoryRequirementsInfo2(const VkBufferMemoryRequirementsInfo2* in_struct);
    safe_VkBufferMemoryRequirementsInfo2(const safe_VkBufferMemoryRequirementsInfo2& copy_src);
    safe_VkBufferMemoryRequirementsInfo2& operator=(const safe_VkBufferMemoryRequirementsInfo2& copy_src);
    safe_VkBufferMemoryRequirementsInfo2();
    ~safe_VkBufferMemoryRequirementsInfo2();
    void initialize(const VkBufferMemoryRequirementsInfo2* in_struct);
    void initialize(const safe_VkBufferMemoryRequirementsInfo2* copy_src);
    VkBufferMemoryRequirementsInfo2 *ptr() { return reinterpret_cast<VkBufferMemoryRequirementsInfo2 *>(this); }
    VkBufferMemoryRequirementsInfo2 const *ptr() const { return reinterpret_cast<VkBufferMemoryRequirementsInfo2 const *>(this); }
};

struct safe_VkImageMemoryRequirementsInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    safe_VkImageMemoryRequirementsInfo2(const VkImageMemoryRequirementsInfo2* in_struct);
    safe_VkImageMemoryRequirementsInfo2(const safe_VkImageMemoryRequirementsInfo2& copy_src);
    safe_VkImageMemoryRequirementsInfo2& operator=(const safe_VkImageMemoryRequirementsInfo2& copy_src);
    safe_VkImageMemoryRequirementsInfo2();
    ~safe_VkImageMemoryRequirementsInfo2();
    void initialize(const VkImageMemoryRequirementsInfo2* in_struct);
    void initialize(const safe_VkImageMemoryRequirementsInfo2* copy_src);
    VkImageMemoryRequirementsInfo2 *ptr() { return reinterpret_cast<VkImageMemoryRequirementsInfo2 *>(this); }
    VkImageMemoryRequirementsInfo2 const *ptr() const { return reinterpret_cast<VkImageMemoryRequirementsInfo2 const *>(this); }
};

struct safe_VkImageSparseMemoryRequirementsInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    safe_VkImageSparseMemoryRequirementsInfo2(const VkImageSparseMemoryRequirementsInfo2* in_struct);
    safe_VkImageSparseMemoryRequirementsInfo2(const safe_VkImageSparseMemoryRequirementsInfo2& copy_src);
    safe_VkImageSparseMemoryRequirementsInfo2& operator=(const safe_VkImageSparseMemoryRequirementsInfo2& copy_src);
    safe_VkImageSparseMemoryRequirementsInfo2();
    ~safe_VkImageSparseMemoryRequirementsInfo2();
    void initialize(const VkImageSparseMemoryRequirementsInfo2* in_struct);
    void initialize(const safe_VkImageSparseMemoryRequirementsInfo2* copy_src);
    VkImageSparseMemoryRequirementsInfo2 *ptr() { return reinterpret_cast<VkImageSparseMemoryRequirementsInfo2 *>(this); }
    VkImageSparseMemoryRequirementsInfo2 const *ptr() const { return reinterpret_cast<VkImageSparseMemoryRequirementsInfo2 const *>(this); }
};

struct safe_VkMemoryRequirements2 {
    VkStructureType sType;
    void* pNext;
    VkMemoryRequirements memoryRequirements;
    safe_VkMemoryRequirements2(const VkMemoryRequirements2* in_struct);
    safe_VkMemoryRequirements2(const safe_VkMemoryRequirements2& copy_src);
    safe_VkMemoryRequirements2& operator=(const safe_VkMemoryRequirements2& copy_src);
    safe_VkMemoryRequirements2();
    ~safe_VkMemoryRequirements2();
    void initialize(const VkMemoryRequirements2* in_struct);
    void initialize(const safe_VkMemoryRequirements2* copy_src);
    VkMemoryRequirements2 *ptr() { return reinterpret_cast<VkMemoryRequirements2 *>(this); }
    VkMemoryRequirements2 const *ptr() const { return reinterpret_cast<VkMemoryRequirements2 const *>(this); }
};

struct safe_VkSparseImageMemoryRequirements2 {
    VkStructureType sType;
    void* pNext;
    VkSparseImageMemoryRequirements memoryRequirements;
    safe_VkSparseImageMemoryRequirements2(const VkSparseImageMemoryRequirements2* in_struct);
    safe_VkSparseImageMemoryRequirements2(const safe_VkSparseImageMemoryRequirements2& copy_src);
    safe_VkSparseImageMemoryRequirements2& operator=(const safe_VkSparseImageMemoryRequirements2& copy_src);
    safe_VkSparseImageMemoryRequirements2();
    ~safe_VkSparseImageMemoryRequirements2();
    void initialize(const VkSparseImageMemoryRequirements2* in_struct);
    void initialize(const safe_VkSparseImageMemoryRequirements2* copy_src);
    VkSparseImageMemoryRequirements2 *ptr() { return reinterpret_cast<VkSparseImageMemoryRequirements2 *>(this); }
    VkSparseImageMemoryRequirements2 const *ptr() const { return reinterpret_cast<VkSparseImageMemoryRequirements2 const *>(this); }
};

struct safe_VkPhysicalDeviceFeatures2 {
    VkStructureType sType;
    void* pNext;
    VkPhysicalDeviceFeatures features;
    safe_VkPhysicalDeviceFeatures2(const VkPhysicalDeviceFeatures2* in_struct);
    safe_VkPhysicalDeviceFeatures2(const safe_VkPhysicalDeviceFeatures2& copy_src);
    safe_VkPhysicalDeviceFeatures2& operator=(const safe_VkPhysicalDeviceFeatures2& copy_src);
    safe_VkPhysicalDeviceFeatures2();
    ~safe_VkPhysicalDeviceFeatures2();
    void initialize(const VkPhysicalDeviceFeatures2* in_struct);
    void initialize(const safe_VkPhysicalDeviceFeatures2* copy_src);
    VkPhysicalDeviceFeatures2 *ptr() { return reinterpret_cast<VkPhysicalDeviceFeatures2 *>(this); }
    VkPhysicalDeviceFeatures2 const *ptr() const { return reinterpret_cast<VkPhysicalDeviceFeatures2 const *>(this); }
};

struct safe_VkPhysicalDeviceProperties2 {
    VkStructureType sType;
    void* pNext;
    VkPhysicalDeviceProperties properties;
    safe_VkPhysicalDeviceProperties2(const VkPhysicalDeviceProperties2* in_struct);
    safe_VkPhysicalDeviceProperties2(const safe_VkPhysicalDeviceProperties2& copy_src);
    safe_VkPhysicalDeviceProperties2& operator=(const safe_VkPhysicalDeviceProperties2& copy_src);
    safe_VkPhysicalDeviceProperties2();
    ~safe_VkPhysicalDeviceProperties2();
    void initialize(const VkPhysicalDeviceProperties2* in_struct);
    void initialize(const safe_VkPhysicalDeviceProperties2* copy_src);
    VkPhysicalDeviceProperties2 *ptr() { return reinterpret_cast<VkPhysicalDeviceProperties2 *>(this); }
    VkPhysicalDeviceProperties2 const *ptr() const { return reinterpret_cast<VkPhysicalDeviceProperties2 const *>(this); }
};

struct safe_VkFormatProperties2 {
    VkStructureType sType;
    void* pNext;
    VkFormatProperties formatProperties;
    safe_VkFormatProperties2(const VkFormatProperties2* in_struct);
    safe_VkFormatProperties2(const safe_VkFormatProperties2& copy_src);
    safe_VkFormatProperties2& operator=(const safe_VkFormatProperties2& copy_src);
    safe_VkFormatProperties2();
    ~safe_VkFormatProperties2();
    void initialize(const VkFormatProperties2* in_struct);
    void initialize(const safe_VkFormatProperties2* copy_src);
    VkFormatProperties2 *ptr() { return reinterpret_cast<VkFormatProperties2 *>(this); }
    VkFormatProperties2 const *ptr() const { return reinterpret_cast<VkFormatProperties2 const *>(this); }
};

struct safe_VkImageFormatProperties2 {
    VkStructureType sType;
    void* pNext;
    VkImageFormatProperties imageFormatProperties;
    safe_VkImageFormatProperties2(const VkImageFormatProperties2* in_struct);
    safe_VkImageFormatProperties2(const safe_VkImageFormatProperties2& copy_src);
    safe_VkImageFormatProperties2& operator=(const safe_VkImageFormatProperties2& copy_src);
    safe_VkImageFormatProperties2();
    ~safe_VkImageFormatProperties2();
    void initialize(const VkImageFormatProperties2* in_struct);
    void initialize(const safe_VkImageFormatProperties2* copy_src);
    VkImageFormatProperties2 *ptr() { return reinterpret_cast<VkImageFormatProperties2 *>(this); }
    VkImageFormatProperties2 const *ptr() const { return reinterpret_cast<VkImageFormatProperties2 const *>(this); }
};

struct safe_VkPhysicalDeviceImageFormatInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    safe_VkPhysicalDeviceImageFormatInfo2(const VkPhysicalDeviceImageFormatInfo2* in_struct);
    safe_VkPhysicalDeviceImageFormatInfo2(const safe_VkPhysicalDeviceImageFormatInfo2& copy_src);
    safe_VkPhysicalDeviceImageFormatInfo2& operator=(const safe_VkPhysicalDeviceImageFormatInfo2& copy_src);
    safe_VkPhysicalDeviceImageFormatInfo2();
    ~safe_VkPhysicalDeviceImageFormatInfo2();
    void initialize(const VkPhysicalDeviceImageFormatInfo2* in_struct);
    void initialize(const safe_VkPhysicalDeviceImageFormatInfo2* copy_src);
    VkPhysicalDeviceImageFormatInfo2 *ptr() { return reinterpret_cast<VkPhysicalDeviceImageFormatInfo2 *>(this); }
    VkPhysicalDeviceImageFormatInfo2 const *ptr() const { return reinterpret_cast<VkPhysicalDeviceImageFormatInfo2 const *>(this); }
};

struct safe_VkQueueFamilyProperties2 {
    VkStructureType sType;
    void* pNext;
    VkQueueFamilyProperties queueFamilyProperties;
    safe_VkQueueFamilyProperties2(const VkQueueFamilyProperties2* in_struct);
    safe_VkQueueFamilyProperties2(const safe_VkQueueFamilyProperties2& copy_src);
    safe_VkQueueFamilyProperties2& operator=(const safe_VkQueueFamilyProperties2& copy_src);
    safe_VkQueueFamilyProperties2();
    ~safe_VkQueueFamilyProperties2();
    void initialize(const VkQueueFamilyProperties2* in_struct);
    void initialize(const safe_VkQueueFamilyProperties2* copy_src);
    VkQueueFamilyProperties2 *ptr() { return reinterpret_cast<VkQueueFamilyProperties2 *>(this); }
    VkQueueFamilyProperties2 const *ptr() const { return reinterpret_cast<VkQueueFamilyProperties2 const *>(this); }
};

struct safe_VkPhysicalDeviceMemoryProperties2 {
    VkStructureType sType;
    void* pNext;
    VkPhysicalDeviceMemoryProperties memoryProperties;
    safe_VkPhysicalDeviceMemoryProperties2(const VkPhysicalDeviceMemoryProperties2* in_struct);
    safe_VkPhysicalDeviceMemoryProperties2(const safe_VkPhysicalDeviceMemoryProperties2& copy_src);
    safe_VkPhysicalDeviceMemoryProperties2& operator=(const safe_VkPhysicalDeviceMemoryProperties2& copy_src);
    safe_VkPhysicalDeviceMemoryProperties2();
    ~safe_VkPhysicalDeviceMemoryProperties2();
    void initialize(const VkPhysicalDeviceMemoryProperties2* in_struct);
    void initialize(const safe_VkPhysicalDeviceMemoryProperties2* copy_src);
    VkPhysicalDeviceMemoryProperties2 *ptr() { return reinterpret_cast<VkPhysicalDeviceMemoryProperties2 *>(this); }
    VkPhysicalDeviceMemoryProperties2 const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMemoryProperties2 const *>(this); }
};

struct safe_VkSparseImageFormatProperties2 {
    VkStructureType sType;
    void* pNext;
    VkSparseImageFormatProperties properties;
    safe_VkSparseImageFormatProperties2(const VkSparseImageFormatProperties2* in_struct);
    safe_VkSparseImageFormatProperties2(const safe_VkSparseImageFormatProperties2& copy_src);
    safe_VkSparseImageFormatProperties2& operator=(const safe_VkSparseImageFormatProperties2& copy_src);
    safe_VkSparseImageFormatProperties2();
    ~safe_VkSparseImageFormatProperties2();
    void initialize(const VkSparseImageFormatProperties2* in_struct);
    void initialize(const safe_VkSparseImageFormatProperties2* copy_src);
    VkSparseImageFormatProperties2 *ptr() { return reinterpret_cast<VkSparseImageFormatProperties2 *>(this); }
    VkSparseImageFormatProperties2 const *ptr() const { return reinterpret_cast<VkSparseImageFormatProperties2 const *>(this); }
};

struct safe_VkPhysicalDeviceSparseImageFormatInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    safe_VkPhysicalDeviceSparseImageFormatInfo2(const VkPhysicalDeviceSparseImageFormatInfo2* in_struct);
    safe_VkPhysicalDeviceSparseImageFormatInfo2(const safe_VkPhysicalDeviceSparseImageFormatInfo2& copy_src);
    safe_VkPhysicalDeviceSparseImageFormatInfo2& operator=(const safe_VkPhysicalDeviceSparseImageFormatInfo2& copy_src);
    safe_VkPhysicalDeviceSparseImageFormatInfo2();
    ~safe_VkPhysicalDeviceSparseImageFormatInfo2();
    void initialize(const VkPhysicalDeviceSparseImageFormatInfo2* in_struct);
    void initialize(const safe_VkPhysicalDeviceSparseImageFormatInfo2* copy_src);
    VkPhysicalDeviceSparseImageFormatInfo2 *ptr() { return reinterpret_cast<VkPhysicalDeviceSparseImageFormatInfo2 *>(this); }
    VkPhysicalDeviceSparseImageFormatInfo2 const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSparseImageFormatInfo2 const *>(this); }
};

struct safe_VkPhysicalDevicePointClippingProperties {
    VkStructureType sType;
    void* pNext;
    VkPointClippingBehavior pointClippingBehavior;
    safe_VkPhysicalDevicePointClippingProperties(const VkPhysicalDevicePointClippingProperties* in_struct);
    safe_VkPhysicalDevicePointClippingProperties(const safe_VkPhysicalDevicePointClippingProperties& copy_src);
    safe_VkPhysicalDevicePointClippingProperties& operator=(const safe_VkPhysicalDevicePointClippingProperties& copy_src);
    safe_VkPhysicalDevicePointClippingProperties();
    ~safe_VkPhysicalDevicePointClippingProperties();
    void initialize(const VkPhysicalDevicePointClippingProperties* in_struct);
    void initialize(const safe_VkPhysicalDevicePointClippingProperties* copy_src);
    VkPhysicalDevicePointClippingProperties *ptr() { return reinterpret_cast<VkPhysicalDevicePointClippingProperties *>(this); }
    VkPhysicalDevicePointClippingProperties const *ptr() const { return reinterpret_cast<VkPhysicalDevicePointClippingProperties const *>(this); }
};

struct safe_VkRenderPassInputAttachmentAspectCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t aspectReferenceCount;
    const VkInputAttachmentAspectReference* pAspectReferences;
    safe_VkRenderPassInputAttachmentAspectCreateInfo(const VkRenderPassInputAttachmentAspectCreateInfo* in_struct);
    safe_VkRenderPassInputAttachmentAspectCreateInfo(const safe_VkRenderPassInputAttachmentAspectCreateInfo& copy_src);
    safe_VkRenderPassInputAttachmentAspectCreateInfo& operator=(const safe_VkRenderPassInputAttachmentAspectCreateInfo& copy_src);
    safe_VkRenderPassInputAttachmentAspectCreateInfo();
    ~safe_VkRenderPassInputAttachmentAspectCreateInfo();
    void initialize(const VkRenderPassInputAttachmentAspectCreateInfo* in_struct);
    void initialize(const safe_VkRenderPassInputAttachmentAspectCreateInfo* copy_src);
    VkRenderPassInputAttachmentAspectCreateInfo *ptr() { return reinterpret_cast<VkRenderPassInputAttachmentAspectCreateInfo *>(this); }
    VkRenderPassInputAttachmentAspectCreateInfo const *ptr() const { return reinterpret_cast<VkRenderPassInputAttachmentAspectCreateInfo const *>(this); }
};

struct safe_VkImageViewUsageCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageUsageFlags usage;
    safe_VkImageViewUsageCreateInfo(const VkImageViewUsageCreateInfo* in_struct);
    safe_VkImageViewUsageCreateInfo(const safe_VkImageViewUsageCreateInfo& copy_src);
    safe_VkImageViewUsageCreateInfo& operator=(const safe_VkImageViewUsageCreateInfo& copy_src);
    safe_VkImageViewUsageCreateInfo();
    ~safe_VkImageViewUsageCreateInfo();
    void initialize(const VkImageViewUsageCreateInfo* in_struct);
    void initialize(const safe_VkImageViewUsageCreateInfo* copy_src);
    VkImageViewUsageCreateInfo *ptr() { return reinterpret_cast<VkImageViewUsageCreateInfo *>(this); }
    VkImageViewUsageCreateInfo const *ptr() const { return reinterpret_cast<VkImageViewUsageCreateInfo const *>(this); }
};

struct safe_VkPipelineTessellationDomainOriginStateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkTessellationDomainOrigin domainOrigin;
    safe_VkPipelineTessellationDomainOriginStateCreateInfo(const VkPipelineTessellationDomainOriginStateCreateInfo* in_struct);
    safe_VkPipelineTessellationDomainOriginStateCreateInfo(const safe_VkPipelineTessellationDomainOriginStateCreateInfo& copy_src);
    safe_VkPipelineTessellationDomainOriginStateCreateInfo& operator=(const safe_VkPipelineTessellationDomainOriginStateCreateInfo& copy_src);
    safe_VkPipelineTessellationDomainOriginStateCreateInfo();
    ~safe_VkPipelineTessellationDomainOriginStateCreateInfo();
    void initialize(const VkPipelineTessellationDomainOriginStateCreateInfo* in_struct);
    void initialize(const safe_VkPipelineTessellationDomainOriginStateCreateInfo* copy_src);
    VkPipelineTessellationDomainOriginStateCreateInfo *ptr() { return reinterpret_cast<VkPipelineTessellationDomainOriginStateCreateInfo *>(this); }
    VkPipelineTessellationDomainOriginStateCreateInfo const *ptr() const { return reinterpret_cast<VkPipelineTessellationDomainOriginStateCreateInfo const *>(this); }
};

struct safe_VkRenderPassMultiviewCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t subpassCount;
    const uint32_t* pViewMasks;
    uint32_t dependencyCount;
    const int32_t* pViewOffsets;
    uint32_t correlationMaskCount;
    const uint32_t* pCorrelationMasks;
    safe_VkRenderPassMultiviewCreateInfo(const VkRenderPassMultiviewCreateInfo* in_struct);
    safe_VkRenderPassMultiviewCreateInfo(const safe_VkRenderPassMultiviewCreateInfo& copy_src);
    safe_VkRenderPassMultiviewCreateInfo& operator=(const safe_VkRenderPassMultiviewCreateInfo& copy_src);
    safe_VkRenderPassMultiviewCreateInfo();
    ~safe_VkRenderPassMultiviewCreateInfo();
    void initialize(const VkRenderPassMultiviewCreateInfo* in_struct);
    void initialize(const safe_VkRenderPassMultiviewCreateInfo* copy_src);
    VkRenderPassMultiviewCreateInfo *ptr() { return reinterpret_cast<VkRenderPassMultiviewCreateInfo *>(this); }
    VkRenderPassMultiviewCreateInfo const *ptr() const { return reinterpret_cast<VkRenderPassMultiviewCreateInfo const *>(this); }
};

struct safe_VkPhysicalDeviceMultiviewFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 multiview;
    VkBool32 multiviewGeometryShader;
    VkBool32 multiviewTessellationShader;
    safe_VkPhysicalDeviceMultiviewFeatures(const VkPhysicalDeviceMultiviewFeatures* in_struct);
    safe_VkPhysicalDeviceMultiviewFeatures(const safe_VkPhysicalDeviceMultiviewFeatures& copy_src);
    safe_VkPhysicalDeviceMultiviewFeatures& operator=(const safe_VkPhysicalDeviceMultiviewFeatures& copy_src);
    safe_VkPhysicalDeviceMultiviewFeatures();
    ~safe_VkPhysicalDeviceMultiviewFeatures();
    void initialize(const VkPhysicalDeviceMultiviewFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceMultiviewFeatures* copy_src);
    VkPhysicalDeviceMultiviewFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceMultiviewFeatures *>(this); }
    VkPhysicalDeviceMultiviewFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMultiviewFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceMultiviewProperties {
    VkStructureType sType;
    void* pNext;
    uint32_t maxMultiviewViewCount;
    uint32_t maxMultiviewInstanceIndex;
    safe_VkPhysicalDeviceMultiviewProperties(const VkPhysicalDeviceMultiviewProperties* in_struct);
    safe_VkPhysicalDeviceMultiviewProperties(const safe_VkPhysicalDeviceMultiviewProperties& copy_src);
    safe_VkPhysicalDeviceMultiviewProperties& operator=(const safe_VkPhysicalDeviceMultiviewProperties& copy_src);
    safe_VkPhysicalDeviceMultiviewProperties();
    ~safe_VkPhysicalDeviceMultiviewProperties();
    void initialize(const VkPhysicalDeviceMultiviewProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceMultiviewProperties* copy_src);
    VkPhysicalDeviceMultiviewProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceMultiviewProperties *>(this); }
    VkPhysicalDeviceMultiviewProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMultiviewProperties const *>(this); }
};

struct safe_VkPhysicalDeviceVariablePointersFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 variablePointersStorageBuffer;
    VkBool32 variablePointers;
    safe_VkPhysicalDeviceVariablePointersFeatures(const VkPhysicalDeviceVariablePointersFeatures* in_struct);
    safe_VkPhysicalDeviceVariablePointersFeatures(const safe_VkPhysicalDeviceVariablePointersFeatures& copy_src);
    safe_VkPhysicalDeviceVariablePointersFeatures& operator=(const safe_VkPhysicalDeviceVariablePointersFeatures& copy_src);
    safe_VkPhysicalDeviceVariablePointersFeatures();
    ~safe_VkPhysicalDeviceVariablePointersFeatures();
    void initialize(const VkPhysicalDeviceVariablePointersFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceVariablePointersFeatures* copy_src);
    VkPhysicalDeviceVariablePointersFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceVariablePointersFeatures *>(this); }
    VkPhysicalDeviceVariablePointersFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVariablePointersFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceProtectedMemoryFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 protectedMemory;
    safe_VkPhysicalDeviceProtectedMemoryFeatures(const VkPhysicalDeviceProtectedMemoryFeatures* in_struct);
    safe_VkPhysicalDeviceProtectedMemoryFeatures(const safe_VkPhysicalDeviceProtectedMemoryFeatures& copy_src);
    safe_VkPhysicalDeviceProtectedMemoryFeatures& operator=(const safe_VkPhysicalDeviceProtectedMemoryFeatures& copy_src);
    safe_VkPhysicalDeviceProtectedMemoryFeatures();
    ~safe_VkPhysicalDeviceProtectedMemoryFeatures();
    void initialize(const VkPhysicalDeviceProtectedMemoryFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceProtectedMemoryFeatures* copy_src);
    VkPhysicalDeviceProtectedMemoryFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceProtectedMemoryFeatures *>(this); }
    VkPhysicalDeviceProtectedMemoryFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceProtectedMemoryFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceProtectedMemoryProperties {
    VkStructureType sType;
    void* pNext;
    VkBool32 protectedNoFault;
    safe_VkPhysicalDeviceProtectedMemoryProperties(const VkPhysicalDeviceProtectedMemoryProperties* in_struct);
    safe_VkPhysicalDeviceProtectedMemoryProperties(const safe_VkPhysicalDeviceProtectedMemoryProperties& copy_src);
    safe_VkPhysicalDeviceProtectedMemoryProperties& operator=(const safe_VkPhysicalDeviceProtectedMemoryProperties& copy_src);
    safe_VkPhysicalDeviceProtectedMemoryProperties();
    ~safe_VkPhysicalDeviceProtectedMemoryProperties();
    void initialize(const VkPhysicalDeviceProtectedMemoryProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceProtectedMemoryProperties* copy_src);
    VkPhysicalDeviceProtectedMemoryProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceProtectedMemoryProperties *>(this); }
    VkPhysicalDeviceProtectedMemoryProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceProtectedMemoryProperties const *>(this); }
};

struct safe_VkDeviceQueueInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkDeviceQueueCreateFlags flags;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    safe_VkDeviceQueueInfo2(const VkDeviceQueueInfo2* in_struct);
    safe_VkDeviceQueueInfo2(const safe_VkDeviceQueueInfo2& copy_src);
    safe_VkDeviceQueueInfo2& operator=(const safe_VkDeviceQueueInfo2& copy_src);
    safe_VkDeviceQueueInfo2();
    ~safe_VkDeviceQueueInfo2();
    void initialize(const VkDeviceQueueInfo2* in_struct);
    void initialize(const safe_VkDeviceQueueInfo2* copy_src);
    VkDeviceQueueInfo2 *ptr() { return reinterpret_cast<VkDeviceQueueInfo2 *>(this); }
    VkDeviceQueueInfo2 const *ptr() const { return reinterpret_cast<VkDeviceQueueInfo2 const *>(this); }
};

struct safe_VkProtectedSubmitInfo {
    VkStructureType sType;
    const void* pNext;
    VkBool32 protectedSubmit;
    safe_VkProtectedSubmitInfo(const VkProtectedSubmitInfo* in_struct);
    safe_VkProtectedSubmitInfo(const safe_VkProtectedSubmitInfo& copy_src);
    safe_VkProtectedSubmitInfo& operator=(const safe_VkProtectedSubmitInfo& copy_src);
    safe_VkProtectedSubmitInfo();
    ~safe_VkProtectedSubmitInfo();
    void initialize(const VkProtectedSubmitInfo* in_struct);
    void initialize(const safe_VkProtectedSubmitInfo* copy_src);
    VkProtectedSubmitInfo *ptr() { return reinterpret_cast<VkProtectedSubmitInfo *>(this); }
    VkProtectedSubmitInfo const *ptr() const { return reinterpret_cast<VkProtectedSubmitInfo const *>(this); }
};

struct safe_VkSamplerYcbcrConversionCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkFormat format;
    VkSamplerYcbcrModelConversion ycbcrModel;
    VkSamplerYcbcrRange ycbcrRange;
    VkComponentMapping components;
    VkChromaLocation xChromaOffset;
    VkChromaLocation yChromaOffset;
    VkFilter chromaFilter;
    VkBool32 forceExplicitReconstruction;
    safe_VkSamplerYcbcrConversionCreateInfo(const VkSamplerYcbcrConversionCreateInfo* in_struct);
    safe_VkSamplerYcbcrConversionCreateInfo(const safe_VkSamplerYcbcrConversionCreateInfo& copy_src);
    safe_VkSamplerYcbcrConversionCreateInfo& operator=(const safe_VkSamplerYcbcrConversionCreateInfo& copy_src);
    safe_VkSamplerYcbcrConversionCreateInfo();
    ~safe_VkSamplerYcbcrConversionCreateInfo();
    void initialize(const VkSamplerYcbcrConversionCreateInfo* in_struct);
    void initialize(const safe_VkSamplerYcbcrConversionCreateInfo* copy_src);
    VkSamplerYcbcrConversionCreateInfo *ptr() { return reinterpret_cast<VkSamplerYcbcrConversionCreateInfo *>(this); }
    VkSamplerYcbcrConversionCreateInfo const *ptr() const { return reinterpret_cast<VkSamplerYcbcrConversionCreateInfo const *>(this); }
};

struct safe_VkSamplerYcbcrConversionInfo {
    VkStructureType sType;
    const void* pNext;
    VkSamplerYcbcrConversion conversion;
    safe_VkSamplerYcbcrConversionInfo(const VkSamplerYcbcrConversionInfo* in_struct);
    safe_VkSamplerYcbcrConversionInfo(const safe_VkSamplerYcbcrConversionInfo& copy_src);
    safe_VkSamplerYcbcrConversionInfo& operator=(const safe_VkSamplerYcbcrConversionInfo& copy_src);
    safe_VkSamplerYcbcrConversionInfo();
    ~safe_VkSamplerYcbcrConversionInfo();
    void initialize(const VkSamplerYcbcrConversionInfo* in_struct);
    void initialize(const safe_VkSamplerYcbcrConversionInfo* copy_src);
    VkSamplerYcbcrConversionInfo *ptr() { return reinterpret_cast<VkSamplerYcbcrConversionInfo *>(this); }
    VkSamplerYcbcrConversionInfo const *ptr() const { return reinterpret_cast<VkSamplerYcbcrConversionInfo const *>(this); }
};

struct safe_VkBindImagePlaneMemoryInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageAspectFlagBits planeAspect;
    safe_VkBindImagePlaneMemoryInfo(const VkBindImagePlaneMemoryInfo* in_struct);
    safe_VkBindImagePlaneMemoryInfo(const safe_VkBindImagePlaneMemoryInfo& copy_src);
    safe_VkBindImagePlaneMemoryInfo& operator=(const safe_VkBindImagePlaneMemoryInfo& copy_src);
    safe_VkBindImagePlaneMemoryInfo();
    ~safe_VkBindImagePlaneMemoryInfo();
    void initialize(const VkBindImagePlaneMemoryInfo* in_struct);
    void initialize(const safe_VkBindImagePlaneMemoryInfo* copy_src);
    VkBindImagePlaneMemoryInfo *ptr() { return reinterpret_cast<VkBindImagePlaneMemoryInfo *>(this); }
    VkBindImagePlaneMemoryInfo const *ptr() const { return reinterpret_cast<VkBindImagePlaneMemoryInfo const *>(this); }
};

struct safe_VkImagePlaneMemoryRequirementsInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageAspectFlagBits planeAspect;
    safe_VkImagePlaneMemoryRequirementsInfo(const VkImagePlaneMemoryRequirementsInfo* in_struct);
    safe_VkImagePlaneMemoryRequirementsInfo(const safe_VkImagePlaneMemoryRequirementsInfo& copy_src);
    safe_VkImagePlaneMemoryRequirementsInfo& operator=(const safe_VkImagePlaneMemoryRequirementsInfo& copy_src);
    safe_VkImagePlaneMemoryRequirementsInfo();
    ~safe_VkImagePlaneMemoryRequirementsInfo();
    void initialize(const VkImagePlaneMemoryRequirementsInfo* in_struct);
    void initialize(const safe_VkImagePlaneMemoryRequirementsInfo* copy_src);
    VkImagePlaneMemoryRequirementsInfo *ptr() { return reinterpret_cast<VkImagePlaneMemoryRequirementsInfo *>(this); }
    VkImagePlaneMemoryRequirementsInfo const *ptr() const { return reinterpret_cast<VkImagePlaneMemoryRequirementsInfo const *>(this); }
};

struct safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 samplerYcbcrConversion;
    safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures(const VkPhysicalDeviceSamplerYcbcrConversionFeatures* in_struct);
    safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures(const safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures& copy_src);
    safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures& operator=(const safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures& copy_src);
    safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures();
    ~safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures();
    void initialize(const VkPhysicalDeviceSamplerYcbcrConversionFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceSamplerYcbcrConversionFeatures* copy_src);
    VkPhysicalDeviceSamplerYcbcrConversionFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures *>(this); }
    VkPhysicalDeviceSamplerYcbcrConversionFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSamplerYcbcrConversionFeatures const *>(this); }
};

struct safe_VkSamplerYcbcrConversionImageFormatProperties {
    VkStructureType sType;
    void* pNext;
    uint32_t combinedImageSamplerDescriptorCount;
    safe_VkSamplerYcbcrConversionImageFormatProperties(const VkSamplerYcbcrConversionImageFormatProperties* in_struct);
    safe_VkSamplerYcbcrConversionImageFormatProperties(const safe_VkSamplerYcbcrConversionImageFormatProperties& copy_src);
    safe_VkSamplerYcbcrConversionImageFormatProperties& operator=(const safe_VkSamplerYcbcrConversionImageFormatProperties& copy_src);
    safe_VkSamplerYcbcrConversionImageFormatProperties();
    ~safe_VkSamplerYcbcrConversionImageFormatProperties();
    void initialize(const VkSamplerYcbcrConversionImageFormatProperties* in_struct);
    void initialize(const safe_VkSamplerYcbcrConversionImageFormatProperties* copy_src);
    VkSamplerYcbcrConversionImageFormatProperties *ptr() { return reinterpret_cast<VkSamplerYcbcrConversionImageFormatProperties *>(this); }
    VkSamplerYcbcrConversionImageFormatProperties const *ptr() const { return reinterpret_cast<VkSamplerYcbcrConversionImageFormatProperties const *>(this); }
};

struct safe_VkDescriptorUpdateTemplateCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkDescriptorUpdateTemplateCreateFlags flags;
    uint32_t descriptorUpdateEntryCount;
    const VkDescriptorUpdateTemplateEntry* pDescriptorUpdateEntries;
    VkDescriptorUpdateTemplateType templateType;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout pipelineLayout;
    uint32_t set;
    safe_VkDescriptorUpdateTemplateCreateInfo(const VkDescriptorUpdateTemplateCreateInfo* in_struct);
    safe_VkDescriptorUpdateTemplateCreateInfo(const safe_VkDescriptorUpdateTemplateCreateInfo& copy_src);
    safe_VkDescriptorUpdateTemplateCreateInfo& operator=(const safe_VkDescriptorUpdateTemplateCreateInfo& copy_src);
    safe_VkDescriptorUpdateTemplateCreateInfo();
    ~safe_VkDescriptorUpdateTemplateCreateInfo();
    void initialize(const VkDescriptorUpdateTemplateCreateInfo* in_struct);
    void initialize(const safe_VkDescriptorUpdateTemplateCreateInfo* copy_src);
    VkDescriptorUpdateTemplateCreateInfo *ptr() { return reinterpret_cast<VkDescriptorUpdateTemplateCreateInfo *>(this); }
    VkDescriptorUpdateTemplateCreateInfo const *ptr() const { return reinterpret_cast<VkDescriptorUpdateTemplateCreateInfo const *>(this); }
};

struct safe_VkPhysicalDeviceExternalImageFormatInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagBits handleType;
    safe_VkPhysicalDeviceExternalImageFormatInfo(const VkPhysicalDeviceExternalImageFormatInfo* in_struct);
    safe_VkPhysicalDeviceExternalImageFormatInfo(const safe_VkPhysicalDeviceExternalImageFormatInfo& copy_src);
    safe_VkPhysicalDeviceExternalImageFormatInfo& operator=(const safe_VkPhysicalDeviceExternalImageFormatInfo& copy_src);
    safe_VkPhysicalDeviceExternalImageFormatInfo();
    ~safe_VkPhysicalDeviceExternalImageFormatInfo();
    void initialize(const VkPhysicalDeviceExternalImageFormatInfo* in_struct);
    void initialize(const safe_VkPhysicalDeviceExternalImageFormatInfo* copy_src);
    VkPhysicalDeviceExternalImageFormatInfo *ptr() { return reinterpret_cast<VkPhysicalDeviceExternalImageFormatInfo *>(this); }
    VkPhysicalDeviceExternalImageFormatInfo const *ptr() const { return reinterpret_cast<VkPhysicalDeviceExternalImageFormatInfo const *>(this); }
};

struct safe_VkExternalImageFormatProperties {
    VkStructureType sType;
    void* pNext;
    VkExternalMemoryProperties externalMemoryProperties;
    safe_VkExternalImageFormatProperties(const VkExternalImageFormatProperties* in_struct);
    safe_VkExternalImageFormatProperties(const safe_VkExternalImageFormatProperties& copy_src);
    safe_VkExternalImageFormatProperties& operator=(const safe_VkExternalImageFormatProperties& copy_src);
    safe_VkExternalImageFormatProperties();
    ~safe_VkExternalImageFormatProperties();
    void initialize(const VkExternalImageFormatProperties* in_struct);
    void initialize(const safe_VkExternalImageFormatProperties* copy_src);
    VkExternalImageFormatProperties *ptr() { return reinterpret_cast<VkExternalImageFormatProperties *>(this); }
    VkExternalImageFormatProperties const *ptr() const { return reinterpret_cast<VkExternalImageFormatProperties const *>(this); }
};

struct safe_VkPhysicalDeviceExternalBufferInfo {
    VkStructureType sType;
    const void* pNext;
    VkBufferCreateFlags flags;
    VkBufferUsageFlags usage;
    VkExternalMemoryHandleTypeFlagBits handleType;
    safe_VkPhysicalDeviceExternalBufferInfo(const VkPhysicalDeviceExternalBufferInfo* in_struct);
    safe_VkPhysicalDeviceExternalBufferInfo(const safe_VkPhysicalDeviceExternalBufferInfo& copy_src);
    safe_VkPhysicalDeviceExternalBufferInfo& operator=(const safe_VkPhysicalDeviceExternalBufferInfo& copy_src);
    safe_VkPhysicalDeviceExternalBufferInfo();
    ~safe_VkPhysicalDeviceExternalBufferInfo();
    void initialize(const VkPhysicalDeviceExternalBufferInfo* in_struct);
    void initialize(const safe_VkPhysicalDeviceExternalBufferInfo* copy_src);
    VkPhysicalDeviceExternalBufferInfo *ptr() { return reinterpret_cast<VkPhysicalDeviceExternalBufferInfo *>(this); }
    VkPhysicalDeviceExternalBufferInfo const *ptr() const { return reinterpret_cast<VkPhysicalDeviceExternalBufferInfo const *>(this); }
};

struct safe_VkExternalBufferProperties {
    VkStructureType sType;
    void* pNext;
    VkExternalMemoryProperties externalMemoryProperties;
    safe_VkExternalBufferProperties(const VkExternalBufferProperties* in_struct);
    safe_VkExternalBufferProperties(const safe_VkExternalBufferProperties& copy_src);
    safe_VkExternalBufferProperties& operator=(const safe_VkExternalBufferProperties& copy_src);
    safe_VkExternalBufferProperties();
    ~safe_VkExternalBufferProperties();
    void initialize(const VkExternalBufferProperties* in_struct);
    void initialize(const safe_VkExternalBufferProperties* copy_src);
    VkExternalBufferProperties *ptr() { return reinterpret_cast<VkExternalBufferProperties *>(this); }
    VkExternalBufferProperties const *ptr() const { return reinterpret_cast<VkExternalBufferProperties const *>(this); }
};

struct safe_VkPhysicalDeviceIDProperties {
    VkStructureType sType;
    void* pNext;
    uint8_t deviceUUID[VK_UUID_SIZE];
    uint8_t driverUUID[VK_UUID_SIZE];
    uint8_t deviceLUID[VK_LUID_SIZE];
    uint32_t deviceNodeMask;
    VkBool32 deviceLUIDValid;
    safe_VkPhysicalDeviceIDProperties(const VkPhysicalDeviceIDProperties* in_struct);
    safe_VkPhysicalDeviceIDProperties(const safe_VkPhysicalDeviceIDProperties& copy_src);
    safe_VkPhysicalDeviceIDProperties& operator=(const safe_VkPhysicalDeviceIDProperties& copy_src);
    safe_VkPhysicalDeviceIDProperties();
    ~safe_VkPhysicalDeviceIDProperties();
    void initialize(const VkPhysicalDeviceIDProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceIDProperties* copy_src);
    VkPhysicalDeviceIDProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceIDProperties *>(this); }
    VkPhysicalDeviceIDProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceIDProperties const *>(this); }
};

struct safe_VkExternalMemoryImageCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlags handleTypes;
    safe_VkExternalMemoryImageCreateInfo(const VkExternalMemoryImageCreateInfo* in_struct);
    safe_VkExternalMemoryImageCreateInfo(const safe_VkExternalMemoryImageCreateInfo& copy_src);
    safe_VkExternalMemoryImageCreateInfo& operator=(const safe_VkExternalMemoryImageCreateInfo& copy_src);
    safe_VkExternalMemoryImageCreateInfo();
    ~safe_VkExternalMemoryImageCreateInfo();
    void initialize(const VkExternalMemoryImageCreateInfo* in_struct);
    void initialize(const safe_VkExternalMemoryImageCreateInfo* copy_src);
    VkExternalMemoryImageCreateInfo *ptr() { return reinterpret_cast<VkExternalMemoryImageCreateInfo *>(this); }
    VkExternalMemoryImageCreateInfo const *ptr() const { return reinterpret_cast<VkExternalMemoryImageCreateInfo const *>(this); }
};

struct safe_VkExternalMemoryBufferCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlags handleTypes;
    safe_VkExternalMemoryBufferCreateInfo(const VkExternalMemoryBufferCreateInfo* in_struct);
    safe_VkExternalMemoryBufferCreateInfo(const safe_VkExternalMemoryBufferCreateInfo& copy_src);
    safe_VkExternalMemoryBufferCreateInfo& operator=(const safe_VkExternalMemoryBufferCreateInfo& copy_src);
    safe_VkExternalMemoryBufferCreateInfo();
    ~safe_VkExternalMemoryBufferCreateInfo();
    void initialize(const VkExternalMemoryBufferCreateInfo* in_struct);
    void initialize(const safe_VkExternalMemoryBufferCreateInfo* copy_src);
    VkExternalMemoryBufferCreateInfo *ptr() { return reinterpret_cast<VkExternalMemoryBufferCreateInfo *>(this); }
    VkExternalMemoryBufferCreateInfo const *ptr() const { return reinterpret_cast<VkExternalMemoryBufferCreateInfo const *>(this); }
};

struct safe_VkExportMemoryAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlags handleTypes;
    safe_VkExportMemoryAllocateInfo(const VkExportMemoryAllocateInfo* in_struct);
    safe_VkExportMemoryAllocateInfo(const safe_VkExportMemoryAllocateInfo& copy_src);
    safe_VkExportMemoryAllocateInfo& operator=(const safe_VkExportMemoryAllocateInfo& copy_src);
    safe_VkExportMemoryAllocateInfo();
    ~safe_VkExportMemoryAllocateInfo();
    void initialize(const VkExportMemoryAllocateInfo* in_struct);
    void initialize(const safe_VkExportMemoryAllocateInfo* copy_src);
    VkExportMemoryAllocateInfo *ptr() { return reinterpret_cast<VkExportMemoryAllocateInfo *>(this); }
    VkExportMemoryAllocateInfo const *ptr() const { return reinterpret_cast<VkExportMemoryAllocateInfo const *>(this); }
};

struct safe_VkPhysicalDeviceExternalFenceInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalFenceHandleTypeFlagBits handleType;
    safe_VkPhysicalDeviceExternalFenceInfo(const VkPhysicalDeviceExternalFenceInfo* in_struct);
    safe_VkPhysicalDeviceExternalFenceInfo(const safe_VkPhysicalDeviceExternalFenceInfo& copy_src);
    safe_VkPhysicalDeviceExternalFenceInfo& operator=(const safe_VkPhysicalDeviceExternalFenceInfo& copy_src);
    safe_VkPhysicalDeviceExternalFenceInfo();
    ~safe_VkPhysicalDeviceExternalFenceInfo();
    void initialize(const VkPhysicalDeviceExternalFenceInfo* in_struct);
    void initialize(const safe_VkPhysicalDeviceExternalFenceInfo* copy_src);
    VkPhysicalDeviceExternalFenceInfo *ptr() { return reinterpret_cast<VkPhysicalDeviceExternalFenceInfo *>(this); }
    VkPhysicalDeviceExternalFenceInfo const *ptr() const { return reinterpret_cast<VkPhysicalDeviceExternalFenceInfo const *>(this); }
};

struct safe_VkExternalFenceProperties {
    VkStructureType sType;
    void* pNext;
    VkExternalFenceHandleTypeFlags exportFromImportedHandleTypes;
    VkExternalFenceHandleTypeFlags compatibleHandleTypes;
    VkExternalFenceFeatureFlags externalFenceFeatures;
    safe_VkExternalFenceProperties(const VkExternalFenceProperties* in_struct);
    safe_VkExternalFenceProperties(const safe_VkExternalFenceProperties& copy_src);
    safe_VkExternalFenceProperties& operator=(const safe_VkExternalFenceProperties& copy_src);
    safe_VkExternalFenceProperties();
    ~safe_VkExternalFenceProperties();
    void initialize(const VkExternalFenceProperties* in_struct);
    void initialize(const safe_VkExternalFenceProperties* copy_src);
    VkExternalFenceProperties *ptr() { return reinterpret_cast<VkExternalFenceProperties *>(this); }
    VkExternalFenceProperties const *ptr() const { return reinterpret_cast<VkExternalFenceProperties const *>(this); }
};

struct safe_VkExportFenceCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalFenceHandleTypeFlags handleTypes;
    safe_VkExportFenceCreateInfo(const VkExportFenceCreateInfo* in_struct);
    safe_VkExportFenceCreateInfo(const safe_VkExportFenceCreateInfo& copy_src);
    safe_VkExportFenceCreateInfo& operator=(const safe_VkExportFenceCreateInfo& copy_src);
    safe_VkExportFenceCreateInfo();
    ~safe_VkExportFenceCreateInfo();
    void initialize(const VkExportFenceCreateInfo* in_struct);
    void initialize(const safe_VkExportFenceCreateInfo* copy_src);
    VkExportFenceCreateInfo *ptr() { return reinterpret_cast<VkExportFenceCreateInfo *>(this); }
    VkExportFenceCreateInfo const *ptr() const { return reinterpret_cast<VkExportFenceCreateInfo const *>(this); }
};

struct safe_VkExportSemaphoreCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalSemaphoreHandleTypeFlags handleTypes;
    safe_VkExportSemaphoreCreateInfo(const VkExportSemaphoreCreateInfo* in_struct);
    safe_VkExportSemaphoreCreateInfo(const safe_VkExportSemaphoreCreateInfo& copy_src);
    safe_VkExportSemaphoreCreateInfo& operator=(const safe_VkExportSemaphoreCreateInfo& copy_src);
    safe_VkExportSemaphoreCreateInfo();
    ~safe_VkExportSemaphoreCreateInfo();
    void initialize(const VkExportSemaphoreCreateInfo* in_struct);
    void initialize(const safe_VkExportSemaphoreCreateInfo* copy_src);
    VkExportSemaphoreCreateInfo *ptr() { return reinterpret_cast<VkExportSemaphoreCreateInfo *>(this); }
    VkExportSemaphoreCreateInfo const *ptr() const { return reinterpret_cast<VkExportSemaphoreCreateInfo const *>(this); }
};

struct safe_VkPhysicalDeviceExternalSemaphoreInfo {
    VkStructureType sType;
    const void* pNext;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    safe_VkPhysicalDeviceExternalSemaphoreInfo(const VkPhysicalDeviceExternalSemaphoreInfo* in_struct);
    safe_VkPhysicalDeviceExternalSemaphoreInfo(const safe_VkPhysicalDeviceExternalSemaphoreInfo& copy_src);
    safe_VkPhysicalDeviceExternalSemaphoreInfo& operator=(const safe_VkPhysicalDeviceExternalSemaphoreInfo& copy_src);
    safe_VkPhysicalDeviceExternalSemaphoreInfo();
    ~safe_VkPhysicalDeviceExternalSemaphoreInfo();
    void initialize(const VkPhysicalDeviceExternalSemaphoreInfo* in_struct);
    void initialize(const safe_VkPhysicalDeviceExternalSemaphoreInfo* copy_src);
    VkPhysicalDeviceExternalSemaphoreInfo *ptr() { return reinterpret_cast<VkPhysicalDeviceExternalSemaphoreInfo *>(this); }
    VkPhysicalDeviceExternalSemaphoreInfo const *ptr() const { return reinterpret_cast<VkPhysicalDeviceExternalSemaphoreInfo const *>(this); }
};

struct safe_VkExternalSemaphoreProperties {
    VkStructureType sType;
    void* pNext;
    VkExternalSemaphoreHandleTypeFlags exportFromImportedHandleTypes;
    VkExternalSemaphoreHandleTypeFlags compatibleHandleTypes;
    VkExternalSemaphoreFeatureFlags externalSemaphoreFeatures;
    safe_VkExternalSemaphoreProperties(const VkExternalSemaphoreProperties* in_struct);
    safe_VkExternalSemaphoreProperties(const safe_VkExternalSemaphoreProperties& copy_src);
    safe_VkExternalSemaphoreProperties& operator=(const safe_VkExternalSemaphoreProperties& copy_src);
    safe_VkExternalSemaphoreProperties();
    ~safe_VkExternalSemaphoreProperties();
    void initialize(const VkExternalSemaphoreProperties* in_struct);
    void initialize(const safe_VkExternalSemaphoreProperties* copy_src);
    VkExternalSemaphoreProperties *ptr() { return reinterpret_cast<VkExternalSemaphoreProperties *>(this); }
    VkExternalSemaphoreProperties const *ptr() const { return reinterpret_cast<VkExternalSemaphoreProperties const *>(this); }
};

struct safe_VkPhysicalDeviceMaintenance3Properties {
    VkStructureType sType;
    void* pNext;
    uint32_t maxPerSetDescriptors;
    VkDeviceSize maxMemoryAllocationSize;
    safe_VkPhysicalDeviceMaintenance3Properties(const VkPhysicalDeviceMaintenance3Properties* in_struct);
    safe_VkPhysicalDeviceMaintenance3Properties(const safe_VkPhysicalDeviceMaintenance3Properties& copy_src);
    safe_VkPhysicalDeviceMaintenance3Properties& operator=(const safe_VkPhysicalDeviceMaintenance3Properties& copy_src);
    safe_VkPhysicalDeviceMaintenance3Properties();
    ~safe_VkPhysicalDeviceMaintenance3Properties();
    void initialize(const VkPhysicalDeviceMaintenance3Properties* in_struct);
    void initialize(const safe_VkPhysicalDeviceMaintenance3Properties* copy_src);
    VkPhysicalDeviceMaintenance3Properties *ptr() { return reinterpret_cast<VkPhysicalDeviceMaintenance3Properties *>(this); }
    VkPhysicalDeviceMaintenance3Properties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMaintenance3Properties const *>(this); }
};

struct safe_VkDescriptorSetLayoutSupport {
    VkStructureType sType;
    void* pNext;
    VkBool32 supported;
    safe_VkDescriptorSetLayoutSupport(const VkDescriptorSetLayoutSupport* in_struct);
    safe_VkDescriptorSetLayoutSupport(const safe_VkDescriptorSetLayoutSupport& copy_src);
    safe_VkDescriptorSetLayoutSupport& operator=(const safe_VkDescriptorSetLayoutSupport& copy_src);
    safe_VkDescriptorSetLayoutSupport();
    ~safe_VkDescriptorSetLayoutSupport();
    void initialize(const VkDescriptorSetLayoutSupport* in_struct);
    void initialize(const safe_VkDescriptorSetLayoutSupport* copy_src);
    VkDescriptorSetLayoutSupport *ptr() { return reinterpret_cast<VkDescriptorSetLayoutSupport *>(this); }
    VkDescriptorSetLayoutSupport const *ptr() const { return reinterpret_cast<VkDescriptorSetLayoutSupport const *>(this); }
};

struct safe_VkPhysicalDeviceShaderDrawParametersFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderDrawParameters;
    safe_VkPhysicalDeviceShaderDrawParametersFeatures(const VkPhysicalDeviceShaderDrawParametersFeatures* in_struct);
    safe_VkPhysicalDeviceShaderDrawParametersFeatures(const safe_VkPhysicalDeviceShaderDrawParametersFeatures& copy_src);
    safe_VkPhysicalDeviceShaderDrawParametersFeatures& operator=(const safe_VkPhysicalDeviceShaderDrawParametersFeatures& copy_src);
    safe_VkPhysicalDeviceShaderDrawParametersFeatures();
    ~safe_VkPhysicalDeviceShaderDrawParametersFeatures();
    void initialize(const VkPhysicalDeviceShaderDrawParametersFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderDrawParametersFeatures* copy_src);
    VkPhysicalDeviceShaderDrawParametersFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderDrawParametersFeatures *>(this); }
    VkPhysicalDeviceShaderDrawParametersFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderDrawParametersFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceVulkan11Features {
    VkStructureType sType;
    void* pNext;
    VkBool32 storageBuffer16BitAccess;
    VkBool32 uniformAndStorageBuffer16BitAccess;
    VkBool32 storagePushConstant16;
    VkBool32 storageInputOutput16;
    VkBool32 multiview;
    VkBool32 multiviewGeometryShader;
    VkBool32 multiviewTessellationShader;
    VkBool32 variablePointersStorageBuffer;
    VkBool32 variablePointers;
    VkBool32 protectedMemory;
    VkBool32 samplerYcbcrConversion;
    VkBool32 shaderDrawParameters;
    safe_VkPhysicalDeviceVulkan11Features(const VkPhysicalDeviceVulkan11Features* in_struct);
    safe_VkPhysicalDeviceVulkan11Features(const safe_VkPhysicalDeviceVulkan11Features& copy_src);
    safe_VkPhysicalDeviceVulkan11Features& operator=(const safe_VkPhysicalDeviceVulkan11Features& copy_src);
    safe_VkPhysicalDeviceVulkan11Features();
    ~safe_VkPhysicalDeviceVulkan11Features();
    void initialize(const VkPhysicalDeviceVulkan11Features* in_struct);
    void initialize(const safe_VkPhysicalDeviceVulkan11Features* copy_src);
    VkPhysicalDeviceVulkan11Features *ptr() { return reinterpret_cast<VkPhysicalDeviceVulkan11Features *>(this); }
    VkPhysicalDeviceVulkan11Features const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVulkan11Features const *>(this); }
};

struct safe_VkPhysicalDeviceVulkan11Properties {
    VkStructureType sType;
    void* pNext;
    uint8_t deviceUUID[VK_UUID_SIZE];
    uint8_t driverUUID[VK_UUID_SIZE];
    uint8_t deviceLUID[VK_LUID_SIZE];
    uint32_t deviceNodeMask;
    VkBool32 deviceLUIDValid;
    uint32_t subgroupSize;
    VkShaderStageFlags subgroupSupportedStages;
    VkSubgroupFeatureFlags subgroupSupportedOperations;
    VkBool32 subgroupQuadOperationsInAllStages;
    VkPointClippingBehavior pointClippingBehavior;
    uint32_t maxMultiviewViewCount;
    uint32_t maxMultiviewInstanceIndex;
    VkBool32 protectedNoFault;
    uint32_t maxPerSetDescriptors;
    VkDeviceSize maxMemoryAllocationSize;
    safe_VkPhysicalDeviceVulkan11Properties(const VkPhysicalDeviceVulkan11Properties* in_struct);
    safe_VkPhysicalDeviceVulkan11Properties(const safe_VkPhysicalDeviceVulkan11Properties& copy_src);
    safe_VkPhysicalDeviceVulkan11Properties& operator=(const safe_VkPhysicalDeviceVulkan11Properties& copy_src);
    safe_VkPhysicalDeviceVulkan11Properties();
    ~safe_VkPhysicalDeviceVulkan11Properties();
    void initialize(const VkPhysicalDeviceVulkan11Properties* in_struct);
    void initialize(const safe_VkPhysicalDeviceVulkan11Properties* copy_src);
    VkPhysicalDeviceVulkan11Properties *ptr() { return reinterpret_cast<VkPhysicalDeviceVulkan11Properties *>(this); }
    VkPhysicalDeviceVulkan11Properties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVulkan11Properties const *>(this); }
};

struct safe_VkPhysicalDeviceVulkan12Features {
    VkStructureType sType;
    void* pNext;
    VkBool32 samplerMirrorClampToEdge;
    VkBool32 drawIndirectCount;
    VkBool32 storageBuffer8BitAccess;
    VkBool32 uniformAndStorageBuffer8BitAccess;
    VkBool32 storagePushConstant8;
    VkBool32 shaderBufferInt64Atomics;
    VkBool32 shaderSharedInt64Atomics;
    VkBool32 shaderFloat16;
    VkBool32 shaderInt8;
    VkBool32 descriptorIndexing;
    VkBool32 shaderInputAttachmentArrayDynamicIndexing;
    VkBool32 shaderUniformTexelBufferArrayDynamicIndexing;
    VkBool32 shaderStorageTexelBufferArrayDynamicIndexing;
    VkBool32 shaderUniformBufferArrayNonUniformIndexing;
    VkBool32 shaderSampledImageArrayNonUniformIndexing;
    VkBool32 shaderStorageBufferArrayNonUniformIndexing;
    VkBool32 shaderStorageImageArrayNonUniformIndexing;
    VkBool32 shaderInputAttachmentArrayNonUniformIndexing;
    VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing;
    VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing;
    VkBool32 descriptorBindingUniformBufferUpdateAfterBind;
    VkBool32 descriptorBindingSampledImageUpdateAfterBind;
    VkBool32 descriptorBindingStorageImageUpdateAfterBind;
    VkBool32 descriptorBindingStorageBufferUpdateAfterBind;
    VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind;
    VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind;
    VkBool32 descriptorBindingUpdateUnusedWhilePending;
    VkBool32 descriptorBindingPartiallyBound;
    VkBool32 descriptorBindingVariableDescriptorCount;
    VkBool32 runtimeDescriptorArray;
    VkBool32 samplerFilterMinmax;
    VkBool32 scalarBlockLayout;
    VkBool32 imagelessFramebuffer;
    VkBool32 uniformBufferStandardLayout;
    VkBool32 shaderSubgroupExtendedTypes;
    VkBool32 separateDepthStencilLayouts;
    VkBool32 hostQueryReset;
    VkBool32 timelineSemaphore;
    VkBool32 bufferDeviceAddress;
    VkBool32 bufferDeviceAddressCaptureReplay;
    VkBool32 bufferDeviceAddressMultiDevice;
    VkBool32 vulkanMemoryModel;
    VkBool32 vulkanMemoryModelDeviceScope;
    VkBool32 vulkanMemoryModelAvailabilityVisibilityChains;
    VkBool32 shaderOutputViewportIndex;
    VkBool32 shaderOutputLayer;
    VkBool32 subgroupBroadcastDynamicId;
    safe_VkPhysicalDeviceVulkan12Features(const VkPhysicalDeviceVulkan12Features* in_struct);
    safe_VkPhysicalDeviceVulkan12Features(const safe_VkPhysicalDeviceVulkan12Features& copy_src);
    safe_VkPhysicalDeviceVulkan12Features& operator=(const safe_VkPhysicalDeviceVulkan12Features& copy_src);
    safe_VkPhysicalDeviceVulkan12Features();
    ~safe_VkPhysicalDeviceVulkan12Features();
    void initialize(const VkPhysicalDeviceVulkan12Features* in_struct);
    void initialize(const safe_VkPhysicalDeviceVulkan12Features* copy_src);
    VkPhysicalDeviceVulkan12Features *ptr() { return reinterpret_cast<VkPhysicalDeviceVulkan12Features *>(this); }
    VkPhysicalDeviceVulkan12Features const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVulkan12Features const *>(this); }
};

struct safe_VkPhysicalDeviceVulkan12Properties {
    VkStructureType sType;
    void* pNext;
    VkDriverId driverID;
    char driverName[VK_MAX_DRIVER_NAME_SIZE];
    char driverInfo[VK_MAX_DRIVER_INFO_SIZE];
    VkConformanceVersion conformanceVersion;
    VkShaderFloatControlsIndependence denormBehaviorIndependence;
    VkShaderFloatControlsIndependence roundingModeIndependence;
    VkBool32 shaderSignedZeroInfNanPreserveFloat16;
    VkBool32 shaderSignedZeroInfNanPreserveFloat32;
    VkBool32 shaderSignedZeroInfNanPreserveFloat64;
    VkBool32 shaderDenormPreserveFloat16;
    VkBool32 shaderDenormPreserveFloat32;
    VkBool32 shaderDenormPreserveFloat64;
    VkBool32 shaderDenormFlushToZeroFloat16;
    VkBool32 shaderDenormFlushToZeroFloat32;
    VkBool32 shaderDenormFlushToZeroFloat64;
    VkBool32 shaderRoundingModeRTEFloat16;
    VkBool32 shaderRoundingModeRTEFloat32;
    VkBool32 shaderRoundingModeRTEFloat64;
    VkBool32 shaderRoundingModeRTZFloat16;
    VkBool32 shaderRoundingModeRTZFloat32;
    VkBool32 shaderRoundingModeRTZFloat64;
    uint32_t maxUpdateAfterBindDescriptorsInAllPools;
    VkBool32 shaderUniformBufferArrayNonUniformIndexingNative;
    VkBool32 shaderSampledImageArrayNonUniformIndexingNative;
    VkBool32 shaderStorageBufferArrayNonUniformIndexingNative;
    VkBool32 shaderStorageImageArrayNonUniformIndexingNative;
    VkBool32 shaderInputAttachmentArrayNonUniformIndexingNative;
    VkBool32 robustBufferAccessUpdateAfterBind;
    VkBool32 quadDivergentImplicitLod;
    uint32_t maxPerStageDescriptorUpdateAfterBindSamplers;
    uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers;
    uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages;
    uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments;
    uint32_t maxPerStageUpdateAfterBindResources;
    uint32_t maxDescriptorSetUpdateAfterBindSamplers;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
    uint32_t maxDescriptorSetUpdateAfterBindSampledImages;
    uint32_t maxDescriptorSetUpdateAfterBindStorageImages;
    uint32_t maxDescriptorSetUpdateAfterBindInputAttachments;
    VkResolveModeFlags supportedDepthResolveModes;
    VkResolveModeFlags supportedStencilResolveModes;
    VkBool32 independentResolveNone;
    VkBool32 independentResolve;
    VkBool32 filterMinmaxSingleComponentFormats;
    VkBool32 filterMinmaxImageComponentMapping;
    uint64_t maxTimelineSemaphoreValueDifference;
    VkSampleCountFlags framebufferIntegerColorSampleCounts;
    safe_VkPhysicalDeviceVulkan12Properties(const VkPhysicalDeviceVulkan12Properties* in_struct);
    safe_VkPhysicalDeviceVulkan12Properties(const safe_VkPhysicalDeviceVulkan12Properties& copy_src);
    safe_VkPhysicalDeviceVulkan12Properties& operator=(const safe_VkPhysicalDeviceVulkan12Properties& copy_src);
    safe_VkPhysicalDeviceVulkan12Properties();
    ~safe_VkPhysicalDeviceVulkan12Properties();
    void initialize(const VkPhysicalDeviceVulkan12Properties* in_struct);
    void initialize(const safe_VkPhysicalDeviceVulkan12Properties* copy_src);
    VkPhysicalDeviceVulkan12Properties *ptr() { return reinterpret_cast<VkPhysicalDeviceVulkan12Properties *>(this); }
    VkPhysicalDeviceVulkan12Properties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVulkan12Properties const *>(this); }
};

struct safe_VkImageFormatListCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t viewFormatCount;
    const VkFormat* pViewFormats;
    safe_VkImageFormatListCreateInfo(const VkImageFormatListCreateInfo* in_struct);
    safe_VkImageFormatListCreateInfo(const safe_VkImageFormatListCreateInfo& copy_src);
    safe_VkImageFormatListCreateInfo& operator=(const safe_VkImageFormatListCreateInfo& copy_src);
    safe_VkImageFormatListCreateInfo();
    ~safe_VkImageFormatListCreateInfo();
    void initialize(const VkImageFormatListCreateInfo* in_struct);
    void initialize(const safe_VkImageFormatListCreateInfo* copy_src);
    VkImageFormatListCreateInfo *ptr() { return reinterpret_cast<VkImageFormatListCreateInfo *>(this); }
    VkImageFormatListCreateInfo const *ptr() const { return reinterpret_cast<VkImageFormatListCreateInfo const *>(this); }
};

struct safe_VkAttachmentDescription2 {
    VkStructureType sType;
    const void* pNext;
    VkAttachmentDescriptionFlags flags;
    VkFormat format;
    VkSampleCountFlagBits samples;
    VkAttachmentLoadOp loadOp;
    VkAttachmentStoreOp storeOp;
    VkAttachmentLoadOp stencilLoadOp;
    VkAttachmentStoreOp stencilStoreOp;
    VkImageLayout initialLayout;
    VkImageLayout finalLayout;
    safe_VkAttachmentDescription2(const VkAttachmentDescription2* in_struct);
    safe_VkAttachmentDescription2(const safe_VkAttachmentDescription2& copy_src);
    safe_VkAttachmentDescription2& operator=(const safe_VkAttachmentDescription2& copy_src);
    safe_VkAttachmentDescription2();
    ~safe_VkAttachmentDescription2();
    void initialize(const VkAttachmentDescription2* in_struct);
    void initialize(const safe_VkAttachmentDescription2* copy_src);
    VkAttachmentDescription2 *ptr() { return reinterpret_cast<VkAttachmentDescription2 *>(this); }
    VkAttachmentDescription2 const *ptr() const { return reinterpret_cast<VkAttachmentDescription2 const *>(this); }
};

struct safe_VkAttachmentReference2 {
    VkStructureType sType;
    const void* pNext;
    uint32_t attachment;
    VkImageLayout layout;
    VkImageAspectFlags aspectMask;
    safe_VkAttachmentReference2(const VkAttachmentReference2* in_struct);
    safe_VkAttachmentReference2(const safe_VkAttachmentReference2& copy_src);
    safe_VkAttachmentReference2& operator=(const safe_VkAttachmentReference2& copy_src);
    safe_VkAttachmentReference2();
    ~safe_VkAttachmentReference2();
    void initialize(const VkAttachmentReference2* in_struct);
    void initialize(const safe_VkAttachmentReference2* copy_src);
    VkAttachmentReference2 *ptr() { return reinterpret_cast<VkAttachmentReference2 *>(this); }
    VkAttachmentReference2 const *ptr() const { return reinterpret_cast<VkAttachmentReference2 const *>(this); }
};

struct safe_VkSubpassDescription2 {
    VkStructureType sType;
    const void* pNext;
    VkSubpassDescriptionFlags flags;
    VkPipelineBindPoint pipelineBindPoint;
    uint32_t viewMask;
    uint32_t inputAttachmentCount;
    safe_VkAttachmentReference2* pInputAttachments;
    uint32_t colorAttachmentCount;
    safe_VkAttachmentReference2* pColorAttachments;
    safe_VkAttachmentReference2* pResolveAttachments;
    safe_VkAttachmentReference2* pDepthStencilAttachment;
    uint32_t preserveAttachmentCount;
    const uint32_t* pPreserveAttachments;
    safe_VkSubpassDescription2(const VkSubpassDescription2* in_struct);
    safe_VkSubpassDescription2(const safe_VkSubpassDescription2& copy_src);
    safe_VkSubpassDescription2& operator=(const safe_VkSubpassDescription2& copy_src);
    safe_VkSubpassDescription2();
    ~safe_VkSubpassDescription2();
    void initialize(const VkSubpassDescription2* in_struct);
    void initialize(const safe_VkSubpassDescription2* copy_src);
    VkSubpassDescription2 *ptr() { return reinterpret_cast<VkSubpassDescription2 *>(this); }
    VkSubpassDescription2 const *ptr() const { return reinterpret_cast<VkSubpassDescription2 const *>(this); }
};

struct safe_VkSubpassDependency2 {
    VkStructureType sType;
    const void* pNext;
    uint32_t srcSubpass;
    uint32_t dstSubpass;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkAccessFlags srcAccessMask;
    VkAccessFlags dstAccessMask;
    VkDependencyFlags dependencyFlags;
    int32_t viewOffset;
    safe_VkSubpassDependency2(const VkSubpassDependency2* in_struct);
    safe_VkSubpassDependency2(const safe_VkSubpassDependency2& copy_src);
    safe_VkSubpassDependency2& operator=(const safe_VkSubpassDependency2& copy_src);
    safe_VkSubpassDependency2();
    ~safe_VkSubpassDependency2();
    void initialize(const VkSubpassDependency2* in_struct);
    void initialize(const safe_VkSubpassDependency2* copy_src);
    VkSubpassDependency2 *ptr() { return reinterpret_cast<VkSubpassDependency2 *>(this); }
    VkSubpassDependency2 const *ptr() const { return reinterpret_cast<VkSubpassDependency2 const *>(this); }
};

struct safe_VkRenderPassCreateInfo2 {
    VkStructureType sType;
    const void* pNext;
    VkRenderPassCreateFlags flags;
    uint32_t attachmentCount;
    safe_VkAttachmentDescription2* pAttachments;
    uint32_t subpassCount;
    safe_VkSubpassDescription2* pSubpasses;
    uint32_t dependencyCount;
    safe_VkSubpassDependency2* pDependencies;
    uint32_t correlatedViewMaskCount;
    const uint32_t* pCorrelatedViewMasks;
    safe_VkRenderPassCreateInfo2(const VkRenderPassCreateInfo2* in_struct);
    safe_VkRenderPassCreateInfo2(const safe_VkRenderPassCreateInfo2& copy_src);
    safe_VkRenderPassCreateInfo2& operator=(const safe_VkRenderPassCreateInfo2& copy_src);
    safe_VkRenderPassCreateInfo2();
    ~safe_VkRenderPassCreateInfo2();
    void initialize(const VkRenderPassCreateInfo2* in_struct);
    void initialize(const safe_VkRenderPassCreateInfo2* copy_src);
    VkRenderPassCreateInfo2 *ptr() { return reinterpret_cast<VkRenderPassCreateInfo2 *>(this); }
    VkRenderPassCreateInfo2 const *ptr() const { return reinterpret_cast<VkRenderPassCreateInfo2 const *>(this); }
};

struct safe_VkSubpassBeginInfo {
    VkStructureType sType;
    const void* pNext;
    VkSubpassContents contents;
    safe_VkSubpassBeginInfo(const VkSubpassBeginInfo* in_struct);
    safe_VkSubpassBeginInfo(const safe_VkSubpassBeginInfo& copy_src);
    safe_VkSubpassBeginInfo& operator=(const safe_VkSubpassBeginInfo& copy_src);
    safe_VkSubpassBeginInfo();
    ~safe_VkSubpassBeginInfo();
    void initialize(const VkSubpassBeginInfo* in_struct);
    void initialize(const safe_VkSubpassBeginInfo* copy_src);
    VkSubpassBeginInfo *ptr() { return reinterpret_cast<VkSubpassBeginInfo *>(this); }
    VkSubpassBeginInfo const *ptr() const { return reinterpret_cast<VkSubpassBeginInfo const *>(this); }
};

struct safe_VkSubpassEndInfo {
    VkStructureType sType;
    const void* pNext;
    safe_VkSubpassEndInfo(const VkSubpassEndInfo* in_struct);
    safe_VkSubpassEndInfo(const safe_VkSubpassEndInfo& copy_src);
    safe_VkSubpassEndInfo& operator=(const safe_VkSubpassEndInfo& copy_src);
    safe_VkSubpassEndInfo();
    ~safe_VkSubpassEndInfo();
    void initialize(const VkSubpassEndInfo* in_struct);
    void initialize(const safe_VkSubpassEndInfo* copy_src);
    VkSubpassEndInfo *ptr() { return reinterpret_cast<VkSubpassEndInfo *>(this); }
    VkSubpassEndInfo const *ptr() const { return reinterpret_cast<VkSubpassEndInfo const *>(this); }
};

struct safe_VkPhysicalDevice8BitStorageFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 storageBuffer8BitAccess;
    VkBool32 uniformAndStorageBuffer8BitAccess;
    VkBool32 storagePushConstant8;
    safe_VkPhysicalDevice8BitStorageFeatures(const VkPhysicalDevice8BitStorageFeatures* in_struct);
    safe_VkPhysicalDevice8BitStorageFeatures(const safe_VkPhysicalDevice8BitStorageFeatures& copy_src);
    safe_VkPhysicalDevice8BitStorageFeatures& operator=(const safe_VkPhysicalDevice8BitStorageFeatures& copy_src);
    safe_VkPhysicalDevice8BitStorageFeatures();
    ~safe_VkPhysicalDevice8BitStorageFeatures();
    void initialize(const VkPhysicalDevice8BitStorageFeatures* in_struct);
    void initialize(const safe_VkPhysicalDevice8BitStorageFeatures* copy_src);
    VkPhysicalDevice8BitStorageFeatures *ptr() { return reinterpret_cast<VkPhysicalDevice8BitStorageFeatures *>(this); }
    VkPhysicalDevice8BitStorageFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDevice8BitStorageFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceDriverProperties {
    VkStructureType sType;
    void* pNext;
    VkDriverId driverID;
    char driverName[VK_MAX_DRIVER_NAME_SIZE];
    char driverInfo[VK_MAX_DRIVER_INFO_SIZE];
    VkConformanceVersion conformanceVersion;
    safe_VkPhysicalDeviceDriverProperties(const VkPhysicalDeviceDriverProperties* in_struct);
    safe_VkPhysicalDeviceDriverProperties(const safe_VkPhysicalDeviceDriverProperties& copy_src);
    safe_VkPhysicalDeviceDriverProperties& operator=(const safe_VkPhysicalDeviceDriverProperties& copy_src);
    safe_VkPhysicalDeviceDriverProperties();
    ~safe_VkPhysicalDeviceDriverProperties();
    void initialize(const VkPhysicalDeviceDriverProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceDriverProperties* copy_src);
    VkPhysicalDeviceDriverProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceDriverProperties *>(this); }
    VkPhysicalDeviceDriverProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDriverProperties const *>(this); }
};

struct safe_VkPhysicalDeviceShaderAtomicInt64Features {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderBufferInt64Atomics;
    VkBool32 shaderSharedInt64Atomics;
    safe_VkPhysicalDeviceShaderAtomicInt64Features(const VkPhysicalDeviceShaderAtomicInt64Features* in_struct);
    safe_VkPhysicalDeviceShaderAtomicInt64Features(const safe_VkPhysicalDeviceShaderAtomicInt64Features& copy_src);
    safe_VkPhysicalDeviceShaderAtomicInt64Features& operator=(const safe_VkPhysicalDeviceShaderAtomicInt64Features& copy_src);
    safe_VkPhysicalDeviceShaderAtomicInt64Features();
    ~safe_VkPhysicalDeviceShaderAtomicInt64Features();
    void initialize(const VkPhysicalDeviceShaderAtomicInt64Features* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderAtomicInt64Features* copy_src);
    VkPhysicalDeviceShaderAtomicInt64Features *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderAtomicInt64Features *>(this); }
    VkPhysicalDeviceShaderAtomicInt64Features const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderAtomicInt64Features const *>(this); }
};

struct safe_VkPhysicalDeviceShaderFloat16Int8Features {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderFloat16;
    VkBool32 shaderInt8;
    safe_VkPhysicalDeviceShaderFloat16Int8Features(const VkPhysicalDeviceShaderFloat16Int8Features* in_struct);
    safe_VkPhysicalDeviceShaderFloat16Int8Features(const safe_VkPhysicalDeviceShaderFloat16Int8Features& copy_src);
    safe_VkPhysicalDeviceShaderFloat16Int8Features& operator=(const safe_VkPhysicalDeviceShaderFloat16Int8Features& copy_src);
    safe_VkPhysicalDeviceShaderFloat16Int8Features();
    ~safe_VkPhysicalDeviceShaderFloat16Int8Features();
    void initialize(const VkPhysicalDeviceShaderFloat16Int8Features* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderFloat16Int8Features* copy_src);
    VkPhysicalDeviceShaderFloat16Int8Features *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderFloat16Int8Features *>(this); }
    VkPhysicalDeviceShaderFloat16Int8Features const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderFloat16Int8Features const *>(this); }
};

struct safe_VkPhysicalDeviceFloatControlsProperties {
    VkStructureType sType;
    void* pNext;
    VkShaderFloatControlsIndependence denormBehaviorIndependence;
    VkShaderFloatControlsIndependence roundingModeIndependence;
    VkBool32 shaderSignedZeroInfNanPreserveFloat16;
    VkBool32 shaderSignedZeroInfNanPreserveFloat32;
    VkBool32 shaderSignedZeroInfNanPreserveFloat64;
    VkBool32 shaderDenormPreserveFloat16;
    VkBool32 shaderDenormPreserveFloat32;
    VkBool32 shaderDenormPreserveFloat64;
    VkBool32 shaderDenormFlushToZeroFloat16;
    VkBool32 shaderDenormFlushToZeroFloat32;
    VkBool32 shaderDenormFlushToZeroFloat64;
    VkBool32 shaderRoundingModeRTEFloat16;
    VkBool32 shaderRoundingModeRTEFloat32;
    VkBool32 shaderRoundingModeRTEFloat64;
    VkBool32 shaderRoundingModeRTZFloat16;
    VkBool32 shaderRoundingModeRTZFloat32;
    VkBool32 shaderRoundingModeRTZFloat64;
    safe_VkPhysicalDeviceFloatControlsProperties(const VkPhysicalDeviceFloatControlsProperties* in_struct);
    safe_VkPhysicalDeviceFloatControlsProperties(const safe_VkPhysicalDeviceFloatControlsProperties& copy_src);
    safe_VkPhysicalDeviceFloatControlsProperties& operator=(const safe_VkPhysicalDeviceFloatControlsProperties& copy_src);
    safe_VkPhysicalDeviceFloatControlsProperties();
    ~safe_VkPhysicalDeviceFloatControlsProperties();
    void initialize(const VkPhysicalDeviceFloatControlsProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceFloatControlsProperties* copy_src);
    VkPhysicalDeviceFloatControlsProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceFloatControlsProperties *>(this); }
    VkPhysicalDeviceFloatControlsProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceFloatControlsProperties const *>(this); }
};

struct safe_VkDescriptorSetLayoutBindingFlagsCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t bindingCount;
    const VkDescriptorBindingFlags* pBindingFlags;
    safe_VkDescriptorSetLayoutBindingFlagsCreateInfo(const VkDescriptorSetLayoutBindingFlagsCreateInfo* in_struct);
    safe_VkDescriptorSetLayoutBindingFlagsCreateInfo(const safe_VkDescriptorSetLayoutBindingFlagsCreateInfo& copy_src);
    safe_VkDescriptorSetLayoutBindingFlagsCreateInfo& operator=(const safe_VkDescriptorSetLayoutBindingFlagsCreateInfo& copy_src);
    safe_VkDescriptorSetLayoutBindingFlagsCreateInfo();
    ~safe_VkDescriptorSetLayoutBindingFlagsCreateInfo();
    void initialize(const VkDescriptorSetLayoutBindingFlagsCreateInfo* in_struct);
    void initialize(const safe_VkDescriptorSetLayoutBindingFlagsCreateInfo* copy_src);
    VkDescriptorSetLayoutBindingFlagsCreateInfo *ptr() { return reinterpret_cast<VkDescriptorSetLayoutBindingFlagsCreateInfo *>(this); }
    VkDescriptorSetLayoutBindingFlagsCreateInfo const *ptr() const { return reinterpret_cast<VkDescriptorSetLayoutBindingFlagsCreateInfo const *>(this); }
};

struct safe_VkPhysicalDeviceDescriptorIndexingFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderInputAttachmentArrayDynamicIndexing;
    VkBool32 shaderUniformTexelBufferArrayDynamicIndexing;
    VkBool32 shaderStorageTexelBufferArrayDynamicIndexing;
    VkBool32 shaderUniformBufferArrayNonUniformIndexing;
    VkBool32 shaderSampledImageArrayNonUniformIndexing;
    VkBool32 shaderStorageBufferArrayNonUniformIndexing;
    VkBool32 shaderStorageImageArrayNonUniformIndexing;
    VkBool32 shaderInputAttachmentArrayNonUniformIndexing;
    VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing;
    VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing;
    VkBool32 descriptorBindingUniformBufferUpdateAfterBind;
    VkBool32 descriptorBindingSampledImageUpdateAfterBind;
    VkBool32 descriptorBindingStorageImageUpdateAfterBind;
    VkBool32 descriptorBindingStorageBufferUpdateAfterBind;
    VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind;
    VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind;
    VkBool32 descriptorBindingUpdateUnusedWhilePending;
    VkBool32 descriptorBindingPartiallyBound;
    VkBool32 descriptorBindingVariableDescriptorCount;
    VkBool32 runtimeDescriptorArray;
    safe_VkPhysicalDeviceDescriptorIndexingFeatures(const VkPhysicalDeviceDescriptorIndexingFeatures* in_struct);
    safe_VkPhysicalDeviceDescriptorIndexingFeatures(const safe_VkPhysicalDeviceDescriptorIndexingFeatures& copy_src);
    safe_VkPhysicalDeviceDescriptorIndexingFeatures& operator=(const safe_VkPhysicalDeviceDescriptorIndexingFeatures& copy_src);
    safe_VkPhysicalDeviceDescriptorIndexingFeatures();
    ~safe_VkPhysicalDeviceDescriptorIndexingFeatures();
    void initialize(const VkPhysicalDeviceDescriptorIndexingFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceDescriptorIndexingFeatures* copy_src);
    VkPhysicalDeviceDescriptorIndexingFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceDescriptorIndexingFeatures *>(this); }
    VkPhysicalDeviceDescriptorIndexingFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDescriptorIndexingFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceDescriptorIndexingProperties {
    VkStructureType sType;
    void* pNext;
    uint32_t maxUpdateAfterBindDescriptorsInAllPools;
    VkBool32 shaderUniformBufferArrayNonUniformIndexingNative;
    VkBool32 shaderSampledImageArrayNonUniformIndexingNative;
    VkBool32 shaderStorageBufferArrayNonUniformIndexingNative;
    VkBool32 shaderStorageImageArrayNonUniformIndexingNative;
    VkBool32 shaderInputAttachmentArrayNonUniformIndexingNative;
    VkBool32 robustBufferAccessUpdateAfterBind;
    VkBool32 quadDivergentImplicitLod;
    uint32_t maxPerStageDescriptorUpdateAfterBindSamplers;
    uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers;
    uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages;
    uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages;
    uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments;
    uint32_t maxPerStageUpdateAfterBindResources;
    uint32_t maxDescriptorSetUpdateAfterBindSamplers;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers;
    uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers;
    uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
    uint32_t maxDescriptorSetUpdateAfterBindSampledImages;
    uint32_t maxDescriptorSetUpdateAfterBindStorageImages;
    uint32_t maxDescriptorSetUpdateAfterBindInputAttachments;
    safe_VkPhysicalDeviceDescriptorIndexingProperties(const VkPhysicalDeviceDescriptorIndexingProperties* in_struct);
    safe_VkPhysicalDeviceDescriptorIndexingProperties(const safe_VkPhysicalDeviceDescriptorIndexingProperties& copy_src);
    safe_VkPhysicalDeviceDescriptorIndexingProperties& operator=(const safe_VkPhysicalDeviceDescriptorIndexingProperties& copy_src);
    safe_VkPhysicalDeviceDescriptorIndexingProperties();
    ~safe_VkPhysicalDeviceDescriptorIndexingProperties();
    void initialize(const VkPhysicalDeviceDescriptorIndexingProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceDescriptorIndexingProperties* copy_src);
    VkPhysicalDeviceDescriptorIndexingProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceDescriptorIndexingProperties *>(this); }
    VkPhysicalDeviceDescriptorIndexingProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDescriptorIndexingProperties const *>(this); }
};

struct safe_VkDescriptorSetVariableDescriptorCountAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t descriptorSetCount;
    const uint32_t* pDescriptorCounts;
    safe_VkDescriptorSetVariableDescriptorCountAllocateInfo(const VkDescriptorSetVariableDescriptorCountAllocateInfo* in_struct);
    safe_VkDescriptorSetVariableDescriptorCountAllocateInfo(const safe_VkDescriptorSetVariableDescriptorCountAllocateInfo& copy_src);
    safe_VkDescriptorSetVariableDescriptorCountAllocateInfo& operator=(const safe_VkDescriptorSetVariableDescriptorCountAllocateInfo& copy_src);
    safe_VkDescriptorSetVariableDescriptorCountAllocateInfo();
    ~safe_VkDescriptorSetVariableDescriptorCountAllocateInfo();
    void initialize(const VkDescriptorSetVariableDescriptorCountAllocateInfo* in_struct);
    void initialize(const safe_VkDescriptorSetVariableDescriptorCountAllocateInfo* copy_src);
    VkDescriptorSetVariableDescriptorCountAllocateInfo *ptr() { return reinterpret_cast<VkDescriptorSetVariableDescriptorCountAllocateInfo *>(this); }
    VkDescriptorSetVariableDescriptorCountAllocateInfo const *ptr() const { return reinterpret_cast<VkDescriptorSetVariableDescriptorCountAllocateInfo const *>(this); }
};

struct safe_VkDescriptorSetVariableDescriptorCountLayoutSupport {
    VkStructureType sType;
    void* pNext;
    uint32_t maxVariableDescriptorCount;
    safe_VkDescriptorSetVariableDescriptorCountLayoutSupport(const VkDescriptorSetVariableDescriptorCountLayoutSupport* in_struct);
    safe_VkDescriptorSetVariableDescriptorCountLayoutSupport(const safe_VkDescriptorSetVariableDescriptorCountLayoutSupport& copy_src);
    safe_VkDescriptorSetVariableDescriptorCountLayoutSupport& operator=(const safe_VkDescriptorSetVariableDescriptorCountLayoutSupport& copy_src);
    safe_VkDescriptorSetVariableDescriptorCountLayoutSupport();
    ~safe_VkDescriptorSetVariableDescriptorCountLayoutSupport();
    void initialize(const VkDescriptorSetVariableDescriptorCountLayoutSupport* in_struct);
    void initialize(const safe_VkDescriptorSetVariableDescriptorCountLayoutSupport* copy_src);
    VkDescriptorSetVariableDescriptorCountLayoutSupport *ptr() { return reinterpret_cast<VkDescriptorSetVariableDescriptorCountLayoutSupport *>(this); }
    VkDescriptorSetVariableDescriptorCountLayoutSupport const *ptr() const { return reinterpret_cast<VkDescriptorSetVariableDescriptorCountLayoutSupport const *>(this); }
};

struct safe_VkSubpassDescriptionDepthStencilResolve {
    VkStructureType sType;
    const void* pNext;
    VkResolveModeFlagBits depthResolveMode;
    VkResolveModeFlagBits stencilResolveMode;
    safe_VkAttachmentReference2* pDepthStencilResolveAttachment;
    safe_VkSubpassDescriptionDepthStencilResolve(const VkSubpassDescriptionDepthStencilResolve* in_struct);
    safe_VkSubpassDescriptionDepthStencilResolve(const safe_VkSubpassDescriptionDepthStencilResolve& copy_src);
    safe_VkSubpassDescriptionDepthStencilResolve& operator=(const safe_VkSubpassDescriptionDepthStencilResolve& copy_src);
    safe_VkSubpassDescriptionDepthStencilResolve();
    ~safe_VkSubpassDescriptionDepthStencilResolve();
    void initialize(const VkSubpassDescriptionDepthStencilResolve* in_struct);
    void initialize(const safe_VkSubpassDescriptionDepthStencilResolve* copy_src);
    VkSubpassDescriptionDepthStencilResolve *ptr() { return reinterpret_cast<VkSubpassDescriptionDepthStencilResolve *>(this); }
    VkSubpassDescriptionDepthStencilResolve const *ptr() const { return reinterpret_cast<VkSubpassDescriptionDepthStencilResolve const *>(this); }
};

struct safe_VkPhysicalDeviceDepthStencilResolveProperties {
    VkStructureType sType;
    void* pNext;
    VkResolveModeFlags supportedDepthResolveModes;
    VkResolveModeFlags supportedStencilResolveModes;
    VkBool32 independentResolveNone;
    VkBool32 independentResolve;
    safe_VkPhysicalDeviceDepthStencilResolveProperties(const VkPhysicalDeviceDepthStencilResolveProperties* in_struct);
    safe_VkPhysicalDeviceDepthStencilResolveProperties(const safe_VkPhysicalDeviceDepthStencilResolveProperties& copy_src);
    safe_VkPhysicalDeviceDepthStencilResolveProperties& operator=(const safe_VkPhysicalDeviceDepthStencilResolveProperties& copy_src);
    safe_VkPhysicalDeviceDepthStencilResolveProperties();
    ~safe_VkPhysicalDeviceDepthStencilResolveProperties();
    void initialize(const VkPhysicalDeviceDepthStencilResolveProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceDepthStencilResolveProperties* copy_src);
    VkPhysicalDeviceDepthStencilResolveProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceDepthStencilResolveProperties *>(this); }
    VkPhysicalDeviceDepthStencilResolveProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDepthStencilResolveProperties const *>(this); }
};

struct safe_VkPhysicalDeviceScalarBlockLayoutFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 scalarBlockLayout;
    safe_VkPhysicalDeviceScalarBlockLayoutFeatures(const VkPhysicalDeviceScalarBlockLayoutFeatures* in_struct);
    safe_VkPhysicalDeviceScalarBlockLayoutFeatures(const safe_VkPhysicalDeviceScalarBlockLayoutFeatures& copy_src);
    safe_VkPhysicalDeviceScalarBlockLayoutFeatures& operator=(const safe_VkPhysicalDeviceScalarBlockLayoutFeatures& copy_src);
    safe_VkPhysicalDeviceScalarBlockLayoutFeatures();
    ~safe_VkPhysicalDeviceScalarBlockLayoutFeatures();
    void initialize(const VkPhysicalDeviceScalarBlockLayoutFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceScalarBlockLayoutFeatures* copy_src);
    VkPhysicalDeviceScalarBlockLayoutFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceScalarBlockLayoutFeatures *>(this); }
    VkPhysicalDeviceScalarBlockLayoutFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceScalarBlockLayoutFeatures const *>(this); }
};

struct safe_VkImageStencilUsageCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageUsageFlags stencilUsage;
    safe_VkImageStencilUsageCreateInfo(const VkImageStencilUsageCreateInfo* in_struct);
    safe_VkImageStencilUsageCreateInfo(const safe_VkImageStencilUsageCreateInfo& copy_src);
    safe_VkImageStencilUsageCreateInfo& operator=(const safe_VkImageStencilUsageCreateInfo& copy_src);
    safe_VkImageStencilUsageCreateInfo();
    ~safe_VkImageStencilUsageCreateInfo();
    void initialize(const VkImageStencilUsageCreateInfo* in_struct);
    void initialize(const safe_VkImageStencilUsageCreateInfo* copy_src);
    VkImageStencilUsageCreateInfo *ptr() { return reinterpret_cast<VkImageStencilUsageCreateInfo *>(this); }
    VkImageStencilUsageCreateInfo const *ptr() const { return reinterpret_cast<VkImageStencilUsageCreateInfo const *>(this); }
};

struct safe_VkSamplerReductionModeCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkSamplerReductionMode reductionMode;
    safe_VkSamplerReductionModeCreateInfo(const VkSamplerReductionModeCreateInfo* in_struct);
    safe_VkSamplerReductionModeCreateInfo(const safe_VkSamplerReductionModeCreateInfo& copy_src);
    safe_VkSamplerReductionModeCreateInfo& operator=(const safe_VkSamplerReductionModeCreateInfo& copy_src);
    safe_VkSamplerReductionModeCreateInfo();
    ~safe_VkSamplerReductionModeCreateInfo();
    void initialize(const VkSamplerReductionModeCreateInfo* in_struct);
    void initialize(const safe_VkSamplerReductionModeCreateInfo* copy_src);
    VkSamplerReductionModeCreateInfo *ptr() { return reinterpret_cast<VkSamplerReductionModeCreateInfo *>(this); }
    VkSamplerReductionModeCreateInfo const *ptr() const { return reinterpret_cast<VkSamplerReductionModeCreateInfo const *>(this); }
};

struct safe_VkPhysicalDeviceSamplerFilterMinmaxProperties {
    VkStructureType sType;
    void* pNext;
    VkBool32 filterMinmaxSingleComponentFormats;
    VkBool32 filterMinmaxImageComponentMapping;
    safe_VkPhysicalDeviceSamplerFilterMinmaxProperties(const VkPhysicalDeviceSamplerFilterMinmaxProperties* in_struct);
    safe_VkPhysicalDeviceSamplerFilterMinmaxProperties(const safe_VkPhysicalDeviceSamplerFilterMinmaxProperties& copy_src);
    safe_VkPhysicalDeviceSamplerFilterMinmaxProperties& operator=(const safe_VkPhysicalDeviceSamplerFilterMinmaxProperties& copy_src);
    safe_VkPhysicalDeviceSamplerFilterMinmaxProperties();
    ~safe_VkPhysicalDeviceSamplerFilterMinmaxProperties();
    void initialize(const VkPhysicalDeviceSamplerFilterMinmaxProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceSamplerFilterMinmaxProperties* copy_src);
    VkPhysicalDeviceSamplerFilterMinmaxProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceSamplerFilterMinmaxProperties *>(this); }
    VkPhysicalDeviceSamplerFilterMinmaxProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSamplerFilterMinmaxProperties const *>(this); }
};

struct safe_VkPhysicalDeviceVulkanMemoryModelFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 vulkanMemoryModel;
    VkBool32 vulkanMemoryModelDeviceScope;
    VkBool32 vulkanMemoryModelAvailabilityVisibilityChains;
    safe_VkPhysicalDeviceVulkanMemoryModelFeatures(const VkPhysicalDeviceVulkanMemoryModelFeatures* in_struct);
    safe_VkPhysicalDeviceVulkanMemoryModelFeatures(const safe_VkPhysicalDeviceVulkanMemoryModelFeatures& copy_src);
    safe_VkPhysicalDeviceVulkanMemoryModelFeatures& operator=(const safe_VkPhysicalDeviceVulkanMemoryModelFeatures& copy_src);
    safe_VkPhysicalDeviceVulkanMemoryModelFeatures();
    ~safe_VkPhysicalDeviceVulkanMemoryModelFeatures();
    void initialize(const VkPhysicalDeviceVulkanMemoryModelFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceVulkanMemoryModelFeatures* copy_src);
    VkPhysicalDeviceVulkanMemoryModelFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceVulkanMemoryModelFeatures *>(this); }
    VkPhysicalDeviceVulkanMemoryModelFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVulkanMemoryModelFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceImagelessFramebufferFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 imagelessFramebuffer;
    safe_VkPhysicalDeviceImagelessFramebufferFeatures(const VkPhysicalDeviceImagelessFramebufferFeatures* in_struct);
    safe_VkPhysicalDeviceImagelessFramebufferFeatures(const safe_VkPhysicalDeviceImagelessFramebufferFeatures& copy_src);
    safe_VkPhysicalDeviceImagelessFramebufferFeatures& operator=(const safe_VkPhysicalDeviceImagelessFramebufferFeatures& copy_src);
    safe_VkPhysicalDeviceImagelessFramebufferFeatures();
    ~safe_VkPhysicalDeviceImagelessFramebufferFeatures();
    void initialize(const VkPhysicalDeviceImagelessFramebufferFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceImagelessFramebufferFeatures* copy_src);
    VkPhysicalDeviceImagelessFramebufferFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceImagelessFramebufferFeatures *>(this); }
    VkPhysicalDeviceImagelessFramebufferFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceImagelessFramebufferFeatures const *>(this); }
};

struct safe_VkFramebufferAttachmentImageInfo {
    VkStructureType sType;
    const void* pNext;
    VkImageCreateFlags flags;
    VkImageUsageFlags usage;
    uint32_t width;
    uint32_t height;
    uint32_t layerCount;
    uint32_t viewFormatCount;
    const VkFormat* pViewFormats;
    safe_VkFramebufferAttachmentImageInfo(const VkFramebufferAttachmentImageInfo* in_struct);
    safe_VkFramebufferAttachmentImageInfo(const safe_VkFramebufferAttachmentImageInfo& copy_src);
    safe_VkFramebufferAttachmentImageInfo& operator=(const safe_VkFramebufferAttachmentImageInfo& copy_src);
    safe_VkFramebufferAttachmentImageInfo();
    ~safe_VkFramebufferAttachmentImageInfo();
    void initialize(const VkFramebufferAttachmentImageInfo* in_struct);
    void initialize(const safe_VkFramebufferAttachmentImageInfo* copy_src);
    VkFramebufferAttachmentImageInfo *ptr() { return reinterpret_cast<VkFramebufferAttachmentImageInfo *>(this); }
    VkFramebufferAttachmentImageInfo const *ptr() const { return reinterpret_cast<VkFramebufferAttachmentImageInfo const *>(this); }
};

struct safe_VkFramebufferAttachmentsCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t attachmentImageInfoCount;
    safe_VkFramebufferAttachmentImageInfo* pAttachmentImageInfos;
    safe_VkFramebufferAttachmentsCreateInfo(const VkFramebufferAttachmentsCreateInfo* in_struct);
    safe_VkFramebufferAttachmentsCreateInfo(const safe_VkFramebufferAttachmentsCreateInfo& copy_src);
    safe_VkFramebufferAttachmentsCreateInfo& operator=(const safe_VkFramebufferAttachmentsCreateInfo& copy_src);
    safe_VkFramebufferAttachmentsCreateInfo();
    ~safe_VkFramebufferAttachmentsCreateInfo();
    void initialize(const VkFramebufferAttachmentsCreateInfo* in_struct);
    void initialize(const safe_VkFramebufferAttachmentsCreateInfo* copy_src);
    VkFramebufferAttachmentsCreateInfo *ptr() { return reinterpret_cast<VkFramebufferAttachmentsCreateInfo *>(this); }
    VkFramebufferAttachmentsCreateInfo const *ptr() const { return reinterpret_cast<VkFramebufferAttachmentsCreateInfo const *>(this); }
};

struct safe_VkRenderPassAttachmentBeginInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t attachmentCount;
    VkImageView* pAttachments;
    safe_VkRenderPassAttachmentBeginInfo(const VkRenderPassAttachmentBeginInfo* in_struct);
    safe_VkRenderPassAttachmentBeginInfo(const safe_VkRenderPassAttachmentBeginInfo& copy_src);
    safe_VkRenderPassAttachmentBeginInfo& operator=(const safe_VkRenderPassAttachmentBeginInfo& copy_src);
    safe_VkRenderPassAttachmentBeginInfo();
    ~safe_VkRenderPassAttachmentBeginInfo();
    void initialize(const VkRenderPassAttachmentBeginInfo* in_struct);
    void initialize(const safe_VkRenderPassAttachmentBeginInfo* copy_src);
    VkRenderPassAttachmentBeginInfo *ptr() { return reinterpret_cast<VkRenderPassAttachmentBeginInfo *>(this); }
    VkRenderPassAttachmentBeginInfo const *ptr() const { return reinterpret_cast<VkRenderPassAttachmentBeginInfo const *>(this); }
};

struct safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 uniformBufferStandardLayout;
    safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* in_struct);
    safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(const safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures& copy_src);
    safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures& operator=(const safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures& copy_src);
    safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures();
    ~safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures();
    void initialize(const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* copy_src);
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceUniformBufferStandardLayoutFeatures *>(this); }
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceUniformBufferStandardLayoutFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderSubgroupExtendedTypes;
    safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* in_struct);
    safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(const safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& copy_src);
    safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& operator=(const safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& copy_src);
    safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures();
    ~safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures();
    void initialize(const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* copy_src);
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *>(this); }
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 separateDepthStencilLayouts;
    safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* in_struct);
    safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(const safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& copy_src);
    safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& operator=(const safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& copy_src);
    safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures();
    ~safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures();
    void initialize(const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* copy_src);
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *>(this); }
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures const *>(this); }
};

struct safe_VkAttachmentReferenceStencilLayout {
    VkStructureType sType;
    void* pNext;
    VkImageLayout stencilLayout;
    safe_VkAttachmentReferenceStencilLayout(const VkAttachmentReferenceStencilLayout* in_struct);
    safe_VkAttachmentReferenceStencilLayout(const safe_VkAttachmentReferenceStencilLayout& copy_src);
    safe_VkAttachmentReferenceStencilLayout& operator=(const safe_VkAttachmentReferenceStencilLayout& copy_src);
    safe_VkAttachmentReferenceStencilLayout();
    ~safe_VkAttachmentReferenceStencilLayout();
    void initialize(const VkAttachmentReferenceStencilLayout* in_struct);
    void initialize(const safe_VkAttachmentReferenceStencilLayout* copy_src);
    VkAttachmentReferenceStencilLayout *ptr() { return reinterpret_cast<VkAttachmentReferenceStencilLayout *>(this); }
    VkAttachmentReferenceStencilLayout const *ptr() const { return reinterpret_cast<VkAttachmentReferenceStencilLayout const *>(this); }
};

struct safe_VkAttachmentDescriptionStencilLayout {
    VkStructureType sType;
    void* pNext;
    VkImageLayout stencilInitialLayout;
    VkImageLayout stencilFinalLayout;
    safe_VkAttachmentDescriptionStencilLayout(const VkAttachmentDescriptionStencilLayout* in_struct);
    safe_VkAttachmentDescriptionStencilLayout(const safe_VkAttachmentDescriptionStencilLayout& copy_src);
    safe_VkAttachmentDescriptionStencilLayout& operator=(const safe_VkAttachmentDescriptionStencilLayout& copy_src);
    safe_VkAttachmentDescriptionStencilLayout();
    ~safe_VkAttachmentDescriptionStencilLayout();
    void initialize(const VkAttachmentDescriptionStencilLayout* in_struct);
    void initialize(const safe_VkAttachmentDescriptionStencilLayout* copy_src);
    VkAttachmentDescriptionStencilLayout *ptr() { return reinterpret_cast<VkAttachmentDescriptionStencilLayout *>(this); }
    VkAttachmentDescriptionStencilLayout const *ptr() const { return reinterpret_cast<VkAttachmentDescriptionStencilLayout const *>(this); }
};

struct safe_VkPhysicalDeviceHostQueryResetFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 hostQueryReset;
    safe_VkPhysicalDeviceHostQueryResetFeatures(const VkPhysicalDeviceHostQueryResetFeatures* in_struct);
    safe_VkPhysicalDeviceHostQueryResetFeatures(const safe_VkPhysicalDeviceHostQueryResetFeatures& copy_src);
    safe_VkPhysicalDeviceHostQueryResetFeatures& operator=(const safe_VkPhysicalDeviceHostQueryResetFeatures& copy_src);
    safe_VkPhysicalDeviceHostQueryResetFeatures();
    ~safe_VkPhysicalDeviceHostQueryResetFeatures();
    void initialize(const VkPhysicalDeviceHostQueryResetFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceHostQueryResetFeatures* copy_src);
    VkPhysicalDeviceHostQueryResetFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceHostQueryResetFeatures *>(this); }
    VkPhysicalDeviceHostQueryResetFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceHostQueryResetFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceTimelineSemaphoreFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 timelineSemaphore;
    safe_VkPhysicalDeviceTimelineSemaphoreFeatures(const VkPhysicalDeviceTimelineSemaphoreFeatures* in_struct);
    safe_VkPhysicalDeviceTimelineSemaphoreFeatures(const safe_VkPhysicalDeviceTimelineSemaphoreFeatures& copy_src);
    safe_VkPhysicalDeviceTimelineSemaphoreFeatures& operator=(const safe_VkPhysicalDeviceTimelineSemaphoreFeatures& copy_src);
    safe_VkPhysicalDeviceTimelineSemaphoreFeatures();
    ~safe_VkPhysicalDeviceTimelineSemaphoreFeatures();
    void initialize(const VkPhysicalDeviceTimelineSemaphoreFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceTimelineSemaphoreFeatures* copy_src);
    VkPhysicalDeviceTimelineSemaphoreFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreFeatures *>(this); }
    VkPhysicalDeviceTimelineSemaphoreFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreFeatures const *>(this); }
};

struct safe_VkPhysicalDeviceTimelineSemaphoreProperties {
    VkStructureType sType;
    void* pNext;
    uint64_t maxTimelineSemaphoreValueDifference;
    safe_VkPhysicalDeviceTimelineSemaphoreProperties(const VkPhysicalDeviceTimelineSemaphoreProperties* in_struct);
    safe_VkPhysicalDeviceTimelineSemaphoreProperties(const safe_VkPhysicalDeviceTimelineSemaphoreProperties& copy_src);
    safe_VkPhysicalDeviceTimelineSemaphoreProperties& operator=(const safe_VkPhysicalDeviceTimelineSemaphoreProperties& copy_src);
    safe_VkPhysicalDeviceTimelineSemaphoreProperties();
    ~safe_VkPhysicalDeviceTimelineSemaphoreProperties();
    void initialize(const VkPhysicalDeviceTimelineSemaphoreProperties* in_struct);
    void initialize(const safe_VkPhysicalDeviceTimelineSemaphoreProperties* copy_src);
    VkPhysicalDeviceTimelineSemaphoreProperties *ptr() { return reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreProperties *>(this); }
    VkPhysicalDeviceTimelineSemaphoreProperties const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTimelineSemaphoreProperties const *>(this); }
};

struct safe_VkSemaphoreTypeCreateInfo {
    VkStructureType sType;
    const void* pNext;
    VkSemaphoreType semaphoreType;
    uint64_t initialValue;
    safe_VkSemaphoreTypeCreateInfo(const VkSemaphoreTypeCreateInfo* in_struct);
    safe_VkSemaphoreTypeCreateInfo(const safe_VkSemaphoreTypeCreateInfo& copy_src);
    safe_VkSemaphoreTypeCreateInfo& operator=(const safe_VkSemaphoreTypeCreateInfo& copy_src);
    safe_VkSemaphoreTypeCreateInfo();
    ~safe_VkSemaphoreTypeCreateInfo();
    void initialize(const VkSemaphoreTypeCreateInfo* in_struct);
    void initialize(const safe_VkSemaphoreTypeCreateInfo* copy_src);
    VkSemaphoreTypeCreateInfo *ptr() { return reinterpret_cast<VkSemaphoreTypeCreateInfo *>(this); }
    VkSemaphoreTypeCreateInfo const *ptr() const { return reinterpret_cast<VkSemaphoreTypeCreateInfo const *>(this); }
};

struct safe_VkTimelineSemaphoreSubmitInfo {
    VkStructureType sType;
    const void* pNext;
    uint32_t waitSemaphoreValueCount;
    const uint64_t* pWaitSemaphoreValues;
    uint32_t signalSemaphoreValueCount;
    const uint64_t* pSignalSemaphoreValues;
    safe_VkTimelineSemaphoreSubmitInfo(const VkTimelineSemaphoreSubmitInfo* in_struct);
    safe_VkTimelineSemaphoreSubmitInfo(const safe_VkTimelineSemaphoreSubmitInfo& copy_src);
    safe_VkTimelineSemaphoreSubmitInfo& operator=(const safe_VkTimelineSemaphoreSubmitInfo& copy_src);
    safe_VkTimelineSemaphoreSubmitInfo();
    ~safe_VkTimelineSemaphoreSubmitInfo();
    void initialize(const VkTimelineSemaphoreSubmitInfo* in_struct);
    void initialize(const safe_VkTimelineSemaphoreSubmitInfo* copy_src);
    VkTimelineSemaphoreSubmitInfo *ptr() { return reinterpret_cast<VkTimelineSemaphoreSubmitInfo *>(this); }
    VkTimelineSemaphoreSubmitInfo const *ptr() const { return reinterpret_cast<VkTimelineSemaphoreSubmitInfo const *>(this); }
};

struct safe_VkSemaphoreWaitInfo {
    VkStructureType sType;
    const void* pNext;
    VkSemaphoreWaitFlags flags;
    uint32_t semaphoreCount;
    VkSemaphore* pSemaphores;
    const uint64_t* pValues;
    safe_VkSemaphoreWaitInfo(const VkSemaphoreWaitInfo* in_struct);
    safe_VkSemaphoreWaitInfo(const safe_VkSemaphoreWaitInfo& copy_src);
    safe_VkSemaphoreWaitInfo& operator=(const safe_VkSemaphoreWaitInfo& copy_src);
    safe_VkSemaphoreWaitInfo();
    ~safe_VkSemaphoreWaitInfo();
    void initialize(const VkSemaphoreWaitInfo* in_struct);
    void initialize(const safe_VkSemaphoreWaitInfo* copy_src);
    VkSemaphoreWaitInfo *ptr() { return reinterpret_cast<VkSemaphoreWaitInfo *>(this); }
    VkSemaphoreWaitInfo const *ptr() const { return reinterpret_cast<VkSemaphoreWaitInfo const *>(this); }
};

struct safe_VkSemaphoreSignalInfo {
    VkStructureType sType;
    const void* pNext;
    VkSemaphore semaphore;
    uint64_t value;
    safe_VkSemaphoreSignalInfo(const VkSemaphoreSignalInfo* in_struct);
    safe_VkSemaphoreSignalInfo(const safe_VkSemaphoreSignalInfo& copy_src);
    safe_VkSemaphoreSignalInfo& operator=(const safe_VkSemaphoreSignalInfo& copy_src);
    safe_VkSemaphoreSignalInfo();
    ~safe_VkSemaphoreSignalInfo();
    void initialize(const VkSemaphoreSignalInfo* in_struct);
    void initialize(const safe_VkSemaphoreSignalInfo* copy_src);
    VkSemaphoreSignalInfo *ptr() { return reinterpret_cast<VkSemaphoreSignalInfo *>(this); }
    VkSemaphoreSignalInfo const *ptr() const { return reinterpret_cast<VkSemaphoreSignalInfo const *>(this); }
};

struct safe_VkPhysicalDeviceBufferDeviceAddressFeatures {
    VkStructureType sType;
    void* pNext;
    VkBool32 bufferDeviceAddress;
    VkBool32 bufferDeviceAddressCaptureReplay;
    VkBool32 bufferDeviceAddressMultiDevice;
    safe_VkPhysicalDeviceBufferDeviceAddressFeatures(const VkPhysicalDeviceBufferDeviceAddressFeatures* in_struct);
    safe_VkPhysicalDeviceBufferDeviceAddressFeatures(const safe_VkPhysicalDeviceBufferDeviceAddressFeatures& copy_src);
    safe_VkPhysicalDeviceBufferDeviceAddressFeatures& operator=(const safe_VkPhysicalDeviceBufferDeviceAddressFeatures& copy_src);
    safe_VkPhysicalDeviceBufferDeviceAddressFeatures();
    ~safe_VkPhysicalDeviceBufferDeviceAddressFeatures();
    void initialize(const VkPhysicalDeviceBufferDeviceAddressFeatures* in_struct);
    void initialize(const safe_VkPhysicalDeviceBufferDeviceAddressFeatures* copy_src);
    VkPhysicalDeviceBufferDeviceAddressFeatures *ptr() { return reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures *>(this); }
    VkPhysicalDeviceBufferDeviceAddressFeatures const *ptr() const { return reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeatures const *>(this); }
};

struct safe_VkBufferDeviceAddressInfo {
    VkStructureType sType;
    const void* pNext;
    VkBuffer buffer;
    safe_VkBufferDeviceAddressInfo(const VkBufferDeviceAddressInfo* in_struct);
    safe_VkBufferDeviceAddressInfo(const safe_VkBufferDeviceAddressInfo& copy_src);
    safe_VkBufferDeviceAddressInfo& operator=(const safe_VkBufferDeviceAddressInfo& copy_src);
    safe_VkBufferDeviceAddressInfo();
    ~safe_VkBufferDeviceAddressInfo();
    void initialize(const VkBufferDeviceAddressInfo* in_struct);
    void initialize(const safe_VkBufferDeviceAddressInfo* copy_src);
    VkBufferDeviceAddressInfo *ptr() { return reinterpret_cast<VkBufferDeviceAddressInfo *>(this); }
    VkBufferDeviceAddressInfo const *ptr() const { return reinterpret_cast<VkBufferDeviceAddressInfo const *>(this); }
};

struct safe_VkBufferOpaqueCaptureAddressCreateInfo {
    VkStructureType sType;
    const void* pNext;
    uint64_t opaqueCaptureAddress;
    safe_VkBufferOpaqueCaptureAddressCreateInfo(const VkBufferOpaqueCaptureAddressCreateInfo* in_struct);
    safe_VkBufferOpaqueCaptureAddressCreateInfo(const safe_VkBufferOpaqueCaptureAddressCreateInfo& copy_src);
    safe_VkBufferOpaqueCaptureAddressCreateInfo& operator=(const safe_VkBufferOpaqueCaptureAddressCreateInfo& copy_src);
    safe_VkBufferOpaqueCaptureAddressCreateInfo();
    ~safe_VkBufferOpaqueCaptureAddressCreateInfo();
    void initialize(const VkBufferOpaqueCaptureAddressCreateInfo* in_struct);
    void initialize(const safe_VkBufferOpaqueCaptureAddressCreateInfo* copy_src);
    VkBufferOpaqueCaptureAddressCreateInfo *ptr() { return reinterpret_cast<VkBufferOpaqueCaptureAddressCreateInfo *>(this); }
    VkBufferOpaqueCaptureAddressCreateInfo const *ptr() const { return reinterpret_cast<VkBufferOpaqueCaptureAddressCreateInfo const *>(this); }
};

struct safe_VkMemoryOpaqueCaptureAddressAllocateInfo {
    VkStructureType sType;
    const void* pNext;
    uint64_t opaqueCaptureAddress;
    safe_VkMemoryOpaqueCaptureAddressAllocateInfo(const VkMemoryOpaqueCaptureAddressAllocateInfo* in_struct);
    safe_VkMemoryOpaqueCaptureAddressAllocateInfo(const safe_VkMemoryOpaqueCaptureAddressAllocateInfo& copy_src);
    safe_VkMemoryOpaqueCaptureAddressAllocateInfo& operator=(const safe_VkMemoryOpaqueCaptureAddressAllocateInfo& copy_src);
    safe_VkMemoryOpaqueCaptureAddressAllocateInfo();
    ~safe_VkMemoryOpaqueCaptureAddressAllocateInfo();
    void initialize(const VkMemoryOpaqueCaptureAddressAllocateInfo* in_struct);
    void initialize(const safe_VkMemoryOpaqueCaptureAddressAllocateInfo* copy_src);
    VkMemoryOpaqueCaptureAddressAllocateInfo *ptr() { return reinterpret_cast<VkMemoryOpaqueCaptureAddressAllocateInfo *>(this); }
    VkMemoryOpaqueCaptureAddressAllocateInfo const *ptr() const { return reinterpret_cast<VkMemoryOpaqueCaptureAddressAllocateInfo const *>(this); }
};

struct safe_VkDeviceMemoryOpaqueCaptureAddressInfo {
    VkStructureType sType;
    const void* pNext;
    VkDeviceMemory memory;
    safe_VkDeviceMemoryOpaqueCaptureAddressInfo(const VkDeviceMemoryOpaqueCaptureAddressInfo* in_struct);
    safe_VkDeviceMemoryOpaqueCaptureAddressInfo(const safe_VkDeviceMemoryOpaqueCaptureAddressInfo& copy_src);
    safe_VkDeviceMemoryOpaqueCaptureAddressInfo& operator=(const safe_VkDeviceMemoryOpaqueCaptureAddressInfo& copy_src);
    safe_VkDeviceMemoryOpaqueCaptureAddressInfo();
    ~safe_VkDeviceMemoryOpaqueCaptureAddressInfo();
    void initialize(const VkDeviceMemoryOpaqueCaptureAddressInfo* in_struct);
    void initialize(const safe_VkDeviceMemoryOpaqueCaptureAddressInfo* copy_src);
    VkDeviceMemoryOpaqueCaptureAddressInfo *ptr() { return reinterpret_cast<VkDeviceMemoryOpaqueCaptureAddressInfo *>(this); }
    VkDeviceMemoryOpaqueCaptureAddressInfo const *ptr() const { return reinterpret_cast<VkDeviceMemoryOpaqueCaptureAddressInfo const *>(this); }
};

struct safe_VkSwapchainCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSwapchainCreateFlagsKHR flags;
    VkSurfaceKHR surface;
    uint32_t minImageCount;
    VkFormat imageFormat;
    VkColorSpaceKHR imageColorSpace;
    VkExtent2D imageExtent;
    uint32_t imageArrayLayers;
    VkImageUsageFlags imageUsage;
    VkSharingMode imageSharingMode;
    uint32_t queueFamilyIndexCount;
    const uint32_t* pQueueFamilyIndices;
    VkSurfaceTransformFlagBitsKHR preTransform;
    VkCompositeAlphaFlagBitsKHR compositeAlpha;
    VkPresentModeKHR presentMode;
    VkBool32 clipped;
    VkSwapchainKHR oldSwapchain;
    safe_VkSwapchainCreateInfoKHR(const VkSwapchainCreateInfoKHR* in_struct);
    safe_VkSwapchainCreateInfoKHR(const safe_VkSwapchainCreateInfoKHR& copy_src);
    safe_VkSwapchainCreateInfoKHR& operator=(const safe_VkSwapchainCreateInfoKHR& copy_src);
    safe_VkSwapchainCreateInfoKHR();
    ~safe_VkSwapchainCreateInfoKHR();
    void initialize(const VkSwapchainCreateInfoKHR* in_struct);
    void initialize(const safe_VkSwapchainCreateInfoKHR* copy_src);
    VkSwapchainCreateInfoKHR *ptr() { return reinterpret_cast<VkSwapchainCreateInfoKHR *>(this); }
    VkSwapchainCreateInfoKHR const *ptr() const { return reinterpret_cast<VkSwapchainCreateInfoKHR const *>(this); }
};

struct safe_VkPresentInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t waitSemaphoreCount;
    VkSemaphore* pWaitSemaphores;
    uint32_t swapchainCount;
    VkSwapchainKHR* pSwapchains;
    const uint32_t* pImageIndices;
    VkResult* pResults;
    safe_VkPresentInfoKHR(const VkPresentInfoKHR* in_struct);
    safe_VkPresentInfoKHR(const safe_VkPresentInfoKHR& copy_src);
    safe_VkPresentInfoKHR& operator=(const safe_VkPresentInfoKHR& copy_src);
    safe_VkPresentInfoKHR();
    ~safe_VkPresentInfoKHR();
    void initialize(const VkPresentInfoKHR* in_struct);
    void initialize(const safe_VkPresentInfoKHR* copy_src);
    VkPresentInfoKHR *ptr() { return reinterpret_cast<VkPresentInfoKHR *>(this); }
    VkPresentInfoKHR const *ptr() const { return reinterpret_cast<VkPresentInfoKHR const *>(this); }
};

struct safe_VkImageSwapchainCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSwapchainKHR swapchain;
    safe_VkImageSwapchainCreateInfoKHR(const VkImageSwapchainCreateInfoKHR* in_struct);
    safe_VkImageSwapchainCreateInfoKHR(const safe_VkImageSwapchainCreateInfoKHR& copy_src);
    safe_VkImageSwapchainCreateInfoKHR& operator=(const safe_VkImageSwapchainCreateInfoKHR& copy_src);
    safe_VkImageSwapchainCreateInfoKHR();
    ~safe_VkImageSwapchainCreateInfoKHR();
    void initialize(const VkImageSwapchainCreateInfoKHR* in_struct);
    void initialize(const safe_VkImageSwapchainCreateInfoKHR* copy_src);
    VkImageSwapchainCreateInfoKHR *ptr() { return reinterpret_cast<VkImageSwapchainCreateInfoKHR *>(this); }
    VkImageSwapchainCreateInfoKHR const *ptr() const { return reinterpret_cast<VkImageSwapchainCreateInfoKHR const *>(this); }
};

struct safe_VkBindImageMemorySwapchainInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSwapchainKHR swapchain;
    uint32_t imageIndex;
    safe_VkBindImageMemorySwapchainInfoKHR(const VkBindImageMemorySwapchainInfoKHR* in_struct);
    safe_VkBindImageMemorySwapchainInfoKHR(const safe_VkBindImageMemorySwapchainInfoKHR& copy_src);
    safe_VkBindImageMemorySwapchainInfoKHR& operator=(const safe_VkBindImageMemorySwapchainInfoKHR& copy_src);
    safe_VkBindImageMemorySwapchainInfoKHR();
    ~safe_VkBindImageMemorySwapchainInfoKHR();
    void initialize(const VkBindImageMemorySwapchainInfoKHR* in_struct);
    void initialize(const safe_VkBindImageMemorySwapchainInfoKHR* copy_src);
    VkBindImageMemorySwapchainInfoKHR *ptr() { return reinterpret_cast<VkBindImageMemorySwapchainInfoKHR *>(this); }
    VkBindImageMemorySwapchainInfoKHR const *ptr() const { return reinterpret_cast<VkBindImageMemorySwapchainInfoKHR const *>(this); }
};

struct safe_VkAcquireNextImageInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSwapchainKHR swapchain;
    uint64_t timeout;
    VkSemaphore semaphore;
    VkFence fence;
    uint32_t deviceMask;
    safe_VkAcquireNextImageInfoKHR(const VkAcquireNextImageInfoKHR* in_struct);
    safe_VkAcquireNextImageInfoKHR(const safe_VkAcquireNextImageInfoKHR& copy_src);
    safe_VkAcquireNextImageInfoKHR& operator=(const safe_VkAcquireNextImageInfoKHR& copy_src);
    safe_VkAcquireNextImageInfoKHR();
    ~safe_VkAcquireNextImageInfoKHR();
    void initialize(const VkAcquireNextImageInfoKHR* in_struct);
    void initialize(const safe_VkAcquireNextImageInfoKHR* copy_src);
    VkAcquireNextImageInfoKHR *ptr() { return reinterpret_cast<VkAcquireNextImageInfoKHR *>(this); }
    VkAcquireNextImageInfoKHR const *ptr() const { return reinterpret_cast<VkAcquireNextImageInfoKHR const *>(this); }
};

struct safe_VkDeviceGroupPresentCapabilitiesKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t presentMask[VK_MAX_DEVICE_GROUP_SIZE];
    VkDeviceGroupPresentModeFlagsKHR modes;
    safe_VkDeviceGroupPresentCapabilitiesKHR(const VkDeviceGroupPresentCapabilitiesKHR* in_struct);
    safe_VkDeviceGroupPresentCapabilitiesKHR(const safe_VkDeviceGroupPresentCapabilitiesKHR& copy_src);
    safe_VkDeviceGroupPresentCapabilitiesKHR& operator=(const safe_VkDeviceGroupPresentCapabilitiesKHR& copy_src);
    safe_VkDeviceGroupPresentCapabilitiesKHR();
    ~safe_VkDeviceGroupPresentCapabilitiesKHR();
    void initialize(const VkDeviceGroupPresentCapabilitiesKHR* in_struct);
    void initialize(const safe_VkDeviceGroupPresentCapabilitiesKHR* copy_src);
    VkDeviceGroupPresentCapabilitiesKHR *ptr() { return reinterpret_cast<VkDeviceGroupPresentCapabilitiesKHR *>(this); }
    VkDeviceGroupPresentCapabilitiesKHR const *ptr() const { return reinterpret_cast<VkDeviceGroupPresentCapabilitiesKHR const *>(this); }
};

struct safe_VkDeviceGroupPresentInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t swapchainCount;
    const uint32_t* pDeviceMasks;
    VkDeviceGroupPresentModeFlagBitsKHR mode;
    safe_VkDeviceGroupPresentInfoKHR(const VkDeviceGroupPresentInfoKHR* in_struct);
    safe_VkDeviceGroupPresentInfoKHR(const safe_VkDeviceGroupPresentInfoKHR& copy_src);
    safe_VkDeviceGroupPresentInfoKHR& operator=(const safe_VkDeviceGroupPresentInfoKHR& copy_src);
    safe_VkDeviceGroupPresentInfoKHR();
    ~safe_VkDeviceGroupPresentInfoKHR();
    void initialize(const VkDeviceGroupPresentInfoKHR* in_struct);
    void initialize(const safe_VkDeviceGroupPresentInfoKHR* copy_src);
    VkDeviceGroupPresentInfoKHR *ptr() { return reinterpret_cast<VkDeviceGroupPresentInfoKHR *>(this); }
    VkDeviceGroupPresentInfoKHR const *ptr() const { return reinterpret_cast<VkDeviceGroupPresentInfoKHR const *>(this); }
};

struct safe_VkDeviceGroupSwapchainCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDeviceGroupPresentModeFlagsKHR modes;
    safe_VkDeviceGroupSwapchainCreateInfoKHR(const VkDeviceGroupSwapchainCreateInfoKHR* in_struct);
    safe_VkDeviceGroupSwapchainCreateInfoKHR(const safe_VkDeviceGroupSwapchainCreateInfoKHR& copy_src);
    safe_VkDeviceGroupSwapchainCreateInfoKHR& operator=(const safe_VkDeviceGroupSwapchainCreateInfoKHR& copy_src);
    safe_VkDeviceGroupSwapchainCreateInfoKHR();
    ~safe_VkDeviceGroupSwapchainCreateInfoKHR();
    void initialize(const VkDeviceGroupSwapchainCreateInfoKHR* in_struct);
    void initialize(const safe_VkDeviceGroupSwapchainCreateInfoKHR* copy_src);
    VkDeviceGroupSwapchainCreateInfoKHR *ptr() { return reinterpret_cast<VkDeviceGroupSwapchainCreateInfoKHR *>(this); }
    VkDeviceGroupSwapchainCreateInfoKHR const *ptr() const { return reinterpret_cast<VkDeviceGroupSwapchainCreateInfoKHR const *>(this); }
};

struct safe_VkDisplayPropertiesKHR {
    VkDisplayKHR display;
    const char* displayName;
    VkExtent2D physicalDimensions;
    VkExtent2D physicalResolution;
    VkSurfaceTransformFlagsKHR supportedTransforms;
    VkBool32 planeReorderPossible;
    VkBool32 persistentContent;
    safe_VkDisplayPropertiesKHR(const VkDisplayPropertiesKHR* in_struct);
    safe_VkDisplayPropertiesKHR(const safe_VkDisplayPropertiesKHR& copy_src);
    safe_VkDisplayPropertiesKHR& operator=(const safe_VkDisplayPropertiesKHR& copy_src);
    safe_VkDisplayPropertiesKHR();
    ~safe_VkDisplayPropertiesKHR();
    void initialize(const VkDisplayPropertiesKHR* in_struct);
    void initialize(const safe_VkDisplayPropertiesKHR* copy_src);
    VkDisplayPropertiesKHR *ptr() { return reinterpret_cast<VkDisplayPropertiesKHR *>(this); }
    VkDisplayPropertiesKHR const *ptr() const { return reinterpret_cast<VkDisplayPropertiesKHR const *>(this); }
};

struct safe_VkDisplayModeCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDisplayModeCreateFlagsKHR flags;
    VkDisplayModeParametersKHR parameters;
    safe_VkDisplayModeCreateInfoKHR(const VkDisplayModeCreateInfoKHR* in_struct);
    safe_VkDisplayModeCreateInfoKHR(const safe_VkDisplayModeCreateInfoKHR& copy_src);
    safe_VkDisplayModeCreateInfoKHR& operator=(const safe_VkDisplayModeCreateInfoKHR& copy_src);
    safe_VkDisplayModeCreateInfoKHR();
    ~safe_VkDisplayModeCreateInfoKHR();
    void initialize(const VkDisplayModeCreateInfoKHR* in_struct);
    void initialize(const safe_VkDisplayModeCreateInfoKHR* copy_src);
    VkDisplayModeCreateInfoKHR *ptr() { return reinterpret_cast<VkDisplayModeCreateInfoKHR *>(this); }
    VkDisplayModeCreateInfoKHR const *ptr() const { return reinterpret_cast<VkDisplayModeCreateInfoKHR const *>(this); }
};

struct safe_VkDisplaySurfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDisplaySurfaceCreateFlagsKHR flags;
    VkDisplayModeKHR displayMode;
    uint32_t planeIndex;
    uint32_t planeStackIndex;
    VkSurfaceTransformFlagBitsKHR transform;
    float globalAlpha;
    VkDisplayPlaneAlphaFlagBitsKHR alphaMode;
    VkExtent2D imageExtent;
    safe_VkDisplaySurfaceCreateInfoKHR(const VkDisplaySurfaceCreateInfoKHR* in_struct);
    safe_VkDisplaySurfaceCreateInfoKHR(const safe_VkDisplaySurfaceCreateInfoKHR& copy_src);
    safe_VkDisplaySurfaceCreateInfoKHR& operator=(const safe_VkDisplaySurfaceCreateInfoKHR& copy_src);
    safe_VkDisplaySurfaceCreateInfoKHR();
    ~safe_VkDisplaySurfaceCreateInfoKHR();
    void initialize(const VkDisplaySurfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkDisplaySurfaceCreateInfoKHR* copy_src);
    VkDisplaySurfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkDisplaySurfaceCreateInfoKHR *>(this); }
    VkDisplaySurfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkDisplaySurfaceCreateInfoKHR const *>(this); }
};

struct safe_VkDisplayPresentInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkRect2D srcRect;
    VkRect2D dstRect;
    VkBool32 persistent;
    safe_VkDisplayPresentInfoKHR(const VkDisplayPresentInfoKHR* in_struct);
    safe_VkDisplayPresentInfoKHR(const safe_VkDisplayPresentInfoKHR& copy_src);
    safe_VkDisplayPresentInfoKHR& operator=(const safe_VkDisplayPresentInfoKHR& copy_src);
    safe_VkDisplayPresentInfoKHR();
    ~safe_VkDisplayPresentInfoKHR();
    void initialize(const VkDisplayPresentInfoKHR* in_struct);
    void initialize(const safe_VkDisplayPresentInfoKHR* copy_src);
    VkDisplayPresentInfoKHR *ptr() { return reinterpret_cast<VkDisplayPresentInfoKHR *>(this); }
    VkDisplayPresentInfoKHR const *ptr() const { return reinterpret_cast<VkDisplayPresentInfoKHR const *>(this); }
};

#ifdef VK_USE_PLATFORM_XLIB_KHR
struct safe_VkXlibSurfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkXlibSurfaceCreateFlagsKHR flags;
    Display* dpy;
    Window window;
    safe_VkXlibSurfaceCreateInfoKHR(const VkXlibSurfaceCreateInfoKHR* in_struct);
    safe_VkXlibSurfaceCreateInfoKHR(const safe_VkXlibSurfaceCreateInfoKHR& copy_src);
    safe_VkXlibSurfaceCreateInfoKHR& operator=(const safe_VkXlibSurfaceCreateInfoKHR& copy_src);
    safe_VkXlibSurfaceCreateInfoKHR();
    ~safe_VkXlibSurfaceCreateInfoKHR();
    void initialize(const VkXlibSurfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkXlibSurfaceCreateInfoKHR* copy_src);
    VkXlibSurfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkXlibSurfaceCreateInfoKHR *>(this); }
    VkXlibSurfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkXlibSurfaceCreateInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR
struct safe_VkXcbSurfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkXcbSurfaceCreateFlagsKHR flags;
    xcb_connection_t* connection;
    xcb_window_t window;
    safe_VkXcbSurfaceCreateInfoKHR(const VkXcbSurfaceCreateInfoKHR* in_struct);
    safe_VkXcbSurfaceCreateInfoKHR(const safe_VkXcbSurfaceCreateInfoKHR& copy_src);
    safe_VkXcbSurfaceCreateInfoKHR& operator=(const safe_VkXcbSurfaceCreateInfoKHR& copy_src);
    safe_VkXcbSurfaceCreateInfoKHR();
    ~safe_VkXcbSurfaceCreateInfoKHR();
    void initialize(const VkXcbSurfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkXcbSurfaceCreateInfoKHR* copy_src);
    VkXcbSurfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkXcbSurfaceCreateInfoKHR *>(this); }
    VkXcbSurfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkXcbSurfaceCreateInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
struct safe_VkWaylandSurfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkWaylandSurfaceCreateFlagsKHR flags;
    struct wl_display* display;
    struct wl_surface* surface;
    safe_VkWaylandSurfaceCreateInfoKHR(const VkWaylandSurfaceCreateInfoKHR* in_struct);
    safe_VkWaylandSurfaceCreateInfoKHR(const safe_VkWaylandSurfaceCreateInfoKHR& copy_src);
    safe_VkWaylandSurfaceCreateInfoKHR& operator=(const safe_VkWaylandSurfaceCreateInfoKHR& copy_src);
    safe_VkWaylandSurfaceCreateInfoKHR();
    ~safe_VkWaylandSurfaceCreateInfoKHR();
    void initialize(const VkWaylandSurfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkWaylandSurfaceCreateInfoKHR* copy_src);
    VkWaylandSurfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkWaylandSurfaceCreateInfoKHR *>(this); }
    VkWaylandSurfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkWaylandSurfaceCreateInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkAndroidSurfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAndroidSurfaceCreateFlagsKHR flags;
    struct ANativeWindow* window;
    safe_VkAndroidSurfaceCreateInfoKHR(const VkAndroidSurfaceCreateInfoKHR* in_struct);
    safe_VkAndroidSurfaceCreateInfoKHR(const safe_VkAndroidSurfaceCreateInfoKHR& copy_src);
    safe_VkAndroidSurfaceCreateInfoKHR& operator=(const safe_VkAndroidSurfaceCreateInfoKHR& copy_src);
    safe_VkAndroidSurfaceCreateInfoKHR();
    ~safe_VkAndroidSurfaceCreateInfoKHR();
    void initialize(const VkAndroidSurfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkAndroidSurfaceCreateInfoKHR* copy_src);
    VkAndroidSurfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkAndroidSurfaceCreateInfoKHR *>(this); }
    VkAndroidSurfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkAndroidSurfaceCreateInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkWin32SurfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkWin32SurfaceCreateFlagsKHR flags;
    HINSTANCE hinstance;
    HWND hwnd;
    safe_VkWin32SurfaceCreateInfoKHR(const VkWin32SurfaceCreateInfoKHR* in_struct);
    safe_VkWin32SurfaceCreateInfoKHR(const safe_VkWin32SurfaceCreateInfoKHR& copy_src);
    safe_VkWin32SurfaceCreateInfoKHR& operator=(const safe_VkWin32SurfaceCreateInfoKHR& copy_src);
    safe_VkWin32SurfaceCreateInfoKHR();
    ~safe_VkWin32SurfaceCreateInfoKHR();
    void initialize(const VkWin32SurfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkWin32SurfaceCreateInfoKHR* copy_src);
    VkWin32SurfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkWin32SurfaceCreateInfoKHR *>(this); }
    VkWin32SurfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkWin32SurfaceCreateInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkImportMemoryWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagBits handleType;
    HANDLE handle;
    LPCWSTR name;
    safe_VkImportMemoryWin32HandleInfoKHR(const VkImportMemoryWin32HandleInfoKHR* in_struct);
    safe_VkImportMemoryWin32HandleInfoKHR(const safe_VkImportMemoryWin32HandleInfoKHR& copy_src);
    safe_VkImportMemoryWin32HandleInfoKHR& operator=(const safe_VkImportMemoryWin32HandleInfoKHR& copy_src);
    safe_VkImportMemoryWin32HandleInfoKHR();
    ~safe_VkImportMemoryWin32HandleInfoKHR();
    void initialize(const VkImportMemoryWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkImportMemoryWin32HandleInfoKHR* copy_src);
    VkImportMemoryWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkImportMemoryWin32HandleInfoKHR *>(this); }
    VkImportMemoryWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkImportMemoryWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkExportMemoryWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD dwAccess;
    LPCWSTR name;
    safe_VkExportMemoryWin32HandleInfoKHR(const VkExportMemoryWin32HandleInfoKHR* in_struct);
    safe_VkExportMemoryWin32HandleInfoKHR(const safe_VkExportMemoryWin32HandleInfoKHR& copy_src);
    safe_VkExportMemoryWin32HandleInfoKHR& operator=(const safe_VkExportMemoryWin32HandleInfoKHR& copy_src);
    safe_VkExportMemoryWin32HandleInfoKHR();
    ~safe_VkExportMemoryWin32HandleInfoKHR();
    void initialize(const VkExportMemoryWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkExportMemoryWin32HandleInfoKHR* copy_src);
    VkExportMemoryWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkExportMemoryWin32HandleInfoKHR *>(this); }
    VkExportMemoryWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkExportMemoryWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkMemoryWin32HandlePropertiesKHR {
    VkStructureType sType;
    void* pNext;
    uint32_t memoryTypeBits;
    safe_VkMemoryWin32HandlePropertiesKHR(const VkMemoryWin32HandlePropertiesKHR* in_struct);
    safe_VkMemoryWin32HandlePropertiesKHR(const safe_VkMemoryWin32HandlePropertiesKHR& copy_src);
    safe_VkMemoryWin32HandlePropertiesKHR& operator=(const safe_VkMemoryWin32HandlePropertiesKHR& copy_src);
    safe_VkMemoryWin32HandlePropertiesKHR();
    ~safe_VkMemoryWin32HandlePropertiesKHR();
    void initialize(const VkMemoryWin32HandlePropertiesKHR* in_struct);
    void initialize(const safe_VkMemoryWin32HandlePropertiesKHR* copy_src);
    VkMemoryWin32HandlePropertiesKHR *ptr() { return reinterpret_cast<VkMemoryWin32HandlePropertiesKHR *>(this); }
    VkMemoryWin32HandlePropertiesKHR const *ptr() const { return reinterpret_cast<VkMemoryWin32HandlePropertiesKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkMemoryGetWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDeviceMemory memory;
    VkExternalMemoryHandleTypeFlagBits handleType;
    safe_VkMemoryGetWin32HandleInfoKHR(const VkMemoryGetWin32HandleInfoKHR* in_struct);
    safe_VkMemoryGetWin32HandleInfoKHR(const safe_VkMemoryGetWin32HandleInfoKHR& copy_src);
    safe_VkMemoryGetWin32HandleInfoKHR& operator=(const safe_VkMemoryGetWin32HandleInfoKHR& copy_src);
    safe_VkMemoryGetWin32HandleInfoKHR();
    ~safe_VkMemoryGetWin32HandleInfoKHR();
    void initialize(const VkMemoryGetWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkMemoryGetWin32HandleInfoKHR* copy_src);
    VkMemoryGetWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkMemoryGetWin32HandleInfoKHR *>(this); }
    VkMemoryGetWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkMemoryGetWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

struct safe_VkImportMemoryFdInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    safe_VkImportMemoryFdInfoKHR(const VkImportMemoryFdInfoKHR* in_struct);
    safe_VkImportMemoryFdInfoKHR(const safe_VkImportMemoryFdInfoKHR& copy_src);
    safe_VkImportMemoryFdInfoKHR& operator=(const safe_VkImportMemoryFdInfoKHR& copy_src);
    safe_VkImportMemoryFdInfoKHR();
    ~safe_VkImportMemoryFdInfoKHR();
    void initialize(const VkImportMemoryFdInfoKHR* in_struct);
    void initialize(const safe_VkImportMemoryFdInfoKHR* copy_src);
    VkImportMemoryFdInfoKHR *ptr() { return reinterpret_cast<VkImportMemoryFdInfoKHR *>(this); }
    VkImportMemoryFdInfoKHR const *ptr() const { return reinterpret_cast<VkImportMemoryFdInfoKHR const *>(this); }
};

struct safe_VkMemoryFdPropertiesKHR {
    VkStructureType sType;
    void* pNext;
    uint32_t memoryTypeBits;
    safe_VkMemoryFdPropertiesKHR(const VkMemoryFdPropertiesKHR* in_struct);
    safe_VkMemoryFdPropertiesKHR(const safe_VkMemoryFdPropertiesKHR& copy_src);
    safe_VkMemoryFdPropertiesKHR& operator=(const safe_VkMemoryFdPropertiesKHR& copy_src);
    safe_VkMemoryFdPropertiesKHR();
    ~safe_VkMemoryFdPropertiesKHR();
    void initialize(const VkMemoryFdPropertiesKHR* in_struct);
    void initialize(const safe_VkMemoryFdPropertiesKHR* copy_src);
    VkMemoryFdPropertiesKHR *ptr() { return reinterpret_cast<VkMemoryFdPropertiesKHR *>(this); }
    VkMemoryFdPropertiesKHR const *ptr() const { return reinterpret_cast<VkMemoryFdPropertiesKHR const *>(this); }
};

struct safe_VkMemoryGetFdInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDeviceMemory memory;
    VkExternalMemoryHandleTypeFlagBits handleType;
    safe_VkMemoryGetFdInfoKHR(const VkMemoryGetFdInfoKHR* in_struct);
    safe_VkMemoryGetFdInfoKHR(const safe_VkMemoryGetFdInfoKHR& copy_src);
    safe_VkMemoryGetFdInfoKHR& operator=(const safe_VkMemoryGetFdInfoKHR& copy_src);
    safe_VkMemoryGetFdInfoKHR();
    ~safe_VkMemoryGetFdInfoKHR();
    void initialize(const VkMemoryGetFdInfoKHR* in_struct);
    void initialize(const safe_VkMemoryGetFdInfoKHR* copy_src);
    VkMemoryGetFdInfoKHR *ptr() { return reinterpret_cast<VkMemoryGetFdInfoKHR *>(this); }
    VkMemoryGetFdInfoKHR const *ptr() const { return reinterpret_cast<VkMemoryGetFdInfoKHR const *>(this); }
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkWin32KeyedMutexAcquireReleaseInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t acquireCount;
    VkDeviceMemory* pAcquireSyncs;
    const uint64_t* pAcquireKeys;
    const uint32_t* pAcquireTimeouts;
    uint32_t releaseCount;
    VkDeviceMemory* pReleaseSyncs;
    const uint64_t* pReleaseKeys;
    safe_VkWin32KeyedMutexAcquireReleaseInfoKHR(const VkWin32KeyedMutexAcquireReleaseInfoKHR* in_struct);
    safe_VkWin32KeyedMutexAcquireReleaseInfoKHR(const safe_VkWin32KeyedMutexAcquireReleaseInfoKHR& copy_src);
    safe_VkWin32KeyedMutexAcquireReleaseInfoKHR& operator=(const safe_VkWin32KeyedMutexAcquireReleaseInfoKHR& copy_src);
    safe_VkWin32KeyedMutexAcquireReleaseInfoKHR();
    ~safe_VkWin32KeyedMutexAcquireReleaseInfoKHR();
    void initialize(const VkWin32KeyedMutexAcquireReleaseInfoKHR* in_struct);
    void initialize(const safe_VkWin32KeyedMutexAcquireReleaseInfoKHR* copy_src);
    VkWin32KeyedMutexAcquireReleaseInfoKHR *ptr() { return reinterpret_cast<VkWin32KeyedMutexAcquireReleaseInfoKHR *>(this); }
    VkWin32KeyedMutexAcquireReleaseInfoKHR const *ptr() const { return reinterpret_cast<VkWin32KeyedMutexAcquireReleaseInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkImportSemaphoreWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSemaphore semaphore;
    VkSemaphoreImportFlags flags;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    HANDLE handle;
    LPCWSTR name;
    safe_VkImportSemaphoreWin32HandleInfoKHR(const VkImportSemaphoreWin32HandleInfoKHR* in_struct);
    safe_VkImportSemaphoreWin32HandleInfoKHR(const safe_VkImportSemaphoreWin32HandleInfoKHR& copy_src);
    safe_VkImportSemaphoreWin32HandleInfoKHR& operator=(const safe_VkImportSemaphoreWin32HandleInfoKHR& copy_src);
    safe_VkImportSemaphoreWin32HandleInfoKHR();
    ~safe_VkImportSemaphoreWin32HandleInfoKHR();
    void initialize(const VkImportSemaphoreWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkImportSemaphoreWin32HandleInfoKHR* copy_src);
    VkImportSemaphoreWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkImportSemaphoreWin32HandleInfoKHR *>(this); }
    VkImportSemaphoreWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkImportSemaphoreWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkExportSemaphoreWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD dwAccess;
    LPCWSTR name;
    safe_VkExportSemaphoreWin32HandleInfoKHR(const VkExportSemaphoreWin32HandleInfoKHR* in_struct);
    safe_VkExportSemaphoreWin32HandleInfoKHR(const safe_VkExportSemaphoreWin32HandleInfoKHR& copy_src);
    safe_VkExportSemaphoreWin32HandleInfoKHR& operator=(const safe_VkExportSemaphoreWin32HandleInfoKHR& copy_src);
    safe_VkExportSemaphoreWin32HandleInfoKHR();
    ~safe_VkExportSemaphoreWin32HandleInfoKHR();
    void initialize(const VkExportSemaphoreWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkExportSemaphoreWin32HandleInfoKHR* copy_src);
    VkExportSemaphoreWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkExportSemaphoreWin32HandleInfoKHR *>(this); }
    VkExportSemaphoreWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkExportSemaphoreWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkD3D12FenceSubmitInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t waitSemaphoreValuesCount;
    const uint64_t* pWaitSemaphoreValues;
    uint32_t signalSemaphoreValuesCount;
    const uint64_t* pSignalSemaphoreValues;
    safe_VkD3D12FenceSubmitInfoKHR(const VkD3D12FenceSubmitInfoKHR* in_struct);
    safe_VkD3D12FenceSubmitInfoKHR(const safe_VkD3D12FenceSubmitInfoKHR& copy_src);
    safe_VkD3D12FenceSubmitInfoKHR& operator=(const safe_VkD3D12FenceSubmitInfoKHR& copy_src);
    safe_VkD3D12FenceSubmitInfoKHR();
    ~safe_VkD3D12FenceSubmitInfoKHR();
    void initialize(const VkD3D12FenceSubmitInfoKHR* in_struct);
    void initialize(const safe_VkD3D12FenceSubmitInfoKHR* copy_src);
    VkD3D12FenceSubmitInfoKHR *ptr() { return reinterpret_cast<VkD3D12FenceSubmitInfoKHR *>(this); }
    VkD3D12FenceSubmitInfoKHR const *ptr() const { return reinterpret_cast<VkD3D12FenceSubmitInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkSemaphoreGetWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSemaphore semaphore;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    safe_VkSemaphoreGetWin32HandleInfoKHR(const VkSemaphoreGetWin32HandleInfoKHR* in_struct);
    safe_VkSemaphoreGetWin32HandleInfoKHR(const safe_VkSemaphoreGetWin32HandleInfoKHR& copy_src);
    safe_VkSemaphoreGetWin32HandleInfoKHR& operator=(const safe_VkSemaphoreGetWin32HandleInfoKHR& copy_src);
    safe_VkSemaphoreGetWin32HandleInfoKHR();
    ~safe_VkSemaphoreGetWin32HandleInfoKHR();
    void initialize(const VkSemaphoreGetWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkSemaphoreGetWin32HandleInfoKHR* copy_src);
    VkSemaphoreGetWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkSemaphoreGetWin32HandleInfoKHR *>(this); }
    VkSemaphoreGetWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkSemaphoreGetWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

struct safe_VkImportSemaphoreFdInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSemaphore semaphore;
    VkSemaphoreImportFlags flags;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    int fd;
    safe_VkImportSemaphoreFdInfoKHR(const VkImportSemaphoreFdInfoKHR* in_struct);
    safe_VkImportSemaphoreFdInfoKHR(const safe_VkImportSemaphoreFdInfoKHR& copy_src);
    safe_VkImportSemaphoreFdInfoKHR& operator=(const safe_VkImportSemaphoreFdInfoKHR& copy_src);
    safe_VkImportSemaphoreFdInfoKHR();
    ~safe_VkImportSemaphoreFdInfoKHR();
    void initialize(const VkImportSemaphoreFdInfoKHR* in_struct);
    void initialize(const safe_VkImportSemaphoreFdInfoKHR* copy_src);
    VkImportSemaphoreFdInfoKHR *ptr() { return reinterpret_cast<VkImportSemaphoreFdInfoKHR *>(this); }
    VkImportSemaphoreFdInfoKHR const *ptr() const { return reinterpret_cast<VkImportSemaphoreFdInfoKHR const *>(this); }
};

struct safe_VkSemaphoreGetFdInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkSemaphore semaphore;
    VkExternalSemaphoreHandleTypeFlagBits handleType;
    safe_VkSemaphoreGetFdInfoKHR(const VkSemaphoreGetFdInfoKHR* in_struct);
    safe_VkSemaphoreGetFdInfoKHR(const safe_VkSemaphoreGetFdInfoKHR& copy_src);
    safe_VkSemaphoreGetFdInfoKHR& operator=(const safe_VkSemaphoreGetFdInfoKHR& copy_src);
    safe_VkSemaphoreGetFdInfoKHR();
    ~safe_VkSemaphoreGetFdInfoKHR();
    void initialize(const VkSemaphoreGetFdInfoKHR* in_struct);
    void initialize(const safe_VkSemaphoreGetFdInfoKHR* copy_src);
    VkSemaphoreGetFdInfoKHR *ptr() { return reinterpret_cast<VkSemaphoreGetFdInfoKHR *>(this); }
    VkSemaphoreGetFdInfoKHR const *ptr() const { return reinterpret_cast<VkSemaphoreGetFdInfoKHR const *>(this); }
};

struct safe_VkPhysicalDevicePushDescriptorPropertiesKHR {
    VkStructureType sType;
    void* pNext;
    uint32_t maxPushDescriptors;
    safe_VkPhysicalDevicePushDescriptorPropertiesKHR(const VkPhysicalDevicePushDescriptorPropertiesKHR* in_struct);
    safe_VkPhysicalDevicePushDescriptorPropertiesKHR(const safe_VkPhysicalDevicePushDescriptorPropertiesKHR& copy_src);
    safe_VkPhysicalDevicePushDescriptorPropertiesKHR& operator=(const safe_VkPhysicalDevicePushDescriptorPropertiesKHR& copy_src);
    safe_VkPhysicalDevicePushDescriptorPropertiesKHR();
    ~safe_VkPhysicalDevicePushDescriptorPropertiesKHR();
    void initialize(const VkPhysicalDevicePushDescriptorPropertiesKHR* in_struct);
    void initialize(const safe_VkPhysicalDevicePushDescriptorPropertiesKHR* copy_src);
    VkPhysicalDevicePushDescriptorPropertiesKHR *ptr() { return reinterpret_cast<VkPhysicalDevicePushDescriptorPropertiesKHR *>(this); }
    VkPhysicalDevicePushDescriptorPropertiesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDevicePushDescriptorPropertiesKHR const *>(this); }
};

struct safe_VkPresentRegionKHR {
    uint32_t rectangleCount;
    const VkRectLayerKHR* pRectangles;
    safe_VkPresentRegionKHR(const VkPresentRegionKHR* in_struct);
    safe_VkPresentRegionKHR(const safe_VkPresentRegionKHR& copy_src);
    safe_VkPresentRegionKHR& operator=(const safe_VkPresentRegionKHR& copy_src);
    safe_VkPresentRegionKHR();
    ~safe_VkPresentRegionKHR();
    void initialize(const VkPresentRegionKHR* in_struct);
    void initialize(const safe_VkPresentRegionKHR* copy_src);
    VkPresentRegionKHR *ptr() { return reinterpret_cast<VkPresentRegionKHR *>(this); }
    VkPresentRegionKHR const *ptr() const { return reinterpret_cast<VkPresentRegionKHR const *>(this); }
};

struct safe_VkPresentRegionsKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t swapchainCount;
    safe_VkPresentRegionKHR* pRegions;
    safe_VkPresentRegionsKHR(const VkPresentRegionsKHR* in_struct);
    safe_VkPresentRegionsKHR(const safe_VkPresentRegionsKHR& copy_src);
    safe_VkPresentRegionsKHR& operator=(const safe_VkPresentRegionsKHR& copy_src);
    safe_VkPresentRegionsKHR();
    ~safe_VkPresentRegionsKHR();
    void initialize(const VkPresentRegionsKHR* in_struct);
    void initialize(const safe_VkPresentRegionsKHR* copy_src);
    VkPresentRegionsKHR *ptr() { return reinterpret_cast<VkPresentRegionsKHR *>(this); }
    VkPresentRegionsKHR const *ptr() const { return reinterpret_cast<VkPresentRegionsKHR const *>(this); }
};

struct safe_VkSharedPresentSurfaceCapabilitiesKHR {
    VkStructureType sType;
    void* pNext;
    VkImageUsageFlags sharedPresentSupportedUsageFlags;
    safe_VkSharedPresentSurfaceCapabilitiesKHR(const VkSharedPresentSurfaceCapabilitiesKHR* in_struct);
    safe_VkSharedPresentSurfaceCapabilitiesKHR(const safe_VkSharedPresentSurfaceCapabilitiesKHR& copy_src);
    safe_VkSharedPresentSurfaceCapabilitiesKHR& operator=(const safe_VkSharedPresentSurfaceCapabilitiesKHR& copy_src);
    safe_VkSharedPresentSurfaceCapabilitiesKHR();
    ~safe_VkSharedPresentSurfaceCapabilitiesKHR();
    void initialize(const VkSharedPresentSurfaceCapabilitiesKHR* in_struct);
    void initialize(const safe_VkSharedPresentSurfaceCapabilitiesKHR* copy_src);
    VkSharedPresentSurfaceCapabilitiesKHR *ptr() { return reinterpret_cast<VkSharedPresentSurfaceCapabilitiesKHR *>(this); }
    VkSharedPresentSurfaceCapabilitiesKHR const *ptr() const { return reinterpret_cast<VkSharedPresentSurfaceCapabilitiesKHR const *>(this); }
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkImportFenceWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkFence fence;
    VkFenceImportFlags flags;
    VkExternalFenceHandleTypeFlagBits handleType;
    HANDLE handle;
    LPCWSTR name;
    safe_VkImportFenceWin32HandleInfoKHR(const VkImportFenceWin32HandleInfoKHR* in_struct);
    safe_VkImportFenceWin32HandleInfoKHR(const safe_VkImportFenceWin32HandleInfoKHR& copy_src);
    safe_VkImportFenceWin32HandleInfoKHR& operator=(const safe_VkImportFenceWin32HandleInfoKHR& copy_src);
    safe_VkImportFenceWin32HandleInfoKHR();
    ~safe_VkImportFenceWin32HandleInfoKHR();
    void initialize(const VkImportFenceWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkImportFenceWin32HandleInfoKHR* copy_src);
    VkImportFenceWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkImportFenceWin32HandleInfoKHR *>(this); }
    VkImportFenceWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkImportFenceWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkExportFenceWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD dwAccess;
    LPCWSTR name;
    safe_VkExportFenceWin32HandleInfoKHR(const VkExportFenceWin32HandleInfoKHR* in_struct);
    safe_VkExportFenceWin32HandleInfoKHR(const safe_VkExportFenceWin32HandleInfoKHR& copy_src);
    safe_VkExportFenceWin32HandleInfoKHR& operator=(const safe_VkExportFenceWin32HandleInfoKHR& copy_src);
    safe_VkExportFenceWin32HandleInfoKHR();
    ~safe_VkExportFenceWin32HandleInfoKHR();
    void initialize(const VkExportFenceWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkExportFenceWin32HandleInfoKHR* copy_src);
    VkExportFenceWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkExportFenceWin32HandleInfoKHR *>(this); }
    VkExportFenceWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkExportFenceWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkFenceGetWin32HandleInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkFence fence;
    VkExternalFenceHandleTypeFlagBits handleType;
    safe_VkFenceGetWin32HandleInfoKHR(const VkFenceGetWin32HandleInfoKHR* in_struct);
    safe_VkFenceGetWin32HandleInfoKHR(const safe_VkFenceGetWin32HandleInfoKHR& copy_src);
    safe_VkFenceGetWin32HandleInfoKHR& operator=(const safe_VkFenceGetWin32HandleInfoKHR& copy_src);
    safe_VkFenceGetWin32HandleInfoKHR();
    ~safe_VkFenceGetWin32HandleInfoKHR();
    void initialize(const VkFenceGetWin32HandleInfoKHR* in_struct);
    void initialize(const safe_VkFenceGetWin32HandleInfoKHR* copy_src);
    VkFenceGetWin32HandleInfoKHR *ptr() { return reinterpret_cast<VkFenceGetWin32HandleInfoKHR *>(this); }
    VkFenceGetWin32HandleInfoKHR const *ptr() const { return reinterpret_cast<VkFenceGetWin32HandleInfoKHR const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

struct safe_VkImportFenceFdInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkFence fence;
    VkFenceImportFlags flags;
    VkExternalFenceHandleTypeFlagBits handleType;
    int fd;
    safe_VkImportFenceFdInfoKHR(const VkImportFenceFdInfoKHR* in_struct);
    safe_VkImportFenceFdInfoKHR(const safe_VkImportFenceFdInfoKHR& copy_src);
    safe_VkImportFenceFdInfoKHR& operator=(const safe_VkImportFenceFdInfoKHR& copy_src);
    safe_VkImportFenceFdInfoKHR();
    ~safe_VkImportFenceFdInfoKHR();
    void initialize(const VkImportFenceFdInfoKHR* in_struct);
    void initialize(const safe_VkImportFenceFdInfoKHR* copy_src);
    VkImportFenceFdInfoKHR *ptr() { return reinterpret_cast<VkImportFenceFdInfoKHR *>(this); }
    VkImportFenceFdInfoKHR const *ptr() const { return reinterpret_cast<VkImportFenceFdInfoKHR const *>(this); }
};

struct safe_VkFenceGetFdInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkFence fence;
    VkExternalFenceHandleTypeFlagBits handleType;
    safe_VkFenceGetFdInfoKHR(const VkFenceGetFdInfoKHR* in_struct);
    safe_VkFenceGetFdInfoKHR(const safe_VkFenceGetFdInfoKHR& copy_src);
    safe_VkFenceGetFdInfoKHR& operator=(const safe_VkFenceGetFdInfoKHR& copy_src);
    safe_VkFenceGetFdInfoKHR();
    ~safe_VkFenceGetFdInfoKHR();
    void initialize(const VkFenceGetFdInfoKHR* in_struct);
    void initialize(const safe_VkFenceGetFdInfoKHR* copy_src);
    VkFenceGetFdInfoKHR *ptr() { return reinterpret_cast<VkFenceGetFdInfoKHR *>(this); }
    VkFenceGetFdInfoKHR const *ptr() const { return reinterpret_cast<VkFenceGetFdInfoKHR const *>(this); }
};

struct safe_VkPhysicalDevicePerformanceQueryFeaturesKHR {
    VkStructureType sType;
    void* pNext;
    VkBool32 performanceCounterQueryPools;
    VkBool32 performanceCounterMultipleQueryPools;
    safe_VkPhysicalDevicePerformanceQueryFeaturesKHR(const VkPhysicalDevicePerformanceQueryFeaturesKHR* in_struct);
    safe_VkPhysicalDevicePerformanceQueryFeaturesKHR(const safe_VkPhysicalDevicePerformanceQueryFeaturesKHR& copy_src);
    safe_VkPhysicalDevicePerformanceQueryFeaturesKHR& operator=(const safe_VkPhysicalDevicePerformanceQueryFeaturesKHR& copy_src);
    safe_VkPhysicalDevicePerformanceQueryFeaturesKHR();
    ~safe_VkPhysicalDevicePerformanceQueryFeaturesKHR();
    void initialize(const VkPhysicalDevicePerformanceQueryFeaturesKHR* in_struct);
    void initialize(const safe_VkPhysicalDevicePerformanceQueryFeaturesKHR* copy_src);
    VkPhysicalDevicePerformanceQueryFeaturesKHR *ptr() { return reinterpret_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR *>(this); }
    VkPhysicalDevicePerformanceQueryFeaturesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDevicePerformanceQueryFeaturesKHR const *>(this); }
};

struct safe_VkPhysicalDevicePerformanceQueryPropertiesKHR {
    VkStructureType sType;
    void* pNext;
    VkBool32 allowCommandBufferQueryCopies;
    safe_VkPhysicalDevicePerformanceQueryPropertiesKHR(const VkPhysicalDevicePerformanceQueryPropertiesKHR* in_struct);
    safe_VkPhysicalDevicePerformanceQueryPropertiesKHR(const safe_VkPhysicalDevicePerformanceQueryPropertiesKHR& copy_src);
    safe_VkPhysicalDevicePerformanceQueryPropertiesKHR& operator=(const safe_VkPhysicalDevicePerformanceQueryPropertiesKHR& copy_src);
    safe_VkPhysicalDevicePerformanceQueryPropertiesKHR();
    ~safe_VkPhysicalDevicePerformanceQueryPropertiesKHR();
    void initialize(const VkPhysicalDevicePerformanceQueryPropertiesKHR* in_struct);
    void initialize(const safe_VkPhysicalDevicePerformanceQueryPropertiesKHR* copy_src);
    VkPhysicalDevicePerformanceQueryPropertiesKHR *ptr() { return reinterpret_cast<VkPhysicalDevicePerformanceQueryPropertiesKHR *>(this); }
    VkPhysicalDevicePerformanceQueryPropertiesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDevicePerformanceQueryPropertiesKHR const *>(this); }
};

struct safe_VkPerformanceCounterKHR {
    VkStructureType sType;
    const void* pNext;
    VkPerformanceCounterUnitKHR unit;
    VkPerformanceCounterScopeKHR scope;
    VkPerformanceCounterStorageKHR storage;
    uint8_t uuid[VK_UUID_SIZE];
    safe_VkPerformanceCounterKHR(const VkPerformanceCounterKHR* in_struct);
    safe_VkPerformanceCounterKHR(const safe_VkPerformanceCounterKHR& copy_src);
    safe_VkPerformanceCounterKHR& operator=(const safe_VkPerformanceCounterKHR& copy_src);
    safe_VkPerformanceCounterKHR();
    ~safe_VkPerformanceCounterKHR();
    void initialize(const VkPerformanceCounterKHR* in_struct);
    void initialize(const safe_VkPerformanceCounterKHR* copy_src);
    VkPerformanceCounterKHR *ptr() { return reinterpret_cast<VkPerformanceCounterKHR *>(this); }
    VkPerformanceCounterKHR const *ptr() const { return reinterpret_cast<VkPerformanceCounterKHR const *>(this); }
};

struct safe_VkPerformanceCounterDescriptionKHR {
    VkStructureType sType;
    const void* pNext;
    VkPerformanceCounterDescriptionFlagsKHR flags;
    char name[VK_MAX_DESCRIPTION_SIZE];
    char category[VK_MAX_DESCRIPTION_SIZE];
    char description[VK_MAX_DESCRIPTION_SIZE];
    safe_VkPerformanceCounterDescriptionKHR(const VkPerformanceCounterDescriptionKHR* in_struct);
    safe_VkPerformanceCounterDescriptionKHR(const safe_VkPerformanceCounterDescriptionKHR& copy_src);
    safe_VkPerformanceCounterDescriptionKHR& operator=(const safe_VkPerformanceCounterDescriptionKHR& copy_src);
    safe_VkPerformanceCounterDescriptionKHR();
    ~safe_VkPerformanceCounterDescriptionKHR();
    void initialize(const VkPerformanceCounterDescriptionKHR* in_struct);
    void initialize(const safe_VkPerformanceCounterDescriptionKHR* copy_src);
    VkPerformanceCounterDescriptionKHR *ptr() { return reinterpret_cast<VkPerformanceCounterDescriptionKHR *>(this); }
    VkPerformanceCounterDescriptionKHR const *ptr() const { return reinterpret_cast<VkPerformanceCounterDescriptionKHR const *>(this); }
};

struct safe_VkQueryPoolPerformanceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t queueFamilyIndex;
    uint32_t counterIndexCount;
    const uint32_t* pCounterIndices;
    safe_VkQueryPoolPerformanceCreateInfoKHR(const VkQueryPoolPerformanceCreateInfoKHR* in_struct);
    safe_VkQueryPoolPerformanceCreateInfoKHR(const safe_VkQueryPoolPerformanceCreateInfoKHR& copy_src);
    safe_VkQueryPoolPerformanceCreateInfoKHR& operator=(const safe_VkQueryPoolPerformanceCreateInfoKHR& copy_src);
    safe_VkQueryPoolPerformanceCreateInfoKHR();
    ~safe_VkQueryPoolPerformanceCreateInfoKHR();
    void initialize(const VkQueryPoolPerformanceCreateInfoKHR* in_struct);
    void initialize(const safe_VkQueryPoolPerformanceCreateInfoKHR* copy_src);
    VkQueryPoolPerformanceCreateInfoKHR *ptr() { return reinterpret_cast<VkQueryPoolPerformanceCreateInfoKHR *>(this); }
    VkQueryPoolPerformanceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkQueryPoolPerformanceCreateInfoKHR const *>(this); }
};

struct safe_VkAcquireProfilingLockInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAcquireProfilingLockFlagsKHR flags;
    uint64_t timeout;
    safe_VkAcquireProfilingLockInfoKHR(const VkAcquireProfilingLockInfoKHR* in_struct);
    safe_VkAcquireProfilingLockInfoKHR(const safe_VkAcquireProfilingLockInfoKHR& copy_src);
    safe_VkAcquireProfilingLockInfoKHR& operator=(const safe_VkAcquireProfilingLockInfoKHR& copy_src);
    safe_VkAcquireProfilingLockInfoKHR();
    ~safe_VkAcquireProfilingLockInfoKHR();
    void initialize(const VkAcquireProfilingLockInfoKHR* in_struct);
    void initialize(const safe_VkAcquireProfilingLockInfoKHR* copy_src);
    VkAcquireProfilingLockInfoKHR *ptr() { return reinterpret_cast<VkAcquireProfilingLockInfoKHR *>(this); }
    VkAcquireProfilingLockInfoKHR const *ptr() const { return reinterpret_cast<VkAcquireProfilingLockInfoKHR const *>(this); }
};

struct safe_VkPerformanceQuerySubmitInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t counterPassIndex;
    safe_VkPerformanceQuerySubmitInfoKHR(const VkPerformanceQuerySubmitInfoKHR* in_struct);
    safe_VkPerformanceQuerySubmitInfoKHR(const safe_VkPerformanceQuerySubmitInfoKHR& copy_src);
    safe_VkPerformanceQuerySubmitInfoKHR& operator=(const safe_VkPerformanceQuerySubmitInfoKHR& copy_src);
    safe_VkPerformanceQuerySubmitInfoKHR();
    ~safe_VkPerformanceQuerySubmitInfoKHR();
    void initialize(const VkPerformanceQuerySubmitInfoKHR* in_struct);
    void initialize(const safe_VkPerformanceQuerySubmitInfoKHR* copy_src);
    VkPerformanceQuerySubmitInfoKHR *ptr() { return reinterpret_cast<VkPerformanceQuerySubmitInfoKHR *>(this); }
    VkPerformanceQuerySubmitInfoKHR const *ptr() const { return reinterpret_cast<VkPerformanceQuerySubmitInfoKHR const *>(this); }
};

struct safe_VkPhysicalDeviceSurfaceInfo2KHR {
    VkStructureType sType;
    const void* pNext;
    VkSurfaceKHR surface;
    safe_VkPhysicalDeviceSurfaceInfo2KHR(const VkPhysicalDeviceSurfaceInfo2KHR* in_struct);
    safe_VkPhysicalDeviceSurfaceInfo2KHR(const safe_VkPhysicalDeviceSurfaceInfo2KHR& copy_src);
    safe_VkPhysicalDeviceSurfaceInfo2KHR& operator=(const safe_VkPhysicalDeviceSurfaceInfo2KHR& copy_src);
    safe_VkPhysicalDeviceSurfaceInfo2KHR();
    ~safe_VkPhysicalDeviceSurfaceInfo2KHR();
    void initialize(const VkPhysicalDeviceSurfaceInfo2KHR* in_struct);
    void initialize(const safe_VkPhysicalDeviceSurfaceInfo2KHR* copy_src);
    VkPhysicalDeviceSurfaceInfo2KHR *ptr() { return reinterpret_cast<VkPhysicalDeviceSurfaceInfo2KHR *>(this); }
    VkPhysicalDeviceSurfaceInfo2KHR const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSurfaceInfo2KHR const *>(this); }
};

struct safe_VkSurfaceCapabilities2KHR {
    VkStructureType sType;
    void* pNext;
    VkSurfaceCapabilitiesKHR surfaceCapabilities;
    safe_VkSurfaceCapabilities2KHR(const VkSurfaceCapabilities2KHR* in_struct);
    safe_VkSurfaceCapabilities2KHR(const safe_VkSurfaceCapabilities2KHR& copy_src);
    safe_VkSurfaceCapabilities2KHR& operator=(const safe_VkSurfaceCapabilities2KHR& copy_src);
    safe_VkSurfaceCapabilities2KHR();
    ~safe_VkSurfaceCapabilities2KHR();
    void initialize(const VkSurfaceCapabilities2KHR* in_struct);
    void initialize(const safe_VkSurfaceCapabilities2KHR* copy_src);
    VkSurfaceCapabilities2KHR *ptr() { return reinterpret_cast<VkSurfaceCapabilities2KHR *>(this); }
    VkSurfaceCapabilities2KHR const *ptr() const { return reinterpret_cast<VkSurfaceCapabilities2KHR const *>(this); }
};

struct safe_VkSurfaceFormat2KHR {
    VkStructureType sType;
    void* pNext;
    VkSurfaceFormatKHR surfaceFormat;
    safe_VkSurfaceFormat2KHR(const VkSurfaceFormat2KHR* in_struct);
    safe_VkSurfaceFormat2KHR(const safe_VkSurfaceFormat2KHR& copy_src);
    safe_VkSurfaceFormat2KHR& operator=(const safe_VkSurfaceFormat2KHR& copy_src);
    safe_VkSurfaceFormat2KHR();
    ~safe_VkSurfaceFormat2KHR();
    void initialize(const VkSurfaceFormat2KHR* in_struct);
    void initialize(const safe_VkSurfaceFormat2KHR* copy_src);
    VkSurfaceFormat2KHR *ptr() { return reinterpret_cast<VkSurfaceFormat2KHR *>(this); }
    VkSurfaceFormat2KHR const *ptr() const { return reinterpret_cast<VkSurfaceFormat2KHR const *>(this); }
};

struct safe_VkDisplayProperties2KHR {
    VkStructureType sType;
    void* pNext;
    safe_VkDisplayPropertiesKHR displayProperties;
    safe_VkDisplayProperties2KHR(const VkDisplayProperties2KHR* in_struct);
    safe_VkDisplayProperties2KHR(const safe_VkDisplayProperties2KHR& copy_src);
    safe_VkDisplayProperties2KHR& operator=(const safe_VkDisplayProperties2KHR& copy_src);
    safe_VkDisplayProperties2KHR();
    ~safe_VkDisplayProperties2KHR();
    void initialize(const VkDisplayProperties2KHR* in_struct);
    void initialize(const safe_VkDisplayProperties2KHR* copy_src);
    VkDisplayProperties2KHR *ptr() { return reinterpret_cast<VkDisplayProperties2KHR *>(this); }
    VkDisplayProperties2KHR const *ptr() const { return reinterpret_cast<VkDisplayProperties2KHR const *>(this); }
};

struct safe_VkDisplayPlaneProperties2KHR {
    VkStructureType sType;
    void* pNext;
    VkDisplayPlanePropertiesKHR displayPlaneProperties;
    safe_VkDisplayPlaneProperties2KHR(const VkDisplayPlaneProperties2KHR* in_struct);
    safe_VkDisplayPlaneProperties2KHR(const safe_VkDisplayPlaneProperties2KHR& copy_src);
    safe_VkDisplayPlaneProperties2KHR& operator=(const safe_VkDisplayPlaneProperties2KHR& copy_src);
    safe_VkDisplayPlaneProperties2KHR();
    ~safe_VkDisplayPlaneProperties2KHR();
    void initialize(const VkDisplayPlaneProperties2KHR* in_struct);
    void initialize(const safe_VkDisplayPlaneProperties2KHR* copy_src);
    VkDisplayPlaneProperties2KHR *ptr() { return reinterpret_cast<VkDisplayPlaneProperties2KHR *>(this); }
    VkDisplayPlaneProperties2KHR const *ptr() const { return reinterpret_cast<VkDisplayPlaneProperties2KHR const *>(this); }
};

struct safe_VkDisplayModeProperties2KHR {
    VkStructureType sType;
    void* pNext;
    VkDisplayModePropertiesKHR displayModeProperties;
    safe_VkDisplayModeProperties2KHR(const VkDisplayModeProperties2KHR* in_struct);
    safe_VkDisplayModeProperties2KHR(const safe_VkDisplayModeProperties2KHR& copy_src);
    safe_VkDisplayModeProperties2KHR& operator=(const safe_VkDisplayModeProperties2KHR& copy_src);
    safe_VkDisplayModeProperties2KHR();
    ~safe_VkDisplayModeProperties2KHR();
    void initialize(const VkDisplayModeProperties2KHR* in_struct);
    void initialize(const safe_VkDisplayModeProperties2KHR* copy_src);
    VkDisplayModeProperties2KHR *ptr() { return reinterpret_cast<VkDisplayModeProperties2KHR *>(this); }
    VkDisplayModeProperties2KHR const *ptr() const { return reinterpret_cast<VkDisplayModeProperties2KHR const *>(this); }
};

struct safe_VkDisplayPlaneInfo2KHR {
    VkStructureType sType;
    const void* pNext;
    VkDisplayModeKHR mode;
    uint32_t planeIndex;
    safe_VkDisplayPlaneInfo2KHR(const VkDisplayPlaneInfo2KHR* in_struct);
    safe_VkDisplayPlaneInfo2KHR(const safe_VkDisplayPlaneInfo2KHR& copy_src);
    safe_VkDisplayPlaneInfo2KHR& operator=(const safe_VkDisplayPlaneInfo2KHR& copy_src);
    safe_VkDisplayPlaneInfo2KHR();
    ~safe_VkDisplayPlaneInfo2KHR();
    void initialize(const VkDisplayPlaneInfo2KHR* in_struct);
    void initialize(const safe_VkDisplayPlaneInfo2KHR* copy_src);
    VkDisplayPlaneInfo2KHR *ptr() { return reinterpret_cast<VkDisplayPlaneInfo2KHR *>(this); }
    VkDisplayPlaneInfo2KHR const *ptr() const { return reinterpret_cast<VkDisplayPlaneInfo2KHR const *>(this); }
};

struct safe_VkDisplayPlaneCapabilities2KHR {
    VkStructureType sType;
    void* pNext;
    VkDisplayPlaneCapabilitiesKHR capabilities;
    safe_VkDisplayPlaneCapabilities2KHR(const VkDisplayPlaneCapabilities2KHR* in_struct);
    safe_VkDisplayPlaneCapabilities2KHR(const safe_VkDisplayPlaneCapabilities2KHR& copy_src);
    safe_VkDisplayPlaneCapabilities2KHR& operator=(const safe_VkDisplayPlaneCapabilities2KHR& copy_src);
    safe_VkDisplayPlaneCapabilities2KHR();
    ~safe_VkDisplayPlaneCapabilities2KHR();
    void initialize(const VkDisplayPlaneCapabilities2KHR* in_struct);
    void initialize(const safe_VkDisplayPlaneCapabilities2KHR* copy_src);
    VkDisplayPlaneCapabilities2KHR *ptr() { return reinterpret_cast<VkDisplayPlaneCapabilities2KHR *>(this); }
    VkDisplayPlaneCapabilities2KHR const *ptr() const { return reinterpret_cast<VkDisplayPlaneCapabilities2KHR const *>(this); }
};

struct safe_VkPhysicalDeviceShaderClockFeaturesKHR {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderSubgroupClock;
    VkBool32 shaderDeviceClock;
    safe_VkPhysicalDeviceShaderClockFeaturesKHR(const VkPhysicalDeviceShaderClockFeaturesKHR* in_struct);
    safe_VkPhysicalDeviceShaderClockFeaturesKHR(const safe_VkPhysicalDeviceShaderClockFeaturesKHR& copy_src);
    safe_VkPhysicalDeviceShaderClockFeaturesKHR& operator=(const safe_VkPhysicalDeviceShaderClockFeaturesKHR& copy_src);
    safe_VkPhysicalDeviceShaderClockFeaturesKHR();
    ~safe_VkPhysicalDeviceShaderClockFeaturesKHR();
    void initialize(const VkPhysicalDeviceShaderClockFeaturesKHR* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderClockFeaturesKHR* copy_src);
    VkPhysicalDeviceShaderClockFeaturesKHR *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderClockFeaturesKHR *>(this); }
    VkPhysicalDeviceShaderClockFeaturesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderClockFeaturesKHR const *>(this); }
};

struct safe_VkSurfaceProtectedCapabilitiesKHR {
    VkStructureType sType;
    const void* pNext;
    VkBool32 supportsProtected;
    safe_VkSurfaceProtectedCapabilitiesKHR(const VkSurfaceProtectedCapabilitiesKHR* in_struct);
    safe_VkSurfaceProtectedCapabilitiesKHR(const safe_VkSurfaceProtectedCapabilitiesKHR& copy_src);
    safe_VkSurfaceProtectedCapabilitiesKHR& operator=(const safe_VkSurfaceProtectedCapabilitiesKHR& copy_src);
    safe_VkSurfaceProtectedCapabilitiesKHR();
    ~safe_VkSurfaceProtectedCapabilitiesKHR();
    void initialize(const VkSurfaceProtectedCapabilitiesKHR* in_struct);
    void initialize(const safe_VkSurfaceProtectedCapabilitiesKHR* copy_src);
    VkSurfaceProtectedCapabilitiesKHR *ptr() { return reinterpret_cast<VkSurfaceProtectedCapabilitiesKHR *>(this); }
    VkSurfaceProtectedCapabilitiesKHR const *ptr() const { return reinterpret_cast<VkSurfaceProtectedCapabilitiesKHR const *>(this); }
};

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkDeferredOperationInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDeferredOperationKHR operationHandle;
    safe_VkDeferredOperationInfoKHR(const VkDeferredOperationInfoKHR* in_struct);
    safe_VkDeferredOperationInfoKHR(const safe_VkDeferredOperationInfoKHR& copy_src);
    safe_VkDeferredOperationInfoKHR& operator=(const safe_VkDeferredOperationInfoKHR& copy_src);
    safe_VkDeferredOperationInfoKHR();
    ~safe_VkDeferredOperationInfoKHR();
    void initialize(const VkDeferredOperationInfoKHR* in_struct);
    void initialize(const safe_VkDeferredOperationInfoKHR* copy_src);
    VkDeferredOperationInfoKHR *ptr() { return reinterpret_cast<VkDeferredOperationInfoKHR *>(this); }
    VkDeferredOperationInfoKHR const *ptr() const { return reinterpret_cast<VkDeferredOperationInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

struct safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR {
    VkStructureType sType;
    void* pNext;
    VkBool32 pipelineExecutableInfo;
    safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* in_struct);
    safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(const safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR& copy_src);
    safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR& operator=(const safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR& copy_src);
    safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR();
    ~safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR();
    void initialize(const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* in_struct);
    void initialize(const safe_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* copy_src);
    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR *ptr() { return reinterpret_cast<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR *>(this); }
    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR const *>(this); }
};

struct safe_VkPipelineInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkPipeline pipeline;
    safe_VkPipelineInfoKHR(const VkPipelineInfoKHR* in_struct);
    safe_VkPipelineInfoKHR(const safe_VkPipelineInfoKHR& copy_src);
    safe_VkPipelineInfoKHR& operator=(const safe_VkPipelineInfoKHR& copy_src);
    safe_VkPipelineInfoKHR();
    ~safe_VkPipelineInfoKHR();
    void initialize(const VkPipelineInfoKHR* in_struct);
    void initialize(const safe_VkPipelineInfoKHR* copy_src);
    VkPipelineInfoKHR *ptr() { return reinterpret_cast<VkPipelineInfoKHR *>(this); }
    VkPipelineInfoKHR const *ptr() const { return reinterpret_cast<VkPipelineInfoKHR const *>(this); }
};

struct safe_VkPipelineExecutablePropertiesKHR {
    VkStructureType sType;
    void* pNext;
    VkShaderStageFlags stages;
    char name[VK_MAX_DESCRIPTION_SIZE];
    char description[VK_MAX_DESCRIPTION_SIZE];
    uint32_t subgroupSize;
    safe_VkPipelineExecutablePropertiesKHR(const VkPipelineExecutablePropertiesKHR* in_struct);
    safe_VkPipelineExecutablePropertiesKHR(const safe_VkPipelineExecutablePropertiesKHR& copy_src);
    safe_VkPipelineExecutablePropertiesKHR& operator=(const safe_VkPipelineExecutablePropertiesKHR& copy_src);
    safe_VkPipelineExecutablePropertiesKHR();
    ~safe_VkPipelineExecutablePropertiesKHR();
    void initialize(const VkPipelineExecutablePropertiesKHR* in_struct);
    void initialize(const safe_VkPipelineExecutablePropertiesKHR* copy_src);
    VkPipelineExecutablePropertiesKHR *ptr() { return reinterpret_cast<VkPipelineExecutablePropertiesKHR *>(this); }
    VkPipelineExecutablePropertiesKHR const *ptr() const { return reinterpret_cast<VkPipelineExecutablePropertiesKHR const *>(this); }
};

struct safe_VkPipelineExecutableInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkPipeline pipeline;
    uint32_t executableIndex;
    safe_VkPipelineExecutableInfoKHR(const VkPipelineExecutableInfoKHR* in_struct);
    safe_VkPipelineExecutableInfoKHR(const safe_VkPipelineExecutableInfoKHR& copy_src);
    safe_VkPipelineExecutableInfoKHR& operator=(const safe_VkPipelineExecutableInfoKHR& copy_src);
    safe_VkPipelineExecutableInfoKHR();
    ~safe_VkPipelineExecutableInfoKHR();
    void initialize(const VkPipelineExecutableInfoKHR* in_struct);
    void initialize(const safe_VkPipelineExecutableInfoKHR* copy_src);
    VkPipelineExecutableInfoKHR *ptr() { return reinterpret_cast<VkPipelineExecutableInfoKHR *>(this); }
    VkPipelineExecutableInfoKHR const *ptr() const { return reinterpret_cast<VkPipelineExecutableInfoKHR const *>(this); }
};

struct safe_VkPipelineExecutableStatisticKHR {
    VkStructureType sType;
    void* pNext;
    char name[VK_MAX_DESCRIPTION_SIZE];
    char description[VK_MAX_DESCRIPTION_SIZE];
    VkPipelineExecutableStatisticFormatKHR format;
    VkPipelineExecutableStatisticValueKHR value;
    safe_VkPipelineExecutableStatisticKHR(const VkPipelineExecutableStatisticKHR* in_struct);
    safe_VkPipelineExecutableStatisticKHR(const safe_VkPipelineExecutableStatisticKHR& copy_src);
    safe_VkPipelineExecutableStatisticKHR& operator=(const safe_VkPipelineExecutableStatisticKHR& copy_src);
    safe_VkPipelineExecutableStatisticKHR();
    ~safe_VkPipelineExecutableStatisticKHR();
    void initialize(const VkPipelineExecutableStatisticKHR* in_struct);
    void initialize(const safe_VkPipelineExecutableStatisticKHR* copy_src);
    VkPipelineExecutableStatisticKHR *ptr() { return reinterpret_cast<VkPipelineExecutableStatisticKHR *>(this); }
    VkPipelineExecutableStatisticKHR const *ptr() const { return reinterpret_cast<VkPipelineExecutableStatisticKHR const *>(this); }
};

struct safe_VkPipelineExecutableInternalRepresentationKHR {
    VkStructureType sType;
    void* pNext;
    char name[VK_MAX_DESCRIPTION_SIZE];
    char description[VK_MAX_DESCRIPTION_SIZE];
    VkBool32 isText;
    size_t dataSize;
    void* pData;
    safe_VkPipelineExecutableInternalRepresentationKHR(const VkPipelineExecutableInternalRepresentationKHR* in_struct);
    safe_VkPipelineExecutableInternalRepresentationKHR(const safe_VkPipelineExecutableInternalRepresentationKHR& copy_src);
    safe_VkPipelineExecutableInternalRepresentationKHR& operator=(const safe_VkPipelineExecutableInternalRepresentationKHR& copy_src);
    safe_VkPipelineExecutableInternalRepresentationKHR();
    ~safe_VkPipelineExecutableInternalRepresentationKHR();
    void initialize(const VkPipelineExecutableInternalRepresentationKHR* in_struct);
    void initialize(const safe_VkPipelineExecutableInternalRepresentationKHR* copy_src);
    VkPipelineExecutableInternalRepresentationKHR *ptr() { return reinterpret_cast<VkPipelineExecutableInternalRepresentationKHR *>(this); }
    VkPipelineExecutableInternalRepresentationKHR const *ptr() const { return reinterpret_cast<VkPipelineExecutableInternalRepresentationKHR const *>(this); }
};

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkPipelineLibraryCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t libraryCount;
    VkPipeline* pLibraries;
    safe_VkPipelineLibraryCreateInfoKHR(const VkPipelineLibraryCreateInfoKHR* in_struct);
    safe_VkPipelineLibraryCreateInfoKHR(const safe_VkPipelineLibraryCreateInfoKHR& copy_src);
    safe_VkPipelineLibraryCreateInfoKHR& operator=(const safe_VkPipelineLibraryCreateInfoKHR& copy_src);
    safe_VkPipelineLibraryCreateInfoKHR();
    ~safe_VkPipelineLibraryCreateInfoKHR();
    void initialize(const VkPipelineLibraryCreateInfoKHR* in_struct);
    void initialize(const safe_VkPipelineLibraryCreateInfoKHR* copy_src);
    VkPipelineLibraryCreateInfoKHR *ptr() { return reinterpret_cast<VkPipelineLibraryCreateInfoKHR *>(this); }
    VkPipelineLibraryCreateInfoKHR const *ptr() const { return reinterpret_cast<VkPipelineLibraryCreateInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

struct safe_VkDebugReportCallbackCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDebugReportFlagsEXT flags;
    PFN_vkDebugReportCallbackEXT pfnCallback;
    void* pUserData;
    safe_VkDebugReportCallbackCreateInfoEXT(const VkDebugReportCallbackCreateInfoEXT* in_struct);
    safe_VkDebugReportCallbackCreateInfoEXT(const safe_VkDebugReportCallbackCreateInfoEXT& copy_src);
    safe_VkDebugReportCallbackCreateInfoEXT& operator=(const safe_VkDebugReportCallbackCreateInfoEXT& copy_src);
    safe_VkDebugReportCallbackCreateInfoEXT();
    ~safe_VkDebugReportCallbackCreateInfoEXT();
    void initialize(const VkDebugReportCallbackCreateInfoEXT* in_struct);
    void initialize(const safe_VkDebugReportCallbackCreateInfoEXT* copy_src);
    VkDebugReportCallbackCreateInfoEXT *ptr() { return reinterpret_cast<VkDebugReportCallbackCreateInfoEXT *>(this); }
    VkDebugReportCallbackCreateInfoEXT const *ptr() const { return reinterpret_cast<VkDebugReportCallbackCreateInfoEXT const *>(this); }
};

struct safe_VkPipelineRasterizationStateRasterizationOrderAMD {
    VkStructureType sType;
    const void* pNext;
    VkRasterizationOrderAMD rasterizationOrder;
    safe_VkPipelineRasterizationStateRasterizationOrderAMD(const VkPipelineRasterizationStateRasterizationOrderAMD* in_struct);
    safe_VkPipelineRasterizationStateRasterizationOrderAMD(const safe_VkPipelineRasterizationStateRasterizationOrderAMD& copy_src);
    safe_VkPipelineRasterizationStateRasterizationOrderAMD& operator=(const safe_VkPipelineRasterizationStateRasterizationOrderAMD& copy_src);
    safe_VkPipelineRasterizationStateRasterizationOrderAMD();
    ~safe_VkPipelineRasterizationStateRasterizationOrderAMD();
    void initialize(const VkPipelineRasterizationStateRasterizationOrderAMD* in_struct);
    void initialize(const safe_VkPipelineRasterizationStateRasterizationOrderAMD* copy_src);
    VkPipelineRasterizationStateRasterizationOrderAMD *ptr() { return reinterpret_cast<VkPipelineRasterizationStateRasterizationOrderAMD *>(this); }
    VkPipelineRasterizationStateRasterizationOrderAMD const *ptr() const { return reinterpret_cast<VkPipelineRasterizationStateRasterizationOrderAMD const *>(this); }
};

struct safe_VkDebugMarkerObjectNameInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    const char* pObjectName;
    safe_VkDebugMarkerObjectNameInfoEXT(const VkDebugMarkerObjectNameInfoEXT* in_struct);
    safe_VkDebugMarkerObjectNameInfoEXT(const safe_VkDebugMarkerObjectNameInfoEXT& copy_src);
    safe_VkDebugMarkerObjectNameInfoEXT& operator=(const safe_VkDebugMarkerObjectNameInfoEXT& copy_src);
    safe_VkDebugMarkerObjectNameInfoEXT();
    ~safe_VkDebugMarkerObjectNameInfoEXT();
    void initialize(const VkDebugMarkerObjectNameInfoEXT* in_struct);
    void initialize(const safe_VkDebugMarkerObjectNameInfoEXT* copy_src);
    VkDebugMarkerObjectNameInfoEXT *ptr() { return reinterpret_cast<VkDebugMarkerObjectNameInfoEXT *>(this); }
    VkDebugMarkerObjectNameInfoEXT const *ptr() const { return reinterpret_cast<VkDebugMarkerObjectNameInfoEXT const *>(this); }
};

struct safe_VkDebugMarkerObjectTagInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    uint64_t tagName;
    size_t tagSize;
    const void* pTag;
    safe_VkDebugMarkerObjectTagInfoEXT(const VkDebugMarkerObjectTagInfoEXT* in_struct);
    safe_VkDebugMarkerObjectTagInfoEXT(const safe_VkDebugMarkerObjectTagInfoEXT& copy_src);
    safe_VkDebugMarkerObjectTagInfoEXT& operator=(const safe_VkDebugMarkerObjectTagInfoEXT& copy_src);
    safe_VkDebugMarkerObjectTagInfoEXT();
    ~safe_VkDebugMarkerObjectTagInfoEXT();
    void initialize(const VkDebugMarkerObjectTagInfoEXT* in_struct);
    void initialize(const safe_VkDebugMarkerObjectTagInfoEXT* copy_src);
    VkDebugMarkerObjectTagInfoEXT *ptr() { return reinterpret_cast<VkDebugMarkerObjectTagInfoEXT *>(this); }
    VkDebugMarkerObjectTagInfoEXT const *ptr() const { return reinterpret_cast<VkDebugMarkerObjectTagInfoEXT const *>(this); }
};

struct safe_VkDebugMarkerMarkerInfoEXT {
    VkStructureType sType;
    const void* pNext;
    const char* pMarkerName;
    float color[4];
    safe_VkDebugMarkerMarkerInfoEXT(const VkDebugMarkerMarkerInfoEXT* in_struct);
    safe_VkDebugMarkerMarkerInfoEXT(const safe_VkDebugMarkerMarkerInfoEXT& copy_src);
    safe_VkDebugMarkerMarkerInfoEXT& operator=(const safe_VkDebugMarkerMarkerInfoEXT& copy_src);
    safe_VkDebugMarkerMarkerInfoEXT();
    ~safe_VkDebugMarkerMarkerInfoEXT();
    void initialize(const VkDebugMarkerMarkerInfoEXT* in_struct);
    void initialize(const safe_VkDebugMarkerMarkerInfoEXT* copy_src);
    VkDebugMarkerMarkerInfoEXT *ptr() { return reinterpret_cast<VkDebugMarkerMarkerInfoEXT *>(this); }
    VkDebugMarkerMarkerInfoEXT const *ptr() const { return reinterpret_cast<VkDebugMarkerMarkerInfoEXT const *>(this); }
};

struct safe_VkDedicatedAllocationImageCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkBool32 dedicatedAllocation;
    safe_VkDedicatedAllocationImageCreateInfoNV(const VkDedicatedAllocationImageCreateInfoNV* in_struct);
    safe_VkDedicatedAllocationImageCreateInfoNV(const safe_VkDedicatedAllocationImageCreateInfoNV& copy_src);
    safe_VkDedicatedAllocationImageCreateInfoNV& operator=(const safe_VkDedicatedAllocationImageCreateInfoNV& copy_src);
    safe_VkDedicatedAllocationImageCreateInfoNV();
    ~safe_VkDedicatedAllocationImageCreateInfoNV();
    void initialize(const VkDedicatedAllocationImageCreateInfoNV* in_struct);
    void initialize(const safe_VkDedicatedAllocationImageCreateInfoNV* copy_src);
    VkDedicatedAllocationImageCreateInfoNV *ptr() { return reinterpret_cast<VkDedicatedAllocationImageCreateInfoNV *>(this); }
    VkDedicatedAllocationImageCreateInfoNV const *ptr() const { return reinterpret_cast<VkDedicatedAllocationImageCreateInfoNV const *>(this); }
};

struct safe_VkDedicatedAllocationBufferCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkBool32 dedicatedAllocation;
    safe_VkDedicatedAllocationBufferCreateInfoNV(const VkDedicatedAllocationBufferCreateInfoNV* in_struct);
    safe_VkDedicatedAllocationBufferCreateInfoNV(const safe_VkDedicatedAllocationBufferCreateInfoNV& copy_src);
    safe_VkDedicatedAllocationBufferCreateInfoNV& operator=(const safe_VkDedicatedAllocationBufferCreateInfoNV& copy_src);
    safe_VkDedicatedAllocationBufferCreateInfoNV();
    ~safe_VkDedicatedAllocationBufferCreateInfoNV();
    void initialize(const VkDedicatedAllocationBufferCreateInfoNV* in_struct);
    void initialize(const safe_VkDedicatedAllocationBufferCreateInfoNV* copy_src);
    VkDedicatedAllocationBufferCreateInfoNV *ptr() { return reinterpret_cast<VkDedicatedAllocationBufferCreateInfoNV *>(this); }
    VkDedicatedAllocationBufferCreateInfoNV const *ptr() const { return reinterpret_cast<VkDedicatedAllocationBufferCreateInfoNV const *>(this); }
};

struct safe_VkDedicatedAllocationMemoryAllocateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkImage image;
    VkBuffer buffer;
    safe_VkDedicatedAllocationMemoryAllocateInfoNV(const VkDedicatedAllocationMemoryAllocateInfoNV* in_struct);
    safe_VkDedicatedAllocationMemoryAllocateInfoNV(const safe_VkDedicatedAllocationMemoryAllocateInfoNV& copy_src);
    safe_VkDedicatedAllocationMemoryAllocateInfoNV& operator=(const safe_VkDedicatedAllocationMemoryAllocateInfoNV& copy_src);
    safe_VkDedicatedAllocationMemoryAllocateInfoNV();
    ~safe_VkDedicatedAllocationMemoryAllocateInfoNV();
    void initialize(const VkDedicatedAllocationMemoryAllocateInfoNV* in_struct);
    void initialize(const safe_VkDedicatedAllocationMemoryAllocateInfoNV* copy_src);
    VkDedicatedAllocationMemoryAllocateInfoNV *ptr() { return reinterpret_cast<VkDedicatedAllocationMemoryAllocateInfoNV *>(this); }
    VkDedicatedAllocationMemoryAllocateInfoNV const *ptr() const { return reinterpret_cast<VkDedicatedAllocationMemoryAllocateInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 transformFeedback;
    VkBool32 geometryStreams;
    safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT(const VkPhysicalDeviceTransformFeedbackFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT(const safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT& operator=(const safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT();
    ~safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT();
    void initialize(const VkPhysicalDeviceTransformFeedbackFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceTransformFeedbackFeaturesEXT* copy_src);
    VkPhysicalDeviceTransformFeedbackFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT *>(this); }
    VkPhysicalDeviceTransformFeedbackFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTransformFeedbackFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t maxTransformFeedbackStreams;
    uint32_t maxTransformFeedbackBuffers;
    VkDeviceSize maxTransformFeedbackBufferSize;
    uint32_t maxTransformFeedbackStreamDataSize;
    uint32_t maxTransformFeedbackBufferDataSize;
    uint32_t maxTransformFeedbackBufferDataStride;
    VkBool32 transformFeedbackQueries;
    VkBool32 transformFeedbackStreamsLinesTriangles;
    VkBool32 transformFeedbackRasterizationStreamSelect;
    VkBool32 transformFeedbackDraw;
    safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT(const VkPhysicalDeviceTransformFeedbackPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT(const safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT& operator=(const safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT();
    ~safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT();
    void initialize(const VkPhysicalDeviceTransformFeedbackPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceTransformFeedbackPropertiesEXT* copy_src);
    VkPhysicalDeviceTransformFeedbackPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceTransformFeedbackPropertiesEXT *>(this); }
    VkPhysicalDeviceTransformFeedbackPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTransformFeedbackPropertiesEXT const *>(this); }
};

struct safe_VkPipelineRasterizationStateStreamCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkPipelineRasterizationStateStreamCreateFlagsEXT flags;
    uint32_t rasterizationStream;
    safe_VkPipelineRasterizationStateStreamCreateInfoEXT(const VkPipelineRasterizationStateStreamCreateInfoEXT* in_struct);
    safe_VkPipelineRasterizationStateStreamCreateInfoEXT(const safe_VkPipelineRasterizationStateStreamCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationStateStreamCreateInfoEXT& operator=(const safe_VkPipelineRasterizationStateStreamCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationStateStreamCreateInfoEXT();
    ~safe_VkPipelineRasterizationStateStreamCreateInfoEXT();
    void initialize(const VkPipelineRasterizationStateStreamCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineRasterizationStateStreamCreateInfoEXT* copy_src);
    VkPipelineRasterizationStateStreamCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineRasterizationStateStreamCreateInfoEXT *>(this); }
    VkPipelineRasterizationStateStreamCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineRasterizationStateStreamCreateInfoEXT const *>(this); }
};

struct safe_VkImageViewHandleInfoNVX {
    VkStructureType sType;
    const void* pNext;
    VkImageView imageView;
    VkDescriptorType descriptorType;
    VkSampler sampler;
    safe_VkImageViewHandleInfoNVX(const VkImageViewHandleInfoNVX* in_struct);
    safe_VkImageViewHandleInfoNVX(const safe_VkImageViewHandleInfoNVX& copy_src);
    safe_VkImageViewHandleInfoNVX& operator=(const safe_VkImageViewHandleInfoNVX& copy_src);
    safe_VkImageViewHandleInfoNVX();
    ~safe_VkImageViewHandleInfoNVX();
    void initialize(const VkImageViewHandleInfoNVX* in_struct);
    void initialize(const safe_VkImageViewHandleInfoNVX* copy_src);
    VkImageViewHandleInfoNVX *ptr() { return reinterpret_cast<VkImageViewHandleInfoNVX *>(this); }
    VkImageViewHandleInfoNVX const *ptr() const { return reinterpret_cast<VkImageViewHandleInfoNVX const *>(this); }
};

struct safe_VkImageViewAddressPropertiesNVX {
    VkStructureType sType;
    void* pNext;
    VkDeviceAddress deviceAddress;
    VkDeviceSize size;
    safe_VkImageViewAddressPropertiesNVX(const VkImageViewAddressPropertiesNVX* in_struct);
    safe_VkImageViewAddressPropertiesNVX(const safe_VkImageViewAddressPropertiesNVX& copy_src);
    safe_VkImageViewAddressPropertiesNVX& operator=(const safe_VkImageViewAddressPropertiesNVX& copy_src);
    safe_VkImageViewAddressPropertiesNVX();
    ~safe_VkImageViewAddressPropertiesNVX();
    void initialize(const VkImageViewAddressPropertiesNVX* in_struct);
    void initialize(const safe_VkImageViewAddressPropertiesNVX* copy_src);
    VkImageViewAddressPropertiesNVX *ptr() { return reinterpret_cast<VkImageViewAddressPropertiesNVX *>(this); }
    VkImageViewAddressPropertiesNVX const *ptr() const { return reinterpret_cast<VkImageViewAddressPropertiesNVX const *>(this); }
};

struct safe_VkTextureLODGatherFormatPropertiesAMD {
    VkStructureType sType;
    void* pNext;
    VkBool32 supportsTextureGatherLODBiasAMD;
    safe_VkTextureLODGatherFormatPropertiesAMD(const VkTextureLODGatherFormatPropertiesAMD* in_struct);
    safe_VkTextureLODGatherFormatPropertiesAMD(const safe_VkTextureLODGatherFormatPropertiesAMD& copy_src);
    safe_VkTextureLODGatherFormatPropertiesAMD& operator=(const safe_VkTextureLODGatherFormatPropertiesAMD& copy_src);
    safe_VkTextureLODGatherFormatPropertiesAMD();
    ~safe_VkTextureLODGatherFormatPropertiesAMD();
    void initialize(const VkTextureLODGatherFormatPropertiesAMD* in_struct);
    void initialize(const safe_VkTextureLODGatherFormatPropertiesAMD* copy_src);
    VkTextureLODGatherFormatPropertiesAMD *ptr() { return reinterpret_cast<VkTextureLODGatherFormatPropertiesAMD *>(this); }
    VkTextureLODGatherFormatPropertiesAMD const *ptr() const { return reinterpret_cast<VkTextureLODGatherFormatPropertiesAMD const *>(this); }
};

#ifdef VK_USE_PLATFORM_GGP
struct safe_VkStreamDescriptorSurfaceCreateInfoGGP {
    VkStructureType sType;
    const void* pNext;
    VkStreamDescriptorSurfaceCreateFlagsGGP flags;
    GgpStreamDescriptor streamDescriptor;
    safe_VkStreamDescriptorSurfaceCreateInfoGGP(const VkStreamDescriptorSurfaceCreateInfoGGP* in_struct);
    safe_VkStreamDescriptorSurfaceCreateInfoGGP(const safe_VkStreamDescriptorSurfaceCreateInfoGGP& copy_src);
    safe_VkStreamDescriptorSurfaceCreateInfoGGP& operator=(const safe_VkStreamDescriptorSurfaceCreateInfoGGP& copy_src);
    safe_VkStreamDescriptorSurfaceCreateInfoGGP();
    ~safe_VkStreamDescriptorSurfaceCreateInfoGGP();
    void initialize(const VkStreamDescriptorSurfaceCreateInfoGGP* in_struct);
    void initialize(const safe_VkStreamDescriptorSurfaceCreateInfoGGP* copy_src);
    VkStreamDescriptorSurfaceCreateInfoGGP *ptr() { return reinterpret_cast<VkStreamDescriptorSurfaceCreateInfoGGP *>(this); }
    VkStreamDescriptorSurfaceCreateInfoGGP const *ptr() const { return reinterpret_cast<VkStreamDescriptorSurfaceCreateInfoGGP const *>(this); }
};
#endif // VK_USE_PLATFORM_GGP

struct safe_VkPhysicalDeviceCornerSampledImageFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 cornerSampledImage;
    safe_VkPhysicalDeviceCornerSampledImageFeaturesNV(const VkPhysicalDeviceCornerSampledImageFeaturesNV* in_struct);
    safe_VkPhysicalDeviceCornerSampledImageFeaturesNV(const safe_VkPhysicalDeviceCornerSampledImageFeaturesNV& copy_src);
    safe_VkPhysicalDeviceCornerSampledImageFeaturesNV& operator=(const safe_VkPhysicalDeviceCornerSampledImageFeaturesNV& copy_src);
    safe_VkPhysicalDeviceCornerSampledImageFeaturesNV();
    ~safe_VkPhysicalDeviceCornerSampledImageFeaturesNV();
    void initialize(const VkPhysicalDeviceCornerSampledImageFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceCornerSampledImageFeaturesNV* copy_src);
    VkPhysicalDeviceCornerSampledImageFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceCornerSampledImageFeaturesNV *>(this); }
    VkPhysicalDeviceCornerSampledImageFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceCornerSampledImageFeaturesNV const *>(this); }
};

struct safe_VkExternalMemoryImageCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagsNV handleTypes;
    safe_VkExternalMemoryImageCreateInfoNV(const VkExternalMemoryImageCreateInfoNV* in_struct);
    safe_VkExternalMemoryImageCreateInfoNV(const safe_VkExternalMemoryImageCreateInfoNV& copy_src);
    safe_VkExternalMemoryImageCreateInfoNV& operator=(const safe_VkExternalMemoryImageCreateInfoNV& copy_src);
    safe_VkExternalMemoryImageCreateInfoNV();
    ~safe_VkExternalMemoryImageCreateInfoNV();
    void initialize(const VkExternalMemoryImageCreateInfoNV* in_struct);
    void initialize(const safe_VkExternalMemoryImageCreateInfoNV* copy_src);
    VkExternalMemoryImageCreateInfoNV *ptr() { return reinterpret_cast<VkExternalMemoryImageCreateInfoNV *>(this); }
    VkExternalMemoryImageCreateInfoNV const *ptr() const { return reinterpret_cast<VkExternalMemoryImageCreateInfoNV const *>(this); }
};

struct safe_VkExportMemoryAllocateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagsNV handleTypes;
    safe_VkExportMemoryAllocateInfoNV(const VkExportMemoryAllocateInfoNV* in_struct);
    safe_VkExportMemoryAllocateInfoNV(const safe_VkExportMemoryAllocateInfoNV& copy_src);
    safe_VkExportMemoryAllocateInfoNV& operator=(const safe_VkExportMemoryAllocateInfoNV& copy_src);
    safe_VkExportMemoryAllocateInfoNV();
    ~safe_VkExportMemoryAllocateInfoNV();
    void initialize(const VkExportMemoryAllocateInfoNV* in_struct);
    void initialize(const safe_VkExportMemoryAllocateInfoNV* copy_src);
    VkExportMemoryAllocateInfoNV *ptr() { return reinterpret_cast<VkExportMemoryAllocateInfoNV *>(this); }
    VkExportMemoryAllocateInfoNV const *ptr() const { return reinterpret_cast<VkExportMemoryAllocateInfoNV const *>(this); }
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkImportMemoryWin32HandleInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    HANDLE handle;
    safe_VkImportMemoryWin32HandleInfoNV(const VkImportMemoryWin32HandleInfoNV* in_struct);
    safe_VkImportMemoryWin32HandleInfoNV(const safe_VkImportMemoryWin32HandleInfoNV& copy_src);
    safe_VkImportMemoryWin32HandleInfoNV& operator=(const safe_VkImportMemoryWin32HandleInfoNV& copy_src);
    safe_VkImportMemoryWin32HandleInfoNV();
    ~safe_VkImportMemoryWin32HandleInfoNV();
    void initialize(const VkImportMemoryWin32HandleInfoNV* in_struct);
    void initialize(const safe_VkImportMemoryWin32HandleInfoNV* copy_src);
    VkImportMemoryWin32HandleInfoNV *ptr() { return reinterpret_cast<VkImportMemoryWin32HandleInfoNV *>(this); }
    VkImportMemoryWin32HandleInfoNV const *ptr() const { return reinterpret_cast<VkImportMemoryWin32HandleInfoNV const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkExportMemoryWin32HandleInfoNV {
    VkStructureType sType;
    const void* pNext;
    const SECURITY_ATTRIBUTES* pAttributes;
    DWORD dwAccess;
    safe_VkExportMemoryWin32HandleInfoNV(const VkExportMemoryWin32HandleInfoNV* in_struct);
    safe_VkExportMemoryWin32HandleInfoNV(const safe_VkExportMemoryWin32HandleInfoNV& copy_src);
    safe_VkExportMemoryWin32HandleInfoNV& operator=(const safe_VkExportMemoryWin32HandleInfoNV& copy_src);
    safe_VkExportMemoryWin32HandleInfoNV();
    ~safe_VkExportMemoryWin32HandleInfoNV();
    void initialize(const VkExportMemoryWin32HandleInfoNV* in_struct);
    void initialize(const safe_VkExportMemoryWin32HandleInfoNV* copy_src);
    VkExportMemoryWin32HandleInfoNV *ptr() { return reinterpret_cast<VkExportMemoryWin32HandleInfoNV *>(this); }
    VkExportMemoryWin32HandleInfoNV const *ptr() const { return reinterpret_cast<VkExportMemoryWin32HandleInfoNV const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkWin32KeyedMutexAcquireReleaseInfoNV {
    VkStructureType sType;
    const void* pNext;
    uint32_t acquireCount;
    VkDeviceMemory* pAcquireSyncs;
    const uint64_t* pAcquireKeys;
    const uint32_t* pAcquireTimeoutMilliseconds;
    uint32_t releaseCount;
    VkDeviceMemory* pReleaseSyncs;
    const uint64_t* pReleaseKeys;
    safe_VkWin32KeyedMutexAcquireReleaseInfoNV(const VkWin32KeyedMutexAcquireReleaseInfoNV* in_struct);
    safe_VkWin32KeyedMutexAcquireReleaseInfoNV(const safe_VkWin32KeyedMutexAcquireReleaseInfoNV& copy_src);
    safe_VkWin32KeyedMutexAcquireReleaseInfoNV& operator=(const safe_VkWin32KeyedMutexAcquireReleaseInfoNV& copy_src);
    safe_VkWin32KeyedMutexAcquireReleaseInfoNV();
    ~safe_VkWin32KeyedMutexAcquireReleaseInfoNV();
    void initialize(const VkWin32KeyedMutexAcquireReleaseInfoNV* in_struct);
    void initialize(const safe_VkWin32KeyedMutexAcquireReleaseInfoNV* copy_src);
    VkWin32KeyedMutexAcquireReleaseInfoNV *ptr() { return reinterpret_cast<VkWin32KeyedMutexAcquireReleaseInfoNV *>(this); }
    VkWin32KeyedMutexAcquireReleaseInfoNV const *ptr() const { return reinterpret_cast<VkWin32KeyedMutexAcquireReleaseInfoNV const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

struct safe_VkValidationFlagsEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t disabledValidationCheckCount;
    const VkValidationCheckEXT* pDisabledValidationChecks;
    safe_VkValidationFlagsEXT(const VkValidationFlagsEXT* in_struct);
    safe_VkValidationFlagsEXT(const safe_VkValidationFlagsEXT& copy_src);
    safe_VkValidationFlagsEXT& operator=(const safe_VkValidationFlagsEXT& copy_src);
    safe_VkValidationFlagsEXT();
    ~safe_VkValidationFlagsEXT();
    void initialize(const VkValidationFlagsEXT* in_struct);
    void initialize(const safe_VkValidationFlagsEXT* copy_src);
    VkValidationFlagsEXT *ptr() { return reinterpret_cast<VkValidationFlagsEXT *>(this); }
    VkValidationFlagsEXT const *ptr() const { return reinterpret_cast<VkValidationFlagsEXT const *>(this); }
};

#ifdef VK_USE_PLATFORM_VI_NN
struct safe_VkViSurfaceCreateInfoNN {
    VkStructureType sType;
    const void* pNext;
    VkViSurfaceCreateFlagsNN flags;
    void* window;
    safe_VkViSurfaceCreateInfoNN(const VkViSurfaceCreateInfoNN* in_struct);
    safe_VkViSurfaceCreateInfoNN(const safe_VkViSurfaceCreateInfoNN& copy_src);
    safe_VkViSurfaceCreateInfoNN& operator=(const safe_VkViSurfaceCreateInfoNN& copy_src);
    safe_VkViSurfaceCreateInfoNN();
    ~safe_VkViSurfaceCreateInfoNN();
    void initialize(const VkViSurfaceCreateInfoNN* in_struct);
    void initialize(const safe_VkViSurfaceCreateInfoNN* copy_src);
    VkViSurfaceCreateInfoNN *ptr() { return reinterpret_cast<VkViSurfaceCreateInfoNN *>(this); }
    VkViSurfaceCreateInfoNN const *ptr() const { return reinterpret_cast<VkViSurfaceCreateInfoNN const *>(this); }
};
#endif // VK_USE_PLATFORM_VI_NN

struct safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 textureCompressionASTC_HDR;
    safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT(const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT(const safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT& operator=(const safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT();
    ~safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT();
    void initialize(const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT* copy_src);
    VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *>(this); }
    VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT const *>(this); }
};

struct safe_VkImageViewASTCDecodeModeEXT {
    VkStructureType sType;
    const void* pNext;
    VkFormat decodeMode;
    safe_VkImageViewASTCDecodeModeEXT(const VkImageViewASTCDecodeModeEXT* in_struct);
    safe_VkImageViewASTCDecodeModeEXT(const safe_VkImageViewASTCDecodeModeEXT& copy_src);
    safe_VkImageViewASTCDecodeModeEXT& operator=(const safe_VkImageViewASTCDecodeModeEXT& copy_src);
    safe_VkImageViewASTCDecodeModeEXT();
    ~safe_VkImageViewASTCDecodeModeEXT();
    void initialize(const VkImageViewASTCDecodeModeEXT* in_struct);
    void initialize(const safe_VkImageViewASTCDecodeModeEXT* copy_src);
    VkImageViewASTCDecodeModeEXT *ptr() { return reinterpret_cast<VkImageViewASTCDecodeModeEXT *>(this); }
    VkImageViewASTCDecodeModeEXT const *ptr() const { return reinterpret_cast<VkImageViewASTCDecodeModeEXT const *>(this); }
};

struct safe_VkPhysicalDeviceASTCDecodeFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 decodeModeSharedExponent;
    safe_VkPhysicalDeviceASTCDecodeFeaturesEXT(const VkPhysicalDeviceASTCDecodeFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceASTCDecodeFeaturesEXT(const safe_VkPhysicalDeviceASTCDecodeFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceASTCDecodeFeaturesEXT& operator=(const safe_VkPhysicalDeviceASTCDecodeFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceASTCDecodeFeaturesEXT();
    ~safe_VkPhysicalDeviceASTCDecodeFeaturesEXT();
    void initialize(const VkPhysicalDeviceASTCDecodeFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceASTCDecodeFeaturesEXT* copy_src);
    VkPhysicalDeviceASTCDecodeFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceASTCDecodeFeaturesEXT *>(this); }
    VkPhysicalDeviceASTCDecodeFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceASTCDecodeFeaturesEXT const *>(this); }
};

struct safe_VkConditionalRenderingBeginInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkConditionalRenderingFlagsEXT flags;
    safe_VkConditionalRenderingBeginInfoEXT(const VkConditionalRenderingBeginInfoEXT* in_struct);
    safe_VkConditionalRenderingBeginInfoEXT(const safe_VkConditionalRenderingBeginInfoEXT& copy_src);
    safe_VkConditionalRenderingBeginInfoEXT& operator=(const safe_VkConditionalRenderingBeginInfoEXT& copy_src);
    safe_VkConditionalRenderingBeginInfoEXT();
    ~safe_VkConditionalRenderingBeginInfoEXT();
    void initialize(const VkConditionalRenderingBeginInfoEXT* in_struct);
    void initialize(const safe_VkConditionalRenderingBeginInfoEXT* copy_src);
    VkConditionalRenderingBeginInfoEXT *ptr() { return reinterpret_cast<VkConditionalRenderingBeginInfoEXT *>(this); }
    VkConditionalRenderingBeginInfoEXT const *ptr() const { return reinterpret_cast<VkConditionalRenderingBeginInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 conditionalRendering;
    VkBool32 inheritedConditionalRendering;
    safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT(const VkPhysicalDeviceConditionalRenderingFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT(const safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT& operator=(const safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT();
    ~safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT();
    void initialize(const VkPhysicalDeviceConditionalRenderingFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceConditionalRenderingFeaturesEXT* copy_src);
    VkPhysicalDeviceConditionalRenderingFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT *>(this); }
    VkPhysicalDeviceConditionalRenderingFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceConditionalRenderingFeaturesEXT const *>(this); }
};

struct safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkBool32 conditionalRenderingEnable;
    safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT(const VkCommandBufferInheritanceConditionalRenderingInfoEXT* in_struct);
    safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT(const safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT& copy_src);
    safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT& operator=(const safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT& copy_src);
    safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT();
    ~safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT();
    void initialize(const VkCommandBufferInheritanceConditionalRenderingInfoEXT* in_struct);
    void initialize(const safe_VkCommandBufferInheritanceConditionalRenderingInfoEXT* copy_src);
    VkCommandBufferInheritanceConditionalRenderingInfoEXT *ptr() { return reinterpret_cast<VkCommandBufferInheritanceConditionalRenderingInfoEXT *>(this); }
    VkCommandBufferInheritanceConditionalRenderingInfoEXT const *ptr() const { return reinterpret_cast<VkCommandBufferInheritanceConditionalRenderingInfoEXT const *>(this); }
};

struct safe_VkPipelineViewportWScalingStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkBool32 viewportWScalingEnable;
    uint32_t viewportCount;
    const VkViewportWScalingNV* pViewportWScalings;
    safe_VkPipelineViewportWScalingStateCreateInfoNV(const VkPipelineViewportWScalingStateCreateInfoNV* in_struct);
    safe_VkPipelineViewportWScalingStateCreateInfoNV(const safe_VkPipelineViewportWScalingStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportWScalingStateCreateInfoNV& operator=(const safe_VkPipelineViewportWScalingStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportWScalingStateCreateInfoNV();
    ~safe_VkPipelineViewportWScalingStateCreateInfoNV();
    void initialize(const VkPipelineViewportWScalingStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineViewportWScalingStateCreateInfoNV* copy_src);
    VkPipelineViewportWScalingStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineViewportWScalingStateCreateInfoNV *>(this); }
    VkPipelineViewportWScalingStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineViewportWScalingStateCreateInfoNV const *>(this); }
};

struct safe_VkSurfaceCapabilities2EXT {
    VkStructureType sType;
    void* pNext;
    uint32_t minImageCount;
    uint32_t maxImageCount;
    VkExtent2D currentExtent;
    VkExtent2D minImageExtent;
    VkExtent2D maxImageExtent;
    uint32_t maxImageArrayLayers;
    VkSurfaceTransformFlagsKHR supportedTransforms;
    VkSurfaceTransformFlagBitsKHR currentTransform;
    VkCompositeAlphaFlagsKHR supportedCompositeAlpha;
    VkImageUsageFlags supportedUsageFlags;
    VkSurfaceCounterFlagsEXT supportedSurfaceCounters;
    safe_VkSurfaceCapabilities2EXT(const VkSurfaceCapabilities2EXT* in_struct);
    safe_VkSurfaceCapabilities2EXT(const safe_VkSurfaceCapabilities2EXT& copy_src);
    safe_VkSurfaceCapabilities2EXT& operator=(const safe_VkSurfaceCapabilities2EXT& copy_src);
    safe_VkSurfaceCapabilities2EXT();
    ~safe_VkSurfaceCapabilities2EXT();
    void initialize(const VkSurfaceCapabilities2EXT* in_struct);
    void initialize(const safe_VkSurfaceCapabilities2EXT* copy_src);
    VkSurfaceCapabilities2EXT *ptr() { return reinterpret_cast<VkSurfaceCapabilities2EXT *>(this); }
    VkSurfaceCapabilities2EXT const *ptr() const { return reinterpret_cast<VkSurfaceCapabilities2EXT const *>(this); }
};

struct safe_VkDisplayPowerInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDisplayPowerStateEXT powerState;
    safe_VkDisplayPowerInfoEXT(const VkDisplayPowerInfoEXT* in_struct);
    safe_VkDisplayPowerInfoEXT(const safe_VkDisplayPowerInfoEXT& copy_src);
    safe_VkDisplayPowerInfoEXT& operator=(const safe_VkDisplayPowerInfoEXT& copy_src);
    safe_VkDisplayPowerInfoEXT();
    ~safe_VkDisplayPowerInfoEXT();
    void initialize(const VkDisplayPowerInfoEXT* in_struct);
    void initialize(const safe_VkDisplayPowerInfoEXT* copy_src);
    VkDisplayPowerInfoEXT *ptr() { return reinterpret_cast<VkDisplayPowerInfoEXT *>(this); }
    VkDisplayPowerInfoEXT const *ptr() const { return reinterpret_cast<VkDisplayPowerInfoEXT const *>(this); }
};

struct safe_VkDeviceEventInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDeviceEventTypeEXT deviceEvent;
    safe_VkDeviceEventInfoEXT(const VkDeviceEventInfoEXT* in_struct);
    safe_VkDeviceEventInfoEXT(const safe_VkDeviceEventInfoEXT& copy_src);
    safe_VkDeviceEventInfoEXT& operator=(const safe_VkDeviceEventInfoEXT& copy_src);
    safe_VkDeviceEventInfoEXT();
    ~safe_VkDeviceEventInfoEXT();
    void initialize(const VkDeviceEventInfoEXT* in_struct);
    void initialize(const safe_VkDeviceEventInfoEXT* copy_src);
    VkDeviceEventInfoEXT *ptr() { return reinterpret_cast<VkDeviceEventInfoEXT *>(this); }
    VkDeviceEventInfoEXT const *ptr() const { return reinterpret_cast<VkDeviceEventInfoEXT const *>(this); }
};

struct safe_VkDisplayEventInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDisplayEventTypeEXT displayEvent;
    safe_VkDisplayEventInfoEXT(const VkDisplayEventInfoEXT* in_struct);
    safe_VkDisplayEventInfoEXT(const safe_VkDisplayEventInfoEXT& copy_src);
    safe_VkDisplayEventInfoEXT& operator=(const safe_VkDisplayEventInfoEXT& copy_src);
    safe_VkDisplayEventInfoEXT();
    ~safe_VkDisplayEventInfoEXT();
    void initialize(const VkDisplayEventInfoEXT* in_struct);
    void initialize(const safe_VkDisplayEventInfoEXT* copy_src);
    VkDisplayEventInfoEXT *ptr() { return reinterpret_cast<VkDisplayEventInfoEXT *>(this); }
    VkDisplayEventInfoEXT const *ptr() const { return reinterpret_cast<VkDisplayEventInfoEXT const *>(this); }
};

struct safe_VkSwapchainCounterCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkSurfaceCounterFlagsEXT surfaceCounters;
    safe_VkSwapchainCounterCreateInfoEXT(const VkSwapchainCounterCreateInfoEXT* in_struct);
    safe_VkSwapchainCounterCreateInfoEXT(const safe_VkSwapchainCounterCreateInfoEXT& copy_src);
    safe_VkSwapchainCounterCreateInfoEXT& operator=(const safe_VkSwapchainCounterCreateInfoEXT& copy_src);
    safe_VkSwapchainCounterCreateInfoEXT();
    ~safe_VkSwapchainCounterCreateInfoEXT();
    void initialize(const VkSwapchainCounterCreateInfoEXT* in_struct);
    void initialize(const safe_VkSwapchainCounterCreateInfoEXT* copy_src);
    VkSwapchainCounterCreateInfoEXT *ptr() { return reinterpret_cast<VkSwapchainCounterCreateInfoEXT *>(this); }
    VkSwapchainCounterCreateInfoEXT const *ptr() const { return reinterpret_cast<VkSwapchainCounterCreateInfoEXT const *>(this); }
};

struct safe_VkPresentTimesInfoGOOGLE {
    VkStructureType sType;
    const void* pNext;
    uint32_t swapchainCount;
    const VkPresentTimeGOOGLE* pTimes;
    safe_VkPresentTimesInfoGOOGLE(const VkPresentTimesInfoGOOGLE* in_struct);
    safe_VkPresentTimesInfoGOOGLE(const safe_VkPresentTimesInfoGOOGLE& copy_src);
    safe_VkPresentTimesInfoGOOGLE& operator=(const safe_VkPresentTimesInfoGOOGLE& copy_src);
    safe_VkPresentTimesInfoGOOGLE();
    ~safe_VkPresentTimesInfoGOOGLE();
    void initialize(const VkPresentTimesInfoGOOGLE* in_struct);
    void initialize(const safe_VkPresentTimesInfoGOOGLE* copy_src);
    VkPresentTimesInfoGOOGLE *ptr() { return reinterpret_cast<VkPresentTimesInfoGOOGLE *>(this); }
    VkPresentTimesInfoGOOGLE const *ptr() const { return reinterpret_cast<VkPresentTimesInfoGOOGLE const *>(this); }
};

struct safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX {
    VkStructureType sType;
    void* pNext;
    VkBool32 perViewPositionAllComponents;
    safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* in_struct);
    safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(const safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& copy_src);
    safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& operator=(const safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& copy_src);
    safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX();
    ~safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX();
    void initialize(const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* in_struct);
    void initialize(const safe_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* copy_src);
    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *ptr() { return reinterpret_cast<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *>(this); }
    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX const *>(this); }
};

struct safe_VkPipelineViewportSwizzleStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineViewportSwizzleStateCreateFlagsNV flags;
    uint32_t viewportCount;
    const VkViewportSwizzleNV* pViewportSwizzles;
    safe_VkPipelineViewportSwizzleStateCreateInfoNV(const VkPipelineViewportSwizzleStateCreateInfoNV* in_struct);
    safe_VkPipelineViewportSwizzleStateCreateInfoNV(const safe_VkPipelineViewportSwizzleStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportSwizzleStateCreateInfoNV& operator=(const safe_VkPipelineViewportSwizzleStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportSwizzleStateCreateInfoNV();
    ~safe_VkPipelineViewportSwizzleStateCreateInfoNV();
    void initialize(const VkPipelineViewportSwizzleStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineViewportSwizzleStateCreateInfoNV* copy_src);
    VkPipelineViewportSwizzleStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineViewportSwizzleStateCreateInfoNV *>(this); }
    VkPipelineViewportSwizzleStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineViewportSwizzleStateCreateInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t maxDiscardRectangles;
    safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT(const VkPhysicalDeviceDiscardRectanglePropertiesEXT* in_struct);
    safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT(const safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT& copy_src);
    safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT& operator=(const safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT& copy_src);
    safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT();
    ~safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT();
    void initialize(const VkPhysicalDeviceDiscardRectanglePropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceDiscardRectanglePropertiesEXT* copy_src);
    VkPhysicalDeviceDiscardRectanglePropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceDiscardRectanglePropertiesEXT *>(this); }
    VkPhysicalDeviceDiscardRectanglePropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDiscardRectanglePropertiesEXT const *>(this); }
};

struct safe_VkPipelineDiscardRectangleStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkPipelineDiscardRectangleStateCreateFlagsEXT flags;
    VkDiscardRectangleModeEXT discardRectangleMode;
    uint32_t discardRectangleCount;
    const VkRect2D* pDiscardRectangles;
    safe_VkPipelineDiscardRectangleStateCreateInfoEXT(const VkPipelineDiscardRectangleStateCreateInfoEXT* in_struct);
    safe_VkPipelineDiscardRectangleStateCreateInfoEXT(const safe_VkPipelineDiscardRectangleStateCreateInfoEXT& copy_src);
    safe_VkPipelineDiscardRectangleStateCreateInfoEXT& operator=(const safe_VkPipelineDiscardRectangleStateCreateInfoEXT& copy_src);
    safe_VkPipelineDiscardRectangleStateCreateInfoEXT();
    ~safe_VkPipelineDiscardRectangleStateCreateInfoEXT();
    void initialize(const VkPipelineDiscardRectangleStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineDiscardRectangleStateCreateInfoEXT* copy_src);
    VkPipelineDiscardRectangleStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineDiscardRectangleStateCreateInfoEXT *>(this); }
    VkPipelineDiscardRectangleStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineDiscardRectangleStateCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    float primitiveOverestimationSize;
    float maxExtraPrimitiveOverestimationSize;
    float extraPrimitiveOverestimationSizeGranularity;
    VkBool32 primitiveUnderestimation;
    VkBool32 conservativePointAndLineRasterization;
    VkBool32 degenerateTrianglesRasterized;
    VkBool32 degenerateLinesRasterized;
    VkBool32 fullyCoveredFragmentShaderInputVariable;
    VkBool32 conservativeRasterizationPostDepthCoverage;
    safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(const safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT& operator=(const safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT();
    ~safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT();
    void initialize(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* copy_src);
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceConservativeRasterizationPropertiesEXT *>(this); }
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceConservativeRasterizationPropertiesEXT const *>(this); }
};

struct safe_VkPipelineRasterizationConservativeStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkPipelineRasterizationConservativeStateCreateFlagsEXT flags;
    VkConservativeRasterizationModeEXT conservativeRasterizationMode;
    float extraPrimitiveOverestimationSize;
    safe_VkPipelineRasterizationConservativeStateCreateInfoEXT(const VkPipelineRasterizationConservativeStateCreateInfoEXT* in_struct);
    safe_VkPipelineRasterizationConservativeStateCreateInfoEXT(const safe_VkPipelineRasterizationConservativeStateCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationConservativeStateCreateInfoEXT& operator=(const safe_VkPipelineRasterizationConservativeStateCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationConservativeStateCreateInfoEXT();
    ~safe_VkPipelineRasterizationConservativeStateCreateInfoEXT();
    void initialize(const VkPipelineRasterizationConservativeStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineRasterizationConservativeStateCreateInfoEXT* copy_src);
    VkPipelineRasterizationConservativeStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineRasterizationConservativeStateCreateInfoEXT *>(this); }
    VkPipelineRasterizationConservativeStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineRasterizationConservativeStateCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 depthClipEnable;
    safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT(const VkPhysicalDeviceDepthClipEnableFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT(const safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT& operator=(const safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT();
    ~safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT();
    void initialize(const VkPhysicalDeviceDepthClipEnableFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceDepthClipEnableFeaturesEXT* copy_src);
    VkPhysicalDeviceDepthClipEnableFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceDepthClipEnableFeaturesEXT *>(this); }
    VkPhysicalDeviceDepthClipEnableFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDepthClipEnableFeaturesEXT const *>(this); }
};

struct safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkPipelineRasterizationDepthClipStateCreateFlagsEXT flags;
    VkBool32 depthClipEnable;
    safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT(const VkPipelineRasterizationDepthClipStateCreateInfoEXT* in_struct);
    safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT(const safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT& operator=(const safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT();
    ~safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT();
    void initialize(const VkPipelineRasterizationDepthClipStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineRasterizationDepthClipStateCreateInfoEXT* copy_src);
    VkPipelineRasterizationDepthClipStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineRasterizationDepthClipStateCreateInfoEXT *>(this); }
    VkPipelineRasterizationDepthClipStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineRasterizationDepthClipStateCreateInfoEXT const *>(this); }
};

struct safe_VkHdrMetadataEXT {
    VkStructureType sType;
    const void* pNext;
    VkXYColorEXT displayPrimaryRed;
    VkXYColorEXT displayPrimaryGreen;
    VkXYColorEXT displayPrimaryBlue;
    VkXYColorEXT whitePoint;
    float maxLuminance;
    float minLuminance;
    float maxContentLightLevel;
    float maxFrameAverageLightLevel;
    safe_VkHdrMetadataEXT(const VkHdrMetadataEXT* in_struct);
    safe_VkHdrMetadataEXT(const safe_VkHdrMetadataEXT& copy_src);
    safe_VkHdrMetadataEXT& operator=(const safe_VkHdrMetadataEXT& copy_src);
    safe_VkHdrMetadataEXT();
    ~safe_VkHdrMetadataEXT();
    void initialize(const VkHdrMetadataEXT* in_struct);
    void initialize(const safe_VkHdrMetadataEXT* copy_src);
    VkHdrMetadataEXT *ptr() { return reinterpret_cast<VkHdrMetadataEXT *>(this); }
    VkHdrMetadataEXT const *ptr() const { return reinterpret_cast<VkHdrMetadataEXT const *>(this); }
};

#ifdef VK_USE_PLATFORM_IOS_MVK
struct safe_VkIOSSurfaceCreateInfoMVK {
    VkStructureType sType;
    const void* pNext;
    VkIOSSurfaceCreateFlagsMVK flags;
    const void* pView;
    safe_VkIOSSurfaceCreateInfoMVK(const VkIOSSurfaceCreateInfoMVK* in_struct);
    safe_VkIOSSurfaceCreateInfoMVK(const safe_VkIOSSurfaceCreateInfoMVK& copy_src);
    safe_VkIOSSurfaceCreateInfoMVK& operator=(const safe_VkIOSSurfaceCreateInfoMVK& copy_src);
    safe_VkIOSSurfaceCreateInfoMVK();
    ~safe_VkIOSSurfaceCreateInfoMVK();
    void initialize(const VkIOSSurfaceCreateInfoMVK* in_struct);
    void initialize(const safe_VkIOSSurfaceCreateInfoMVK* copy_src);
    VkIOSSurfaceCreateInfoMVK *ptr() { return reinterpret_cast<VkIOSSurfaceCreateInfoMVK *>(this); }
    VkIOSSurfaceCreateInfoMVK const *ptr() const { return reinterpret_cast<VkIOSSurfaceCreateInfoMVK const *>(this); }
};
#endif // VK_USE_PLATFORM_IOS_MVK

#ifdef VK_USE_PLATFORM_MACOS_MVK
struct safe_VkMacOSSurfaceCreateInfoMVK {
    VkStructureType sType;
    const void* pNext;
    VkMacOSSurfaceCreateFlagsMVK flags;
    const void* pView;
    safe_VkMacOSSurfaceCreateInfoMVK(const VkMacOSSurfaceCreateInfoMVK* in_struct);
    safe_VkMacOSSurfaceCreateInfoMVK(const safe_VkMacOSSurfaceCreateInfoMVK& copy_src);
    safe_VkMacOSSurfaceCreateInfoMVK& operator=(const safe_VkMacOSSurfaceCreateInfoMVK& copy_src);
    safe_VkMacOSSurfaceCreateInfoMVK();
    ~safe_VkMacOSSurfaceCreateInfoMVK();
    void initialize(const VkMacOSSurfaceCreateInfoMVK* in_struct);
    void initialize(const safe_VkMacOSSurfaceCreateInfoMVK* copy_src);
    VkMacOSSurfaceCreateInfoMVK *ptr() { return reinterpret_cast<VkMacOSSurfaceCreateInfoMVK *>(this); }
    VkMacOSSurfaceCreateInfoMVK const *ptr() const { return reinterpret_cast<VkMacOSSurfaceCreateInfoMVK const *>(this); }
};
#endif // VK_USE_PLATFORM_MACOS_MVK

struct safe_VkDebugUtilsObjectNameInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkObjectType objectType;
    uint64_t objectHandle;
    const char* pObjectName;
    safe_VkDebugUtilsObjectNameInfoEXT(const VkDebugUtilsObjectNameInfoEXT* in_struct);
    safe_VkDebugUtilsObjectNameInfoEXT(const safe_VkDebugUtilsObjectNameInfoEXT& copy_src);
    safe_VkDebugUtilsObjectNameInfoEXT& operator=(const safe_VkDebugUtilsObjectNameInfoEXT& copy_src);
    safe_VkDebugUtilsObjectNameInfoEXT();
    ~safe_VkDebugUtilsObjectNameInfoEXT();
    void initialize(const VkDebugUtilsObjectNameInfoEXT* in_struct);
    void initialize(const safe_VkDebugUtilsObjectNameInfoEXT* copy_src);
    VkDebugUtilsObjectNameInfoEXT *ptr() { return reinterpret_cast<VkDebugUtilsObjectNameInfoEXT *>(this); }
    VkDebugUtilsObjectNameInfoEXT const *ptr() const { return reinterpret_cast<VkDebugUtilsObjectNameInfoEXT const *>(this); }
};

struct safe_VkDebugUtilsObjectTagInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkObjectType objectType;
    uint64_t objectHandle;
    uint64_t tagName;
    size_t tagSize;
    const void* pTag;
    safe_VkDebugUtilsObjectTagInfoEXT(const VkDebugUtilsObjectTagInfoEXT* in_struct);
    safe_VkDebugUtilsObjectTagInfoEXT(const safe_VkDebugUtilsObjectTagInfoEXT& copy_src);
    safe_VkDebugUtilsObjectTagInfoEXT& operator=(const safe_VkDebugUtilsObjectTagInfoEXT& copy_src);
    safe_VkDebugUtilsObjectTagInfoEXT();
    ~safe_VkDebugUtilsObjectTagInfoEXT();
    void initialize(const VkDebugUtilsObjectTagInfoEXT* in_struct);
    void initialize(const safe_VkDebugUtilsObjectTagInfoEXT* copy_src);
    VkDebugUtilsObjectTagInfoEXT *ptr() { return reinterpret_cast<VkDebugUtilsObjectTagInfoEXT *>(this); }
    VkDebugUtilsObjectTagInfoEXT const *ptr() const { return reinterpret_cast<VkDebugUtilsObjectTagInfoEXT const *>(this); }
};

struct safe_VkDebugUtilsLabelEXT {
    VkStructureType sType;
    const void* pNext;
    const char* pLabelName;
    float color[4];
    safe_VkDebugUtilsLabelEXT(const VkDebugUtilsLabelEXT* in_struct);
    safe_VkDebugUtilsLabelEXT(const safe_VkDebugUtilsLabelEXT& copy_src);
    safe_VkDebugUtilsLabelEXT& operator=(const safe_VkDebugUtilsLabelEXT& copy_src);
    safe_VkDebugUtilsLabelEXT();
    ~safe_VkDebugUtilsLabelEXT();
    void initialize(const VkDebugUtilsLabelEXT* in_struct);
    void initialize(const safe_VkDebugUtilsLabelEXT* copy_src);
    VkDebugUtilsLabelEXT *ptr() { return reinterpret_cast<VkDebugUtilsLabelEXT *>(this); }
    VkDebugUtilsLabelEXT const *ptr() const { return reinterpret_cast<VkDebugUtilsLabelEXT const *>(this); }
};

struct safe_VkDebugUtilsMessengerCallbackDataEXT {
    VkStructureType sType;
    const void* pNext;
    VkDebugUtilsMessengerCallbackDataFlagsEXT flags;
    const char* pMessageIdName;
    int32_t messageIdNumber;
    const char* pMessage;
    uint32_t queueLabelCount;
    safe_VkDebugUtilsLabelEXT* pQueueLabels;
    uint32_t cmdBufLabelCount;
    safe_VkDebugUtilsLabelEXT* pCmdBufLabels;
    uint32_t objectCount;
    safe_VkDebugUtilsObjectNameInfoEXT* pObjects;
    safe_VkDebugUtilsMessengerCallbackDataEXT(const VkDebugUtilsMessengerCallbackDataEXT* in_struct);
    safe_VkDebugUtilsMessengerCallbackDataEXT(const safe_VkDebugUtilsMessengerCallbackDataEXT& copy_src);
    safe_VkDebugUtilsMessengerCallbackDataEXT& operator=(const safe_VkDebugUtilsMessengerCallbackDataEXT& copy_src);
    safe_VkDebugUtilsMessengerCallbackDataEXT();
    ~safe_VkDebugUtilsMessengerCallbackDataEXT();
    void initialize(const VkDebugUtilsMessengerCallbackDataEXT* in_struct);
    void initialize(const safe_VkDebugUtilsMessengerCallbackDataEXT* copy_src);
    VkDebugUtilsMessengerCallbackDataEXT *ptr() { return reinterpret_cast<VkDebugUtilsMessengerCallbackDataEXT *>(this); }
    VkDebugUtilsMessengerCallbackDataEXT const *ptr() const { return reinterpret_cast<VkDebugUtilsMessengerCallbackDataEXT const *>(this); }
};

struct safe_VkDebugUtilsMessengerCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDebugUtilsMessengerCreateFlagsEXT flags;
    VkDebugUtilsMessageSeverityFlagsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageType;
    PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback;
    void* pUserData;
    safe_VkDebugUtilsMessengerCreateInfoEXT(const VkDebugUtilsMessengerCreateInfoEXT* in_struct);
    safe_VkDebugUtilsMessengerCreateInfoEXT(const safe_VkDebugUtilsMessengerCreateInfoEXT& copy_src);
    safe_VkDebugUtilsMessengerCreateInfoEXT& operator=(const safe_VkDebugUtilsMessengerCreateInfoEXT& copy_src);
    safe_VkDebugUtilsMessengerCreateInfoEXT();
    ~safe_VkDebugUtilsMessengerCreateInfoEXT();
    void initialize(const VkDebugUtilsMessengerCreateInfoEXT* in_struct);
    void initialize(const safe_VkDebugUtilsMessengerCreateInfoEXT* copy_src);
    VkDebugUtilsMessengerCreateInfoEXT *ptr() { return reinterpret_cast<VkDebugUtilsMessengerCreateInfoEXT *>(this); }
    VkDebugUtilsMessengerCreateInfoEXT const *ptr() const { return reinterpret_cast<VkDebugUtilsMessengerCreateInfoEXT const *>(this); }
};

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkAndroidHardwareBufferUsageANDROID {
    VkStructureType sType;
    void* pNext;
    uint64_t androidHardwareBufferUsage;
    safe_VkAndroidHardwareBufferUsageANDROID(const VkAndroidHardwareBufferUsageANDROID* in_struct);
    safe_VkAndroidHardwareBufferUsageANDROID(const safe_VkAndroidHardwareBufferUsageANDROID& copy_src);
    safe_VkAndroidHardwareBufferUsageANDROID& operator=(const safe_VkAndroidHardwareBufferUsageANDROID& copy_src);
    safe_VkAndroidHardwareBufferUsageANDROID();
    ~safe_VkAndroidHardwareBufferUsageANDROID();
    void initialize(const VkAndroidHardwareBufferUsageANDROID* in_struct);
    void initialize(const safe_VkAndroidHardwareBufferUsageANDROID* copy_src);
    VkAndroidHardwareBufferUsageANDROID *ptr() { return reinterpret_cast<VkAndroidHardwareBufferUsageANDROID *>(this); }
    VkAndroidHardwareBufferUsageANDROID const *ptr() const { return reinterpret_cast<VkAndroidHardwareBufferUsageANDROID const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkAndroidHardwareBufferPropertiesANDROID {
    VkStructureType sType;
    void* pNext;
    VkDeviceSize allocationSize;
    uint32_t memoryTypeBits;
    safe_VkAndroidHardwareBufferPropertiesANDROID(const VkAndroidHardwareBufferPropertiesANDROID* in_struct);
    safe_VkAndroidHardwareBufferPropertiesANDROID(const safe_VkAndroidHardwareBufferPropertiesANDROID& copy_src);
    safe_VkAndroidHardwareBufferPropertiesANDROID& operator=(const safe_VkAndroidHardwareBufferPropertiesANDROID& copy_src);
    safe_VkAndroidHardwareBufferPropertiesANDROID();
    ~safe_VkAndroidHardwareBufferPropertiesANDROID();
    void initialize(const VkAndroidHardwareBufferPropertiesANDROID* in_struct);
    void initialize(const safe_VkAndroidHardwareBufferPropertiesANDROID* copy_src);
    VkAndroidHardwareBufferPropertiesANDROID *ptr() { return reinterpret_cast<VkAndroidHardwareBufferPropertiesANDROID *>(this); }
    VkAndroidHardwareBufferPropertiesANDROID const *ptr() const { return reinterpret_cast<VkAndroidHardwareBufferPropertiesANDROID const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkAndroidHardwareBufferFormatPropertiesANDROID {
    VkStructureType sType;
    void* pNext;
    VkFormat format;
    uint64_t externalFormat;
    VkFormatFeatureFlags formatFeatures;
    VkComponentMapping samplerYcbcrConversionComponents;
    VkSamplerYcbcrModelConversion suggestedYcbcrModel;
    VkSamplerYcbcrRange suggestedYcbcrRange;
    VkChromaLocation suggestedXChromaOffset;
    VkChromaLocation suggestedYChromaOffset;
    safe_VkAndroidHardwareBufferFormatPropertiesANDROID(const VkAndroidHardwareBufferFormatPropertiesANDROID* in_struct);
    safe_VkAndroidHardwareBufferFormatPropertiesANDROID(const safe_VkAndroidHardwareBufferFormatPropertiesANDROID& copy_src);
    safe_VkAndroidHardwareBufferFormatPropertiesANDROID& operator=(const safe_VkAndroidHardwareBufferFormatPropertiesANDROID& copy_src);
    safe_VkAndroidHardwareBufferFormatPropertiesANDROID();
    ~safe_VkAndroidHardwareBufferFormatPropertiesANDROID();
    void initialize(const VkAndroidHardwareBufferFormatPropertiesANDROID* in_struct);
    void initialize(const safe_VkAndroidHardwareBufferFormatPropertiesANDROID* copy_src);
    VkAndroidHardwareBufferFormatPropertiesANDROID *ptr() { return reinterpret_cast<VkAndroidHardwareBufferFormatPropertiesANDROID *>(this); }
    VkAndroidHardwareBufferFormatPropertiesANDROID const *ptr() const { return reinterpret_cast<VkAndroidHardwareBufferFormatPropertiesANDROID const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkImportAndroidHardwareBufferInfoANDROID {
    VkStructureType sType;
    const void* pNext;
    struct AHardwareBuffer* buffer;
    safe_VkImportAndroidHardwareBufferInfoANDROID(const VkImportAndroidHardwareBufferInfoANDROID* in_struct);
    safe_VkImportAndroidHardwareBufferInfoANDROID(const safe_VkImportAndroidHardwareBufferInfoANDROID& copy_src);
    safe_VkImportAndroidHardwareBufferInfoANDROID& operator=(const safe_VkImportAndroidHardwareBufferInfoANDROID& copy_src);
    safe_VkImportAndroidHardwareBufferInfoANDROID();
    ~safe_VkImportAndroidHardwareBufferInfoANDROID();
    void initialize(const VkImportAndroidHardwareBufferInfoANDROID* in_struct);
    void initialize(const safe_VkImportAndroidHardwareBufferInfoANDROID* copy_src);
    VkImportAndroidHardwareBufferInfoANDROID *ptr() { return reinterpret_cast<VkImportAndroidHardwareBufferInfoANDROID *>(this); }
    VkImportAndroidHardwareBufferInfoANDROID const *ptr() const { return reinterpret_cast<VkImportAndroidHardwareBufferInfoANDROID const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkMemoryGetAndroidHardwareBufferInfoANDROID {
    VkStructureType sType;
    const void* pNext;
    VkDeviceMemory memory;
    safe_VkMemoryGetAndroidHardwareBufferInfoANDROID(const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_struct);
    safe_VkMemoryGetAndroidHardwareBufferInfoANDROID(const safe_VkMemoryGetAndroidHardwareBufferInfoANDROID& copy_src);
    safe_VkMemoryGetAndroidHardwareBufferInfoANDROID& operator=(const safe_VkMemoryGetAndroidHardwareBufferInfoANDROID& copy_src);
    safe_VkMemoryGetAndroidHardwareBufferInfoANDROID();
    ~safe_VkMemoryGetAndroidHardwareBufferInfoANDROID();
    void initialize(const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_struct);
    void initialize(const safe_VkMemoryGetAndroidHardwareBufferInfoANDROID* copy_src);
    VkMemoryGetAndroidHardwareBufferInfoANDROID *ptr() { return reinterpret_cast<VkMemoryGetAndroidHardwareBufferInfoANDROID *>(this); }
    VkMemoryGetAndroidHardwareBufferInfoANDROID const *ptr() const { return reinterpret_cast<VkMemoryGetAndroidHardwareBufferInfoANDROID const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct safe_VkExternalFormatANDROID {
    VkStructureType sType;
    void* pNext;
    uint64_t externalFormat;
    safe_VkExternalFormatANDROID(const VkExternalFormatANDROID* in_struct);
    safe_VkExternalFormatANDROID(const safe_VkExternalFormatANDROID& copy_src);
    safe_VkExternalFormatANDROID& operator=(const safe_VkExternalFormatANDROID& copy_src);
    safe_VkExternalFormatANDROID();
    ~safe_VkExternalFormatANDROID();
    void initialize(const VkExternalFormatANDROID* in_struct);
    void initialize(const safe_VkExternalFormatANDROID* copy_src);
    VkExternalFormatANDROID *ptr() { return reinterpret_cast<VkExternalFormatANDROID *>(this); }
    VkExternalFormatANDROID const *ptr() const { return reinterpret_cast<VkExternalFormatANDROID const *>(this); }
};
#endif // VK_USE_PLATFORM_ANDROID_KHR

struct safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 inlineUniformBlock;
    VkBool32 descriptorBindingInlineUniformBlockUpdateAfterBind;
    safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT(const VkPhysicalDeviceInlineUniformBlockFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT(const safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT& operator=(const safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT();
    ~safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT();
    void initialize(const VkPhysicalDeviceInlineUniformBlockFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceInlineUniformBlockFeaturesEXT* copy_src);
    VkPhysicalDeviceInlineUniformBlockFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceInlineUniformBlockFeaturesEXT *>(this); }
    VkPhysicalDeviceInlineUniformBlockFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceInlineUniformBlockFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t maxInlineUniformBlockSize;
    uint32_t maxPerStageDescriptorInlineUniformBlocks;
    uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks;
    uint32_t maxDescriptorSetInlineUniformBlocks;
    uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks;
    safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT(const VkPhysicalDeviceInlineUniformBlockPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT(const safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT& operator=(const safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT();
    ~safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT();
    void initialize(const VkPhysicalDeviceInlineUniformBlockPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceInlineUniformBlockPropertiesEXT* copy_src);
    VkPhysicalDeviceInlineUniformBlockPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceInlineUniformBlockPropertiesEXT *>(this); }
    VkPhysicalDeviceInlineUniformBlockPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceInlineUniformBlockPropertiesEXT const *>(this); }
};

struct safe_VkWriteDescriptorSetInlineUniformBlockEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t dataSize;
    const void* pData;
    safe_VkWriteDescriptorSetInlineUniformBlockEXT(const VkWriteDescriptorSetInlineUniformBlockEXT* in_struct);
    safe_VkWriteDescriptorSetInlineUniformBlockEXT(const safe_VkWriteDescriptorSetInlineUniformBlockEXT& copy_src);
    safe_VkWriteDescriptorSetInlineUniformBlockEXT& operator=(const safe_VkWriteDescriptorSetInlineUniformBlockEXT& copy_src);
    safe_VkWriteDescriptorSetInlineUniformBlockEXT();
    ~safe_VkWriteDescriptorSetInlineUniformBlockEXT();
    void initialize(const VkWriteDescriptorSetInlineUniformBlockEXT* in_struct);
    void initialize(const safe_VkWriteDescriptorSetInlineUniformBlockEXT* copy_src);
    VkWriteDescriptorSetInlineUniformBlockEXT *ptr() { return reinterpret_cast<VkWriteDescriptorSetInlineUniformBlockEXT *>(this); }
    VkWriteDescriptorSetInlineUniformBlockEXT const *ptr() const { return reinterpret_cast<VkWriteDescriptorSetInlineUniformBlockEXT const *>(this); }
};

struct safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t maxInlineUniformBlockBindings;
    safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT(const VkDescriptorPoolInlineUniformBlockCreateInfoEXT* in_struct);
    safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT(const safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT& copy_src);
    safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT& operator=(const safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT& copy_src);
    safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT();
    ~safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT();
    void initialize(const VkDescriptorPoolInlineUniformBlockCreateInfoEXT* in_struct);
    void initialize(const safe_VkDescriptorPoolInlineUniformBlockCreateInfoEXT* copy_src);
    VkDescriptorPoolInlineUniformBlockCreateInfoEXT *ptr() { return reinterpret_cast<VkDescriptorPoolInlineUniformBlockCreateInfoEXT *>(this); }
    VkDescriptorPoolInlineUniformBlockCreateInfoEXT const *ptr() const { return reinterpret_cast<VkDescriptorPoolInlineUniformBlockCreateInfoEXT const *>(this); }
};

struct safe_VkSampleLocationsInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkSampleCountFlagBits sampleLocationsPerPixel;
    VkExtent2D sampleLocationGridSize;
    uint32_t sampleLocationsCount;
    const VkSampleLocationEXT* pSampleLocations;
    safe_VkSampleLocationsInfoEXT(const VkSampleLocationsInfoEXT* in_struct);
    safe_VkSampleLocationsInfoEXT(const safe_VkSampleLocationsInfoEXT& copy_src);
    safe_VkSampleLocationsInfoEXT& operator=(const safe_VkSampleLocationsInfoEXT& copy_src);
    safe_VkSampleLocationsInfoEXT();
    ~safe_VkSampleLocationsInfoEXT();
    void initialize(const VkSampleLocationsInfoEXT* in_struct);
    void initialize(const safe_VkSampleLocationsInfoEXT* copy_src);
    VkSampleLocationsInfoEXT *ptr() { return reinterpret_cast<VkSampleLocationsInfoEXT *>(this); }
    VkSampleLocationsInfoEXT const *ptr() const { return reinterpret_cast<VkSampleLocationsInfoEXT const *>(this); }
};

struct safe_VkRenderPassSampleLocationsBeginInfoEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t attachmentInitialSampleLocationsCount;
    const VkAttachmentSampleLocationsEXT* pAttachmentInitialSampleLocations;
    uint32_t postSubpassSampleLocationsCount;
    const VkSubpassSampleLocationsEXT* pPostSubpassSampleLocations;
    safe_VkRenderPassSampleLocationsBeginInfoEXT(const VkRenderPassSampleLocationsBeginInfoEXT* in_struct);
    safe_VkRenderPassSampleLocationsBeginInfoEXT(const safe_VkRenderPassSampleLocationsBeginInfoEXT& copy_src);
    safe_VkRenderPassSampleLocationsBeginInfoEXT& operator=(const safe_VkRenderPassSampleLocationsBeginInfoEXT& copy_src);
    safe_VkRenderPassSampleLocationsBeginInfoEXT();
    ~safe_VkRenderPassSampleLocationsBeginInfoEXT();
    void initialize(const VkRenderPassSampleLocationsBeginInfoEXT* in_struct);
    void initialize(const safe_VkRenderPassSampleLocationsBeginInfoEXT* copy_src);
    VkRenderPassSampleLocationsBeginInfoEXT *ptr() { return reinterpret_cast<VkRenderPassSampleLocationsBeginInfoEXT *>(this); }
    VkRenderPassSampleLocationsBeginInfoEXT const *ptr() const { return reinterpret_cast<VkRenderPassSampleLocationsBeginInfoEXT const *>(this); }
};

struct safe_VkPipelineSampleLocationsStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkBool32 sampleLocationsEnable;
    safe_VkSampleLocationsInfoEXT sampleLocationsInfo;
    safe_VkPipelineSampleLocationsStateCreateInfoEXT(const VkPipelineSampleLocationsStateCreateInfoEXT* in_struct);
    safe_VkPipelineSampleLocationsStateCreateInfoEXT(const safe_VkPipelineSampleLocationsStateCreateInfoEXT& copy_src);
    safe_VkPipelineSampleLocationsStateCreateInfoEXT& operator=(const safe_VkPipelineSampleLocationsStateCreateInfoEXT& copy_src);
    safe_VkPipelineSampleLocationsStateCreateInfoEXT();
    ~safe_VkPipelineSampleLocationsStateCreateInfoEXT();
    void initialize(const VkPipelineSampleLocationsStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineSampleLocationsStateCreateInfoEXT* copy_src);
    VkPipelineSampleLocationsStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineSampleLocationsStateCreateInfoEXT *>(this); }
    VkPipelineSampleLocationsStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineSampleLocationsStateCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceSampleLocationsPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkSampleCountFlags sampleLocationSampleCounts;
    VkExtent2D maxSampleLocationGridSize;
    float sampleLocationCoordinateRange[2];
    uint32_t sampleLocationSubPixelBits;
    VkBool32 variableSampleLocations;
    safe_VkPhysicalDeviceSampleLocationsPropertiesEXT(const VkPhysicalDeviceSampleLocationsPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceSampleLocationsPropertiesEXT(const safe_VkPhysicalDeviceSampleLocationsPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceSampleLocationsPropertiesEXT& operator=(const safe_VkPhysicalDeviceSampleLocationsPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceSampleLocationsPropertiesEXT();
    ~safe_VkPhysicalDeviceSampleLocationsPropertiesEXT();
    void initialize(const VkPhysicalDeviceSampleLocationsPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceSampleLocationsPropertiesEXT* copy_src);
    VkPhysicalDeviceSampleLocationsPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceSampleLocationsPropertiesEXT *>(this); }
    VkPhysicalDeviceSampleLocationsPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSampleLocationsPropertiesEXT const *>(this); }
};

struct safe_VkMultisamplePropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkExtent2D maxSampleLocationGridSize;
    safe_VkMultisamplePropertiesEXT(const VkMultisamplePropertiesEXT* in_struct);
    safe_VkMultisamplePropertiesEXT(const safe_VkMultisamplePropertiesEXT& copy_src);
    safe_VkMultisamplePropertiesEXT& operator=(const safe_VkMultisamplePropertiesEXT& copy_src);
    safe_VkMultisamplePropertiesEXT();
    ~safe_VkMultisamplePropertiesEXT();
    void initialize(const VkMultisamplePropertiesEXT* in_struct);
    void initialize(const safe_VkMultisamplePropertiesEXT* copy_src);
    VkMultisamplePropertiesEXT *ptr() { return reinterpret_cast<VkMultisamplePropertiesEXT *>(this); }
    VkMultisamplePropertiesEXT const *ptr() const { return reinterpret_cast<VkMultisamplePropertiesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 advancedBlendCoherentOperations;
    safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(const safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& operator=(const safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT();
    ~safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT();
    void initialize(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* copy_src);
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *>(this); }
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t advancedBlendMaxColorAttachments;
    VkBool32 advancedBlendIndependentBlend;
    VkBool32 advancedBlendNonPremultipliedSrcColor;
    VkBool32 advancedBlendNonPremultipliedDstColor;
    VkBool32 advancedBlendCorrelatedOverlap;
    VkBool32 advancedBlendAllOperations;
    safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(const safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& operator=(const safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT();
    ~safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT();
    void initialize(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* copy_src);
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *>(this); }
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT const *>(this); }
};

struct safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkBool32 srcPremultiplied;
    VkBool32 dstPremultiplied;
    VkBlendOverlapEXT blendOverlap;
    safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT(const VkPipelineColorBlendAdvancedStateCreateInfoEXT* in_struct);
    safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT(const safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT& copy_src);
    safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT& operator=(const safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT& copy_src);
    safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT();
    ~safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT();
    void initialize(const VkPipelineColorBlendAdvancedStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineColorBlendAdvancedStateCreateInfoEXT* copy_src);
    VkPipelineColorBlendAdvancedStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineColorBlendAdvancedStateCreateInfoEXT *>(this); }
    VkPipelineColorBlendAdvancedStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineColorBlendAdvancedStateCreateInfoEXT const *>(this); }
};

struct safe_VkPipelineCoverageToColorStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCoverageToColorStateCreateFlagsNV flags;
    VkBool32 coverageToColorEnable;
    uint32_t coverageToColorLocation;
    safe_VkPipelineCoverageToColorStateCreateInfoNV(const VkPipelineCoverageToColorStateCreateInfoNV* in_struct);
    safe_VkPipelineCoverageToColorStateCreateInfoNV(const safe_VkPipelineCoverageToColorStateCreateInfoNV& copy_src);
    safe_VkPipelineCoverageToColorStateCreateInfoNV& operator=(const safe_VkPipelineCoverageToColorStateCreateInfoNV& copy_src);
    safe_VkPipelineCoverageToColorStateCreateInfoNV();
    ~safe_VkPipelineCoverageToColorStateCreateInfoNV();
    void initialize(const VkPipelineCoverageToColorStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineCoverageToColorStateCreateInfoNV* copy_src);
    VkPipelineCoverageToColorStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineCoverageToColorStateCreateInfoNV *>(this); }
    VkPipelineCoverageToColorStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineCoverageToColorStateCreateInfoNV const *>(this); }
};

struct safe_VkPipelineCoverageModulationStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCoverageModulationStateCreateFlagsNV flags;
    VkCoverageModulationModeNV coverageModulationMode;
    VkBool32 coverageModulationTableEnable;
    uint32_t coverageModulationTableCount;
    const float* pCoverageModulationTable;
    safe_VkPipelineCoverageModulationStateCreateInfoNV(const VkPipelineCoverageModulationStateCreateInfoNV* in_struct);
    safe_VkPipelineCoverageModulationStateCreateInfoNV(const safe_VkPipelineCoverageModulationStateCreateInfoNV& copy_src);
    safe_VkPipelineCoverageModulationStateCreateInfoNV& operator=(const safe_VkPipelineCoverageModulationStateCreateInfoNV& copy_src);
    safe_VkPipelineCoverageModulationStateCreateInfoNV();
    ~safe_VkPipelineCoverageModulationStateCreateInfoNV();
    void initialize(const VkPipelineCoverageModulationStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineCoverageModulationStateCreateInfoNV* copy_src);
    VkPipelineCoverageModulationStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineCoverageModulationStateCreateInfoNV *>(this); }
    VkPipelineCoverageModulationStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineCoverageModulationStateCreateInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV {
    VkStructureType sType;
    void* pNext;
    uint32_t shaderSMCount;
    uint32_t shaderWarpsPerSM;
    safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* in_struct);
    safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(const safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV& copy_src);
    safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV& operator=(const safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV& copy_src);
    safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV();
    ~safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV();
    void initialize(const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* copy_src);
    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV *>(this); }
    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV const *>(this); }
};

struct safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderSMBuiltins;
    safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* in_struct);
    safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(const safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV& copy_src);
    safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV& operator=(const safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV& copy_src);
    safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV();
    ~safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV();
    void initialize(const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* copy_src);
    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV *>(this); }
    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV const *>(this); }
};

struct safe_VkDrmFormatModifierPropertiesListEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t drmFormatModifierCount;
    VkDrmFormatModifierPropertiesEXT* pDrmFormatModifierProperties;
    safe_VkDrmFormatModifierPropertiesListEXT(const VkDrmFormatModifierPropertiesListEXT* in_struct);
    safe_VkDrmFormatModifierPropertiesListEXT(const safe_VkDrmFormatModifierPropertiesListEXT& copy_src);
    safe_VkDrmFormatModifierPropertiesListEXT& operator=(const safe_VkDrmFormatModifierPropertiesListEXT& copy_src);
    safe_VkDrmFormatModifierPropertiesListEXT();
    ~safe_VkDrmFormatModifierPropertiesListEXT();
    void initialize(const VkDrmFormatModifierPropertiesListEXT* in_struct);
    void initialize(const safe_VkDrmFormatModifierPropertiesListEXT* copy_src);
    VkDrmFormatModifierPropertiesListEXT *ptr() { return reinterpret_cast<VkDrmFormatModifierPropertiesListEXT *>(this); }
    VkDrmFormatModifierPropertiesListEXT const *ptr() const { return reinterpret_cast<VkDrmFormatModifierPropertiesListEXT const *>(this); }
};

struct safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT {
    VkStructureType sType;
    const void* pNext;
    uint64_t drmFormatModifier;
    VkSharingMode sharingMode;
    uint32_t queueFamilyIndexCount;
    const uint32_t* pQueueFamilyIndices;
    safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(const VkPhysicalDeviceImageDrmFormatModifierInfoEXT* in_struct);
    safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(const safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT& copy_src);
    safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT& operator=(const safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT& copy_src);
    safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT();
    ~safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT();
    void initialize(const VkPhysicalDeviceImageDrmFormatModifierInfoEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* copy_src);
    VkPhysicalDeviceImageDrmFormatModifierInfoEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceImageDrmFormatModifierInfoEXT *>(this); }
    VkPhysicalDeviceImageDrmFormatModifierInfoEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceImageDrmFormatModifierInfoEXT const *>(this); }
};

struct safe_VkImageDrmFormatModifierListCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t drmFormatModifierCount;
    const uint64_t* pDrmFormatModifiers;
    safe_VkImageDrmFormatModifierListCreateInfoEXT(const VkImageDrmFormatModifierListCreateInfoEXT* in_struct);
    safe_VkImageDrmFormatModifierListCreateInfoEXT(const safe_VkImageDrmFormatModifierListCreateInfoEXT& copy_src);
    safe_VkImageDrmFormatModifierListCreateInfoEXT& operator=(const safe_VkImageDrmFormatModifierListCreateInfoEXT& copy_src);
    safe_VkImageDrmFormatModifierListCreateInfoEXT();
    ~safe_VkImageDrmFormatModifierListCreateInfoEXT();
    void initialize(const VkImageDrmFormatModifierListCreateInfoEXT* in_struct);
    void initialize(const safe_VkImageDrmFormatModifierListCreateInfoEXT* copy_src);
    VkImageDrmFormatModifierListCreateInfoEXT *ptr() { return reinterpret_cast<VkImageDrmFormatModifierListCreateInfoEXT *>(this); }
    VkImageDrmFormatModifierListCreateInfoEXT const *ptr() const { return reinterpret_cast<VkImageDrmFormatModifierListCreateInfoEXT const *>(this); }
};

struct safe_VkImageDrmFormatModifierExplicitCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    uint64_t drmFormatModifier;
    uint32_t drmFormatModifierPlaneCount;
    const VkSubresourceLayout* pPlaneLayouts;
    safe_VkImageDrmFormatModifierExplicitCreateInfoEXT(const VkImageDrmFormatModifierExplicitCreateInfoEXT* in_struct);
    safe_VkImageDrmFormatModifierExplicitCreateInfoEXT(const safe_VkImageDrmFormatModifierExplicitCreateInfoEXT& copy_src);
    safe_VkImageDrmFormatModifierExplicitCreateInfoEXT& operator=(const safe_VkImageDrmFormatModifierExplicitCreateInfoEXT& copy_src);
    safe_VkImageDrmFormatModifierExplicitCreateInfoEXT();
    ~safe_VkImageDrmFormatModifierExplicitCreateInfoEXT();
    void initialize(const VkImageDrmFormatModifierExplicitCreateInfoEXT* in_struct);
    void initialize(const safe_VkImageDrmFormatModifierExplicitCreateInfoEXT* copy_src);
    VkImageDrmFormatModifierExplicitCreateInfoEXT *ptr() { return reinterpret_cast<VkImageDrmFormatModifierExplicitCreateInfoEXT *>(this); }
    VkImageDrmFormatModifierExplicitCreateInfoEXT const *ptr() const { return reinterpret_cast<VkImageDrmFormatModifierExplicitCreateInfoEXT const *>(this); }
};

struct safe_VkImageDrmFormatModifierPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint64_t drmFormatModifier;
    safe_VkImageDrmFormatModifierPropertiesEXT(const VkImageDrmFormatModifierPropertiesEXT* in_struct);
    safe_VkImageDrmFormatModifierPropertiesEXT(const safe_VkImageDrmFormatModifierPropertiesEXT& copy_src);
    safe_VkImageDrmFormatModifierPropertiesEXT& operator=(const safe_VkImageDrmFormatModifierPropertiesEXT& copy_src);
    safe_VkImageDrmFormatModifierPropertiesEXT();
    ~safe_VkImageDrmFormatModifierPropertiesEXT();
    void initialize(const VkImageDrmFormatModifierPropertiesEXT* in_struct);
    void initialize(const safe_VkImageDrmFormatModifierPropertiesEXT* copy_src);
    VkImageDrmFormatModifierPropertiesEXT *ptr() { return reinterpret_cast<VkImageDrmFormatModifierPropertiesEXT *>(this); }
    VkImageDrmFormatModifierPropertiesEXT const *ptr() const { return reinterpret_cast<VkImageDrmFormatModifierPropertiesEXT const *>(this); }
};

struct safe_VkValidationCacheCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkValidationCacheCreateFlagsEXT flags;
    size_t initialDataSize;
    const void* pInitialData;
    safe_VkValidationCacheCreateInfoEXT(const VkValidationCacheCreateInfoEXT* in_struct);
    safe_VkValidationCacheCreateInfoEXT(const safe_VkValidationCacheCreateInfoEXT& copy_src);
    safe_VkValidationCacheCreateInfoEXT& operator=(const safe_VkValidationCacheCreateInfoEXT& copy_src);
    safe_VkValidationCacheCreateInfoEXT();
    ~safe_VkValidationCacheCreateInfoEXT();
    void initialize(const VkValidationCacheCreateInfoEXT* in_struct);
    void initialize(const safe_VkValidationCacheCreateInfoEXT* copy_src);
    VkValidationCacheCreateInfoEXT *ptr() { return reinterpret_cast<VkValidationCacheCreateInfoEXT *>(this); }
    VkValidationCacheCreateInfoEXT const *ptr() const { return reinterpret_cast<VkValidationCacheCreateInfoEXT const *>(this); }
};

struct safe_VkShaderModuleValidationCacheCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkValidationCacheEXT validationCache;
    safe_VkShaderModuleValidationCacheCreateInfoEXT(const VkShaderModuleValidationCacheCreateInfoEXT* in_struct);
    safe_VkShaderModuleValidationCacheCreateInfoEXT(const safe_VkShaderModuleValidationCacheCreateInfoEXT& copy_src);
    safe_VkShaderModuleValidationCacheCreateInfoEXT& operator=(const safe_VkShaderModuleValidationCacheCreateInfoEXT& copy_src);
    safe_VkShaderModuleValidationCacheCreateInfoEXT();
    ~safe_VkShaderModuleValidationCacheCreateInfoEXT();
    void initialize(const VkShaderModuleValidationCacheCreateInfoEXT* in_struct);
    void initialize(const safe_VkShaderModuleValidationCacheCreateInfoEXT* copy_src);
    VkShaderModuleValidationCacheCreateInfoEXT *ptr() { return reinterpret_cast<VkShaderModuleValidationCacheCreateInfoEXT *>(this); }
    VkShaderModuleValidationCacheCreateInfoEXT const *ptr() const { return reinterpret_cast<VkShaderModuleValidationCacheCreateInfoEXT const *>(this); }
};

struct safe_VkShadingRatePaletteNV {
    uint32_t shadingRatePaletteEntryCount;
    const VkShadingRatePaletteEntryNV* pShadingRatePaletteEntries;
    safe_VkShadingRatePaletteNV(const VkShadingRatePaletteNV* in_struct);
    safe_VkShadingRatePaletteNV(const safe_VkShadingRatePaletteNV& copy_src);
    safe_VkShadingRatePaletteNV& operator=(const safe_VkShadingRatePaletteNV& copy_src);
    safe_VkShadingRatePaletteNV();
    ~safe_VkShadingRatePaletteNV();
    void initialize(const VkShadingRatePaletteNV* in_struct);
    void initialize(const safe_VkShadingRatePaletteNV* copy_src);
    VkShadingRatePaletteNV *ptr() { return reinterpret_cast<VkShadingRatePaletteNV *>(this); }
    VkShadingRatePaletteNV const *ptr() const { return reinterpret_cast<VkShadingRatePaletteNV const *>(this); }
};

struct safe_VkPipelineViewportShadingRateImageStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkBool32 shadingRateImageEnable;
    uint32_t viewportCount;
    safe_VkShadingRatePaletteNV* pShadingRatePalettes;
    safe_VkPipelineViewportShadingRateImageStateCreateInfoNV(const VkPipelineViewportShadingRateImageStateCreateInfoNV* in_struct);
    safe_VkPipelineViewportShadingRateImageStateCreateInfoNV(const safe_VkPipelineViewportShadingRateImageStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportShadingRateImageStateCreateInfoNV& operator=(const safe_VkPipelineViewportShadingRateImageStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportShadingRateImageStateCreateInfoNV();
    ~safe_VkPipelineViewportShadingRateImageStateCreateInfoNV();
    void initialize(const VkPipelineViewportShadingRateImageStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineViewportShadingRateImageStateCreateInfoNV* copy_src);
    VkPipelineViewportShadingRateImageStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineViewportShadingRateImageStateCreateInfoNV *>(this); }
    VkPipelineViewportShadingRateImageStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineViewportShadingRateImageStateCreateInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceShadingRateImageFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 shadingRateImage;
    VkBool32 shadingRateCoarseSampleOrder;
    safe_VkPhysicalDeviceShadingRateImageFeaturesNV(const VkPhysicalDeviceShadingRateImageFeaturesNV* in_struct);
    safe_VkPhysicalDeviceShadingRateImageFeaturesNV(const safe_VkPhysicalDeviceShadingRateImageFeaturesNV& copy_src);
    safe_VkPhysicalDeviceShadingRateImageFeaturesNV& operator=(const safe_VkPhysicalDeviceShadingRateImageFeaturesNV& copy_src);
    safe_VkPhysicalDeviceShadingRateImageFeaturesNV();
    ~safe_VkPhysicalDeviceShadingRateImageFeaturesNV();
    void initialize(const VkPhysicalDeviceShadingRateImageFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceShadingRateImageFeaturesNV* copy_src);
    VkPhysicalDeviceShadingRateImageFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceShadingRateImageFeaturesNV *>(this); }
    VkPhysicalDeviceShadingRateImageFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShadingRateImageFeaturesNV const *>(this); }
};

struct safe_VkPhysicalDeviceShadingRateImagePropertiesNV {
    VkStructureType sType;
    void* pNext;
    VkExtent2D shadingRateTexelSize;
    uint32_t shadingRatePaletteSize;
    uint32_t shadingRateMaxCoarseSamples;
    safe_VkPhysicalDeviceShadingRateImagePropertiesNV(const VkPhysicalDeviceShadingRateImagePropertiesNV* in_struct);
    safe_VkPhysicalDeviceShadingRateImagePropertiesNV(const safe_VkPhysicalDeviceShadingRateImagePropertiesNV& copy_src);
    safe_VkPhysicalDeviceShadingRateImagePropertiesNV& operator=(const safe_VkPhysicalDeviceShadingRateImagePropertiesNV& copy_src);
    safe_VkPhysicalDeviceShadingRateImagePropertiesNV();
    ~safe_VkPhysicalDeviceShadingRateImagePropertiesNV();
    void initialize(const VkPhysicalDeviceShadingRateImagePropertiesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceShadingRateImagePropertiesNV* copy_src);
    VkPhysicalDeviceShadingRateImagePropertiesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceShadingRateImagePropertiesNV *>(this); }
    VkPhysicalDeviceShadingRateImagePropertiesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShadingRateImagePropertiesNV const *>(this); }
};

struct safe_VkCoarseSampleOrderCustomNV {
    VkShadingRatePaletteEntryNV shadingRate;
    uint32_t sampleCount;
    uint32_t sampleLocationCount;
    const VkCoarseSampleLocationNV* pSampleLocations;
    safe_VkCoarseSampleOrderCustomNV(const VkCoarseSampleOrderCustomNV* in_struct);
    safe_VkCoarseSampleOrderCustomNV(const safe_VkCoarseSampleOrderCustomNV& copy_src);
    safe_VkCoarseSampleOrderCustomNV& operator=(const safe_VkCoarseSampleOrderCustomNV& copy_src);
    safe_VkCoarseSampleOrderCustomNV();
    ~safe_VkCoarseSampleOrderCustomNV();
    void initialize(const VkCoarseSampleOrderCustomNV* in_struct);
    void initialize(const safe_VkCoarseSampleOrderCustomNV* copy_src);
    VkCoarseSampleOrderCustomNV *ptr() { return reinterpret_cast<VkCoarseSampleOrderCustomNV *>(this); }
    VkCoarseSampleOrderCustomNV const *ptr() const { return reinterpret_cast<VkCoarseSampleOrderCustomNV const *>(this); }
};

struct safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    safe_VkCoarseSampleOrderCustomNV* pCustomSampleOrders;
    safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* in_struct);
    safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(const safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& operator=(const safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV();
    ~safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV();
    void initialize(const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* copy_src);
    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV *>(this); }
    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV const *>(this); }
};

struct safe_VkRayTracingShaderGroupCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkRayTracingShaderGroupTypeKHR type;
    uint32_t generalShader;
    uint32_t closestHitShader;
    uint32_t anyHitShader;
    uint32_t intersectionShader;
    safe_VkRayTracingShaderGroupCreateInfoNV(const VkRayTracingShaderGroupCreateInfoNV* in_struct);
    safe_VkRayTracingShaderGroupCreateInfoNV(const safe_VkRayTracingShaderGroupCreateInfoNV& copy_src);
    safe_VkRayTracingShaderGroupCreateInfoNV& operator=(const safe_VkRayTracingShaderGroupCreateInfoNV& copy_src);
    safe_VkRayTracingShaderGroupCreateInfoNV();
    ~safe_VkRayTracingShaderGroupCreateInfoNV();
    void initialize(const VkRayTracingShaderGroupCreateInfoNV* in_struct);
    void initialize(const safe_VkRayTracingShaderGroupCreateInfoNV* copy_src);
    VkRayTracingShaderGroupCreateInfoNV *ptr() { return reinterpret_cast<VkRayTracingShaderGroupCreateInfoNV *>(this); }
    VkRayTracingShaderGroupCreateInfoNV const *ptr() const { return reinterpret_cast<VkRayTracingShaderGroupCreateInfoNV const *>(this); }
};

struct safe_VkRayTracingPipelineCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCreateFlags flags;
    uint32_t stageCount;
    safe_VkPipelineShaderStageCreateInfo* pStages;
    uint32_t groupCount;
    safe_VkRayTracingShaderGroupCreateInfoNV* pGroups;
    uint32_t maxRecursionDepth;
    VkPipelineLayout layout;
    VkPipeline basePipelineHandle;
    int32_t basePipelineIndex;
    safe_VkRayTracingPipelineCreateInfoNV(const VkRayTracingPipelineCreateInfoNV* in_struct);
    safe_VkRayTracingPipelineCreateInfoNV(const safe_VkRayTracingPipelineCreateInfoNV& copy_src);
    safe_VkRayTracingPipelineCreateInfoNV& operator=(const safe_VkRayTracingPipelineCreateInfoNV& copy_src);
    safe_VkRayTracingPipelineCreateInfoNV();
    ~safe_VkRayTracingPipelineCreateInfoNV();
    void initialize(const VkRayTracingPipelineCreateInfoNV* in_struct);
    void initialize(const safe_VkRayTracingPipelineCreateInfoNV* copy_src);
    VkRayTracingPipelineCreateInfoNV *ptr() { return reinterpret_cast<VkRayTracingPipelineCreateInfoNV *>(this); }
    VkRayTracingPipelineCreateInfoNV const *ptr() const { return reinterpret_cast<VkRayTracingPipelineCreateInfoNV const *>(this); }
};

struct safe_VkGeometryTrianglesNV {
    VkStructureType sType;
    const void* pNext;
    VkBuffer vertexData;
    VkDeviceSize vertexOffset;
    uint32_t vertexCount;
    VkDeviceSize vertexStride;
    VkFormat vertexFormat;
    VkBuffer indexData;
    VkDeviceSize indexOffset;
    uint32_t indexCount;
    VkIndexType indexType;
    VkBuffer transformData;
    VkDeviceSize transformOffset;
    safe_VkGeometryTrianglesNV(const VkGeometryTrianglesNV* in_struct);
    safe_VkGeometryTrianglesNV(const safe_VkGeometryTrianglesNV& copy_src);
    safe_VkGeometryTrianglesNV& operator=(const safe_VkGeometryTrianglesNV& copy_src);
    safe_VkGeometryTrianglesNV();
    ~safe_VkGeometryTrianglesNV();
    void initialize(const VkGeometryTrianglesNV* in_struct);
    void initialize(const safe_VkGeometryTrianglesNV* copy_src);
    VkGeometryTrianglesNV *ptr() { return reinterpret_cast<VkGeometryTrianglesNV *>(this); }
    VkGeometryTrianglesNV const *ptr() const { return reinterpret_cast<VkGeometryTrianglesNV const *>(this); }
};

struct safe_VkGeometryAABBNV {
    VkStructureType sType;
    const void* pNext;
    VkBuffer aabbData;
    uint32_t numAABBs;
    uint32_t stride;
    VkDeviceSize offset;
    safe_VkGeometryAABBNV(const VkGeometryAABBNV* in_struct);
    safe_VkGeometryAABBNV(const safe_VkGeometryAABBNV& copy_src);
    safe_VkGeometryAABBNV& operator=(const safe_VkGeometryAABBNV& copy_src);
    safe_VkGeometryAABBNV();
    ~safe_VkGeometryAABBNV();
    void initialize(const VkGeometryAABBNV* in_struct);
    void initialize(const safe_VkGeometryAABBNV* copy_src);
    VkGeometryAABBNV *ptr() { return reinterpret_cast<VkGeometryAABBNV *>(this); }
    VkGeometryAABBNV const *ptr() const { return reinterpret_cast<VkGeometryAABBNV const *>(this); }
};

struct safe_VkGeometryNV {
    VkStructureType sType;
    const void* pNext;
    VkGeometryTypeKHR geometryType;
    VkGeometryDataNV geometry;
    VkGeometryFlagsKHR flags;
    safe_VkGeometryNV(const VkGeometryNV* in_struct);
    safe_VkGeometryNV(const safe_VkGeometryNV& copy_src);
    safe_VkGeometryNV& operator=(const safe_VkGeometryNV& copy_src);
    safe_VkGeometryNV();
    ~safe_VkGeometryNV();
    void initialize(const VkGeometryNV* in_struct);
    void initialize(const safe_VkGeometryNV* copy_src);
    VkGeometryNV *ptr() { return reinterpret_cast<VkGeometryNV *>(this); }
    VkGeometryNV const *ptr() const { return reinterpret_cast<VkGeometryNV const *>(this); }
};

struct safe_VkAccelerationStructureInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureTypeNV type;
    VkBuildAccelerationStructureFlagsNV flags;
    uint32_t instanceCount;
    uint32_t geometryCount;
    safe_VkGeometryNV* pGeometries;
    safe_VkAccelerationStructureInfoNV(const VkAccelerationStructureInfoNV* in_struct);
    safe_VkAccelerationStructureInfoNV(const safe_VkAccelerationStructureInfoNV& copy_src);
    safe_VkAccelerationStructureInfoNV& operator=(const safe_VkAccelerationStructureInfoNV& copy_src);
    safe_VkAccelerationStructureInfoNV();
    ~safe_VkAccelerationStructureInfoNV();
    void initialize(const VkAccelerationStructureInfoNV* in_struct);
    void initialize(const safe_VkAccelerationStructureInfoNV* copy_src);
    VkAccelerationStructureInfoNV *ptr() { return reinterpret_cast<VkAccelerationStructureInfoNV *>(this); }
    VkAccelerationStructureInfoNV const *ptr() const { return reinterpret_cast<VkAccelerationStructureInfoNV const *>(this); }
};

struct safe_VkAccelerationStructureCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkDeviceSize compactedSize;
    safe_VkAccelerationStructureInfoNV info;
    safe_VkAccelerationStructureCreateInfoNV(const VkAccelerationStructureCreateInfoNV* in_struct);
    safe_VkAccelerationStructureCreateInfoNV(const safe_VkAccelerationStructureCreateInfoNV& copy_src);
    safe_VkAccelerationStructureCreateInfoNV& operator=(const safe_VkAccelerationStructureCreateInfoNV& copy_src);
    safe_VkAccelerationStructureCreateInfoNV();
    ~safe_VkAccelerationStructureCreateInfoNV();
    void initialize(const VkAccelerationStructureCreateInfoNV* in_struct);
    void initialize(const safe_VkAccelerationStructureCreateInfoNV* copy_src);
    VkAccelerationStructureCreateInfoNV *ptr() { return reinterpret_cast<VkAccelerationStructureCreateInfoNV *>(this); }
    VkAccelerationStructureCreateInfoNV const *ptr() const { return reinterpret_cast<VkAccelerationStructureCreateInfoNV const *>(this); }
};

struct safe_VkBindAccelerationStructureMemoryInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureKHR accelerationStructure;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    uint32_t deviceIndexCount;
    const uint32_t* pDeviceIndices;
    safe_VkBindAccelerationStructureMemoryInfoKHR(const VkBindAccelerationStructureMemoryInfoKHR* in_struct);
    safe_VkBindAccelerationStructureMemoryInfoKHR(const safe_VkBindAccelerationStructureMemoryInfoKHR& copy_src);
    safe_VkBindAccelerationStructureMemoryInfoKHR& operator=(const safe_VkBindAccelerationStructureMemoryInfoKHR& copy_src);
    safe_VkBindAccelerationStructureMemoryInfoKHR();
    ~safe_VkBindAccelerationStructureMemoryInfoKHR();
    void initialize(const VkBindAccelerationStructureMemoryInfoKHR* in_struct);
    void initialize(const safe_VkBindAccelerationStructureMemoryInfoKHR* copy_src);
    VkBindAccelerationStructureMemoryInfoKHR *ptr() { return reinterpret_cast<VkBindAccelerationStructureMemoryInfoKHR *>(this); }
    VkBindAccelerationStructureMemoryInfoKHR const *ptr() const { return reinterpret_cast<VkBindAccelerationStructureMemoryInfoKHR const *>(this); }
};

struct safe_VkWriteDescriptorSetAccelerationStructureKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t accelerationStructureCount;
    VkAccelerationStructureKHR* pAccelerationStructures;
    safe_VkWriteDescriptorSetAccelerationStructureKHR(const VkWriteDescriptorSetAccelerationStructureKHR* in_struct);
    safe_VkWriteDescriptorSetAccelerationStructureKHR(const safe_VkWriteDescriptorSetAccelerationStructureKHR& copy_src);
    safe_VkWriteDescriptorSetAccelerationStructureKHR& operator=(const safe_VkWriteDescriptorSetAccelerationStructureKHR& copy_src);
    safe_VkWriteDescriptorSetAccelerationStructureKHR();
    ~safe_VkWriteDescriptorSetAccelerationStructureKHR();
    void initialize(const VkWriteDescriptorSetAccelerationStructureKHR* in_struct);
    void initialize(const safe_VkWriteDescriptorSetAccelerationStructureKHR* copy_src);
    VkWriteDescriptorSetAccelerationStructureKHR *ptr() { return reinterpret_cast<VkWriteDescriptorSetAccelerationStructureKHR *>(this); }
    VkWriteDescriptorSetAccelerationStructureKHR const *ptr() const { return reinterpret_cast<VkWriteDescriptorSetAccelerationStructureKHR const *>(this); }
};

struct safe_VkAccelerationStructureMemoryRequirementsInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureMemoryRequirementsTypeNV type;
    VkAccelerationStructureNV accelerationStructure;
    safe_VkAccelerationStructureMemoryRequirementsInfoNV(const VkAccelerationStructureMemoryRequirementsInfoNV* in_struct);
    safe_VkAccelerationStructureMemoryRequirementsInfoNV(const safe_VkAccelerationStructureMemoryRequirementsInfoNV& copy_src);
    safe_VkAccelerationStructureMemoryRequirementsInfoNV& operator=(const safe_VkAccelerationStructureMemoryRequirementsInfoNV& copy_src);
    safe_VkAccelerationStructureMemoryRequirementsInfoNV();
    ~safe_VkAccelerationStructureMemoryRequirementsInfoNV();
    void initialize(const VkAccelerationStructureMemoryRequirementsInfoNV* in_struct);
    void initialize(const safe_VkAccelerationStructureMemoryRequirementsInfoNV* copy_src);
    VkAccelerationStructureMemoryRequirementsInfoNV *ptr() { return reinterpret_cast<VkAccelerationStructureMemoryRequirementsInfoNV *>(this); }
    VkAccelerationStructureMemoryRequirementsInfoNV const *ptr() const { return reinterpret_cast<VkAccelerationStructureMemoryRequirementsInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceRayTracingPropertiesNV {
    VkStructureType sType;
    void* pNext;
    uint32_t shaderGroupHandleSize;
    uint32_t maxRecursionDepth;
    uint32_t maxShaderGroupStride;
    uint32_t shaderGroupBaseAlignment;
    uint64_t maxGeometryCount;
    uint64_t maxInstanceCount;
    uint64_t maxTriangleCount;
    uint32_t maxDescriptorSetAccelerationStructures;
    safe_VkPhysicalDeviceRayTracingPropertiesNV(const VkPhysicalDeviceRayTracingPropertiesNV* in_struct);
    safe_VkPhysicalDeviceRayTracingPropertiesNV(const safe_VkPhysicalDeviceRayTracingPropertiesNV& copy_src);
    safe_VkPhysicalDeviceRayTracingPropertiesNV& operator=(const safe_VkPhysicalDeviceRayTracingPropertiesNV& copy_src);
    safe_VkPhysicalDeviceRayTracingPropertiesNV();
    ~safe_VkPhysicalDeviceRayTracingPropertiesNV();
    void initialize(const VkPhysicalDeviceRayTracingPropertiesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceRayTracingPropertiesNV* copy_src);
    VkPhysicalDeviceRayTracingPropertiesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceRayTracingPropertiesNV *>(this); }
    VkPhysicalDeviceRayTracingPropertiesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceRayTracingPropertiesNV const *>(this); }
};

struct safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 representativeFragmentTest;
    safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* in_struct);
    safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(const safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& copy_src);
    safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& operator=(const safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& copy_src);
    safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV();
    ~safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV();
    void initialize(const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* copy_src);
    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV *>(this); }
    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV const *>(this); }
};

struct safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkBool32 representativeFragmentTestEnable;
    safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(const VkPipelineRepresentativeFragmentTestStateCreateInfoNV* in_struct);
    safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(const safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV& copy_src);
    safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV& operator=(const safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV& copy_src);
    safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV();
    ~safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV();
    void initialize(const VkPipelineRepresentativeFragmentTestStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* copy_src);
    VkPipelineRepresentativeFragmentTestStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineRepresentativeFragmentTestStateCreateInfoNV *>(this); }
    VkPipelineRepresentativeFragmentTestStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineRepresentativeFragmentTestStateCreateInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceImageViewImageFormatInfoEXT {
    VkStructureType sType;
    void* pNext;
    VkImageViewType imageViewType;
    safe_VkPhysicalDeviceImageViewImageFormatInfoEXT(const VkPhysicalDeviceImageViewImageFormatInfoEXT* in_struct);
    safe_VkPhysicalDeviceImageViewImageFormatInfoEXT(const safe_VkPhysicalDeviceImageViewImageFormatInfoEXT& copy_src);
    safe_VkPhysicalDeviceImageViewImageFormatInfoEXT& operator=(const safe_VkPhysicalDeviceImageViewImageFormatInfoEXT& copy_src);
    safe_VkPhysicalDeviceImageViewImageFormatInfoEXT();
    ~safe_VkPhysicalDeviceImageViewImageFormatInfoEXT();
    void initialize(const VkPhysicalDeviceImageViewImageFormatInfoEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceImageViewImageFormatInfoEXT* copy_src);
    VkPhysicalDeviceImageViewImageFormatInfoEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceImageViewImageFormatInfoEXT *>(this); }
    VkPhysicalDeviceImageViewImageFormatInfoEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceImageViewImageFormatInfoEXT const *>(this); }
};

struct safe_VkFilterCubicImageViewImageFormatPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 filterCubic;
    VkBool32 filterCubicMinmax;
    safe_VkFilterCubicImageViewImageFormatPropertiesEXT(const VkFilterCubicImageViewImageFormatPropertiesEXT* in_struct);
    safe_VkFilterCubicImageViewImageFormatPropertiesEXT(const safe_VkFilterCubicImageViewImageFormatPropertiesEXT& copy_src);
    safe_VkFilterCubicImageViewImageFormatPropertiesEXT& operator=(const safe_VkFilterCubicImageViewImageFormatPropertiesEXT& copy_src);
    safe_VkFilterCubicImageViewImageFormatPropertiesEXT();
    ~safe_VkFilterCubicImageViewImageFormatPropertiesEXT();
    void initialize(const VkFilterCubicImageViewImageFormatPropertiesEXT* in_struct);
    void initialize(const safe_VkFilterCubicImageViewImageFormatPropertiesEXT* copy_src);
    VkFilterCubicImageViewImageFormatPropertiesEXT *ptr() { return reinterpret_cast<VkFilterCubicImageViewImageFormatPropertiesEXT *>(this); }
    VkFilterCubicImageViewImageFormatPropertiesEXT const *ptr() const { return reinterpret_cast<VkFilterCubicImageViewImageFormatPropertiesEXT const *>(this); }
};

struct safe_VkDeviceQueueGlobalPriorityCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkQueueGlobalPriorityEXT globalPriority;
    safe_VkDeviceQueueGlobalPriorityCreateInfoEXT(const VkDeviceQueueGlobalPriorityCreateInfoEXT* in_struct);
    safe_VkDeviceQueueGlobalPriorityCreateInfoEXT(const safe_VkDeviceQueueGlobalPriorityCreateInfoEXT& copy_src);
    safe_VkDeviceQueueGlobalPriorityCreateInfoEXT& operator=(const safe_VkDeviceQueueGlobalPriorityCreateInfoEXT& copy_src);
    safe_VkDeviceQueueGlobalPriorityCreateInfoEXT();
    ~safe_VkDeviceQueueGlobalPriorityCreateInfoEXT();
    void initialize(const VkDeviceQueueGlobalPriorityCreateInfoEXT* in_struct);
    void initialize(const safe_VkDeviceQueueGlobalPriorityCreateInfoEXT* copy_src);
    VkDeviceQueueGlobalPriorityCreateInfoEXT *ptr() { return reinterpret_cast<VkDeviceQueueGlobalPriorityCreateInfoEXT *>(this); }
    VkDeviceQueueGlobalPriorityCreateInfoEXT const *ptr() const { return reinterpret_cast<VkDeviceQueueGlobalPriorityCreateInfoEXT const *>(this); }
};

struct safe_VkImportMemoryHostPointerInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkExternalMemoryHandleTypeFlagBits handleType;
    void* pHostPointer;
    safe_VkImportMemoryHostPointerInfoEXT(const VkImportMemoryHostPointerInfoEXT* in_struct);
    safe_VkImportMemoryHostPointerInfoEXT(const safe_VkImportMemoryHostPointerInfoEXT& copy_src);
    safe_VkImportMemoryHostPointerInfoEXT& operator=(const safe_VkImportMemoryHostPointerInfoEXT& copy_src);
    safe_VkImportMemoryHostPointerInfoEXT();
    ~safe_VkImportMemoryHostPointerInfoEXT();
    void initialize(const VkImportMemoryHostPointerInfoEXT* in_struct);
    void initialize(const safe_VkImportMemoryHostPointerInfoEXT* copy_src);
    VkImportMemoryHostPointerInfoEXT *ptr() { return reinterpret_cast<VkImportMemoryHostPointerInfoEXT *>(this); }
    VkImportMemoryHostPointerInfoEXT const *ptr() const { return reinterpret_cast<VkImportMemoryHostPointerInfoEXT const *>(this); }
};

struct safe_VkMemoryHostPointerPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t memoryTypeBits;
    safe_VkMemoryHostPointerPropertiesEXT(const VkMemoryHostPointerPropertiesEXT* in_struct);
    safe_VkMemoryHostPointerPropertiesEXT(const safe_VkMemoryHostPointerPropertiesEXT& copy_src);
    safe_VkMemoryHostPointerPropertiesEXT& operator=(const safe_VkMemoryHostPointerPropertiesEXT& copy_src);
    safe_VkMemoryHostPointerPropertiesEXT();
    ~safe_VkMemoryHostPointerPropertiesEXT();
    void initialize(const VkMemoryHostPointerPropertiesEXT* in_struct);
    void initialize(const safe_VkMemoryHostPointerPropertiesEXT* copy_src);
    VkMemoryHostPointerPropertiesEXT *ptr() { return reinterpret_cast<VkMemoryHostPointerPropertiesEXT *>(this); }
    VkMemoryHostPointerPropertiesEXT const *ptr() const { return reinterpret_cast<VkMemoryHostPointerPropertiesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkDeviceSize minImportedHostPointerAlignment;
    safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(const safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT& operator=(const safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT();
    ~safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT();
    void initialize(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* copy_src);
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceExternalMemoryHostPropertiesEXT *>(this); }
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceExternalMemoryHostPropertiesEXT const *>(this); }
};

struct safe_VkPipelineCompilerControlCreateInfoAMD {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCompilerControlFlagsAMD compilerControlFlags;
    safe_VkPipelineCompilerControlCreateInfoAMD(const VkPipelineCompilerControlCreateInfoAMD* in_struct);
    safe_VkPipelineCompilerControlCreateInfoAMD(const safe_VkPipelineCompilerControlCreateInfoAMD& copy_src);
    safe_VkPipelineCompilerControlCreateInfoAMD& operator=(const safe_VkPipelineCompilerControlCreateInfoAMD& copy_src);
    safe_VkPipelineCompilerControlCreateInfoAMD();
    ~safe_VkPipelineCompilerControlCreateInfoAMD();
    void initialize(const VkPipelineCompilerControlCreateInfoAMD* in_struct);
    void initialize(const safe_VkPipelineCompilerControlCreateInfoAMD* copy_src);
    VkPipelineCompilerControlCreateInfoAMD *ptr() { return reinterpret_cast<VkPipelineCompilerControlCreateInfoAMD *>(this); }
    VkPipelineCompilerControlCreateInfoAMD const *ptr() const { return reinterpret_cast<VkPipelineCompilerControlCreateInfoAMD const *>(this); }
};

struct safe_VkCalibratedTimestampInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkTimeDomainEXT timeDomain;
    safe_VkCalibratedTimestampInfoEXT(const VkCalibratedTimestampInfoEXT* in_struct);
    safe_VkCalibratedTimestampInfoEXT(const safe_VkCalibratedTimestampInfoEXT& copy_src);
    safe_VkCalibratedTimestampInfoEXT& operator=(const safe_VkCalibratedTimestampInfoEXT& copy_src);
    safe_VkCalibratedTimestampInfoEXT();
    ~safe_VkCalibratedTimestampInfoEXT();
    void initialize(const VkCalibratedTimestampInfoEXT* in_struct);
    void initialize(const safe_VkCalibratedTimestampInfoEXT* copy_src);
    VkCalibratedTimestampInfoEXT *ptr() { return reinterpret_cast<VkCalibratedTimestampInfoEXT *>(this); }
    VkCalibratedTimestampInfoEXT const *ptr() const { return reinterpret_cast<VkCalibratedTimestampInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceShaderCorePropertiesAMD {
    VkStructureType sType;
    void* pNext;
    uint32_t shaderEngineCount;
    uint32_t shaderArraysPerEngineCount;
    uint32_t computeUnitsPerShaderArray;
    uint32_t simdPerComputeUnit;
    uint32_t wavefrontsPerSimd;
    uint32_t wavefrontSize;
    uint32_t sgprsPerSimd;
    uint32_t minSgprAllocation;
    uint32_t maxSgprAllocation;
    uint32_t sgprAllocationGranularity;
    uint32_t vgprsPerSimd;
    uint32_t minVgprAllocation;
    uint32_t maxVgprAllocation;
    uint32_t vgprAllocationGranularity;
    safe_VkPhysicalDeviceShaderCorePropertiesAMD(const VkPhysicalDeviceShaderCorePropertiesAMD* in_struct);
    safe_VkPhysicalDeviceShaderCorePropertiesAMD(const safe_VkPhysicalDeviceShaderCorePropertiesAMD& copy_src);
    safe_VkPhysicalDeviceShaderCorePropertiesAMD& operator=(const safe_VkPhysicalDeviceShaderCorePropertiesAMD& copy_src);
    safe_VkPhysicalDeviceShaderCorePropertiesAMD();
    ~safe_VkPhysicalDeviceShaderCorePropertiesAMD();
    void initialize(const VkPhysicalDeviceShaderCorePropertiesAMD* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderCorePropertiesAMD* copy_src);
    VkPhysicalDeviceShaderCorePropertiesAMD *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderCorePropertiesAMD *>(this); }
    VkPhysicalDeviceShaderCorePropertiesAMD const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderCorePropertiesAMD const *>(this); }
};

struct safe_VkDeviceMemoryOverallocationCreateInfoAMD {
    VkStructureType sType;
    const void* pNext;
    VkMemoryOverallocationBehaviorAMD overallocationBehavior;
    safe_VkDeviceMemoryOverallocationCreateInfoAMD(const VkDeviceMemoryOverallocationCreateInfoAMD* in_struct);
    safe_VkDeviceMemoryOverallocationCreateInfoAMD(const safe_VkDeviceMemoryOverallocationCreateInfoAMD& copy_src);
    safe_VkDeviceMemoryOverallocationCreateInfoAMD& operator=(const safe_VkDeviceMemoryOverallocationCreateInfoAMD& copy_src);
    safe_VkDeviceMemoryOverallocationCreateInfoAMD();
    ~safe_VkDeviceMemoryOverallocationCreateInfoAMD();
    void initialize(const VkDeviceMemoryOverallocationCreateInfoAMD* in_struct);
    void initialize(const safe_VkDeviceMemoryOverallocationCreateInfoAMD* copy_src);
    VkDeviceMemoryOverallocationCreateInfoAMD *ptr() { return reinterpret_cast<VkDeviceMemoryOverallocationCreateInfoAMD *>(this); }
    VkDeviceMemoryOverallocationCreateInfoAMD const *ptr() const { return reinterpret_cast<VkDeviceMemoryOverallocationCreateInfoAMD const *>(this); }
};

struct safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t maxVertexAttribDivisor;
    safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(const safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& operator=(const safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT();
    ~safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT();
    void initialize(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* copy_src);
    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *>(this); }
    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT const *>(this); }
};

struct safe_VkPipelineVertexInputDivisorStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t vertexBindingDivisorCount;
    const VkVertexInputBindingDivisorDescriptionEXT* pVertexBindingDivisors;
    safe_VkPipelineVertexInputDivisorStateCreateInfoEXT(const VkPipelineVertexInputDivisorStateCreateInfoEXT* in_struct);
    safe_VkPipelineVertexInputDivisorStateCreateInfoEXT(const safe_VkPipelineVertexInputDivisorStateCreateInfoEXT& copy_src);
    safe_VkPipelineVertexInputDivisorStateCreateInfoEXT& operator=(const safe_VkPipelineVertexInputDivisorStateCreateInfoEXT& copy_src);
    safe_VkPipelineVertexInputDivisorStateCreateInfoEXT();
    ~safe_VkPipelineVertexInputDivisorStateCreateInfoEXT();
    void initialize(const VkPipelineVertexInputDivisorStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineVertexInputDivisorStateCreateInfoEXT* copy_src);
    VkPipelineVertexInputDivisorStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineVertexInputDivisorStateCreateInfoEXT *>(this); }
    VkPipelineVertexInputDivisorStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineVertexInputDivisorStateCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 vertexAttributeInstanceRateDivisor;
    VkBool32 vertexAttributeInstanceRateZeroDivisor;
    safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(const safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& operator=(const safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT();
    ~safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT();
    void initialize(const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* copy_src);
    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *>(this); }
    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT const *>(this); }
};

#ifdef VK_USE_PLATFORM_GGP
struct safe_VkPresentFrameTokenGGP {
    VkStructureType sType;
    const void* pNext;
    GgpFrameToken frameToken;
    safe_VkPresentFrameTokenGGP(const VkPresentFrameTokenGGP* in_struct);
    safe_VkPresentFrameTokenGGP(const safe_VkPresentFrameTokenGGP& copy_src);
    safe_VkPresentFrameTokenGGP& operator=(const safe_VkPresentFrameTokenGGP& copy_src);
    safe_VkPresentFrameTokenGGP();
    ~safe_VkPresentFrameTokenGGP();
    void initialize(const VkPresentFrameTokenGGP* in_struct);
    void initialize(const safe_VkPresentFrameTokenGGP* copy_src);
    VkPresentFrameTokenGGP *ptr() { return reinterpret_cast<VkPresentFrameTokenGGP *>(this); }
    VkPresentFrameTokenGGP const *ptr() const { return reinterpret_cast<VkPresentFrameTokenGGP const *>(this); }
};
#endif // VK_USE_PLATFORM_GGP

struct safe_VkPipelineCreationFeedbackCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCreationFeedbackEXT* pPipelineCreationFeedback;
    uint32_t pipelineStageCreationFeedbackCount;
    VkPipelineCreationFeedbackEXT* pPipelineStageCreationFeedbacks;
    safe_VkPipelineCreationFeedbackCreateInfoEXT(const VkPipelineCreationFeedbackCreateInfoEXT* in_struct);
    safe_VkPipelineCreationFeedbackCreateInfoEXT(const safe_VkPipelineCreationFeedbackCreateInfoEXT& copy_src);
    safe_VkPipelineCreationFeedbackCreateInfoEXT& operator=(const safe_VkPipelineCreationFeedbackCreateInfoEXT& copy_src);
    safe_VkPipelineCreationFeedbackCreateInfoEXT();
    ~safe_VkPipelineCreationFeedbackCreateInfoEXT();
    void initialize(const VkPipelineCreationFeedbackCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineCreationFeedbackCreateInfoEXT* copy_src);
    VkPipelineCreationFeedbackCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineCreationFeedbackCreateInfoEXT *>(this); }
    VkPipelineCreationFeedbackCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineCreationFeedbackCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 computeDerivativeGroupQuads;
    VkBool32 computeDerivativeGroupLinear;
    safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV(const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* in_struct);
    safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV(const safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& copy_src);
    safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& operator=(const safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& copy_src);
    safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV();
    ~safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV();
    void initialize(const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* copy_src);
    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV *>(this); }
    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV const *>(this); }
};

struct safe_VkPhysicalDeviceMeshShaderFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 taskShader;
    VkBool32 meshShader;
    safe_VkPhysicalDeviceMeshShaderFeaturesNV(const VkPhysicalDeviceMeshShaderFeaturesNV* in_struct);
    safe_VkPhysicalDeviceMeshShaderFeaturesNV(const safe_VkPhysicalDeviceMeshShaderFeaturesNV& copy_src);
    safe_VkPhysicalDeviceMeshShaderFeaturesNV& operator=(const safe_VkPhysicalDeviceMeshShaderFeaturesNV& copy_src);
    safe_VkPhysicalDeviceMeshShaderFeaturesNV();
    ~safe_VkPhysicalDeviceMeshShaderFeaturesNV();
    void initialize(const VkPhysicalDeviceMeshShaderFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceMeshShaderFeaturesNV* copy_src);
    VkPhysicalDeviceMeshShaderFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceMeshShaderFeaturesNV *>(this); }
    VkPhysicalDeviceMeshShaderFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMeshShaderFeaturesNV const *>(this); }
};

struct safe_VkPhysicalDeviceMeshShaderPropertiesNV {
    VkStructureType sType;
    void* pNext;
    uint32_t maxDrawMeshTasksCount;
    uint32_t maxTaskWorkGroupInvocations;
    uint32_t maxTaskWorkGroupSize[3];
    uint32_t maxTaskTotalMemorySize;
    uint32_t maxTaskOutputCount;
    uint32_t maxMeshWorkGroupInvocations;
    uint32_t maxMeshWorkGroupSize[3];
    uint32_t maxMeshTotalMemorySize;
    uint32_t maxMeshOutputVertices;
    uint32_t maxMeshOutputPrimitives;
    uint32_t maxMeshMultiviewViewCount;
    uint32_t meshOutputPerVertexGranularity;
    uint32_t meshOutputPerPrimitiveGranularity;
    safe_VkPhysicalDeviceMeshShaderPropertiesNV(const VkPhysicalDeviceMeshShaderPropertiesNV* in_struct);
    safe_VkPhysicalDeviceMeshShaderPropertiesNV(const safe_VkPhysicalDeviceMeshShaderPropertiesNV& copy_src);
    safe_VkPhysicalDeviceMeshShaderPropertiesNV& operator=(const safe_VkPhysicalDeviceMeshShaderPropertiesNV& copy_src);
    safe_VkPhysicalDeviceMeshShaderPropertiesNV();
    ~safe_VkPhysicalDeviceMeshShaderPropertiesNV();
    void initialize(const VkPhysicalDeviceMeshShaderPropertiesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceMeshShaderPropertiesNV* copy_src);
    VkPhysicalDeviceMeshShaderPropertiesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceMeshShaderPropertiesNV *>(this); }
    VkPhysicalDeviceMeshShaderPropertiesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMeshShaderPropertiesNV const *>(this); }
};

struct safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 fragmentShaderBarycentric;
    safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV(const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* in_struct);
    safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV(const safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV& copy_src);
    safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV& operator=(const safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV& copy_src);
    safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV();
    ~safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV();
    void initialize(const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* copy_src);
    VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV *>(this); }
    VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV const *>(this); }
};

struct safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 imageFootprint;
    safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV(const VkPhysicalDeviceShaderImageFootprintFeaturesNV* in_struct);
    safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV(const safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV& copy_src);
    safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV& operator=(const safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV& copy_src);
    safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV();
    ~safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV();
    void initialize(const VkPhysicalDeviceShaderImageFootprintFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderImageFootprintFeaturesNV* copy_src);
    VkPhysicalDeviceShaderImageFootprintFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderImageFootprintFeaturesNV *>(this); }
    VkPhysicalDeviceShaderImageFootprintFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderImageFootprintFeaturesNV const *>(this); }
};

struct safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    uint32_t exclusiveScissorCount;
    const VkRect2D* pExclusiveScissors;
    safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV(const VkPipelineViewportExclusiveScissorStateCreateInfoNV* in_struct);
    safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV(const safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV& operator=(const safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV& copy_src);
    safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV();
    ~safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV();
    void initialize(const VkPipelineViewportExclusiveScissorStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineViewportExclusiveScissorStateCreateInfoNV* copy_src);
    VkPipelineViewportExclusiveScissorStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineViewportExclusiveScissorStateCreateInfoNV *>(this); }
    VkPipelineViewportExclusiveScissorStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineViewportExclusiveScissorStateCreateInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceExclusiveScissorFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 exclusiveScissor;
    safe_VkPhysicalDeviceExclusiveScissorFeaturesNV(const VkPhysicalDeviceExclusiveScissorFeaturesNV* in_struct);
    safe_VkPhysicalDeviceExclusiveScissorFeaturesNV(const safe_VkPhysicalDeviceExclusiveScissorFeaturesNV& copy_src);
    safe_VkPhysicalDeviceExclusiveScissorFeaturesNV& operator=(const safe_VkPhysicalDeviceExclusiveScissorFeaturesNV& copy_src);
    safe_VkPhysicalDeviceExclusiveScissorFeaturesNV();
    ~safe_VkPhysicalDeviceExclusiveScissorFeaturesNV();
    void initialize(const VkPhysicalDeviceExclusiveScissorFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceExclusiveScissorFeaturesNV* copy_src);
    VkPhysicalDeviceExclusiveScissorFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceExclusiveScissorFeaturesNV *>(this); }
    VkPhysicalDeviceExclusiveScissorFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceExclusiveScissorFeaturesNV const *>(this); }
};

struct safe_VkQueueFamilyCheckpointPropertiesNV {
    VkStructureType sType;
    void* pNext;
    VkPipelineStageFlags checkpointExecutionStageMask;
    safe_VkQueueFamilyCheckpointPropertiesNV(const VkQueueFamilyCheckpointPropertiesNV* in_struct);
    safe_VkQueueFamilyCheckpointPropertiesNV(const safe_VkQueueFamilyCheckpointPropertiesNV& copy_src);
    safe_VkQueueFamilyCheckpointPropertiesNV& operator=(const safe_VkQueueFamilyCheckpointPropertiesNV& copy_src);
    safe_VkQueueFamilyCheckpointPropertiesNV();
    ~safe_VkQueueFamilyCheckpointPropertiesNV();
    void initialize(const VkQueueFamilyCheckpointPropertiesNV* in_struct);
    void initialize(const safe_VkQueueFamilyCheckpointPropertiesNV* copy_src);
    VkQueueFamilyCheckpointPropertiesNV *ptr() { return reinterpret_cast<VkQueueFamilyCheckpointPropertiesNV *>(this); }
    VkQueueFamilyCheckpointPropertiesNV const *ptr() const { return reinterpret_cast<VkQueueFamilyCheckpointPropertiesNV const *>(this); }
};

struct safe_VkCheckpointDataNV {
    VkStructureType sType;
    void* pNext;
    VkPipelineStageFlagBits stage;
    void* pCheckpointMarker;
    safe_VkCheckpointDataNV(const VkCheckpointDataNV* in_struct);
    safe_VkCheckpointDataNV(const safe_VkCheckpointDataNV& copy_src);
    safe_VkCheckpointDataNV& operator=(const safe_VkCheckpointDataNV& copy_src);
    safe_VkCheckpointDataNV();
    ~safe_VkCheckpointDataNV();
    void initialize(const VkCheckpointDataNV* in_struct);
    void initialize(const safe_VkCheckpointDataNV* copy_src);
    VkCheckpointDataNV *ptr() { return reinterpret_cast<VkCheckpointDataNV *>(this); }
    VkCheckpointDataNV const *ptr() const { return reinterpret_cast<VkCheckpointDataNV const *>(this); }
};

struct safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderIntegerFunctions2;
    safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* in_struct);
    safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(const safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL& copy_src);
    safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL& operator=(const safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL& copy_src);
    safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL();
    ~safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL();
    void initialize(const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* copy_src);
    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL *>(this); }
    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL const *>(this); }
};

union safe_VkPerformanceValueDataINTEL {
    uint32_t value32;
    uint64_t value64;
    float valueFloat;
    VkBool32 valueBool;
    const char* valueString;
    safe_VkPerformanceValueDataINTEL(const VkPerformanceValueDataINTEL* in_struct);
    safe_VkPerformanceValueDataINTEL(const safe_VkPerformanceValueDataINTEL& copy_src);
    safe_VkPerformanceValueDataINTEL& operator=(const safe_VkPerformanceValueDataINTEL& copy_src);
    safe_VkPerformanceValueDataINTEL();
    ~safe_VkPerformanceValueDataINTEL();
    void initialize(const VkPerformanceValueDataINTEL* in_struct);
    void initialize(const safe_VkPerformanceValueDataINTEL* copy_src);
    VkPerformanceValueDataINTEL *ptr() { return reinterpret_cast<VkPerformanceValueDataINTEL *>(this); }
    VkPerformanceValueDataINTEL const *ptr() const { return reinterpret_cast<VkPerformanceValueDataINTEL const *>(this); }
};

struct safe_VkInitializePerformanceApiInfoINTEL {
    VkStructureType sType;
    const void* pNext;
    void* pUserData;
    safe_VkInitializePerformanceApiInfoINTEL(const VkInitializePerformanceApiInfoINTEL* in_struct);
    safe_VkInitializePerformanceApiInfoINTEL(const safe_VkInitializePerformanceApiInfoINTEL& copy_src);
    safe_VkInitializePerformanceApiInfoINTEL& operator=(const safe_VkInitializePerformanceApiInfoINTEL& copy_src);
    safe_VkInitializePerformanceApiInfoINTEL();
    ~safe_VkInitializePerformanceApiInfoINTEL();
    void initialize(const VkInitializePerformanceApiInfoINTEL* in_struct);
    void initialize(const safe_VkInitializePerformanceApiInfoINTEL* copy_src);
    VkInitializePerformanceApiInfoINTEL *ptr() { return reinterpret_cast<VkInitializePerformanceApiInfoINTEL *>(this); }
    VkInitializePerformanceApiInfoINTEL const *ptr() const { return reinterpret_cast<VkInitializePerformanceApiInfoINTEL const *>(this); }
};

struct safe_VkQueryPoolPerformanceQueryCreateInfoINTEL {
    VkStructureType sType;
    const void* pNext;
    VkQueryPoolSamplingModeINTEL performanceCountersSampling;
    safe_VkQueryPoolPerformanceQueryCreateInfoINTEL(const VkQueryPoolPerformanceQueryCreateInfoINTEL* in_struct);
    safe_VkQueryPoolPerformanceQueryCreateInfoINTEL(const safe_VkQueryPoolPerformanceQueryCreateInfoINTEL& copy_src);
    safe_VkQueryPoolPerformanceQueryCreateInfoINTEL& operator=(const safe_VkQueryPoolPerformanceQueryCreateInfoINTEL& copy_src);
    safe_VkQueryPoolPerformanceQueryCreateInfoINTEL();
    ~safe_VkQueryPoolPerformanceQueryCreateInfoINTEL();
    void initialize(const VkQueryPoolPerformanceQueryCreateInfoINTEL* in_struct);
    void initialize(const safe_VkQueryPoolPerformanceQueryCreateInfoINTEL* copy_src);
    VkQueryPoolPerformanceQueryCreateInfoINTEL *ptr() { return reinterpret_cast<VkQueryPoolPerformanceQueryCreateInfoINTEL *>(this); }
    VkQueryPoolPerformanceQueryCreateInfoINTEL const *ptr() const { return reinterpret_cast<VkQueryPoolPerformanceQueryCreateInfoINTEL const *>(this); }
};

struct safe_VkPerformanceMarkerInfoINTEL {
    VkStructureType sType;
    const void* pNext;
    uint64_t marker;
    safe_VkPerformanceMarkerInfoINTEL(const VkPerformanceMarkerInfoINTEL* in_struct);
    safe_VkPerformanceMarkerInfoINTEL(const safe_VkPerformanceMarkerInfoINTEL& copy_src);
    safe_VkPerformanceMarkerInfoINTEL& operator=(const safe_VkPerformanceMarkerInfoINTEL& copy_src);
    safe_VkPerformanceMarkerInfoINTEL();
    ~safe_VkPerformanceMarkerInfoINTEL();
    void initialize(const VkPerformanceMarkerInfoINTEL* in_struct);
    void initialize(const safe_VkPerformanceMarkerInfoINTEL* copy_src);
    VkPerformanceMarkerInfoINTEL *ptr() { return reinterpret_cast<VkPerformanceMarkerInfoINTEL *>(this); }
    VkPerformanceMarkerInfoINTEL const *ptr() const { return reinterpret_cast<VkPerformanceMarkerInfoINTEL const *>(this); }
};

struct safe_VkPerformanceStreamMarkerInfoINTEL {
    VkStructureType sType;
    const void* pNext;
    uint32_t marker;
    safe_VkPerformanceStreamMarkerInfoINTEL(const VkPerformanceStreamMarkerInfoINTEL* in_struct);
    safe_VkPerformanceStreamMarkerInfoINTEL(const safe_VkPerformanceStreamMarkerInfoINTEL& copy_src);
    safe_VkPerformanceStreamMarkerInfoINTEL& operator=(const safe_VkPerformanceStreamMarkerInfoINTEL& copy_src);
    safe_VkPerformanceStreamMarkerInfoINTEL();
    ~safe_VkPerformanceStreamMarkerInfoINTEL();
    void initialize(const VkPerformanceStreamMarkerInfoINTEL* in_struct);
    void initialize(const safe_VkPerformanceStreamMarkerInfoINTEL* copy_src);
    VkPerformanceStreamMarkerInfoINTEL *ptr() { return reinterpret_cast<VkPerformanceStreamMarkerInfoINTEL *>(this); }
    VkPerformanceStreamMarkerInfoINTEL const *ptr() const { return reinterpret_cast<VkPerformanceStreamMarkerInfoINTEL const *>(this); }
};

struct safe_VkPerformanceOverrideInfoINTEL {
    VkStructureType sType;
    const void* pNext;
    VkPerformanceOverrideTypeINTEL type;
    VkBool32 enable;
    uint64_t parameter;
    safe_VkPerformanceOverrideInfoINTEL(const VkPerformanceOverrideInfoINTEL* in_struct);
    safe_VkPerformanceOverrideInfoINTEL(const safe_VkPerformanceOverrideInfoINTEL& copy_src);
    safe_VkPerformanceOverrideInfoINTEL& operator=(const safe_VkPerformanceOverrideInfoINTEL& copy_src);
    safe_VkPerformanceOverrideInfoINTEL();
    ~safe_VkPerformanceOverrideInfoINTEL();
    void initialize(const VkPerformanceOverrideInfoINTEL* in_struct);
    void initialize(const safe_VkPerformanceOverrideInfoINTEL* copy_src);
    VkPerformanceOverrideInfoINTEL *ptr() { return reinterpret_cast<VkPerformanceOverrideInfoINTEL *>(this); }
    VkPerformanceOverrideInfoINTEL const *ptr() const { return reinterpret_cast<VkPerformanceOverrideInfoINTEL const *>(this); }
};

struct safe_VkPerformanceConfigurationAcquireInfoINTEL {
    VkStructureType sType;
    const void* pNext;
    VkPerformanceConfigurationTypeINTEL type;
    safe_VkPerformanceConfigurationAcquireInfoINTEL(const VkPerformanceConfigurationAcquireInfoINTEL* in_struct);
    safe_VkPerformanceConfigurationAcquireInfoINTEL(const safe_VkPerformanceConfigurationAcquireInfoINTEL& copy_src);
    safe_VkPerformanceConfigurationAcquireInfoINTEL& operator=(const safe_VkPerformanceConfigurationAcquireInfoINTEL& copy_src);
    safe_VkPerformanceConfigurationAcquireInfoINTEL();
    ~safe_VkPerformanceConfigurationAcquireInfoINTEL();
    void initialize(const VkPerformanceConfigurationAcquireInfoINTEL* in_struct);
    void initialize(const safe_VkPerformanceConfigurationAcquireInfoINTEL* copy_src);
    VkPerformanceConfigurationAcquireInfoINTEL *ptr() { return reinterpret_cast<VkPerformanceConfigurationAcquireInfoINTEL *>(this); }
    VkPerformanceConfigurationAcquireInfoINTEL const *ptr() const { return reinterpret_cast<VkPerformanceConfigurationAcquireInfoINTEL const *>(this); }
};

struct safe_VkPhysicalDevicePCIBusInfoPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t pciDomain;
    uint32_t pciBus;
    uint32_t pciDevice;
    uint32_t pciFunction;
    safe_VkPhysicalDevicePCIBusInfoPropertiesEXT(const VkPhysicalDevicePCIBusInfoPropertiesEXT* in_struct);
    safe_VkPhysicalDevicePCIBusInfoPropertiesEXT(const safe_VkPhysicalDevicePCIBusInfoPropertiesEXT& copy_src);
    safe_VkPhysicalDevicePCIBusInfoPropertiesEXT& operator=(const safe_VkPhysicalDevicePCIBusInfoPropertiesEXT& copy_src);
    safe_VkPhysicalDevicePCIBusInfoPropertiesEXT();
    ~safe_VkPhysicalDevicePCIBusInfoPropertiesEXT();
    void initialize(const VkPhysicalDevicePCIBusInfoPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDevicePCIBusInfoPropertiesEXT* copy_src);
    VkPhysicalDevicePCIBusInfoPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDevicePCIBusInfoPropertiesEXT *>(this); }
    VkPhysicalDevicePCIBusInfoPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDevicePCIBusInfoPropertiesEXT const *>(this); }
};

struct safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD {
    VkStructureType sType;
    void* pNext;
    VkBool32 localDimmingSupport;
    safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD(const VkDisplayNativeHdrSurfaceCapabilitiesAMD* in_struct);
    safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD(const safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD& copy_src);
    safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD& operator=(const safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD& copy_src);
    safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD();
    ~safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD();
    void initialize(const VkDisplayNativeHdrSurfaceCapabilitiesAMD* in_struct);
    void initialize(const safe_VkDisplayNativeHdrSurfaceCapabilitiesAMD* copy_src);
    VkDisplayNativeHdrSurfaceCapabilitiesAMD *ptr() { return reinterpret_cast<VkDisplayNativeHdrSurfaceCapabilitiesAMD *>(this); }
    VkDisplayNativeHdrSurfaceCapabilitiesAMD const *ptr() const { return reinterpret_cast<VkDisplayNativeHdrSurfaceCapabilitiesAMD const *>(this); }
};

struct safe_VkSwapchainDisplayNativeHdrCreateInfoAMD {
    VkStructureType sType;
    const void* pNext;
    VkBool32 localDimmingEnable;
    safe_VkSwapchainDisplayNativeHdrCreateInfoAMD(const VkSwapchainDisplayNativeHdrCreateInfoAMD* in_struct);
    safe_VkSwapchainDisplayNativeHdrCreateInfoAMD(const safe_VkSwapchainDisplayNativeHdrCreateInfoAMD& copy_src);
    safe_VkSwapchainDisplayNativeHdrCreateInfoAMD& operator=(const safe_VkSwapchainDisplayNativeHdrCreateInfoAMD& copy_src);
    safe_VkSwapchainDisplayNativeHdrCreateInfoAMD();
    ~safe_VkSwapchainDisplayNativeHdrCreateInfoAMD();
    void initialize(const VkSwapchainDisplayNativeHdrCreateInfoAMD* in_struct);
    void initialize(const safe_VkSwapchainDisplayNativeHdrCreateInfoAMD* copy_src);
    VkSwapchainDisplayNativeHdrCreateInfoAMD *ptr() { return reinterpret_cast<VkSwapchainDisplayNativeHdrCreateInfoAMD *>(this); }
    VkSwapchainDisplayNativeHdrCreateInfoAMD const *ptr() const { return reinterpret_cast<VkSwapchainDisplayNativeHdrCreateInfoAMD const *>(this); }
};

#ifdef VK_USE_PLATFORM_FUCHSIA
struct safe_VkImagePipeSurfaceCreateInfoFUCHSIA {
    VkStructureType sType;
    const void* pNext;
    VkImagePipeSurfaceCreateFlagsFUCHSIA flags;
    zx_handle_t imagePipeHandle;
    safe_VkImagePipeSurfaceCreateInfoFUCHSIA(const VkImagePipeSurfaceCreateInfoFUCHSIA* in_struct);
    safe_VkImagePipeSurfaceCreateInfoFUCHSIA(const safe_VkImagePipeSurfaceCreateInfoFUCHSIA& copy_src);
    safe_VkImagePipeSurfaceCreateInfoFUCHSIA& operator=(const safe_VkImagePipeSurfaceCreateInfoFUCHSIA& copy_src);
    safe_VkImagePipeSurfaceCreateInfoFUCHSIA();
    ~safe_VkImagePipeSurfaceCreateInfoFUCHSIA();
    void initialize(const VkImagePipeSurfaceCreateInfoFUCHSIA* in_struct);
    void initialize(const safe_VkImagePipeSurfaceCreateInfoFUCHSIA* copy_src);
    VkImagePipeSurfaceCreateInfoFUCHSIA *ptr() { return reinterpret_cast<VkImagePipeSurfaceCreateInfoFUCHSIA *>(this); }
    VkImagePipeSurfaceCreateInfoFUCHSIA const *ptr() const { return reinterpret_cast<VkImagePipeSurfaceCreateInfoFUCHSIA const *>(this); }
};
#endif // VK_USE_PLATFORM_FUCHSIA

#ifdef VK_USE_PLATFORM_METAL_EXT
struct safe_VkMetalSurfaceCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkMetalSurfaceCreateFlagsEXT flags;
    const CAMetalLayer* pLayer;
    safe_VkMetalSurfaceCreateInfoEXT(const VkMetalSurfaceCreateInfoEXT* in_struct);
    safe_VkMetalSurfaceCreateInfoEXT(const safe_VkMetalSurfaceCreateInfoEXT& copy_src);
    safe_VkMetalSurfaceCreateInfoEXT& operator=(const safe_VkMetalSurfaceCreateInfoEXT& copy_src);
    safe_VkMetalSurfaceCreateInfoEXT();
    ~safe_VkMetalSurfaceCreateInfoEXT();
    void initialize(const VkMetalSurfaceCreateInfoEXT* in_struct);
    void initialize(const safe_VkMetalSurfaceCreateInfoEXT* copy_src);
    VkMetalSurfaceCreateInfoEXT *ptr() { return reinterpret_cast<VkMetalSurfaceCreateInfoEXT *>(this); }
    VkMetalSurfaceCreateInfoEXT const *ptr() const { return reinterpret_cast<VkMetalSurfaceCreateInfoEXT const *>(this); }
};
#endif // VK_USE_PLATFORM_METAL_EXT

struct safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 fragmentDensityMap;
    VkBool32 fragmentDensityMapDynamic;
    VkBool32 fragmentDensityMapNonSubsampledImages;
    safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(const safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT& operator=(const safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT();
    ~safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT();
    void initialize(const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* copy_src);
    VkPhysicalDeviceFragmentDensityMapFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT *>(this); }
    VkPhysicalDeviceFragmentDensityMapFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceFragmentDensityMapFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkExtent2D minFragmentDensityTexelSize;
    VkExtent2D maxFragmentDensityTexelSize;
    VkBool32 fragmentDensityInvocations;
    safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(const VkPhysicalDeviceFragmentDensityMapPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(const safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT& operator=(const safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT();
    ~safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT();
    void initialize(const VkPhysicalDeviceFragmentDensityMapPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* copy_src);
    VkPhysicalDeviceFragmentDensityMapPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceFragmentDensityMapPropertiesEXT *>(this); }
    VkPhysicalDeviceFragmentDensityMapPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceFragmentDensityMapPropertiesEXT const *>(this); }
};

struct safe_VkRenderPassFragmentDensityMapCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkAttachmentReference fragmentDensityMapAttachment;
    safe_VkRenderPassFragmentDensityMapCreateInfoEXT(const VkRenderPassFragmentDensityMapCreateInfoEXT* in_struct);
    safe_VkRenderPassFragmentDensityMapCreateInfoEXT(const safe_VkRenderPassFragmentDensityMapCreateInfoEXT& copy_src);
    safe_VkRenderPassFragmentDensityMapCreateInfoEXT& operator=(const safe_VkRenderPassFragmentDensityMapCreateInfoEXT& copy_src);
    safe_VkRenderPassFragmentDensityMapCreateInfoEXT();
    ~safe_VkRenderPassFragmentDensityMapCreateInfoEXT();
    void initialize(const VkRenderPassFragmentDensityMapCreateInfoEXT* in_struct);
    void initialize(const safe_VkRenderPassFragmentDensityMapCreateInfoEXT* copy_src);
    VkRenderPassFragmentDensityMapCreateInfoEXT *ptr() { return reinterpret_cast<VkRenderPassFragmentDensityMapCreateInfoEXT *>(this); }
    VkRenderPassFragmentDensityMapCreateInfoEXT const *ptr() const { return reinterpret_cast<VkRenderPassFragmentDensityMapCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 subgroupSizeControl;
    VkBool32 computeFullSubgroups;
    safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT(const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT(const safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT& operator=(const safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT();
    ~safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT();
    void initialize(const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT* copy_src);
    VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *>(this); }
    VkPhysicalDeviceSubgroupSizeControlFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t minSubgroupSize;
    uint32_t maxSubgroupSize;
    uint32_t maxComputeWorkgroupSubgroups;
    VkShaderStageFlags requiredSubgroupSizeStages;
    safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT(const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT(const safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT& operator=(const safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT();
    ~safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT();
    void initialize(const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT* copy_src);
    VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *>(this); }
    VkPhysicalDeviceSubgroupSizeControlPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceSubgroupSizeControlPropertiesEXT const *>(this); }
};

struct safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t requiredSubgroupSize;
    safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT(const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT* in_struct);
    safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT(const safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT& copy_src);
    safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT& operator=(const safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT& copy_src);
    safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT();
    ~safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT();
    void initialize(const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT* copy_src);
    VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT *>(this); }
    VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceShaderCoreProperties2AMD {
    VkStructureType sType;
    void* pNext;
    VkShaderCorePropertiesFlagsAMD shaderCoreFeatures;
    uint32_t activeComputeUnitCount;
    safe_VkPhysicalDeviceShaderCoreProperties2AMD(const VkPhysicalDeviceShaderCoreProperties2AMD* in_struct);
    safe_VkPhysicalDeviceShaderCoreProperties2AMD(const safe_VkPhysicalDeviceShaderCoreProperties2AMD& copy_src);
    safe_VkPhysicalDeviceShaderCoreProperties2AMD& operator=(const safe_VkPhysicalDeviceShaderCoreProperties2AMD& copy_src);
    safe_VkPhysicalDeviceShaderCoreProperties2AMD();
    ~safe_VkPhysicalDeviceShaderCoreProperties2AMD();
    void initialize(const VkPhysicalDeviceShaderCoreProperties2AMD* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderCoreProperties2AMD* copy_src);
    VkPhysicalDeviceShaderCoreProperties2AMD *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderCoreProperties2AMD *>(this); }
    VkPhysicalDeviceShaderCoreProperties2AMD const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderCoreProperties2AMD const *>(this); }
};

struct safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD {
    VkStructureType sType;
    void* pNext;
    VkBool32 deviceCoherentMemory;
    safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD(const VkPhysicalDeviceCoherentMemoryFeaturesAMD* in_struct);
    safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD(const safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD& copy_src);
    safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD& operator=(const safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD& copy_src);
    safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD();
    ~safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD();
    void initialize(const VkPhysicalDeviceCoherentMemoryFeaturesAMD* in_struct);
    void initialize(const safe_VkPhysicalDeviceCoherentMemoryFeaturesAMD* copy_src);
    VkPhysicalDeviceCoherentMemoryFeaturesAMD *ptr() { return reinterpret_cast<VkPhysicalDeviceCoherentMemoryFeaturesAMD *>(this); }
    VkPhysicalDeviceCoherentMemoryFeaturesAMD const *ptr() const { return reinterpret_cast<VkPhysicalDeviceCoherentMemoryFeaturesAMD const *>(this); }
};

struct safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkDeviceSize heapBudget[VK_MAX_MEMORY_HEAPS];
    VkDeviceSize heapUsage[VK_MAX_MEMORY_HEAPS];
    safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT(const VkPhysicalDeviceMemoryBudgetPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT(const safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT& operator=(const safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT();
    ~safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT();
    void initialize(const VkPhysicalDeviceMemoryBudgetPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceMemoryBudgetPropertiesEXT* copy_src);
    VkPhysicalDeviceMemoryBudgetPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceMemoryBudgetPropertiesEXT *>(this); }
    VkPhysicalDeviceMemoryBudgetPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMemoryBudgetPropertiesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 memoryPriority;
    safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT(const VkPhysicalDeviceMemoryPriorityFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT(const safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT& operator=(const safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT();
    ~safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT();
    void initialize(const VkPhysicalDeviceMemoryPriorityFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceMemoryPriorityFeaturesEXT* copy_src);
    VkPhysicalDeviceMemoryPriorityFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceMemoryPriorityFeaturesEXT *>(this); }
    VkPhysicalDeviceMemoryPriorityFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceMemoryPriorityFeaturesEXT const *>(this); }
};

struct safe_VkMemoryPriorityAllocateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    float priority;
    safe_VkMemoryPriorityAllocateInfoEXT(const VkMemoryPriorityAllocateInfoEXT* in_struct);
    safe_VkMemoryPriorityAllocateInfoEXT(const safe_VkMemoryPriorityAllocateInfoEXT& copy_src);
    safe_VkMemoryPriorityAllocateInfoEXT& operator=(const safe_VkMemoryPriorityAllocateInfoEXT& copy_src);
    safe_VkMemoryPriorityAllocateInfoEXT();
    ~safe_VkMemoryPriorityAllocateInfoEXT();
    void initialize(const VkMemoryPriorityAllocateInfoEXT* in_struct);
    void initialize(const safe_VkMemoryPriorityAllocateInfoEXT* copy_src);
    VkMemoryPriorityAllocateInfoEXT *ptr() { return reinterpret_cast<VkMemoryPriorityAllocateInfoEXT *>(this); }
    VkMemoryPriorityAllocateInfoEXT const *ptr() const { return reinterpret_cast<VkMemoryPriorityAllocateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 dedicatedAllocationImageAliasing;
    safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* in_struct);
    safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(const safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV& copy_src);
    safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV& operator=(const safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV& copy_src);
    safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV();
    ~safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV();
    void initialize(const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* copy_src);
    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV *>(this); }
    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV const *>(this); }
};

struct safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 bufferDeviceAddress;
    VkBool32 bufferDeviceAddressCaptureReplay;
    VkBool32 bufferDeviceAddressMultiDevice;
    safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(const safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT& operator=(const safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT();
    ~safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT();
    void initialize(const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* copy_src);
    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT *>(this); }
    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT const *>(this); }
};

struct safe_VkBufferDeviceAddressCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkDeviceAddress deviceAddress;
    safe_VkBufferDeviceAddressCreateInfoEXT(const VkBufferDeviceAddressCreateInfoEXT* in_struct);
    safe_VkBufferDeviceAddressCreateInfoEXT(const safe_VkBufferDeviceAddressCreateInfoEXT& copy_src);
    safe_VkBufferDeviceAddressCreateInfoEXT& operator=(const safe_VkBufferDeviceAddressCreateInfoEXT& copy_src);
    safe_VkBufferDeviceAddressCreateInfoEXT();
    ~safe_VkBufferDeviceAddressCreateInfoEXT();
    void initialize(const VkBufferDeviceAddressCreateInfoEXT* in_struct);
    void initialize(const safe_VkBufferDeviceAddressCreateInfoEXT* copy_src);
    VkBufferDeviceAddressCreateInfoEXT *ptr() { return reinterpret_cast<VkBufferDeviceAddressCreateInfoEXT *>(this); }
    VkBufferDeviceAddressCreateInfoEXT const *ptr() const { return reinterpret_cast<VkBufferDeviceAddressCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceToolPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    char name[VK_MAX_EXTENSION_NAME_SIZE];
    char version[VK_MAX_EXTENSION_NAME_SIZE];
    VkToolPurposeFlagsEXT purposes;
    char description[VK_MAX_DESCRIPTION_SIZE];
    char layer[VK_MAX_EXTENSION_NAME_SIZE];
    safe_VkPhysicalDeviceToolPropertiesEXT(const VkPhysicalDeviceToolPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceToolPropertiesEXT(const safe_VkPhysicalDeviceToolPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceToolPropertiesEXT& operator=(const safe_VkPhysicalDeviceToolPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceToolPropertiesEXT();
    ~safe_VkPhysicalDeviceToolPropertiesEXT();
    void initialize(const VkPhysicalDeviceToolPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceToolPropertiesEXT* copy_src);
    VkPhysicalDeviceToolPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceToolPropertiesEXT *>(this); }
    VkPhysicalDeviceToolPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceToolPropertiesEXT const *>(this); }
};

struct safe_VkValidationFeaturesEXT {
    VkStructureType sType;
    const void* pNext;
    uint32_t enabledValidationFeatureCount;
    const VkValidationFeatureEnableEXT* pEnabledValidationFeatures;
    uint32_t disabledValidationFeatureCount;
    const VkValidationFeatureDisableEXT* pDisabledValidationFeatures;
    safe_VkValidationFeaturesEXT(const VkValidationFeaturesEXT* in_struct);
    safe_VkValidationFeaturesEXT(const safe_VkValidationFeaturesEXT& copy_src);
    safe_VkValidationFeaturesEXT& operator=(const safe_VkValidationFeaturesEXT& copy_src);
    safe_VkValidationFeaturesEXT();
    ~safe_VkValidationFeaturesEXT();
    void initialize(const VkValidationFeaturesEXT* in_struct);
    void initialize(const safe_VkValidationFeaturesEXT* copy_src);
    VkValidationFeaturesEXT *ptr() { return reinterpret_cast<VkValidationFeaturesEXT *>(this); }
    VkValidationFeaturesEXT const *ptr() const { return reinterpret_cast<VkValidationFeaturesEXT const *>(this); }
};

struct safe_VkCooperativeMatrixPropertiesNV {
    VkStructureType sType;
    void* pNext;
    uint32_t MSize;
    uint32_t NSize;
    uint32_t KSize;
    VkComponentTypeNV AType;
    VkComponentTypeNV BType;
    VkComponentTypeNV CType;
    VkComponentTypeNV DType;
    VkScopeNV scope;
    safe_VkCooperativeMatrixPropertiesNV(const VkCooperativeMatrixPropertiesNV* in_struct);
    safe_VkCooperativeMatrixPropertiesNV(const safe_VkCooperativeMatrixPropertiesNV& copy_src);
    safe_VkCooperativeMatrixPropertiesNV& operator=(const safe_VkCooperativeMatrixPropertiesNV& copy_src);
    safe_VkCooperativeMatrixPropertiesNV();
    ~safe_VkCooperativeMatrixPropertiesNV();
    void initialize(const VkCooperativeMatrixPropertiesNV* in_struct);
    void initialize(const safe_VkCooperativeMatrixPropertiesNV* copy_src);
    VkCooperativeMatrixPropertiesNV *ptr() { return reinterpret_cast<VkCooperativeMatrixPropertiesNV *>(this); }
    VkCooperativeMatrixPropertiesNV const *ptr() const { return reinterpret_cast<VkCooperativeMatrixPropertiesNV const *>(this); }
};

struct safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 cooperativeMatrix;
    VkBool32 cooperativeMatrixRobustBufferAccess;
    safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV(const VkPhysicalDeviceCooperativeMatrixFeaturesNV* in_struct);
    safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV(const safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV& copy_src);
    safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV& operator=(const safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV& copy_src);
    safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV();
    ~safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV();
    void initialize(const VkPhysicalDeviceCooperativeMatrixFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceCooperativeMatrixFeaturesNV* copy_src);
    VkPhysicalDeviceCooperativeMatrixFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV *>(this); }
    VkPhysicalDeviceCooperativeMatrixFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceCooperativeMatrixFeaturesNV const *>(this); }
};

struct safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV {
    VkStructureType sType;
    void* pNext;
    VkShaderStageFlags cooperativeMatrixSupportedStages;
    safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV(const VkPhysicalDeviceCooperativeMatrixPropertiesNV* in_struct);
    safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV(const safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV& copy_src);
    safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV& operator=(const safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV& copy_src);
    safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV();
    ~safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV();
    void initialize(const VkPhysicalDeviceCooperativeMatrixPropertiesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceCooperativeMatrixPropertiesNV* copy_src);
    VkPhysicalDeviceCooperativeMatrixPropertiesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceCooperativeMatrixPropertiesNV *>(this); }
    VkPhysicalDeviceCooperativeMatrixPropertiesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceCooperativeMatrixPropertiesNV const *>(this); }
};

struct safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 coverageReductionMode;
    safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV(const VkPhysicalDeviceCoverageReductionModeFeaturesNV* in_struct);
    safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV(const safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV& copy_src);
    safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV& operator=(const safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV& copy_src);
    safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV();
    ~safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV();
    void initialize(const VkPhysicalDeviceCoverageReductionModeFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceCoverageReductionModeFeaturesNV* copy_src);
    VkPhysicalDeviceCoverageReductionModeFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceCoverageReductionModeFeaturesNV *>(this); }
    VkPhysicalDeviceCoverageReductionModeFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceCoverageReductionModeFeaturesNV const *>(this); }
};

struct safe_VkPipelineCoverageReductionStateCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCoverageReductionStateCreateFlagsNV flags;
    VkCoverageReductionModeNV coverageReductionMode;
    safe_VkPipelineCoverageReductionStateCreateInfoNV(const VkPipelineCoverageReductionStateCreateInfoNV* in_struct);
    safe_VkPipelineCoverageReductionStateCreateInfoNV(const safe_VkPipelineCoverageReductionStateCreateInfoNV& copy_src);
    safe_VkPipelineCoverageReductionStateCreateInfoNV& operator=(const safe_VkPipelineCoverageReductionStateCreateInfoNV& copy_src);
    safe_VkPipelineCoverageReductionStateCreateInfoNV();
    ~safe_VkPipelineCoverageReductionStateCreateInfoNV();
    void initialize(const VkPipelineCoverageReductionStateCreateInfoNV* in_struct);
    void initialize(const safe_VkPipelineCoverageReductionStateCreateInfoNV* copy_src);
    VkPipelineCoverageReductionStateCreateInfoNV *ptr() { return reinterpret_cast<VkPipelineCoverageReductionStateCreateInfoNV *>(this); }
    VkPipelineCoverageReductionStateCreateInfoNV const *ptr() const { return reinterpret_cast<VkPipelineCoverageReductionStateCreateInfoNV const *>(this); }
};

struct safe_VkFramebufferMixedSamplesCombinationNV {
    VkStructureType sType;
    void* pNext;
    VkCoverageReductionModeNV coverageReductionMode;
    VkSampleCountFlagBits rasterizationSamples;
    VkSampleCountFlags depthStencilSamples;
    VkSampleCountFlags colorSamples;
    safe_VkFramebufferMixedSamplesCombinationNV(const VkFramebufferMixedSamplesCombinationNV* in_struct);
    safe_VkFramebufferMixedSamplesCombinationNV(const safe_VkFramebufferMixedSamplesCombinationNV& copy_src);
    safe_VkFramebufferMixedSamplesCombinationNV& operator=(const safe_VkFramebufferMixedSamplesCombinationNV& copy_src);
    safe_VkFramebufferMixedSamplesCombinationNV();
    ~safe_VkFramebufferMixedSamplesCombinationNV();
    void initialize(const VkFramebufferMixedSamplesCombinationNV* in_struct);
    void initialize(const safe_VkFramebufferMixedSamplesCombinationNV* copy_src);
    VkFramebufferMixedSamplesCombinationNV *ptr() { return reinterpret_cast<VkFramebufferMixedSamplesCombinationNV *>(this); }
    VkFramebufferMixedSamplesCombinationNV const *ptr() const { return reinterpret_cast<VkFramebufferMixedSamplesCombinationNV const *>(this); }
};

struct safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 fragmentShaderSampleInterlock;
    VkBool32 fragmentShaderPixelInterlock;
    VkBool32 fragmentShaderShadingRateInterlock;
    safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(const safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT& operator=(const safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT();
    ~safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT();
    void initialize(const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* copy_src);
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *>(this); }
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 ycbcrImageArrays;
    safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(const safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT& operator=(const safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT();
    ~safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT();
    void initialize(const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* copy_src);
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *>(this); }
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT const *>(this); }
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkSurfaceFullScreenExclusiveInfoEXT {
    VkStructureType sType;
    void* pNext;
    VkFullScreenExclusiveEXT fullScreenExclusive;
    safe_VkSurfaceFullScreenExclusiveInfoEXT(const VkSurfaceFullScreenExclusiveInfoEXT* in_struct);
    safe_VkSurfaceFullScreenExclusiveInfoEXT(const safe_VkSurfaceFullScreenExclusiveInfoEXT& copy_src);
    safe_VkSurfaceFullScreenExclusiveInfoEXT& operator=(const safe_VkSurfaceFullScreenExclusiveInfoEXT& copy_src);
    safe_VkSurfaceFullScreenExclusiveInfoEXT();
    ~safe_VkSurfaceFullScreenExclusiveInfoEXT();
    void initialize(const VkSurfaceFullScreenExclusiveInfoEXT* in_struct);
    void initialize(const safe_VkSurfaceFullScreenExclusiveInfoEXT* copy_src);
    VkSurfaceFullScreenExclusiveInfoEXT *ptr() { return reinterpret_cast<VkSurfaceFullScreenExclusiveInfoEXT *>(this); }
    VkSurfaceFullScreenExclusiveInfoEXT const *ptr() const { return reinterpret_cast<VkSurfaceFullScreenExclusiveInfoEXT const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 fullScreenExclusiveSupported;
    safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT(const VkSurfaceCapabilitiesFullScreenExclusiveEXT* in_struct);
    safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT(const safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT& copy_src);
    safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT& operator=(const safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT& copy_src);
    safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT();
    ~safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT();
    void initialize(const VkSurfaceCapabilitiesFullScreenExclusiveEXT* in_struct);
    void initialize(const safe_VkSurfaceCapabilitiesFullScreenExclusiveEXT* copy_src);
    VkSurfaceCapabilitiesFullScreenExclusiveEXT *ptr() { return reinterpret_cast<VkSurfaceCapabilitiesFullScreenExclusiveEXT *>(this); }
    VkSurfaceCapabilitiesFullScreenExclusiveEXT const *ptr() const { return reinterpret_cast<VkSurfaceCapabilitiesFullScreenExclusiveEXT const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct safe_VkSurfaceFullScreenExclusiveWin32InfoEXT {
    VkStructureType sType;
    const void* pNext;
    HMONITOR hmonitor;
    safe_VkSurfaceFullScreenExclusiveWin32InfoEXT(const VkSurfaceFullScreenExclusiveWin32InfoEXT* in_struct);
    safe_VkSurfaceFullScreenExclusiveWin32InfoEXT(const safe_VkSurfaceFullScreenExclusiveWin32InfoEXT& copy_src);
    safe_VkSurfaceFullScreenExclusiveWin32InfoEXT& operator=(const safe_VkSurfaceFullScreenExclusiveWin32InfoEXT& copy_src);
    safe_VkSurfaceFullScreenExclusiveWin32InfoEXT();
    ~safe_VkSurfaceFullScreenExclusiveWin32InfoEXT();
    void initialize(const VkSurfaceFullScreenExclusiveWin32InfoEXT* in_struct);
    void initialize(const safe_VkSurfaceFullScreenExclusiveWin32InfoEXT* copy_src);
    VkSurfaceFullScreenExclusiveWin32InfoEXT *ptr() { return reinterpret_cast<VkSurfaceFullScreenExclusiveWin32InfoEXT *>(this); }
    VkSurfaceFullScreenExclusiveWin32InfoEXT const *ptr() const { return reinterpret_cast<VkSurfaceFullScreenExclusiveWin32InfoEXT const *>(this); }
};
#endif // VK_USE_PLATFORM_WIN32_KHR

struct safe_VkHeadlessSurfaceCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkHeadlessSurfaceCreateFlagsEXT flags;
    safe_VkHeadlessSurfaceCreateInfoEXT(const VkHeadlessSurfaceCreateInfoEXT* in_struct);
    safe_VkHeadlessSurfaceCreateInfoEXT(const safe_VkHeadlessSurfaceCreateInfoEXT& copy_src);
    safe_VkHeadlessSurfaceCreateInfoEXT& operator=(const safe_VkHeadlessSurfaceCreateInfoEXT& copy_src);
    safe_VkHeadlessSurfaceCreateInfoEXT();
    ~safe_VkHeadlessSurfaceCreateInfoEXT();
    void initialize(const VkHeadlessSurfaceCreateInfoEXT* in_struct);
    void initialize(const safe_VkHeadlessSurfaceCreateInfoEXT* copy_src);
    VkHeadlessSurfaceCreateInfoEXT *ptr() { return reinterpret_cast<VkHeadlessSurfaceCreateInfoEXT *>(this); }
    VkHeadlessSurfaceCreateInfoEXT const *ptr() const { return reinterpret_cast<VkHeadlessSurfaceCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceLineRasterizationFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 rectangularLines;
    VkBool32 bresenhamLines;
    VkBool32 smoothLines;
    VkBool32 stippledRectangularLines;
    VkBool32 stippledBresenhamLines;
    VkBool32 stippledSmoothLines;
    safe_VkPhysicalDeviceLineRasterizationFeaturesEXT(const VkPhysicalDeviceLineRasterizationFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceLineRasterizationFeaturesEXT(const safe_VkPhysicalDeviceLineRasterizationFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceLineRasterizationFeaturesEXT& operator=(const safe_VkPhysicalDeviceLineRasterizationFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceLineRasterizationFeaturesEXT();
    ~safe_VkPhysicalDeviceLineRasterizationFeaturesEXT();
    void initialize(const VkPhysicalDeviceLineRasterizationFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceLineRasterizationFeaturesEXT* copy_src);
    VkPhysicalDeviceLineRasterizationFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT *>(this); }
    VkPhysicalDeviceLineRasterizationFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceLineRasterizationFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceLineRasterizationPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    uint32_t lineSubPixelPrecisionBits;
    safe_VkPhysicalDeviceLineRasterizationPropertiesEXT(const VkPhysicalDeviceLineRasterizationPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceLineRasterizationPropertiesEXT(const safe_VkPhysicalDeviceLineRasterizationPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceLineRasterizationPropertiesEXT& operator=(const safe_VkPhysicalDeviceLineRasterizationPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceLineRasterizationPropertiesEXT();
    ~safe_VkPhysicalDeviceLineRasterizationPropertiesEXT();
    void initialize(const VkPhysicalDeviceLineRasterizationPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceLineRasterizationPropertiesEXT* copy_src);
    VkPhysicalDeviceLineRasterizationPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceLineRasterizationPropertiesEXT *>(this); }
    VkPhysicalDeviceLineRasterizationPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceLineRasterizationPropertiesEXT const *>(this); }
};

struct safe_VkPipelineRasterizationLineStateCreateInfoEXT {
    VkStructureType sType;
    const void* pNext;
    VkLineRasterizationModeEXT lineRasterizationMode;
    VkBool32 stippledLineEnable;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;
    safe_VkPipelineRasterizationLineStateCreateInfoEXT(const VkPipelineRasterizationLineStateCreateInfoEXT* in_struct);
    safe_VkPipelineRasterizationLineStateCreateInfoEXT(const safe_VkPipelineRasterizationLineStateCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationLineStateCreateInfoEXT& operator=(const safe_VkPipelineRasterizationLineStateCreateInfoEXT& copy_src);
    safe_VkPipelineRasterizationLineStateCreateInfoEXT();
    ~safe_VkPipelineRasterizationLineStateCreateInfoEXT();
    void initialize(const VkPipelineRasterizationLineStateCreateInfoEXT* in_struct);
    void initialize(const safe_VkPipelineRasterizationLineStateCreateInfoEXT* copy_src);
    VkPipelineRasterizationLineStateCreateInfoEXT *ptr() { return reinterpret_cast<VkPipelineRasterizationLineStateCreateInfoEXT *>(this); }
    VkPipelineRasterizationLineStateCreateInfoEXT const *ptr() const { return reinterpret_cast<VkPipelineRasterizationLineStateCreateInfoEXT const *>(this); }
};

struct safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 indexTypeUint8;
    safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT(const VkPhysicalDeviceIndexTypeUint8FeaturesEXT* in_struct);
    safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT(const safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT& copy_src);
    safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT& operator=(const safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT& copy_src);
    safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT();
    ~safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT();
    void initialize(const VkPhysicalDeviceIndexTypeUint8FeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceIndexTypeUint8FeaturesEXT* copy_src);
    VkPhysicalDeviceIndexTypeUint8FeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceIndexTypeUint8FeaturesEXT *>(this); }
    VkPhysicalDeviceIndexTypeUint8FeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceIndexTypeUint8FeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 shaderDemoteToHelperInvocation;
    safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT(const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT(const safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT& operator=(const safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT();
    ~safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT();
    void initialize(const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT* copy_src);
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *>(this); }
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV {
    VkStructureType sType;
    void* pNext;
    uint32_t maxGraphicsShaderGroupCount;
    uint32_t maxIndirectSequenceCount;
    uint32_t maxIndirectCommandsTokenCount;
    uint32_t maxIndirectCommandsStreamCount;
    uint32_t maxIndirectCommandsTokenOffset;
    uint32_t maxIndirectCommandsStreamStride;
    uint32_t minSequencesCountBufferOffsetAlignment;
    uint32_t minSequencesIndexBufferOffsetAlignment;
    uint32_t minIndirectCommandsBufferOffsetAlignment;
    safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* in_struct);
    safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(const safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV& copy_src);
    safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV& operator=(const safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV& copy_src);
    safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV();
    ~safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV();
    void initialize(const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* copy_src);
    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV *>(this); }
    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV const *>(this); }
};

struct safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 deviceGeneratedCommands;
    safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* in_struct);
    safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(const safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV& copy_src);
    safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV& operator=(const safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV& copy_src);
    safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV();
    ~safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV();
    void initialize(const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* copy_src);
    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV *>(this); }
    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV const *>(this); }
};

struct safe_VkGraphicsShaderGroupCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    uint32_t stageCount;
    safe_VkPipelineShaderStageCreateInfo* pStages;
    safe_VkPipelineVertexInputStateCreateInfo* pVertexInputState;
    safe_VkPipelineTessellationStateCreateInfo* pTessellationState;
    safe_VkGraphicsShaderGroupCreateInfoNV(const VkGraphicsShaderGroupCreateInfoNV* in_struct);
    safe_VkGraphicsShaderGroupCreateInfoNV(const safe_VkGraphicsShaderGroupCreateInfoNV& copy_src);
    safe_VkGraphicsShaderGroupCreateInfoNV& operator=(const safe_VkGraphicsShaderGroupCreateInfoNV& copy_src);
    safe_VkGraphicsShaderGroupCreateInfoNV();
    ~safe_VkGraphicsShaderGroupCreateInfoNV();
    void initialize(const VkGraphicsShaderGroupCreateInfoNV* in_struct);
    void initialize(const safe_VkGraphicsShaderGroupCreateInfoNV* copy_src);
    VkGraphicsShaderGroupCreateInfoNV *ptr() { return reinterpret_cast<VkGraphicsShaderGroupCreateInfoNV *>(this); }
    VkGraphicsShaderGroupCreateInfoNV const *ptr() const { return reinterpret_cast<VkGraphicsShaderGroupCreateInfoNV const *>(this); }
};

struct safe_VkGraphicsPipelineShaderGroupsCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    uint32_t groupCount;
    safe_VkGraphicsShaderGroupCreateInfoNV* pGroups;
    uint32_t pipelineCount;
    VkPipeline* pPipelines;
    safe_VkGraphicsPipelineShaderGroupsCreateInfoNV(const VkGraphicsPipelineShaderGroupsCreateInfoNV* in_struct);
    safe_VkGraphicsPipelineShaderGroupsCreateInfoNV(const safe_VkGraphicsPipelineShaderGroupsCreateInfoNV& copy_src);
    safe_VkGraphicsPipelineShaderGroupsCreateInfoNV& operator=(const safe_VkGraphicsPipelineShaderGroupsCreateInfoNV& copy_src);
    safe_VkGraphicsPipelineShaderGroupsCreateInfoNV();
    ~safe_VkGraphicsPipelineShaderGroupsCreateInfoNV();
    void initialize(const VkGraphicsPipelineShaderGroupsCreateInfoNV* in_struct);
    void initialize(const safe_VkGraphicsPipelineShaderGroupsCreateInfoNV* copy_src);
    VkGraphicsPipelineShaderGroupsCreateInfoNV *ptr() { return reinterpret_cast<VkGraphicsPipelineShaderGroupsCreateInfoNV *>(this); }
    VkGraphicsPipelineShaderGroupsCreateInfoNV const *ptr() const { return reinterpret_cast<VkGraphicsPipelineShaderGroupsCreateInfoNV const *>(this); }
};

struct safe_VkIndirectCommandsLayoutTokenNV {
    VkStructureType sType;
    const void* pNext;
    VkIndirectCommandsTokenTypeNV tokenType;
    uint32_t stream;
    uint32_t offset;
    uint32_t vertexBindingUnit;
    VkBool32 vertexDynamicStride;
    VkPipelineLayout pushconstantPipelineLayout;
    VkShaderStageFlags pushconstantShaderStageFlags;
    uint32_t pushconstantOffset;
    uint32_t pushconstantSize;
    VkIndirectStateFlagsNV indirectStateFlags;
    uint32_t indexTypeCount;
    const VkIndexType* pIndexTypes;
    const uint32_t* pIndexTypeValues;
    safe_VkIndirectCommandsLayoutTokenNV(const VkIndirectCommandsLayoutTokenNV* in_struct);
    safe_VkIndirectCommandsLayoutTokenNV(const safe_VkIndirectCommandsLayoutTokenNV& copy_src);
    safe_VkIndirectCommandsLayoutTokenNV& operator=(const safe_VkIndirectCommandsLayoutTokenNV& copy_src);
    safe_VkIndirectCommandsLayoutTokenNV();
    ~safe_VkIndirectCommandsLayoutTokenNV();
    void initialize(const VkIndirectCommandsLayoutTokenNV* in_struct);
    void initialize(const safe_VkIndirectCommandsLayoutTokenNV* copy_src);
    VkIndirectCommandsLayoutTokenNV *ptr() { return reinterpret_cast<VkIndirectCommandsLayoutTokenNV *>(this); }
    VkIndirectCommandsLayoutTokenNV const *ptr() const { return reinterpret_cast<VkIndirectCommandsLayoutTokenNV const *>(this); }
};

struct safe_VkIndirectCommandsLayoutCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkIndirectCommandsLayoutUsageFlagsNV flags;
    VkPipelineBindPoint pipelineBindPoint;
    uint32_t tokenCount;
    safe_VkIndirectCommandsLayoutTokenNV* pTokens;
    uint32_t streamCount;
    const uint32_t* pStreamStrides;
    safe_VkIndirectCommandsLayoutCreateInfoNV(const VkIndirectCommandsLayoutCreateInfoNV* in_struct);
    safe_VkIndirectCommandsLayoutCreateInfoNV(const safe_VkIndirectCommandsLayoutCreateInfoNV& copy_src);
    safe_VkIndirectCommandsLayoutCreateInfoNV& operator=(const safe_VkIndirectCommandsLayoutCreateInfoNV& copy_src);
    safe_VkIndirectCommandsLayoutCreateInfoNV();
    ~safe_VkIndirectCommandsLayoutCreateInfoNV();
    void initialize(const VkIndirectCommandsLayoutCreateInfoNV* in_struct);
    void initialize(const safe_VkIndirectCommandsLayoutCreateInfoNV* copy_src);
    VkIndirectCommandsLayoutCreateInfoNV *ptr() { return reinterpret_cast<VkIndirectCommandsLayoutCreateInfoNV *>(this); }
    VkIndirectCommandsLayoutCreateInfoNV const *ptr() const { return reinterpret_cast<VkIndirectCommandsLayoutCreateInfoNV const *>(this); }
};

struct safe_VkGeneratedCommandsInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;
    VkIndirectCommandsLayoutNV indirectCommandsLayout;
    uint32_t streamCount;
    VkIndirectCommandsStreamNV* pStreams;
    uint32_t sequencesCount;
    VkBuffer preprocessBuffer;
    VkDeviceSize preprocessOffset;
    VkDeviceSize preprocessSize;
    VkBuffer sequencesCountBuffer;
    VkDeviceSize sequencesCountOffset;
    VkBuffer sequencesIndexBuffer;
    VkDeviceSize sequencesIndexOffset;
    safe_VkGeneratedCommandsInfoNV(const VkGeneratedCommandsInfoNV* in_struct);
    safe_VkGeneratedCommandsInfoNV(const safe_VkGeneratedCommandsInfoNV& copy_src);
    safe_VkGeneratedCommandsInfoNV& operator=(const safe_VkGeneratedCommandsInfoNV& copy_src);
    safe_VkGeneratedCommandsInfoNV();
    ~safe_VkGeneratedCommandsInfoNV();
    void initialize(const VkGeneratedCommandsInfoNV* in_struct);
    void initialize(const safe_VkGeneratedCommandsInfoNV* copy_src);
    VkGeneratedCommandsInfoNV *ptr() { return reinterpret_cast<VkGeneratedCommandsInfoNV *>(this); }
    VkGeneratedCommandsInfoNV const *ptr() const { return reinterpret_cast<VkGeneratedCommandsInfoNV const *>(this); }
};

struct safe_VkGeneratedCommandsMemoryRequirementsInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;
    VkIndirectCommandsLayoutNV indirectCommandsLayout;
    uint32_t maxSequencesCount;
    safe_VkGeneratedCommandsMemoryRequirementsInfoNV(const VkGeneratedCommandsMemoryRequirementsInfoNV* in_struct);
    safe_VkGeneratedCommandsMemoryRequirementsInfoNV(const safe_VkGeneratedCommandsMemoryRequirementsInfoNV& copy_src);
    safe_VkGeneratedCommandsMemoryRequirementsInfoNV& operator=(const safe_VkGeneratedCommandsMemoryRequirementsInfoNV& copy_src);
    safe_VkGeneratedCommandsMemoryRequirementsInfoNV();
    ~safe_VkGeneratedCommandsMemoryRequirementsInfoNV();
    void initialize(const VkGeneratedCommandsMemoryRequirementsInfoNV* in_struct);
    void initialize(const safe_VkGeneratedCommandsMemoryRequirementsInfoNV* copy_src);
    VkGeneratedCommandsMemoryRequirementsInfoNV *ptr() { return reinterpret_cast<VkGeneratedCommandsMemoryRequirementsInfoNV *>(this); }
    VkGeneratedCommandsMemoryRequirementsInfoNV const *ptr() const { return reinterpret_cast<VkGeneratedCommandsMemoryRequirementsInfoNV const *>(this); }
};

struct safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 texelBufferAlignment;
    safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* in_struct);
    safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(const safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT& operator=(const safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT& copy_src);
    safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT();
    ~safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT();
    void initialize(const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* copy_src);
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *>(this); }
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT {
    VkStructureType sType;
    void* pNext;
    VkDeviceSize storageTexelBufferOffsetAlignmentBytes;
    VkBool32 storageTexelBufferOffsetSingleTexelAlignment;
    VkDeviceSize uniformTexelBufferOffsetAlignmentBytes;
    VkBool32 uniformTexelBufferOffsetSingleTexelAlignment;
    safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT(const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT* in_struct);
    safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT(const safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT& operator=(const safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT& copy_src);
    safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT();
    ~safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT();
    void initialize(const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT* in_struct);
    void initialize(const safe_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT* copy_src);
    VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *ptr() { return reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *>(this); }
    VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT const *>(this); }
};

struct safe_VkRenderPassTransformBeginInfoQCOM {
    VkStructureType sType;
    void* pNext;
    VkSurfaceTransformFlagBitsKHR transform;
    safe_VkRenderPassTransformBeginInfoQCOM(const VkRenderPassTransformBeginInfoQCOM* in_struct);
    safe_VkRenderPassTransformBeginInfoQCOM(const safe_VkRenderPassTransformBeginInfoQCOM& copy_src);
    safe_VkRenderPassTransformBeginInfoQCOM& operator=(const safe_VkRenderPassTransformBeginInfoQCOM& copy_src);
    safe_VkRenderPassTransformBeginInfoQCOM();
    ~safe_VkRenderPassTransformBeginInfoQCOM();
    void initialize(const VkRenderPassTransformBeginInfoQCOM* in_struct);
    void initialize(const safe_VkRenderPassTransformBeginInfoQCOM* copy_src);
    VkRenderPassTransformBeginInfoQCOM *ptr() { return reinterpret_cast<VkRenderPassTransformBeginInfoQCOM *>(this); }
    VkRenderPassTransformBeginInfoQCOM const *ptr() const { return reinterpret_cast<VkRenderPassTransformBeginInfoQCOM const *>(this); }
};

struct safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM {
    VkStructureType sType;
    void* pNext;
    VkSurfaceTransformFlagBitsKHR transform;
    VkRect2D renderArea;
    safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(const VkCommandBufferInheritanceRenderPassTransformInfoQCOM* in_struct);
    safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(const safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM& copy_src);
    safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM& operator=(const safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM& copy_src);
    safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM();
    ~safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM();
    void initialize(const VkCommandBufferInheritanceRenderPassTransformInfoQCOM* in_struct);
    void initialize(const safe_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* copy_src);
    VkCommandBufferInheritanceRenderPassTransformInfoQCOM *ptr() { return reinterpret_cast<VkCommandBufferInheritanceRenderPassTransformInfoQCOM *>(this); }
    VkCommandBufferInheritanceRenderPassTransformInfoQCOM const *ptr() const { return reinterpret_cast<VkCommandBufferInheritanceRenderPassTransformInfoQCOM const *>(this); }
};

struct safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT {
    VkStructureType sType;
    void* pNext;
    VkBool32 pipelineCreationCacheControl;
    safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT(const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT* in_struct);
    safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT(const safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT& copy_src);
    safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT& operator=(const safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT& copy_src);
    safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT();
    ~safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT();
    void initialize(const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT* in_struct);
    void initialize(const safe_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT* copy_src);
    VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT *ptr() { return reinterpret_cast<VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT *>(this); }
    VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT const *ptr() const { return reinterpret_cast<VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT const *>(this); }
};

struct safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV {
    VkStructureType sType;
    void* pNext;
    VkBool32 diagnosticsConfig;
    safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* in_struct);
    safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(const safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV& copy_src);
    safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV& operator=(const safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV& copy_src);
    safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV();
    ~safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV();
    void initialize(const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* in_struct);
    void initialize(const safe_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* copy_src);
    VkPhysicalDeviceDiagnosticsConfigFeaturesNV *ptr() { return reinterpret_cast<VkPhysicalDeviceDiagnosticsConfigFeaturesNV *>(this); }
    VkPhysicalDeviceDiagnosticsConfigFeaturesNV const *ptr() const { return reinterpret_cast<VkPhysicalDeviceDiagnosticsConfigFeaturesNV const *>(this); }
};

struct safe_VkDeviceDiagnosticsConfigCreateInfoNV {
    VkStructureType sType;
    const void* pNext;
    VkDeviceDiagnosticsConfigFlagsNV flags;
    safe_VkDeviceDiagnosticsConfigCreateInfoNV(const VkDeviceDiagnosticsConfigCreateInfoNV* in_struct);
    safe_VkDeviceDiagnosticsConfigCreateInfoNV(const safe_VkDeviceDiagnosticsConfigCreateInfoNV& copy_src);
    safe_VkDeviceDiagnosticsConfigCreateInfoNV& operator=(const safe_VkDeviceDiagnosticsConfigCreateInfoNV& copy_src);
    safe_VkDeviceDiagnosticsConfigCreateInfoNV();
    ~safe_VkDeviceDiagnosticsConfigCreateInfoNV();
    void initialize(const VkDeviceDiagnosticsConfigCreateInfoNV* in_struct);
    void initialize(const safe_VkDeviceDiagnosticsConfigCreateInfoNV* copy_src);
    VkDeviceDiagnosticsConfigCreateInfoNV *ptr() { return reinterpret_cast<VkDeviceDiagnosticsConfigCreateInfoNV *>(this); }
    VkDeviceDiagnosticsConfigCreateInfoNV const *ptr() const { return reinterpret_cast<VkDeviceDiagnosticsConfigCreateInfoNV const *>(this); }
};

#ifdef VK_ENABLE_BETA_EXTENSIONS
union safe_VkDeviceOrHostAddressKHR {
    VkDeviceAddress deviceAddress;
    void* hostAddress;
    safe_VkDeviceOrHostAddressKHR(const VkDeviceOrHostAddressKHR* in_struct);
    safe_VkDeviceOrHostAddressKHR(const safe_VkDeviceOrHostAddressKHR& copy_src);
    safe_VkDeviceOrHostAddressKHR& operator=(const safe_VkDeviceOrHostAddressKHR& copy_src);
    safe_VkDeviceOrHostAddressKHR();
    ~safe_VkDeviceOrHostAddressKHR();
    void initialize(const VkDeviceOrHostAddressKHR* in_struct);
    void initialize(const safe_VkDeviceOrHostAddressKHR* copy_src);
    VkDeviceOrHostAddressKHR *ptr() { return reinterpret_cast<VkDeviceOrHostAddressKHR *>(this); }
    VkDeviceOrHostAddressKHR const *ptr() const { return reinterpret_cast<VkDeviceOrHostAddressKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
union safe_VkDeviceOrHostAddressConstKHR {
    VkDeviceAddress deviceAddress;
    const void* hostAddress;
    safe_VkDeviceOrHostAddressConstKHR(const VkDeviceOrHostAddressConstKHR* in_struct);
    safe_VkDeviceOrHostAddressConstKHR(const safe_VkDeviceOrHostAddressConstKHR& copy_src);
    safe_VkDeviceOrHostAddressConstKHR& operator=(const safe_VkDeviceOrHostAddressConstKHR& copy_src);
    safe_VkDeviceOrHostAddressConstKHR();
    ~safe_VkDeviceOrHostAddressConstKHR();
    void initialize(const VkDeviceOrHostAddressConstKHR* in_struct);
    void initialize(const safe_VkDeviceOrHostAddressConstKHR* copy_src);
    VkDeviceOrHostAddressConstKHR *ptr() { return reinterpret_cast<VkDeviceOrHostAddressConstKHR *>(this); }
    VkDeviceOrHostAddressConstKHR const *ptr() const { return reinterpret_cast<VkDeviceOrHostAddressConstKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkRayTracingShaderGroupCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkRayTracingShaderGroupTypeKHR type;
    uint32_t generalShader;
    uint32_t closestHitShader;
    uint32_t anyHitShader;
    uint32_t intersectionShader;
    const void* pShaderGroupCaptureReplayHandle;
    safe_VkRayTracingShaderGroupCreateInfoKHR(const VkRayTracingShaderGroupCreateInfoKHR* in_struct);
    safe_VkRayTracingShaderGroupCreateInfoKHR(const safe_VkRayTracingShaderGroupCreateInfoKHR& copy_src);
    safe_VkRayTracingShaderGroupCreateInfoKHR& operator=(const safe_VkRayTracingShaderGroupCreateInfoKHR& copy_src);
    safe_VkRayTracingShaderGroupCreateInfoKHR();
    ~safe_VkRayTracingShaderGroupCreateInfoKHR();
    void initialize(const VkRayTracingShaderGroupCreateInfoKHR* in_struct);
    void initialize(const safe_VkRayTracingShaderGroupCreateInfoKHR* copy_src);
    VkRayTracingShaderGroupCreateInfoKHR *ptr() { return reinterpret_cast<VkRayTracingShaderGroupCreateInfoKHR *>(this); }
    VkRayTracingShaderGroupCreateInfoKHR const *ptr() const { return reinterpret_cast<VkRayTracingShaderGroupCreateInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkRayTracingPipelineInterfaceCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    uint32_t maxPayloadSize;
    uint32_t maxAttributeSize;
    uint32_t maxCallableSize;
    safe_VkRayTracingPipelineInterfaceCreateInfoKHR(const VkRayTracingPipelineInterfaceCreateInfoKHR* in_struct);
    safe_VkRayTracingPipelineInterfaceCreateInfoKHR(const safe_VkRayTracingPipelineInterfaceCreateInfoKHR& copy_src);
    safe_VkRayTracingPipelineInterfaceCreateInfoKHR& operator=(const safe_VkRayTracingPipelineInterfaceCreateInfoKHR& copy_src);
    safe_VkRayTracingPipelineInterfaceCreateInfoKHR();
    ~safe_VkRayTracingPipelineInterfaceCreateInfoKHR();
    void initialize(const VkRayTracingPipelineInterfaceCreateInfoKHR* in_struct);
    void initialize(const safe_VkRayTracingPipelineInterfaceCreateInfoKHR* copy_src);
    VkRayTracingPipelineInterfaceCreateInfoKHR *ptr() { return reinterpret_cast<VkRayTracingPipelineInterfaceCreateInfoKHR *>(this); }
    VkRayTracingPipelineInterfaceCreateInfoKHR const *ptr() const { return reinterpret_cast<VkRayTracingPipelineInterfaceCreateInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkRayTracingPipelineCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkPipelineCreateFlags flags;
    uint32_t stageCount;
    safe_VkPipelineShaderStageCreateInfo* pStages;
    uint32_t groupCount;
    safe_VkRayTracingShaderGroupCreateInfoKHR* pGroups;
    uint32_t maxRecursionDepth;
    safe_VkPipelineLibraryCreateInfoKHR libraries;
    safe_VkRayTracingPipelineInterfaceCreateInfoKHR* pLibraryInterface;
    VkPipelineLayout layout;
    VkPipeline basePipelineHandle;
    int32_t basePipelineIndex;
    safe_VkRayTracingPipelineCreateInfoKHR(const VkRayTracingPipelineCreateInfoKHR* in_struct);
    safe_VkRayTracingPipelineCreateInfoKHR(const safe_VkRayTracingPipelineCreateInfoKHR& copy_src);
    safe_VkRayTracingPipelineCreateInfoKHR& operator=(const safe_VkRayTracingPipelineCreateInfoKHR& copy_src);
    safe_VkRayTracingPipelineCreateInfoKHR();
    ~safe_VkRayTracingPipelineCreateInfoKHR();
    void initialize(const VkRayTracingPipelineCreateInfoKHR* in_struct);
    void initialize(const safe_VkRayTracingPipelineCreateInfoKHR* copy_src);
    VkRayTracingPipelineCreateInfoKHR *ptr() { return reinterpret_cast<VkRayTracingPipelineCreateInfoKHR *>(this); }
    VkRayTracingPipelineCreateInfoKHR const *ptr() const { return reinterpret_cast<VkRayTracingPipelineCreateInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureGeometryTrianglesDataKHR {
    VkStructureType sType;
    const void* pNext;
    VkFormat vertexFormat;
    safe_VkDeviceOrHostAddressConstKHR vertexData;
    VkDeviceSize vertexStride;
    VkIndexType indexType;
    safe_VkDeviceOrHostAddressConstKHR indexData;
    safe_VkDeviceOrHostAddressConstKHR transformData;
    safe_VkAccelerationStructureGeometryTrianglesDataKHR(const VkAccelerationStructureGeometryTrianglesDataKHR* in_struct);
    safe_VkAccelerationStructureGeometryTrianglesDataKHR(const safe_VkAccelerationStructureGeometryTrianglesDataKHR& copy_src);
    safe_VkAccelerationStructureGeometryTrianglesDataKHR& operator=(const safe_VkAccelerationStructureGeometryTrianglesDataKHR& copy_src);
    safe_VkAccelerationStructureGeometryTrianglesDataKHR();
    ~safe_VkAccelerationStructureGeometryTrianglesDataKHR();
    void initialize(const VkAccelerationStructureGeometryTrianglesDataKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureGeometryTrianglesDataKHR* copy_src);
    VkAccelerationStructureGeometryTrianglesDataKHR *ptr() { return reinterpret_cast<VkAccelerationStructureGeometryTrianglesDataKHR *>(this); }
    VkAccelerationStructureGeometryTrianglesDataKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureGeometryTrianglesDataKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureGeometryAabbsDataKHR {
    VkStructureType sType;
    const void* pNext;
    safe_VkDeviceOrHostAddressConstKHR data;
    VkDeviceSize stride;
    safe_VkAccelerationStructureGeometryAabbsDataKHR(const VkAccelerationStructureGeometryAabbsDataKHR* in_struct);
    safe_VkAccelerationStructureGeometryAabbsDataKHR(const safe_VkAccelerationStructureGeometryAabbsDataKHR& copy_src);
    safe_VkAccelerationStructureGeometryAabbsDataKHR& operator=(const safe_VkAccelerationStructureGeometryAabbsDataKHR& copy_src);
    safe_VkAccelerationStructureGeometryAabbsDataKHR();
    ~safe_VkAccelerationStructureGeometryAabbsDataKHR();
    void initialize(const VkAccelerationStructureGeometryAabbsDataKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureGeometryAabbsDataKHR* copy_src);
    VkAccelerationStructureGeometryAabbsDataKHR *ptr() { return reinterpret_cast<VkAccelerationStructureGeometryAabbsDataKHR *>(this); }
    VkAccelerationStructureGeometryAabbsDataKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureGeometryAabbsDataKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureGeometryInstancesDataKHR {
    VkStructureType sType;
    const void* pNext;
    VkBool32 arrayOfPointers;
    safe_VkDeviceOrHostAddressConstKHR data;
    safe_VkAccelerationStructureGeometryInstancesDataKHR(const VkAccelerationStructureGeometryInstancesDataKHR* in_struct);
    safe_VkAccelerationStructureGeometryInstancesDataKHR(const safe_VkAccelerationStructureGeometryInstancesDataKHR& copy_src);
    safe_VkAccelerationStructureGeometryInstancesDataKHR& operator=(const safe_VkAccelerationStructureGeometryInstancesDataKHR& copy_src);
    safe_VkAccelerationStructureGeometryInstancesDataKHR();
    ~safe_VkAccelerationStructureGeometryInstancesDataKHR();
    void initialize(const VkAccelerationStructureGeometryInstancesDataKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureGeometryInstancesDataKHR* copy_src);
    VkAccelerationStructureGeometryInstancesDataKHR *ptr() { return reinterpret_cast<VkAccelerationStructureGeometryInstancesDataKHR *>(this); }
    VkAccelerationStructureGeometryInstancesDataKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureGeometryInstancesDataKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureGeometryKHR {
    VkStructureType sType;
    const void* pNext;
    VkGeometryTypeKHR geometryType;
    VkAccelerationStructureGeometryDataKHR geometry;
    VkGeometryFlagsKHR flags;
    safe_VkAccelerationStructureGeometryKHR(const VkAccelerationStructureGeometryKHR* in_struct);
    safe_VkAccelerationStructureGeometryKHR(const safe_VkAccelerationStructureGeometryKHR& copy_src);
    safe_VkAccelerationStructureGeometryKHR& operator=(const safe_VkAccelerationStructureGeometryKHR& copy_src);
    safe_VkAccelerationStructureGeometryKHR();
    ~safe_VkAccelerationStructureGeometryKHR();
    void initialize(const VkAccelerationStructureGeometryKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureGeometryKHR* copy_src);
    VkAccelerationStructureGeometryKHR *ptr() { return reinterpret_cast<VkAccelerationStructureGeometryKHR *>(this); }
    VkAccelerationStructureGeometryKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureGeometryKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureBuildGeometryInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureTypeKHR type;
    VkBuildAccelerationStructureFlagsKHR flags;
    VkBool32 update;
    VkAccelerationStructureKHR srcAccelerationStructure;
    VkAccelerationStructureKHR dstAccelerationStructure;
    VkBool32 geometryArrayOfPointers;
    uint32_t geometryCount;
    safe_VkAccelerationStructureGeometryKHR** ppGeometries;
    safe_VkDeviceOrHostAddressKHR scratchData;
    safe_VkAccelerationStructureBuildGeometryInfoKHR(const VkAccelerationStructureBuildGeometryInfoKHR* in_struct);
    safe_VkAccelerationStructureBuildGeometryInfoKHR(const safe_VkAccelerationStructureBuildGeometryInfoKHR& copy_src);
    safe_VkAccelerationStructureBuildGeometryInfoKHR& operator=(const safe_VkAccelerationStructureBuildGeometryInfoKHR& copy_src);
    safe_VkAccelerationStructureBuildGeometryInfoKHR();
    ~safe_VkAccelerationStructureBuildGeometryInfoKHR();
    void initialize(const VkAccelerationStructureBuildGeometryInfoKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureBuildGeometryInfoKHR* copy_src);
    VkAccelerationStructureBuildGeometryInfoKHR *ptr() { return reinterpret_cast<VkAccelerationStructureBuildGeometryInfoKHR *>(this); }
    VkAccelerationStructureBuildGeometryInfoKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureBuildGeometryInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureCreateGeometryTypeInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkGeometryTypeKHR geometryType;
    uint32_t maxPrimitiveCount;
    VkIndexType indexType;
    uint32_t maxVertexCount;
    VkFormat vertexFormat;
    VkBool32 allowsTransforms;
    safe_VkAccelerationStructureCreateGeometryTypeInfoKHR(const VkAccelerationStructureCreateGeometryTypeInfoKHR* in_struct);
    safe_VkAccelerationStructureCreateGeometryTypeInfoKHR(const safe_VkAccelerationStructureCreateGeometryTypeInfoKHR& copy_src);
    safe_VkAccelerationStructureCreateGeometryTypeInfoKHR& operator=(const safe_VkAccelerationStructureCreateGeometryTypeInfoKHR& copy_src);
    safe_VkAccelerationStructureCreateGeometryTypeInfoKHR();
    ~safe_VkAccelerationStructureCreateGeometryTypeInfoKHR();
    void initialize(const VkAccelerationStructureCreateGeometryTypeInfoKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureCreateGeometryTypeInfoKHR* copy_src);
    VkAccelerationStructureCreateGeometryTypeInfoKHR *ptr() { return reinterpret_cast<VkAccelerationStructureCreateGeometryTypeInfoKHR *>(this); }
    VkAccelerationStructureCreateGeometryTypeInfoKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureCreateGeometryTypeInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureCreateInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkDeviceSize compactedSize;
    VkAccelerationStructureTypeKHR type;
    VkBuildAccelerationStructureFlagsKHR flags;
    uint32_t maxGeometryCount;
    safe_VkAccelerationStructureCreateGeometryTypeInfoKHR* pGeometryInfos;
    VkDeviceAddress deviceAddress;
    safe_VkAccelerationStructureCreateInfoKHR(const VkAccelerationStructureCreateInfoKHR* in_struct);
    safe_VkAccelerationStructureCreateInfoKHR(const safe_VkAccelerationStructureCreateInfoKHR& copy_src);
    safe_VkAccelerationStructureCreateInfoKHR& operator=(const safe_VkAccelerationStructureCreateInfoKHR& copy_src);
    safe_VkAccelerationStructureCreateInfoKHR();
    ~safe_VkAccelerationStructureCreateInfoKHR();
    void initialize(const VkAccelerationStructureCreateInfoKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureCreateInfoKHR* copy_src);
    VkAccelerationStructureCreateInfoKHR *ptr() { return reinterpret_cast<VkAccelerationStructureCreateInfoKHR *>(this); }
    VkAccelerationStructureCreateInfoKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureCreateInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureMemoryRequirementsInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureMemoryRequirementsTypeKHR type;
    VkAccelerationStructureBuildTypeKHR buildType;
    VkAccelerationStructureKHR accelerationStructure;
    safe_VkAccelerationStructureMemoryRequirementsInfoKHR(const VkAccelerationStructureMemoryRequirementsInfoKHR* in_struct);
    safe_VkAccelerationStructureMemoryRequirementsInfoKHR(const safe_VkAccelerationStructureMemoryRequirementsInfoKHR& copy_src);
    safe_VkAccelerationStructureMemoryRequirementsInfoKHR& operator=(const safe_VkAccelerationStructureMemoryRequirementsInfoKHR& copy_src);
    safe_VkAccelerationStructureMemoryRequirementsInfoKHR();
    ~safe_VkAccelerationStructureMemoryRequirementsInfoKHR();
    void initialize(const VkAccelerationStructureMemoryRequirementsInfoKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureMemoryRequirementsInfoKHR* copy_src);
    VkAccelerationStructureMemoryRequirementsInfoKHR *ptr() { return reinterpret_cast<VkAccelerationStructureMemoryRequirementsInfoKHR *>(this); }
    VkAccelerationStructureMemoryRequirementsInfoKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureMemoryRequirementsInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkPhysicalDeviceRayTracingFeaturesKHR {
    VkStructureType sType;
    void* pNext;
    VkBool32 rayTracing;
    VkBool32 rayTracingShaderGroupHandleCaptureReplay;
    VkBool32 rayTracingShaderGroupHandleCaptureReplayMixed;
    VkBool32 rayTracingAccelerationStructureCaptureReplay;
    VkBool32 rayTracingIndirectTraceRays;
    VkBool32 rayTracingIndirectAccelerationStructureBuild;
    VkBool32 rayTracingHostAccelerationStructureCommands;
    VkBool32 rayQuery;
    VkBool32 rayTracingPrimitiveCulling;
    safe_VkPhysicalDeviceRayTracingFeaturesKHR(const VkPhysicalDeviceRayTracingFeaturesKHR* in_struct);
    safe_VkPhysicalDeviceRayTracingFeaturesKHR(const safe_VkPhysicalDeviceRayTracingFeaturesKHR& copy_src);
    safe_VkPhysicalDeviceRayTracingFeaturesKHR& operator=(const safe_VkPhysicalDeviceRayTracingFeaturesKHR& copy_src);
    safe_VkPhysicalDeviceRayTracingFeaturesKHR();
    ~safe_VkPhysicalDeviceRayTracingFeaturesKHR();
    void initialize(const VkPhysicalDeviceRayTracingFeaturesKHR* in_struct);
    void initialize(const safe_VkPhysicalDeviceRayTracingFeaturesKHR* copy_src);
    VkPhysicalDeviceRayTracingFeaturesKHR *ptr() { return reinterpret_cast<VkPhysicalDeviceRayTracingFeaturesKHR *>(this); }
    VkPhysicalDeviceRayTracingFeaturesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDeviceRayTracingFeaturesKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkPhysicalDeviceRayTracingPropertiesKHR {
    VkStructureType sType;
    void* pNext;
    uint32_t shaderGroupHandleSize;
    uint32_t maxRecursionDepth;
    uint32_t maxShaderGroupStride;
    uint32_t shaderGroupBaseAlignment;
    uint64_t maxGeometryCount;
    uint64_t maxInstanceCount;
    uint64_t maxPrimitiveCount;
    uint32_t maxDescriptorSetAccelerationStructures;
    uint32_t shaderGroupHandleCaptureReplaySize;
    safe_VkPhysicalDeviceRayTracingPropertiesKHR(const VkPhysicalDeviceRayTracingPropertiesKHR* in_struct);
    safe_VkPhysicalDeviceRayTracingPropertiesKHR(const safe_VkPhysicalDeviceRayTracingPropertiesKHR& copy_src);
    safe_VkPhysicalDeviceRayTracingPropertiesKHR& operator=(const safe_VkPhysicalDeviceRayTracingPropertiesKHR& copy_src);
    safe_VkPhysicalDeviceRayTracingPropertiesKHR();
    ~safe_VkPhysicalDeviceRayTracingPropertiesKHR();
    void initialize(const VkPhysicalDeviceRayTracingPropertiesKHR* in_struct);
    void initialize(const safe_VkPhysicalDeviceRayTracingPropertiesKHR* copy_src);
    VkPhysicalDeviceRayTracingPropertiesKHR *ptr() { return reinterpret_cast<VkPhysicalDeviceRayTracingPropertiesKHR *>(this); }
    VkPhysicalDeviceRayTracingPropertiesKHR const *ptr() const { return reinterpret_cast<VkPhysicalDeviceRayTracingPropertiesKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureDeviceAddressInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureKHR accelerationStructure;
    safe_VkAccelerationStructureDeviceAddressInfoKHR(const VkAccelerationStructureDeviceAddressInfoKHR* in_struct);
    safe_VkAccelerationStructureDeviceAddressInfoKHR(const safe_VkAccelerationStructureDeviceAddressInfoKHR& copy_src);
    safe_VkAccelerationStructureDeviceAddressInfoKHR& operator=(const safe_VkAccelerationStructureDeviceAddressInfoKHR& copy_src);
    safe_VkAccelerationStructureDeviceAddressInfoKHR();
    ~safe_VkAccelerationStructureDeviceAddressInfoKHR();
    void initialize(const VkAccelerationStructureDeviceAddressInfoKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureDeviceAddressInfoKHR* copy_src);
    VkAccelerationStructureDeviceAddressInfoKHR *ptr() { return reinterpret_cast<VkAccelerationStructureDeviceAddressInfoKHR *>(this); }
    VkAccelerationStructureDeviceAddressInfoKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureDeviceAddressInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkAccelerationStructureVersionKHR {
    VkStructureType sType;
    const void* pNext;
    const uint8_t* versionData;
    safe_VkAccelerationStructureVersionKHR(const VkAccelerationStructureVersionKHR* in_struct);
    safe_VkAccelerationStructureVersionKHR(const safe_VkAccelerationStructureVersionKHR& copy_src);
    safe_VkAccelerationStructureVersionKHR& operator=(const safe_VkAccelerationStructureVersionKHR& copy_src);
    safe_VkAccelerationStructureVersionKHR();
    ~safe_VkAccelerationStructureVersionKHR();
    void initialize(const VkAccelerationStructureVersionKHR* in_struct);
    void initialize(const safe_VkAccelerationStructureVersionKHR* copy_src);
    VkAccelerationStructureVersionKHR *ptr() { return reinterpret_cast<VkAccelerationStructureVersionKHR *>(this); }
    VkAccelerationStructureVersionKHR const *ptr() const { return reinterpret_cast<VkAccelerationStructureVersionKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkCopyAccelerationStructureToMemoryInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureKHR src;
    safe_VkDeviceOrHostAddressKHR dst;
    VkCopyAccelerationStructureModeKHR mode;
    safe_VkCopyAccelerationStructureToMemoryInfoKHR(const VkCopyAccelerationStructureToMemoryInfoKHR* in_struct);
    safe_VkCopyAccelerationStructureToMemoryInfoKHR(const safe_VkCopyAccelerationStructureToMemoryInfoKHR& copy_src);
    safe_VkCopyAccelerationStructureToMemoryInfoKHR& operator=(const safe_VkCopyAccelerationStructureToMemoryInfoKHR& copy_src);
    safe_VkCopyAccelerationStructureToMemoryInfoKHR();
    ~safe_VkCopyAccelerationStructureToMemoryInfoKHR();
    void initialize(const VkCopyAccelerationStructureToMemoryInfoKHR* in_struct);
    void initialize(const safe_VkCopyAccelerationStructureToMemoryInfoKHR* copy_src);
    VkCopyAccelerationStructureToMemoryInfoKHR *ptr() { return reinterpret_cast<VkCopyAccelerationStructureToMemoryInfoKHR *>(this); }
    VkCopyAccelerationStructureToMemoryInfoKHR const *ptr() const { return reinterpret_cast<VkCopyAccelerationStructureToMemoryInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkCopyMemoryToAccelerationStructureInfoKHR {
    VkStructureType sType;
    const void* pNext;
    safe_VkDeviceOrHostAddressConstKHR src;
    VkAccelerationStructureKHR dst;
    VkCopyAccelerationStructureModeKHR mode;
    safe_VkCopyMemoryToAccelerationStructureInfoKHR(const VkCopyMemoryToAccelerationStructureInfoKHR* in_struct);
    safe_VkCopyMemoryToAccelerationStructureInfoKHR(const safe_VkCopyMemoryToAccelerationStructureInfoKHR& copy_src);
    safe_VkCopyMemoryToAccelerationStructureInfoKHR& operator=(const safe_VkCopyMemoryToAccelerationStructureInfoKHR& copy_src);
    safe_VkCopyMemoryToAccelerationStructureInfoKHR();
    ~safe_VkCopyMemoryToAccelerationStructureInfoKHR();
    void initialize(const VkCopyMemoryToAccelerationStructureInfoKHR* in_struct);
    void initialize(const safe_VkCopyMemoryToAccelerationStructureInfoKHR* copy_src);
    VkCopyMemoryToAccelerationStructureInfoKHR *ptr() { return reinterpret_cast<VkCopyMemoryToAccelerationStructureInfoKHR *>(this); }
    VkCopyMemoryToAccelerationStructureInfoKHR const *ptr() const { return reinterpret_cast<VkCopyMemoryToAccelerationStructureInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct safe_VkCopyAccelerationStructureInfoKHR {
    VkStructureType sType;
    const void* pNext;
    VkAccelerationStructureKHR src;
    VkAccelerationStructureKHR dst;
    VkCopyAccelerationStructureModeKHR mode;
    safe_VkCopyAccelerationStructureInfoKHR(const VkCopyAccelerationStructureInfoKHR* in_struct);
    safe_VkCopyAccelerationStructureInfoKHR(const safe_VkCopyAccelerationStructureInfoKHR& copy_src);
    safe_VkCopyAccelerationStructureInfoKHR& operator=(const safe_VkCopyAccelerationStructureInfoKHR& copy_src);
    safe_VkCopyAccelerationStructureInfoKHR();
    ~safe_VkCopyAccelerationStructureInfoKHR();
    void initialize(const VkCopyAccelerationStructureInfoKHR* in_struct);
    void initialize(const safe_VkCopyAccelerationStructureInfoKHR* copy_src);
    VkCopyAccelerationStructureInfoKHR *ptr() { return reinterpret_cast<VkCopyAccelerationStructureInfoKHR *>(this); }
    VkCopyAccelerationStructureInfoKHR const *ptr() const { return reinterpret_cast<VkCopyAccelerationStructureInfoKHR const *>(this); }
};
#endif // VK_ENABLE_BETA_EXTENSIONS
