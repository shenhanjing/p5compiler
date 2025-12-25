#include <cstring>

#include "generated_Switch.hpp"

Switch::Switch() : GtvContext(), BuiltInContext(), Packet() {}

// ========== Parser实现 ==========
void Switch::iprs() {
    return parse_ETHER();
}

void Switch::eprs() {
    return parse_ETHER();
}

void Switch::parse_ETHER() {
    PHI.L2Type = L2_TYPE_ETHERNET;
    
    PHO[PHO_OUTER_L2_START] = _extract(ETHER);

    switch(ETHER.ETHER_TYPE.Type.to_ullong()) {
        case 0x8100: return parse_VlanTag();
        case 0x0800: return parse_IPv4(); 
        case 0x86dd: return parse_IPv6(); 
        default: return _parser_next(0, 0); 
    }
}

void Switch::parse_VlanTag() {
    PHI.TagType = VLAN_SINGLE_TAGGED;
    PHO[PHO_OUTER_VLANS_START] = _extract(VLAN_TAG0);

    switch(VLAN_TAG0.ETHER_TYPE.Type.to_ullong()) {
        case 0x0800: return parse_IPv4(); 
        case 0x86dd: return parse_IPv6(); 
        default: return _parser_next(0, 0); 
    }
}

void Switch::parse_IPv4() {
    PHI.L3Type = L3_TYPE_IPv4;

    PHO[PHO_OUTER_L3_START] = _extract(IPv4);
    
    switch(IPv4.Protocol.to_ullong()) {
        case IP_PROTOCOL_UDP: return parse_UDP(); 
        case IP_PROTOCOL_TCP: return parse_TCP(); 
        default: return _parser_next(0, 0); 
    }
}

void Switch::parse_IPv6() {
    PHI.L3Type = L3_TYPE_IPv6;
    PHO[PHO_OUTER_L3_START] = _extract(IPv6);

    switch(IPv6.NextProtocol.to_ullong()) {
        case IP_PROTOCOL_UDP: return parse_UDP();
        case IP_PROTOCOL_TCP: return parse_TCP();
        default: return _parser_next(0, 0);
    }
}

void Switch::parse_TCP() {
    PHI.L4Type = L4_PROTOCOL_TCP;

    PHO[PHO_OUTER_L4_START] = _extract(TCP);

    return _parser_next(0, 0);
}

void Switch::parse_UDP() {
    PHI.L4Type = L4_PROTOCOL_UDP;

    PHO[PHO_OUTER_L4_START] = _extract(UDP);

    return _parser_next(0, 0);
}

// ========== MA实现 ==========
IPATFull_S Switch::IpatLookup(p5::uint<2> &Status) {
    p5::uint<10> Glsp;
    _inflate<IPATRSP_S> CompressedIpatRsp = { 0 };
    _inflate<IPATRSP_S> Mem = { 0 };
    Glsp = _key<decltype(Glsp)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_IPAT, TBL_LKUP_TYPE_INDEX, Glsp);
    Status = _status(SE_TID_IPAT);
    _memcpy(CompressedIpatRsp, { Mem });
    return CompressedIpatRsp;
}
IPATFull_S Switch::IpatLookup(p5::member<p5::uint<2>> &Status) {
    p5::uint<10> Glsp;
    _inflate<IPATRSP_S> CompressedIpatRsp = { 0 };
    _inflate<IPATRSP_S> Mem = { 0 };
    Glsp = _key<decltype(Glsp)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_IPAT, TBL_LKUP_TYPE_INDEX, Glsp);
    Status = _status(SE_TID_IPAT);
    _memcpy(CompressedIpatRsp, { Mem });
    return CompressedIpatRsp;
}

void Switch::iMA0Action(IPATFull_S rsIpat, p5::uint<2> IpatStatus) {
    if (_valid(rsIpat) && PHI.L3Type[p5::bit_range<1, 1>] == 1) {
        Vrf = rsIpat.VrfId;
        IsUc = 1;
    } else {
        DropFlag = 1;
    }
}

FIBFull_S Switch::FibLookup(p5::uint<2> &Status) {
    p5::uint<136> FibKey;
    _inflate<FIBRSP_S> CompressedFibRsp = { 0 };
    _inflate<FIBRSP_S> Mem = { 0 };
    FibKey = _key<decltype(FibKey)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_FIB, TBL_LKUP_TYPE_LPM, FibKey);
    Status = _status(SE_TID_FIB);
    _memcpy(CompressedFibRsp, { Mem });
    return CompressedFibRsp;
}
FIBFull_S Switch::FibLookup(p5::member<p5::uint<2>> &Status) {
    p5::uint<136> FibKey;
    _inflate<FIBRSP_S> CompressedFibRsp = { 0 };
    _inflate<FIBRSP_S> Mem = { 0 };
    FibKey = _key<decltype(FibKey)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_FIB, TBL_LKUP_TYPE_LPM, FibKey);
    Status = _status(SE_TID_FIB);
    _memcpy(CompressedFibRsp, { Mem });
    return CompressedFibRsp;
}

void Switch::iMA1Action(FIBFull_S rsFib) {
    if (_valid(rsFib)) {
        GLTP = rsFib.Port;
        EncapIndex = rsFib.EncapIndex;
        TTL = TTL - 1;
    }
}

// ========== ingress 实现 ==========
void Switch::pre_iMAControl()
{
  IPRS_TBL tbIprs = IPRS_TBL(*this);
  tbIprs.apply();
}

