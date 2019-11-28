#ifndef EFFECT_FXAA_HPP_INCLUDED
#define EFFECT_FXAA_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

#include "effect_simple.hpp"
#include "config.hpp"

namespace vkBasalt{
    class FxaaEffect : public SimpleEffect
    {
    public:
        FxaaEffect(VkPhysicalDevice physicalDevice, VkLayerInstanceDispatchTable instanceDispatchTable, VkDevice device, VkLayerDispatchTable dispatchTable, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig);
        ~FxaaEffect();
    };
}


#endif // EFFECT_FXAA_HPP_INCLUDED
