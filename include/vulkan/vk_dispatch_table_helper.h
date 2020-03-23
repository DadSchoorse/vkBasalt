#pragma once
// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See dispatch_helper_generator.py for modifications

/*
 * Copyright (c) 2015-2020 The Khronos Group Inc.
 * Copyright (c) 2015-2020 Valve Corporation
 * Copyright (c) 2015-2020 LunarG, Inc.
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
 * Author: Courtney Goeltzenleuchter <courtney@LunarG.com>
 * Author: Jon Ashburn <jon@lunarg.com>
 * Author: Mark Lobodzinski <mark@lunarg.com>
 */

#include <vulkan/vulkan.h>
#include <vulkan/vk_layer.h>
#include <cstring>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "vk_layer_dispatch_table.h"
#include "vk_extension_helper.h"

static VKAPI_ATTR VkResult VKAPI_CALL StubBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR void VKAPI_CALL StubUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL StubGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR uint64_t VKAPI_CALL StubGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR uint64_t VKAPI_CALL StubGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR void VKAPI_CALL StubDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) { return VK_SUCCESS; };
#ifdef VK_USE_PLATFORM_XLIB_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
static VKAPI_ATTR VkBool32 VKAPI_CALL StubGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) { return VK_FALSE; };
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
static VKAPI_ATTR VkBool32 VKAPI_CALL StubGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) { return VK_FALSE; };
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
static VKAPI_ATTR VkBool32 VKAPI_CALL StubGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) { return VK_FALSE; };
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkBool32 VKAPI_CALL StubGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) { return VK_FALSE; };
#endif // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {  };
static VKAPI_ATTR void VKAPI_CALL StubTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {  };
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {  };
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR void VKAPI_CALL StubUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {  };
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubReleaseProfilingLockKHR(VkDevice device) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL StubGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR uint64_t VKAPI_CALL StubGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR uint64_t VKAPI_CALL StubGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPipelineExecutablePropertiesKHR(VkDevice                        device, const VkPipelineInfoKHR*        pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPipelineExecutableStatisticsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPipelineExecutableInternalRepresentationsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR void VKAPI_CALL StubDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {  };
static VKAPI_ATTR uint32_t VKAPI_CALL StubGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) { return 0; };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) { return VK_SUCCESS; };
#ifdef VK_USE_PLATFORM_GGP
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_GGP
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) { return VK_SUCCESS; };
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_VI_NN
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_VI_NN
static VKAPI_ATTR void VKAPI_CALL StubCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdProcessCommandsNVX(VkCommandBuffer commandBuffer, const VkCmdProcessCommandsInfoNVX* pProcessCommandsInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdReserveSpaceForCommandsNVX(VkCommandBuffer commandBuffer, const VkCmdReserveSpaceForCommandsInfoNVX* pReserveSpaceInfo) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateIndirectCommandsLayoutNVX(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNVX* pIndirectCommandsLayout) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyIndirectCommandsLayoutNVX(VkDevice device, VkIndirectCommandsLayoutNVX indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateObjectTableNVX(VkDevice device, const VkObjectTableCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkObjectTableNVX* pObjectTable) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyObjectTableNVX(VkDevice device, VkObjectTableNVX objectTable, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubRegisterObjectsNVX(VkDevice device, VkObjectTableNVX objectTable, uint32_t objectCount, const VkObjectTableEntryNVX* const*    ppObjectTableEntries, const uint32_t* pObjectIndices) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubUnregisterObjectsNVX(VkDevice device, VkObjectTableNVX objectTable, uint32_t objectCount, const VkObjectEntryTypeNVX* pObjectEntryTypes, const uint32_t* pObjectIndices) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceGeneratedCommandsPropertiesNVX(VkPhysicalDevice physicalDevice, VkDeviceGeneratedCommandsFeaturesNVX* pFeatures, VkDeviceGeneratedCommandsLimitsNVX* pLimits) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) { return VK_SUCCESS; };
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
static VKAPI_ATTR VkResult VKAPI_CALL StubAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
static VKAPI_ATTR VkResult VKAPI_CALL StubGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {  };
static VKAPI_ATTR void VKAPI_CALL StubSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) {  };
#ifdef VK_USE_PLATFORM_IOS_MVK
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_MACOS_MVK
static VKAPI_ATTR VkResult VKAPI_CALL StubSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubQueueEndDebugUtilsLabelEXT(VkQueue queue) {  };
static VKAPI_ATTR void VKAPI_CALL StubQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR void VKAPI_CALL StubSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {  };
#ifdef VK_USE_PLATFORM_ANDROID_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_ANDROID_KHR
static VKAPI_ATTR void VKAPI_CALL StubCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeNV mode) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {  };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {  };
static VKAPI_ATTR void VKAPI_CALL StubGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubUninitializePerformanceApiINTEL(VkDevice device) {  };
static VKAPI_ATTR VkResult VKAPI_CALL StubCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) {  };
#ifdef VK_USE_PLATFORM_FUCHSIA
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_METAL_EXT
static VKAPI_ATTR VkDeviceAddress VKAPI_CALL StubGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { return 0; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) { return VK_SUCCESS; };
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) { return VK_SUCCESS; };
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) { return VK_SUCCESS; };
#endif // VK_USE_PLATFORM_WIN32_KHR
static VKAPI_ATTR VkResult VKAPI_CALL StubCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { return VK_SUCCESS; };
static VKAPI_ATTR void VKAPI_CALL StubCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {  };
static VKAPI_ATTR void VKAPI_CALL StubResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {  };



