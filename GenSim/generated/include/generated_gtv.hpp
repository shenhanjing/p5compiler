#ifndef GENERATED_GTV_HPP
#define GENERATED_GTV_HPP

#include <array>
#include <cstdint>
#include <type_traits>
#include <vector>

#include "table.hpp"
#include "SE.hpp"
#include "key.hpp"
#include "BuiltIn.hpp"
#include "p5_types.hpp"
#include "model_intf_1027.h"

#include "generated_struct.hpp"

// GTV 容器：封装外层头部解析字段和 fv 字段，并提供 pack/unpack
class GtvContext {
public:
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

    using GtvPackedBuffer = std::array<uint8_t, FV_GTV_MAX_BYTE_NUM>;
    using PhiPackedBuffer = std::array<uint8_t, FV_PHI_BYTE_NUM>;
    using PhoPackedBuffer = std::array<uint8_t, FV_PHO_BYTE_NUM>;

    // 将 PHI 字段按声明顺序拼成 10 字节数组
    PhiPackedBuffer pack_phi_to_bytes() const {
        std::vector<bool> bits;
        bits.reserve(32);

        append_bits(bits, PHI.PortType);
        append_bits(bits, PHI.L2Type);
        append_bits(bits, PHI.TagType);
        append_bits(bits, PHI.L3Type);
        append_bits(bits, PHI.L4Type);

        PhiPackedBuffer out{};
        write_bits_to_buffer(bits, out);
        return out;
    }

    // 从 10 字节数组按同样顺序解析回 PHI 字段
    void unpack_phi_from_bytes(const PhiPackedBuffer &in) {
        std::size_t cursor = 0;

        assign_from_bits(in, cursor, PHI.PortType);
        assign_from_bits(in, cursor, PHI.L2Type);
        assign_from_bits(in, cursor, PHI.TagType);
        assign_from_bits(in, cursor, PHI.L3Type);
        assign_from_bits(in, cursor, PHI.L4Type);
    }

    // 将 PHO[5] (每个 7bit) 按顺序拼成 32 字节数组
    PhoPackedBuffer pack_pho_to_bytes() const {
        std::vector<bool> bits;
        bits.reserve(40);

        for (const auto &v : PHO) {
            append_bits(bits, v);
        }

        PhoPackedBuffer out{};
        write_bits_to_buffer(bits, out);
        return out;
    }

    // 从 32 字节数组解析回 PHO[5]
    void unpack_pho_from_bytes(const PhoPackedBuffer &in) {
        std::size_t cursor = 0;
        for (auto &v : PHO) {
            assign_from_bits(in, cursor, v);
        }
    }

