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
 * Author: Tobin Ehlis <tobine@google.com>
 */

#ifndef LAYER_DATA_H
#define LAYER_DATA_H

#include <cassert>
#include <unordered_map>
#include <unordered_set>

// This is a wrapper around unordered_map that optimizes for the common case
// of only containing a small number of elements. The first N elements are stored
// inline in the object and don't require hashing or memory (de)allocation.

template <typename Key, typename value_type, typename inner_container_type, typename value_type_helper, int N>
class small_container {
  protected:
    bool small_data_allocated[N];
    value_type small_data[N];

    inner_container_type inner_cont;

  public:
    small_container() {
        for (int i = 0; i < N; ++i) {
            small_data_allocated[i] = false;
        }
    }

    class iterator {
        typedef typename inner_container_type::iterator inner_iterator;
        friend class small_container<Key, value_type, inner_container_type, value_type_helper, N>;

        small_container<Key, value_type, inner_container_type, value_type_helper, N> *parent;
        int index;
        inner_iterator it;

      public:
        iterator() {}

        iterator operator++() {
            if (index < N) {
                index++;
                while (index < N && !parent->small_data_allocated[index]) {
                    index++;
                }
                if (index < N) {
                    return *this;
                }
                it = parent->inner_cont.begin();
                return *this;
            }
            ++it;
            return *this;
        }

        bool operator==(const iterator &other) const {
            if ((index < N) != (other.index < N)) {
                return false;
            }
            if (index < N) {
                return (index == other.index);
            }
            return it == other.it;
        }

        bool operator!=(const iterator &other) const { return !(*this == other); }

        value_type &operator*() const {
            if (index < N) {
                return parent->small_data[index];
            }
            return *it;
        }
        value_type *operator->() const {
            if (index < N) {
                return &parent->small_data[index];
            }
            return &*it;
        }
    };

    class const_iterator {
        typedef typename inner_container_type::const_iterator inner_iterator;
        friend class small_container<Key, value_type, inner_container_type, value_type_helper, N>;

        const small_container<Key, value_type, inner_container_type, value_type_helper, N> *parent;
        int index;
        inner_iterator it;

      public:
        const_iterator() {}

        const_iterator operator++() {
            if (index < N) {
                index++;
                while (index < N && !parent->small_data_allocated[index]) {
                    index++;
                }
                if (index < N) {
                    return *this;
                }
                it = parent->inner_cont.begin();
                return *this;
            }
            ++it;
            return *this;
        }

        bool operator==(const const_iterator &other) const {
            if ((index < N) != (other.index < N)) {
                return false;
            }
            if (index < N) {
                return (index == other.index);
            }
            return it == other.it;
        }

        bool operator!=(const const_iterator &other) const { return !(*this == other); }

        const value_type &operator*() const {
            if (index < N) {
                return parent->small_data[index];
            }
            return *it;
        }
        const value_type *operator->() const {
            if (index < N) {
                return &parent->small_data[index];
            }
            return &*it;
        }
    };

    iterator begin() {
        iterator it;
        it.parent = this;
        // If index 0 is allocated, return it, otherwise use operator++ to find the first
        // allocated element.
        it.index = 0;
        if (small_data_allocated[0]) {
            return it;
        }
        ++it;
        return it;
    }

    iterator end() {
        iterator it;
        it.parent = this;
        it.index = N;
        it.it = inner_cont.end();
        return it;
    }

    const_iterator begin() const {
        const_iterator it;
        it.parent = this;
        // If index 0 is allocated, return it, otherwise use operator++ to find the first
        // allocated element.
        it.index = 0;
        if (small_data_allocated[0]) {
            return it;
        }
        ++it;
        return it;
    }

    const_iterator end() const {
        const_iterator it;
        it.parent = this;
        it.index = N;
        it.it = inner_cont.end();
        return it;
    }

    bool contains(const Key &key) const {
        for (int i = 0; i < N; ++i) {
            if (value_type_helper().compare_equal(small_data[i], key) && small_data_allocated[i]) {
                return true;
            }
        }
        // check size() first to avoid hashing key unnecessarily.
        if (inner_cont.size() == 0) {
            return false;
        }
        return inner_cont.find(key) != inner_cont.end();
    }

    typename inner_container_type::size_type count(const Key &key) const { return contains(key) ? 1 : 0; }

    std::pair<iterator, bool> insert(const value_type &value) {
        for (int i = 0; i < N; ++i) {
            if (value_type_helper().compare_equal(small_data[i], value) && small_data_allocated[i]) {
                iterator it;
                it.parent = this;
                it.index = i;
                return std::make_pair(it, false);
            }
        }
        // check size() first to avoid hashing key unnecessarily.
        auto iter = inner_cont.size() > 0 ? inner_cont.find(value_type_helper().get_key(value)) : inner_cont.end();
        if (iter != inner_cont.end()) {
            iterator it;
            it.parent = this;
            it.index = N;
            it.it = iter;
            return std::make_pair(it, false);
        } else {
            for (int i = 0; i < N; ++i) {
                if (!small_data_allocated[i]) {
                    small_data_allocated[i] = true;
                    value_type_helper().assign(small_data[i], value);
                    iterator it;
                    it.parent = this;
                    it.index = i;
                    return std::make_pair(it, true);
                }
            }
            iter = inner_cont.insert(value).first;
            iterator it;
            it.parent = this;
            it.index = N;
            it.it = iter;
            return std::make_pair(it, true);
        }
    }

