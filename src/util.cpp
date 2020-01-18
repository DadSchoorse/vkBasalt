#include "util.hpp"

#include <string>

namespace vkBasalt
{
    void addUniqueCString(std::vector<const char*>& stringVector, const char* addString)
    {
        for(const char* other: stringVector)
        {
            if(other == std::string(addString))
            {
                return;
            }
        }
        stringVector.push_back(addString);
    }
}
