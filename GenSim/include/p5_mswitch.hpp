// p5_mswitch.hpp
// Runtime support for "multi-parameter switch/case" lowering.
//
// Design goal:
// - Support arbitrary number of switch parameters (N >= 1)
// - Support arbitrary parameter types via:
//   - direct equality match (value == pattern)
//   - masked match (mask(value, mask): (in & mask) == (value & mask))
// - Order sensitive (tuple position matters)
// - Preserve C/C++ switch semantics (fallthrough + break) by lowering to:
//     int tag = ...;  // computed by ordered if/else with mswitch::match(...)
//     switch(tag) { case 1: ...; break; case 2: ...; /* fallthrough */ ... }
//
// This header intentionally does NOT implement code generation; it provides the
// runtime matching primitives needed by generated C++.
//
#ifndef P5_MSWITCH_HPP
#define P5_MSWITCH_HPP

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>
#include "p5_types.hpp"

namespace p5::mswitch {

namespace detail {
template <typename...>
struct always_false : std::false_type {};

template <typename Pattern>
using decay_t = std::decay_t<Pattern>;

// Detect p5::uint<N>.
template <typename T>
struct is_p5_uint : std::false_type {};
template <std::size_t N>
struct is_p5_uint<p5::uint<N>> : std::true_type {};

// Detect p5::member<p5::uint<N>>.
template <typename T>
struct is_p5_member : std::false_type {};
template <typename UIntT>
struct is_p5_member<p5::member<UIntT>> : std::true_type {};

// Detect whether (V == P) is a valid expression (C++17 SFINAE).
template <typename V, typename P, typename = void>
struct is_eq_comparable : std::false_type {};
template <typename V, typename P>
struct is_eq_comparable<V, P, std::void_t<decltype(std::declval<V>() == std::declval<P>())>> : std::true_type {};

// Detect whether (V & M) is a valid expression (C++17 SFINAE).
template <typename V, typename M, typename = void>
struct is_andable : std::false_type {};
template <typename V, typename M>
struct is_andable<V, M, std::void_t<decltype(std::declval<V>() & std::declval<M>())>> : std::true_type {};

template <typename ValueT, typename MaskT>
struct mask_pattern {
    ValueT value;
    MaskT mask;
};

template <typename T>
struct is_mask_pattern : std::false_type {};
template <typename V, typename M>
struct is_mask_pattern<mask_pattern<V, M>> : std::true_type {};

template <typename Pattern, typename Value>
constexpr bool match_one(Pattern &&pat, Value &&val) {
    using P = decay_t<Pattern>;
    if constexpr (is_mask_pattern<P>::value) {
        // Masked match: (in & mask) == (value & mask)
        // Robustness rule:
        // - If the bitwise-& expressions are ill-formed for these types, treat as "not matched".
        // - If the resulting masked values aren't comparable, treat as "not matched".
        using Vd = std::decay_t<Value>;

        // Common case for generated code:
        // - input is p5::uint<N>
        // - pattern uses integral literals for value/mask
        // Convert pattern components into the same p5::uint<N> domain before applying &.
        if constexpr (is_p5_uint<Vd>::value &&
                      (std::is_integral_v<std::decay_t<decltype(pat.value)>> || std::is_integral_v<std::decay_t<decltype(pat.mask)>>)) {
            auto m = Vd(pat.mask);
            auto v = Vd(pat.value);
            auto in_masked = (std::forward<Value>(val) & m);
            auto v_masked = (v & m);
            if constexpr (is_eq_comparable<decltype(in_masked), decltype(v_masked)>::value) {
                return static_cast<bool>(in_masked == v_masked);
            } else {
                return false;
            }
        } else if constexpr (is_p5_member<Vd>::value &&
                             (std::is_integral_v<std::decay_t<decltype(pat.value)>> || std::is_integral_v<std::decay_t<decltype(pat.mask)>>)) {
            // Common case for generated code:
            // - input is p5::member<p5::uint<N>>
            // - pattern uses integral literals for value/mask
            // Convert pattern components into the same p5::uint<N> domain before applying &.
            using U = typename Vd::value_type;  // p5::uint<N>
            auto m = U(pat.mask);
            auto v = U(pat.value);
            auto in_masked = (std::forward<Value>(val) & m);
            auto v_masked = (v & m);
            if constexpr (is_eq_comparable<decltype(in_masked), decltype(v_masked)>::value) {
                return static_cast<bool>(in_masked == v_masked);
            } else {
                return false;
            }
        } else {
            if constexpr (is_andable<decltype(val), decltype(pat.mask)>::value && is_andable<decltype(pat.value), decltype(pat.mask)>::value) {
                auto in_masked = (std::forward<Value>(val) & pat.mask);
                auto v_masked = (pat.value & pat.mask);
                if constexpr (is_eq_comparable<decltype(in_masked), decltype(v_masked)>::value) {
                    return static_cast<bool>(in_masked == v_masked);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    } else {
        // Value match: val == pat (when well-formed); otherwise treat as "not matched".
        // This makes the matcher robust to "wrong-type" patterns (it simply won't match),
        // while still allowing mask patterns for bitwise-match cases.
        if constexpr (is_eq_comparable<decltype(val), decltype(pat)>::value) {
            return static_cast<bool>(std::forward<Value>(val) == std::forward<Pattern>(pat));
        } else {
            return false;
        }
    }
}

template <typename ValuesTuple, typename PatternsTuple, std::size_t... I>
constexpr bool match_tuple_impl(ValuesTuple &&vals, PatternsTuple &&pats, std::index_sequence<I...>) {
    return (match_one(std::get<I>(std::forward<PatternsTuple>(pats)),
                      std::get<I>(std::forward<ValuesTuple>(vals))) &&
            ...);
}
} // namespace detail

// Build a mask pattern for a single switch parameter.
// Matching rule: (input & Mask) == (Value & Mask)
// NOTE: When Mask==0 and Value==0, the match is always true (acts as wildcard for andable types).
template <typename ValueT, typename MaskT>
constexpr detail::mask_pattern<std::decay_t<ValueT>, std::decay_t<MaskT>> mask(ValueT &&value, MaskT &&mask) {
    using Vd = std::decay_t<ValueT>;
    using Md = std::decay_t<MaskT>;
    return detail::mask_pattern<Vd, Md>{Vd(std::forward<ValueT>(value)), Md(std::forward<MaskT>(mask))};
}

// Build a tuple of (references to) switch values; evaluates each argument once.
// Prefer this over manually writing std::forward_as_tuple in generated code.
template <typename... Values>
constexpr auto tie(Values &&...vals) {
    return std::forward_as_tuple(std::forward<Values>(vals)...);
}

// Match a values tuple against a patterns tuple. Arity must match exactly.
template <typename... Values, typename... Patterns>
constexpr bool match(const std::tuple<Values...> &values, const std::tuple<Patterns...> &patterns) {
    static_assert(sizeof...(Values) == sizeof...(Patterns),
                  "p5::mswitch::match: number of values must equal number of patterns");
    return detail::match_tuple_impl(values, patterns, std::index_sequence_for<Values...>{});
}

// Convenience overload: pass patterns as variadic args.
template <typename... Values, typename... Patterns>
constexpr bool match(const std::tuple<Values...> &values, Patterns &&...patterns) {
    static_assert(sizeof...(Values) == sizeof...(Patterns),
                  "p5::mswitch::match: number of values must equal number of patterns");
    auto pats = std::forward_as_tuple(std::forward<Patterns>(patterns)...);
    return detail::match_tuple_impl(values, pats, std::index_sequence_for<Values...>{});
}

} // namespace p5::mswitch

#endif // P5_MSWITCH_HPP

