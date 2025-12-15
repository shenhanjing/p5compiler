#ifndef PARSER_CONTEXT_HPP
#define PARSER_CONTEXT_HPP

// ===================================================================
// ParserContext 已合并到 ParserImpl 中
// 
// 原来的 ParserContext 功能已迁移到：
// 1. ParserState 结构体（在 parser.hpp 中）- 包含状态信息
// 2. ParserImpl 类（在 parser.hpp 中）- 包含 extract 函数和解析逻辑
//
// 此文件保留为空，以保持向后兼容性（如果有其他代码仍引用此头文件）
// ===================================================================

// 如果需要使用 ParserContext 的功能，请使用 ParserImpl 类
// 示例：
//   ParserImpl parser;
//   parser.PrsProcPkt(...);
//   使用 parser.get_phi() 和 parser.get_pho() 访问结果

#endif // PARSER_CONTEXT_HPP
private:
    const uint8_t* pkt_data_ptr;      // 指向 pkt_hdr.pkt_data
    size_t pkt_data_size;              // 数据包大小（字节）
    size_t current_offset_bytes;       // 当前解析偏移量（字节）
    
    PHI_S phi_temp;                    // PHI 临时变量
    p5::uint<7> pho_temp[5];           // PHO 临时数组
    
    // ========== 新增：Parser 引用 ==========
    ParserImpl* parser_ptr;            // 指向 Parser 实例，用于访问 header 成员变量

public:
    // 初始化
    void init(const PktHeader& pkt_hdr, ParserImpl* parser, size_t start_offset = 0) {
        pkt_data_ptr = pkt_hdr.pkt_data;
        pkt_data_size = PKT_HEADER_BYTE_LEN;
        current_offset_bytes = start_offset;
        parser_ptr = parser;  // 保存 Parser 引用
        
        // 初始化 phi_temp 和 pho_temp 为 0
        memset(&phi_temp, 0, sizeof(phi_temp));
        for (int i = 0; i < 5; i++) {
            pho_temp[i] = p5::uint<7>(0);
        }
    }
    
    // Extract 函数：提取 header 并更新偏移量
    // 使用函数重载为每种 header 类型提供特化实现
    size_t extract_impl(ETHER_S& header) {
        size_t header_size_bytes = 14;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract ETHER");
        }
        uint64_t dmac = 0, smac = 0;
        for (int i = 0; i < 6; ++i) {
            dmac = (dmac << 8) | pkt_data_ptr[current_offset_bytes + i];
            smac = (smac << 8) | pkt_data_ptr[current_offset_bytes + 6 + i];
        }
        header.Dmac = p5::uint<48>(dmac);
        header.Smac = p5::uint<48>(smac);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    size_t extract_impl(ETHER_TYPE_S& header) {
        size_t header_size_bytes = 2;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract ETHER_TYPE");
        }
        uint16_t type = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes]) << 8) |
                        pkt_data_ptr[current_offset_bytes + 1];
        header.Type = p5::uint<16>(type);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    size_t extract_impl(VLAN_TAG_S& header) {
        size_t header_size_bytes = 4;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract VLAN_TAG");
        }
        uint16_t tpid = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes]) << 8) |
                       pkt_data_ptr[current_offset_bytes + 1];
        uint16_t vlan_info = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes + 2]) << 8) |
                             pkt_data_ptr[current_offset_bytes + 3];
        header.Tpid = p5::uint<16>(tpid);
        header.VlanInfo.PriCfi(p5::uint<4>((vlan_info >> 12) & 0x0F));
        header.VlanInfo.VlanID = p5::uint<12>(vlan_info & 0x0FFF);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    size_t extract_impl(IPv4_S& header) {
        size_t header_size_bytes = 20;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract IPv4");
        }
        header.Version = p5::uint<4>((pkt_data_ptr[current_offset_bytes] >> 4) & 0x0F);
        header.Ihl = p5::uint<4>(pkt_data_ptr[current_offset_bytes] & 0x0F);
        header.u_0.TOS_raw = pkt_data_ptr[current_offset_bytes + 1];
        uint16_t total_len = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes + 2]) << 8) |
                            pkt_data_ptr[current_offset_bytes + 3];
        header.TotalLen = p5::uint<16>(total_len);
        header.Protocol = p5::uint<8>(pkt_data_ptr[current_offset_bytes + 9]);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    size_t extract_impl(IPv6_S& header) {
        size_t header_size_bytes = 40;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract IPv6");
        }
        header.Version = p5::uint<4>((pkt_data_ptr[current_offset_bytes] >> 4) & 0x0F);
        header.tc_union.TC_raw = ((pkt_data_ptr[current_offset_bytes] & 0x0F) << 4) | 
                                 ((pkt_data_ptr[current_offset_bytes + 1] >> 4) & 0x0F);
        header.NextProtocol = p5::uint<8>(pkt_data_ptr[current_offset_bytes + 6]);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    size_t extract_impl(TCP_S& header) {
        size_t header_size_bytes = 20;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract TCP");
        }
        uint16_t src_port = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes]) << 8) |
                           pkt_data_ptr[current_offset_bytes + 1];
        uint16_t dst_port = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes + 2]) << 8) |
                           pkt_data_ptr[current_offset_bytes + 3];
        header.SrcPort = p5::uint<16>(src_port);
        header.DstPort = p5::uint<16>(dst_port);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    size_t extract_impl(UDP_S& header) {
        size_t header_size_bytes = 8;
        if (current_offset_bytes + header_size_bytes > pkt_data_size) {
            throw std::runtime_error("PacketTooShort: cannot extract UDP");
        }
        uint16_t src_port = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes]) << 8) |
                           pkt_data_ptr[current_offset_bytes + 1];
        uint16_t dst_port = (static_cast<uint16_t>(pkt_data_ptr[current_offset_bytes + 2]) << 8) |
                           pkt_data_ptr[current_offset_bytes + 3];
        header.SrcPort = p5::uint<16>(src_port);
        header.DstPort = p5::uint<16>(dst_port);
        size_t old_offset = current_offset_bytes;
        current_offset_bytes += header_size_bytes;
        return old_offset;
    }
    
    // ========== Extract 函数：统一的 extract 接口，通过函数重载支持不同 header 类型 ==========
    // 这些函数接受 header 引用作为参数，内部调用相应的 extract_impl
    size_t extract(ETHER_S& header) {
        return extract_impl(header);
    }
    
    size_t extract(ETHER_TYPE_S& header) {
        return extract_impl(header);
    }
    
    size_t extract(VLAN_TAG_S& header) {
        return extract_impl(header);
    }
    
    size_t extract(IPv4_S& header) {
        return extract_impl(header);
    }
    
    size_t extract(IPv6_S& header) {
        return extract_impl(header);
    }
    
    size_t extract(TCP_S& header) {
        return extract_impl(header);
    }
    
    size_t extract(UDP_S& header) {
        return extract_impl(header);
    }
    
    // ========== 保留原有的 extract_* 函数以保持向后兼容（可选）==========
    // 注意：这些函数需要 ParserImpl 的完整定义，所以在函数定义之前包含 parser.hpp
    // parser.hpp 只使用 ParserContext 的前向声明，不会导致循环依赖
    size_t extract_ether();
    
    size_t extract_ether_type();
    size_t extract_vlan_tag0();
    size_t extract_ipv4();
    size_t extract_ipv6();
    size_t extract_tcp();
    size_t extract_udp();
    
    // ========== Lookahead 函数：通过 Parser 访问 header 成员变量 ==========
    void lookahead_ether_type();
    void lookahead_ether_type_at_offset(size_t offset);
    
    // ========== 保留原有的 lookahead 模板函数（内部使用）==========
    template<typename HeaderType>
    void lookahead(HeaderType& header) {
        // 临时保存偏移量
        size_t saved_offset = current_offset_bytes;
        
        // 使用 extract_impl 提取，但不更新偏移量
        extract_impl(header);
        
        // 恢复偏移量
        current_offset_bytes = saved_offset;
    }
    
    // 获取 PHI/PHO（用于序列化）
    const PHI_S& get_phi() const { return phi_temp; }
    PHI_S& get_phi() { return phi_temp; }
    const p5::uint<7>* get_pho() const { return pho_temp; }
    p5::uint<7>* get_pho() { return pho_temp; }
    
    // 获取当前偏移量（用于调试）
    size_t get_current_offset() const { return current_offset_bytes; }
};

