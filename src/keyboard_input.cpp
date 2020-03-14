#include "keyboard_input.hpp"

#include <memory>
#include <functional>

namespace vkBasalt
{

    std::unique_ptr<Display, std::function<void(Display*)>> display(XOpenDisplay(":0"), [](Display* d) { XCloseDisplay(d); });

    bool isKeyPressed(KeySym ks)
    {
        char keys_return[32];

        XQueryKeymap(display.get(), keys_return);

        KeyCode kc2 = XKeysymToKeycode(display.get(), ks);

        return !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
    }

} // namespace vkBasalt
