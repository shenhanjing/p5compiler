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

// 对接 search engine / key 的上下文封装，内部自带实例。
class BuiltInContext {
public:
    BuiltInContext() = default;

    template <typename T>
        inline T _key() const {
            return key_.getKey<T>(bit_width_of_type<T>());
    }

        inline uint8_t _status(int tableId = 0) const {
            return static_cast<uint8_t>(se_.status(tableId));
    }

    template <typename Value, typename Key>
    inline _inflate<Value> _lookup(int tableId, int lookupType, const Key &key) {
        const auto mt = static_cast<MatchType>(lookupType);
            auto result = se_.lookup<Key, Value>(tableId, mt, key);
        if (result) {
            return *result;  // valid=true via _inflate(Value)
        }
        return std::nullopt; // valid=false
    }

    template <typename... Parts>
    inline void buildKey(const Parts &...parts) {
        key_.buildKey(parts...);
    }

    // Incremental key construction:
    // auto kb = ctx.keyBuilder(); kb.append(...); ...; kb.commit();
    inline KeyManager::KeyBuilder keyBuilder() { return key_.keyBuilder(); }

    template <typename T>
        inline bool _valid(const _inflate<T> &v) const {
        return v.valid;
    }

    template <typename T>
    inline void _memcpy(T &dst, const T &src) {
        dst = src;
    }

    SearchEngine &searchEngine() { return se_; }
    KeyManager &keyManager() { return key_; }

private:
    SearchEngine se_;
    KeyManager key_;
};

#endif // BUILTIN_HPP