#ifndef GENERATED_GTV_HPP
#define GENERATED_GTV_HPP

#include <array>
#include <cstdint>
#include <vector>

#include "table.hpp"
#include "SE.hpp"
#include "key.hpp"
#include "BuiltIn.hpp"
#include "p5_types.hpp"
#include "model_intf_1027.h"

#include "generated_struct.hpp"

/****************************        Outer Headers           *********************************/
ETHER_S ETHER;
VLAN_TAG_S VLAN_TAG0;
ETHER_TYPE_S ETHER_TYPE;
IPv4_S IPv4;
IPv6_S IPv6;
UDP_S UDP;
TCP_S TCP;

/****************************              fv                *********************************/
PHI_S PHI;
p5::uint<7> PHO[5];
p5::uint<8> NGSFBuffer[64];
p5::uint<10> GLSP;
p5::uint<10> GLTP;
p5::uint<6> LLTP;
p5::uint<8> Vrf;
p5::uint<6> FQID;
p5::uint<14> PktLength;
p5::uint<1> DropFlag;
p5::uint<1> IsUc;
p5::uint<12> Mgid;
p5::uint<8> SB;
p5::uint<8> SP;
p5::uint<8> TB;
p5::uint<8> TP;
p5::uint<16> HashValue;
p5::uint<8> TOS;
p5::uint<8> TTL;
p5::uint<8> EncapIndex;
p5::uint<3> HubSpkGrp;
p5::uint<2> EncapProfile;

// 将 fv 字段压缩/解压为固定长度的字节数组，便于调试或跨模块传输
namespace {

    using FvPackedBuffer = std::array<uint8_t, FV_GTV_MAX_BYTE_NUM>;
    using PhiPackedBuffer = std::array<uint8_t, FV_PHI_BYTE_NUM>;
    using PhoPackedBuffer = std::array<uint8_t, FV_PHO_BYTE_NUM>;
    
    template <typename P5UInt>
    void append_bits(std::vector<bool> &bits, const P5UInt &value, std::size_t width) {
        uint64_t v = value.to_ullong();
        for (std::size_t i = 0; i < width; ++i) {
            const bool bit = (v >> (width - 1 - i)) & 0x1;
            bits.push_back(bit);
        }
    }
    
    template <typename Buffer, typename P5UInt>
    void assign_from_bits(const Buffer &buf, std::size_t &cursor, std::size_t width, P5UInt &target) {
        uint64_t v = 0;
        const std::size_t max_bits = buf.size() * 8;
        for (std::size_t i = 0; i < width; ++i) {
            // 在循环开始时检查边界，防止缓冲区越界
            if (cursor >= max_bits) {
                break;
            }
            const std::size_t byte_idx = cursor / 8;
            // 双重检查：确保 byte_idx 在有效范围内
            if (byte_idx >= buf.size()) {
                break;
            }
            const std::size_t bit_idx = 7 - (cursor % 8); // 高位在前
            const bool bit = (buf[byte_idx] >> bit_idx) & 0x1;
            v = (v << 1) | static_cast<uint64_t>(bit);
            ++cursor;
        }
        target = v;
    }
    
} // namespace

// 将 PHI 字段按声明顺序拼成 10 字节数组
PhiPackedBuffer pack_phi_to_bytes() {
    std::vector<bool> bits;
    bits.reserve(32);

    append_bits(bits, PHI.PortType, 4);
    append_bits(bits, PHI.L2Type, 2);
    append_bits(bits, PHI.TagType, 2);
    append_bits(bits, PHI.L3Type, 2);
    append_bits(bits, PHI.L4Type, 8);

    PhiPackedBuffer out{};
    for (std::size_t i = 0; i < bits.size() && i < out.size() * 8; ++i) {
        if (bits[i]) {
            const std::size_t byte_idx = i / 8;
            const std::size_t bit_idx = 7 - (i % 8);
            out[byte_idx] |= static_cast<uint8_t>(1u << bit_idx);
        }
    }
    return out;
}

