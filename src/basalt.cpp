#include "vulkan_include.hpp"

#include <mutex>
#include <map>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <memory>
#include <cstring>

#include "util.hpp"
#include "keyboard_input.hpp"

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
#include "logger.hpp"

#include "effect.hpp"
#include "effect_fxaa.hpp"
#include "effect_cas.hpp"
#include "effect_smaa.hpp"
#include "effect_deband.hpp"
#include "effect_lut.hpp"
#include "effect_reshade.hpp"
#include "effect_transfer.hpp"

namespace vkBasalt
{
    std::shared_ptr<Config> pConfig = nullptr;

    Logger Logger::s_instance;

    // layer book-keeping information, to store dispatch tables by key
    std::unordered_map<void*, VkLayerInstanceDispatchTable>               instanceDispatchMap;
    std::unordered_map<void*, VkInstance>                                 instanceMap;
    std::unordered_map<void*, std::shared_ptr<LogicalDevice>>             deviceMap;
    std::unordered_map<VkSwapchainKHR, std::shared_ptr<LogicalSwapchain>> swapchainMap;

    std::mutex globalLock;
#ifdef _GCC_
    using scoped_lock __attribute__((unused)) = std::lock_guard<std::mutex>;
#else
    using scoped_lock = std::lock_guard<std::mutex>;
#endif