const std::unordered_map<std::string, std::string> api_extension_map {
    {"vkBindBufferMemory2", "VK_VERSION_1_1"},
    {"vkBindImageMemory2", "VK_VERSION_1_1"},
    {"vkGetDeviceGroupPeerMemoryFeatures", "VK_VERSION_1_1"},
    {"vkCmdSetDeviceMask", "VK_VERSION_1_1"},
    {"vkCmdDispatchBase", "VK_VERSION_1_1"},
    {"vkGetImageMemoryRequirements2", "VK_VERSION_1_1"},
    {"vkGetBufferMemoryRequirements2", "VK_VERSION_1_1"},
    {"vkGetImageSparseMemoryRequirements2", "VK_VERSION_1_1"},
    {"vkTrimCommandPool", "VK_VERSION_1_1"},
    {"vkGetDeviceQueue2", "VK_VERSION_1_1"},
    {"vkCreateSamplerYcbcrConversion", "VK_VERSION_1_1"},
    {"vkDestroySamplerYcbcrConversion", "VK_VERSION_1_1"},
    {"vkCreateDescriptorUpdateTemplate", "VK_VERSION_1_1"},
    {"vkDestroyDescriptorUpdateTemplate", "VK_VERSION_1_1"},
    {"vkUpdateDescriptorSetWithTemplate", "VK_VERSION_1_1"},
    {"vkGetDescriptorSetLayoutSupport", "VK_VERSION_1_1"},
    {"vkCmdDrawIndirectCount", "VK_VERSION_1_2"},
    {"vkCmdDrawIndexedIndirectCount", "VK_VERSION_1_2"},
    {"vkCreateRenderPass2", "VK_VERSION_1_2"},
    {"vkCmdBeginRenderPass2", "VK_VERSION_1_2"},
    {"vkCmdNextSubpass2", "VK_VERSION_1_2"},
    {"vkCmdEndRenderPass2", "VK_VERSION_1_2"},
    {"vkResetQueryPool", "VK_VERSION_1_2"},
    {"vkGetSemaphoreCounterValue", "VK_VERSION_1_2"},
    {"vkWaitSemaphores", "VK_VERSION_1_2"},
    {"vkSignalSemaphore", "VK_VERSION_1_2"},
    {"vkGetBufferDeviceAddress", "VK_VERSION_1_2"},
    {"vkGetBufferOpaqueCaptureAddress", "VK_VERSION_1_2"},
    {"vkGetDeviceMemoryOpaqueCaptureAddress", "VK_VERSION_1_2"},
    {"vkCreateSwapchainKHR", "VK_KHR_swapchain"},
    {"vkDestroySwapchainKHR", "VK_KHR_swapchain"},
    {"vkGetSwapchainImagesKHR", "VK_KHR_swapchain"},
    {"vkAcquireNextImageKHR", "VK_KHR_swapchain"},
    {"vkQueuePresentKHR", "VK_KHR_swapchain"},
    {"vkGetDeviceGroupPresentCapabilitiesKHR", "VK_KHR_swapchain"},
    {"vkGetDeviceGroupSurfacePresentModesKHR", "VK_KHR_swapchain"},
    {"vkAcquireNextImage2KHR", "VK_KHR_swapchain"},
    {"vkCreateSharedSwapchainsKHR", "VK_KHR_display_swapchain"},
    {"vkGetDeviceGroupPeerMemoryFeaturesKHR", "VK_KHR_device_group"},
    {"vkCmdSetDeviceMaskKHR", "VK_KHR_device_group"},
    {"vkCmdDispatchBaseKHR", "VK_KHR_device_group"},
    {"vkTrimCommandPoolKHR", "VK_KHR_maintenance1"},
    {"vkGetMemoryWin32HandleKHR", "VK_KHR_external_memory_win32"},
    {"vkGetMemoryWin32HandlePropertiesKHR", "VK_KHR_external_memory_win32"},
    {"vkGetMemoryFdKHR", "VK_KHR_external_memory_fd"},
    {"vkGetMemoryFdPropertiesKHR", "VK_KHR_external_memory_fd"},
    {"vkImportSemaphoreWin32HandleKHR", "VK_KHR_external_semaphore_win32"},
    {"vkGetSemaphoreWin32HandleKHR", "VK_KHR_external_semaphore_win32"},
    {"vkImportSemaphoreFdKHR", "VK_KHR_external_semaphore_fd"},
    {"vkGetSemaphoreFdKHR", "VK_KHR_external_semaphore_fd"},
    {"vkCmdPushDescriptorSetKHR", "VK_KHR_push_descriptor"},
    {"vkCmdPushDescriptorSetWithTemplateKHR", "VK_KHR_push_descriptor"},
    {"vkCreateDescriptorUpdateTemplateKHR", "VK_KHR_descriptor_update_template"},
    {"vkDestroyDescriptorUpdateTemplateKHR", "VK_KHR_descriptor_update_template"},
    {"vkUpdateDescriptorSetWithTemplateKHR", "VK_KHR_descriptor_update_template"},
    {"vkCreateRenderPass2KHR", "VK_KHR_create_renderpass2"},
    {"vkCmdBeginRenderPass2KHR", "VK_KHR_create_renderpass2"},
    {"vkCmdNextSubpass2KHR", "VK_KHR_create_renderpass2"},
    {"vkCmdEndRenderPass2KHR", "VK_KHR_create_renderpass2"},
    {"vkGetSwapchainStatusKHR", "VK_KHR_shared_presentable_image"},
    {"vkImportFenceWin32HandleKHR", "VK_KHR_external_fence_win32"},
    {"vkGetFenceWin32HandleKHR", "VK_KHR_external_fence_win32"},
    {"vkImportFenceFdKHR", "VK_KHR_external_fence_fd"},
    {"vkGetFenceFdKHR", "VK_KHR_external_fence_fd"},
    {"vkAcquireProfilingLockKHR", "VK_KHR_performance_query"},
    {"vkReleaseProfilingLockKHR", "VK_KHR_performance_query"},
    {"vkGetImageMemoryRequirements2KHR", "VK_KHR_get_memory_requirements2"},
    {"vkGetBufferMemoryRequirements2KHR", "VK_KHR_get_memory_requirements2"},
    {"vkGetImageSparseMemoryRequirements2KHR", "VK_KHR_get_memory_requirements2"},
    {"vkCreateSamplerYcbcrConversionKHR", "VK_KHR_sampler_ycbcr_conversion"},
    {"vkDestroySamplerYcbcrConversionKHR", "VK_KHR_sampler_ycbcr_conversion"},
    {"vkBindBufferMemory2KHR", "VK_KHR_bind_memory2"},
    {"vkBindImageMemory2KHR", "VK_KHR_bind_memory2"},
    {"vkGetDescriptorSetLayoutSupportKHR", "VK_KHR_maintenance3"},
    {"vkCmdDrawIndirectCountKHR", "VK_KHR_draw_indirect_count"},
    {"vkCmdDrawIndexedIndirectCountKHR", "VK_KHR_draw_indirect_count"},
    {"vkGetSemaphoreCounterValueKHR", "VK_KHR_timeline_semaphore"},
    {"vkWaitSemaphoresKHR", "VK_KHR_timeline_semaphore"},
    {"vkSignalSemaphoreKHR", "VK_KHR_timeline_semaphore"},
    {"vkGetBufferDeviceAddressKHR", "VK_KHR_buffer_device_address"},
    {"vkGetBufferOpaqueCaptureAddressKHR", "VK_KHR_buffer_device_address"},
    {"vkGetDeviceMemoryOpaqueCaptureAddressKHR", "VK_KHR_buffer_device_address"},
    {"vkGetPipelineExecutablePropertiesKHR", "VK_KHR_pipeline_executable_properties"},
    {"vkGetPipelineExecutableStatisticsKHR", "VK_KHR_pipeline_executable_properties"},
    {"vkGetPipelineExecutableInternalRepresentationsKHR", "VK_KHR_pipeline_executable_properties"},
    {"vkDebugMarkerSetObjectTagEXT", "VK_EXT_debug_marker"},
    {"vkDebugMarkerSetObjectNameEXT", "VK_EXT_debug_marker"},
    {"vkCmdDebugMarkerBeginEXT", "VK_EXT_debug_marker"},
    {"vkCmdDebugMarkerEndEXT", "VK_EXT_debug_marker"},
    {"vkCmdDebugMarkerInsertEXT", "VK_EXT_debug_marker"},
    {"vkCmdBindTransformFeedbackBuffersEXT", "VK_EXT_transform_feedback"},
    {"vkCmdBeginTransformFeedbackEXT", "VK_EXT_transform_feedback"},
    {"vkCmdEndTransformFeedbackEXT", "VK_EXT_transform_feedback"},
    {"vkCmdBeginQueryIndexedEXT", "VK_EXT_transform_feedback"},
    {"vkCmdEndQueryIndexedEXT", "VK_EXT_transform_feedback"},
    {"vkCmdDrawIndirectByteCountEXT", "VK_EXT_transform_feedback"},
    {"vkGetImageViewHandleNVX", "VK_NVX_image_view_handle"},
    {"vkCmdDrawIndirectCountAMD", "VK_AMD_draw_indirect_count"},
    {"vkCmdDrawIndexedIndirectCountAMD", "VK_AMD_draw_indirect_count"},
    {"vkGetShaderInfoAMD", "VK_AMD_shader_info"},
    {"vkGetMemoryWin32HandleNV", "VK_NV_external_memory_win32"},
    {"vkCmdBeginConditionalRenderingEXT", "VK_EXT_conditional_rendering"},
    {"vkCmdEndConditionalRenderingEXT", "VK_EXT_conditional_rendering"},
    {"vkCmdProcessCommandsNVX", "VK_NVX_device_generated_commands"},
    {"vkCmdReserveSpaceForCommandsNVX", "VK_NVX_device_generated_commands"},
    {"vkCreateIndirectCommandsLayoutNVX", "VK_NVX_device_generated_commands"},
    {"vkDestroyIndirectCommandsLayoutNVX", "VK_NVX_device_generated_commands"},
    {"vkCreateObjectTableNVX", "VK_NVX_device_generated_commands"},
    {"vkDestroyObjectTableNVX", "VK_NVX_device_generated_commands"},
    {"vkRegisterObjectsNVX", "VK_NVX_device_generated_commands"},
    {"vkUnregisterObjectsNVX", "VK_NVX_device_generated_commands"},
    {"vkCmdSetViewportWScalingNV", "VK_NV_clip_space_w_scaling"},
    {"vkDisplayPowerControlEXT", "VK_EXT_display_control"},
    {"vkRegisterDeviceEventEXT", "VK_EXT_display_control"},
    {"vkRegisterDisplayEventEXT", "VK_EXT_display_control"},
    {"vkGetSwapchainCounterEXT", "VK_EXT_display_control"},
    {"vkGetRefreshCycleDurationGOOGLE", "VK_GOOGLE_display_timing"},
    {"vkGetPastPresentationTimingGOOGLE", "VK_GOOGLE_display_timing"},
    {"vkCmdSetDiscardRectangleEXT", "VK_EXT_discard_rectangles"},
    {"vkSetHdrMetadataEXT", "VK_EXT_hdr_metadata"},
    {"vkSetDebugUtilsObjectNameEXT", "VK_EXT_debug_utils"},
    {"vkSetDebugUtilsObjectTagEXT", "VK_EXT_debug_utils"},
    {"vkQueueBeginDebugUtilsLabelEXT", "VK_EXT_debug_utils"},
    {"vkQueueEndDebugUtilsLabelEXT", "VK_EXT_debug_utils"},
    {"vkQueueInsertDebugUtilsLabelEXT", "VK_EXT_debug_utils"},
    {"vkCmdBeginDebugUtilsLabelEXT", "VK_EXT_debug_utils"},
    {"vkCmdEndDebugUtilsLabelEXT", "VK_EXT_debug_utils"},
    {"vkCmdInsertDebugUtilsLabelEXT", "VK_EXT_debug_utils"},
    {"vkGetAndroidHardwareBufferPropertiesANDROID", "VK_ANDROID_external_memory_android_hardware_buffer"},
    {"vkGetMemoryAndroidHardwareBufferANDROID", "VK_ANDROID_external_memory_android_hardware_buffer"},
    {"vkCmdSetSampleLocationsEXT", "VK_EXT_sample_locations"},
    {"vkGetImageDrmFormatModifierPropertiesEXT", "VK_EXT_image_drm_format_modifier"},
    {"vkCreateValidationCacheEXT", "VK_EXT_validation_cache"},
    {"vkDestroyValidationCacheEXT", "VK_EXT_validation_cache"},
    {"vkMergeValidationCachesEXT", "VK_EXT_validation_cache"},
    {"vkGetValidationCacheDataEXT", "VK_EXT_validation_cache"},
    {"vkCmdBindShadingRateImageNV", "VK_NV_shading_rate_image"},
    {"vkCmdSetViewportShadingRatePaletteNV", "VK_NV_shading_rate_image"},
    {"vkCmdSetCoarseSampleOrderNV", "VK_NV_shading_rate_image"},
    {"vkCreateAccelerationStructureNV", "VK_NV_ray_tracing"},
    {"vkDestroyAccelerationStructureNV", "VK_NV_ray_tracing"},
    {"vkGetAccelerationStructureMemoryRequirementsNV", "VK_NV_ray_tracing"},
    {"vkBindAccelerationStructureMemoryNV", "VK_NV_ray_tracing"},
    {"vkCmdBuildAccelerationStructureNV", "VK_NV_ray_tracing"},
    {"vkCmdCopyAccelerationStructureNV", "VK_NV_ray_tracing"},
    {"vkCmdTraceRaysNV", "VK_NV_ray_tracing"},
    {"vkCreateRayTracingPipelinesNV", "VK_NV_ray_tracing"},
    {"vkGetRayTracingShaderGroupHandlesNV", "VK_NV_ray_tracing"},
    {"vkGetAccelerationStructureHandleNV", "VK_NV_ray_tracing"},
    {"vkCmdWriteAccelerationStructuresPropertiesNV", "VK_NV_ray_tracing"},
    {"vkCompileDeferredNV", "VK_NV_ray_tracing"},
    {"vkGetMemoryHostPointerPropertiesEXT", "VK_EXT_external_memory_host"},
    {"vkCmdWriteBufferMarkerAMD", "VK_AMD_buffer_marker"},
    {"vkGetCalibratedTimestampsEXT", "VK_EXT_calibrated_timestamps"},
    {"vkCmdDrawMeshTasksNV", "VK_NV_mesh_shader"},
    {"vkCmdDrawMeshTasksIndirectNV", "VK_NV_mesh_shader"},
    {"vkCmdDrawMeshTasksIndirectCountNV", "VK_NV_mesh_shader"},
    {"vkCmdSetExclusiveScissorNV", "VK_NV_scissor_exclusive"},
    {"vkCmdSetCheckpointNV", "VK_NV_device_diagnostic_checkpoints"},
    {"vkGetQueueCheckpointDataNV", "VK_NV_device_diagnostic_checkpoints"},
    {"vkInitializePerformanceApiINTEL", "VK_INTEL_performance_query"},
    {"vkUninitializePerformanceApiINTEL", "VK_INTEL_performance_query"},
    {"vkCmdSetPerformanceMarkerINTEL", "VK_INTEL_performance_query"},
    {"vkCmdSetPerformanceStreamMarkerINTEL", "VK_INTEL_performance_query"},
    {"vkCmdSetPerformanceOverrideINTEL", "VK_INTEL_performance_query"},
    {"vkAcquirePerformanceConfigurationINTEL", "VK_INTEL_performance_query"},
    {"vkReleasePerformanceConfigurationINTEL", "VK_INTEL_performance_query"},
    {"vkQueueSetPerformanceConfigurationINTEL", "VK_INTEL_performance_query"},
    {"vkGetPerformanceParameterINTEL", "VK_INTEL_performance_query"},
    {"vkSetLocalDimmingAMD", "VK_AMD_display_native_hdr"},
    {"vkGetBufferDeviceAddressEXT", "VK_EXT_buffer_device_address"},
    {"vkAcquireFullScreenExclusiveModeEXT", "VK_EXT_full_screen_exclusive"},
    {"vkReleaseFullScreenExclusiveModeEXT", "VK_EXT_full_screen_exclusive"},
    {"vkGetDeviceGroupSurfacePresentModes2EXT", "VK_EXT_full_screen_exclusive"},
    {"vkCmdSetLineStippleEXT", "VK_EXT_line_rasterization"},
    {"vkResetQueryPoolEXT", "VK_EXT_host_query_reset"},
};

// Using the above code-generated map of APINames-to-parent extension names, this function will:
//   o  Determine if the API has an associated extension
//   o  If it does, determine if that extension name is present in the passed-in set of enabled_ext_names 
//   If the APIname has no parent extension, OR its parent extension name is IN the set, return TRUE, else FALSE
static inline bool ApiParentExtensionEnabled(const std::string api_name, const DeviceExtensions *device_extension_info) {
    auto has_ext = api_extension_map.find(api_name);
    // Is this API part of an extension or feature group?
    if (has_ext != api_extension_map.end()) {
        // Was the extension for this API enabled in the CreateDevice call?
        auto info = device_extension_info->get_info(has_ext->second.c_str());
        if ((!info.state) || (device_extension_info->*(info.state) != kEnabledByCreateinfo)) {
            return false;
        }
    }
    return true;
}



