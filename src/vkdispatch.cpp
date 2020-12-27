#include "vkdispatch.hpp"

#include "vkfuncs.hpp"

namespace vkBasalt
{

    void fillDispatchTableInstance(VkInstance instance, PFN_vkGetInstanceProcAddr gipa, InstanceDispatch* table)
    {
        table->GetInstanceProcAddr = gipa;
#define FORVKFUNC(func) \
    do \
    { \
        if (!table->func) \
            table->func = (PFN_vk##func) gipa(instance, "vk" #func); \
    } while (false);
        VK_INSTANCE_FUNCS
#undef FORVKFUNC
    }

    void fillDispatchTableDevice(VkDevice device, PFN_vkGetDeviceProcAddr gdpa, DeviceDispatch* table)
    {
        table->GetDeviceProcAddr = gdpa;
#define FORVKFUNC(func) \
    do \
    { \
        if (!table->func) \
            table->func = (PFN_vk##func) gdpa(device, "vk" #func); \
    } while (false);
        VK_DEVICE_FUNCS
#undef FORVKFUNC
    }

} // namespace vkBasalt

#undef VK_INSTANCE_FUNCS
#undef VK_DEVICE_FUNCS
