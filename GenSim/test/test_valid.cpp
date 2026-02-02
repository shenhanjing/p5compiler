// 手写测试：验证 BuiltInContext::_valid 的两套语义：
// 1) _valid(const _inflate<T>&) -> bool：读取 _inflate<T>::valid
// 2) _valid(any T&) / _valid(const T&) -> ValidProxy：基于“变量地址->valid”的字典
//    - 首次访问：若地址不在字典中，插入并默认 valid=false(0)
//    - RHS：读取 valid
//    - LHS：写入 valid
//
// 说明：
// - 测试风格参考 test_prs_trans_info.cpp（自带 main，输出 PASS/FAIL）
// - 编译建议：g++ -std=c++17 -I ../include test_valid.cpp -o test_valid

#include <iostream>
#include <type_traits>
#include <cstdint>

#include "BuiltIn.hpp"

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

struct SimpleAgg {
    int x;
    std::uint32_t y;
};

// Compile-time checks: overload resolution should keep _inflate<T> path intact.
static_assert(std::is_same_v<
                  decltype(std::declval<const BuiltInContext &>()._valid(std::declval<const _inflate<SimpleAgg> &>())),
                  bool>,
              "_valid(_inflate<T>) must return bool");

static_assert(std::is_same_v<
                  decltype(std::declval<const BuiltInContext &>()._valid(std::declval<int &>())),
                  BuiltInContext::ValidProxy>,
              "_valid(T&) must return BuiltInContext::ValidProxy");

static_assert(std::is_same_v<
                  decltype(std::declval<const BuiltInContext &>()._valid(std::declval<const int &>())),
                  BuiltInContext::ValidProxy>,
              "_valid(const T&) must return BuiltInContext::ValidProxy");

} // namespace

int main() {
    std::cout << "[test_valid] start\n";

    BuiltInContext ctx;
    bool ok = true;

    // NOTE:
    // _valid(T) 的字典 key 仅是“地址”，不跟踪对象生命周期。
    // 因此测试里不要把变量放在不同的内层作用域（栈地址可能被复用），
    // 统一放在 main() 的同一作用域可以确保地址稳定，避免假失败。
    int a = 123;
    int b = 456;
    const std::uint32_t c = 0xdeadbeefu;
    SimpleAgg s{1, 2};
    int arr[4] = {1, 2, 3, 4};

    // -------------------------
    // Test A: generic _valid(T&) / _valid(const T&) via address->valid dict
    // -------------------------
    // A1) First read inserts with default false
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(a)), false, "first read inserts default false (a)");
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(a)), false, "second read stays false (a)");

    // A2) LHS write then RHS read
    ctx._valid(a) = 1;
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(a)), true, "write 1 then read true (a)");

    ctx._valid(a) = 0;
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(a)), false, "write 0 then read false (a)");

    // A3) Different addresses are isolated
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(b)), false, "first read inserts default false (b)");
    ctx._valid(b) = true;
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(b)), true, "b set true");
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(a)), false, "a remains false after b changes");

    // A4) const object is supported (valid is associated with address, not mutability of T)
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(c)), false, "const first read default false (c)");
    ctx._valid(c) = 1;
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(c)), true, "const c set true then read true");

    // A5) Aggregate type address works
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(s)), false, "aggregate default false");
    ctx._valid(s) = true;
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(s)), true, "aggregate set true");

    // A6) Array type address works (T deduces as int[N])
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(arr)), false, "array default false");
    ctx._valid(arr) = 1;
    ok &= expect_eq<bool>(static_cast<bool>(ctx._valid(arr)), true, "array set true");

    // -------------------------
    // Test B: _valid(const _inflate<T>&) reads v.valid and remains unaffected by dict logic
    // -------------------------
    {
        _inflate<SimpleAgg> iv; // default valid=false
        ok &= expect_eq<bool>(ctx._valid(iv), false, "_inflate default valid=false");

        iv = SimpleAgg{7, 8}; // assignment sets iv.valid=true
        ok &= expect_eq<bool>(ctx._valid(iv), true, "_inflate assignment sets valid=true");

        iv = std::nullopt; // sets valid=false
        ok &= expect_eq<bool>(ctx._valid(iv), false, "_inflate nullopt sets valid=false");
    }

    std::cout << "[test_valid] " << (ok ? "PASS" : "FAILED") << "\n";
    return ok ? 0 : 1;
}

