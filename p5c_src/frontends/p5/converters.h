#ifndef FRONTENDS_P5_CONVERTERS_H_
#define FRONTENDS_P5_CONVERTERS_H_

#include <typeindex>
#include <typeinfo>

#include "frontends/p4-14/fromv1.0/programStructure.h"
#include "frontends/p4-14/fromv1.0/v1model.h"
#include "frontends/p4/coreLibrary.h"
#include "ir/dump.h"
#include "ir/ir.h"
#include "ir/pass_manager.h"
#include "lib/safe_vector.h"

namespace P4::P5 {

/// P5 程序结构管理类
/// 负责收集 P5 程序中的组件，包含 v1model.p4，并生成 V1Switch main
class P5ProgramStructure {
 public:
    P4V1::V1Model &v1model;
    P4::P4CoreLibrary &p4lib;

    // 存储所有生成的声明（包括 v1model.p4 的内容）
    IR::Vector<IR::Node> *declarations;

    // 从 P5 IR 中提取的组件
    const IR::P4Parser *parser_i = nullptr;   // ingress parser
    const IR::P4Parser *parser_e = nullptr;   // egress parser
    const IR::P4Control *verifyChecksum = nullptr;
    const IR::P4Control *ingress = nullptr;
    const IR::P4Control *egress = nullptr;
    const IR::P4Control *computeChecksum = nullptr;
    const IR::P4Control *deparser = nullptr;

    P5ProgramStructure();

    /// 包含 v1model.p4
    void loadModel();

    /// 通用的包含文件方法
    void include(cstring filename, cstring ppoptions = cstring());

    /// 从 P5 IR 中提取组件
    void extractComponents(const IR::P4Program *p5Program);

    /// 生成最终的 P4Program（包含 v1model.p4 和 V1Switch main）
    const IR::P4Program *create(Util::SourceInfo info);

    /// 生成 V1Switch(...) main; 声明（支持双 parser）
    void createMain();

    /// 辅助方法：创建空的 parser
    const IR::P4Parser *createEmptyParser(cstring name);

    /// 辅助方法：创建空的 control（用于 ingress/egress，3个参数）
    const IR::P4Control *createEmptyControl(cstring name);

    /// 辅助方法：创建空的 checksum control（用于 verifyChecksum/computeChecksum，2个参数）
    const IR::P4Control *createEmptyChecksumControl(cstring name);

    /// 辅助方法：创建空的 deparser（参数签名不同于普通 control）
    const IR::P4Control *createEmptyDeparser(cstring name);

    /// 辅助方法：确保必需的类型定义存在（headers, metadata）
    void ensureRequiredTypes();

    /// 辅助方法：检查类型是否已定义
    bool isTypeDefined(cstring typeName);
};

/// 从 P5 IR 中提取组件的 Inspector
/// 注意：当前未使用，因为 InjectV1Model 内部会调用 extractComponents()
/// 保留此类供将来可能的优化使用
class ExtractComponents : public Inspector {
 public:
    P5ProgramStructure *structure;

    explicit ExtractComponents(P5ProgramStructure *structure) : structure(structure) {
        CHECK_NULL(structure);
        setName("ExtractComponents");
    }

    bool preorder(const IR::P4Parser *parser) override;
    bool preorder(const IR::P4Control *control) override;
};

/// P5 转换器的主 Pass
/// 将 P5 IR（已经是 P4-16 格式）添加 v1model.p4 和 V1Switch main
class InjectV1Model : public Transform {
 public:
    P5ProgramStructure *structure;

    explicit InjectV1Model(P5ProgramStructure *structure) : structure(structure) {
        CHECK_NULL(structure);
        setName("InjectV1Model");
    }

    const IR::Node *preorder(IR::P4Program *program) override;
};

/// P5 到 P4-16 的转换器
class Converter : public PassManager {
 public:
    P5ProgramStructure *structure;

    Converter();
};

}  // namespace P4::P5

#endif /* FRONTENDS_P5_CONVERTERS_H_ */
