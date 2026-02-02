#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include <cstddef>
#include <any>
#include <cstdint>
#include <optional>
#include <initializer_list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <utility>
#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <memory>

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

// Type traits for _list_flatten: detect if a type is std::vector
template <typename T>
struct is_vector : std::false_type {};

template <typename T>
struct is_vector<std::vector<T>> : std::true_type {};

// Recursively extract the innermost element type from nested vectors
// Example: vector<vector<int>> -> int
template <typename T>
struct flatten_element_type {
    using type = T;
};

template <typename T>
struct flatten_element_type<std::vector<T>> {
    using type = typename flatten_element_type<T>::type;
};

template <typename T>
using flatten_element_type_t = typename flatten_element_type<T>::type;

// Recursive flatten helper function
// Base case: element is not a vector, add it directly
template <typename ElemType>
inline void flatten_into(const ElemType& elem, std::vector<ElemType>& result) {
    result.push_back(elem);
}

// Recursive case: element is a vector, recursively flatten its elements
template <typename InnerType>
inline void flatten_into(const std::vector<InnerType>& elem,
                         std::vector<flatten_element_type_t<InnerType>>& result) {
    for (const auto& sub_elem : elem) {
        flatten_into(sub_elem, result);
    }
}

// Helper function for _slice: common implementation
template <typename T>
inline std::vector<T> slice_impl(const std::vector<T>& list_variable,
                                  size_t start_idx, size_t end_idx,
                                  bool start_negative = false, bool end_negative = false) {
    std::vector<T> result;

    if (list_variable.empty()) {
        return result;
    }

    // 如果 end 是负数，返回空列表
    if (end_negative) {
        return result;
    }

    // 如果 start 是负数，将其视为 0
    if (start_negative) {
        start_idx = 0;
    }

    // 边界检查：确保索引在有效范围内
    size_t list_size = list_variable.size();
    start_idx = std::min(start_idx, list_size);
    end_idx = std::min(end_idx, list_size - 1);  // end 索引最大为 size-1

    // 如果 start > end，返回空列表
    if (start_idx > end_idx) {
        return result;
    }

    // 提取子列表 [start_idx, end_idx]（包含两端）
    result.reserve(end_idx - start_idx + 1);
    for (size_t i = start_idx; i <= end_idx; ++i) {
        result.push_back(list_variable[i]);
    }

    return result;
}

// Helper for _map: field name mapping structure
// Users need to specialize this template for each struct type they want to use with _map
template <typename StructType>
struct struct_field_names {
    // Default: empty array, users must specialize for their struct types
    static constexpr const char* names[] = {};
    static constexpr std::size_t count = 0;
};

// Helper: find field index by field name (case-sensitive)
template <typename StructType>
inline std::size_t find_field_index(const char* field_name) {
    constexpr auto& names = struct_field_names<StructType>::names;
    constexpr std::size_t name_count = struct_field_names<StructType>::count;
    constexpr std::size_t field_count = boost::pfr::tuple_size_v<StructType>;
    
    // Check if field names are defined
    if (name_count == 0) {
        throw std::runtime_error("Field names not defined for this struct type. "
                                "Please specialize struct_field_names template.");
    }
    
    // Verify field count matches
    if (name_count != field_count) {
        throw std::runtime_error("Field name count does not match struct field count.");
    }
    
    // Find matching field name (case-sensitive)
    for (std::size_t i = 0; i < name_count; ++i) {
        if (std::strcmp(names[i], field_name) == 0) {
            return i;
        }
    }
    
    return SIZE_MAX; // Not found
}

// Helper: extract field value by index
template <typename StructType, std::size_t FieldIndex>
inline auto map_field_by_index_impl(const std::vector<StructType>& struct_list) {
    using FieldType = std::decay_t<decltype(boost::pfr::get<FieldIndex>(std::declval<StructType>()))>;
    std::vector<FieldType> result;
    result.reserve(struct_list.size());
    for (const auto& obj : struct_list) {
        result.push_back(boost::pfr::get<FieldIndex>(obj));
    }
    return result;
}

