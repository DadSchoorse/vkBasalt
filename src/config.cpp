#include "config.hpp"

namespace vkBasalt
{
    Config::Config()
    {
        std::ifstream configFile("vkBasalt.conf");//per game config
        if(!configFile.good())
        {
            configFile = std::ifstream(std::string(getenv("HOME")) + "/.local/share/vkBasalt/vkBasalt.conf");//global config file
            if(!configFile.good())
            {
                std::cout << "no good config file" << std::endl;
                return;
            }
            else
            {
                std::cout << std::string(getenv("HOME")) + "/.local/share/vkBasalt/vkBasalt.conf" << std::endl;
            }
        }
        else
        {
            std::cout << "vkBasalt.conf" << std::endl;
        }
        readConfigFile(configFile);
    }
    void Config::readConfigFile(std::ifstream& stream)
    {
        std::string line;

        while (std::getline(stream, line))
        {
            readConfigLine(line);
            std::cout << line << std::endl;
        }
    }
    void Config::readConfigLine(std::string line)
    {
        //TODO this needs to die in flames
        if(line.substr(0,1)==std::string("#"))
        {
            return;
        }
        size_t equal = line.find("=");
        if(equal==std::string::npos)
        {
            return;
        }
        std::cout  << "set option " << line.substr(0,equal) << " equal to " << line.substr(equal+1) << std::endl;
        options[line.substr(0,equal)] = line.substr(equal+1);
    }
    std::string Config::getOption(std::string option){
        return options[option];
    }
}
