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

#include "shader_sources.hpp"

namespace vkBasalt
{
    FxaaEffect::FxaaEffect(LogicalDevice*       pLogicalDevice,
                           VkFormat             format,
                           VkExtent2D           imageExtent,
                           std::vector<VkImage> inputImages,
                           std::vector<VkImage> outputImages,
                           Config*              pConfig)
    {
        float fxaaQualitySubpix           = pConfig->getOption<float>("fxaaQualitySubpix", 0.75f);
        float fxaaQualityEdgeThreshold    = pConfig->getOption<float>("fxaaQualityEdgeThreshold", 0.125f);
        float fxaaQualityEdgeThresholdMin = pConfig->getOption<float>("fxaaQualityEdgeThresholdMin", 0.0312f);

        vertexCode   = full_screen_triangle_vert;
        fragmentCode = fxaa_frag;

        std::vector<VkSpecializationMapEntry> specMapEntrys(5);

        for (uint32_t i = 0; i < specMapEntrys.size(); i++)
        {
            specMapEntrys[i].constantID = i;
            specMapEntrys[i].offset     = sizeof(float) * i;
            specMapEntrys[i].size       = sizeof(float);
        }
        std::vector<float> specData = {
            fxaaQualitySubpix, fxaaQualityEdgeThreshold, fxaaQualityEdgeThresholdMin, (float) imageExtent.width, (float) imageExtent.height};

        VkSpecializationInfo fragmentSpecializationInfo;
        fragmentSpecializationInfo.mapEntryCount = specMapEntrys.size();
        fragmentSpecializationInfo.pMapEntries   = specMapEntrys.data();
        fragmentSpecializationInfo.dataSize      = sizeof(float) * specData.size();
        fragmentSpecializationInfo.pData         = specData.data();

        pVertexSpecInfo   = nullptr;
        pFragmentSpecInfo = &fragmentSpecializationInfo;

        init(pLogicalDevice, format, imageExtent, inputImages, outputImages, pConfig);
    }
    FxaaEffect::~FxaaEffect()
    {
    }
} // namespace vkBasalt
