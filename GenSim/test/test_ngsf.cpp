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
    ctx.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;

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
    ctx.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
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

    // -------- Temporary argument tests --------
    // Validate that `_add_to_ngsf(p5::uint<N>(...))` works in FV2NGSF direction and that
    // NGSF2FV direction consumes bits (skip) to keep stream aligned.
    {
        GtvContext ctxTmp{};
        clear_ngsf(ctxTmp);
        ctxTmp.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;

        // Use temporaries for append.
        ctxTmp._add_to_ngsf(p5::uint<5>(0b10101));
        ctxTmp._add_to_ngsf(p5::uint<11>(0x655));

        all_ok &= expect_eq_u64(ctxTmp.NGSFBuffer[0].to_ullong(), 0xAE, "tmp byte0 after append(temp a,b)");
        all_ok &= expect_eq_u64(ctxTmp.NGSFBuffer[1].to_ullong(), 0x55, "tmp byte1 after append(temp a,b)");
        all_ok &= expect_eq_u64(ctxTmp.ngsf_byte_offset, 2, "tmp cursor byte_offset after 16 bits");
        all_ok &= expect_eq_u64(ctxTmp.ngsf_bit_offset, 0, "tmp cursor bit_offset after 16 bits");

        // Switch to restore direction. Temporaries cannot be written back to, so we expect
        // the stream cursor to advance (skip) while leaving the buffer intact.
        ctxTmp.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
        ctxTmp.reset_ngsf_offset();

        ctxTmp._add_to_ngsf(p5::uint<5>(0));
        ctxTmp._add_to_ngsf(p5::uint<11>(0));
        all_ok &= expect_eq_u64(ctxTmp.ngsf_byte_offset, 2, "tmp cursor byte_offset after skip 16 bits");
        all_ok &= expect_eq_u64(ctxTmp.ngsf_bit_offset, 0, "tmp cursor bit_offset after skip 16 bits");
        all_ok &= expect_eq_u64(ctxTmp.NGSFBuffer[0].to_ullong(), 0xAE, "tmp buffer unchanged byte0 after skip");
        all_ok &= expect_eq_u64(ctxTmp.NGSFBuffer[1].to_ullong(), 0x55, "tmp buffer unchanged byte1 after skip");

        // Reset and do a real restore into lvalues to ensure data is still decodable.
        ctxTmp.reset_ngsf_offset();
        p5::uint<5> a3{};
        p5::uint<11> b3{};
        ctxTmp._add_to_ngsf(a3);
        ctxTmp._add_to_ngsf(b3);
        all_ok &= expect_eq_p5(a3, p5::uint<5>(0b10101), "tmp restore a after reset");
        all_ok &= expect_eq_p5(b3, p5::uint<11>(0x655), "tmp restore b after reset");
    }

    // -------- Slice proxy tests (p5::uint / p5::member) --------
    // These cover "slice an existing variable then pass into _add_to_ngsf".
    // - Read value: FV2NGSF appends bits from slice proxy temporaries
    // - Write value: NGSF2FV restores bits into slice proxy lvalues (writing back to the original storage)
    {
        // --- p5::uint slice: read (temporary slice_proxy passed as const T&) ---
        GtvContext c{};
        clear_ngsf(c);
        c.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;

        p5::uint<16> hv = p5::uint<16>(0xABCD);
        c._add_to_ngsf(hv[p5::bit_range<7, 0>]); // low byte (0xCD)
        c._add_to_ngsf(hv[p5::bit_range<9, 8>]); // 2-bit slice (bits 9..8 are 0b11 for 0xABCD)

        all_ok &= expect_eq_u64(c.NGSFBuffer[0].to_ullong(), 0xCD, "uint slice read: byte0 == low8(HashValue)");
        all_ok &= expect_eq_u64(c.NGSFBuffer[1].to_ullong(), 0xC0, "uint slice read: next2bits in byte1[7:6]");
        all_ok &= expect_eq_u64(c.ngsf_byte_offset, 1, "uint slice read: cursor byte_offset after 10 bits");
        all_ok &= expect_eq_u64(c.ngsf_bit_offset, 2, "uint slice read: cursor bit_offset after 10 bits");
    }

    {
        // --- p5::member slice: read (temporary member::slice_proxy passed as const T&) ---
        GtvContext c{};
        clear_ngsf(c);
        c.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;

        p5::Union<ULayout> u{};
        u.long_ = p5::uint<10>(0b1101010110); // low8 = 0x56, bits9..8 = 0b11

        c._add_to_ngsf(u.long_[p5::bit_range<7, 0>]);
        c._add_to_ngsf(u.long_[p5::bit_range<9, 8>]);

        all_ok &= expect_eq_u64(c.NGSFBuffer[0].to_ullong(), 0x56, "member slice read: byte0 == low8(u.long_)");
        all_ok &= expect_eq_u64(c.NGSFBuffer[1].to_ullong(), 0xC0, "member slice read: next2bits in byte1[7:6]");
        all_ok &= expect_eq_u64(c.ngsf_byte_offset, 1, "member slice read: cursor byte_offset after 10 bits");
        all_ok &= expect_eq_u64(c.ngsf_bit_offset, 2, "member slice read: cursor bit_offset after 10 bits");
    }

    {
        // --- p5::uint slice: write (slice_proxy lvalue passed as T&) ---
        // Build a buffer using known values, then restore into slices of an existing uint variable.
        GtvContext c{};
        clear_ngsf(c);
        c.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;
        c._add_to_ngsf(p5::uint<8>(0x5A));   // 8 bits
        c._add_to_ngsf(p5::uint<2>(0b10));   // 2 bits

        c.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
        c.reset_ngsf_offset();

        p5::uint<16> out = 0;
        // Restore directly into slice proxies (temporary expressions) to verify _add_to_ngsf
        // can write through them back to the underlying variable.
        c._add_to_ngsf(out[p5::bit_range<7, 0>]);
        c._add_to_ngsf(out[p5::bit_range<9, 8>]);

        // Note: p5::uint::slice()/const operator[] currently isn't usable here due to cross-instantiation
        // private access in p5::uint::slice() implementation. Read back via slice_proxy materialization.
        all_ok &= expect_eq_u64(static_cast<p5::uint<8>>(out[p5::bit_range<7, 0>]).to_ullong(), 0x5A,
                                "uint slice write: out[7:0] restored");
        all_ok &= expect_eq_u64(static_cast<p5::uint<2>>(out[p5::bit_range<9, 8>]).to_ullong(), 0b10,
                                "uint slice write: out[9:8] restored");
    }

    {
        // --- p5::member slice: write (member::slice_proxy lvalue passed as T&) ---
        GtvContext c{};
        clear_ngsf(c);
        c.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;
        c._add_to_ngsf(p5::uint<8>(0xA5));   // 8 bits
        c._add_to_ngsf(p5::uint<2>(0b01));   // 2 bits

        c.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
        c.reset_ngsf_offset();

        p5::Union<ULayout> u{};
        u.long_ = p5::uint<10>(0);
        // Restore directly into member slice proxies (temporary expressions).
        c._add_to_ngsf(u.long_[p5::bit_range<7, 0>]);
        c._add_to_ngsf(u.long_[p5::bit_range<9, 8>]);

        all_ok &= expect_eq_u64(static_cast<p5::uint<8>>(u.long_[p5::bit_range<7, 0>]).to_ullong(), 0xA5,
                                "member slice write: u.long_[7:0] restored");
        all_ok &= expect_eq_u64(static_cast<p5::uint<2>>(u.long_[p5::bit_range<9, 8>]).to_ullong(), 0b01,
                                "member slice write: u.long_[9:8] restored");
    }

    std::cout << "[ngsf test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}


