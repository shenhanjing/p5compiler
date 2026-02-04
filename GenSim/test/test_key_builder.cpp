#include <iostream>

#include "../include/key.hpp"
#include "../include/p5_types.hpp"

namespace {

bool expect_eq(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

bool test_builder_equivalence_uint_parts() {
    KeyManager km;
    km.initKey({24});

    p5::uint<8> a = 0x12;
    p5::uint<16> b = 0x3456;

    // Baseline: one-shot buildKey
    km.buildKey(a, b);
    auto key_one_shot = km.getKey<p5::uint<24>>(24);

    // Incremental: append in multiple steps, commit once
    auto kb = km.keyBuilder();
    kb.append(a);   // "switch 1"
    kb.append(b);   // "switch 2"
    bool committed = kb.commit();

    auto key_incremental = km.getKey<p5::uint<24>>(24);

    bool ok = true;
    ok &= expect_eq(committed ? 1 : 0, 1, "KeyBuilder.commit matched slot");
    ok &= expect_eq(key_incremental.to_ullong(), key_one_shot.to_ullong(), "KeyBuilder == buildKey (uint parts)");
    return ok;
}

struct Parts {
    p5::member<p5::uint<3>> a;
    p5::member<p5::uint<5>> b;
};

struct Layout {
    Parts st;
};

bool test_builder_equivalence_member_parts() {
    KeyManager km;
    km.initKey({8});

    p5::Union<Layout> u{};
    u.st.a = 0b101;
    u.st.b = 0b11001;

    // Baseline
    km.buildKey(u.st.a, u.st.b);
    auto key_one_shot = km.getKey<p5::uint<8>>(8);

    // Incremental
    auto kb = km.keyBuilder();
    kb.append(u.st.a);
    kb.append(u.st.b);
    bool committed = kb.commit();
    auto key_incremental = km.getKey<p5::uint<8>>(8);

    bool ok = true;
    ok &= expect_eq(committed ? 1 : 0, 1, "KeyBuilder.commit matched slot (member parts)");
    ok &= expect_eq(key_incremental.to_ullong(), key_one_shot.to_ullong(), "KeyBuilder == buildKey (member parts)");
    return ok;
}

struct Agg {
    p5::uint<3> x;
    p5::uint<5> y;
};

bool test_builder_supports_slice_array_union_aggregate() {
    bool ok = true;

    // ---- slice proxy: p5::uint ----
    {
        KeyManager km;
        km.initKey({10});

        p5::uint<16> v = p5::uint<16>(0xABCD);

        km.buildKey(p5::uint<8>(0xCD), p5::uint<2>(0b11));
        auto baseline = km.getKey<p5::uint<10>>(10);

        auto kb = km.keyBuilder();
        kb.append(v[p5::bit_range<7, 0>]);
        kb.append(v[p5::bit_range<9, 8>]);
        bool committed = kb.commit();

        auto got = km.getKey<p5::uint<10>>(10);
        ok &= expect_eq(committed ? 1 : 0, 1, "slice(uint) commit");
        ok &= expect_eq(got.to_ullong(), baseline.to_ullong(), "slice(uint) == baseline");
    }

    // ---- slice proxy: p5::member ----
    {
        KeyManager km;
        km.initKey({5});

        p5::Union<Layout> u{};
        u.st.b = 0b11001; // [4:0]

        km.buildKey(p5::uint<3>(0b001), p5::uint<2>(0b11)); // low3 then [4:3]=11
        auto baseline = km.getKey<p5::uint<5>>(5);

        auto kb = km.keyBuilder();
        kb.append(u.st.b[p5::bit_range<2, 0>]); // low 3
        kb.append(u.st.b[p5::bit_range<4, 3>]); // high 2
        bool committed = kb.commit();

        auto got = km.getKey<p5::uint<5>>(5);
        ok &= expect_eq(committed ? 1 : 0, 1, "slice(member) commit");
        ok &= expect_eq(got.to_ullong(), baseline.to_ullong(), "slice(member) == baseline");
    }

    // ---- array of p5::uint ----
    {
        KeyManager km;
        km.initKey({12});

        p5::uint<4> arr[3] = {p5::uint<4>(0x1), p5::uint<4>(0x2), p5::uint<4>(0x3)};

        km.buildKey(arr[0], arr[1], arr[2]);
        auto baseline = km.getKey<p5::uint<12>>(12);

        auto kb = km.keyBuilder();
        kb.append(arr); // append whole array
        bool committed = kb.commit();

        auto got = km.getKey<p5::uint<12>>(12);
        ok &= expect_eq(committed ? 1 : 0, 1, "array(uint) commit");
        ok &= expect_eq(got.to_ullong(), baseline.to_ullong(), "array(uint) == baseline");
    }

    // ---- union as a whole ----
    {
        KeyManager km;
        km.initKey({8});

        p5::Union<Layout> u{};
        u.st.a = 0b101;
        u.st.b = 0b11001;

        km.buildKey(u.st.a, u.st.b);
        auto baseline = km.getKey<p5::uint<8>>(8);

        auto kb = km.keyBuilder();
        kb.append(u); // append union as raw storage bits
        bool committed = kb.commit();

        auto got = km.getKey<p5::uint<8>>(8);
        ok &= expect_eq(committed ? 1 : 0, 1, "union commit");
        ok &= expect_eq(got.to_ullong(), baseline.to_ullong(), "union == baseline(parts)");
    }

    // ---- aggregate ----
    {
        KeyManager km;
        km.initKey({8});

        Agg a{};
        a.x = 0b101;
        a.y = 0b11001;

        km.buildKey(a.x, a.y);
        auto baseline = km.getKey<p5::uint<8>>(8);

        auto kb = km.keyBuilder();
        kb.append(a);
        bool committed = kb.commit();

        auto got = km.getKey<p5::uint<8>>(8);
        ok &= expect_eq(committed ? 1 : 0, 1, "aggregate commit");
        ok &= expect_eq(got.to_ullong(), baseline.to_ullong(), "aggregate == baseline(parts)");
    }

    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_builder_equivalence_uint_parts();
    all_ok &= test_builder_equivalence_member_parts();
    all_ok &= test_builder_supports_slice_array_union_aggregate();

    if (all_ok) {
        std::cout << "[PASS] key KeyBuilder tests\n";
        return 0;
    }
    std::cerr << "[FAIL] key KeyBuilder tests\n";
    return 1;
}


