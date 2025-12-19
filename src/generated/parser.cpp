/*****************************************************************************************************************
 *                               Parser Implementation (Refactored)                                *
 ******************************************************************************************************************/

#include "parser.hpp"
#include "serializer.hpp"
#include "fv_structs.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>

// ========== PrsProcPkt 实现 ==========
void ParserImpl::PrsProcPkt(
    bool direction,
    const ParserHwInfo &parser_hinfo,
    [[maybe_unused]] NhiDef &nhi_info,
    [[maybe_unused]] Cp2NpHeader &cp2np_hdr,
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
    
    // 3.1 设置 parser_hinfo.port_id 到 FV.GLSP（新增）
    state.fv.GLSP = p5::uint<10>(parser_hinfo.port_id);
    
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
    serialize_phi(state.phi_temp, fv_info.phiData);
    
    // 6. 序列化 PHO 到 phoData
    serialize_pho(state.pho_temp, 5, fv_info.phoData);
    
    // 7. 序列化 FV 到 gtvData（新增）
    serialize_fv(state.fv, fv_info.gtvData);
    
    // 注意：udfData, pgtvData 在 Parser 阶段不填充，保持默认值 0
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
    state.phi_temp.L2Type = L2_TYPE_ETHERNET;
    
    // 先 lookahead ETHER_TYPE（在偏移量 current_offset + 12 的位置）
    // 因为 ETHER_TYPE 是 ETHER 头的一部分（最后2字节）
    _lookahead(ether_type, state.current_offset_bytes + 12);
    uint16_t ether_type_val = ether_type.Type;  // 使用隐式类型转换
    
    size_t offset = _extract(state, ether);
    state.pho_temp[PHO_OUTER_L2_START] = p5::uint<7>(offset);

    switch(ether_type_val) {
        case 0x8100: 
            parse_VlanTag(); 
            break;
        case 0x0800:
            parse_IPv4();
            break;
        default: 
            _parser_next(0, 0); 
            break;
    }
}

// ========== parse_VlanTag 实现 ==========
void ParserImpl::parse_VlanTag() {
    state.phi_temp.TagType = VLAN_SINGLE_TAGGED;
    state.pho_temp[PHO_OUTER_VLANS_START] = p5::uint<7>(_extract(state, vlan_tag0));

    // VLAN 标签结构：TPID(2) + VLAN Info(2)
    // VLAN Info 的最后 2 字节就是 EtherType
    // extract 提取了 4 字节，当前偏移在 EtherType 之后
    // 需要回退 2 字节来读取 EtherType（VLAN 标签的最后 2 字节）
    size_t vlan_start = state.pho_temp[PHO_OUTER_VLANS_START];  // 使用隐式类型转换
    _lookahead(ether_type, vlan_start + 2);  // VLAN 标签的偏移 + 2 字节 = EtherType 位置
    uint16_t ether_type_val = ether_type.Type;  // 使用隐式类型转换
    switch(ether_type_val) {
        case 0x0800: 
            parse_IPv4(); 
            break;
        case 0x86dd: 
            parse_IPv6(); 
            break;
        default: 
            _parser_next(0, 0); 
            break;
    }
}

// ========== parse_IPv4 实现 ==========
void ParserImpl::parse_IPv4() {
    state.phi_temp.L3Type = L3_TYPE_IPv4;
    
    size_t offset = _extract(state, ipv4);
    state.pho_temp[PHO_OUTER_L3_START] = p5::uint<7>(offset);
    
    uint8_t protocol = ipv4.Protocol;  // 使用隐式类型转换
    switch(protocol) {
        case IP_PROTOCOL_UDP: 
            parse_UDP(); 
            break;
        case IP_PROTOCOL_TCP: 
            parse_TCP(); 
            break;
        default: 
            _parser_next(0, 0); 
            break;
    }
}

// ========== parse_IPv6 实现 ==========
void ParserImpl::parse_IPv6() {
    state.phi_temp.L3Type = L3_TYPE_IPv6;
    state.pho_temp[PHO_OUTER_L3_START] = p5::uint<7>(_extract(state, ipv6));

    uint8_t next_protocol = ipv6.NextProtocol;  // 使用隐式类型转换
    switch(next_protocol) {
        case IP_PROTOCOL_UDP: parse_UDP(); break;
        case IP_PROTOCOL_TCP: parse_TCP(); break;
        default: _parser_next(0, 0); break;
    }
}

// ========== parse_TCP 实现 ==========
void ParserImpl::parse_TCP() {
    state.phi_temp.L4Type = L4_PROTOCOL_TCP;
    
    size_t offset = _extract(state, tcp);
    state.pho_temp[PHO_OUTER_L4_START] = p5::uint<7>(offset);

    _parser_next(0, 0);
}

// ========== parse_UDP 实现 ==========
void ParserImpl::parse_UDP() {
    state.phi_temp.L4Type = L4_PROTOCOL_UDP;
    state.pho_temp[PHO_OUTER_L4_START] = p5::uint<7>(_extract(state, udp));

    _parser_next(0, 0);
}

