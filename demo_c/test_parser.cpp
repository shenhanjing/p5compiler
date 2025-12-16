#include <iostream>
#include <iomanip>
#include <cstring>
#include "model_intf_1027.h"
// 注意：不要包含 .cpp 文件，应该链接编译好的目标文件
// PrsProcPkt 函数在 parser_interface.cpp 中定义

// 辅助函数：打印十六进制数据
void print_hex(const char* label, const uint8_t* data, size_t len) {
    std::cout << label << " (" << len << " bytes): ";
    for (size_t i = 0; i < len && i < 64; ++i) {  // 最多打印64字节
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::dec << std::endl;
}

// 辅助函数：打印 PHI 信息
void print_phi_info(const Prs2Ma0FvInfoDef& fv_info) {
    std::cout << "\n=== PHI Information ===" << std::endl;
    
    // 解析 phiData（前18位有效，按位解析）
    // phiData 是按位紧密拼接的，需要按位读取
    uint64_t phi_value = 0;
    
    // 读取前18位（从高位到低位）
    for (int bit = 0; bit < 18; ++bit) {
        size_t byte_idx = bit / 8;
        size_t bit_idx = bit % 8;
        if (byte_idx < FV_PHI_BYTE_NUM) {
            // 大端序：bit 0 是 MSB
            if (fv_info.phiData[byte_idx] & (1 << (7 - bit_idx))) {
                phi_value |= (1ULL << (17 - bit));
            }
        }
    }
    
    uint8_t port_type = (phi_value >> 14) & 0x0F;  // bits 17-14
    uint8_t l2_type = (phi_value >> 12) & 0x03;     // bits 13-12
    uint8_t tag_type = (phi_value >> 10) & 0x03;    // bits 11-10
    uint8_t l3_type = (phi_value >> 8) & 0x03;      // bits 9-8
    uint8_t l4_type = phi_value & 0xFF;              // bits 7-0
    
    std::cout << "PortType: " << static_cast<int>(port_type) << std::endl;
    std::cout << "L2Type: " << static_cast<int>(l2_type) 
              << " (1=ETHERNET)" << std::endl;
    std::cout << "TagType: " << static_cast<int>(tag_type) 
              << " (1=SINGLE_TAGGED)" << std::endl;
    std::cout << "L3Type: " << static_cast<int>(l3_type) 
              << " (2=IPv4, 3=IPv6)" << std::endl;
    std::cout << "L4Type: " << static_cast<int>(l4_type) 
              << " (10=TCP, 32=UDP)" << std::endl;
}

// 辅助函数：打印 PHO 信息
void print_pho_info(const Prs2Ma0FvInfoDef& fv_info) {
    std::cout << "\n=== PHO Information ===" << std::endl;
    
    // PHO 每个字段是7位，紧密拼接（按位读取）
    size_t bit_offset = 0;
    for (int i = 0; i < 5; ++i) {
        uint8_t value = 0;
        
        // 读取7位（从高位到低位）
        for (int bit = 0; bit < 7; ++bit) {
            size_t total_bit = bit_offset + bit;
            size_t byte_idx = total_bit / 8;
            size_t bit_idx = total_bit % 8;
            
            if (byte_idx < FV_PHO_BYTE_NUM) {
                // 大端序：bit 0 是 MSB
                if (fv_info.phoData[byte_idx] & (1 << (7 - bit_idx))) {
                    value |= (1 << (6 - bit));  // 7位字段，最高位是 bit 6
                }
            }
        }
        
        std::cout << "PHO[" << i << "] = " << static_cast<int>(value) << " bytes" << std::endl;
        bit_offset += 7;
    }
}

// 构造以太网 + IPv4 + TCP 数据包
void create_ethernet_ipv4_tcp_packet(PktHeader& pkt_hdr) {
    memset(&pkt_hdr, 0, sizeof(pkt_hdr));
    
    // 以太网头 (14 bytes)
    // Dst MAC: 00:11:22:33:44:55
    pkt_hdr.pkt_data[0] = 0x00; pkt_hdr.pkt_data[1] = 0x11;
    pkt_hdr.pkt_data[2] = 0x22; pkt_hdr.pkt_data[3] = 0x33;
    pkt_hdr.pkt_data[4] = 0x44; pkt_hdr.pkt_data[5] = 0x55;
    // Src MAC: 66:77:88:99:AA:BB
    pkt_hdr.pkt_data[6] = 0x66; pkt_hdr.pkt_data[7] = 0x77;
    pkt_hdr.pkt_data[8] = 0x88; pkt_hdr.pkt_data[9] = 0x99;
    pkt_hdr.pkt_data[10] = 0xAA; pkt_hdr.pkt_data[11] = 0xBB;
    // EtherType: 0x0800 (IPv4)
    pkt_hdr.pkt_data[12] = 0x08;
    pkt_hdr.pkt_data[13] = 0x00;
    
    // IPv4 头 (20 bytes)
    // Version(4) + IHL(4) = 0x45
    pkt_hdr.pkt_data[14] = 0x45;
    // TOS = 0
    pkt_hdr.pkt_data[15] = 0x00;
    // Total Length = 40 (20 IPv4 + 20 TCP)
    pkt_hdr.pkt_data[16] = 0x00;
    pkt_hdr.pkt_data[17] = 0x28;
    // Identification = 0x1234
    pkt_hdr.pkt_data[18] = 0x12;
    pkt_hdr.pkt_data[19] = 0x34;
    // Flags + Fragment Offset = 0x4000
    pkt_hdr.pkt_data[20] = 0x40;
    pkt_hdr.pkt_data[21] = 0x00;
    // TTL = 64
    pkt_hdr.pkt_data[22] = 0x40;
    // Protocol = 6 (TCP)
    pkt_hdr.pkt_data[23] = 0x06;
    // Checksum = 0 (简化测试)
    pkt_hdr.pkt_data[24] = 0x00;
    pkt_hdr.pkt_data[25] = 0x00;
    // Source IP = 192.168.1.1
    pkt_hdr.pkt_data[26] = 0xC0;
    pkt_hdr.pkt_data[27] = 0xA8;
    pkt_hdr.pkt_data[28] = 0x01;
    pkt_hdr.pkt_data[29] = 0x01;
    // Dest IP = 192.168.1.2
    pkt_hdr.pkt_data[30] = 0xC0;
    pkt_hdr.pkt_data[31] = 0xA8;
    pkt_hdr.pkt_data[32] = 0x01;
    pkt_hdr.pkt_data[33] = 0x02;
    
    // TCP 头 (20 bytes)
    // Source Port = 12345
    pkt_hdr.pkt_data[34] = 0x30;
    pkt_hdr.pkt_data[35] = 0x39;
    // Dest Port = 80
    pkt_hdr.pkt_data[36] = 0x00;
    pkt_hdr.pkt_data[37] = 0x50;
    // Seq No = 0x12345678
    pkt_hdr.pkt_data[38] = 0x12;
    pkt_hdr.pkt_data[39] = 0x34;
    pkt_hdr.pkt_data[40] = 0x56;
    pkt_hdr.pkt_data[41] = 0x78;
    // Ack No = 0
    pkt_hdr.pkt_data[42] = 0x00;
    pkt_hdr.pkt_data[43] = 0x00;
    pkt_hdr.pkt_data[44] = 0x00;
    pkt_hdr.pkt_data[45] = 0x00;
    // Data Offset(4) + Reserved(3) + Flags(9) = 0x5010 (SYN flag)
    pkt_hdr.pkt_data[46] = 0x50;
    pkt_hdr.pkt_data[47] = 0x10;
    // Window = 8192
    pkt_hdr.pkt_data[48] = 0x20;
    pkt_hdr.pkt_data[49] = 0x00;
    // Checksum = 0
    pkt_hdr.pkt_data[50] = 0x00;
    pkt_hdr.pkt_data[51] = 0x00;
    // Urgent Pointer = 0
    pkt_hdr.pkt_data[52] = 0x00;
    pkt_hdr.pkt_data[53] = 0x00;
}

// 构造以太网 + VLAN + IPv4 + UDP 数据包
void create_ethernet_vlan_ipv4_udp_packet(PktHeader& pkt_hdr) {
    memset(&pkt_hdr, 0, sizeof(pkt_hdr));
    
    // 以太网头 (14 bytes)
    pkt_hdr.pkt_data[0] = 0x00; pkt_hdr.pkt_data[1] = 0x11;
    pkt_hdr.pkt_data[2] = 0x22; pkt_hdr.pkt_data[3] = 0x33;
    pkt_hdr.pkt_data[4] = 0x44; pkt_hdr.pkt_data[5] = 0x55;
    pkt_hdr.pkt_data[6] = 0x66; pkt_hdr.pkt_data[7] = 0x77;
    pkt_hdr.pkt_data[8] = 0x88; pkt_hdr.pkt_data[9] = 0x99;
    pkt_hdr.pkt_data[10] = 0xAA; pkt_hdr.pkt_data[11] = 0xBB;
    // EtherType: 0x8100 (VLAN)
    pkt_hdr.pkt_data[12] = 0x81;
    pkt_hdr.pkt_data[13] = 0x00;
    
    // VLAN 标签 (4 bytes)
    // TPID = 0x8100 (already in EtherType)
    // Priority(3) + CFI(1) + VLAN ID(12) = 0x1001 (VLAN ID = 1)
    pkt_hdr.pkt_data[14] = 0x10;
    pkt_hdr.pkt_data[15] = 0x01;
    // EtherType: 0x0800 (IPv4)
    pkt_hdr.pkt_data[16] = 0x08;
    pkt_hdr.pkt_data[17] = 0x00;
    
    // IPv4 头 (20 bytes)
    pkt_hdr.pkt_data[18] = 0x45;  // Version + IHL
    pkt_hdr.pkt_data[19] = 0x00;  // TOS
    pkt_hdr.pkt_data[20] = 0x00;  // Total Length
    pkt_hdr.pkt_data[21] = 0x1C;  // 28 bytes (20 IPv4 + 8 UDP)
    pkt_hdr.pkt_data[22] = 0x12;  // Identification
    pkt_hdr.pkt_data[23] = 0x34;
    pkt_hdr.pkt_data[24] = 0x40;  // Flags
    pkt_hdr.pkt_data[25] = 0x00;
    pkt_hdr.pkt_data[26] = 0x40;  // TTL
    pkt_hdr.pkt_data[27] = 0x11;  // Protocol = 17 (UDP)
    pkt_hdr.pkt_data[28] = 0x00;  // Checksum
    pkt_hdr.pkt_data[29] = 0x00;
    pkt_hdr.pkt_data[30] = 0xC0;  // Source IP
    pkt_hdr.pkt_data[31] = 0xA8;
    pkt_hdr.pkt_data[32] = 0x01;
    pkt_hdr.pkt_data[33] = 0x01;
    pkt_hdr.pkt_data[34] = 0xC0;  // Dest IP
    pkt_hdr.pkt_data[35] = 0xA8;
    pkt_hdr.pkt_data[36] = 0x01;
    pkt_hdr.pkt_data[37] = 0x02;
    
    // UDP 头 (8 bytes)
    pkt_hdr.pkt_data[38] = 0x13;  // Source Port = 5000
    pkt_hdr.pkt_data[39] = 0x88;
    pkt_hdr.pkt_data[40] = 0x00;  // Dest Port = 53
    pkt_hdr.pkt_data[41] = 0x35;
    pkt_hdr.pkt_data[42] = 0x00;  // Length
    pkt_hdr.pkt_data[43] = 0x08;
    pkt_hdr.pkt_data[44] = 0x00;  // Checksum
    pkt_hdr.pkt_data[45] = 0x00;
}

int main() {
    std::cout << "=== P5 Parser Test Program ===" << std::endl;
    
    // 初始化参数
    ParserHwInfo parser_hinfo;
    parser_hinfo.port_id = 1;
    parser_hinfo.port_type = 0;  // PORT_TYPE_ETH
    parser_hinfo.parser_start = 0;
    parser_hinfo.init_ti_value = 0;
    parser_hinfo.init_ti_mask = 0;
    parser_hinfo.pre_ipat_info = 0;
    
    NhiDef nhi_info;
    Cp2NpHeader cp2np_hdr;
    Prs2Ma0FvInfoDef fv_info;
    
    // 测试 1: 以太网 + IPv4 + TCP
    std::cout << "\n========== Test 1: Ethernet + IPv4 + TCP ==========" << std::endl;
    {
        PktHeader pkt_hdr;
        create_ethernet_ipv4_tcp_packet(pkt_hdr);
        
        memset(&fv_info, 0, sizeof(fv_info));
        
        std::cout << "\nInput Packet:" << std::endl;
        print_hex("  Raw Data", pkt_hdr.pkt_data, 54);
        
        // 调用 PrsProcPkt (ingress)
        PrsProcPkt(false, parser_hinfo, nhi_info, cp2np_hdr, pkt_hdr, fv_info);
        
        std::cout << "\nOutput FV Info:" << std::endl;
        print_hex("  phData", fv_info.phData, FV_PH_BYTE_NUM);
        print_hex("  phiData", fv_info.phiData, FV_PHI_BYTE_NUM);
        print_hex("  phoData", fv_info.phoData, FV_PHO_BYTE_NUM);
        
        print_phi_info(fv_info);
        print_pho_info(fv_info);
        
        // 验证结果
        std::cout << "\nVerification:" << std::endl;
        // 检查 phData 是否与输入一致（只比较实际数据包大小，避免越界）
        bool ph_match = (memcmp(fv_info.phData, pkt_hdr.pkt_data, PKT_HEADER_BYTE_LEN) == 0);
        std::cout << "  phData matches input: " << (ph_match ? "YES" : "NO") << std::endl;
    }
    
    // 测试 2: 以太网 + VLAN + IPv4 + UDP
    std::cout << "\n========== Test 2: Ethernet + VLAN + IPv4 + UDP ==========" << std::endl;
    {
        PktHeader pkt_hdr;
        create_ethernet_vlan_ipv4_udp_packet(pkt_hdr);
        
        memset(&fv_info, 0, sizeof(fv_info));
        
        std::cout << "\nInput Packet:" << std::endl;
        print_hex("  Raw Data", pkt_hdr.pkt_data, 46);
        
        // 调用 PrsProcPkt (ingress)
        PrsProcPkt(false, parser_hinfo, nhi_info, cp2np_hdr, pkt_hdr, fv_info);
        
        std::cout << "\nOutput FV Info:" << std::endl;
        print_hex("  phData", fv_info.phData, FV_PH_BYTE_NUM);
        print_hex("  phiData", fv_info.phiData, FV_PHI_BYTE_NUM);
        print_hex("  phoData", fv_info.phoData, FV_PHO_BYTE_NUM);
        
        print_phi_info(fv_info);
        print_pho_info(fv_info);
    }
    
    // 测试 3: Egress 方向
    std::cout << "\n========== Test 3: Egress Direction ==========" << std::endl;
    {
        PktHeader pkt_hdr;
        create_ethernet_ipv4_tcp_packet(pkt_hdr);
        
        memset(&fv_info, 0, sizeof(fv_info));
        
        // 调用 PrsProcPkt (egress)
        PrsProcPkt(true, parser_hinfo, nhi_info, cp2np_hdr, pkt_hdr, fv_info);
        
        print_phi_info(fv_info);
        print_pho_info(fv_info);
    }
    
    std::cout << "\n=== Test Complete ===" << std::endl;
    return 0;
}

