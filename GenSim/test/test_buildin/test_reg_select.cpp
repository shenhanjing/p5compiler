// _reg_select tests: test the _reg_select function that unconditionally returns swValue
#include <iostream>
#include <string>

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
    std::cout << "[_reg_select test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Basic functionality - returns swValue
    {
        std::cout << "\n[Test 1] Testing _reg_select basic functionality...\n";
        std::cout << "  Input: hwValue=100, swValue=200\n";

        int hwValue = 100;
        int swValue = 200;
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "basic functionality");
        ok &= expect_true(result != hwValue, "result should not equal hwValue");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") && result != hwValue ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 2: Same values
    {
        std::cout << "\n[Test 2] Testing _reg_select with same values...\n";
        std::cout << "  Input: hwValue=50, swValue=50\n";

        int hwValue = 50;
        int swValue = 50;
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "same values");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 3: Zero values
    {
        std::cout << "\n[Test 3] Testing _reg_select with zero swValue...\n";
        std::cout << "  Input: hwValue=100, swValue=0\n";

        int hwValue = 100;
        int swValue = 0;
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "zero swValue");
        ok &= expect_eq(result, 0, "result should be zero");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") && result == 0 ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 4: Negative values
    {
        std::cout << "\n[Test 4] Testing _reg_select with negative values...\n";
        std::cout << "  Input: hwValue=-100, swValue=-50\n";

        int hwValue = -100;
        int swValue = -50;
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "negative values");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 5: Large values
    {
        std::cout << "\n[Test 5] Testing _reg_select with large values...\n";
        std::cout << "  Input: hwValue=1000000, swValue=999999\n";

        int hwValue = 1000000;
        int swValue = 999999;
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "large values");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 6: hwValue is ignored
    {
        std::cout << "\n[Test 6] Testing _reg_select ignores hwValue...\n";
        std::cout << "  Input: hwValue=999, swValue=1\n";

        int hwValue = 999;
        int swValue = 1;
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "hwValue ignored");
        ok &= expect_true(result != hwValue, "result should not equal hwValue");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") && result != hwValue ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 7: Multiple calls with different values
    {
        std::cout << "\n[Test 7] Testing _reg_select with multiple calls...\n";

        struct TestCase {
            int hwValue;
            int swValue;
            const char* description;
        };

        TestCase testCases[] = {
            {10, 20, "case 1"},
            {30, 40, "case 2"},
            {0, 100, "case 3"},
            {-10, -20, "case 4"},
            {1000, 2000, "case 5"}
        };

        bool allPass = true;
        for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
            int result = ctx._reg_select(testCases[i].hwValue, testCases[i].swValue);
            if (result != testCases[i].swValue) {
                std::cerr << "  [FAIL] " << testCases[i].description 
                          << ": got=" << result << " expect=" << testCases[i].swValue << "\n";
                allPass = false;
            } else {
                std::cout << "  " << testCases[i].description 
                          << ": hwValue=" << testCases[i].hwValue 
                          << ", swValue=" << testCases[i].swValue 
                          << ", result=" << result << " ✓\n";
            }
        }
        ok &= expect_true(allPass, "multiple calls");
        std::cout << "  Result: " << (allPass ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 8: Edge case - maximum int values
    {
        std::cout << "\n[Test 8] Testing _reg_select with edge values...\n";
        std::cout << "  Input: hwValue=2147483647, swValue=-2147483648\n";

        int hwValue = 2147483647;  // INT_MAX
        int swValue = -2147483648; // INT_MIN
        int result = ctx._reg_select(hwValue, swValue);
        
        std::cout << "  Output: " << result << "\n";
        std::cout << "  Expected: " << swValue << "\n";
        ok &= expect_eq(result, swValue, "edge values");
        std::cout << "  Result: " << (expect_eq(result, swValue, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 9: Verify function signature
    {
        std::cout << "\n[Test 9] Testing _reg_select function signature...\n";
        
        int hwValue = 1;
        int swValue = 2;
        int result = ctx._reg_select(hwValue, swValue);
        
        static_assert(std::is_same_v<decltype(ctx._reg_select(0, 0)), int>, 
                     "Return type should be int");
        
        std::cout << "  Function signature: int _reg_select(int hwValue, int swValue)\n";
        std::cout << "  Return type: int ✓\n";
        ok &= expect_true(true, "function signature");
        std::cout << "  Result: ✓ PASS\n";
    }

    // Test 10: Consistency check - same swValue with different hwValue
    {
        std::cout << "\n[Test 10] Testing _reg_select consistency...\n";
        std::cout << "  Testing same swValue with different hwValue values\n";

        int swValue = 42;
        int hwValues[] = {0, 1, 100, -100, 9999};
        bool allSame = true;
        
        int firstResult = ctx._reg_select(hwValues[0], swValue);
        for (size_t i = 1; i < sizeof(hwValues) / sizeof(hwValues[0]); ++i) {
            int result = ctx._reg_select(hwValues[i], swValue);
            if (result != firstResult) {
                std::cerr << "  [FAIL] Inconsistent result: hwValue=" << hwValues[i] 
                          << ", got=" << result << " expect=" << firstResult << "\n";
                allSame = false;
            }
        }
        
        std::cout << "  All results with same swValue: " << firstResult << "\n";
        ok &= expect_true(allSame && firstResult == swValue, "consistency");
        std::cout << "  Result: " << (allSame && firstResult == swValue ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "[_reg_select test] " << (ok ? "ALL PASS ✓" : "FAILED ✗") << "\n";
    std::cout << std::string(50, '=') << "\n";
    return ok ? 0 : 1;
}
