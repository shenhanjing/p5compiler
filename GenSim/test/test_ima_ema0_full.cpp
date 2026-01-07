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

void build_ipv4_tcp_pkt(PktHeader &pkt, uint8_t ttl, uint8_t tos, uint32_t sip, uint32_t dip) {
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> buf{};
    // Ethernet: DMAC=00:11:22:33:44:55, SMAC=66:77:88:99:aa:bb, EtherType IPv4
    uint8_t eth[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55,
        0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
        0x08, 0x00
    };
    std::memcpy(buf.data(), eth, sizeof(eth));

    // IPv4 header (20 bytes)
    std::array<uint8_t, 20> ipv4{};
    ipv4[0] = 0x45;
    ipv4[1] = tos;
    ipv4[2] = 0x00;
    ipv4[3] = 0x28;  // total len 40 (20 IP + 20 TCP)
    ipv4[4] = 0x00;
    ipv4[5] = 0x01;
    ipv4[6] = 0x00;
    ipv4[7] = 0x00;
    ipv4[8] = ttl;
    ipv4[9] = 0x06;  // TCP
    ipv4[10] = 0x00;
    ipv4[11] = 0x00;
    ipv4[12] = static_cast<uint8_t>((sip >> 24) & 0xff);
    ipv4[13] = static_cast<uint8_t>((sip >> 16) & 0xff);
    ipv4[14] = static_cast<uint8_t>((sip >> 8) & 0xff);
    ipv4[15] = static_cast<uint8_t>(sip & 0xff);
    ipv4[16] = static_cast<uint8_t>((dip >> 24) & 0xff);
    ipv4[17] = static_cast<uint8_t>((dip >> 16) & 0xff);
    ipv4[18] = static_cast<uint8_t>((dip >> 8) & 0xff);
    ipv4[19] = static_cast<uint8_t>(dip & 0xff);
    std::memcpy(buf.data() + 14, ipv4.data(), ipv4.size());

    // TCP (20 bytes)
    std::array<uint8_t, 20> tcp{};
    tcp[0] = 0x13;
    tcp[1] = 0x88;  // sport 5000
    tcp[2] = 0x1f;
    tcp[3] = 0x90;  // dport 8080
    tcp[12] = 0x50; // data offset=5
    std::memcpy(buf.data() + 14 + 20, tcp.data(), tcp.size());

    std::memcpy(pkt.pkt_data, buf.data(), PKT_HEADER_BYTE_LEN);
}

