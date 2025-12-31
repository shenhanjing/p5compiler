#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include <cstddef>
#include <any>
#include <cstdint>
#include <optional>
#include <initializer_list>
#include <cstring>
#include <algorithm>
#include <type_traits>
#include <utility>

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
    BuiltInContext()
        : table_id(se_.table_id),
          command(se_.command),
          ma_id(0),
          _header_access(0),
          decomp_profile(0),
          control_info(&stored_control_info_) {}

    // *********************** Control Parameters ***********************
    // Expose SearchEngine control parameters as public members.
    // These are references bound to the underlying se_ instance, so any updates
    // are reflected back into SearchEngine immediately.
    uint16_t &table_id;
    uint16_t &command;
    inline uint16_t _table_id() const { return table_id; }
    inline uint16_t _command() const { return command; }

    uint16_t ma_id;
    uint16_t _header_access;
    uint16_t decomp_profile;
    inline uint16_t _profile_id() const { return decomp_profile; }

    // Store arbitrary "control_info" value (supports any type, including aggregates via {}).
    // We expose a proxy so generated code can do:
    //   control_info = (Type){...};   // GCC compound-literal extension in C++
    // and users can retrieve via:
    //   Type v = _control_info();
    struct ControlInfoProxy {
        std::any *slot{nullptr};

        explicit ControlInfoProxy(std::any *slot_in = nullptr) : slot(slot_in) {}

        template <typename T>
        ControlInfoProxy &operator=(T &&value) {
            if (slot) {
                *slot = std::forward<T>(value);
            }
            return *this;
        }

        template <typename T>
        T as() const {
            return slot ? std::any_cast<T>(*slot) : T{};
        }

        template <typename T>
        operator T() const {
            return as<T>();
        }

        bool has_value() const { return slot && slot->has_value(); }
    };

    ControlInfoProxy control_info;

    inline const ControlInfoProxy &_control_info() const { return control_info; }

    // *********************** _key() ***********************
    template <typename T>
    inline T _key() const {
        return key_.getKey<T>(bit_width_of_type<T>());
    }

    // *********************** _status() ***********************
    // No-arg form: return an "empty" value for declarations like:
    //   p5::uint<2> IpatStatus = _status();
    // This initialization is semantically a no-op in the generated flow.
    inline uint8_t _status() const { return 2; }

    // Table-specific status query (real lookup status).
    inline uint8_t _status(int tableId) const { return static_cast<uint8_t>(se_.status(tableId)); }

    // *********************** _lookup() ***********************
    template <typename Value, typename Key>
    inline _inflate<Value> _lookup(int tableId, int lookupType, const Key &key) {
        const auto mt = static_cast<MatchType>(lookupType);
            auto result = se_.lookup<Key, Value>(tableId, mt, key);
        if (result) {
            return *result;  // valid=true via _inflate(Value)
        }
        return std::nullopt; // valid=false
    }

    // *********************** Key Construction ***********************
    template <typename... Parts>
    inline void buildKey(const Parts &...parts) {
        key_.buildKey(parts...);
    }

    // Incremental key construction:
    // auto kb = ctx.keyBuilder(); kb.append(...); ...; kb.commit();
    inline KeyManager::KeyBuilder keyBuilder() { return key_.keyBuilder(); }

    // *********************** _valid() ***********************
    template <typename T>
        inline bool _valid(const _inflate<T> &v) const {
        return v.valid;
    }

    // *********************** _memcpy() ***********************
    template <typename T>
    inline void _memcpy(T &dst, const T &src) {
        dst = src;
    }

    // *********************** searchEngine() ***********************
    SearchEngine &searchEngine() { return se_; }

    // *********************** keyManager() ***********************
    KeyManager &keyManager() { return key_; }

protected:
    SearchEngine se_;
    KeyManager key_;

    // Backing storage for control_info.
    std::any stored_control_info_;
};

#endif // BUILTIN_HPP