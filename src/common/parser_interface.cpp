/*****************************************************************************************************************
 *                               Parser Interface (C-style wrapper)                                *
 ******************************************************************************************************************/

#include "parser.hpp"
#include "model_intf_1027.h"
#include <thread>

/**
 * @brief Parser 接口函数（C 风格）
 * 
 * 保持与 model_intf_1027.h 中定义的接口一致
 * 内部使用 ParserImpl 类实现
 * 使用线程局部存储确保线程安全
 */
void PrsProcPkt(
    bool direction,
    const ParserHwInfo &parser_hinfo,
    NhiDef &nhi_info,
    Cp2NpHeader &cp2np_hdr,
    const PktHeader &pkt_hdr,
    Prs2Ma0FvInfoDef &fv_info
) {
    // 使用线程局部存储，确保线程安全
    // 每个线程有独立的 Parser 实例，避免数据竞争
    static thread_local ParserImpl parser;
    
    // 调用实现类的 PrsProcPkt
    parser.PrsProcPkt(direction, parser_hinfo, nhi_info, cp2np_hdr, pkt_hdr, fv_info);
}
