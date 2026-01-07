GenSim 项目说明
================

`GenSim/` 是 **P5 → C++ 可执行仿真** 的运行时支撑目录：它提供一套可复用的 C++ 运行时（固定位宽整数、键构建、查表引擎、报文解析、表接口与内置函数封装），并与“P5 转换得到的管线/数据结构代码”（见 `generated/` 与 `out_dir/` 的说明）拼装，最终通过 `test/test_*.cpp` 这类驱动程序构建成可执行文件。

换句话说：**运行时库 + 生成代码 + 测试驱动 = 一个可运行的“软件数据面”二进制**。

目录结构与文件职责
------------------

- **`Makefile`**：构建入口。
  - 通过 `TEST=<path/to/test.cpp>` 指定要编译的测试/示例驱动（必填，除 `clean/run_tests/help` 等目标外）。
  - 通过 `OUT_DIR=<path>` 选择“P5 转换代码”的来源目录：
    - 默认 `OUT_DIR=./generated`：使用 **手工**转写/维护的版本（便于调试与对照语义）
    - 指定 `OUT_DIR=./out_dir`：使用 **编译器自动转换**的版本（用于验证/回归自动转换结果）
  - 产物输出到 `bin/`，名字取 `TEST` 的基名（例如 `TEST=test/test_ima.cpp` → `bin/test_ima`）。
- **`run_tests.sh`**：自动发现并运行所有 `test/test_*.cpp`：
  - `make clean`
  - 依次 `make TEST=...` 编译
  - 运行对应 `./bin/test_xxx`
- **`include/`**：运行时公共头文件（生成代码与测试驱动都会 `#include`）。
  - `p5_types.hpp`：**P5 类型系统核心**，`p5::uint<N>`（1~256bit）及其切片/算术/位运算；还包含 `p5::member<>`、`p5::Union<>` 等布局视图相关类型（供生成结构体与“位域式字段”使用）。
  - `key.hpp`：**Key 管理与构建**（`KeyManager`）。
    - `initKey({bitWidths...})`：初始化若干“key 槽位”（每个槽位固定一个 bit 宽）。
    - `buildKey(parts...)`：一次性拼接多个字段，写入匹配总位宽的槽位。
    - `keyBuilder()`：增量式拼 key（跨多个 switch/分支 append，最后 `commit()` 一次写槽位），生成代码中大量使用。
    - `getKey<T>(bits)`：按位宽从槽位读取 key（`BuiltInContext::_key<T>()` 会调用它）。
  - `SE.hpp`：**查表引擎**（`SearchEngine`），面向“表 ID + 匹配类型”的 in-memory 表。
    - `MatchType::{INDEX, EXACT, LPM, TCAM}`（数值与生成代码/测试中的 lookupType 对齐）。
    - `initTable<Key, Value>(tableId, matchType)`：声明某 tableId 的 key/value 类型与匹配类型。
    - `config(...)`：下发表项（LPM 支持 `prefixLen`）。
    - `lookup(...)`：执行查找并返回 `optional<Value>`；`status(tableId)` 返回上次查找状态。
  - `BuiltIn.hpp`：**P5 内置函数语义封装**（生成代码通过它调用运行时）：
    - `_key<T>()`：从 `KeyManager` 读取 key
    - `_lookup<Value>(tableId, lookupType, key)`：调用 `SearchEngine` 并返回 `_inflate<Value>`
    - `_status(tableId)` / `_valid(_inflate<T>)` / `_memcpy(dst, src)` 等
    - `_inflate<T>`：给“表返回结构体”加上 `valid` 标志，模拟 P5 “命中/未命中”语义（未命中时 `valid=false`）
  - `packet.hpp`：**报文视图与解析**（`Packet`）：
    - `data_`：固定长度报文头缓冲（长度由 `model_intf_1027.h` 的 `PKT_HEADER_BYTE_LEN` 决定）
    - `_lookahead(hdr)` / `_extract(hdr)`：将 bit 流解码到生成的 header struct（支持 `p5::uint` / `p5::member` / `p5::Union` 以及它们的聚合嵌套），`_extract` 会推进解析光标
  - `table.hpp`：**表的统一接口**：`class Table { virtual void apply() = 0; }`。生成代码会把 match/action 拆成多个 `Table` 子类并在 control 中串起来。
  - `model_intf_1027.h`：**模型接口与常量**（包头长度、FV 各段宽度、以及仿真入口函数原型等），供运行时/生成代码/测试共享。
