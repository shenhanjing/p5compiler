#ifndef PARSER_CONTEXT_HPP
#define PARSER_CONTEXT_HPP

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <type_traits>
#include "../../model_intf_1027.h"
#include "headers.hpp"

// ParserContext 类：管理解析状态
class ParserContext {
private:
    const uint8_t* pkt_data_ptr;      // 指向 pkt_hdr.pkt_data
    size_t pkt_data_size;              // 数据包大小（字节）
    size_t current_offset_bytes;       // 当前解析偏移量（字节）
    
    PHI_S phi_temp;                    // PHI 临时变量
    p5::uint<7> pho_temp[5];           // PHO 临时数组

public:
    // 初始化
    void init(const PktHeader& pkt_hdr, size_t start_offset = 0) {
        pkt_data_ptr = pkt_hdr.pkt_data;
        pkt_data_size = PKT_HEADER_BYTE_LEN;
        current_offset_bytes = start_offset;
        
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
    
    // 通用 extract 模板函数
    template<typename HeaderType>
    size_t extract(HeaderType& header) {
        return extract_impl(header);
    }
    
    // Lookahead 函数：预读 header 但不更新偏移量
    template<typename HeaderType>
    void lookahead(HeaderType& header) {
        // 临时保存偏移量
        size_t saved_offset = current_offset_bytes;
        
        // 使用 extract 提取，但不更新偏移量
        extract(header);
        
        // 恢复偏移量
        current_offset_bytes = saved_offset;
    }
    
    // Lookahead 函数：在指定偏移量预读 header
    template<typename HeaderType>
    void lookahead_at_offset(HeaderType& header, size_t offset) {
        // 临时保存偏移量
        size_t saved_offset = current_offset_bytes;
        
        // 设置临时偏移量
        current_offset_bytes = offset;
        
        // 使用 extract 提取，但不更新偏移量
        extract(header);
        
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

#endif // PARSER_CONTEXT_HPP

