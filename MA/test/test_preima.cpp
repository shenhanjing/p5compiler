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

} // namespace

int main() {
    std::cout << "[pre_iMAControl test] start\n";

    Switch sw;

    // prepare packet and parser info
    PktHeader pkt{};
    build_ipv4_udp_pkt(pkt);

    ParserHwInfo parser_hinfo{};
    parser_hinfo.port_id = 10;
    parser_hinfo.port_type = PORT_TYPE_ETH;

    NhiDef nhi{};
    Cp2NpHeader cp2np{};
    Prs2Ma0FvInfoDef fv{};

    sw.PrsProcPkt(/*direction=*/0, parser_hinfo, nhi, cp2np, pkt, fv);

    bool ok = true;
    ok &= (sw.PHI.L2Type.to_ullong() == L2_TYPE_ETHERNET);
    ok &= (sw.PHI.L3Type.to_ullong() == L3_TYPE_IPv4);
    ok &= (sw.PHI.L4Type.to_ullong() == L4_PROTOCOL_UDP);
    ok &= (sw.GLSP.to_ullong() == parser_hinfo.port_id);
    ok &= (sw.PHO[PHO_OUTER_L2_START].to_ullong() == 14);
    ok &= (sw.PHO[PHO_OUTER_L3_START].to_ullong() == 34);
    ok &= (sw.PHO[PHO_OUTER_L4_START].to_ullong() == 42);

    std::cout << "PHI.PortType=" << sw.PHI.PortType.to_ullong()
              << " L2Type=" << sw.PHI.L2Type.to_ullong()
              << " L3Type=" << sw.PHI.L3Type.to_ullong()
              << " L4Type=" << sw.PHI.L4Type.to_ullong() << "\n";
    std::cout << "PHO L2=" << sw.PHO[PHO_OUTER_L2_START].to_ullong()
              << " L3=" << sw.PHO[PHO_OUTER_L3_START].to_ullong()
              << " L4=" << sw.PHO[PHO_OUTER_L4_START].to_ullong() << "\n";

    std::cout << "[pre_iMAControl test] " << (ok ? "PASS" : "FAIL") << "\n";
    return ok ? 0 : 1;
}

