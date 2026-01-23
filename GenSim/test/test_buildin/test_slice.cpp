// _slice tests: test the _slice function that extracts sublists from lists
#include <iostream>
#include <vector>
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

template <typename T>
bool expect_vector_eq(const std::vector<T> &got, const std::vector<T> &expect, const char *msg) {
    if (got.size() != expect.size()) {
        std::cerr << "[FAIL] " << msg << " size mismatch: got=" << got.size() << " expect=" << expect.size() << "\n";
        return false;
    }
    for (size_t i = 0; i < got.size(); ++i) {
        if (got[i] != expect[i]) {
            std::cerr << "[FAIL] " << msg << " element[" << i << "] mismatch: got=" << got[i] << " expect=" << expect[i] << "\n";
            return false;
        }
    }
    return true;
}

// Specialization for p5::uint
template <size_t N>
bool expect_vector_eq(const std::vector<p5::uint<N>> &got, const std::vector<p5::uint<N>> &expect, const char *msg) {
    if (got.size() != expect.size()) {
        std::cerr << "[FAIL] " << msg << " size mismatch: got=" << got.size() << " expect=" << expect.size() << "\n";
        return false;
    }
    for (size_t i = 0; i < got.size(); ++i) {
        if (got[i].to_ullong() != expect[i].to_ullong()) {
            std::cerr << "[FAIL] " << msg << " element[" << i << "] mismatch: got=" << got[i].to_ullong() << " expect=" << expect[i].to_ullong() << "\n";
            return false;
        }
    }
    return true;
}

// Helper function to print vector for debugging
template <typename T>
void print_vector(const std::vector<T> &vec, const char *name) {
    std::cout << "  " << name << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Specialization for p5::uint
template <size_t N>
void print_vector(const std::vector<p5::uint<N>> &vec, const char *name) {
    std::cout << "  " << name << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i].to_ullong();
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

} // namespace

