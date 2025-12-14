/**
 * @file p5_builtin_functions.cpp
 * @brief P5 内置函数库实现
 */

#include "p5_builtin_functions.hpp"

namespace p5 {

// 全局运行时上下文指针
P5RuntimeContext* g_p5_runtime = &P5RuntimeContext::instance();

} // namespace p5

