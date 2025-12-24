#ifndef PACKET_HPP
#define PACKET_HPP

#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <type_traits>
#include <vector>

#include <boost/pfr.hpp>

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
    // ---- 类型检测：仅允许 p5::uint<N> 或其递归聚合 ----
    template <typename T>
    struct is_p5_uint : std::false_type {};
    template <std::size_t N>
    struct is_p5_uint<p5::uint<N>> : std::true_type {};

    template <typename T>
    static constexpr bool is_supported_header();

    template <typename T, std::size_t... I>
    static constexpr bool is_supported_fields(std::index_sequence<I...>);

    // ---- 位宽计算 ----
    template <typename T>
    static constexpr std::size_t bit_width_of();

    template <typename T, std::size_t... I>
    static constexpr std::size_t bit_width_fields(std::index_sequence<I...>);

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

    template <typename Field>
    static void decode_any(const std::vector<bool> &bits, std::size_t &cursor, Field &target) {
        using Decayed = std::decay_t<Field>;
        if constexpr (is_p5_uint<Decayed>::value) {
            assign_bits(bits, cursor, target);
        } else {
            static_assert(is_supported_header<Decayed>(),
                          "Header fields must be p5::uint<N> or nested aggregates thereof.");
            boost::pfr::for_each_field(target, [&](auto &sub) { decode_any(bits, cursor, sub); });
        }
    }

    template <typename Header>
    void process_header(Header &hdr, bool advance) const {
        static_assert(is_supported_header<Header>(),
                      "_extract/_lookahead supports only p5::uint<N> or their aggregates.");

        constexpr std::size_t hdr_bits = bit_width_of<Header>();
        constexpr std::size_t hdr_len_bytes = (hdr_bits + 7) / 8;
        const std::size_t start = static_cast<std::size_t>(offset_.to_ullong());

        if (start + hdr_len_bytes > PKT_HEADER_BYTE_LEN) {
            std::cerr << "[Packet] insufficient data: need " << hdr_len_bytes
                      << " bytes, have "
                      << (PKT_HEADER_BYTE_LEN > start ? (PKT_HEADER_BYTE_LEN - start) : 0)
                      << " bytes\n";
        }

        std::vector<bool> bits;
        bits.reserve(hdr_len_bytes * 8);
        for (std::size_t i = 0; i < hdr_len_bytes; ++i) {
            uint8_t byte = 0;
            if (start + i < PKT_HEADER_BYTE_LEN) {
                byte = data_[start + i];
            }
            for (int b = 7; b >= 0; --b) {
                bits.push_back((byte >> b) & 0x1);
            }
        }

        std::size_t cur = 0;
        decode_any(bits, cur, hdr);

        if (advance) {
            offset_ = static_cast<uint64_t>(start + hdr_len_bytes);
        }
    }
};

// ---- inline template definitions (after class to avoid redecl issues) ----
template <typename T>
inline constexpr bool Packet::is_supported_header() {
    using Decayed = std::decay_t<T>;
    if constexpr (is_p5_uint<Decayed>::value) {
        return true;
    } else if constexpr (std::is_aggregate_v<Decayed>) {
        constexpr std::size_t fields = boost::pfr::tuple_size_v<Decayed>;
        return is_supported_fields<Decayed>(std::make_index_sequence<fields>{});
    } else {
        return false;
    }
}

template <typename T, std::size_t... I>
inline constexpr bool Packet::is_supported_fields(std::index_sequence<I...>) {
    return (is_supported_header<typename boost::pfr::tuple_element_t<I, T>>() && ...);
}

template <typename T>
inline constexpr std::size_t Packet::bit_width_of() {
    using Decayed = std::decay_t<T>;
    if constexpr (is_p5_uint<Decayed>::value) {
        return Decayed::width();
    } else {
        static_assert(std::is_aggregate_v<Decayed>,
                      "Header must be aggregate or p5::uint<N>.");
        static_assert(is_supported_header<Decayed>(),
                      "All fields must be p5::uint<N> or nested aggregates thereof.");
        constexpr std::size_t fields = boost::pfr::tuple_size_v<Decayed>;
        return bit_width_fields<Decayed>(std::make_index_sequence<fields>{});
    }
}

template <typename T, std::size_t... I>
inline constexpr std::size_t Packet::bit_width_fields(std::index_sequence<I...>) {
    return (bit_width_of<typename boost::pfr::tuple_element_t<I, T>>() + ... + 0);
}

#endif // PACKET_HPP


