#ifndef GENERATED_MA_HPP
#define GENERATED_MA_HPP

#include <string>

#include "table.hpp"
#include "SE.hpp"
#include "key.hpp"
#include "BuiltIn.hpp"
#include "p5_types.hpp"
#include "model_intf_1027.h"
#include "generated_gtv.hpp"
#include "packet.hpp"

class Switch : public GtvContext, public BuiltInContext, public Packet {
public:
    Switch();

    void iprs();
    void eprs();
    void parse_ETHER();
    void parse_VlanTag();
    void parse_IPv4();
    void parse_IPv6();
    void parse_TCP();
    void parse_UDP();

    IPATFull_S IpatLookup(p5::uint_ref<2> Status);
    void iMA0Action(IPATFull_S rsIpat, p5::uint<2> IpatStatus);
    FIBFull_S FibLookup(p5::uint_ref<2> Status);
    void iMA1Action(FIBFull_S rsFib);

    void pre_iMAControl();
    void iMA0Control();
    void iMA1Control();
    void ingress();

    // IPAT lookup table wrapper
    class IPAT_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IPAT_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        p5::uint<2> IpatStatus;
        IPATFull_S rsIpat;

        void apply() override {
            switch (ctx.PHI.PortType.to_ullong())
            {
                case PORT_TYPE_ETH:
                {
                    ctx.buildKey(ctx.GLSP);
                    break;
                }
                default:
                {
                    break;
                }
            }
            rsIpat = ctx.IpatLookup(IpatStatus);
        }
    };

    class IMA0_MATCH_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IMA0_MATCH_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        IPAT_TBL tbIPAT = IPAT_TBL(ctx);

        void apply() override {
            tbIPAT.apply();
        }
    };

    class IMA0_ACTION_TBL : public Table {
    private:
        Switch &ctx;
        IMA0_MATCH_TBL &tbIMA0Match;

    public:
        explicit IMA0_ACTION_TBL(Switch &ctx_in, IMA0_MATCH_TBL &tbIMA0Match_in) : ctx(ctx_in), tbIMA0Match(tbIMA0Match_in) {}

        void apply() override {
            ctx.iMA0Action(tbIMA0Match.tbIPAT.rsIpat, tbIMA0Match.tbIPAT.IpatStatus);
        }
    };

    class FIB_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit FIB_TBL(Switch &ctx_in) : ctx(ctx_in) {}
    
        p5::uint<2> StatusFib;
        FIBFull_S rsFib;

        void apply() override {
            switch (ctx.PHI.L3Type.to_ullong()) 
            {
                case L3_TYPE_IPv4: 
                { 
                    ctx.buildKey(ctx.Vrf, ctx.IPv4.DIP, p5::uint<32>(0), p5::uint<32>(0), p5::uint<32>(0));
                    break;
                }
                case L3_TYPE_IPv6: 
                { 
                    ctx.buildKey(ctx.Vrf, ctx.IPv6.DIP);
                    break;
                }
                default: { 
                    break;
                }
            }
            rsFib = ctx.FibLookup(StatusFib);
        }
    };

    class IMA1_MATCH_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IMA1_MATCH_TBL(Switch &ctx_in) : ctx(ctx_in) {}    
        
        FIB_TBL tbFib = FIB_TBL(ctx);

        void apply() override {
            tbFib.apply();
        }
    };

    class IMA1_ACTION_TBL : public Table {
    private:
        Switch &ctx;
        IMA1_MATCH_TBL &tbIMA1Match;
    public:
        explicit IMA1_ACTION_TBL(Switch &ctx_in, IMA1_MATCH_TBL &tbIMA1Match_in) : ctx(ctx_in), tbIMA1Match(tbIMA1Match_in) {}

        void apply() override {
            ctx.iMA1Action(tbIMA1Match.tbFib.rsFib);
        }
    };

    class IPRS_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IPRS_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        void apply() override {
            ctx.iprs();
        }
    };

public:
    void PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, NhiDef &nhi_info, 
                    Cp2NpHeader &cp2np_hdr, const PktHeader &pkt_hdr, Prs2Ma0FvInfoDef &fv_info);
    void ImaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ima2IpmFvInfoDef &fv_out);
    void EmaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ema2EpmFvInfoDef &fv_out);
    void IpmProcPkt(const int port_id, const Ima2IpmFvInfoDef &fv_in, Np2NpHeader &np2np_hdr, 
                    Np2TmHeader &np2tm_hdr);
    void SingleMaProc(const int ma_id, const std::string &packet_id, const int port_id,
                      const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out);

    void reset_all_fields();

    SearchEngine &searchEngine() { return BuiltInContext::searchEngine(); }
    KeyManager &keyManager() { return BuiltInContext::keyManager(); }
};

#endif // GENERATED_MA_HPP