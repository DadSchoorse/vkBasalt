#include "config.hpp"

namespace vkBasalt
{
    Config::Config()
    {
        // Custom config file path
        const char* tmpConfEnv       = std::getenv("VKBASALT_CONFIG_FILE");
        std::string customConfigFile = tmpConfEnv ? std::string(tmpConfEnv) : "";

        // User config file path
        const char* tmpHomeEnv     = std::getenv("XDG_DATA_HOME");
        std::string userConfigFile = tmpHomeEnv ? std::string(tmpHomeEnv) + "/vkBasalt/vkBasalt.conf"
                                                : std::string(std::getenv("HOME")) + "/.local/share/vkBasalt/vkBasalt.conf";
        const char* tmpConfigEnv      = std::getenv("XDG_CONFIG_HOME");
        std::string userXdgConfigFile = tmpConfigEnv ? std::string(tmpConfigEnv) + "/vkBasalt/vkBasalt.conf"
                                                     : std::string(std::getenv("HOME")) + "/.config/vkBasalt/vkBasalt.conf";

        // Allowed config paths
        const std::array<std::string, 6> configPath = {
            customConfigFile,                          // custom config (VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf)
            "vkBasalt.conf",                           // per game config
            userXdgConfigFile,                         // user-global config
            userConfigFile,                            // default config
            "/usr/share/vkBasalt/vkBasalt.conf",       // system-wide config
            "/usr/local/share/vkBasalt/vkBasalt.conf", // system-wide config (alternative)
        };

        for (const auto& cFile : configPath)
        {
            std::ifstream configFile(cFile);
            if (!configFile.good())
                continue;

            Logger::info("config file: " + cFile);
            readConfigFile(configFile);
            return;
        }

        Logger::err("no good config file");
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
        // TODO this needs to die in flames
        if (line.find("#") != std::string::npos)
        {
            line = line.erase(line.find("#"), std::string::npos);
        }
        size_t space = line.find(" ");
        while (space != std::string::npos)
        {
            line  = line.erase(space, 1);
            space = line.find(" ");
        }
        space = line.find("\t");
        while (space != std::string::npos)
        {
            line  = line.erase(space, 1);
            space = line.find("\t");
        }
        size_t equal = line.find("=");
        if (equal == std::string::npos)
        {
            return;
        }
        Logger::info(line.substr(0, equal) + " = " + line.substr(equal + 1));
        options[line.substr(0, equal)] = line.substr(equal + 1);
    }

    std::string Config::getOption(const std::string& option, const std::string& defaultValue)
    {
        auto found = options.find(option);
        return found != options.end() ? found->second : defaultValue;
    }
} // namespace vkBasalt
