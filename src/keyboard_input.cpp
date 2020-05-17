#include "keyboard_input.hpp"

#include "logger.hpp"

// TODO build without X11
#ifndef VKBASALT_X11
#define VKBASALT_X11 1
#endif

#if VKBASALT_X11
#include "keyboard_input_x11.hpp"
#endif

namespace vkBasalt
{
    uint32_t convertToKeySym(std::string key)
    {
#if VKBASALT_X11
        return convertToKeySymX11(key);
#endif
        return 0u;
    }

    bool isKeyPressed(uint32_t ks)
    {
#if VKBASALT_X11
        return isKeyPressedX11(ks);
#endif
        return false;
    }
} // namespace vkBasalt
