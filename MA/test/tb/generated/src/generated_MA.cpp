#include <cstring>

#include "generated_MA.hpp"

Ingress::Ingress(SearchEngine &se, KeyManager &key) : Control(se, key) {}

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
