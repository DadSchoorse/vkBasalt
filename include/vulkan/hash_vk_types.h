/* Copyright (c) 2019 The Khronos Group Inc.
 * Copyright (c) 2019 Valve Corporation
 * Copyright (c) 2019 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: John Zulauf <jzulauf@lunarg.com>
 */
#ifndef HASH_VK_TYPES_H_
#define HASH_VK_TYPES_H_

// Includes everything needed for overloading std::hash
#include "hash_util.h"

#include <vulkan/vulkan.h>
#include "vk_safe_struct.h"
#include <vector>

// Hash and equality and/or compare functions for selected Vk types (and useful collections thereof)

// VkDescriptorSetLayoutBinding
static bool operator==(const safe_VkDescriptorSetLayoutBinding &lhs, const safe_VkDescriptorSetLayoutBinding &rhs) {
    if ((lhs.binding != rhs.binding) || (lhs.descriptorType != rhs.descriptorType) ||
        (lhs.descriptorCount != rhs.descriptorCount) || (lhs.stageFlags != rhs.stageFlags) ||
        !hash_util::similar_for_nullity(lhs.pImmutableSamplers, rhs.pImmutableSamplers)) {
        return false;
    }
    if (lhs.pImmutableSamplers) {  // either one will do as they *are* similar for nullity (i.e. either both null or both non-null)
        for (uint32_t samp = 0; samp < lhs.descriptorCount; samp++) {
            if (lhs.pImmutableSamplers[samp] != rhs.pImmutableSamplers[samp]) {
                return false;
            }
        }
    }
    return true;
}

namespace std {
template <>
struct hash<safe_VkDescriptorSetLayoutBinding> {
    size_t operator()(const safe_VkDescriptorSetLayoutBinding &value) const {
        hash_util::HashCombiner hc;
        hc << value.binding << value.descriptorType << value.descriptorCount << value.stageFlags;
        if (value.pImmutableSamplers) {
            for (uint32_t samp = 0; samp < value.descriptorCount; samp++) {
                hc << value.pImmutableSamplers[samp];
            }
        }
        return hc.Value();
    }
};
}  // namespace std

// VkPushConstantRange
static inline bool operator==(const VkPushConstantRange &lhs, const VkPushConstantRange &rhs) {
    return (lhs.stageFlags == rhs.stageFlags) && (lhs.offset == rhs.offset) && (lhs.size == rhs.size);
}

namespace std {
template <>
struct hash<VkPushConstantRange> {
    size_t operator()(const VkPushConstantRange &value) const {
        hash_util::HashCombiner hc;
        return (hc << value.stageFlags << value.offset << value.size).Value();
    }
};
}  // namespace std

using PushConstantRanges = std::vector<VkPushConstantRange>;

namespace std {
template <>
struct hash<PushConstantRanges> : public hash_util::IsOrderedContainer<PushConstantRanges> {};
}  // namespace std

// VkImageSubresourceRange
static bool operator==(const VkImageSubresourceRange &lhs, const VkImageSubresourceRange &rhs) {
    return (lhs.aspectMask == rhs.aspectMask) && (lhs.baseMipLevel == rhs.baseMipLevel) && (lhs.levelCount == rhs.levelCount) &&
           (lhs.baseArrayLayer == rhs.baseArrayLayer) && (lhs.layerCount == rhs.layerCount);
}
namespace std {
template <>
struct hash<VkImageSubresourceRange> {
    size_t operator()(const VkImageSubresourceRange &value) const {
        hash_util::HashCombiner hc;
        hc << value.aspectMask << value.baseMipLevel << value.levelCount << value.baseArrayLayer << value.layerCount;
        return hc.Value();
    }
};
}  // namespace std

#endif  // HASH_VK_TYPES_H_