- **`src/`**：运行时实现（目前主要是 `KeyManager`、`Table` 的 out-of-line 实现；`SearchEngine` 以模板为主，主要逻辑在头文件里）。
  - `key.cpp`、`table.cpp`、`SE.cpp`
- **`generated/`**：**手工**根据 `.p5` 转写/维护的 C++ 代码（便于对照语义、快速调试，也可直接用来跑测试）。
  - `generated/include/generated_*.hpp`：手工维护的枚举/结构体/常量/上下文等
  - `generated/src/generated_switch.cpp`：手工维护的管线实现（parser + ingress/egress controls + 表封装类等）
- **`out_dir/`**：**编译器自动转换** `.p5` 输出的产物目录（用于验证/回归“自动转换”结果）。
  - 结构同 `generated/`：包含 `include/` 与 `src/`，可用 `OUT_DIR=out_dir` 切换编译链接到“编译器自动生成”的代码。
- **`test/`**：测试与示例驱动（`test/test_*.cpp` 会被 `run_tests.sh` 自动发现并构建运行）。
  - 除顶层测试外，`test/ima0/`、`test/ima1/`、`test/ema0/`、`test/iprs/` 等子目录包含更细分场景的输入/生成产物/对照文件。
- **`bin/`**：构建产物输出目录（可执行文件）。

核心拼装方式（运行时 ↔ 生成代码）
-------------------------------

生成代码里通常会提供一个类似 `Switch` 的上下文类（见 `generated/include/generated_switch.hpp`）：

- `Switch` **同时继承**：
  - `BuiltInContext`：提供 `_key/_lookup/_status/_valid/...`，内部持有 `SearchEngine` 与 `KeyManager`
  - `Packet`：提供 `_extract/_lookahead` 与解析光标
  - `GtvContext`（生成代码提供）：管理/打包/解包 FV/GTV/PHI/PHO 等生成结构
- 生成代码会把每个表拆成 `Table` 子类（例如 `IPAT_TBL`、`FIB_TBL`），`apply()` 中用 `keyBuilder().append(...).commit()` 构 key，然后调用 `ctx.XxxLookup(...)` 完成查表。

内嵌函数（built-in）实现位置速查
------------------------------

为了便于定位“生成代码里调用的内嵌函数/内置接口”到底落在哪个文件，这里列一个速查表：

- **`/GenSim/include/BuiltIn.hpp`**：
  - `_valid()`
  - `_lookup()`
  - `_status()`
  - `_key()`
  - `_memcpy()`
  - `_profile_id()`
  - `_control_info()`
- **`/GenSim/include/packet.hpp`**：
  - `_extract()`
  - `_lookahead()`
  - `_advance()`
  - `_parser_next()`
- **`/GenSim/generated/include/generated_gtv.hpp`**：
  - `_add_to_ngsf()`
- **`_apply()` 的实现方式**：
  - GenSim 里不单独实现一个 `_apply()` 函数；生成的 control/match/action 会**直接调用对应 `Table` 子类的 `apply()`**（也就是 `_apply` 语义通过 `Table::apply()` 的组合来达成）。

构建与运行
----------

### 依赖

- **C++17 编译器**（默认 `g++`）
- `boost::pfr`（`packet.hpp` 与 `p5_types.hpp` 使用，用于反射遍历聚合字段）

### 编译单个测试/示例

在 `GenSim/` 根目录：

- `make TEST=test/test_ima.cpp`
- `./bin/test_ima`

如果要使用 **编译器自动转换**的 `out_dir/` 代码：

- `make OUT_DIR=out_dir TEST=test/test_ima.cpp`
- `./bin/test_ima`

更多目标见：

- `make help`

### 一键跑所有测试

- `make run_tests`
- 或 `make tests`

如何写一个最小驱动（测试示例的共同套路）
-----------------------------------

大多数 `test/test_*.cpp` 都遵循类似流程：