// Helper: dispatch wrapper using function template overloading
// Each index gets its own overloaded function to avoid return type deduction issues
template <typename StructType>
struct map_field_dispatch_wrapper {
    template <std::size_t Index>
    static auto dispatch_impl(const std::vector<StructType>& struct_list) {
        return map_field_by_index_impl<StructType, Index>(struct_list);
    }
};






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

// Global _sizeof function: returns bit width (in bits) based on argument type.
template <typename T>
constexpr std::size_t _sizeof(const T&) {
    using Decayed = std::decay_t<T>;
    return p5::bit_width_v<Decayed>;
}

// Global _lenof function: can be called without context instance
template <typename T>
inline p5::uint<16> _lenof(const std::vector<T>& v) {
    return p5::uint<16>(v.size());
}

template <typename T, std::size_t N>
inline p5::uint<16> _lenof(const T (&arr)[N]) {
    return p5::uint<16>(N);
}

// Global _log2 function: integer floor(log2(n)).
// - Accepts integral constants like: _log2(33)
// - Returns 0 for n <= 0
// - Returns an unsigned integer
template <typename Int>
constexpr std::uint32_t _log2(Int n) {
    static_assert(std::is_integral_v<std::decay_t<Int>>, "_log2 requires an integral argument");

    std::uint64_t x = 0;
    if constexpr (std::is_signed_v<std::decay_t<Int>>) {
        if (n <= 0) return 0;
        x = static_cast<std::uint64_t>(n);
    } else {
        x = static_cast<std::uint64_t>(n);
        if (x == 0) return 0;
    }

    std::uint32_t r = 0;
    while (x > 1) {
        x >>= 1;
        ++r;
    }
    return r;
}

