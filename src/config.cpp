#include "config.hpp"

namespace vkBasalt
{
    Config::Config()
    {
        // Custom config file path
        const char* tmpConfEnv = getenv("VKBASALT_CONFIG_FILE");
        std::string customConfigFile = tmpConfEnv ? std::string(tmpConfEnv) : "";

        // User config file path
        const char* tmpHomeEnv = getenv("XDG_DATA_HOME");
        std::string userConfigFile = tmpHomeEnv
            ? std::string(tmpHomeEnv) + "/vkBasalt/vkBasalt.conf"
            : std::string(getenv("HOME")) + "/.local/share/vkBasalt/vkBasalt.conf";

        // Allowed config paths
        const std::array<std::string, 5> configPath = {
            customConfigFile,                          // custom config (VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf)
            "vkBasalt.conf",                           // per game config
            userConfigFile,                            // default config
            "/usr/share/vkBasalt/vkBasalt.conf",       // system-wide config
            "/usr/local/share/vkBasalt/vkBasalt.conf", // system-wide config (alternative)
        };

        for(const auto& cFile: configPath){
            std::ifstream configFile(cFile);
            if (!configFile.good()) continue;

            std::cout << cFile << std::endl;
            readConfigFile(configFile);
            return;
        }

        std::cout << "no good config file" << std::endl;
    }
    Config::Config(const Config& other)
    {
        this->options = other.options;
    }
    void Config::readConfigFile(std::ifstream& stream)
    {
        std::string line;

        while (std::getline(stream, line))
        {
            readConfigLine(line);
        }
    }
    void Config::readConfigLine(std::string line)
    {
        //TODO this needs to die in flames
        if(line.find("#")!=std::string::npos)
        {
            line = line.erase(line.find("#"),std::string::npos);
        }
        size_t space = line.find(" ");
        while(space!=std::string::npos)
        {
            line = line.erase(space,1);
            space = line.find(" ");
        }
        space = line.find("\t");
        while(space!=std::string::npos)
        {
            line = line.erase(space,1);
            space = line.find("\t");
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
