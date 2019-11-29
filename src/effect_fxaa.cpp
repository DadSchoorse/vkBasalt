#include "effect_fxaa.hpp"

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
    FxaaEffect::FxaaEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::string fullScreenRectFile = "full_screen_triangle.vert.spv";
        std::string fxaaFragmentFile = "fxaa.frag.spv";
        float fxaaQualitySubpix = 0.75f;
        float fxaaQualityEdgeThreshold = 0.125f;
        float fxaaQualityEdgeThresholdMin = 0.0312f;
        if(pConfig->getOption("fxaaQualitySubpix")!=std::string(""))
        {
            fxaaQualitySubpix = std::stod(pConfig->getOption("fxaaQualitySubpix"));
        }
        if(pConfig->getOption("fxaaQualityEdgeThreshold")!=std::string(""))
        {
            fxaaQualityEdgeThreshold = std::stod(pConfig->getOption("fxaaQualityEdgeThreshold"));
        }
        if(pConfig->getOption("fxaaQualityEdgeThresholdMin")!=std::string(""))
        {
            fxaaQualityEdgeThresholdMin = std::stod(pConfig->getOption("fxaaQualityEdgeThresholdMin"));
        }

        shaderInfo.vertexCode   = readFile(fullScreenRectFile);
        shaderInfo.fragmentCode = readFile(fxaaFragmentFile);

        std::vector<VkSpecializationMapEntry> specMapEntrys(5);

        for(uint32_t i=0;i<specMapEntrys.size();i++)
        {
            specMapEntrys[i].constantID = i;
            specMapEntrys[i].offset = sizeof(float) * i;
            specMapEntrys[i].size = sizeof(float);
        }
        std::vector<float> specData = {fxaaQualitySubpix,
                                       fxaaQualityEdgeThreshold,
                                       fxaaQualityEdgeThresholdMin,
                                       (float) imageExtent.width,
                                       (float) imageExtent.height
                                      };

        VkSpecializationInfo fragmentSpecializationInfo;
        fragmentSpecializationInfo.mapEntryCount = specMapEntrys.size();
        fragmentSpecializationInfo.pMapEntries = specMapEntrys.data();
        fragmentSpecializationInfo.dataSize = sizeof(float)*specData.size();
        fragmentSpecializationInfo.pData = specData.data();

        shaderInfo.pVertexSpecInfo = nullptr;
        shaderInfo.pFragmentSpecInfo = &fragmentSpecializationInfo;

        init(physicalDevice, instanceDispatchTable, device, dispatchTable, format,  imageExtent, inputImages, outputImages, pConfig);
    }
    FxaaEffect::~FxaaEffect()
    {

    }
}
