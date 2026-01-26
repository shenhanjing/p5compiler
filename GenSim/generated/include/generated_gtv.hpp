#ifndef GENERATED_GTV_HPP
#define GENERATED_GTV_HPP

#include <array>
#include <cstdint>
#include <type_traits>
#include <vector>

#include <boost/pfr.hpp>

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

    // ============================ NGSF stream state ============================
    // Public direction selector for _add_to_ngsf():
    // - FV2NGSF: append bits from argument into NGSFBuffer (stream write)
    // - NGSF2FV: restore bits from NGSFBuffer into argument (stream read)
    enum class NgsfDirection : uint8_t { FV2NGSF = 0, NGSF2FV = 1 };
    NgsfDirection ngsf_direction{NgsfDirection::FV2NGSF};

    // Cursor within NGSFBuffer. bit_offset is MSB-first within a byte:
    // - bit_offset==0 targets the current byte's MSB
    // - bit_offset==7 targets the current byte's LSB
    std::size_t ngsf_byte_offset{0};
    uint8_t ngsf_bit_offset{0};

    enum class NPorTM : uint8_t { NP = 0, TM = 1 };
    NPorTM npor_tm{NPorTM::NP};

    std::size_t tm_byte_offset{0};
    uint8_t tm_bit_offset{0};

    void reset_ngsf_offset() {
        ngsf_byte_offset = 0;
        ngsf_bit_offset = 0;
        tm_byte_offset = 0;
        tm_bit_offset = 0;
    }

    // Add to / restore from NGSF bit stream.
    // Accepts:
    // - p5::uint<N>
    // - p5::member<p5::uint<N>>
    // - p5::Union<Layout>
    // - aggregate structs composed of the above (nesting allowed)
    template <typename T>
    void _add_to_ngsf(T &value) {
        if (ngsf_direction == NgsfDirection::FV2NGSF) {
            ngsf_append_any(value);
            if (npor_tm == NPorTM::TM) {
                tm_byte_offset = ngsf_byte_offset;
                tm_bit_offset = ngsf_bit_offset;
            }
        } else {
            ngsf_restore_any(value);
        }
    }

    template <typename T>
    void _add_to_ngsf(const T &value) {
        if (ngsf_direction == NgsfDirection::FV2NGSF) {
            ngsf_append_any(value);
            if (npor_tm == NPorTM::TM) {
                tm_byte_offset = ngsf_byte_offset;
                tm_bit_offset = ngsf_bit_offset;
            }
        } else {
            // Restore direction: cannot write back to a temporary.
            // Consume bits to keep stream aligned.
            ngsf_skip_any<T>();
        }
    }

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
    struct is_p5_uint_type : std::false_type {};
    template <std::size_t N>
    struct is_p5_uint_type<p5::uint<N>> : std::true_type {};

    template <typename T>
    struct is_p5_member_type : std::false_type {};
    template <typename UIntT>
    struct is_p5_member_type<p5::member<UIntT>> : std::true_type {};

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

    // ============================ NGSF helpers ============================
    bool ngsf_has_capacity(std::size_t bits_needed) const {
        const std::size_t total_bits = sizeof(NGSFBuffer) / sizeof(NGSFBuffer[0]) * 8; // 64 bytes * 8
        const std::size_t cur_bits = ngsf_byte_offset * 8 + ngsf_bit_offset;
        return cur_bits + bits_needed <= total_bits;
    }

    void ngsf_write_bit(bool bit) {
        if (ngsf_byte_offset >= 64) return;
        // bit_offset is MSB-first; p5::uint bit index 7 is MSB.
        NGSFBuffer[ngsf_byte_offset][static_cast<std::size_t>(7 - ngsf_bit_offset)] = bit;
        ++ngsf_bit_offset;
        if (ngsf_bit_offset >= 8) {
            ngsf_bit_offset = 0;
            ++ngsf_byte_offset;
        }
    }

    bool ngsf_read_bit() {
        if (ngsf_byte_offset >= 64) return false;
        const bool bit = NGSFBuffer[ngsf_byte_offset][static_cast<std::size_t>(7 - ngsf_bit_offset)];
        ++ngsf_bit_offset;
        if (ngsf_bit_offset >= 8) {
            ngsf_bit_offset = 0;
            ++ngsf_byte_offset;
        }
        return bit;
    }

    template <typename P5T>
    static constexpr std::size_t ngsf_width_bits() {
        using D = std::decay_t<P5T>;
        if constexpr (is_p5_union_type<D>::value) {
            return D::width();
        } else if constexpr (is_p5_uint_type<D>::value) {
            return D::width();
        } else if constexpr (is_p5_member_type<D>::value) {
            return D::width();
        } else {
            return 0;
        }
    }

    template <typename Field>
    void ngsf_append_leaf(const Field &field) {
        using D = std::decay_t<Field>;
        constexpr std::size_t W = ngsf_width_bits<D>();
        static_assert(W > 0, "Unsupported NGSF leaf type");

        if constexpr (is_p5_union_type<D>::value) {
            const auto raw = field.to_uint(); // p5::uint<W>
            for (std::size_t i = 0; i < W; ++i) {
                ngsf_write_bit(raw[W - 1 - i]);
            }
        } else {
            for (std::size_t i = 0; i < W; ++i) {
                ngsf_write_bit(field[W - 1 - i]);
            }
        }
    }

    template <typename Field>
    void ngsf_restore_leaf(Field &field) {
        using D = std::decay_t<Field>;
        constexpr std::size_t W = ngsf_width_bits<D>();
        static_assert(W > 0, "Unsupported NGSF leaf type");

        p5::uint<W> tmp{};
        for (std::size_t i = 0; i < W; ++i) {
            const bool bit = ngsf_read_bit();
            tmp[W - 1 - i] = bit;
        }
        // Works for p5::uint / p5::member / p5::Union (writes underlying storage/view).
        field = tmp;
    }

    template <typename Field>
    void ngsf_skip_leaf() {
        using D = std::decay_t<Field>;
        constexpr std::size_t W = ngsf_width_bits<D>();
        static_assert(W > 0, "Unsupported NGSF leaf type");
        for (std::size_t i = 0; i < W; ++i) {
            (void)ngsf_read_bit();
        }
    }

    template <typename T>
    void ngsf_skip_any() {
        using D = std::decay_t<T>;
        if constexpr (is_p5_uint_type<D>::value || is_p5_member_type<D>::value || is_p5_union_type<D>::value) {
            ngsf_skip_leaf<D>();
        } else {
            static_assert(std::is_aggregate_v<D>,
                          "_add_to_ngsf supports only p5::uint/p5::member/p5::Union or aggregates composed of them.");
            static_assert(std::is_default_constructible_v<D>,
                          "ngsf_skip_any requires aggregate types to be default-constructible.");
            D tmp{};
            boost::pfr::for_each_field(tmp, [&](auto &sub) { ngsf_skip_any<std::decay_t<decltype(sub)>>(); });
        }
    }

    template <typename T>
    void ngsf_append_any(const T &value) {
        using D = std::decay_t<T>;
        if constexpr (is_p5_uint_type<D>::value || is_p5_member_type<D>::value || is_p5_union_type<D>::value) {
            ngsf_append_leaf(value);
        } else {
            static_assert(std::is_aggregate_v<D>,
                          "_add_to_ngsf supports only p5::uint/p5::member/p5::Union or aggregates composed of them.");
            boost::pfr::for_each_field(value, [&](const auto &sub) { ngsf_append_any(sub); });
        }
    }

    template <typename T>
    void ngsf_restore_any(T &value) {
        using D = std::decay_t<T>;
        if constexpr (is_p5_uint_type<D>::value || is_p5_member_type<D>::value || is_p5_union_type<D>::value) {
            ngsf_restore_leaf(value);
        } else {
            static_assert(std::is_aggregate_v<D>,
                          "_add_to_ngsf supports only p5::uint/p5::member/p5::Union or aggregates composed of them.");
            boost::pfr::for_each_field(value, [&](auto &sub) { ngsf_restore_any(sub); });
        }
    }
};

#endif // GENERATED_GTV_HPP