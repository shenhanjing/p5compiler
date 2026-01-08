#ifndef FRONTENDS_P5_PASSES_REMOVE_UNUSED_H_
#define FRONTENDS_P5_PASSES_REMOVE_UNUSED_H_

#include <vector>

#include "frontends/p4/unusedDeclarations.h"

namespace P4::P5 {

/// Collect used declarations starting from functions with specific annotations.
class CollectAnnotatedFunctions : public Inspector {
    UsedDeclSet &used;
    std::vector<cstring> entryAnnotations;

 public:
    CollectAnnotatedFunctions(UsedDeclSet &used, std::vector<cstring> annotations);

    Visitor::profile_t init_apply(const IR::Node *node) override;
    bool preorder(const IR::P4Program *program) override;
};

/// Remove unused declarations using annotated functions as roots.
class RemoveAllUnusedDeclarationsFromAnnotations : public PassRepeated {
    UsedDeclSet used;

 public:
    RemoveAllUnusedDeclarationsFromAnnotations(const RemoveUnusedPolicy &policy,
                                               std::vector<cstring> annotations, bool warn = false);
};

}  // namespace P4::P5

#endif  // FRONTENDS_P5_PASSES_REMOVE_UNUSED_H_

