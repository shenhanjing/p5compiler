#include "frontends/p5/passes/add_main_annotation.h"

namespace P4::P5 {

bool AddMainAnnotation::matchFunction(const IR::Function *function) const {
    if (function == nullptr) return false;
    if (function->name != targetName) return false;

    auto type = function->type;
    if (type == nullptr) return false;
    auto mt = type->to<IR::Type_Method>();
    if (mt == nullptr) return false;
    auto returnType = mt->returnType;
    if (returnType == nullptr) return false;
    return returnType->is<IR::Type_Void>();
}

const IR::Node *AddMainAnnotation::preorder(IR::Function *function) {
    if (!matchFunction(function)) return function;

    for (const auto *anno : function->annotations) {
        if (anno->name == annotationName) return function;
    }

    auto clone = function->clone();
    auto annotations = clone->annotations;
    IR::Vector<IR::Expression> args;
    annotations.push_back(
        new IR::Annotation(IR::ID(function->srcInfo, annotationName), args));
    annotations.srcInfo = function->annotations.srcInfo;
    clone->annotations = annotations;
    return clone;
}

}  // namespace P4::P5

