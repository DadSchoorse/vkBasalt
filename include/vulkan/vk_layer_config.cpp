/**************************************************************************
 *
 * Copyright 2014-2020 Valve Software
 * Copyright 2015-2020 Google Inc.
 * Copyright 2019-2020 LunarG, Inc.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Jon Ashburn <jon@lunarg.com>
 * Author: Courtney Goeltzenleuchter <courtney@LunarG.com>
 * Author: Tobin Ehlis <tobin@lunarg.com>
 * Author: Mark Lobodzinski <mark@lunarg.com>
 **************************************************************************/
#include "vk_layer_config.h"

#include <string.h>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/stat.h>

#include <vulkan/vk_layer.h>
// sdk_platform header redefines NOMINMAX
#undef NOMINMAX
#include <vulkan/vk_sdk_platform.h>
#include "vk_layer_utils.h"

#if defined(_WIN32)
#include <windows.h>
#endif

using std::string;

class ConfigFile {
  public:
    ConfigFile();
    ~ConfigFile(){};

    const char *GetOption(const string &option);
    void SetOption(const string &option, const string &value);
    string vk_layer_disables_env_var;

  private:
    bool file_is_parsed_;
    std::map<string, string> value_map_;

    string FindSettings();
    void ParseFile(const char *filename);
};

static ConfigFile layer_config;

string GetEnvironment(const char *variable) {
#if !defined(__ANDROID__) && !defined(_WIN32)
    const char *output = getenv(variable);
    return output == NULL ? "" : output;
#elif defined(_WIN32)
    int size = GetEnvironmentVariable(variable, NULL, 0);
    if (size == 0) {
        return "";
    }
    char *buffer = new char[size];
    GetEnvironmentVariable(variable, buffer, size);
    string output = buffer;
    delete[] buffer;
    return output;
#else
    return "";
#endif
}

VK_LAYER_EXPORT const char *getLayerOption(const char *option) { return layer_config.GetOption(option); }
VK_LAYER_EXPORT const char *GetLayerEnvVar(const char *option) {
    layer_config.vk_layer_disables_env_var = GetEnvironment(option);
    return layer_config.vk_layer_disables_env_var.c_str();
}

// If option is NULL or stdout, return stdout, otherwise try to open option
// as a filename. If successful, return file handle, otherwise stdout
VK_LAYER_EXPORT FILE *getLayerLogOutput(const char *option, const char *layer_name) {
    FILE *log_output = NULL;
    if (!option || !strcmp("stdout", option))
        log_output = stdout;
    else {
        log_output = fopen(option, "w");
        if (log_output == NULL) {
            if (option)
                std::cout << std::endl
                          << layer_name << " ERROR: Bad output filename specified: " << option << ". Writing to STDOUT instead"
                          << std::endl
                          << std::endl;
            log_output = stdout;
        }
    }
    return log_output;
}

// Map option strings to flag enum values
VK_LAYER_EXPORT VkFlags GetLayerOptionFlags(string option, std::unordered_map<string, VkFlags> const &enum_data,
                                            uint32_t option_default) {
    VkDebugReportFlagsEXT flags = option_default;
    string option_list = layer_config.GetOption(option.c_str());

    while (option_list.length() != 0) {
        // Find length of option string
        std::size_t option_length = option_list.find(",");
        if (option_length == option_list.npos) {
            option_length = option_list.size();
        }

        // Get first option item in list
        const string option_item = option_list.substr(0, option_length);

        auto enum_value = enum_data.find(option_item);
        if (enum_value != enum_data.end()) {
            flags |= enum_value->second;
        }

        // Remove first option from option_list
        option_list.erase(0, option_length);
        // Remove possible comma separator
        std::size_t char_position = option_list.find(",");
        if (char_position == 0) {
            option_list.erase(char_position, 1);
        }
        // Remove possible space
        char_position = option_list.find(" ");
        if (char_position == 0) {
            option_list.erase(char_position, 1);
        }
    }
    return flags;
}

VK_LAYER_EXPORT void setLayerOption(const char *option, const char *value) { layer_config.SetOption(option, value); }

// Constructor for ConfigFile. Initialize layers to log error messages to stdout by default. If a vk_layer_settings file is present,
// its settings will override the defaults.
ConfigFile::ConfigFile() : file_is_parsed_(false) {
    value_map_["khronos_validation.report_flags"] = "error";

#ifdef WIN32
    // For Windows, enable message logging AND OutputDebugString
    value_map_["khronos_validation.debug_action"] =
        "VK_DBG_LAYER_ACTION_DEFAULT,VK_DBG_LAYER_ACTION_LOG_MSG,VK_DBG_LAYER_ACTION_DEBUG_OUTPUT";
#else   // WIN32
    value_map_["khronos_validation.debug_action"] = "VK_DBG_LAYER_ACTION_DEFAULT,VK_DBG_LAYER_ACTION_LOG_MSG";
#endif  // WIN32
    value_map_["khronos_validation.log_filename"] = "stdout";
}

