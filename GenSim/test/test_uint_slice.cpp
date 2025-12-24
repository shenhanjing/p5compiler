#include <iostream>
#include "../include/p5_types.hpp"

namespace {

bool expect_eq(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

bool test_single_bit_rw() {
    p5::uint<8> v = 0;
    v[0] = 1;
    v[7] = 1;
    bool ok = expect_eq(v.to_ullong(), 0b10000001, "single bit set");

    v[0] = 0; // clear
    ok &= expect_eq(v.to_ullong(), 0b10000000, "single bit clear");
    ok &= (v[7] == true);
    ok &= (v[0] == false);
    return ok;
}

bool test_slice_rw_uint() {
    p5::uint<8> v = 0;
    p5::uint<3> slice_val = 0b101;

    v[p5::bit_range<3, 1>] = slice_val; // write bits 1..3
    bool ok = expect_eq(v.to_ullong(), 0b00001010, "write slice from uint<3>");

    p5::uint<3> read_back = v[p5::bit_range<3, 1>];
    ok &= expect_eq(read_back.to_ullong(), slice_val.to_ullong(), "read slice as uint<3>");
    return ok;
}

bool test_slice_rw_int_and_truncate() {
    p5::uint<8> v = 0;

    // 写高半字节（bits 4..7）= 1101
    v[p5::bit_range<7, 4>] = 0b1101;
    bool ok = expect_eq(v.to_ullong(), 0b11010000, "write slice from int");

    // 将低 4 位写入一个更宽的切片，源宽度更窄，剩余位需清零
    p5::uint<2> narrow = 0b11;
    v[p5::bit_range<3, 0>] = narrow; // width=4, copy_width=2 -> bits 2,3 清零
    ok &= expect_eq(v.to_ullong(), 0b11010011, "write narrow into wider slice with zeroing");

    p5::uint<4> low4 = v[p5::bit_range<3, 0>];
    ok &= expect_eq(low4.to_ullong(), 0b0011, "read low nibble");
    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_single_bit_rw();
    all_ok &= test_slice_rw_uint();
    all_ok &= test_slice_rw_int_and_truncate();

    if (all_ok) {
        std::cout << "[PASS] uint slice/bit tests\n";
        return 0;
    }
    std::cerr << "[FAIL] uint slice/bit tests\n";
    return 1;
}

