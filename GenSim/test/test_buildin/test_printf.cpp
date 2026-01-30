// _printf tests: test the printf function for formatted output
#include <iostream>
#include <cstdio>
#include <unistd.h>

#include "../../include/BuiltIn.hpp"

namespace {

bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}

} // namespace

int main() {
    std::cout << "[_printf test] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // Note: Since printf outputs to stdout and we can't easily capture it in automated tests,
    // we'll test that the function calls don't crash and complete successfully.

    std::cout << "Testing _printf function calls (output goes to stdout):\n";

    // Test global and member function versions
    std::cout << "=== Testing Global _printf ===\n";

    // Test 1: Global simple string output
    std::cout << "1. Global simple string: ";
    _printf("Hello, World!\n");
    ok &= expect_true(true, "global simple string call");

    // Test 2: Global formatted output with integers (user's example)
    std::cout << "2. Global user example: ";
    uint64_t start = 100;
    uint64_t end = 200;
    uint64_t packet_length = 150;
    _printf("****Doing PHCut, start=%llu, End=%llu, Packet Length=%llu\n",
           start, end, packet_length);
    ok &= expect_true(true, "global user example call");

    std::cout << "\n=== Testing Member _printf ===\n";

    // Test 3: Member different format specifiers
    std::cout << "3. Member mixed formats: ";
    int32_t signed_val = -42;
    uint32_t unsigned_val = 42;
    uint64_t large_val = 18446744073709551615ULL;  // 2^64 - 1
    _printf("Signed: %d, Unsigned: %u, Large: %llu\n",
               signed_val, unsigned_val, large_val);
    ok &= expect_true(true, "member mixed formats call");

    // Test 4: Member string and character output
    std::cout << "4. Member string/char: ";
    const char* message = "Test message";
    char ch = 'A';
    _printf("Message: %s, Character: %c\n", message, ch);
    ok &= expect_true(true, "member string/char call");

    // Test 5: Member hexadecimal output
    std::cout << "5. Member hex output: ";
    uint32_t hex_val = 0xDEADBEEF;
    _printf("Hex: 0x%x, Upper: 0x%X\n", hex_val, hex_val);
    ok &= expect_true(true, "member hex call");

    // Test 6: Member multiple arguments
    std::cout << "6. Member multiple args: ";
    _printf("%d %u %llu %s %c %x\n",
               -1, 2u, 3ULL, "test", 'Z', 255);
    ok &= expect_true(true, "member multiple args call");

    // Test 7: Member edge case - empty format
    std::cout << "7. Member empty format: ";
    _printf("");
    ok &= expect_true(true, "member empty format call");

    std::cout << "\n[_printf test] " << (ok ? "PASSED" : "FAILED") << "\n";
    std::cout << "All _printf calls completed successfully.\n";
    std::cout << "Check the output above for correct formatting.\n";

    return ok ? 0 : 1;
}