#ifndef _MODEL_INTF_H_
#define _MODEL_INTF_H_

#define PKT_HEADER_BYTE_LEN     192

// FV数据宽度取决于微码代码版本，可能会有变化
#define FV_PH_BIT_WIDTH         1568
#define FV_PHI_BIT_WIDTH        80
#define FV_UDF_BIT_WIDTH        256
#define FV_GTV_MAX_BIT_WIDTH    1414
#define FV_PGTV_BIT_WIDTH       192

#define FV_PH_BYTE_NUM          ((FV_PH_BIT_WIDTH + 7) / 8)       // 196
#define FV_PHI_BYTE_NUM         ((FV_PHI_BIT_WIDTH + 7) / 8)      // 10
#define FV_PHO_BYTE_NUM         32
#define FV_UDF_BYTE_NUM         ((FV_UDF_BIT_WIDTH + 7) / 8)      // 32
#define FV_GTV_MAX_BYTE_NUM     ((FV_GTV_MAX_BIT_WIDTH + 7) / 8)  // 177
#define FV_PGTV_BYTE_NUM        ((FV_PGTV_BIT_WIDTH + 7) / 8)     // 24

//
struct ParserHwInfo {
    uint32_t port_id;
    uint32_t port_type;
    uint32_t parser_start; // InitNS.block_id + InitNS.state_id
    uint16_t init_ti_value;
    uint16_t init_ti_mask;
    uint16_t pre_ipat_info;
};

// next hop information, from loopback path
struct NhiDef {
    // TODO :
};

// cp2np header, from control plane
struct Cp2NpHeader {
    // TODO :
};

struct Np2NpHeader {
    // TODO :
};

struct Np2TmHeader {
    // TODO :
};

struct PktHeader {
    uint8_t pkt_data[PKT_HEADER_BYTE_LEN];
};

struct Prs2Ma0FvInfoDef {
    uint8_t phData[FV_PH_BYTE_NUM];     // packet header
    // uint8_t phValidPart;
    uint8_t phiData[FV_PHI_BYTE_NUM];   // PH information, 报文头按照协议树解析结果
    uint8_t phoData[FV_PHO_BYTE_NUM];        // PH offset, 各协议字段偏移, 每个pho字段是7bit，这里多个字段间不能有空隙
    uint8_t udfData[FV_UDF_BYTE_NUM];   // User defined fields， Ingress only
    uint8_t gtvData[FV_GTV_MAX_BYTE_NUM]; // Global temporal vector
    uint8_t pgtvData[FV_PGTV_BYTE_NUM];   // Programmable GTV
};

struct Ima2IpmFvInfoDef {
    uint8_t gtvData[FV_GTV_MAX_BYTE_NUM];
    uint8_t pgtvData[FV_PGTV_BYTE_NUM];
    // bool FvNoAcLkp;  // 只做资源回收用，不影响转发结果
};

struct Ema2EpmFvInfoDef {
    uint8_t phData[FV_PH_BYTE_NUM];
    uint8_t phoData[FV_PHO_BYTE_NUM];
    uint8_t gtvData[FV_GTV_MAX_BYTE_NUM];
    uint8_t pgtvData[FV_PGTV_BYTE_NUM];
    bool fvHmOvfl; // Header modification overflow indication
};

struct MaToMaFvInfoDef {
    uint8_t phData[FV_PH_BYTE_NUM];     // packet header
    uint8_t phiData[FV_PHI_BYTE_NUM];   // PH information, 报文头按照协议树解析结果
    uint8_t phoData[FV_PHO_BYTE_NUM];        // PH offset, 各协议字段偏移, 每个pho字段是7bit，这里多个字段间不能有空隙
    uint8_t udfData[FV_UDF_BYTE_NUM];   // User defined fields， Ingress only
    uint8_t gtvData[FV_GTV_MAX_BYTE_NUM]; // Global temporal vector
    uint8_t pgtvData[FV_PGTV_BYTE_NUM];   // Programmable GTV
};

/*
    A接口: Parser业务模型接口
    参数：
    direction [in] 0-ingress, 1- egress
    port_id [in] port number
    parser_hinfo [in] parser硬件预解析信息，给业务模型使用，部分信息用于解析流程处理，部分信息需要通过 FV 往下级传递（如 port_type）
    nhi_info [in] next hop information, from loopback path
    cp2np_hdr [in] cp2np header, from control plane
    pkt_hdr [in] 报文头信息，具体定义见PktHeader结构
    fv_info [out] parser生成的fv信息，具体定义见Prs2Ma0FvInfoDef 结构
*/
void PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, NhiDef &nhi_info, Cp2NpHeader &cp2np_hdr, const PktHeader &pkt_hdr, Prs2Ma0FvInfoDef &fv_info);

/*
    B接口: 上行MA业务模型接口
    参数：
    port_id [in] port number
    fv_in [in] parser生成的fv信息，具体定义见Prs2Ma0FvInfoDef 结构
    fv_out [out] IMA处理后的fv信息，具体定义见Ima2IpmFvInfoDef 结构
*/
void ImaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ima2IpmFvInfoDef &fv_out);

/*
    C接口: 下行MA业务模型接口
    参数：
    port_id [in] port number
    fv_in [in] parser生成的fv信息，具体定义见Prs2Ma0FvInfoDef 结构
    fv_out [out] EMA处理后的fv信息，具体定义见Ema2EpmFvInfoDef 结构
*/
void EmaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ema2EpmFvInfoDef &fv_out);

/*
    D接口: IPM业务模型接口
    参数：
    port_id [in] port number
    fv_in [in] parser生成的fv信息，具体定义见Prs2Ma0FvInfoDef 结构
*/
void IpmProcPkt(const int port_id, const Ima2IpmFvInfoDef &fv_in, Np2NpHeader &np2np_hdr, Np2TmHeader &np2tm_hdr);

/*
    E接口: MA业务模型接口
    参数：
    ma_id [in]
    packet_id [in] packet id str, 仅用于打印
    port_id [in] port number
    fv_in [in] 前级MA生成的fv信息，具体定义见MaToMaFvInfoDef 结构
    fv_out [out] MA处理后的fv信息，具体定义见MaToMaFvInfoDef 结构
*/
void SingleMaProc(const int ma_id, const std::string &packet_id, const int port_id, const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out);

#endif