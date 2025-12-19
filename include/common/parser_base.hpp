#ifndef PARSER_BASE_HPP
#define PARSER_BASE_HPP

#include "model_intf_1027.h"
#include "headers.hpp"
#include <cstdint>
#include <cstring>
#include <climits>

// 注意：extract.h 需要 ParserState 的完整定义，所以先定义 ParserState，再包含 extract.h

/**
 * @brief FV (Field Values) 结构体
 * 
 * 包含解析过程中需要的所有字段值，这些值会被序列化到 gtvData 中
 */
struct FV_S {
    // p5::uint<8> NGSFBuffer[64];  // 注释掉：不包含在 FV_S 中
    p5::uint<10> GLSP;
    p5::uint<10> GLTP;
    p5::uint<6> LLTP;
    p5::uint<8> Vrf;
    p5::uint<6> FQID;
    p5::uint<14> PktLength;
    p5::uint<1> DropFlag;
    p5::uint<1> IsUc;
    p5::uint<12> Mgid;
    p5::uint<8> SB;
    p5::uint<8> SP;
    p5::uint<8> TB;
    p5::uint<8> TP;
    p5::uint<16> HashValue;
    p5::uint<8> TOS;
    p5::uint<8> TTL;
    p5::uint<8> EncapIndex;
    p5::uint<3> HubSpkGrp;
    p5::uint<2> EncapProfile;
    
    // 默认构造函数，初始化为 0
    FV_S() {
        GLSP = p5::uint<10>(0);
        GLTP = p5::uint<10>(0);
        LLTP = p5::uint<6>(0);
        Vrf = p5::uint<8>(0);
        FQID = p5::uint<6>(0);
        PktLength = p5::uint<14>(0);
        DropFlag = p5::uint<1>(0);
        IsUc = p5::uint<1>(0);
        Mgid = p5::uint<12>(0);
        SB = p5::uint<8>(0);
        SP = p5::uint<8>(0);
        TB = p5::uint<8>(0);
        TP = p5::uint<8>(0);
        HashValue = p5::uint<16>(0);
        TOS = p5::uint<8>(0);
        TTL = p5::uint<8>(0);
        EncapIndex = p5::uint<8>(0);
        HubSpkGrp = p5::uint<3>(0);
        EncapProfile = p5::uint<2>(0);
    }
};

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
    FV_S fv;                           // FV 字段值（新增）
    
    // 初始化函数
    void init(const PktHeader& pkt_hdr, size_t start_offset = 0) {
        pkt_data_ptr = pkt_hdr.pkt_data;
        pkt_data_size = PKT_HEADER_BYTE_LEN;
        current_offset_bytes = start_offset;
        
        // 初始化 phi_temp 和 pho_temp 为 0
        phi_temp = PHI_S{};  // 使用值初始化替代 memset
        for (int i = 0; i < 5; i++) {
            pho_temp[i] = p5::uint<7>(0);
        }
        
        // 初始化 fv 为 0（新增）
        fv = FV_S{};  // 使用默认构造函数，所有字段初始化为 0
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
    void _lookahead(HeaderType& header, size_t offset = SIZE_MAX) {
        size_t saved_offset = state.current_offset_bytes;
        if (offset != SIZE_MAX) {
            state.current_offset_bytes = offset;
        }
        _extract(state, header);
        state.current_offset_bytes = saved_offset;
    }

    // ========== 内置函数：_parser_next ==========
    /**
     * @brief Parser 状态转换函数
     * 
     * @param group 解析组 ID
     * @param stage 解析阶段 ID
     */
    void _parser_next(int group, int stage) {
        // TODO: 后续实现
        (void)group;
        (void)stage;
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
