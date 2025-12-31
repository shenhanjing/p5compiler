#ifndef GENERATED_SWITCH_HPP
#define GENERATED_SWITCH_HPP

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
    EPATFull_S EpatLookup(p5::uint_ref<2> Status);
    ENCAPFull_S EncapLookup(p5::uint_ref<2> Status);
    void eMA0Action(EPATFull_S rsEpat, ENCAPFull_S rsEncap);
    void EthODma(EPATFull_S rsEpat, ENCAPFull_S rsEncap);
    void IpOverwrite();
    void eMA0_HmProc(EPATFull_S rsEpat, ENCAPFull_S rsEncap);
    void pre_eMAControl();
    void eMA0Control();
    void egress();
    class IPAT_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IPAT_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        p5::uint<2> IpatStatus;
        IPATFull_S rsIpat;

        void apply() override {
            auto _KeyBuilder = ctx.keyBuilder();
            bool _BuiltKey = true;
            switch (ctx.PHI.PortType.to_ullong()) {
                case PORT_TYPE_ETH: {
                    _KeyBuilder.append(ctx.GLSP);
                    break;
                }
                case PORT_TYPE_CPU: {
                    _BuiltKey = false;
                    break;
                }
                case PORT_TYPE_STACK: {
                    _BuiltKey = false;
                    break;
                }
                default: {
                    _BuiltKey = false;
                    break;
                }
            }
            if (_BuiltKey) {
                _KeyBuilder.commit();
            }

            IpatStatus = _status();
            rsIpat = ctx.IpatLookup(IpatStatus);
        }
    };

    class IMA0_MATCH_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IMA0_MATCH_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        IPAT_TBL tbIPAT;

        void apply() override {
            tbIPAT = IPAT_TBL(ctx);
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
            auto _KeyBuilder = ctx.keyBuilder();
            bool _BuiltKey = true;
            switch (ctx.PHI.L3Type.to_ullong()) {
                case L3_TYPE_IPv4: {
                    _KeyBuilder.append(ctx.Vrf);
                    _KeyBuilder.append(ctx.IPv4.DIP);
                    _KeyBuilder.append((p5::uint<32>)0);
                    _KeyBuilder.append((p5::uint<32>)0);
                    _KeyBuilder.append((p5::uint<32>)0);
                    break;
                }
                case L3_TYPE_IPv6: {
                    _KeyBuilder.append(ctx.Vrf);
                    _KeyBuilder.append(ctx.IPv6.DIP);
                    break;
                }
                case L3_TYPE_NON_IP: {
                    _BuiltKey = false;
                    break;
                }
                case L3_TYPE_INVALID: {
                    _BuiltKey = false;
                    break;
                }
                default: {
                    _BuiltKey = false;
                    break;
                }
            }
            if (_BuiltKey) {
                _KeyBuilder.commit();
            }

            StatusFib = _status();
            rsFib = ctx.FibLookup(StatusFib);
        }
    };

    class IMA1_MATCH_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit IMA1_MATCH_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        FIB_TBL tbFib;

        void apply() override {
            tbFib = FIB_TBL(ctx);
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

    class EPAT_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit EPAT_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        p5::uint<2> EpatStatus;
        EPATFull_S rsEpat;

        void apply() override {
            auto _KeyBuilder = ctx.keyBuilder();
            bool _BuiltKey = true;
            switch (ctx.PHI.PortType.to_ullong()) {
                case PORT_TYPE_ETH: {
                    _KeyBuilder.append(ctx.GLTP);
                    break;
                }
                default: {
                    _BuiltKey = false;
                    break;
                }
            }
            if (_BuiltKey) {
                _KeyBuilder.commit();
            }

            EpatStatus = _status();
            rsEpat = ctx.EpatLookup(EpatStatus);
        }
    };

    class ENCAP_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit ENCAP_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        p5::uint<2> EncapStatus;
        ENCAPFull_S rsEncap;

        void apply() override {
            auto _KeyBuilder = ctx.keyBuilder();
            bool _BuiltKey = true;
            switch (ctx.PHI.PortType.to_ullong()) {
                case PORT_TYPE_ETH: {
                    _KeyBuilder.append(ctx.EncapIndex);
                    break;
                }
                default: {
                    _BuiltKey = false;
                    break;
                }
            }
            if (_BuiltKey) {
                _KeyBuilder.commit();
            }

            EncapStatus = _status();
            rsEncap = ctx.EncapLookup(EncapStatus);
        }
    };

    class EMA0_MATCH_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit EMA0_MATCH_TBL(Switch &ctx_in) : ctx(ctx_in) {}

        EPAT_TBL tbEPAT;
        ENCAP_TBL tbEncap;

        void apply() override {
            tbEPAT = EPAT_TBL(ctx);
            tbEncap = ENCAP_TBL(ctx);
            tbEPAT.apply();
            tbEncap.apply();
        }
    };

    class EMA0_ACTION_TBL : public Table {
    private:
        Switch &ctx;
        EMA0_MATCH_TBL &tbEMA0Match;
    public:
        explicit EMA0_ACTION_TBL(Switch &ctx_in, EMA0_MATCH_TBL &tbEMA0Match_in) : ctx(ctx_in), tbEMA0Match(tbEMA0Match_in) {}


        void apply() override {
            ctx.eMA0Action(tbEMA0Match.tbEPAT.rsEpat, tbEMA0Match.tbEncap.rsEncap);
        }
    };

    class EMA0_HM_TBL : public Table {
    private:
        Switch &ctx;
        EMA0_MATCH_TBL &tbEMA0Match;
    public:
        explicit EMA0_HM_TBL(Switch &ctx_in, EMA0_MATCH_TBL &tbEMA0Match_in) : ctx(ctx_in), tbEMA0Match(tbEMA0Match_in) {}


        void apply() override {
            ctx.eMA0_HmProc(tbEMA0Match.tbEPAT.rsEpat, tbEMA0Match.tbEncap.rsEncap);
        }
    };

    class EPRS_TBL : public Table {
    private:
        Switch &ctx;
    public:
        explicit EPRS_TBL(Switch &ctx_in) : ctx(ctx_in) {}


        void apply() override {
            ctx.eprs();
        }
    };

public:
    void PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, NhiDef &nhi_info, Cp2NpHeader &cp2np_hdr, const PktHeader &pkt_hdr, Prs2Ma0FvInfoDef &fv_info);
    void ImaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ima2IpmFvInfoDef &fv_out);
    void EmaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ema2EpmFvInfoDef &fv_out);
    void IpmProcPkt(const int port_id, const Ima2IpmFvInfoDef &fv_in, Np2NpHeader &np2np_hdr, Np2TmHeader &np2tm_hdr);
    void SingleMaProc(const int ma_id, const std::string &packet_id, const int port_id, const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out);

    void reset_all_fields();

    SearchEngine &searchEngine() { return BuiltInContext::searchEngine(); }
    KeyManager &keyManager() { return BuiltInContext::keyManager(); }

};

#endif // GENERATED_SWITCH_HPP
