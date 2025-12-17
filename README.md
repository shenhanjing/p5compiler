# P5toC Runtime Library

P5到C++转换的运行时支撑库，提供完整的P5程序运行时环境，包括Parser（解析器）和Table（匹配-动作表）的运行时支持。

## 项目概述

本项目合并了以下两个项目的功能：
- **MA项目**：提供Table（匹配-动作表）的运行时支撑
- **demo_c项目**：提供Parser（数据包解析器）的功能

合并后的项目提供完整的P5→C++转换运行时支撑，支持：
- P5 Parser的解析功能
- P5 Table的查表和执行功能
- 统一的类型系统和接口定义

## 目录结构

```
P5toC/
├── include/              # 头文件目录
│   ├── BuiltIn.hpp      # P5内置函数包装
│   ├── key.hpp          # 键管理器
│   ├── SE.hpp           # 查表引擎
│   ├── table.hpp        # 表基类
│   ├── parser_base.hpp  # 解析器基类
│   ├── parser.hpp       # Parser实现
│   ├── extract.h        # Header提取函数
│   ├── headers.hpp      # Header定义
│   ├── fv.hpp           # FV相关
│   ├── fv_structs.hpp   # FV结构体
│   ├── serializer.hpp   # 序列化
│   ├── p5_types.hpp     # P5类型系统
│   └── model_intf_1027.h # 接口定义
├── src/                  # 源代码目录
│   ├── key.cpp          # 键管理器实现
│   ├── SE.cpp           # 查表引擎实现
│   ├── table.cpp        # 表基类实现
│   ├── parser.cpp       # Parser实现
│   └── parser_interface.cpp # Parser接口实现
├── docs/                 # 文档目录
│   ├── builtin.md       # 内置函数说明
│   ├── conversion_logic.md # 转换逻辑
│   ├── design_idea.md   # 设计思路
│   └── ...
├── test/                 # 测试目录
│   ├── test_parser.cpp  # Parser测试
│   └── tb/              # Table测试
│       ├── main.cpp
│       └── generated/   # 生成的代码
├── bin/                  # 构建输出目录（自动创建）
├── Makefile             # 构建文件
└── README.md            # 本文件
```

## 核心功能模块

### 1. 类型系统 (p5_types.hpp)
- `p5::uint<N>`：固定位宽整数类型（支持1-256位）
- 提供位切片、算术运算、位运算等功能

### 2. 键管理系统 (key.hpp, key.cpp)
- `KeyManager`：全局键管理器（`g_key`）
- 支持多部分键的构建和管理
- 支持多种位宽的键存储

### 3. 查表引擎 (SE.hpp, SE.cpp)
- `SearchEngine`：全局查表引擎（`g_se`）
- 支持多种匹配类型：INDEX, EXACT, LPM, TCAM
- 按表ID管理不同的查表操作

### 4. 内置函数 (BuiltIn.hpp)
- `_key<T>()`：获取键值
- `_lookup<Value, Key>()`：执行查表
- `_status()`：获取查表状态
- `_inflate<T>`：包装结构体，添加valid标志
- `_valid()`：判断查表是否命中

### 5. Parser支持 (parser_base.hpp, parser.hpp)
- `ParserBase`：Parser基类
- `ParserImpl`：Parser实现类
- 支持数据包解析和Header提取

### 6. Table支持 (table.hpp)
- `Table`：Table基类
- 提供`apply()`虚函数接口

## 构建说明

### 环境要求
- C++17或更高版本的编译器（g++推荐）
- Make工具

### 构建选项

#### 1. 构建Parser测试
```bash
make parser-test
```
构建结果：`bin/test_parser`

#### 2. 构建Table测试
```bash
make table-test TEST=test/tb/main.cpp
```
构建结果：`bin/main`（根据测试文件名）

#### 3. 构建所有组件
```bash
# 只构建Parser测试
make all

# 同时构建Parser和Table测试（需要指定TEST变量）
make all TEST=test/tb/main.cpp
```

#### 4. 查看帮助
```bash
make help
```

#### 5. 清理构建文件
```bash
make clean
```

## 使用示例

### Parser使用
```cpp
#include "model_intf_1027.h"
#include "parser.hpp"

// 调用Parser接口
PrsProcPkt(false, parser_hinfo, nhi_info, cp2np_hdr, pkt_hdr, fv_info);
```

### Table使用
```cpp
#include "BuiltIn.hpp"
#include "SE.hpp"
#include "key.hpp"

// 初始化键管理器
g_key.initKey({10});

// 初始化查表引擎
g_se.initTable<p5::uint<10>, ResponseType>(tableId, MatchType::INDEX);

// 配置表项
g_se.config<p5::uint<10>, ResponseType>(tableId, key, value);

// 执行查表
auto result = _lookup<ResponseType>(tableId, lookupType, key);
if (_valid(result)) {
    // 命中处理
}
```

## 设计说明

### Table转换设计
- P5 Table转换为继承`Table`基类的C++类
- Table体逻辑放在`apply()`方法中
- Key构建使用全局`g_key`对象
- 查表操作使用全局`g_se`对象

### Parser转换设计
- P5 Parser转换为继承`ParserBase`的C++类
- 实现`PrsProcPkt`接口方法
- 使用`extract()`函数提取Header
- 使用`serializer`进行数据打包

### 类型转换
- P5的`_compressed_type`转换为`_inflate<type>`
- `_apply(tb)`转换为`tb.apply()`
- `_key()`使用模板参数指定类型

## 文档

详细的设计文档和说明请参考`docs/`目录：
- `design_idea.md`：设计思路
- `conversion_logic.md`：转换逻辑说明
- `builtin.md`：内置函数说明
- `search_engine.md`：查表引擎说明

## 许可证

[根据实际情况添加许可证信息]

## 贡献

[根据实际情况添加贡献指南]

