#include "shader.hpp"

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed " + std::to_string(val));\
        }
#endif

namespace vkBasalt{
    std::vector<char> readFile(const std::string &filename)
    {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);

        if(file)
        {
            size_t fileSize = (size_t) file.tellg();
            std::vector<char> fileBuffer(fileSize);
            file.seekg(0);
            file.read(fileBuffer.data(),fileSize);
            file.close();
            return fileBuffer;
        }
        else
        {
            throw std::runtime_error("read file " + filename + " failed");
        }
    }


    void createShaderModule(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const std::vector<char> &code, VkShaderModule *shaderModule)
    {
        VkShaderModuleCreateInfo shaderCreateInfo;

        shaderCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shaderCreateInfo.pNext = nullptr;
        shaderCreateInfo.flags = 0;
        shaderCreateInfo.codeSize = code.size();
        shaderCreateInfo.pCode = (uint32_t*) code.data();

        VkResult result = dispatchTable.CreateShaderModule(device,&shaderCreateInfo,nullptr,shaderModule);
        ASSERT_VULKAN(result);
    }
}
