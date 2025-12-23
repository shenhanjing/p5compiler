#include <iostream>
#include "../include/p5_types.hpp"

/**
 * Demo program: write the widest p5::uint<N> in a union and
 * read narrower members. This relies on undefined behavior;
 * the output merely shows what happens on this platform/build.
 */
int main() {
    union U {
        p5::uint<10> u10;
        p5::uint<9>  u9;
        p5::uint<8>  u8;
        struct {
            p5::uint<4>  u4;
            p5::uint<6>  u6;
        } u4_6;
    } u{};

    // 10-bit value: 0b1010'1100'11 = 691 decimal
    const p5::uint<10> value{0b1010110011};
    u.u10 = value; // activate the widest member

    const auto expect9 = p5::uint<9>(value.to_ullong() & ((1u << 9) - 1));
    const auto expect8 = p5::uint<8>(value.to_ullong() & ((1u << 8) - 1));
    const auto expect4 = p5::uint<4>(0b1010);
    const auto expect6 = p5::uint<6>(0b110011);

    std::cout << "write u10 = " << value.to_ullong() << "\n";
    std::cout << "read  u10 -> " << u.u10.to_ullong() << "\n";
    std::cout << "read  u9  -> " << u.u9.to_ullong()
              << " (expected trunc " << expect9.to_ullong() << ")\n";
    std::cout << "read  u8  -> " << u.u8.to_ullong()
              << " (expected trunc " << expect8.to_ullong() << ")\n";
    std::cout << "read  u4  -> " << u.u4_6.u4.to_ullong()
              << " (expected trunc " << expect4.to_ullong() << ")\n";
    std::cout << "read  u6  -> " << u.u4_6.u6.to_ullong()
              << " (expected trunc " << expect6.to_ullong() << ")\n";

    const bool same9 = (u.u9.to_ullong() == expect9.to_ullong());
    const bool same8 = (u.u8.to_ullong() == expect8.to_ullong());

    std::cout << "[note] Reading inactive union members is undefined behavior.\n";
    std::cout << "      On this run: u9 "
              << (same9 ? "matches" : "differs from")
              << " truncated value, u8 "
              << (same8 ? "matches" : "differs from")
              << " truncated value.\n";

    return 0;
}

