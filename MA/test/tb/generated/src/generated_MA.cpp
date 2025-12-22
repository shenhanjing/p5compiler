#include <cstring>

#include "generated_MA.hpp"

Ingress::Ingress() : GtvContext(), BuiltInContext() {}

IPATFull_S Ingress::IpatLookup(p5::uint<2> &Status) {
    p5::uint<10> Glsp;
    _inflate<IPATRSP_S> CompressedIpatRsp = { 0 };
    _inflate<IPATRSP_S> Mem = { 0 };
    Glsp = _key<decltype(Glsp)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_IPAT, TBL_LKUP_TYPE_INDEX, Glsp);
    Status = _status(SE_TID_IPAT);
    _memcpy(CompressedIpatRsp, { Mem });
    return CompressedIpatRsp;
}

void Ingress::iMA0Action(IPATFull_S rsIpat, p5::uint<2> IpatStatus) {
    if (_valid(rsIpat) && (PHI.L3Type == L3_TYPE_IPv4 || PHI.L3Type == L3_TYPE_IPv6)) {
        Vrf = rsIpat.VrfId;
        IsUc = 1;
    } else {
        DropFlag = 1;
    }
}

FIBFull_S Ingress::FibLookup(p5::uint<2> &Status) {
    p5::uint<136> FibKey;
    _inflate<FIBRSP_S> CompressedFibRsp = { 0 };
    _inflate<FIBRSP_S> Mem = { 0 };
    FibKey = _key<decltype(FibKey)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_FIB, TBL_LKUP_TYPE_LPM, FibKey);
    Status = _status(SE_TID_FIB);
    _memcpy(CompressedFibRsp, { Mem });
    return CompressedFibRsp;
}

void Ingress::iMA1Action(FIBFull_S rsFib) {
    if (_valid(rsFib)) {
        GLTP = rsFib.Port;
        EncapIndex = rsFib.EncapIndex;
        TTL = TTL - 1;
    }
}

void Ingress::iMA0Control() {
    IMA0_MATCH_TBL tbIMA0Match = IMA0_MATCH_TBL(*this);
    IMA0_ACTION_TBL tbIMA0Action = IMA0_ACTION_TBL(*this, tbIMA0Match);
    tbIMA0Match.apply();
    tbIMA0Action.apply();
}

void Ingress::iMA1Control() {
    IMA1_MATCH_TBL  tbIMA1Match = IMA1_MATCH_TBL(*this);
    IMA1_ACTION_TBL tbIMA1Action = IMA1_ACTION_TBL(*this, tbIMA1Match);
    tbIMA1Match.apply();
    tbIMA1Action.apply();
}

void Ingress::ingress() {
    iMA0Control();
    iMA1Control();
}

// 单个 MA 处理流程
void Ingress::SingleMaProc(const int ma_id, const std::string &packet_id, const int port_id,
    const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out) {
    (void)packet_id; // 当前流程未使用
    (void)port_id;   // 当前流程未使用

    // 解包输入的 PHI / PHO / GTV
    PhiPackedBuffer phiIn{};
    std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);
    unpack_phi_from_bytes(phiIn);

    PhoPackedBuffer phoIn{};
    std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);
    unpack_pho_from_bytes(phoIn);

    FvPackedBuffer gtvIn{};
    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);
    unpack_fv_from_bytes(gtvIn);

    // 按 ma_id 选择执行的控制流程
    if (ma_id == 0) {
    iMA0Control();
    } else if (ma_id == 1) {
    iMA1Control();
    }

    // 将最新的 PHI / PHO / GTV 打包写回输出 fv
    auto phiOut = pack_phi_to_bytes();
    auto phoOut = pack_pho_to_bytes();
    auto gtvOut = pack_fv_to_bytes();

    std::memcpy(fv_out.phiData, phiOut.data(), FV_PHI_BYTE_NUM);
    std::memcpy(fv_out.phoData, phoOut.data(), FV_PHO_BYTE_NUM);
    std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);
}
