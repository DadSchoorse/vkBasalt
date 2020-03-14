#ifndef KEYBOARD_INPUT_HPP_INCLUDED
#define KEYBOARD_INPUT_HPP_INCLUDED

#include <X11/Xlib.h>
#include <X11/keysym.h>

namespace vkBasalt
{
    bool isKeyPressed(KeySym ks);
}

#endif // KEYBOARD_INPUT_HPP_INCLUDED
