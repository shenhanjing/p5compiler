#include <iostream>
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
    // Values are comparable and bitwise-andable here (uint/int), so no predicate patterns needed.
    p5::uint<2> a = 1;
    p5::uint<8> b = 7;
    p5::uint<8> c = 0x22;

    auto sw = p5::mswitch::tie(a, b, c);

    int tag = 0; // 0 means default here
    if (p5::mswitch::match(sw, p5::uint<2>(1), p5::mswitch::mask(0, 0), p5::uint<8>(0x22))) tag = 1;
    else if (p5::mswitch::match(sw, p5::uint<2>(1), p5::uint<8>(7), p5::mswitch::mask(0, 0))) tag = 2;
    else tag = 0;

    // Verify order-sensitivity: swapping pattern positions should not match.
    bool order_sensitive_ok = !p5::mswitch::match(sw, p5::uint<2>(1), c, b);

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

bool test_masked_match_single_param() {
    // Verify mask semantics: (in & mask) == (value & mask)
    p5::uint<8> x = 0x12;
    auto sw = p5::mswitch::tie(x);

    // Match high nibble == 0x10
    //
    // x     = 0x12 = 0b0001'0010
    // mask  = 0xF0 = 0b1111'0000
    // value = 0x10 = 0b0001'0000
    // (x & mask)     = 0b0001'0000
    // (value & mask) = 0b0001'0000
    bool matched = p5::mswitch::match(sw, p5::mswitch::mask(0x10, 0xF0));
    bool not_matched = p5::mswitch::match(sw, p5::mswitch::mask(0x20, 0xF0));

    // Wildcard via mask(0,0)
    //
    // mask  = 0 = 0b0000'0000
    // value = 0 = 0b0000'0000
    // (x & 0) == (0 & 0)  => 0 == 0  => always true (for andable types)
    bool wildcard = p5::mswitch::match(sw, p5::mswitch::mask(0, 0));

    bool ok = true;
    ok &= expect_true(matched, "masked match: high nibble matches");
    ok &= expect_true(!not_matched, "masked match: high nibble does not match");
    ok &= expect_true(wildcard, "mask(0,0) acts as wildcard for andable types");
    return ok;
}

struct MemberParts {
    p5::member<p5::uint<8>> a;
};

struct MemberLayout {
    MemberParts st;
};

bool test_masked_match_member() {
    p5::Union<MemberLayout> u{};
    u.st.a = 0x12;
    auto sw = p5::mswitch::tie(u.st.a);

    // Same bit rule as p5::uint:
    //
    // input = 0x12 = 0b0001'0010
    // mask  = 0xF0 = 0b1111'0000
    // value = 0x10 = 0b0001'0000
    // (input & mask) == (value & mask) => 0b0001'0000 == 0b0001'0000
    bool matched = p5::mswitch::match(sw, p5::mswitch::mask(0x10, 0xF0));
    bool not_matched = p5::mswitch::match(sw, p5::mswitch::mask(0x20, 0xF0));
    bool wildcard = p5::mswitch::match(sw, p5::mswitch::mask(0, 0));

    bool ok = true;
    ok &= expect_true(matched, "member masked match: high nibble matches");
    ok &= expect_true(!not_matched, "member masked match: high nibble does not match");
    ok &= expect_true(wildcard, "member mask(0,0) acts as wildcard");
    return ok;
}

bool test_eq_uint_with_integral_pattern() {
    p5::uint<8> x = 7;
    auto sw = p5::mswitch::tie(x);

    // direct equality: uint == integral pattern
    bool matched = p5::mswitch::match(sw, 7);
    bool not_matched = p5::mswitch::match(sw, 8);

    bool ok = true;
    ok &= expect_true(matched, "uint == integral pattern matches");
    ok &= expect_true(!not_matched, "uint == integral pattern does not match");
    return ok;
}

bool test_eq_member_with_integral_pattern() {
    p5::Union<MemberLayout> u{};
    u.st.a = 7;
    auto sw = p5::mswitch::tie(u.st.a);

    // direct equality: member == integral pattern
    bool matched = p5::mswitch::match(sw, 7);
    bool not_matched = p5::mswitch::match(sw, 8);

    bool ok = true;
    ok &= expect_true(matched, "member == integral pattern matches");
    ok &= expect_true(!not_matched, "member == integral pattern does not match");
    return ok;
}

