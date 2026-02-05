#include <cstdint>
#include <iostream>
#
#include "../include/p5_types.hpp"
#
namespace {
#
template <std::size_t N>
bool expect_eq_u(const p5::uint<N> &got, const p5::uint<N> &expect, const char *msg) {
    if (got == expect) return true;
    std::size_t first = N;
    for (std::size_t i = 0; i < N; ++i) {
        if (got[i] != expect[i]) {
            first = i;
            break;
        }
    }
    std::cerr << "[FAIL] " << msg << " first_diff_bit=" << first
              << " got_low64=0x" << std::hex << got.to_ullong()
              << " expect_low64=0x" << expect.to_ullong()
              << std::dec << "\n";
    return false;
}
#
bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}
#
template <std::size_t N>
p5::uint<N> one_at(std::size_t pos) {
    p5::uint<N> x = 0;
    if (pos < N) x[pos] = true;
    return x;
}
#
bool test_u128_add_sub_carry_across_64() {
    bool ok = true;
#
    // Carry from bit 63 to bit 64
    p5::uint<128> a = 0;
    a[63] = true;
    p5::uint<128> b = 0;
    b[63] = true;
    p5::uint<128> sum = a + b;
#
    p5::uint<128> expect = 0;
    expect[64] = true;
    ok &= expect_eq_u(sum, expect, "u128 add carry 63->64");
#
    // Borrow across 64 boundary: (1<<64) - 1 == low 64 bits all ones
    p5::uint<128> c = 0;
    c[64] = true;
    p5::uint<128> d = 1;
    p5::uint<128> diff = c - d;
    p5::uint<128> expect_diff = 0;
    for (std::size_t i = 0; i < 64; ++i) expect_diff[i] = true;
    ok &= expect_eq_u(diff, expect_diff, "u128 sub borrow 64");
#
    return ok;
}
#
bool test_u128_mul_shiftadd() {
    bool ok = true;
#
    // (3 * 2^100) == 2^100 + 2^101
    p5::uint<128> three = 3;
    p5::uint<128> two100 = one_at<128>(100);
    p5::uint<128> prod = three * two100;
#
    p5::uint<128> expect = 0;
    expect[100] = true;
    expect[101] = true;
    ok &= expect_eq_u(prod, expect, "u128 mul (3 * 2^100)");
    return ok;
}
#
bool test_u128_div_mod_pow2() {
    bool ok = true;
#
    // denom = 2^80. For num = 2^120 + 2^80 + 5:
    // q = 2^40 + 1, r = 5
    p5::uint<128> denom = one_at<128>(80);
    p5::uint<128> num = one_at<128>(120) | one_at<128>(80);
    num += 5;
#
    p5::uint<128> q = num / denom;
    p5::uint<128> r = num % denom;
#
    p5::uint<128> expect_q = one_at<128>(40);
    expect_q += 1;
    p5::uint<128> expect_r = 5;
#
    ok &= expect_eq_u(q, expect_q, "u128 div by pow2");
    ok &= expect_eq_u(r, expect_r, "u128 mod by pow2");
#
    // Invariant: q*denom + r == num and r < denom
    ok &= expect_eq_u(q * denom + r, num, "u128 div/mod invariant");
    ok &= expect_true(r < denom, "u128 remainder < denom");
#
    return ok;
}
#
bool test_u128_compare_uint64_semantics() {
    bool ok = true;
#
    // Matches the slice test expectation: do not truncate RHS integer.
    ok &= expect_true(p5::uint<3>(0b111) < 0b1000, "u3 < 8 (no truncation)");
    ok &= expect_true(!(p5::uint<3>(0b111) > 0b1000), "u3 not > 8");
#
    ok &= expect_true(p5::uint<8>(255) < 256, "u8 < 256");
    ok &= expect_true(!(p5::uint<8>(255) == 256), "u8 != 256");
#
    // N >= 64: values can exceed uint64_t range.
    p5::uint<128> big = 0;
    big[100] = true;
    ok &= expect_true(big > 0xFFFFFFFFFFFFFFFFULL, "u128 > UINT64_MAX");
    ok &= expect_true(!(big == 0ULL), "u128 with high bits != 0ULL");
    ok &= expect_true(big != 0ULL, "u128 != 0ULL");
    ok &= expect_true(!(big <= 0xFFFFFFFFFFFFFFFFULL), "u128 not <= UINT64_MAX");
    ok &= expect_true(big >= 0xFFFFFFFFFFFFFFFFULL, "u128 >= UINT64_MAX");
#
    return ok;
}

bool test_max_and_wraparound() {
    bool ok = true;
#
    auto m128 = p5::uint<128>::max();
    auto z128 = p5::uint<128>(0);
    ok &= expect_true((m128 + 1) == z128, "u128 max + 1 wraps to 0");
#
    auto m256 = p5::uint<256>::max();
    auto z256 = p5::uint<256>(0);
    ok &= expect_true((m256 + 1) == z256, "u256 max + 1 wraps to 0");
#
    return ok;
}

