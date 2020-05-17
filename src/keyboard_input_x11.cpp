#include "keyboard_input_x11.hpp"

#include "logger.hpp"

#include <X11/Xlib.h>
#include <X11/keysym.h>

#include <memory>
#include <functional>

#include <unistd.h>
#include <cstring>

namespace vkBasalt
{
    uint32_t convertToKeySymX11(std::string key)
    {
        // TODO what if X11 isn't loaded?
        uint32_t result = (uint32_t) XStringToKeysym(key.c_str());
        if (!result)
        {
            Logger::err("invalid key");
        }
        return result;
    }

    bool isKeyPressedX11(uint32_t ks)
    {
        static int usesX11 = -1;

        static std::unique_ptr<Display, std::function<void(Display*)>> display;

        if (usesX11 < 0)
        {
            const char* disVar = getenv("DISPLAY");
            if (!disVar || !std::strcmp(disVar, ""))
            {
                usesX11 = 0;
                Logger::debug("no X11 support");
            }
            else
            {
                display = std::unique_ptr<Display, std::function<void(Display*)>>(XOpenDisplay(disVar), [](Display* d) { XCloseDisplay(d); });
                usesX11 = 1;
                Logger::debug("X11 support");
            }
        }

        if (!usesX11)
        {
            return false;
        }

        char keys_return[32];

        XQueryKeymap(display.get(), keys_return);

        KeyCode kc2 = XKeysymToKeycode(display.get(), (KeySym) ks);

        return !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
    }

} // namespace vkBasalt