// 从 10 字节数组按同样顺序解析回 PHI 字段
void unpack_phi_from_bytes(const PhiPackedBuffer &in) {
    std::size_t cursor = 0;

    assign_from_bits(in, cursor, 4, PHI.PortType);
    assign_from_bits(in, cursor, 2, PHI.L2Type);
    assign_from_bits(in, cursor, 2, PHI.TagType);
    assign_from_bits(in, cursor, 2, PHI.L3Type);
    assign_from_bits(in, cursor, 8, PHI.L4Type);
}

// 将 PHO[5] (每个 7bit) 按顺序拼成 32 字节数组
PhoPackedBuffer pack_pho_to_bytes() {
    std::vector<bool> bits;
    bits.reserve(40);

    for (const auto &v : PHO) {
        append_bits(bits, v, 7);
    }

    PhoPackedBuffer out{};
    for (std::size_t i = 0; i < bits.size() && i < out.size() * 8; ++i) {
        if (bits[i]) {
            const std::size_t byte_idx = i / 8;
            const std::size_t bit_idx = 7 - (i % 8);
            out[byte_idx] |= static_cast<uint8_t>(1u << bit_idx);
        }
    }
    return out;
}

// 从 32 字节数组解析回 PHO[5]
void unpack_pho_from_bytes(const PhoPackedBuffer &in) {
    std::size_t cursor = 0;
    for (auto &v : PHO) {
        assign_from_bits(in, cursor, 7, v);
    }
}

// 按字段声明顺序将位拼接到字节数组（大端 bit 顺序）
FvPackedBuffer pack_fv_to_bytes() {
    std::vector<bool> bits;
    bits.reserve(200); // 当前仅用到 145bit，预留冗余

    append_bits(bits, GLSP, 10);
    append_bits(bits, GLTP, 10);
    append_bits(bits, LLTP, 6);
    append_bits(bits, Vrf, 8);
    append_bits(bits, FQID, 6);
    append_bits(bits, PktLength, 14);
    append_bits(bits, DropFlag, 1);
    append_bits(bits, IsUc, 1);
    append_bits(bits, Mgid, 12);
    append_bits(bits, SB, 8);
    append_bits(bits, SP, 8);
    append_bits(bits, TB, 8);
    append_bits(bits, TP, 8);
    append_bits(bits, HashValue, 16);
    append_bits(bits, TOS, 8);
    append_bits(bits, TTL, 8);
    append_bits(bits, EncapIndex, 8);
    append_bits(bits, HubSpkGrp, 3);
    append_bits(bits, EncapProfile, 2);

    FvPackedBuffer out{};
    for (std::size_t i = 0; i < bits.size() && i < out.size() * 8; ++i) {
        if (bits[i]) {
            const std::size_t byte_idx = i / 8;
            const std::size_t bit_idx = 7 - (i % 8); // 每个字节内同样高位在前
            out[byte_idx] |= static_cast<uint8_t>(1u << bit_idx);
        }
    }
    return out;
}

// 从字节数组按同样顺序解析出各个字段
void unpack_fv_from_bytes(const FvPackedBuffer &in) {
    std::size_t cursor = 0;

    assign_from_bits(in, cursor, 10, GLSP);
    assign_from_bits(in, cursor, 10, GLTP);
    assign_from_bits(in, cursor, 6, LLTP);
    assign_from_bits(in, cursor, 8, Vrf);
    assign_from_bits(in, cursor, 6, FQID);
    assign_from_bits(in, cursor, 14, PktLength);
    assign_from_bits(in, cursor, 1, DropFlag);
    assign_from_bits(in, cursor, 1, IsUc);
    assign_from_bits(in, cursor, 12, Mgid);
    assign_from_bits(in, cursor, 8, SB);
    assign_from_bits(in, cursor, 8, SP);
    assign_from_bits(in, cursor, 8, TB);
    assign_from_bits(in, cursor, 8, TP);
    assign_from_bits(in, cursor, 16, HashValue);
    assign_from_bits(in, cursor, 8, TOS);
    assign_from_bits(in, cursor, 8, TTL);
    assign_from_bits(in, cursor, 8, EncapIndex);
    assign_from_bits(in, cursor, 3, HubSpkGrp);
    assign_from_bits(in, cursor, 2, EncapProfile);
}

#endif // GENERATED_GTV_HPP
