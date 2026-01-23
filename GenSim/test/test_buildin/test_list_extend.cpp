// _list_extend tests: test the _list_extend function that extends a variable to a list
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

} // namespace

int main() {
    std::cout << "[_list_extend test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Basic functionality with int count and p5::uint<N>
    {
        std::cout << "Testing _list_extend with int count and p5::uint<N>...\n";

        p5::uint<4> _vbit = p5::uint<4>(5);
        auto result = ctx._list_extend(_vbit, 3);
        
        static_assert(std::is_same_v<decltype(result), std::vector<p5::uint<4>>>, 
                     "Return type should be std::vector<p5::uint<4>>");
        
        ok &= expect_true(result.size() == 3, "result size should be 3");
        ok &= expect_true(result[0] == _vbit, "first element equals _vbit");
        ok &= expect_true(result[1] == _vbit, "second element equals _vbit");
        ok &= expect_true(result[2] == _vbit, "third element equals _vbit");
        
        // Verify all elements are equal
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), 5u, 
                                     ("element[" + std::to_string(i) + "] value").c_str());
        }
    }

    // Test 2: Using p5::uint<N> as count parameter
    {
        std::cout << "Testing _list_extend with p5::uint<N> count...\n";

        p5::uint<8> value = p5::uint<8>(42);
        p5::uint<8> count = p5::uint<8>(5);
        auto result = ctx._list_extend(value, count);
        
        ok &= expect_true(result.size() == 5, "result size should be 5");
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), 42u, 
                                     ("p5::uint count element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 3: Using size_t as count parameter
    {
        std::cout << "Testing _list_extend with size_t count...\n";

        p5::uint<16> value = p5::uint<16>(100);
        size_t count = 4;
        auto result = ctx._list_extend(value, count);
        
        ok &= expect_true(result.size() == 4, "result size should be 4");
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), 100u, 
                                     ("size_t count element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 4: Edge case - count = 0
    {
        std::cout << "Testing _list_extend with count = 0...\n";

        p5::uint<4> value = p5::uint<4>(7);
        auto result = ctx._list_extend(value, 0);
        
        ok &= expect_true(result.size() == 0, "result size should be 0 for count=0");
        ok &= expect_true(result.empty(), "result should be empty for count=0");
    }

    // Test 5: Edge case - count = 1
    {
        std::cout << "Testing _list_extend with count = 1...\n";

        p5::uint<4> value = p5::uint<4>(9);
        auto result = ctx._list_extend(value, 1);
        
        ok &= expect_true(result.size() == 1, "result size should be 1");
        ok &= expect_eq<uint64_t>(result[0].to_ullong(), 9u, "single element value");
    }

    // Test 6: Edge case - negative count (should be clamped to 0)
    {
        std::cout << "Testing _list_extend with negative count...\n";

        p5::uint<4> value = p5::uint<4>(3);
        auto result = ctx._list_extend(value, -5);
        
        ok &= expect_true(result.size() == 0, "result size should be 0 for negative count");
        ok &= expect_true(result.empty(), "result should be empty for negative count");
    }

    // Test 7: Different p5::uint bit widths
    {
        std::cout << "Testing _list_extend with different p5::uint bit widths...\n";

        p5::uint<1> bit1 = p5::uint<1>(1);
        auto result1 = ctx._list_extend(bit1, 2);
        ok &= expect_true(result1.size() == 2, "p5::uint<1> list size");
        ok &= expect_eq<uint64_t>(result1[0].to_ullong(), 1u, "p5::uint<1> element 0");
        ok &= expect_eq<uint64_t>(result1[1].to_ullong(), 1u, "p5::uint<1> element 1");

        p5::uint<32> bit32 = p5::uint<32>(0x12345678);
        auto result32 = ctx._list_extend(bit32, 3);
        ok &= expect_true(result32.size() == 3, "p5::uint<32> list size");
        for (size_t i = 0; i < result32.size(); ++i) {
            ok &= expect_eq<uint64_t>(result32[i].to_ullong(), 0x12345678u, 
                                     ("p5::uint<32> element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 8: Large count values
    {
        std::cout << "Testing _list_extend with large count...\n";

        p5::uint<8> value = p5::uint<8>(255);
        auto result = ctx._list_extend(value, 100);
        
        ok &= expect_true(result.size() == 100, "result size should be 100");
        for (size_t i = 0; i < result.size(); ++i) {
            ok &= expect_eq<uint64_t>(result[i].to_ullong(), 255u, 
                                     ("large count element[" + std::to_string(i) + "]").c_str());
        }
    }

    // Test 9: Using p5::uint<N> with different count types
    {
        std::cout << "Testing _list_extend with p5::uint<N> and various count types...\n";

        p5::uint<4> value = p5::uint<4>(10);
        
        // Test with p5::uint<8> count
        p5::uint<8> count8 = p5::uint<8>(3);
        auto result8 = ctx._list_extend(value, count8);
        ok &= expect_true(result8.size() == 3, "p5::uint<8> count result size");
        
        // Test with p5::uint<16> count
        p5::uint<16> count16 = p5::uint<16>(7);
        auto result16 = ctx._list_extend(value, count16);
        ok &= expect_true(result16.size() == 7, "p5::uint<16> count result size");
    }

    // Test 10: Verify elements are independent copies (not references)
    {
        std::cout << "Testing that _list_extend creates independent copies...\n";

        p5::uint<4> original = p5::uint<4>(15);
        auto result = ctx._list_extend(original, 3);
        
        // Modify original - should not affect result
        original = p5::uint<4>(99);
        
        ok &= expect_eq<uint64_t>(result[0].to_ullong(), 15u, "element 0 unchanged after original modification");
        ok &= expect_eq<uint64_t>(result[1].to_ullong(), 15u, "element 1 unchanged after original modification");
        ok &= expect_eq<uint64_t>(result[2].to_ullong(), 15u, "element 2 unchanged after original modification");
    }

    // Test 11: Example from user requirement: _list_extend(_vbit, 3) equivalent to {_vbit, _vbit, _vbit}
    {
        std::cout << "Testing user example: _list_extend(_vbit, 3) equivalent to {_vbit, _vbit, _vbit}...\n";

        p5::uint<4> _vbit = p5::uint<4>(5);
        auto extended = ctx._list_extend(_vbit, 3);
        
        // Create expected result manually
        std::vector<p5::uint<4>> expected = {_vbit, _vbit, _vbit};
        
        ok &= expect_true(extended.size() == expected.size(), "extended size matches expected");
        for (size_t i = 0; i < extended.size(); ++i) {
            ok &= expect_eq<uint64_t>(extended[i].to_ullong(), expected[i].to_ullong(), 
                                     ("user example element[" + std::to_string(i) + "]").c_str());
        }
    }

    std::cout << "[_list_extend test] " << (ok ? "ALL PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}
