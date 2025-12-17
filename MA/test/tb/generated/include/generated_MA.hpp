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

void iMA0Control();

void ingress();

class IPAT_TBL : public Table {
public:
    p5::uint<2> IpatStatus;
    IPATFull_S rsIpat;

    IPAT_TBL() {}

    void apply() override {
        g_key.buildKey(GLSP);
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

#endif // GENERATED_MA_HPP