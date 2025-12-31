// control parameters tests for BuiltInContext:
// - table_id / command: reference bound to SearchEngine fields (two-way sync)
// - ma_id / _header_access / decomp_profile: default 0 + writable
// - _table_id() / _command() / _profile_id() accessors
#include <iostream>

#include "../include/BuiltIn.hpp"
#include "generated_Switch.hpp"

namespace {

bool expect_eq_u64(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

} // namespace

int main() {
    std::cout << "[control parameters test] start\n";

    bool ok = true;

    // ---- BuiltInContext view ----
    {
        BuiltInContext ctx;

        // Defaults
        ok &= expect_eq_u64(ctx.table_id, 0, "BuiltInContext.table_id default 0");
        ok &= expect_eq_u64(ctx.command, 0, "BuiltInContext.command default 0");
        ok &= expect_eq_u64(ctx.ma_id, 0, "BuiltInContext.ma_id default 0");
        ok &= expect_eq_u64(ctx._header_access, 0, "BuiltInContext._header_access default 0");
        ok &= expect_eq_u64(ctx.decomp_profile, 0, "BuiltInContext.decomp_profile default 0");
        ok &= expect_eq_u64(ctx._table_id(), 0, "_table_id() default 0");
        ok &= expect_eq_u64(ctx._command(), 0, "_command() default 0");
        ok &= expect_eq_u64(ctx._profile_id(), 0, "_profile_id() default 0");

        // Write via public members -> reflect into SearchEngine
        ctx.table_id = 0x1234;
        ctx.command = 0x00fe;
        ok &= expect_eq_u64(ctx.searchEngine().table_id, 0x1234, "table_id reflects into SearchEngine (ctx->se)");
        ok &= expect_eq_u64(ctx.searchEngine().command, 0x00fe, "command reflects into SearchEngine (ctx->se)");
        ok &= expect_eq_u64(ctx._table_id(), 0x1234, "_table_id() reflects updated value");
        ok &= expect_eq_u64(ctx._command(), 0x00fe, "_command() reflects updated value");

        // Write via SearchEngine -> reflect back into reference members
        ctx.searchEngine().table_id = 0x2222;
        ctx.searchEngine().command = 0xabcd;
        ok &= expect_eq_u64(ctx.table_id, 0x2222, "table_id reflects back from SearchEngine (se->ctx)");
        ok &= expect_eq_u64(ctx.command, 0xabcd, "command reflects back from SearchEngine (se->ctx)");
        ok &= expect_eq_u64(ctx._table_id(), 0x2222, "_table_id() reflects se-updated value");
        ok &= expect_eq_u64(ctx._command(), 0xabcd, "_command() reflects se-updated value");

        // Other control parameters
        ctx.ma_id = 7;
        ctx._header_access = 3;
        ctx.decomp_profile = 55;
        ok &= expect_eq_u64(ctx.ma_id, 7, "ma_id writable");
        ok &= expect_eq_u64(ctx._header_access, 3, "_header_access writable");
        ok &= expect_eq_u64(ctx.decomp_profile, 55, "decomp_profile writable");
        ok &= expect_eq_u64(ctx._profile_id(), 55, "_profile_id() returns decomp_profile");
    }

    // ---- Switch inheritance view (direct access) ----
    {
        Switch sw;
        sw.table_id = 9;
        sw.command = 10;
        sw.ma_id = 1;
        sw._header_access = 2;
        sw.decomp_profile = 3;

        ok &= expect_eq_u64(sw.searchEngine().table_id, 9, "Switch.table_id updates SearchEngine");
        ok &= expect_eq_u64(sw.searchEngine().command, 10, "Switch.command updates SearchEngine");
        ok &= expect_eq_u64(sw._table_id(), 9, "Switch _table_id()");
        ok &= expect_eq_u64(sw._command(), 10, "Switch _command()");
        ok &= expect_eq_u64(sw._profile_id(), 3, "Switch _profile_id()");
    }

    std::cout << "[control parameters test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}


