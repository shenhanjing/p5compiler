# SearchEngine 设计与用法

## 作用
集中管理按表 ID 分组的查表逻辑。每个表可有自己的键类型与返回类型，并支持按匹配类型（当前实现 INDEX，其它类型占位）进行查询。

## 核心类型
- `MatchType`（数值与 `TLB_LKUP_TYPE_E` 对齐）：`INDEX=0, EXACT=1, LPM=3, TCAM=4`
- `SearchEngine::Status`：`MATCH / NO_MATCH / LOOKUP_SKIPPED / ERROR`

## 全局实例
- `extern SearchEngine g_se;`（在 `src/SE.cpp` 定义）

## 主要接口
- `initTable<Key, Value>(tableId, matchType)`：创建/重建指定 ID 的表，固定键/值类型与匹配类型。
- `config<Key, Value>(tableId, key, value)`：配置表项。键存在则覆盖。类型或匹配类型不符会将状态置为 `ERROR` 并跳过。
- `lookup<Key, Value>(tableId, matchType, key) -> std::optional<Value>`：按键查询；命中返回值，未命中返回 `nullopt`，并记录最近状态。
- `status(tableId) -> Status`：获取指定表 ID 最近一次查询/配置的状态（若表不存在返回 `LOOKUP_SKIPPED`）。

## 使用流程示例
```cpp
// 初始化：键/值类型与匹配类型
g_se.initTable<uint16_t, LURSP_S>(SE_TID_LU, MatchType::INDEX);

// 配置表项（可覆盖）
g_se.config<uint16_t, LURSP_S>(SE_TID_LU, 0, LURSP_S{1, 2});

// 查询
auto rspOpt = g_se.lookup<uint16_t, LURSP_S>(SE_TID_LU, MatchType::INDEX, key);
auto st = g_se.status(SE_TID_LU); // MATCH / NO_MATCH / ERROR ...
```

## 设计要点
- 按表 ID 存储不同的键/值类型，运行时使用 `std::type_index` 校验，避免类型混用。
- 当前仅 `INDEX` 有实际逻辑，`EXACT/LPM/TCAM` 复用索引表实现，可在对应派生类中扩展。
- `config` 覆盖同键表项；尚未提供删除单键接口，如需清空可重新 `initTable`。***

