#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

#include "vulkan_include.hpp"

namespace vkBasalt
{
    class Config
    {
    public:
        Config();
        Config(const Config& other);
        std::string getOption(const std::string& option, const std::string& defaultValue = "");

    private:
        std::unordered_map<std::string, std::string> options;

        void readConfigLine(std::string line);
        void readConfigFile(std::ifstream& stream);
    };
} // namespace vkBasalt

#endif // CONFIG_HPP_INCLUDED