void build_ipv6_tcp_pkt(PktHeader &pkt, uint8_t hop_limit, uint8_t traffic_class,
                        const std::array<uint8_t, 16> &sip, const std::array<uint8_t, 16> &dip) {
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> buf{};
    // Ethernet: DMAC=00:11:22:33:44:55, SMAC=66:77:88:99:aa:bb, EtherType IPv6
    uint8_t eth[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55,
        0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
        0x86, 0xdd
    };
    std::memcpy(buf.data(), eth, sizeof(eth));

    // IPv6 header (40 bytes)
    std::array<uint8_t, 40> ipv6{};
    // Version(6) + Traffic Class(8) + Flow Label(20)
    ipv6[0] = static_cast<uint8_t>(0x60 | ((traffic_class >> 4) & 0x0f));
    ipv6[1] = static_cast<uint8_t>(((traffic_class & 0x0f) << 4) | 0x00);
    ipv6[2] = 0x00;
    ipv6[3] = 0x00;

    // Payload len: TCP header only (20 bytes)
    ipv6[4] = 0x00;
    ipv6[5] = 0x14;
    ipv6[6] = 0x06;  // Next header: TCP
    ipv6[7] = hop_limit;

    std::memcpy(ipv6.data() + 8, sip.data(), sip.size());
    std::memcpy(ipv6.data() + 24, dip.data(), dip.size());
    std::memcpy(buf.data() + 14, ipv6.data(), ipv6.size());

    // TCP (20 bytes)
    std::array<uint8_t, 20> tcp{};
    tcp[0] = 0x13;
    tcp[1] = 0x88;  // sport 5000
    tcp[2] = 0x1f;
    tcp[3] = 0x90;  // dport 8080
    tcp[12] = 0x50; // data offset=5
    std::memcpy(buf.data() + 14 + 40, tcp.data(), tcp.size());

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

MaToMaFvInfoDef to_ma_fv(const Prs2Ma0FvInfoDef &prs_fv) {
    MaToMaFvInfoDef fv{};
    std::memcpy(fv.phData, prs_fv.phData, PKT_HEADER_BYTE_LEN);
    std::memcpy(fv.phiData, prs_fv.phiData, FV_PHI_BYTE_NUM);
    std::memcpy(fv.phoData, prs_fv.phoData, FV_PHO_BYTE_NUM);
    std::memcpy(fv.gtvData, prs_fv.gtvData, FV_GTV_MAX_BYTE_NUM);
    // udf/pgtv are not used by SingleMaProc in current generated flow.
    return fv;
}

template <std::size_t Bits>
p5::uint<Bits> uint_from_bytes_msb_first(const std::array<uint8_t, Bits / 8> &bytes) {
    std::vector<bool> bits;
    bits.reserve(Bits);
    for (auto b : bytes) {
        for (int i = 7; i >= 0; --i) bits.push_back(((b >> i) & 1) != 0);
    }
    return p5::uint<Bits>::from_bits(bits);
}

// Keep the original test semantics: seed FV-level TTL from parsed L3 header so iMA1Action (TTL--)
// and eMA0 HM overwrite are meaningful.
// - IPv4: TTL/TOS from IPv4 header
// - IPv6: TTL from HopLimit (TOS is not relied upon in IPv6 cases)
void seed_fv_ttl_tos_from_parsed_l3(MaToMaFvInfoDef &fv) {
    Switch tmp;
    tmp.reset_all_fields();

    // Unpack PHI (not part of GTV) so we can tell IPv4 vs IPv6.
    Switch::PhiPackedBuffer phiIn{};
    std::memcpy(phiIn.data(), fv.phiData, FV_PHI_BYTE_NUM);
    tmp.unpack_phi_from_bytes(phiIn);

    // Unpack GTV into tmp (contains outer headers + fv fields).
    Switch::GtvPackedBuffer gtvIn{};
    std::memcpy(gtvIn.data(), fv.gtvData, FV_GTV_MAX_BYTE_NUM);
    tmp.unpack_gtv_from_bytes(gtvIn);

    // Copy parsed L3 header fields into FV-level fields.
    if (tmp.PHI.L3Type.to_ullong() == L3_TYPE_IPv4) {
        tmp.TTL = tmp.IPv4.TTL;
        tmp.TOS = tmp.IPv4.u_0.TOS;
    } else if (tmp.PHI.L3Type.to_ullong() == L3_TYPE_IPv6) {
        tmp.TTL = tmp.IPv6.HopLmt;
    }

    auto gtvOut = tmp.pack_gtv_to_bytes();
    std::memcpy(fv.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);
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
    // - IPAT: GLSP=20 -> VrfId=200
    // - FIB:  vrf=100 + dip=10.0.0.2 (/32) -> port=25, encap=3
    // - FIB:  vrf=200 + dip=10.1.0.0 (/16) -> port=55, encap=7
    // - EPAT: GLTP=25/55 -> SMAC
    // - ENCAP: idx=3/7 -> DMAC
    se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, p5::uint<10>(10), IPATRSP_S{1, 0, 0, 100, {}});
    se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, p5::uint<10>(20), IPATRSP_S{1, 0, 0, 200, {}});

    key.buildKey(p5::uint<8>(100), p5::uint<32>(0x0A000002), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    auto fib_key_host = key.getKey<p5::uint<136>>(136);
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, fib_key_host, FIBRSP_S{25, 3}, 8 + 32);

    // Extra FIB entries for negative coverage:
    // - EPAT miss only: port=99, encap=3 (ENCAP hit, EPAT miss)
    key.buildKey(p5::uint<8>(100), p5::uint<32>(0x0A000004), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, key.getKey<p5::uint<136>>(136), FIBRSP_S{99, 3}, 8 + 32);
    // - ENCAP miss only: port=25, encap=9 (EPAT hit, ENCAP miss)
    key.buildKey(p5::uint<8>(100), p5::uint<32>(0x0A000005), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, key.getKey<p5::uint<136>>(136), FIBRSP_S{25, 9}, 8 + 32);
    // - Both miss: port=99, encap=9 (EPAT miss, ENCAP miss)
    key.buildKey(p5::uint<8>(100), p5::uint<32>(0x0A000003), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, key.getKey<p5::uint<136>>(136), FIBRSP_S{99, 9}, 8 + 32);

    // LPM /16 for vrf=200 + dip=10.1.0.0/16
    key.buildKey(p5::uint<8>(200), p5::uint<32>(0x0A010000), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, key.getKey<p5::uint<136>>(136), FIBRSP_S{55, 7}, 8 + 16);

    // IPv6 FIB /128 for vrf=100 + dip=2001:db8::2 -> port=25, encap=3
    const std::array<uint8_t, 16> sip6 = {0x20, 0x01, 0x0d, 0xb8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x01};
    const std::array<uint8_t, 16> dip6 = {0x20, 0x01, 0x0d, 0xb8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x02};
    const auto dip6_u128 = uint_from_bytes_msb_first<128>(dip6);
    key.buildKey(p5::uint<8>(100), dip6_u128);
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, key.getKey<p5::uint<136>>(136), FIBRSP_S{25, 3}, 8 + 128);

    const uint64_t cfg_smac_25 = mac48(0x66, 0x55, 0x44, 0x33, 0x22, 0x11);
    const uint64_t cfg_smac_55 = mac48(0x10, 0x20, 0x30, 0x40, 0x50, 0x60);
    const uint64_t cfg_dmac_3  = mac48(0x11, 0x22, 0x33, 0x44, 0x55, 0x66);
    const uint64_t cfg_dmac_7  = mac48(0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff);
    se.config<p5::uint<10>, EPATRSP_S>(SE_TID_EPAT, p5::uint<10>(25), make_epat_rsp(cfg_smac_25));
    se.config<p5::uint<10>, EPATRSP_S>(SE_TID_EPAT, p5::uint<10>(55), make_epat_rsp(cfg_smac_55));
    se.config<p5::uint<8>, ENCAPRSP_S>(SE_TID_ENCAP, p5::uint<8>(3), make_encap_rsp(cfg_dmac_3));
    se.config<p5::uint<8>, ENCAPRSP_S>(SE_TID_ENCAP, p5::uint<8>(7), make_encap_rsp(cfg_dmac_7));

    struct Case {
        std::string name;
        enum class PktKind { IPV4_UDP, IPV4_TCP, IPV6_TCP } kind;
        uint16_t port_id;
        uint32_t dip;
        uint8_t ttl;
        uint8_t tos;
        bool expect_hit;
        bool expect_fib_hit;
        bool expect_epat_hit;
        bool expect_encap_hit;
        uint16_t expect_gltp;
        uint8_t expect_encap;
        uint8_t expect_ttl_out;
        uint64_t expect_dmac;
        uint64_t expect_smac;
        uint8_t expect_l3;
        uint8_t expect_l4;
        bool check_ipv4_overwrite;
    };
    std::vector<Case> cases = {
        // name,           port_id, dip,        ttl, tos,  ipat_hit, fib_hit, epat_hit, encap_hit,
        // expect_gltp, expect_encap, expect_ttl_out, expect_dmac,  expect_smac
        {"hit-all-stages", Case::PktKind::IPV4_UDP, 10, 0x0A000002, 64, 0x10, true,  true,  true,  true,
            25, 3, 63, cfg_dmac_3, cfg_smac_25, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
        {"hit-all-stages-tcp", Case::PktKind::IPV4_TCP, 10, 0x0A000002, 64, 0x22, true,  true,  true,  true,
            25, 3, 63, cfg_dmac_3, cfg_smac_25, L3_TYPE_IPv4, L4_PROTOCOL_TCP, true},
        {"hit-vrf200-lpm16", Case::PktKind::IPV4_UDP, 20, 0x0A010203, 128, 0x5a, true,  true,  true,  true,
            55, 7, 127, cfg_dmac_7, cfg_smac_55, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
        {"fib-miss-no-route", Case::PktKind::IPV4_UDP, 10, 0x0A000099, 64, 0x10, true,  false, false, false,
            0, 0, 64, 0, 0, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
        {"epat-miss-only", Case::PktKind::IPV4_UDP, 10, 0x0A000004, 64, 0x10, true,  true,  false, true,
            99, 3, 63, cfg_dmac_3, 0, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
        {"encap-miss-only", Case::PktKind::IPV4_UDP, 10, 0x0A000005, 64, 0x10, true,  true,  true,  false,
            25, 9, 63, 0, cfg_smac_25, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
        {"epat+encap-miss", Case::PktKind::IPV4_UDP, 10, 0x0A000003, 64, 0x10, true,  true,  false, false,
            99, 9, 63, 0, 0, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
        // IPv6 + TCP hit path (FIB v6 /128 configured above).
        // - ttl/tos are used only for packet construction; FV TTL is seeded from IPv6 HopLimit.
        {"ipv6-tcp-hit-all-stages", Case::PktKind::IPV6_TCP, 10, /*dip=*/0, 64, 0x33, true, true, true, true,
            25, 3, 63, cfg_dmac_3, cfg_smac_25, L3_TYPE_IPv6, L4_PROTOCOL_TCP, false},
        {"ipat-miss-drop", Case::PktKind::IPV4_UDP, 11, 0x0A000002, 64, 0x10, false, false, false, false,
            0, 0, 64, 0, 0, L3_TYPE_IPv4, L4_PROTOCOL_UDP, true},
    };

    bool all_ok = true;

    for (const auto &tc : cases) {
        PktHeader pkt{};
        switch (tc.kind) {
            case Case::PktKind::IPV4_UDP:
                build_ipv4_udp_pkt(pkt, tc.ttl, tc.tos, /*sip=*/0x0A000001, /*dip=*/tc.dip);
                break;
            case Case::PktKind::IPV4_TCP:
                build_ipv4_tcp_pkt(pkt, tc.ttl, tc.tos, /*sip=*/0x0A000001, /*dip=*/tc.dip);
                break;
            case Case::PktKind::IPV6_TCP:
                build_ipv6_tcp_pkt(pkt, /*hop_limit=*/tc.ttl, /*traffic_class=*/tc.tos, sip6, dip6);
                break;
        }

        // ---- Interfaces-driven sequence ----
        ParserHwInfo parser_hinfo{};
        parser_hinfo.port_id = tc.port_id;
        parser_hinfo.port_type = PORT_TYPE_ETH;
        NhiDef nhi{};
        Cp2NpHeader cp2np{};
        Prs2Ma0FvInfoDef fv_prs{};

        sw.reset_all_fields();
        sw.PrsProcPkt(/*direction=*/0, parser_hinfo, nhi, cp2np, pkt, fv_prs);

        MaToMaFvInfoDef fv_ma0_in = to_ma_fv(fv_prs);
        seed_fv_ttl_tos_from_parsed_l3(fv_ma0_in);

        MaToMaFvInfoDef fv_ma0_out{};
        MaToMaFvInfoDef fv_ma1_out{};
        MaToMaFvInfoDef fv_ma2_out{};

        sw.reset_all_fields();
        sw.SingleMaProc(/*ma_id=*/0, /*packet_id=*/"", /*port_id=*/static_cast<int>(tc.port_id), fv_ma0_in, fv_ma0_out);  // iMA0
        sw.reset_all_fields();
        sw.SingleMaProc(/*ma_id=*/1, /*packet_id=*/"", /*port_id=*/static_cast<int>(tc.port_id), fv_ma0_out, fv_ma1_out); // iMA1
        sw.reset_all_fields();
        sw.SingleMaProc(/*ma_id=*/2, /*packet_id=*/"", /*port_id=*/static_cast<int>(tc.port_id), fv_ma1_out, fv_ma2_out); // eMA0

        bool ok = true;

        ok &= expect_eq_u64(sw.PHI.L3Type.to_ullong(), tc.expect_l3, "PHI.L3Type as expected");
        ok &= expect_eq_u64(sw.PHI.L4Type.to_ullong(), tc.expect_l4, "PHI.L4Type as expected");

        if (tc.expect_hit) {
            ok &= expect_true(se.status(SE_TID_IPAT) == SearchEngine::Status::MATCH, "IPAT status MATCH");
            ok &= expect_true((se.status(SE_TID_FIB) == SearchEngine::Status::MATCH) == tc.expect_fib_hit, "FIB status as expected");
            ok &= expect_true((se.status(SE_TID_EPAT) == SearchEngine::Status::MATCH) == tc.expect_epat_hit, "EPAT status as expected");
            ok &= expect_true((se.status(SE_TID_ENCAP) == SearchEngine::Status::MATCH) == tc.expect_encap_hit, "ENCAP status as expected");

            ok &= expect_eq_u64(sw.DropFlag.to_ullong(), 0, "DropFlag=0 on hit");
            ok &= expect_eq_u64(sw.IsUc.to_ullong(), 1, "IsUc=1 on hit");
            ok &= expect_eq_u64(sw.Vrf.to_ullong(), (tc.port_id == 20 ? 200 : 100), "Vrf from IPAT");

            ok &= expect_eq_u64(sw.GLTP.to_ullong(), tc.expect_gltp, "GLTP from FIB");
            ok &= expect_eq_u64(sw.EncapIndex.to_ullong(), tc.expect_encap, "EncapIndex from FIB");
            ok &= expect_eq_u64(sw.TTL.to_ullong(), tc.expect_ttl_out, "TTL after iMA1Action");

            ok &= expect_eq_u64(sw.EncapProfile.to_ullong(), 1, "EncapProfile=1 when IsUc=1");
            ok &= expect_eq_u64(sw.ETHER.Dmac.to_ullong(), tc.expect_dmac, "ETHER.Dmac after eMA0 HM");
            ok &= expect_eq_u64(sw.ETHER.Smac.to_ullong(), tc.expect_smac, "ETHER.Smac after eMA0 HM");
            if (tc.check_ipv4_overwrite) {
                ok &= expect_eq_u64(sw.IPv4.TTL.to_ullong(), tc.expect_ttl_out, "IPv4.TTL overwritten with FV TTL");
                ok &= expect_eq_u64(sw.IPv4.u_0.TOS.to_ullong(), tc.tos, "IPv4.TOS overwritten from FV TOS");
            }
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
            ok &= expect_eq_u64(sw.IPv4.TTL.to_ullong(), tc.ttl, "IPv4.TTL unchanged on drop");
            ok &= expect_eq_u64(sw.IPv4.u_0.TOS.to_ullong(), tc.tos, "IPv4.TOS unchanged on drop");
        }

        all_ok = all_ok && ok;
        std::cout << tc.name << " => " << (ok ? "PASS" : "FAIL") << "\n";
    }

    std::cout << "[integrated iMA+eMA0 test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}