int main() {
    std::cout << "[_slice test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Basic functionality - example from requirement
    {
        std::cout << "\n[Test 1] Testing _slice with basic functionality...\n";
        std::cout << "  Input: {0, 1, 2, 3, 4, 5}, start=1, end=3\n";

        std::vector<int> list = {0, 1, 2, 3, 4, 5};
        auto result = ctx._slice(list, 1, 3);
        
        static_assert(std::is_same_v<decltype(result), std::vector<int>>, 
                     "Return type should be std::vector<int>");
        
        std::vector<int> expected = {1, 2, 3};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "basic functionality");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 2: Single element slice
    {
        std::cout << "\n[Test 2] Testing _slice with single element...\n";
        std::cout << "  Input: {0, 1, 2}, start=0, end=0\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 0, 0);
        
        std::vector<int> expected = {0};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "single element");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 3: Full list slice
    {
        std::cout << "\n[Test 3] Testing _slice with full list...\n";
        std::cout << "  Input: {0, 1, 2}, start=0, end=2\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 0, 2);
        
        std::vector<int> expected = {0, 1, 2};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "full list");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 4: End index out of range
    {
        std::cout << "\n[Test 4] Testing _slice with end index out of range...\n";
        std::cout << "  Input: {0, 1, 2}, start=1, end=5\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 1, 5);
        
        std::vector<int> expected = {1, 2};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "end out of range");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 5: Negative start index
    {
        std::cout << "\n[Test 5] Testing _slice with negative start index...\n";
        std::cout << "  Input: {0, 1, 2}, start=-1, end=1\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, -1, 1);
        
        std::vector<int> expected = {0, 1};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "negative start");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 6: Negative end index
    {
        std::cout << "\n[Test 6] Testing _slice with negative end index...\n";
        std::cout << "  Input: {0, 1, 2}, start=0, end=-1\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 0, -1);
        
        std::vector<int> expected = {};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "negative end");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 7: Start > end (should return empty)
    {
        std::cout << "\n[Test 7] Testing _slice with start > end...\n";
        std::cout << "  Input: {0, 1, 2}, start=2, end=1\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 2, 1);
        
        std::vector<int> expected = {};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "start > end");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 8: Empty list
    {
        std::cout << "\n[Test 8] Testing _slice with empty list...\n";
        std::cout << "  Input: {}, start=0, end=2\n";

        std::vector<int> list = {};
        auto result = ctx._slice(list, 0, 2);
        
        std::vector<int> expected = {};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "empty list");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 9: size_t type parameters
    {
        std::cout << "\n[Test 9] Testing _slice with size_t parameters...\n";
        std::cout << "  Input: {10, 20, 30, 40}, start=1, end=2\n";

        std::vector<int> list = {10, 20, 30, 40};
        size_t start = 1;
        size_t end = 2;
        auto result = ctx._slice(list, start, end);
        
        std::vector<int> expected = {20, 30};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "size_t parameters");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 10: p5::uint type parameters
    {
        std::cout << "\n[Test 10] Testing _slice with p5::uint parameters...\n";
        std::cout << "  Input: {uint8(0), uint8(1), uint8(2), uint8(3)}, start=1, end=2\n";

        std::vector<p5::uint<8>> list = {
            p5::uint<8>(0), p5::uint<8>(1), p5::uint<8>(2), p5::uint<8>(3)
        };
        p5::uint<8> start = p5::uint<8>(1);
        p5::uint<8> end = p5::uint<8>(2);
        auto result = ctx._slice(list, start, end);
        
        static_assert(std::is_same_v<decltype(result), std::vector<p5::uint<8>>>, 
                     "Return type should be std::vector<p5::uint<8>>");
        
        std::vector<p5::uint<8>> expected = {p5::uint<8>(1), p5::uint<8>(2)};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "p5::uint parameters");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 11: Mixed types (int start, p5::uint end)
    {
        std::cout << "\n[Test 11] Testing _slice with mixed types (int, p5::uint)...\n";
        std::cout << "  Input: {100, 200, 300}, start=0, end=uint8(1)\n";

        std::vector<int> list = {100, 200, 300};
        int start = 0;
        p5::uint<8> end = p5::uint<8>(1);
        auto result = ctx._slice(list, start, end);
        
        std::vector<int> expected = {100, 200};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "mixed types (int, p5::uint)");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 12: Mixed types (p5::uint start, int end)
    {
        std::cout << "\n[Test 12] Testing _slice with mixed types (p5::uint, int)...\n";
        std::cout << "  Input: {100, 200, 300}, start=uint8(1), end=2\n";

        std::vector<int> list = {100, 200, 300};
        p5::uint<8> start = p5::uint<8>(1);
        int end = 2;
        auto result = ctx._slice(list, start, end);
        
        std::vector<int> expected = {200, 300};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "mixed types (p5::uint, int)");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 13: Large list slice
    {
        std::cout << "\n[Test 13] Testing _slice with large list...\n";
        std::cout << "  Input: list of 100 elements, start=10, end=19\n";

        std::vector<int> list;
        std::vector<int> expected;
        for (int i = 0; i < 100; ++i) {
            list.push_back(i);
            if (i >= 10 && i <= 19) {
                expected.push_back(i);
            }
        }
        
        auto result = ctx._slice(list, 10, 19);
        std::cout << "  Output size: " << result.size() << "\n";
        std::cout << "  Expected size: " << expected.size() << "\n";
        bool test_ok = expect_vector_eq(result, expected, "");
        ok &= test_ok;
        std::cout << "  Result: " << (test_ok ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 14: Start index out of range
    {
        std::cout << "\n[Test 14] Testing _slice with start index out of range...\n";
        std::cout << "  Input: {0, 1, 2}, start=5, end=6\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 5, 6);
        
        std::vector<int> expected = {};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "start out of range");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 15: Both indices out of range
    {
        std::cout << "\n[Test 15] Testing _slice with both indices out of range...\n";
        std::cout << "  Input: {0, 1, 2}, start=10, end=20\n";

        std::vector<int> list = {0, 1, 2};
        auto result = ctx._slice(list, 10, 20);
        
        std::vector<int> expected = {};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "both indices out of range");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "[_slice test] " << (ok ? "ALL PASS ✓" : "FAILED ✗") << "\n";
    std::cout << std::string(50, '=') << "\n";
    return ok ? 0 : 1;
}
