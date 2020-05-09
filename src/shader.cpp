#include "shader.hpp"

#include <array>
#include <filesystem>

namespace vkBasalt
{
    std::vector<char> readFile(const std::string& filename)
    {
        static std::string shaderDir;

        if (shaderDir.empty())
        {
            // Custom shader directory path
            const char* tmpShaderEnv    = std::getenv("VKBASALT_SHADER_PATH");
            std::string customShaderDir = tmpShaderEnv ? std::string(tmpShaderEnv) : "";

            // User shader directory path
            const char* tmpHomeEnv = std::getenv("XDG_DATA_HOME");
            std::string userShaderDir =
                tmpHomeEnv ? std::string(tmpHomeEnv) + "/vkBasalt/shader" : std::string(std::getenv("HOME")) + "/.local/share/vkBasalt/shader";

            // Allowed config paths
            const std::array<std::string, 4> shaderPath = {
                customShaderDir,                    // custom shaders (VKBASALT_SHADER_PATH=/path/to/vkBasalt/shader)
                userShaderDir,                      // default shaders
                "/usr/share/vkBasalt/shader",       // system-wide shaders
                "/usr/local/share/vkBasalt/shader", // system-wide shaders (alternative)
            };

            for (const auto& sDir : shaderPath)
            {
                if (!std::filesystem::is_directory(sDir))
                    continue;

                Logger::info("shader directory: " + sDir);
                shaderDir = sDir + "/";
                break;
            }
        }
        std::ifstream file;

        if (filename[0] != '/')
        {
            file = std::ifstream(shaderDir + filename, std::ios::binary | std::ios::ate);
        }
        else
        {
            file = std::ifstream(filename, std::ios::binary | std::ios::ate);
        }

        if (file)
        {
            size_t            fileSize = (size_t) file.tellg();
            std::vector<char> fileBuffer(fileSize);
            file.seekg(0);
            file.read(fileBuffer.data(), fileSize);
            file.close();
            return fileBuffer;
        }
        else
        {
            Logger::err("read file " + filename + " failed");
            return std::vector<char>(0);
        }
    }

    void createShaderModule(std::shared_ptr<LogicalDevice> pLogicalDevice, const std::vector<char>& code, VkShaderModule* shaderModule)
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

    void createShaderModule(std::shared_ptr<LogicalDevice> pLogicalDevice, const std::vector<uint32_t>& code, VkShaderModule* shaderModule)
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