bool test_mask_patterns_more() {
    bool ok = true;

    // 1) integral input with masks
    {
        uint32_t x = 0b1010'1100u; // 0xAC
        auto sw = p5::mswitch::tie(x);
        // x     = 0b1010'1100
        // mask  = 0b1111'0000
        // value = 0b1010'0000
        // (x & mask)     = 0b1010'0000
        // (value & mask) = 0b1010'0000
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0b1010'0000u, 0b1111'0000u)),
                          "integral masked match: high nibble matches");
        // value = 0b1001'0000
        // (value & mask) = 0b1001'0000 != 0b1010'0000
        ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(0b1001'0000u, 0b1111'0000u)),
                          "integral masked match: high nibble does not match");
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0u, 0u)),
                          "integral mask(0,0) acts as wildcard");
    }

    // 2) p5::uint input, value/mask as integral literals (special support path)
    {
        p5::uint<8> x = 0xAC;
        auto sw = p5::mswitch::tie(x);
        // x     = 0xAC = 0b1010'1100
        // mask  = 0xF0 = 0b1111'0000
        // value = 0xA0 = 0b1010'0000
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0xA0, 0xF0)),
                          "p5::uint masked match with integral value/mask");
        // value = 0xB0 = 0b1011'0000
        ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(0xB0, 0xF0)),
                          "p5::uint masked mismatch with integral value/mask");
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0, 0)),
                          "p5::uint mask(0,0) acts as wildcard");
    }

    // 3) p5::member input, value/mask as integral literals (member special support path)
    {
        p5::Union<MemberLayout> u{};
        u.st.a = 0xAC;
        auto sw = p5::mswitch::tie(u.st.a);
        // input = 0xAC = 0b1010'1100
        // mask  = 0xF0 = 0b1111'0000
        // value = 0xA0 = 0b1010'0000
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0xA0, 0xF0)),
                          "p5::member masked match with integral value/mask");
        // value = 0xB0 = 0b1011'0000
        ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(0xB0, 0xF0)),
                          "p5::member masked mismatch with integral value/mask");
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0, 0)),
                          "p5::member mask(0,0) acts as wildcard");
    }

    // 4) p5::uint input, value/mask as p5::uint values (generic mask path)
    {
        p5::uint<8> x = 0xAC;
        auto sw = p5::mswitch::tie(x);
        // Same as case (2), but Value/Mask are p5::uint<8> instead of integral literals:
        // value = p5::uint<8>(0xA0) = 0b1010'0000
        // mask  = p5::uint<8>(0xF0) = 0b1111'0000
        ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(p5::uint<8>(0xA0), p5::uint<8>(0xF0))),
                          "p5::uint masked match with p5::uint value/mask");
    }

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

bool test_mswitch_with_slices() {
    bool ok = true;

    // ---- p5::uint slice: equality match ----
    {
        p5::uint<16> x = 0xABCD;
        // Directly pass temporary slice_proxy into tie (should be safe now).
        auto sw = p5::mswitch::tie(x[p5::bit_range<7, 0>], x[p5::bit_range<9, 8>]);
        ok &= expect_true(p5::mswitch::match(sw, 0xCD, 0b11), "uint slice == integral patterns");
        ok &= expect_true(!p5::mswitch::match(sw, 0xCC, 0b11), "uint slice mismatch on low8");
        ok &= expect_true(!p5::mswitch::match(sw, 0xCD, 0b10), "uint slice mismatch on [9:8]");
    }

    // ---- p5::member slice: equality match ----
    {
        p5::Union<MemberLayout> u{};
        u.st.a = 0xAB;
        // Directly pass temporary slice_proxy into tie (should be safe now).
        auto sw = p5::mswitch::tie(u.st.a[p5::bit_range<3, 0>], u.st.a[p5::bit_range<7, 4>]);
        ok &= expect_true(p5::mswitch::match(sw, 0xB, 0xA), "member slice == integral patterns");
        ok &= expect_true(!p5::mswitch::match(sw, 0xB, 0xB), "member slice mismatch on high nibble");
    }

    // ---- p5::uint slice: masked match (materialize slice to p5::uint) ----
    // Directly use temporary slice_proxy as input; tie() now stores rvalues by value safely.
    {
        p5::uint<16> x = 0xABCD;
        auto sw = p5::mswitch::tie(x[p5::bit_range<7, 0>]); // low8 == 0xCD
        ok &= expect_true(
            p5::mswitch::match(sw, p5::mswitch::mask(p5::uint<8>(0xC0), p5::uint<8>(0xF0))),
            "slice masked match on high nibble");
        ok &= expect_true(
            !p5::mswitch::match(sw, p5::mswitch::mask(p5::uint<8>(0xD0), p5::uint<8>(0xF0))),
            "slice masked mismatch on high nibble");
    }

    return ok;
}

struct MaskUnionLayout {
    p5::member<p5::uint<8>> whole;
    struct {
        p5::member<p5::uint<4>> hi;
        p5::member<p5::uint<4>> lo;
    } nybble;
};

struct MaskNestedAgg {
    p5::uint<4> x;
    p5::uint<4> y;
};

struct MaskAgg {
    p5::uint<8> a;
    p5::Union<MaskUnionLayout> u;
    p5::uint<4> arr[2];
    MaskNestedAgg nested;
};

