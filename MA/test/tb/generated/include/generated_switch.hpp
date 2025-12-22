#ifndef GENERATED_SWITCH_HPP
#define GENERATED_SWITCH_HPP

#include <cstring>
#include <string>

#include "SE.hpp"
#include "key.hpp"
#include "model_intf_1027.h"
#include "generated_MA.hpp"
#include "../src/generated_MA.cpp" // unity-style include to provide definitions

// 顶层 Switch 封装：持有 SearchEngine / KeyManager 以及 Ingress 实例
class GeneratedSwitch {
public:
    GeneratedSwitch() : ingress_(se_, key_) {}

    SearchEngine &searchEngine() { return se_; }
    KeyManager &keyManager() { return key_; }
    Ingress &ingress() { return ingress_; }

    // 单个 MA 处理流程
    void SingleMaProc(const int ma_id, const std::string &packet_id, const int port_id,
                      const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out) {
        (void)packet_id; // 当前流程未使用
        (void)port_id;   // 当前流程未使用

        // 解包输入的 PHI / PHO / GTV
        Ingress::PhiPackedBuffer phiIn{};
        std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);
        ingress_.unpack_phi_from_bytes(phiIn);

        Ingress::PhoPackedBuffer phoIn{};
        std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);
        ingress_.unpack_pho_from_bytes(phoIn);

        Ingress::FvPackedBuffer gtvIn{};
        std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);
        ingress_.unpack_fv_from_bytes(gtvIn);

        // 按 ma_id 选择执行的控制流程
        if (ma_id == 0) {
            ingress_.iMA0Control();
        } else if (ma_id == 1) {
            ingress_.iMA1Control();
        }

        // 将最新的 PHI / PHO / GTV 打包写回输出 fv
        auto phiOut = ingress_.pack_phi_to_bytes();
        auto phoOut = ingress_.pack_pho_to_bytes();
        auto gtvOut = ingress_.pack_fv_to_bytes();

        std::memcpy(fv_out.phiData, phiOut.data(), FV_PHI_BYTE_NUM);
        std::memcpy(fv_out.phoData, phoOut.data(), FV_PHO_BYTE_NUM);
        std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);
    }

private:
    SearchEngine se_;
    KeyManager key_;
    Ingress ingress_;
};

#endif // GENERATED_SWITCH_HPP

