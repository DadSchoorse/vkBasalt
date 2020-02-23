#ifndef UTIL_HPP_INCLUDED
#define UTIL_HPP_INCLUDED

#include <string>
#include <vector>

namespace vkBasalt
{
    void addUniqueCString(std::vector<const char*>& stringVector, const char* addString);

    enum class Color
    {
        defaultColor,

        black,
        red,
        green,
        yellow,
        blue,
        magenta,
        cyan,
        white
    };

    void outputInColor(std::string output, Color foreground = Color::defaultColor, Color background = Color::defaultColor);
} // namespace vkBasalt

#endif // UTIL_HPP_INCLUDED
