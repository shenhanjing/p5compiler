#ifndef P5_TYPES_HPP
#define P5_TYPES_HPP

#include <bitset>
#include <cstdint>
#include <cstring>
#include <type_traits>

namespace p5 {

/**
 * @brief P5 固定位宽整数类型
 * 
 * 支持 1-128 位的固定位宽整数，提供位切片、运算符重载等功能
 * 
 * @tparam N 位宽（1-128）
 */
template<size_t N>
class uint {
    static_assert(N > 0 && N <= 128, "Bit width must be between 1 and 128");
    
private:
    std::bitset<N> value;

public:
    // 默认构造函数
    uint() = default;
    
    // 从整数构造
    explicit uint(uint64_t val) : value(val) {}
    
    // 从其他 uint<N> 构造
    template<size_t M>
    explicit uint(const uint<M>& other) {
        if constexpr (M <= N) {
            value = other.value.to_ullong();
        } else {
            // 截断高位
            value = other.value.to_ullong() & ((1ULL << N) - 1);
        }
    }
    
    // 赋值运算符
    uint& operator=(uint64_t val) {
        value = val;
        return *this;
    }
    
    template<size_t M>
    uint& operator=(const uint<M>& other) {
        if constexpr (M <= N) {
            value = other.value.to_ullong();
        } else {
            value = other.value.to_ullong() & ((1ULL << N) - 1);
        }
        return *this;
    }
    
    // 类型转换
    // 提供隐式转换运算符，支持转换为常用的无符号整数类型
    // 注意：size_t 在64位系统上通常是 uint64_t 的别名，因此不单独提供转换运算符
    operator uint8_t() const { return static_cast<uint8_t>(value.to_ullong()); }
    operator uint16_t() const { return static_cast<uint16_t>(value.to_ullong()); }
    operator uint32_t() const { return static_cast<uint32_t>(value.to_ullong()); }
    operator uint64_t() const { return value.to_ullong(); }
    
    // 算术运算符
    uint operator+(const uint& other) const {
        uint64_t result = value.to_ullong() + other.value.to_ullong();
        return uint(result & ((1ULL << N) - 1));
    }
    
    uint operator-(const uint& other) const {
        uint64_t result = value.to_ullong() - other.value.to_ullong();
        return uint(result & ((1ULL << N) - 1));
    }
    
    uint operator*(const uint& other) const {
        uint64_t result = value.to_ullong() * other.value.to_ullong();
        return uint(result & ((1ULL << N) - 1));
    }
    
    uint operator/(const uint& other) const {
        if (other.value.to_ullong() == 0) return uint(0);
        return uint(value.to_ullong() / other.value.to_ullong());
    }
    
    uint operator%(const uint& other) const {
        if (other.value.to_ullong() == 0) return uint(0);
        return uint(value.to_ullong() % other.value.to_ullong());
    }
    
    // 自增自减
    uint& operator++() {
        uint64_t val = value.to_ullong();
        value = (val + 1) & ((1ULL << N) - 1);
        return *this;
    }
    
    uint operator++(int) {
        uint tmp = *this;
        ++(*this);
        return tmp;
    }
    
    uint& operator--() {
        uint64_t val = value.to_ullong();
        value = (val - 1) & ((1ULL << N) - 1);
        return *this;
    }
    
    uint operator--(int) {
        uint tmp = *this;
        --(*this);
        return tmp;
    }
    
    // 位运算符
    uint operator&(const uint& other) const {
        return uint((value & other.value).to_ullong());
    }
    
    uint operator|(const uint& other) const {
        return uint((value | other.value).to_ullong());
    }
    
    uint operator^(const uint& other) const {
        return uint((value ^ other.value).to_ullong());
    }
    
    uint operator~() const {
        return uint((~value).to_ullong() & ((1ULL << N) - 1));
    }
    
    uint operator<<(size_t shift) const {
        return uint((value << shift).to_ullong() & ((1ULL << N) - 1));
    }
    
    uint operator>>(size_t shift) const {
        return uint((value >> shift).to_ullong());
    }
    
    // 复合赋值运算符
    uint& operator+=(const uint& other) {
        *this = *this + other;
        return *this;
    }
    
    uint& operator-=(const uint& other) {
        *this = *this - other;
        return *this;
    }
    
    uint& operator*=(const uint& other) {
        *this = *this * other;
        return *this;
    }
    
