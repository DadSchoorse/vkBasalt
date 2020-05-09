#include "effect_deband.hpp"

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
    DebandEffect::DebandEffect(std::shared_ptr<LogicalDevice>    pLogicalDevice,
                               VkFormat                          format,
                               VkExtent2D                        imageExtent,
                               std::vector<VkImage>              inputImages,
                               std::vector<VkImage>              outputImages,
                               std::shared_ptr<vkBasalt::Config> pConfig)
    {
        vertexCode   = full_screen_triangle_vert;
        fragmentCode = deband_frag;

        struct
        {
            float   screenWidth;
            float   screenHeight;
            float   reverseScreenWidth;
            float   reverseScreenHeight;
            float   debandAvgdiff;
            float   debandMaxdiff;
            float   debandMiddiff;
            float   range;
            int32_t iterations;
        } debandOptions{};

        debandOptions.screenWidth         = (float) imageExtent.width;
        debandOptions.screenHeight        = (float) imageExtent.height;
        debandOptions.reverseScreenWidth  = 1.0f / imageExtent.width;
        debandOptions.reverseScreenHeight = 1.0f / imageExtent.height;

        // get Options
        debandOptions.debandAvgdiff = std::stod(pConfig->getOption("debandAvgdiff", "3.4"));
        debandOptions.debandMaxdiff = std::stod(pConfig->getOption("debandMaxdiff", "6.8"));
        debandOptions.debandMiddiff = std::stod(pConfig->getOption("debandMiddiff", "3.3"));
        debandOptions.range         = std::stod(pConfig->getOption("debandRange", "16.0"));
        debandOptions.iterations    = std::stoi(pConfig->getOption("debandIterations", "4"));

        std::vector<VkSpecializationMapEntry> specMapEntrys(9);
        for (uint32_t i = 0; i < specMapEntrys.size(); i++)
        {
            specMapEntrys[i].constantID = i;
            specMapEntrys[i].offset     = sizeof(float) * i; // TODO not clean to assume that sizeof(int32_t) == sizeof(float)
            specMapEntrys[i].size       = sizeof(float);
        }

        VkSpecializationInfo specializationInfo;
        specializationInfo.mapEntryCount = specMapEntrys.size();
        specializationInfo.pMapEntries   = specMapEntrys.data();
        specializationInfo.dataSize      = sizeof(debandOptions);
        specializationInfo.pData         = &debandOptions;

        pVertexSpecInfo   = nullptr;
        pFragmentSpecInfo = &specializationInfo;

        init(pLogicalDevice, format, imageExtent, inputImages, outputImages, pConfig);
    }
    DebandEffect::~DebandEffect()
    {
    }
} // namespace vkBasalt
