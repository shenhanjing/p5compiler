// _memcpy tests: test memcpy function for both simple assignment and array copying
#include <iostream>
#include <cstring>

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
    std::cout << "[_memcpy test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Test 1: Simple assignment (existing functionality)
    {
        std::cout << "Testing simple assignment...\n";

        p5::uint<16> dst = 0;
        p5::uint<16> src = 42;

        ctx._memcpy(dst, src);
        ok &= expect_eq<uint64_t>(dst.to_ullong(), 42u, "simple assignment");
    }

    // Test 2: Fixed-size array copying (same size)
    {
        std::cout << "Testing fixed-size array copying (same size)...\n";

        p5::uint<8> dst[3] = {0, 0, 0};
        p5::uint<8> src[3] = {10, 20, 30};

        ctx._memcpy(dst, src);

        ok &= expect_eq<uint64_t>(dst[0].to_ullong(), 10u, "array copy element 0");
        ok &= expect_eq<uint64_t>(dst[1].to_ullong(), 20u, "array copy element 1");
        ok &= expect_eq<uint64_t>(dst[2].to_ullong(), 30u, "array copy element 2");
    }

    // Test 3: Fixed-size array copying (different sizes - dst smaller)
    {
        std::cout << "Testing fixed-size array copying (dst smaller)...\n";

        p5::uint<8> dst[2] = {0, 0};
        p5::uint<8> src[3] = {100, 200, 300};

        ctx._memcpy(dst, src);

        // Should only copy first 2 elements
        ok &= expect_eq<uint64_t>(dst[0].to_ullong(), 100u, "partial copy element 0");
        ok &= expect_eq<uint64_t>(dst[1].to_ullong(), 200u, "partial copy element 1");
    }

    // Test 4: Fixed-size array copying (different sizes - src smaller)
    {
        std::cout << "Testing fixed-size array copying (src smaller)...\n";

        p5::uint<8> dst[4] = {0, 0, 0, 0};
        p5::uint<8> src[2] = {150, 250};

        ctx._memcpy(dst, src);

        // Should copy all src elements, dst[2] and dst[3] remain unchanged
        ok &= expect_eq<uint64_t>(dst[0].to_ullong(), 150u, "partial copy src smaller element 0");
        ok &= expect_eq<uint64_t>(dst[1].to_ullong(), 250u, "partial copy src smaller element 1");
        ok &= expect_eq<uint64_t>(dst[2].to_ullong(), 0u, "partial copy src smaller element 2 unchanged");
        ok &= expect_eq<uint64_t>(dst[3].to_ullong(), 0u, "partial copy src smaller element 3 unchanged");
    }

    // Test 5: PHO-like array copying (user's example)
    {
        std::cout << "Testing PHO-like array copying (user's example)...\n";

        // Simulate PHO[5] and Buffer array
        const std::size_t PHO_SIZE = 5;
        p5::uint<7> PHO[PHO_SIZE] = {0, 0, 0, 0, 0};
        p5::uint<7> Buffer[PHO_SIZE] = {11, 22, 33, 44, 55};

        // This simulates: _memcpy(PHO, Buffer);
        ctx._memcpy(PHO, Buffer);

        ok &= expect_eq<uint64_t>(PHO[0].to_ullong(), 11u, "PHO copy element 0");
        ok &= expect_eq<uint64_t>(PHO[1].to_ullong(), 22u, "PHO copy element 1");
        ok &= expect_eq<uint64_t>(PHO[2].to_ullong(), 33u, "PHO copy element 2");
        ok &= expect_eq<uint64_t>(PHO[3].to_ullong(), 44u, "PHO copy element 3");
        ok &= expect_eq<uint64_t>(PHO[4].to_ullong(), 55u, "PHO copy element 4");
    }

    // Test 6: Different element types
    {
        std::cout << "Testing different element types...\n";

        p5::uint<16> dst[3] = {0, 0, 0};
        p5::uint<16> src[3] = {1000, 2000, 3000};

        ctx._memcpy(dst, src);

        ok &= expect_eq<uint64_t>(dst[0].to_ullong(), 1000u, "uint16 array copy element 0");
        ok &= expect_eq<uint64_t>(dst[1].to_ullong(), 2000u, "uint16 array copy element 1");
        ok &= expect_eq<uint64_t>(dst[2].to_ullong(), 3000u, "uint16 array copy element 2");
    }

    // Test 7: Dynamic array copying with size parameter
    {
        std::cout << "Testing dynamic array copying...\n";

        p5::uint<8> dst_dynamic[10] = {0};
        p5::uint<8> src_dynamic[5] = {1, 2, 3, 4, 5};

        // Copy only first 3 elements
        ctx._memcpy(dst_dynamic, src_dynamic, 3);

        ok &= expect_eq<uint64_t>(dst_dynamic[0].to_ullong(), 1u, "dynamic copy element 0");
        ok &= expect_eq<uint64_t>(dst_dynamic[1].to_ullong(), 2u, "dynamic copy element 1");
        ok &= expect_eq<uint64_t>(dst_dynamic[2].to_ullong(), 3u, "dynamic copy element 2");
        ok &= expect_eq<uint64_t>(dst_dynamic[3].to_ullong(), 0u, "dynamic copy element 3 unchanged");
    }

    std::cout << "[_memcpy test] " << (ok ? "PASSED" : "FAILED") << "\n";
    return ok ? 0 : 1;
}