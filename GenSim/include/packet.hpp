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
    // 当前解析偏移：
    // - offset_：以字节为单位（保持 7 位，不改动）
    // - bit_offset_：字节内偏移（以 bit 为单位，0~7）
    // 绝对 bit 光标 = offset_ * 8 + bit_offset_（bit_offset_ 采用 MSB-first：0 表示当前字节的最高位）
    mutable p5::uint<7> offset_;
    mutable p5::uint<3> bit_offset_{0};

    // 重置解析偏移（不清理 data_ 内容）
    void reset_offset() const {
        offset_ = 0;
        bit_offset_ = 0;
    }

    // Advance bit stream pointer by bits.
    // Note: bit_offset_ is MSB-first within a byte (0 means the current byte's MSB).
    void _advance(p5::uint<16> bits) const {
        const std::size_t start_byte = static_cast<std::size_t>(offset_.to_ullong());
        const std::size_t start_bit_in_byte = static_cast<std::size_t>(bit_offset_.to_ullong());
        const std::size_t start_bit = start_byte * 8 + start_bit_in_byte;

        const std::size_t total_bits = static_cast<std::size_t>(PKT_HEADER_BYTE_LEN) * 8;
        std::size_t new_bit = start_bit + static_cast<std::size_t>(bits.to_ullong());
        if (new_bit > total_bits) {
            std::cerr << "[Packet] _advance overflow: start_bit=" << start_bit
                      << " advance=" << bits.to_ullong()
                      << " total_bits=" << total_bits
                      << " (clamp to end)\n";
            new_bit = total_bits;
        }

        offset_ = static_cast<uint64_t>(new_bit / 8);
        bit_offset_ = static_cast<uint64_t>(new_bit % 8);
    }

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
    struct is_p5_member : std::false_type {};
    template <typename UIntT>
    struct is_p5_member<p5::member<UIntT>> : std::true_type {};

    template <typename T>
    struct is_p5_union : std::false_type {};
    template <typename Layout>
    struct is_p5_union<p5::Union<Layout>> : std::true_type {};

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
        using Decayed = std::decay_t<P5UInt>;
        constexpr std::size_t width = Decayed::width();
        p5::uint<width> tmp{};
        // bits vector is in high-first order; assign tmp[width-1]..tmp[0].
        for (std::size_t i = 0; i < width && cursor < bits.size(); ++i, ++cursor) {
            tmp[width - 1 - i] = bits[cursor];
        }
        // For p5::uint / p5::member / p5::Union: assignment writes to the underlying storage/view.
        target = tmp;
    }

    template <typename Field>
    static void decode_any(const std::vector<bool> &bits, std::size_t &cursor, Field &target) {
        using Decayed = std::decay_t<Field>;
        if constexpr (is_p5_uint<Decayed>::value || is_p5_member<Decayed>::value || is_p5_union<Decayed>::value) {
            assign_bits(bits, cursor, target);
        } else {
            static_assert(is_supported_header<Decayed>(),
                          "Header fields must be p5::uint<N>/p5::member/p5::Union or nested aggregates thereof.");
            boost::pfr::for_each_field(target, [&](auto &sub) { decode_any(bits, cursor, sub); });
        }
    }

    template <typename Header>
    void process_header(Header &hdr, bool advance) const {
        static_assert(is_supported_header<Header>(),
                      "_extract/_lookahead supports only p5::uint<N>/p5::member/p5::Union or their aggregates.");

        constexpr std::size_t hdr_bits = bit_width_of<Header>();
        const std::size_t start_byte = static_cast<std::size_t>(offset_.to_ullong());
        const std::size_t start_bit_in_byte = static_cast<std::size_t>(bit_offset_.to_ullong());
        const std::size_t start_bit = start_byte * 8 + start_bit_in_byte;
        const std::size_t end_bit = start_bit + hdr_bits;
        const std::size_t total_bits = static_cast<std::size_t>(PKT_HEADER_BYTE_LEN) * 8;

        if (end_bit > total_bits) {
            std::cerr << "[Packet] insufficient data: need " << hdr_bits
                      << " bits, have "
                      << (total_bits > start_bit ? (total_bits - start_bit) : 0)
                      << " bits\n";
        }

        std::vector<bool> bits;
        bits.reserve(hdr_bits);
        for (std::size_t i = 0; i < hdr_bits; ++i) {
            const std::size_t abs_bit = start_bit + i;
            const std::size_t byte_idx = abs_bit / 8;
            const std::size_t bit_idx_in_byte = abs_bit % 8; // 0..7, MSB-first
            uint8_t byte = 0;
            if (byte_idx < PKT_HEADER_BYTE_LEN) {
                byte = data_[byte_idx];
            }
            const uint8_t bit = static_cast<uint8_t>((byte >> (7 - bit_idx_in_byte)) & 0x1);
            bits.push_back(bit != 0);
        }

        std::size_t cur = 0;
        decode_any(bits, cur, hdr);

        if (advance) {
            const std::size_t new_bit = end_bit;
            offset_ = static_cast<uint64_t>(new_bit / 8);
            bit_offset_ = static_cast<uint64_t>(new_bit % 8);
        }
    }
};

// ---- inline template definitions (after class to avoid redecl issues) ----
template <typename T>
inline constexpr bool Packet::is_supported_header() {
    using Decayed = std::decay_t<T>;
    if constexpr (is_p5_uint<Decayed>::value) {
        return true;
    } else if constexpr (is_p5_member<Decayed>::value) {
        return true;
    } else if constexpr (is_p5_union<Decayed>::value) {
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
    } else if constexpr (is_p5_member<Decayed>::value) {
        return Decayed::width();
    } else if constexpr (is_p5_union<Decayed>::value) {
        return Decayed::width();
    } else {
        static_assert(std::is_aggregate_v<Decayed>,
                      "Header must be aggregate or p5::uint<N>.");
        static_assert(is_supported_header<Decayed>(),
                      "All fields must be p5::uint<N>/p5::member/p5::Union or nested aggregates thereof.");
        constexpr std::size_t fields = boost::pfr::tuple_size_v<Decayed>;
        return bit_width_fields<Decayed>(std::make_index_sequence<fields>{});
    }
}

template <typename T, std::size_t... I>
inline constexpr std::size_t Packet::bit_width_fields(std::index_sequence<I...>) {
    return (bit_width_of<typename boost::pfr::tuple_element_t<I, T>>() + ... + 0);
}

#endif // PACKET_HPP