void Switch::iMA0Control() {
    IMA0_MATCH_TBL tbIMA0Match = IMA0_MATCH_TBL(*this);
    IMA0_ACTION_TBL tbIMA0Action = IMA0_ACTION_TBL(*this, tbIMA0Match);
    tbIMA0Match.apply();
    tbIMA0Action.apply();
}

void Switch::iMA1Control() {
    IMA1_MATCH_TBL  tbIMA1Match = IMA1_MATCH_TBL(*this);
    IMA1_ACTION_TBL tbIMA1Action = IMA1_ACTION_TBL(*this, tbIMA1Match);
    tbIMA1Match.apply();
    tbIMA1Action.apply();
}

void Switch::ingress() {
    pre_iMAControl();
    iMA0Control();
    iMA1Control();
}

// ========== interface 实现 ==========
void Switch::PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, NhiDef &nhi_info, 
                    Cp2NpHeader &cp2np_hdr, const PktHeader &pkt_hdr, Prs2Ma0FvInfoDef &fv_info) {
    (void)nhi_info;
    (void)cp2np_hdr;
    // 载入原始包
    std::memcpy(data_.data(), pkt_hdr.pkt_data, PKT_HEADER_BYTE_LEN);
    offset_ = 0;
    // 基础字段
    PHI.PortType = parser_hinfo.port_type;
    GLSP = parser_hinfo.port_id;

    if (direction == 0) {
        pre_iMAControl();
    }

    // 打包输出
    std::memcpy(fv_info.phData, data_.data(), PKT_HEADER_BYTE_LEN);
    auto phiOut = pack_phi_to_bytes();
    auto phoOut = pack_pho_to_bytes();
    auto gtvOut = pack_gtv_to_bytes();
    std::memcpy(fv_info.phiData, phiOut.data(), FV_PHI_BYTE_NUM);
    std::memcpy(fv_info.phoData, phoOut.data(), FV_PHO_BYTE_NUM);
    std::memcpy(fv_info.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);
}

// 单个 MA 处理流程
void Switch::SingleMaProc(const int ma_id, const std::string &packet_id, const int port_id,
    const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out) {
    (void)packet_id; // 当前流程未使用
    (void)port_id;   // 当前流程未使用

    // 载入 PH 数据
    std::memcpy(data_.data(), fv_in.phData, PKT_HEADER_BYTE_LEN);
    
    // 解包输入的 PHI / PHO / GTV
    PhiPackedBuffer phiIn{};
    std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);
    unpack_phi_from_bytes(phiIn);

    PhoPackedBuffer phoIn{};
    std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);
    unpack_pho_from_bytes(phoIn);

    GtvPackedBuffer gtvIn{};
    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);
    unpack_gtv_from_bytes(gtvIn);

    // 按 ma_id 选择执行的控制流程
    if (ma_id == 0) {
        iMA0Control();
    } else if (ma_id == 1) {
        iMA1Control();
    }

    std::memcpy(fv_out.phData, data_.data(), PKT_HEADER_BYTE_LEN);
    // 将最新的 PHI / PHO / GTV 打包写回输出 fv
    auto phiOut = pack_phi_to_bytes();
    auto phoOut = pack_pho_to_bytes();
    auto gtvOut = pack_gtv_to_bytes();
    std::memcpy(fv_out.phiData, phiOut.data(), FV_PHI_BYTE_NUM);
    std::memcpy(fv_out.phoData, phoOut.data(), FV_PHO_BYTE_NUM);
    std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);
}

void Switch::ImaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ima2IpmFvInfoDef &fv_out) {
    (void)port_id;

    // 载入 PH 数据
    std::memcpy(data_.data(), fv_in.phData, PKT_HEADER_BYTE_LEN);

    // 解包 PHI/PHO/GTV
    PhiPackedBuffer phiIn{};
    std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);
    unpack_phi_from_bytes(phiIn);

    PhoPackedBuffer phoIn{};
    std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);
    unpack_pho_from_bytes(phoIn);

    GtvPackedBuffer gtvIn{};
    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);
    unpack_gtv_from_bytes(gtvIn);

    // 执行 IMA 流程
    iMA0Control();
    iMA1Control();

    // 打包输出，仅 gtvData
    auto gtvOut = pack_gtv_to_bytes();
    std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);
}

// ========== 重置所有字段 ==========
void Switch::reset_all_fields() {
    // 清零 data_/offset_
    std::memset(data_.data(), 0, data_.size());
    offset_ = 0;

    // 清零 PHI
    PHI = PHI_S{};
    // 清零 PHO
    for (auto &v : PHO) v = 0;
    // 清零 headers
    ETHER = ETHER_S{};
    VLAN_TAG0 = VLAN_TAG_S{};
    ETHER_TYPE = ETHER_TYPE_S{};
    IPv4 = IPv4_S{};
    IPv6 = IPv6_S{};
    UDP = UDP_S{};
    TCP = TCP_S{};

    // 清零 fv字段
    GLSP = 0;
    GLTP = 0;
    LLTP = 0;
    Vrf = 0;
    FQID = 0;
    PktLength = 0;
    DropFlag = 0;
    IsUc = 0;
    Mgid = 0;
    SB = 0; SP = 0; TB = 0; TP = 0;
    HashValue = 0;
    TOS = 0;
    TTL = 0;
    EncapIndex = 0;
    HubSpkGrp = 0;
    EncapProfile = 0;
    // NGSFBuffer
    for (auto &b : NGSFBuffer) b = 0;
}
