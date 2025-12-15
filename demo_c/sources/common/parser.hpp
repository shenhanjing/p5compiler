#ifndef PARSER_HPP
#define PARSER_HPP

#include "parser_base.hpp"
#include "headers.hpp"
#include "../../model_intf_1027.h"
#include <cstdint>
#include <cstring>
#include <climits>

// 注意：extract.h 需要 ParserState 的完整定义，所以先定义 ParserState，再包含 extract.h

/**
 * @brief Parser 状态结构体
 * 
 * 包含解析过程中需要的所有状态信息
 */
struct ParserState {
    const uint8_t* pkt_data_ptr;      // 指向 pkt_hdr.pkt_data
    size_t pkt_data_size;              // 数据包大小（字节）
    size_t current_offset_bytes;       // 当前解析偏移量（字节）
    PHI_S phi_temp;                    // PHI 临时变量
    p5::uint<7> pho_temp[5];           // PHO 临时数组
    
    // 初始化函数
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
};

// 在定义 ParserState 之后，包含 extract.h（extract.h 需要 ParserState 的完整定义）
#include "extract.h"

/**
 * @brief Parser 实现类
 * 
 * 包含所有 header 成员变量和解析状态，实现具体的解析逻辑
 */
class ParserImpl : public ParserBase {
private:
    // ========== Header 成员变量（替代全局变量）==========
    ETHER_S ether;
    VLAN_TAG_S vlan_tag0;
    ETHER_TYPE_S ether_type;
    IPv4_S ipv4;
    IPv6_S ipv6;
    UDP_S udp;
    TCP_S tcp;
    
    // ========== Parser 状态 ==========
    ParserState state;
    
    // ========== Lookahead 函数 ==========
    void lookahead_ether_type_at_offset(size_t offset);
    
    template<typename HeaderType>
    void lookahead(HeaderType& header, size_t offset = SIZE_MAX) {
        size_t saved_offset = state.current_offset_bytes;
        if (offset != SIZE_MAX) {
            state.current_offset_bytes = offset;
        }
        extract(state, header);
        state.current_offset_bytes = saved_offset;
    }
    
    // ========== 解析函数（私有成员函数）==========
    void iprs();
    void eprs();
    void parse_ETHER();
    void parse_VlanTag();
    void parse_IPv4();
    void parse_IPv6();
    void parse_TCP();
    void parse_UDP();
    
public:
    // ========== 构造函数/析构函数 ==========
    ParserImpl() = default;
    ~ParserImpl() = default;
    
    // ========== 实现基类接口 ==========
    void PrsProcPkt(
        bool direction,
        const ParserHwInfo &parser_hinfo,
        NhiDef &nhi_info,
        Cp2NpHeader &cp2np_hdr,
        const PktHeader &pkt_hdr,
        Prs2Ma0FvInfoDef &fv_info
    ) override;
    
    // ========== Header 访问器方法 ==========
    ETHER_S& get_ether() { return ether; }
    const ETHER_S& get_ether() const { return ether; }
    
    VLAN_TAG_S& get_vlan_tag0() { return vlan_tag0; }
    const VLAN_TAG_S& get_vlan_tag0() const { return vlan_tag0; }
    
    ETHER_TYPE_S& get_ether_type() { return ether_type; }
    const ETHER_TYPE_S& get_ether_type() const { return ether_type; }
    
    IPv4_S& get_ipv4() { return ipv4; }
    const IPv4_S& get_ipv4() const { return ipv4; }
    
    IPv6_S& get_ipv6() { return ipv6; }
    const IPv6_S& get_ipv6() const { return ipv6; }
    
    UDP_S& get_udp() { return udp; }
    const UDP_S& get_udp() const { return udp; }
    
    TCP_S& get_tcp() { return tcp; }
    const TCP_S& get_tcp() const { return tcp; }
    
    // ========== State 访问器方法 ==========
    const PHI_S& get_phi() const { return state.phi_temp; }
    PHI_S& get_phi() { return state.phi_temp; }
    const p5::uint<7>* get_pho() const { return state.pho_temp; }
    p5::uint<7>* get_pho() { return state.pho_temp; }
    size_t get_current_offset() const { return state.current_offset_bytes; }
};

#endif // PARSER_HPP

