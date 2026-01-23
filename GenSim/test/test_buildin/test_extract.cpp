// _extract tests: test both fixed and variable length extract functions
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
    std::cout << "[_extract test] start\n";

    bool ok = true;

    // Test data: 20 bytes of test packet data
    const uint8_t test_data[20] = {
        0xAA, 0xBB, 0xCC, 0xDD,  // Bytes 0-3
        0xEE, 0xFF, 0x11, 0x22,  // Bytes 4-7
        0x33, 0x44, 0x55, 0x66,  // Bytes 8-11
        0x77, 0x88, 0x99, 0xAA,  // Bytes 12-15
        0xBB, 0xCC, 0xDD, 0xEE   // Bytes 16-19
    };

    Packet pkt;
    std::memcpy(pkt.data_.data(), test_data, sizeof(test_data));

    // Reset parsing position
    pkt.reset_offset();
    ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 0u, "initial offset");
    ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "initial bit_offset");

    // Test 1: Fixed length extract - extract 4 bytes (32 bits)
    {
        std::cout << "Testing fixed length _extract...\n";

        // Define a simple header structure (4 bytes = 32 bits)
        struct TestHeader {
            p5::uint<8> byte0;
            p5::uint<8> byte1;
            p5::uint<8> byte2;
            p5::uint<8> byte3;
        };

        TestHeader hdr;
        uint32_t new_offset = pkt._extract(hdr).to_ullong();

        // Verify extracted data
        ok &= expect_eq<uint64_t>(hdr.byte0.to_ullong(), 0xAAu, "extracted byte0");
        ok &= expect_eq<uint64_t>(hdr.byte1.to_ullong(), 0xBBu, "extracted byte1");
        ok &= expect_eq<uint64_t>(hdr.byte2.to_ullong(), 0xCCu, "extracted byte2");
        ok &= expect_eq<uint64_t>(hdr.byte3.to_ullong(), 0xDDu, "extracted byte3");

        // Verify position advanced correctly (4 bytes)
        ok &= expect_eq<uint32_t>(new_offset, 4u, "offset after fixed extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 4u, "current offset after fixed extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "bit_offset after fixed extract");
    }

    // Test 2: Variable length extract - extract 6 bytes (48 bits)
    {
        std::cout << "Testing variable length _extract...\n";

        // Define another header structure (2 bytes = 16 bits)
        struct VarHeader {
            p5::uint<8> byte0;
            p5::uint<8> byte1;
        };

        VarHeader hdr;
        // Extract 6 bytes (48 bits) of data into a 2-byte header
        uint32_t new_offset = pkt._extract(hdr, p5::uint<16>(48)).to_ullong();

        // Should extract first 2 bytes of the remaining 6 bytes
        ok &= expect_eq<uint64_t>(hdr.byte0.to_ullong(), 0xEEu, "var extracted byte0");
        ok &= expect_eq<uint64_t>(hdr.byte1.to_ullong(), 0xFFu, "var extracted byte1");

        // Position should advance by 6 bytes (48 bits), not 2 bytes
        ok &= expect_eq<uint32_t>(new_offset, 10u, "offset after variable extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 10u, "current offset after variable extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "bit_offset after variable extract");
    }

    // Test 3: Variable length extract with bit-level precision
    {
        std::cout << "Testing variable length _extract with bit precision...\n";

        // Reset to beginning for a fresh test
        pkt.reset_offset();

        // Extract 12 bits of data
        struct BitHeader {
            p5::uint<4> nibble0;
            p5::uint<4> nibble1;
            p5::uint<4> nibble2;
        };

        BitHeader hdr;
        // Extract 12 bits into a 12-bit header structure
        uint32_t new_offset = pkt._extract(hdr, p5::uint<16>(12)).to_ullong();

        // First byte is 0xAA = 1010 1010, second byte is 0xBB = 1011 1011
        // Should extract first 12 bits: 1010 1010 1011 -> nibble0=1010, nibble1=1010, nibble2=1011
        ok &= expect_eq<uint64_t>(hdr.nibble0.to_ullong(), 0xAu, "bit extracted nibble0");
        ok &= expect_eq<uint64_t>(hdr.nibble1.to_ullong(), 0xAu, "bit extracted nibble1");
        ok &= expect_eq<uint64_t>(hdr.nibble2.to_ullong(), 0xBu, "bit extracted nibble2");

        // Position should advance by 12 bits = 1.5 bytes, so offset=1, bit_offset=4
        ok &= expect_eq<uint32_t>(new_offset, 1u, "offset after bit extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 1u, "current offset after bit extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 4u, "bit_offset after bit extract");
    }

    // Test 4: Edge case - extract 0 bits
    {
        std::cout << "Testing edge case: extract 0 bits...\n";

        pkt.reset_offset();

        struct EmptyHeader {
            // Empty header
        };

        EmptyHeader hdr;
        uint32_t new_offset = pkt._extract(hdr, p5::uint<16>(0)).to_ullong();

        // Should not advance position
        ok &= expect_eq<uint32_t>(new_offset, 0u, "offset after 0-bit extract");
        ok &= expect_eq<uint64_t>(pkt.offset_.to_ullong(), 0u, "current offset after 0-bit extract");
        ok &= expect_eq<uint64_t>(pkt.bit_offset_.to_ullong(), 0u, "bit_offset after 0-bit extract");
    }

    std::cout << "[_extract test] " << (ok ? "PASSED" : "FAILED") << "\n";
    return ok ? 0 : 1;
}