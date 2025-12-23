GenSim 项目说明
----------------

该目录包含将 P5 程序转换为 C++ 可执行仿真的支撑代码、示例以及生成产物。核心目标是以接近原始 P5 代码的形式运行数据平面逻辑，并提供查表、键构建、数据包解析等运行时能力。

目录结构与作用
--------------
- `Makefile`：构建入口，需通过 `TEST=<path/to/test.cpp>` 指定测试或示例文件，产物输出到 `bin/`。
- `src/`：运行时核心实现的源文件，与 `include/` 中的头文件配套（查表引擎、键管理等）。
- `include/`：公共头文件。
  - `p5_types.hpp`：固定位宽整数类型 `p5::uint<N>` 的实现。
  - `key.hpp`：键管理器 `KeyManager`，负责组合多段 key 并按位宽存取。
  - `SE.hpp`：搜索引擎 `SearchEngine`，支持 INDEX/EXACT/LPM/TCAM 等匹配类型的表项配置与查找。
  - `BuiltIn.hpp`：封装 P5 内置函数行为（_key/_lookup/_status/_valid 等）及 `_inflate` 包装类型。
  - `table.hpp`：P5 表的基类接口 `Table`，声明 `apply()`。
  - `packet.hpp`：报文视图与解析工具，支持 `_lookahead`、`_extract` 以及多种头部字段解码。
  - `model_intf_1027.h`：模型接口与常量定义，供生成代码及运行时共享。
- `generated/`：编译器生成的头/源文件（如 `generated_enum.hpp`、`generated_struct.hpp`、`generated_Switch.*`），承载从 P5 转出的数据结构和管线逻辑。
- `docs/`：设计与实现文档（例如 `design_idea.md`、`conversion_logic.md`、`preP5.md` 等）。
- `test/`：示例与测试用例。包含 P5 源（`.p5`）、对应生成/手写的 C++ 测试（如 `test_ima.cpp`、`test_ingress_full.cpp`），以及分组子目录示例（`ima0/`、`ima1/`、`ema0/` 等）。
- `bin/`：`make` 生成的可执行文件输出目录。

核心组件概览
------------
- 键管理（`KeyManager`）：初始化不同位宽的键槽，支持用 `buildKey` 组合多段键，再通过 `_key<T>()` 按位宽读取。
- 查表引擎（`SearchEngine`）：按表 ID 和匹配类型管理表项，提供 `config`/`lookup` 与 `status`，覆盖 EXACT、LPM、TCAM、INDEX 等模式。
- 内置函数封装（`BuiltInContext`）：面向转换后代码的上下文对象，连接键管理与查表引擎，提供 `_lookup`、`_status`、`_valid`、`_memcpy` 等接口。
- 报文处理（`Packet`）：基于 `model_intf_1027.h` 和生成的结构体，对报文缓冲执行 `_lookahead`、`_extract`，并提供多种协议头的解码辅助。
- 类型系统（`p5::uint<N>`）：支持 1-256 位无符号整数的位运算、切片与基本算术，保持 P5 语义。

构建与运行
----------
1) 在项目根目录执行，例如：
   - `make TEST=test/test_ima.cpp`
   - `make TEST=test/test_ingress_full.cpp`
2) 生成的可执行文件位于 `bin/`，名称取自 `TEST` 的基名。
3) 清理产物：`make clean`

测试与示例
-----------
- `test/test_ima.cpp`、`test/test_preima.cpp`、`test/test_ingress_full.cpp`：针对不同 P5 场景的驱动代码。
- 子目录示例（如 `test/ima0/`, `test/ima1/`, `test/ema0/`）：包含 P5 源、生成的中间文件及对应的 C++。
