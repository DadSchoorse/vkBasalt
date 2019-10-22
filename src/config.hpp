#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"

namespace vkBasalt{
    class Config
    {
    public:
        Config();
        
        std::string getOption(std::string option);
    private:
        std::unordered_map<std::string,std::string> options;
        void readConfigLine(std::string line);
        void readConfigFile(std::ifstream& stream);
    };
}


#endif // CONFIG_HPP_INCLUDED
