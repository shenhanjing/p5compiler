// test_memove.cpp: 测试 _memove 函数功能
// _memove 函数功能分析：
// 1. 从源容器移动到目标容器，支持偏移量和重叠区域
// 2. 类似于 memmove，可以处理重叠区域
// 3. 支持 vector 和数组之间的相互复制
// 4. 支持 int 和 p5::uint<N> 类型的偏移量和大小参数
// 5. 有边界检查，如果超出范围会警告并调整大小
// 6. 对于同一容器内的重叠复制，如果 dst_offset > src_offset，采用反向复制策略

#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>

#include "../../include/BuiltIn.hpp"

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

template <typename T>
bool expect_array_eq(const T *got, const T *expect, size_t size, const char *msg) {
    for (size_t i = 0; i < size; ++i) {
        if (got[i] != expect[i]) {
            std::cerr << "[FAIL] " << msg << " at index " << i 
                      << " got=" << got[i] << " expect=" << expect[i] << "\n";
            return false;
        }
    }
    return true;
}

// 打印 vector 内容（用于调试）
template <typename T>
void print_vector(const std::vector<T> &v, const char *name) {
    std::cout << "  " << name << ": [";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// 打印数组内容（用于调试）
template <typename T, size_t N>
void print_array(const T (&arr)[N], const char *name) {
    std::cout << "  " << name << ": [";
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i];
        if (i < N - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

} // namespace

int main() {
    std::cout << "[test_memove] 开始测试 _memove 函数\n\n";
    
    BuiltInContext ctx;
    bool ok = true;
    int test_count = 0;

    // ==================== Test Case 1: vector -> vector (int offsets/size) ====================
    std::cout << "Test Case 1: vector -> vector (int offsets/size)\n";
    {
        std::vector<int> dst = {0, 0, 0, 0, 0, 0, 0, 0};
        std::vector<int> src = {1, 2, 3, 4, 5};
        
        ctx._memove(dst, 2, src, 0, 3);
        // 期望: dst = [0, 0, 1, 2, 3, 0, 0, 0]
        ok &= expect_eq(dst[0], 0, "dst[0]");
        ok &= expect_eq(dst[1], 0, "dst[1]");
        ok &= expect_eq(dst[2], 1, "dst[2]");
        ok &= expect_eq(dst[3], 2, "dst[3]");
        ok &= expect_eq(dst[4], 3, "dst[4]");
        ok &= expect_eq(dst[5], 0, "dst[5]");
        test_count++;
    }

    // ==================== Test Case 2: vector -> vector (重叠区域，正向复制) ====================
    std::cout << "\nTest Case 2: vector -> vector (重叠区域，正向复制: dst_offset < src_offset)\n";
    {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
        // 从 vec[0] 复制 3 个元素到 vec[2]
        // 期望: vec = [1, 2, 1, 2, 3, 6, 7, 8]
        ctx._memove(vec, 2, vec, 0, 3);
        ok &= expect_eq(vec[0], 1, "overlap vec[0]");
        ok &= expect_eq(vec[1], 2, "overlap vec[1]");
        ok &= expect_eq(vec[2], 1, "overlap vec[2]");
        ok &= expect_eq(vec[3], 2, "overlap vec[3]");
        ok &= expect_eq(vec[4], 3, "overlap vec[4]");
        ok &= expect_eq(vec[5], 6, "overlap vec[5]");
        test_count++;
    }

    // ==================== Test Case 3: vector -> vector (重叠区域，反向复制) ====================
    std::cout << "\nTest Case 3: vector -> vector (重叠区域，反向复制: dst_offset > src_offset)\n";
    {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
        // 从 vec[2] 复制 3 个元素到 vec[4] (重叠)
        // 期望: vec = [1, 2, 3, 4, 3, 4, 5, 8]
        ctx._memove(vec, 4, vec, 2, 3);
        ok &= expect_eq(vec[0], 1, "reverse overlap vec[0]");
        ok &= expect_eq(vec[1], 2, "reverse overlap vec[1]");
        ok &= expect_eq(vec[2], 3, "reverse overlap vec[2]");
        ok &= expect_eq(vec[3], 4, "reverse overlap vec[3]");
        ok &= expect_eq(vec[4], 3, "reverse overlap vec[4]");
        ok &= expect_eq(vec[5], 4, "reverse overlap vec[5]");
        ok &= expect_eq(vec[6], 5, "reverse overlap vec[6]");
        ok &= expect_eq(vec[7], 8, "reverse overlap vec[7]");
        test_count++;
    }

    // ==================== Test Case 4: vector -> vector (p5::uint offsets/size) ====================
    std::cout << "\nTest Case 4: vector -> vector (p5::uint offsets/size)\n";
    {
        std::vector<int> dst = {0, 0, 0, 0, 0};
        std::vector<int> src = {10, 20, 30, 40};
        
        p5::uint<8> dst_offset(1);
        p5::uint<8> src_offset(0);
        p5::uint<8> size(3);
        
        ctx._memove(dst, dst_offset, src, src_offset, size);
        // 期望: dst = [0, 10, 20, 30, 0]
        ok &= expect_eq(dst[0], 0, "p5::uint dst[0]");
        ok &= expect_eq(dst[1], 10, "p5::uint dst[1]");
        ok &= expect_eq(dst[2], 20, "p5::uint dst[2]");
        ok &= expect_eq(dst[3], 30, "p5::uint dst[3]");
        ok &= expect_eq(dst[4], 0, "p5::uint dst[4]");
        test_count++;
    }

    // ==================== Test Case 5: array -> array (int offsets/size) ====================
    std::cout << "\nTest Case 5: array -> array (int offsets/size)\n";
    {
        int dst[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        int src[5] = {100, 200, 300, 400, 500};
        
        ctx._memove(dst, 1, src, 1, 3);
        // 期望: dst = [0, 200, 300, 400, 0, 0, 0, 0]
        ok &= expect_eq(dst[0], 0, "array dst[0]");
        ok &= expect_eq(dst[1], 200, "array dst[1]");
        ok &= expect_eq(dst[2], 300, "array dst[2]");
        ok &= expect_eq(dst[3], 400, "array dst[3]");
        ok &= expect_eq(dst[4], 0, "array dst[4]");
        test_count++;
    }

    // ==================== Test Case 6: array -> array (重叠区域) ====================
    std::cout << "\nTest Case 6: array -> array (重叠区域，反向复制)\n";
    {
        int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        // 从 arr[1] 复制 3 个元素到 arr[3] (重叠)
        // 期望: arr = [1, 2, 3, 2, 3, 4, 7, 8]
        ctx._memove(arr, 3, arr, 1, 3);
        ok &= expect_eq(arr[0], 1, "array overlap arr[0]");
        ok &= expect_eq(arr[1], 2, "array overlap arr[1]");
        ok &= expect_eq(arr[2], 3, "array overlap arr[2]");
        ok &= expect_eq(arr[3], 2, "array overlap arr[3]");
        ok &= expect_eq(arr[4], 3, "array overlap arr[4]");
        ok &= expect_eq(arr[5], 4, "array overlap arr[5]");
        ok &= expect_eq(arr[6], 7, "array overlap arr[6]");
        ok &= expect_eq(arr[7], 8, "array overlap arr[7]");
        test_count++;
    }

    // ==================== Test Case 7: array -> array (p5::uint offsets/size) ====================
    std::cout << "\nTest Case 7: array -> array (p5::uint offsets/size)\n";
    {
        int dst[6] = {0, 0, 0, 0, 0, 0};
        int src[4] = {11, 22, 33, 44};
        
        p5::uint<16> dst_offset(2);
        p5::uint<16> src_offset(1);
        p5::uint<16> size(2);
        
        ctx._memove(dst, dst_offset, src, src_offset, size);
        // 期望: dst = [0, 0, 22, 33, 0, 0]
        ok &= expect_eq(dst[0], 0, "p5::uint array dst[0]");
        ok &= expect_eq(dst[1], 0, "p5::uint array dst[1]");
        ok &= expect_eq(dst[2], 22, "p5::uint array dst[2]");
        ok &= expect_eq(dst[3], 33, "p5::uint array dst[3]");
        ok &= expect_eq(dst[4], 0, "p5::uint array dst[4]");
        ok &= expect_eq(dst[5], 0, "p5::uint array dst[5]");
        test_count++;
    }

    // ==================== Test Case 8: array -> vector (int offsets/size) ====================
    std::cout << "\nTest Case 8: array -> vector (int offsets/size)\n";
    {
        std::vector<int> dst(6, 0);
        int src[5] = {50, 60, 70, 80, 90};
        
        ctx._memove(dst, 1, src, 2, 3);
        // 期望: dst = [0, 70, 80, 90, 0, 0]
        ok &= expect_eq(dst[0], 0, "array->vector dst[0]");
        ok &= expect_eq(dst[1], 70, "array->vector dst[1]");
        ok &= expect_eq(dst[2], 80, "array->vector dst[2]");
        ok &= expect_eq(dst[3], 90, "array->vector dst[3]");
        ok &= expect_eq(dst[4], 0, "array->vector dst[4]");
        ok &= expect_eq(dst[5], 0, "array->vector dst[5]");
        test_count++;
    }

    // ==================== Test Case 9: array -> vector (p5::uint offsets/size) ====================
    std::cout << "\nTest Case 9: array -> vector (p5::uint offsets/size)\n";
    {
        std::vector<int> dst(5, 0);
        int src[4] = {111, 222, 333, 444};
        
        p5::uint<32> dst_offset(0);
        p5::uint<32> src_offset(1);
        p5::uint<32> size(2);
        
        ctx._memove(dst, dst_offset, src, src_offset, size);
        // 期望: dst = [222, 333, 0, 0, 0]
        ok &= expect_eq(dst[0], 222, "p5::uint array->vector dst[0]");
        ok &= expect_eq(dst[1], 333, "p5::uint array->vector dst[1]");
        ok &= expect_eq(dst[2], 0, "p5::uint array->vector dst[2]");
        ok &= expect_eq(dst[3], 0, "p5::uint array->vector dst[3]");
        ok &= expect_eq(dst[4], 0, "p5::uint array->vector dst[4]");
        test_count++;
    }

    // ==================== Test Case 10: vector -> array (int offsets/size) ====================
    std::cout << "\nTest Case 10: vector -> array (int offsets/size)\n";
    {
        int dst[7] = {0, 0, 0, 0, 0, 0, 0};
        std::vector<int> src = {999, 888, 777, 666, 555};
        
        ctx._memove(dst, 2, src, 1, 3);
        // 期望: dst = [0, 0, 888, 777, 666, 0, 0]
        ok &= expect_eq(dst[0], 0, "vector->array dst[0]");
        ok &= expect_eq(dst[1], 0, "vector->array dst[1]");
        ok &= expect_eq(dst[2], 888, "vector->array dst[2]");
        ok &= expect_eq(dst[3], 777, "vector->array dst[3]");
        ok &= expect_eq(dst[4], 666, "vector->array dst[4]");
        ok &= expect_eq(dst[5], 0, "vector->array dst[5]");
        ok &= expect_eq(dst[6], 0, "vector->array dst[6]");
        test_count++;
    }

    // ==================== Test Case 11: vector -> array (p5::uint offsets/size) ====================
    std::cout << "\nTest Case 11: vector -> array (p5::uint offsets/size)\n";
    {
        int dst[5] = {0, 0, 0, 0, 0};
        std::vector<int> src = {1111, 2222, 3333, 4444};
        
        p5::uint<8> dst_offset(1);
        p5::uint<8> src_offset(0);
        p5::uint<8> size(3);
        
        ctx._memove(dst, dst_offset, src, src_offset, size);
        // 期望: dst = [0, 1111, 2222, 3333, 0]
        ok &= expect_eq(dst[0], 0, "p5::uint vector->array dst[0]");
        ok &= expect_eq(dst[1], 1111, "p5::uint vector->array dst[1]");
        ok &= expect_eq(dst[2], 2222, "p5::uint vector->array dst[2]");
        ok &= expect_eq(dst[3], 3333, "p5::uint vector->array dst[3]");
        ok &= expect_eq(dst[4], 0, "p5::uint vector->array dst[4]");
        test_count++;
    }

    // ==================== Test Case 12: 边界检查测试 ====================
    std::cout << "\nTest Case 12: 边界检查测试（超出范围应自动调整）\n";
    {
        std::vector<int> dst = {0, 0, 0, 0};
        std::vector<int> src = {1, 2, 3};
        
        // 尝试复制超出范围的大小，应该自动调整
        ctx._memove(dst, 2, src, 0, 5);  // size=5 但 dst 只有 4 个元素，src 只有 3 个
        // 应该只复制 min(4-2, 3-0) = min(2, 3) = 2 个元素
        // 期望: dst = [0, 0, 1, 2]
        ok &= expect_eq(dst[0], 0, "boundary check dst[0]");
        ok &= expect_eq(dst[1], 0, "boundary check dst[1]");
        ok &= expect_eq(dst[2], 1, "boundary check dst[2]");
        ok &= expect_eq(dst[3], 2, "boundary check dst[3]");
        test_count++;
    }

    // ==================== Test Case 13: 零大小测试 ====================
    std::cout << "\nTest Case 13: 零大小测试（size=0 应该不改变任何内容）\n";
    {
        std::vector<int> dst = {100, 200, 300};
        std::vector<int> src = {999, 888, 777};
        
        ctx._memove(dst, 0, src, 0, 0);
        // 期望: dst 保持不变 = [100, 200, 300]
        ok &= expect_eq(dst[0], 100, "zero size dst[0]");
        ok &= expect_eq(dst[1], 200, "zero size dst[1]");
        ok &= expect_eq(dst[2], 300, "zero size dst[2]");
        test_count++;
    }

    // ==================== Test Case 14: 完整复制测试 ====================
    std::cout << "\nTest Case 14: 完整复制测试（从开头复制整个源）\n";
    {
        std::vector<int> dst(5, 0);
        std::vector<int> src = {42, 43, 44, 45};
        
        ctx._memove(dst, 0, src, 0, 4);
        // 期望: dst = [42, 43, 44, 45, 0]
        ok &= expect_eq(dst[0], 42, "full copy dst[0]");
        ok &= expect_eq(dst[1], 43, "full copy dst[1]");
        ok &= expect_eq(dst[2], 44, "full copy dst[2]");
        ok &= expect_eq(dst[3], 45, "full copy dst[3]");
        ok &= expect_eq(dst[4], 0, "full copy dst[4]");
        test_count++;
    }

    std::cout << "\n========================================\n";
    std::cout << "测试完成！共执行 " << test_count << " 个测试用例\n";
    std::cout << "结果: " << (ok ? "ALL PASS" : "FAILED") << "\n";
    std::cout << "========================================\n";
    
    return ok ? 0 : 1;
}
