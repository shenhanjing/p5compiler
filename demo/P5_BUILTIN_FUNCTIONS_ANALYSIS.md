# P5 内置函数与 Behavioral-Model 对应关系分析

## 分析结果汇总表

| P5 内置函数 | 功能描述 | Behavioral-Model 对应 | 实现位置 | 匹配状态 |
|------------|---------|----------------------|---------|---------|
| `_extract()` | 从数据包中提取头部 | `extract()` | `src/bm_sim/parser.cpp`<br>`src/bm_sim/extract.h` | ✅ 已实现 |
| `_lookahead()` | 预读数据包内容（不移动游标） | `lookahead()` | `src/bm_sim/parser.cpp`<br>`ParserLookAhead::peek()` | ✅ 已实现 |
| `_advance()` | 移动数据包游标 | `advance()` | `src/bm_sim/parser.cpp` | ✅ 已实现 |
| `_emit()` | 将头部写入输出数据包 | `emit()` | `src/bm_sim/deparser.cpp`<br>`header.deparse()` | ✅ 已实现 |
| `_apply()` | 应用表查找和执行动作 | `table.apply()` | `src/bm_sim/tables.cpp`<br>`MatchActionTable::operator()()` | ✅ 已实现 |
| `_valid()` | 检查查找结果是否有效 | `header.is_valid()`<br>`match_result.hit` | `src/bm_sim/headers.cpp`<br>`src/bm_sim/match_tables.cpp` | ✅ 部分实现 |
| `_lookup()` | 执行表查找操作 | `MatchTableAbstract::lookup()` | `src/bm_sim/match_tables.cpp` | ✅ 已实现 |
| `_status()` | 获取表查找状态（匹配/未匹配） | `match_result.hit`<br>`table_miss/hit` | `src/bm_sim/match_tables.cpp` | ✅ 部分实现 |
| `_parser_next()` | 解析器状态转换 | 解析器状态机 | `src/bm_sim/parser.cpp` | ✅ 已实现（通过状态机） |
| `_key()` | 获取表查找键值 | 表键构建 | `src/bm_sim/match_tables.cpp`<br>`MatchKeyBuilder` | ⚠️ 间接实现 |
| `_table_id()` | 获取表ID | `table.get_id()` | `src/bm_sim/tables.cpp` | ✅ 已实现 |
| `_control_info()` | 获取控制信息 | 动作参数/元数据 | `src/bm_sim/actions.cpp` | ⚠️ 间接实现 |
| `_memcpy()` | 内存拷贝操作 | 无直接对应 | - | ❌ 未实现 |
| `_inflate()` | 解压缩结构体 | 无直接对应 | - | ❌ 未实现 |
| `_add_to_ngsf()` | 添加到NGSF缓冲区 | 无直接对应 | - | ❌ 未实现 |
| `_port_mapping()`<br>`_mapping_converter()` | 端口映射转换 | 无直接对应 | - | ❌ 未实现 |

## 详细说明

### ✅ 完全对应的函数

#### 1. `_extract()` ↔ `extract()`
- **P5**: `PHO[PHO_OUTER_L2_START] = _extract(ETHER);`
- **BM**: `packet_in.extract<T>(out T hdr)`
- **实现**: 
  - `src/bm_sim/parser.cpp:244` - `extract_fixed()`
  - `src/bm_sim/extract.h:30` - `generic_extract()`
  - `src/bm_sim/parser.cpp:283` - `ParserOpExtract`

#### 2. `_lookahead()` ↔ `lookahead()`
- **P5**: `_lookahead(ETHER_TYPE);`
- **BM**: `packet_in.lookahead<T>()`
- **实现**:
  - `src/bm_sim/parser.cpp:42` - `ParserLookAhead::make()`
  - `src/bm_sim/parser.cpp:49` - `ParserLookAhead::peek()`
  - `src/bm_sim/parser.cpp:92` - `ParserOpSet<ParserLookAhead>`

