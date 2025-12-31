// eMA0 tests: EPAT/ENCAP INDEX lookups + EncapProfile gating + HM overwrites
#include <iostream>

#include "generated_Switch.hpp"

namespace {

bool expect_eq_u64(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

bool expect_eq_bool(bool got, bool expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << (got ? 1 : 0) << " expect=" << (expect ? 1 : 0) << "\n";
    return false;
}

EPATRSP_S make_epat_rsp(uint64_t smac48) {
    EPATRSP_S v{};
    v.Valid = 1;
    v.Rsvd = 0;
    v.Dma.Addr.SMAC = p5::uint<48>(smac48);
    return v;
}

ENCAPRSP_S make_encap_rsp(uint64_t dmac48) {
    ENCAPRSP_S v{};
    v.Valid = 1;
    v.Rsvd = 0;
    v.Dma.Arp.DMAC = p5::uint<48>(dmac48);
    return v;
}

} // namespace

int main() {
    std::cout << "[eMA0 test] start\n";

    Switch sw;
    auto &se = sw.searchEngine();
    auto &key = sw.keyManager();

    // eMA0 uses:
    // - EPAT: key=GLTP (uint<10>) INDEX
    // - ENCAP: key=EncapIndex (uint<8>) INDEX
    se.initTable<p5::uint<10>, EPATRSP_S>(SE_TID_EPAT, MatchType::INDEX);
    se.initTable<p5::uint<8>, ENCAPRSP_S>(SE_TID_ENCAP, MatchType::INDEX);
    key.initKey({10, 8});

    // Configure: EPAT hit at GLTP=42, ENCAP hit at idx=7
    const uint16_t k_gltp = 42;
    const uint8_t k_encap = 7;
    const uint64_t expect_smac = 0x665544332211ULL;
    const uint64_t expect_dmac = 0x112233445566ULL;

    se.config<p5::uint<10>, EPATRSP_S>(SE_TID_EPAT, p5::uint<10>(k_gltp), make_epat_rsp(expect_smac));
    se.config<p5::uint<8>, ENCAPRSP_S>(SE_TID_ENCAP, p5::uint<8>(k_encap), make_encap_rsp(expect_dmac));

    bool all_ok = true;

    // ---- Case 1: IsUc=1 => EncapProfile=1, overwrite ETHER + IPv4 fields ----
    {
        sw.reset_all_fields();
        sw.PHI.PortType = PORT_TYPE_ETH;
        sw.IsUc = 1;
        sw.GLTP = k_gltp;
        sw.EncapIndex = k_encap;
        sw.TTL = 60;
        sw.TOS = 0x5a;

        // Set baseline values that should be overwritten.
        sw.ETHER.Dmac = p5::uint<48>(0);
        sw.ETHER.Smac = p5::uint<48>(0);
        sw.IPv4.TTL = p5::uint<8>(0);
        sw.IPv4.u_0.TOS = p5::uint<8>(0);

        sw.eMA0Control();

        all_ok &= expect_eq_bool(se.status(SE_TID_EPAT) == SearchEngine::Status::MATCH, true, "EPAT status MATCH");
        all_ok &= expect_eq_bool(se.status(SE_TID_ENCAP) == SearchEngine::Status::MATCH, true, "ENCAP status MATCH");
        all_ok &= expect_eq_u64(sw.EncapProfile.to_ullong(), 1, "EncapProfile=1 when IsUc=1");
        all_ok &= expect_eq_u64(sw.ETHER.Dmac.to_ullong(), expect_dmac, "ETHER.Dmac overwritten from ENCAP");
        all_ok &= expect_eq_u64(sw.ETHER.Smac.to_ullong(), expect_smac, "ETHER.Smac overwritten from EPAT");
        all_ok &= expect_eq_u64(sw.IPv4.TTL.to_ullong(), 60, "IPv4.TTL overwritten from TTL");
        all_ok &= expect_eq_u64(sw.IPv4.u_0.TOS.to_ullong(), 0x5a, "IPv4.TOS overwritten from TOS");
    }

    // ---- Case 2: IsUc=0 => EncapProfile=0, no overwrite ----
    {
        sw.reset_all_fields();
        sw.PHI.PortType = PORT_TYPE_ETH;
        sw.IsUc = 0;
        sw.GLTP = k_gltp;
        sw.EncapIndex = k_encap;
        sw.TTL = 99;
        sw.TOS = 0x34;

        const uint64_t base_dmac = 0x00deadbeef0001ULL;
        const uint64_t base_smac = 0x00deadbeef0002ULL;
        sw.ETHER.Dmac = p5::uint<48>(base_dmac);
        sw.ETHER.Smac = p5::uint<48>(base_smac);
        sw.IPv4.TTL = p5::uint<8>(0x40);
        sw.IPv4.u_0.TOS = p5::uint<8>(0x12);

        sw.eMA0Control();

        all_ok &= expect_eq_u64(sw.EncapProfile.to_ullong(), 0, "EncapProfile=0 when IsUc=0");
        all_ok &= expect_eq_u64(sw.ETHER.Dmac.to_ullong(), base_dmac, "ETHER.Dmac unchanged when EncapProfile=0");
        all_ok &= expect_eq_u64(sw.ETHER.Smac.to_ullong(), base_smac, "ETHER.Smac unchanged when EncapProfile=0");
        all_ok &= expect_eq_u64(sw.IPv4.TTL.to_ullong(), 0x40, "IPv4.TTL unchanged when EncapProfile=0");
        all_ok &= expect_eq_u64(sw.IPv4.u_0.TOS.to_ullong(), 0x12, "IPv4.TOS unchanged when EncapProfile=0");
    }

    // ---- Case 3: IsUc=1, ENCAP miss => Dmac becomes 0, Smac still from EPAT hit ----
    {
        sw.reset_all_fields();
        sw.PHI.PortType = PORT_TYPE_ETH;
        sw.IsUc = 1;
        sw.GLTP = k_gltp;
        sw.EncapIndex = 9; // not configured
        sw.TTL = 1;
        sw.TOS = 0xff;

        sw.ETHER.Dmac = p5::uint<48>(0x123456789abcULL);
        sw.ETHER.Smac = p5::uint<48>(0xcba987654321ULL);

        sw.eMA0Control();

        all_ok &= expect_eq_bool(se.status(SE_TID_EPAT) == SearchEngine::Status::MATCH, true, "EPAT status MATCH (case3)");
        all_ok &= expect_eq_bool(se.status(SE_TID_ENCAP) == SearchEngine::Status::NO_MATCH, true, "ENCAP status NO_MATCH (case3)");
        all_ok &= expect_eq_u64(sw.EncapProfile.to_ullong(), 1, "EncapProfile=1 (case3)");
        all_ok &= expect_eq_u64(sw.ETHER.Dmac.to_ullong(), 0, "ETHER.Dmac becomes 0 on ENCAP miss");
        all_ok &= expect_eq_u64(sw.ETHER.Smac.to_ullong(), expect_smac, "ETHER.Smac still from EPAT hit on ENCAP miss");
        all_ok &= expect_eq_u64(sw.IPv4.TTL.to_ullong(), 1, "IPv4.TTL overwritten even when ENCAP miss");
        all_ok &= expect_eq_u64(sw.IPv4.u_0.TOS.to_ullong(), 0xff, "IPv4.TOS overwritten even when ENCAP miss");
    }

    std::cout << "[eMA0 test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}


