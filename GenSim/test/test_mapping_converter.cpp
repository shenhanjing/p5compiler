// Test for GtvContext::_mapping_converter(): bidirectional mapping tables.
#include <iostream>

// Ensure we pick up the header that contains _mapping_converter().
// When building GenSim tests, pass -I.../out_dir/include (or ensure it is earlier than other generated include dirs).
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
    std::cerr << "[FAIL] " << msg << " got=" << got.to_ullong() << " expect=" << expect.to_ullong()
              << "\n";
    return false;
}

}  // namespace

int main() {
    std::cout << "[mapping_converter test] start\n";
    bool all_ok = true;

    GtvContext ctx{};

    // ---------------- Configure two tables with different widths ----------------
    // Table "GLTP": v4 is 10b, v2/v3 are 8b+8b (fits your example shape).
    const p5::uint<8> tb_expect = p5::uint<8>(0xAB);
    const p5::uint<8> tp_expect = p5::uint<8>(0xCD);
    const p5::uint<10> gltp_key_fv2ngsf = p5::uint<10>(0x155);  // 0b01_0101_0101
    const p5::uint<10> gltp_key_ngsf2fv = p5::uint<10>(0x341);  // deliberately different
    ctx.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;
    ctx._mapping_add("GLTP", tb_expect, tp_expect, gltp_key_fv2ngsf);  // FV2NGSF: key->(tb,tp)
    ctx.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
    ctx._mapping_add("GLTP", tb_expect, tp_expect, gltp_key_ngsf2fv);  // NGSF2FV: (tb,tp)->key (different)

    // Table "SMALL": non-byte-aligned widths (3b, 5b, 9b).
    const p5::uint<3> s2_expect = p5::uint<3>(0b101);
    const p5::uint<5> s3_expect = p5::uint<5>(0b11010);
    const p5::uint<9> s4_key = p5::uint<9>(0b1'0110'0101);  // 0x165
    ctx.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;
    ctx._mapping_add("SMALL", s2_expect, s3_expect, s4_key);  // add FV2NGSF entry
    ctx.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
    ctx._mapping_add("SMALL", s2_expect, s3_expect, s4_key);  // add NGSF2FV entry

    // ---------------- FV2NGSF direction: lookup by v4 -> set (v2,v3) ----------------
    ctx.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;

    // "GLTP" hit
    p5::uint<8> tb{};
    p5::uint<8> tp{};
    p5::uint<10> gltp = gltp_key_fv2ngsf;
    ctx._mapping_converter("GLTP", tb, tp, gltp);
    all_ok &= expect_eq_p5(tb, tb_expect, "FV2NGSF GLTP: tb");
    all_ok &= expect_eq_p5(tp, tp_expect, "FV2NGSF GLTP: tp");

    // "SMALL" hit
    p5::uint<3> s2{};
    p5::uint<5> s3{};
    p5::uint<9> s4 = s4_key;
    ctx._mapping_converter("SMALL", s2, s3, s4);
    all_ok &= expect_eq_p5(s2, s2_expect, "FV2NGSF SMALL: v2");
    all_ok &= expect_eq_p5(s3, s3_expect, "FV2NGSF SMALL: v3");

    // Miss case should zero (v2,v3)
    p5::uint<8> miss2 = p5::uint<8>(0xFF);
    p5::uint<8> miss3 = p5::uint<8>(0xFF);
    p5::uint<10> miss4 = p5::uint<10>(0x3FF);  // not configured
    ctx._mapping_converter("GLTP", miss2, miss3, miss4);
    all_ok &= expect_eq_u64(miss2.to_ullong(), 0, "FV2NGSF miss: v2 zero");
    all_ok &= expect_eq_u64(miss3.to_ullong(), 0, "FV2NGSF miss: v3 zero");

    // ---------------- NGSF2FV direction: lookup by concat(v2,v3) -> set v4 ----------------
    ctx.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;

    // "GLTP" hit
    p5::uint<8> tb2 = tb_expect;
    p5::uint<8> tp2 = tp_expect;
    p5::uint<10> gltp2{};
    ctx._mapping_converter("GLTP", tb2, tp2, gltp2);
    all_ok &= expect_eq_p5(gltp2, gltp_key_ngsf2fv, "NGSF2FV GLTP: gltp (direction can differ)");

    // "SMALL" hit
    p5::uint<3> s2b = s2_expect;
    p5::uint<5> s3b = s3_expect;
    p5::uint<9> s4b{};
    ctx._mapping_converter("SMALL", s2b, s3b, s4b);
    all_ok &= expect_eq_p5(s4b, s4_key, "NGSF2FV SMALL: v4");

    // Miss case should zero v4
    p5::uint<8> miss2b = p5::uint<8>(0x12);
    p5::uint<8> miss3b = p5::uint<8>(0x34);
    p5::uint<10> miss4b = p5::uint<10>(0x3FF);
    ctx._mapping_converter("GLTP", miss2b, miss3b, miss4b);
    all_ok &= expect_eq_u64(miss4b.to_ullong(), 0, "NGSF2FV miss: v4 zero");

    // ---------------- Table isolation: same keys in different tables must not conflict ----------------
    // Use same (tb,tp) in a different table name; it should NOT affect "GLTP".
    ctx.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;
    ctx._mapping_add("OTHER", tb_expect, tp_expect, p5::uint<10>(0x2AA));  // only FV2NGSF side
    p5::uint<10> gltp3{};
    ctx.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
    ctx._mapping_converter("GLTP", tb2, tp2, gltp3);
    all_ok &= expect_eq_p5(gltp3, gltp_key_ngsf2fv, "table isolation: GLTP unaffected by OTHER");

    // ---------------- Directional independence: FV2NGSF and NGSF2FV can differ ----------------
    // Create a table where only one direction is configured at a time and verify behavior differs.
    {
        GtvContext ctx2{};
        const p5::uint<8> a = p5::uint<8>(0x11);
        const p5::uint<8> b = p5::uint<8>(0x22);
        const p5::uint<10> k1 = p5::uint<10>(0x123);
        const p5::uint<10> k2 = p5::uint<10>(0x321);

        // Only configure FV2NGSF: k1 -> (a,b)
        ctx2.ngsf_direction = GtvContext::NgsfDirection::FV2NGSF;
        ctx2._mapping_add("ONEWAY", a, b, k1);

        p5::uint<8> oa{};
        p5::uint<8> ob{};
        p5::uint<10> ok = k1;
        ctx2._mapping_converter("ONEWAY", oa, ob, ok);
        all_ok &= expect_eq_p5(oa, a, "directional: FV2NGSF hit v2");
        all_ok &= expect_eq_p5(ob, b, "directional: FV2NGSF hit v3");

        // In NGSF2FV direction, (a,b) should MISS (since NGSF2FV map not configured) and return 0.
        ctx2.ngsf_direction = GtvContext::NgsfDirection::NGSF2FV;
        p5::uint<8> ia = a;
        p5::uint<8> ib = b;
        p5::uint<10> outk = k2;  // non-zero seed to ensure it gets cleared on miss
        ctx2._mapping_converter("ONEWAY", ia, ib, outk);
        all_ok &= expect_eq_u64(outk.to_ullong(), 0, "directional: NGSF2FV miss returns 0");
    }

    std::cout << "[mapping_converter test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}

