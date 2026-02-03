// 手写测试：专门验证 IPM 接口 IpmProcPkt 的解包、IPM 控制、以及 NGSF 分段打包逻辑
#include <cstdint>
#include <cstring>
#include <iostream>
 
#include "generated_switch.hpp"
 
namespace {
 
bool expect_eq_u8(uint8_t got, uint8_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=0x" << std::hex << static_cast<int>(got)
              << " expect=0x" << static_cast<int>(expect) << std::dec << "\n";
    return false;
}
 
bool expect_all_zero(const uint8_t *buf, std::size_t off, std::size_t len, const char *msg) {
    for (std::size_t i = 0; i < len; ++i) {
        if (buf[off + i] != 0) {
            std::cerr << "[FAIL] " << msg << " nonzero at +" << i << " val=0x" << std::hex
                      << static_cast<int>(buf[off + i]) << std::dec << "\n";
            return false;
        }
    }
    return true;
}
 
Ima2IpmFvInfoDef build_ipm_fv_in_from_fields(const Switch &swFields) {
    Ima2IpmFvInfoDef fv{};
    auto gtv = swFields.pack_gtv_to_bytes();
    std::memcpy(fv.gtvData, gtv.data(), FV_GTV_MAX_BYTE_NUM);
    std::memcpy(fv.pgtvData, gtv.data() + FV_GTV_MAX_BYTE_NUM, FV_PGTV_BYTE_NUM);
    return fv;
}
 
} // namespace
 
int main() {
    std::cout << "[ipm test] start\n";
 
    bool all_ok = true;
 
    // 1) 构造输入 fv：只依赖 GTV 里的 fv 字段（DropFlag/IsUc/Mgid/HashValue/HubSpkGrp/TOS）
    Switch swFields{};
    swFields.reset_all_fields();
 
    // 走 IsUc==0 的分支（TM: DropFlag + Mgid；NP: IsUc/tmpSB/tmpSP/HashLow + Mgid + HubSpkGrp + Hash[9:8] + TOS）
    swFields.DropFlag = p5::uint<1>(1);
    swFields.IsUc = p5::uint<1>(0);
    swFields.Mgid = p5::uint<12>(0xABC);         // 1010 1011 1100
    swFields.HashValue = p5::uint<16>(0x1234);   // low8=0x34, [9:8]=0b10
    swFields.HubSpkGrp = p5::uint<3>(5);         // 101
    swFields.TOS = p5::uint<8>(0x5A);            // 0101 1010
 
    Ima2IpmFvInfoDef fv_in = build_ipm_fv_in_from_fields(swFields);
 
    // 2) 调用 IPM 接口
    Switch sw{};
    Np2NpHeader np2np{};
    Np2TmHeader np2tm{};
    std::memset(&np2np, 0, sizeof(np2np));
    std::memset(&np2tm, 0, sizeof(np2tm));
 
    sw.IpmProcPkt(0, fv_in, np2np, np2tm);
 
    // 3) 校验输出分段（只校验前几个字节，剩余应为 0）
    //
    // TM 段（13 bits）：DropFlag(1) + Mgid(12=0xABC)
    // bitstream = 1 101010111100 => 0xD5 0xE0 ...
    all_ok &= expect_eq_u8(np2tm.pkt_data[0], 0xD5, "tm byte0");
    all_ok &= expect_eq_u8(np2tm.pkt_data[1], 0xE0, "tm byte1 (upper 5 bits used)");
    all_ok &= expect_all_zero(np2tm.pkt_data, 2, PKT_HEADER_BYTE_LEN - 2, "tm remaining bytes are zero");
 
    // NP 段从 TM 分界开始（按我们的 pack 规则，NP 段从 byte0 MSB 开始）
    // NP bitstream:
    //   IsUc(0) + tmpSB(0) + tmpSP(0) + HashLow(0x34) + Mgid(0xABC) + Hub(101) + Hash[9:8](10) + TOS(0x5A)
    // 预期前 7 字节：00 00 1A 55 E5 96 80
    all_ok &= expect_eq_u8(np2np.pkt_data[0], 0x00, "np byte0");
    all_ok &= expect_eq_u8(np2np.pkt_data[1], 0x00, "np byte1");
    all_ok &= expect_eq_u8(np2np.pkt_data[2], 0x1A, "np byte2");
    all_ok &= expect_eq_u8(np2np.pkt_data[3], 0x55, "np byte3");
    all_ok &= expect_eq_u8(np2np.pkt_data[4], 0xE5, "np byte4");
    all_ok &= expect_eq_u8(np2np.pkt_data[5], 0x96, "np byte5");
    all_ok &= expect_eq_u8(np2np.pkt_data[6], 0x80, "np byte6 (only top 2 bits used)");
    all_ok &= expect_all_zero(np2np.pkt_data, 7, PKT_HEADER_BYTE_LEN - 7, "np remaining bytes are zero");
 
    std::cout << "[ipm test] " << (all_ok ? "ALL PASS" : "FAILED") << "\n";
    return all_ok ? 0 : 1;
}