static inline void layer_init_device_dispatch_table(VkDevice device, VkLayerDispatchTable *table, PFN_vkGetDeviceProcAddr gpa) {
    memset(table, 0, sizeof(*table));
    // Device function pointers
    table->GetDeviceProcAddr = gpa;
    table->DestroyDevice = (PFN_vkDestroyDevice) gpa(device, "vkDestroyDevice");
    table->GetDeviceQueue = (PFN_vkGetDeviceQueue) gpa(device, "vkGetDeviceQueue");
    table->QueueSubmit = (PFN_vkQueueSubmit) gpa(device, "vkQueueSubmit");
    table->QueueWaitIdle = (PFN_vkQueueWaitIdle) gpa(device, "vkQueueWaitIdle");
    table->DeviceWaitIdle = (PFN_vkDeviceWaitIdle) gpa(device, "vkDeviceWaitIdle");
    table->AllocateMemory = (PFN_vkAllocateMemory) gpa(device, "vkAllocateMemory");
    table->FreeMemory = (PFN_vkFreeMemory) gpa(device, "vkFreeMemory");
    table->MapMemory = (PFN_vkMapMemory) gpa(device, "vkMapMemory");
    table->UnmapMemory = (PFN_vkUnmapMemory) gpa(device, "vkUnmapMemory");
    table->FlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges) gpa(device, "vkFlushMappedMemoryRanges");
    table->InvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges) gpa(device, "vkInvalidateMappedMemoryRanges");
    table->GetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment) gpa(device, "vkGetDeviceMemoryCommitment");
    table->BindBufferMemory = (PFN_vkBindBufferMemory) gpa(device, "vkBindBufferMemory");
    table->BindImageMemory = (PFN_vkBindImageMemory) gpa(device, "vkBindImageMemory");
    table->GetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements) gpa(device, "vkGetBufferMemoryRequirements");
    table->GetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements) gpa(device, "vkGetImageMemoryRequirements");
    table->GetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements) gpa(device, "vkGetImageSparseMemoryRequirements");
    table->QueueBindSparse = (PFN_vkQueueBindSparse) gpa(device, "vkQueueBindSparse");
    table->CreateFence = (PFN_vkCreateFence) gpa(device, "vkCreateFence");
    table->DestroyFence = (PFN_vkDestroyFence) gpa(device, "vkDestroyFence");
    table->ResetFences = (PFN_vkResetFences) gpa(device, "vkResetFences");
    table->GetFenceStatus = (PFN_vkGetFenceStatus) gpa(device, "vkGetFenceStatus");
    table->WaitForFences = (PFN_vkWaitForFences) gpa(device, "vkWaitForFences");
    table->CreateSemaphore = (PFN_vkCreateSemaphore) gpa(device, "vkCreateSemaphore");
    table->DestroySemaphore = (PFN_vkDestroySemaphore) gpa(device, "vkDestroySemaphore");
    table->CreateEvent = (PFN_vkCreateEvent) gpa(device, "vkCreateEvent");
    table->DestroyEvent = (PFN_vkDestroyEvent) gpa(device, "vkDestroyEvent");
    table->GetEventStatus = (PFN_vkGetEventStatus) gpa(device, "vkGetEventStatus");
    table->SetEvent = (PFN_vkSetEvent) gpa(device, "vkSetEvent");
    table->ResetEvent = (PFN_vkResetEvent) gpa(device, "vkResetEvent");
    table->CreateQueryPool = (PFN_vkCreateQueryPool) gpa(device, "vkCreateQueryPool");
    table->DestroyQueryPool = (PFN_vkDestroyQueryPool) gpa(device, "vkDestroyQueryPool");
    table->GetQueryPoolResults = (PFN_vkGetQueryPoolResults) gpa(device, "vkGetQueryPoolResults");
    table->CreateBuffer = (PFN_vkCreateBuffer) gpa(device, "vkCreateBuffer");
    table->DestroyBuffer = (PFN_vkDestroyBuffer) gpa(device, "vkDestroyBuffer");
    table->CreateBufferView = (PFN_vkCreateBufferView) gpa(device, "vkCreateBufferView");
    table->DestroyBufferView = (PFN_vkDestroyBufferView) gpa(device, "vkDestroyBufferView");
    table->CreateImage = (PFN_vkCreateImage) gpa(device, "vkCreateImage");
    table->DestroyImage = (PFN_vkDestroyImage) gpa(device, "vkDestroyImage");
    table->GetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout) gpa(device, "vkGetImageSubresourceLayout");
    table->CreateImageView = (PFN_vkCreateImageView) gpa(device, "vkCreateImageView");
    table->DestroyImageView = (PFN_vkDestroyImageView) gpa(device, "vkDestroyImageView");
    table->CreateShaderModule = (PFN_vkCreateShaderModule) gpa(device, "vkCreateShaderModule");
    table->DestroyShaderModule = (PFN_vkDestroyShaderModule) gpa(device, "vkDestroyShaderModule");
    table->CreatePipelineCache = (PFN_vkCreatePipelineCache) gpa(device, "vkCreatePipelineCache");
    table->DestroyPipelineCache = (PFN_vkDestroyPipelineCache) gpa(device, "vkDestroyPipelineCache");
    table->GetPipelineCacheData = (PFN_vkGetPipelineCacheData) gpa(device, "vkGetPipelineCacheData");
    table->MergePipelineCaches = (PFN_vkMergePipelineCaches) gpa(device, "vkMergePipelineCaches");
    table->CreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines) gpa(device, "vkCreateGraphicsPipelines");
    table->CreateComputePipelines = (PFN_vkCreateComputePipelines) gpa(device, "vkCreateComputePipelines");
    table->DestroyPipeline = (PFN_vkDestroyPipeline) gpa(device, "vkDestroyPipeline");
    table->CreatePipelineLayout = (PFN_vkCreatePipelineLayout) gpa(device, "vkCreatePipelineLayout");
    table->DestroyPipelineLayout = (PFN_vkDestroyPipelineLayout) gpa(device, "vkDestroyPipelineLayout");
    table->CreateSampler = (PFN_vkCreateSampler) gpa(device, "vkCreateSampler");
    table->DestroySampler = (PFN_vkDestroySampler) gpa(device, "vkDestroySampler");
    table->CreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout) gpa(device, "vkCreateDescriptorSetLayout");
    table->DestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout) gpa(device, "vkDestroyDescriptorSetLayout");
    table->CreateDescriptorPool = (PFN_vkCreateDescriptorPool) gpa(device, "vkCreateDescriptorPool");
    table->DestroyDescriptorPool = (PFN_vkDestroyDescriptorPool) gpa(device, "vkDestroyDescriptorPool");
    table->ResetDescriptorPool = (PFN_vkResetDescriptorPool) gpa(device, "vkResetDescriptorPool");
    table->AllocateDescriptorSets = (PFN_vkAllocateDescriptorSets) gpa(device, "vkAllocateDescriptorSets");
    table->FreeDescriptorSets = (PFN_vkFreeDescriptorSets) gpa(device, "vkFreeDescriptorSets");
    table->UpdateDescriptorSets = (PFN_vkUpdateDescriptorSets) gpa(device, "vkUpdateDescriptorSets");
    table->CreateFramebuffer = (PFN_vkCreateFramebuffer) gpa(device, "vkCreateFramebuffer");
    table->DestroyFramebuffer = (PFN_vkDestroyFramebuffer) gpa(device, "vkDestroyFramebuffer");
    table->CreateRenderPass = (PFN_vkCreateRenderPass) gpa(device, "vkCreateRenderPass");
    table->DestroyRenderPass = (PFN_vkDestroyRenderPass) gpa(device, "vkDestroyRenderPass");
    table->GetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity) gpa(device, "vkGetRenderAreaGranularity");
    table->CreateCommandPool = (PFN_vkCreateCommandPool) gpa(device, "vkCreateCommandPool");
    table->DestroyCommandPool = (PFN_vkDestroyCommandPool) gpa(device, "vkDestroyCommandPool");
    table->ResetCommandPool = (PFN_vkResetCommandPool) gpa(device, "vkResetCommandPool");
    table->AllocateCommandBuffers = (PFN_vkAllocateCommandBuffers) gpa(device, "vkAllocateCommandBuffers");
    table->FreeCommandBuffers = (PFN_vkFreeCommandBuffers) gpa(device, "vkFreeCommandBuffers");
    table->BeginCommandBuffer = (PFN_vkBeginCommandBuffer) gpa(device, "vkBeginCommandBuffer");
    table->EndCommandBuffer = (PFN_vkEndCommandBuffer) gpa(device, "vkEndCommandBuffer");
    table->ResetCommandBuffer = (PFN_vkResetCommandBuffer) gpa(device, "vkResetCommandBuffer");
    table->CmdBindPipeline = (PFN_vkCmdBindPipeline) gpa(device, "vkCmdBindPipeline");
    table->CmdSetViewport = (PFN_vkCmdSetViewport) gpa(device, "vkCmdSetViewport");
    table->CmdSetScissor = (PFN_vkCmdSetScissor) gpa(device, "vkCmdSetScissor");
    table->CmdSetLineWidth = (PFN_vkCmdSetLineWidth) gpa(device, "vkCmdSetLineWidth");
    table->CmdSetDepthBias = (PFN_vkCmdSetDepthBias) gpa(device, "vkCmdSetDepthBias");
    table->CmdSetBlendConstants = (PFN_vkCmdSetBlendConstants) gpa(device, "vkCmdSetBlendConstants");
    table->CmdSetDepthBounds = (PFN_vkCmdSetDepthBounds) gpa(device, "vkCmdSetDepthBounds");
    table->CmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask) gpa(device, "vkCmdSetStencilCompareMask");
    table->CmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask) gpa(device, "vkCmdSetStencilWriteMask");
    table->CmdSetStencilReference = (PFN_vkCmdSetStencilReference) gpa(device, "vkCmdSetStencilReference");
    table->CmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets) gpa(device, "vkCmdBindDescriptorSets");
    table->CmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer) gpa(device, "vkCmdBindIndexBuffer");
    table->CmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers) gpa(device, "vkCmdBindVertexBuffers");
    table->CmdDraw = (PFN_vkCmdDraw) gpa(device, "vkCmdDraw");
    table->CmdDrawIndexed = (PFN_vkCmdDrawIndexed) gpa(device, "vkCmdDrawIndexed");
    table->CmdDrawIndirect = (PFN_vkCmdDrawIndirect) gpa(device, "vkCmdDrawIndirect");
    table->CmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect) gpa(device, "vkCmdDrawIndexedIndirect");
    table->CmdDispatch = (PFN_vkCmdDispatch) gpa(device, "vkCmdDispatch");
    table->CmdDispatchIndirect = (PFN_vkCmdDispatchIndirect) gpa(device, "vkCmdDispatchIndirect");
    table->CmdCopyBuffer = (PFN_vkCmdCopyBuffer) gpa(device, "vkCmdCopyBuffer");
    table->CmdCopyImage = (PFN_vkCmdCopyImage) gpa(device, "vkCmdCopyImage");
    table->CmdBlitImage = (PFN_vkCmdBlitImage) gpa(device, "vkCmdBlitImage");
    table->CmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage) gpa(device, "vkCmdCopyBufferToImage");
    table->CmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer) gpa(device, "vkCmdCopyImageToBuffer");
    table->CmdUpdateBuffer = (PFN_vkCmdUpdateBuffer) gpa(device, "vkCmdUpdateBuffer");
    table->CmdFillBuffer = (PFN_vkCmdFillBuffer) gpa(device, "vkCmdFillBuffer");
    table->CmdClearColorImage = (PFN_vkCmdClearColorImage) gpa(device, "vkCmdClearColorImage");
    table->CmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage) gpa(device, "vkCmdClearDepthStencilImage");
    table->CmdClearAttachments = (PFN_vkCmdClearAttachments) gpa(device, "vkCmdClearAttachments");
    table->CmdResolveImage = (PFN_vkCmdResolveImage) gpa(device, "vkCmdResolveImage");
    table->CmdSetEvent = (PFN_vkCmdSetEvent) gpa(device, "vkCmdSetEvent");
    table->CmdResetEvent = (PFN_vkCmdResetEvent) gpa(device, "vkCmdResetEvent");
    table->CmdWaitEvents = (PFN_vkCmdWaitEvents) gpa(device, "vkCmdWaitEvents");
    table->CmdPipelineBarrier = (PFN_vkCmdPipelineBarrier) gpa(device, "vkCmdPipelineBarrier");
    table->CmdBeginQuery = (PFN_vkCmdBeginQuery) gpa(device, "vkCmdBeginQuery");
    table->CmdEndQuery = (PFN_vkCmdEndQuery) gpa(device, "vkCmdEndQuery");
    table->CmdResetQueryPool = (PFN_vkCmdResetQueryPool) gpa(device, "vkCmdResetQueryPool");
    table->CmdWriteTimestamp = (PFN_vkCmdWriteTimestamp) gpa(device, "vkCmdWriteTimestamp");
    table->CmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults) gpa(device, "vkCmdCopyQueryPoolResults");
    table->CmdPushConstants = (PFN_vkCmdPushConstants) gpa(device, "vkCmdPushConstants");
    table->CmdBeginRenderPass = (PFN_vkCmdBeginRenderPass) gpa(device, "vkCmdBeginRenderPass");
    table->CmdNextSubpass = (PFN_vkCmdNextSubpass) gpa(device, "vkCmdNextSubpass");
    table->CmdEndRenderPass = (PFN_vkCmdEndRenderPass) gpa(device, "vkCmdEndRenderPass");
    table->CmdExecuteCommands = (PFN_vkCmdExecuteCommands) gpa(device, "vkCmdExecuteCommands");
    table->BindBufferMemory2 = (PFN_vkBindBufferMemory2) gpa(device, "vkBindBufferMemory2");
    if (table->BindBufferMemory2 == nullptr) { table->BindBufferMemory2 = (PFN_vkBindBufferMemory2)StubBindBufferMemory2; }
    table->BindImageMemory2 = (PFN_vkBindImageMemory2) gpa(device, "vkBindImageMemory2");
    if (table->BindImageMemory2 == nullptr) { table->BindImageMemory2 = (PFN_vkBindImageMemory2)StubBindImageMemory2; }
    table->GetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures) gpa(device, "vkGetDeviceGroupPeerMemoryFeatures");
    if (table->GetDeviceGroupPeerMemoryFeatures == nullptr) { table->GetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)StubGetDeviceGroupPeerMemoryFeatures; }
    table->CmdSetDeviceMask = (PFN_vkCmdSetDeviceMask) gpa(device, "vkCmdSetDeviceMask");
    if (table->CmdSetDeviceMask == nullptr) { table->CmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)StubCmdSetDeviceMask; }
    table->CmdDispatchBase = (PFN_vkCmdDispatchBase) gpa(device, "vkCmdDispatchBase");
    if (table->CmdDispatchBase == nullptr) { table->CmdDispatchBase = (PFN_vkCmdDispatchBase)StubCmdDispatchBase; }
    table->GetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2) gpa(device, "vkGetImageMemoryRequirements2");
    if (table->GetImageMemoryRequirements2 == nullptr) { table->GetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)StubGetImageMemoryRequirements2; }
    table->GetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2) gpa(device, "vkGetBufferMemoryRequirements2");
    if (table->GetBufferMemoryRequirements2 == nullptr) { table->GetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)StubGetBufferMemoryRequirements2; }
    table->GetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2) gpa(device, "vkGetImageSparseMemoryRequirements2");
    if (table->GetImageSparseMemoryRequirements2 == nullptr) { table->GetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)StubGetImageSparseMemoryRequirements2; }
    table->TrimCommandPool = (PFN_vkTrimCommandPool) gpa(device, "vkTrimCommandPool");
    if (table->TrimCommandPool == nullptr) { table->TrimCommandPool = (PFN_vkTrimCommandPool)StubTrimCommandPool; }
    table->GetDeviceQueue2 = (PFN_vkGetDeviceQueue2) gpa(device, "vkGetDeviceQueue2");
    if (table->GetDeviceQueue2 == nullptr) { table->GetDeviceQueue2 = (PFN_vkGetDeviceQueue2)StubGetDeviceQueue2; }
    table->CreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion) gpa(device, "vkCreateSamplerYcbcrConversion");
    if (table->CreateSamplerYcbcrConversion == nullptr) { table->CreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)StubCreateSamplerYcbcrConversion; }
    table->DestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion) gpa(device, "vkDestroySamplerYcbcrConversion");
    if (table->DestroySamplerYcbcrConversion == nullptr) { table->DestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)StubDestroySamplerYcbcrConversion; }
    table->CreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate) gpa(device, "vkCreateDescriptorUpdateTemplate");
    if (table->CreateDescriptorUpdateTemplate == nullptr) { table->CreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)StubCreateDescriptorUpdateTemplate; }
    table->DestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate) gpa(device, "vkDestroyDescriptorUpdateTemplate");
    if (table->DestroyDescriptorUpdateTemplate == nullptr) { table->DestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)StubDestroyDescriptorUpdateTemplate; }
    table->UpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate) gpa(device, "vkUpdateDescriptorSetWithTemplate");
    if (table->UpdateDescriptorSetWithTemplate == nullptr) { table->UpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)StubUpdateDescriptorSetWithTemplate; }
    table->GetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport) gpa(device, "vkGetDescriptorSetLayoutSupport");
    if (table->GetDescriptorSetLayoutSupport == nullptr) { table->GetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)StubGetDescriptorSetLayoutSupport; }
    table->CmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount) gpa(device, "vkCmdDrawIndirectCount");
    if (table->CmdDrawIndirectCount == nullptr) { table->CmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)StubCmdDrawIndirectCount; }
    table->CmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount) gpa(device, "vkCmdDrawIndexedIndirectCount");
    if (table->CmdDrawIndexedIndirectCount == nullptr) { table->CmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)StubCmdDrawIndexedIndirectCount; }
    table->CreateRenderPass2 = (PFN_vkCreateRenderPass2) gpa(device, "vkCreateRenderPass2");
    if (table->CreateRenderPass2 == nullptr) { table->CreateRenderPass2 = (PFN_vkCreateRenderPass2)StubCreateRenderPass2; }
    table->CmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2) gpa(device, "vkCmdBeginRenderPass2");
    if (table->CmdBeginRenderPass2 == nullptr) { table->CmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)StubCmdBeginRenderPass2; }
    table->CmdNextSubpass2 = (PFN_vkCmdNextSubpass2) gpa(device, "vkCmdNextSubpass2");
    if (table->CmdNextSubpass2 == nullptr) { table->CmdNextSubpass2 = (PFN_vkCmdNextSubpass2)StubCmdNextSubpass2; }
    table->CmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2) gpa(device, "vkCmdEndRenderPass2");
    if (table->CmdEndRenderPass2 == nullptr) { table->CmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)StubCmdEndRenderPass2; }
    table->ResetQueryPool = (PFN_vkResetQueryPool) gpa(device, "vkResetQueryPool");
    if (table->ResetQueryPool == nullptr) { table->ResetQueryPool = (PFN_vkResetQueryPool)StubResetQueryPool; }
    table->GetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue) gpa(device, "vkGetSemaphoreCounterValue");
    if (table->GetSemaphoreCounterValue == nullptr) { table->GetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)StubGetSemaphoreCounterValue; }
    table->WaitSemaphores = (PFN_vkWaitSemaphores) gpa(device, "vkWaitSemaphores");
    if (table->WaitSemaphores == nullptr) { table->WaitSemaphores = (PFN_vkWaitSemaphores)StubWaitSemaphores; }
    table->SignalSemaphore = (PFN_vkSignalSemaphore) gpa(device, "vkSignalSemaphore");
    if (table->SignalSemaphore == nullptr) { table->SignalSemaphore = (PFN_vkSignalSemaphore)StubSignalSemaphore; }
    table->GetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress) gpa(device, "vkGetBufferDeviceAddress");
    if (table->GetBufferDeviceAddress == nullptr) { table->GetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)StubGetBufferDeviceAddress; }
    table->GetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress) gpa(device, "vkGetBufferOpaqueCaptureAddress");
    if (table->GetBufferOpaqueCaptureAddress == nullptr) { table->GetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress)StubGetBufferOpaqueCaptureAddress; }
    table->GetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) gpa(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
    if (table->GetDeviceMemoryOpaqueCaptureAddress == nullptr) { table->GetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)StubGetDeviceMemoryOpaqueCaptureAddress; }
    table->CreateSwapchainKHR = (PFN_vkCreateSwapchainKHR) gpa(device, "vkCreateSwapchainKHR");
    if (table->CreateSwapchainKHR == nullptr) { table->CreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)StubCreateSwapchainKHR; }
    table->DestroySwapchainKHR = (PFN_vkDestroySwapchainKHR) gpa(device, "vkDestroySwapchainKHR");
    if (table->DestroySwapchainKHR == nullptr) { table->DestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)StubDestroySwapchainKHR; }
    table->GetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR) gpa(device, "vkGetSwapchainImagesKHR");
    if (table->GetSwapchainImagesKHR == nullptr) { table->GetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)StubGetSwapchainImagesKHR; }
    table->AcquireNextImageKHR = (PFN_vkAcquireNextImageKHR) gpa(device, "vkAcquireNextImageKHR");
    if (table->AcquireNextImageKHR == nullptr) { table->AcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)StubAcquireNextImageKHR; }
    table->QueuePresentKHR = (PFN_vkQueuePresentKHR) gpa(device, "vkQueuePresentKHR");
    if (table->QueuePresentKHR == nullptr) { table->QueuePresentKHR = (PFN_vkQueuePresentKHR)StubQueuePresentKHR; }
    table->GetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) gpa(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
    if (table->GetDeviceGroupPresentCapabilitiesKHR == nullptr) { table->GetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)StubGetDeviceGroupPresentCapabilitiesKHR; }
    table->GetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) gpa(device, "vkGetDeviceGroupSurfacePresentModesKHR");
    if (table->GetDeviceGroupSurfacePresentModesKHR == nullptr) { table->GetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)StubGetDeviceGroupSurfacePresentModesKHR; }
    table->AcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) gpa(device, "vkAcquireNextImage2KHR");
    if (table->AcquireNextImage2KHR == nullptr) { table->AcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)StubAcquireNextImage2KHR; }
    table->CreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR) gpa(device, "vkCreateSharedSwapchainsKHR");
    if (table->CreateSharedSwapchainsKHR == nullptr) { table->CreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)StubCreateSharedSwapchainsKHR; }
    table->GetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR) gpa(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
    if (table->GetDeviceGroupPeerMemoryFeaturesKHR == nullptr) { table->GetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)StubGetDeviceGroupPeerMemoryFeaturesKHR; }
    table->CmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR) gpa(device, "vkCmdSetDeviceMaskKHR");
    if (table->CmdSetDeviceMaskKHR == nullptr) { table->CmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)StubCmdSetDeviceMaskKHR; }
    table->CmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR) gpa(device, "vkCmdDispatchBaseKHR");
    if (table->CmdDispatchBaseKHR == nullptr) { table->CmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)StubCmdDispatchBaseKHR; }
    table->TrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR) gpa(device, "vkTrimCommandPoolKHR");
    if (table->TrimCommandPoolKHR == nullptr) { table->TrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)StubTrimCommandPoolKHR; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR) gpa(device, "vkGetMemoryWin32HandleKHR");
    if (table->GetMemoryWin32HandleKHR == nullptr) { table->GetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)StubGetMemoryWin32HandleKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR) gpa(device, "vkGetMemoryWin32HandlePropertiesKHR");
    if (table->GetMemoryWin32HandlePropertiesKHR == nullptr) { table->GetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)StubGetMemoryWin32HandlePropertiesKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->GetMemoryFdKHR = (PFN_vkGetMemoryFdKHR) gpa(device, "vkGetMemoryFdKHR");
    if (table->GetMemoryFdKHR == nullptr) { table->GetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)StubGetMemoryFdKHR; }
    table->GetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR) gpa(device, "vkGetMemoryFdPropertiesKHR");
    if (table->GetMemoryFdPropertiesKHR == nullptr) { table->GetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)StubGetMemoryFdPropertiesKHR; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->ImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR) gpa(device, "vkImportSemaphoreWin32HandleKHR");
    if (table->ImportSemaphoreWin32HandleKHR == nullptr) { table->ImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)StubImportSemaphoreWin32HandleKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR) gpa(device, "vkGetSemaphoreWin32HandleKHR");
    if (table->GetSemaphoreWin32HandleKHR == nullptr) { table->GetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)StubGetSemaphoreWin32HandleKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->ImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR) gpa(device, "vkImportSemaphoreFdKHR");
    if (table->ImportSemaphoreFdKHR == nullptr) { table->ImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)StubImportSemaphoreFdKHR; }
    table->GetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR) gpa(device, "vkGetSemaphoreFdKHR");
    if (table->GetSemaphoreFdKHR == nullptr) { table->GetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)StubGetSemaphoreFdKHR; }
    table->CmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR) gpa(device, "vkCmdPushDescriptorSetKHR");
    if (table->CmdPushDescriptorSetKHR == nullptr) { table->CmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)StubCmdPushDescriptorSetKHR; }
    table->CmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) gpa(device, "vkCmdPushDescriptorSetWithTemplateKHR");
    if (table->CmdPushDescriptorSetWithTemplateKHR == nullptr) { table->CmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)StubCmdPushDescriptorSetWithTemplateKHR; }
    table->CreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR) gpa(device, "vkCreateDescriptorUpdateTemplateKHR");
    if (table->CreateDescriptorUpdateTemplateKHR == nullptr) { table->CreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)StubCreateDescriptorUpdateTemplateKHR; }
    table->DestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR) gpa(device, "vkDestroyDescriptorUpdateTemplateKHR");
    if (table->DestroyDescriptorUpdateTemplateKHR == nullptr) { table->DestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)StubDestroyDescriptorUpdateTemplateKHR; }
    table->UpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR) gpa(device, "vkUpdateDescriptorSetWithTemplateKHR");
    if (table->UpdateDescriptorSetWithTemplateKHR == nullptr) { table->UpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)StubUpdateDescriptorSetWithTemplateKHR; }
    table->CreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR) gpa(device, "vkCreateRenderPass2KHR");
    if (table->CreateRenderPass2KHR == nullptr) { table->CreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)StubCreateRenderPass2KHR; }
    table->CmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR) gpa(device, "vkCmdBeginRenderPass2KHR");
    if (table->CmdBeginRenderPass2KHR == nullptr) { table->CmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)StubCmdBeginRenderPass2KHR; }
    table->CmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR) gpa(device, "vkCmdNextSubpass2KHR");
    if (table->CmdNextSubpass2KHR == nullptr) { table->CmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)StubCmdNextSubpass2KHR; }
    table->CmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR) gpa(device, "vkCmdEndRenderPass2KHR");
    if (table->CmdEndRenderPass2KHR == nullptr) { table->CmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)StubCmdEndRenderPass2KHR; }
    table->GetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR) gpa(device, "vkGetSwapchainStatusKHR");
    if (table->GetSwapchainStatusKHR == nullptr) { table->GetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)StubGetSwapchainStatusKHR; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->ImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR) gpa(device, "vkImportFenceWin32HandleKHR");
    if (table->ImportFenceWin32HandleKHR == nullptr) { table->ImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)StubImportFenceWin32HandleKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR) gpa(device, "vkGetFenceWin32HandleKHR");
    if (table->GetFenceWin32HandleKHR == nullptr) { table->GetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)StubGetFenceWin32HandleKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->ImportFenceFdKHR = (PFN_vkImportFenceFdKHR) gpa(device, "vkImportFenceFdKHR");
    if (table->ImportFenceFdKHR == nullptr) { table->ImportFenceFdKHR = (PFN_vkImportFenceFdKHR)StubImportFenceFdKHR; }
    table->GetFenceFdKHR = (PFN_vkGetFenceFdKHR) gpa(device, "vkGetFenceFdKHR");
    if (table->GetFenceFdKHR == nullptr) { table->GetFenceFdKHR = (PFN_vkGetFenceFdKHR)StubGetFenceFdKHR; }
    table->AcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR) gpa(device, "vkAcquireProfilingLockKHR");
    if (table->AcquireProfilingLockKHR == nullptr) { table->AcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)StubAcquireProfilingLockKHR; }
    table->ReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR) gpa(device, "vkReleaseProfilingLockKHR");
    if (table->ReleaseProfilingLockKHR == nullptr) { table->ReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)StubReleaseProfilingLockKHR; }
    table->GetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR) gpa(device, "vkGetImageMemoryRequirements2KHR");
    if (table->GetImageMemoryRequirements2KHR == nullptr) { table->GetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)StubGetImageMemoryRequirements2KHR; }
    table->GetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR) gpa(device, "vkGetBufferMemoryRequirements2KHR");
    if (table->GetBufferMemoryRequirements2KHR == nullptr) { table->GetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)StubGetBufferMemoryRequirements2KHR; }
    table->GetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR) gpa(device, "vkGetImageSparseMemoryRequirements2KHR");
    if (table->GetImageSparseMemoryRequirements2KHR == nullptr) { table->GetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)StubGetImageSparseMemoryRequirements2KHR; }
    table->CreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR) gpa(device, "vkCreateSamplerYcbcrConversionKHR");
    if (table->CreateSamplerYcbcrConversionKHR == nullptr) { table->CreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)StubCreateSamplerYcbcrConversionKHR; }
    table->DestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR) gpa(device, "vkDestroySamplerYcbcrConversionKHR");
    if (table->DestroySamplerYcbcrConversionKHR == nullptr) { table->DestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)StubDestroySamplerYcbcrConversionKHR; }
    table->BindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR) gpa(device, "vkBindBufferMemory2KHR");
    if (table->BindBufferMemory2KHR == nullptr) { table->BindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)StubBindBufferMemory2KHR; }
    table->BindImageMemory2KHR = (PFN_vkBindImageMemory2KHR) gpa(device, "vkBindImageMemory2KHR");
    if (table->BindImageMemory2KHR == nullptr) { table->BindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)StubBindImageMemory2KHR; }
    table->GetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR) gpa(device, "vkGetDescriptorSetLayoutSupportKHR");
    if (table->GetDescriptorSetLayoutSupportKHR == nullptr) { table->GetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)StubGetDescriptorSetLayoutSupportKHR; }
    table->CmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR) gpa(device, "vkCmdDrawIndirectCountKHR");
    if (table->CmdDrawIndirectCountKHR == nullptr) { table->CmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)StubCmdDrawIndirectCountKHR; }
    table->CmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR) gpa(device, "vkCmdDrawIndexedIndirectCountKHR");
    if (table->CmdDrawIndexedIndirectCountKHR == nullptr) { table->CmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)StubCmdDrawIndexedIndirectCountKHR; }
    table->GetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR) gpa(device, "vkGetSemaphoreCounterValueKHR");
    if (table->GetSemaphoreCounterValueKHR == nullptr) { table->GetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)StubGetSemaphoreCounterValueKHR; }
    table->WaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR) gpa(device, "vkWaitSemaphoresKHR");
    if (table->WaitSemaphoresKHR == nullptr) { table->WaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)StubWaitSemaphoresKHR; }
    table->SignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR) gpa(device, "vkSignalSemaphoreKHR");
    if (table->SignalSemaphoreKHR == nullptr) { table->SignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)StubSignalSemaphoreKHR; }
    table->GetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR) gpa(device, "vkGetBufferDeviceAddressKHR");
    if (table->GetBufferDeviceAddressKHR == nullptr) { table->GetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)StubGetBufferDeviceAddressKHR; }
    table->GetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR) gpa(device, "vkGetBufferOpaqueCaptureAddressKHR");
    if (table->GetBufferOpaqueCaptureAddressKHR == nullptr) { table->GetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR)StubGetBufferOpaqueCaptureAddressKHR; }
    table->GetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR) gpa(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    if (table->GetDeviceMemoryOpaqueCaptureAddressKHR == nullptr) { table->GetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)StubGetDeviceMemoryOpaqueCaptureAddressKHR; }
    table->GetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR) gpa(device, "vkGetPipelineExecutablePropertiesKHR");
    if (table->GetPipelineExecutablePropertiesKHR == nullptr) { table->GetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)StubGetPipelineExecutablePropertiesKHR; }
    table->GetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR) gpa(device, "vkGetPipelineExecutableStatisticsKHR");
    if (table->GetPipelineExecutableStatisticsKHR == nullptr) { table->GetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)StubGetPipelineExecutableStatisticsKHR; }
    table->GetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR) gpa(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
    if (table->GetPipelineExecutableInternalRepresentationsKHR == nullptr) { table->GetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)StubGetPipelineExecutableInternalRepresentationsKHR; }
    table->DebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT) gpa(device, "vkDebugMarkerSetObjectTagEXT");
    if (table->DebugMarkerSetObjectTagEXT == nullptr) { table->DebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)StubDebugMarkerSetObjectTagEXT; }
    table->DebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT) gpa(device, "vkDebugMarkerSetObjectNameEXT");
    if (table->DebugMarkerSetObjectNameEXT == nullptr) { table->DebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)StubDebugMarkerSetObjectNameEXT; }
    table->CmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT) gpa(device, "vkCmdDebugMarkerBeginEXT");
    if (table->CmdDebugMarkerBeginEXT == nullptr) { table->CmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)StubCmdDebugMarkerBeginEXT; }
    table->CmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT) gpa(device, "vkCmdDebugMarkerEndEXT");
    if (table->CmdDebugMarkerEndEXT == nullptr) { table->CmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)StubCmdDebugMarkerEndEXT; }
    table->CmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT) gpa(device, "vkCmdDebugMarkerInsertEXT");
    if (table->CmdDebugMarkerInsertEXT == nullptr) { table->CmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)StubCmdDebugMarkerInsertEXT; }
    table->CmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT) gpa(device, "vkCmdBindTransformFeedbackBuffersEXT");
    if (table->CmdBindTransformFeedbackBuffersEXT == nullptr) { table->CmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)StubCmdBindTransformFeedbackBuffersEXT; }
    table->CmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT) gpa(device, "vkCmdBeginTransformFeedbackEXT");
    if (table->CmdBeginTransformFeedbackEXT == nullptr) { table->CmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)StubCmdBeginTransformFeedbackEXT; }
    table->CmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT) gpa(device, "vkCmdEndTransformFeedbackEXT");
    if (table->CmdEndTransformFeedbackEXT == nullptr) { table->CmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)StubCmdEndTransformFeedbackEXT; }
    table->CmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT) gpa(device, "vkCmdBeginQueryIndexedEXT");
    if (table->CmdBeginQueryIndexedEXT == nullptr) { table->CmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)StubCmdBeginQueryIndexedEXT; }
    table->CmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT) gpa(device, "vkCmdEndQueryIndexedEXT");
    if (table->CmdEndQueryIndexedEXT == nullptr) { table->CmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)StubCmdEndQueryIndexedEXT; }
    table->CmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT) gpa(device, "vkCmdDrawIndirectByteCountEXT");
    if (table->CmdDrawIndirectByteCountEXT == nullptr) { table->CmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)StubCmdDrawIndirectByteCountEXT; }
    table->GetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX) gpa(device, "vkGetImageViewHandleNVX");
    if (table->GetImageViewHandleNVX == nullptr) { table->GetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)StubGetImageViewHandleNVX; }
    table->CmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD) gpa(device, "vkCmdDrawIndirectCountAMD");
    if (table->CmdDrawIndirectCountAMD == nullptr) { table->CmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)StubCmdDrawIndirectCountAMD; }
    table->CmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD) gpa(device, "vkCmdDrawIndexedIndirectCountAMD");
    if (table->CmdDrawIndexedIndirectCountAMD == nullptr) { table->CmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)StubCmdDrawIndexedIndirectCountAMD; }
    table->GetShaderInfoAMD = (PFN_vkGetShaderInfoAMD) gpa(device, "vkGetShaderInfoAMD");
    if (table->GetShaderInfoAMD == nullptr) { table->GetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)StubGetShaderInfoAMD; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV) gpa(device, "vkGetMemoryWin32HandleNV");
    if (table->GetMemoryWin32HandleNV == nullptr) { table->GetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)StubGetMemoryWin32HandleNV; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->CmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT) gpa(device, "vkCmdBeginConditionalRenderingEXT");
    if (table->CmdBeginConditionalRenderingEXT == nullptr) { table->CmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)StubCmdBeginConditionalRenderingEXT; }
    table->CmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT) gpa(device, "vkCmdEndConditionalRenderingEXT");
    if (table->CmdEndConditionalRenderingEXT == nullptr) { table->CmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)StubCmdEndConditionalRenderingEXT; }
    table->CmdProcessCommandsNVX = (PFN_vkCmdProcessCommandsNVX) gpa(device, "vkCmdProcessCommandsNVX");
    if (table->CmdProcessCommandsNVX == nullptr) { table->CmdProcessCommandsNVX = (PFN_vkCmdProcessCommandsNVX)StubCmdProcessCommandsNVX; }
    table->CmdReserveSpaceForCommandsNVX = (PFN_vkCmdReserveSpaceForCommandsNVX) gpa(device, "vkCmdReserveSpaceForCommandsNVX");
    if (table->CmdReserveSpaceForCommandsNVX == nullptr) { table->CmdReserveSpaceForCommandsNVX = (PFN_vkCmdReserveSpaceForCommandsNVX)StubCmdReserveSpaceForCommandsNVX; }
    table->CreateIndirectCommandsLayoutNVX = (PFN_vkCreateIndirectCommandsLayoutNVX) gpa(device, "vkCreateIndirectCommandsLayoutNVX");
    if (table->CreateIndirectCommandsLayoutNVX == nullptr) { table->CreateIndirectCommandsLayoutNVX = (PFN_vkCreateIndirectCommandsLayoutNVX)StubCreateIndirectCommandsLayoutNVX; }
    table->DestroyIndirectCommandsLayoutNVX = (PFN_vkDestroyIndirectCommandsLayoutNVX) gpa(device, "vkDestroyIndirectCommandsLayoutNVX");
    if (table->DestroyIndirectCommandsLayoutNVX == nullptr) { table->DestroyIndirectCommandsLayoutNVX = (PFN_vkDestroyIndirectCommandsLayoutNVX)StubDestroyIndirectCommandsLayoutNVX; }
    table->CreateObjectTableNVX = (PFN_vkCreateObjectTableNVX) gpa(device, "vkCreateObjectTableNVX");
    if (table->CreateObjectTableNVX == nullptr) { table->CreateObjectTableNVX = (PFN_vkCreateObjectTableNVX)StubCreateObjectTableNVX; }
    table->DestroyObjectTableNVX = (PFN_vkDestroyObjectTableNVX) gpa(device, "vkDestroyObjectTableNVX");
    if (table->DestroyObjectTableNVX == nullptr) { table->DestroyObjectTableNVX = (PFN_vkDestroyObjectTableNVX)StubDestroyObjectTableNVX; }
    table->RegisterObjectsNVX = (PFN_vkRegisterObjectsNVX) gpa(device, "vkRegisterObjectsNVX");
    if (table->RegisterObjectsNVX == nullptr) { table->RegisterObjectsNVX = (PFN_vkRegisterObjectsNVX)StubRegisterObjectsNVX; }
    table->UnregisterObjectsNVX = (PFN_vkUnregisterObjectsNVX) gpa(device, "vkUnregisterObjectsNVX");
    if (table->UnregisterObjectsNVX == nullptr) { table->UnregisterObjectsNVX = (PFN_vkUnregisterObjectsNVX)StubUnregisterObjectsNVX; }
    table->CmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV) gpa(device, "vkCmdSetViewportWScalingNV");
    if (table->CmdSetViewportWScalingNV == nullptr) { table->CmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)StubCmdSetViewportWScalingNV; }
    table->DisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT) gpa(device, "vkDisplayPowerControlEXT");
    if (table->DisplayPowerControlEXT == nullptr) { table->DisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)StubDisplayPowerControlEXT; }
    table->RegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT) gpa(device, "vkRegisterDeviceEventEXT");
    if (table->RegisterDeviceEventEXT == nullptr) { table->RegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)StubRegisterDeviceEventEXT; }
    table->RegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT) gpa(device, "vkRegisterDisplayEventEXT");
    if (table->RegisterDisplayEventEXT == nullptr) { table->RegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)StubRegisterDisplayEventEXT; }
    table->GetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT) gpa(device, "vkGetSwapchainCounterEXT");
    if (table->GetSwapchainCounterEXT == nullptr) { table->GetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)StubGetSwapchainCounterEXT; }
    table->GetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE) gpa(device, "vkGetRefreshCycleDurationGOOGLE");
    if (table->GetRefreshCycleDurationGOOGLE == nullptr) { table->GetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)StubGetRefreshCycleDurationGOOGLE; }
    table->GetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE) gpa(device, "vkGetPastPresentationTimingGOOGLE");
    if (table->GetPastPresentationTimingGOOGLE == nullptr) { table->GetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)StubGetPastPresentationTimingGOOGLE; }
    table->CmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT) gpa(device, "vkCmdSetDiscardRectangleEXT");
    if (table->CmdSetDiscardRectangleEXT == nullptr) { table->CmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)StubCmdSetDiscardRectangleEXT; }
    table->SetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT) gpa(device, "vkSetHdrMetadataEXT");
    if (table->SetHdrMetadataEXT == nullptr) { table->SetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)StubSetHdrMetadataEXT; }
    table->SetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT) gpa(device, "vkSetDebugUtilsObjectNameEXT");
    if (table->SetDebugUtilsObjectNameEXT == nullptr) { table->SetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)StubSetDebugUtilsObjectNameEXT; }
    table->SetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT) gpa(device, "vkSetDebugUtilsObjectTagEXT");
    if (table->SetDebugUtilsObjectTagEXT == nullptr) { table->SetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)StubSetDebugUtilsObjectTagEXT; }
    table->QueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT) gpa(device, "vkQueueBeginDebugUtilsLabelEXT");
    if (table->QueueBeginDebugUtilsLabelEXT == nullptr) { table->QueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)StubQueueBeginDebugUtilsLabelEXT; }
    table->QueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT) gpa(device, "vkQueueEndDebugUtilsLabelEXT");
    if (table->QueueEndDebugUtilsLabelEXT == nullptr) { table->QueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)StubQueueEndDebugUtilsLabelEXT; }
    table->QueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT) gpa(device, "vkQueueInsertDebugUtilsLabelEXT");
    if (table->QueueInsertDebugUtilsLabelEXT == nullptr) { table->QueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)StubQueueInsertDebugUtilsLabelEXT; }
    table->CmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT) gpa(device, "vkCmdBeginDebugUtilsLabelEXT");
    if (table->CmdBeginDebugUtilsLabelEXT == nullptr) { table->CmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)StubCmdBeginDebugUtilsLabelEXT; }
    table->CmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT) gpa(device, "vkCmdEndDebugUtilsLabelEXT");
    if (table->CmdEndDebugUtilsLabelEXT == nullptr) { table->CmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)StubCmdEndDebugUtilsLabelEXT; }
    table->CmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT) gpa(device, "vkCmdInsertDebugUtilsLabelEXT");
    if (table->CmdInsertDebugUtilsLabelEXT == nullptr) { table->CmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)StubCmdInsertDebugUtilsLabelEXT; }
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    table->GetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID) gpa(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
    if (table->GetAndroidHardwareBufferPropertiesANDROID == nullptr) { table->GetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)StubGetAndroidHardwareBufferPropertiesANDROID; }
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    table->GetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID) gpa(device, "vkGetMemoryAndroidHardwareBufferANDROID");
    if (table->GetMemoryAndroidHardwareBufferANDROID == nullptr) { table->GetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)StubGetMemoryAndroidHardwareBufferANDROID; }
