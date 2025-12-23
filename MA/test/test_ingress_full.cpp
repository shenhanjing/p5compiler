#include <cstring>
#include <iostream>
#include <vector>

#include "generated_Switch.hpp"

namespace {

void build_ipv4_udp_pkt(PktHeader &pkt) {
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> buf{};
    // Ethernet
    uint8_t eth[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, // DMAC
        0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, // SMAC
        0x08, 0x00                          // EtherType IPv4
    };
    std::memcpy(buf.data(), eth, sizeof(eth));

    // IPv4 (20 bytes)
    std::array<uint8_t, 20> ipv4{};
    ipv4[0] = 0x45;              // Version=4, IHL=5
    ipv4[1] = 0x00;              // TOS
    ipv4[2] = 0x00; ipv4[3] = 0x1c; // Total length = 28
    ipv4[4] = 0x00; ipv4[5] = 0x01; // Identification
    ipv4[6] = 0x00; ipv4[7] = 0x00; // Flags/Fragment offset
    ipv4[8] = 0x40;              // TTL
    ipv4[9] = 0x11;              // Protocol = UDP
    ipv4[10] = 0x00; ipv4[11] = 0x00; // Checksum (ignored here)
    ipv4[12] = 0x0a; ipv4[13] = 0x00; ipv4[14] = 0x00; ipv4[15] = 0x01; // SIP 10.0.0.1
    ipv4[16] = 0x0a; ipv4[17] = 0x00; ipv4[18] = 0x00; ipv4[19] = 0x02; // DIP 10.0.0.2
    std::memcpy(buf.data() + 14, ipv4.data(), ipv4.size());

    // UDP (8 bytes)
    std::array<uint8_t, 8> udp{};
    udp[0] = 0x03; udp[1] = 0xe8; // SrcPort 1000
    udp[2] = 0x07; udp[3] = 0xd0; // DstPort 2000
    udp[4] = 0x00; udp[5] = 0x08; // Length 8
    udp[6] = 0x00; udp[7] = 0x00; // Checksum
    std::memcpy(buf.data() + 14 + 20, udp.data(), udp.size());

    std::memcpy(pkt.pkt_data, buf.data(), PKT_HEADER_BYTE_LEN);
}

void build_ipv4_tcp_pkt(PktHeader &pkt) {
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> buf{};
    uint8_t eth[] = {
        0x00, 0xaa, 0xbb, 0xcc, 0xdd, 0xee,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66,
        0x08, 0x00 // IPv4
    };
    std::memcpy(buf.data(), eth, sizeof(eth));

    std::array<uint8_t, 20> ipv4{};
    ipv4[0] = 0x45;
    ipv4[1] = 0x00;
    ipv4[2] = 0x00; ipv4[3] = 0x28; // len 40
    ipv4[4] = 0x12; ipv4[5] = 0x34;
    ipv4[6] = 0x00; ipv4[7] = 0x00;
    ipv4[8] = 0x40;
    ipv4[9] = 0x06; // TCP
    ipv4[10] = 0x00; ipv4[11] = 0x00;
    ipv4[12] = 0x0a; ipv4[13] = 0x00; ipv4[14] = 0x00; ipv4[15] = 0x09; // 10.0.0.9
    ipv4[16] = 0x0a; ipv4[17] = 0x00; ipv4[18] = 0x01; ipv4[19] = 0x02; // 10.0.1.2
    std::memcpy(buf.data() + 14, ipv4.data(), ipv4.size());

    std::array<uint8_t, 20> tcp{};
    tcp[0] = 0x13; tcp[1] = 0x88; // sport 5000
    tcp[2] = 0x1f; tcp[3] = 0x90; // dport 8080
    tcp[12] = 0x50; // data offset=5, flags all zero
    std::memcpy(buf.data() + 14 + 20, tcp.data(), tcp.size());

    std::memcpy(pkt.pkt_data, buf.data(), PKT_HEADER_BYTE_LEN);
}

void build_ipv6_udp_pkt(PktHeader &pkt) {
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> buf{};
    uint8_t eth[] = {
        0xde, 0xad, 0xbe, 0xef, 0x00, 0x01,
        0xde, 0xad, 0xbe, 0xef, 0x00, 0x02,
        0x86, 0xdd // IPv6
    };
    std::memcpy(buf.data(), eth, sizeof(eth));

    std::array<uint8_t, 40> ipv6{};
    ipv6[0] = 0x60; // version=6
    ipv6[4] = 0x00; ipv6[5] = 0x08; // payload len 8 (just UDP header)
    ipv6[6] = 0x11; // next header UDP
    ipv6[7] = 0x40; // hop limit
    // SIP: 2001:db8::1
    ipv6[8] = 0x20; ipv6[9] = 0x01; ipv6[10] = 0x0d; ipv6[11] = 0xb8;
    ipv6[23] = 0x01;
    // DIP: 2001:db8::2
    ipv6[24] = 0x20; ipv6[25] = 0x01; ipv6[26] = 0x0d; ipv6[27] = 0xb8;
    ipv6[39] = 0x02;
    std::memcpy(buf.data() + 14, ipv6.data(), ipv6.size());

    std::array<uint8_t, 8> udp{};
    udp[0] = 0x12; udp[1] = 0x34;
    udp[2] = 0x56; udp[3] = 0x78;
    udp[4] = 0x00; udp[5] = 0x08;
    udp[6] = 0x00; udp[7] = 0x00;
    std::memcpy(buf.data() + 14 + 40, udp.data(), udp.size());

    std::memcpy(pkt.pkt_data, buf.data(), PKT_HEADER_BYTE_LEN);
}

} // namespace

