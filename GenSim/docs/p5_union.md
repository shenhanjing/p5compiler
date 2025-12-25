# p5::Union —— 按位 Overlay 的“确定行为 union”

本文档描述 `p5::Union`（以及配套的 `p5::member` 与宏工厂）在 GenSim 中的实现方法、语义规则、支持能力与使用方式。代码实现位于：

- `GenSim/include/p5_types.hpp`
- 测试/示例位于 `GenSim/test/test_uint_union.cpp`

> 说明：C++ 中 `union` 是关键字，因此类型命名为 `p5::Union`（首字母大写），不是 `p5::union`。

---

## 目标与动机

原生 C++ `union` 读取非活动成员是未定义行为（UB），这会导致“把最宽成员写进去，再从窄成员/结构体成员读出来”这种行为不可移植、不可依赖。

`p5::Union` 的目标是提供一个 **确定行为** 的“位级 overlay”类型：

- 只有一份底层 bit 存储
- 顶层成员像 union 一样从 bit0 开始 overlay 到同一份存储
- 成员可以是：
  - `p5::uint<N>` 的位视图（通过 `p5::member<p5::uint<N>>`）
  - 另一个 `p5::Union<...>`（嵌套 union）
  - 由上述成员组成的 **聚合结构体（aggregate struct）**（可嵌套）
- 结构体内部字段按声明顺序顺次排布（类似“打包结构体/bitfield pack”）

---

## 关键类型一览

### `p5::member<p5::uint<N>>`：按位成员视图

`p5::member<T>` 是一个“视图成员”，它本身不拥有 bits，而是绑定到某个底层存储的某段 bit 区间。

当前实现仅支持：

- `T = p5::uint<N>`

典型用途：在 `p5::Union` 或 aggregate struct 里，把字段声明成 `p5::member<p5::uint<N>>`，使其成为可读写的位段映射。

### `p5::Union<Layout>`：确定行为 union

`p5::Union<Layout>` 继承自 `Layout`，因此你可以用 `u.field` 访问布局里的字段。

`Layout` 必须是 **aggregate**（Boost.PFR 需要），并且它的字段只能由下列类型递归组成：

- `p5::member<p5::uint<N>>`
- `p5::Union<OtherLayout>`
- aggregate struct（字段递归满足上述限制）

---

## 位布局规则（最重要的语义）

### 1) bit 编号与方向

与 `p5::uint<N>` 一致：

- **bit0 是最低位（LSB）**
- `member` 的第 i 位对应底层存储的 `offset + i`

### 2) `Union` 的底层存储位宽

`p5::Union<Layout>` 的底层存储类型为：

- `p5::uint<width>`

其中 `width` 定义为：

- `width = max( bit_width(field_i) )`，对 `Layout` 顶层所有字段取最大值
- 若某字段是 struct，则它的位宽按 “结构体整体” 计算（见下一节）

因此：顶层字段像 union 成员一样都从 bit0 overlay；谁最宽，谁决定底层存储宽度。

### 3) 顶层字段：全部从 offset=0 开始 overlay

对于 `Layout` 的每一个顶层字段：

- 字段绑定到同一份底层存储
- 字段的 base offset = 0

这就是 union 语义：多个视图覆盖同一份 bits。

### 4) struct（aggregate）字段：内部按声明顺序顺排

若某个字段是 aggregate struct，则它内部的字段按声明顺序顺次排布：

- 第 0 个子字段 offset = base
- 第 1 个子字段 offset = base + width(字段0)
- 第 2 个子字段 offset = base + width(字段0)+width(字段1)
- ...

结构体整体位宽为所有字段位宽之和，并支持递归嵌套。

---

## 支持的读写与表达式能力

### 1) `p5::member` 的赋值/读取

支持：

- `member = p5::uint<N>(...)`
- `member = p5::uint<M>(...)`：复制低位，若成员更宽则剩余位清 0
- `member = integral`：按低位写入（基于 `uint64_t`）
- `p5::uint<N> x = member;`：隐式读取为 `p5::uint<N>`
- `member.to_ullong()`：直接读取（调试/测试常用）

> 注意：`p5::uint<N>::to_ullong()` 仅适用于 N≤64 的场景（由 `std::bitset::to_ullong()` 限制）。

### 2) `p5::member` 的“像变量一样”运算

为了让 `member` 在表达式里更像一个独立变量，`member` 提供了常用运算符：

- 与 `member` / `p5::uint<N>` / integral 的比较：`== != < <= > >=`
- 加法：`member + (member/uint/integral) -> p5::uint<N>`

原因：C++ 在选择运算符候选时并不会因为“可隐式转换成 `p5::uint<N>`”就自动把 `p5::uint` 的成员运算符纳入候选集，因此需要在 `member` 自身补齐这些重载。

### 3) `p5::Union` 作为整体读写

`p5::Union<Layout>` 支持把整个 union 当作一个 `p5::uint<Union::width()>` 来用：

- `u = p5::uint<M>(...)`：写入底层 bits（低位复制，剩余清 0）
- `u = integral`：写入底层 bits（基于 `uint64_t`）
- `p5::uint<width> raw = u;` 或 `u.to_uint()`

拷贝构造/赋值会复制 bits，并保证所有视图重新绑定到新对象的存储上（不会“指向旧对象”）。

---

## 使用方法与示例