bool test_from_bits_and_slices_across_64() {
    bool ok = true;
#
    std::vector<bool> bits = {1,0,1,1,  1,1,0,0,  0,0,1,1}; // 0b1011'1100'0011 == 0xBC3
    auto u12 = p5::uint<12>::from_bits(bits);
    ok &= expect_true(u12.to_ullong() == 0xBC3, "from_bits MSB-first into uint<12>");
#
    p5::uint<128> w = 0;
    w[p5::bit_range<70, 59>] = u12;
    auto read_back = w[p5::bit_range<70, 59>];
    ok &= expect_true(read_back == u12, "slice across 64 boundary write/read");
#
    p5::uint<4> low4 = w[p5::bit_range<70, 59>][p5::bit_range<3, 0>];
    ok &= expect_true(low4 == p5::uint<4>(0x3), "nested slice across 64 boundary");
#
    return ok;
}

bool test_u256_div_mod_non_pow2() {
    bool ok = true;
#
    // denom = 2^130 + 2^7 + 3 (not a power of two)
    p5::uint<256> denom = 0;
    denom[130] = true;
    denom[7] = true;
    denom += 3;
#
    // num = denom * (2^20 + 5) + 0x12345
    p5::uint<256> factor = 0;
    factor[20] = true;
    factor += 5;
    p5::uint<256> num = denom * factor;
    num += 0x12345;
#
    p5::uint<256> q = num / denom;
    p5::uint<256> r = num % denom;
#
    ok &= expect_true(q == factor, "u256 div non-pow2 quotient");
    ok &= expect_true(r == p5::uint<256>(0x12345), "u256 div non-pow2 remainder");
    ok &= expect_true(r < denom, "u256 remainder < denom");
    ok &= expect_true(q * denom + r == num, "u256 div/mod invariant");
#
    return ok;
}
#
bool test_cross_width_copy_truncate_zeroextend() {
    bool ok = true;
#
    p5::uint<256> u256 = 0;
    u256[5] = true;
    u256[200] = true; // should be truncated when copying to u128
#
    p5::uint<128> u128(u256);
    p5::uint<128> expect128 = 0;
    expect128[5] = true;
    ok &= expect_eq_u(u128, expect128, "u128(u256) truncates high bits");
#
    p5::uint<256> back(u128);
    ok &= expect_true(back[5] == true, "u256(u128) keeps low bits");
    ok &= expect_true(back[200] == false, "u256(u128) zero-extends high bits");
#
    return ok;
}
#
void set_u16(p5::uint_ref<16> x, uint16_t v) { x = v; }
#
struct WideLayout {
    p5::member<p5::uint<128>> word;
};
#
bool test_slices_and_uint_ref_on_wide() {
    bool ok = true;
#
    // Slice of uint<128>
    p5::uint<128> u = 0;
    set_u16(u[p5::bit_range<95, 80>], 0xBEEF);
    p5::uint<16> got = u[p5::bit_range<95, 80>];
    ok &= expect_true(got == p5::uint<16>(0xBEEF), "uint_ref writes back into uint<128> slice");
#
    // Slice of member<uint<128>> inside Union
    p5::Union<WideLayout> un{};
    un.word = p5::uint<128>(0);
    set_u16(un.word[p5::bit_range<95, 80>], 0x1234);
    p5::uint<16> got2 = un.word[p5::bit_range<95, 80>];
    ok &= expect_true(got2 == p5::uint<16>(0x1234), "uint_ref writes back into member<uint<128>> slice");
#
    // Nested slice on a wider type (uint<256>), then take a sub-slice.
    p5::uint<256> w = 0;
    w[p5::bit_range<140, 129>] = p5::uint<12>(0xABC);
    p5::uint<12> read12 = w[p5::bit_range<140, 129>];
    ok &= expect_true(read12 == p5::uint<12>(0xABC), "u256 wide slice write/read");
#
    // Now take lower 4 bits of that slice: 0xC
    p5::uint<4> low4 = w[p5::bit_range<140, 129>][p5::bit_range<3, 0>];
    ok &= expect_true(low4 == p5::uint<4>(0xC), "u256 nested slice on wide field");
#
    return ok;
}
#
} // namespace
#
int main() {
    bool all_ok = true;
    all_ok &= test_u128_add_sub_carry_across_64();
    all_ok &= test_u128_mul_shiftadd();
    all_ok &= test_u128_div_mod_pow2();
    all_ok &= test_u128_compare_uint64_semantics();
    all_ok &= test_max_and_wraparound();
    all_ok &= test_from_bits_and_slices_across_64();
    all_ok &= test_u256_div_mod_non_pow2();
    all_ok &= test_cross_width_copy_truncate_zeroextend();
    all_ok &= test_slices_and_uint_ref_on_wide();
#
    if (all_ok) {
        std::cout << "[PASS] high-width uint tests\n";
        return 0;
    }
    std::cerr << "[FAIL] high-width uint tests\n";
    return 1;
}