    typename inner_container_type::size_type erase(const Key &key) {
        for (int i = 0; i < N; ++i) {
            if (value_type_helper().compare_equal(small_data[i], key) && small_data_allocated[i]) {
                small_data_allocated[i] = false;
                return 1;
            }
        }
        return inner_cont.erase(key);
    }

    typename inner_container_type::size_type size() const {
        auto size = inner_cont.size();
        for (int i = 0; i < N; ++i) {
            if (small_data_allocated[i]) {
                size++;
            }
        }
        return size;
    }

    bool empty() const {
        for (int i = 0; i < N; ++i) {
            if (small_data_allocated[i]) {
                return false;
            }
        }
        return inner_cont.size() == 0;
    }

    void clear() {
        for (int i = 0; i < N; ++i) {
            small_data_allocated[i] = false;
        }
        inner_cont.clear();
    }
};

// Helper function objects to compare/assign/get keys in small_unordered_set/map.
// This helps to abstract away whether value_type is a Key or a pair<Key, T>.
template <typename Key, typename T>
class value_type_helper_map {
  public:
    bool compare_equal(const std::pair<const Key, T> &lhs, const Key &rhs) const { return lhs.first == rhs; }
    bool compare_equal(const std::pair<const Key, T> &lhs, const std::pair<const Key, T> &rhs) const {
        return lhs.first == rhs.first;
    }

    void assign(std::pair<const Key, T> &lhs, const std::pair<Key, T> &rhs) const {
        // While the const_cast may be unsatisfactory, we are using small_data as
        // stand-in for placement new and a small-block allocator, so the const_cast
        // is minimal, contained, valid, and allows operators * and -> to avoid copies
        const_cast<Key &>(lhs.first) = rhs.first;
        lhs.second = rhs.second;
    }

    Key get_key(const std::pair<const Key, T> &value) const { return value.first; }
};

template <typename Key>
class value_type_helper_set {
  public:
    bool compare_equal(const Key &lhs, const Key &rhs) const { return lhs == rhs; }

    void assign(Key &lhs, const Key &rhs) const { lhs = rhs; }

    Key get_key(const Key &value) const { return value; }
};

template <typename Key, typename T, int N = 1>
class small_unordered_map
    : public small_container<Key, std::pair<const Key, T>, std::unordered_map<Key, T>, value_type_helper_map<Key, T>, N> {
  public:
    T &operator[](const Key &key) {
        for (int i = 0; i < N; ++i) {
            if (value_type_helper_map<Key, T>().compare_equal(this->small_data[i], key) && this->small_data_allocated[i]) {
                return this->small_data[i].second;
            }
        }
        auto iter = this->inner_cont.find(key);
        if (iter != this->inner_cont.end()) {
            return iter->second;
        } else {
            for (int i = 0; i < N; ++i) {
                if (!this->small_data_allocated[i]) {
                    this->small_data_allocated[i] = true;
                    value_type_helper_map<Key, T>().assign(this->small_data[i], std::make_pair(key, T()));

                    return this->small_data[i].second;
                }
            }
            return this->inner_cont[key];
        }
    }
};

template <typename Key, int N = 1>
class small_unordered_set : public small_container<Key, Key, std::unordered_set<Key>, value_type_helper_set<Key>, N> {};

// For the given data key, look up the layer_data instance from given layer_data_map
template <typename DATA_T>
DATA_T *GetLayerDataPtr(void *data_key, small_unordered_map<void *, DATA_T *, 2> &layer_data_map) {
    /* TODO: We probably should lock here, or have caller lock */
    DATA_T *&got = layer_data_map[data_key];

    if (got == nullptr) {
        got = new DATA_T;
    }

    return got;
}

template <typename DATA_T>
void FreeLayerDataPtr(void *data_key, small_unordered_map<void *, DATA_T *, 2> &layer_data_map) {
    delete layer_data_map[data_key];
    layer_data_map.erase(data_key);
}

// For the given data key, look up the layer_data instance from given layer_data_map
template <typename DATA_T>
DATA_T *GetLayerDataPtr(void *data_key, std::unordered_map<void *, DATA_T *> &layer_data_map) {
    DATA_T *debug_data;
    typename std::unordered_map<void *, DATA_T *>::const_iterator got;

    /* TODO: We probably should lock here, or have caller lock */
    got = layer_data_map.find(data_key);

    if (got == layer_data_map.end()) {
        debug_data = new DATA_T;
        layer_data_map[(void *)data_key] = debug_data;
    } else {
        debug_data = got->second;
    }

    return debug_data;
}

template <typename DATA_T>
void FreeLayerDataPtr(void *data_key, std::unordered_map<void *, DATA_T *> &layer_data_map) {
    auto got = layer_data_map.find(data_key);
    assert(got != layer_data_map.end());

    delete got->second;
    layer_data_map.erase(got);
}

#endif  // LAYER_DATA_H