#endif // VK_USE_PLATFORM_ANDROID_KHR
    table->CmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT) gpa(device, "vkCmdSetSampleLocationsEXT");
    if (table->CmdSetSampleLocationsEXT == nullptr) { table->CmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)StubCmdSetSampleLocationsEXT; }
    table->GetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) gpa(device, "vkGetImageDrmFormatModifierPropertiesEXT");
    if (table->GetImageDrmFormatModifierPropertiesEXT == nullptr) { table->GetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)StubGetImageDrmFormatModifierPropertiesEXT; }
    table->CreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT) gpa(device, "vkCreateValidationCacheEXT");
    if (table->CreateValidationCacheEXT == nullptr) { table->CreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)StubCreateValidationCacheEXT; }
    table->DestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT) gpa(device, "vkDestroyValidationCacheEXT");
    if (table->DestroyValidationCacheEXT == nullptr) { table->DestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)StubDestroyValidationCacheEXT; }
    table->MergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT) gpa(device, "vkMergeValidationCachesEXT");
    if (table->MergeValidationCachesEXT == nullptr) { table->MergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)StubMergeValidationCachesEXT; }
    table->GetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT) gpa(device, "vkGetValidationCacheDataEXT");
    if (table->GetValidationCacheDataEXT == nullptr) { table->GetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)StubGetValidationCacheDataEXT; }
    table->CmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV) gpa(device, "vkCmdBindShadingRateImageNV");
    if (table->CmdBindShadingRateImageNV == nullptr) { table->CmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)StubCmdBindShadingRateImageNV; }
    table->CmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV) gpa(device, "vkCmdSetViewportShadingRatePaletteNV");
    if (table->CmdSetViewportShadingRatePaletteNV == nullptr) { table->CmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)StubCmdSetViewportShadingRatePaletteNV; }
    table->CmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV) gpa(device, "vkCmdSetCoarseSampleOrderNV");
    if (table->CmdSetCoarseSampleOrderNV == nullptr) { table->CmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)StubCmdSetCoarseSampleOrderNV; }
    table->CreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV) gpa(device, "vkCreateAccelerationStructureNV");
    if (table->CreateAccelerationStructureNV == nullptr) { table->CreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)StubCreateAccelerationStructureNV; }
    table->DestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV) gpa(device, "vkDestroyAccelerationStructureNV");
    if (table->DestroyAccelerationStructureNV == nullptr) { table->DestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)StubDestroyAccelerationStructureNV; }
    table->GetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV) gpa(device, "vkGetAccelerationStructureMemoryRequirementsNV");
    if (table->GetAccelerationStructureMemoryRequirementsNV == nullptr) { table->GetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)StubGetAccelerationStructureMemoryRequirementsNV; }
    table->BindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV) gpa(device, "vkBindAccelerationStructureMemoryNV");
    if (table->BindAccelerationStructureMemoryNV == nullptr) { table->BindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)StubBindAccelerationStructureMemoryNV; }
    table->CmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV) gpa(device, "vkCmdBuildAccelerationStructureNV");
    if (table->CmdBuildAccelerationStructureNV == nullptr) { table->CmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)StubCmdBuildAccelerationStructureNV; }
    table->CmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV) gpa(device, "vkCmdCopyAccelerationStructureNV");
    if (table->CmdCopyAccelerationStructureNV == nullptr) { table->CmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)StubCmdCopyAccelerationStructureNV; }
    table->CmdTraceRaysNV = (PFN_vkCmdTraceRaysNV) gpa(device, "vkCmdTraceRaysNV");
    if (table->CmdTraceRaysNV == nullptr) { table->CmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)StubCmdTraceRaysNV; }
    table->CreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV) gpa(device, "vkCreateRayTracingPipelinesNV");
    if (table->CreateRayTracingPipelinesNV == nullptr) { table->CreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)StubCreateRayTracingPipelinesNV; }
    table->GetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV) gpa(device, "vkGetRayTracingShaderGroupHandlesNV");
    if (table->GetRayTracingShaderGroupHandlesNV == nullptr) { table->GetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)StubGetRayTracingShaderGroupHandlesNV; }
    table->GetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV) gpa(device, "vkGetAccelerationStructureHandleNV");
    if (table->GetAccelerationStructureHandleNV == nullptr) { table->GetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)StubGetAccelerationStructureHandleNV; }
    table->CmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV) gpa(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
    if (table->CmdWriteAccelerationStructuresPropertiesNV == nullptr) { table->CmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)StubCmdWriteAccelerationStructuresPropertiesNV; }
    table->CompileDeferredNV = (PFN_vkCompileDeferredNV) gpa(device, "vkCompileDeferredNV");
    if (table->CompileDeferredNV == nullptr) { table->CompileDeferredNV = (PFN_vkCompileDeferredNV)StubCompileDeferredNV; }
    table->GetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT) gpa(device, "vkGetMemoryHostPointerPropertiesEXT");
    if (table->GetMemoryHostPointerPropertiesEXT == nullptr) { table->GetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)StubGetMemoryHostPointerPropertiesEXT; }
    table->CmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD) gpa(device, "vkCmdWriteBufferMarkerAMD");
    if (table->CmdWriteBufferMarkerAMD == nullptr) { table->CmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)StubCmdWriteBufferMarkerAMD; }
    table->GetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT) gpa(device, "vkGetCalibratedTimestampsEXT");
    if (table->GetCalibratedTimestampsEXT == nullptr) { table->GetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)StubGetCalibratedTimestampsEXT; }
    table->CmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV) gpa(device, "vkCmdDrawMeshTasksNV");
    if (table->CmdDrawMeshTasksNV == nullptr) { table->CmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)StubCmdDrawMeshTasksNV; }
    table->CmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV) gpa(device, "vkCmdDrawMeshTasksIndirectNV");
    if (table->CmdDrawMeshTasksIndirectNV == nullptr) { table->CmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)StubCmdDrawMeshTasksIndirectNV; }
    table->CmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV) gpa(device, "vkCmdDrawMeshTasksIndirectCountNV");
    if (table->CmdDrawMeshTasksIndirectCountNV == nullptr) { table->CmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)StubCmdDrawMeshTasksIndirectCountNV; }
    table->CmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV) gpa(device, "vkCmdSetExclusiveScissorNV");
    if (table->CmdSetExclusiveScissorNV == nullptr) { table->CmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)StubCmdSetExclusiveScissorNV; }
    table->CmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV) gpa(device, "vkCmdSetCheckpointNV");
    if (table->CmdSetCheckpointNV == nullptr) { table->CmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)StubCmdSetCheckpointNV; }
    table->GetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV) gpa(device, "vkGetQueueCheckpointDataNV");
    if (table->GetQueueCheckpointDataNV == nullptr) { table->GetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)StubGetQueueCheckpointDataNV; }
    table->InitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL) gpa(device, "vkInitializePerformanceApiINTEL");
    if (table->InitializePerformanceApiINTEL == nullptr) { table->InitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)StubInitializePerformanceApiINTEL; }
    table->UninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL) gpa(device, "vkUninitializePerformanceApiINTEL");
    if (table->UninitializePerformanceApiINTEL == nullptr) { table->UninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)StubUninitializePerformanceApiINTEL; }
    table->CmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL) gpa(device, "vkCmdSetPerformanceMarkerINTEL");
    if (table->CmdSetPerformanceMarkerINTEL == nullptr) { table->CmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)StubCmdSetPerformanceMarkerINTEL; }
    table->CmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL) gpa(device, "vkCmdSetPerformanceStreamMarkerINTEL");
    if (table->CmdSetPerformanceStreamMarkerINTEL == nullptr) { table->CmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)StubCmdSetPerformanceStreamMarkerINTEL; }
    table->CmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL) gpa(device, "vkCmdSetPerformanceOverrideINTEL");
    if (table->CmdSetPerformanceOverrideINTEL == nullptr) { table->CmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)StubCmdSetPerformanceOverrideINTEL; }
    table->AcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL) gpa(device, "vkAcquirePerformanceConfigurationINTEL");
    if (table->AcquirePerformanceConfigurationINTEL == nullptr) { table->AcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)StubAcquirePerformanceConfigurationINTEL; }
    table->ReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL) gpa(device, "vkReleasePerformanceConfigurationINTEL");
    if (table->ReleasePerformanceConfigurationINTEL == nullptr) { table->ReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)StubReleasePerformanceConfigurationINTEL; }
    table->QueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL) gpa(device, "vkQueueSetPerformanceConfigurationINTEL");
    if (table->QueueSetPerformanceConfigurationINTEL == nullptr) { table->QueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)StubQueueSetPerformanceConfigurationINTEL; }
    table->GetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL) gpa(device, "vkGetPerformanceParameterINTEL");
    if (table->GetPerformanceParameterINTEL == nullptr) { table->GetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)StubGetPerformanceParameterINTEL; }
    table->SetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD) gpa(device, "vkSetLocalDimmingAMD");
    if (table->SetLocalDimmingAMD == nullptr) { table->SetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)StubSetLocalDimmingAMD; }
    table->GetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT) gpa(device, "vkGetBufferDeviceAddressEXT");
    if (table->GetBufferDeviceAddressEXT == nullptr) { table->GetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)StubGetBufferDeviceAddressEXT; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->AcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT) gpa(device, "vkAcquireFullScreenExclusiveModeEXT");
    if (table->AcquireFullScreenExclusiveModeEXT == nullptr) { table->AcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)StubAcquireFullScreenExclusiveModeEXT; }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->ReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT) gpa(device, "vkReleaseFullScreenExclusiveModeEXT");
    if (table->ReleaseFullScreenExclusiveModeEXT == nullptr) { table->ReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)StubReleaseFullScreenExclusiveModeEXT; }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT) gpa(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
    if (table->GetDeviceGroupSurfacePresentModes2EXT == nullptr) { table->GetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)StubGetDeviceGroupSurfacePresentModes2EXT; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->CmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT) gpa(device, "vkCmdSetLineStippleEXT");
    if (table->CmdSetLineStippleEXT == nullptr) { table->CmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)StubCmdSetLineStippleEXT; }
    table->ResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT) gpa(device, "vkResetQueryPoolEXT");
    if (table->ResetQueryPoolEXT == nullptr) { table->ResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)StubResetQueryPoolEXT; }
}


