/* Copyright (c) 2015-2016, 2020 The Khronos Group Inc.
 * Copyright (c) 2015-2016, 2020 Valve Corporation
 * Copyright (c) 2015-2016, 2020 LunarG, Inc.
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
 * Author: Mark Lobodzinski <mark@lunarg.com>
 * Author: Dave Houlton <daveh@lunarg.com>
 *
 */

#include "vk_layer_utils.h"

#include <string.h>
#include <string>
#include <map>
#include <vector>

#include "vulkan/vulkan.h"
#include "vk_layer_config.h"

static const uint8_t UTF8_ONE_BYTE_CODE = 0xC0;
static const uint8_t UTF8_ONE_BYTE_MASK = 0xE0;
static const uint8_t UTF8_TWO_BYTE_CODE = 0xE0;
static const uint8_t UTF8_TWO_BYTE_MASK = 0xF0;
static const uint8_t UTF8_THREE_BYTE_CODE = 0xF0;
static const uint8_t UTF8_THREE_BYTE_MASK = 0xF8;
static const uint8_t UTF8_DATA_BYTE_CODE = 0x80;
static const uint8_t UTF8_DATA_BYTE_MASK = 0xC0;

VK_LAYER_EXPORT VkStringErrorFlags vk_string_validate(const int max_length, const char *utf8) {
    VkStringErrorFlags result = VK_STRING_ERROR_NONE;
    int num_char_bytes = 0;
    int i, j;

    for (i = 0; i <= max_length; i++) {
        if (utf8[i] == 0) {
            break;
        } else if (i == max_length) {
            result |= VK_STRING_ERROR_LENGTH;
            break;
        } else if ((utf8[i] >= 0xa) && (utf8[i] < 0x7f)) {
            num_char_bytes = 0;
        } else if ((utf8[i] & UTF8_ONE_BYTE_MASK) == UTF8_ONE_BYTE_CODE) {
            num_char_bytes = 1;
        } else if ((utf8[i] & UTF8_TWO_BYTE_MASK) == UTF8_TWO_BYTE_CODE) {
            num_char_bytes = 2;
        } else if ((utf8[i] & UTF8_THREE_BYTE_MASK) == UTF8_THREE_BYTE_CODE) {
            num_char_bytes = 3;
        } else {
            result |= VK_STRING_ERROR_BAD_DATA;
            break;
        }

        // Validate the following num_char_bytes of data
        for (j = 0; (j < num_char_bytes) && (i < max_length); j++) {
            if (++i == max_length) {
                result |= VK_STRING_ERROR_LENGTH;
                break;
            }
            if ((utf8[i] & UTF8_DATA_BYTE_MASK) != UTF8_DATA_BYTE_CODE) {
                result |= VK_STRING_ERROR_BAD_DATA;
                break;
            }
        }
        if (result != VK_STRING_ERROR_NONE) break;
    }
    return result;
}

// Utility function for determining if a string is in a set of strings
VK_LAYER_EXPORT bool white_list(const char *item, const std::set<std::string> &list) { return (list.find(item) != list.end()); }

// Debug callbacks get created in three ways:
//   o  Application-defined debug callbacks
//   o  Through settings in a vk_layer_settings.txt file
//   o  By default, if neither an app-defined debug callback nor a vk_layer_settings.txt file is present
//
// At layer initialization time, default logging callbacks are created to output layer error messages.
// If a vk_layer_settings.txt file is present its settings will override any default settings.
//
// If a vk_layer_settings.txt file is present and an application defines a debug callback, both callbacks
// will be active.  If no vk_layer_settings.txt file is present, creating an application-defined debug
// callback will cause the default callbacks to be unregisterd and removed.
VK_LAYER_EXPORT void layer_debug_messenger_actions(debug_report_data *report_data, const VkAllocationCallbacks *pAllocator,
                                                   const char *layer_identifier) {
    VkDebugUtilsMessengerEXT messenger = VK_NULL_HANDLE;

    std::string report_flags_key = layer_identifier;
    std::string debug_action_key = layer_identifier;
    std::string log_filename_key = layer_identifier;
    report_flags_key.append(".report_flags");
    debug_action_key.append(".debug_action");
    log_filename_key.append(".log_filename");

    // Initialize layer options
    LogMessageTypeFlags report_flags = GetLayerOptionFlags(report_flags_key, log_msg_type_option_definitions, 0);
    VkLayerDbgActionFlags debug_action = GetLayerOptionFlags(debug_action_key, debug_actions_option_definitions, 0);
    // Flag as default if these settings are not from a vk_layer_settings.txt file
    VkDebugUtilsMessengerCreateInfoEXT dbgCreateInfo;
    memset(&dbgCreateInfo, 0, sizeof(dbgCreateInfo));
    dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    dbgCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
    if (report_flags & kErrorBit) {
        dbgCreateInfo.messageSeverity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    }
    if (report_flags & kWarningBit) {
        dbgCreateInfo.messageSeverity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
    }
    if (report_flags & kPerformanceWarningBit) {
        dbgCreateInfo.messageSeverity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
        dbgCreateInfo.messageType |= VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    }
    if (report_flags & kInformationBit) {
        dbgCreateInfo.messageSeverity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
    }
    if (report_flags & kDebugBit) {
        dbgCreateInfo.messageSeverity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
    }

    if (debug_action & VK_DBG_LAYER_ACTION_LOG_MSG) {
        const char *log_filename = getLayerOption(log_filename_key.c_str());
        FILE *log_output = getLayerLogOutput(log_filename, layer_identifier);
        dbgCreateInfo.pfnUserCallback = messenger_log_callback;
        dbgCreateInfo.pUserData = (void *)log_output;
        layer_create_messenger_callback(report_data, true, &dbgCreateInfo, pAllocator, &messenger);
    }

    messenger = VK_NULL_HANDLE;

    if (debug_action & VK_DBG_LAYER_ACTION_DEBUG_OUTPUT) {
        dbgCreateInfo.pfnUserCallback = messenger_win32_debug_output_msg;
        dbgCreateInfo.pUserData = NULL;
        layer_create_messenger_callback(report_data, true, &dbgCreateInfo, pAllocator, &messenger);
    }

    messenger = VK_NULL_HANDLE;

    if (debug_action & VK_DBG_LAYER_ACTION_BREAK) {
        dbgCreateInfo.pfnUserCallback = MessengerBreakCallback;
        dbgCreateInfo.pUserData = NULL;
        layer_create_messenger_callback(report_data, true, &dbgCreateInfo, pAllocator, &messenger);
    }
}

