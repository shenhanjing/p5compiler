// Tests for modified BuiltInContext::_lookup():
// If Key is an aggregate (struct / nested) or contains p5::member, it is packed into p5::uint<bits>
// by concatenating all fields MSB-first before SearchEngine lookup.
#include <iostream>

#include "generated_switch.hpp"

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

struct Resp {
    p5::uint<8> x;
    p5::uint<8> y;
};

struct K24 {
    p5::uint<8> a;
    p5::uint<16> b;
};

struct K28 {
    K24 k;
    p5::uint<4> c;
};

struct Parts {
    p5::member<p5::uint<3>> a;
    p5::member<p5::uint<5>> b;
};

struct Layout {
    Parts st;
};

} // namespace

int main() {
    std::cout << "[lookup struct-key test] start\n";

    bool ok = true;

    Switch sw;
    auto &se = sw.searchEngine();

    constexpr int TID = 77;

    // ---- Case 1: flat struct key {uint<8>, uint<16>} => packed uint<24> = (a<<16)|b ----
    se.initTable<p5::uint<24>, Resp>(TID, MatchType::EXACT);

    const uint64_t a = 0x12;
    const uint64_t b = 0x3456;
    const p5::uint<24> packed24((a << 16) | b);
    se.config<p5::uint<24>, Resp>(TID, packed24, Resp{p5::uint<8>(0xaa), p5::uint<8>(0xbb)});

    K24 k24{p5::uint<8>(a), p5::uint<16>(b)};
    auto r1 = sw._lookup<Resp>(TID, static_cast<int>(MatchType::EXACT), k24);
    ok &= expect_true(sw._valid(r1), "Case1: lookup hit (valid=true)");
    ok &= expect_eq_u64(r1.x.to_ullong(), 0xaa, "Case1: Resp.x");
    ok &= expect_eq_u64(r1.y.to_ullong(), 0xbb, "Case1: Resp.y");

    // ---- Case 2: nested struct key { {uint<8>,uint<16>}, uint<4>} => packed uint<28> ----
    constexpr int TID2 = 78;
    se.initTable<p5::uint<28>, Resp>(TID2, MatchType::EXACT);

    const uint64_t c = 0xD;
    const p5::uint<28> packed28((((a << 16) | b) << 4) | c);
    se.config<p5::uint<28>, Resp>(TID2, packed28, Resp{p5::uint<8>(1), p5::uint<8>(2)});

    K28 k28{K24{p5::uint<8>(a), p5::uint<16>(b)}, p5::uint<4>(c)};
    auto r2 = sw._lookup<Resp>(TID2, static_cast<int>(MatchType::EXACT), k28);
    ok &= expect_true(sw._valid(r2), "Case2: lookup hit (valid=true)");
    ok &= expect_eq_u64(r2.x.to_ullong(), 1, "Case2: Resp.x");
    ok &= expect_eq_u64(r2.y.to_ullong(), 2, "Case2: Resp.y");

    // ---- Case 3: struct of p5::member fields (view-bound via Union) => packed uint<8> ----
    constexpr int TID3 = 79;
    se.initTable<p5::uint<8>, Resp>(TID3, MatchType::EXACT);

    // Build expected packed key: a(3 bits)=101, b(5 bits)=11001 => 0b10111001 = 0xB9
    const uint64_t packed8_val = 0xB9;
    se.config<p5::uint<8>, Resp>(TID3, p5::uint<8>(packed8_val), Resp{p5::uint<8>(9), p5::uint<8>(8)});

    p5::Union<Layout> u{};
    u.st.a = p5::uint<3>(0b101);
    u.st.b = p5::uint<5>(0b11001);

    auto r3 = sw._lookup<Resp>(TID3, static_cast<int>(MatchType::EXACT), u.st);
    ok &= expect_true(sw._valid(r3), "Case3: lookup hit (valid=true)");
    ok &= expect_eq_u64(r3.x.to_ullong(), 9, "Case3: Resp.x");
    ok &= expect_eq_u64(r3.y.to_ullong(), 8, "Case3: Resp.y");

    std::cout << "[lookup struct-key test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}


