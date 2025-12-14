/*****************************************************************************************************************
 *                               Parser Functions (Converted from P5)                                *
 ******************************************************************************************************************/

#include "parser_context.hpp"
#include "serializer.hpp"
#include "headers.hpp"
#include "fv_structs.hpp"
#include "../../model_intf_1027.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

// 内置函数：_parser_next (暂时为空实现)
void _parser_next(int group, int stage) {
    // TODO: 后续实现
    (void)group;
    (void)stage;
}

// Parser 入口函数
void iprs(ParserContext& ctx);
void eprs(ParserContext& ctx);

// Parser 函数声明
void parse_ETHER(ParserContext& ctx);
void parse_VlanTag(ParserContext& ctx);
void parse_IPv4(ParserContext& ctx);
void parse_IPv6(ParserContext& ctx);
void parse_TCP(ParserContext& ctx);
void parse_UDP(ParserContext& ctx);

// Parser 入口函数实现
void iprs(ParserContext& ctx) {
    parse_ETHER(ctx);
}

void eprs(ParserContext& ctx) {
    parse_ETHER(ctx);
}

// parse_ETHER 函数
void parse_ETHER(ParserContext& ctx) {
    std::cerr << "[DEBUG] parse_ETHER called" << std::endl;
    ctx.get_phi().L2Type = L2_TYPE_ETHERNET;
    std::cerr << "[DEBUG] L2Type set to: " << static_cast<int>(ctx.get_phi().L2Type.to_ullong()) << std::endl;
    
    // 先 lookahead ETHER_TYPE（在偏移量 current_offset + 12 的位置）
    // 因为 ETHER_TYPE 是 ETHER 头的一部分（最后2字节）
    ctx.lookahead_at_offset(ETHER_TYPE, ctx.get_current_offset() + 12);
    uint16_t ether_type = ETHER_TYPE.Type.to_ullong();
    std::cerr << "[DEBUG] ETHER_TYPE: 0x" << std::hex << ether_type << std::dec << std::endl;
    
    size_t offset = ctx.extract(ETHER);
    std::cerr << "[DEBUG] ETHER extracted at offset: " << offset << std::endl;
    ctx.get_pho()[PHO_OUTER_L2_START] = p5::uint<7>(offset);
    std::cerr << "[DEBUG] PHO[0] set to: " << static_cast<int>(ctx.get_pho()[PHO_OUTER_L2_START].to_ullong()) << std::endl;

    switch(ether_type) {
        case 0x8100: 
            std::cerr << "[DEBUG] Calling parse_VlanTag" << std::endl;
            parse_VlanTag(ctx); 
            break;
        case 0x0800:
            std::cerr << "[DEBUG] Calling parse_IPv4 directly" << std::endl;
            parse_IPv4(ctx);
            break;
        default: 
            std::cerr << "[DEBUG] Calling _parser_next (default case), ether_type=0x" << std::hex << ether_type << std::dec << std::endl;
            _parser_next(0, 0); 
            break;
    }
}

// parse_VlanTag 函数
void parse_VlanTag(ParserContext& ctx) {
    ctx.get_phi().TagType = VLAN_SINGLE_TAGGED;
    ctx.get_pho()[PHO_OUTER_VLANS_START] = p5::uint<7>(ctx.extract(VLAN_TAG0));

    ctx.lookahead(ETHER_TYPE);
    switch(ETHER_TYPE.Type.to_ullong()) {
        case 0x0800: parse_IPv4(ctx); break;
        case 0x86dd: parse_IPv6(ctx); break;
        default: _parser_next(0, 0); break;
    }
}

// parse_IPv4 函数
void parse_IPv4(ParserContext& ctx) {
    std::cerr << "[DEBUG] parse_IPv4 called" << std::endl;
    ctx.get_phi().L3Type = L3_TYPE_IPv4;
    std::cerr << "[DEBUG] L3Type set to: " << static_cast<int>(ctx.get_phi().L3Type.to_ullong()) << std::endl;
    
    size_t offset = ctx.extract(IPv4);
    std::cerr << "[DEBUG] IPv4 extracted at offset: " << offset << std::endl;
    ctx.get_pho()[PHO_OUTER_L3_START] = p5::uint<7>(offset);
    
    uint8_t protocol = IPv4.Protocol.to_ullong();
    std::cerr << "[DEBUG] IPv4 Protocol: " << static_cast<int>(protocol) << std::endl;
    switch(protocol) {
        case IP_PROTOCOL_UDP: 
            std::cerr << "[DEBUG] Calling parse_UDP" << std::endl;
            parse_UDP(ctx); 
            break;
        case IP_PROTOCOL_TCP: 
            std::cerr << "[DEBUG] Calling parse_TCP" << std::endl;
            parse_TCP(ctx); 
            break;
        default: 
            std::cerr << "[DEBUG] Calling _parser_next (default case)" << std::endl;
            _parser_next(0, 0); 
            break;
    }
}

