#include "effect_dls.hpp"

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
    DlsEffect::DlsEffect(LogicalDevice*       pLogicalDevice,
                         VkFormat             format,
                         VkExtent2D           imageExtent,
                         std::vector<VkImage> inputImages,
                         std::vector<VkImage> outputImages,
                         Config*              pConfig)
    {
        float sharpness = pConfig->getOption<float>("dlsSharpness", 0.5f);
        float denoise   = pConfig->getOption<float>("dlsDenoise", 0.17f);

        float specData[2] = {sharpness, denoise};

        vertexCode   = full_screen_triangle_vert;
        fragmentCode = dls_frag;

        VkSpecializationMapEntry mapEntries[2];
        mapEntries[0].constantID = 0;
        mapEntries[0].offset     = 0;
        mapEntries[0].size       = sizeof(float);
        mapEntries[1].constantID = 1;
        mapEntries[1].offset     = sizeof(float);
        mapEntries[1].size       = sizeof(float);

        VkSpecializationInfo fragmentSpecializationInfo;
        fragmentSpecializationInfo.mapEntryCount = 1;
        fragmentSpecializationInfo.pMapEntries   = mapEntries;
        fragmentSpecializationInfo.dataSize      = sizeof(float) * 2;
        fragmentSpecializationInfo.pData         = specData;

        pVertexSpecInfo   = nullptr;
        pFragmentSpecInfo = &fragmentSpecializationInfo;

        init(pLogicalDevice, format, imageExtent, inputImages, outputImages, pConfig);
    }
    DlsEffect::~DlsEffect()
    {
    }
} // namespace vkBasalt
