#ifndef FRONTENDS_P5_TYPECHECKING_TYPECHECKER_H_
#define FRONTENDS_P5_TYPECHECKING_TYPECHECKER_H_

#include "frontends/p4/typeChecking/typeChecker.h"

namespace P4::P5 {

/// P5-specific TypeInference that allows returning void-valued expressions
/// (e.g. `return foo();` where `foo` returns void) from void functions by
/// rewriting them into `foo(); return;`.
class TypeInference : public P4::TypeInference {
 public:
    using P4::TypeInference::TypeInference;

    const IR::Node *postorder(IR::ReturnStatement *statement) override;
};

}  // namespace P4::P5

#endif  // FRONTENDS_P5_TYPECHECKING_TYPECHECKER_H_

