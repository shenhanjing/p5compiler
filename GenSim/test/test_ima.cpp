// 手写测试：演示 SingleMaProc 的查表、打包/解包流程
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>
#include "generated_switch.hpp"

namespace {

// 预置一些全局字段的基准值，方便复用
void set_common_fields(Switch &sw) {
    sw.PHI.PortType = 0;
    sw.PHI.L2Type = 2;
    sw.PHI.TagType = 1;
    sw.PHI.L4Type = 10; // TCP

    for (int i = 0; i < 5; ++i) {
        sw.PHO[i] = static_cast<uint8_t>(i + 1);
    }

    sw.GLTP = 200;
    sw.LLTP = 15;
    sw.FQID = 12;
    sw.PktLength = 1500;
    sw.DropFlag = 0;
    sw.IsUc = 0;
    sw.Mgid = 55;
    sw.SB = 10;
    sw.SP = 11;
    sw.TB = 12;
    sw.TP = 13;
    sw.HashValue = 0xABCD;
    sw.TOS = 0x10;
    sw.TTL = 64;
    sw.EncapIndex = 2;
    sw.HubSpkGrp = 5;
    sw.EncapProfile = 1;
}

// 构造 IPv4 FIB 查表 key（Vrf + DIP + 3 个 32bit 0 填充）
// 位序为高位在前，符合 KeyManager/pack 函数的约定
p5::uint<136> make_fib_key_v4(uint8_t vrf, uint32_t dip) {
    std::vector<bool> bits;
    bits.reserve(136);

    // Vrf: 8bit
    for (int i = 7; i >= 0; --i) bits.push_back((vrf >> i) & 1);
    // DIP: 32bit
    for (int i = 31; i >= 0; --i) bits.push_back((dip >> i) & 1);
    // 3 * 32bit padding zeros
    for (int i = 0; i < 96; ++i) bits.push_back(false);

    return p5::uint<136>::from_bits(bits);
}

// 根据当前全局字段打包 fv_in
MaToMaFvInfoDef build_fv_in(Switch &sw) {
    MaToMaFvInfoDef fv{};
    auto phi_buf = sw.pack_phi_to_bytes();
    auto pho_buf = sw.pack_pho_to_bytes();
    auto gtv_buf = sw.pack_gtv_to_bytes();
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

    Switch sw;
    auto &se = sw.searchEngine();
    auto &key = sw.keyManager();

    // 初始化查表与 key，匹配 generated.hpp 中 iMA0Control/iMA1Control 的逻辑
    se.initTable<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, MatchType::INDEX);
    se.initTable<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, MatchType::LPM);
    key.initKey({10, 136});

    // 配置两条 IPAT 表项：GLSP=10/20 命中，Vrf 分别为 100/200
    se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, 10, IPATRSP_S{1, 0, 0, 100, {}});
    se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, 20, IPATRSP_S{1, 0, 0, 200, {}});

    // 配置 FIB LPM 表项（基于 Vrf + IPv4 DIP）
    // /32: vrf=100, dip=10.0.0.1 -> port=25, encap=3
    auto fib_key_v4_host = make_fib_key_v4(100, 0x0A000001);
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, fib_key_v4_host, FIBRSP_S{25, 3}, 8 + 32);
    // /16: vrf=200, dip=10.1.0.0 -> port=55, encap=9
    auto fib_key_v4_subnet = make_fib_key_v4(200, 0x0A010000);
    se.config<p5::uint<136>, FIBRSP_S>(SE_TID_FIB, fib_key_v4_subnet, FIBRSP_S{55, 9}, 8 + 16);

    std::vector<CaseCfg> cases = {
    //    name,           glsp,     l3_type,    expect_drop, expect_vrf
        {"hit-ipv4-valid", 10,   L3_TYPE_IPv4,     false,      100},
        {"hit-ipv6-valid", 10,   L3_TYPE_IPv6,     false,      100},
        {"hit-vrf-200",    20,   L3_TYPE_IPv4,     false,      200},
        {"miss-no-entry",  30,   L3_TYPE_IPv4,     true,       0},
        {"non-ip",         10,   L3_TYPE_NON_IP,   true,       0},
    };

    bool all_pass = true;

    // -------- ma_id = 0 测试（已有）--------
    for (const auto &c : cases) {
        set_common_fields(sw);
        sw.GLSP = c.glsp;
        sw.PHI.L3Type = c.l3_type;
        sw.Vrf = 0;
        sw.DropFlag = 0;
        sw.IsUc = 0;

        MaToMaFvInfoDef fv_in = build_fv_in(sw);
        MaToMaFvInfoDef fv_out{};

        sw.SingleMaProc(0, "", 0, fv_in, fv_out);

        bool drop_ok = (sw.DropFlag.to_ullong() == static_cast<uint64_t>(c.expect_drop));
        bool vrf_ok = (!c.expect_drop) ? (sw.Vrf.to_ullong() == c.expect_vrf) : true;
        bool isuc_ok = (!c.expect_drop) ? (sw.IsUc.to_ullong() == 1) : true;

        bool pack_phi_ok = std::memcmp(fv_out.phiData, fv_in.phiData, FV_PHI_BYTE_NUM) == 0;
        bool pack_pho_ok = std::memcmp(fv_out.phoData, fv_in.phoData, FV_PHO_BYTE_NUM) == 0;
        // gtv_data 经过 iMA0Control 后会写入新的 Vrf/DropFlag/IsUc，无法与输入直接比对

        bool pass = drop_ok && vrf_ok && isuc_ok && pack_phi_ok && pack_pho_ok;
        all_pass = all_pass && pass;

        std::cout << c.name
                  << " => drop=" << sw.DropFlag.to_ullong()
                  << " vrf=" << sw.Vrf.to_ullong()
                  << " isUc=" << sw.IsUc.to_ullong()
                  << " pack_phi=" << (pack_phi_ok ? "OK" : "BAD")
                  << " pack_pho=" << (pack_pho_ok ? "OK" : "BAD")
                  << " => " << (pass ? "PASS" : "FAIL") << "\n";
    }

    // -------- ma_id = 1 测试（新增 FIB LPM）--------
    struct Ma1Case {
        std::string name;
        uint8_t vrf;
        uint32_t dip;
        uint8_t l3_type;
        bool expect_hit;
        uint16_t expect_port;
        uint8_t expect_encap;
    };

    std::vector<Ma1Case> ma1_cases = {
        // name, vrf, dip(u32), l3_type, expect_hit, expect_port, expect_encap
        {"fib-hit-v4-host",   100, 0x0A000001, L3_TYPE_IPv4, true, 25, 3}, // 10.0.0.1 (/32)
        {"fib-hit-v4-subnet", 200, 0x0A010203, L3_TYPE_IPv4, true, 55, 9}, // 10.1.2.3 (/16 match on 10.1.0.0)
        {"fib-miss-v4",       100, 0x0B000001, L3_TYPE_IPv4, false, 0, 0}, // 11.0.0.1 (no route)
    };

    for (const auto &c : ma1_cases) {
        set_common_fields(sw);
        // 只跑 MA1，这里不依赖 IPAT，直接设置 Vrf/DIP
        sw.Vrf = c.vrf;
        sw.PHI.L3Type = c.l3_type;
        sw.IPv4.DIP = c.dip;
        sw.GLTP = 0;
        sw.EncapIndex = 0;
        sw.TTL = 64;

        MaToMaFvInfoDef fv_in = build_fv_in(sw);
        MaToMaFvInfoDef fv_out{};

        sw.SingleMaProc(1, "", 0, fv_in, fv_out);

        const bool hit = (se.status(SE_TID_FIB) == SearchEngine::Status::MATCH);
        const bool port_ok = c.expect_hit ? (sw.GLTP.to_ullong() == c.expect_port) : (sw.GLTP.to_ullong() == 0);
        const bool encap_ok = c.expect_hit ? (sw.EncapIndex.to_ullong() == c.expect_encap) : (sw.EncapIndex.to_ullong() == 0);
        const bool ttl_ok = c.expect_hit ? (sw.TTL.to_ullong() == 63) : (sw.TTL.to_ullong() == 64);

        bool pass = (hit == c.expect_hit) && port_ok && encap_ok && ttl_ok;
        all_pass = all_pass && pass;

        std::cout << c.name
                  << " => hit=" << hit
                  << " gltp=" << sw.GLTP.to_ullong()
                  << " encap=" << sw.EncapIndex.to_ullong()
                  << " ttl=" << sw.TTL.to_ullong()
                  << " => " << (pass ? "PASS" : "FAIL") << "\n";
    }

    std::cout << "[tb_2 hand] summary: " << (all_pass ? "ALL PASS" : "FAILED") << "\n";
    return all_pass ? 0 : 1;
}

