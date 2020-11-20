#include "config.hpp"
#include "config_paths.hpp"

#include <sstream>
#include <locale>

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
        const std::array<std::string, 7> configPath = {
            customConfigFile,                                    // custom config (VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf)
            "vkBasalt.conf",                                     // per game config
            userXdgConfigFile,                                   // user-global config
            userConfigFile,                                      // legacy default config
            std::string(SYSCONFDIR) + "/vkBasalt.conf",          // system-wide config
            std::string(SYSCONFDIR) + "/vkBasalt/vkBasalt.conf", // system-wide config (alternative)
            std::string(DATADIR) + "/vkBasalt/vkBasalt.conf",    // legacy system-wide config
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
        std::string key;
        std::string value;

        bool inQuotes    = false;
        bool foundEquals = false;

        auto appendChar = [&key, &value, &foundEquals](const char& newChar) {
            if (foundEquals)
                value += newChar;
            else
                key += newChar;
        };

        for (const char& nextChar : line)
        {
            if (inQuotes)
            {
                if (nextChar == '"')
                    inQuotes = false;
                else
                    appendChar(nextChar);
                continue;
            }
            switch (nextChar)
            {
                case '#': goto BREAK;
                case '"': inQuotes = true; break;
                case '\t':
                case ' ': break;
                case '=': foundEquals = true; break;
                default: appendChar(nextChar); break;
            }
        }

    BREAK:

        if (!key.empty() && !value.empty())
        {
            Logger::info(key + " = " + value);
            options[key] = value;
        }
    }

    void Config::parseOption(const std::string& option, int32_t& result)
    {
        auto found = options.find(option);
        if (found != options.end())
        {
            try
            {
                result = std::stoi(found->second);
            }
            catch (...)
            {
                Logger::warn("invalid int32_t value for: " + option);
            }
        }
    }

    void Config::parseOption(const std::string& option, float& result)
    {
        auto found = options.find(option);
        if (found != options.end())
        {
            // TODO find a better float parsing way, std::stof has locale issues
            std::stringstream ss(found->second);
            ss.imbue(std::locale("C"));
            float value;
            ss >> value;

            bool failed = ss.fail();

            std::string rest;
            ss >> rest;
            if (failed || (!rest.empty() && rest != "f"))
            {
                Logger::warn("invalid float value for: " + option);
            }
            else
            {
                result = value;
            }
        }
    }

    void Config::parseOption(const std::string& option, bool& result)
    {
        auto found = options.find(option);
        if (found != options.end())
        {
            if (found->second == "True" || found->second == "true" || found->second == "1")
            {
                result = true;
            }
            else if (found->second == "False" || found->second == "false" || found->second == "0")
            {
                result = false;
            }
            else
            {
                Logger::warn("invalid bool value for: " + option);
            }
        }
    }

    void Config::parseOption(const std::string& option, std::string& result)
    {
        auto found = options.find(option);
        if (found != options.end())
        {
            result = found->second;
        }
    }

    void Config::parseOption(const std::string& option, std::vector<std::string>& result)
    {
        auto found = options.find(option);
        if (found != options.end())
        {
            result = {};
            std::stringstream stringStream(found->second);
            std::string       newString;
            while (getline(stringStream, newString, ':'))
            {
                result.push_back(newString);
            }
        }
    }
} // namespace vkBasalt
