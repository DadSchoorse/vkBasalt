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

namespace vkBasalt
{
    FxaaEffect::FxaaEffect(LogicalDevice logicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::string fullScreenRectFile = "full_screen_triangle.vert.spv";
        std::string fxaaFragmentFile = "fxaa.frag.spv";

        float fxaaQualitySubpix = std::stod(pConfig->getOption("fxaaQualitySubpix", "0.75"));
        float fxaaQualityEdgeThreshold = std::stod(pConfig->getOption("fxaaQualityEdgeThreshold", "0.125"));
        float fxaaQualityEdgeThresholdMin = std::stod(pConfig->getOption("fxaaQualityEdgeThresholdMin", "0.0312"));

        vertexCode   = readFile(fullScreenRectFile);
        fragmentCode = readFile(fxaaFragmentFile);

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

        pVertexSpecInfo = nullptr;
        pFragmentSpecInfo = &fragmentSpecializationInfo;

        init(logicalDevice, format,  imageExtent, inputImages, outputImages, pConfig);
    }
    FxaaEffect::~FxaaEffect()
    {

    }
}
