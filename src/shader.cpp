#include "shader.hpp"

#include <array>
#include <filesystem>

namespace vkBasalt
{
    void createShaderModule(LogicalDevice* pLogicalDevice, const std::vector<char>& code, VkShaderModule* shaderModule)
    {
        VkShaderModuleCreateInfo shaderCreateInfo;

        shaderCreateInfo.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shaderCreateInfo.pNext    = nullptr;
        shaderCreateInfo.flags    = 0;
        shaderCreateInfo.codeSize = code.size();
        shaderCreateInfo.pCode    = (uint32_t*) code.data();

        VkResult result = pLogicalDevice->vkd.CreateShaderModule(pLogicalDevice->device, &shaderCreateInfo, nullptr, shaderModule);
        ASSERT_VULKAN(result);
    }

    void createShaderModule(LogicalDevice* pLogicalDevice, const std::vector<uint32_t>& code, VkShaderModule* shaderModule)
    {
        VkShaderModuleCreateInfo shaderCreateInfo;

        shaderCreateInfo.sType    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shaderCreateInfo.pNext    = nullptr;
        shaderCreateInfo.flags    = 0;
        shaderCreateInfo.codeSize = code.size() * sizeof(uint32_t);
        shaderCreateInfo.pCode    = code.data();

        VkResult result = pLogicalDevice->vkd.CreateShaderModule(pLogicalDevice->device, &shaderCreateInfo, nullptr, shaderModule);
        ASSERT_VULKAN(result);
    }
} // namespace vkBasalt
