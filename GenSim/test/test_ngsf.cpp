// Test for GtvContext::_add_to_ngsf(): ingress append + egress restore with cursor continuity.
#include <iostream>

#include "generated_gtv.hpp"

namespace {

bool expect_eq_u64(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

template <typename T>
bool expect_eq_p5(const T &got, const T &expect, const char *msg) {
    if (got.to_ullong() == expect.to_ullong()) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got.to_ullong() << " expect=" << expect.to_ullong() << "\n";
    return false;
}

void clear_ngsf(GtvContext &ctx) {
    for (auto &b : ctx.NGSFBuffer) b = 0;
    ctx.reset_ngsf_offset();
}

// A nested aggregate (non-union) to validate boost::pfr recursion.
struct NestedAgg {
    p5::uint<3> x;
    p5::uint<9> y;
};

// Union layout to validate p5::member and p5::Union are supported as leaves and via aggregates.
struct St {
    p5::member<p5::uint<3>> a;
    p5::member<p5::uint<3>> b;
};

struct ULayout {
    p5::member<p5::uint<10>> long_;
    p5::member<p5::uint<2>> short_;
    St st;
};

} // namespace

int main() {
    std::cout << "[ngsf test] start\n";

    bool all_ok = true;
    GtvContext ctx{};

    // -------- Ingress: append bits into NGSFBuffer across multiple calls --------
    clear_ngsf(ctx);
    ctx.ngsf_direction = GtvContext::NgsfDirection::INGRESS;

    // Choose values so the first 16 bits pack to two known bytes (MSB-first):
    // a (5 bits) = 10101
    // b (11 bits)= 11001010101
    // Concatenated = 10101110 01010101 = 0xAE 0x55
    p5::uint<5> a = p5::uint<5>(0b10101);
    p5::uint<11> b = p5::uint<11>(0x655);

    ctx._add_to_ngsf(a);
    ctx._add_to_ngsf(b);

    all_ok &= expect_eq_u64(ctx.NGSFBuffer[0].to_ullong(), 0xAE, "byte0 after append(a,b)");
    all_ok &= expect_eq_u64(ctx.NGSFBuffer[1].to_ullong(), 0x55, "byte1 after append(a,b)");
    all_ok &= expect_eq_u64(ctx.ngsf_byte_offset, 2, "cursor byte_offset after 16 bits");
    all_ok &= expect_eq_u64(ctx.ngsf_bit_offset, 0, "cursor bit_offset after 16 bits");

    // Append a nested aggregate (12 bits) to force non-byte alignment.
    NestedAgg s{};
    s.x = p5::uint<3>(0b101);
    s.y = p5::uint<9>(0b011001100); // 0x0CC
    ctx._add_to_ngsf(s);

    all_ok &= expect_eq_u64(ctx.ngsf_byte_offset, 3, "cursor byte_offset after +12 bits");
    all_ok &= expect_eq_u64(ctx.ngsf_bit_offset, 4, "cursor bit_offset after +12 bits (should be 4)");

    // Append a union to validate p5::Union and p5::member support.
    p5::Union<ULayout> u{};
    u.long_ = p5::uint<10>(0b1010110011);
    ctx._add_to_ngsf(u);

    // Total bits appended: 16 + 12 + 10 = 38 => byte_offset=4, bit_offset=6
    all_ok &= expect_eq_u64(ctx.ngsf_byte_offset, 4, "cursor byte_offset after +10 bits (union)");
    all_ok &= expect_eq_u64(ctx.ngsf_bit_offset, 6, "cursor bit_offset after +10 bits (union)");

    // -------- Egress: restore bits from NGSFBuffer back into variables, continuing from cursor --------
    ctx.ngsf_direction = GtvContext::NgsfDirection::EGRESS;
    ctx.reset_ngsf_offset();

    p5::uint<5> a2{};
    p5::uint<11> b2{};
    NestedAgg s2{};
    p5::Union<ULayout> u2{};

    ctx._add_to_ngsf(a2);
    ctx._add_to_ngsf(b2);
    ctx._add_to_ngsf(s2);
    ctx._add_to_ngsf(u2);

    all_ok &= expect_eq_p5(a2, a, "restore a");
    all_ok &= expect_eq_p5(b2, b, "restore b");
    all_ok &= expect_eq_p5(s2.x, s.x, "restore nested.x");
    all_ok &= expect_eq_p5(s2.y, s.y, "restore nested.y");
    all_ok &= expect_eq_p5(p5::uint<10>(u2.long_), p5::uint<10>(u.long_), "restore union.long_");
    all_ok &= expect_eq_p5(p5::uint<3>(u2.st.a), p5::uint<3>(u.st.a), "restore union.st.a");
    all_ok &= expect_eq_p5(p5::uint<3>(u2.st.b), p5::uint<3>(u.st.b), "restore union.st.b");

    all_ok &= expect_eq_u64(ctx.ngsf_byte_offset, 4, "egress cursor byte_offset after restore all");
    all_ok &= expect_eq_u64(ctx.ngsf_bit_offset, 6, "egress cursor bit_offset after restore all");

    std::cout << "[ngsf test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}


