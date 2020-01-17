#include "vulkan_include.hpp"

#include <mutex>
#include <map>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <memory>
#include <cstring>

#include "logical_device.hpp"
#include "logical_swapchain.hpp"

#include "image_view.hpp"
#include "sampler.hpp"
#include "framebuffer.hpp"
#include "descriptor_set.hpp"
#include "shader.hpp"
#include "graphics_pipeline.hpp"
#include "command_buffer.hpp"
#include "buffer.hpp"
#include "config.hpp"
#include "fake_swapchain.hpp"
#include "renderpass.hpp"
#include "format.hpp"

#include "effect.hpp"
#include "effect_fxaa.hpp"
#include "effect_cas.hpp"
#include "effect_smaa.hpp"
#include "effect_deband.hpp"
#include "effect_lut.hpp"
#include "effect_reshade.hpp"

namespace vkBasalt
{
    std::shared_ptr<Config> pConfig = nullptr;
    
    // layer book-keeping information, to store dispatch tables by key
    std::unordered_map<void *, VkLayerInstanceDispatchTable> instanceDispatchMap;
    std::unordered_map<void *, VkInstance>                   instanceMap;
    std::unordered_map<void *, LogicalDevice>                deviceMap;
    std::unordered_map<VkSwapchainKHR, LogicalSwapchain>      swapchainMap;
    
    std::mutex globalLock;
    #ifdef _GCC_
    using scoped_lock __attribute__((unused)) = std::lock_guard<std::mutex>;
    #else
    using scoped_lock = std::lock_guard<std::mutex>;
    #endif
    
    template<typename DispatchableType>
    void *GetKey(DispatchableType inst)
    {
        return *(void **)inst;
    }
    

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
        std::cout << "interrupted create instance" << std::endl;
        if(layerCreateInfo == nullptr)
        {
            // No loader instance create info
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        PFN_vkGetInstanceProcAddr gpa = layerCreateInfo->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        // move chain on for next layer
        layerCreateInfo->u.pLayerInfo = layerCreateInfo->u.pLayerInfo->pNext;

        PFN_vkCreateInstance createFunc = (PFN_vkCreateInstance)gpa(VK_NULL_HANDLE, "vkCreateInstance");
        
        VkInstanceCreateInfo modifiedCreateInfo = *pCreateInfo;
        VkApplicationInfo appInfo;
        if(modifiedCreateInfo.pApplicationInfo)
        {
            appInfo = *(modifiedCreateInfo.pApplicationInfo);
            if(appInfo.apiVersion < VK_API_VERSION_1_1)
            {
                appInfo.apiVersion = VK_API_VERSION_1_1;
            }
        }
        else
        {
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pNext = nullptr;
            appInfo.pApplicationName = nullptr;
            appInfo.applicationVersion = 0;
            appInfo.pEngineName = nullptr;
            appInfo.engineVersion = 0;
            appInfo.apiVersion = VK_API_VERSION_1_1;
        }

        modifiedCreateInfo.pApplicationInfo = &appInfo;
        VkResult ret = createFunc(&modifiedCreateInfo, pAllocator, pInstance);

        // fetch our own dispatch table for the functions we need, into the next layer
        VkLayerInstanceDispatchTable dispatchTable;
        layer_init_instance_dispatch_table(*pInstance,&dispatchTable,gpa);
        
        // store the table by key
        {
            scoped_lock l(globalLock);
            instanceDispatchMap[GetKey(*pInstance)] = dispatchTable;
            instanceMap[GetKey(*pInstance)]  = *pInstance;
            if(pConfig == nullptr)
            {
                pConfig = std::shared_ptr<Config>(new Config());
            }
        }

        return ret;
    }

