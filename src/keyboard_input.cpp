#include "logger.hpp"

#include "keyboard_input.hpp"

#include <memory>
#include <functional>

#include <unistd.h>
#include <cstring>

namespace vkBasalt
{
    bool isKeyPressed(KeySym ks)
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

        KeyCode kc2 = XKeysymToKeycode(display.get(), ks);

        return !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
    }

} // namespace vkBasalt
