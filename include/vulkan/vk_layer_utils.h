/* Copyright (c) 2015-2017, 2019 The Khronos Group Inc.
 * Copyright (c) 2015-2017, 2019 Valve Corporation
 * Copyright (c) 2015-2017, 2019 LunarG, Inc.
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
 * Author: Mark Lobodzinski <mark@lunarg.com>
 * Author: Courtney Goeltzenleuchter <courtney@LunarG.com>
 * Author: Dave Houlton <daveh@lunarg.com>
 */

#pragma once

#include <cassert>
#include <cstddef>
#include <functional>
#include <stdbool.h>
#include <string>
#include <vector>
#include <set>
#include "cast_utils.h"
#include "vk_format_utils.h"
#include "vk_layer_logging.h"

#ifndef WIN32
#include <strings.h>  // For ffs()
#else
#include <intrin.h>  // For __lzcnt()
#endif

#define STRINGIFY(s) STRINGIFY_HELPER(s)
#define STRINGIFY_HELPER(s) #s

#ifdef __cplusplus
// Traits objects to allow string_join to operate on collections of const char *
template <typename String>
struct StringJoinSizeTrait {
    static size_t size(const String &str) { return str.size(); }
};

template <>
struct StringJoinSizeTrait<const char *> {
    static size_t size(const char *str) {
        if (!str) return 0;
        return strlen(str);
    }
};
// Similar to perl/python join
//    * String must support size, reserve, append, and be default constructable
//    * StringCollection must support size, const forward iteration, and store
//      strings compatible with String::append
//    * Accessor trait can be set if default accessors (compatible with string
//      and const char *) don't support size(StringCollection::value_type &)
//
// Return type based on sep type
template <typename String = std::string, typename StringCollection = std::vector<String>,
          typename Accessor = StringJoinSizeTrait<typename StringCollection::value_type>>
static inline String string_join(const String &sep, const StringCollection &strings) {
    String joined;
    const size_t count = strings.size();
    if (!count) return joined;

    // Prereserved storage, s.t. we will execute in linear time (avoids reallocation copies)
    size_t reserve = (count - 1) * sep.size();
    for (const auto &str : strings) {
        reserve += Accessor::size(str);  // abstracted to allow const char * type in StringCollection
    }
    joined.reserve(reserve + 1);

    // Seps only occur *between* strings entries, so first is special
    auto current = strings.cbegin();
    joined.append(*current);
    ++current;
    for (; current != strings.cend(); ++current) {
        joined.append(sep);
        joined.append(*current);
    }
    return joined;
}

// Requires StringCollection::value_type has a const char * constructor and is compatible the string_join::String above
template <typename StringCollection = std::vector<std::string>, typename SepString = std::string>
static inline SepString string_join(const char *sep, const StringCollection &strings) {
    return string_join<SepString, StringCollection>(SepString(sep), strings);
}

static inline std::string string_trim(const std::string &s) {
    const char *whitespace = " \t\f\v\n\r";

    const auto trimmed_beg = s.find_first_not_of(whitespace);
    if (trimmed_beg == std::string::npos) return "";

    const auto trimmed_end = s.find_last_not_of(whitespace);
    assert(trimmed_end != std::string::npos && trimmed_beg <= trimmed_end);

    return s.substr(trimmed_beg, trimmed_end - trimmed_beg + 1);
}

// Perl/Python style join operation for general types using stream semantics
// Note: won't be as fast as string_join above, but simpler to use (and code)
// Note: Modifiable reference doesn't match the google style but does match std style for stream handling and algorithms
template <typename Stream, typename String, typename ForwardIt>
Stream &stream_join(Stream &stream, const String &sep, ForwardIt first, ForwardIt last) {
    if (first != last) {
        stream << *first;
        ++first;
        while (first != last) {
            stream << sep << *first;
            ++first;
        }
    }
    return stream;
}

// stream_join For whole collections with forward iterators
template <typename Stream, typename String, typename Collection>
Stream &stream_join(Stream &stream, const String &sep, const Collection &values) {
    return stream_join(stream, sep, values.cbegin(), values.cend());
}

