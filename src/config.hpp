#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
    class Config
    {
    public:
        Config();
        Config(const Config& other);
        std::string getOption(const std::string& option, const std::string& defaultValue = "");
    private:
        std::unordered_map<std::string,std::string> options;
        void readConfigLine(std::string line);
        void readConfigFile(std::ifstream& stream);
    };
}


#endif // CONFIG_HPP_INCLUDED
