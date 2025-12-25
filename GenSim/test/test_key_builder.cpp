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

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_builder_equivalence_uint_parts();
    all_ok &= test_builder_equivalence_member_parts();

    if (all_ok) {
        std::cout << "[PASS] key KeyBuilder tests\n";
        return 0;
    }
    std::cerr << "[FAIL] key KeyBuilder tests\n";
    return 1;
}


