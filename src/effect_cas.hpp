#ifndef EFFECT_CAS_HPP_INCLUDED
#define EFFECT_CAS_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

#include "vulkan_include.hpp"

#include "effect_simple.hpp"
#include "config.hpp"

namespace vkBasalt{
    class CasEffect : public SimpleEffect
    {
    public:
        CasEffect(LogicalDevice logicalDevice, VkFormat format,  VkExtent2D imageExtent, std::vector<VkImage> inputImages, std::vector<VkImage> outputImages, std::shared_ptr<vkBasalt::Config> pConfig);
        ~CasEffect();
    };
}


#endif // EFFECT_CAS_HPP_INCLUDED
