#include "util.hpp"

#include <iostream>
#include <unistd.h>

namespace vkBasalt
{
    void addUniqueCString(std::vector<const char*>& stringVector, const char* addString)
    {
        for (const char* other : stringVector)
        {
            if (other == std::string(addString))
            {
                return;
            }
        }
        stringVector.push_back(addString);
    }

    void outputInColor(std::string output, Color foreground, Color background)
    {
        std::vector<std::string> magicNumbers;
        switch (foreground)
        {
            case Color::black: magicNumbers.push_back("30"); break;
            case Color::red: magicNumbers.push_back("31"); break;
            case Color::green: magicNumbers.push_back("32"); break;
            case Color::yellow: magicNumbers.push_back("33"); break;
            case Color::blue: magicNumbers.push_back("34"); break;
            case Color::magenta: magicNumbers.push_back("35"); break;
            case Color::cyan: magicNumbers.push_back("36"); break;
            case Color::white: magicNumbers.push_back("37"); break;
            default: break;
        }
        switch (background)
        {
            case Color::black: magicNumbers.push_back("40"); break;
            case Color::red: magicNumbers.push_back("41"); break;
            case Color::green: magicNumbers.push_back("42"); break;
            case Color::yellow: magicNumbers.push_back("43"); break;
            case Color::blue: magicNumbers.push_back("44"); break;
            case Color::magenta: magicNumbers.push_back("45"); break;
            case Color::cyan: magicNumbers.push_back("46"); break;
            case Color::white: magicNumbers.push_back("47"); break;
            default: break;
        }
        std::string magicString = "";
        for (bool first = true; auto& magicNumber : magicNumbers)
        {
            if (!first)
            {
                magicString += ";";
            }
            magicString += magicNumber;
            first = false;
        }
        if (magicString.size() == 0 || !isatty(fileno(stdout)))
        {
            std::cout << output << std::endl;
        }
        else
        {
            std::cout << "\033[" << magicString << "m" << output << "\033[0m" << std::endl;
        }
    }
} // namespace vkBasalt
