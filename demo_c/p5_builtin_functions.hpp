#ifndef P5_BUILTIN_FUNCTIONS_HPP
#define P5_BUILTIN_FUNCTIONS_HPP

/**
 * @file p5_builtin_functions.hpp
 * @brief P5 内置函数库 - 映射到 behavioral-model 的对应函数
 * 
 * 这个文件提供了 P5 内置函数的 C++ 实现，映射到 behavioral-model 的对应函数。
 * 在 P5 转 C++ 时，可以按需调用这些函数。
 */

#include "p5_types.hpp"
#include <bm/bm_sim/packet.h>
#include <bm/bm_sim/parser.h>
#include <bm/bm_sim/match_tables.h>
#include <bm/bm_sim/headers.h>
#include <cstring>
#include <cstdint>
#include <type_traits>

// extract.h 在 src 目录，需要根据实际路径调整
// #include <bm/bm_sim/extract.h> 或
// #include "../../behavioral-model/src/bm_sim/extract.h"

namespace p5 {

// 前向声明
class P5RuntimeContext;

/**
 * @brief P5 运行时上下文
 * 
 * 管理 P5 程序运行时的各种上下文信息，包括：
 * - 当前数据包
 * - 解析器状态
 * - 表查找上下文
 */
class P5RuntimeContext {
public:
    bm::Packet* packet = nullptr;
    bm::PHV* phv = nullptr;
    bm::ParserState* parser_state = nullptr;
    bm::MatchTableAbstract* current_table = nullptr;
    
    // 表查找上下文
    struct TableContext {
        void* key = nullptr;
        void* control_info = nullptr;
        uint32_t table_id = 0;
        bool hit = false;
        bm::entry_handle_t handle = 0;
    } table_ctx;
    
    // 解析器上下文
    struct ParserContext {
        const char* data = nullptr;
        size_t offset = 0;
        size_t data_size = 0;
    } parser_ctx;
    
    static P5RuntimeContext& instance() {
        static P5RuntimeContext inst;
        return inst;
    }
    