1) **创建生成代码的上下文**（例如 `Switch sw;`）
2) **初始化查表引擎与 key 槽位**（重要：位宽要与生成代码中的 key 拼接总宽一致）
   - `sw.searchEngine().initTable<Key, Value>(tableId, MatchType::...)`
   - `sw.keyManager().initKey({10, 136, ...})`
3) **下发表项**（`config`；LPM 用 `prefixLen`）
4) **准备输入**：
   - 若测试走 parser：填 `sw.data_` 并调用 `sw.ingress()/sw.egress()` 或相关控制函数
   - 若测试走 FV 打包：调用生成代码提供的 `pack_*_to_bytes()` / `unpack_*_from_bytes()`（例如 `test/test_ima.cpp`）
5) **检查输出与状态**：
   - `sw._valid(rs)` / `sw.searchEngine().status(tableId)` / 对字段做断言比对

下面补充几个生成代码（`generated_switch.hpp`）里常见“流程入口”接口的最小用法（可直接拷贝到测试里改参数）：

### `Switch` 流程接口：Prs/Ima/Ema/Ipm/SingleMa

- **`PrsProcPkt(...)`**：把原始 `PktHeader`（报文头缓冲）按 parser 逻辑解析成 `Prs2Ma0FvInfoDef`（FV）。
- **`ImaProcPkt(...)`**：对 ingress 方向的 FV 执行 IMA 处理，输出 `Ima2IpmFvInfoDef`。
- **`EmaProcPkt(...)`**：对 egress 方向的 FV 执行 EMA 处理，输出 `Ema2EpmFvInfoDef`。
- **`SingleMaProc(...)`**：仅运行某一个 MA（`ma_id`）阶段，输入/输出均为 `MaToMaFvInfoDef`。

```cpp
// 示例：Parser -> IMA -> IPM 的串联调用（结构体定义见 model_intf_1027.h）
#include <cstring>   // for std::memcpy

Switch sw;

// 1) 准备原始输入（根据你的场景填充字段）
ParserHwInfo hw{};
hw.port_id = 0;
// hw.port_type / hw.parser_start / ... 视具体测试需要设置

PktHeader pkt{};
// 将报文头拷入 pkt（注意：只会使用 PKT_HEADER_BYTE_LEN 字节）
// std::memcpy(pkt.pkt_data, raw_bytes, raw_len);

NhiDef nhi{};
Cp2NpHeader cp2np{};
Prs2Ma0FvInfoDef fv_prs{};

// 2) Parser：pkt -> fv_prs
sw.PrsProcPkt(/*direction=*/false, hw, nhi, cp2np, pkt, fv_prs);

// 3) IMA：fv_prs -> fv_ima
Ima2IpmFvInfoDef fv_ima{};
sw.ImaProcPkt(/*port_id=*/static_cast<int>(hw.port_id), fv_prs, fv_ima);

// （可选）如果你在验证 egress 分支，可调用：
// Ema2EpmFvInfoDef fv_ema{};
// sw.EmaProcPkt(/*port_id=*/static_cast<int>(hw.port_id), fv_prs, fv_ema);

// （可选）只跑某个 MA 阶段（分段验证时很常用）：
// MaToMaFvInfoDef fv_in{}, fv_out{};
// sw.SingleMaProc(/*ma_id=*/0, /*packet_id=*/"pkt0", /*port_id=*/static_cast<int>(hw.port_id), fv_in, fv_out);
```

常见问题与排查入口
------------------

- **编译报找不到转换代码的头文件**：确认 `OUT_DIR` 指向的目录下存在 `include/` 与 `src/`，且 `Makefile` 已用 `-I$(OUT_DIR)/include`。
- **lookup 一直 miss**：
  - 确认 `KeyManager::initKey` 包含了“总位宽”等于生成代码拼出来 key 的槽位
  - 确认 `SearchEngine::initTable` 的 `Key/Value` 类型与生成代码里 `_lookup<...>` 使用的类型一致
  - 对 LPM：确认 `prefixLen`（msb-first）是否按期望设置
- **parser/extract 结果不对**：
  - `Packet` 以 MSB-first bit 序解码，且光标由 `offset_`(byte) 与 `bit_offset_`(0~7) 共同决定；如果你手工构造报文，注意字节序与位序

