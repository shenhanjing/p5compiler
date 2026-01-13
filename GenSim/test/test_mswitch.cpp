#include <iostream>
#include <string>

#include "../include/p5_mswitch.hpp"
#include "../include/p5_types.hpp"

namespace {

bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}

bool expect_eq_int(int got, int expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

// Demonstrates the *recommended lowering*:
// 1) Evaluate N switch-values once (mswitch::tie)
// 2) Compute a case-tag via ordered if/else using mswitch::match
// 3) Use native switch(tag) so fallthrough/break behave exactly like C/C++ switch.
bool test_multi_param_wildcard_fallthrough_break() {
    // Values can be any types (p5::uint, enums/ints, std::string, aggregates...)
    p5::uint<2> a = 1;
    int b = 7;
    std::string c = "ok";

    auto sw = p5::mswitch::tie(a, b, c);

    int tag = 0; // 0 means default here
    if (p5::mswitch::match(sw, p5::uint<2>(1), p5::mswitch::_, std::string("ok"))) tag = 1;
    else if (p5::mswitch::match(sw, p5::uint<2>(1), 7, p5::mswitch::_)) tag = 2;
    else tag = 0;

    // Verify order-sensitivity: swapping pattern positions should not match.
    bool order_sensitive_ok = !p5::mswitch::match(sw, p5::uint<2>(1), std::string("ok"), p5::mswitch::_);

    int ran = 0;
    switch (tag) {
        case 1: {
            ran += 1; // matched
            [[fallthrough]]; // fallthrough on purpose
        }
        case 2: {
            ran += 10; // executed due to fallthrough from case 1
            break;     // break should exit the switch
        }
        default: {
            ran += 100;
            break;
        }
    }

    bool ok = true;
    ok &= expect_true(order_sensitive_ok, "multi-param match is order sensitive");
    ok &= expect_eq_int(tag, 1, "selected tag is first matching case (ordered)");
    ok &= expect_eq_int(ran, 11, "fallthrough from case 1 to case 2, then break");
    return ok;
}

struct NoEq {
    int v;
    // intentionally no operator==
};

bool test_predicate_pattern_for_non_eq_types() {
    NoEq x{42};
    auto sw = p5::mswitch::tie(x);

    // Use a predicate pattern when operator== isn't available.
    bool matched = p5::mswitch::match(sw, [](const NoEq &t) { return t.v == 42; });
    bool not_matched = p5::mswitch::match(sw, [](const NoEq &t) { return t.v == 7; });

    bool ok = true;
    ok &= expect_true(matched, "predicate pattern matches");
    ok &= expect_true(!not_matched, "predicate pattern does not match");
    return ok;
}

bool test_single_param_switch_style() {
    // Single-parameter use is just a special case of N=1.
    int x = 3;
    auto sw = p5::mswitch::tie(x);

    int tag = 0;
    if (p5::mswitch::match(sw, 1)) tag = 1;
    else if (p5::mswitch::match(sw, 3)) tag = 2;
    else tag = 0;

    int out = 0;
    switch (tag) {
        case 1: out = 10; break;
        case 2: out = 30; break;
        default: out = -1; break;
    }

    bool ok = true;
    ok &= expect_eq_int(tag, 2, "single-param tag selection");
    ok &= expect_eq_int(out, 30, "single-param switch result");
    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_multi_param_wildcard_fallthrough_break();
    all_ok &= test_predicate_pattern_for_non_eq_types();
    all_ok &= test_single_param_switch_style();

    if (all_ok) {
        std::cout << "[PASS] mswitch tests\n";
        return 0;
    }
    std::cerr << "[FAIL] mswitch tests\n";
    return 1;
}

