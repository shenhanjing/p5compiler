// 手写测试：验证全局 ClearFields(...) 能对不同类型参数递归清零。
//
// 覆盖范围：
// - p5::uint / p5::member / p5::Union
// - uint/member 的切片（slice_proxy），通过 `auto s = x[bit_range]` 形式传入
// - 标准 C 数组 / std::array / std::vector
// - 由上述类型组成的聚合结构体（boost::pfr 遍历字段递归清零）
//
// 编译建议：
//   g++ -std=c++17 -I ../include test_clear_fields.cpp -o test_clear_fields
//
#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <type_traits>

#include "BuiltIn.hpp"

namespace {

bool expect_true(bool cond, const char *msg) {
    if (cond) return true;
    std::cerr << "[FAIL] " << msg << "\n";
    return false;
}

bool expect_eq_u64(std::uint64_t got, std::uint64_t expect, const char *msg) {
    if (got == expect) return true;
    std::cerr << "[FAIL] " << msg << " got=" << got << " expect=" << expect << "\n";
    return false;
}

struct WordLayout {
    p5::member<p5::uint<16>> word;
};

struct SmallUnionLayout {
    p5::member<p5::uint<8>> a;
    p5::member<p5::uint<4>> b;
};

struct Agg {
    p5::uint<8> x;
    p5::uint<8> y;
    std::vector<p5::uint<4>> v;
    std::array<p5::uint<2>, 3> aa;
    p5::Union<WordLayout> un;
};

static_assert(std::is_aggregate_v<Agg>, "Agg should be an aggregate for boost::pfr traversal");

bool test_uint_and_uint_slice() {
    bool ok = true;

    p5::uint<16> u = 0;
    u = 0xABCD;
    ok &= expect_eq_u64(u.to_ullong(), 0xABCD, "uint setup");

    // slice_proxy is returned by value; ClearFields supports passing it directly.
    ClearFields(u[p5::bit_range<7, 0>]);
    ok &= expect_eq_u64(u.to_ullong(), 0xAB00, "ClearFields(uint slice) clears low 8 bits");

    ClearFields(u);
    ok &= expect_eq_u64(u.to_ullong(), 0, "ClearFields(uint) clears all bits");
    return ok;
}

bool test_member_and_member_slice() {
    bool ok = true;

    p5::Union<WordLayout> un{};
    un.word = 0xBEEF;
    ok &= expect_eq_u64(p5::uint<16>(un.word).to_ullong(), 0xBEEF, "member setup");

    ClearFields(un.word[p5::bit_range<7, 0>]);
    ok &= expect_eq_u64(p5::uint<16>(un.word).to_ullong(), 0xBE00, "ClearFields(member slice) clears low 8 bits");

    ClearFields(un.word);
    ok &= expect_eq_u64(p5::uint<16>(un.word).to_ullong(), 0, "ClearFields(member) clears member bits");
    return ok;
}

bool test_union_and_nested_fields() {
    bool ok = true;

    p5::Union<SmallUnionLayout> u{};
    u = 0xFF; // sets raw storage bits
    ok &= expect_true(u.to_ullong() != 0, "union setup nonzero");

    // Also validate clearing via overlay members.
    u.a = 0xAA;
    u.b = 0xF;
    ok &= expect_true(u.to_ullong() != 0, "union members set nonzero");

    ClearFields(u);
    ok &= expect_eq_u64(u.to_ullong(), 0, "ClearFields(Union) clears raw storage");
    ok &= expect_eq_u64(p5::uint<8>(u.a).to_ullong(), 0, "Union member view cleared (a)");
    ok &= expect_eq_u64(p5::uint<4>(u.b).to_ullong(), 0, "Union member view cleared (b)");
    return ok;
}

bool test_c_array_std_array_vector_and_aggregate() {
    bool ok = true;

    // --- Standard C array ---
    p5::uint<4> carr[3] = {1, 2, 3};
    ClearFields(carr);
    ok &= expect_eq_u64(carr[0].to_ullong(), 0, "ClearFields(C array) element0");
    ok &= expect_eq_u64(carr[1].to_ullong(), 0, "ClearFields(C array) element1");
    ok &= expect_eq_u64(carr[2].to_ullong(), 0, "ClearFields(C array) element2");

    // --- std::array ---
    std::array<p5::uint<2>, 3> aa{p5::uint<2>(1), p5::uint<2>(2), p5::uint<2>(3)};
    ClearFields(aa);
    ok &= expect_eq_u64(aa[0].to_ullong(), 0, "ClearFields(std::array) element0");
    ok &= expect_eq_u64(aa[1].to_ullong(), 0, "ClearFields(std::array) element1");
    ok &= expect_eq_u64(aa[2].to_ullong(), 0, "ClearFields(std::array) element2");

    // --- std::vector ---
    std::vector<p5::uint<8>> vv{p5::uint<8>(0x12), p5::uint<8>(0x34)};
    ClearFields(vv);
    ok &= expect_eq_u64(vv.size(), 2, "ClearFields(vector) keeps size");
    ok &= expect_eq_u64(vv[0].to_ullong(), 0, "ClearFields(vector) element0");
    ok &= expect_eq_u64(vv[1].to_ullong(), 0, "ClearFields(vector) element1");

    // --- Aggregate struct containing vector/array/union ---
    Agg a{};
    a.x = 0x11;
    a.y = 0x22;
    a.v = {p5::uint<4>(1), p5::uint<4>(2), p5::uint<4>(3)};
    a.aa = {p5::uint<2>(1), p5::uint<2>(2), p5::uint<2>(3)};
    a.un.word = 0x1234;

    ClearFields(a);
    ok &= expect_eq_u64(a.x.to_ullong(), 0, "ClearFields(aggregate) clears x");
    ok &= expect_eq_u64(a.y.to_ullong(), 0, "ClearFields(aggregate) clears y");
    ok &= expect_eq_u64(a.v.size(), 3, "ClearFields(aggregate) keeps vector size");
    ok &= expect_eq_u64(a.v[0].to_ullong(), 0, "ClearFields(aggregate) clears vector element0");
    ok &= expect_eq_u64(a.v[1].to_ullong(), 0, "ClearFields(aggregate) clears vector element1");
    ok &= expect_eq_u64(a.v[2].to_ullong(), 0, "ClearFields(aggregate) clears vector element2");
    ok &= expect_eq_u64(a.aa[0].to_ullong(), 0, "ClearFields(aggregate) clears array element0");
    ok &= expect_eq_u64(a.aa[1].to_ullong(), 0, "ClearFields(aggregate) clears array element1");
    ok &= expect_eq_u64(a.aa[2].to_ullong(), 0, "ClearFields(aggregate) clears array element2");
    ok &= expect_eq_u64(p5::uint<16>(a.un.word).to_ullong(), 0, "ClearFields(aggregate) clears nested union/member");

    // --- Mixed multi-arg call ---
    p5::uint<8> u8 = 0xAB;
    p5::Union<WordLayout> un2{};
    un2.word = 0xBEEF;
    std::vector<p5::uint<4>> v4{p5::uint<4>(7)};
    ClearFields(u8, un2, v4);
    ok &= expect_eq_u64(u8.to_ullong(), 0, "ClearFields(multi-arg) clears u8");
    ok &= expect_eq_u64(p5::uint<16>(un2.word).to_ullong(), 0, "ClearFields(multi-arg) clears union member");
    ok &= expect_eq_u64(v4[0].to_ullong(), 0, "ClearFields(multi-arg) clears vector element");

    return ok;
}

bool test_valid_proxy() {
    bool ok = true;

    BuiltInContext ctx;
    int x = 123;

    // Set valid bit to 1 then clear it via ClearFields on the proxy.
    ctx._valid(x) = true;
    ok &= expect_true(static_cast<bool>(ctx._valid(x)) == true, "_valid(x) precondition true");

    // Pass the proxy expression directly (temporary).
    ClearFields(ctx._valid(x));
    ok &= expect_true(static_cast<bool>(ctx._valid(x)) == false, "ClearFields(_valid(x)) clears valid bit");

    return ok;
}

struct PlainAgg {
    int x;
    std::uint32_t y;
};

bool test_inflate_valid_overloads() {
    bool ok = true;

    BuiltInContext ctx;

    // Default: valid=false
    _inflate<PlainAgg> iv;
    ok &= expect_true(ctx._valid(static_cast<const _inflate<PlainAgg> &>(iv)) == false,
                      "_valid(const _inflate<T>&) reads default valid=false");

    // Assignment from T sets valid=true
    iv = PlainAgg{7, 8};
    ok &= expect_true(ctx._valid(static_cast<const _inflate<PlainAgg> &>(iv)) == true,
                      "_inflate assignment sets valid=true");

    // Writable overload returns bool&, can clear directly.
    ctx._valid(iv) = false;
    ok &= expect_true(ctx._valid(static_cast<const _inflate<PlainAgg> &>(iv)) == false,
                      "_valid(_inflate<T>&) allows clearing valid=false");

    // Set true again, then clear via ClearFields on the lvalue bool&.
    ctx._valid(iv) = true;
    ClearFields(ctx._valid(iv));
    ok &= expect_true(ctx._valid(static_cast<const _inflate<PlainAgg> &>(iv)) == false,
                      "ClearFields(_valid(_inflate<T>&)) clears valid=false");

    // Also support clearing the whole inflate wrapper (value reset + valid=false).
    iv = PlainAgg{1, 2};
    ok &= expect_true(ctx._valid(static_cast<const _inflate<PlainAgg> &>(iv)) == true, "precondition true before ClearFields(iv)");
    ClearFields(iv);
    ok &= expect_true(ctx._valid(static_cast<const _inflate<PlainAgg> &>(iv)) == false, "ClearFields(_inflate<T>) resets valid=false");

    return ok;
}

} // namespace

int main() {
    std::cout << "[test_clear_fields] start\n";
    bool ok = true;

    ok &= test_uint_and_uint_slice();
    ok &= test_member_and_member_slice();
    ok &= test_union_and_nested_fields();
    ok &= test_c_array_std_array_vector_and_aggregate();
    ok &= test_valid_proxy();
    ok &= test_inflate_valid_overloads();

    std::cout << "[test_clear_fields] " << (ok ? "PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}

