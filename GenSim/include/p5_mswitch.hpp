// p5_mswitch.hpp
// Runtime support for "multi-parameter switch/case" lowering.
//
// Design goal:
// - Support arbitrary number of switch parameters (N >= 1)
// - Support arbitrary parameter types via:
//   - direct equality match (value == pattern)
//   - wildcard match (p5::mswitch::_)
//   - predicate match (callable pattern: bool(const T&))
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

#include <tuple>
#include <type_traits>
#include <utility>

namespace p5::mswitch {

// Wildcard pattern: matches any value at this position.
struct any_t {
    constexpr any_t() = default;
};
inline constexpr any_t _{};

namespace detail {
template <typename...>
struct always_false : std::false_type {};

template <typename Pattern>
using decay_t = std::decay_t<Pattern>;

// Detect whether (V == P) is a valid expression (C++17 SFINAE).
template <typename V, typename P, typename = void>
struct is_eq_comparable : std::false_type {};
template <typename V, typename P>
struct is_eq_comparable<V, P, std::void_t<decltype(std::declval<V>() == std::declval<P>())>> : std::true_type {};

template <typename Pattern, typename Value>
constexpr bool match_one(Pattern &&pat, Value &&val) {
    using P = decay_t<Pattern>;
    if constexpr (std::is_same_v<P, any_t>) {
        (void)pat;
        (void)val;
        return true;
    } else if constexpr (std::is_invocable_r_v<bool, P, decltype(val)>) {
        // Callable predicate: pat(val) -> bool
        return static_cast<bool>(std::forward<Pattern>(pat)(std::forward<Value>(val)));
    } else if constexpr (std::is_invocable_r_v<bool, P, std::add_lvalue_reference_t<std::add_const_t<std::remove_reference_t<Value>>>>) {
        // Callable predicate that expects const T& (common for lambdas / function objects).
        return static_cast<bool>(std::forward<Pattern>(pat)(std::as_const(val)));
    } else {
        // Value match: val == pat (when well-formed); otherwise treat as "not matched".
        // This makes the matcher robust to "wrong-type" patterns (it simply won't match),
        // while still allowing non-equality types via predicate patterns.
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

