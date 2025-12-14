#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <cstring>
#include "../../model_intf_1027.h"
#include "headers.hpp"

// 辅助函数：按位写入（大端序，MSB first）
// bit_idx=0 表示字节内的 MSB（bit 7），bit_idx=7 表示 LSB（bit 0）
inline void write_bits(uint8_t* data, size_t bit_offset, uint64_t value, size_t nbits) {
    for (size_t bit = 0; bit < nbits; ++bit) {
        // 检查 value 的第 (nbits-1-bit) 位（从高位开始）
        if (value & (1ULL << (nbits - 1 - bit))) {
            size_t total_bit_pos = bit_offset + bit;
            size_t byte_idx = total_bit_pos / 8;
            size_t bit_idx = total_bit_pos % 8;  // bit_idx=0 是字节内的第0位（MSB）
            if (byte_idx < FV_PHI_BYTE_NUM) {
                // 大端序：bit_idx=0 对应 bit 7（MSB），bit_idx=7 对应 bit 0（LSB）
                data[byte_idx] |= (1 << (7 - bit_idx));
            }
        }
    }
}

// PHI 序列化函数
inline void serialize_phi(const PHI_S& phi, uint8_t* phiData) {
    memset(phiData, 0, FV_PHI_BYTE_NUM);
    
    size_t bit_offset = 0;
    
    // PortType (4 bits)
    write_bits(phiData, bit_offset, phi.PortType.to_ullong(), 4);
    bit_offset += 4;
    
    // L2Type (2 bits)
    write_bits(phiData, bit_offset, phi.L2Type.to_ullong(), 2);
    bit_offset += 2;
    
    // TagType (2 bits)
    write_bits(phiData, bit_offset, phi.TagType.to_ullong(), 2);
    bit_offset += 2;
    
    // L3Type (2 bits)
    write_bits(phiData, bit_offset, phi.L3Type.to_ullong(), 2);
    bit_offset += 2;
    
    // L4Type (8 bits)
    write_bits(phiData, bit_offset, phi.L4Type.to_ullong(), 8);
    bit_offset += 8;
    
    // 注意：PHI_S 总共只有 18 bits，但 phiData 是 80 bits
    // 剩余 62 bits 可能用于其他字段，这里只序列化已定义的字段
}

// PHO 序列化函数
inline void serialize_pho(const p5::uint<7>* pho, size_t count, uint8_t* phoData) {
    memset(phoData, 0, FV_PHO_BYTE_NUM);
    
    size_t bit_offset = 0;
    
    for (size_t i = 0; i < count; ++i) {
        // 每个 PHO 字段是 7 bits
        write_bits(phoData, bit_offset, pho[i].to_ullong(), 7);
        bit_offset += 7;
    }
}

#endif // SERIALIZER_HPP

