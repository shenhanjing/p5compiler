// 手写测试：验证 _prs_trans_info<T> 与 T 完全等价（不引入包装类型）
#include <type_traits>
#include <iostream>

#include "BuiltIn.hpp"

namespace {
struct TransInfo_S {
    int x;
};

using ParserTransInfo_S = _prs_trans_info<TransInfo_S>;

static_assert(std::is_same_v<ParserTransInfo_S, TransInfo_S>,
              "_prs_trans_info<T> must be exactly T");
static_assert(std::is_same_v<_prs_trans_info<const TransInfo_S>, const TransInfo_S>,
              "_prs_trans_info must preserve const");
static_assert(std::is_same_v<_prs_trans_info<TransInfo_S &>, TransInfo_S &>,
              "_prs_trans_info must preserve references");
static_assert(std::is_same_v<_prs_trans_info<TransInfo_S &&>, TransInfo_S &&>,
              "_prs_trans_info must preserve rvalue references");
} // namespace

int main() {
    ParserTransInfo_S v{42};

    // 如果类型完全等价，这里的指针类型也应当自然匹配
    TransInfo_S *p = &v;
    (void)p;

    std::cout << "[test_prs_trans_info] PASS\n";
    return 0;
}

