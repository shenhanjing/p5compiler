#include <cstdint>
#include <optional>
#include <limits>
#include <iostream>
#include "table.hpp"
#include "SE.hpp"
#include "key.hpp"
// Built-in helpers (inflate, key/status, lookup, memcpy, bit width)
#include "BuiltIn.hpp"

// --- Types translated from trial_0.p5 ---
enum SE_TID_E {
    SE_TID_LU = 0
};

enum TLB_LKUP_TYPE_E {
    TBL_LKUP_TYPE_INDEX = 0,
    TBL_LKUP_TYPE_EM = 1,
    TBL_LKUP_TYPE_LPM = 3,
    TBL_LKUP_TYPE_TCAM = 4
};

enum RSP_STATUS_E {
    RSP_STATUS_MATCH = 0,
    RSP_STATUS_NO_MATCH = 1,
    RSP_STATUS_LOOKUP_SKIPPED = 2,
    RSP_STATUS_ERROR = 3
};

// Global variables declared in the P5 snippet.
p5::uint<1> SEL;
p5::uint<10> KE0;
p5::uint<1> DropFlag;
p5::uint<2> RSP;

struct LuCtrlInfo_S {
    p5::uint<1> ForwardEn;
};

struct LURSP_S {
    p5::uint<1> Rsp_0;
    p5::uint<2> Rsp_1;
};

using LUFull_S = _inflate<LURSP_S>;

// @lookup function
LUFull_S LuLookup(p5::uint<2> &Status) {
    p5::uint<10> Ke0;
    _inflate<LURSP_S> CompressedLuRsp = {0};
    _inflate<LURSP_S> Mem = {0};

    Ke0 = _key<decltype(KE0)>();

    Mem = _lookup<typename std::remove_reference_t<decltype(Mem)>::value_type>(
        SE_TID_LU, TBL_LKUP_TYPE_INDEX, Ke0);
    _memcpy(CompressedLuRsp, {Mem});
    Status = _status(SE_TID_LU);

    return CompressedLuRsp;
}

// --- Table subclasses ---
class LU_TBL : public Table {
public:
    p5::uint<2> LuStatus;
    LUFull_S rsLu{};

    void apply() override {
        g_key.buildKey(KE0);
        rsLu = LuLookup(LuStatus);
    }
};

class MATCH_TBL : public Table {
public:
    LU_TBL tbLU{};

    void apply() override {
        tbLU.apply();
    }
};

// Mirrors Action(rsLu, LuStatus) in trial_0.p5
void Action(LUFull_S rsLu, p5::uint<2> LuStatus) {

    if (_valid(rsLu)) {
        RSP = rsLu.Rsp_1;
    } else {
        DropFlag = 1;
    }
}

class ACTION_TBL : public Table {
public:
    MATCH_TBL *tbMatch = nullptr;

    explicit ACTION_TBL(MATCH_TBL &match) : tbMatch(&match) {}

    void apply() override {
        Action(tbMatch->tbLU.rsLu, tbMatch->tbLU.LuStatus);
    }
};

// Control block equivalent
void Control() {
    MATCH_TBL tbMatch;
    ACTION_TBL tbAction(tbMatch);

    tbMatch.apply();
    tbAction.apply();
}

int main() {
    auto statusToStr = [](SearchEngine::Status s) {
        switch (s) {
            case SearchEngine::Status::MATCH: return "MATCH";
            case SearchEngine::Status::NO_MATCH: return "NO_MATCH";
            case SearchEngine::Status::LOOKUP_SKIPPED: return "LOOKUP_SKIPPED";
            case SearchEngine::Status::ERROR: return "ERROR";
        }
        return "UNKNOWN";
    };

    std::cout << "[trial_0_hand test] start\n";

    // Initialize and configure search engine and key manager.
    g_se.initTable<p5::uint<10>, LURSP_S>(SE_TID_LU, MatchType::INDEX);
    g_key.initKey({10});

    // Configure table entries
    // key=0 => {Rsp_0=1, Rsp_1=2}
    g_se.config<p5::uint<10>, LURSP_S>(SE_TID_LU, 0, LURSP_S{1, 2});
    // key=2 => {Rsp_0=1, Rsp_1=3} (fits in uint<2>)
    g_se.config<p5::uint<10>, LURSP_S>(SE_TID_LU, 2, LURSP_S{1, 3});

    // Test case 1: hit
    KE0 = 0;
    RSP = 0;
    DropFlag = 0;
    Control();
    auto st1 = g_se.status(SE_TID_LU);
    bool pass1 = (st1 == SearchEngine::Status::MATCH) && (DropFlag == 0) && (RSP == 2);
    std::cout << "Case1 (hit): status=" << statusToStr(st1)
              << " RSP=" << static_cast<int>(RSP.to_ullong())
              << " DropFlag=" << static_cast<int>(DropFlag.to_ullong())
              << " => " << (pass1 ? "PASS" : "FAIL") << "\n";

    // Test case 2: another hit
    KE0 = 2;
    RSP = 0;
    DropFlag = 0;
    Control();
    auto st2 = g_se.status(SE_TID_LU);
    bool pass2 = (st2 == SearchEngine::Status::MATCH) && (DropFlag == 0) && (RSP == 3);
    std::cout << "Case2 (hit): status=" << statusToStr(st2)
              << " RSP=" << static_cast<int>(RSP.to_ullong())
              << " DropFlag=" << static_cast<int>(DropFlag.to_ullong())
              << " => " << (pass2 ? "PASS" : "FAIL") << "\n";

    // Test case 3: miss
    KE0 = 99;          // key not configured
    RSP = 0;
    DropFlag = 0;
    Control();
    auto st3 = g_se.status(SE_TID_LU);
    bool pass3 = (st3 == SearchEngine::Status::NO_MATCH) && (DropFlag == 1);
    std::cout << "Case3 (miss): status=" << statusToStr(st3)
              << " RSP=" << static_cast<int>(RSP.to_ullong())
              << " DropFlag=" << static_cast<int>(DropFlag.to_ullong())
              << " => " << (pass3 ? "PASS" : "FAIL") << "\n";

    bool allPass = pass1 && pass2 && pass3;
    std::cout << "[trial_0_hand test] result: " << (allPass ? "ALL PASS" : "FAILED") << "\n";

    return allPass ? 0 : 1;
}
