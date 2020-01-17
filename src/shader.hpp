#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "vulkan_include.hpp"

namespace vkBasalt{
    std::vector<char> readFile(const std::string &filename);
    void createShaderModule(VkDevice device, VkLayerDispatchTable dispatchTable, const std::vector<char> &code, VkShaderModule *shaderModule);
}


#endif // SHADER_HPP_INCLUDED
