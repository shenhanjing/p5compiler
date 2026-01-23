// _anchor tests: test the anchor function for current parsing offset
#include <iostream>
#include <cstring>

#include "../../include/packet.hpp"

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
    std::cout << "[_anchor test] start\n";

    bool ok = true;

    // Test data: some test packet data
    const uint8_t test_data[32] = {
        0xAA, 0xBB, 0xCC, 0xDD,  // Bytes 0-3
        0xEE, 0xFF, 0x11, 0x22,  // Bytes 4-7
        0x33, 0x44, 0x55, 0x66,  // Bytes 8-11
        0x77, 0x88, 0x99, 0xAA,  // Bytes 12-15
        0xBB, 0xCC, 0xDD, 0xEE,  // Bytes 16-19
        0xFF, 0x00, 0x11, 0x22,  // Bytes 20-23
        0x33, 0x44, 0x55, 0x66   // Bytes 24-27
    };

    Packet pkt;
    std::memcpy(pkt.data_.data(), test_data, sizeof(test_data));

    // Reset parsing position
    pkt.reset_offset();

    // Test 1: Initial anchor position
    {
        std::cout << "Testing initial anchor position...\n";

        auto anchor_pos = pkt._anchor();
        ok &= expect_eq<uint64_t>(anchor_pos.to_ullong(), 0u, "initial anchor position");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 0u, "initial offset");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "initial bit_offset");
    }

    // Test 2: Anchor after fixed length extract
    {
        std::cout << "Testing anchor after fixed length extract...\n";

        // Define a simple header structure (4 bytes = 32 bits)
        struct TestHeader {
            p5::uint<8> byte0;
            p5::uint<8> byte1;
            p5::uint<8> byte2;
            p5::uint<8> byte3;
        };

        TestHeader hdr;
        pkt._extract(hdr);  // Extract 4 bytes (32 bits)

        auto anchor_pos = pkt._anchor();
        ok &= expect_eq<uint64_t>(anchor_pos.to_ullong(), 32u, "anchor after 4-byte extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 4u, "offset after 4-byte extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "bit_offset after 4-byte extract");
    }

    // Test 3: Anchor after variable length extract
    {
        std::cout << "Testing anchor after variable length extract...\n";

        // Extract 6 more bytes (48 bits) with variable length
        struct VarHeader {
            p5::uint<8> byte0;
            p5::uint<8> byte1;
        };

        VarHeader hdr;
        pkt._extract(hdr, p5::uint<16>(48));  // Extract 48 bits (6 bytes)

        auto anchor_pos = pkt._anchor();
        ok &= expect_eq<uint64_t>(anchor_pos.to_ullong(), 80u, "anchor after 6-byte variable extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 10u, "offset after 6-byte variable extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "bit_offset after 6-byte variable extract");
    }

    // Test 4: Anchor with bit-level precision
    {
        std::cout << "Testing anchor with bit-level precision...\n";

        // Reset to test bit-level operations
        pkt.reset_offset();

        // Extract 12 bits
        struct BitHeader {
            p5::uint<4> nibble0;
            p5::uint<4> nibble1;
            p5::uint<4> nibble2;
        };

        BitHeader hdr;
        pkt._extract(hdr, p5::uint<16>(12));  // Extract 12 bits

        auto anchor_pos = pkt._anchor();
        ok &= expect_eq<uint64_t>(anchor_pos.to_ullong(), 12u, "anchor after 12-bit extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 1u, "offset after 12-bit extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 4u, "bit_offset after 12-bit extract");
    }

    // Test 5: Multiple anchor calls consistency
    {
        std::cout << "Testing multiple anchor calls consistency...\n";

        auto anchor1 = pkt._anchor();
        auto anchor2 = pkt._anchor();

        ok &= expect_eq<uint64_t>(anchor1.to_ullong(), anchor2.to_ullong(), "anchor calls consistency");
    }

    // Test 6: Anchor after advance operation
    {
        std::cout << "Testing anchor after manual advance...\n";

        pkt.reset_offset();
        pkt._advance(p5::uint<16>(24));  // Advance 24 bits (3 bytes)

        auto anchor_pos = pkt._anchor();
        ok &= expect_eq<uint64_t>(anchor_pos.to_ullong(), 24u, "anchor after 24-bit advance");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 3u, "offset after 24-bit advance");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "bit_offset after 24-bit advance");
    }

    std::cout << "[_anchor test] " << (ok ? "PASSED" : "FAILED") << "\n";
    return ok ? 0 : 1;
}