// Global _printf function: can be called without context instance
template <typename... Args>
inline void _printf(const char* format, Args&&... args) {
    std::printf(format, std::forward<Args>(args)...);
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

// Parser transition info "wrapper" that preserves the original type exactly.
// This is intentionally NOT a struct/class wrapper: alias templates make
//   _prs_trans_info<T>
// identical to T, so e.g.
//   using ParserTransInfo_S = _prs_trans_info<TransInfo_S>;
// is exactly the same as:
//   using ParserTransInfo_S = TransInfo_S;
template <typename T>
using _prs_trans_info = T;

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

    // Generic validity storage for arbitrary variables.
    // - Keyed by the variable's address.
    // - If address not present, it's inserted with valid=false (0).
    // - Returned proxy can be used on RHS (read) or LHS (write), e.g.:
    //     if (_valid(x)) { ... }
    //     _valid(x) = 1;
    struct ValidProxy {
        const BuiltInContext *ctx{nullptr};
        const void *addr{nullptr};

        explicit ValidProxy(const BuiltInContext *c = nullptr, const void *a = nullptr) : ctx(c), addr(a) {}

        operator bool() const { return ctx ? ctx->validSlotForAddress_(addr) : false; }

        ValidProxy &operator=(bool v) {
            if (ctx) ctx->validSlotForAddress_(addr) = v;
            return *this;
        }

        template <typename U, typename = std::enable_if_t<std::is_convertible_v<U, bool>>>
        ValidProxy &operator=(U &&v) {
            return (*this = static_cast<bool>(std::forward<U>(v)));
        }
    };

    template <typename U>
    struct _is_inflate : std::false_type {};
    template <typename U>
    struct _is_inflate<_inflate<U>> : std::true_type {};

    template <typename T, typename = std::enable_if_t<!_is_inflate<std::decay_t<T>>::value>>
    inline ValidProxy _valid(T &v) const {
        return ValidProxy{this, static_cast<const void *>(std::addressof(v))};
    }

    template <typename T, typename = std::enable_if_t<!_is_inflate<std::decay_t<T>>::value>>
    inline ValidProxy _valid(const T &v) const {
        return ValidProxy{this, static_cast<const void *>(std::addressof(v))};
    }

    // Prevent taking address of temporaries (would store dangling pointers in the dict).
    template <typename T>
    ValidProxy _valid(const T &&) const = delete;

    // *********************** _memcpy() ***********************
    template <typename T, typename = std::enable_if_t<!std::is_array_v<std::remove_reference_t<T>>>>
    inline void _memcpy(T &dst, const T &src) {
        // NOTE:
        // - 目前仅实现 demo 中用到的“同类型之间”的 _memcpy（语义等价于赋值拷贝）。
        // - 后续会补充“不同类型之间”的版本（例如不同 struct 之间的字段级拷贝或按位宽拷贝），以覆盖更完整的 P5 内置语义。
        dst = src;
    }

    // Array copy version: copy elements from source array to destination array
    template <typename T, std::size_t N, std::size_t M>
    inline void _memcpy(T (&dst)[N], const T (&src)[M]) {
        // Copy elements up to the minimum of the two array sizes
        constexpr std::size_t copy_size = (N < M) ? N : M;
        for (std::size_t i = 0; i < copy_size; ++i) {
            dst[i] = src[i];
        }
    }

    // Dynamic array copy version with explicit size
    template <typename T>
    inline void _memcpy(T dst[], const T src[], std::size_t size) {
        for (std::size_t i = 0; i < size; ++i) {
            dst[i] = src[i];
        }
    }

    // ======================= Placeholder builtins =======================
    // Some P5 built-ins may appear in generated code but are not semantically
    // required for current unit tests. Provide permissive placeholders that:
    // - accept any arguments (single arg or multiple args)
    // - can be used as an rvalue in assignments/initializations (convertible to any T)
    struct _any_rvalue {
        template <typename T>
        operator T() const {
            return T{};
        }
    };

    // Intrisic functions placeholders.
    // template <typename T>
    // constexpr std::size_t _sizeof(const T&) const {
    //     using Decayed = std::decay_t<T>;
    //     return p5::bit_width_v<Decayed>;
    // }

    // template <typename T>
    // inline p5::uint<16> _lenof(const std::vector<T>& v) const {
    //     return p5::uint<16>(v.size());
    // }

    // template <typename T, std::size_t N>
    // inline p5::uint<16> _lenof(const T (&arr)[N]) const {
    //     return p5::uint<16>(N);
    // }

    template <typename... Args>
    inline _any_rvalue _offsetof(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _min(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _max(Args &&... /*args*/) const {
        return {};
    }

    // template <typename Int>
    // constexpr std::uint32_t _log2(Int n) const {
    //     return ::_log2(n);
    // }

    template <typename... Args>
    inline _any_rvalue _valid_set(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _stack_push(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _checksum16(Args &&... /*args*/) const {
        return {};
    }

    // _anchor is implemented in Packet class
    // template <typename... Args>
    // inline _any_rvalue _anchor(Args &&... /*args*/) const {
    //     return {};
    // }

    template <typename... Args>
    inline _any_rvalue _packet_len_get(Args &&... /*args*/) const {
        return {};
    }

    // template <typename... Args>
    // void _printf(const char* format, Args&&... args) const {
    //     std::printf(format, std::forward<Args>(args)...);
    // }

    template <typename... Args>
    inline _any_rvalue _restrict(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _extend(Args &&... /*args*/) const {
        return {};
    }

    // _list_extend: 将变量按照指定个数扩展为 list
    // 例如: _list_extend(_vbit, 3) 返回包含 3 个 _vbit 的 vector
    template <typename T>
    inline std::vector<T> _list_extend(const T& var, int count) const {
        if (count < 0) count = 0;  // 防御性检查
        std::vector<T> result;
        result.reserve(static_cast<std::size_t>(count));
        for (int i = 0; i < count; ++i) {
            result.push_back(var);
        }
        return result;
    }

    // 重载版本：支持 p5::uint<N> 作为 count 参数
    template <typename T, size_t N>
    inline std::vector<T> _list_extend(const T& var, const p5::uint<N>& count) const {
        uint64_t n = count.to_ullong();
        std::vector<T> result;
        result.reserve(n);
        for (uint64_t i = 0; i < n; ++i) {
            result.push_back(var);
        }
        return result;
    }

    // 重载版本：支持 size_t 作为 count 参数
    template <typename T>
    inline std::vector<T> _list_extend(const T& var, size_t count) const {
        std::vector<T> result;
        result.reserve(count);
        for (size_t i = 0; i < count; ++i) {
            result.push_back(var);
        }
        return result;
    }

    template <typename... Args>
    inline _any_rvalue _suppress_warning(Args &&... /*args*/) const {
        return {};
    }

    // _array_to_list: 将 C 风格数组转换为 std::vector
    // 例如: int arr[5] = {1, 2, 3, 4, 5}; auto vec = ctx._array_to_list(arr);
    template <typename T, std::size_t N>
    inline std::vector<T> _array_to_list(const T (&arr)[N]) const {
        return std::vector<T>(std::begin(arr), std::end(arr));
    }

    // _list_alloc: 分配一个与输入列表相同大小和长度的新列表
    // 例如: int arr[5] = {1, 2, 3, 4, 5}; auto new_list = ctx._list_alloc(arr);
    //      返回 std::vector<int>(5)，元素为默认构造的 int{} (即 0)
    //      用途：用于避免依赖，创建一个独立的新列表
    // 版本1: 接受数组参数
    template <typename T, std::size_t N>
    inline std::vector<T> _list_alloc(const T (&arr)[N]) const {
        return std::vector<T>(N);
    }

    // 版本2: 接受 std::vector 参数
    template <typename T>
    inline std::vector<T> _list_alloc(const std::vector<T>& list) const {
        return std::vector<T>(list.size());
    }

    // _map: 从结构体列表中提取特定字段，生成字段值列表
    // 例如: ControlInfo list = {ci0, ci1, ci2, ci3};
    //      _map(list, "Priority") 返回 {ci0.Priority, ci1.Priority, ci2.Priority, ci3.Priority}
    // 注意：使用前需要为结构体类型特化 detail_builtin::struct_field_names 模板
    // 示例：
    //   namespace detail_builtin {
    //     template <>
    //     struct struct_field_names<ControlInfo> {
    //         static constexpr const char* names[] = {"Priority", "Value", "Type"};
    //         static constexpr std::size_t count = 3;
    //     };
    //   }
    template <typename T>
    inline auto _map(const std::vector<T>& struct_list, const char* field_name) const {
        using StructType = std::decay_t<T>;
        
        // 查找字段索引
        std::size_t field_index = detail_builtin::find_field_index<StructType>(field_name);
        
        if (field_index == SIZE_MAX) {
            throw std::invalid_argument(std::string("Field '") + field_name + 
                                       "' not found in struct");
        }
        
        constexpr std::size_t field_count = boost::pfr::tuple_size_v<StructType>;
        if (field_index >= field_count) {
            throw std::invalid_argument("Field index out of range");
        }
        
        // Dispatch based on field_index using explicit template instantiation
        // Each branch calls a different template function with its own return type
        // We use separate if statements (not else-if) so compiler can optimize
        // Note: C++17 requires all return statements to have compatible types for auto deduction
        // However, with if constexpr, only the matching branch is compiled, so this should work
        if (field_index == 0) {
            if constexpr (field_count > 0) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<0>(struct_list);
            }
        }
        if (field_index == 1) {
            if constexpr (field_count > 1) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<1>(struct_list);
            }
        }
        if (field_index == 2) {
            if constexpr (field_count > 2) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<2>(struct_list);
            }
        }
        if (field_index == 3) {
            if constexpr (field_count > 3) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<3>(struct_list);
            }
        }
        if (field_index == 4) {
            if constexpr (field_count > 4) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<4>(struct_list);
            }
        }
        if (field_index == 5) {
            if constexpr (field_count > 5) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<5>(struct_list);
            }
        }
        if (field_index == 6) {
            if constexpr (field_count > 6) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<6>(struct_list);
            }
        }
        if (field_index == 7) {
            if constexpr (field_count > 7) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<7>(struct_list);
            }
        }
        if (field_index == 8) {
            if constexpr (field_count > 8) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<8>(struct_list);
            }
        }
        if (field_index == 9) {
            if constexpr (field_count > 9) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<9>(struct_list);
            }
        }
        if (field_index == 10) {
            if constexpr (field_count > 10) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<10>(struct_list);
            }
        }
        if (field_index == 11) {
            if constexpr (field_count > 11) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<11>(struct_list);
            }
        }
        if (field_index == 12) {
            if constexpr (field_count > 12) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<12>(struct_list);
            }
        }
        if (field_index == 13) {
            if constexpr (field_count > 13) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<13>(struct_list);
            }
        }
        if (field_index == 14) {
            if constexpr (field_count > 14) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<14>(struct_list);
            }
        }
        if (field_index == 15) {
            if constexpr (field_count > 15) {
                return detail_builtin::map_field_dispatch_wrapper<StructType>::template dispatch_impl<15>(struct_list);
            }
        }
        
        // If we reach here, field_index is out of range
        throw std::invalid_argument("Field index out of range (max 16 fields supported)");
    }

    // _list_flatten: 展平嵌套列表，将所有子列表的元素移动到顶层，保持相对位置
    // 例如: _list_flatten({{1, 2}, {3, 4}, {5}}) 返回 {1, 2, 3, 4, 5}
    // 支持任意深度的嵌套: _list_flatten({{{1, 2}}, {{3, 4}}}) 返回 {1, 2, 3, 4}
    template <typename T>
    inline auto _list_flatten(const std::vector<T>& list_variable) const {
        using ElemType = std::decay_t<T>;
        using FlatType = detail_builtin::flatten_element_type_t<ElemType>;

        std::vector<FlatType> result;

        // 预分配空间（优化性能，虽然无法准确估计，但至少分配初始大小）
        result.reserve(list_variable.size());

        // 遍历输入列表，递归展平每个元素
        for (const auto& elem : list_variable) {
            detail_builtin::flatten_into(elem, result);
        }

        return result;
    }

    // _slice: 从列表中提取子列表，支持 [start, end] 范围（包含两端）
    // 例如: _slice({e0, e1, e2, e3, e4, e5}, 1, 3) 返回 {e1, e2, e3}

    // 版本 1: int 类型的 start 和 end
    template <typename T>
    inline std::vector<T> _slice(const std::vector<T>& list_variable, int start, int end) const {
        bool start_negative = (start < 0);
        bool end_negative = (end < 0);
        size_t start_idx = start_negative ? 0 : static_cast<size_t>(start);
        size_t end_idx = end_negative ? 0 : static_cast<size_t>(end);
        return detail_builtin::slice_impl(list_variable, start_idx, end_idx, start_negative, end_negative);
    }

    // 版本 2: size_t 类型的 start 和 end
    template <typename T>
    inline std::vector<T> _slice(const std::vector<T>& list_variable, size_t start, size_t end) const {
        return detail_builtin::slice_impl(list_variable, start, end, false, false);
    }

    // 版本 3: p5::uint<N> 类型的 start 和 end
    template <typename T, size_t N1, size_t N2>
    inline std::vector<T> _slice(const std::vector<T>& list_variable,
                                  const p5::uint<N1>& start,
                                  const p5::uint<N2>& end) const {
        size_t start_idx = static_cast<size_t>(start.to_ullong());
        size_t end_idx = static_cast<size_t>(end.to_ullong());
        return detail_builtin::slice_impl(list_variable, start_idx, end_idx, false, false);
    }

    // 版本 4: 混合类型（int start, p5::uint end）
    template <typename T, size_t N>
    inline std::vector<T> _slice(const std::vector<T>& list_variable,
                                  int start,
                                  const p5::uint<N>& end) const {
        bool start_negative = (start < 0);
        size_t start_idx = start_negative ? 0 : static_cast<size_t>(start);
        size_t end_idx = static_cast<size_t>(end.to_ullong());
        return detail_builtin::slice_impl(list_variable, start_idx, end_idx, start_negative, false);
    }

    // 版本 5: 混合类型（p5::uint start, int end）
    template <typename T, size_t N>
    inline std::vector<T> _slice(const std::vector<T>& list_variable,
                                  const p5::uint<N>& start,
                                  int end) const {
        bool end_negative = (end < 0);
        size_t start_idx = static_cast<size_t>(start.to_ullong());
        size_t end_idx = end_negative ? 0 : static_cast<size_t>(end);
        return detail_builtin::slice_impl(list_variable, start_idx, end_idx, false, end_negative);
    }

    // _vector_reduce: 对列表进行归约操作
    // 例如: _vector_reduce({1, 2, 3, 4}, "+") 返回 1+2+3+4 = 10
    //      _vector_reduce({1, 2, 3, 4}, "-") 返回 1-2-3-4 = -8
    //      _vector_reduce({1, 2, 3, 4}, "|") 返回 1|2|3|4
    //      _vector_reduce({1, 2, 3, 4}, "&") 返回 1&2&3&4
    //      _vector_reduce({1, 2, 3, 4}, "^") 返回 1^2^3^4
    template <typename T>
    inline T _vector_reduce(const std::vector<T>& list, const char* op) const {
        // 处理空列表
        if (list.empty()) {
            return T{};
        }

        // 处理单元素列表
        if (list.size() == 1) {
            return list[0];
        }

        // 根据操作符进行归约
        T result = list[0];
        
        if (std::strcmp(op, "+") == 0) {
            // 加法: list[0] + list[1] + ... + list[n-1]
            for (size_t i = 1; i < list.size(); ++i) {
                result = result + list[i];
            }
        } else if (std::strcmp(op, "-") == 0) {
            // 减法: list[0] - list[1] - ... - list[n-1]
            for (size_t i = 1; i < list.size(); ++i) {
                result = result - list[i];
            }
        } else if (std::strcmp(op, "|") == 0) {
            // 按位或: list[0] | list[1] | ... | list[n-1]
            for (size_t i = 1; i < list.size(); ++i) {
                result = result | list[i];
            }
        } else if (std::strcmp(op, "&") == 0) {
            // 按位与: list[0] & list[1] & ... & list[n-1]
            for (size_t i = 1; i < list.size(); ++i) {
                result = result & list[i];
            }
        } else if (std::strcmp(op, "^") == 0) {
            // 按位异或: list[0] ^ list[1] ^ ... ^ list[n-1]
            for (size_t i = 1; i < list.size(); ++i) {
                result = result ^ list[i];
            }
        } else {
            // 不支持的操作符，抛出异常
            throw std::invalid_argument(std::string("Unsupported operator: ") + op + 
                                        ". Supported operators: +, -, |, &, ^");
        }

        return result;
    }

    template <typename... Args>
    inline _any_rvalue _BALU_priority_selectField(Args &&... /*args*/) const {
        return {};
    }

    // _reg_select: 寄存器选择函数，无条件返回 swValue
    // 参数: hwValue - 硬件值（未使用）
    //       swValue - 软件值（返回值）
    inline int _reg_select(int hwValue, int swValue) const {
        (void)hwValue;  // 明确标记未使用的参数
        return swValue;
    }

    template <typename... Args>
    inline _any_rvalue _trans_offset_load(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _trans_offset_store(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _port_type(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _hdr_bind(Args &&... /*args*/) {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _hdr_ref(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _hdr_expand(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _hdr_shrink(Args &&... /*args*/) const {
        return {};
    }

    // _memove: 从源容器移动到目标容器，支持偏移量和重叠区域
    // 例如: _memove(dst_vec, 2, src_vec, 0, 5);  // 从 src_vec[0] 开始复制 5 个元素到 dst_vec[2]
    // 注意: 与 memmove 类似，可以处理重叠区域

    // Helper: 将 offset/size 参数转换为 size_t
    template <typename OffsetType>
    inline std::size_t to_size_t_value(OffsetType offset) const {
        if constexpr (std::is_integral_v<OffsetType>) {
            return static_cast<std::size_t>(offset);
        } else {
            // 假设是 p5::uint<N>
            return static_cast<std::size_t>(offset.to_ullong());
        }
    }

    // Case 1: vector -> vector (int offsets/size)
    template <typename T>
    inline void _memove(std::vector<T> &dst, int dst_offset,
                        const std::vector<T> &src, int src_offset, int size) const {
        std::size_t dst_off = static_cast<std::size_t>(dst_offset);
        std::size_t src_off = static_cast<std::size_t>(src_offset);
        std::size_t n = static_cast<std::size_t>(size);

        // 边界检查
        if (dst_off + n > dst.size() || src_off + n > src.size()) {
            std::cerr << "[_memove] Warning: offset + size exceeds container size\n";
            n = std::min(dst.size() - dst_off, src.size() - src_off);
        }

        if (n == 0) return;

        // 处理重叠：如果 dst 和 src 是同一个对象，且 dst_offset > src_offset，需要反向复制
        if (&dst == &src && dst_off > src_off) {
            for (std::size_t i = n; i > 0; --i) {
                dst[dst_off + i - 1] = src[src_off + i - 1];
            }
        } else {
            for (std::size_t i = 0; i < n; ++i) {
                dst[dst_off + i] = src[src_off + i];
            }
        }
    }

    // Case 1b: vector -> vector (p5::uint<N> offsets/size)
    template <typename T, size_t N1, size_t N2, size_t N3>
    inline void _memove(std::vector<T> &dst, const p5::uint<N1> &dst_offset,
                        const std::vector<T> &src, const p5::uint<N2> &src_offset,
                        const p5::uint<N3> &size) const {
        std::size_t dst_off = dst_offset.to_ullong();
        std::size_t src_off = src_offset.to_ullong();
        std::size_t n = size.to_ullong();

        // 边界检查
        if (dst_off + n > dst.size() || src_off + n > src.size()) {
            std::cerr << "[_memove] Warning: offset + size exceeds container size\n";
            n = std::min(dst.size() - dst_off, src.size() - src_off);
        }

        if (n == 0) return;

        // 处理重叠
        if (&dst == &src && dst_off > src_off) {
            for (std::size_t i = n; i > 0; --i) {
                dst[dst_off + i - 1] = src[src_off + i - 1];
            }
        } else {
            for (std::size_t i = 0; i < n; ++i) {
                dst[dst_off + i] = src[src_off + i];
            }
        }
    }

    // Case 2: array -> array (int offsets/size)
    template <typename T, std::size_t N, std::size_t M>
    inline void _memove(T (&dst)[N], int dst_offset,
                        const T (&src)[M], int src_offset, int size) const {
        std::size_t dst_off = static_cast<std::size_t>(dst_offset);
        std::size_t src_off = static_cast<std::size_t>(src_offset);
        std::size_t n = static_cast<std::size_t>(size);

        // 边界检查
        if (dst_off + n > N || src_off + n > M) {
            std::cerr << "[_memove] Warning: offset + size exceeds array size\n";
            n = std::min(N - dst_off, M - src_off);
        }

        if (n == 0) return;

        // 处理重叠：如果 dst 和 src 是同一个数组，且 dst_offset > src_offset，需要反向复制
        // 注意：数组比较需要比较指针
        const T* dst_ptr = dst;
        const T* src_ptr = src;
        if (dst_ptr == src_ptr && dst_off > src_off) {
            for (std::size_t i = n; i > 0; --i) {
                dst[dst_off + i - 1] = src[src_off + i - 1];
            }
        } else {
            for (std::size_t i = 0; i < n; ++i) {
                dst[dst_off + i] = src[src_off + i];
            }
        }
    }

    // Case 2b: array -> array (p5::uint<N> offsets/size)
    template <typename T, std::size_t N, std::size_t M, size_t N1, size_t N2, size_t N3>
    inline void _memove(T (&dst)[N], const p5::uint<N1> &dst_offset,
                        const T (&src)[M], const p5::uint<N2> &src_offset,
                        const p5::uint<N3> &size) const {
        std::size_t dst_off = dst_offset.to_ullong();
        std::size_t src_off = src_offset.to_ullong();
        std::size_t n = size.to_ullong();

        // 边界检查
        if (dst_off + n > N || src_off + n > M) {
            std::cerr << "[_memove] Warning: offset + size exceeds array size\n";
            n = std::min(N - dst_off, M - src_off);
        }

        if (n == 0) return;

        // 处理重叠
        const T* dst_ptr = dst;
        const T* src_ptr = src;
        if (dst_ptr == src_ptr && dst_off > src_off) {
            for (std::size_t i = n; i > 0; --i) {
                dst[dst_off + i - 1] = src[src_off + i - 1];
            }
        } else {
            for (std::size_t i = 0; i < n; ++i) {
                dst[dst_off + i] = src[src_off + i];
            }
        }
    }

    // Case 3: array -> vector (int offsets/size)
    template <typename T, std::size_t M>
    inline void _memove(std::vector<T> &dst, int dst_offset,
                        const T (&src)[M], int src_offset, int size) const {
        std::size_t dst_off = static_cast<std::size_t>(dst_offset);
        std::size_t src_off = static_cast<std::size_t>(src_offset);
        std::size_t n = static_cast<std::size_t>(size);

        // 边界检查
        if (dst_off + n > dst.size() || src_off + n > M) {
            std::cerr << "[_memove] Warning: offset + size exceeds container size\n";
            n = std::min(dst.size() - dst_off, M - src_off);
        }

        if (n == 0) return;

        // 数组到 vector，不会有重叠问题，直接复制
        for (std::size_t i = 0; i < n; ++i) {
            dst[dst_off + i] = src[src_off + i];
        }
    }

    // Case 3b: array -> vector (p5::uint<N> offsets/size)
    template <typename T, std::size_t M, size_t N1, size_t N2, size_t N3>
    inline void _memove(std::vector<T> &dst, const p5::uint<N1> &dst_offset,
                        const T (&src)[M], const p5::uint<N2> &src_offset,
                        const p5::uint<N3> &size) const {
        std::size_t dst_off = dst_offset.to_ullong();
        std::size_t src_off = src_offset.to_ullong();
        std::size_t n = size.to_ullong();

        // 边界检查
        if (dst_off + n > dst.size() || src_off + n > M) {
            std::cerr << "[_memove] Warning: offset + size exceeds container size\n";
            n = std::min(dst.size() - dst_off, M - src_off);
        }

        if (n == 0) return;

        // 数组到 vector，不会有重叠问题，直接复制
        for (std::size_t i = 0; i < n; ++i) {
            dst[dst_off + i] = src[src_off + i];
        }
    }

    // Case 4: vector -> array (int offsets/size)
    template <typename T, std::size_t N>
    inline void _memove(T (&dst)[N], int dst_offset,
                        const std::vector<T> &src, int src_offset, int size) const {
        std::size_t dst_off = static_cast<std::size_t>(dst_offset);
        std::size_t src_off = static_cast<std::size_t>(src_offset);
        std::size_t n = static_cast<std::size_t>(size);

        // 边界检查
        if (dst_off + n > N || src_off + n > src.size()) {
            std::cerr << "[_memove] Warning: offset + size exceeds container size\n";
            n = std::min(N - dst_off, src.size() - src_off);
        }

        if (n == 0) return;

        // vector 到数组，不会有重叠问题，直接复制
        for (std::size_t i = 0; i < n; ++i) {
            dst[dst_off + i] = src[src_off + i];
        }
    }

    // Case 4b: vector -> array (p5::uint<N> offsets/size)
    template <typename T, std::size_t N, size_t N1, size_t N2, size_t N3>
    inline void _memove(T (&dst)[N], const p5::uint<N1> &dst_offset,
                        const std::vector<T> &src, const p5::uint<N2> &src_offset,
                        const p5::uint<N3> &size) const {
        std::size_t dst_off = dst_offset.to_ullong();
        std::size_t src_off = src_offset.to_ullong();
        std::size_t n = size.to_ullong();

        // 边界检查
        if (dst_off + n > N || src_off + n > src.size()) {
            std::cerr << "[_memove] Warning: offset + size exceeds container size\n";
            n = std::min(N - dst_off, src.size() - src_off);
        }

        if (n == 0) return;

        // vector 到数组，不会有重叠问题，直接复制
        for (std::size_t i = 0; i < n; ++i) {
            dst[dst_off + i] = src[src_off + i];
        }
    }

    template <typename... Args>
    inline _any_rvalue _mapping_converter(Args &&... /*args*/) const {
        return {};
    }

    template <typename... Args>
    inline _any_rvalue _pkt_offset_reached(Args &&... /*args*/) const {
        return {};
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

    // Address -> valid mapping for generic _valid().
    mutable std::unordered_map<const void *, bool> valid_dict_{};

    // Ensure slot exists and return it.
    inline bool &validSlotForAddress_(const void *addr) const {
        return valid_dict_[addr];
    }
};

#endif // BUILTIN_HPP