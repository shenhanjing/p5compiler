## p5 预编译器（从 p4c 驱动中抽离）

这个目录提供一个独立的 **P5 预编译** 工具：输入一个目录，递归查找所有 `.p5` 文件，对每个文件运行 C 预处理器生成 `.p4i`，然后把所有 `.p4i` 合并为一个最终的合并文件。

### 对齐的行为（对应命令）

原命令：

```bash
p4c -b bmv2-v1model ./test -o ./out_dir --std p5
```

其中 “P5 预编译” 阶段等价于：

- 输入目录：`./test`
- 输出目录：`./out_dir`
- 合并输出文件：`./out_dir/test_merged.p4i`

### 用法

```bash
cd /root
python3 -m p5compiler.precompiler.p5_precompile ./test -o ./out_dir
```

可选参数：

- `--output-file PATH`：指定合并输出文件路径（默认按输入目录名生成 `<dir>_merged.p4i`）
- `-I PATH`：增加 include 搜索路径（可重复）
- `-D NAME[=VALUE]`：增加宏定义（可重复）
- `--preprocessor CC`：指定预处理器可执行文件（默认 `cc`）
- `--keep-tmp`：保留每个源文件对应生成的中间 `.p4i` 文件（默认会删除，只保留合并文件）

