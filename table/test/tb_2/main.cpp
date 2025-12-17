// 手写测试：演示 SingleMaProc 的查表、打包/解包流程
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>
#include "generated_MA.hpp"

namespace {

// 预置一些全局字段的基准值，方便复用
void set_common_fields() {
    PHI.PortType = 1;
    PHI.L2Type = 2;
    PHI.TagType = 1;
    PHI.L4Type = 10; // TCP

    for (int i = 0; i < 5; ++i) {
        PHO[i] = static_cast<uint8_t>(i + 1);
    }

    GLTP = 200;
    LLTP = 15;
    FQID = 12;
    PktLength = 1500;
    DropFlag = 0;
    IsUc = 0;
    Mgid = 55;
    SB = 10;
    SP = 11;
    TB = 12;
    TP = 13;
    HashValue = 0xABCD;
    TOS = 0x10;
    TTL = 64;
    EncapIndex = 2;
    HubSpkGrp = 5;
    EncapProfile = 1;
}

// 根据当前全局字段打包 fv_in
MaToMaFvInfoDef build_fv_in() {
    MaToMaFvInfoDef fv{};
    auto phi_buf = pack_phi_to_bytes();
    auto pho_buf = pack_pho_to_bytes();
    auto gtv_buf = pack_fv_to_bytes();
    std::memcpy(fv.phiData, phi_buf.data(), FV_PHI_BYTE_NUM);
    std::memcpy(fv.phoData, pho_buf.data(), FV_PHO_BYTE_NUM);
    std::memcpy(fv.gtvData, gtv_buf.data(), FV_GTV_MAX_BYTE_NUM);
    return fv;
}

struct CaseCfg {
    std::string name;
    uint16_t glsp;
    uint8_t l3_type;   // 2=IPv4, 3=IPv6, others => non-IP
    bool expect_drop;
    uint8_t expect_vrf;
};

} // namespace

int main() {
    std::cout << "[tb_2 hand] SingleMaProc table + pack/unpack tests\n";

    // 初始化查表与 key，匹配 generated.hpp 中 iMA0Control 的逻辑
    g_se.initTable<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, MatchType::INDEX);
    g_key.initKey({10});

    // 配置两条 IPAT 表项：GLSP=10/20 命中，Vrf 分别为 100/200
    g_se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, 10, IPATRSP_S{1, 0, 0, 100, {}});
    g_se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, 20, IPATRSP_S{1, 0, 0, 200, {}});

    std::vector<CaseCfg> cases = {
        {"hit-ipv4-valid", 10, L3_TYPE_IPv4, false, 100},
        {"hit-ipv6-valid", 10, L3_TYPE_IPv6, false, 100},
        {"hit-vrf-200", 20, L3_TYPE_IPv4, false, 200},
        {"miss-no-entry", 30, L3_TYPE_IPv4, true, 0},
        {"non-ip", 10, L3_TYPE_NON_IP, true, 0},
    };

    bool all_pass = true;
    for (const auto &c : cases) {
        set_common_fields();
        GLSP = c.glsp;
        PHI.L3Type = c.l3_type;
        Vrf = 0;
        DropFlag = 0;
        IsUc = 0;

        MaToMaFvInfoDef fv_in = build_fv_in();
        MaToMaFvInfoDef fv_out{};

        SingleMaProc(0, "", 0, fv_in, fv_out);

        bool drop_ok = (DropFlag.to_ullong() == static_cast<uint64_t>(c.expect_drop));
        bool vrf_ok = (!c.expect_drop) ? (Vrf.to_ullong() == c.expect_vrf) : true;
        bool isuc_ok = (!c.expect_drop) ? (IsUc.to_ullong() == 1) : true;

        bool pack_phi_ok = std::memcmp(fv_out.phiData, fv_in.phiData, FV_PHI_BYTE_NUM) == 0;
        bool pack_pho_ok = std::memcmp(fv_out.phoData, fv_in.phoData, FV_PHO_BYTE_NUM) == 0;
        // gtv_data 经过 iMA0Control 后会写入新的 Vrf/DropFlag/IsUc，无法与输入直接比对

        bool pass = drop_ok && vrf_ok && isuc_ok && pack_phi_ok && pack_pho_ok;
        all_pass = all_pass && pass;

        std::cout << c.name
                  << " => drop=" << DropFlag.to_ullong()
                  << " vrf=" << Vrf.to_ullong()
                  << " isUc=" << IsUc.to_ullong()
                  << " pack_phi=" << (pack_phi_ok ? "OK" : "BAD")
                  << " pack_pho=" << (pack_pho_ok ? "OK" : "BAD")
                  << " => " << (pass ? "PASS" : "FAIL") << "\n";
    }

    std::cout << "[tb_2 hand] summary: " << (all_pass ? "ALL PASS" : "FAILED") << "\n";
    return all_pass ? 0 : 1;
}

