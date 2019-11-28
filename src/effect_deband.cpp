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

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt
{   
    DebandEffect::DebandEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig)
    {
        std::string fullScreenRectFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/full_screen_triangle.vert.spv";
        std::string debandFragmentFile = std::string(getenv("HOME")) + "/.local/share/vkBasalt/shader/deband.frag.spv";
        
        shaderInfo.vertexCode = readFile(fullScreenRectFile.c_str());
        shaderInfo.fragmentCode = readFile(debandFragmentFile.c_str());
        
        struct{
            float     screenWidth;
            float     screenHeight;
            float     reverseScreenWidth;
            float     reverseScreenHeight;
            float     debandAvgdiff = 3.4;
            float     debandMaxdiff = 6.8;
            float     debandMiddiff = 3.3;
            float     range = 16.0;
            int32_t   iterations = 4;
        } debandOptions;
        
        debandOptions.screenWidth = (float) imageExtent.width;
        debandOptions.screenHeight = (float) imageExtent.height;
        debandOptions.reverseScreenWidth = 1.0f / imageExtent.width;
        debandOptions.reverseScreenHeight = 1.0f / imageExtent.height;
        //get Options
        if(pConfig->getOption("debandAvgdiff")!=std::string(""))
        {
            debandOptions.debandAvgdiff = std::stod(pConfig->getOption("debandAvgdiff"));
        }
        if(pConfig->getOption("debandMaxdiff")!=std::string(""))
        {
            debandOptions.debandMaxdiff = std::stod(pConfig->getOption("debandMaxdiff"));
        }
        if(pConfig->getOption("debandMiddiff")!=std::string(""))
        {
            debandOptions.debandMiddiff = std::stod(pConfig->getOption("debandMiddiff"));
        }
        if(pConfig->getOption("debandRange")!=std::string(""))
        {
            debandOptions.range = std::stod(pConfig->getOption("debandRange"));
        }
        if(pConfig->getOption("debandIterations")!=std::string(""))
        {
            debandOptions.iterations = std::stod(pConfig->getOption("debandIterations"));
        }
        
        std::vector<VkSpecializationMapEntry> specMapEntrys(9);
        for(uint32_t i=0;i<specMapEntrys.size();i++)
        {
            specMapEntrys[i].constantID = i;
            specMapEntrys[i].offset = sizeof(float) * i;//TODO not clean to assume that sizeof(int32_t) == sizeof(float)
            specMapEntrys[i].size = sizeof(float);
        }
        
        VkSpecializationInfo specializationInfo;
        specializationInfo.mapEntryCount = specMapEntrys.size();
        specializationInfo.pMapEntries = specMapEntrys.data();
        specializationInfo.dataSize = sizeof(debandOptions);
        specializationInfo.pData = &debandOptions;
        
        shaderInfo.pVertexSpecInfo = nullptr;
        shaderInfo.pFragmentSpecInfo = &specializationInfo;
        
        init(physicalDevice, instanceDispatchTable, device, dispatchTable, format,  imageExtent, inputImages, outputImages, pConfig);
    }
    DebandEffect::~DebandEffect()
    {
    
    }
}
