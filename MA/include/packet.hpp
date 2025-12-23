#ifndef PACKET_HPP
#define PACKET_HPP

#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include "p5_types.hpp"
#include "model_intf_1027.h"
#include "generated_struct.hpp"

class Packet {
public:
    Packet() = default;

    // 原始数据缓冲区（最多 PKT_HEADER_BYTE_LEN 字节）
    std::array<uint8_t, PKT_HEADER_BYTE_LEN> data_;
    mutable p5::uint<7> offset_;   // 当前解析偏移，单位：字节

    template <typename Header>
    void _lookahead(Header &hdr) const {
        process_header(hdr, /*advance=*/false);
    }

    template <typename Header>
    p5::uint<7> _extract(Header &hdr) {
        process_header(hdr, /*advance=*/true);
        return offset_;
    }

    // ========== 内置函数：_parser_next ==========
    /**
     * @brief Parser 状态转换函数
     * 
     * @param group 解析组 ID
     * @param stage 解析阶段 ID
     */
    void _parser_next(int group, int stage) {
        // TODO: 后续实现
        (void)group;
        (void)stage;
        return;
    }

private:
    // ---- bit 赋值辅助 ----
    template <typename P5UInt>
    static void assign_bits(const std::vector<bool> &bits, std::size_t &cursor, P5UInt &target) {
        const std::size_t width = P5UInt::width();
        uint64_t v = 0;
        for (std::size_t i = 0; i < width && cursor < bits.size(); ++i, ++cursor) {
            v = (v << 1) | static_cast<uint64_t>(bits[cursor]);
        }
        target = v;
    }

    // ---- 各头部专用 decode ----
    static void decode_header(const std::vector<bool> &bits, ETHER_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.Dmac);
        assign_bits(bits, cur, hdr.Smac);
        assign_bits(bits, cur, hdr.ETHER_TYPE.Type);
    }

    static void decode_header(const std::vector<bool> &bits, VLAN_TAG_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.Tpid);
        assign_bits(bits, cur, hdr.VlanInfo.Pri);
        assign_bits(bits, cur, hdr.VlanInfo.Dei);
        assign_bits(bits, cur, hdr.VlanInfo.VlanID);
        assign_bits(bits, cur, hdr.ETHER_TYPE.Type);
    }

    static void decode_header(const std::vector<bool> &bits, ETHER_TYPE_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.Type);
    }

    static void decode_header(const std::vector<bool> &bits, IPv4_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.Version);
        assign_bits(bits, cur, hdr.Ihl);
        assign_bits(bits, cur, hdr.TOS);
        assign_bits(bits, cur, hdr.TotalLen);
        assign_bits(bits, cur, hdr.Iden);
        assign_bits(bits, cur, hdr.R);
        assign_bits(bits, cur, hdr.DF);
        assign_bits(bits, cur, hdr.MF);
        assign_bits(bits, cur, hdr.FragOffset);
        assign_bits(bits, cur, hdr.TTL);
        assign_bits(bits, cur, hdr.Protocol);
        assign_bits(bits, cur, hdr.Checksum);
        assign_bits(bits, cur, hdr.SIP);
        assign_bits(bits, cur, hdr.DIP);
    }

    static void decode_header(const std::vector<bool> &bits, IPv6_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.Version);
        assign_bits(bits, cur, hdr.TC);
        assign_bits(bits, cur, hdr.FlowLabel);
        assign_bits(bits, cur, hdr.PayloadLen);
        assign_bits(bits, cur, hdr.NextProtocol);
        assign_bits(bits, cur, hdr.HopLmt);
        assign_bits(bits, cur, hdr.SIP);
        assign_bits(bits, cur, hdr.DIP);
    }

    static void decode_header(const std::vector<bool> &bits, UDP_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.SrcPort);
        assign_bits(bits, cur, hdr.DstPort);
        assign_bits(bits, cur, hdr.Length);
        assign_bits(bits, cur, hdr.Checksum);
    }

    static void decode_header(const std::vector<bool> &bits, TCP_S &hdr) {
        std::size_t cur = 0;
        assign_bits(bits, cur, hdr.SrcPort);
        assign_bits(bits, cur, hdr.DstPort);
        assign_bits(bits, cur, hdr.SeqNo);
        assign_bits(bits, cur, hdr.AckNo);
        assign_bits(bits, cur, hdr.DataCtrl.DataOffset);
        assign_bits(bits, cur, hdr.DataCtrl.Res);
        assign_bits(bits, cur, hdr.DataCtrl.Ecn);
        assign_bits(bits, cur, hdr.DataCtrl.Ctrl.Urg);
        assign_bits(bits, cur, hdr.DataCtrl.Ctrl.Ack);
        assign_bits(bits, cur, hdr.DataCtrl.Ctrl.Psh);
        assign_bits(bits, cur, hdr.DataCtrl.Ctrl.Rst);
        assign_bits(bits, cur, hdr.DataCtrl.Ctrl.Syn);
        assign_bits(bits, cur, hdr.DataCtrl.Ctrl.Fin);
        assign_bits(bits, cur, hdr.Window);
        assign_bits(bits, cur, hdr.Checksum);
        assign_bits(bits, cur, hdr.UrgentPtr);
    }

    template <typename Header>
    static constexpr std::size_t header_bytes();

    template <typename Header>
    void process_header(Header &hdr, bool advance) const {
        const std::size_t hdr_len = header_bytes<Header>();
        const std::size_t start = static_cast<std::size_t>(offset_.to_ullong());

        if (start + hdr_len > PKT_HEADER_BYTE_LEN) {
            std::cerr << "[Packet] insufficient data: need " << hdr_len
                      << " bytes, have " << (PKT_HEADER_BYTE_LEN > start ? (PKT_HEADER_BYTE_LEN - start) : 0)
                      << " bytes\n";
        }

        std::vector<bool> bits;
        bits.reserve(hdr_len * 8);
        for (std::size_t i = 0; i < hdr_len; ++i) {
            uint8_t byte = 0;
            if (start + i < PKT_HEADER_BYTE_LEN) {
                byte = data_[start + i];
            }
            for (int b = 7; b >= 0; --b) {
                bits.push_back((byte >> b) & 0x1);
            }
        }

        decode_header(bits, hdr);

        if (advance) {
            offset_ = static_cast<uint64_t>(start + hdr_len);
        }
    }
};

// ---- header_bytes 特化 ----
template <> constexpr std::size_t Packet::header_bytes<ETHER_S>() { return 14; }
template <> constexpr std::size_t Packet::header_bytes<VLAN_TAG_S>() { return 6; }
template <> constexpr std::size_t Packet::header_bytes<ETHER_TYPE_S>() { return 2; }
template <> constexpr std::size_t Packet::header_bytes<IPv4_S>() { return 20; }
template <> constexpr std::size_t Packet::header_bytes<IPv6_S>() { return 40; }
template <> constexpr std::size_t Packet::header_bytes<UDP_S>() { return 8; }
template <> constexpr std::size_t Packet::header_bytes<TCP_S>() { return 20; }

#endif // PACKET_HPP

