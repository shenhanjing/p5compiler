#include "frontends/p5/passes/typeChecking/typeChecker.h"

namespace P4::P5 {

const IR::Node *TypeInference::postorder(IR::ReturnStatement *statement) {
    auto func = findOrigCtxt<IR::Function>();
    if (func != nullptr && statement->expression != nullptr) {
        auto ftype = getType(func);
        if (ftype != nullptr && ftype->is<IR::Type_Method>()) {
            auto mt = ftype->to<IR::Type_Method>();
            auto returnType = mt->returnType;
            CHECK_NULL(returnType);
            if (returnType->is<IR::Type_Void>()) {
                auto exprType = getType(statement->expression);
                if (exprType == nullptr) return statement;
                if (!exprType->is<IR::Type_Void>()) {
                    typeError("%1%: return expression in function with void return", statement);
                    return statement;
                }

                auto expr = statement->expression;
                statement->expression = nullptr;

                if (auto mce = expr->to<IR::MethodCallExpression>()) {
                    auto block = new IR::BlockStatement(statement->srcInfo);
                    block->components.push_back(new IR::MethodCallStatement(mce->srcInfo, mce));
                    block->components.push_back(
                        new IR::ReturnStatement(statement->srcInfo, nullptr));
                    return block;
                }

                // If it's not a method call, fall back to the base behavior which will
                // signal an error.
                statement->expression = expr;
            }
        }
    }

    return P4::TypeInference::postorder(statement);
}

}  // namespace P4::P5

