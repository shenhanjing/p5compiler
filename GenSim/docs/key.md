# KeyManager 设计与用法

## 作用
管理多种位宽的 Key 槽。初始化时固定各槽位宽，构建时自动根据输入字段位宽总和选择匹配槽；可按指定位宽读取某槽的值。

## 核心类型与函数
- `KeyPart { uint64_t value; std::size_t bits; }`：单字段及其位宽（高位在前）。
- `KeyManager::initKey(bitWidths)`：设定槽位宽列表（如 `{16, 32, 48}`），会清空已有数据。
- `KeyManager::buildKey(parts)`：将若干 `KeyPart` 依序拼接，位宽之和需与某槽相等；匹配失败则忽略本次构建。
- `KeyManager::KeyBuilder`：增量构建 Key（支持跨多个 switch/分支 append），最后 `commit()` 一次写入槽。
- `KeyManager::getKey<T>(bits)`：按位宽找到对应槽并以类型 `T` 返回（未命中返回 0）。
- `KeyManager::getKeyRaw(bits) -> std::optional<uint64_t>`：返回指定位宽槽的原始值。
- 辅助：`bit_width_of_type<T>()`（定义在 `BuiltIn.h`）。
- 全局实例：`extern KeyManager g_key;`（在 `src/key.cpp` 定义）。

## 使用流程示例
```cpp
// 初始化：声明 16-bit 槽
g_key.initKey({16});

// 构建：按字段位宽总和匹配槽（此处总和 16）
g_key.buildKey({KeyPart{KE0, bit_width_of_type<decltype(KE0)>()}});

// 读取：指定位宽返回
auto k = g_key.getKey<uint16_t>(16);
```

## 多 switch 共同构建同一个 key（增量 append + 最后 commit）
当 table 的 key 字段会在多个 switch/分支里分别决定时，不适合在每个分支直接调用 `buildKey(...)`（它会“写槽”，不会合并多次调用）。
推荐用 `KeyBuilder` 累积 bits，最后在 lookup 前 `commit()` 一次：

```cpp
KeyManager km;
km.initKey({24});

auto kb = km.keyBuilder(); // 或 ctx.keyBuilder()

// switch 1: append 第一段 key
kb.append(p5::uint<8>(0x12));

// switch 2: append 第二段 key
kb.append(p5::uint<16>(0x3456));

// lookup 前：只 commit 一次
kb.commit();

auto key = km.getKey<p5::uint<24>>(24);
```

## 设计要点与限制
- 以“位宽总和 == 某槽位宽”确定目标槽，不需显式指定槽位索引。
- 拼接顺序即传入顺序，高位在前；单字段位宽目前示例限制在 64bit 以内。
- 未做线程安全；类型读取需调用方确保与槽位宽一致。***

## 切片赋值给结构体
用“专用特化/宏”在编译期写死字段序，运行时按位切片填充，不需要在调用点显式写成员名。在P5转换过程中自动生成。示例思路：

```cpp
// 帮助函数：从高到低切一段 bits，再用 p5::uint<W>::from_bits 重建
template <std::size_t W, std::size_t Total>
p5::uint<W> slice_segment(const p5::uint<Total> &key, std::size_t high_exclusive) {
    std::vector<bool> bits;
    bits.reserve(W);
    for (std::size_t i = 0; i < W; ++i) {
        bits.push_back(key[high_exclusive - 1 - i]); // 高 -> 低
    }
    return p5::uint<W>::from_bits(bits); // from_bits 期望高->低输入
}

// 结构体示例
struct MyKey {
    p5::uint<3> f1;
    p5::uint<5> f2;
};

// 专用特化：告诉框架如何把总 key 拆回 MyKey
template <>
struct KeyUnpack<MyKey> {
    static constexpr std::size_t total_width =
        decltype(MyKey{}.f1)::width() + decltype(MyKey{}.f2)::width();

    static MyKey from_key(const p5::uint<total_width> &key) {
        MyKey out{};
        std::size_t pos = total_width;
        auto take = [&](auto &field) {
            constexpr std::size_t W = std::decay_t<decltype(field)>::width();
            std::size_t hi = pos;
            pos -= W;
            field = slice_segment<W>(key, hi);
        };
        take(out.f1);
        take(out.f2);
        return out;
    }
};
```

使用时：

```cpp
p5::uint<8> rawKey = ...;      // 已拼好的 3+5 位 key
MyKey mk = KeyUnpack<MyKey>::from_key(rawKey); // 自动按顺序切片填充
```

如果不想每个特化都手写 `take(out.fX);`，可加一个小宏减少样板：

```cpp
#define TAKE_FIELD(obj, field, pos, key)                        \
    do {                                                        \
        constexpr std::size_t W = std::decay_t<decltype((obj).field)>::width(); \
        std::size_t hi = (pos);                                 \
        (pos) -= W;                                             \
        (obj).field = slice_segment<W>((key), hi);              \
    } while (0)

template <>
struct KeyUnpack<MyKey> {
    static constexpr std::size_t total_width =
        decltype(MyKey{}.f1)::width() + decltype(MyKey{}.f2)::width();

    static MyKey from_key(const p5::uint<total_width> &key) {
        MyKey out{};
        std::size_t pos = total_width;
        TAKE_FIELD(out, f1, pos, key);
        TAKE_FIELD(out, f2, pos, key);
        return out;
    }
};
```

要点：
- 需要为每个“已知字段序”的结构体写一份特化或用宏列出字段顺序。
- 不可直接 memcpy 整个 key 到 struct，因为 `p5::uint<N>` 内部是 `std::bitset`，布局与目标位串不同。

