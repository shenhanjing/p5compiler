#include <ostream>

#include "ir/ir.h"

namespace P4::IR {

// Standalone p5compiler does not use the DPDK backend, but the pre-generated IR
// includes DPDK-specific IR node types with `toSpec()` declarations. In the
// full p4c build these are implemented by the DPDK backend (e.g. spec.cpp).
// We provide no-op implementations to satisfy vtables and allow linking.

#define P5C_DPDK_TOSPEC_STUB(T) \
    std::ostream &T::toSpec(std::ostream &out) const { return out; }

P5C_DPDK_TOSPEC_STUB(DpdkDeclaration)
P5C_DPDK_TOSPEC_STUB(DpdkExternDeclaration)
P5C_DPDK_TOSPEC_STUB(DpdkHeaderType)
P5C_DPDK_TOSPEC_STUB(DpdkHeaderInstance)
P5C_DPDK_TOSPEC_STUB(DpdkStructType)
P5C_DPDK_TOSPEC_STUB(DpdkAsmStatement)
P5C_DPDK_TOSPEC_STUB(DpdkListStatement)
P5C_DPDK_TOSPEC_STUB(DpdkApplyStatement)
P5C_DPDK_TOSPEC_STUB(DpdkLearnStatement)
P5C_DPDK_TOSPEC_STUB(DpdkMirrorStatement)
P5C_DPDK_TOSPEC_STUB(DpdkEmitStatement)
P5C_DPDK_TOSPEC_STUB(DpdkExtractStatement)
P5C_DPDK_TOSPEC_STUB(DpdkLookaheadStatement)
P5C_DPDK_TOSPEC_STUB(DpdkJmpStatement)
P5C_DPDK_TOSPEC_STUB(DpdkJmpActionStatement)
P5C_DPDK_TOSPEC_STUB(DpdkJmpHeaderStatement)
P5C_DPDK_TOSPEC_STUB(DpdkJmpCondStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRxStatement)
P5C_DPDK_TOSPEC_STUB(DpdkTxStatement)
P5C_DPDK_TOSPEC_STUB(DpdkUnaryStatement)
P5C_DPDK_TOSPEC_STUB(DpdkBinaryStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRecircidStatement)
P5C_DPDK_TOSPEC_STUB(DpdkReturnStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRearmStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRecirculateStatement)
P5C_DPDK_TOSPEC_STUB(DpdkLabelStatement)
P5C_DPDK_TOSPEC_STUB(DpdkChecksumAddStatement)
P5C_DPDK_TOSPEC_STUB(DpdkChecksumSubStatement)
P5C_DPDK_TOSPEC_STUB(DpdkChecksumClearStatement)
P5C_DPDK_TOSPEC_STUB(DpdkHashDeclStatement)
P5C_DPDK_TOSPEC_STUB(DpdkGetHashStatement)
P5C_DPDK_TOSPEC_STUB(DpdkGetChecksumStatement)
P5C_DPDK_TOSPEC_STUB(DpdkCastStatement)
P5C_DPDK_TOSPEC_STUB(DpdkVerifyStatement)
P5C_DPDK_TOSPEC_STUB(DpdkMeterDeclStatement)
P5C_DPDK_TOSPEC_STUB(DpdkMeterExecuteStatement)
P5C_DPDK_TOSPEC_STUB(DpdkGetTableEntryIndex)
P5C_DPDK_TOSPEC_STUB(DpdkCounterCountStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRegisterDeclStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRegisterReadStatement)
P5C_DPDK_TOSPEC_STUB(DpdkRegisterWriteStatement)
P5C_DPDK_TOSPEC_STUB(DpdkValidateStatement)
P5C_DPDK_TOSPEC_STUB(DpdkInvalidateStatement)
P5C_DPDK_TOSPEC_STUB(DpdkDropStatement)

#undef P5C_DPDK_TOSPEC_STUB

}  // namespace P4::IR


