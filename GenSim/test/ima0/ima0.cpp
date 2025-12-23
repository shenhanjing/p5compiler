struct IPATRSP_S {
    p5::uint<1> Valid;
    p5::uint<1> RouterIntf;
    p5::uint<1> QinQ;
    p5::uint<8> VrfId;
    VlanInfo_S Pvid;
};

using IPATFull_S = _inflate<IPATRSP_S>;

IPATFull_S IpatLookup(p5::uint<2> &Status) {
    p5::uint<10> Glsp;
    _inflate<IPATRSP_S> CompressedIpatRsp = { 0 };
    _inflate<IPATRSP_S> Mem = { 0 };
    Glsp = _key<decltype(Glsp)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_IPAT, TBL_LKUP_TYPE_INDEX, Glsp);
    Status = _status(SE_TID_IPAT);
    _memcpy(CompressedIpatRsp, { Mem });
    return CompressedIpatRsp;
}

class IPAT_TBL : public Table {
public:
    p5::uint<2> IpatStatus;
    IPATFull_S rsIpat;

    IPAT_TBL() {}

    void apply() override {
        switch (PHI.PortType)
        {
            case PORT_TYPE_ETH:
            {
                g_key.buildKey(GLSP);
                break;
            }
            default:
            {
                break;
            }
        }
        rsIpat = IpatLookup(IpatStatus);
    }
};

class IMA0_MATCH_TBL : public Table {
public:
    IPAT_TBL tbIPAT;

    IMA0_MATCH_TBL() {}

    void apply() override {
        tbIPAT.apply();
    }
};

void iMA0Action(IPATFull_S rsIpat, p5::uint<2> IpatStatus) {
    if (_valid(rsIpat) && (PHI.L3Type == L3_TYPE_IPv4 || PHI.L3Type == L3_TYPE_IPv6)) {
        Vrf = rsIpat.VrfId;
        IsUc = 1;
    } else {
        DropFlag = 1;
    }
}

class IMA0_ACTION_TBL : public Table {
public:
    IMA0_MATCH_TBL &tbIMA0Match;

    explicit IMA0_ACTION_TBL(IMA0_MATCH_TBL &tbIMA0Match_in) : tbIMA0Match(tbIMA0Match_in) {}

    void apply() override {
        iMA0Action(tbIMA0Match.tbIPAT.rsIpat, tbIMA0Match.tbIPAT.IpatStatus);
    }
};

void iMA0Control() {
    IMA0_MATCH_TBL tbIMA0Match;
    IMA0_ACTION_TBL tbIMA0Action(tbIMA0Match);
    tbIMA0Match.apply();
    tbIMA0Action.apply();
}

void ingress() {
    iMA0Control();
}