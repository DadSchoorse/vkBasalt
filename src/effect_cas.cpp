#include "effect_cas.hpp"

#include <cstring>

#include "image_view.hpp"
#include "descriptor_set.hpp"
#include "buffer.hpp"
#include "renderpass.hpp"
#include "graphics_pipeline.hpp"
#include "framebuffer.hpp"
#include "shader.hpp"
#include "sampler.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{
    CasEffect::CasEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::string fullScreenRectFile = "full_screen_triangle.vert.spv";
        std::string casFragmentFile = "cas.frag.spv";

        float sharpness = std::stod(pConfig->getOption("casSharpness", "0.4"));

        vertexCode = readFile(fullScreenRectFile);
        fragmentCode = readFile(casFragmentFile);


        VkSpecializationMapEntry sharpnessMapEntry;
        sharpnessMapEntry.constantID = 0;
        sharpnessMapEntry.offset = 0;
        sharpnessMapEntry.size = sizeof(float);

        VkSpecializationInfo fragmentSpecializationInfo;
        fragmentSpecializationInfo.mapEntryCount = 1;
        fragmentSpecializationInfo.pMapEntries = &sharpnessMapEntry;
        fragmentSpecializationInfo.dataSize = sizeof(float);
        fragmentSpecializationInfo.pData = &sharpness;

        pVertexSpecInfo = nullptr;
        pFragmentSpecInfo = &fragmentSpecializationInfo;

        init(physicalDevice, instanceDispatchTable, device, dispatchTable, format,  imageExtent, inputImages, outputImages, pConfig);
    }
    CasEffect::~CasEffect()
    {

    }
}