    // 按字段声明顺序将位拼接到字节数组（大端 bit 顺序）
    GtvPackedBuffer pack_gtv_to_bytes() const {
        std::vector<bool> bits;
        bits.reserve(1200); // 外层头部 + fv

        // outer headers
        append_bits(bits, ETHER.Dmac);
        append_bits(bits, ETHER.Smac);
        append_bits(bits, ETHER.ETHER_TYPE.Type);

        append_bits(bits, VLAN_TAG0.Tpid);
        append_bits(bits, VLAN_TAG0.VlanInfo._noname_u_0);
        append_bits(bits, VLAN_TAG0.VlanInfo.VlanID);
        append_bits(bits, VLAN_TAG0.ETHER_TYPE.Type);

        append_bits(bits, ETHER_TYPE.Type);

        append_bits(bits, IPv4.Version);
        append_bits(bits, IPv4.Ihl);
        append_bits(bits, IPv4.u_0);
        append_bits(bits, IPv4.TotalLen);
        append_bits(bits, IPv4.Iden);
        append_bits(bits, IPv4.R);
        append_bits(bits, IPv4.DF);
        append_bits(bits, IPv4.MF);
        append_bits(bits, IPv4.FragOffset);
        append_bits(bits, IPv4.TTL);
        append_bits(bits, IPv4.Protocol);
        append_bits(bits, IPv4.Checksum);
        append_bits(bits, IPv4.SIP);
        append_bits(bits, IPv4.DIP);

        append_bits(bits, IPv6.Version);
        append_bits(bits, IPv6._noname_u_0);
        append_bits(bits, IPv6.FlowLabel);
        append_bits(bits, IPv6.PayloadLen);
        append_bits(bits, IPv6.NextProtocol);
        append_bits(bits, IPv6.HopLmt);
        append_bits(bits, IPv6.SIP);
        append_bits(bits, IPv6.DIP);

        append_bits(bits, UDP.SrcPort);
        append_bits(bits, UDP.DstPort);
        append_bits(bits, UDP.Length);
        append_bits(bits, UDP.Checksum);

        append_bits(bits, TCP.SrcPort);
        append_bits(bits, TCP.DstPort);
        append_bits(bits, TCP.SeqNo);
        append_bits(bits, TCP.AckNo);
        append_bits(bits, TCP.DataCtrl.DataOffset);
        append_bits(bits, TCP.DataCtrl._noname_u_0);
        append_bits(bits, TCP.DataCtrl.Ctrl.Urg);
        append_bits(bits, TCP.DataCtrl.Ctrl.Ack);
        append_bits(bits, TCP.DataCtrl.Ctrl.Psh);
        append_bits(bits, TCP.DataCtrl.Ctrl.Rst);
        append_bits(bits, TCP.DataCtrl.Ctrl.Syn);
        append_bits(bits, TCP.DataCtrl.Ctrl.Fin);
        append_bits(bits, TCP.Window);
        append_bits(bits, TCP.Checksum);
        append_bits(bits, TCP.UrgentPtr);

        // fv fields
        append_bits(bits, GLSP);
        append_bits(bits, GLTP);
        append_bits(bits, LLTP);
        append_bits(bits, Vrf);
        append_bits(bits, FQID);
        append_bits(bits, PktLength);
        append_bits(bits, DropFlag);
        append_bits(bits, IsUc);
        append_bits(bits, Mgid);
        append_bits(bits, SB);
        append_bits(bits, SP);
        append_bits(bits, TB);
        append_bits(bits, TP);
        append_bits(bits, HashValue);
        append_bits(bits, TOS);
        append_bits(bits, TTL);
        append_bits(bits, EncapIndex);
        append_bits(bits, HubSpkGrp);
        append_bits(bits, EncapProfile);

        GtvPackedBuffer out{};
        write_bits_to_buffer(bits, out);
        return out;
    }

    // 从字节数组按同样顺序解析出各个字段
    void unpack_gtv_from_bytes(const GtvPackedBuffer &in) {
        std::size_t cursor = 0;

        // outer headers
        assign_from_bits(in, cursor, ETHER.Dmac);
        assign_from_bits(in, cursor, ETHER.Smac);
        assign_from_bits(in, cursor, ETHER.ETHER_TYPE.Type);

        assign_from_bits(in, cursor, VLAN_TAG0.Tpid);
        assign_from_bits(in, cursor, VLAN_TAG0.VlanInfo._noname_u_0);
        assign_from_bits(in, cursor, VLAN_TAG0.VlanInfo.VlanID);
        assign_from_bits(in, cursor, VLAN_TAG0.ETHER_TYPE.Type);

        assign_from_bits(in, cursor, ETHER_TYPE.Type);

        assign_from_bits(in, cursor, IPv4.Version);
        assign_from_bits(in, cursor, IPv4.Ihl);
        assign_from_bits(in, cursor, IPv4.u_0);
        assign_from_bits(in, cursor, IPv4.TotalLen);
        assign_from_bits(in, cursor, IPv4.Iden);
        assign_from_bits(in, cursor, IPv4.R);
        assign_from_bits(in, cursor, IPv4.DF);
        assign_from_bits(in, cursor, IPv4.MF);
        assign_from_bits(in, cursor, IPv4.FragOffset);
        assign_from_bits(in, cursor, IPv4.TTL);
        assign_from_bits(in, cursor, IPv4.Protocol);
        assign_from_bits(in, cursor, IPv4.Checksum);
        assign_from_bits(in, cursor, IPv4.SIP);
        assign_from_bits(in, cursor, IPv4.DIP);

        assign_from_bits(in, cursor, IPv6.Version);
        assign_from_bits(in, cursor, IPv6._noname_u_0);
        assign_from_bits(in, cursor, IPv6.FlowLabel);
        assign_from_bits(in, cursor, IPv6.PayloadLen);
        assign_from_bits(in, cursor, IPv6.NextProtocol);
        assign_from_bits(in, cursor, IPv6.HopLmt);
        assign_from_bits(in, cursor, IPv6.SIP);
        assign_from_bits(in, cursor, IPv6.DIP);

        assign_from_bits(in, cursor, UDP.SrcPort);
        assign_from_bits(in, cursor, UDP.DstPort);
        assign_from_bits(in, cursor, UDP.Length);
        assign_from_bits(in, cursor, UDP.Checksum);

        assign_from_bits(in, cursor, TCP.SrcPort);
        assign_from_bits(in, cursor, TCP.DstPort);
        assign_from_bits(in, cursor, TCP.SeqNo);
        assign_from_bits(in, cursor, TCP.AckNo);
        assign_from_bits(in, cursor, TCP.DataCtrl.DataOffset);
        assign_from_bits(in, cursor, TCP.DataCtrl._noname_u_0);
        assign_from_bits(in, cursor, TCP.DataCtrl.Ctrl.Urg);
        assign_from_bits(in, cursor, TCP.DataCtrl.Ctrl.Ack);
        assign_from_bits(in, cursor, TCP.DataCtrl.Ctrl.Psh);
        assign_from_bits(in, cursor, TCP.DataCtrl.Ctrl.Rst);
        assign_from_bits(in, cursor, TCP.DataCtrl.Ctrl.Syn);
        assign_from_bits(in, cursor, TCP.DataCtrl.Ctrl.Fin);
        assign_from_bits(in, cursor, TCP.Window);
        assign_from_bits(in, cursor, TCP.Checksum);
        assign_from_bits(in, cursor, TCP.UrgentPtr);

        // fv fields
        assign_from_bits(in, cursor, GLSP);
        assign_from_bits(in, cursor, GLTP);
        assign_from_bits(in, cursor, LLTP);
        assign_from_bits(in, cursor, Vrf);
        assign_from_bits(in, cursor, FQID);
        assign_from_bits(in, cursor, PktLength);
        assign_from_bits(in, cursor, DropFlag);
        assign_from_bits(in, cursor, IsUc);
        assign_from_bits(in, cursor, Mgid);
        assign_from_bits(in, cursor, SB);
        assign_from_bits(in, cursor, SP);
        assign_from_bits(in, cursor, TB);
        assign_from_bits(in, cursor, TP);
        assign_from_bits(in, cursor, HashValue);
        assign_from_bits(in, cursor, TOS);
        assign_from_bits(in, cursor, TTL);
        assign_from_bits(in, cursor, EncapIndex);
        assign_from_bits(in, cursor, HubSpkGrp);
        assign_from_bits(in, cursor, EncapProfile);
    }

protected:
    template <typename T>
    struct is_p5_union_type : std::false_type {};
    template <typename Layout>
    struct is_p5_union_type<p5::Union<Layout>> : std::true_type {};

