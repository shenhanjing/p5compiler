#ifndef FRONTENDS_P5_PASSES_ADD_MAIN_ANNOTATION_H_
#define FRONTENDS_P5_PASSES_ADD_MAIN_ANNOTATION_H_

#include "ir/ir.h"

namespace P4::P5 {

/// Adds a configurable annotation to a specific void function (if found).
class AddMainAnnotation : public Transform {
    cstring targetName;
    cstring annotationName;

    bool matchFunction(const IR::Function *function) const;

 public:
    AddMainAnnotation(cstring targetName, cstring annotationName)
        : targetName(targetName), annotationName(annotationName) {
        CHECK_NULL(targetName);
        CHECK_NULL(annotationName);
        setName("AddMainAnnotation");
    }

    const IR::Node *preorder(IR::Function *function) override;
};

}  // namespace P4::P5

#endif  // FRONTENDS_P5_PASSES_ADD_MAIN_ANNOTATION_H_

