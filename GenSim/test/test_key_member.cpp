#include <iostream>

#include "../include/key.hpp"
#include "../include/p5_types.hpp"

namespace {

bool expect_eq(uint64_t got, uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

struct Parts {
    p5::member<p5::uint<3>> a; // bits0..2
    p5::member<p5::uint<5>> b; // bits3..7 (within struct sequential packing)
};

struct Layout {
    Parts st;
};

bool test_buildKey_with_member_parts() {
    KeyManager km;
    km.initKey({8});

    p5::Union<Layout> u{};
    u.st.a = 0b101;    // 3 bits
    u.st.b = 0b11001;  // 5 bits

    // buildKey appends bits high-first per part, in argument order:
    // key = (a << 5) | b
    km.buildKey(u.st.a, u.st.b);
    auto key = km.getKey<p5::uint<8>>(8);

    bool ok = true;
    ok &= expect_eq(key.to_ullong(), ((0b101ULL << 5) | 0b11001ULL), "buildKey(member, member)");
    return ok;
}

} // namespace

int main() {
    bool all_ok = true;
    all_ok &= test_buildKey_with_member_parts();

    if (all_ok) {
        std::cout << "[PASS] key buildKey(member) tests\n";
        return 0;
    }
    std::cerr << "[FAIL] key buildKey(member) tests\n";
    return 1;
}