    template <typename P5UInt>
    static void append_bits(std::vector<bool> &bits, const P5UInt &value) {
        using T = std::decay_t<P5UInt>;
        constexpr std::size_t width = T::width();
        if constexpr (is_p5_union_type<T>::value) {
            // For p5::Union: treat it as its underlying storage bits (width = base storage width).
            // Write bits in high-first order.
            const auto raw = value.to_uint(); // p5::uint<width>
            for (std::size_t i = 0; i < width; ++i) {
                bits.push_back(raw[width - 1 - i]);
            }
        } else {
            // For p5::uint / p5::member: read bits directly (high-first).
            for (std::size_t i = 0; i < width; ++i) {
                bits.push_back(value[width - 1 - i]);
            }
        }
    }

    template <typename Buffer, typename P5UInt>
    static void assign_from_bits(const Buffer &buf, std::size_t &cursor, P5UInt &target) {
        using T = std::decay_t<P5UInt>;
        constexpr std::size_t width = T::width();

        // Read width bits from buffer in high-first order, then assign to target.
        // This works for p5::uint, p5::member and p5::Union (writes to union's base storage).
        p5::uint<width> tmp{};
        for (std::size_t i = 0; i < width && cursor < buf.size() * 8; ++i, ++cursor) {
            const std::size_t byte_idx = cursor / 8;
            const std::size_t bit_idx = 7 - (cursor % 8); // 高位在前
            const bool bit = (buf[byte_idx] >> bit_idx) & 0x1;
            tmp[width - 1 - i] = bit; // i=0 is MSB
        }
        target = tmp;
    }

    template <typename Buffer>
    static void write_bits_to_buffer(const std::vector<bool> &bits, Buffer &out) {
        for (std::size_t i = 0; i < bits.size() && i < out.size() * 8; ++i) {
            if (bits[i]) {
                const std::size_t byte_idx = i / 8;
                const std::size_t bit_idx = 7 - (i % 8);
                out[byte_idx] |= static_cast<uint8_t>(1u << bit_idx);
            }
        }
    }
};

#endif // GENERATED_GTV_HPP