    VK_LAYER_EXPORT void VKAPI_CALL vkBasalt_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);
        VkLayerInstanceDispatchTable dispatchTable = instanceDispatchMap[GetKey(instance)];
        
        dispatchTable.DestroyInstance(instance, pAllocator);
        std::cout << "afer destroy instance" << std::endl;
        
        instanceDispatchMap.erase(GetKey(instance));
        instanceMap.erase(GetKey(instance));
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

        if(layerCreateInfo == nullptr)
        {
        // No loader instance create info
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        PFN_vkGetInstanceProcAddr gipa = layerCreateInfo->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        PFN_vkGetDeviceProcAddr gdpa = layerCreateInfo->u.pLayerInfo->pfnNextGetDeviceProcAddr;
        // move chain on for next layer
        layerCreateInfo->u.pLayerInfo = layerCreateInfo->u.pLayerInfo->pNext;

        PFN_vkCreateDevice createFunc = (PFN_vkCreateDevice)gipa(VK_NULL_HANDLE, "vkCreateDevice");
        
        //Active needed Features
        
        VkDeviceCreateInfo modifiedCreateInfo = *pCreateInfo;
        std::vector<const char*> enabledExtensionNames;
        if(modifiedCreateInfo.enabledExtensionCount)
        {
            enabledExtensionNames = std::vector<const char*>(modifiedCreateInfo.ppEnabledExtensionNames, modifiedCreateInfo.ppEnabledExtensionNames + modifiedCreateInfo.enabledExtensionCount);
        }
        enabledExtensionNames.push_back("VK_KHR_swapchain_mutable_format");
        enabledExtensionNames.push_back("VK_KHR_image_format_list");
        modifiedCreateInfo.ppEnabledExtensionNames = enabledExtensionNames.data();
        modifiedCreateInfo.enabledExtensionCount = enabledExtensionNames.size();
        
        VkPhysicalDeviceFeatures deviceFeatures = {};
        if(modifiedCreateInfo.pEnabledFeatures)
        {
            deviceFeatures = *(modifiedCreateInfo.pEnabledFeatures);
        }
        deviceFeatures.shaderImageGatherExtended = VK_TRUE;
        modifiedCreateInfo.pEnabledFeatures = &deviceFeatures;

        VkResult ret = createFunc(physicalDevice, &modifiedCreateInfo, pAllocator, pDevice);
        
        // fetch our own dispatch table for the functions we need, into the next layer
        VkLayerDispatchTable dispatchTable;
        layer_init_device_dispatch_table(*pDevice,&dispatchTable,gdpa);
        
        LogicalDevice logicalDevice;
        logicalDevice.vkd = dispatchTable;
        logicalDevice.vki = instanceDispatchMap[GetKey(physicalDevice)];
        logicalDevice.device = *pDevice;
        logicalDevice.physicalDevice = physicalDevice;
        logicalDevice.instance = instanceMap[GetKey(physicalDevice)];
        logicalDevice.queue = VK_NULL_HANDLE;
        logicalDevice.queueFamilyIndex = 0;
        logicalDevice.commandPool = VK_NULL_HANDLE;
        
        // store the table by key
        {
            scoped_lock l(globalLock);
            deviceMap[GetKey(*pDevice)] = logicalDevice;
        }

        return ret;
    }

    VK_LAYER_EXPORT void VKAPI_CALL vkBasalt_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);
        LogicalDevice& logicalDevice = deviceMap[GetKey(device)];
        if(logicalDevice.commandPool != VK_NULL_HANDLE)
        {
            std::cout << "DestroyCommandPool" << std::endl;
            logicalDevice.vkd.DestroyCommandPool(device, logicalDevice.commandPool, pAllocator);
        }
        
        logicalDevice.vkd.DestroyDevice(device,pAllocator);
        
        deviceMap.erase(GetKey(device));
        std::cout << "after  Destroy Device" << std::endl;
    }

    VKAPI_ATTR void VKAPI_CALL vkBasalt_GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue *pQueue)
    {
        scoped_lock l(globalLock);
        LogicalDevice& logicalDevice = deviceMap[GetKey(device)];
        
        logicalDevice.vkd.GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
        
        if(logicalDevice.queue != VK_NULL_HANDLE)
        {
            return;//we allready have a queue
        }
        
        //Save the first graphic capable queue in our deviceMap
        uint32_t count;
        VkBool32 graphicsCapable = VK_FALSE;
        //TODO also check if the queue is present capable
        logicalDevice.vki.GetPhysicalDeviceQueueFamilyProperties(logicalDevice.physicalDevice, &count, nullptr);
        
        std::vector<VkQueueFamilyProperties> queueProperties(count);
        
        if(count > 0)
        {
            logicalDevice.vki.GetPhysicalDeviceQueueFamilyProperties(logicalDevice.physicalDevice, &count, queueProperties.data());
            if((queueProperties[queueFamilyIndex].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0)
            {
                graphicsCapable = VK_TRUE;
            }
        }
        else
        {
            //TODO
            graphicsCapable = VK_TRUE;
        }
        
        if(graphicsCapable)
        {   
            VkCommandPoolCreateInfo commandPoolCreateInfo;
            commandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
            commandPoolCreateInfo.pNext = nullptr;
            commandPoolCreateInfo.flags = 0;
            commandPoolCreateInfo.queueFamilyIndex = queueFamilyIndex;
            
            std::cout << "found graphic capable queue" << std::endl;
            logicalDevice.vkd.CreateCommandPool(device, &commandPoolCreateInfo, nullptr, &logicalDevice.commandPool);
            logicalDevice.queue = *pQueue;
            logicalDevice.queueFamilyIndex = queueFamilyIndex;
        }
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
    {
        VkSwapchainCreateInfoKHR modifiedCreateInfo = *pCreateInfo;
        modifiedCreateInfo.imageUsage |= VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;//we want to use the swapchain images as output of the graphics pipeline
        modifiedCreateInfo.flags |= VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR;
        //TODO what if the application already uses multiple formats for the swapchain?
        
        VkFormat format = modifiedCreateInfo.imageFormat;
        
        VkFormat srgbFormat = isSRGB(format) ? format : convertToSRGB(format);
        VkFormat unormFormat = isSRGB(format) ? convertToUNORM(format) : format;
        std::cout << srgbFormat << " " << unormFormat << std::endl;
        
        VkFormat formats[] = {unormFormat, srgbFormat};
        
        VkImageFormatListCreateInfoKHR imageFormatListCreateInfo;
        imageFormatListCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR;
        imageFormatListCreateInfo.pNext = modifiedCreateInfo.pNext;
        imageFormatListCreateInfo.viewFormatCount = (srgbFormat == unormFormat) ? 1 : 2;
        imageFormatListCreateInfo.pViewFormats = formats;
        
        modifiedCreateInfo.pNext = &imageFormatListCreateInfo;
        
        scoped_lock l(globalLock);
        
        
        LogicalDevice& logicalDevice = deviceMap[GetKey(device)];
        std::cout << "format " << modifiedCreateInfo.imageFormat << std::endl;
        LogicalSwapchain logicalSwapchain;
        logicalSwapchain.logicalDevice = logicalDevice;
        logicalSwapchain.swapchainCreateInfo = *pCreateInfo;
        logicalSwapchain.imageExtent = modifiedCreateInfo.imageExtent;
        logicalSwapchain.format = modifiedCreateInfo.imageFormat;
        logicalSwapchain.imageCount = 0;
        
        VkResult result = logicalDevice.vkd.CreateSwapchainKHR(device, &modifiedCreateInfo, pAllocator, pSwapchain);
        
        swapchainMap[*pSwapchain] = logicalSwapchain;
        
        std::cout << "Interrupted create swapchain" << std::endl;
        
        return result;
    }       

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_GetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pCount, VkImage *pSwapchainImages) 
    {
        scoped_lock l(globalLock);
        std::cout << "Interrupted get swapchain images " << *pCount << std::endl;
        
        LogicalDevice& logicalDevice = deviceMap[GetKey(device)];
        
        if(pSwapchainImages == nullptr)
        {
            return logicalDevice.vkd.GetSwapchainImagesKHR(device, swapchain, pCount, pSwapchainImages);
        }
        
        LogicalSwapchain& logicalSwapchain = swapchainMap[swapchain];
        logicalSwapchain.imageCount = *pCount;
        logicalSwapchain.images.reserve(*pCount);
        logicalSwapchain.commandBuffers.reserve(*pCount);
        
        std::string effectOption = pConfig->getOption("effects", "cas");
        std::vector<std::string> effectStrings;
        while(effectOption!=std::string(""))
        {
            size_t colon = effectOption.find(":");
            effectStrings.push_back(effectOption.substr(0,colon));
            if(colon==std::string::npos)
            {
                effectOption = std::string("");
            }
            else
            {
                effectOption = effectOption.substr(colon+1);
            }
        }
        
        logicalSwapchain.fakeImages = createFakeSwapchainImages(logicalDevice,
                                                                logicalSwapchain.swapchainCreateInfo,
                                                                *pCount * effectStrings.size(),
                                                                logicalSwapchain.fakeImageMemory);
        std::cout << "after createFakeSwapchainImages " << std::endl;
        
        
        VkResult result = logicalDevice.vkd.GetSwapchainImagesKHR(device, swapchain, pCount, pSwapchainImages);
        for(unsigned int i=0;i<*pCount;i++)
        {
            logicalSwapchain.images.push_back(pSwapchainImages[i]);
            pSwapchainImages[i] = logicalSwapchain.fakeImages[i];
        }
        
        std::cout << logicalSwapchain.images.size() << "swapchain images" << std::endl;
        
        
        
        for(uint32_t i=0;i<effectStrings.size();i++)
        {
            std::cout << "current effectString " << effectStrings[i] << std::endl;
            std::vector<VkImage> firstImages(logicalSwapchain.fakeImages.begin() + logicalSwapchain.imageCount * i,
                                             logicalSwapchain.fakeImages.begin() + logicalSwapchain.imageCount * (i+1));
            std::cout << firstImages.size() << " images in firstImages" << std::endl;
            std::vector<VkImage> secondImages;
            if(i == effectStrings.size() - 1)
            {
                secondImages = logicalSwapchain.images;
                std::cout << "using swapchain images as second images" << std::endl;
            }
            else
            {
                secondImages = std::vector<VkImage>(logicalSwapchain.fakeImages.begin() + logicalSwapchain.imageCount * (i+1),
                                                    logicalSwapchain.fakeImages.begin() + logicalSwapchain.imageCount * (i+2));
                std::cout << "not using swapchain images as second images" << std::endl;
            }
            std::cout << secondImages.size() << " images in secondImages" << std::endl;
            if(effectStrings[i] == std::string("fxaa"))
            {
                logicalSwapchain.effects.push_back(std::shared_ptr<Effect>(new FxaaEffect(logicalDevice,
                                                             convertToSRGB(logicalSwapchain.format),
                                                             logicalSwapchain.imageExtent,
                                                             firstImages,
                                                             secondImages,
                                                             pConfig)));
                std::cout << "after creating FxaaEffect " << std::endl;
            }
            else if(effectStrings[i] == std::string("cas"))
            {
                logicalSwapchain.effects.push_back(std::shared_ptr<Effect>(new CasEffect(logicalDevice,
                                                             convertToUNORM(logicalSwapchain.format),
                                                             logicalSwapchain.imageExtent,
                                                             firstImages,
                                                             secondImages,
                                                             pConfig)));
                std::cout << "after creating CasEffect " << std::endl;
            }
            else if(effectStrings[i] == std::string("deband"))
            {
                logicalSwapchain.effects.push_back(std::shared_ptr<Effect>(new DebandEffect(logicalDevice,
                                                             convertToUNORM(logicalSwapchain.format),
                                                             logicalSwapchain.imageExtent,
                                                             firstImages,
                                                             secondImages,
                                                             pConfig)));
                std::cout << "after creating DebandEffect " << std::endl;
            }
            else if(effectStrings[i] == std::string("smaa"))
            {
                logicalSwapchain.effects.push_back(std::shared_ptr<Effect>(new SmaaEffect(logicalDevice.physicalDevice,
                                                             logicalDevice.vki,
                                                             device,
                                                             logicalDevice.vkd,
                                                             convertToUNORM(logicalSwapchain.format),
                                                             logicalSwapchain.imageExtent,
                                                             firstImages,
                                                             secondImages,
                                                             pConfig,
                                                             logicalDevice.queue,
                                                             logicalDevice.commandPool)));
            }
            else if(effectStrings[i] == std::string("lut"))
            {
                logicalSwapchain.effects.push_back(std::shared_ptr<Effect>(new LutEffect(logicalDevice,
                                                             convertToUNORM(logicalSwapchain.format),
                                                             logicalSwapchain.imageExtent,
                                                             firstImages,
                                                             secondImages,
                                                             pConfig)));
            }
            else
            {
                logicalSwapchain.effects.push_back(std::shared_ptr<Effect>(new ReshadeEffect(logicalDevice.physicalDevice,
                                                             logicalDevice.vki,
                                                             device,
                                                             logicalDevice.vkd,
                                                             logicalSwapchain.format,
                                                             logicalSwapchain.imageExtent,
                                                             firstImages,
                                                             secondImages,
                                                             pConfig,
                                                             logicalDevice.queue,
                                                             logicalDevice.commandPool,
                                                             effectStrings[i])));
            }
        }
        std::cout << "effect string count: " << effectStrings.size() << std::endl;
        std::cout << "effect count: " << logicalSwapchain.effects.size() << std::endl;
        
        logicalSwapchain.commandBuffers = allocateCommandBuffer(device, logicalDevice.vkd, logicalDevice.commandPool, logicalSwapchain.imageCount);
        std::cout << "after allocateCommandBuffer " << std::endl;
        
        writeCommandBuffers(device, logicalDevice.vkd, logicalSwapchain.effects,  logicalSwapchain.commandBuffers);
        std::cout << "after write CommandBuffer" << std::endl;
        
        logicalSwapchain.semaphores = createSemaphores(device, logicalDevice.vkd, logicalSwapchain.imageCount);
        std::cout << "after create semaphores" << std::endl;
        for(unsigned int i = 0; i < logicalSwapchain.imageCount; i++)
        {
            std::cout << i << "writen commandbuffer" << logicalSwapchain.commandBuffers[i] << std::endl;
        }
        std::cout << "after getswapchainimages " << std::endl;
        
        return result;
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_QueuePresentKHR(VkQueue queue,const VkPresentInfoKHR* pPresentInfo)
    {
        scoped_lock l(globalLock);
        
        LogicalDevice& logicalDevice = deviceMap[GetKey(queue)];
        
        std::vector<VkSemaphore> presentSemaphores;
        presentSemaphores.reserve(pPresentInfo->swapchainCount);

        std::vector<VkPipelineStageFlags> waitStages;

        for(unsigned int i = 0; i < (*pPresentInfo).swapchainCount; i++)
        {
            uint32_t index = (*pPresentInfo).pImageIndices[i];
            VkSwapchainKHR swapchain = (*pPresentInfo).pSwapchains[i];
            LogicalSwapchain& logicalSwapchain = swapchainMap[swapchain];
            
            for(auto& effect: logicalSwapchain.effects)
            {
                effect->updateEffect();
            }

            waitStages.resize(pPresentInfo->waitSemaphoreCount, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);

            VkSubmitInfo submitInfo;
            submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
            submitInfo.pNext = nullptr;
            submitInfo.waitSemaphoreCount = 0;
            submitInfo.pWaitSemaphores = nullptr;
            submitInfo.pWaitDstStageMask = nullptr;
            submitInfo.commandBufferCount = 1;
            submitInfo.pCommandBuffers = &(logicalSwapchain.commandBuffers[index]);
            submitInfo.signalSemaphoreCount = 1;
            submitInfo.pSignalSemaphores = &(logicalSwapchain.semaphores[index]);

            presentSemaphores.push_back(logicalSwapchain.semaphores[index]);

            if (i == 0)
            {
                submitInfo.waitSemaphoreCount = pPresentInfo->waitSemaphoreCount;
                submitInfo.pWaitSemaphores = pPresentInfo->pWaitSemaphores;
                submitInfo.pWaitDstStageMask = waitStages.data();
            }

            VkResult vr = logicalDevice.vkd.QueueSubmit(logicalDevice.queue, 1, &submitInfo, VK_NULL_HANDLE);

            if (vr != VK_SUCCESS)
            {
                return vr;
            }
        }
        VkPresentInfoKHR presentInfo = *pPresentInfo;
        presentInfo.waitSemaphoreCount = presentSemaphores.size();
        presentInfo.pWaitSemaphores = presentSemaphores.data();

        return logicalDevice.vkd.QueuePresentKHR(queue, &presentInfo);
    }

    VKAPI_ATTR void VKAPI_CALL vkBasalt_DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain,const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);
        //we need to delete the infos of the oldswapchain 
        
        std::cout << "destroying swapchain " << swapchain << std::endl;
        swapchainMap[swapchain].destroy();
        LogicalDevice& logicalDevice = deviceMap[GetKey(device)];
        
        logicalDevice.vkd.DestroySwapchainKHR(device, swapchain,pAllocator);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////
    // Enumeration function

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateInstanceLayerProperties(uint32_t *pPropertyCount,
                                                                           VkLayerProperties *pProperties)
    {
        if(pPropertyCount) *pPropertyCount = 1;

        if(pProperties)
        {
            #ifdef __x86_64__
            std::strcpy(pProperties->layerName, "VK_LAYER_VKBASALT_PostProcess64");
            #else
            std::strcpy(pProperties->layerName, "VK_LAYER_VKBASALT_PostProcess32");
            #endif
            std::strcpy(pProperties->description, "a post processing layer");
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
        if(pLayerName == NULL || (std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess32") && std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess64")))
        {
            return VK_ERROR_LAYER_NOT_PRESENT;
        }

        // don't expose any extensions
        if(pPropertyCount)
        {
            *pPropertyCount = 0;
        }
        return VK_SUCCESS;
    }

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateDeviceExtensionProperties(
                                         VkPhysicalDevice physicalDevice, const char *pLayerName,
                                         uint32_t *pPropertyCount, VkExtensionProperties *pProperties)
    {
        // pass through any queries that aren't to us
        if(pLayerName == NULL || (std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess32") && std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess64")))
        {
            if(physicalDevice == VK_NULL_HANDLE)
            {
                return VK_SUCCESS;
            }

            scoped_lock l(globalLock);
            return instanceDispatchMap[GetKey(physicalDevice)].EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
        }

        // don't expose any extensions
        if(pPropertyCount) 
        {
            *pPropertyCount = 0;
        }
        return VK_SUCCESS;
    }
}

