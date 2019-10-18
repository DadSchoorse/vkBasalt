#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"


namespace vkBasalt{
    std::vector<char> readFile(const std::string &filename);
    void createShaderModule(const VkDevice& device, const VkLayerDispatchTable& dispatchTable, const std::vector<char> &code, VkShaderModule *shaderModule);
}


#endif // SHADER_HPP_INCLUDED
