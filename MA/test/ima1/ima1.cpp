struct FIBRSP_S {
    p5::uint<10> Port;
    p5::uint<8> EncapIndex;
};

using FIBFull_S = _inflate<FIBRSP_S>;

FIBFull_S FibLookup(p5::uint<2> &Status) {
    p5::uint<136> FibKey;
    _inflate<FIBRSP_S> CompressedFibRsp = { 0 };
    _inflate<FIBRSP_S> Mem = { 0 };
    FibKey = _key<decltype(FibKey)>();
    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(SE_TID_FIB, TBL_LKUP_TYPE_LPM, FibKey);
    Status = _status(SE_TID_FIB);
    _memcpy(CompressedFibRsp, { Mem });
    return CompressedFibRsp;
}

class FIB_TBL : public Table {
public:
    p5::uint<2> StatusFib;
    FIBFull_S rsFib;

    FIB_TBL() {}

    void apply() override {
        switch (PHI.L3Type.to_ullong()) 
        {
            case L3_TYPE_IPv4: 
            { 
                g_key.buildKey(Vrf, IPv4.DIP, p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
                break;
            }
            case L3_TYPE_IPv6: 
            { 
                g_key.buildKey(Vrf, IPv6.DIP);
                break;
            }
            default: { 
                break;
            }
        }
        rsFib = FibLookup(StatusFib);
    }
};

class IMA1_MATCH_TBL : public Table {
public:
    FIB_TBL tbFib;

    IMA1_MATCH_TBL() {}

    void apply() override {
        tbFib.apply();
    }
};

void iMA1Action(FIBFull_S rsFib) {
    if (_valid(rsFib)) {
        GLTP = rsFib.Port;
        EncapIndex = rsFib.EncapIndex;
        TTL = TTL - 1;
    }
}

class IMA1_ACTION_TBL : public Table {
public:
    IMA1_MATCH_TBL &tbIMA1Match;

    explicit IMA1_ACTION_TBL(IMA1_MATCH_TBL &tbIMA1Match_in) : tbIMA1Match(tbIMA1Match_in) {}

    void apply() override {
        iMA1Action(tbIMA1Match.tbFib.rsFib);
    }
};

void iMA1Control() {
    IMA1_MATCH_TBL  tbIMA1Match   =  IMA1_MATCH_TBL();
    IMA1_ACTION_TBL tbIMA1Action  =  IMA1_ACTION_TBL(tbIMA1Match);
    tbIMA1Match.apply();
    tbIMA1Action.apply();
}

void ingress() {
    iMA1Control();
}