const char *ConfigFile::GetOption(const string &option) {
    std::map<string, string>::const_iterator it;
    if (!file_is_parsed_) {
        string settings_file = FindSettings();
        ParseFile(settings_file.c_str());
    }

    if ((it = value_map_.find(option)) == value_map_.end())
        return "";
    else
        return it->second.c_str();
}

void ConfigFile::SetOption(const string &option, const string &val) {
    if (!file_is_parsed_) {
        string settings_file = FindSettings();
        ParseFile(settings_file.c_str());
    }

    value_map_[option] = val;
}

string ConfigFile::FindSettings() {
    struct stat info;

#if defined(WIN32)
    HKEY hive;
    LSTATUS err = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Khronos\\Vulkan\\Settings", 0, KEY_READ, &hive);
    if (err == ERROR_SUCCESS) {
        char name[2048];
        DWORD i = 0, name_size, type, value, value_size;
        while (ERROR_SUCCESS == RegEnumValue(hive, i++, name, &(name_size = sizeof(name)), nullptr, &type,
                                             reinterpret_cast<LPBYTE>(&value), &(value_size = sizeof(value)))) {
            // Check if the registry entry is a dword with a value of zero
            if (type != REG_DWORD || value != 0) {
                continue;
            }

            // Check if this actually points to a file
            if ((stat(name, &info) != 0) || !(info.st_mode & S_IFREG)) {
                continue;
            }

            // Use this file
            RegCloseKey(hive);
            return name;
        }

        RegCloseKey(hive);
    }
#else
    string search_path = GetEnvironment("XDG_DATA_HOME");
    if (search_path == "") {
        search_path = GetEnvironment("HOME");
        if (search_path != "") {
            search_path += "/.local/share";
        }
    }

    // Use the vk_layer_settings.txt file from here, if it is present
    if (search_path != "") {
        string home_file = search_path + "/vulkan/settings.d/vk_layer_settings.txt";
        if (stat(home_file.c_str(), &info) == 0) {
            if (info.st_mode & S_IFREG) {
                return home_file;
            }
        }
    }

#endif

    string env_path = GetEnvironment("VK_LAYER_SETTINGS_PATH");

    // If the path exists use it, else use vk_layer_settings
    if (stat(env_path.c_str(), &info) == 0) {
        // If this is a directory, look for vk_layer_settings within the directory
        if (info.st_mode & S_IFDIR) {
            return env_path + "/vk_layer_settings.txt";
        }
        return env_path;
    }
    return "vk_layer_settings.txt";
}

void ConfigFile::ParseFile(const char *filename) {
    file_is_parsed_ = true;

    // extract option = value pairs from a file
    std::ifstream file(filename);
    for (string line; std::getline(file, line);) {
        // discard comments, which start with '#'
        const auto comments_pos = line.find_first_of('#');
        if (comments_pos != string::npos) line.erase(comments_pos);

        const auto value_pos = line.find_first_of('=');
        if (value_pos != string::npos) {
            const string option = string_trim(line.substr(0, value_pos));
            const string value = string_trim(line.substr(value_pos + 1));
            value_map_[option] = value;
        }
    }
}

VK_LAYER_EXPORT void PrintMessageFlags(VkFlags vk_flags, char *msg_flags) {
    bool separator = false;

    msg_flags[0] = 0;
    if (vk_flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT) {
        strcat(msg_flags, "DEBUG");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "INFO");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_REPORT_WARNING_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "WARN");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "PERF");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "ERROR");
    }
}

VK_LAYER_EXPORT void PrintMessageSeverity(VkFlags vk_flags, char *msg_flags) {
    bool separator = false;

    msg_flags[0] = 0;
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) {
        strcat(msg_flags, "VERBOSE");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "INFO");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "WARN");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "ERROR");
    }
}

VK_LAYER_EXPORT void PrintMessageType(VkFlags vk_flags, char *msg_flags) {
    bool separator = false;

    msg_flags[0] = 0;
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT) {
        strcat(msg_flags, "GEN");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "SPEC");
        separator = true;
    }
    if (vk_flags & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) {
        if (separator) strcat(msg_flags, ",");
        strcat(msg_flags, "PERF");
    }
}
