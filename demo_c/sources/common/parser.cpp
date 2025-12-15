/*****************************************************************************************************************
 *                               Parser Implementation (Refactored)                                *
 ******************************************************************************************************************/

#include "parser.hpp"
#include "serializer.hpp"
#include "fv_structs.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>

// 内置函数：_parser_next (暂时为空实现)
static void _parser_next(int group, int stage) {
    // TODO: 后续实现
    (void)group;
    (void)stage;
}

// ========== Extract 函数实现已移至 extract.h ==========

void ParserImpl::lookahead_ether_type_at_offset(size_t offset) {
    size_t saved_offset = state.current_offset_bytes;
    state.current_offset_bytes = offset;
    extract(state, ether_type);
    state.current_offset_bytes = saved_offset;
}

// ========== PrsProcPkt 实现 ==========
void ParserImpl::PrsProcPkt(
    bool direction,
    const ParserHwInfo &parser_hinfo,
    NhiDef &nhi_info,
    Cp2NpHeader &cp2np_hdr,
    const PktHeader &pkt_hdr,
    Prs2Ma0FvInfoDef &fv_info
) {
    // 1. 初始化 phData：直接复制原始数据包
    memcpy(fv_info.phData, pkt_hdr.pkt_data, sizeof(fv_info.phData));
    
    // 2. 初始化 ParserState
    size_t start_offset = 0;  // 从 0 开始，或从 parser_hinfo.parser_start 获取
    state.init(pkt_hdr, start_offset);
    
    // 3. 设置 parser_hinfo 到 PHI
    state.phi_temp.PortType = p5::uint<4>(parser_hinfo.port_type & 0xF);
    
    // 4. 根据 direction 调用入口函数
    try {
        if (direction == 0) {  // ingress
            iprs();
        } else {  // egress
            eprs();
        }
    } catch (const std::exception& e) {
        // 错误处理：解析失败时，保持默认值（已初始化为 0）
        std::cerr << "Parser error: " << e.what() << std::endl;
    }
    
    // 5. 序列化 PHI 到 phiData
    std::cerr << "[DEBUG] Before serialization - PHI: PortType=" << static_cast<int>(state.phi_temp.PortType.to_ullong())
              << ", L2Type=" << static_cast<int>(state.phi_temp.L2Type.to_ullong())
              << ", L3Type=" << static_cast<int>(state.phi_temp.L3Type.to_ullong())
              << ", L4Type=" << static_cast<int>(state.phi_temp.L4Type.to_ullong()) << std::endl;
    serialize_phi(state.phi_temp, fv_info.phiData);
    
    // 6. 序列化 PHO 到 phoData
    std::cerr << "[DEBUG] Before serialization - PHO: ";
    for (int i = 0; i < 5; ++i) {
        std::cerr << "[" << i << "]=" << static_cast<int>(state.pho_temp[i].to_ullong()) << " ";
    }
    std::cerr << std::endl;
    serialize_pho(state.pho_temp, 5, fv_info.phoData);
    
    // 注意：udfData, gtvData, pgtvData 在 Parser 阶段不填充，保持默认值 0
}

// ========== 入口函数实现 ==========
void ParserImpl::iprs() {
    parse_ETHER();
}

void ParserImpl::eprs() {
    parse_ETHER();
}

// ========== parse_ETHER 实现 ==========
void ParserImpl::parse_ETHER() {
    std::cerr << "[DEBUG] parse_ETHER called" << std::endl;
    state.phi_temp.L2Type = L2_TYPE_ETHERNET;
    std::cerr << "[DEBUG] L2Type set to: " << static_cast<int>(state.phi_temp.L2Type.to_ullong()) << std::endl;
    
    // 先 lookahead ETHER_TYPE（在偏移量 current_offset + 12 的位置）
    // 因为 ETHER_TYPE 是 ETHER 头的一部分（最后2字节）
    lookahead_ether_type_at_offset(state.current_offset_bytes + 12);
    uint16_t ether_type_val = ether_type.Type.to_ullong();  // 使用成员变量
    std::cerr << "[DEBUG] ETHER_TYPE: 0x" << std::hex << ether_type_val << std::dec << std::endl;
    
    size_t offset = extract(state, ether);  // 使用统一的 extract 函数
    std::cerr << "[DEBUG] ETHER extracted at offset: " << offset << std::endl;
    state.pho_temp[PHO_OUTER_L2_START] = p5::uint<7>(offset);
    std::cerr << "[DEBUG] PHO[0] set to: " << static_cast<int>(state.pho_temp[PHO_OUTER_L2_START].to_ullong()) << std::endl;

    switch(ether_type_val) {
        case 0x8100: 
            std::cerr << "[DEBUG] Calling parse_VlanTag" << std::endl;
            parse_VlanTag(); 
            break;
        case 0x0800:
            std::cerr << "[DEBUG] Calling parse_IPv4 directly" << std::endl;
            parse_IPv4();
            break;
        default: 
            std::cerr << "[DEBUG] Calling _parser_next (default case), ether_type=0x" << std::hex << ether_type_val << std::dec << std::endl;
            _parser_next(0, 0); 
            break;
    }
}

