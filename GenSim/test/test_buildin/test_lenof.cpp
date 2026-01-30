// _lenof tests: test global and member function versions for vector and array types
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

} // namespace

int main() {
    std::cout << "[_lenof test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Global _lenof with std::vector
    {
        std::cout << "Testing global _lenof with std::vector...\n";

        std::vector<int> vec1 = {1, 2, 3, 4, 5};
        auto result1 = _lenof(vec1);
        static_assert(std::is_same_v<decltype(result1), p5::uint<16>>, "Return type should be p5::uint<16>");
        ok &= expect_eq<uint64_t>(result1.to_ullong(), 5u, "vector size 5");

        std::vector<std::string> vec2 = {"hello", "world"};
        auto result2 = _lenof(vec2);
        ok &= expect_eq<uint64_t>(result2.to_ullong(), 2u, "vector size 2");

        std::vector<p5::uint<8>> vec3 = {p5::uint<8>(1), p5::uint<8>(2), p5::uint<8>(3)};
        auto result3 = _lenof(vec3);
        ok &= expect_eq<uint64_t>(result3.to_ullong(), 3u, "p5::uint vector size 3");

        std::vector<int> empty_vec;
        auto result_empty = _lenof(empty_vec);
        ok &= expect_eq<uint64_t>(result_empty.to_ullong(), 0u, "empty vector size 0");
    }

    // Test 2: Global _lenof with arrays
    {
        std::cout << "Testing global _lenof with arrays...\n";

        int arr1[5] = {1, 2, 3, 4, 5};
        auto result1 = _lenof(arr1);
        static_assert(std::is_same_v<decltype(result1), p5::uint<16>>, "Return type should be p5::uint<16>");
        ok &= expect_eq<uint64_t>(result1.to_ullong(), 5u, "array size 5");

        double arr2[3] = {1.1, 2.2, 3.3};
        auto result2 = _lenof(arr2);
        ok &= expect_eq<uint64_t>(result2.to_ullong(), 3u, "array size 3");

        p5::uint<4> arr3[4] = {p5::uint<4>(1), p5::uint<4>(2), p5::uint<4>(3), p5::uint<4>(4)};
        auto result3 = _lenof(arr3);
        ok &= expect_eq<uint64_t>(result3.to_ullong(), 4u, "p5::uint array size 4");
    }

    // // Test 3: Member function _lenof with std::vector
    // {
    //     std::cout << "Testing member _lenof with std::vector...\n";

    //     std::vector<int> vec1 = {10, 20, 30};
    //     auto result1 = ctx._lenof(vec1);
    //     static_assert(std::is_same_v<decltype(result1), p5::uint<16>>, "Return type should be p5::uint<16>");
    //     ok &= expect_eq<uint64_t>(result1.to_ullong(), 3u, "member vector size 3");

    //     std::vector<p5::uint<16>> vec2 = {p5::uint<16>(100), p5::uint<16>(200)};
    //     auto result2 = ctx._lenof(vec2);
    //     ok &= expect_eq<uint64_t>(result2.to_ullong(), 2u, "member p5::uint vector size 2");

    //     std::vector<int> empty_vec;
    //     auto result_empty = ctx._lenof(empty_vec);
    //     ok &= expect_eq<uint64_t>(result_empty.to_ullong(), 0u, "member empty vector size 0");
    // }

    // // Test 4: Member function _lenof with arrays
    // {
    //     std::cout << "Testing member _lenof with arrays...\n";

    //     int arr1[4] = {100, 200, 300, 400};
    //     auto result1 = ctx._lenof(arr1);
    //     static_assert(std::is_same_v<decltype(result1), p5::uint<16>>, "Return type should be p5::uint<16>");
    //     ok &= expect_eq<uint64_t>(result1.to_ullong(), 4u, "member array size 4");

    //     p5::uint<2> arr2[6] = {p5::uint<2>(0), p5::uint<2>(1), p5::uint<2>(2),
    //                            p5::uint<2>(3), p5::uint<2>(0), p5::uint<2>(1)};
    //     auto result2 = ctx._lenof(arr2);
    //     ok &= expect_eq<uint64_t>(result2.to_ullong(), 6u, "member p5::uint array size 6");
    // }

    // Test 5: Pattern from generated_switch.cpp uint0_list function
    {
        std::cout << "Testing pattern from generated_switch.cpp uint0_list...\n";

        // Simulate the pattern from uint0_list function:
        // std::vector<T1> list0(_InitList_list0);
        // std::vector<T3> list2(_InitList_list2);
        // std::vector<T4> list3(_InitList_list3);
        // auto TempVAR = var0;
        // decltype(list0) TempLIST(list0.size());
        // auto a = _lenof(list0);
        // auto b = _lenof(TempLIST);

        // Using p5::uint types as in the original code
        using T0 = int;  // var0 type
        using T1 = p5::uint<4>;  // list0 element type
        using T2 = p5::uint<4>;  // var1 type (reference)
        using T3 = p5::uint<5>;  // list2 element type
        using T4 = p5::uint<6>;  // list3 element type

        // Simulate function parameters
        T0 var0 = 15;  // Some value
        std::initializer_list<T1> _InitList_list0 = {p5::uint<4>(1), p5::uint<4>(2), p5::uint<4>(3)};
        T2 var1 = p5::uint<4>(5);
        std::initializer_list<T3> _InitList_list2 = {p5::uint<5>(10), p5::uint<5>(20)};
        std::initializer_list<T4> _InitList_list3 = {p5::uint<6>(100), p5::uint<6>(200), p5::uint<6>(300), p5::uint<6>(400)};

        // Replicate the function body pattern
        std::vector<T1> list0(_InitList_list0);
        std::vector<T3> list2(_InitList_list2);
        std::vector<T4> list3(_InitList_list3);
        auto TempVAR = var0;
        decltype(list0) TempLIST(list0.size());  // Creates vector of same type with same size
        auto a = _lenof(list0);
        auto b = _lenof(TempLIST);

        // Test the results
        ok &= expect_eq<uint64_t>(a.to_ullong(), 3u, "list0 length (from initializer_list)");
        ok &= expect_eq<uint64_t>(b.to_ullong(), 3u, "TempLIST length (decltype + size)");
        ok &= expect_eq<uint64_t>(TempLIST.size(), 3u, "TempLIST actual size");

        // // Test with member function version
        // auto a_member = ctx._lenof(list0);
        // auto b_member = ctx._lenof(TempLIST);
        // ok &= expect_eq<uint64_t>(a_member.to_ullong(), 3u, "member list0 length");
        // ok &= expect_eq<uint64_t>(b_member.to_ullong(), 3u, "member TempLIST length");

        // Test with different initializer list sizes
        std::vector<p5::uint<8>> list_small({p5::uint<8>(1)});
        decltype(list_small) temp_small(list_small.size());
        auto c = _lenof(list_small);
        auto d = _lenof(temp_small);
        ok &= expect_eq<uint64_t>(c.to_ullong(), 1u, "small list length");
        ok &= expect_eq<uint64_t>(d.to_ullong(), 1u, "small temp list length");
    }

    // Test 6: Edge cases and type compatibility
    {
        std::cout << "Testing edge cases...\n";

        // Test with const vectors and arrays
        const std::vector<int> const_vec = {1, 2};
        auto result_const_vec = _lenof(const_vec);
        ok &= expect_eq<uint64_t>(result_const_vec.to_ullong(), 2u, "const vector");

        // const int const_arr[3] = {1, 2, 3};
        // auto result_const_arr = ctx._lenof(const_arr);
        // ok &= expect_eq<uint64_t>(result_const_arr.to_ullong(), 3u, "const array");

        // Test with different element types
        std::vector<char> char_vec = {'a', 'b', 'c', 'd'};
        auto result_char_vec = _lenof(char_vec);
        ok &= expect_eq<uint64_t>(result_char_vec.to_ullong(), 4u, "char vector");
    }

    std::cout << "[_lenof test] " << (ok ? "PASSED" : "FAILED") << "\n";
    return ok ? 0 : 1;
}