typedef void *dispatch_key;
static inline dispatch_key get_dispatch_key(const void *object) { return (dispatch_key) * (VkLayerDispatchTable **)object; }

VK_LAYER_EXPORT VkLayerInstanceCreateInfo *get_chain_info(const VkInstanceCreateInfo *pCreateInfo, VkLayerFunction func);
VK_LAYER_EXPORT VkLayerDeviceCreateInfo *get_chain_info(const VkDeviceCreateInfo *pCreateInfo, VkLayerFunction func);

static inline bool IsPowerOfTwo(unsigned x) { return x && !(x & (x - 1)); }

extern "C" {
#endif

#define VK_LAYER_API_VERSION VK_MAKE_VERSION(1, 0, VK_HEADER_VERSION)

typedef enum VkStringErrorFlagBits {
    VK_STRING_ERROR_NONE = 0x00000000,
    VK_STRING_ERROR_LENGTH = 0x00000001,
    VK_STRING_ERROR_BAD_DATA = 0x00000002,
} VkStringErrorFlagBits;
typedef VkFlags VkStringErrorFlags;

VK_LAYER_EXPORT void layer_debug_report_actions(debug_report_data *report_data, const VkAllocationCallbacks *pAllocator,
                                                const char *layer_identifier);

VK_LAYER_EXPORT void layer_debug_messenger_actions(debug_report_data *report_data, const VkAllocationCallbacks *pAllocator,
                                                   const char *layer_identifier);

VK_LAYER_EXPORT VkStringErrorFlags vk_string_validate(const int max_length, const char *char_array);
VK_LAYER_EXPORT bool white_list(const char *item, const std::set<std::string> &whitelist);

static inline int u_ffs(int val) {
#ifdef WIN32
    unsigned long bit_pos = 0;
    if (_BitScanForward(&bit_pos, val) != 0) {
        bit_pos += 1;
    }
    return bit_pos;
#else
    return ffs(val);
#endif
}

#ifdef __cplusplus
}
#endif

// shared_mutex support added in MSVC 2015 update 2
#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023918 && NTDDI_VERSION > NTDDI_WIN10_RS2
#include <shared_mutex>
#endif

class ReadWriteLock {
  private:
#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023918 && NTDDI_VERSION > NTDDI_WIN10_RS2
    typedef std::shared_mutex lock_t;
#else
    typedef std::mutex lock_t;
#endif

  public:
    void lock() { m_lock.lock(); }
    bool try_lock() { return m_lock.try_lock(); }
    void unlock() { m_lock.unlock(); }
#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023918 && NTDDI_VERSION > NTDDI_WIN10_RS2
    void lock_shared() { m_lock.lock_shared(); }
    bool try_lock_shared() { return m_lock.try_lock_shared(); }
    void unlock_shared() { m_lock.unlock_shared(); }
#else
    void lock_shared() { lock(); }
    bool try_lock_shared() { return try_lock(); }
    void unlock_shared() { unlock(); }
#endif
  private:
    lock_t m_lock;
};

#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023918 && NTDDI_VERSION > NTDDI_WIN10_RS2
typedef std::shared_lock<ReadWriteLock> read_lock_guard_t;
typedef std::unique_lock<ReadWriteLock> write_lock_guard_t;
#else
typedef std::unique_lock<ReadWriteLock> read_lock_guard_t;
typedef std::unique_lock<ReadWriteLock> write_lock_guard_t;
#endif