// 在类定义之后包含 parser.hpp，使 extract_* 函数实现能够访问 ParserImpl 的完整定义
// 注意：parser.hpp 只使用 ParserContext 的前向声明，不会导致循环依赖
#include "parser.hpp"

// ========== Extract 和 Lookahead 函数的实现（需要 ParserImpl 的完整定义）==========
inline size_t ParserContext::extract_ether() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    ETHER_S& header = parser_ptr->get_ether();
    return extract_impl(header);
}

inline size_t ParserContext::extract_ether_type() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    ETHER_TYPE_S& header = parser_ptr->get_ether_type();
    return extract_impl(header);
}

inline size_t ParserContext::extract_vlan_tag0() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    VLAN_TAG_S& header = parser_ptr->get_vlan_tag0();
    return extract_impl(header);
}

inline size_t ParserContext::extract_ipv4() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    IPv4_S& header = parser_ptr->get_ipv4();
    return extract_impl(header);
}

inline size_t ParserContext::extract_ipv6() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    IPv6_S& header = parser_ptr->get_ipv6();
    return extract_impl(header);
}

inline size_t ParserContext::extract_tcp() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    TCP_S& header = parser_ptr->get_tcp();
    return extract_impl(header);
}

inline size_t ParserContext::extract_udp() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    UDP_S& header = parser_ptr->get_udp();
    return extract_impl(header);
}

inline void ParserContext::lookahead_ether_type() {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    ETHER_TYPE_S& header = parser_ptr->get_ether_type();
    size_t saved_offset = current_offset_bytes;
    extract_impl(header);
    current_offset_bytes = saved_offset;
}

inline void ParserContext::lookahead_ether_type_at_offset(size_t offset) {
    if (!parser_ptr) {
        throw std::runtime_error("Parser pointer is null");
    }
    ETHER_TYPE_S& header = parser_ptr->get_ether_type();
    size_t saved_offset = current_offset_bytes;
    current_offset_bytes = offset;
    extract_impl(header);
    current_offset_bytes = saved_offset;
}

#endif // PARSER_CONTEXT_HPP

