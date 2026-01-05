// Tests for KeyManager::assignKey + BuiltInContext::_key(out)
#include <iostream>

#include "generated_switch.hpp"

namespace {

bool expect_eq_u64(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}

struct KeyStruct {
    p5::uint<8> a;
    p5::uint<16> b;
};

struct Parts {
    p5::member<p5::uint<3>> a;
    p5::member<p5::uint<5>> b;
};

struct Layout {
    Parts st;
    p5::member<p5::uint<8>> whole;
};

} // namespace

int main() {
    std::cout << "[key assign struct test] start\n";

    bool ok = true;

    // ---- Case 1: assign into aggregate of p5::uint ----
    {
        Switch sw;
        auto &km = sw.keyManager();
        km.initKey({24});
        km.buildKey(p5::uint<8>(0x12), p5::uint<16>(0x3456));

        KeyStruct out{};
        ok &= expect_true(sw._key(out), "BuiltInContext::_key(out) returns true for matching slot");
        ok &= expect_eq_u64(out.a.to_ullong(), 0x12, "KeyStruct.a");
        ok &= expect_eq_u64(out.b.to_ullong(), 0x3456, "KeyStruct.b");
    }

    // ---- Case 2: assign into nested aggregate containing p5::member (must be view-bound, use Union) ----
    {
        Switch sw;
        auto &km = sw.keyManager();
        km.initKey({8});
        km.buildKey(p5::uint<8>(0b10111001)); // 0xB9

        p5::Union<Layout> u{};
        ok &= expect_true(sw._key(u.st), "_key(u.st) returns true for matching slot (member fields)");

        auto a = static_cast<p5::uint<3>>(u.st.a).to_ullong();
        auto b = static_cast<p5::uint<5>>(u.st.b).to_ullong();
        ok &= expect_eq_u64(a, 0b101, "u.st.a (top 3 bits of 0xB9)");
        ok &= expect_eq_u64(b, 0b11001, "u.st.b (low 5 bits of 0xB9)");

        // Also verify assigning into the whole union works.
        p5::Union<Layout> u2{};
        ok &= expect_true(sw._key(u2), "_key(union) returns true for matching slot");
        auto whole = static_cast<p5::uint<8>>(u2.whole).to_ullong();
        ok &= expect_eq_u64(whole, 0xB9, "u2.whole == 0xB9");
    }

    std::cout << "[key assign struct test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}


