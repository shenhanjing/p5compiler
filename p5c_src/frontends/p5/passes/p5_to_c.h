#ifndef FRONTENDS_P5_PASSES_P5_TO_C_H_
#define FRONTENDS_P5_PASSES_P5_TO_C_H_

#include <filesystem>
#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "ir/ir.h"
#include "ir/pass_manager.h"

namespace P4::P5 {

struct IndentGuard;

class P5ToC {
 public:
    explicit P5ToC(std::ostream *out = &std::cout, const std::string &out_dir = ".")
        : outputStream(out), defaultStream(out) {
        CHECK_NULL(outputStream);
        CHECK_NULL(defaultStream);
        outputDir = std::filesystem::path(out_dir);
        if (outputDir.empty()) {
            outputDir = std::filesystem::current_path();
        }
        std::error_code ec;
        std::filesystem::create_directories(outputDir, ec);
        if (ec) {
            ::P4::error("Could not create output directory %s: %s", outputDir.string(),
                        ec.message());
        }
        std::filesystem::create_directories(outputDir / "include", ec);
        if (ec) {
            ::P4::error("Could not create output directory %s: %s",
                        (outputDir / "include").string(), ec.message());
        }
        std::filesystem::create_directories(outputDir / "src", ec);
        if (ec) {
            ::P4::error("Could not create output directory %s: %s", (outputDir / "src").string(),
                        ec.message());
        }
    }
    void emitP5Program(const IR::P4Program *program);

 private:
    std::ostream *outputStream;
    std::ostream *defaultStream;
    std::string indent;
    std::filesystem::path outputDir;
    std::unordered_map<std::string, std::unique_ptr<std::ostream>> streams;
    friend struct IndentGuard;
    bool inSwitchMethod = false;

    struct Uint0InitListParam {
        std::string tname;     // e.g. "T0"
        cstring origName;      // e.g. "list0"
        std::string initName;  // e.g. "_InitList_list0"
    };
    // For the currently emitted function signature/body: uint<0> list[] (non-ref)
    // becomes an initializer_list parameter plus a vector constructed in the prologue.
    std::vector<Uint0InitListParam> curUint0InitListParams;

    std::unordered_set<cstring> switchMembers;

    std::ostream *getStream(const std::string &filename);
    void flushCFile();

    enum class EmitMode { Standard, Memberized };

    bool isUnion(const IR::Type_Struct *st);
    bool isAnonymous(const IR::Type_Struct *st);
    void emitSerEnum(const IR::Type_SerEnum *serEnum);
    void emitStructOrUnion(const IR::Type_Struct *st, bool isNested = false);
    void emitStructOrUnionImpl(const IR::Type_Struct *st, bool isNested, EmitMode mode, int &anon_counter);
    void emitStructMembers(const IR::Type_Struct *st, EmitMode mode, int &anon_counter);
    void emitFieldType(const IR::Type *type, EmitMode mode = EmitMode::Standard);
    void emitNestedStructOrUnion(const IR::Type_Struct *st, EmitMode mode, int &anon_counter);
    void emitVariableDecl(const IR::Declaration_Variable *var, const std::unordered_set<cstring> &locals = {});
    void emitHeaderDecl(const IR::Declaration_Instance *inst);
    void emitTypedef(const IR::Type_Typedef *td);
    void emitTable(const IR::P5Table *tbl);
    void emitIfStat(const IR::IfStatement *ifs, const std::unordered_set<cstring> &locals = {});
    bool emitMethodCall(const IR::MethodCallExpression *mc, const cstring &lhs, std::ostream &os, const std::unordered_set<cstring> &locals = {});
    bool emitMethodCall(const IR::MethodCallExpression *mc, std::ostream &os, const std::unordered_set<cstring> &locals = {});
    void emitGtvHpp(const IR::P4Program *program);
    void emitEnumsHpp(const IR::P4Program *program);
    void emitStructHpp(const IR::P4Program *program);
    void emitSwitch(const IR::P4Program *program);
    void emitStructsAndUnions(const IR::P4Program *program);
    void emitHeaders(const IR::P4Program *program);
    void emitPackGtvToBytes(const IR::P4Program *program);
    void emitUnpackGtvFromBytes(const IR::P4Program *program);
    void emitPhiPackUnpack(const IR::P4Program *program);
    void emitPhoPackUnpack(const IR::P4Program *program);
    void emitResetAllFields(const IR::P4Program *program);
    void emitStructFieldTraverse(const IR::Type_Struct* st, const std::string& prefix, const std::unordered_map<cstring, const IR::Type_Struct*>& structMap, int& anon_counter, bool emit = true, bool is_pack = true);
    void emitGtvFieldLoop(const IR::P4Program *program, bool is_pack);
    void emitFunction(const IR::Function *func, const std::string &class_name = "");
    void emitFunctionSignature(const IR::Function *func, const std::string &class_name = "");
    void emitFunctionDeclaration(const IR::Function *func, const std::string &class_name = "");
    void emitFunctionBody(const IR::BlockStatement *body);
    void emitComponent(const IR::StatOrDecl *comp, const std::unordered_set<cstring> &locals = {});
    void emitExpressionWithCtx(const IR::Expression *expr,
                               const std::unordered_set<cstring> &locals);
    void emitSwitchStatement(const IR::SwitchStatement *swStmt, const std::unordered_set<cstring> &locals = {});
    void emitSwitchTagMatching(const IR::SwitchStatement *swStmt, const std::unordered_set<cstring> &locals = {});
    void emitSwitchDispatch(const IR::SwitchStatement *swStmt, const std::unordered_set<cstring> &locals = {});
    void emitSwitchRuntimeImpl();
    void emitTableConstructor(const IR::P5Table *tbl);
    void emitTableKeyMatching(const IR::P5Key *keyNode, const std::unordered_set<cstring> &locals);
    void emitTableKeySelect(const IR::P5Key *keyNode, const std::unordered_set<cstring> &locals);
    void emitTableKeyElements(const IR::P5Key *keyNode, const std::unordered_set<cstring> &locals);
    bool isInlineInit(const IR::Declaration_Variable *var);
};

/// Convenience entry point: run the P5ToC on a P4Program.
const IR::P4Program *runP5ToC(const IR::P4Program *program, const std::string &out_dir = ".");

}  // namespace P4::P5

#endif  // FRONTENDS_P5_PASSES_P5_TO_C_H_