static inline void layer_init_instance_dispatch_table(VkInstance instance, VkLayerInstanceDispatchTable *table, PFN_vkGetInstanceProcAddr gpa) {
    memset(table, 0, sizeof(*table));
    // Instance function pointers
    table->DestroyInstance = (PFN_vkDestroyInstance) gpa(instance, "vkDestroyInstance");
    table->EnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices) gpa(instance, "vkEnumeratePhysicalDevices");
    table->GetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures) gpa(instance, "vkGetPhysicalDeviceFeatures");
    table->GetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties) gpa(instance, "vkGetPhysicalDeviceFormatProperties");
    table->GetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties) gpa(instance, "vkGetPhysicalDeviceImageFormatProperties");
    table->GetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties) gpa(instance, "vkGetPhysicalDeviceProperties");
    table->GetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) gpa(instance, "vkGetPhysicalDeviceQueueFamilyProperties");
    table->GetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) gpa(instance, "vkGetPhysicalDeviceMemoryProperties");
    table->GetInstanceProcAddr = gpa;
    table->EnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties) gpa(instance, "vkEnumerateDeviceExtensionProperties");
    table->EnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties) gpa(instance, "vkEnumerateDeviceLayerProperties");
    table->GetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) gpa(instance, "vkGetPhysicalDeviceSparseImageFormatProperties");
    table->EnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups) gpa(instance, "vkEnumeratePhysicalDeviceGroups");
    if (table->EnumeratePhysicalDeviceGroups == nullptr) { table->EnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)StubEnumeratePhysicalDeviceGroups; }
    table->GetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2) gpa(instance, "vkGetPhysicalDeviceFeatures2");
    if (table->GetPhysicalDeviceFeatures2 == nullptr) { table->GetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)StubGetPhysicalDeviceFeatures2; }
    table->GetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2) gpa(instance, "vkGetPhysicalDeviceProperties2");
    if (table->GetPhysicalDeviceProperties2 == nullptr) { table->GetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)StubGetPhysicalDeviceProperties2; }
    table->GetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2) gpa(instance, "vkGetPhysicalDeviceFormatProperties2");
    if (table->GetPhysicalDeviceFormatProperties2 == nullptr) { table->GetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)StubGetPhysicalDeviceFormatProperties2; }
    table->GetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2) gpa(instance, "vkGetPhysicalDeviceImageFormatProperties2");
    if (table->GetPhysicalDeviceImageFormatProperties2 == nullptr) { table->GetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)StubGetPhysicalDeviceImageFormatProperties2; }
    table->GetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) gpa(instance, "vkGetPhysicalDeviceQueueFamilyProperties2");
    if (table->GetPhysicalDeviceQueueFamilyProperties2 == nullptr) { table->GetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)StubGetPhysicalDeviceQueueFamilyProperties2; }
    table->GetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2) gpa(instance, "vkGetPhysicalDeviceMemoryProperties2");
    if (table->GetPhysicalDeviceMemoryProperties2 == nullptr) { table->GetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)StubGetPhysicalDeviceMemoryProperties2; }
    table->GetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) gpa(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    if (table->GetPhysicalDeviceSparseImageFormatProperties2 == nullptr) { table->GetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)StubGetPhysicalDeviceSparseImageFormatProperties2; }
    table->GetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties) gpa(instance, "vkGetPhysicalDeviceExternalBufferProperties");
    if (table->GetPhysicalDeviceExternalBufferProperties == nullptr) { table->GetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)StubGetPhysicalDeviceExternalBufferProperties; }
    table->GetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties) gpa(instance, "vkGetPhysicalDeviceExternalFenceProperties");
    if (table->GetPhysicalDeviceExternalFenceProperties == nullptr) { table->GetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)StubGetPhysicalDeviceExternalFenceProperties; }
    table->GetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) gpa(instance, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    if (table->GetPhysicalDeviceExternalSemaphoreProperties == nullptr) { table->GetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)StubGetPhysicalDeviceExternalSemaphoreProperties; }
    table->DestroySurfaceKHR = (PFN_vkDestroySurfaceKHR) gpa(instance, "vkDestroySurfaceKHR");
    if (table->DestroySurfaceKHR == nullptr) { table->DestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)StubDestroySurfaceKHR; }
    table->GetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) gpa(instance, "vkGetPhysicalDeviceSurfaceSupportKHR");
    if (table->GetPhysicalDeviceSurfaceSupportKHR == nullptr) { table->GetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)StubGetPhysicalDeviceSurfaceSupportKHR; }
    table->GetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) gpa(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    if (table->GetPhysicalDeviceSurfaceCapabilitiesKHR == nullptr) { table->GetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)StubGetPhysicalDeviceSurfaceCapabilitiesKHR; }
    table->GetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) gpa(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    if (table->GetPhysicalDeviceSurfaceFormatsKHR == nullptr) { table->GetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)StubGetPhysicalDeviceSurfaceFormatsKHR; }
    table->GetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) gpa(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    if (table->GetPhysicalDeviceSurfacePresentModesKHR == nullptr) { table->GetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)StubGetPhysicalDeviceSurfacePresentModesKHR; }
    table->GetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) gpa(instance, "vkGetPhysicalDevicePresentRectanglesKHR");
    if (table->GetPhysicalDevicePresentRectanglesKHR == nullptr) { table->GetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)StubGetPhysicalDevicePresentRectanglesKHR; }
    table->GetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) gpa(instance, "vkGetPhysicalDeviceDisplayPropertiesKHR");
    if (table->GetPhysicalDeviceDisplayPropertiesKHR == nullptr) { table->GetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)StubGetPhysicalDeviceDisplayPropertiesKHR; }
    table->GetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) gpa(instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    if (table->GetPhysicalDeviceDisplayPlanePropertiesKHR == nullptr) { table->GetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)StubGetPhysicalDeviceDisplayPlanePropertiesKHR; }
    table->GetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) gpa(instance, "vkGetDisplayPlaneSupportedDisplaysKHR");
    if (table->GetDisplayPlaneSupportedDisplaysKHR == nullptr) { table->GetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)StubGetDisplayPlaneSupportedDisplaysKHR; }
    table->GetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR) gpa(instance, "vkGetDisplayModePropertiesKHR");
    if (table->GetDisplayModePropertiesKHR == nullptr) { table->GetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)StubGetDisplayModePropertiesKHR; }
    table->CreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR) gpa(instance, "vkCreateDisplayModeKHR");
    if (table->CreateDisplayModeKHR == nullptr) { table->CreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)StubCreateDisplayModeKHR; }
    table->GetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR) gpa(instance, "vkGetDisplayPlaneCapabilitiesKHR");
    if (table->GetDisplayPlaneCapabilitiesKHR == nullptr) { table->GetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)StubGetDisplayPlaneCapabilitiesKHR; }
    table->CreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR) gpa(instance, "vkCreateDisplayPlaneSurfaceKHR");
    if (table->CreateDisplayPlaneSurfaceKHR == nullptr) { table->CreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)StubCreateDisplayPlaneSurfaceKHR; }
