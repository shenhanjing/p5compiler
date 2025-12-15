#ifndef EXTRACT_H
#define EXTRACT_H

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include "headers.hpp"

// 注意：此文件中的内联函数需要 ParserState 的完整定义
// 使用此文件前，请确保 ParserState 已完整定义
// 例如：在 parser.hpp 中先定义 ParserState，然后包含 extract.h

// 前向声明（仅用于函数声明，实际使用时需要完整定义）
struct ParserState;

// ========== Extract 函数实现：通过函数重载支持不同 header 类型 ==========

// ETHER header 提取实现
inline size_t extract(ParserState& state, ETHER_S& header) {
    size_t header_size_bytes = 14;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract ETHER");
    }
    uint64_t dmac = 0, smac = 0;
    for (int i = 0; i < 6; ++i) {
        dmac = (dmac << 8) | state.pkt_data_ptr[state.current_offset_bytes + i];
        smac = (smac << 8) | state.pkt_data_ptr[state.current_offset_bytes + 6 + i];
    }
    header.Dmac = p5::uint<48>(dmac);
    header.Smac = p5::uint<48>(smac);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

// ETHER_TYPE header 提取实现
inline size_t extract(ParserState& state, ETHER_TYPE_S& header) {
    size_t header_size_bytes = 2;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract ETHER_TYPE");
    }
    uint16_t type = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes]) << 8) |
                    state.pkt_data_ptr[state.current_offset_bytes + 1];
    header.Type = p5::uint<16>(type);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

// VLAN_TAG header 提取实现
inline size_t extract(ParserState& state, VLAN_TAG_S& header) {
    size_t header_size_bytes = 4;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract VLAN_TAG");
    }
    uint16_t tpid = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes]) << 8) |
                   state.pkt_data_ptr[state.current_offset_bytes + 1];
    uint16_t vlan_info = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes + 2]) << 8) |
                         state.pkt_data_ptr[state.current_offset_bytes + 3];
    header.Tpid = p5::uint<16>(tpid);
    header.VlanInfo.PriCfi(p5::uint<4>((vlan_info >> 12) & 0x0F));
    header.VlanInfo.VlanID = p5::uint<12>(vlan_info & 0x0FFF);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

// IPv4 header 提取实现
inline size_t extract(ParserState& state, IPv4_S& header) {
    size_t header_size_bytes = 20;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract IPv4");
    }
    header.Version = p5::uint<4>((state.pkt_data_ptr[state.current_offset_bytes] >> 4) & 0x0F);
    header.Ihl = p5::uint<4>(state.pkt_data_ptr[state.current_offset_bytes] & 0x0F);
    header.u_0.TOS_raw = static_cast<uint8_t>(state.pkt_data_ptr[state.current_offset_bytes + 1]);
    uint16_t total_len = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes + 2]) << 8) |
                        state.pkt_data_ptr[state.current_offset_bytes + 3];
    header.TotalLen = p5::uint<16>(total_len);
    header.Protocol = p5::uint<8>(state.pkt_data_ptr[state.current_offset_bytes + 9]);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

// IPv6 header 提取实现
inline size_t extract(ParserState& state, IPv6_S& header) {
    size_t header_size_bytes = 40;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract IPv6");
    }
    header.Version = p5::uint<4>((state.pkt_data_ptr[state.current_offset_bytes] >> 4) & 0x0F);
    header.tc_union.TC_raw = static_cast<uint8_t>(((state.pkt_data_ptr[state.current_offset_bytes] & 0x0F) << 4) | 
                             ((state.pkt_data_ptr[state.current_offset_bytes + 1] >> 4) & 0x0F));
    header.NextProtocol = p5::uint<8>(state.pkt_data_ptr[state.current_offset_bytes + 6]);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

// TCP header 提取实现
inline size_t extract(ParserState& state, TCP_S& header) {
    size_t header_size_bytes = 20;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract TCP");
    }
    uint16_t src_port = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes]) << 8) |
                       state.pkt_data_ptr[state.current_offset_bytes + 1];
    uint16_t dst_port = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes + 2]) << 8) |
                       state.pkt_data_ptr[state.current_offset_bytes + 3];
    header.SrcPort = p5::uint<16>(src_port);
    header.DstPort = p5::uint<16>(dst_port);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

// UDP header 提取实现
inline size_t extract(ParserState& state, UDP_S& header) {
    size_t header_size_bytes = 8;
    if (state.current_offset_bytes + header_size_bytes > state.pkt_data_size) {
        throw std::runtime_error("PacketTooShort: cannot extract UDP");
    }
    uint16_t src_port = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes]) << 8) |
                       state.pkt_data_ptr[state.current_offset_bytes + 1];
    uint16_t dst_port = (static_cast<uint16_t>(state.pkt_data_ptr[state.current_offset_bytes + 2]) << 8) |
                       state.pkt_data_ptr[state.current_offset_bytes + 3];
    header.SrcPort = p5::uint<16>(src_port);
    header.DstPort = p5::uint<16>(dst_port);
    size_t old_offset = state.current_offset_bytes;
    state.current_offset_bytes += header_size_bytes;
    return old_offset;
}

#endif // EXTRACT_H
