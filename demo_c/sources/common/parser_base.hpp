#ifndef PARSER_BASE_HPP
#define PARSER_BASE_HPP

#include "../../model_intf_1027.h"
#include "headers.hpp"
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
 * @brief Parser 基类
 * 
 * 定义 Parser 的接口，所有 P5 转换后的 Parser 实现都应该继承此类
 */
class ParserBase {
protected:
    // ========== Parser 状态 ==========
    ParserState state;
    
    // ========== Lookahead 函数 ==========
    template<typename HeaderType>
    void lookahead(HeaderType& header, size_t offset = SIZE_MAX) {
        size_t saved_offset = state.current_offset_bytes;
        if (offset != SIZE_MAX) {
            state.current_offset_bytes = offset;
        }
        extract(state, header);
        state.current_offset_bytes = saved_offset;
    }

public:
    virtual ~ParserBase() = default;
    
    /**
     * @brief 解析数据包的主入口函数
     * 
     * @param direction 0-ingress, 1-egress
     * @param parser_hinfo Parser 硬件信息
     * @param nhi_info 下一跳信息
     * @param cp2np_hdr 控制平面到数据平面 header
     * @param pkt_hdr 数据包头部
     * @param fv_info 输出的 FV 信息
     */
    virtual void PrsProcPkt(
        bool direction,
        const ParserHwInfo &parser_hinfo,
        NhiDef &nhi_info,
        Cp2NpHeader &cp2np_hdr,
        const PktHeader &pkt_hdr,
        Prs2Ma0FvInfoDef &fv_info
    ) = 0;
};

#endif // PARSER_BASE_HPP