bool test_masked_match_aggregate_recursive() {
    bool ok = true;

    MaskAgg in{};
    in.a = 0x5A;
    in.u = p5::uint<8>(0xBC);
    in.arr[0] = 0x3;
    in.arr[1] = 0x7;
    in.nested.x = 0xE;
    in.nested.y = 0x1;

    auto sw = p5::mswitch::tie(in);

    MaskAgg val{};
    val.a = 0x5A;
    val.u = p5::uint<8>(0xB0); // only high nibble is checked by mask
    val.arr[0] = 0x3;
    val.arr[1] = 0x0;          // wildcarded by mask
    val.nested.x = 0xE;
    val.nested.y = 0x0;        // wildcarded by mask

    MaskAgg m{};
    m.a = 0xFF;
    m.u = p5::uint<8>(0xF0);
    m.arr[0] = 0xF;
    m.arr[1] = 0x0;
    m.nested.x = 0xF;
    m.nested.y = 0x0;

    ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(val, m)),
                      "aggregate recursive masked match succeeds");

    MaskAgg bad = val;
    bad.nested.x = 0xD; // this field is masked-in, must fail
    ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(bad, m)),
                      "aggregate recursive masked match fails on masked field mismatch");

    MaskAgg zero{};
    ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(zero, zero)),
                      "aggregate mask(0,0) acts as wildcard");

    return ok;
}

bool test_masked_match_union_direct() {
    bool ok = true;

    p5::Union<MaskUnionLayout> in{};
    in = p5::uint<8>(0xBC);
    auto sw = p5::mswitch::tie(in);

    // Check high nibble only.
    ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(0xB0, 0xF0)),
                      "union direct masked match with integral pattern succeeds");
    ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(0xA0, 0xF0)),
                      "union direct masked match fails on high nibble mismatch");

    // Pattern as Union object.
    p5::Union<MaskUnionLayout> val{};
    p5::Union<MaskUnionLayout> m{};
    val = p5::uint<8>(0xB0);
    m = p5::uint<8>(0xF0);
    ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(val, m)),
                      "union direct masked match with union value/mask succeeds");

    return ok;
}

bool test_masked_match_aggregate_with_raw_uint_pattern() {
    bool ok = true;

    MaskAgg in{};
    in.a = 0x5A;
    in.u = p5::uint<8>(0xBC);
    in.arr[0] = 0x3;
    in.arr[1] = 0x7;
    in.nested.x = 0xE;
    in.nested.y = 0x1;
    auto sw = p5::mswitch::tie(in);

    constexpr std::size_t W = p5::bit_width_v<MaskAgg>;
    using U = p5::uint<W>;
    U in_bits = p5::mswitch::detail::to_bits(in);

    // Build raw uint patterns from runtime-flattened bits, then toggle masked/unmasked bits.
    U v = in_bits;
    U m = U::max();
    m[0] = false;      // ignore one bit
    v[0] = !in_bits[0];
    ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(v, m)),
                      "aggregate masked match with raw uint pattern succeeds");

    U bad_v = v;
    bad_v[1] = !in_bits[1];   // this bit is still masked-in
    ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(bad_v, m)),
                      "aggregate masked match with raw uint pattern fails on masked-in mismatch");

    return ok;
}

bool test_masked_match_aggregate_array_only() {
    bool ok = true;

    MaskAgg in{};
    in.a = 0x12;
    in.u = p5::uint<8>(0x34);
    in.arr[0] = 0xA;
    in.arr[1] = 0x5;
    in.nested.x = 0x6;
    in.nested.y = 0x7;
    auto sw = p5::mswitch::tie(in);

    // Only check arr[0], everything else wildcard.
    MaskAgg val{};
    MaskAgg m{};
    val.arr[0] = 0xA;
    m.arr[0] = 0xF;
    ok &= expect_true(p5::mswitch::match(sw, p5::mswitch::mask(val, m)),
                      "aggregate masked match on array-only field succeeds");

    MaskAgg bad = val;
    bad.arr[0] = 0x9;
    ok &= expect_true(!p5::mswitch::match(sw, p5::mswitch::mask(bad, m)),
                      "aggregate masked match on array-only field fails when mismatched");

    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_multi_param_wildcard_fallthrough_break();
    all_ok &= test_masked_match_single_param();
    all_ok &= test_masked_match_member();
    all_ok &= test_eq_uint_with_integral_pattern();
    all_ok &= test_eq_member_with_integral_pattern();
    all_ok &= test_mask_patterns_more();
    all_ok &= test_single_param_switch_style();
    all_ok &= test_mswitch_with_slices();
    all_ok &= test_masked_match_aggregate_recursive();
    all_ok &= test_masked_match_union_direct();
    all_ok &= test_masked_match_aggregate_with_raw_uint_pattern();
    all_ok &= test_masked_match_aggregate_array_only();

    if (all_ok) {
        std::cout << "[PASS] mswitch tests\n";
        return 0;
    }
    std::cerr << "[FAIL] mswitch tests\n";
    return 1;
}

