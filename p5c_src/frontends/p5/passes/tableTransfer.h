/* TableTransfer pass for P5.
 *
 * The first sub-pass (TableStructGen) finds all IR::P5Table declarations
 * and, for each table, generates a struct type whose name matches the
 * table name and whose fields correspond to the variables declared in
 * the table body.
 */

#ifndef FRONTENDS_P5_PASSES_TABLETRANSFER_H_
#define FRONTENDS_P5_PASSES_TABLETRANSFER_H_

#include "ir/ir.h"
#include "ir/pass_manager.h"

namespace P4::P5 {

/// Single transform that:
///  - for each P5Table, generates a struct type with the same name containing
///    all local variables declared in the table body;
///  - generates a function `<TableName>_f` returning that struct and with the
///    same parameters as the table;
///  - removes the original P5Table from the program;
///  - then, in all functions, rewrites declarations of those structs initialized
///    by function calls to use `<StructName>_f(...)` instead and expands
///    `_apply(var)` calls into the corresponding declarations.
class TableTransform : public Transform {
 public:
    TableTransform() { setName("TableTransform"); }

    const IR::Node *postorder(IR::P4Program *program) override;
};

/// High-level pass manager for all table-related transforms.
class TableTransfer : public PassManager {
 public:
    TableTransfer() {
        passes.push_back(new TableTransform());
        setName("TableTransfer");
    }
};

/// Convenience entry point: run the TableTransfer pipeline on a P4Program.
const IR::P4Program *runTableTransfer(const IR::P4Program *program);

}  // namespace P4::P5

#endif  // FRONTENDS_P5_PASSES_TABLETRANSFER_H_


