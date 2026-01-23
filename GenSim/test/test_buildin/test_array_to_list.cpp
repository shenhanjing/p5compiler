// _array_to_list tests: test the _array_to_list function that converts array to vector
#include <iostream>
#include <vector>
#include <string>

#include "../../include/BuiltIn.hpp"
#include "../../generated/include/generated_struct.hpp"

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

} // namespace

int main() {
    std::cout << "[_array_to_list test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Basic functionality with int array
    {
        std::cout << "Testing _array_to_list with int array...\n";

        int arr[5] = {1, 2, 3, 4, 5};
        auto result = ctx._array_to_list(arr);
        
        static_assert(std::is_same_v<decltype(result), std::vector<int>>, 
                     "Return type should be std::vector<int>");
        
        ok &= expect_true(result.size() == 5, "result size should be 5");
        ok &= expect_eq<int>(result[0], 1, "first element should be 1");
        ok &= expect_eq<int>(result[4], 5, "last element should be 5");
        
        // Verify all elements
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<int>(result[i], static_cast<int>(i + 1), 
                                ("element[" + std::to_string(i) + "] value").c_str());
        }
    }

    // Test 2: p5::uint array conversion
    {
        std::cout << "Testing _array_to_list with p5::uint array...\n";

        p5::uint<8> arr[3] = {p5::uint<8>(10), p5::uint<8>(20), p5::uint<8>(30)};
        auto result = ctx._array_to_list(arr);
        
        static_assert(std::is_same_v<decltype(result), std::vector<p5::uint<8>>>, 
                     "Return type should be std::vector<p5::uint<8>>");
        
        ok &= expect_true(result.size() == 3, "result size should be 3");
        ok &= expect_eq<uint64_t>(result[0].to_ullong(), 10u, "first element should be 10");
        ok &= expect_eq<uint64_t>(result[2].to_ullong(), 30u, "last element should be 30");
        
        // Verify all elements
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), static_cast<uint64_t>((i + 1) * 10), 
                                     ("p5::uint element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 3: Single element array
    {
        std::cout << "Testing _array_to_list with single element array...\n";

        int arr[1] = {42};
        auto result = ctx._array_to_list(arr);
        
        ok &= expect_true(result.size() == 1, "result size should be 1");
        ok &= expect_eq<int>(result[0], 42, "single element value");
    }

    // Test 4: Different p5::uint bit widths
    {
        std::cout << "Testing _array_to_list with different p5::uint bit widths...\n";

        p5::uint<1> arr1[2] = {p5::uint<1>(1), p5::uint<1>(0)};
        auto result1 = ctx._array_to_list(arr1);
        ok &= expect_true(result1.size() == 2, "p5::uint<1> array size");
        ok &= expect_eq<uint64_t>(result1[0].to_ullong(), 1u, "p5::uint<1> element 0");
        ok &= expect_eq<uint64_t>(result1[1].to_ullong(), 0u, "p5::uint<1> element 1");

        p5::uint<32> arr32[3] = {p5::uint<32>(0x12345678), p5::uint<32>(0xABCDEF00), p5::uint<32>(0xDEADBEEF)};
        auto result32 = ctx._array_to_list(arr32);
        ok &= expect_true(result32.size() == 3, "p5::uint<32> array size");
        ok &= expect_eq<uint64_t>(result32[0].to_ullong(), 0x12345678u, "p5::uint<32> element 0");
        ok &= expect_eq<uint64_t>(result32[1].to_ullong(), 0xABCDEF00u, "p5::uint<32> element 1");
        ok &= expect_eq<uint64_t>(result32[2].to_ullong(), 0xDEADBEEFu, "p5::uint<32> element 2");
    }

    // Test 5: Large array
    {
        std::cout << "Testing _array_to_list with large array...\n";

        p5::uint<8> arr[100];
        for (int i = 0; i < 100; ++i) {
            arr[i] = p5::uint<8>(i);
        }
        auto result = ctx._array_to_list(arr);
        
        ok &= expect_true(result.size() == 100, "result size should be 100");
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), i, 
                                     ("large array element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 6: Integration with _lenof
    {
        std::cout << "Testing _array_to_list integration with _lenof...\n";

        p5::uint<4> arr[4] = {p5::uint<4>(1), p5::uint<4>(2), p5::uint<4>(3), p5::uint<4>(4)};
        auto len1 = ctx._lenof(arr);
        auto vec = ctx._array_to_list(arr);
        auto len2 = ctx._lenof(vec);
        
        ok &= expect_eq<uint64_t>(len1.to_ullong(), 4u, "array length should be 4");
        ok &= expect_eq<uint64_t>(len2.to_ullong(), 4u, "vector length should be 4");
        ok &= expect_eq<uint64_t>(len1.to_ullong(), len2.to_ullong(), "array and vector lengths should match");
    }

    // Test 7: Verify elements are independent copies (not references)
    {
        std::cout << "Testing that _array_to_list creates independent copies...\n";

        int arr[3] = {10, 20, 30};
        auto result = ctx._array_to_list(arr);
        
        // Modify original array - should not affect result
        arr[0] = 99;
        arr[1] = 99;
        arr[2] = 99;
        
        ok &= expect_eq<int>(result[0], 10, "element 0 unchanged after array modification");
        ok &= expect_eq<int>(result[1], 20, "element 1 unchanged after array modification");
        ok &= expect_eq<int>(result[2], 30, "element 2 unchanged after array modification");
    }

    // Test 8: Comparison with manually created vector
    {
        std::cout << "Testing _array_to_list result matches manually created vector...\n";

        p5::uint<8> arr[5] = {p5::uint<8>(1), p5::uint<8>(2), p5::uint<8>(3), 
                              p5::uint<8>(4), p5::uint<8>(5)};
        auto result = ctx._array_to_list(arr);
        
        // Create expected result manually
        std::vector<p5::uint<8>> expected = {
            p5::uint<8>(1), p5::uint<8>(2), p5::uint<8>(3), 
            p5::uint<8>(4), p5::uint<8>(5)
        };
        
        ok &= expect_true(result.size() == expected.size(), "size matches expected");
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), expected[i].to_ullong(), 
                                     ("comparison element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 9: Different array sizes
    {
        std::cout << "Testing _array_to_list with different array sizes...\n";

        // Size 2
        int arr2[2] = {1, 2};
        auto vec2 = ctx._array_to_list(arr2);
        ok &= expect_true(vec2.size() == 2, "size 2 array");

        // Size 10
        int arr10[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto vec10 = ctx._array_to_list(arr10);
        ok &= expect_true(vec10.size() == 10, "size 10 array");
        for (size_t i = 0; i < vec10.size(); ++i) {
            ok &= expect_eq<int>(vec10[i], static_cast<int>(i), 
                                ("size 10 element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 10: Const array
    {
        std::cout << "Testing _array_to_list with const array...\n";

        const int arr[3] = {100, 200, 300};
        auto result = ctx._array_to_list(arr);
        
        ok &= expect_true(result.size() == 3, "const array size");
        ok &= expect_eq<int>(result[0], 100, "const array element 0");
        ok &= expect_eq<int>(result[1], 200, "const array element 1");
        ok &= expect_eq<int>(result[2], 300, "const array element 2");
    }

    // Test 11: Integration with _list_extend (convert array, then extend)
    {
        std::cout << "Testing _array_to_list integration with _list_extend...\n";

        p5::uint<4> arr[2] = {p5::uint<4>(5), p5::uint<4>(10)};
        auto vec = ctx._array_to_list(arr);
        ok &= expect_true(vec.size() == 2, "converted array size");
        
        // Now extend the first element
        auto extended = ctx._list_extend(vec[0], 3);
        ok &= expect_true(extended.size() == 3, "extended size");
        for (size_t i = 0; i < extended.size(); ++i) {
            ok &= expect_eq<uint64_t>(extended[i].to_ullong(), 5u, 
                                     ("extended element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 12: Verify all elements are correctly copied
    {
        std::cout << "Testing element-by-element correctness...\n";

        p5::uint<8> arr[7] = {
            p5::uint<8>(0), p5::uint<8>(1), p5::uint<8>(2), 
            p5::uint<8>(3), p5::uint<8>(4), p5::uint<8>(5), p5::uint<8>(6)
        };
        auto result = ctx._array_to_list(arr);
        
        ok &= expect_true(result.size() == 7, "element correctness size check");
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), i, 
                                     ("element correctness[" + std::to_string(i) + "]").c_str());
        }
    }

    std::cout << "[_array_to_list test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}
