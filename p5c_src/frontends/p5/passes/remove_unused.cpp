#include "frontends/p5/passes/remove_unused.h"

#include "ir/ir.h"

namespace P4::P5 {

namespace {

class CollectUsedDeclarationsNoClear : public CollectUsedDeclarations {
 public:
    explicit CollectUsedDeclarationsNoClear(UsedDeclSet &used) : CollectUsedDeclarations(used) {}
    profile_t init_apply(const IR::Node *node) override {
        return Inspector::init_apply(node);
    }
};

bool hasAnnotation(const IR::IAnnotated *node, const std::vector<cstring> &annotations) {
    if (node == nullptr) return false;
    for (const auto &anno : annotations) {
        if (node->hasAnnotation(anno)) return true;
    }
    return false;
}

}  // namespace

CollectAnnotatedFunctions::CollectAnnotatedFunctions(UsedDeclSet &used,
                                                     std::vector<cstring> annotations)
    : used(used), entryAnnotations(std::move(annotations)) {
    setName("CollectAnnotatedFunctions");
}

Visitor::profile_t CollectAnnotatedFunctions::init_apply(const IR::Node *node) {
    auto rv = Inspector::init_apply(node);
    used.clear();
    return rv;
}

bool CollectAnnotatedFunctions::preorder(const IR::P4Program *program) {
    CollectUsedDeclarationsNoClear collector(used);
    for (auto decl : program->objects) {
        if (auto func = decl->to<IR::Function>()) {
            if (!hasAnnotation(func, entryAnnotations)) continue;
            used.setUsed(func);
            func->apply(collector);
        }
    }
    return false;
}

RemoveAllUnusedDeclarationsFromAnnotations::RemoveAllUnusedDeclarationsFromAnnotations(
    const RemoveUnusedPolicy &policy, std::vector<cstring> annotations, bool warn)
    : PassRepeated({new CollectAnnotatedFunctions(used, std::move(annotations)),
                    policy.getRemoveUnusedDeclarationsPass(used, warn)}) {
    setName("RemoveAllUnusedDeclarationsFromAnnotations");
    setStopOnError(true);
}

}  // namespace P4::P5

