#include <iostream>
#include "../include/p5_types.hpp"

namespace {

bool expect_eq(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

// struct member layout: declaration order packs from MSB -> LSB.
struct St {
    p5::member<p5::uint<3>> a;
    p5::member<p5::uint<3>> b;
};

// union layout: all top-level members overlay with MSB alignment inside raw storage.
struct ULayout {
    p5::member<p5::uint<10>> long_;
    p5::member<p5::uint<2>> short_;
    St st;
};

// ---- C-style array member layouts ----
struct ArrLayoutTopLevel {
    p5::member<p5::uint<3>> a[2];     // total width = 6, a[0] -> bits3..5, a[1] -> bits0..2
    p5::member<p5::uint<6>> raw6;     // overlay full 6 bits
};

struct ArrStruct {
    p5::member<p5::uint<2>> a[3];     // total width = 6, a[0] -> bits4..5, a[1] -> bits2..3, a[2] -> bits0..1
};

struct ArrLayoutInStruct {
    ArrStruct st;                     // width = 6
    p5::member<p5::uint<6>> raw6;     // overlay full 6 bits
};

// nested union inside a struct, to validate nested binding
struct InnerLayout {
    p5::member<p5::uint<3>> x;
    p5::member<p5::uint<5>> y;
};

struct OuterStruct {
    p5::member<p5::uint<1>> a;      // MSB of struct (when struct is MSB-aligned in its union)
    p5::Union<InnerLayout> inner;   // next bits (MSB->LSB packing inside struct)
    p5::member<p5::uint<2>> b;      // LSB of struct
};

struct OuterLayout {
    OuterStruct st;                 // width=1+5+2=8
    p5::member<p5::uint<10>> raw;   // width=10 (union base = 10)
};

bool test_basic_overlay() {
    p5::Union<ULayout> u{};
    const p5::uint<10> value{0b1010110011}; // 10-bit

    u.long_ = value;

    const uint64_t got_long  = p5::uint<10>(u.long_).to_ullong();
    const uint64_t got_short = p5::uint<2>(u.short_).to_ullong();  // bits8..9 (MSB-aligned)
    const uint64_t got_a     = p5::uint<3>(u.st.a).to_ullong();    // bits7..9 (struct packs MSB->LSB)
    const uint64_t got_b     = p5::uint<3>(u.st.b).to_ullong();    // bits4..6

    bool ok = true;
    ok &= expect_eq(got_long,  value.to_ullong(), "read/write long_ (full 10 bits)");
    ok &= expect_eq(got_short, 0b10,             "short_ reads high 2 bits (MSB-aligned)");
    ok &= expect_eq(got_a,     0b101,            "st.a reads bits7..9");
    ok &= expect_eq(got_b,     0b011,            "st.b reads bits4..6");

    // Write short_ should only affect low 2 bits, leaving others intact.
    u.short_ = p5::uint<2>(0);
    const uint64_t got_long2 = p5::uint<10>(u.long_).to_ullong();
    // 0b1010110011 with bits8..9 cleared -> 0b0010110011
    ok &= expect_eq(got_long2, 0b0010110011ULL, "write short_ affects only bits8..9");
    return ok;
}

bool test_nested_union_in_struct() {
    p5::Union<OuterLayout> u{};
    // Set raw bits then observe structured view.
    // raw = 10'b 1 0 1 0 1 1 0 0 1 1 (same as above)
    u.raw = p5::uint<10>(0b1010110011);

    bool ok = true;
    ok &= expect_eq(p5::uint<1>(u.st.a).to_ullong(), 1, "st.a (bit9)");
    ok &= expect_eq(p5::uint<5>(u.st.inner.y).to_ullong(), 0b01011, "st.inner.y (bits4..8)");
    ok &= expect_eq(p5::uint<2>(u.st.b).to_ullong(), 0b00, "st.b (bits2..3)");

    // Mutate nested union field and check raw view reflects it.
    u.st.inner.y = p5::uint<5>(0);
    // 0b1010110011 with bits4..8 cleared -> 0b1000000011
    ok &= expect_eq(p5::uint<10>(u.raw).to_ullong(), 0b1000000011ULL, "write inner.y clears bits4..8");
    return ok;
}

bool test_macro_factory_smoke() {
    // "Anonymous layout" via macro factory.
    auto u = P5_MAKE_UNION({
        p5::member<p5::uint<10>> long_;
        p5::member<p5::uint<2>> short_;
        struct {
            p5::member<p5::uint<3>> a;
            p5::member<p5::uint<3>> b;
        } st;
    });

    u.long_ = p5::uint<10>(0b1010110011);
    bool ok = true;
    ok &= expect_eq(p5::uint<2>(u.short_).to_ullong(), 0b10, "macro factory: short_ reads bits8..9");
    ok &= expect_eq(p5::uint<3>(u.st.a).to_ullong(), 0b101, "macro factory: st.a reads bits7..9");
    ok &= expect_eq(p5::uint<3>(u.st.b).to_ullong(), 0b011, "macro factory: st.b reads bits4..6");
    return ok;
}

bool test_c_array_members() {
    bool ok = true;

    // 1) Top-level array member overlays raw storage.
    {
        p5::Union<ArrLayoutTopLevel> u{};
        u.raw6 = p5::uint<6>(0b101011); // high3=101, low3=011

        ok &= expect_eq(u.a[0].to_ullong(), 0b101ULL, "c-array top-level: a[0] reads high 3 bits");
        ok &= expect_eq(u.a[1].to_ullong(), 0b011ULL, "c-array top-level: a[1] reads low 3 bits");

        // Mutate via array elements and verify raw view updates.
        u.a[0] = 0;
        ok &= expect_eq(u.raw6.to_ullong(), 0b000011ULL, "c-array top-level: write a[0] clears high 3 bits only");
        u.a[1] = 0;
        ok &= expect_eq(u.raw6.to_ullong(), 0b000000ULL, "c-array top-level: write a[1] clears low 3 bits only");
    }

    // 2) Array nested inside an aggregate struct, which is then used as a union member.
    {
        p5::Union<ArrLayoutInStruct> u{};
        u.raw6 = p5::uint<6>(0b111001); // split into 2-bit chunks: 11 10 01

        ok &= expect_eq(u.st.a[0].to_ullong(), 0b11ULL, "c-array in struct: st.a[0] reads bits4..5");
        ok &= expect_eq(u.st.a[1].to_ullong(), 0b10ULL, "c-array in struct: st.a[1] reads bits2..3");
        ok &= expect_eq(u.st.a[2].to_ullong(), 0b01ULL, "c-array in struct: st.a[2] reads bits0..1");

        // Mutate one element and ensure only its slice changes.
        u.st.a[1] = 0;
        ok &= expect_eq(u.raw6.to_ullong(), 0b110001ULL, "c-array in struct: write st.a[1] clears bits2..3 only");
    }

    return ok;
}

// A more complex nested example (macro factory version):
// - Top-level Union contains: uint members + struct member + Union member
// - struct member contains another Union member
// This shows the macro factory can handle multi-level nested layouts too.
struct InnerMostLayout {
    p5::member<p5::uint<3>> x;      // bits0..2
    p5::member<p5::uint<5>> y;      // bits0..4 (widest => inner width = 5)
    struct {
        p5::member<p5::uint<2>> p;  // bits0..1
        p5::member<p5::uint<2>> q;  // bits2..3
    } pq;                           // width=4
};
using InnerMostUnion = p5::Union<InnerMostLayout>;

struct AltLayout {
    p5::member<p5::uint<6>> low6;      // bits0..5
    struct {
        p5::member<p5::uint<2>> a;     // bits0..1
        p5::member<p5::uint<3>> b;     // bits2..4
        p5::member<p5::uint<1>> c;     // bit5
    } st6;                              // width=6
    p5::member<p5::uint<12>> low12;    // bits0..11 (widest => alt width = 12)
};

bool test_complex_nested_layout() {
    P5_UNION(u, {
        p5::member<p5::uint<16>> whole;        // bits0..15 (widest => union base = 16)
        p5::member<p5::uint<4>>  low4;         // bits0..3
        struct {
            p5::member<p5::uint<1>> flag;      // bit0
            InnerMostUnion inner;              // bits1..5 (width=5)
            p5::member<p5::uint<2>> pad;       // bits6..7
        } st;
        P5_UNION(alt, {
            p5::member<p5::uint<6>> low6;      // bits0..5
            struct {
                p5::member<p5::uint<2>> a;     // bits0..1
                p5::member<p5::uint<3>> b;     // bits2..4
                p5::member<p5::uint<1>> c;     // bit5
            } st6;                              // width=6
            p5::member<p5::uint<12>> low12;    // bits0..11 (widest => alt width = 12)
        });
    });

    // 16-bit baseline value.
    // Bits (low..high) for reference (LSB is bit0):
    // value = 0b1011001111010101 (msb..lsb)
    const uint64_t value = 0b1011001111010101ULL;
    u.whole = p5::uint<16>(value);

    bool ok = true;

    // Top-level uint views.
    ok &= expect_eq(u.whole.to_ullong(), value, "complex: whole reads full 16 bits");
    ok &= expect_eq(u.low4.to_ullong(),  0b1011ULL, "complex: low4 reads bits12..15 (MSB-aligned)");

    // Struct view (MSB->LSB packing inside struct; struct itself is MSB-aligned in 16-bit union).
    ok &= expect_eq(u.st.flag.to_ullong(), 0b1ULL, "complex: st.flag = bit15");
    ok &= expect_eq(p5::uint<5>(u.st.inner.y).to_ullong(), 0b01100ULL, "complex: st.inner.y = bits10..14");
    ok &= expect_eq(p5::uint<3>(u.st.inner.x).to_ullong(), 0b011ULL, "complex: st.inner.x = bits12..14");
    ok &= expect_eq(p5::uint<2>(u.st.inner.pq.p).to_ullong(), 0b01ULL, "complex: st.inner.pq.p = bits13..14");
    ok &= expect_eq(p5::uint<2>(u.st.inner.pq.q).to_ullong(), 0b10ULL, "complex: st.inner.pq.q = bits11..12");
    ok &= expect_eq(u.st.pad.to_ullong(), 0b11ULL, "complex: st.pad = bits8..9");

    // Union view (overlay) for another nested union member.
    ok &= expect_eq(u.alt.low6.to_ullong(),  0b101100ULL, "complex: alt.low6 = bits10..15");
    ok &= expect_eq(u.alt.st6.a.to_ullong(), 0b10ULL,     "complex: alt.st6.a = bits14..15");
    ok &= expect_eq(u.alt.st6.b.to_ullong(), 0b110ULL,    "complex: alt.st6.b = bits11..13");
    ok &= expect_eq(u.alt.st6.c.to_ullong(), 0b0ULL,      "complex: alt.st6.c = bit10");
    ok &= expect_eq(u.alt.low12.to_ullong(), 0b101100111101ULL, "complex: alt.low12 = bits4..15");

    // Write through nested union field and verify whole reflects the change (only bits10..14).
    u.st.inner.y = p5::uint<5>(0);
    // 0b1011001111010101 with bits10..14 cleared -> 0b1000001111010101
    ok &= expect_eq(u.whole.to_ullong(), 0b1000001111010101ULL, "complex: write st.inner.y clears bits10..14 only");

    // Write through another nested view and verify update (high 6 bits via alt.st6).
    u.alt.st6.a = 0;   // clear bits14..15
    u.alt.st6.b = 0;   // clear bits11..13
    u.alt.st6.c = 0;   // clear bit10
    // 0b1000001111010101 with bits10..15 cleared -> 0b0000001111010101
    ok &= expect_eq(u.whole.to_ullong(), 0b0000001111010101ULL, "complex: write alt.st6 clears bits10..15");

    return ok;
}

bool test_integral_assignment_and_implicit_reads() {
    p5::Union<ULayout> u{};

    // 直接用整型赋值（member 支持 Integral -> 写低位）
    u.long_ = 0;
    u.st.a = 7;     // 0b111 -> bits7..9
    u.st.b = 1;     // 0b001 -> bits4..6
    u.short_ = 3;   // 0b11  -> bits8..9（只覆盖最高 2 位）

    bool ok = true;

    // 不做显式类型转换：直接读 member.to_ullong()
    ok &= expect_eq(u.short_.to_ullong(), 0b11, "integral assign: short_.to_ullong()");
    ok &= expect_eq(u.st.a.to_ullong(),   0b111, "integral assign: st.a.to_ullong()");
    ok &= expect_eq(u.st.b.to_ullong(),   0b001, "integral assign: st.b.to_ullong()");

    // 隐式读成 p5::uint<N>
    p5::uint<10> long_read = u.long_;
    ok &= expect_eq(long_read.to_ullong(), 0b1110010000ULL, "implicit read: p5::uint<10> long_read = u.long_");

    // member 直接参与比较（不显式 cast）
    ok &= (u.short_ == 0b11);
    ok &= (u.short_ != 0b10);
    ok &= (u.short_ <  0b100);
    ok &= (u.short_ <= 0b11);
    ok &= (u.short_ >  0b1);
    ok &= (u.short_ >= 0b11);

    // member 直接参与算术表达式（结果是 p5::uint<N>）
    p5::uint<2> plus1 = u.short_ + 1; // 3+1 -> 0 (2-bit wrap)
    ok &= expect_eq(plus1.to_ullong(), 0b0, "implicit arithmetic: (u.short_ + 1) wraps at width");

    return ok;
}

bool test_union_assign_from_integral() {
    p5::Union<ULayout> u{};

    // 直接把整个 union 当成“底层 uint<width>”来写入：Integral -> storage_
    u = 0b1010110011; // width=10

    bool ok = true;
    ok &= expect_eq(u.long_.to_ullong(),  0b1010110011ULL, "union=Integral updates long_ view");
    ok &= expect_eq(u.short_.to_ullong(), 0b10ULL,         "union=Integral updates short_ view");
    ok &= expect_eq(u.st.a.to_ullong(),   0b101ULL,        "union=Integral updates st.a view");
    ok &= expect_eq(u.st.b.to_ullong(),   0b011ULL,        "union=Integral updates st.b view");
    return ok;
}

bool test_member_uint_like_ops() {
    // A small union with a single member view, to exercise p5::member's uint-like APIs.
    P5_UNION(u, { p5::member<p5::uint<8>> x; });

    u.x = 0b10101100; // 0xAC
    bool ok = true;

    // Read without explicit cast.
    ok &= expect_eq(u.x.to_ullong(), 0b10101100, "member: to_ullong reads");

    // integral-lhs and member-lhs expressions
    ok &= ((u.x & 0b00001111ULL).to_ullong() == 0b00001100ULL);
    ok &= ((0b00001111ULL & u.x).to_ullong() == 0b00001100ULL);
    ok &= ((u.x | 0b00000001ULL).to_ullong() == 0b10101101ULL);
    ok &= ((u.x ^ 0b11111111ULL).to_ullong() == 0b01010011ULL);
    ok &= ((0b1 + u.x).to_ullong() == 0b10101101ULL);

    // compound ops
    u.x += 1; // 0xAD
    ok &= expect_eq(u.x.to_ullong(), 0b10101101, "member: +=");
    u.x &= 0b00001111; // 0x0D
    ok &= expect_eq(u.x.to_ullong(), 0b00001101, "member: &=");
    u.x <<= 1; // 0x1A
    ok &= expect_eq(u.x.to_ullong(), 0b00011010, "member: <<=");

    // ++ / --
    ++u.x; // 0x1B
    ok &= expect_eq(u.x.to_ullong(), 0b00011011, "member: pre++");
    auto old = u.x++; // returns uint<8>(0x1B), then x=0x1C
    ok &= expect_eq(old.to_ullong(), 0b00011011, "member: post++ returns old");
    ok &= expect_eq(u.x.to_ullong(), 0b00011100, "member: post++ updates");

    // bit access
    u.x[0] = 1;
    ok &= (u.x[0] == true);

    // compile-time slice access
    u.x[p5::bit_range<3, 1>] = p5::uint<3>(0b101);
    p5::uint<3> s = u.x[p5::bit_range<3, 1>];
    ok &= expect_eq(s.to_ullong(), 0b101, "member: bit_range slice read/write");
    ok &= expect_eq(u.x.slice<3, 1>().to_ullong(), 0b101, "member: slice<High,Low>()");

    // nested slice: (x[5:0])[2:1] maps to x[2:1]
    u.x[p5::bit_range<5, 0>][p5::bit_range<2, 1>] = p5::uint<2>(0b10);
    ok &= expect_eq(u.x[p5::bit_range<2, 1>].to_ullong(), 0b10, "member: nested slice write");

    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_basic_overlay();
    all_ok &= test_nested_union_in_struct();
    all_ok &= test_macro_factory_smoke();
    all_ok &= test_c_array_members();
    all_ok &= test_complex_nested_layout();
    all_ok &= test_integral_assignment_and_implicit_reads();
    all_ok &= test_union_assign_from_integral();
    all_ok &= test_member_uint_like_ops();

    if (all_ok) {
        std::cout << "[PASS] p5::Union overlay tests\n";
        return 0;
    }
    std::cerr << "[FAIL] p5::Union overlay tests\n";
    return 1;
}

