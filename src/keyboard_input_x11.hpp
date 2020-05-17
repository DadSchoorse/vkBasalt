#pragma once

#include <cstdint>
#include <string>

namespace vkBasalt
{
    uint32_t convertToKeySymX11(std::string key);
    bool     isKeyPressedX11(uint32_t ks);
} // namespace vkBasalt