// Limited concurrent_unordered_map that supports internally-synchronized
// insert/erase/access. Splits locking across N buckets and uses shared_mutex
// for read/write locking. Iterators are not supported. The following
// operations are supported:
//
// insert_or_assign: Insert a new element or update an existing element.
// insert: Insert a new element and return whether it was inserted.
// erase: Remove an element.
// contains: Returns true if the key is in the map.
// find: Returns != end() if found, value is in ret->second.
// pop: Erases and returns the erased value if found.
//
// find/end: find returns a vaguely iterator-like type that can be compared to
// end and can use iter->second to retrieve the reference. This is to ease porting
// for existing code that combines the existence check and lookup in a single
// operation (and thus a single lock). i.e.:
//
//      auto iter = map.find(key);
//      if (iter != map.end()) {
//          T t = iter->second;
//          ...
//
// snapshot: Return an array of elements (key, value pairs) that satisfy an optional
// predicate. This can be used as a substitute for iterators in exceptional cases.
template <typename Key, typename T, int BUCKETSLOG2 = 2, typename Hash = std::hash<Key>>
class vl_concurrent_unordered_map {
  public:
    void insert_or_assign(const Key &key, const T &value) {
        uint32_t h = ConcurrentMapHashObject(key);
        write_lock_guard_t lock(locks[h].lock);
        maps[h][key] = value;
    }

    bool insert(const Key &key, const T &value) {
        uint32_t h = ConcurrentMapHashObject(key);
        write_lock_guard_t lock(locks[h].lock);
        auto ret = maps[h].insert(typename std::unordered_map<Key, T>::value_type(key, value));
        return ret.second;
    }

    // returns size_type
    size_t erase(const Key &key) {
        uint32_t h = ConcurrentMapHashObject(key);
        write_lock_guard_t lock(locks[h].lock);
        return maps[h].erase(key);
    }

    bool contains(const Key &key) const {
        uint32_t h = ConcurrentMapHashObject(key);
        read_lock_guard_t lock(locks[h].lock);
        return maps[h].count(key) != 0;
    }

    // type returned by find() and end().
    class FindResult {
      public:
        FindResult(bool a, T b) : result(a, std::move(b)) {}

        // == and != only support comparing against end()
        bool operator==(const FindResult &other) const {
            if (result.first == false && other.result.first == false) {
                return true;
            }
            return false;
        }
        bool operator!=(const FindResult &other) const { return !(*this == other); }

        // Make -> act kind of like an iterator.
        std::pair<bool, T> *operator->() { return &result; }
        const std::pair<bool, T> *operator->() const { return &result; }

      private:
        // (found, reference to element)
        std::pair<bool, T> result;
    };

    // find()/end() return a FindResult containing a copy of the value. For end(),
    // return a default value.
    FindResult end() const { return FindResult(false, T()); }

    FindResult find(const Key &key) const {
        uint32_t h = ConcurrentMapHashObject(key);
        read_lock_guard_t lock(locks[h].lock);

        auto itr = maps[h].find(key);
        bool found = itr != maps[h].end();

        if (found) {
            return FindResult(true, itr->second);
        } else {
            return end();
        }
    }

    FindResult pop(const Key &key) {
        uint32_t h = ConcurrentMapHashObject(key);
        write_lock_guard_t lock(locks[h].lock);

        auto itr = maps[h].find(key);
        bool found = itr != maps[h].end();

        if (found) {
            auto ret = std::move(FindResult(true, itr->second));
            maps[h].erase(itr);
            return ret;
        } else {
            return end();
        }
    }

    std::vector<std::pair<const Key, T>> snapshot(std::function<bool(T)> f = nullptr) const {
        std::vector<std::pair<const Key, T>> ret;
        for (int h = 0; h < BUCKETS; ++h) {
            read_lock_guard_t lock(locks[h].lock);
            for (auto j : maps[h]) {
                if (!f || f(j.second)) {
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }

  private:
    static const int BUCKETS = (1 << BUCKETSLOG2);

    std::unordered_map<Key, T, Hash> maps[BUCKETS];
    struct {
        mutable ReadWriteLock lock;
        // Put each lock on its own cache line to avoid false cache line sharing.
        char padding[(-int(sizeof(ReadWriteLock))) & 63];
    } locks[BUCKETS];

    uint32_t ConcurrentMapHashObject(const Key &object) const {
        uint64_t u64 = (uint64_t)(uintptr_t)object;
        uint32_t hash = (uint32_t)(u64 >> 32) + (uint32_t)u64;
        hash ^= (hash >> BUCKETSLOG2) ^ (hash >> (2 * BUCKETSLOG2));
        hash &= (BUCKETS - 1);
        return hash;
    }
};
