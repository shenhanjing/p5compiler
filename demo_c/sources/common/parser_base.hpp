#ifndef PARSER_BASE_HPP
#define PARSER_BASE_HPP

#include "../../model_intf_1027.h"

/**
 * @brief Parser 基类
 * 
 * 定义 Parser 的接口，所有 P5 转换后的 Parser 实现都应该继承此类
 */
class ParserBase {
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
