#ifndef FRONTENDS_P5_PARSE_ANNOTATIONS_H_
#define FRONTENDS_P5_PARSE_ANNOTATIONS_H_

#include "ir/ir.h"

namespace P4::P5 {

/// 解析并展开 P5 注解（iMA）
/// 扫描名称以 `pre_iMA` 开头的函数，定位 `P5Table` 的声明及其 `_apply(table)`；
/// 将前后代码分别抽取为辅助函数 `<name>_MA0`/`<name>_MA1`，原函数仅保留表声明与调用；
/// 并重写全程序调用点，在调用该函数前后插入辅助函数，递归处理块、if、switch。
void parseAnnotations(IR::P4Program *program);

/// 聚合顶层变量生成 `metadata_t`
/// 若不存在 `metadata_t`，收集所有 `Type_Bits`/`Type_Stack` 变量为结构字段，
/// 创建 `Type_Struct("metadata_t")` 并追加到 `program->objects`。
void packMetadata(IR::P4Program *program);

void enumToUint(IR::P4Program *program);

void normalizeAnonStructUnion(IR::P4Program *program);
}

#endif