    template<typename DispatchableType>
    void* GetKey(DispatchableType inst)
    {
        return *(void**) inst;
    }

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_CreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                                const VkAllocationCallbacks* pAllocator,
                                                                VkInstance*                  pInstance)
    {
        VkLayerInstanceCreateInfo* layerCreateInfo = (VkLayerInstanceCreateInfo*) pCreateInfo->pNext;

        // step through the chain of pNext until we get to the link info
        while (layerCreateInfo
               && (layerCreateInfo->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO || layerCreateInfo->function != VK_LAYER_LINK_INFO))
        {
            layerCreateInfo = (VkLayerInstanceCreateInfo*) layerCreateInfo->pNext;
        }

        Logger::trace("vkCreateInstance");

        if (layerCreateInfo == nullptr)
        {
            // No loader instance create info
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        PFN_vkGetInstanceProcAddr gpa = layerCreateInfo->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        // move chain on for next layer
        layerCreateInfo->u.pLayerInfo = layerCreateInfo->u.pLayerInfo->pNext;

        PFN_vkCreateInstance createFunc = (PFN_vkCreateInstance) gpa(VK_NULL_HANDLE, "vkCreateInstance");

        VkInstanceCreateInfo modifiedCreateInfo = *pCreateInfo;
        VkApplicationInfo    appInfo;
        if (modifiedCreateInfo.pApplicationInfo)
        {
            appInfo = *(modifiedCreateInfo.pApplicationInfo);
            if (appInfo.apiVersion < VK_API_VERSION_1_1)
            {
                appInfo.apiVersion = VK_API_VERSION_1_1;
            }
        }
        else
        {
            appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pNext              = nullptr;
            appInfo.pApplicationName   = nullptr;
            appInfo.applicationVersion = 0;
            appInfo.pEngineName        = nullptr;
            appInfo.engineVersion      = 0;
            appInfo.apiVersion         = VK_API_VERSION_1_1;
        }

        modifiedCreateInfo.pApplicationInfo = &appInfo;
        VkResult ret                        = createFunc(&modifiedCreateInfo, pAllocator, pInstance);

        // fetch our own dispatch table for the functions we need, into the next layer
        VkLayerInstanceDispatchTable dispatchTable;
        layer_init_instance_dispatch_table(*pInstance, &dispatchTable, gpa);

        // store the table by key
        {
            scoped_lock l(globalLock);
            instanceDispatchMap[GetKey(*pInstance)] = dispatchTable;
            instanceMap[GetKey(*pInstance)]         = *pInstance;
        }

        return ret;
    }

    VK_LAYER_EXPORT void VKAPI_CALL vkBasalt_DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);

        Logger::trace("vkDestroyInstance");

        VkLayerInstanceDispatchTable dispatchTable = instanceDispatchMap[GetKey(instance)];

        dispatchTable.DestroyInstance(instance, pAllocator);

        instanceDispatchMap.erase(GetKey(instance));
        instanceMap.erase(GetKey(instance));
    }

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_CreateDevice(VkPhysicalDevice             physicalDevice,
                                                              const VkDeviceCreateInfo*    pCreateInfo,
                                                              const VkAllocationCallbacks* pAllocator,
                                                              VkDevice*                    pDevice)
    {
        Logger::trace("vkCreateDevice");
        VkLayerDeviceCreateInfo* layerCreateInfo = (VkLayerDeviceCreateInfo*) pCreateInfo->pNext;

        // step through the chain of pNext until we get to the link info
        while (layerCreateInfo
               && (layerCreateInfo->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO || layerCreateInfo->function != VK_LAYER_LINK_INFO))
        {
            layerCreateInfo = (VkLayerDeviceCreateInfo*) layerCreateInfo->pNext;
        }

        if (layerCreateInfo == nullptr)
        {
            // No loader instance create info
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        PFN_vkGetInstanceProcAddr gipa = layerCreateInfo->u.pLayerInfo->pfnNextGetInstanceProcAddr;
        PFN_vkGetDeviceProcAddr   gdpa = layerCreateInfo->u.pLayerInfo->pfnNextGetDeviceProcAddr;
        // move chain on for next layer
        layerCreateInfo->u.pLayerInfo = layerCreateInfo->u.pLayerInfo->pNext;

        PFN_vkCreateDevice createFunc = (PFN_vkCreateDevice) gipa(VK_NULL_HANDLE, "vkCreateDevice");

        // check and activate extentions
        uint32_t extensionCount = 0;

        instanceDispatchMap[GetKey(physicalDevice)].EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensionProperties(extensionCount);
        instanceDispatchMap[GetKey(physicalDevice)].EnumerateDeviceExtensionProperties(
            physicalDevice, nullptr, &extensionCount, extensionProperties.data());

        bool supportsMutableFormat = false;
        for (VkExtensionProperties properties : extensionProperties)
        {
            if (properties.extensionName == std::string("VK_KHR_swapchain_mutable_format"))
            {
                Logger::debug("device supports VK_KHR_swapchain_mutable_format");
                supportsMutableFormat = true;
                break;
            }
        }

        if (pConfig->getOption("mutableFormat") == "on")
        {
            supportsMutableFormat = true;
        }
        if (pConfig->getOption("mutableFormat") == "off")
        {
            supportsMutableFormat = false;
        }

        VkDeviceCreateInfo       modifiedCreateInfo = *pCreateInfo;
        std::vector<const char*> enabledExtensionNames;
        if (modifiedCreateInfo.enabledExtensionCount)
        {
            enabledExtensionNames = std::vector<const char*>(modifiedCreateInfo.ppEnabledExtensionNames,
                                                             modifiedCreateInfo.ppEnabledExtensionNames + modifiedCreateInfo.enabledExtensionCount);
        }

        if (supportsMutableFormat)
        {
            Logger::debug("activating mutable_format");
            addUniqueCString(enabledExtensionNames, "VK_KHR_swapchain_mutable_format");
        }
        addUniqueCString(enabledExtensionNames, "VK_KHR_image_format_list");
        modifiedCreateInfo.ppEnabledExtensionNames = enabledExtensionNames.data();
        modifiedCreateInfo.enabledExtensionCount   = enabledExtensionNames.size();

        // Active needed Features
        VkPhysicalDeviceFeatures deviceFeatures = {};
        if (modifiedCreateInfo.pEnabledFeatures)
        {
            deviceFeatures = *(modifiedCreateInfo.pEnabledFeatures);
        }
        deviceFeatures.shaderImageGatherExtended = VK_TRUE;
        modifiedCreateInfo.pEnabledFeatures      = &deviceFeatures;

        VkResult ret = createFunc(physicalDevice, &modifiedCreateInfo, pAllocator, pDevice);

        // fetch our own dispatch table for the functions we need, into the next layer
        VkLayerDispatchTable dispatchTable;
        layer_init_device_dispatch_table(*pDevice, &dispatchTable, gdpa);

        std::shared_ptr<LogicalDevice> pLogicalDevice(new LogicalDevice());
        pLogicalDevice->vkd                   = dispatchTable;
        pLogicalDevice->vki                   = instanceDispatchMap[GetKey(physicalDevice)];
        pLogicalDevice->device                = *pDevice;
        pLogicalDevice->physicalDevice        = physicalDevice;
        pLogicalDevice->instance              = instanceMap[GetKey(physicalDevice)];
        pLogicalDevice->queue                 = VK_NULL_HANDLE;
        pLogicalDevice->queueFamilyIndex      = 0;
        pLogicalDevice->commandPool           = VK_NULL_HANDLE;
        pLogicalDevice->supportsMutableFormat = supportsMutableFormat;

        // store the table by key
        {
            scoped_lock l(globalLock);
            deviceMap[GetKey(*pDevice)] = pLogicalDevice;
        }

        return ret;
    }

    VK_LAYER_EXPORT void VKAPI_CALL vkBasalt_DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);

        Logger::trace("vkDestroyDevice");

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];
        if (pLogicalDevice->commandPool != VK_NULL_HANDLE)
        {
            Logger::debug("DestroyCommandPool");
            pLogicalDevice->vkd.DestroyCommandPool(device, pLogicalDevice->commandPool, pAllocator);
        }

        pLogicalDevice->vkd.DestroyDevice(device, pAllocator);

        deviceMap.erase(GetKey(device));
    }

    static void saveDeviceQueue(std::shared_ptr<LogicalDevice> pLogicalDevice, uint32_t queueFamilyIndex, VkQueue* pQueue)
    {
        if (pLogicalDevice->queue != VK_NULL_HANDLE)
        {
            return; // we allready have a queue
        }

        // Save the first graphic capable queue in our deviceMap
        uint32_t count;
        VkBool32 graphicsCapable = VK_FALSE;
        // TODO also check if the queue is present capable
        pLogicalDevice->vki.GetPhysicalDeviceQueueFamilyProperties(pLogicalDevice->physicalDevice, &count, nullptr);

        std::vector<VkQueueFamilyProperties> queueProperties(count);

        if (count > 0)
        {
            pLogicalDevice->vki.GetPhysicalDeviceQueueFamilyProperties(pLogicalDevice->physicalDevice, &count, queueProperties.data());
            if ((queueProperties[queueFamilyIndex].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0)
            {
                graphicsCapable = VK_TRUE;
            }
        }
        else
        {
            // TODO
            graphicsCapable = VK_TRUE;
        }

        if (graphicsCapable)
        {
            VkCommandPoolCreateInfo commandPoolCreateInfo;
            commandPoolCreateInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
            commandPoolCreateInfo.pNext            = nullptr;
            commandPoolCreateInfo.flags            = 0;
            commandPoolCreateInfo.queueFamilyIndex = queueFamilyIndex;

            Logger::debug("found graphic capable queue");
            pLogicalDevice->vkd.CreateCommandPool(pLogicalDevice->device, &commandPoolCreateInfo, nullptr, &pLogicalDevice->commandPool);
            pLogicalDevice->queue            = *pQueue;
            pLogicalDevice->queueFamilyIndex = queueFamilyIndex;
        }
    }

    VKAPI_ATTR void VKAPI_CALL vkBasalt_GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue)
    {
        scoped_lock l(globalLock);

        Logger::trace("vkGetDeviceQueue2");

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        pLogicalDevice->vkd.GetDeviceQueue2(device, pQueueInfo, pQueue);

        saveDeviceQueue(pLogicalDevice, pQueueInfo->queueFamilyIndex, pQueue);
    }

    VKAPI_ATTR void VKAPI_CALL vkBasalt_GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
    {
        scoped_lock l(globalLock);

        Logger::trace("vkGetDeviceQueue");

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        pLogicalDevice->vkd.GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

        saveDeviceQueue(pLogicalDevice, queueFamilyIndex, pQueue);
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_CreateSwapchainKHR(VkDevice                        device,
                                                               const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                               const VkAllocationCallbacks*    pAllocator,
                                                               VkSwapchainKHR*                 pSwapchain)
    {
        scoped_lock l(globalLock);

        Logger::trace("vkCreateSwapchainKHR");

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        VkSwapchainCreateInfoKHR modifiedCreateInfo = *pCreateInfo;

        VkFormat format = modifiedCreateInfo.imageFormat;

        VkFormat srgbFormat  = isSRGB(format) ? format : convertToSRGB(format);
        VkFormat unormFormat = isSRGB(format) ? convertToUNORM(format) : format;
        Logger::debug(std::to_string(srgbFormat) + " " + std::to_string(unormFormat));

        VkFormat formats[] = {unormFormat, srgbFormat};

        VkImageFormatListCreateInfoKHR imageFormatListCreateInfo;
        if (pLogicalDevice->supportsMutableFormat)
        {
            modifiedCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT
                                            | VK_IMAGE_USAGE_SAMPLED_BIT; // we want to use the swapchain images as output of the graphics pipeline
            modifiedCreateInfo.flags |= VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR;
            // TODO what if the application already uses multiple formats for the swapchain?

            imageFormatListCreateInfo.sType           = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR;
            imageFormatListCreateInfo.pNext           = modifiedCreateInfo.pNext;
            imageFormatListCreateInfo.viewFormatCount = (srgbFormat == unormFormat) ? 1 : 2;
            imageFormatListCreateInfo.pViewFormats    = formats;

            modifiedCreateInfo.pNext = &imageFormatListCreateInfo;
        }
        else
        {
            modifiedCreateInfo.imageUsage = VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        }

        Logger::debug("format " + std::to_string(modifiedCreateInfo.imageFormat));
        std::shared_ptr<LogicalSwapchain> pLogicalSwapchain(new LogicalSwapchain());
        pLogicalSwapchain->pLogicalDevice      = pLogicalDevice;
        pLogicalSwapchain->swapchainCreateInfo = *pCreateInfo;
        pLogicalSwapchain->imageExtent         = modifiedCreateInfo.imageExtent;
        pLogicalSwapchain->format              = modifiedCreateInfo.imageFormat;
        pLogicalSwapchain->imageCount          = 0;

        VkResult result = pLogicalDevice->vkd.CreateSwapchainKHR(device, &modifiedCreateInfo, pAllocator, pSwapchain);

        swapchainMap[*pSwapchain] = pLogicalSwapchain;

        return result;
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_GetSwapchainImagesKHR(VkDevice       device,
                                                                  VkSwapchainKHR swapchain,
                                                                  uint32_t*      pCount,
                                                                  VkImage*       pSwapchainImages)
    {
        scoped_lock l(globalLock);
        Logger::trace("vkGetSwapchainImagesKHR " + std::to_string(*pCount));

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        if (pSwapchainImages == nullptr)
        {
            return pLogicalDevice->vkd.GetSwapchainImagesKHR(device, swapchain, pCount, pSwapchainImages);
        }

        std::shared_ptr<LogicalSwapchain> pLogicalSwapchain = swapchainMap[swapchain];

        // If the images got already requested once, return them again instead of creating new images
        if (pLogicalSwapchain->fakeImages.size())
        {
            std::memcpy(pSwapchainImages, pLogicalSwapchain->fakeImages.data(), sizeof(VkImage) * (*pCount));
            return VK_SUCCESS;
        }

        pLogicalSwapchain->imageCount = *pCount;
        pLogicalSwapchain->images.reserve(*pCount);
        pLogicalSwapchain->commandBuffers.reserve(*pCount);

        std::string effectOption = pConfig->getOption("effects", "cas");

        std::vector<std::string> effectStrings;
        while (effectOption != std::string(""))
        {
            size_t colon = effectOption.find(":");
            effectStrings.push_back(effectOption.substr(0, colon));
            if (colon == std::string::npos)
            {
                effectOption = std::string("");
            }
            else
            {
                effectOption = effectOption.substr(colon + 1);
            }
        }

        pLogicalSwapchain->fakeImages = createFakeSwapchainImages(
            pLogicalDevice,
            pLogicalSwapchain->swapchainCreateInfo,
            *pCount
                * (effectStrings.size()
                   + !pLogicalDevice->supportsMutableFormat), // create 1 more set of images when we can't use the swapchain it self
            pLogicalSwapchain->fakeImageMemory);
        Logger::debug("created fake swapchain images");

        VkResult result = pLogicalDevice->vkd.GetSwapchainImagesKHR(device, swapchain, pCount, pSwapchainImages);
        for (unsigned int i = 0; i < *pCount; i++)
        {
            pLogicalSwapchain->images.push_back(pSwapchainImages[i]);
            pSwapchainImages[i] = pLogicalSwapchain->fakeImages[i];
        }

        for (uint32_t i = 0; i < effectStrings.size(); i++)
        {
            Logger::debug("current effectString " + effectStrings[i]);
            std::vector<VkImage> firstImages(pLogicalSwapchain->fakeImages.begin() + pLogicalSwapchain->imageCount * i,
                                             pLogicalSwapchain->fakeImages.begin() + pLogicalSwapchain->imageCount * (i + 1));
            Logger::debug(std::to_string(firstImages.size()) + " images in firstImages");
            std::vector<VkImage> secondImages;
            if (i == effectStrings.size() - 1)
            {
                secondImages = pLogicalDevice->supportsMutableFormat
                                   ? pLogicalSwapchain->images
                                   : std::vector<VkImage>(pLogicalSwapchain->fakeImages.end() - pLogicalSwapchain->imageCount,
                                                          pLogicalSwapchain->fakeImages.end());
                Logger::debug("using swapchain images as second images");
            }
            else
            {
                secondImages = std::vector<VkImage>(pLogicalSwapchain->fakeImages.begin() + pLogicalSwapchain->imageCount * (i + 1),
                                                    pLogicalSwapchain->fakeImages.begin() + pLogicalSwapchain->imageCount * (i + 2));
                Logger::debug("not using swapchain images as second images");
            }
            Logger::debug(std::to_string(secondImages.size()) + " images in secondImages");
            if (effectStrings[i] == std::string("fxaa"))
            {
                pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new FxaaEffect(
                    pLogicalDevice, convertToSRGB(pLogicalSwapchain->format), pLogicalSwapchain->imageExtent, firstImages, secondImages, pConfig)));
                Logger::debug("created FxaaEffect");
            }
            else if (effectStrings[i] == std::string("cas"))
            {
                pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new CasEffect(
                    pLogicalDevice, convertToUNORM(pLogicalSwapchain->format), pLogicalSwapchain->imageExtent, firstImages, secondImages, pConfig)));
                Logger::debug("created CasEffect");
            }
            else if (effectStrings[i] == std::string("deband"))
            {
                pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new DebandEffect(
                    pLogicalDevice, convertToUNORM(pLogicalSwapchain->format), pLogicalSwapchain->imageExtent, firstImages, secondImages, pConfig)));
                Logger::debug("created DebandEffect");
            }
            else if (effectStrings[i] == std::string("smaa"))
            {
                pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new SmaaEffect(
                    pLogicalDevice, convertToUNORM(pLogicalSwapchain->format), pLogicalSwapchain->imageExtent, firstImages, secondImages, pConfig)));
                Logger::debug("created SmaaEffect");
            }
            else if (effectStrings[i] == std::string("lut"))
            {
                pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new LutEffect(
                    pLogicalDevice, convertToUNORM(pLogicalSwapchain->format), pLogicalSwapchain->imageExtent, firstImages, secondImages, pConfig)));
                Logger::debug("created LutEffect");
            }
            else
            {
                pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new ReshadeEffect(pLogicalDevice,
                                                                                               pLogicalSwapchain->format,
                                                                                               pLogicalSwapchain->imageExtent,
                                                                                               firstImages,
                                                                                               secondImages,
                                                                                               pConfig,
                                                                                               effectStrings[i])));
                Logger::debug("created ReshadeEffect");
            }
        }

        if (!pLogicalDevice->supportsMutableFormat)
        {
            pLogicalSwapchain->effects.push_back(std::shared_ptr<Effect>(new TransferEffect(
                pLogicalDevice,
                pLogicalSwapchain->format,
                pLogicalSwapchain->imageExtent,
                std::vector<VkImage>(pLogicalSwapchain->fakeImages.end() - pLogicalSwapchain->imageCount, pLogicalSwapchain->fakeImages.end()),
                pLogicalSwapchain->images,
                pConfig)));
        }

        VkImageView depthImageView = pLogicalDevice->depthImageViews.size() ? pLogicalDevice->depthImageViews[0] : VK_NULL_HANDLE;
        VkImage     depthImage     = pLogicalDevice->depthImageViews.size() ? pLogicalDevice->depthImages[0] : VK_NULL_HANDLE;
        VkFormat    depthFormat    = pLogicalDevice->depthImageViews.size() ? pLogicalDevice->depthFormats[0] : VK_FORMAT_UNDEFINED;

        Logger::debug("effect string count: " + std::to_string(effectStrings.size()));
        Logger::debug("effect count: " + std::to_string(pLogicalSwapchain->effects.size()));

        pLogicalSwapchain->commandBuffers = allocateCommandBuffer(pLogicalDevice, pLogicalSwapchain->imageCount);
        Logger::debug("allocated ComandBuffers " + std::to_string(pLogicalSwapchain->commandBuffers.size()) + " for swapchain "
                      + convertToString(swapchain));

        writeCommandBuffers(pLogicalDevice, pLogicalSwapchain->effects, depthImage, depthImageView, depthFormat, pLogicalSwapchain->commandBuffers);
        Logger::debug("wrote CommandBuffers");

        pLogicalSwapchain->semaphores = createSemaphores(pLogicalDevice, pLogicalSwapchain->imageCount);
        Logger::debug("created semaphores");
        for (unsigned int i = 0; i < pLogicalSwapchain->imageCount; i++)
        {
            Logger::debug(std::to_string(i) + " writen commandbuffer " + convertToString(pLogicalSwapchain->commandBuffers[i]));
        }
        Logger::trace("vkGetSwapchainImagesKHR");

        return result;
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
    {
        scoped_lock l(globalLock);
        
        static bool pressed = false;
        int toggle = 0;

        if (isKeyPressed(XK_Home))
        {
            if (!pressed)
            {
                toggle = 1;
                pressed = true;
            }
        }
        else
        {
            if (pressed)
            {
                toggle = -1;
                pressed = false;
            }
        }
        
        if(toggle)
        {
            Logger::trace("toggled " + std::to_string(toggle));
        }

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(queue)];

        std::vector<VkSemaphore> presentSemaphores;
        presentSemaphores.reserve(pPresentInfo->swapchainCount);

        std::vector<VkPipelineStageFlags> waitStages;

        for (unsigned int i = 0; i < (*pPresentInfo).swapchainCount; i++)
        {
            uint32_t                          index             = (*pPresentInfo).pImageIndices[i];
            VkSwapchainKHR                    swapchain         = (*pPresentInfo).pSwapchains[i];
            std::shared_ptr<LogicalSwapchain> pLogicalSwapchain = swapchainMap[swapchain];

            for (auto& effect : pLogicalSwapchain->effects)
            {
                effect->updateEffect();
            }

            waitStages.resize(pPresentInfo->waitSemaphoreCount, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);

            VkSubmitInfo submitInfo;
            submitInfo.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
            submitInfo.pNext                = nullptr;
            submitInfo.waitSemaphoreCount   = 0;
            submitInfo.pWaitSemaphores      = nullptr;
            submitInfo.pWaitDstStageMask    = nullptr;
            submitInfo.commandBufferCount   = 1;
            submitInfo.pCommandBuffers      = &(pLogicalSwapchain->commandBuffers[index]);
            submitInfo.signalSemaphoreCount = 1;
            submitInfo.pSignalSemaphores    = &(pLogicalSwapchain->semaphores[index]);

            presentSemaphores.push_back(pLogicalSwapchain->semaphores[index]);

            if (i == 0)
            {
                submitInfo.waitSemaphoreCount = pPresentInfo->waitSemaphoreCount;
                submitInfo.pWaitSemaphores    = pPresentInfo->pWaitSemaphores;
                submitInfo.pWaitDstStageMask  = waitStages.data();
            }

            VkResult vr = pLogicalDevice->vkd.QueueSubmit(pLogicalDevice->queue, 1, &submitInfo, VK_NULL_HANDLE);

            if (vr != VK_SUCCESS)
            {
                return vr;
            }
        }
        VkPresentInfoKHR presentInfo   = *pPresentInfo;
        presentInfo.waitSemaphoreCount = presentSemaphores.size();
        presentInfo.pWaitSemaphores    = presentSemaphores.data();

        return pLogicalDevice->vkd.QueuePresentKHR(queue, &presentInfo);
    }

    VKAPI_ATTR void VKAPI_CALL vkBasalt_DestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);
        // we need to delete the infos of the oldswapchain

        Logger::trace("vkDestroySwapchainKHR " + convertToString(swapchain));
        swapchainMap[swapchain]->destroy();
        swapchainMap.erase(swapchain);
        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        pLogicalDevice->vkd.DestroySwapchainKHR(device, swapchain, pAllocator);
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_CreateImage(VkDevice                     device,
                                                        const VkImageCreateInfo*     pCreateInfo,
                                                        const VkAllocationCallbacks* pAllocator,
                                                        VkImage*                     pImage)
    {
        scoped_lock l(globalLock);

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];
        if (isDepthFormat(pCreateInfo->format)
            && ((pCreateInfo->usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT)
                == VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT)) //&& pCreateInfo->extent.width == 2560 && pCreateInfo->extent.height == 1440)
        {
            Logger::debug("detected depth image with format: " + convertToString(pCreateInfo->format));
            Logger::debug(std::to_string(pCreateInfo->extent.width) + "x" + std::to_string(pCreateInfo->extent.height));
            Logger::debug(
                std::to_string((pCreateInfo->usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) == VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT));

            VkImageCreateInfo modifiedCreateInfo = *pCreateInfo;
            modifiedCreateInfo.usage |= VK_IMAGE_USAGE_SAMPLED_BIT;
            VkResult result = pLogicalDevice->vkd.CreateImage(device, &modifiedCreateInfo, pAllocator, pImage);
            pLogicalDevice->depthImages.push_back(*pImage);
            pLogicalDevice->depthFormats.push_back(pCreateInfo->format);

            return result;
        }
        else
        {
            return pLogicalDevice->vkd.CreateImage(device, pCreateInfo, pAllocator, pImage);
        }
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkBasalt_BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
    {
        scoped_lock l(globalLock);

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        VkResult result = pLogicalDevice->vkd.BindImageMemory(device, image, memory, memoryOffset);
        // TODO what if the application creates more than one image before binding memory?
        if (pLogicalDevice->depthImages.size() && image == pLogicalDevice->depthImages.back())
        {
            Logger::debug("before creating depth image view");
            VkImageView depthImageView = createImageViews(pLogicalDevice,
                                                          pLogicalDevice->depthFormats[pLogicalDevice->depthImages.size() - 1],
                                                          {image},
                                                          VK_IMAGE_VIEW_TYPE_2D,
                                                          VK_IMAGE_ASPECT_DEPTH_BIT)[0];

            VkFormat depthFormat = pLogicalDevice->depthFormats[pLogicalDevice->depthImages.size() - 1];

            Logger::debug("created depth image view");
            pLogicalDevice->depthImageViews.push_back(depthImageView);
            if (pLogicalDevice->depthImageViews.size() > 1)
            {
                return result;
            }

            for (auto& it : swapchainMap)
            {
                std::shared_ptr<LogicalSwapchain> pLogicalSwapchain = it.second;
                if (pLogicalSwapchain->pLogicalDevice == pLogicalDevice)
                {
                    if (pLogicalSwapchain->commandBuffers.size())
                    {
                        pLogicalDevice->vkd.FreeCommandBuffers(pLogicalDevice->device,
                                                               pLogicalDevice->commandPool,
                                                               pLogicalSwapchain->commandBuffers.size(),
                                                               pLogicalSwapchain->commandBuffers.data());
                        pLogicalSwapchain->commandBuffers.clear();
                        pLogicalSwapchain->commandBuffers = allocateCommandBuffer(pLogicalDevice, pLogicalSwapchain->imageCount);
                        Logger::debug("allocated CommandBuffers for swapchain " + convertToString(it.first));

                        writeCommandBuffers(
                            pLogicalDevice, pLogicalSwapchain->effects, image, depthImageView, depthFormat, pLogicalSwapchain->commandBuffers);
                        Logger::debug("wrote CommandBuffers");
                    }
                }
            }
        }
        return result;
    }

    VKAPI_ATTR void VKAPI_CALL vkBasalt_DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
    {
        scoped_lock l(globalLock);

        std::shared_ptr<LogicalDevice> pLogicalDevice = deviceMap[GetKey(device)];

        for (uint32_t i = 0; i < pLogicalDevice->depthImages.size(); i++)
        {
            if (pLogicalDevice->depthImages[i] == image)
            {
                pLogicalDevice->depthImages.erase(pLogicalDevice->depthImages.begin() + i);
                // TODO what if a image gets destroyed before binding memory?
                if (pLogicalDevice->depthImageViews.size() - 1 >= i)
                {
                    pLogicalDevice->vkd.DestroyImageView(pLogicalDevice->device, pLogicalDevice->depthImageViews[i], nullptr);
                    pLogicalDevice->depthImageViews.erase(pLogicalDevice->depthImageViews.begin() + i);
                }
                pLogicalDevice->depthFormats.erase(pLogicalDevice->depthFormats.begin() + i);

                VkImageView depthImageView = pLogicalDevice->depthImageViews.size() ? pLogicalDevice->depthImageViews[0] : VK_NULL_HANDLE;
                VkImage     depthImage     = pLogicalDevice->depthImageViews.size() ? pLogicalDevice->depthImages[0] : VK_NULL_HANDLE;
                VkFormat    depthFormat    = pLogicalDevice->depthImageViews.size() ? pLogicalDevice->depthFormats[0] : VK_FORMAT_UNDEFINED;
                for (auto& it : swapchainMap)
                {
                    std::shared_ptr<LogicalSwapchain> pLogicalSwapchain = it.second;
                    if (pLogicalSwapchain->pLogicalDevice == pLogicalDevice)
                    {
                        if (pLogicalSwapchain->commandBuffers.size())
                        {
                            pLogicalDevice->vkd.FreeCommandBuffers(pLogicalDevice->device,
                                                                   pLogicalDevice->commandPool,
                                                                   pLogicalSwapchain->commandBuffers.size(),
                                                                   pLogicalSwapchain->commandBuffers.data());
                            pLogicalSwapchain->commandBuffers.clear();
                            pLogicalSwapchain->commandBuffers = allocateCommandBuffer(pLogicalDevice, pLogicalSwapchain->imageCount);
                            Logger::debug("allocated CommandBuffers for swapchain " + convertToString(it.first));

                            writeCommandBuffers(pLogicalDevice,
                                                pLogicalSwapchain->effects,
                                                depthImage,
                                                depthImageView,
                                                depthFormat,
                                                pLogicalSwapchain->commandBuffers);
                            Logger::debug("wrote CommandBuffers");
                        }
                    }
                }
            }
        }

        pLogicalDevice->vkd.DestroyImage(pLogicalDevice->device, image, pAllocator);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    // Enumeration function

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
    {
        if (pPropertyCount)
            *pPropertyCount = 1;

        if (pProperties)
        {
#ifdef __x86_64__
            std::strcpy(pProperties->layerName, "VK_LAYER_VKBASALT_PostProcess64");
#else
            std::strcpy(pProperties->layerName, "VK_LAYER_VKBASALT_PostProcess32");
#endif
            std::strcpy(pProperties->description, "a post processing layer");
            pProperties->implementationVersion = 1;
            pProperties->specVersion           = VK_API_VERSION_1_0;
        }

        return VK_SUCCESS;
    }

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateDeviceLayerProperties(VkPhysicalDevice   physicalDevice,
                                                                                uint32_t*          pPropertyCount,
                                                                                VkLayerProperties* pProperties)
    {
        return vkBasalt_EnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    }

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateInstanceExtensionProperties(const char*            pLayerName,
                                                                                      uint32_t*              pPropertyCount,
                                                                                      VkExtensionProperties* pProperties)
    {
        if (pLayerName == NULL
            || (std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess32") && std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess64")))
        {
            return VK_ERROR_LAYER_NOT_PRESENT;
        }

        // don't expose any extensions
        if (pPropertyCount)
        {
            *pPropertyCount = 0;
        }
        return VK_SUCCESS;
    }

    VK_LAYER_EXPORT VkResult VKAPI_CALL vkBasalt_EnumerateDeviceExtensionProperties(VkPhysicalDevice       physicalDevice,
                                                                                    const char*            pLayerName,
                                                                                    uint32_t*              pPropertyCount,
                                                                                    VkExtensionProperties* pProperties)
    {
        // pass through any queries that aren't to us
        if (pLayerName == NULL
            || (std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess32") && std::strcmp(pLayerName, "VK_LAYER_VKBASALT_PostProcess64")))
        {
            if (physicalDevice == VK_NULL_HANDLE)
            {
                return VK_SUCCESS;
            }

            scoped_lock l(globalLock);
            return instanceDispatchMap[GetKey(physicalDevice)].EnumerateDeviceExtensionProperties(
                physicalDevice, pLayerName, pPropertyCount, pProperties);
        }

        // don't expose any extensions
        if (pPropertyCount)
        {
            *pPropertyCount = 0;
        }
        return VK_SUCCESS;
    }
} // namespace vkBasalt

extern "C"
{ // these are the entry points for the layer, so they need to be c-linkeable

#define GETPROCADDR(func)                                                                                                                            \
    if (!std::strcmp(pName, "vk" #func))                                                                                                             \
        return (PFN_vkVoidFunction) &vkBasalt::vkBasalt_##func;
    /*
    Return our funktions for the funktions we want to intercept
    the macro takes the name and returns our vkBasalt_##func, if the name is equal
    */
    VK_LAYER_EXPORT PFN_vkVoidFunction VKAPI_CALL vkBasalt_GetDeviceProcAddr(VkDevice device, const char* pName)
    {
        if (vkBasalt::pConfig == nullptr)
        {
            vkBasalt::pConfig = std::shared_ptr<vkBasalt::Config>(new vkBasalt::Config());
        }
        // device chain functions we intercept
        if (!std::strcmp(pName, "vkGetDeviceProcAddr"))
            return (PFN_vkVoidFunction) &vkBasalt_GetDeviceProcAddr;
        GETPROCADDR(EnumerateDeviceLayerProperties);
        GETPROCADDR(EnumerateDeviceExtensionProperties);
        GETPROCADDR(CreateDevice);
        GETPROCADDR(DestroyDevice);
        GETPROCADDR(GetDeviceQueue);
        GETPROCADDR(GetDeviceQueue2);
        GETPROCADDR(CreateSwapchainKHR);
        GETPROCADDR(GetSwapchainImagesKHR);
        GETPROCADDR(QueuePresentKHR);
        GETPROCADDR(DestroySwapchainKHR);

        if (vkBasalt::pConfig->getOption("depthCapture", "off") == "on")
        {
            GETPROCADDR(CreateImage);
            GETPROCADDR(DestroyImage);
            GETPROCADDR(BindImageMemory);
        }

        {
            vkBasalt::scoped_lock l(vkBasalt::globalLock);
            return vkBasalt::deviceMap[vkBasalt::GetKey(device)]->vkd.GetDeviceProcAddr(device, pName);
        }
    }

    VK_LAYER_EXPORT PFN_vkVoidFunction VKAPI_CALL vkBasalt_GetInstanceProcAddr(VkInstance instance, const char* pName)
    {
        if (vkBasalt::pConfig == nullptr)
        {
            vkBasalt::pConfig = std::shared_ptr<vkBasalt::Config>(new vkBasalt::Config());
        }
        // instance chain functions we intercept
        if (!std::strcmp(pName, "vkGetInstanceProcAddr"))
            return (PFN_vkVoidFunction) &vkBasalt_GetInstanceProcAddr;
        GETPROCADDR(EnumerateInstanceLayerProperties);
        GETPROCADDR(EnumerateInstanceExtensionProperties);
        GETPROCADDR(CreateInstance);
        GETPROCADDR(DestroyInstance);

        // device chain functions we intercept
        if (!std::strcmp(pName, "vkGetDeviceProcAddr"))
            return (PFN_vkVoidFunction) &vkBasalt_GetDeviceProcAddr;
        GETPROCADDR(EnumerateDeviceLayerProperties);
        GETPROCADDR(EnumerateDeviceExtensionProperties);
        GETPROCADDR(CreateDevice);
        GETPROCADDR(DestroyDevice);
        GETPROCADDR(GetDeviceQueue);
        GETPROCADDR(GetDeviceQueue2);
        GETPROCADDR(CreateSwapchainKHR);
        GETPROCADDR(GetSwapchainImagesKHR);
        GETPROCADDR(QueuePresentKHR);
        GETPROCADDR(DestroySwapchainKHR);

        if (vkBasalt::pConfig->getOption("depthCapture", "off") == "on")
        {
            GETPROCADDR(CreateImage);
            GETPROCADDR(DestroyImage);
            GETPROCADDR(BindImageMemory);
        }

        {
            vkBasalt::scoped_lock l(vkBasalt::globalLock);
            return vkBasalt::instanceDispatchMap[vkBasalt::GetKey(instance)].GetInstanceProcAddr(instance, pName);
        }
    }

} // extern "C"