    uint& operator/=(const uint& other) {
        *this = *this / other;
        return *this;
    }
    
    uint& operator%=(const uint& other) {
        *this = *this % other;
        return *this;
    }
    
    uint& operator&=(const uint& other) {
        value &= other.value;
        return *this;
    }
    
    uint& operator|=(const uint& other) {
        value |= other.value;
        return *this;
    }
    
    uint& operator^=(const uint& other) {
        value ^= other.value;
        return *this;
    }
    
    uint& operator<<=(size_t shift) {
        value <<= shift;
        value &= std::bitset<N>((1ULL << N) - 1);
        return *this;
    }
    
    uint& operator>>=(size_t shift) {
        value >>= shift;
        return *this;
    }
    
    // 比较运算符
    bool operator==(const uint& other) const {
        return value == other.value;
    }
    
    bool operator!=(const uint& other) const {
        return value != other.value;
    }
    
    bool operator<(const uint& other) const {
        return value.to_ullong() < other.value.to_ullong();
    }
    
    bool operator<=(const uint& other) const {
        return value.to_ullong() <= other.value.to_ullong();
    }
    
    bool operator>(const uint& other) const {
        return value.to_ullong() > other.value.to_ullong();
    }
    
    bool operator>=(const uint& other) const {
        return value.to_ullong() >= other.value.to_ullong();
    }
    
    // 与整数比较
    bool operator==(uint64_t val) const {
        return value.to_ullong() == val;
    }
    
    bool operator!=(uint64_t val) const {
        return value.to_ullong() != val;
    }
    
    bool operator<(uint64_t val) const {
        return value.to_ullong() < val;
    }
    
    bool operator<=(uint64_t val) const {
        return value.to_ullong() <= val;
    }
    
    bool operator>(uint64_t val) const {
        return value.to_ullong() > val;
    }
    
    bool operator>=(uint64_t val) const {
        return value.to_ullong() >= val;
    }
    
    // 位切片操作 [high:low]
    template<size_t High, size_t Low>
    uint<High - Low + 1> slice() const {
        static_assert(High >= Low, "High must be >= Low");
        static_assert(High < N, "High must be < N");
        
        uint<High - Low + 1> result;
        for (size_t i = 0; i <= High - Low; ++i) {
            result.value[i] = value[Low + i];
        }
        return result;
    }
    
    // 单 bit 访问
    bool operator[](size_t pos) const {
        return value[pos];
    }
    
    // 获取底层值（用于调试）
    uint64_t to_ullong() const {
        return value.to_ullong();
    }
    
    // 获取位宽
    static constexpr size_t width() {
        return N;
    }
    
    // 获取最大值
    static uint max() {
        return uint((1ULL << N) - 1);
    }
    
    // 获取最小值
    static uint min() {
        return uint(0);
    }
};

// 类型别名（常用位宽）
using uint1 = uint<1>;
using uint2 = uint<2>;
using uint3 = uint<3>;
using uint4 = uint<4>;
using uint6 = uint<6>;
using uint8 = uint<8>;
using uint10 = uint<10>;
using uint12 = uint<12>;
using uint13 = uint<13>;
using uint14 = uint<14>;
using uint16 = uint<16>;
using uint20 = uint<20>;
using uint31 = uint<31>;
using uint32 = uint<32>;
using uint48 = uint<48>;
using uint128 = uint<128>;

// 全局运算符重载（支持整数与 uint<N> 的运算）
template<size_t N>
uint<N> operator+(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) + rhs;
}

template<size_t N>
uint<N> operator-(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) - rhs;
}

template<size_t N>
uint<N> operator*(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) * rhs;
}

template<size_t N>
uint<N> operator/(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) / rhs;
}

template<size_t N>
bool operator==(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) == rhs;
}

template<size_t N>
bool operator!=(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) != rhs;
}

template<size_t N>
bool operator<(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) < rhs;
}

template<size_t N>
bool operator<=(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) <= rhs;
}

template<size_t N>
bool operator>(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) > rhs;
}

template<size_t N>
bool operator>=(uint64_t lhs, const uint<N>& rhs) {
    return uint<N>(lhs) >= rhs;
}

} // namespace p5

// 为了兼容 P5 代码，可以使用全局命名空间
// 注释掉以避免与系统 uint 冲突
// using p5::uint;

#endif // P5_TYPES_HPP

