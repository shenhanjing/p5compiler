#include "frontends/p5/passes/p5_to_c.h"

#include <cctype>
#include <cmath>
#include <cstring>
#include <filesystem>
#include <functional>
#include <fstream>
#include <sstream>
#include <type_traits>
#include <variant>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lib/error.h"
#include "lib/stringify.h"

namespace P4::P5 {

struct IndentGuard {
    P5ToC *self;
    std::string old;
    explicit IndentGuard(P5ToC *s) : self(s), old(s->indent) { self->indent += "    "; }
    ~IndentGuard() { self->indent = old; }
};

void P5ToC::emitP5Program(const IR::P4Program *program) {
    // Collect Switch members
    switchMembers.clear();
    globalVariables.clear();
    structMap.clear();

    // Populate structMap first
    for (const auto *obj : program->objects) {
        if (auto *st = obj->to<IR::Type_Struct>()) {
            structMap.emplace(st->name, st);
        }
    }

    // Add predefined members
    switchMembers.insert(cstring("_status"));
    // Built-in control parameters / accessors (GenSim BuiltInContext)
    switchMembers.insert(cstring("table_id"));
    switchMembers.insert(cstring("command"));
    switchMembers.insert(cstring("ma_id"));
    switchMembers.insert(cstring("_header_access"));
    switchMembers.insert(cstring("decomp_profile"));
    switchMembers.insert(cstring("control_info"));
    switchMembers.insert(cstring("_command"));
    switchMembers.insert(cstring("_table_id"));
    switchMembers.insert(cstring("_profile_id"));
    switchMembers.insert(cstring("_control_info"));

    for (const auto *obj : program->objects) {
        if (auto *var = obj->to<IR::Declaration_Variable>()) {
            switchMembers.insert(var->name);
            globalVariables.emplace(var->name, var->type);
        } else if (auto *inst = obj->to<IR::Declaration_Instance>()) {
            switchMembers.insert(inst->name);
            globalVariables.emplace(inst->name, inst->type);
        } else if (auto *func = obj->to<IR::Function>()) {
            switchMembers.insert(func->name);
        }
    }

    // In generated headers, members are in-scope, so avoid emitting "ctx." prefixes.
    bool oldBypass = bypassCtxPrefix;
    bypassCtxPrefix = true;
    emitEnumsHpp(program);
    emitStructHpp(program);
    emitGtvHpp(program);
    bypassCtxPrefix = oldBypass;
    emitSwitch(program);

    flushCFile();
}

std::string P5ToC::resolveMemberPath(const IR::Type_Struct *st, cstring memberName) {
    if (!st) return "";
    for (const auto *field : st->fields) {
        if (field->name == memberName) {
            return "." + std::string(memberName.c_str());
        }
        if (auto *nestedSt = field->type->to<IR::Type_Struct>()) {
            if (isAnonymous(nestedSt)) {
                auto sub = resolveMemberPath(nestedSt, memberName);
                if (!sub.empty()) {
                    return "." + std::string(field->name.name.c_str()) + sub;
                }
            }
        }
    }
    return "";
}

const IR::Type *P5ToC::resolveType(const IR::Expression *expr, const LocalsMap &locals) {
    if (expr == nullptr) return nullptr;
    if (auto *pe = expr->to<IR::PathExpression>()) {
        if (locals.count(pe->path->name)) return locals.at(pe->path->name);
        if (globalVariables.count(pe->path->name)) return globalVariables.at(pe->path->name);
        return nullptr;
    }
    if (auto *mem = expr->to<IR::Member>()) {
        auto *baseType = resolveType(mem->expr, locals);
        if (!baseType) return nullptr;

        if (auto *tn = baseType->to<IR::Type_Name>()) {
            if (structMap.count(tn->path->name)) {
                baseType = structMap.at(tn->path->name);
            }
        }

        if (auto *st = baseType->to<IR::Type_Struct>()) {
            std::function<const IR::Type *(const IR::Type_Struct *, cstring)> findField =
                [&](const IR::Type_Struct *s, cstring name) -> const IR::Type * {
                for (auto *f : s->fields) {
                    if (f->name == name) return f->type;
                    if (auto *nested = f->type->to<IR::Type_Struct>()) {
                        if (isAnonymous(nested)) {
                            auto *t = findField(nested, name);
                            if (t) return t;
                        }
                    }
                }
                return nullptr;
            };
            return findField(st, mem->member);
        }
    }
    if (auto *ai = expr->to<IR::ArrayIndex>()) {
        auto *baseType = resolveType(ai->left, locals);
        if (!baseType) return nullptr;
        if (auto *stk = baseType->to<IR::Type_Stack>()) {
            return stk->elementType;
        }
    }
    return nullptr;
}

std::ostream *P5ToC::getStream(const std::string &filename) {
    auto it = streams.find(filename);
    if (it != streams.end()) return it->second.get();
    auto path = outputDir / filename;
    std::cout << "Open file: " << path << std::endl;
    auto ofs = std::make_unique<std::ofstream>(path);

    // Check if file opened successfully
    if (!ofs->is_open()) {
        ::P4::error("Could not open file %s for writing", path.string().c_str());
        return outputStream;  // Fallback to original output stream
    }

    auto *ptr = ofs.get();
    streams.emplace(filename, std::move(ofs));

    return ptr;
}

void P5ToC::flushCFile() {
    for (auto &[filename, stream] : streams) {
        stream->flush();
    }
}

bool P5ToC::isUnion(const IR::Type_Struct *st) {
    if (st == nullptr) return false;
    for (const auto *ann : st->annotations) {
        if (ann->name == "union" || ann->name == IR::ID("union")) {
            return true;
        }
    }
    return false;
}

bool P5ToC::isAnonymous(const IR::Type_Struct *st) {
    if (st == nullptr) return false;
    return st->name == " " || st->name.toString().startsWith("_anon_");
}

void P5ToC::emitFieldType(const IR::Type *type, EmitMode mode) {
    if (type == nullptr) {
        *outputStream << "void";
        return;
    }

    if (auto *bits = type->to<IR::Type_Bits>()) {
        if (mode == EmitMode::Memberized) *outputStream << "p5::member<";

        if (!bits->isSigned) {
            // 无符号 Type_Bits 生成 p5::uint<N>
            *outputStream << "p5::uint<";
            if (bits->expression) {
                emitExpressionWithCtx(bits->expression, {});
            } else {
                *outputStream << bits->size;
            }
            *outputStream << ">";
        } else {
            // 有符号的生成标准整数类型
            int width = bits->size;
            if (bits->expression) {
                width = evaluateExprToInt(bits->expression);
            }
            *outputStream << "int" << width << "_t";
        }
        if (mode == EmitMode::Memberized) *outputStream << ">";
        return;
    }

    if (auto *tn = type->to<IR::Type_Name>()) {
        if (mode == EmitMode::Memberized) {
            *outputStream << "_inU_" << tn->path->name;
        } else {
            *outputStream << tn->path->name;
        }
        return;
    }

    if (type->is<IR::Type_Boolean>()) {
        if (mode == EmitMode::Memberized)
            *outputStream << "p5::member<bool>";
        else
            *outputStream << "bool";
        return;
    }

    // 处理嵌套的 struct/union
    if (auto *st = type->to<IR::Type_Struct>()) {
        if (isAnonymous(st)) {
            // 匿名 struct/union，内联输出
            int dummy = 0;
            emitNestedStructOrUnion(st, mode, dummy);
        } else {
            // 命名的 struct/union，使用类型名
            if (mode == EmitMode::Memberized)
                *outputStream << "_inU_" << st->name;
            else
                *outputStream << st->name;
        }
        return;
    }

    *outputStream << type->toString();
}

void P5ToC::emitVariableDecl(const IR::Declaration_Variable *var, const LocalsMap &locals) {
    if (var == nullptr) return;

    const IR::Type *baseType = var->type;
    std::vector<const IR::Expression *> dims;

    while (auto *stk = baseType->to<IR::Type_Stack>()) {
        dims.push_back(stk->size);
        baseType = stk->elementType;
    }

    // Special cases for uint<0> declarations:
    // 1) uint<0> newVec = _list_alloc(oldVec);  -> decltype(oldVec) newVec(oldVec.size());
    // 2) Other uint<0> scalar declarations      -> auto newVar (= ...);
    const bool isUint0Scalar = dims.empty() && [&]() {
        if (auto *bits = baseType->to<IR::Type_Bits>()) {
            // Only treat it as true uint<0> when the width is literally 0.
            // If width comes from an expression (e.g. uint<_log2(33)>), bits->size may still be 0
            // in the IR, but it is NOT a uint<0> and should keep an explicit p5::uint<...> type.
            return !bits->isSigned && bits->expression == nullptr && bits->size == 0;
        }
        return false;
    }();

    if (isUint0Scalar && var->initializer) {
        if (auto *mc = var->initializer->to<IR::MethodCallExpression>()) {
            if (auto *pe = mc->method->to<IR::PathExpression>()) {
                if (pe->path->name == "_list_alloc" && mc->arguments &&
                    mc->arguments->size() == 1) {
                    // Render the argument expression with the same context rules (ctx./locals).
                    std::ostringstream argOs;
                    auto *old = outputStream;
                    outputStream = &argOs;
                    emitExpressionWithCtx(mc->arguments->at(0)->expression, locals);
                    outputStream = old;
                    const auto argStr = argOs.str();

                    *outputStream << indent << "decltype(" << argStr << ") " << var->name << "("
                                  << argStr << ".size());\n";
                    return;
                }
            }
        }
    }

    // Map _compressed_X -> _inflate<X>, otherwise reuse emitFieldType
    auto writeMappedType = [this](const IR::Type *type, std::ostream &os) {
        if (auto *tn = type->to<IR::Type_Name>()) {
            auto name = tn->path->name.toString();
            if (name.startsWith("_compressed_")) {
                auto inner = name.substr(strlen("_compressed_"));
                os << "_inflate<" << inner << ">";
                return;
            }
        }
        auto *old = outputStream;
        outputStream = &os;
        emitFieldType(type);
        outputStream = old;
    };

    std::ostringstream typeBuf;
    writeMappedType(baseType, typeBuf);

    // For uint<0> scalar declarations, emit 'auto' (unless handled by _list_alloc rewrite above).
    if (isUint0Scalar) {
        *outputStream << indent << "auto " << var->name;
    } else {
        *outputStream << indent << typeBuf.str() << " " << var->name;
    }

    for (auto *dim : dims) {
        *outputStream << "[";
        if (dim) {
            emitExpressionWithCtx(dim, locals);
        }
        *outputStream << "]";
    }

    if (var->initializer) {
        // Specialize _key/_lookup with lhs type when used in initializer
        if (auto *mc = var->initializer->to<IR::MethodCallExpression>()) {
            if (auto *pe = mc->method->to<IR::PathExpression>()) {
                auto lhsName = var->name.toString();
                auto argsToString = [mc]() {
                    std::ostringstream os;
                    if (mc->arguments) {
                        bool first = true;
                        for (const auto *arg : *mc->arguments) {
                            if (!first) os << ", ";
                            first = false;
                            os << arg->toString();
                        }
                    }
                    return os.str();
                };
                if (pe->path->name == "_key") {
                    // Emit key assignment in out-parameter form:
                    //   lhs = _key(lhs);
                    // (Works for p5::uint as well as aggregates/union via overload.)
                    (void)argsToString; // keep lambda for symmetry with other built-ins
                    *outputStream << " = _key(" << lhsName << ")";
                } else if (pe->path->name == "_lookup") {
                    auto args = argsToString();
                    *outputStream << " = _lookup<typename std::remove_reference_t<decltype("
                                  << lhsName << ")>::value_type>(" << args << ")";
                } else {
                    *outputStream << " = ";
                    emitExpressionWithCtx(var->initializer, locals);
                }
            } else {
                *outputStream << " = ";
                emitExpressionWithCtx(var->initializer, locals);
            }
        } else {
            *outputStream << " = ";
            emitExpressionWithCtx(var->initializer, locals);
        }
    }

    *outputStream << ";\n";
}

void P5ToC::emitHeaderDecl(const IR::Declaration_Instance *inst) {
    if (inst == nullptr) return;

    const IR::Type *baseType = inst->type;
    std::vector<const IR::Expression *> dims;

    while (auto *stk = baseType->to<IR::Type_Stack>()) {
        dims.push_back(stk->size);
        baseType = stk->elementType;
    }

    *outputStream << indent;
    emitFieldType(baseType);
    *outputStream << " " << inst->name;
    for (auto *dim : dims) {
        *outputStream << "[";
        if (dim) {
            emitExpressionWithCtx(dim, {});
        }
        *outputStream << "]";
    }
    *outputStream << ";\n";
}

bool P5ToC::emitMethodCall(const IR::MethodCallExpression *mc, const cstring &lhs, std::ostream &os,
                           const LocalsMap &locals) {
    if (mc == nullptr || mc->method == nullptr) return false;
    auto *pe = mc->method->to<IR::PathExpression>();
    if (!pe) return false;

    auto argsToString = [this, mc, &locals]() {
        std::ostringstream osArgs;
        auto *old = outputStream;
        outputStream = &osArgs;
        if (mc->arguments) {
            bool first = true;
            for (const auto *arg : *mc->arguments) {
                if (!first) *outputStream << ", ";
                first = false;
                emitExpressionWithCtx(arg->expression, locals);
            }
        }
        outputStream = old;
        return osArgs.str();
    };

    if (pe->path->name == "_key") {
        // Emit key assignment in out-parameter form:
        //   lhs = _key(lhs);
        // (Works for p5::uint as well as aggregates/union via overload.)
        (void)argsToString; // keep lambda for symmetry with other built-ins
        os << lhs << " = _key(" << lhs << ");";
        return true;
    }

    if (pe->path->name == "_lookup") {
        auto args = argsToString();
        os << lhs << " = _lookup<typename std::remove_reference_t<decltype(" << lhs
           << ")>::value_type>(" << args << ");";
        return true;
    }

    return false;
}

bool P5ToC::emitMethodCall(const IR::MethodCallExpression *mc, std::ostream &os,
                           const LocalsMap &locals) {
    if (mc == nullptr || mc->method == nullptr) return false;
    auto *pe = mc->method->to<IR::PathExpression>();
    if (!pe) return false;

    // ClearFields is a global builtin in GenSim. In P5 it is always called as:
    //   ClearFields({var0, var1, ...})
    // where the braced part parses into an IR::ListExpression as a single argument.
    // In C++, ClearFields is variadic, so we must drop the braces:
    //   ClearFields(var0, var1, ...)
    if (pe->path->name == "ClearFields") {
        auto *old = outputStream;
        outputStream = &os;

        os << "ClearFields(";
        bool first = true;
        if (mc->arguments && mc->arguments->size() == 1) {
            const auto *arg0 = mc->arguments->at(0);
            if (arg0 && arg0->expression) {
                if (auto *list = arg0->expression->to<IR::ListExpression>()) {
                    for (auto *comp : list->components) {
                        if (!first) os << ", ";
                        first = false;
                        emitExpressionWithCtx(comp, locals);
                    }
                } else {
                    // Fallback: not a braced list, emit the single argument as-is.
                    emitExpressionWithCtx(arg0->expression, locals);
                    first = false;
                }
            }
        } else if (mc->arguments) {
            // Defensive: if frontend ever emits real arguments list, keep it.
            for (const auto *arg : *mc->arguments) {
                if (!first) os << ", ";
                first = false;
                emitExpressionWithCtx(arg->expression, locals);
            }
        }
        os << ");";

        outputStream = old;
        return true;
    }

    if (pe->path->name == "_apply" && mc->arguments && mc->arguments->size() == 1) {
        auto *old = outputStream;
        outputStream = &os;
        emitExpressionWithCtx(mc->arguments->at(0)->expression, locals);
        outputStream = old;
        os << ".apply();";
        return true;
    }

    return false;
}

void P5ToC::emitTypedef(const IR::Type_Typedef *td) {
    if (td == nullptr) return;

    // Render mapped type using existing emitFieldType (Standard)
    std::ostringstream oss;
    auto *oldStream = outputStream;
    outputStream = &oss;
    emitFieldType(td->type, EmitMode::Standard);
    outputStream = oldStream;
    std::string mappedType = oss.str();

    *outputStream << indent;
    *outputStream << "using " << td->name << " = " << mappedType << ";\n";
}

void P5ToC::emitSerEnum(const IR::Type_SerEnum *serEnum) {
    if (serEnum == nullptr) return;

    *outputStream << "enum " << serEnum->name << " {\n";

    for (size_t i = 0; i < serEnum->members.size(); ++i) {
        const auto *member = serEnum->members[i];
        *outputStream << indent << "    " << member->name;

        if (member->value) {
            // 尝试获取常量值
            if (auto *c = member->value->to<IR::Constant>()) {
                *outputStream << " = " << c->value;
            } else {
                // 如果不是常量，输出表达式（简化处理）
                *outputStream << " = " << member->value->toString();
            }
        }

        if (i < serEnum->members.size() - 1) {
            *outputStream << ",";
        }
        *outputStream << "\n";
    }

    *outputStream << "};\n\n";
}

void P5ToC::emitFunctionSignature(const IR::Function *func, const std::string &class_name) {
    if (func == nullptr) return;

    // Pre-scan parameters to collect generic template typenames for uint<0>.
    // Rules:
    // - uint<0> var        -> Tn var
    // - uint<0> list[]     -> std::vector<Tn> list
    // Each occurrence gets its own distinct typename.
    curUint0InitListParams.clear();
    std::vector<std::string> genericTypenames;
    std::unordered_map<const IR::Parameter *, std::string> paramTypeOverride;
    std::unordered_map<const IR::Parameter *, std::string> paramNameOverride;

    auto isUnsizedArrayParam = [](const IR::Parameter *p) -> bool {
        if (p == nullptr) return false;
        for (const auto *ann : p->annotations) {
            if (ann->name == "p5_unsized_array" || ann->name == IR::ID("p5_unsized_array")) {
                return true;
            }
        }
        return false;
    };

    if (auto *mt = func->type->to<IR::Type_Method>()) {
        if (mt->parameters) {
            int tIndex = 0;
            auto nextT = [&]() { return std::string("T") + std::to_string(tIndex++); };

            for (const auto *param : mt->parameters->parameters) {
                if (!param || !param->type) continue;

                if (auto *bits = param->type->to<IR::Type_Bits>()) {
                    if (!bits->isSigned && bits->size == 0) {
                        auto t = nextT();
                        genericTypenames.push_back(t);
                        if (isUnsizedArrayParam(param)) {
                            if (param->direction == IR::Direction::InOut) {
                                // Keep old behavior for inout uint<0>[]: treat as vector reference.
                                paramTypeOverride.emplace(param, "std::vector<" + t + ">");
                            } else {
                                // uint<0> list0[] -> std::initializer_list<T0> _InitList_list0
                                const std::string initName = "_InitList_" + param->name.toString();
                                paramTypeOverride.emplace(param,
                                                          "std::initializer_list<" + t + ">");
                                paramNameOverride.emplace(param, initName);
                                curUint0InitListParams.push_back(
                                    Uint0InitListParam{t, param->name, initName});
                            }
                        } else {
                            paramTypeOverride.emplace(param, t);
                        }
                        continue;
                    }
                }
            }
        }
    }

    // Emit template first (if needed), then the function signature.
    if (!genericTypenames.empty()) {
        *outputStream << indent << "template <";
        for (size_t i = 0; i < genericTypenames.size(); ++i) {
            if (i != 0) *outputStream << ", ";
            *outputStream << "typename " << genericTypenames[i];
        }
        *outputStream << ">\n";
        *outputStream << indent;
    }

    *outputStream << indent;

    // 输出返回类型
    if (auto *mt = func->type->to<IR::Type_Method>()) {
        if (mt->returnType) {
            emitFieldType(mt->returnType);
        } else {
            *outputStream << "void";
        }
    } else {
        *outputStream << "void";
    }

    // 输出函数名
    *outputStream << " " << class_name << func->name << "(";

    // 输出参数列表
    if (auto *mt = func->type->to<IR::Type_Method>()) {
        if (mt->parameters) {
            bool first = true;
            for (const auto *param : mt->parameters->parameters) {
                if (!first) {
                    *outputStream << ", ";
                }
                first = false;
                bool handled = false;

                // Override uint<0> (scalar/array) to generic types.
                if (auto it = paramTypeOverride.find(param); it != paramTypeOverride.end()) {
                    *outputStream << it->second;
                    const auto nameIt = paramNameOverride.find(param);
                    const auto &emitName = (nameIt != paramNameOverride.end())
                                               ? nameIt->second
                                               : param->name.toString();
                    if (param->direction == IR::Direction::InOut) {
                        *outputStream << " &" << emitName;
                    } else {
                        *outputStream << " " << emitName;
                    }
                    handled = true;
                }

                // Unsized array parameters (T a[]) are represented via annotation.
                // Keep the original "[]" form in the generated signature.
                if (!handled && isUnsizedArrayParam(param)) {
                    emitFieldType(param->type);
                    if (param->direction == IR::Direction::InOut) {
                        // C++: reference to array of unknown bound: T (&name)[]
                        *outputStream << " (&" << param->name << ")[]";
                    } else {
                        // C/C++: parameter as array: T name[]
                        *outputStream << " " << param->name << "[]";
                    }
                    handled = true;
                }

                // For regular inout uint<N> (N != 0), keep existing p5::uint_ref<N> emission.
                // If the parameter was already overridden (e.g. uint<0> -> Tn), do not emit again.
                if (!handled && param->direction == IR::Direction::InOut) {
                    if (auto *bits = param->type->to<IR::Type_Bits>()) {
                        if (!bits->isSigned) {
                            *outputStream << "p5::uint_ref<" << bits->size << "> " << param->name;
                            handled = true;
                        }
                    }
                }

                if (!handled) {
                    emitFieldType(param->type);
                    if (param->direction == IR::Direction::InOut) {
                        *outputStream << " &" << param->name;
                    } else {
                        *outputStream << " " << param->name;
                    }
                }
            }
        }
    }

    *outputStream << ")";
}

void P5ToC::emitFunctionBody(const IR::BlockStatement *body, LocalsMap locals) {
    if (body == nullptr) {
        *outputStream << ";\n\n";
        return;
    }

    *outputStream << " {\n";

    {
        IndentGuard ig(this);

        // Prologue for uint<0> non-ref array params:
        //   std::initializer_list<T0> _InitList_list0
        // becomes:
        //   std::vector<T0> list0(_InitList_list0);
        for (const auto &p : curUint0InitListParams) {
            *outputStream << indent << "std::vector<" << p.tname << "> " << p.origName << "("
                          << p.initName << ");\n";
        }

        if (currentAcceleratorNgsfDir == AcceleratorNgsfDir::FV2NGSF) {
            *outputStream << indent << "ngsf_direction = NgsfDirection::FV2NGSF;\n";
        } else if (currentAcceleratorNgsfDir == AcceleratorNgsfDir::NGSF2FV) {
            *outputStream << indent << "ngsf_direction = NgsfDirection::NGSF2FV;\n";
        }

        if (!currentFunctionName.isNullOrEmpty()) {
            if (currentFunctionName == "genNGSFNp2Tm" || currentFunctionName == "genNGSFTm2Np") {
                *outputStream << indent << "npor_tm = NPorTM::TM;\n";
            } else if (currentFunctionName.startsWith("genNGSF")) {
                *outputStream << indent << "npor_tm = NPorTM::NP;\n";
            }
        }

        for (const auto *comp : body->components) {
            if (auto *var = comp->to<IR::Declaration_Variable>()) {
                locals.emplace(var->name, var->type);
            }
            emitComponent(comp, locals);
        }
    }
    *outputStream << indent << "}\n\n";
}

void P5ToC::emitComponent(const IR::StatOrDecl *comp, const LocalsMap &locals) {
    // *outputStream << indent;
    if (auto *ifs = comp->to<IR::IfStatement>()) {
        emitIfStat(ifs, locals);
        return;
    }
    if (auto *fs = comp->to<IR::ForStatement>()) {
        emitForStatement(fs, locals);
        return;
    }
    if (auto *mcs = comp->to<IR::MethodCallStatement>()) {
        auto *mc = mcs->methodCall;
        std::ostringstream os;
        if (emitMethodCall(mc, os, locals)) {
            *outputStream << indent << os.str() << "\n";
            return;
        }
        *outputStream << indent;
        emitExpressionWithCtx(mc, locals);
        *outputStream << ";\n";
        return;
    }
    if (auto *var = comp->to<IR::Declaration_Variable>()) {
        emitVariableDecl(var, locals);
        return;
    }
    if (auto *as = comp->to<IR::AssignmentStatement>()) {
        auto lhs = as->left->toString();
        if (auto *mc = as->right->to<IR::MethodCallExpression>()) {
            std::ostringstream os;
            if (emitMethodCall(mc, lhs, os, locals)) {
                *outputStream << indent << os.str() << "\n";
                return;
            }
        }
        *outputStream << indent;
        emitExpressionWithCtx(as->left, locals);
        *outputStream << " = ";
        emitExpressionWithCtx(as->right, locals);
        *outputStream << ";\n";
        return;
    }
    if (auto *swStmt = comp->to<IR::SwitchStatement>()) {
        emitSwitchStatement(swStmt, locals);
        return;
    }
    if (auto *blk = comp->to<IR::BlockStatement>()) {
        for (const auto *c : blk->components) emitComponent(c, locals);
        return;
    }

    auto text = comp->toString();
    *outputStream << indent << text << ";\n";

    return;
}

void P5ToC::emitSwitchTagMatching(const IR::SwitchStatement *swStmt, const LocalsMap &locals) {
    // 2. Emit tie
    *outputStream << indent << "auto _msw = p5::mswitch::tie(";
    const IR::Expression *expr = swStmt->expression;
    if (auto *list = expr->to<IR::ListExpression>()) {
        bool first = true;
        for (auto *comp : list->components) {
            if (!first) *outputStream << ", ";
            first = false;
            emitExpressionWithCtx(comp, locals);
        }
    } else {
        emitExpressionWithCtx(expr, locals);
    }
    *outputStream << ");\n";

    // 3. Emit tag
    *outputStream << indent << "int _tag = 0;\n";

    // 4. Emit match logic
    int caseId = 0;
    bool firstMatch = true;
    for (const auto &caseStmt : swStmt->cases) {
        caseId++;
        if (caseStmt->label->is<IR::DefaultExpression>()) continue;

        *outputStream << indent;
        if (!firstMatch) *outputStream << "else ";
        *outputStream << "if (p5::mswitch::match(_msw, ";

        // Helper to emit match args
        auto emitMatchArg = [&](const IR::Expression *e) {
            if (auto *m = e->to<IR::Mask>()) {
                *outputStream << "p5::mswitch::mask(";
                emitExpressionWithCtx(m->left, locals);
                *outputStream << ", ";
                emitExpressionWithCtx(m->right, locals);
                *outputStream << ")";
                return;
            }
            emitExpressionWithCtx(e, locals);
        };

        const IR::Expression *label = caseStmt->label;
        if (auto *list = label->to<IR::ListExpression>()) {
            bool firstArg = true;
            for (auto *comp : list->components) {
                if (!firstArg) *outputStream << ", ";
                firstArg = false;
                emitMatchArg(comp);
            }
        } else {
            emitMatchArg(label);
        }

        *outputStream << ")) _tag = " << caseId << ";\n";
        firstMatch = false;
    }
}

void P5ToC::emitSwitchDispatch(const IR::SwitchStatement *swStmt, const LocalsMap &locals) {
    // 5. Emit switch
    *outputStream << indent << "switch (_tag) {\n";
    {
        IndentGuard igSwitch(this);
        int caseId = 0;
        for (const auto &caseStmt : swStmt->cases) {
            caseId++;
            *outputStream << indent;
            if (caseStmt->label->is<IR::DefaultExpression>()) {
                *outputStream << "default: ";
            } else {
                *outputStream << "case " << caseId << ": ";
            }

            if (caseStmt->statement) {
                bool isEmptyBlock = false;
                if (auto *bs = caseStmt->statement->to<IR::BlockStatement>()) {
                    if (bs->components.empty()) isEmptyBlock = true;
                }

                if (isEmptyBlock) {
                    *outputStream << "{\n";
                    *outputStream << indent << "    break;\n";
                    *outputStream << indent << "}\n";
                } else {
                    *outputStream << "{\n";
                    {
                        IndentGuard igBody(this);
                        if (auto *bs = caseStmt->statement->to<IR::BlockStatement>()) {
                            for (const auto *comp : bs->components) {
                                emitComponent(comp, locals);
                            }
                        } else {
                            if (auto *stat = caseStmt->statement->to<IR::StatOrDecl>()) {
                                emitComponent(stat, locals);
                            } else {
                                *outputStream << indent << caseStmt->statement->toString() << ";\n";
                            }
                        }
                        *outputStream << indent << "break;\n";
                    }
                    *outputStream << indent << "}\n";
                }
            } else {
                *outputStream << "\n";
            }
        }
    }
    *outputStream << indent << "}\n";
}

void P5ToC::emitSwitchStatement(const IR::SwitchStatement *swStmt, const LocalsMap &locals) {
    if (swStmt->expression == nullptr) {
        *outputStream << indent << "{\n";
        {
            IndentGuard ig(this);
            for (const auto &caseStmt : swStmt->cases) {
                if (caseStmt->label->is<IR::DefaultExpression>()) {
                    if (caseStmt->statement) {
                        if (auto *bs = caseStmt->statement->to<IR::BlockStatement>()) {
                            for (const auto *comp : bs->components) {
                                emitComponent(comp, locals);
                            }
                        } else {
                            if (auto *stat = caseStmt->statement->to<IR::StatOrDecl>()) {
                                emitComponent(stat, locals);
                            } else {
                                *outputStream << indent << caseStmt->statement->toString() << ";\n";
                            }
                        }
                    }
                    break;
                }
            }
        }
        *outputStream << indent << "}\n";
        return;
    }

    // 1. Emit block start
    *outputStream << indent << "{\n";
    IndentGuard ig(this);

    emitSwitchTagMatching(swStmt, locals);
    emitSwitchDispatch(swStmt, locals);

    // 6. Close block
    *outputStream << indent << "}\n";
}

void P5ToC::emitIfStat(const IR::IfStatement *ifs, const LocalsMap &locals) {
    if (ifs == nullptr) return;

    // Emit condition with an extra rule:
    // If a sub-expression is a "pure variable" (PathExpression / Member) used as a boolean,
    // append ".to_ullong()" so code like:
    //   if (IsUc)                 -> if (IsUc.to_ullong())
    //   if (_valid(x) && y.Flag)  -> if (_valid(x) && y.Flag.to_ullong())
    //
    // Only applies to boolean-context operators (top-level, &&, ||, !) and does not
    // change non-boolean operators (comparisons, arithmetic, etc.).
    std::function<void(const IR::Expression *, bool)> emitIfCond = [&](const IR::Expression *expr,
                                                                       bool boolContext) {
        if (expr == nullptr) return;

        // Unwrap single-element list expression (common artifact in this frontend).
        if (auto *list = expr->to<IR::ListExpression>()) {
            if (list->components.size() == 1) {
                emitIfCond(list->components.at(0), boolContext);
                return;
            }
        }

        if (expr->is<IR::PathExpression>() || expr->is<IR::Member>()) {
            emitExpressionWithCtx(expr, locals);
            if (boolContext) *outputStream << ".to_ullong()";
            return;
        }

        if (auto *un = expr->to<IR::Operation_Unary>()) {
            // Only treat logical NOT as boolean-context; other unary ops fall back.
            if (un->getStringOp() == "!") {
                *outputStream << "!";
                emitIfCond(un->expr, true);
                return;
            }
            emitExpressionWithCtx(expr, locals);
            return;
        }

        if (auto *bin = expr->to<IR::Operation_Binary>()) {
            const auto op = bin->getStringOp();
            if (op == "&&" || op == "||") {
                *outputStream << "(";
                emitIfCond(bin->left, true);
                *outputStream << " " << op << " ";
                emitIfCond(bin->right, true);
                *outputStream << ")";
                return;
            }
            // Comparisons/arithmetic/etc: keep existing emission.
            emitExpressionWithCtx(expr, locals);
            return;
        }

        // Default: keep existing emission.
        emitExpressionWithCtx(expr, locals);
    };

    *outputStream << indent << "if (";
    emitIfCond(ifs->condition, true);
    *outputStream << ") {\n";
    {
        IndentGuard ig(this);
        if (ifs->ifTrue) {
            emitComponent(ifs->ifTrue, locals);
        }
    }
    *outputStream << indent << "}";

    if (ifs->ifFalse) {
        *outputStream << " else {\n";
        {
            IndentGuard ig(this);
            emitComponent(ifs->ifFalse, locals);
        }
        *outputStream << indent << "}";
    }

    *outputStream << "\n";
}

void P5ToC::emitForStatement(const IR::ForStatement *fs, const LocalsMap &locals) {
    if (fs == nullptr) return;

    *outputStream << indent << "for (";
    bool first = true;
    for (auto *s : fs->init) {
        if (!first) *outputStream << ", ";
        first = false;
        if (auto *decl = s->to<IR::Parameter>()) {
            emitFieldType(decl->type);
            *outputStream << " " << decl->name;
            if (decl->defaultValue) {
                *outputStream << " = ";
                emitExpressionWithCtx(decl->defaultValue, locals);
            }
        } else if (auto *var = s->to<IR::Declaration_Variable>()) {
            emitFieldType(var->type);
            *outputStream << " " << var->name;
            if (var->initializer) {
                *outputStream << " = ";
                emitExpressionWithCtx(var->initializer, locals);
            }
        } else if (auto *stat = s->to<IR::Statement>()) {
            if (auto *as = stat->to<IR::AssignmentStatement>()) {
                emitExpressionWithCtx(as->left, locals);
                *outputStream << " = ";
                emitExpressionWithCtx(as->right, locals);
            }
        }
    }
    *outputStream << "; ";
    emitExpressionWithCtx(fs->condition, locals);
    *outputStream << "; ";
    first = true;
    for (auto *s : fs->updates) {
        if (!first) *outputStream << ", ";
        first = false;
        if (auto *as = s->to<IR::AssignmentStatement>()) {
            emitExpressionWithCtx(as->left, locals);
            *outputStream << " = ";
            emitExpressionWithCtx(as->right, locals);
        } else if (auto *stat = s->to<IR::Statement>()) {
            if (auto *expr = stat->to<IR::Expression>()) {
                emitExpressionWithCtx(expr, locals);
            }
        }
    }
    *outputStream << ") {\n";
    {
        IndentGuard ig(this);
        emitComponent(fs->body, locals);
    }
    *outputStream << indent << "}\n";
}

void P5ToC::emitExpressionWithCtx(const IR::Expression *expr, const LocalsMap &locals) {
    if (expr == nullptr) return;

    if (auto *di = expr->to<IR::P5DesignatedInitializer>()) {
        if (di->isMember) {
            *outputStream << "." << di->designator->toString() << " = ";
            emitExpressionWithCtx(di->value, locals);
        } else {
            *outputStream << "[";
            emitExpressionWithCtx(di->designator, locals);
            *outputStream << "] = ";
            emitExpressionWithCtx(di->value, locals);
        }
        return;
    }

    if (auto *pi = expr->to<IR::P5PostIncrement>()) {
        // Emit native C++ post-increment expression.
        // p5_types.hpp provides operator++(int) for the relevant P5 value wrappers.
        *outputStream << "(";
        emitExpressionWithCtx(pi->expr, locals);
        *outputStream << ")++";
        return;
    }

    if (auto *pe = expr->to<IR::PathExpression>()) {
        if (inSwitchMethod) {
            *outputStream << pe->path->name;
        } else {
            if (bypassCtxPrefix || locals.count(pe->path->name) || !switchMembers.count(pe->path->name)) {
                *outputStream << pe->path->name;
            } else {
                *outputStream << "ctx." << pe->path->name;
            }
        }
        return;
    }

    if (auto *mem = expr->to<IR::Member>()) {
        emitExpressionWithCtx(mem->expr, locals);

        bool handled = false;
        auto *baseType = resolveType(mem->expr, locals);
        if (baseType) {
            if (auto *tn = baseType->to<IR::Type_Name>()) {
                if (structMap.count(tn->path->name)) {
                    baseType = structMap.at(tn->path->name);
                }
            }
            if (auto *st = baseType->to<IR::Type_Struct>()) {
                bool directMatch = false;
                for (auto *f : st->fields) {
                    if (f->name == mem->member) {
                        directMatch = true;
                        break;
                    }
                }
                if (!directMatch) {
                    std::string path = resolveMemberPath(st, mem->member);
                    if (!path.empty()) {
                        *outputStream << path;
                        handled = true;
                    }
                }
            }
        }

        if (!handled) {
            *outputStream << "." << mem->member;
        }
        return;
    }

    if (auto *mc = expr->to<IR::MethodCallExpression>()) {
        emitExpressionWithCtx(mc->method, locals);
        *outputStream << "(";
        bool addedCtx = false;
        const IR::PathExpression *methodPath = mc->method->to<IR::PathExpression>();
        if (methodPath) {
            // Special-case: ClearFields({a,b,...}) in P5 should become ClearFields(a,b,...)
            // in C++ (variadic builtin). We strip the braces by expanding the ListExpression.
            if (methodPath->path->name == "ClearFields" && mc->arguments && mc->arguments->size() == 1) {
                if (auto *list = mc->arguments->at(0)->expression->to<IR::ListExpression>()) {
                    bool first = true;
                    for (auto *comp : list->components) {
                        if (!first) *outputStream << ", ";
                        first = false;
                        emitExpressionWithCtx(comp, locals);
                    }
                    *outputStream << ")";
                    return;
                }
            }
        }
        if (auto *pe = methodPath) {
            if (pe->path->name.toString().endsWith("_TBL")) {
                if (inSwitchMethod) {
                    *outputStream << "*this";
                } else {
                    *outputStream << "ctx";
                }
                addedCtx = true;
            }
        }

        if (mc->arguments) {
            bool first = !addedCtx;
            for (const auto *arg : *mc->arguments) {
                if (!first) *outputStream << ", ";
                first = false;
                emitExpressionWithCtx(arg->expression, locals);
            }
        }
        *outputStream << ")";
        return;
    }

    if (auto *cc = expr->to<IR::ConstructorCallExpression>()) {
        emitFieldType(cc->constructedType);
        *outputStream << "(";
        bool addedCtx = false;
        if (auto *tn = cc->constructedType->to<IR::Type_Name>()) {
            if (tn->path->name.toString().endsWith("_TBL")) {
                if (inSwitchMethod) {
                    *outputStream << "*this";
                } else {
                    *outputStream << "ctx";
                }
                addedCtx = true;
            }
        }

        if (cc->arguments) {
            bool first = !addedCtx;
            for (const auto *arg : *cc->arguments) {
                if (!first) *outputStream << ", ";
                first = false;
                emitExpressionWithCtx(arg->expression, locals);
            }
        }
        *outputStream << ")";
        return;
    }

    if (auto *list = expr->to<IR::ListExpression>()) {
        // If this is a designated-initializer list of the form:
        //   { .a.a = 1, .c = 3, .b = 2, .a.d = 0 }
        // rewrite it into nested designated initializers:
        //   { .a = { .a = 1, .d = 0 }, .c = 3, .b = 2 }
        //
        // This is purely a codegen-time formatting/rewriting pass. It assumes all elements are
        // member-designators (start with '.') and only supports Member/PathExpression chains.
        // If we encounter anything else, we fall back to the original emission.
        struct DiItem {
            std::vector<cstring> path;  // ["a","b","c"] means .a.b.c = value
            const IR::Expression *value = nullptr;
        };

        auto collectMemberPath = [&](const IR::Expression *d, std::vector<cstring> &out,
                                     const auto &self) -> bool {
            if (d == nullptr) return false;
            if (auto *pe = d->to<IR::PathExpression>()) {
                out.push_back(pe->path->name);
                return true;
            }
            if (auto *mem = d->to<IR::Member>()) {
                if (!self(mem->expr, out, self)) return false;
                out.push_back(mem->member);
                return true;
            }
            // Unsupported designator shape (e.g., ArrayIndex/Slice). Caller will fall back.
            return false;
        };

        auto isAllDotDesignators = [&]() -> bool {
            if (list->components.empty()) return false;
            // If the first is a member-designator, assume the whole list is the designated form.
            auto *first = list->components.at(0);
            auto *di0 = first ? first->to<IR::P5DesignatedInitializer>() : nullptr;
            if (!di0 || !di0->isMember) return false;
            for (auto *c : list->components) {
                auto *di = c ? c->to<IR::P5DesignatedInitializer>() : nullptr;
                if (!di || !di->isMember) return false;
            }
            return true;
        };

        auto emitPathDesignator = [&](const std::vector<cstring> &p) {
            for (size_t i = 0; i < p.size(); ++i) {
                if (i == 0)
                    *outputStream << "." << p[i];
                else
                    *outputStream << "." << p[i];
            }
        };

        std::function<bool(const std::vector<DiItem> &, bool)> emitGrouped;
        emitGrouped = [&](const std::vector<DiItem> &items, bool topLevel) -> bool {
            if (items.empty()) return true;

            // Preserve first-seen order of outer keys.
            std::vector<cstring> order;
            std::unordered_map<cstring, std::vector<DiItem>> groups;
            order.reserve(items.size());

            for (const auto &it : items) {
                if (it.path.empty()) return false;
                const auto key = it.path.front();
                if (!groups.count(key)) order.push_back(key);
                groups[key].push_back(it);
            }

            bool firstOut = true;
            for (const auto &key : order) {
                const auto &g = groups.at(key);
                if (g.empty()) continue;

                // Split into direct (depth=1) and nested (depth>1).
                bool hasDirect = false;
                bool hasNested = false;
                for (const auto &it : g) {
                    if (it.path.size() == 1) hasDirect = true;
                    else hasNested = true;
                }

                // If we have both direct and nested initializers for the same key, do NOT rewrite
                // (ambiguous/likely invalid). Let original emission handle it.
                if (hasDirect && hasNested) return false;

                if (!firstOut) *outputStream << ", ";
                firstOut = false;

                if (hasNested) {
                    // Group: .key = { ... }
                    *outputStream << "." << key << " = { ";
                    std::vector<DiItem> inner;
                    inner.reserve(g.size());
                    for (const auto &it : g) {
                        DiItem sub;
                        sub.value = it.value;
                        sub.path.assign(it.path.begin() + 1, it.path.end());
                        inner.push_back(std::move(sub));
                    }
                    if (!emitGrouped(inner, /*topLevel=*/false)) return false;
                    *outputStream << " }";
                } else {
                    // Direct: .key = value
                    // (There can be multiple direct entries for the same key; keep them in-order.)
                    // Since we grouped, we need to emit all entries in this group.
                    // Use comma separation local to this group.
                    bool firstInGroup = true;
                    for (const auto &it : g) {
                        if (!firstInGroup) *outputStream << ", ";
                        firstInGroup = false;
                        emitPathDesignator(it.path);
                        *outputStream << " = ";
                        emitExpressionWithCtx(it.value, locals);
                    }
                }
            }

            (void)topLevel;
            return true;
        };

        if (isAllDotDesignators()) {
            std::vector<DiItem> items;
            items.reserve(list->components.size());
            bool ok = true;
            for (auto *c : list->components) {
                auto *di = c->to<IR::P5DesignatedInitializer>();
                std::vector<cstring> p;
                if (!collectMemberPath(di->designator, p, collectMemberPath) || p.empty()) {
                    ok = false;
                    break;
                }
                items.push_back(DiItem{std::move(p), di->value});
            }

            if (ok) {
                std::ostringstream buf;
                auto *old = outputStream;
                outputStream = &buf;
                bool rewrote = emitGrouped(items, /*topLevel=*/true);
                outputStream = old;

                if (rewrote) {
                    *outputStream << "{ " << buf.str() << " }";
                    return;
                }
            }
        }

        // Fallback: original emission.
        *outputStream << "{ ";
        bool first = true;
        for (auto *comp : list->components) {
            if (!first) *outputStream << ", ";
            first = false;
            emitExpressionWithCtx(comp, locals);
        }
        *outputStream << " }";
        return;
    }

    if (auto *slice = expr->to<IR::Slice>()) {
        emitExpressionWithCtx(slice->e0, locals);
        *outputStream << "[p5::bit_range<";
        emitExpressionWithCtx(slice->e1, locals);
        *outputStream << ", ";
        emitExpressionWithCtx(slice->e2, locals);
        *outputStream << ">]";
        return;
    }

    if (auto *ai = expr->to<IR::ArrayIndex>()) {
        emitExpressionWithCtx(ai->left, locals);
        if (ai->right && ai->right->is<IR::DefaultExpression>())
            return;
        *outputStream << "[";
        emitExpressionWithCtx(ai->right, locals);
        *outputStream << "]";
        return;
    }

    if (auto *cast = expr->to<IR::Cast>()) {
        emitFieldType(cast->destType);
        *outputStream << "(";
        emitExpressionWithCtx(cast->expr, locals);
        *outputStream << ")";
        return;
    }

    if (auto *bin = expr->to<IR::Operation_Binary>()) {
        *outputStream << "(";
        emitExpressionWithCtx(bin->left, locals);
        *outputStream << " " << bin->getStringOp() << " ";
        emitExpressionWithCtx(bin->right, locals);
        *outputStream << ")";
        return;
    }

    if (auto *un = expr->to<IR::Operation_Unary>()) {
        *outputStream << un->getStringOp();
        emitExpressionWithCtx(un->expr, locals);
        return;
    }

    if (auto *c = expr->to<IR::Constant>()) {
        *outputStream << c->value;
        return;
    }

    if (auto *b = expr->to<IR::BoolLiteral>()) {
        *outputStream << (b->value ? "true" : "false");
        return;
    }

    *outputStream << expr->toString();
}

bool P5ToC::isInlineInit(const IR::Declaration_Variable *var) {
    if (!var->initializer) return false;

    cstring typeName;
    if (auto *tn = var->type->to<IR::Type_Name>()) {
        typeName = tn->path->name;
    }

    if (typeName.isNullOrEmpty()) return false;

    if (auto *mc = var->initializer->to<IR::MethodCallExpression>()) {
        if (auto *pe = mc->method->to<IR::PathExpression>()) {
            if (pe->path->name == typeName) return true;
        }
    } else if (auto *cc = var->initializer->to<IR::ConstructorCallExpression>()) {
        if (auto *tn = cc->constructedType->to<IR::Type_Name>()) {
            if (tn->path->name == typeName) return true;
        }
    }
    return false;
}

void P5ToC::emitTableConstructor(const IR::P5Table *tbl) {
    *outputStream << indent << "explicit " << tbl->name << "(Switch &ctx_in";
    if (tbl->parameters) {
        for (const auto *param : tbl->parameters->parameters) {
            *outputStream << ", ";
            emitFieldType(param->type);
            *outputStream << " &" << param->name << "_in";
        }
    }
    *outputStream << ") : ctx(ctx_in)";
    if (tbl->parameters) {
        for (const auto *param : tbl->parameters->parameters) {
            *outputStream << ", " << param->name << "(" << param->name << "_in)";
        }
    }
    *outputStream << " {}\n\n";
}

void P5ToC::emitTableKeySelect(const IR::P5Key *keyNode, const LocalsMap &locals) {
    auto emitOneKeySwitch = [&](const IR::Expression *expr,
                                const IR::Vector<IR::P5KeyCase> &cases) {
        *outputStream << indent << "{\n";
        {
            IndentGuard igSwitch(this);
            *outputStream << indent << "auto _msw = p5::mswitch::tie(";
            if (auto *list = expr->to<IR::ListExpression>()) {
                bool first = true;
                for (auto *comp : list->components) {
                    if (!first) *outputStream << ", ";
                    first = false;
                    emitExpressionWithCtx(comp, locals);
                }
            } else {
                emitExpressionWithCtx(expr, locals);
            }
            *outputStream << ");\n";

            *outputStream << indent << "int _tag = 0;\n";

            int caseId = 0;
            bool firstMatch = true;
            if (!cases.empty()) {
                for (const auto *cse : cases) {
                    caseId++;
                    if (!cse->label || cse->label->is<IR::DefaultExpression>()) continue;

                    *outputStream << indent;
                    if (!firstMatch) *outputStream << "else ";
                    *outputStream << "if (p5::mswitch::match(_msw, ";

                    auto emitMatchArg = [&](const IR::Expression *e) {
                        if (auto *m = e->to<IR::Mask>()) {
                            *outputStream << "p5::mswitch::mask(";
                            emitExpressionWithCtx(m->left, locals);
                            *outputStream << ", ";
                            emitExpressionWithCtx(m->right, locals);
                            *outputStream << ")";
                            return;
                        }
                        emitExpressionWithCtx(e, locals);
                    };

                    const IR::Expression *label = cse->label;
                    if (auto *list = label->to<IR::ListExpression>()) {
                        bool firstArg = true;
                        for (auto *comp : list->components) {
                            if (!firstArg) *outputStream << ", ";
                            firstArg = false;
                            emitMatchArg(comp);
                        }
                    } else {
                        emitMatchArg(label);
                    }

                    *outputStream << ")) _tag = " << caseId << ";\n";
                    firstMatch = false;
                }
            }

            *outputStream << indent << "switch (_tag) {\n";
            {
                IndentGuard igCase(this);
                caseId = 0;
                if (!cases.empty()) {
                    for (const auto *cse : cases) {
                        caseId++;
                        *outputStream << indent;
                        const bool isDefault =
                            (!cse->label || cse->label->is<IR::DefaultExpression>());
                        const bool isFallthroughOnly = cse->fallthrough;

                        if (isDefault) {
                            *outputStream << "default:";
                        } else {
                            *outputStream << "case " << caseId << ":";
                        }

                        if (isFallthroughOnly) {
                            *outputStream << "\n";
                            continue;
                        }

                        *outputStream << " {\n";
                        {
                            IndentGuard igBody(this);
                            bool hasExpr = false;
                            for (const auto *elem : cse->elements) {
                                if (elem->expr) {
                                    hasExpr = true;
                                    *outputStream << indent << "_KeyBuilder.append(";
                                    emitExpressionWithCtx(elem->expr, locals);
                                    *outputStream << ");\n";
                                }
                                if (!elem->control.components.empty()) {
                                    for (const auto *c : elem->control.components) {
                                        emitComponent(c, locals);
                                    }
                                }
                            }
                            if (!hasExpr) {
                                *outputStream << indent << "_BuiltKey = false;\n";
                            }
                            *outputStream << indent << "break;\n";
                        }
                        *outputStream << indent << "}\n";
                    }
                }
            }
            *outputStream << indent << "}\n";
        }
        *outputStream << indent << "}\n";
    };

    if (!keyNode->switches.empty()) {
        for (const auto *sw : keyNode->switches) {
            emitOneKeySwitch(sw->select, sw->cases);
        }
        return;
    }
}

void P5ToC::emitTableKeyElements(const IR::P5Key *keyNode, const LocalsMap &locals) {
    bool hasExpr = false;
    for (const auto *elem : keyNode->elements) {
        if (elem->expr) {
            hasExpr = true;
            *outputStream << indent << "_KeyBuilder.append(";
            emitExpressionWithCtx(elem->expr, locals);
            *outputStream << ");\n";
        }
        if (!elem->control.components.empty()) {
            for (const auto *c : elem->control.components) {
                emitComponent(c, locals);
            }
        }
    }
    if (!hasExpr) {
        *outputStream << indent << "_BuiltKey = false;\n";
    }
}

void P5ToC::emitTableKeyMatching(const IR::P5Key *keyNode, const LocalsMap &locals) {
    // Emit key-building code in the same order as it appears in the body.
    // Scope the builder variables so multiple key blocks do not collide.
    *outputStream << indent << "{\n";
    {
        IndentGuard igKey(this);
        *outputStream << indent << "auto _KeyBuilder = ctx.keyBuilder();\n";
        *outputStream << indent << "bool _BuiltKey = true;\n";

        if (!keyNode->switches.empty()) {
            emitTableKeySelect(keyNode, locals);
        } else if (!keyNode->elements.empty()) {
            emitTableKeyElements(keyNode, locals);
        }

        *outputStream << indent << "if (_BuiltKey) {\n";
        {
            IndentGuard igCommit(this);
            *outputStream << indent << "_KeyBuilder.commit();\n";
        }
        *outputStream << indent << "}\n";
    }
    *outputStream << indent << "}\n";
}

void P5ToC::emitTable(const IR::P5Table *tbl) {
    if (tbl == nullptr) return;

    *outputStream << indent << "class " << tbl->name << " : public Table {\n";
    {
        IndentGuard ig(this);
        *outputStream << ig.old << "private:\n";
        *outputStream << indent << "Switch &ctx;\n";

        LocalsMap locals;

        if (tbl->parameters) {
            for (const auto *param : tbl->parameters->parameters) {
                locals.emplace(param->name, param->type);
                *outputStream << indent;
                emitFieldType(param->type);
                *outputStream << " &" << param->name << ";\n";
            }
        }

        *outputStream << ig.old << "public:\n";

        emitTableConstructor(tbl);

        if (tbl->body) {
            for (const auto *comp : tbl->body->components) {
                if (auto *var = comp->to<IR::Declaration_Variable>()) {
                    locals.emplace(var->name, var->type);
                    *outputStream << indent;
                    emitFieldType(var->type);
                    *outputStream << " " << var->name;

                    if (isInlineInit(var)) {
                        *outputStream << " = ";
                        emitExpressionWithCtx(var->initializer, locals);
                    }
                    *outputStream << ";\n";
                }
            }
        }

        *outputStream << "\n";
        *outputStream << indent << "void apply() override {\n";
        {
            IndentGuard ig(this);
            // if (tbl->name == "INGSF2FV_TBL" || tbl->name == "INGSF2FV_IF_TBL" ||
            //     tbl->name == "ENGSF2FV_TBL" || tbl->name == "ENGSF2FV_IF_TBL") {
            //     *outputStream << indent << "ctx.ngsf_direction = NgsfDirection::NGSF2FV;\n";
            // } else if (tbl->name == "IFV2NGSF_TBL") {
            //     *outputStream << indent << "ctx.ngsf_direction = NgsfDirection::FV2NGSF;\n";
            // }
            if (tbl->body) {
                for (const auto *comp : tbl->body->components) {
                    if (auto *keyNode = comp->to<IR::P5Key>()) {
                        emitTableKeyMatching(keyNode, locals);
                        continue;
                    }

                    if (auto *var = comp->to<IR::Declaration_Variable>()) {
                        if (var->initializer && !isInlineInit(var)) {
                            *outputStream << indent;
                            *outputStream << var->name << " = ";
                            emitExpressionWithCtx(var->initializer, locals);
                            *outputStream << ";\n";
                        }
                        continue;
                    }

                    emitComponent(comp, locals);
                }
            }
        }
        *outputStream << indent << "}\n";
    }
    *outputStream << indent << "};\n\n";
}

void P5ToC::emitFunction(const IR::Function *func, const std::string &class_name) {
    if (func == nullptr) return;
    // ClearFields is implemented in GenSim BuiltIn.hpp. Do not generate it here
    // to avoid duplicate definitions/declarations.
    if (func->name == "ClearFields") return;

    bool oldInSwitch = inSwitchMethod;
    if (class_name == "Switch::") {
        inSwitchMethod = true;
    }

    cstring oldFunctionName = currentFunctionName;
    currentFunctionName = func->name;
    AcceleratorNgsfDir oldAccel = currentAcceleratorNgsfDir;
    currentAcceleratorNgsfDir = AcceleratorNgsfDir::None;

    // Parse function annotation: @accelerator("NP") / @accelerator("NGSF")
    if (!func->annotations.empty()) {
        for (const auto *ann : func->annotations) {
            if (!ann) continue;
            if (!(ann->name == "accelerator" || ann->name == IR::ID("accelerator"))) continue;

            // Extract the first argument in a robust way:
            // - @accelerator("NP")   -> StringLiteral(value="NP")
            // - @accelerator(NP)     -> PathExpression(path="NP")
            // - fallback to textual normalization for other forms/unparsed tokens.
            std::string norm;
            if (std::holds_alternative<IR::Vector<IR::Expression>>(ann->body)) {
                const auto &exprs = std::get<IR::Vector<IR::Expression>>(ann->body);
                if (!exprs.empty() && exprs.at(0)) {
                    const auto *e0 = exprs.at(0);
                    if (auto *sl = e0->to<IR::StringLiteral>()) {
                        norm = sl->value.c_str();
                    } else if (auto *pe = e0->to<IR::PathExpression>()) {
                        norm = pe->path->name.toString();
                    } else {
                        // Last-resort: stringify and strip punctuation.
                        const std::string blob = e0->toString().c_str();
                        norm.reserve(blob.size());
                        for (char c : blob) {
                            if (std::isalnum(static_cast<unsigned char>(c)) || c == '_')
                                norm.push_back(c);
                        }
                    }
                }
            } else if (std::holds_alternative<IR::Vector<IR::AnnotationToken>>(ann->body)) {
                const auto &toks = std::get<IR::Vector<IR::AnnotationToken>>(ann->body);
                std::string blob;
                for (const auto *t : toks) {
                    if (t) blob += t->text.c_str();
                }
                norm.reserve(blob.size());
                for (char c : blob) {
                    if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') norm.push_back(c);
                }
            }

            if (norm == "NP" || norm.find("NP") != std::string::npos) {
                currentAcceleratorNgsfDir = AcceleratorNgsfDir::FV2NGSF;
                break;
            }
            if (norm == "NGSF" || norm.find("NGSF") != std::string::npos) {
                currentAcceleratorNgsfDir = AcceleratorNgsfDir::NGSF2FV;
                break;
            }
        }
    }

    emitFunctionSignature(func, class_name);

    LocalsMap locals;
    if (auto *mt = func->type->to<IR::Type_Method>()) {
        if (mt->parameters) {
            for (const auto *param : mt->parameters->parameters) {
                locals.emplace(param->name, param->type);
            }
        }
    }

    emitFunctionBody(func->body, locals);

    currentAcceleratorNgsfDir = oldAccel;
    currentFunctionName = oldFunctionName;
    inSwitchMethod = oldInSwitch;
}

void P5ToC::emitFunctionDeclaration(const IR::Function *func, const std::string &class_name) {
    if (func == nullptr) return;
    // ClearFields is implemented in GenSim BuiltIn.hpp. Do not redeclare it.
    if (func->name == "ClearFields") return;
    emitFunctionSignature(func, class_name);
    *outputStream << ";\n";
}

void P5ToC::emitStructMembers(const IR::Type_Struct *st, EmitMode mode, int &anon_counter) {
    if (st == nullptr) return;

    IndentGuard ig(this);
    for (const auto *field : st->fields) {
        *outputStream << indent;

        // Handle nested anonymous struct/union
        if (auto *nestedSt = field->type->to<IR::Type_Struct>()) {
            if (isAnonymous(nestedSt)) {
                std::string name = field->name.toString().c_str();
                bool isAnonField = (name == " " || name.empty());

                if (isUnion(nestedSt)) {
                    // Union: always use P5_UNION, members are always Memberized
                    if (isAnonField) name = "_noname_u_" + std::to_string(anon_counter++);

                    *outputStream << "P5_UNION(" << name << ", {\n";
                    emitStructMembers(nestedSt, EmitMode::Memberized, anon_counter);
                    *outputStream << indent << "});\n";
                } else {
                    // Struct: inherits mode
                    if (isAnonField) name = "_noname_st_" + std::to_string(anon_counter++);

                    *outputStream << "struct {\n";
                    emitStructMembers(nestedSt, mode, anon_counter);
                    *outputStream << indent << "} " << name << ";\n";
                }
                continue;
            }
        }

        // Standard field
        const IR::Type *baseType = field->type;
        std::vector<const IR::Expression *> dims;
        while (auto *stk = baseType->to<IR::Type_Stack>()) {
            dims.push_back(stk->size);
            baseType = stk->elementType;
        }

        emitFieldType(baseType, mode);
        if (field->name != " " && field->name != cstring::empty) {
            *outputStream << " " << field->name;
        }
        for (auto *dim : dims) {
            *outputStream << "[";
            if (dim) {
                emitExpressionWithCtx(dim, {});
            }
            *outputStream << "]";
        }
        *outputStream << ";\n";
    }
}

void P5ToC::emitNestedStructOrUnion(const IR::Type_Struct *st, EmitMode mode, int &anon_counter) {
    // Legacy/Fallback: Just emit struct body
    *outputStream << "struct {\n";
    emitStructMembers(st, mode, anon_counter);
    *outputStream << indent << "}";
}

void P5ToC::emitStructOrUnionImpl(const IR::Type_Struct *st, bool isNested, EmitMode mode,
                                  int &anon_counter) {
    if (st == nullptr) return;

    bool isUnionType = isUnion(st);
    if (isUnionType) {
        // Top-level union
        *outputStream << "struct _Layout_" << st->name << " {\n";
        emitStructMembers(st, EmitMode::Memberized, anon_counter);
        *outputStream << indent << "}";
    } else {
        // Top-level struct
        std::string name = st->name.toString().c_str();
        if (mode == EmitMode::Memberized) name = "_inU_" + name;

        *outputStream << "struct " << name << " {\n";
        emitStructMembers(st, mode, anon_counter);
        *outputStream << indent << "}";
    }

    if (!isNested) {
        *outputStream << ";\n";
    }

    if (isUnionType) {
        *outputStream << "using " << st->name << " = p5::Union<_Layout_" << st->name << ">;\n";
    }

    if (!isNested) {
        *outputStream << "\n";
    }
}

void P5ToC::emitStructOrUnion(const IR::Type_Struct *st, bool isNested) {
    int anon_counter = 0;

    // Pass 1: Standard (or Memberized if Union)
    bool isUnionType = isUnion(st);
    if (isUnionType) {
        emitStructOrUnionImpl(st, isNested, EmitMode::Memberized, anon_counter);
    } else {
        emitStructOrUnionImpl(st, isNested, EmitMode::Standard, anon_counter);

        // Pass 2: Generate _inU_ version for named structs
        if (!isNested && !isAnonymous(st)) {
            anon_counter = 0;  // Reset counter to ensure deterministic names
            emitStructOrUnionImpl(st, isNested, EmitMode::Memberized, anon_counter);
        }
    }
}

void P5ToC::emitEnumsHpp(const IR::P4Program *program) {
    outputStream = getStream("include/generated_enum.hpp");

    *outputStream << "#ifndef GENERATED_ENUM_HPP\n"
                  << "#define GENERATED_ENUM_HPP\n"
                  << "\n"
                  << "#include \"table.hpp\"\n"
                  << "#include \"SE.hpp\"\n"
                  << "#include \"key.hpp\"\n"
                  << "#include \"BuiltIn.hpp\"\n"
                  << "#include \"p5_types.hpp\"\n"
                  << "#include \"model_intf_1027.h\"\n"
                  << "\n";
    for (const auto *obj : program->objects) {
        if (auto *serEnum = obj->to<IR::Type_SerEnum>()) {
            emitSerEnum(serEnum);
        }
    }
    *outputStream << "#endif // GENERATED_ENUM_HPP\n";

    outputStream = defaultStream;
}

void P5ToC::emitStructHpp(const IR::P4Program *program) {
    outputStream = getStream("include/generated_struct.hpp");

    *outputStream << "#ifndef GENERATED_STRUCT_HPP\n"
                  << "#define GENERATED_STRUCT_HPP\n"
                  << "\n"
                  << "#include \"table.hpp\"\n"
                  << "#include \"SE.hpp\"\n"
                  << "#include \"key.hpp\"\n"
                  << "#include \"BuiltIn.hpp\"\n"
                  << "#include \"p5_types.hpp\"\n"
                  << "#include \"model_intf_1027.h\"\n"
                  << "\n"
                  << "#include \"generated_enum.hpp\"\n"
                  << "\n";

    emitStructsAndUnions(program);

    for (const auto *obj : program->objects) {
        if (auto *td = obj->to<IR::Type_Typedef>()) {
            emitTypedef(td);
        }
    }

    *outputStream << "\n#endif // GENERATED_STRUCT_HPP\n";

    outputStream = defaultStream;
}

void P5ToC::emitGtvHpp(const IR::P4Program *program) {
    outputStream = getStream("include/generated_gtv.hpp");

    *outputStream << "#ifndef GENERATED_GTV_HPP\n"
                  << "#define GENERATED_GTV_HPP\n"
                  << "\n"
                  << "#include <array>\n"
                  << "#include <cstdint>\n"
                  << "#include <string>\n"
                  << "#include <string_view>\n"
                  << "#include <type_traits>\n"
                  << "#include <unordered_map>\n"
                  << "#include <utility>\n"
                  << "#include <vector>\n"
                  << "\n"
                  << "#include <boost/pfr.hpp>\n"
                  << "\n"
                  << "#include \"table.hpp\"\n"
                  << "#include \"SE.hpp\"\n"
                  << "#include \"key.hpp\"\n"
                  << "#include \"BuiltIn.hpp\"\n"
                  << "#include \"p5_types.hpp\"\n"
                  << "#include \"model_intf_1027.h\"\n"
                  << "\n"
                  << "#include \"generated_struct.hpp\"\n"
                  << "\n";

    *outputStream << "class GtvContext {\n"
                  << "  public:\n";
    {
        IndentGuard ig(this);
        emitHeaders(program);
        *outputStream << "\n";

        for (const auto *obj : program->objects) {
            if (auto *var = obj->to<IR::Declaration_Variable>()) {
                emitVariableDecl(var);
            }
        }
        *outputStream << "\n";

        *outputStream << indent << "enum class NgsfDirection : uint8_t { FV2NGSF = 0, NGSF2FV = 1 };\n"
                      << indent << "NgsfDirection ngsf_direction{NgsfDirection::FV2NGSF};\n"
                      << "\n"
                      << indent << "std::size_t ngsf_byte_offset{0};\n"
                      << indent << "uint8_t ngsf_bit_offset{0};\n"
                      << "\n"
                      << indent << "enum class NPorTM : uint8_t { NP = 0, TM = 1 };\n"
                      << indent << "NPorTM npor_tm{NPorTM::NP};\n"
                      << "\n"
                      << indent << "std::size_t tm_byte_offset{0};\n"
                      << indent << "uint8_t tm_bit_offset{0};\n"
                      << "\n"
                      << indent << "// Track last direction to auto-reset offsets on direction changes.\n"
                      << indent << "NgsfDirection last_ngsf_direction{ngsf_direction};\n"
                      << "\n"
                      << indent << "void reset_ngsf_offset() { \n"
                      << indent << "    ngsf_byte_offset = 0;\n"
                      << indent << "    ngsf_bit_offset = 0;\n"
                      << indent << "    tm_byte_offset = 0;\n"
                      << indent << "    tm_bit_offset = 0;\n"
                      << indent << "}\n"
                      << "\n";

        *outputStream << indent << "void maybe_reset_offsets_on_direction_change() {\n"
                      << indent << "    if (last_ngsf_direction == ngsf_direction) return;\n"
                      << "\n"
                      << indent << "    // Always reset NGSF cursor when direction changes.\n"
                      << indent << "    ngsf_byte_offset = 0;\n"
                      << indent << "    ngsf_bit_offset = 0;\n"
                      << "\n"
                      << indent << "    // Only reset TM cursor when switching from restore->append.\n"
                      << indent << "    if (last_ngsf_direction == NgsfDirection::NGSF2FV && ngsf_direction == NgsfDirection::FV2NGSF) {\n"
                      << indent << "        tm_byte_offset = 0;\n"
                      << indent << "        tm_bit_offset = 0;\n"
                      << indent << "    }\n"
                      << "\n"
                      << indent << "    last_ngsf_direction = ngsf_direction;\n"
                      << indent << "}\n"
                      << "\n";

        *outputStream << indent << "template <typename T>\n"
                      << indent << "void _add_to_ngsf(T &value) {\n"
                      << indent << "    maybe_reset_offsets_on_direction_change();\n"
                      << indent << "    if (ngsf_direction == NgsfDirection::FV2NGSF) {\n"
                      << indent << "        ngsf_append_any(value);\n"
                      << indent << "        if (npor_tm == NPorTM::TM) {\n"
                      << indent << "            tm_byte_offset = ngsf_byte_offset;\n"
                      << indent << "            tm_bit_offset = ngsf_bit_offset;\n"
                      << indent << "        }\n"
                      << indent << "    } else {\n"
                      << indent << "        ngsf_restore_any(value);\n"
                      << indent << "    }\n"
                      << indent << "}\n"
                      << "\n"
                      << indent << "template <typename T>\n"
                      << indent << "void _add_to_ngsf(const T &value) {\n"
                      << indent << "    maybe_reset_offsets_on_direction_change();\n"
                      << indent << "    if (ngsf_direction == NgsfDirection::FV2NGSF) {\n"
                      << indent << "        ngsf_append_any(value);\n"
                      << indent << "        if (npor_tm == NPorTM::TM) {\n"
                      << indent << "            tm_byte_offset = ngsf_byte_offset;\n"
                      << indent << "            tm_bit_offset = ngsf_bit_offset;\n"
                      << indent << "        }\n"
                      << indent << "    } else {\n"
                      << indent << "        // Restore direction:\n"
                      << indent << "        // - For most temporaries (e.g. p5::uint<N>(...)), we cannot write back, so we skip bits.\n"
                      << indent << "        // - For slice proxies (p5::uint::slice_proxy / p5::member::slice_proxy), even a temporary\n"
                      << indent << "        //   proxy still references underlying storage, so we *can* restore through it.\n"
                      << indent << "        using D = std::decay_t<T>;\n"
                      << indent << "        if constexpr (is_p5_slice_proxy_type<D>::value) {\n"
                      << indent << "            auto proxy = value; // copy the proxy handle (still points to original storage)\n"
                      << indent << "            ngsf_restore_any(proxy);\n"
                      << indent << "        } else {\n"
                      << indent << "            // Consume bits to keep stream aligned.\n"
                      << indent << "            ngsf_skip_any<T>();\n"
                      << indent << "        }\n"
                      << indent << "    }\n"
                      << indent << "}\n"
                      << "\n";

        *outputStream
            << indent << "// Mapping converter:\n"
            << indent << "// - Maintains multiple named mapping tables (by the first string parameter).\n"
            << indent << "// - Each mapping table has two logical directions:\n"
            << indent << "//   FV2NGSF: key = 4th parameter, value = (2nd, 3rd)\n"
            << indent << "//   NGSF2FV: key = concat(2nd, 3rd), value = 4th\n"
            << indent << "//\n"
            << indent << "// Example:\n"
            << indent << "//   _mapping_converter(\"GLTP\", TB, TP, GLTP);\n"
            << indent << "//     - FV2NGSF: lookup by GLTP, set TB/TP\n"
            << indent << "//     - NGSF2FV: lookup by (TB||TP), set GLTP\n"
            << indent << "template <typename U2, typename U3, typename U4>\n"
            << indent
            << "void _mapping_converter(std::string_view table_name, U2 &v2, U3 &v3, U4 &v4) {\n"
            << indent << "    using D2 = std::decay_t<U2>;\n"
            << indent << "    using D3 = std::decay_t<U3>;\n"
            << indent << "    using D4 = std::decay_t<U4>;\n"
            << indent
            << "    static_assert(is_p5_uint_type<D2>::value, \"_mapping_converter: 2nd arg must be p5::uint<N>\");\n"
            << indent
            << "    static_assert(is_p5_uint_type<D3>::value, \"_mapping_converter: 3rd arg must be p5::uint<N>\");\n"
            << indent
            << "    static_assert(is_p5_uint_type<D4>::value, \"_mapping_converter: 4th arg must be p5::uint<N>\");\n"
            << "\n"
            << indent << "    auto &tbl = mapping_tables_[std::string(table_name)];\n"
            << "\n"
            << indent << "    if (ngsf_direction == NgsfDirection::FV2NGSF) {\n"
            << indent << "        const auto key = bits_key(v4);\n"
            << indent << "        auto it = tbl.fv2ngsf.find(key);\n"
            << indent << "        if (it == tbl.fv2ngsf.end()) {\n"
            << indent << "            v2 = 0;\n"
            << indent << "            v3 = 0;\n"
            << indent << "            return;\n"
            << indent << "        }\n"
            << indent << "        assign_from_key<D2>(v2, it->second.first);\n"
            << indent << "        assign_from_key<D3>(v3, it->second.second);\n"
            << indent << "        return;\n"
            << indent << "    }\n"
            << "\n"
            << indent << "    // NGSF2FV\n"
            << indent << "    const auto key = bits_key_concat(v2, v3);\n"
            << indent << "    auto it = tbl.ngsf2fv.find(key);\n"
            << indent << "    if (it == tbl.ngsf2fv.end()) {\n"
            << indent << "        v4 = 0;\n"
            << indent << "        return;\n"
            << indent << "    }\n"
            << indent << "    assign_from_key<D4>(v4, it->second);\n"
            << indent << "}\n"
            << "\n"
            << indent << "// Optional configuration helper: add one entry for the CURRENT direction only.\n"
            << indent << "// - When ngsf_direction == FV2NGSF: add FV2NGSF entry (key=v4 -> (v2,v3))\n"
            << indent << "// - When ngsf_direction == NGSF2FV: add NGSF2FV entry (key=(v2||v3) -> v4)\n"
            << indent << "template <typename U2, typename U3, typename U4>\n"
            << indent
            << "void _mapping_add(std::string_view table_name, const U2 &v2, const U3 &v3, const U4 &v4) {\n"
            << indent << "    using D2 = std::decay_t<U2>;\n"
            << indent << "    using D3 = std::decay_t<U3>;\n"
            << indent << "    using D4 = std::decay_t<U4>;\n"
            << indent
            << "    static_assert(is_p5_uint_type<D2>::value, \"_mapping_add: 2nd arg must be p5::uint<N>\");\n"
            << indent
            << "    static_assert(is_p5_uint_type<D3>::value, \"_mapping_add: 3rd arg must be p5::uint<N>\");\n"
            << indent
            << "    static_assert(is_p5_uint_type<D4>::value, \"_mapping_add: 4th arg must be p5::uint<N>\");\n"
            << "\n"
            << indent << "    auto &tbl = mapping_tables_[std::string(table_name)];\n"
            << indent << "    if (ngsf_direction == NgsfDirection::FV2NGSF) {\n"
            << indent << "        tbl.fv2ngsf[bits_key(v4)] = {bits_key(v2), bits_key(v3)};\n"
            << indent << "    } else {\n"
            << indent << "        tbl.ngsf2fv[bits_key_concat(v2, v3)] = bits_key(v4);\n"
            << indent << "    }\n"
            << indent << "}\n"
            << "\n";

        *outputStream << indent
                      << "// Packed GTV buffer contains both gtvData and pgtvData parts.\n"
                      << indent << "using GtvPackedBuffer = std::array<uint8_t, FV_GTV_MAX_BYTE_NUM + FV_PGTV_BYTE_NUM>;\n"
                      << indent << "using PhiPackedBuffer = std::array<uint8_t, FV_PHI_BYTE_NUM>;\n"
                      << indent << "using PhoPackedBuffer = std::array<uint8_t, FV_PHO_BYTE_NUM>;\n"
                      << "\n";

        emitPhiPackUnpack(program);
        emitPhoPackUnpack(program);
        emitPackGtvToBytes(program);
        emitUnpackGtvFromBytes(program);

        *outputStream
            << "protected:\n"
            << "    struct _MappingTable {\n"
            << "        // key: bits(v4) -> (bits(v2), bits(v3))\n"
            << "        std::unordered_map<std::string, std::pair<std::string, std::string>> fv2ngsf;\n"
            << "        // key: bits(v2)||bits(v3) -> bits(v4)\n"
            << "        std::unordered_map<std::string, std::string> ngsf2fv;\n"
            << "    };\n"
            << "\n"
            << "    std::unordered_map<std::string, _MappingTable> mapping_tables_;\n"
            << "\n"
            << "    template <typename T>\n"
            << "    static std::string bits_key(const T &v) {\n"
            << "        std::vector<bool> bits;\n"
            << "        bits.reserve(std::decay_t<T>::width());\n"
            << "        append_bits(bits, v);\n"
            << "        std::string out;\n"
            << "        out.reserve(bits.size());\n"
            << "        for (bool b : bits) out.push_back(b ? '1' : '0');\n"
            << "        return out;\n"
            << "    }\n"
            << "\n"
            << "    template <typename A, typename B>\n"
            << "    static std::string bits_key_concat(const A &a, const B &b) {\n"
            << "        std::vector<bool> bits;\n"
            << "        bits.reserve(std::decay_t<A>::width() + std::decay_t<B>::width());\n"
            << "        append_bits(bits, a);\n"
            << "        append_bits(bits, b);\n"
            << "        std::string out;\n"
            << "        out.reserve(bits.size());\n"
            << "        for (bool bb : bits) out.push_back(bb ? '1' : '0');\n"
            << "        return out;\n"
            << "    }\n"
            << "\n"
            << "    template <typename Dst>\n"
            << "    static void assign_from_key(Dst &dst, const std::string &key_bits) {\n"
            << "        constexpr std::size_t W = Dst::width();\n"
            << "        p5::uint<W> tmp{};\n"
            << "        // key_bits is MSB-first (same as append_bits output order)\n"
            << "        const std::size_t n = key_bits.size();\n"
            << "        const std::size_t lim = (n < W) ? n : W;\n"
            << "        for (std::size_t i = 0; i < lim; ++i) {\n"
            << "            tmp[W - 1 - i] = (key_bits[i] == '1');\n"
            << "        }\n"
            << "        // If key_bits shorter than W, remaining bits stay 0.\n"
            << "        dst = tmp;\n"
            << "    }\n"
            << "\n"
            << "    template <typename T>\n"
            << "    struct is_p5_uint_type : std::false_type {};\n"
            << "    template <std::size_t N>\n"
            << "    struct is_p5_uint_type<p5::uint<N>> : std::true_type {};\n"
            << "\n"
            << "    template <typename T>\n"
            << "    struct is_p5_member_type : std::false_type {};\n"
            << "    template <typename UIntT>\n"
            << "    struct is_p5_member_type<p5::member<UIntT>> : std::true_type {};\n"
            << "\n"
            << "    template <typename T>\n"
            << "    struct is_p5_union_type : std::false_type {};\n"
            << "    template <typename Layout>\n"
            << "    struct is_p5_union_type<p5::Union<Layout>> : std::true_type {};\n"
            << "\n"
            << "    // p5::uint::slice_proxy / p5::member::slice_proxy support:\n"
            << "    // Both slice proxy types expose a public nested `value_type` which is a p5::uint<W>.\n"
            << "    // Note: we intentionally *don't* try to name the proxy types directly (uint::slice_proxy\n"
            << "    // is a private nested type). Instead, we detect them structurally.\n"
            << "    template <typename T, typename = void>\n"
            << "    struct is_p5_slice_proxy_type : std::false_type {};\n"
            << "    template <typename T>\n"
            << "    struct is_p5_slice_proxy_type<T, std::void_t<typename std::decay_t<T>::value_type>>\n"
            << "        : std::bool_constant<\n"
            << "              is_p5_uint_type<std::decay_t<typename std::decay_t<T>::value_type>>::value &&\n"
            << "              !is_p5_uint_type<std::decay_t<T>>::value &&\n"
            << "              !is_p5_member_type<std::decay_t<T>>::value &&\n"
            << "              !is_p5_union_type<std::decay_t<T>>::value> {};\n"
            << "\n"
            << "    template <typename P5UInt>\n"
            << "    static void append_bits(std::vector<bool> &bits, const P5UInt &value) {\n"
            << "        using Raw = std::remove_reference_t<P5UInt>;\n"
            << "        if constexpr (std::is_array_v<Raw>) {\n"
            << "            constexpr std::size_t N = std::extent_v<Raw>;\n"
            << "            for (std::size_t i = 0; i < N; ++i) {\n"
            << "                append_bits(bits, value[i]);\n"
            << "            }\n"
            << "        } else {\n"
            << "            using T = std::decay_t<P5UInt>;\n"
            << "            if constexpr (is_p5_union_type<T>::value) {\n"
            << "                constexpr std::size_t width = T::width();\n"
            << "                // For p5::Union: treat it as its underlying storage bits (width = base storage width).\n"
            << "                // Write bits in high-first order.\n"
            << "                const auto raw = value.to_uint(); // p5::uint<width>\n"
            << "                for (std::size_t i = 0; i < width; ++i) {\n"
            << "                    bits.push_back(static_cast<bool>(raw[width - 1 - i]));\n"
            << "                }\n"
            << "            } else if constexpr (is_p5_slice_proxy_type<T>::value) {\n"
            << "                // slice_proxy: materialize to its value_type (p5::uint<W>) and recurse.\n"
            << "                using V = typename T::value_type;\n"
            << "                append_bits(bits, static_cast<V>(value));\n"
            << "            } else if constexpr (is_p5_uint_type<T>::value || is_p5_member_type<T>::value) {\n"
            << "                constexpr std::size_t width = T::width();\n"
            << "                // For p5::uint / p5::member: read bits directly (high-first).\n"
            << "                for (std::size_t i = 0; i < width; ++i) {\n"
            << "                    bits.push_back(static_cast<bool>(value[width - 1 - i]));\n"
            << "                }\n"
            << "            } else {\n"
            << "                static_assert(std::is_aggregate_v<T>,\n"
            << "                              \"append_bits supports only p5::uint/p5::member/p5::Union, arrays of them, \"\n"
            << "                              \"or aggregates composed of them.\");\n"
            << "                boost::pfr::for_each_field(value, [&](const auto &sub) { append_bits(bits, sub); });\n"
            << "            }\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename Buffer, typename P5UInt>\n"
            << "    static void assign_from_bits(const Buffer &buf, std::size_t &cursor, P5UInt "
               "&target) {\n"
            << "        using Raw = std::remove_reference_t<P5UInt>;\n"
            << "        if constexpr (std::is_array_v<Raw>) {\n"
            << "            constexpr std::size_t N = std::extent_v<Raw>;\n"
            << "            for (std::size_t i = 0; i < N; ++i) {\n"
            << "                assign_from_bits(buf, cursor, target[i]);\n"
            << "            }\n"
            << "        } else {\n"
            << "            using T = std::decay_t<P5UInt>;\n"
            << "            if constexpr (is_p5_slice_proxy_type<T>::value) {\n"
            << "                constexpr std::size_t width = p5::bit_width_v<typename T::value_type>;\n"
            << "\n"
            << "                p5::uint<width> tmp{};\n"
            << "                for (std::size_t i = 0; i < width && cursor < buf.size() * 8; ++i, ++cursor) {\n"
            << "                    const std::size_t byte_idx = cursor / 8;\n"
            << "                    const std::size_t bit_idx = 7 - (cursor % 8); // 高位在前\n"
            << "                    const bool bit = (buf[byte_idx] >> bit_idx) & 0x1;\n"
            << "                    tmp[width - 1 - i] = bit; // i=0 is MSB\n"
            << "                }\n"
            << "                target = tmp;\n"
            << "            } else if constexpr (is_p5_uint_type<T>::value || is_p5_member_type<T>::value || is_p5_union_type<T>::value) {\n"
            << "                constexpr std::size_t width = T::width();\n"
            << "\n"
            << "                // Read width bits from buffer in high-first order, then assign to target.\n"
            << "                // This works for p5::uint, p5::member and p5::Union (writes to union's base storage).\n"
            << "                p5::uint<width> tmp{};\n"
            << "                for (std::size_t i = 0; i < width && cursor < buf.size() * 8; ++i, ++cursor) {\n"
            << "                    const std::size_t byte_idx = cursor / 8;\n"
            << "                    const std::size_t bit_idx = 7 - (cursor % 8); // 高位在前\n"
            << "                    const bool bit = (buf[byte_idx] >> bit_idx) & 0x1;\n"
            << "                    tmp[width - 1 - i] = bit; // i=0 is MSB\n"
            << "                }\n"
            << "                target = tmp;\n"
            << "            } else {\n"
            << "                static_assert(std::is_aggregate_v<T>,\n"
            << "                              \"assign_from_bits supports only p5::uint/p5::member/p5::Union, arrays of them, \"\n"
            << "                              \"or aggregates composed of them.\");\n"
            << "                boost::pfr::for_each_field(target, [&](auto &sub) { assign_from_bits(buf, cursor, sub); });\n"
            << "            }\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename Buffer>\n"
            << "    static void write_bits_to_buffer(const std::vector<bool> &bits, Buffer &out) "
               "{\n"
            << "        for (std::size_t i = 0; i < bits.size() && i < out.size() * 8; ++i) {\n"
            << "            if (bits[i]) {\n"
            << "                const std::size_t byte_idx = i / 8;\n"
            << "                const std::size_t bit_idx = 7 - (i % 8);\n"
            << "                out[byte_idx] |= static_cast<uint8_t>(1u << bit_idx);\n"
            << "            }\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    // ============================ NGSF helpers ============================\n"
            << "    // NGSFBuffer is an array of fixed-width p5::uint<W> words. The word count and word width\n"
            << "    // are not assumed to be 64 and 8; compute them from the actual type.\n"
            << "    static constexpr std::size_t ngsf_word_bits() {\n"
            << "        using Word = std::decay_t<decltype(NGSFBuffer[0])>;\n"
            << "        return p5::bit_width_v<Word>;\n"
            << "    }\n"
            << "    static constexpr std::size_t ngsf_word_count() {\n"
            << "        using Arr = std::remove_reference_t<decltype(NGSFBuffer)>;\n"
            << "        return std::extent_v<Arr>;\n"
            << "    }\n"
            << "    static constexpr std::size_t ngsf_capacity_bits() { return ngsf_word_count() * ngsf_word_bits(); }\n"
            << "\n"
            << "    bool ngsf_has_capacity(std::size_t bits_needed) const {\n"
            << "        const std::size_t cur_bits = ngsf_byte_offset * ngsf_word_bits() + ngsf_bit_offset;\n"
            << "        return cur_bits + bits_needed <= ngsf_capacity_bits();\n"
            << "    }\n"
            << "\n"
            << "    void ngsf_write_bit(bool bit) {\n"
            << "        if (ngsf_byte_offset >= ngsf_word_count()) return;\n"
            << "        // bit_offset is MSB-first; p5::uint bit index (W-1) is MSB.\n"
            << "        const std::size_t W = ngsf_word_bits();\n"
            << "        NGSFBuffer[ngsf_byte_offset][static_cast<std::size_t>(W - 1 - ngsf_bit_offset)] = bit;\n"
            << "        ++ngsf_bit_offset;\n"
            << "        if (ngsf_bit_offset >= ngsf_word_bits()) {\n"
            << "            ngsf_bit_offset = 0;\n"
            << "            ++ngsf_byte_offset;\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    bool ngsf_read_bit() {\n"
            << "        if (ngsf_byte_offset >= ngsf_word_count()) return false;\n"
            << "        const std::size_t W = ngsf_word_bits();\n"
            << "        const bool bit = NGSFBuffer[ngsf_byte_offset][static_cast<std::size_t>(W - 1 - ngsf_bit_offset)];\n"
            << "        ++ngsf_bit_offset;\n"
            << "        if (ngsf_bit_offset >= ngsf_word_bits()) {\n"
            << "            ngsf_bit_offset = 0;\n"
            << "            ++ngsf_byte_offset;\n"
            << "        }\n"
            << "        return bit;\n"
            << "    }\n"
            << "\n"
            << "    template <typename P5T>\n"
            << "    static constexpr std::size_t ngsf_width_bits() {\n"
            << "        using D = std::decay_t<P5T>;\n"
            << "        if constexpr (is_p5_union_type<D>::value) {\n"
            << "            return D::width();\n"
            << "        } else if constexpr (is_p5_uint_type<D>::value) {\n"
            << "            return D::width();\n"
            << "        } else if constexpr (is_p5_member_type<D>::value) {\n"
            << "            return D::width();\n"
            << "        } else if constexpr (is_p5_slice_proxy_type<D>::value) {\n"
            << "            return p5::bit_width_v<typename D::value_type>;\n"
            << "        } else {\n"
            << "            return 0;\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename Field>\n"
            << "    void ngsf_append_leaf(const Field &field) {\n"
            << "        using D = std::decay_t<Field>;\n"
            << "        constexpr std::size_t W = ngsf_width_bits<D>();\n"
            << "        static_assert(W > 0, \"Unsupported NGSF leaf type\");\n"
            << "\n"
            << "        if constexpr (is_p5_union_type<D>::value) {\n"
            << "            const auto raw = field.to_uint(); // p5::uint<W>\n"
            << "            for (std::size_t i = 0; i < W; ++i) {\n"
            << "                ngsf_write_bit(raw[W - 1 - i]);\n"
            << "            }\n"
            << "        } else {\n"
            << "            for (std::size_t i = 0; i < W; ++i) {\n"
            << "                ngsf_write_bit(field[W - 1 - i]);\n"
            << "            }\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename Field>\n"
            << "    void ngsf_restore_leaf(Field &field) {\n"
            << "        using D = std::decay_t<Field>;\n"
            << "        constexpr std::size_t W = ngsf_width_bits<D>();\n"
            << "        static_assert(W > 0, \"Unsupported NGSF leaf type\");\n"
            << "\n"
            << "        p5::uint<W> tmp{};\n"
            << "        for (std::size_t i = 0; i < W; ++i) {\n"
            << "            const bool bit = ngsf_read_bit();\n"
            << "            tmp[W - 1 - i] = bit;\n"
            << "        }\n"
            << "        // Works for p5::uint / p5::member / p5::Union (writes underlying storage/view).\n"
            << "        field = tmp;\n"
            << "    }\n"
            << "\n"
            << "    template <typename Field>\n"
            << "    void ngsf_skip_leaf() {\n"
            << "        using D = std::decay_t<Field>;\n"
            << "        constexpr std::size_t W = ngsf_width_bits<D>();\n"
            << "        static_assert(W > 0, \"Unsupported NGSF leaf type\");\n"
            << "        for (std::size_t i = 0; i < W; ++i) {\n"
            << "            (void)ngsf_read_bit();\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename T>\n"
            << "    void ngsf_skip_any() {\n"
            << "        using D = std::decay_t<T>;\n"
            << "        if constexpr (is_p5_uint_type<D>::value || is_p5_member_type<D>::value || is_p5_union_type<D>::value ||\n"
            << "                      is_p5_slice_proxy_type<D>::value) {\n"
            << "            ngsf_skip_leaf<D>();\n"
            << "        } else {\n"
            << "            static_assert(std::is_aggregate_v<D>,\n"
            << "                          \"_add_to_ngsf supports only p5::uint/p5::member/p5::Union or aggregates composed of them.\");\n"
            << "            static_assert(std::is_default_constructible_v<D>,\n"
            << "                          \"ngsf_skip_any requires aggregate types to be default-constructible.\");\n"
            << "            D tmp{};\n"
            << "            boost::pfr::for_each_field(tmp, [&](auto &sub) { ngsf_skip_any<std::decay_t<decltype(sub)>>(); });\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename T>\n"
            << "    void ngsf_append_any(const T &value) {\n"
            << "        using D = std::decay_t<T>;\n"
            << "        if constexpr (is_p5_uint_type<D>::value || is_p5_member_type<D>::value || is_p5_union_type<D>::value ||\n"
            << "                      is_p5_slice_proxy_type<D>::value) {\n"
            << "            ngsf_append_leaf(value);\n"
            << "        } else {\n"
            << "            static_assert(std::is_aggregate_v<D>,\n"
            << "                          \"_add_to_ngsf supports only p5::uint/p5::member/p5::Union or aggregates composed of them.\");\n"
            << "            boost::pfr::for_each_field(value, [&](const auto &sub) { ngsf_append_any(sub); });\n"
            << "        }\n"
            << "    }\n"
            << "\n"
            << "    template <typename T>\n"
            << "    void ngsf_restore_any(T &value) {\n"
            << "        using D = std::decay_t<T>;\n"
            << "        if constexpr (is_p5_uint_type<D>::value || is_p5_member_type<D>::value || is_p5_union_type<D>::value ||\n"
            << "                      is_p5_slice_proxy_type<D>::value) {\n"
            << "            ngsf_restore_leaf(value);\n"
            << "        } else {\n"
            << "            static_assert(std::is_aggregate_v<D>,\n"
            << "                          \"_add_to_ngsf supports only p5::uint/p5::member/p5::Union or aggregates composed of them.\");\n"
            << "            boost::pfr::for_each_field(value, [&](auto &sub) { ngsf_restore_any(sub); });\n"
            << "        }\n"
            << "    }\n";
    }
    *outputStream << "};\n";

    *outputStream << "\n#endif // GENERATED_GTV_HPP\n";

    outputStream = defaultStream;
}

void P5ToC::emitSwitchRuntimeImpl() {
    *outputStream << "// ========== interface 实现 ==========\n"
                  << "void Switch::PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, "
                     "NhiDef &nhi_info, \n"
                  << "                    Cp2NpHeader &cp2np_hdr, const PktHeader &pkt_hdr, "
                     "Prs2Ma0FvInfoDef &fv_info) {\n"
                  << "    (void)nhi_info;\n"
                  << "    (void)cp2np_hdr;\n"
                  << "    // 载入原始包\n"
                  << "    std::memcpy(data_.data(), pkt_hdr.pkt_data, PKT_HEADER_BYTE_LEN);\n"
                  << "    reset_offset();\n"
                  << "    // 基础字段\n"
                  << "    PHI.PortType = parser_hinfo.port_type;\n"
                  << "    GLSP = parser_hinfo.port_id;\n"
                  << "\n"
                  << "    if (direction == 0) {\n"
                  << "        pre_iMAControl();\n"
                  << "    } else if (direction == 1) {\n"
                  << "        pre_eMAControl();\n"
                  << "    }\n"
                  << "\n"
                  << "    // 打包输出\n"
                  << "    std::memcpy(fv_info.phData, data_.data(), PKT_HEADER_BYTE_LEN);\n"
                  << "    auto phiOut = pack_phi_to_bytes();\n"
                  << "    auto phoOut = pack_pho_to_bytes();\n"
                  << "    auto gtvOut = pack_gtv_to_bytes();\n"
                  << "    std::memcpy(fv_info.phiData, phiOut.data(), FV_PHI_BYTE_NUM);\n"
                  << "    std::memcpy(fv_info.phoData, phoOut.data(), FV_PHO_BYTE_NUM);\n"
                  << "    std::memcpy(fv_info.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(fv_info.pgtvData, gtvOut.data() + FV_GTV_MAX_BYTE_NUM, FV_PGTV_BYTE_NUM);\n"
                  << "}\n"
                  << "\n"
                  << "// 单个 MA 处理流程\n"
                  << "void Switch::SingleMaProc(const int ma_id, const std::string &packet_id, "
                     "const int port_id,\n"
                  << "    const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out) {\n"
                  << "    (void)packet_id; // 当前流程未使用\n"
                  << "    (void)port_id;   // 当前流程未使用\n"
                  << "\n"
                  << "    // 载入 PH 数据\n"
                  << "    std::memcpy(data_.data(), fv_in.phData, PKT_HEADER_BYTE_LEN);\n"
                  << "    \n"
                  << "    // 解包输入的 PHI / PHO / GTV\n"
                  << "    PhiPackedBuffer phiIn{};\n"
                  << "    std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);\n"
                  << "    unpack_phi_from_bytes(phiIn);\n"
                  << "\n"
                  << "    PhoPackedBuffer phoIn{};\n"
                  << "    std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);\n"
                  << "    unpack_pho_from_bytes(phoIn);\n"
                  << "\n"
                  << "    GtvPackedBuffer gtvIn{};\n"
                  << "    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(gtvIn.data() + FV_GTV_MAX_BYTE_NUM, fv_in.pgtvData, FV_PGTV_BYTE_NUM);\n"
                  << "    unpack_gtv_from_bytes(gtvIn);\n"
                  << "\n"
                  << "    // 按 ma_id 选择执行的控制流程\n"
                  << "    if (ma_id == 0) {\n"
                  << "        iMA0Control();\n"
                  << "    } else if (ma_id == 1) {\n"
                  << "        iMA1Control();\n"
                  << "    } else if (ma_id == 2) {\n"
                  << "        eMA0Control();\n"
                  << "    }\n"
                  << "\n"
                  << "    std::memcpy(fv_out.phData, data_.data(), PKT_HEADER_BYTE_LEN);\n"
                  << "    // 将最新的 PHI / PHO / GTV 打包写回输出 fv\n"
                  << "    auto phiOut = pack_phi_to_bytes();\n"
                  << "    auto phoOut = pack_pho_to_bytes();\n"
                  << "    auto gtvOut = pack_gtv_to_bytes();\n"
                  << "    std::memcpy(fv_out.phiData, phiOut.data(), FV_PHI_BYTE_NUM);\n"
                  << "    std::memcpy(fv_out.phoData, phoOut.data(), FV_PHO_BYTE_NUM);\n"
                  << "    std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(fv_out.pgtvData, gtvOut.data() + FV_GTV_MAX_BYTE_NUM, FV_PGTV_BYTE_NUM);\n"
                  << "}\n"
                  << "\n"
                  << "void Switch::ImaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, "
                     "Ima2IpmFvInfoDef &fv_out) {\n"
                  << "    (void)port_id;\n"
                  << "\n"
                  << "    // 载入 PH 数据\n"
                  << "    std::memcpy(data_.data(), fv_in.phData, PKT_HEADER_BYTE_LEN);\n"
                  << "\n"
                  << "    // 解包 PHI/PHO/GTV\n"
                  << "    PhiPackedBuffer phiIn{};\n"
                  << "    std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);\n"
                  << "    unpack_phi_from_bytes(phiIn);\n"
                  << "\n"
                  << "    PhoPackedBuffer phoIn{};\n"
                  << "    std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);\n"
                  << "    unpack_pho_from_bytes(phoIn);\n"
                  << "\n"
                  << "    GtvPackedBuffer gtvIn{};\n"
                  << "    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(gtvIn.data() + FV_GTV_MAX_BYTE_NUM, fv_in.pgtvData, FV_PGTV_BYTE_NUM);\n"
                  << "    unpack_gtv_from_bytes(gtvIn);\n"
                  << "\n"
                  << "    // 执行 IMA 流程\n"
                  << "    iMA0Control();\n"
                  << "    iMA1Control();\n"
                  << "\n"
                  << "    // 打包输出：gtvData + pgtvData\n"
                  << "    auto gtvOut = pack_gtv_to_bytes();\n"
                  << "    std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(fv_out.pgtvData, gtvOut.data() + FV_GTV_MAX_BYTE_NUM, FV_PGTV_BYTE_NUM);\n"
                  << "}\n"
                  << "void Switch::EmaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, "
                     "Ema2EpmFvInfoDef &fv_out) {\n"
                  << "    (void)port_id;\n"
                  << "\n"
                  << "    // 载入 PH 数据\n"
                  << "    std::memcpy(data_.data(), fv_in.phData, PKT_HEADER_BYTE_LEN);\n"
                  << "\n"
                  << "    // 解包 PHI/PHO/GTV\n"
                  << "    PhiPackedBuffer phiIn{};\n"
                  << "    std::memcpy(phiIn.data(), fv_in.phiData, FV_PHI_BYTE_NUM);\n"
                  << "    unpack_phi_from_bytes(phiIn);\n"
                  << "\n"
                  << "    PhoPackedBuffer phoIn{};\n"
                  << "    std::memcpy(phoIn.data(), fv_in.phoData, FV_PHO_BYTE_NUM);\n"
                  << "    unpack_pho_from_bytes(phoIn);\n"
                  << "\n"
                  << "    GtvPackedBuffer gtvIn{};\n"
                  << "    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(gtvIn.data() + FV_GTV_MAX_BYTE_NUM, fv_in.pgtvData, FV_PGTV_BYTE_NUM);\n"
                  << "    unpack_gtv_from_bytes(gtvIn);\n"
                  << "\n"
                  << "    // 执行 EMA 流程\n"
                  << "    eMA0Control();\n"
                  << "\n"
                  << "    // 打包输出：gtvData + pgtvData\n"
                  << "    auto gtvOut = pack_gtv_to_bytes();\n"
                  << "    std::memcpy(fv_out.gtvData, gtvOut.data(), FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(fv_out.pgtvData, gtvOut.data() + FV_GTV_MAX_BYTE_NUM, FV_PGTV_BYTE_NUM);\n"
                  << "}\n"
                  << "\n"
                  << "void Switch::IpmProcPkt(const int port_id, const Ima2IpmFvInfoDef &fv_in, Np2NpHeader &np2np_hdr, Np2TmHeader &np2tm_hdr) {\n"
                  << "    (void)port_id;\n"
                  << "\n"
                  << "    // 解包输入的 GTV（包含 FV 字段）\n"
                  << "    GtvPackedBuffer gtvIn{};\n"
                  << "    std::memcpy(gtvIn.data(), fv_in.gtvData, FV_GTV_MAX_BYTE_NUM);\n"
                  << "    std::memcpy(gtvIn.data() + FV_GTV_MAX_BYTE_NUM, fv_in.pgtvData, FV_PGTV_BYTE_NUM);\n"
                  << "    unpack_gtv_from_bytes(gtvIn);\n"
                  << "\n"
                  << "    // IPM 阶段生成新的 NGSF：清空 buffer + offset，避免在旧数据上追加\n"
                  << "    for (auto &b : NGSFBuffer) b = 0;\n"
                  << "    reset_ngsf_offset();\n"
                  << "    // keep direction tracker consistent with current direction\n"
                  << "    last_ngsf_direction = ngsf_direction;\n"
                  << "\n"
                  << "    // 执行 IPM 流程（生成/更新 NGSFBuffer，并维护 tm/ngsf offset）\n"
                  << "    IpmControl();\n"
                  << "\n"
                  << "    using NgsfWord = std::decay_t<decltype(NGSFBuffer[0])>;\n"
                  << "    using NgsfArr = std::remove_reference_t<decltype(NGSFBuffer)>;\n"
                  << "    constexpr std::size_t WORD_BITS = p5::bit_width_v<NgsfWord>;\n"
                  << "    constexpr std::size_t WORDS = std::extent_v<NgsfArr>;\n"
                  << "    constexpr std::size_t CAP_BITS = WORDS * WORD_BITS;\n"
                  << "\n"
                  << "    const std::size_t tm_bits_raw = tm_byte_offset * WORD_BITS + tm_bit_offset;\n"
                  << "    const std::size_t total_bits_raw = ngsf_byte_offset * WORD_BITS + ngsf_bit_offset;\n"
                  << "    const std::size_t total_bits = (total_bits_raw <= CAP_BITS) ? total_bits_raw : CAP_BITS;\n"
                  << "    const std::size_t tm_bits = (tm_bits_raw <= total_bits) ? tm_bits_raw : total_bits;\n"
                  << "\n"
                  << "    auto pack_ngsf_bits = [&](std::size_t start_bit, std::size_t bit_len, uint8_t *dst, std::size_t dst_bytes) {\n"
                  << "        std::memset(dst, 0, dst_bytes);\n"
                  << "        const std::size_t max_bits = dst_bytes * 8;\n"
                  << "        if (bit_len > max_bits) bit_len = max_bits;\n"
                  << "\n"
                  << "        for (std::size_t i = 0; i < bit_len; ++i) {\n"
                  << "            const std::size_t sb = start_bit + i;\n"
                  << "            if (sb >= CAP_BITS) break;\n"
                  << "\n"
                  << "            const std::size_t w = sb / WORD_BITS;\n"
                  << "            const std::size_t b = sb % WORD_BITS;\n"
                  << "            const bool bit = static_cast<bool>(NGSFBuffer[w][static_cast<std::size_t>(WORD_BITS - 1 - b)]);\n"
                  << "            if (bit) {\n"
                  << "                const std::size_t db = i / 8;\n"
                  << "                const std::size_t di = 7 - (i % 8);\n"
                  << "                dst[db] |= static_cast<uint8_t>(1u << di);\n"
                  << "            }\n"
                  << "        }\n"
                  << "    };\n"
                  << "\n"
                  << "    // TM 部分：从头到 tm_byte_offset/tm_bit_offset（不含该位置之后）\n"
                  << "    pack_ngsf_bits(0, tm_bits, np2tm_hdr.pkt_data, PKT_HEADER_BYTE_LEN);\n"
                  << "    // NP 部分：从 tm 分界到 ngsf_byte_offset/ngsf_bit_offset\n"
                  << "    pack_ngsf_bits(tm_bits, total_bits - tm_bits, np2np_hdr.pkt_data, PKT_HEADER_BYTE_LEN);\n"
                  << "}\n"
                  << "\n";
}

void P5ToC::emitSwitch(const IR::P4Program *program) {
    // 1. Emit Header
    outputStream = getStream("include/generated_switch.hpp");
    *outputStream << "#ifndef GENERATED_SWITCH_HPP\n"
                  << "#define GENERATED_SWITCH_HPP\n"
                  << "\n"
                  << "#include <initializer_list>\n"
                  << "#include <string>\n"
                  << "#include <vector>\n"
                  << "\n"
                  << "#include \"table.hpp\"\n"
                  << "#include \"SE.hpp\"\n"
                  << "#include \"key.hpp\"\n"
                  << "#include \"BuiltIn.hpp\"\n"
                  << "#include \"p5_types.hpp\"\n"
                  << "#include \"p5_mswitch.hpp\"\n"
                  << "#include \"model_intf_1027.h\"\n"
                  << "#include \"generated_gtv.hpp\"\n"
                  << "#include \"packet.hpp\"\n"
                  << "\n";

    *outputStream << "class Switch : public GtvContext, public BuiltInContext, public Packet {\n"
                  << "public:\n"
                  << "    Switch();\n"
                  << "\n";

    {
        IndentGuard ig(this);

        for (const auto *obj : program->objects) {
            if (auto *func = obj->to<IR::Function>()) {
                emitFunctionDeclaration(func);
            }
        }
        *outputStream << "\n";

        for (const auto *obj : program->objects) {
            if (auto *tbl = obj->to<IR::P5Table>()) {
                emitTable(tbl);
            }
        }

        *outputStream
            << "public:\n"
            << indent
            << "void PrsProcPkt(bool direction, const ParserHwInfo &parser_hinfo, NhiDef "
               "&nhi_info, "
               "Cp2NpHeader &cp2np_hdr, const PktHeader &pkt_hdr, Prs2Ma0FvInfoDef &fv_info);\n"
            << indent
            << "void ImaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ima2IpmFvInfoDef "
               "&fv_out);\n"
            << indent
            << "void EmaProcPkt(const int port_id, const Prs2Ma0FvInfoDef &fv_in, Ema2EpmFvInfoDef "
               "&fv_out);\n"
            << indent
            << "void IpmProcPkt(const int port_id, const Ima2IpmFvInfoDef &fv_in, Np2NpHeader "
               "&np2np_hdr, Np2TmHeader &np2tm_hdr);\n"
            << indent
            << "void SingleMaProc(const int ma_id, const std::string &packet_id, const int "
               "port_id, "
               "const MaToMaFvInfoDef &fv_in, MaToMaFvInfoDef &fv_out);\n"
            << "\n"
            << indent << "void reset_all_fields();\n"
            << "\n"
            << indent << "SearchEngine &searchEngine() { return BuiltInContext::searchEngine(); }\n"
            << indent << "KeyManager &keyManager() { return BuiltInContext::keyManager(); }\n"
            << "\n";
    }
    *outputStream << "};\n";

    *outputStream << "\n#endif // GENERATED_SWITCH_HPP\n";

    // 2. Emit Source
    outputStream = getStream("src/generated_switch.cpp");
    *outputStream << "#include <cstring>\n"
                  << "\n"
                  << "#include \"generated_switch.hpp\"\n"
                  << "\n"
                  << "Switch::Switch() : GtvContext(), BuiltInContext(), Packet() {}\n"
                  << "\n";

    for (const auto *obj : program->objects) {
        if (auto *func = obj->to<IR::Function>()) {
            emitFunction(func, "Switch::");
        }
    }

    emitSwitchRuntimeImpl();

    emitResetAllFields(program);

    outputStream = defaultStream;
}

void P5ToC::emitStructsAndUnions(const IR::P4Program *program) {
    for (const auto *obj : program->objects) {
        if (auto *st = obj->to<IR::Type_Struct>()) {
            emitStructOrUnion(st);
        }
    }
}

void P5ToC::emitHeaders(const IR::P4Program *program) {
    for (const auto *obj : program->objects) {
        if (auto *inst = obj->to<IR::Declaration_Instance>()) {
            emitHeaderDecl(inst);
        }
    }
}

// void P5ToC::emitStructFieldTraverse(
//     const IR::Type_Struct *st, const std::string &prefix,
//     const std::unordered_map<cstring, const IR::Type_Struct *> &structMap, int &anon_counter,
//     bool emit, bool is_pack) {
//     for (const auto *field : st->fields) {
//         std::string fieldName = field->name.toString().c_str();
//         bool isAnonField = (fieldName == " " || fieldName.empty());

//         if (auto *nestedSt = field->type->to<IR::Type_Struct>()) {
//             if (isAnonymous(nestedSt)) {
//                 if (isUnion(nestedSt)) {
//                     if (isAnonField) fieldName = "_noname_u_" + std::to_string(anon_counter++);
//                     std::string fullName = prefix + "." + fieldName;

//                     if (emit) {
//                         if (is_pack) {
//                             *outputStream << indent << "append_bits(bits, " << fullName << ");\n";
//                         } else {
//                             *outputStream << indent << "assign_from_bits(in, cursor, " << fullName
//                                           << ");\n";
//                         }
//                     }

//                     // Recurse to update counter, but don't emit members
//                     emitStructFieldTraverse(nestedSt, fullName, structMap, anon_counter, false,
//                                             is_pack);

//                 } else {
//                     if (isAnonField) fieldName = "_noname_st_" + std::to_string(anon_counter++);
//                     std::string fullName = prefix + "." + fieldName;
//                     emitStructFieldTraverse(nestedSt, fullName, structMap, anon_counter, emit,
//                                             is_pack);
//                 }
//                 continue;
//             }
//         }

//         if (!emit) continue;

//         std::string fullName = prefix + "." + fieldName;

//         if (auto *tn = field->type->to<IR::Type_Name>()) {
//             cstring typeName = tn->path->name;
//             if (structMap.count(typeName)) {
//                 const auto *typeSt = structMap.at(typeName);
//                 if (isUnion(typeSt)) {
//                     if (is_pack) {
//                         *outputStream << indent << "append_bits(bits, " << fullName << ");\n";
//                     } else {
//                         *outputStream << indent << "assign_from_bits(in, cursor, " << fullName
//                                       << ");\n";
//                     }
//                 } else {
//                     int subCounter = 0;
//                     emitStructFieldTraverse(typeSt, fullName, structMap, subCounter, true, is_pack);
//                 }
//                 continue;
//             }
//         }

//         if (is_pack) {
//             *outputStream << indent << "append_bits(bits, " << fullName << ");\n";
//         } else {
//             *outputStream << indent << "assign_from_bits(in, cursor, " << fullName << ");\n";
//         }
//     }
// }

void P5ToC::emitPhiPackUnpack(const IR::P4Program *program) {
    // const IR::Declaration_Instance *phiInst = nullptr;
    // NOTE: Since append_bits/assign_from_bits now support aggregates/arrays directly, we no longer
    // need to resolve the concrete struct type of PHI here. We only need to know whether PHI exists
    // in the program so we can emit the helper functions.
    //
    // Previous behavior (kept for reference):
    // const IR::Type_Struct *phiStruct = nullptr;
    //
    // std::unordered_map<cstring, const IR::Type_Struct *> structMap;
    // for (const auto *obj : program->objects) {
    //     if (auto *st = obj->to<IR::Type_Struct>()) {
    //         structMap[st->name] = st;
    //     }
    // }
    //
    // for (const auto *obj : program->objects) {
    //     if (auto *var = obj->to<IR::Declaration_Variable>()) {
    //         if (var->name == "PHI") {
    //             if (auto *tn = var->type->to<IR::Type_Name>()) {
    //                 if (structMap.count(tn->path->name)) {
    //                     phiStruct = structMap.at(tn->path->name);
    //                 }
    //             } else if (auto *st = var->type->to<IR::Type_Struct>()) {
    //                 phiStruct = st;
    //             }
    //             if (phiStruct) break;
    //         }
    //     } else if (auto *inst = obj->to<IR::Declaration_Instance>()) {
    //         if (inst->name == "PHI") {
    //             // phiInst = inst;
    //             if (auto *tn = inst->type->to<IR::Type_Name>()) {
    //                 if (structMap.count(tn->path->name)) {
    //                     phiStruct = structMap.at(tn->path->name);
    //                 }
    //             } else if (auto *st = inst->type->to<IR::Type_Struct>()) {
    //                 phiStruct = st;
    //             }
    //             break;
    //         }
    //     }
    // }
    //
    // if (!phiStruct) return;

    bool hasPHI = false;
    for (const auto *obj : program->objects) {
        if (auto *var = obj->to<IR::Declaration_Variable>()) {
            if (var->name == "PHI") {
                hasPHI = true;
                break;
            }
        } else if (auto *inst = obj->to<IR::Declaration_Instance>()) {
            if (inst->name == "PHI") {
                hasPHI = true;
                break;
            }
        }
    }
    if (!hasPHI) return;

    // pack_phi_to_bytes
    *outputStream << indent << "// 将 PHI 字段按声明顺序拼成 FV_PHI_BYTE_NUM*8 字节数组\n";
    *outputStream << indent << "PhiPackedBuffer pack_phi_to_bytes() const {\n";
    {
        IndentGuard ig(this);
        *outputStream << indent << "std::vector<bool> bits;\n";
        *outputStream << indent << "bits.reserve(FV_PHI_BYTE_NUM*8);\n\n";

        // int anon_counter = 0;
        // NOTE: Since append_bits/assign_from_bits now support aggregates/arrays directly,
        // we can serialize/deserialize PHI as a whole without emitting per-field statements.
        //
        // Previous behavior (kept for reference):
        // emitStructFieldTraverse(phiStruct, "PHI", structMap, anon_counter, true, true);
        *outputStream << indent << "append_bits(bits, PHI);\n";

        *outputStream << "\n";
        *outputStream << indent << "PhiPackedBuffer out{};\n";
        *outputStream << indent << "write_bits_to_buffer(bits, out);\n";
        *outputStream << indent << "return out;\n";
    }
    *outputStream << indent << "}\n\n";

    // unpack_phi_from_bytes
    *outputStream << indent << "// 从 FV_PHI_BYTE_NUM*8 字节数组按同样顺序解析回 PHI 字段\n";
    *outputStream << indent << "void unpack_phi_from_bytes(const PhiPackedBuffer &in) {\n";
    {
        IndentGuard ig(this);
        *outputStream << indent << "std::size_t cursor = 0;\n\n";
        // int anon_counter = 0;
        // Previous behavior (kept for reference):
        // emitStructFieldTraverse(phiStruct, "PHI", structMap, anon_counter, true, false);
        *outputStream << indent << "assign_from_bits(in, cursor, PHI);\n";
    }
    *outputStream << indent << "}\n\n";
}

void P5ToC::emitPhoPackUnpack(const IR::P4Program *program) {
    const IR::Declaration_Variable *phoVar = nullptr;
    const IR::Declaration_Instance *phoInst = nullptr;

    for (const auto *obj : program->objects) {
        if (auto *var = obj->to<IR::Declaration_Variable>()) {
            if (var->name == "PHO") {
                phoVar = var;
                break;
            }
        } else if (auto *inst = obj->to<IR::Declaration_Instance>()) {
            if (inst->name == "PHO") {
                phoInst = inst;
                break;
            }
        }
    }

    if (!phoVar && !phoInst) return;

    // pack_pho_to_bytes
    *outputStream << indent << "// 将 PHO 按顺序拼成 FV_PHO_BYTE_NUM*8 字节数组\n";
    *outputStream << indent << "PhoPackedBuffer pack_pho_to_bytes() const {\n";
    {
        IndentGuard ig(this);
        *outputStream << indent << "std::vector<bool> bits;\n";
        *outputStream << indent << "bits.reserve(FV_PHO_BYTE_NUM*8);\n\n";

        // NOTE: Since append_bits/assign_from_bits now support arrays directly,
        // we can serialize/deserialize PHO as a whole.
        //
        // Previous behavior (kept for reference):
        // *outputStream << indent << "for (const auto &v : PHO) {\\n";
        // *outputStream << indent << "    append_bits(bits, v);\\n";
        // *outputStream << indent << "}\\n\\n";
        *outputStream << indent << "append_bits(bits, PHO);\n\n";

        *outputStream << indent << "PhoPackedBuffer out{};\n";
        *outputStream << indent << "write_bits_to_buffer(bits, out);\n";
        *outputStream << indent << "return out;\n";
    }
    *outputStream << indent << "}\n\n";

    // unpack_pho_from_bytes
    *outputStream << indent << "// 从 FV_PHO_BYTE_NUM*8 字节数组解析回 PHO\n";
    *outputStream << indent << "void unpack_pho_from_bytes(const PhoPackedBuffer &in) {\n";
    {
        IndentGuard ig(this);
        *outputStream << indent << "std::size_t cursor = 0;\n";
        // Previous behavior (kept for reference):
        // *outputStream << indent << "for (auto &v : PHO) {\\n";
        // *outputStream << indent << "    assign_from_bits(in, cursor, v);\\n";
        // *outputStream << indent << "}\\n";
        *outputStream << indent << "assign_from_bits(in, cursor, PHO);\n";
    }
    *outputStream << indent << "}\n\n";
}

void P5ToC::emitGtvFieldLoop(const IR::P4Program *program, bool is_pack) {
    // NOTE: Since append_bits/assign_from_bits now support aggregates/arrays directly, we don't
    // need to collect struct types and expand instance members one-by-one here.
    //
    // Previous behavior (kept for reference):
    // std::unordered_map<cstring, const IR::Type_Struct *> structMap;
    // for (const auto *obj : program->objects) {
    //     if (auto *st = obj->to<IR::Type_Struct>()) {
    //         structMap[st->name] = st;
    //     }
    // }

    *outputStream << indent << "// outer headers\n";
    for (const auto *obj : program->objects) {
        if (auto *inst = obj->to<IR::Declaration_Instance>()) {
            // Previous behavior (kept for reference):
            // cstring typeName;
            // if (auto *tn = inst->type->to<IR::Type_Name>()) {
            //     typeName = tn->path->name;
            // } else if (auto *ts = inst->type->to<IR::Type_Struct>()) {
            //     typeName = ts->name;
            // }
            //
            // if (!typeName.isNullOrEmpty() && structMap.count(typeName)) {
            //     int anon_counter = 0;
            //     emitStructFieldTraverse(structMap[typeName], inst->name.toString().c_str(),
            //                             structMap, anon_counter, true, is_pack);
            // } else {
            //     if (is_pack) {
            //         *outputStream << indent << "append_bits(bits, " << inst->name << ");\n";
            //     } else {
            //         *outputStream << indent << "assign_from_bits(in, cursor, " << inst->name
            //                       << ");\n";
            //     }
            // }

            // New behavior: serialize/deserialize the instance as a whole.
            if (is_pack) {
                *outputStream << indent << "append_bits(bits, " << inst->name << ");\n";
            } else {
                *outputStream << indent << "assign_from_bits(in, cursor, " << inst->name << ");\n";
            }
        }
    }
    *outputStream << "\n";

    *outputStream << indent << "// fv fields\n";
    std::set<std::string> print_enable = {"PHI", "PHO"/*, "NGSFBuffer"*/};
    for (const auto *obj : program->objects) {
        if (auto *var = obj->to<IR::Declaration_Variable>()) {
            if (print_enable.find(std::string(var->name.toString())) != print_enable.end()) {
                continue;
            }
            if (is_pack) {
                *outputStream << indent << "append_bits(bits, " << var->name << ");\n";
            } else {
                *outputStream << indent << "assign_from_bits(in, cursor, " << var->name << ");\n";
            }
        }
    }
}

void P5ToC::emitPackGtvToBytes(const IR::P4Program *program) {
    *outputStream << indent << "// 按字段声明顺序将位拼接到字节数组（大端 bit 顺序）\n";
    *outputStream << indent << "GtvPackedBuffer pack_gtv_to_bytes() const {\n";

    {
        IndentGuard ig(this);
        *outputStream << indent << "std::vector<bool> bits;\n";
        *outputStream << indent << "bits.reserve(FV_GTV_MAX_BYTE_NUM*8 + FV_PGTV_BYTE_NUM*8); // 外层头部 + fv\n\n";

        emitGtvFieldLoop(program, true);

        *outputStream << "\n";
        *outputStream << indent << "GtvPackedBuffer out{};\n";
        *outputStream << indent << "write_bits_to_buffer(bits, out);\n";
        *outputStream << indent << "return out;\n";
    }
    *outputStream << indent << "}\n\n";
}

void P5ToC::emitUnpackGtvFromBytes(const IR::P4Program *program) {
    *outputStream << indent << "// 从字节数组按同样顺序解析出各个字段\n";
    *outputStream << indent << "void unpack_gtv_from_bytes(const GtvPackedBuffer &in) {\n";

    {
        IndentGuard ig(this);
        *outputStream << indent << "std::size_t cursor = 0;\n\n";

        emitGtvFieldLoop(program, false);
    }
    *outputStream << indent << "}\n\n";
}

void P5ToC::emitResetAllFields(const IR::P4Program *program) {
    *outputStream << indent << "// ========== 重置所有字段 ==========\n";
    *outputStream << indent << "void Switch::reset_all_fields() {\n";

    {
        IndentGuard ig(this);
        *outputStream << indent << "// 清零 data_/offset_\n";
        *outputStream << indent << "std::memset(data_.data(), 0, data_.size());\n";
        *outputStream << indent << "reset_offset();\n\n";

        *outputStream << indent << "// 清零 PHI\n";
        *outputStream << indent << "PHI = PHI_S{};\n";
        *outputStream << indent << "// 清零 PHO\n";
        *outputStream << indent << "for (auto &v : PHO) v = 0;\n";

        *outputStream << indent << "// 清零 headers\n";
        for (const auto *obj : program->objects) {
            if (auto *inst = obj->to<IR::Declaration_Instance>()) {
                if (inst->name != "PHI" && inst->name != "PHO") {
                    cstring typeName;
                    if (auto *tn = inst->type->to<IR::Type_Name>()) {
                        typeName = tn->path->name;
                    } else if (auto *ts = inst->type->to<IR::Type_Struct>()) {
                        typeName = ts->name;
                    }
                    if (!typeName.isNullOrEmpty()) {
                        *outputStream << indent << inst->name << " = " << typeName << "{};\n";
                    }
                }
            }
        }
        *outputStream << "\n";

        *outputStream << indent << "// 清零 fv字段\n";
        for (const auto *obj : program->objects) {
            if (auto *var = obj->to<IR::Declaration_Variable>()) {
                // Check if it's an array (like NGSFBuffer)
                if (var->type->is<IR::Type_Stack>() ||
                    (var->type->is<IR::Type_Name>() &&
                     var->type->to<IR::Type_Name>()->path->name == "PHO")) {
                    // Skip PHO here as it's already handled, but handle other arrays if any
                    if (var->name != "PHO") {
                        *outputStream << indent << "// " << var->name << "\n";
                        *outputStream << indent << "for (auto &b : " << var->name << ") b = 0;\n";
                    }
                } else if (var->name != "PHI" && var->name != "PHO") {
                    *outputStream << indent << var->name << " = 0;\n";
                }
            }
        }
    }
    *outputStream << indent << "}\n\n";
}

int P5ToC::evaluateExprToInt(const IR::Expression* expr) {
    if (auto c = expr->to<IR::Constant>()) {
        return c->asInt();
    }
    ::P4::error("Cannot evaluate expression to integer: %s", expr);
    return 0;
}

// int P5ToC::getTypeSize(const IR::Type* type) {
//     if (auto tb = type->to<IR::Type_Bits>()) {
//         if (tb->expression) {
//             return evaluateExprToInt(tb->expression);
//         }
//         return tb->width_bits();
//     }
//     if (auto tn = type->to<IR::Type_Name>()) {
//         if (structMap.count(tn->path->name)) {
//             return getTypeSize(structMap.at(tn->path->name));
//         }
//         return 0;
//     }
//     if (auto ts = type->to<IR::Type_Struct>()) {
//         int size = 0;
//         for (auto field : ts->fields) {
//             size += getTypeSize(field->type);
//         }
//         return size;
//     }
//     if (auto stack = type->to<IR::Type_Stack>()) {
//          int elemSize = getTypeSize(stack->elementType);
//          if (auto c = stack->size->to<IR::Constant>()) {
//              return elemSize * c->asInt();
//          }
//          return elemSize * evaluateExprToInt(stack->size);
//     }
//     return 0;
// }

const IR::P4Program *runP5ToC(const IR::P4Program *program, const std::string &out_dir) {
    CHECK_NULL(program);

    P5ToC p5_to_c(&std::cout, out_dir);
    p5_to_c.emitP5Program(program);

    return program;
}

}  // namespace P4::P5
