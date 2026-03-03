#include <iostream>
#include "../include/p5_types.hpp"

namespace {

bool expect_eq(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

// Traditional enums (non-enum-class, no explicit underlying type).
enum LegacyVal {
    LV0 = 0,
    LV1 = 1,
    LV2 = 2,
    LV3 = 3,
    LV4 = 4,
    LV5 = 5,
    LV6 = 6,
    LV7 = 7,
    LV9 = 9,
    LV12 = 12
};

enum LegacyShift {
    LS0 = 0,
    LS1 = 1,
    LS2 = 2,
    LS3 = 3
};

enum LegacyBit {
    LB0 = 0,
    LB1 = 1,
    LB2 = 2,
    LB3 = 3,
    LB4 = 4,
    LB5 = 5,
    LB6 = 6,
    LB7 = 7,
    LB8 = 8,
    LB9 = 9
};

struct ULayout {
    p5::member<p5::uint<10>> raw;
    p5::member<p5::uint<8>> x;
    p5::member<p5::uint<2>> hi2;
};

bool test_uint_with_legacy_enum() {
    bool ok = true;
    p5::uint<8> u{};

    u = LV5;
    ok &= expect_eq(u.to_ullong(), 5, "uint: assign from enum");

    ok &= (u == LV5);
    ok &= (LV5 == u);
    ok &= (u < LV7);
    ok &= (LV7 > u);

    ok &= expect_eq((u + LV3).to_ullong(), 8, "uint: rhs enum +");
    ok &= expect_eq((LV3 + u).to_ullong(), 8, "uint: lhs enum +");
    ok &= expect_eq((LV6 - u).to_ullong(), 1, "uint: lhs enum -");
    ok &= expect_eq((LV3 * u).to_ullong(), 15, "uint: lhs enum *");
    ok &= expect_eq((LV9 / u).to_ullong(), 1, "uint: lhs enum /");
    ok &= expect_eq((LV9 % u).to_ullong(), 4, "uint: lhs enum %");
    ok &= expect_eq((LV6 & u).to_ullong(), 4, "uint: lhs enum &");
    ok &= expect_eq((LV6 | u).to_ullong(), 7, "uint: lhs enum |");
    ok &= expect_eq((LV6 ^ u).to_ullong(), 3, "uint: lhs enum ^");

    u += LV1;  // 6
    u *= LV2;  // 12
    u %= LV5;  // 2
    u <<= LS2; // 8
    u >>= LS1; // 4
    ok &= expect_eq(u.to_ullong(), 4, "uint: enum compound + shift");

    u[LB0] = true;
    ok &= (u[LB0] == true);
    ok &= (u[LB1] == false);
    return ok;
}

bool test_member_uint_ref_and_slice_with_legacy_enum() {
    bool ok = true;
    p5::Union<ULayout> u{};
    u.raw = 0;

    u.x = LV5;
    ok &= expect_eq(u.x.to_ullong(), 5, "member: assign from enum");
    ok &= expect_eq((LV3 + u.x).to_ullong(), 8, "member: lhs enum +");
    ok &= expect_eq((LV3 * u.x).to_ullong(), 15, "member: lhs enum *");
    ok &= expect_eq((LV9 / u.x).to_ullong(), 1, "member: lhs enum /");
    ok &= expect_eq((LV9 % u.x).to_ullong(), 4, "member: lhs enum %");

    u.x += LV1;  // 6
    u.x <<= LS1; // 12
    ok &= expect_eq(u.x.to_ullong(), 12, "member: enum compound");

    u.x[LB0] = true;
    ok &= (u.x[LB0] == true);

    auto ms = u.x[p5::bit_range<3, 0>];
    ms = LV7;
    ok &= expect_eq(ms.to_ullong(), 7, "member slice: assign enum");
    ms %= LV5; // 7 % 5 = 2
    ok &= expect_eq(ms.to_ullong(), 2, "member slice: enum compound %=");
    ok &= expect_eq((LV3 + ms).to_ullong(), 5, "member slice: lhs enum +");
    ok &= expect_eq((LV6 % ms).to_ullong(), 0, "member slice: lhs enum %");

    p5::uint_ref<8> xr = u.x;
    xr = LV9;
    ok &= expect_eq(xr.to_ullong(), 9, "uint_ref: assign enum");
    ok &= expect_eq((LV3 * xr).to_ullong(), 27, "uint_ref: lhs enum *");
    ok &= expect_eq((LV9 % xr).to_ullong(), 0, "uint_ref: lhs enum %");
    xr &= LV7; // 9 & 7 = 1
    xr <<= LS2;
    ok &= expect_eq(xr.to_ullong(), 4, "uint_ref: enum compound and shift");

    auto rs = xr[p5::bit_range<3, 0>];
    rs = LV6;
    rs /= LV2;
    ok &= expect_eq(rs.to_ullong(), 3, "uint_ref slice: enum assign/compound");
    ok &= expect_eq((LV6 / rs).to_ullong(), 2, "uint_ref slice: lhs enum /");
    rs[LB0] = true;
    ok &= (rs[LB0] == true);

    return ok;
}

bool test_union_with_legacy_enum_and_writable_slice() {
    bool ok = true;
    p5::Union<ULayout> u{};
    u = LV12;
    ok &= expect_eq(u.raw.to_ullong(), 12, "union: assign enum");

    ok &= (u == LV12);
    ok &= (LV12 == u);
    ok &= (LV9 < u);
    ok &= (LV12 >= u);

    ok &= expect_eq((u + LV3).to_ullong(), 15, "union: rhs enum +");
    ok &= expect_eq((LV3 + u).to_ullong(), 15, "union: lhs enum +");
    ok &= expect_eq((LV3 * u).to_ullong(), 36, "union: lhs enum *");
    ok &= expect_eq((LV12 % u).to_ullong(), 0, "union: lhs enum %");

    u += LV1;  // 13
    u &= LV7;  // 5
    u <<= LS1; // 10
    ok &= expect_eq(u.raw.to_ullong(), 10, "union: enum compound");

    u[LB0] = true; // 11
    ok &= (u[LB0] == true);
    ok &= expect_eq(u.raw.to_ullong(), 11, "union: enum bit access");

    // Writable union slice (new capability): reuse member-like slice proxy.
    auto s = u[p5::bit_range<3, 0>];
    s = LV7;
    ok &= expect_eq(s.to_ullong(), 7, "union slice: assign enum");
    s += LV1; // wrap on 4-bit slice: 7 -> 8
    ok &= expect_eq(s.to_ullong(), 8, "union slice: enum +=");
    s %= LV3; // 8 % 3 = 2
    ok &= expect_eq(s.to_ullong(), 2, "union slice: enum %=");
    ok &= expect_eq((LV6 % s).to_ullong(), 0, "union slice: lhs enum %");
    s <<= LS1; // 2 -> 4
    ok &= expect_eq(s.to_ullong(), 4, "union slice: enum <<=");
    s[LB0] = true; // 4 -> 5
    ok &= (s[LB0] == true);
    ok &= expect_eq(s.to_ullong(), 5, "union slice: enum bit access");

    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_uint_with_legacy_enum();
    all_ok &= test_member_uint_ref_and_slice_with_legacy_enum();
    all_ok &= test_union_with_legacy_enum_and_writable_slice();

    if (all_ok) {
        std::cout << "[PASS] legacy enum interoperability tests\n";
        return 0;
    }
    std::cerr << "[FAIL] legacy enum interoperability tests\n";
    return 1;
}

