#ifndef PARSER_HPP
#define PARSER_HPP

#include "parser_base.hpp"
#include "headers.hpp"
#include "model_intf_1027.h"

/**
 * @brief Parser 实现类
 * 
 * 实现具体的解析逻辑，使用全局 header 变量（定义在 headers.hpp 中）
 */
class ParserImpl : public ParserBase {
private:
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
    
    // ========== State 访问器方法 ==========
    const PHI_S& get_phi() const { return state.phi_temp; }
    PHI_S& get_phi() { return state.phi_temp; }
    const p5::uint<7>* get_pho() const { return state.pho_temp; }
    p5::uint<7>* get_pho() { return state.pho_temp; }
    size_t get_current_offset() const { return state.current_offset_bytes; }
};

#endif // PARSER_HPP