// ========== parse_VlanTag 实现 ==========
void ParserImpl::parse_VlanTag() {
    std::cerr << "[DEBUG] parse_VlanTag called" << std::endl;
    state.phi_temp.TagType = VLAN_SINGLE_TAGGED;
    state.pho_temp[PHO_OUTER_VLANS_START] = p5::uint<7>(extract(state, vlan_tag0));
    std::cerr << "[DEBUG] VLAN_TAG extracted at offset: " << static_cast<int>(state.pho_temp[PHO_OUTER_VLANS_START].to_ullong()) << std::endl;

    // VLAN 标签结构：TPID(2) + VLAN Info(2)
    // VLAN Info 的最后 2 字节就是 EtherType
    // extract_vlan_tag0 提取了 4 字节，当前偏移在 EtherType 之后
    // 需要回退 2 字节来读取 EtherType（VLAN 标签的最后 2 字节）
    size_t vlan_start = state.pho_temp[PHO_OUTER_VLANS_START].to_ullong();
    lookahead_ether_type_at_offset(vlan_start + 2);  // VLAN 标签的偏移 + 2 字节 = EtherType 位置
    uint16_t ether_type_val = ether_type.Type.to_ullong();  // 使用成员变量
    std::cerr << "[DEBUG] After VLAN, ETHER_TYPE: 0x" << std::hex << ether_type_val << std::dec << std::endl;
    switch(ether_type_val) {
        case 0x0800: 
            std::cerr << "[DEBUG] Calling parse_IPv4 from VLAN" << std::endl;
            parse_IPv4(); 
            break;
        case 0x86dd: 
            std::cerr << "[DEBUG] Calling parse_IPv6 from VLAN" << std::endl;
            parse_IPv6(); 
            break;
        default: 
            std::cerr << "[DEBUG] Calling _parser_next from VLAN (default case), ether_type=0x" << std::hex << ether_type_val << std::dec << std::endl;
            _parser_next(0, 0); 
            break;
    }
}

// ========== parse_IPv4 实现 ==========
void ParserImpl::parse_IPv4() {
    std::cerr << "[DEBUG] parse_IPv4 called" << std::endl;
    state.phi_temp.L3Type = L3_TYPE_IPv4;
    std::cerr << "[DEBUG] L3Type set to: " << static_cast<int>(state.phi_temp.L3Type.to_ullong()) << std::endl;
    
    size_t offset = extract(state, ipv4);  // 使用统一的 extract 函数
    std::cerr << "[DEBUG] IPv4 extracted at offset: " << offset << std::endl;
    state.pho_temp[PHO_OUTER_L3_START] = p5::uint<7>(offset);
    
    uint8_t protocol = ipv4.Protocol.to_ullong();  // 使用成员变量
    std::cerr << "[DEBUG] IPv4 Protocol: " << static_cast<int>(protocol) << std::endl;
    switch(protocol) {
        case IP_PROTOCOL_UDP: 
            std::cerr << "[DEBUG] Calling parse_UDP" << std::endl;
            parse_UDP(); 
            break;
        case IP_PROTOCOL_TCP: 
            std::cerr << "[DEBUG] Calling parse_TCP" << std::endl;
            parse_TCP(); 
            break;
        default: 
            std::cerr << "[DEBUG] Calling _parser_next (default case)" << std::endl;
            _parser_next(0, 0); 
            break;
    }
}

// ========== parse_IPv6 实现 ==========
void ParserImpl::parse_IPv6() {
    state.phi_temp.L3Type = L3_TYPE_IPv6;
    state.pho_temp[PHO_OUTER_L3_START] = p5::uint<7>(extract(state, ipv6));

    switch(ipv6.NextProtocol.to_ullong()) {  // 使用成员变量
        case IP_PROTOCOL_UDP: parse_UDP(); break;
        case IP_PROTOCOL_TCP: parse_TCP(); break;
        default: _parser_next(0, 0); break;
    }
}

// ========== parse_TCP 实现 ==========
void ParserImpl::parse_TCP() {
    std::cerr << "[DEBUG] parse_TCP called" << std::endl;
    state.phi_temp.L4Type = L4_PROTOCOL_TCP;
    std::cerr << "[DEBUG] L4Type set to: " << static_cast<int>(state.phi_temp.L4Type.to_ullong()) << std::endl;
    
    size_t offset = extract(state, tcp);  // 使用统一的 extract 函数
    std::cerr << "[DEBUG] TCP extracted at offset: " << offset << std::endl;
    state.pho_temp[PHO_OUTER_L4_START] = p5::uint<7>(offset);

    _parser_next(0, 0);
}

// ========== parse_UDP 实现 ==========
void ParserImpl::parse_UDP() {
    state.phi_temp.L4Type = L4_PROTOCOL_UDP;
    state.pho_temp[PHO_OUTER_L4_START] = p5::uint<7>(extract(state, udp));

    _parser_next(0, 0);
}

