# BuiltIn 说明

`BuiltIn.h` 汇总了在试验代码中使用的基础辅助函数和包装结构，便于复用。

## 提供的能力
- `bit_width_of_type<T>()`：获取类型的位宽（`sizeof(T)*8`）。
- `_inflate<T>`：在原有结构体基础上增加 `valid` 标志，用于表示查表命中与否；
  - 从值构造/赋值：`valid=true`
  - 从 `std::nullopt` 或 `{0}` 构造：字段清零，`valid=false`
  - 其他非零 brace-init：字段清零，首元素写入低位，`valid=true`
- `_key<T>()`：按类型位宽从全局 `g_key` 读取当前 key。
- `_status(tableId)`：读取全局 `g_se` 中指定表的最近状态。
- `_lookup<Value, Key>(tableId, lookupType, key)`：将外部 lookupType 直接 cast 为 `MatchType`，调用全局 `g_se` 查表，命中返回 `valid=true` 的 `_inflate<Value>`，未命中返回 `valid=false`。
- `_valid(const _inflate<T>&)`：便捷判断命中标志。
- `_memcpy(dst, src)`：简单的赋值封装，便于与 P5 语义对应。

## 依赖
- 头文件依赖：`key.h`（提供 `g_key`）、`SE.h`（提供 `g_se`、`MatchType`）。
- 假设外部定义了与目标类型匹配的 `g_key`/`g_se` 全局实例。

## 典型用法
```cpp
// 读取 key
auto key = _key<uint16_t>();

// 查表
auto rsp = _lookup<LURSP_S>(tableId, TBL_LKUP_TYPE_INDEX, key);
if (_valid(rsp)) { /* 命中 */ } else { /* 未命中 */ }

// 拷贝包装值
_inflate<LURSP_S> dst;
_memcpy(dst, rsp);
```

## 设计注意
- `lookupType` 必须与 `MatchType` 数值对齐（工程中已在 `MatchType` 上显式指定与 TLB 枚举一致的数值）。
- `_inflate` 以继承方式暴露原字段，直接访问 `Rsp_0/ Rsp_1` 等成员，同时用 `valid` 表征命中。

