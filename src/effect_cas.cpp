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

#include "shader_sources.hpp"

namespace vkBasalt
{
    CasEffect::CasEffect(LogicalDevice*       pLogicalDevice,
                         VkFormat             format,
                         VkExtent2D           imageExtent,
                         std::vector<VkImage> inputImages,
                         std::vector<VkImage> outputImages,
                         Config*              pConfig)
    {

        float sharpness = pConfig->getOption<float>("casSharpness", 0.4f);

        vertexCode   = full_screen_triangle_vert;
        fragmentCode = cas_frag;

        VkSpecializationMapEntry sharpnessMapEntry;
        sharpnessMapEntry.constantID = 0;
        sharpnessMapEntry.offset     = 0;
        sharpnessMapEntry.size       = sizeof(float);

        VkSpecializationInfo fragmentSpecializationInfo;
        fragmentSpecializationInfo.mapEntryCount = 1;
        fragmentSpecializationInfo.pMapEntries   = &sharpnessMapEntry;
        fragmentSpecializationInfo.dataSize      = sizeof(float);
        fragmentSpecializationInfo.pData         = &sharpness;

        pVertexSpecInfo   = nullptr;
        pFragmentSpecInfo = &fragmentSpecializationInfo;

        init(pLogicalDevice, format, imageExtent, inputImages, outputImages, pConfig);
    }
    CasEffect::~CasEffect()
    {
    }
} // namespace vkBasalt