#ifdef VK_USE_PLATFORM_XLIB_KHR
    table->CreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR) gpa(instance, "vkCreateXlibSurfaceKHR");
    if (table->CreateXlibSurfaceKHR == nullptr) { table->CreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)StubCreateXlibSurfaceKHR; }
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    table->GetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR) gpa(instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
    if (table->GetPhysicalDeviceXlibPresentationSupportKHR == nullptr) { table->GetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)StubGetPhysicalDeviceXlibPresentationSupportKHR; }
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    table->CreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR) gpa(instance, "vkCreateXcbSurfaceKHR");
    if (table->CreateXcbSurfaceKHR == nullptr) { table->CreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)StubCreateXcbSurfaceKHR; }
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    table->GetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR) gpa(instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
    if (table->GetPhysicalDeviceXcbPresentationSupportKHR == nullptr) { table->GetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)StubGetPhysicalDeviceXcbPresentationSupportKHR; }
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    table->CreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR) gpa(instance, "vkCreateWaylandSurfaceKHR");
    if (table->CreateWaylandSurfaceKHR == nullptr) { table->CreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)StubCreateWaylandSurfaceKHR; }
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    table->GetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR) gpa(instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
    if (table->GetPhysicalDeviceWaylandPresentationSupportKHR == nullptr) { table->GetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)StubGetPhysicalDeviceWaylandPresentationSupportKHR; }
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    table->CreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR) gpa(instance, "vkCreateAndroidSurfaceKHR");
    if (table->CreateAndroidSurfaceKHR == nullptr) { table->CreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)StubCreateAndroidSurfaceKHR; }
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->CreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR) gpa(instance, "vkCreateWin32SurfaceKHR");
    if (table->CreateWin32SurfaceKHR == nullptr) { table->CreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)StubCreateWin32SurfaceKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR) gpa(instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
    if (table->GetPhysicalDeviceWin32PresentationSupportKHR == nullptr) { table->GetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)StubGetPhysicalDeviceWin32PresentationSupportKHR; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->GetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR) gpa(instance, "vkGetPhysicalDeviceFeatures2KHR");
    if (table->GetPhysicalDeviceFeatures2KHR == nullptr) { table->GetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)StubGetPhysicalDeviceFeatures2KHR; }
    table->GetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR) gpa(instance, "vkGetPhysicalDeviceProperties2KHR");
    if (table->GetPhysicalDeviceProperties2KHR == nullptr) { table->GetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)StubGetPhysicalDeviceProperties2KHR; }
    table->GetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR) gpa(instance, "vkGetPhysicalDeviceFormatProperties2KHR");
    if (table->GetPhysicalDeviceFormatProperties2KHR == nullptr) { table->GetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)StubGetPhysicalDeviceFormatProperties2KHR; }
    table->GetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR) gpa(instance, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    if (table->GetPhysicalDeviceImageFormatProperties2KHR == nullptr) { table->GetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)StubGetPhysicalDeviceImageFormatProperties2KHR; }
    table->GetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR) gpa(instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    if (table->GetPhysicalDeviceQueueFamilyProperties2KHR == nullptr) { table->GetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)StubGetPhysicalDeviceQueueFamilyProperties2KHR; }
    table->GetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR) gpa(instance, "vkGetPhysicalDeviceMemoryProperties2KHR");
    if (table->GetPhysicalDeviceMemoryProperties2KHR == nullptr) { table->GetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)StubGetPhysicalDeviceMemoryProperties2KHR; }
    table->GetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR) gpa(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    if (table->GetPhysicalDeviceSparseImageFormatProperties2KHR == nullptr) { table->GetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)StubGetPhysicalDeviceSparseImageFormatProperties2KHR; }
    table->EnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR) gpa(instance, "vkEnumeratePhysicalDeviceGroupsKHR");
    if (table->EnumeratePhysicalDeviceGroupsKHR == nullptr) { table->EnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)StubEnumeratePhysicalDeviceGroupsKHR; }
    table->GetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR) gpa(instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    if (table->GetPhysicalDeviceExternalBufferPropertiesKHR == nullptr) { table->GetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)StubGetPhysicalDeviceExternalBufferPropertiesKHR; }
    table->GetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR) gpa(instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    if (table->GetPhysicalDeviceExternalSemaphorePropertiesKHR == nullptr) { table->GetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)StubGetPhysicalDeviceExternalSemaphorePropertiesKHR; }
    table->GetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR) gpa(instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
    if (table->GetPhysicalDeviceExternalFencePropertiesKHR == nullptr) { table->GetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)StubGetPhysicalDeviceExternalFencePropertiesKHR; }
    table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR) gpa(instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    if (table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR == nullptr) { table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)StubEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR; }
    table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR) gpa(instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    if (table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR == nullptr) { table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)StubGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR; }
    table->GetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) gpa(instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    if (table->GetPhysicalDeviceSurfaceCapabilities2KHR == nullptr) { table->GetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)StubGetPhysicalDeviceSurfaceCapabilities2KHR; }
    table->GetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) gpa(instance, "vkGetPhysicalDeviceSurfaceFormats2KHR");
    if (table->GetPhysicalDeviceSurfaceFormats2KHR == nullptr) { table->GetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)StubGetPhysicalDeviceSurfaceFormats2KHR; }
    table->GetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) gpa(instance, "vkGetPhysicalDeviceDisplayProperties2KHR");
    if (table->GetPhysicalDeviceDisplayProperties2KHR == nullptr) { table->GetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)StubGetPhysicalDeviceDisplayProperties2KHR; }
    table->GetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) gpa(instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    if (table->GetPhysicalDeviceDisplayPlaneProperties2KHR == nullptr) { table->GetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)StubGetPhysicalDeviceDisplayPlaneProperties2KHR; }
    table->GetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR) gpa(instance, "vkGetDisplayModeProperties2KHR");
    if (table->GetDisplayModeProperties2KHR == nullptr) { table->GetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)StubGetDisplayModeProperties2KHR; }
    table->GetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR) gpa(instance, "vkGetDisplayPlaneCapabilities2KHR");
    if (table->GetDisplayPlaneCapabilities2KHR == nullptr) { table->GetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)StubGetDisplayPlaneCapabilities2KHR; }
    table->CreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT) gpa(instance, "vkCreateDebugReportCallbackEXT");
    if (table->CreateDebugReportCallbackEXT == nullptr) { table->CreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)StubCreateDebugReportCallbackEXT; }
    table->DestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT) gpa(instance, "vkDestroyDebugReportCallbackEXT");
    if (table->DestroyDebugReportCallbackEXT == nullptr) { table->DestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)StubDestroyDebugReportCallbackEXT; }
    table->DebugReportMessageEXT = (PFN_vkDebugReportMessageEXT) gpa(instance, "vkDebugReportMessageEXT");
    if (table->DebugReportMessageEXT == nullptr) { table->DebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)StubDebugReportMessageEXT; }
