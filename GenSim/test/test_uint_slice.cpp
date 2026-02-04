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

    // 复合赋值：直接对切片 +=
    v[p5::bit_range<3, 1>] += 1; // 0b101 + 1 = 0b110
    ok &= expect_eq(v.to_ullong(), 0b00001100, "slice +=");

    // 自增：++slice
    ++v[p5::bit_range<3, 1>]; // 0b110 -> 0b111
    ok &= expect_eq(v.to_ullong(), 0b00001110, "++slice");

    // 位运算复合赋值：slice &= 0b011
    v[p5::bit_range<3, 1>] &= 0b011; // 0b111 & 0b011 = 0b011
    ok &= expect_eq(v.to_ullong(), 0b00000110, "slice &=");

    // 切片内 bit 访问与修改：把该切片的最高位(相对 pos=2) 置 1
    v[p5::bit_range<3, 1>][2] = 1; // slice[2] == abs bit 3
    ok &= expect_eq(v.to_ullong(), 0b00001110, "slice bit write");

    // 二级切片：对 [3:1] 再取 [1:0]（相对），应对应原始的 bits[2:1]
    p5::uint<2> sub = v[p5::bit_range<3, 1>][p5::bit_range<1, 0>];
    ok &= expect_eq(sub.to_ullong(), 0b11, "nested slice read");

    // ---- comparisons (should work via implicit conversion to uint<width>) ----
    ok &= (v[p5::bit_range<3, 1>] == p5::uint<3>(0b111));
    ok &= (v[p5::bit_range<3, 1>] != p5::uint<3>(0b000));
    ok &= (v[p5::bit_range<3, 1>] == 0b111);
    ok &= (0b111 == v[p5::bit_range<3, 1>]);
    ok &= (v[p5::bit_range<3, 1>] > 0b001);
    ok &= (v[p5::bit_range<3, 1>] >= 0b111);
    ok &= (v[p5::bit_range<3, 1>] < 0b1000);

    // slice vs slice
    ok &= (v[p5::bit_range<3, 1>] == v[p5::bit_range<3, 1>]);
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

void set_u8(p5::uint_ref<8> x, uint8_t v) { x = v; }
void set_lsb(p5::uint_ref<8> x) { x[0] = true; }

struct RefLayout {
    p5::member<p5::uint<16>> word;
};

bool test_uint_ref_accepts_slices() {
    bool ok = true;

    // ---- slice of p5::uint ----
    p5::uint<16> u = 0;
    set_u8(u[p5::bit_range<7, 0>], 0xA4);
    set_lsb(u[p5::bit_range<7, 0>]); // -> 0xA5
    ok &= expect_eq(u.to_ullong(), 0x00A5, "uint_ref accepts uint slice_proxy and writes back");

    // ---- slice of p5::member ----
    p5::Union<RefLayout> un{};
    un.word = p5::uint<16>(0);
    set_u8(un.word[p5::bit_range<7, 0>], 0x5A);
    set_lsb(un.word[p5::bit_range<7, 0>]); // -> 0x5B
    ok &= expect_eq(p5::uint<16>(un.word).to_ullong(), 0x005B, "uint_ref accepts member slice_proxy and writes back");

    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_single_bit_rw();
    all_ok &= test_slice_rw_uint();
    all_ok &= test_slice_rw_int_and_truncate();
    all_ok &= test_uint_ref_accepts_slices();

    if (all_ok) {
        std::cout << "[PASS] uint slice/bit tests\n";
        return 0;
    }
    std::cerr << "[FAIL] uint slice/bit tests\n";
    return 1;
}

