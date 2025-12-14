# KeyManager 设计与用法

## 作用
管理多种位宽的 Key 槽。初始化时固定各槽位宽，构建时自动根据输入字段位宽总和选择匹配槽；可按指定位宽读取某槽的值。

## 核心类型与函数
- `KeyPart { uint64_t value; std::size_t bits; }`：单字段及其位宽（高位在前）。
- `KeyManager::initKey(bitWidths)`：设定槽位宽列表（如 `{16, 32, 48}`），会清空已有数据。
- `KeyManager::buildKey(parts)`：将若干 `KeyPart` 依序拼接，位宽之和需与某槽相等；匹配失败则忽略本次构建。
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

## 设计要点与限制
- 以“位宽总和 == 某槽位宽”确定目标槽，不需显式指定槽位索引。
- 拼接顺序即传入顺序，高位在前；单字段位宽目前示例限制在 64bit 以内。
- 未做线程安全；类型读取需调用方确保与槽位宽一致。***