#ifdef VK_USE_PLATFORM_GGP
    table->CreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP) gpa(instance, "vkCreateStreamDescriptorSurfaceGGP");
    if (table->CreateStreamDescriptorSurfaceGGP == nullptr) { table->CreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)StubCreateStreamDescriptorSurfaceGGP; }
#endif // VK_USE_PLATFORM_GGP
    table->GetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV) gpa(instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
    if (table->GetPhysicalDeviceExternalImageFormatPropertiesNV == nullptr) { table->GetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)StubGetPhysicalDeviceExternalImageFormatPropertiesNV; }
#ifdef VK_USE_PLATFORM_VI_NN
    table->CreateViSurfaceNN = (PFN_vkCreateViSurfaceNN) gpa(instance, "vkCreateViSurfaceNN");
    if (table->CreateViSurfaceNN == nullptr) { table->CreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)StubCreateViSurfaceNN; }
#endif // VK_USE_PLATFORM_VI_NN
    table->GetPhysicalDeviceGeneratedCommandsPropertiesNVX = (PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX) gpa(instance, "vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX");
    if (table->GetPhysicalDeviceGeneratedCommandsPropertiesNVX == nullptr) { table->GetPhysicalDeviceGeneratedCommandsPropertiesNVX = (PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX)StubGetPhysicalDeviceGeneratedCommandsPropertiesNVX; }
    table->ReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT) gpa(instance, "vkReleaseDisplayEXT");
    if (table->ReleaseDisplayEXT == nullptr) { table->ReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)StubReleaseDisplayEXT; }
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    table->AcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT) gpa(instance, "vkAcquireXlibDisplayEXT");
    if (table->AcquireXlibDisplayEXT == nullptr) { table->AcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)StubAcquireXlibDisplayEXT; }
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    table->GetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT) gpa(instance, "vkGetRandROutputDisplayEXT");
    if (table->GetRandROutputDisplayEXT == nullptr) { table->GetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)StubGetRandROutputDisplayEXT; }
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
    table->GetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT) gpa(instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
    if (table->GetPhysicalDeviceSurfaceCapabilities2EXT == nullptr) { table->GetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)StubGetPhysicalDeviceSurfaceCapabilities2EXT; }
