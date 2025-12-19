#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <cstring>
#include <climits>
#include "model_intf_1027.h"
#include "headers.hpp"
#include "parser_base.hpp"  // 新增：用于 FV_S 结构体

// 辅助函数：按位写入（大端序，MSB first）
// bit_idx=0 表示字节内的 MSB（bit 7），bit_idx=7 表示 LSB（bit 0）
// max_bytes: 最大字节数限制，防止越界
inline void write_bits(uint8_t* data, size_t bit_offset, uint64_t value, size_t nbits, size_t max_bytes = SIZE_MAX) {
    if (max_bytes == SIZE_MAX) {
        max_bytes = FV_PHI_BYTE_NUM;  // 默认使用 FV_PHI_BYTE_NUM 以保持向后兼容
    }
    for (size_t bit = 0; bit < nbits; ++bit) {
        // 检查 value 的第 (nbits-1-bit) 位（从高位开始）
        if (value & (1ULL << (nbits - 1 - bit))) {
            size_t total_bit_pos = bit_offset + bit;
            size_t byte_idx = total_bit_pos / 8;
            size_t bit_idx = total_bit_pos % 8;  // bit_idx=0 是字节内的第0位（MSB）
            if (byte_idx < max_bytes) {
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

// FV 序列化函数（将 FV_S 结构体编码到 gtvData）
inline void serialize_fv(const FV_S& fv, uint8_t* gtvData) {
    memset(gtvData, 0, FV_GTV_MAX_BYTE_NUM);
    
    size_t bit_offset = 0;
    
    // 按照 generated_gtv.hpp 中 pack_fv_to_bytes() 的顺序编码
    // 注意：NGSFBuffer[64] 不包含在 gtvData 中，只编码其他字段
    
    // GLSP (10 bits)
    write_bits(gtvData, bit_offset, fv.GLSP.to_ullong(), 10, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 10;
    
    // GLTP (10 bits)
    write_bits(gtvData, bit_offset, fv.GLTP.to_ullong(), 10, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 10;
    
    // LLTP (6 bits)
    write_bits(gtvData, bit_offset, fv.LLTP.to_ullong(), 6, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 6;
    
    // Vrf (8 bits)
    write_bits(gtvData, bit_offset, fv.Vrf.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // FQID (6 bits)
    write_bits(gtvData, bit_offset, fv.FQID.to_ullong(), 6, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 6;
    
    // PktLength (14 bits)
    write_bits(gtvData, bit_offset, fv.PktLength.to_ullong(), 14, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 14;
    
    // DropFlag (1 bit)
    write_bits(gtvData, bit_offset, fv.DropFlag.to_ullong(), 1, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 1;
    
    // IsUc (1 bit)
    write_bits(gtvData, bit_offset, fv.IsUc.to_ullong(), 1, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 1;
    
    // Mgid (12 bits)
    write_bits(gtvData, bit_offset, fv.Mgid.to_ullong(), 12, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 12;
    
    // SB (8 bits)
    write_bits(gtvData, bit_offset, fv.SB.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // SP (8 bits)
    write_bits(gtvData, bit_offset, fv.SP.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // TB (8 bits)
    write_bits(gtvData, bit_offset, fv.TB.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // TP (8 bits)
    write_bits(gtvData, bit_offset, fv.TP.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // HashValue (16 bits)
    write_bits(gtvData, bit_offset, fv.HashValue.to_ullong(), 16, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 16;
    
    // TOS (8 bits)
    write_bits(gtvData, bit_offset, fv.TOS.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // TTL (8 bits)
    write_bits(gtvData, bit_offset, fv.TTL.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // EncapIndex (8 bits)
    write_bits(gtvData, bit_offset, fv.EncapIndex.to_ullong(), 8, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 8;
    
    // HubSpkGrp (3 bits)
    write_bits(gtvData, bit_offset, fv.HubSpkGrp.to_ullong(), 3, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 3;
    
    // EncapProfile (2 bits)
    write_bits(gtvData, bit_offset, fv.EncapProfile.to_ullong(), 2, FV_GTV_MAX_BYTE_NUM);
    bit_offset += 2;
    
    // 总共编码了 145 bits，剩余部分保持为 0
}

#endif // SERIALIZER_HPP

