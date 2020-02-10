#ifndef VULKAN_INCLUDE_HPP_INCLUDED
#define VULKAN_INCLUDE_HPP_INCLUDED

#include <assert.h>//vulkan/vk_dispatch_table_helper.h needs this

#define VK_NO_PROTOTYPES

#include "vulkan/vulkan.h"
#include "vulkan/vk_layer.h"
#include "vulkan/vk_layer_dispatch_table.h"
#include "vulkan/vk_dispatch_table_helper.h"

#include <string>

#ifndef ASSERT_VULKAN
#define ASSERT_VULKAN(val)\
        if(val!=VK_SUCCESS)\
        {\
            throw std::runtime_error("ASSERT_VULKAN failed in " + std::string(__FILE__) + " : " + std::to_string(__LINE__) + "; " + std::to_string(val));\
        }
#endif

#endif // VULKAN_INCLUDE_HPP_INCLUDED
