// _list_flatten tests: test the _list_flatten function that flattens nested lists
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
    std::cout << "[_list_flatten test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Basic functionality - one level nesting
    {
        std::cout << "\n[Test 1] Testing _list_flatten with one level nesting...\n";
        std::cout << "  Input: {{1, 2}, {3, 4}, {5}}\n";

        std::vector<std::vector<int>> nested = {{1, 2}, {3, 4}, {5}};
        auto result = ctx._list_flatten(nested);
        
        static_assert(std::is_same_v<decltype(result), std::vector<int>>, 
                     "Return type should be std::vector<int>");
        
        std::vector<int> expected = {1, 2, 3, 4, 5};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "one level nesting");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 2: Multi-level nesting
    {
        std::cout << "\n[Test 2] Testing _list_flatten with multi-level nesting (3 levels)...\n";
        std::cout << "  Input: {{{1, 2}}, {{3, 4}}}\n";

        std::vector<std::vector<std::vector<int>>> deep = {{{1, 2}}, {{3, 4}}};
        auto result = ctx._list_flatten(deep);
        
        static_assert(std::is_same_v<decltype(result), std::vector<int>>, 
                     "Return type should be std::vector<int>");
        
        std::vector<int> expected = {1, 2, 3, 4};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "multi-level nesting");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 3: Empty list
    {
        std::cout << "\n[Test 3] Testing _list_flatten with empty list...\n";
        std::cout << "  Input: {}\n";

        std::vector<std::vector<int>> empty = {};
        auto result = ctx._list_flatten(empty);
        
        std::cout << "  Output size: " << result.size() << "\n";
        std::cout << "  Expected size: 0\n";
        bool test_ok = result.size() == 0 && result.empty();
        ok &= expect_true(test_ok, "empty list should return empty result");
        std::cout << "  Result: " << (test_ok ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 4: List with empty sublists
    {
        std::cout << "\n[Test 4] Testing _list_flatten with empty sublists...\n";
        std::cout << "  Input: {{1, 2}, {}, {3, 4}}\n";

        std::vector<std::vector<int>> with_empty = {{1, 2}, {}, {3, 4}};
        auto result = ctx._list_flatten(with_empty);
        
        std::vector<int> expected = {1, 2, 3, 4};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "list with empty sublists");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 5: Single element sublists
    {
        std::cout << "\n[Test 5] Testing _list_flatten with single element sublists...\n";
        std::cout << "  Input: {{1}, {2}, {3}}\n";

        std::vector<std::vector<int>> single = {{1}, {2}, {3}};
        auto result = ctx._list_flatten(single);
        
        std::vector<int> expected = {1, 2, 3};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "single element sublists");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 6: Four-level nesting
    {
        std::cout << "\n[Test 6] Testing _list_flatten with four-level nesting...\n";
        std::cout << "  Input: {{{{1}}}, {{{2, 3}}}, {{{4}}}}\n";

        std::vector<std::vector<std::vector<std::vector<int>>>> very_deep = 
            {{{{1}}}, {{{2, 3}}}, {{{4}}}};
        auto result = ctx._list_flatten(very_deep);
        
        static_assert(std::is_same_v<decltype(result), std::vector<int>>, 
                     "Return type should be std::vector<int>");
        
        std::vector<int> expected = {1, 2, 3, 4};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "four-level nesting");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 7: Mixed nesting depths (all elements at same level, but some are nested)
    {
        std::cout << "\n[Test 7] Testing _list_flatten with mixed nesting...\n";
        std::cout << "  Input: {{1, 2}, {3}, {4, 5, 6}}\n";

        std::vector<std::vector<int>> mixed = {{1, 2}, {3}, {4, 5, 6}};
        auto result = ctx._list_flatten(mixed);
        
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        print_vector(result, "Output");
        print_vector(expected, "Expected");
        ok &= expect_vector_eq(result, expected, "mixed nesting");
        std::cout << "  Result: " << (expect_vector_eq(result, expected, "") ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 8: p5::uint type
    {
        std::cout << "\n[Test 8] Testing _list_flatten with p5::uint type...\n";
        std::cout << "  Input: {{uint8(1), uint8(2)}, {uint8(3), uint8(4)}}\n";

        std::vector<std::vector<p5::uint<8>>> nested_uint = {
            {p5::uint<8>(1), p5::uint<8>(2)}, 
            {p5::uint<8>(3), p5::uint<8>(4)}
        };
        auto result = ctx._list_flatten(nested_uint);
        
        static_assert(std::is_same_v<decltype(result), std::vector<p5::uint<8>>>, 
                     "Return type should be std::vector<p5::uint<8>>");
        
        print_vector(result, "Output");
        std::cout << "  Expected: [1, 2, 3, 4]\n";
        bool test_ok = result.size() == 4 && 
                      result[0].to_ullong() == 1u && result[1].to_ullong() == 2u &&
                      result[2].to_ullong() == 3u && result[3].to_ullong() == 4u;
        ok &= expect_true(test_ok, "p5::uint flatten");
        std::cout << "  Result: " << (test_ok ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 9: Preserve relative position
    {
        std::cout << "\n[Test 9] Testing _list_flatten preserves relative position...\n";
        std::cout << "  Input: {{10, 20}, {30}, {40, 50, 60}}\n";

        std::vector<std::vector<int>> nested = {{10, 20}, {30}, {40, 50, 60}};
        auto result = ctx._list_flatten(nested);
        
        // Verify order: 10, 20 (from first sublist), 30 (from second), 40, 50, 60 (from third)
        print_vector(result, "Output");
        std::cout << "  Expected: [10, 20, 30, 40, 50, 60]\n";
        bool test_ok = result.size() == 6 && 
                      result[0] == 10 && result[1] == 20 && result[2] == 30 &&
                      result[3] == 40 && result[4] == 50 && result[5] == 60;
        ok &= expect_true(test_ok, "relative position");
        std::cout << "  Result: " << (test_ok ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    // Test 10: Large nested list
    {
        std::cout << "\n[Test 10] Testing _list_flatten with large nested list (10x10)...\n";
        std::cout << "  Input: 10 sublists, each containing 10 elements\n";

        std::vector<std::vector<int>> large;
        std::vector<int> expected;
        for (int i = 0; i < 10; ++i) {
            std::vector<int> sublist;
            for (int j = 0; j < 10; ++j) {
                int val = i * 10 + j;
                sublist.push_back(val);
                expected.push_back(val);
            }
            large.push_back(sublist);
        }
        
        auto result = ctx._list_flatten(large);
        std::cout << "  Output size: " << result.size() << "\n";
        std::cout << "  Expected size: " << expected.size() << "\n";
        bool test_ok = expect_vector_eq(result, expected, "");
        ok &= test_ok;
        std::cout << "  Result: " << (test_ok ? "✓ PASS" : "✗ FAIL") << "\n";
    }

    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "[_list_flatten test] " << (ok ? "ALL PASS ✓" : "FAILED ✗") << "\n";
    std::cout << std::string(50, '=') << "\n";
    return ok ? 0 : 1;
}