以下示例都可以在 `test/test_uint_union.cpp` 中找到对应版本并直接运行。

### 示例 1：基本 overlay（long/short + struct slice）

```cpp
struct St {
  p5::member<p5::uint<3>> a;
  p5::member<p5::uint<3>> b;
};

struct ULayout {
  p5::member<p5::uint<10>> long_;
  p5::member<p5::uint<2>>  short_;
  St st;
};

p5::Union<ULayout> u{};
u.long_ = p5::uint<10>(0b1010110011);

p5::uint<2> s = u.short_;     // bits0..1
p5::uint<3> a = u.st.a;       // bits0..2
p5::uint<3> b = u.st.b;       // bits3..5
```

### 示例 2：整型直接赋值 + 不显式转换读取/比较/算术

```cpp
p5::Union<ULayout> u{};
u.st.a = 7;      // integral 赋值
u.short_ = 3;    // integral 赋值

auto x = u.short_.to_ullong();  // 不做类型转换直接读取
bool ok = (u.short_ == 3);      // 直接比较
auto y = u.short_ + 1;          // 直接算术，结果是 p5::uint<2>
```

### 示例 3：复杂嵌套（Union + struct + Union，多层嵌套）

`test_uint_union.cpp` 中包含一个复杂布局：顶层 union 同时包含 uint 成员、struct 成员、union 成员；struct 内部又嵌套 union；并对写回效果做验证。

---

## 宏工厂：用“匿名 layout”写法快速声明

因为 C++ 不允许 `p5::Union<{...}>` 这种模板实参写法，我们提供宏工厂来减少具名 struct 的样板代码。

### 1) `P5_MAKE_UNION({ ... })`：返回一个 union 对象（表达式）

```cpp
auto u = P5_MAKE_UNION({
  p5::member<p5::uint<10>> long_;
  p5::member<p5::uint<2>>  short_;
});
```

### 2) `P5_DECLARE_UNION(name, { ... })`：声明一个具名变量

```cpp
P5_DECLARE_UNION(U, {
  p5::member<p5::uint<10>> long_;
  p5::member<p5::uint<2>>  short_;
});
```

### 3) `P5_UNION(name, { ... })`：一个宏同时支持“声明变量”和“声明嵌套成员”

`P5_UNION(name, { ... })` 可用于：

- 在函数/全局作用域声明一个 `p5::Union` 变量
- 在 layout/struct 内声明一个嵌套 `p5::Union` 成员

`P5_DECLARE_UNION` 与 `P5_UNION_MEMBER` 仍然保留，但都已变为 `P5_UNION` 的别名，推荐直接使用 `P5_UNION`。

在 `P5_MAKE_UNION` 的 layout body 里，必须写“成员声明”，因此 **不支持**：

```cpp
// ❌ 错误：struct 成员里不能用 auto 声明非静态数据成员
auto alt = P5_MAKE_UNION({ ... });
```

正确方式是用 `P5_UNION`（或兼容别名 `P5_UNION_MEMBER`）：

```cpp
auto u = P5_MAKE_UNION({
  p5::member<p5::uint<16>> whole;
  P5_UNION(alt, {
    p5::member<p5::uint<6>> low6;
    p5::member<p5::uint<12>> low12;
  });
});
```

---

## 实现方法（代码结构概览）

实现核心在 `p5_types.hpp` 的 union 区域：

- **bit 访问抽象 `detail_p5_union::bit_access`**：
  - 把“从某个存储读/写 bit i”的能力抽象成函数指针（get/set）+ ctx
  - 当前 ctx 指向 `p5::uint<Bits>` 存储对象

- **位宽计算 `bit_width<T>`**：
  - `bit_width<p5::uint<N>> = N`
  - `bit_width<p5::member<p5::uint<N>>> = N`
  - `bit_width<aggregate struct> = sum(bit_width(fields...))`（Boost.PFR 展开）
  - `bit_width<p5::Union<Layout>> = Union::width()`

- **绑定器 `detail_union_binder`**：
  - 顶层字段：offset=0 绑定到同一份存储（union overlay）
  - struct 字段：递归遍历字段并做 prefix-sum offset 绑定（顺排）
  - nested `p5::Union`：把外部的 `bit_access` 与 base offset 传入，让其作为 view 绑定到外部存储

- **`p5::Union` 自身**：
  - 默认拥有 `storage_`（一个 `p5::uint<width>`）
  - 构造时创建 `bit_access` 指向该存储，并调用 binder 完成所有成员视图绑定
  - 复制/赋值时复制 bits，并重新绑定

---

## 限制与注意事项

- **位宽上限**：最终底层存储是 `p5::uint<width>`，当前 `p5::uint` 限制为 `N<=256`，因此 union 的最大宽度也受限于 256。
- **aggregate 限制**：`Layout` 及其嵌套 struct 必须是 aggregate（Boost.PFR 要求）。
- **可作为位视图的字段**：必须使用 `p5::member<p5::uint<N>>`；直接 `p5::uint<N>` 只是一个普通字段，不会自动 overlay 到 union 的底层存储。
- **`to_ullong()` 限制**：仅适用于位宽 ≤64 的调试/测试。

---

## 相关测试

推荐直接阅读/运行：

- `GenSim/test/test_uint_union.cpp`

构建运行：

```bash
cd /root/p5compiler/GenSim
make TEST=test/test_uint_union.cpp
./bin/test_uint_union
```


