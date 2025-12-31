// control_info tests: std::any-backed arbitrary-type storage + retrieval proxy
#include <iostream>
#include <string>

#include "../include/BuiltIn.hpp"

namespace {

bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}

template <typename T>
bool expect_eq(const T &got, const T &expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

struct CI {
    int a;
    p5::uint<8> b;
};

} // namespace

int main() {
    std::cout << "[control_info test] start\n";

    BuiltInContext ctx;

    bool ok = true;

    // 1) Store/Load a primitive type
    ctx.control_info = uint32_t{0x12345678};
    ok &= expect_true(ctx.control_info.has_value(), "control_info has value after assignment");
    {
        uint32_t v = ctx._control_info();
        ok &= expect_eq<uint32_t>(v, 0x12345678u, "primitive round-trip");
    }

    // 2) Store/Load an aggregate via brace-init (Type{...})
    ctx.control_info = CI{42, 7};
    {
        CI v = ctx._control_info(); // implicit conversion operator
        ok &= expect_eq<int>(v.a, 42, "aggregate field a (brace-init)");
        ok &= expect_eq<uint64_t>(v.b.to_ullong(), 7, "aggregate field b (brace-init)");
    }

    // 3) Store/Load via GCC compound literal extension: (Type){...}
    // This is used by some generated P5->C++ outputs.
    ctx.control_info = (CI){100, 200};
    {
        CI v = ctx._control_info();
        ok &= expect_eq<int>(v.a, 100, "aggregate field a (compound literal)");
        ok &= expect_eq<uint64_t>(v.b.to_ullong(), 200, "aggregate field b (compound literal)");
    }

    // 4) Negative: wrong type should throw std::bad_any_cast
    bool threw = false;
    try {
        (void)static_cast<uint16_t>(ctx._control_info());
    } catch (const std::bad_any_cast &) {
        threw = true;
    }
    ok &= expect_true(threw, "type mismatch throws std::bad_any_cast");

    std::cout << "[control_info test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}


