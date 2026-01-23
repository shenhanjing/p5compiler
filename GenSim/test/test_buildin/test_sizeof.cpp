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
        {"p5::uint<1> (global)", 1, _sizeof<p5::uint<1>>().to_ullong()},
        {"p5::uint<4> (global)", 4, _sizeof<p5::uint<4>>().to_ullong()},
        {"p5::uint<8> (global)", 8, _sizeof<p5::uint<8>>().to_ullong()},
        {"p5::uint<16> (global)", 16, _sizeof<p5::uint<16>>().to_ullong()},
        {"p5::uint<32> (global)", 32, _sizeof<p5::uint<32>>().to_ullong()},
        {"p5::uint<48> (global)", 48, _sizeof<p5::uint<48>>().to_ullong()},
        {"p5::uint<64> (global)", 64, _sizeof<p5::uint<64>>().to_ullong()},
        {"p5::uint<128> (global)", 128, _sizeof<p5::uint<128>>().to_ullong()},
        {"p5::uint<160> (global)", 160, _sizeof<p5::uint<160>>().to_ullong()},
        {"p5::uint<256> (global)", 256, _sizeof<p5::uint<256>>().to_ullong()},

        // p5::uint<N> types (basic types) - Member function
        {"p5::uint<1> (member)", 1, ctx._sizeof<p5::uint<1>>().to_ullong()},
        {"p5::uint<4> (member)", 4, ctx._sizeof<p5::uint<4>>().to_ullong()},
        {"p5::uint<8> (member)", 8, ctx._sizeof<p5::uint<8>>().to_ullong()},
        {"p5::uint<16> (member)", 16, ctx._sizeof<p5::uint<16>>().to_ullong()},
        {"p5::uint<32> (member)", 32, ctx._sizeof<p5::uint<32>>().to_ullong()},

        // p5::member<T> types (wrapped types) - Global function
        {"p5::member<p5::uint<8>> (global)", 8, _sizeof<p5::member<p5::uint<8>>>().to_ullong()},
        {"p5::member<p5::uint<16>> (global)", 16, _sizeof<p5::member<p5::uint<16>>>().to_ullong()},
        {"p5::member<p5::uint<32>> (global)", 32, _sizeof<p5::member<p5::uint<32>>>().to_ullong()},
        {"p5::member<p5::uint<64>> (global)", 64, _sizeof<p5::member<p5::uint<64>>>().to_ullong()},

        // p5::member<T> types (wrapped types) - Member function
        {"p5::member<p5::uint<8>> (member)", 8, ctx._sizeof<p5::member<p5::uint<8>>>().to_ullong()},
        {"p5::member<p5::uint<16>> (member)", 16, ctx._sizeof<p5::member<p5::uint<16>>>().to_ullong()},

        // Simple custom structs for testing - Global function
        {"SimpleStruct1 (global)", 8, _sizeof<SimpleStruct1>().to_ullong()},
        {"SimpleStruct2 (global)", 24, _sizeof<SimpleStruct2>().to_ullong()},
        {"SimpleStruct3 (global)", 15, _sizeof<SimpleStruct3>().to_ullong()},
        {"NestedStruct (global)", 24, _sizeof<NestedStruct>().to_ullong()},

        // Simple custom structs for testing - Member function
        {"SimpleStruct1 (member)", 8, ctx._sizeof<SimpleStruct1>().to_ullong()},
        {"SimpleStruct2 (member)", 24, ctx._sizeof<SimpleStruct2>().to_ullong()},
        {"PHI_S (member)", 18, ctx._sizeof<PHI_S>().to_ullong()},

        // Basic structs
        {"PHI_S", 18, _sizeof<PHI_S>().to_ullong()},
        {"ETHER_TYPE_S", 16, _sizeof<ETHER_TYPE_S>().to_ullong()},
        {"ETHER_S", 112, _sizeof<ETHER_S>().to_ullong()},
        {"VlanInfo_S", 16, _sizeof<VlanInfo_S>().to_ullong()},
        {"VLAN_TAG_S", 48, _sizeof<VLAN_TAG_S>().to_ullong()},
        {"IPv4_S", 160, _sizeof<IPv4_S>().to_ullong()},
        {"IPv6_S", 320, _sizeof<IPv6_S>().to_ullong()},
        {"UDP_S", 64, _sizeof<UDP_S>().to_ullong()},
        {"FlagCtrl_S", 6, _sizeof<FlagCtrl_S>().to_ullong()},
        {"DataCtrl_S", 16, _sizeof<DataCtrl_S>().to_ullong()},
        {"TCP_S", 160, _sizeof<TCP_S>().to_ullong()},
        {"IpatCtrlInfo_S", 1, _sizeof<IpatCtrlInfo_S>().to_ullong()},
        {"IPATRSP_S", 27, _sizeof<IPATRSP_S>().to_ullong()},
        {"FIBRSP_S", 18, _sizeof<FIBRSP_S>().to_ullong()},
        {"FIBKEY_S", 136, _sizeof<FIBKEY_S>().to_ullong()},
        {"ENCAP_LOCAL_ADDR_S", 48, _sizeof<ENCAP_LOCAL_ADDR_S>().to_ullong()},
        {"EPATRSP_S", 80, _sizeof<EPATRSP_S>().to_ullong()},
        {"ENCAP_ARP_S", 48, _sizeof<ENCAP_ARP_S>().to_ullong()},
        {"ENCAPRSP_S", 80, _sizeof<ENCAPRSP_S>().to_ullong()},

        // Member versions (_inU_ prefixed)
        {"_inU_PHI_S", 18, _sizeof<_inU_PHI_S>().to_ullong()},
        {"_inU_ETHER_TYPE_S", 16, _sizeof<_inU_ETHER_TYPE_S>().to_ullong()},
        {"_inU_ETHER_S", 112, _sizeof<_inU_ETHER_S>().to_ullong()},
        {"_inU_VlanInfo_S", 16, _sizeof<_inU_VlanInfo_S>().to_ullong()},
        {"_inU_VLAN_TAG_S", 48, _sizeof<_inU_VLAN_TAG_S>().to_ullong()},
        {"_inU_IPv4_S", 160, _sizeof<_inU_IPv4_S>().to_ullong()},
        {"_inU_IPv6_S", 320, _sizeof<_inU_IPv6_S>().to_ullong()},
        {"_inU_UDP_S", 64, _sizeof<_inU_UDP_S>().to_ullong()},
        {"_inU_FlagCtrl_S", 6, _sizeof<_inU_FlagCtrl_S>().to_ullong()},
        {"_inU_DataCtrl_S", 16, _sizeof<_inU_DataCtrl_S>().to_ullong()},
        {"_inU_TCP_S", 160, _sizeof<_inU_TCP_S>().to_ullong()},
        {"_inU_IpatCtrlInfo_S", 1, _sizeof<_inU_IpatCtrlInfo_S>().to_ullong()},
        {"_inU_IPATRSP_S", 27, _sizeof<_inU_IPATRSP_S>().to_ullong()},
        {"_inU_FIBRSP_S", 18, _sizeof<_inU_FIBRSP_S>().to_ullong()},
        {"_inU_FIBKEY_S", 136, _sizeof<_inU_FIBKEY_S>().to_ullong()},
        {"_inU_ENCAP_LOCAL_ADDR_S", 48, _sizeof<_inU_ENCAP_LOCAL_ADDR_S>().to_ullong()},
        {"_inU_EPATRSP_S", 80, _sizeof<_inU_EPATRSP_S>().to_ullong()},
        {"_inU_ENCAP_ARP_S", 48, _sizeof<_inU_ENCAP_ARP_S>().to_ullong()},
        {"_inU_ENCAPRSP_S", 80, _sizeof<_inU_ENCAPRSP_S>().to_ullong()},
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