#include <iostream>
#include <fstream>
#include "../../include/BuiltIn.hpp"
#include "../../generated/include/generated_struct.hpp"

// Simple test structs
struct SimpleStruct1 {
    p5::uint<8> field1;
};

struct SimpleStruct2 {
    p5::uint<8> field1;
    p5::uint<16> field2;
};

struct SimpleStruct3 {
    p5::uint<1> field1;
    p5::uint<2> field2;
    p5::uint<4> field3;
    p5::uint<8> field4;
};

struct NestedStruct {
    SimpleStruct1 inner;
    p5::uint<16> outer_field;
};

int main() {
    // Open log file
    std::ofstream log_file("sizeof_test.log");
    if (!log_file.is_open()) {
        std::cerr << "Error: Cannot open log file 'sizeof_test.log'\n";
        return 1;
    }

    BuiltInContext ctx{};  // Create context instance for member function tests

    log_file << "[sizeof test] start\n";
    bool all_pass = true;

    // Test all regular structs (non-member versions)
    struct TestCase {
        const char* name;
        size_t expected_bits;
        size_t actual_bits;
    };

    std::vector<TestCase> tests = {
        // p5::uint<N> types (basic types) - Global function
        {"p5::uint<1> (global)", 1, _sizeof(p5::uint<1>{})},
        {"p5::uint<4> (global)", 4, _sizeof(p5::uint<4>{})},
        {"p5::uint<8> (global)", 8, _sizeof(p5::uint<8>{})},
        {"p5::uint<16> (global)", 16, _sizeof(p5::uint<16>{})},
        {"p5::uint<32> (global)", 32, _sizeof(p5::uint<32>{})},
        {"p5::uint<48> (global)", 48, _sizeof(p5::uint<48>{})},
        {"p5::uint<64> (global)", 64, _sizeof(p5::uint<64>{})},
        {"p5::uint<128> (global)", 128, _sizeof(p5::uint<128>{})},
        {"p5::uint<160> (global)", 160, _sizeof(p5::uint<160>{})},
        {"p5::uint<256> (global)", 256, _sizeof(p5::uint<256>{})},

        // p5::uint<N> types (basic types) - Member function
        {"p5::uint<1> (member)", 1, ctx._sizeof(p5::uint<1>{})},
        {"p5::uint<4> (member)", 4, ctx._sizeof(p5::uint<4>{})},
        {"p5::uint<8> (member)", 8, ctx._sizeof(p5::uint<8>{})},
        {"p5::uint<16> (member)", 16, ctx._sizeof(p5::uint<16>{})},
        {"p5::uint<32> (member)", 32, ctx._sizeof(p5::uint<32>{})},

        // p5::member<T> types (wrapped types) - Global function
        {"p5::member<p5::uint<8>> (global)", 8, _sizeof(p5::member<p5::uint<8>>{})},
        {"p5::member<p5::uint<16>> (global)", 16, _sizeof(p5::member<p5::uint<16>>{})},
        {"p5::member<p5::uint<32>> (global)", 32, _sizeof(p5::member<p5::uint<32>>{})},
        {"p5::member<p5::uint<64>> (global)", 64, _sizeof(p5::member<p5::uint<64>>{})},

        // p5::member<T> types (wrapped types) - Member function
        {"p5::member<p5::uint<8>> (member)", 8, ctx._sizeof(p5::member<p5::uint<8>>{})},
        {"p5::member<p5::uint<16>> (member)", 16, ctx._sizeof(p5::member<p5::uint<16>>{})},

        // Simple custom structs for testing - Global function
        {"SimpleStruct1 (global)", 8, _sizeof(SimpleStruct1{})},
        {"SimpleStruct2 (global)", 24, _sizeof(SimpleStruct2{})},
        {"SimpleStruct3 (global)", 15, _sizeof(SimpleStruct3{})},
        {"NestedStruct (global)", 24, _sizeof(NestedStruct{})},

        // Simple custom structs for testing - Member function
        {"SimpleStruct1 (member)", 8, ctx._sizeof(SimpleStruct1{})},
        {"SimpleStruct2 (member)", 24, ctx._sizeof(SimpleStruct2{})},
        {"PHI_S (member)", 18, ctx._sizeof(PHI_S{})},

        // Basic structs
        {"PHI_S", 18, _sizeof(PHI_S{})},
        {"ETHER_TYPE_S", 16, _sizeof(ETHER_TYPE_S{})},
        {"ETHER_S", 112, _sizeof(ETHER_S{})},
        {"VlanInfo_S", 16, _sizeof(VlanInfo_S{})},
        {"VLAN_TAG_S", 48, _sizeof(VLAN_TAG_S{})},
        {"IPv4_S", 160, _sizeof(IPv4_S{})},
        {"IPv6_S", 320, _sizeof(IPv6_S{})},
        {"UDP_S", 64, _sizeof(UDP_S{})},
        {"FlagCtrl_S", 6, _sizeof(FlagCtrl_S{})},
        {"DataCtrl_S", 16, _sizeof(DataCtrl_S{})},
        {"TCP_S", 160, _sizeof(TCP_S{})},
        {"IpatCtrlInfo_S", 1, _sizeof(IpatCtrlInfo_S{})},
        {"IPATRSP_S", 27, _sizeof(IPATRSP_S{})},
        {"FIBRSP_S", 18, _sizeof(FIBRSP_S{})},
        {"FIBKEY_S", 136, _sizeof(FIBKEY_S{})},
        {"ENCAP_LOCAL_ADDR_S", 48, _sizeof(ENCAP_LOCAL_ADDR_S{})},
        {"EPATRSP_S", 80, _sizeof(EPATRSP_S{})},
        {"ENCAP_ARP_S", 48, _sizeof(ENCAP_ARP_S{})},
        {"ENCAPRSP_S", 80, _sizeof(ENCAPRSP_S{})},

        // Member versions (_inU_ prefixed)
        {"_inU_PHI_S", 18, _sizeof(_inU_PHI_S{})},
        {"_inU_ETHER_TYPE_S", 16, _sizeof(_inU_ETHER_TYPE_S{})},
        {"_inU_ETHER_S", 112, _sizeof(_inU_ETHER_S{})},
        {"_inU_VlanInfo_S", 16, _sizeof(_inU_VlanInfo_S{})},
        {"_inU_VLAN_TAG_S", 48, _sizeof(_inU_VLAN_TAG_S{})},
        {"_inU_IPv4_S", 160, _sizeof(_inU_IPv4_S{})},
        {"_inU_IPv6_S", 320, _sizeof(_inU_IPv6_S{})},
        {"_inU_UDP_S", 64, _sizeof(_inU_UDP_S{})},
        {"_inU_FlagCtrl_S", 6, _sizeof(_inU_FlagCtrl_S{})},
        {"_inU_DataCtrl_S", 16, _sizeof(_inU_DataCtrl_S{})},
        {"_inU_TCP_S", 160, _sizeof(_inU_TCP_S{})},
        {"_inU_IpatCtrlInfo_S", 1, _sizeof(_inU_IpatCtrlInfo_S{})},
        {"_inU_IPATRSP_S", 27, _sizeof(_inU_IPATRSP_S{})},
        {"_inU_FIBRSP_S", 18, _sizeof(_inU_FIBRSP_S{})},
        {"_inU_FIBKEY_S", 136, _sizeof(_inU_FIBKEY_S{})},
        {"_inU_ENCAP_LOCAL_ADDR_S", 48, _sizeof(_inU_ENCAP_LOCAL_ADDR_S{})},
        {"_inU_EPATRSP_S", 80, _sizeof(_inU_EPATRSP_S{})},
        {"_inU_ENCAP_ARP_S", 48, _sizeof(_inU_ENCAP_ARP_S{})},
        {"_inU_ENCAPRSP_S", 80, _sizeof(_inU_ENCAPRSP_S{})},
    };

    for (const auto& test : tests) {
        bool pass = (test.actual_bits == test.expected_bits);
        all_pass &= pass;

        std::string result = test.name + std::string(": ") + std::to_string(test.actual_bits) + " bits";
        if (pass) {
            result += " ✓\n";
        } else {
            result += " ✗ (expected " + std::to_string(test.expected_bits) + ")\n";
        }

        std::cout << result;
        log_file << result;
    }

    std::string final_result = "\n[sizeof test] " + std::string(all_pass ? "ALL PASS" : "FAILED") + "\n";
    std::cout << final_result;
    log_file << final_result;

    log_file.close();
    return all_pass ? 0 : 1;
}