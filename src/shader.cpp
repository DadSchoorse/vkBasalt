#include "shader.hpp"

#include <array>
#if __GNUC__ == 7
#include <experimental/filesystem>
#define filesystem experimental::filesystem
#else
#include <filesystem>
#endif

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
        static std::string shaderDir;

        if (shaderDir.empty()) {
            // Custom shader directory path
            const char* tmpShaderEnv = std::getenv("VKBASALT_SHADER_PATH");
            std::string customShaderDir = tmpShaderEnv ? std::string(tmpShaderEnv) : "";

            // User shader directory path
            const char* tmpHomeEnv = std::getenv("XDG_DATA_HOME");
            std::string userShaderDir = tmpHomeEnv
                ? std::string(tmpHomeEnv) + "/vkBasalt/shader"
                : std::string(std::getenv("HOME")) + "/.local/share/vkBasalt/shader";

            // Allowed config paths
            const std::array<std::string, 4> shaderPath = {
                customShaderDir,                    // custom shaders (VKBASALT_SHADER_PATH=/path/to/vkBasalt/shader)
                userShaderDir,                      // default shaders
                "/usr/share/vkBasalt/shader",       // system-wide shaders
                "/usr/local/share/vkBasalt/shader", // system-wide shaders (alternative)
            };

            for(const auto& sDir: shaderPath){
                if (!std::filesystem::is_directory(sDir)) continue;

                std::cout << sDir << std::endl;
                shaderDir = sDir + "/";
                break;
            }
        }

        std::ifstream file(shaderDir + filename, std::ios::binary | std::ios::ate);

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


    void createShaderModule(VkDevice device, VkLayerDispatchTable dispatchTable, const std::vector<char> &code, VkShaderModule *shaderModule)
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
