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
        
        shaderInfo.pVertexSpecInfo = nullptr;
        shaderInfo.pFragmentSpecInfo = nullptr;
        
        init(physicalDevice, instanceDispatchTable, device, dispatchTable, format,  imageExtent, inputImages, outputImages, pConfig);
    }
    DebandEffect::~DebandEffect()
    {
    
    }
}