// parse_IPv6 函数
void parse_IPv6(ParserContext& ctx) {
    ctx.get_phi().L3Type = L3_TYPE_IPv6;
    ctx.get_pho()[PHO_OUTER_L3_START] = p5::uint<7>(ctx.extract(IPv6));

    switch(IPv6.NextProtocol.to_ullong()) {
        case IP_PROTOCOL_UDP: parse_UDP(ctx); break;
        case IP_PROTOCOL_TCP: parse_TCP(ctx); break;
        default: _parser_next(0, 0); break;
    }
}

// parse_TCP 函数
void parse_TCP(ParserContext& ctx) {
    std::cerr << "[DEBUG] parse_TCP called" << std::endl;
    ctx.get_phi().L4Type = L4_PROTOCOL_TCP;
    std::cerr << "[DEBUG] L4Type set to: " << static_cast<int>(ctx.get_phi().L4Type.to_ullong()) << std::endl;
    
    size_t offset = ctx.extract(TCP);
    std::cerr << "[DEBUG] TCP extracted at offset: " << offset << std::endl;
    ctx.get_pho()[PHO_OUTER_L4_START] = p5::uint<7>(offset);

    _parser_next(0, 0);
}

// parse_UDP 函数
void parse_UDP(ParserContext& ctx) {
    ctx.get_phi().L4Type = L4_PROTOCOL_UDP;
    ctx.get_pho()[PHO_OUTER_L4_START] = p5::uint<7>(ctx.extract(UDP));

    _parser_next(0, 0);
}

// PrsProcPkt 顶层函数实现
void PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, 
                NhiDef &nhi_info, Cp2NpHeader &cp2np_hdr, 
                const PktHeader &pkt_hdr, Prs2Ma0FvInfoDef &fv_info) {
    // 1. 初始化 phData：直接复制原始数据包
    memcpy(fv_info.phData, pkt_hdr.pkt_data, sizeof(fv_info.phData));
    
    // 2. 初始化 ParserContext
    ParserContext ctx;
    size_t start_offset = 0;  // 从 0 开始，或从 parser_hinfo.parser_start 获取
    ctx.init(pkt_hdr, start_offset);
    
    // 3. 设置 parser_hinfo 到 PHI
    ctx.get_phi().PortType = p5::uint<4>(parser_hinfo.port_type & 0xF);
    
    // 4. 根据 direction 调用入口函数
    try {
        if (direction == 0) {  // ingress
            iprs(ctx);
        } else {  // egress
            eprs(ctx);
        }
    } catch (const std::exception& e) {
        // 错误处理：解析失败时，保持默认值（已初始化为 0）
        // 可以在这里设置错误码或记录日志
        // 暂时不做特殊处理，保持 fv_info 的默认值
        std::cerr << "Parser error: " << e.what() << std::endl;
    }
    
    // 5. 序列化 PHI 到 phiData
    std::cerr << "[DEBUG] Before serialization - PHI: PortType=" << static_cast<int>(ctx.get_phi().PortType.to_ullong())
              << ", L2Type=" << static_cast<int>(ctx.get_phi().L2Type.to_ullong())
              << ", L3Type=" << static_cast<int>(ctx.get_phi().L3Type.to_ullong())
              << ", L4Type=" << static_cast<int>(ctx.get_phi().L4Type.to_ullong()) << std::endl;
    serialize_phi(ctx.get_phi(), fv_info.phiData);
    
    // 6. 序列化 PHO 到 phoData
    std::cerr << "[DEBUG] Before serialization - PHO: ";
    for (int i = 0; i < 5; ++i) {
        std::cerr << "[" << i << "]=" << static_cast<int>(ctx.get_pho()[i].to_ullong()) << " ";
    }
    std::cerr << std::endl;
    serialize_pho(ctx.get_pho(), 5, fv_info.phoData);
    
    // 注意：udfData, gtvData, pgtvData 在 Parser 阶段不填充，保持默认值 0
}

