#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include <cstddef>
#include <cstdint>
#include <optional>
#include <initializer_list>
#include <cstring>
#include <algorithm>
#include <type_traits>

#include "key.hpp"
#include "SE.hpp"
#include "p5_types.hpp"

template <typename T>
constexpr std::size_t bit_width_of_type();

namespace detail_builtin {
template <typename T>
struct is_p5_uint : std::false_type {};
template <std::size_t N>
struct is_p5_uint<p5::uint<N>> : std::true_type {};

template <typename...>
struct always_false : std::false_type {};
}  // namespace detail_builtin

// Helper: bit width of a type (only p5::uint<N> is supported).
template <typename T>
constexpr std::size_t bit_width_of_type() {
    using Decayed = std::decay_t<T>;
    if constexpr (detail_builtin::is_p5_uint<Decayed>::value) {
        return Decayed::width();
    } else {
        static_assert(detail_builtin::always_false<T>::value, "bit_width_of_type only supports p5::uint<N>");
        return 0;
    }
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
            // Explicit {0}: keep zeroed payload, valid=false.
            return;
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

#endif // BUILTIN_HPP