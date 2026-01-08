#include "frontends/p5/parse_annotations.h"

#include "ir/annotations.h"
#include "ir/ir.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/match.h"
#include <vector>
#include <unordered_map>
#include <map>

namespace P4::P5 {


void parseAnnotations(IR::P4Program *program) {
    if (!program) return;

    // Collect all functions
    std::vector<const IR::Function *> functions;
    for (auto obj : program->objects) {
        if (auto *f = obj->to<IR::Function>()) functions.push_back(f);
    }

    // Collect all p5table
    std::map<std::string, const IR::P5Table *> p5tables;
    for (auto obj : program->objects) {
        if (auto *p5table = obj->to<IR::P5Table>()) {
            p5tables[p5table->name.string()] = p5table;
        }
    }

    std::map<cstring, std::pair<cstring, cstring>> helperNames;
    for (auto f : functions) {
        if (!absl::StartsWith(f->name.string(), "pre_iMA")) continue;

        const IR::ID tableId;  // placeholder
        const IR::Declaration_Variable *keptTableDecl = nullptr;
        const IR::MethodCallStatement *keptApplyStmt = nullptr;

        IR::IndexedVector<IR::StatOrDecl> keep;
        IR::IndexedVector<IR::StatOrDecl> move_before;
        IR::IndexedVector<IR::StatOrDecl> move_after;

        // First pass: find a table declaration and its apply(table)
        for (auto &sd : f->body->components) {
            if (!keptTableDecl) {
                if (auto *decl = sd->to<IR::Declaration_Variable>()) {
                    auto p5table_name = decl->type->to<IR::Type_Name>()->path->name;
                    if (p5tables.find(p5table_name.string()) != p5tables.end()) {
                        keptTableDecl = decl;
                        keep.push_back(sd);
                        continue;
                    }
                }
            }
            if (keptTableDecl && !keptApplyStmt) {
                if (auto *mcs = sd->to<IR::MethodCallStatement>()) {
                    if (auto *mem = mcs->methodCall->method->to<IR::PathExpression>()) {
                        auto *pat = mem->path;
                        if (pat->name == "_apply") {
                            auto* arg = mcs->methodCall->arguments;
                            if (arg->size() == 1) {
                                auto *arg_0 = (*arg)[0];
                                if (auto *exp = arg_0->expression->to<IR::PathExpression>()){
                                    if (exp->path->name == keptTableDecl->name){
                                        keptApplyStmt = mcs;
                                        keep.push_back(sd);
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!keptApplyStmt) {
                move_before.push_back(sd);
            } else {
                move_after.push_back(sd);
            }
        }

        if (!keep.empty()) {
            auto newBody = new IR::BlockStatement(f->body->srcInfo, f->body->annotations);
            newBody->components = keep;
            auto newFunc = new IR::Function(f->srcInfo, f->name, f->annotations, f->type, newBody);

            IR::Function *helper_before = nullptr;
            IR::Function *helper_after = nullptr;
            if (!move_before.empty()) {
                auto helperName = IR::ID(absl::StrCat(f->name.string_view(), "_MA0"));
                auto helperType = new IR::Type_Method(IR::Type_Void::get(), new IR::ParameterList(), helperName);
                auto helperBody = new IR::BlockStatement(f->body->srcInfo, f->body->annotations);
                helperBody->components = move_before;
                helper_before = new IR::Function(helperName, helperType, helperBody);
                helperNames[f->name].first = helperName;
            }

            if (!move_after.empty()) {
                auto helperName = IR::ID(absl::StrCat(f->name.string_view(), "_MA1"));
                auto helperType = new IR::Type_Method(IR::Type_Void::get(), new IR::ParameterList(), helperName);
                auto helperBody = new IR::BlockStatement(f->body->srcInfo, f->body->annotations);
                helperBody->components = move_after;
                helper_after = new IR::Function(helperName, helperType, helperBody);
                helperNames[f->name].second = helperName;
            }


            for (size_t i = 0; i < program->objects.size(); ++i) {
                if (program->objects.at(i) == f) {
                    auto it = program->objects.begin() + i;
                    program->objects.erase(it);
                    it = program->objects.begin() + i;
                    program->objects.insert(it, newFunc);
                    if (helper_after) program->objects.insert(program->objects.begin() + i + 1, helper_after);
                    if (helper_before) program->objects.insert(program->objects.begin() + i + 1, helper_before);

                    break;
                }
            }
        }
    }

    std::function<IR::IndexedVector<IR::StatOrDecl>(const IR::IndexedVector<IR::StatOrDecl>&)> expand;
    expand = [&](const IR::IndexedVector<IR::StatOrDecl> &in) {
        IR::IndexedVector<IR::StatOrDecl> out;
        for (auto &sd : in) {
            if (auto *mcs = sd->to<IR::MethodCallStatement>()) {
                if (auto *pe = mcs->methodCall->method->to<IR::PathExpression>()) {
                    auto it = helperNames.find(pe->path->name);
                    if (it != helperNames.end()) {
                        auto pre = it->second.first;
                        auto post = it->second.second;
                        if (pre) {
                            out.push_back(new IR::MethodCallStatement(
                                mcs->srcInfo, new IR::PathExpression(pre), {}));
                        }
                        out.push_back(sd);
                        if (post) {
                            out.push_back(new IR::MethodCallStatement(
                                mcs->srcInfo, new IR::PathExpression(post), {}));
                        }
                        continue;
                    }
                }
            }
            if (auto *blk = sd->to<IR::BlockStatement>()) {
                auto nb = new IR::BlockStatement(blk->srcInfo, blk->annotations);
                nb->components = expand(blk->components);
                out.push_back(nb);
                continue;
            }
            if (auto *ifs = sd->to<IR::IfStatement>()) {
                auto ifTrueBlk = ifs->ifTrue->to<IR::BlockStatement>();
                auto ifFalseBlk = ifs->ifFalse ? ifs->ifFalse->to<IR::BlockStatement>() : nullptr;
                const IR::Statement *newTrue = ifs->ifTrue;
                const IR::Statement *newFalse = ifs->ifFalse;
                if (ifTrueBlk) {
                    auto nb = new IR::BlockStatement(ifTrueBlk->srcInfo, ifTrueBlk->annotations);
                    nb->components = expand(ifTrueBlk->components);
                    newTrue = nb;
                } else if (auto *mcsTrue = ifs->ifTrue->to<IR::MethodCallStatement>()) {
                    if (auto *pe = mcsTrue->methodCall->method->to<IR::PathExpression>()) {
                        auto it = helperNames.find(pe->path->name);
                        if (it != helperNames.end()) {
                            auto pre = it->second.first;
                            auto post = it->second.second;
                            auto nb = new IR::BlockStatement(ifs->ifTrue->srcInfo);
                            if (pre) nb->push_back(new IR::MethodCallStatement(mcsTrue->srcInfo, new IR::PathExpression(pre), {}));
                            nb->push_back(mcsTrue);
                            if (post) nb->push_back(new IR::MethodCallStatement(mcsTrue->srcInfo, new IR::PathExpression(post), {}));
                            newTrue = nb;
                        }
                    }
                }
                if (ifFalseBlk) {
                    auto nb = new IR::BlockStatement(ifFalseBlk->srcInfo, ifFalseBlk->annotations);
                    nb->components = expand(ifFalseBlk->components);
                    newFalse = nb;
                } else if (ifs->ifFalse) {
                    if (auto *mcsFalse = ifs->ifFalse->to<IR::MethodCallStatement>()) {
                        if (auto *pe = mcsFalse->methodCall->method->to<IR::PathExpression>()) {
                            auto it = helperNames.find(pe->path->name);
                            if (it != helperNames.end()) {
                                auto pre = it->second.first;
                                auto post = it->second.second;
                                auto nb = new IR::BlockStatement(ifs->ifFalse->srcInfo);
                                if (pre) nb->push_back(new IR::MethodCallStatement(mcsFalse->srcInfo, new IR::PathExpression(pre), {}));
                                nb->push_back(mcsFalse);
                                if (post) nb->push_back(new IR::MethodCallStatement(mcsFalse->srcInfo, new IR::PathExpression(post), {}));
                                newFalse = nb;
                            }
                        }
                    }
                }
                out.push_back(new IR::IfStatement(
                    ifs->condition,
                    const_cast<IR::Statement *>(newTrue),
                    const_cast<IR::Statement *>(newFalse)));
                continue;
            }
            if (auto *sw = sd->to<IR::SwitchStatement>()) {
                IR::Vector<IR::SwitchCase> casesVec;
                for (auto &c : sw->cases) {
                    const IR::Statement *st = c->statement;
                    if (auto *b = c->statement ? c->statement->to<IR::BlockStatement>() : nullptr) {
                        auto nb = new IR::BlockStatement(b->srcInfo, b->annotations);
                        nb->components = expand(b->components);
                        st = nb;
                    }
                    casesVec.push_back(new IR::SwitchCase(
                        c->srcInfo, c->label, const_cast<IR::Statement *>(st)));
                }
                out.push_back(new IR::SwitchStatement(sw->srcInfo, sw->expression, casesVec));
                continue;
            }
            out.push_back(sd);
        }
        return out;
    };

    std::vector<const IR::Function *> allFuncs;
    for (auto obj : program->objects) if (auto *f = obj->to<IR::Function>()) allFuncs.push_back(f);
    for (auto f : allFuncs) {
        auto newBody = new IR::BlockStatement(f->body->srcInfo, f->body->annotations);
        newBody->components = expand(f->body->components);
        auto newFunc = new IR::Function(f->srcInfo, f->name, f->annotations, f->type, newBody);
        for (size_t i = 0; i < program->objects.size(); ++i) {
            if (program->objects.at(i) == f) {
                auto it = program->objects.begin() + i;
                program->objects.erase(it);
                it = program->objects.begin() + i;
                program->objects.insert(it, newFunc);
                break;
            }
        }
    }

}

void packMetadata(IR::P4Program *program) {
    if (!program) return;

    bool hasMetadataType = false;
    for (auto obj : program->objects) {
        if (auto *td = obj->to<IR::Type_Declaration>()) {
            if (td->name == "metadata_t") {
                hasMetadataType = true;
                break;
            }
        }
    }

    IR::IndexedVector<IR::StructField> fields;
    for (auto obj : program->objects) {
        if (auto *var = obj->to<IR::Declaration_Variable>()) {
            if (var->type->is<IR::Type_Bits>() || var->type->is<IR::Type_Stack>()) {
                fields.push_back(new IR::StructField(var->name, var->type));
            }
        }
    }

    if (!fields.empty() && !hasMetadataType) {
        auto *md = new IR::Type_Struct("metadata_t", fields);
        program->objects.push_back(md);
    }
}

void enumToUint(IR::P4Program *program) {
    if (!program) return;

    class EnumToUintPass : public Transform {
        std::map<cstring, int> widths;
        std::map<cstring, std::map<cstring, const IR::Expression *>> values;
        std::vector<IR::Declaration_Constant *> decls;

        static int width_for_count(size_t n) {
            int w = 0;
            while ((size_t(1) << w) < n) ++w;
            return w == 0 ? 1 : w;
        }

     public:
        const IR::Node *preorder(IR::Type_SerEnum *e) override {
            auto name = e->name;
            auto w = width_for_count(e->members.size());
            widths[name] = w;
            std::map<cstring, const IR::Expression *> vm;
            for (auto m : e->members) vm[m->name] = m->value;
            values[name] = std::move(vm);
            for (auto m : e->members) {
                auto *tb = IR::Type::Bits::get(w, false);
                const IR::Expression *init = nullptr;
                if (auto *c = m->value->to<IR::Constant>())
                    init = new IR::Constant(tb, c->value);
                else
                    init = new IR::Cast(tb, m->value->clone());
                decls.push_back(new IR::Declaration_Constant(m->name, tb, init));
            }
            // if (getParent<IR::P4Program>()) return nullptr;
            // return e;
            return nullptr;
        }

        // const IR::Node *postorder(IR::Type_Name *tn) override {
        //     if (!tn->path) return tn;
        //     auto it = widths.find(tn->path->name);
        //     if (it == widths.end()) return tn;
        //     return IR::Type::Bits::get(it->second, false);
        // }

        const IR::Node *postorder(IR::Member *m) override {
            if (auto *tne = m->expr->to<IR::TypeNameExpression>()) {
                cstring ename;
                if (auto *tn = tne->typeName->to<IR::Type_Name>())
                    ename = tn->path->name;
                else
                    return m;
                auto vit = values.find(ename);
                if (vit == values.end()) return m;
                auto mit = vit->second.find(m->member);
                if (mit == vit->second.end()) return m;
                return new IR::PathExpression(IR::ID(m->member));
            }
            return m;
        }

        const IR::Node *postorder(IR::P4Program *p) override {
            for (auto *d : decls) p->objects.push_back(d);
            return p;
        }
    };

    EnumToUintPass pass;
    const IR::Node *res = program->apply(pass);
    if (auto *np = res->to<IR::P4Program>()) {
        if (np != program) program->objects = np->objects;
    }
}

void normalizeAnonStructUnion(IR::P4Program *program) {
    class ExtractAnonTypes : public Transform {
        std::vector<IR::Type_Declaration *> newTypes;
        int anonStructCount = 0;
        int anonUnionCount = 0;
        int anonStructFieldCount = 0;
        int anonUnionFieldCount = 0;

        IR::Type_Declaration *makeStructType(const IR::Type_StructLike *inner,
                                             cstring suggestedName) {
            auto name = suggestedName;
            if (name == cstring::empty)
                name = cstring("AnonStruct" + std::to_string(anonStructCount++));
            auto fields = new IR::IndexedVector<IR::StructField>();
            for (auto sf : inner->fields) {
                fields->push_back(new IR::StructField(sf->srcInfo, sf->name, sf->type));
            }
            return new IR::Type_Struct(inner->srcInfo, IR::ID(name), inner->annotations,
                                       inner->typeParameters, *fields);
        }

        IR::Type_Declaration *makeUnionType(const IR::Type_HeaderUnion *inner,
                                            cstring suggestedName) {
            auto name = suggestedName;
            if (name == cstring::empty)
                name = cstring("AnonUnion" + std::to_string(anonUnionCount++));
            auto fields = new IR::IndexedVector<IR::StructField>();
            int wrapCount = 0;
            for (auto sf : inner->fields) {
                const IR::Type *ftype = sf->type;
                if (!ftype->is<IR::Type_Header>()) {
                    auto innerFields = new IR::IndexedVector<IR::StructField>();
                    innerFields->push_back(new IR::StructField(sf->srcInfo, "value", ftype));
                    auto hdr = new IR::Type_Header(
                        sf->srcInfo, IR::ID(cstring("AnonHdr" + std::to_string(wrapCount++))),
                        IR::Vector<IR::Annotation>(), *innerFields);
                    ftype = hdr;
                }
                fields->push_back(new IR::StructField(sf->srcInfo, sf->name, ftype));
            }
            return new IR::Type_HeaderUnion(inner->srcInfo, IR::ID(name), inner->annotations,
                                            inner->typeParameters, *fields);
        }

        const IR::Node *postorder(IR::Type_Header *t) override {
            bool hasUnion = false;
            auto fields = new IR::IndexedVector<IR::StructField>();
            for (auto sf : t->fields) {
                auto ty = sf->type;
                if (auto hu = ty->to<IR::Type_HeaderUnion>()) {
                    hasUnion = true;
                    auto newType = makeUnionType(hu, cstring::empty);
                    newTypes.push_back(newType);
                    auto path = new IR::Path(IR::ID(newType->name));
                    auto typeName = new IR::Type_Name(sf->srcInfo, path);
                    cstring fname = sf->name;
                    if (fname == cstring::empty)
                        fname = cstring("anon_union_" + std::to_string(anonUnionFieldCount++));
                    fields->push_back(new IR::StructField(sf->srcInfo, fname, typeName));
                } else if (auto ih = ty->to<IR::Type_Header>()) {
                    // anonymous struct mapped to header in parser; extract into Type_Struct
                    auto newType = makeStructType(ih, cstring::empty);
                    newTypes.push_back(newType);
                    auto path = new IR::Path(IR::ID(newType->name));
                    auto typeName = new IR::Type_Name(sf->srcInfo, path);
                    cstring fname = sf->name;
                    if (fname == cstring::empty)
                        fname = cstring("anon_struct_" + std::to_string(anonStructFieldCount++));
                    fields->push_back(new IR::StructField(sf->srcInfo, fname, typeName));
                } else if (auto is = ty->to<IR::Type_Struct>()) {
                    // inline struct
                    auto newType = makeStructType(is, cstring::empty);
                    newTypes.push_back(newType);
                    auto path = new IR::Path(IR::ID(newType->name));
                    auto typeName = new IR::Type_Name(sf->srcInfo, path);
                    cstring fname = sf->name;
                    if (fname == cstring::empty)
                        fname = cstring("anon_struct_" + std::to_string(anonStructFieldCount++));
                    fields->push_back(new IR::StructField(sf->srcInfo, fname, typeName));
                } else {
                    fields->push_back(sf);
                }
            }
            if (hasUnion) {
                return new IR::Type_Struct(t->srcInfo, t->name, t->annotations, t->typeParameters,
                                           *fields);
            }
            return new IR::Type_Header(t->srcInfo, t->name, t->annotations, t->typeParameters,
                                       *fields);
        }

        const IR::Node *postorder(IR::Type_Struct *t) override {
            auto fields = new IR::IndexedVector<IR::StructField>();
            for (auto sf : t->fields) {
                auto ty = sf->type;
                if (auto ih = ty->to<IR::Type_Header>()) {
                    auto newType = makeStructType(ih, cstring::empty);
                    newTypes.push_back(newType);
                    auto path = new IR::Path(IR::ID(newType->name));
                    auto typeName = new IR::Type_Name(sf->srcInfo, path);
                    cstring fname = sf->name;
                    if (fname == cstring::empty)
                        fname = cstring("anon_struct_" + std::to_string(anonStructFieldCount++));
                    fields->push_back(new IR::StructField(sf->srcInfo, fname, typeName));
                } else if (auto is = ty->to<IR::Type_Struct>()) {
                    auto newType = makeStructType(is, cstring::empty);
                    newTypes.push_back(newType);
                    auto path = new IR::Path(IR::ID(newType->name));
                    auto typeName = new IR::Type_Name(sf->srcInfo, path);
                    cstring fname = sf->name;
                    if (fname == cstring::empty)
                        fname = cstring("anon_struct_" + std::to_string(anonStructFieldCount++));
                    fields->push_back(new IR::StructField(sf->srcInfo, fname, typeName));
                } else if (auto hu = ty->to<IR::Type_HeaderUnion>()) {
                    auto newType = makeUnionType(hu, cstring::empty);
                    newTypes.push_back(newType);
                    auto path = new IR::Path(IR::ID(newType->name));
                    auto typeName = new IR::Type_Name(sf->srcInfo, path);
                    cstring fname = sf->name;
                    if (fname == cstring::empty)
                        fname = cstring("anon_union_" + std::to_string(anonUnionFieldCount++));
                    fields->push_back(new IR::StructField(sf->srcInfo, fname, typeName));
                } else {
                    fields->push_back(sf);
                }
            }
            return new IR::Type_Struct(t->srcInfo, t->name, t->annotations, t->typeParameters,
                                       *fields);
        }

        const IR::Node *postorder(IR::P4Program *p) override {
            IR::Vector<IR::Node> newObjs;
            for (auto *d : newTypes) newObjs.push_back(d);
            for (auto *n : p->objects) newObjs.push_back(n);
            p->objects = newObjs;
            return p;
        }
    };

    ExtractAnonTypes pass;
    const IR::Node *res = program->apply(pass);
    if (auto *np = res->to<IR::P4Program>()) {
        if (np != program) program->objects = np->objects;
    }
}

}  // namespace P4::P5
