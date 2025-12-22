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

IPATFull_S IpatLookup(p5::uint<2> &Status);

void iMA0Action(IPATFull_S rsIpat, p5::uint<2> IpatStatus);

FIBFull_S FibLookup(p5::uint<2> &Status);

void iMA1Action(FIBFull_S rsFib);

void iMA0Control();

void iMA1Control();

void ingress();

class IPAT_TBL : public Table {
public:
    p5::uint<2> IpatStatus;
    IPATFull_S rsIpat;

    IPAT_TBL() {}

    void apply() override {
        switch (PHI.PortType.to_ullong())
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
    IPAT_TBL tbIPAT = IPAT_TBL();

    IMA0_MATCH_TBL() {}

    void apply() override {
        tbIPAT.apply();
    }
};

class IMA0_ACTION_TBL : public Table {
public:
    IMA0_MATCH_TBL &tbIMA0Match;

    explicit IMA0_ACTION_TBL(IMA0_MATCH_TBL &tbIMA0Match_in) : tbIMA0Match(tbIMA0Match_in) {}

    void apply() override {
        iMA0Action(tbIMA0Match.tbIPAT.rsIpat, tbIMA0Match.tbIPAT.IpatStatus);
    }
};

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

class IMA1_ACTION_TBL : public Table {
public:
    IMA1_MATCH_TBL &tbIMA1Match;

    explicit IMA1_ACTION_TBL(IMA1_MATCH_TBL &tbIMA1Match_in) : tbIMA1Match(tbIMA1Match_in) {}

    void apply() override {
        iMA1Action(tbIMA1Match.tbFib.rsFib);
    }
};

#endif // GENERATED_MA_HPP