    void set_packet(bm::Packet* pkt) {
        packet = pkt;
        if (pkt) {
            phv = pkt->get_phv();
            parser_ctx.data = pkt->data();
            parser_ctx.data_size = pkt->get_data_size();
            parser_ctx.offset = 0;
        }
    }
};

// 全局运行时上下文
extern P5RuntimeContext* g_p5_runtime;

// ============================================================================
// P5 内置函数实现
// ============================================================================

/**
 * @brief _extract() - 从数据包中提取头部
 * 
 * P5: PHO[PHO_OUTER_L2_START] = _extract(ETHER);
 * BM: extract::generic_extract()
 */
template<typename HeaderType>
HeaderType _extract() {
    if (!g_p5_runtime || !g_p5_runtime->packet) {
        // 错误处理
        return HeaderType{};
    }
    
    HeaderType header;
    size_t header_size = sizeof(HeaderType);
    
    // 使用 behavioral-model 的 extract 函数
    // 注意：需要包含 extract.h，这里使用标准 memcpy 作为简化实现
    if (g_p5_runtime->parser_ctx.offset + header_size <= g_p5_runtime->parser_ctx.data_size) {
        // 如果可以使用 bm::extract::generic_extract，取消下面的注释
        // bm::extract::generic_extract(
        //     g_p5_runtime->parser_ctx.data + g_p5_runtime->parser_ctx.offset,
        //     0,  // bit_offset
        //     header_size * 8,  // bitwidth
        //     reinterpret_cast<char*>(&header)
        // );
        
        // 简化实现：直接 memcpy
        std::memcpy(&header, 
                   g_p5_runtime->parser_ctx.data + g_p5_runtime->parser_ctx.offset,
                   header_size);
        g_p5_runtime->parser_ctx.offset += header_size;
    }
    
    return header;
}

/**
 * @brief _lookahead() - 预读数据包内容（不移动游标）
 * 
 * P5: _lookahead(ETHER_TYPE);
 * BM: ParserLookAhead::peek()
 */
template<typename HeaderType>
HeaderType _lookahead() {
    if (!g_p5_runtime || !g_p5_runtime->packet) {
        return HeaderType{};
    }
    
    HeaderType header;
    size_t header_size = sizeof(HeaderType);
    
    // 使用 behavioral-model 的 lookahead
    bm::ParserLookAhead lookahead = bm::ParserLookAhead::make(
        g_p5_runtime->parser_ctx.offset * 8,  // offset in bits
        header_size * 8  // bitwidth
    );
    
    bm::ByteContainer bc;
    lookahead.peek(g_p5_runtime->parser_ctx.data, &bc);
    
    if (bc.size() >= header_size) {
        std::memcpy(&header, bc.data(), header_size);
    }
    
    return header;
}

/**
 * @brief _apply() - 应用表查找和执行动作
 * 
 * P5: _apply(tbIPAT);
 * BM: MatchTableAbstract::apply_action()
 */
template<typename TableType>
void _apply(TableType& table) {
    if (!g_p5_runtime || !g_p5_runtime->packet) {
        return;
    }
    
    // 假设 TableType 继承自 bm::MatchTableAbstract 或提供了 apply() 方法
    // 这里需要根据实际的表类型进行适配
    if constexpr (std::is_base_of_v<bm::MatchTableAbstract, TableType>) {
        g_p5_runtime->current_table = &table;
        table.apply_action(g_p5_runtime->packet);
    } else {
        // 如果 TableType 有自己的 apply 方法
        table.apply();
    }
}

/**
 * @brief _lookup() - 执行表查找操作
 * 
 * P5: Mem = _lookup(SE_TID_FIB, TBL_LKUP_TYPE_LPM, FibKey);
 * BM: MatchTableAbstract::lookup()
 */
template<typename KeyType, typename ResultType>
ResultType _lookup(uint32_t table_id, uint32_t lookup_type, const KeyType& key) {
    if (!g_p5_runtime || !g_p5_runtime->current_table) {
        return ResultType{};
    }
    
    bool hit = false;
    bm::entry_handle_t handle = 0;
    const bm::ControlFlowNode* next_node = nullptr;
    
    // 执行查找
    const bm::ActionEntry& action_entry = g_p5_runtime->current_table->lookup(
        *g_p5_runtime->packet,
        &hit,
        &handle,
        &next_node
    );
    
    // 更新上下文
    g_p5_runtime->table_ctx.hit = hit;
    g_p5_runtime->table_ctx.handle = handle;
    
    // 返回结果（这里需要根据实际的 ResultType 进行转换）
    ResultType result;
    // TODO: 从 action_entry 中提取结果数据
    return result;
}

/**
 * @brief _valid() - 检查查找结果是否有效
 * 
 * P5: if (_valid(rsIpat) && ...)
 * BM: Header::is_valid()
 */
template<typename T>
bool _valid(const T& result) {
    // 如果 T 是 Header 类型
    if constexpr (std::is_base_of_v<bm::Header, T>) {
        return result.is_valid();
    } else {
        // 如果 T 有 Valid 成员（P5 的 @global_valid）
        // 这里需要根据实际的结构体定义来判断
        // 使用 SFINAE 检查是否有 Valid 成员
        // 简化实现：检查是否有 Valid 字段
        // 注意：这需要根据实际的 P5 结构体定义来调整
        return true;  // 默认返回 true，实际使用时需要根据结构体定义调整
    }
}

/**
 * @brief _status() - 获取表查找状态（匹配/未匹配）
 * 
 * P5: uint<2> IpatStatus = _status();
 * BM: lookup() 返回的 hit
 */
template<uint32_t TableID>
uint<2> _status() {
    if (!g_p5_runtime) {
        return uint<2>(0);  // 错误状态
    }
    
    // 返回查找状态
    // 0 = MATCH, 1 = NO_MATCH, 2 = LOOKUP_SKIPPED, 3 = ERROR
    if (g_p5_runtime->table_ctx.hit) {
        return uint<2>(0);  // RSP_STATUS_MATCH
    } else {
        return uint<2>(1);  // RSP_STATUS_NO_MATCH
    }
}

/**
 * @brief _key() - 获取表查找键值
 * 
 * P5: FibKey = _key();
 * BM: 从表上下文中获取
 */
template<typename KeyType>
KeyType _key() {
    if (!g_p5_runtime || !g_p5_runtime->table_ctx.key) {
        return KeyType{};
    }
    
    return *static_cast<KeyType*>(g_p5_runtime->table_ctx.key);
}

/**
 * @brief _table_id() - 获取表ID
 * 
 * P5: uint<4> tid = _table_id();
 * BM: MatchTableAbstract::get_id()
 */
uint<4> _table_id() {
    if (!g_p5_runtime || !g_p5_runtime->current_table) {
        return uint<4>(0);
    }
    
    return uint<4>(g_p5_runtime->current_table->get_id());
}

/**
 * @brief _control_info() - 获取控制信息
 * 
 * P5: IpatCtrlInfo_S IpatCtrlInfo = _control_info();
 * BM: 从动作上下文中获取
 */
template<typename ControlInfoType>
ControlInfoType _control_info() {
    if (!g_p5_runtime || !g_p5_runtime->table_ctx.control_info) {
        return ControlInfoType{};
    }
    
    return *static_cast<ControlInfoType*>(g_p5_runtime->table_ctx.control_info);
}

/**
 * @brief _parser_next() - 解析器状态转换
 * 
 * P5: return _parser_next(0, 0);
 * BM: 解析器状态机
 */
void _parser_next(int group, int stage) {
    if (!g_p5_runtime || !g_p5_runtime->parser_state) {
        return;
    }
    
    // 解析器状态转换由 behavioral-model 的状态机处理
    // 这里可能需要根据 group 和 stage 进行状态跳转
    // TODO: 实现状态转换逻辑
}

/**
 * @brief _memcpy() - 内存拷贝操作
 * 
 * P5: _memcpy(CompressedFibRsp, {Mem});
 * BM: std::memcpy()
 */
template<typename DestType, typename SrcType>
void _memcpy(DestType& dst, const SrcType& src) {
    std::memcpy(&dst, &src, sizeof(DestType));
}

} // namespace p5

// 全局运行时上下文指针
namespace p5 {
    extern P5RuntimeContext* g_p5_runtime;
}

#endif // P5_BUILTIN_FUNCTIONS_HPP

