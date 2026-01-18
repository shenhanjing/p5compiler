#include <cstdint>
#include <iostream>

#include "../include/p5_types.hpp"

namespace {

bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}

bool expect_eq_u64(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

bool test_nested_struct_designators() {
    struct Inner {
        int p;
        int q;
    };
    struct Outer {
        int a;
        Inner in;
        int b;
    };

    Outer o = {.a = 1, .in = {.p = 10, .q = 20}, .b = 2};

    bool ok = true;
    ok &= expect_eq_u64(o.a, 1, "nested: a");
    ok &= expect_eq_u64(o.in.p, 10, "nested: in.p");
    ok &= expect_eq_u64(o.in.q, 20, "nested: in.q");
    ok &= expect_eq_u64(o.b, 2, "nested: b");
    return ok;
}

bool test_union_designator() {
    union U {
        int i;
        long l;
    };

    U u = {.l = 42};
    bool ok = true;
    ok &= expect_eq_u64(static_cast<uint64_t>(u.l), 42, "union: .l = 42");
    return ok;
}

bool test_partial_struct_init() {
    struct S {
        int a;
        int b;
        int c;
    };

    // Partial designated initialization: unspecified members should be value-initialized (0).
    // C++20 requires designators to follow declaration order, so we only designate a prefix.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
    S p = {.a = 11, .b = 22};
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

    bool ok = true;
    ok &= expect_eq_u64(p.a, 11, "partial struct: p.a = 11");
    ok &= expect_eq_u64(p.b, 22, "partial struct: p.b = 22");
    ok &= expect_eq_u64(p.c, 0, "partial struct: p.c default 0");
    return ok;
}

bool test_p5_uint_aggregate() {
    struct P {
        p5::uint<8> a;
        p5::uint<16> b;
    };

    P p = {.a = 0x12, .b = 0x3456};

    bool ok = true;
    ok &= expect_eq_u64(p.a.to_ullong(), 0x12, "p5::uint aggregate: a");
    ok &= expect_eq_u64(p.b.to_ullong(), 0x3456, "p5::uint aggregate: b");
    return ok;
}

}  // namespace

int main() {
    std::cout << "[designated init test] start\n";

    bool ok = true;
    ok &= test_nested_struct_designators();
    ok &= test_union_designator();
    ok &= test_partial_struct_init();
    ok &= test_p5_uint_aggregate();

    ok &= expect_true(ok, "overall");
    std::cout << "[designated init test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}

