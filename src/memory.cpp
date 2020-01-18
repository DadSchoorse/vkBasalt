#include "memory.hpp"

namespace vkBasalt
{
    uint32_t findMemoryTypeIndex(LogicalDevice logicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties)
    {
        VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
        logicalDevice.vki.GetPhysicalDeviceMemoryProperties(logicalDevice.physicalDevice, &physicalDeviceMemoryProperties);
        for(uint32_t i=0;i<physicalDeviceMemoryProperties.memoryTypeCount;i++)
        {
            if((typeFilter & (1 << i)) && (physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & properties) == properties)
            {
                return i;
            }
        }

        throw std::runtime_error("Found no correct memory type");
    }
}