// NOTE: This function has been deprecated, and the above function (layer_debug_messenger_actions) should be
//       used in its place.
VK_LAYER_EXPORT void layer_debug_report_actions(debug_report_data *report_data, const VkAllocationCallbacks *pAllocator,
                                                const char *layer_identifier) {
    VkDebugReportCallbackEXT callback = VK_NULL_HANDLE;

    std::string report_flags_key = layer_identifier;
    std::string debug_action_key = layer_identifier;
    std::string log_filename_key = layer_identifier;
    report_flags_key.append(".report_flags");
    debug_action_key.append(".debug_action");
    log_filename_key.append(".log_filename");

    // Initialize layer options
    VkDebugReportFlagsEXT report_flags = GetLayerOptionFlags(report_flags_key, report_flags_option_definitions, 0);
    VkLayerDbgActionFlags debug_action = GetLayerOptionFlags(debug_action_key, debug_actions_option_definitions, 0);
    // Flag as default if these settings are not from a vk_layer_settings.txt file
    bool default_layer_callback = (debug_action & VK_DBG_LAYER_ACTION_DEFAULT) ? true : false;

    if (debug_action & VK_DBG_LAYER_ACTION_LOG_MSG) {
        const char *log_filename = getLayerOption(log_filename_key.c_str());
        FILE *log_output = getLayerLogOutput(log_filename, layer_identifier);
        VkDebugReportCallbackCreateInfoEXT dbgCreateInfo;
        memset(&dbgCreateInfo, 0, sizeof(dbgCreateInfo));
        dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
        dbgCreateInfo.flags = report_flags;
        dbgCreateInfo.pfnCallback = report_log_callback;
        dbgCreateInfo.pUserData = (void *)log_output;
        layer_create_report_callback(report_data, default_layer_callback, &dbgCreateInfo, pAllocator, &callback);
    }

    callback = VK_NULL_HANDLE;

    if (debug_action & VK_DBG_LAYER_ACTION_DEBUG_OUTPUT) {
        VkDebugReportCallbackCreateInfoEXT dbgCreateInfo;
        memset(&dbgCreateInfo, 0, sizeof(dbgCreateInfo));
        dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
        dbgCreateInfo.flags = report_flags;
        dbgCreateInfo.pfnCallback = report_win32_debug_output_msg;
        dbgCreateInfo.pUserData = NULL;
        layer_create_report_callback(report_data, default_layer_callback, &dbgCreateInfo, pAllocator, &callback);
    }

    callback = VK_NULL_HANDLE;

    if (debug_action & VK_DBG_LAYER_ACTION_BREAK) {
        VkDebugReportCallbackCreateInfoEXT dbgCreateInfo;
        memset(&dbgCreateInfo, 0, sizeof(dbgCreateInfo));
        dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
        dbgCreateInfo.flags = report_flags;
        dbgCreateInfo.pfnCallback = DebugBreakCallback;
        dbgCreateInfo.pUserData = NULL;
        layer_create_report_callback(report_data, default_layer_callback, &dbgCreateInfo, pAllocator, &callback);
    }
}

VK_LAYER_EXPORT VkLayerInstanceCreateInfo *get_chain_info(const VkInstanceCreateInfo *pCreateInfo, VkLayerFunction func) {
    VkLayerInstanceCreateInfo *chain_info = (VkLayerInstanceCreateInfo *)pCreateInfo->pNext;
    while (chain_info && !(chain_info->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO && chain_info->function == func)) {
        chain_info = (VkLayerInstanceCreateInfo *)chain_info->pNext;
    }
    assert(chain_info != NULL);
    return chain_info;
}

VK_LAYER_EXPORT VkLayerDeviceCreateInfo *get_chain_info(const VkDeviceCreateInfo *pCreateInfo, VkLayerFunction func) {
    VkLayerDeviceCreateInfo *chain_info = (VkLayerDeviceCreateInfo *)pCreateInfo->pNext;
    while (chain_info && !(chain_info->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO && chain_info->function == func)) {
        chain_info = (VkLayerDeviceCreateInfo *)chain_info->pNext;
    }
    assert(chain_info != NULL);
    return chain_info;
}