#ifdef VK_USE_PLATFORM_IOS_MVK
    table->CreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK) gpa(instance, "vkCreateIOSSurfaceMVK");
    if (table->CreateIOSSurfaceMVK == nullptr) { table->CreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)StubCreateIOSSurfaceMVK; }
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
    table->CreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK) gpa(instance, "vkCreateMacOSSurfaceMVK");
    if (table->CreateMacOSSurfaceMVK == nullptr) { table->CreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)StubCreateMacOSSurfaceMVK; }
#endif // VK_USE_PLATFORM_MACOS_MVK
    table->CreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT) gpa(instance, "vkCreateDebugUtilsMessengerEXT");
    if (table->CreateDebugUtilsMessengerEXT == nullptr) { table->CreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)StubCreateDebugUtilsMessengerEXT; }
    table->DestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT) gpa(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (table->DestroyDebugUtilsMessengerEXT == nullptr) { table->DestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)StubDestroyDebugUtilsMessengerEXT; }
    table->SubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT) gpa(instance, "vkSubmitDebugUtilsMessageEXT");
    if (table->SubmitDebugUtilsMessageEXT == nullptr) { table->SubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)StubSubmitDebugUtilsMessageEXT; }
    table->GetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) gpa(instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    if (table->GetPhysicalDeviceMultisamplePropertiesEXT == nullptr) { table->GetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)StubGetPhysicalDeviceMultisamplePropertiesEXT; }
    table->GetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT) gpa(instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    if (table->GetPhysicalDeviceCalibrateableTimeDomainsEXT == nullptr) { table->GetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)StubGetPhysicalDeviceCalibrateableTimeDomainsEXT; }
#ifdef VK_USE_PLATFORM_FUCHSIA
    table->CreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA) gpa(instance, "vkCreateImagePipeSurfaceFUCHSIA");
    if (table->CreateImagePipeSurfaceFUCHSIA == nullptr) { table->CreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA)StubCreateImagePipeSurfaceFUCHSIA; }
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
    table->CreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT) gpa(instance, "vkCreateMetalSurfaceEXT");
    if (table->CreateMetalSurfaceEXT == nullptr) { table->CreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)StubCreateMetalSurfaceEXT; }
#endif // VK_USE_PLATFORM_METAL_EXT
    table->GetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT) gpa(instance, "vkGetPhysicalDeviceToolPropertiesEXT");
    if (table->GetPhysicalDeviceToolPropertiesEXT == nullptr) { table->GetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT)StubGetPhysicalDeviceToolPropertiesEXT; }
    table->GetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV) gpa(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    if (table->GetPhysicalDeviceCooperativeMatrixPropertiesNV == nullptr) { table->GetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)StubGetPhysicalDeviceCooperativeMatrixPropertiesNV; }
    table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV) gpa(instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
    if (table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV == nullptr) { table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)StubGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
    table->GetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT) gpa(instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
    if (table->GetPhysicalDeviceSurfacePresentModes2EXT == nullptr) { table->GetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)StubGetPhysicalDeviceSurfacePresentModes2EXT; }
#endif // VK_USE_PLATFORM_WIN32_KHR
    table->CreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT) gpa(instance, "vkCreateHeadlessSurfaceEXT");
    if (table->CreateHeadlessSurfaceEXT == nullptr) { table->CreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)StubCreateHeadlessSurfaceEXT; }
}
