#include "frontends/p5/passes/tableTransfer.h"

#include <unordered_map>
#include <unordered_set>

#include "lib/error.h"

namespace P4::P5 {

namespace {

/// Recursively process a block, performing the ApplyTTTransform logic.
const IR::BlockStatement *processTTBlock(
    const IR::BlockStatement *block,
    const std::unordered_set<cstring> &ttStructs,
    std::unordered_map<cstring, const IR::Declaration_Variable *> &recordedDecls) {
    if (block == nullptr) return nullptr;

    IR::IndexedVector<IR::StatOrDecl> newComponents;

    for (auto comp : block->components) {
        // Recurse into nested blocks first.
        if (auto *nested = comp->to<IR::BlockStatement>()) {
            auto *nestedNew = processTTBlock(nested, ttStructs, recordedDecls);
            newComponents.push_back(nestedNew ? nestedNew : nested);
            continue;
        }

        // Handle declarations of variables of TT_p4c-annotated struct types,
        // where the initializer is a function call.
        if (auto *var = comp->to<IR::Declaration_Variable>()) {
            auto *tn = var->type->to<IR::Type_Name>();
            auto *init = var->initializer;
            auto *mc = init ? init->to<IR::MethodCallExpression>() : nullptr;
            auto *pe = mc ? mc->method->to<IR::PathExpression>() : nullptr;

            // Only handle declarations whose type is a TT_p4c struct AND are initialized
            // by a function/method call with a simple path callee.
            if (tn && ttStructs.count(tn->path->name) > 0 && mc && pe) {
                const IR::Expression *newInit = init;

                auto origName = pe->path->name;
                auto newId = IR::ID(origName.toString() + "_f");
                auto *newMethod = new IR::PathExpression(newId);
                auto *newCall =
                    new IR::MethodCallExpression(mc->srcInfo, newMethod, mc->arguments);
                newInit = newCall;

                auto *newVar = var->clone()->to<IR::Declaration_Variable>();
                newVar->initializer = newInit;

                // Record this declaration and remove original from current position.
                recordedDecls[var->name] = newVar;
                continue;
            }
        }

        // Replace `_apply(var)` calls with recorded declarations, if any.
        if (auto *mcs = comp->to<IR::MethodCallStatement>()) {
            auto *mce = mcs->methodCall;
            if (auto *pe = mce->method->to<IR::PathExpression>()) {
                if (pe->path->name == "_apply") {
                    auto *args = mce->arguments;
                    if (args && args->size() == 1) {
                        auto *argExpr = args->at(0)->expression;
                        if (auto *argPe = argExpr->to<IR::PathExpression>()) {
                            auto varName = argPe->path->name;
                            auto it = recordedDecls.find(varName);
                            if (it != recordedDecls.end()) {
                                // Clone the recorded declaration to insert here.
                                auto *clone = it->second->clone();
                                newComponents.push_back(clone);
                                continue;  // Skip original _apply call.
                            }
                        }
                    }
                }
            }
        }

        newComponents.push_back(comp);
    }

    auto *result = block->clone()->to<IR::BlockStatement>();
    result->components = newComponents;
    return result;
}

}  // namespace

const IR::Node *TableTransform::postorder(IR::P4Program *program) {
    if (program == nullptr) return nullptr;

    // Phase 1: convert P5Table objects into (struct + function) and
    // collect the generated struct names into ttStructs.
    IR::Vector<IR::Node> intermediateObjects;
    std::unordered_set<cstring> ttStructs;

    for (auto obj : program->objects) {
        auto *table = obj->to<IR::P5Table>();
        if (!table) {
            intermediateObjects.push_back(obj);
            continue;
        }

        // 1) Generate struct type with the same name as the table, containing
        // all local variables declared in the table body.
        IR::IndexedVector<IR::StructField> fields;
        std::vector<const IR::Declaration_Variable *> locals;
        if (table->body) {
            for (auto comp : table->body->components) {
                if (auto *var = comp->to<IR::Declaration_Variable>()) {
                    auto *field =
                        new IR::StructField(var->srcInfo, var->name, var->type);
                    fields.push_back(field);
                    locals.push_back(var);
                }
            }
        }

        auto *structType =
            new IR::Type_Struct(table->srcInfo, table->name, fields);
        ttStructs.insert(table->name);
        intermediateObjects.push_back(structType);

        // 2) Generate function `<TableName>_f` returning that struct and taking
        // the same parameters as the table. The body is:
        //   <original table body>
        //   StructName retval;
        //   retval.field_i = local_i;
        //   return retval;
        auto *retPath = new IR::Path(table->srcInfo, table->name);
        auto *retType = new IR::Type_Name(table->srcInfo, retPath);

        auto *funcBody = new IR::BlockStatement(
            table->body ? table->body->srcInfo : table->srcInfo);

        if (table->body) {
            for (auto comp : table->body->components) {
                funcBody->push_back(comp);
            }
        }

        cstring retvalName("retval");
        auto *retDecl = new IR::Declaration_Variable(retvalName, retType);
        funcBody->push_back(retDecl);

        for (auto *var : locals) {
            auto *left =
                new IR::Member(var->srcInfo,
                               new IR::PathExpression(retvalName),
                               var->name);
            auto *right = new IR::PathExpression(var->name);
            auto *assign =
                new IR::AssignmentStatement(var->srcInfo, left, right);
            funcBody->push_back(assign);
        }

        auto *retExpr = new IR::PathExpression(retvalName);
        auto *retStmt =
            new IR::ReturnStatement(table->srcInfo, retExpr);
        funcBody->push_back(retStmt);

        auto funcName = table->name.toString() + "_f";
        auto *funcType =
            new IR::Type_Method(table->srcInfo, retType, table->parameters, funcName);
        auto *func =
            new IR::Function(table->srcInfo, funcName, funcType, funcBody);

        func->annotations = table->annotations;

        intermediateObjects.push_back(func);
    }

    // Phase 2: for all functions, apply TT "_f" rewrite and _apply expansion.
    IR::Vector<IR::Node> finalObjects;
    for (auto obj : intermediateObjects) {
        if (auto *fn = obj->to<IR::Function>()) {
            if (!fn->body) {
                finalObjects.push_back(obj);
                continue;
            }
            std::unordered_map<cstring, const IR::Declaration_Variable *> recordedDecls;
            auto *newBody = processTTBlock(fn->body, ttStructs, recordedDecls);
            if (newBody == nullptr) {
                finalObjects.push_back(obj);
                continue;
            }
            auto *clone = fn->clone();
            clone->body = newBody;
            finalObjects.push_back(clone);
        } else {
            finalObjects.push_back(obj);
        }
    }

    program->objects = finalObjects;
    return program;
}

const IR::P4Program *runTableTransfer(const IR::P4Program *program) {
    CHECK_NULL(program);

    TableTransfer passes;
    auto *result = program->apply(passes);
    if (::P4::errorCount() > 0 || result == nullptr) return program;

    auto *pgm = result->to<IR::P4Program>();
    CHECK_NULL(pgm);
    return pgm;
}

}  // namespace P4::P5


