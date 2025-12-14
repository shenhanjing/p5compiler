#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <initializer_list>
#include <cstring>
#include <algorithm>
#include <type_traits>

#include "key.h"
#include "SE.h"

// Helper: bit width of an integral type.
template <typename T>
constexpr std::size_t bit_width_of_type() {
    return sizeof(T) * 8;
}

// Wrap original struct with a validity flag; defaults to zeroed payload + valid=false.
template <typename T>
struct _inflate : public T {
    using value_type = T;
    bool valid;

    _inflate() : T{}, valid(false) {}
    _inflate(const T &v) : T(v), valid(true) {}
    _inflate(std::nullopt_t) : T{}, valid(false) {}
    _inflate(std::initializer_list<int> ilist) : T{}, valid(false) {
        if (ilist.size() == 1 && *ilist.begin() == 0) {
            valid = false;  // explicit {0} => zeroed payload, valid=false
        } else if (ilist.size() > 0) {
            // Fill fields with the first element best-effort; mark as valid.
            const int v = *ilist.begin();
            std::memset(static_cast<T *>(this), 0, sizeof(T));
            std::memcpy(static_cast<T *>(this), &v, std::min(sizeof(T), sizeof(v)));
            valid = true;
        }
    }

    _inflate &operator=(const T &v) {
        static_cast<T &>(*this) = v;
        valid = true;
        return *this;
    }

    _inflate &operator=(std::nullopt_t) {
        static_cast<T &>(*this) = T{};
        valid = false;
        return *this;
    }
};

// These are stubs; real implementations should hook into the actual table engine.
template <typename T>
inline T _key() {
    return g_key.getKey<T>(bit_width_of_type<T>());
}

inline uint8_t _status(int tableId = 0) {
    return static_cast<uint8_t>(g_se.status(tableId));
}

// Return an inflated value; on miss, valid=false with zeroed payload.
template <typename Value, typename Key>
inline _inflate<Value> _lookup(int tableId, int lookupType, const Key &key) {
    const auto mt = static_cast<MatchType>(lookupType);
    auto result = g_se.lookup<Key, Value>(tableId, mt, key);
    if (result) {
        return *result;  // valid=true via _inflate(Value)
    }
    return std::nullopt; // valid=false
}

template <typename T>
inline bool _valid(const _inflate<T> &v) {
    return v.valid;
}

template <typename T>
inline void _memcpy(T &dst, const T &src) {
    dst = src;
}

