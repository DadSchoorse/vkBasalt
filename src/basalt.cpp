#include <assert.h>
#include <string.h>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"
#include "vulkan/vk_dispatch_table_helper.h"

#include <mutex>
#include <map>
#include <iostream>

#undef VK_LAYER_EXPORT
#if defined(WIN32)
#define VK_LAYER_EXPORT extern "C" __declspec(dllexport)
#else
#define VK_LAYER_EXPORT extern "C"
#endif

std::mutex globalLock;
typedef std::lock_guard<std::mutex> scoped_lock;
template<typename DispatchableType>
void *GetKey(DispatchableType inst)
{
    return *(void **)inst;
}

// layer book-keeping information, to store dispatch tables by key
std::map<void *, VkLayerInstanceDispatchTable> instance_dispatch;
std::map<void *, VkLayerDispatchTable> device_dispatch;

VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    VkLayerInstanceCreateInfo *layerCreateInfo = (VkLayerInstanceCreateInfo *)pCreateInfo->pNext;

    // step through the chain of pNext until we get to the link info
    while(layerCreateInfo && (layerCreateInfo->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO ||
                            layerCreateInfo->function != VK_LAYER_LINK_INFO))
    {
        layerCreateInfo = (VkLayerInstanceCreateInfo *)layerCreateInfo->pNext;
    }
    std::cout << "i am doing something" << std::endl;
    if(layerCreateInfo == NULL)
    {
    // No loader instance create info
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    PFN_vkGetInstanceProcAddr gpa = layerCreateInfo->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    // move chain on for next layer
    layerCreateInfo->u.pLayerInfo = layerCreateInfo->u.pLayerInfo->pNext;

    PFN_vkCreateInstance createFunc = (PFN_vkCreateInstance)gpa(VK_NULL_HANDLE, "vkCreateInstance");

    VkResult ret = createFunc(pCreateInfo, pAllocator, pInstance);

    // fetch our own dispatch table for the functions we need, into the next layer
    VkLayerInstanceDispatchTable dispatchTable;
    layer_init_instance_dispatch_table(*pInstance,&dispatchTable,gpa);
    
    // store the table by key
    {
        scoped_lock l(globalLock);
        instance_dispatch[GetKey(*pInstance)] = dispatchTable;
    }

    return VK_SUCCESS;
}

VK_LAYER_EXPORT void VKAPI_CALL vkBasalt_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
{
    scoped_lock l(globalLock);
    instance_dispatch.erase(GetKey(instance));
}

VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    VkLayerDeviceCreateInfo *layerCreateInfo = (VkLayerDeviceCreateInfo *)pCreateInfo->pNext;

    // step through the chain of pNext until we get to the link info
    while(layerCreateInfo && (layerCreateInfo->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO ||
                            layerCreateInfo->function != VK_LAYER_LINK_INFO))
    {
    layerCreateInfo = (VkLayerDeviceCreateInfo *)layerCreateInfo->pNext;
    }

    if(layerCreateInfo == NULL)
    {
    // No loader instance create info
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    PFN_vkGetInstanceProcAddr gipa = layerCreateInfo->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr gdpa = layerCreateInfo->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    // move chain on for next layer
    layerCreateInfo->u.pLayerInfo = layerCreateInfo->u.pLayerInfo->pNext;

    PFN_vkCreateDevice createFunc = (PFN_vkCreateDevice)gipa(VK_NULL_HANDLE, "vkCreateDevice");

    VkResult ret = createFunc(physicalDevice, pCreateInfo, pAllocator, pDevice);

    // fetch our own dispatch table for the functions we need, into the next layer
    VkLayerDispatchTable dispatchTable;
    layer_init_device_dispatch_table(*pDevice,&dispatchTable,gdpa);

    // store the table by key
    {
        scoped_lock l(globalLock);
        device_dispatch[GetKey(*pDevice)] = dispatchTable;
    }

  return VK_SUCCESS;
}

VK_LAYER_EXPORT void VKAPI_CALL vkBasalt_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
{
    scoped_lock l(globalLock);
    device_dispatch.erase(GetKey(device));
}


VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pCount, VkImage *pSwapchainImages) 
{
    scoped_lock l(globalLock);
    printf("Interrupted gest swapchain images, printf");
    std::cout << "Interrupted gest swapchain images" << std::endl;
    device_dispatch[GetKey(device)].GetSwapchainImagesKHR(device, swapchain, pCount, pSwapchainImages);
}
///////////////////////////////////////////////////////////////////////////////////////////
// Enumeration function

VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateInstanceLayerProperties(uint32_t *pPropertyCount,
                                                                       VkLayerProperties *pProperties)
{
    if(pPropertyCount) *pPropertyCount = 1;

    if(pProperties)
    {
        strcpy(pProperties->layerName, "VK_LAYER_SAMPLE_SampleLayer");
        strcpy(pProperties->description, "Sample layer - https://renderdoc.org/vulkan-layer-guide.html");
        pProperties->implementationVersion = 1;
        pProperties->specVersion = VK_API_VERSION_1_0;
    }

    return VK_SUCCESS;
}

VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateDeviceLayerProperties(
    VkPhysicalDevice physicalDevice, uint32_t *pPropertyCount, VkLayerProperties *pProperties)
{
    return vkBasalt_EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateInstanceExtensionProperties(
    const char *pLayerName, uint32_t *pPropertyCount, VkExtensionProperties *pProperties)
{
    if(pLayerName == NULL || strcmp(pLayerName, "VK_LAYER_SAMPLE_SampleLayer"))
    return VK_ERROR_LAYER_NOT_PRESENT;

    // don't expose any extensions
    if(pPropertyCount) *pPropertyCount = 0;
    return VK_SUCCESS;
}

VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateDeviceExtensionProperties(
                                     VkPhysicalDevice physicalDevice, const char *pLayerName,
                                     uint32_t *pPropertyCount, VkExtensionProperties *pProperties)
{
    // pass through any queries that aren't to us
    if(pLayerName == NULL || strcmp(pLayerName, "VK_LAYER_SAMPLE_SampleLayer"))
    {
        if(physicalDevice == VK_NULL_HANDLE)
          return VK_SUCCESS;

        scoped_lock l(globalLock);
        return instance_dispatch[GetKey(physicalDevice)].EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    }

    // don't expose any extensions
    if(pPropertyCount) *pPropertyCount = 0;
    return VK_SUCCESS;
}


#define GETPROCADDR(func) if(!strcmp(pName, "vk" #func)) return (PFN_vkVoidFunction)&vkBasalt_##func;
/*
Return our funktions for the funktions we want to intercept
the macro takes the name and returns our vkBasalt_##func, if the name is equal
*/
VK_LAYER_EXPORT PFN_vkVoidFunction VKAPI_CALL vkBasalt_GetDeviceProcAddr(VkDevice device, const char *pName)
{
    // device chain functions we intercept
    GETPROCADDR(GetDeviceProcAddr);
    GETPROCADDR(EnumerateDeviceLayerProperties);
    GETPROCADDR(EnumerateDeviceExtensionProperties);
    GETPROCADDR(CreateDevice);
    GETPROCADDR(DestroyDevice);
    GETPROCADDR(GetSwapchainImagesKHR);
    GETPROCADDR(EndCommandBuffer);

    {
        scoped_lock l(globalLock);
        return device_dispatch[GetKey(device)].GetDeviceProcAddr(device, pName);
    }
}

VK_LAYER_EXPORT PFN_vkVoidFunction VKAPI_CALL vkBasalt_GetInstanceProcAddr(VkInstance instance, const char *pName)
{
    // instance chain functions we intercept
    GETPROCADDR(GetInstanceProcAddr);
    GETPROCADDR(EnumerateInstanceLayerProperties);
    GETPROCADDR(EnumerateInstanceExtensionProperties);
    GETPROCADDR(CreateInstance);
    GETPROCADDR(DestroyInstance);

    // device chain functions we intercept
    GETPROCADDR(GetDeviceProcAddr);
    GETPROCADDR(EnumerateDeviceLayerProperties);
    GETPROCADDR(EnumerateDeviceExtensionProperties);
    GETPROCADDR(CreateDevice);
    GETPROCADDR(DestroyDevice);
    GETPROCADDR(GetSwapchainImagesKHR);
    GETPROCADDR(EndCommandBuffer);

    {
        scoped_lock l(globalLock);
        return instance_dispatch[GetKey(instance)].GetInstanceProcAddr(instance, pName);
    }
}