int main() {
    std::cout << "[ingress full test] start\n";

    Switch sw;
    // init tables for iMA stages
    auto &se = sw.searchEngine();
    auto &key = sw.keyManager();
    se.initTable<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, MatchType::INDEX);
    se.initTable<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, MatchType::LPM);
    key.initKey({10, 136});
    se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, 10, IPATRSP_S{1, 0, 0, 100, {}});
    // FIB: vrf=100, dip=10.0.0.2 -> port=25, encap=3 (/32)
    key.buildKey(p5::uint<8>(100), p5::uint<32>(0x0A000002), p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
    auto fib_key_host = key.getKey<p5::uint<136>>(136);
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, fib_key_host, FIBRSP_S{25, 3}, 8 + 32);

    // Build packet + parser info
    struct TestCase {
        std::string name;
        void (*build_pkt)(PktHeader &);
        uint8_t expect_l3;
        uint8_t expect_l4;
        uint16_t expect_gltp;
        uint8_t expect_encap;
    };

    std::vector<TestCase> cases = {
        {"ipv4-udp-hit", build_ipv4_udp_pkt, L3_TYPE_IPv4, L4_PROTOCOL_UDP, 25, 3},
        {"ipv4-tcp-miss", build_ipv4_tcp_pkt, L3_TYPE_IPv4, L4_PROTOCOL_TCP, 0, 0},
        {"ipv6-udp-miss", build_ipv6_udp_pkt, L3_TYPE_IPv6, L4_PROTOCOL_UDP, 0, 0},
    };

    bool all_ok = true;
    for (const auto &tc : cases) {
        PktHeader pkt{};
        tc.build_pkt(pkt);

        ParserHwInfo parser_hinfo{};
        parser_hinfo.port_id = 10;
        parser_hinfo.port_type = PORT_TYPE_ETH;

        NhiDef nhi{};
        Cp2NpHeader cp2np{};
        Prs2Ma0FvInfoDef fv_prs{};
        Ima2IpmFvInfoDef fv_ima{};

        sw.reset_all_fields();
        sw.PrsProcPkt(/*direction=*/0, parser_hinfo, nhi, cp2np, pkt, fv_prs);
        sw.reset_all_fields();
        sw.ImaProcPkt(/*port_id=*/10, fv_prs, fv_ima);

        bool ok = true;
        ok &= (sw.PHI.L2Type.to_ullong() == L2_TYPE_ETHERNET);
        ok &= (sw.PHI.L3Type.to_ullong() == tc.expect_l3);
        ok &= (sw.PHI.L4Type.to_ullong() == tc.expect_l4);
        ok &= (sw.GLTP.to_ullong() == tc.expect_gltp);
        ok &= (sw.EncapIndex.to_ullong() == tc.expect_encap);

        all_ok = all_ok && ok;

        std::cout << tc.name << " => "
                  << "L2=" << sw.PHI.L2Type.to_ullong()
                  << " L3=" << sw.PHI.L3Type.to_ullong()
                  << " L4=" << sw.PHI.L4Type.to_ullong()
                  << " GLTP=" << sw.GLTP.to_ullong()
                  << " Encap=" << sw.EncapIndex.to_ullong()
                  << " => " << (ok ? "PASS" : "FAIL") << "\n";
    }

    std::cout << "[ingress full test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}

