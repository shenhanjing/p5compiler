
## p5compiler / p5c

`p5c` 是一个从 `p4c` 拆分出来的 **独立 P5 前端工具**：输入 `.p5` 文件路径，先调用 `cpp` 做预处理（支持 `#define/#if/#ifdef`），再解析得到 P5 AST（`IR::P4Program`），最后运行 `runP5ToC` 生成 C++ 代码文件（`include/` + `src/`）。

本目录实现的是 **方案 A（源码级 vendor）**：把 p4c 中所需源码与“预生成产物”复制到 `p5compiler/p5c_src` 并在本工程内编译；**不链接**现成的 p4c 编译产物（例如 `/root/p4c/build/libir.a` 等）。

---

## 环境配置（编译 / 运行所需）

### 编译依赖
- **CMake**: 3.20+
- **C++ 编译器**: GCC/Clang，支持 **C++17**
- **Python 3**: 仅用于你自己的脚本场景（本工程构建不强依赖；可选）
- **网络**: 不需要（Abseil 已以源码形式 vendored 在 `third_party/abseil-src` 并随工程一起编译）

### 运行依赖
- **cpp 预处理器**（必须）：运行时会调用 `cpp`（命令为 `cpp -C -undef -nostdinc -x assembler-with-cpp <input>`）
  - 在 Debian/Ubuntu 上通常来自 `cpp`/`gcc` 包（例如 `cpp`、`gcc`）
- **输入文件约束**
  - 输入应为 **P5 源码**（`.p5`），可以包含 `#define/#if/#ifdef` 等宏指令
  - 不要求 `#include`，但即使没有 include 也仍然会跑预处理以展开宏

---

## 从 p4c 复制过来的“预生成内容”（关键点）

为避免在 `p5compiler` 内部再运行 bison/flex 或 IR 生成器，本工程直接使用了从 `p4c/build` 复制的 **预生成产物**：

### 1) IR 预生成产物（来自 `p4c/build/ir/`）
- `ir-generated.h`
- `ir-generated.cpp`
- `gen-tree-macro.h`

它们被复制到：
- `p5compiler/p5c_src/ir/`

### 2) P5 parser/lexer 预生成产物（来自 `p4c/build/frontends/parsers/p5/`）
- `p5parser.cpp`
- `p5parser.hpp`
- `p5lexer.cc`
- `stack.hh`

它们被复制到：
- `p5compiler/p5c_src/frontends/parsers/p5/`

### 3) 第三方依赖（Abseil 源码，来自 `p4c/build/_deps/abseil-src/`）
- `abseil-src/` 整个目录

它被复制到：
- `p5compiler/third_party/abseil-src/`

> 说明：本工程会在构建时直接 `add_subdirectory(third_party/abseil-src)` 编译 Abseil，而不是去链接系统 Abseil 或 p4c 构建目录里的产物。

---

## 构建方法

在 `p5compiler/` 目录下执行：

```bash
mkdir -p build_p5c
cd build_p5c
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j$(nproc)
```

构建完成后可执行文件为：
- `build_p5c/p5c`

---

## 用法

### 基本用法

```bash
./build_p5c/p5c <input.p5> -o <out_dir>
```

- **input.p5**：P5 源码文件路径
- **-o out_dir**：输出目录；生成文件会写入：
  - `<out_dir>/include/generated_enum.hpp`
  - `<out_dir>/include/generated_struct.hpp`
  - `<out_dir>/include/generated_gtv.hpp`
  - `<out_dir>/include/generated_switch.hpp`
  - `<out_dir>/src/generated_switch.cpp`

### 示例

```bash
rm -rf /root/p5compiler/out_dir
mkdir -p /root/p5compiler/out_dir
/root/p5compiler/build_p5c/p5c /root/p4c/GenSim/test/test.p5 -o /root/p5compiler/out_dir
```

---

## 目录结构（最重要的几个）

- `p5c_src/`：从 p4c vendoring 过来的源码 + 少量“独立化补丁”
- `third_party/abseil-src/`：Abseil 源码（vendored）
- `build_p5c/`：本工具的构建目录

