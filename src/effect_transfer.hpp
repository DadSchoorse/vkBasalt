#ifndef EFFECT_TRANSFER_HPP_INCLUDED
#define EFFECT_TRANSFER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

#include "vulkan_include.hpp"

#include "effect.hpp"
#include "config.hpp"

#include "logical_device.hpp"

namespace vkBasalt
{
    class TransferEffect : public Effect
    {
    public:
        TransferEffect(std::shared_ptr<LogicalDevice>    pLogicalDevice,
                       VkFormat                          format,
                       VkExtent2D                        imageExtent,
                       std::vector<VkImage>              inputImages,
                       std::vector<VkImage>              outputImages,
                       std::shared_ptr<vkBasalt::Config> pConfig);
        void virtual applyEffect(uint32_t imageIndex, VkCommandBuffer commandBuffer) override;
        virtual ~TransferEffect();

    private:
        std::shared_ptr<LogicalDevice>    pLogicalDevice;
        std::vector<VkImage>              inputImages;
        std::vector<VkImage>              outputImages;
        VkExtent2D                        imageExtent;
        VkFormat                          format;
        std::shared_ptr<vkBasalt::Config> pConfig;
    };
} // namespace vkBasalt
#endif // EFFECT_TRANSFER_HPP_INCLUDED