#### 3. `_apply()` ↔ `table.apply()`
- **P5**: `_apply(tbIPAT);`
- **BM**: `table.apply()` (通过 JSON 配置)
- **实现**:
  - `src/bm_sim/tables.cpp:36` - `MatchActionTable::operator()()`
  - `src/bm_sim/match_tables.cpp:95` - `MatchTableAbstract::apply_action()`

#### 4. `_lookup()` ↔ `MatchTableAbstract::lookup()`
- **P5**: `Mem = _lookup(SE_TID_FIB, TBL_LKUP_TYPE_LPM, FibKey);`
- **BM**: `MatchTableAbstract::lookup()` (内部使用)
- **实现**:
  - `src/bm_sim/match_tables.cpp:103` - `lookup()` 方法

### ⚠️ 部分对应的函数

#### 5. `_valid()` ↔ `is_valid()`
- **P5**: `if (_valid(rsIpat) && ...)`
- **BM**: `header.is_valid()` 或通过匹配结果判断
- **实现**:
  - `src/bm_sim/headers.cpp` - `Header::is_valid()`
  - `src/bm_sim/match_tables.cpp:121` - `hit` 状态

#### 6. `_status()` ↔ `match_result`
- **P5**: `uint<2> IpatStatus = _status();`
- **BM**: 通过 `hit`/`miss` 状态表示，但无直接的状态码返回
- **实现**:
  - `src/bm_sim/match_tables.cpp:121-130` - hit/miss 日志记录

#### 7. `_key()` ↔ `MatchKeyBuilder`
- **P5**: `FibKey = _key();`
- **BM**: 键值在表查找时自动构建，不直接暴露给用户
- **实现**:
  - `src/bm_sim/match_tables.cpp` - `MatchKeyBuilder`

#### 8. `_control_info()` ↔ 动作参数
- **P5**: `IpatCtrlInfo_S IpatCtrlInfo = _control_info();`
- **BM**: 通过动作参数传递，无直接的控制信息函数
- **实现**:
  - `src/bm_sim/actions.cpp` - 动作参数处理

### ❌ 未实现的函数（P5 特有）

#### 9. `_memcpy()`
- **P5**: `_memcpy(CompressedFibRsp, {Mem});`
- **BM**: 无对应实现
- **说明**: P5 特有的内存拷贝操作，用于压缩/解压缩结构体

#### 10. `_inflate()`
- **P5**: `typedef _inflate<FIBRSP_S> FIBFull_S;`
- **BM**: 无对应实现
- **说明**: P5 特有的结构体解压缩操作

#### 11. `_add_to_ngsf()`
- **P5**: `_add_to_ngsf(FQID);`
- **BM**: 无对应实现
- **说明**: P5 特有的 NGSF (Next Generation Switch Fabric) 缓冲区操作

#### 12. `_port_mapping()` / `_mapping_converter()`
- **P5**: `_port_mapping("GLSP", tmpSb, tmpSP, GLSP);`
- **BM**: 无对应实现
- **说明**: P5 特有的端口映射转换操作

#### 13. `_parser_next()`
- **P5**: `return _parser_next(0, 0);`
- **BM**: 通过解析器状态机实现，但无直接函数调用
- **说明**: P5 的显式状态转换，BM 通过状态机隐式处理

## 统计结果

- **完全对应**: 6 个函数 (`_extract`, `_lookahead`, `_advance`, `_emit`, `_apply`, `_lookup`)
- **部分对应**: 5 个函数 (`_valid`, `_status`, `_key`, `_control_info`, `_table_id`)
- **未实现**: 5 个函数 (`_memcpy`, `_inflate`, `_add_to_ngsf`, `_port_mapping`, `_parser_next`)
- **总计**: 16 个主要内置函数

## 结论

Behavioral-Model 主要实现了 P4 标准的内置函数（如 `extract`, `lookahead`, `emit`, `apply`），这些函数在 P5 中也有对应的 `_` 前缀版本。

P5 特有的函数（如 `_memcpy`, `_inflate`, `_add_to_ngsf`, `_port_mapping`）主要是为了支持特定的硬件功能和优化，这些在标准的 P4/BM 实现中不存在。

