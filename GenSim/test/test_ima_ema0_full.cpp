// Integrated test: pre_iMAControl -> iMA0Control -> iMA1Control -> eMA0Control
// Covers parser extract, IPAT (INDEX), FIB (LPM), EPAT (INDEX), ENCAP (INDEX) and eMA0 HM overwrite.
#include <array>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

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

uint64_t mac48(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5) {
    return (static_cast<uint64_t>(b0) << 40) | (static_cast<uint64_t>(b1) << 32) | (static_cast<uint64_t>(b2) << 24) |
           (static_cast<uint64_t>(b3) << 16) | (static_cast<uint64_t>(b4) << 8) | static_cast<uint64_t>(b5);
}

void build_ipv4_udp_pkt(PktHeader &pkt, uint8_t ttl, uint8_t tos, uint32_t sip, uint32_t dip) {
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> buf{};
    // Ethernet: DMAC=00:11:22:33:44:55, SMAC=66:77:88:99:aa:bb, EtherType IPv4
    uint8_t eth[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55,
        0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
        0x08, 0x00
    };
    std::memcpy(buf.data(), eth, sizeof(eth));

    // IPv4 header (20 bytes), checksum ignored
    std::array<uint8_t, 20> ipv4{};
    ipv4[0] = 0x45;                 // Version=4, IHL=5
    ipv4[1] = tos;                  // TOS
    ipv4[2] = 0x00; ipv4[3] = 0x1c; // Total length = 28
    ipv4[4] = 0x00; ipv4[5] = 0x01; // Identification
    ipv4[6] = 0x00; ipv4[7] = 0x00; // Flags/Fragment offset
    ipv4[8] = ttl;                  // TTL
    ipv4[9] = 0x11;                 // Protocol = UDP
    ipv4[10] = 0x00; ipv4[11] = 0x00;
    ipv4[12] = static_cast<uint8_t>((sip >> 24) & 0xff);
    ipv4[13] = static_cast<uint8_t>((sip >> 16) & 0xff);
    ipv4[14] = static_cast<uint8_t>((sip >> 8) & 0xff);
    ipv4[15] = static_cast<uint8_t>(sip & 0xff);
    ipv4[16] = static_cast<uint8_t>((dip >> 24) & 0xff);
    ipv4[17] = static_cast<uint8_t>((dip >> 16) & 0xff);
    ipv4[18] = static_cast<uint8_t>((dip >> 8) & 0xff);
    ipv4[19] = static_cast<uint8_t>(dip & 0xff);
    std::memcpy(buf.data() + 14, ipv4.data(), ipv4.size());

    // UDP (8 bytes)
    std::array<uint8_t, 8> udp{};
    udp[0] = 0x03; udp[1] = 0xe8; // sport 1000
    udp[2] = 0x07; udp[3] = 0xd0; // dport 2000
    udp[4] = 0x00; udp[5] = 0x08;
    udp[6] = 0x00; udp[7] = 0x00;
    std::memcpy(buf.data() + 14 + 20, udp.data(), udp.size());

    std::memcpy(pkt.pkt_data, buf.data(), PKT_HEADER_BYTE_LEN);
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
    std::cout << "[integrated iMA+eMA0 test] start\n";

    Switch sw;
    auto &se = sw.searchEngine();
    auto &key = sw.keyManager();

    // Init 4 tables used across iMA/eMA0.
    se.initTable<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, MatchType::INDEX);
    se.initTable<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, MatchType::LPM);
    se.initTable<p5::uint<10>, EPATRSP_S>(SE_TID_EPAT, MatchType::INDEX);
    se.initTable<p5::uint<8>, ENCAPRSP_S>(SE_TID_ENCAP, MatchType::INDEX);

    // Key slots: 10 (IPAT/EPAT), 136 (FIB v4), 8 (ENCAP)
    key.initKey({10, 136, 8});

    // Common config for the "hit" path:
    // - IPAT: GLSP=10 -> VrfId=100
    // - FIB:  vrf=100 + dip=10.0.0.2 (/32) -> port=25, encap=3
    // - EPAT: GLTP=25 -> SMAC
    // - ENCAP: idx=3 -> DMAC
    se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, p5::uint<10>(10), IPATRSP_S{1, 0, 0, 100, {}});

    key.buildKey(p5::uint<8>(100), p5::uint<32>(0x0A000002), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    auto fib_key_host = key.getKey<p5::uint<136>>(136);
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, fib_key_host, FIBRSP_S{25, 3}, 8 + 32);

    const uint64_t cfg_smac = mac48(0x66, 0x55, 0x44, 0x33, 0x22, 0x11);
    const uint64_t cfg_dmac = mac48(0x11, 0x22, 0x33, 0x44, 0x55, 0x66);
    se.config<p5::uint<10>, EPATRSP_S>(SE_TID_EPAT, p5::uint<10>(25), make_epat_rsp(cfg_smac));
    se.config<p5::uint<8>, ENCAPRSP_S>(SE_TID_ENCAP, p5::uint<8>(3), make_encap_rsp(cfg_dmac));

    struct Case {
        std::string name;
        uint16_t port_id;
        bool expect_hit;
    };
    std::vector<Case> cases = {
        {"hit-all-stages", 10, true},
        {"ipat-miss-drop", 11, false},
    };

    bool all_ok = true;

    for (const auto &tc : cases) {
        // Load packet into switch data buffer (so pre_iMAControl can parse it).
        sw.reset_all_fields();
        PktHeader pkt{};
        const uint8_t pkt_ttl = 64;
        const uint8_t pkt_tos = 0x10;
        build_ipv4_udp_pkt(pkt, pkt_ttl, pkt_tos, /*sip=*/0x0A000001, /*dip=*/0x0A000002);
        std::memcpy(sw.data_.data(), pkt.pkt_data, PKT_HEADER_BYTE_LEN);
        sw.reset_offset();
        sw.PHI.PortType = PORT_TYPE_ETH;
        sw.GLSP = tc.port_id;

        // ---- Required sequence ----
        sw.pre_iMAControl(); // parser extract: ETHER/IPv4/UDP + PHI/PHO

        // Seed GTV fields from parsed IPv4 header so iMA1Action (TTL--) and eMA0 HM overwrite are meaningful.
        sw.TTL = sw.IPv4.TTL;
        sw.TOS = sw.IPv4.u_0.TOS;

        sw.iMA0Control();    // IPAT -> Vrf/IsUc/DropFlag
        sw.iMA1Control();    // FIB  -> GLTP/EncapIndex/TTL--
        sw.eMA0Control();    // EPAT/ENCAP -> HM overwrite gated by EncapProfile

        bool ok = true;

        if (tc.expect_hit) {
            ok &= expect_true(se.status(SE_TID_IPAT) == SearchEngine::Status::MATCH, "IPAT status MATCH");
            ok &= expect_true(se.status(SE_TID_FIB) == SearchEngine::Status::MATCH, "FIB status MATCH");
            ok &= expect_true(se.status(SE_TID_EPAT) == SearchEngine::Status::MATCH, "EPAT status MATCH");
            ok &= expect_true(se.status(SE_TID_ENCAP) == SearchEngine::Status::MATCH, "ENCAP status MATCH");

            ok &= expect_eq_u64(sw.DropFlag.to_ullong(), 0, "DropFlag=0 on hit");
            ok &= expect_eq_u64(sw.IsUc.to_ullong(), 1, "IsUc=1 on hit");
            ok &= expect_eq_u64(sw.Vrf.to_ullong(), 100, "Vrf=100 from IPAT");

            ok &= expect_eq_u64(sw.GLTP.to_ullong(), 25, "GLTP=25 from FIB");
            ok &= expect_eq_u64(sw.EncapIndex.to_ullong(), 3, "EncapIndex=3 from FIB");
            ok &= expect_eq_u64(sw.TTL.to_ullong(), 63, "TTL decremented by iMA1Action");

            ok &= expect_eq_u64(sw.EncapProfile.to_ullong(), 1, "EncapProfile=1 when IsUc=1");
            ok &= expect_eq_u64(sw.ETHER.Dmac.to_ullong(), cfg_dmac, "ETHER.Dmac overwritten by eMA0");
            ok &= expect_eq_u64(sw.ETHER.Smac.to_ullong(), cfg_smac, "ETHER.Smac overwritten by eMA0");
            ok &= expect_eq_u64(sw.IPv4.TTL.to_ullong(), 63, "IPv4.TTL overwritten with decremented TTL");
            ok &= expect_eq_u64(sw.IPv4.u_0.TOS.to_ullong(), pkt_tos, "IPv4.TOS overwritten from TOS");
        } else {
            // IPAT miss => DropFlag set, IsUc remains 0 => EncapProfile=0 => no overwrite.
            ok &= expect_true(se.status(SE_TID_IPAT) == SearchEngine::Status::NO_MATCH, "IPAT status NO_MATCH");
            ok &= expect_eq_u64(sw.DropFlag.to_ullong(), 1, "DropFlag=1 on IPAT miss");
            ok &= expect_eq_u64(sw.IsUc.to_ullong(), 0, "IsUc=0 on IPAT miss");
            ok &= expect_eq_u64(sw.EncapProfile.to_ullong(), 0, "EncapProfile=0 when IsUc=0");

            // Ethernet stays as parsed from the packet.
            const uint64_t pkt_dmac = mac48(0x00, 0x11, 0x22, 0x33, 0x44, 0x55);
            const uint64_t pkt_smac = mac48(0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb);
            ok &= expect_eq_u64(sw.ETHER.Dmac.to_ullong(), pkt_dmac, "ETHER.Dmac unchanged on drop");
            ok &= expect_eq_u64(sw.ETHER.Smac.to_ullong(), pkt_smac, "ETHER.Smac unchanged on drop");
        }

        all_ok = all_ok && ok;
        std::cout << tc.name << " => " << (ok ? "PASS" : "FAIL") << "\n";
    }

    std::cout << "[integrated iMA+eMA0 test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}


