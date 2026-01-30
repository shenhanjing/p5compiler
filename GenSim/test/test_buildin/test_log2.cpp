// _log2 tests: test global and member function versions for p5::uint types
#include <iostream>

#include "../../include/BuiltIn.hpp"

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

} // namespace

int main() {
    std::cout << "[_log2 test] start\n";

    BuiltInContext ctx;
    bool ok = true;
    using U = std::uint32_t;

    // Test 1: Global _log2 with different values
    {
        std::cout << "Testing global _log2 function...\n";

        // Test power of 2 values
        ok &= expect_eq<U>(_log2(1), U{0}, "log2(1) = 0");     // 2^0 = 1
        ok &= expect_eq<U>(_log2(2), U{1}, "log2(2) = 1");     // 2^1 = 2
        ok &= expect_eq<U>(_log2(4), U{2}, "log2(4) = 2");     // 2^2 = 4
        ok &= expect_eq<U>(_log2(8), U{3}, "log2(8) = 3");     // 2^3 = 8
        ok &= expect_eq<U>(_log2(16), U{4}, "log2(16) = 4");   // 2^4 = 16
        ok &= expect_eq<U>(_log2(32), U{5}, "log2(32) = 5");   // 2^5 = 32
        ok &= expect_eq<U>(_log2(64), U{6}, "log2(64) = 6");   // 2^6 = 64
        ok &= expect_eq<U>(_log2(128), U{7}, "log2(128) = 7"); // 2^7 = 128

        // Test non-power of 2 values (floor behavior)
        ok &= expect_eq<U>(_log2(3), U{1}, "log2(3) = 1");     // floor(log2(3)) = 1
        ok &= expect_eq<U>(_log2(5), U{2}, "log2(5) = 2");     // floor(log2(5)) = 2
        ok &= expect_eq<U>(_log2(6), U{2}, "log2(6) = 2");     // floor(log2(6)) = 2
        ok &= expect_eq<U>(_log2(7), U{2}, "log2(7) = 2");     // floor(log2(7)) = 2
        ok &= expect_eq<U>(_log2(9), U{3}, "log2(9) = 3");     // floor(log2(9)) = 3

        // Test larger values with different bit widths
        ok &= expect_eq<U>(_log2(256), U{8}, "log2(256) = 8");         // 2^8 = 256
        ok &= expect_eq<U>(_log2(1000), U{9}, "log2(1000) = 9");       // floor(log2(1000)) = 9
        ok &= expect_eq<U>(_log2(65536), U{16}, "log2(65536) = 16");   // 2^16 = 65536

        // Test edge case: 0
        ok &= expect_eq<U>(_log2(0), U{0}, "log2(0) = 0");
    }

    // Test 2: Member function _log2
    {
        std::cout << "Testing member _log2 function...\n";

        ok &= expect_eq<U>(_log2(1), U{0}, "member log2(1) = 0");
        ok &= expect_eq<U>(_log2(2), U{1}, "member log2(2) = 1");
        ok &= expect_eq<U>(_log2(4), U{2}, "member log2(4) = 2");
        ok &= expect_eq<U>(_log2(8), U{3}, "member log2(8) = 3");
        ok &= expect_eq<U>(_log2(3), U{1}, "member log2(3) = 1");
        ok &= expect_eq<U>(_log2(7), U{2}, "member log2(7) = 2");
        ok &= expect_eq<U>(_log2(0), U{0}, "member log2(0) = 0");
    }

    // Test 3: Verify mathematical properties
    {
        std::cout << "Testing mathematical properties...\n";

        // For any n > 0, 2^log2(n) <= n < 2^(log2(n)+1)
        auto test_property = [](uint64_t n) -> bool {
            if (n == 0) return true; // Skip 0
            U log_val = _log2(n);
            uint64_t pow2_log = 1ULL << log_val;
            uint64_t pow2_log_plus_1 = 1ULL << (log_val + 1);
            return pow2_log <= n && n < pow2_log_plus_1;
        };

        ok &= expect_true(test_property(1), "property holds for 1");
        ok &= expect_true(test_property(2), "property holds for 2");
        ok &= expect_true(test_property(3), "property holds for 3");
        ok &= expect_true(test_property(7), "property holds for 7");
        ok &= expect_true(test_property(15), "property holds for 15");
        ok &= expect_true(test_property(16), "property holds for 16");
        ok &= expect_true(test_property(100), "property holds for 100");
        ok &= expect_true(test_property(1000), "property holds for 1000");
    }

    std::cout << "[_log2 test] " << (ok ? "PASSED" : "FAILED") << "\n";
    return ok ? 0 : 1;
}