extern "C"{// these are the entry points for the layer, so they need to be c-linkeable

#define GETPROCADDR(func) if(!std::strcmp(pName, "vk" #func)) return (PFN_vkVoidFunction)&vkBasalt::vkBasalt_##func;
/*
Return our funktions for the funktions we want to intercept
the macro takes the name and returns our vkBasalt_##func, if the name is equal
*/
VK_LAYER_EXPORT PFN_vkVoidFunction VKAPI_CALL vkBasalt_GetDeviceProcAddr(VkDevice device, const char *pName)
{
    // device chain functions we intercept
    if(!std::strcmp(pName, "vkGetDeviceProcAddr")) return (PFN_vkVoidFunction)&vkBasalt_GetDeviceProcAddr;
    GETPROCADDR(EnumerateDeviceLayerProperties);
    GETPROCADDR(EnumerateDeviceExtensionProperties);
    GETPROCADDR(CreateDevice);
    GETPROCADDR(DestroyDevice);
    GETPROCADDR(GetDeviceQueue);
    GETPROCADDR(CreateSwapchainKHR);
    GETPROCADDR(GetSwapchainImagesKHR);
    GETPROCADDR(QueuePresentKHR);
    GETPROCADDR(DestroySwapchainKHR);
    {
        vkBasalt::scoped_lock l(vkBasalt::globalLock);
        return vkBasalt::deviceMap[vkBasalt::GetKey(device)].vkd.GetDeviceProcAddr(device, pName);
    }
}

VK_LAYER_EXPORT PFN_vkVoidFunction VKAPI_CALL vkBasalt_GetInstanceProcAddr(VkInstance instance, const char *pName)
{
    // instance chain functions we intercept
    if(!std::strcmp(pName, "vkGetInstanceProcAddr")) return (PFN_vkVoidFunction)&vkBasalt_GetInstanceProcAddr;
    GETPROCADDR(EnumerateInstanceLayerProperties);
    GETPROCADDR(EnumerateInstanceExtensionProperties);
    GETPROCADDR(CreateInstance);
    GETPROCADDR(DestroyInstance);

    // device chain functions we intercept
    if(!std::strcmp(pName, "vkGetDeviceProcAddr")) return (PFN_vkVoidFunction)&vkBasalt_GetDeviceProcAddr;
    GETPROCADDR(EnumerateDeviceLayerProperties);
    GETPROCADDR(EnumerateDeviceExtensionProperties);
    GETPROCADDR(CreateDevice);
    GETPROCADDR(DestroyDevice);
    GETPROCADDR(GetDeviceQueue);
    GETPROCADDR(CreateSwapchainKHR);
    GETPROCADDR(GetSwapchainImagesKHR);
    GETPROCADDR(QueuePresentKHR);
    GETPROCADDR(DestroySwapchainKHR);
    {
        vkBasalt::scoped_lock l(vkBasalt::globalLock);
        return vkBasalt::instanceDispatchMap[vkBasalt::GetKey(instance)].GetInstanceProcAddr(instance, pName);
    }
}

}//extern "C"
