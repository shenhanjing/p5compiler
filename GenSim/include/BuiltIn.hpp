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
#include <vector>

#include <boost/pfr.hpp>

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

template <typename T>
struct is_p5_member : std::false_type {};
template <typename UIntT>
struct is_p5_member<p5::member<UIntT>> : std::true_type {};

template <typename T>
struct is_p5_union : std::false_type {};
template <typename Layout>
struct is_p5_union<p5::Union<Layout>> : std::true_type {};

template <typename...>
struct always_false : std::false_type {};

template <typename T>
inline void append_bits_msb_first(const T &value, std::vector<bool> &out) {
    using D = std::decay_t<T>;
    if constexpr (is_p5_uint<D>::value) {
        constexpr std::size_t N = D::width();
        for (std::size_t i = 0; i < N; ++i) out.push_back(value[N - 1 - i]);
    } else if constexpr (is_p5_member<D>::value) {
        constexpr std::size_t N = D::width();
        for (std::size_t i = 0; i < N; ++i) out.push_back(value[N - 1 - i]);
    } else if constexpr (is_p5_union<D>::value) {
        // Convert union to its raw uint view and append.
        auto raw = value.to_uint();
        constexpr std::size_t N = decltype(raw)::width();
        for (std::size_t i = 0; i < N; ++i) out.push_back(raw[N - 1 - i]);
    } else if constexpr (std::is_aggregate_v<D>) {
        boost::pfr::for_each_field(value, [&](const auto &sub) { append_bits_msb_first(sub, out); });
    } else {
        static_assert(always_false<T>::value,
                      "Key pack supports p5::uint/p5::member/p5::Union or aggregates composed of them.");
    }
}

template <typename Key>
inline auto pack_key_to_uint(const Key &key) {
    using D = std::decay_t<Key>;
    constexpr std::size_t Bits = p5::bit_width_v<D>;
    static_assert(Bits > 0, "Key bit width must be > 0");
    static_assert(Bits <= 256, "Packed key width exceeds p5::uint<N> supported range (<=256)");
    std::vector<bool> bits;
    bits.reserve(Bits);
    append_bits_msb_first(key, bits);
    // Defensive: if someone passes an aggregate with unexpected width, clamp/pad via from_bits behavior.
    return p5::uint<Bits>::from_bits(bits);
}
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

    // Assign key bits into an output variable (supports p5::uint/p5::member/p5::Union
    // and aggregates composed of them).
    template <typename T>
    inline T &_key(T &out) const { return key_.assignKey(out); }

    // If caller needs to check whether a matching key slot existed.
    template <typename T>
    inline bool _try_key(T &out) const { return key_.tryAssignKey(out); }

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
        // If the key is an aggregate/union/member, pack it into a contiguous p5::uint<bits>
        // by concatenating all fields MSB-first (same bit ordering as KeyManager buildKey).
        using DK = std::decay_t<Key>;
        if constexpr (detail_builtin::is_p5_uint<DK>::value) {
            auto result = se_.lookup<Key, Value>(tableId, mt, key);
            if (result) return *result;
            return std::nullopt;
        } else {
            auto packed = detail_builtin::pack_key_to_uint(key);
            using PackedKey = decltype(packed);
            auto result = se_.lookup<PackedKey, Value>(tableId, mt, packed);
            if (result) return *result;
            return std::nullopt;
        }
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
        // NOTE:
        // - 目前仅实现 demo 中用到的“同类型之间”的 _memcpy（语义等价于赋值拷贝）。
        // - 后续会补充“不同类型之间”的版本（例如不同 struct 之间的字段级拷贝或按位宽拷贝），以覆盖更完整的 P5 内置语义。
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