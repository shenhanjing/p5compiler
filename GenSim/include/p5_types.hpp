#ifndef P5_TYPES_HPP
#define P5_TYPES_HPP

#include <bitset>
#include <cstdint>
#include <cstring>
#include <type_traits>
#include <utility>
#include <iterator>
#include <vector>
#include <boost/pfr.hpp>

namespace p5 {

// 编译期描述位范围的标签，用于提供数组下标式的切片访问
template<size_t High, size_t Low>
struct bit_range_t {
    static_assert(High >= Low, "High must be >= Low");
};

// 变量模板，便于以 p5::bit_range<hi, lo> 形式书写
template<size_t High, size_t Low>
inline constexpr bit_range_t<High, Low> bit_range{};

/**
 * @brief P5 固定位宽整数类型
 * 
 * 支持 1-128 位的固定位宽整数，提供位切片、运算符重载等功能
 * 
 * @tparam N 位宽（1-256）
 */
template<size_t N>
class uint {
    static_assert(N > 0 && N <= 256, "Bit width must be between 1 and 256");
    
private:
    std::bitset<N> value;

    // 可写切片代理，支持对固定编译期范围 [High:Low] 进行读写
    template<size_t High, size_t Low>
    class slice_proxy {
        static_assert(High >= Low, "High must be >= Low");
        static_assert(High < N, "High must be < N");

        std::bitset<N> &bits;
        static constexpr size_t width = High - Low + 1;

    public:
        explicit slice_proxy(std::bitset<N> &bits_ref) : bits(bits_ref) {}

        using bit_reference = typename std::bitset<N>::reference;
        using value_type = uint<width>;

        // 便捷：读取当前切片值
        value_type read() const {
            return static_cast<value_type>(*this);
        }

        // 读取切片，返回定长 uint<width>
        operator value_type() const {
            value_type result;
            for (size_t i = 0; i < width; ++i) {
                result[i] = bits[Low + i];
            }
            return result;
        }

        // 赋值自同宽度的 uint
        slice_proxy &operator=(const uint<width> &rhs) {
            for (size_t i = 0; i < width; ++i) {
                bits[Low + i] = rhs[i];
            }
            return *this;
        }

        // 赋值自其他宽度的 uint，按较小位数复制
        template<size_t M>
        slice_proxy &operator=(const uint<M> &rhs) {
            constexpr size_t copy_width = (M < width) ? M : width;
            for (size_t i = 0; i < copy_width; ++i) {
                bits[Low + i] = rhs[i];
            }
            // 多余位清零
            if constexpr (width > copy_width) {
                for (size_t i = copy_width; i < width; ++i) {
                    bits[Low + i] = 0;
                }
            }
            return *this;
        }

        // 赋值自整数（按低位写入，超出 64 位的部分清零）
        template <typename Integral, typename = std::enable_if_t<std::is_integral_v<Integral>>>
        slice_proxy &operator=(Integral rhs) {
            uint64_t v = static_cast<uint64_t>(rhs);
            for (size_t i = 0; i < width; ++i) {
                bits[Low + i] = (v >> i) & 1ULL;
            }
            if constexpr (width > 64) {
                for (size_t i = 64; i < width; ++i) {
                    bits[Low + i] = 0;
                }
            }
            return *this;
        }

        // ---- bit access within slice ----
        bit_reference operator[](size_t pos) {
            return bits[Low + pos];
        }

        bool operator[](size_t pos) const {
            return bits[Low + pos];
        }

        // ---- nested compile-time slice access (relative to this slice) ----
        template<size_t SubHigh, size_t SubLow>
        slice_proxy<Low + SubHigh, Low + SubLow> operator[](bit_range_t<SubHigh, SubLow>) {
            static_assert(SubHigh >= SubLow, "High must be >= Low");
            static_assert(SubHigh < width, "High must be < slice width");
            return slice_proxy<Low + SubHigh, Low + SubLow>(bits);
        }

        template<size_t SubHigh, size_t SubLow>
        uint<SubHigh - SubLow + 1> operator[](bit_range_t<SubHigh, SubLow>) const {
            static_assert(SubHigh >= SubLow, "High must be >= Low");
            static_assert(SubHigh < width, "High must be < slice width");
            uint<SubHigh - SubLow + 1> out{};
            for (size_t i = 0; i <= SubHigh - SubLow; ++i) {
                out[i] = bits[Low + SubLow + i];
            }
            return out;
        }

        // debug convenience
        uint64_t to_ullong() const { return read().to_ullong(); }

        // ---- comparisons (match p5::uint style; also enable integral-lhs) ----
        bool operator==(const value_type &rhs) const { return read() == rhs; }
        bool operator!=(const value_type &rhs) const { return read() != rhs; }
        bool operator<(const value_type &rhs) const { return read() < rhs; }
        bool operator<=(const value_type &rhs) const { return read() <= rhs; }
        bool operator>(const value_type &rhs) const { return read() > rhs; }
        bool operator>=(const value_type &rhs) const { return read() >= rhs; }

        template <size_t M>
        bool operator==(const uint<M> &rhs) const { return read() == value_type(rhs); }
        template <size_t M>
        bool operator!=(const uint<M> &rhs) const { return read() != value_type(rhs); }
        template <size_t M>
        bool operator<(const uint<M> &rhs) const { return read() < value_type(rhs); }
        template <size_t M>
        bool operator<=(const uint<M> &rhs) const { return read() <= value_type(rhs); }
        template <size_t M>
        bool operator>(const uint<M> &rhs) const { return read() > value_type(rhs); }
        template <size_t M>
        bool operator>=(const uint<M> &rhs) const { return read() >= value_type(rhs); }

        template <size_t H2, size_t L2>
        bool operator==(const slice_proxy<H2, L2> &rhs) const { return *this == static_cast<uint<H2 - L2 + 1>>(rhs); }
        template <size_t H2, size_t L2>
        bool operator!=(const slice_proxy<H2, L2> &rhs) const { return *this != static_cast<uint<H2 - L2 + 1>>(rhs); }
        template <size_t H2, size_t L2>
        bool operator<(const slice_proxy<H2, L2> &rhs) const { return *this < static_cast<uint<H2 - L2 + 1>>(rhs); }
        template <size_t H2, size_t L2>
        bool operator<=(const slice_proxy<H2, L2> &rhs) const { return *this <= static_cast<uint<H2 - L2 + 1>>(rhs); }
        template <size_t H2, size_t L2>
        bool operator>(const slice_proxy<H2, L2> &rhs) const { return *this > static_cast<uint<H2 - L2 + 1>>(rhs); }
        template <size_t H2, size_t L2>
        bool operator>=(const slice_proxy<H2, L2> &rhs) const { return *this >= static_cast<uint<H2 - L2 + 1>>(rhs); }

        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        bool operator==(Integral rhs) const { return read() == static_cast<uint64_t>(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        bool operator!=(Integral rhs) const { return read() != static_cast<uint64_t>(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        bool operator<(Integral rhs) const { return read() < static_cast<uint64_t>(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        bool operator<=(Integral rhs) const { return read() <= static_cast<uint64_t>(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        bool operator>(Integral rhs) const { return read() > static_cast<uint64_t>(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        bool operator>=(Integral rhs) const { return read() >= static_cast<uint64_t>(rhs); }

        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend bool operator==(Integral lhs, const slice_proxy &rhs) { return rhs == lhs; }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend bool operator!=(Integral lhs, const slice_proxy &rhs) { return rhs != lhs; }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend bool operator<(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) < rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend bool operator<=(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) <= rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend bool operator>(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) > rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend bool operator>=(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) >= rhs.read(); }

        // ---- binary arithmetic/bitwise ops (return value_type) ----
        value_type operator+(const value_type &rhs) const { return read() + rhs; }
        value_type operator-(const value_type &rhs) const { return read() - rhs; }
        value_type operator*(const value_type &rhs) const { return read() * rhs; }
        value_type operator/(const value_type &rhs) const { return read() / rhs; }
        value_type operator%(const value_type &rhs) const { return read() % rhs; }
        value_type operator&(const value_type &rhs) const { return read() & rhs; }
        value_type operator|(const value_type &rhs) const { return read() | rhs; }
        value_type operator^(const value_type &rhs) const { return read() ^ rhs; }
        value_type operator~() const { return ~read(); }
        value_type operator<<(size_t shift) const { return read() << shift; }
        value_type operator>>(size_t shift) const { return read() >> shift; }

        template <size_t M> value_type operator+(const uint<M> &rhs) const { return read() + value_type(rhs); }
        template <size_t M> value_type operator-(const uint<M> &rhs) const { return read() - value_type(rhs); }
        template <size_t M> value_type operator*(const uint<M> &rhs) const { return read() * value_type(rhs); }
        template <size_t M> value_type operator/(const uint<M> &rhs) const { return read() / value_type(rhs); }
        template <size_t M> value_type operator%(const uint<M> &rhs) const { return read() % value_type(rhs); }
        template <size_t M> value_type operator&(const uint<M> &rhs) const { return read() & value_type(rhs); }
        template <size_t M> value_type operator|(const uint<M> &rhs) const { return read() | value_type(rhs); }
        template <size_t M> value_type operator^(const uint<M> &rhs) const { return read() ^ value_type(rhs); }

        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator+(Integral rhs) const { return read() + value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator-(Integral rhs) const { return read() - value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator*(Integral rhs) const { return read() * value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator/(Integral rhs) const { return read() / value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator%(Integral rhs) const { return read() % value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator&(Integral rhs) const { return read() & value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator|(Integral rhs) const { return read() | value_type(rhs); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        value_type operator^(Integral rhs) const { return read() ^ value_type(rhs); }

        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend value_type operator+(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) + rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend value_type operator-(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) - rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend value_type operator&(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) & rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend value_type operator|(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) | rhs.read(); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        friend value_type operator^(Integral lhs, const slice_proxy &rhs) { return value_type(lhs) ^ rhs.read(); }

        // ---- compound assignments (read-modify-write) ----
        slice_proxy &operator+=(const uint<width> &rhs) { auto tmp = read(); tmp += rhs; *this = tmp; return *this; }
        slice_proxy &operator-=(const uint<width> &rhs) { auto tmp = read(); tmp -= rhs; *this = tmp; return *this; }
        slice_proxy &operator*=(const uint<width> &rhs) { auto tmp = read(); tmp *= rhs; *this = tmp; return *this; }
        slice_proxy &operator/=(const uint<width> &rhs) { auto tmp = read(); tmp /= rhs; *this = tmp; return *this; }
        slice_proxy &operator%=(const uint<width> &rhs) { auto tmp = read(); tmp %= rhs; *this = tmp; return *this; }
        slice_proxy &operator&=(const uint<width> &rhs) { auto tmp = read(); tmp &= rhs; *this = tmp; return *this; }
        slice_proxy &operator|=(const uint<width> &rhs) { auto tmp = read(); tmp |= rhs; *this = tmp; return *this; }
        slice_proxy &operator^=(const uint<width> &rhs) { auto tmp = read(); tmp ^= rhs; *this = tmp; return *this; }
        slice_proxy &operator<<=(size_t shift) { auto tmp = read(); tmp <<= shift; *this = tmp; return *this; }
        slice_proxy &operator>>=(size_t shift) { auto tmp = read(); tmp >>= shift; *this = tmp; return *this; }

        template<size_t M> slice_proxy &operator+=(const uint<M> &rhs) { return (*this += uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator-=(const uint<M> &rhs) { return (*this -= uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator*=(const uint<M> &rhs) { return (*this *= uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator/=(const uint<M> &rhs) { return (*this /= uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator%=(const uint<M> &rhs) { return (*this %= uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator&=(const uint<M> &rhs) { return (*this &= uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator|=(const uint<M> &rhs) { return (*this |= uint<width>(rhs)); }
        template<size_t M> slice_proxy &operator^=(const uint<M> &rhs) { return (*this ^= uint<width>(rhs)); }

        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator+=(Integral rhs) { return (*this += uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator-=(Integral rhs) { return (*this -= uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator*=(Integral rhs) { return (*this *= uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator/=(Integral rhs) { return (*this /= uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator%=(Integral rhs) { return (*this %= uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator&=(Integral rhs) { return (*this &= uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator|=(Integral rhs) { return (*this |= uint<width>(rhs)); }
        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
        slice_proxy &operator^=(Integral rhs) { return (*this ^= uint<width>(rhs)); }

        // ---- ++/-- ----
        slice_proxy &operator++() { auto tmp = read(); ++tmp; *this = tmp; return *this; }
        uint<width> operator++(int) { auto old = read(); ++(*this); return old; }
        slice_proxy &operator--() { auto tmp = read(); --tmp; *this = tmp; return *this; }
        uint<width> operator--(int) { auto old = read(); --(*this); return old; }
    };

public:
    using bit_reference = typename std::bitset<N>::reference;

    // 默认构造函数
    uint() = default;
    
    // 从整数构造（允许隐式从任意非 bool 整型转换）
    explicit uint(uint64_t val) : value(val) {}
    template <typename Integral, typename = std::enable_if_t<std::is_integral_v<Integral> && !std::is_same_v<Integral, bool>>>
    /*implicit*/ uint(Integral val) : value(static_cast<uint64_t>(val)) {}
    
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
    template <typename Integral, typename = std::enable_if_t<std::is_integral_v<Integral> && !std::is_same_v<Integral, bool>>>
    uint& operator=(Integral val) {
        value = static_cast<uint64_t>(val);
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
    // P5 中只有 uint<N> 类型，不提供隐式转换到标准整数类型
    // 如果需要转换为标准类型，使用显式的 to_ullong() 方法
    
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
    bit_reference operator[](size_t pos) {
        return value[pos];
    }

    bool operator[](size_t pos) const {
        return value[pos];
    }

    // 编译期切片访问（可写）
    template<size_t High, size_t Low>
    slice_proxy<High, Low> operator[](bit_range_t<High, Low>) {
        return slice_proxy<High, Low>(value);
    }

    // 编译期切片访问（只读）
    template<size_t High, size_t Low>
    uint<High - Low + 1> operator[](bit_range_t<High, Low>) const {
        return slice<High, Low>();
    }
    
    // 获取底层值（用于调试）
    uint64_t to_ullong() const {
        return value.to_ullong();
    }

    // 以“高位在前”的 bit 序列构造，便于从动态拼接结果生成定长 uint<N>
    template <typename BitIter>
    static uint from_bits(BitIter begin, BitIter end) {
        uint result;
        std::size_t idx = 0;  // 写入到 value[idx]，idx=0 为最低位
        for (auto it = std::make_reverse_iterator(end); it != std::make_reverse_iterator(begin); ++it) {
            if (idx >= N) break;
            result.value[idx++] = (*it);
        }
        return result;
    }

    static uint from_bits(const std::vector<bool> &bits) {
        return from_bits(bits.begin(), bits.end());
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

// =========================
//  Union-like bit overlay
// =========================
//
// C++ 关键字冲突：无法命名为 p5::union，因此这里提供 p5::Union<Layout>。
//
// 设计目标：
// - Union 只有一份底层 bit 存储（位宽=所有“成员视图”的最大位宽）
// - 顶层成员（Layout 的字段）都从 bit offset=0 开始覆盖同一份存储（类似 union）
// - 若某个成员是结构体（aggregate），则把它视为一个整体：其内部字段按声明顺序从 offset=0
//   起顺序排布（位宽=各字段位宽之和），并支持嵌套结构体/嵌套 Union
// - 访问成员使用“可读写视图”：
//   - p5::member<p5::uint<N>>：把底层某段 bits 映射为 uint<N>
//   - p5::Union<Layout2>：可作为成员被绑定成 view，继续以 .x/.y 方式访问
//
// 用法示例（见 test/test_uint_union.cpp）：
// struct St { p5::member<p5::uint<3>> a; p5::member<p5::uint<3>> b; };
// struct ULayout { p5::member<p5::uint<10>> long_; p5::member<p5::uint<2>> short_; St st; };
// p5::Union<ULayout> u; u.long_ = p5::uint<10>(...); u.st.a = p5::uint<3>(...);

namespace detail_p5_union {
// type traits
template <typename T>
struct is_p5_uint : std::false_type {};
template <std::size_t N>
struct is_p5_uint<p5::uint<N>> : std::true_type {};

template <typename...>
struct always_false : std::false_type {};

struct detail_union_binder; // fwd: used as friend of p5::member / p5::Union

struct bit_access {
    void *ctx{nullptr};
    bool (*get)(void *, std::size_t){nullptr};
    void (*set)(void *, std::size_t, bool){nullptr};
};

template <std::size_t Bits>
inline bool get_bit_impl(void *ctx, std::size_t pos) {
    return (*static_cast<p5::uint<Bits> *>(ctx))[pos];
}
template <std::size_t Bits>
inline void set_bit_impl(void *ctx, std::size_t pos, bool v) {
    (*static_cast<p5::uint<Bits> *>(ctx))[pos] = v;
}

template <std::size_t Bits>
inline bit_access make_access(p5::uint<Bits> &u) {
    return bit_access{&u, &get_bit_impl<Bits>, &set_bit_impl<Bits>};
}

}  // namespace detail_p5_union

// ---- bit width metafunction ----
template <typename T, typename Enable = void>
struct bit_width;

template <std::size_t N>
struct bit_width<p5::uint<N>, void> : std::integral_constant<std::size_t, N> {};

template <typename T>
inline constexpr std::size_t bit_width_v = bit_width<std::decay_t<T>>::value;

// A view of a fixed bit range interpreted as a p5::uint<N>.
template <typename UIntT>
class member {
    static_assert(detail_p5_union::is_p5_uint<std::decay_t<UIntT>>::value,
                  "p5::member<T> currently supports only p5::uint<N> as T");

public:
    using value_type = std::decay_t<UIntT>;
    static constexpr std::size_t width() { return bit_width_v<value_type>; }

    member() = default;

    // -------- bit & slice access (uint-like) --------
    class bit_reference {
    public:
        bit_reference(detail_p5_union::bit_access access, std::size_t abs_pos) : access_(access), abs_pos_(abs_pos) {}

        operator bool() const {
            if (!access_.get) return false;
            return access_.get(access_.ctx, abs_pos_);
        }

        bit_reference &operator=(bool v) {
            if (access_.set) access_.set(access_.ctx, abs_pos_, v);
            return *this;
        }

        bit_reference &operator=(const bit_reference &rhs) { return (*this = static_cast<bool>(rhs)); }

    private:
        detail_p5_union::bit_access access_{};
        std::size_t abs_pos_{0};
    };

    // Single bit access (writable)
    bit_reference operator[](std::size_t pos) { return bit_reference(access_, offset_ + pos); }

    // Single bit access (read-only)
    bool operator[](std::size_t pos) const {
        if (!access_.get) return false;
        return access_.get(access_.ctx, offset_ + pos);
    }

    // slice proxy (writable), similar to p5::uint::slice_proxy
    template <std::size_t High, std::size_t Low>
    class slice_proxy {
        static_assert(High >= Low, "High must be >= Low");
        static constexpr std::size_t width_bits = High - Low + 1;

    public:
        explicit slice_proxy(detail_p5_union::bit_access access, std::size_t base_offset)
            : access_(access), base_(base_offset) {}

        operator p5::uint<width_bits>() const {
            p5::uint<width_bits> result{};
            if (!access_.get) return result;
            for (std::size_t i = 0; i < width_bits; ++i) {
                result[i] = access_.get(access_.ctx, base_ + Low + i);
            }
            return result;
        }

        slice_proxy &operator=(const p5::uint<width_bits> &rhs) {
            if (!access_.set) return *this;
            for (std::size_t i = 0; i < width_bits; ++i) {
                access_.set(access_.ctx, base_ + Low + i, rhs[i]);
            }
            return *this;
        }

        template <std::size_t M>
        slice_proxy &operator=(const p5::uint<M> &rhs) {
            if (!access_.set) return *this;
            constexpr std::size_t copy_width = (M < width_bits) ? M : width_bits;
            for (std::size_t i = 0; i < copy_width; ++i) {
                access_.set(access_.ctx, base_ + Low + i, rhs[i]);
            }
            if constexpr (width_bits > copy_width) {
                for (std::size_t i = copy_width; i < width_bits; ++i) {
                    access_.set(access_.ctx, base_ + Low + i, false);
                }
            }
            return *this;
        }

        template <typename Integral,
                  typename = std::enable_if_t<std::is_integral_v<Integral> && !std::is_same_v<Integral, bool>>>
        slice_proxy &operator=(Integral rhs) {
            if (!access_.set) return *this;
            uint64_t v = static_cast<uint64_t>(rhs);
            for (std::size_t i = 0; i < width_bits; ++i) {
                access_.set(access_.ctx, base_ + Low + i, (v >> i) & 1ULL);
            }
            return *this;
        }

    private:
        detail_p5_union::bit_access access_{};
        std::size_t base_{0};
    };

    template <std::size_t High, std::size_t Low>
    p5::uint<High - Low + 1> slice() const {
        static_assert(High >= Low, "High must be >= Low");
        static_assert(High < width(), "High must be < member width");
        p5::uint<High - Low + 1> out{};
        if (!access_.get) return out;
        for (std::size_t i = 0; i <= High - Low; ++i) {
            out[i] = access_.get(access_.ctx, offset_ + Low + i);
        }
        return out;
    }

    template <std::size_t High, std::size_t Low>
    slice_proxy<High, Low> operator[](bit_range_t<High, Low>) {
        static_assert(High >= Low, "High must be >= Low");
        static_assert(High < width(), "High must be < member width");
        return slice_proxy<High, Low>(access_, offset_);
    }

    template <std::size_t High, std::size_t Low>
    p5::uint<High - Low + 1> operator[](bit_range_t<High, Low>) const {
        return slice<High, Low>();
    }

    // Read as value_type (by value)
    operator value_type() const { return read(); }

    // Assign from same-width uint
    member &operator=(const value_type &rhs) {
        write_from(rhs);
        return *this;
    }

    // Assign from other-width uint: copy low bits, clear remaining bits within this member.
    template <std::size_t M>
    member &operator=(const p5::uint<M> &rhs) {
        write_from(rhs);
        return *this;
    }

    // Assign from integer: write low bits.
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<Integral> && !std::is_same_v<Integral, bool>>>
    member &operator=(Integral rhs) {
        write_from(rhs);
        return *this;
    }

    // Convenience: debug extraction (note: p5::uint::to_ullong may overflow if width>64).
    uint64_t to_ullong() const { return read().to_ullong(); }

    // ---- ergonomic operators (so member behaves like a "real variable") ----
    // Note: for operator expressions, C++不会通过隐式转换去引入 p5::uint 的成员运算符候选集，
    // 因此需要在 member 自身提供常用比较/算术运算符。

    // comparisons: member vs member
    bool operator==(const member &rhs) const { return read() == rhs.read(); }
    bool operator!=(const member &rhs) const { return read() != rhs.read(); }
    bool operator<(const member &rhs) const { return read() < rhs.read(); }
    bool operator<=(const member &rhs) const { return read() <= rhs.read(); }
    bool operator>(const member &rhs) const { return read() > rhs.read(); }
    bool operator>=(const member &rhs) const { return read() >= rhs.read(); }

    // comparisons: member vs uint<N>
    bool operator==(const value_type &rhs) const { return read() == rhs; }
    bool operator!=(const value_type &rhs) const { return read() != rhs; }
    bool operator<(const value_type &rhs) const { return read() < rhs; }
    bool operator<=(const value_type &rhs) const { return read() <= rhs; }
    bool operator>(const value_type &rhs) const { return read() > rhs; }
    bool operator>=(const value_type &rhs) const { return read() >= rhs; }

    // comparisons: member vs integral
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    bool operator==(Integral rhs) const {
        return read() == static_cast<uint64_t>(rhs);
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    bool operator!=(Integral rhs) const {
        return read() != static_cast<uint64_t>(rhs);
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    bool operator<(Integral rhs) const {
        return read() < static_cast<uint64_t>(rhs);
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    bool operator<=(Integral rhs) const {
        return read() <= static_cast<uint64_t>(rhs);
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    bool operator>(Integral rhs) const {
        return read() > static_cast<uint64_t>(rhs);
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    bool operator>=(Integral rhs) const {
        return read() >= static_cast<uint64_t>(rhs);
    }

    // arithmetic: member + (member/uint/integral) -> uint<N>
    value_type operator+(const member &rhs) const { return read() + rhs.read(); }
    value_type operator+(const value_type &rhs) const { return read() + rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator+(Integral rhs) const {
        return read() + value_type(rhs);
    }

    // arithmetic: -, *, /, %
    value_type operator-(const member &rhs) const { return read() - rhs.read(); }
    value_type operator-(const value_type &rhs) const { return read() - rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator-(Integral rhs) const {
        return read() - value_type(rhs);
    }

    value_type operator*(const member &rhs) const { return read() * rhs.read(); }
    value_type operator*(const value_type &rhs) const { return read() * rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator*(Integral rhs) const {
        return read() * value_type(rhs);
    }

    value_type operator/(const member &rhs) const { return read() / rhs.read(); }
    value_type operator/(const value_type &rhs) const { return read() / rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator/(Integral rhs) const {
        return read() / value_type(rhs);
    }

    value_type operator%(const member &rhs) const { return read() % rhs.read(); }
    value_type operator%(const value_type &rhs) const { return read() % rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator%(Integral rhs) const {
        return read() % value_type(rhs);
    }

    // bitwise: &, |, ^, ~
    value_type operator&(const member &rhs) const { return read() & rhs.read(); }
    value_type operator&(const value_type &rhs) const { return read() & rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator&(Integral rhs) const {
        return read() & value_type(rhs);
    }

    value_type operator|(const member &rhs) const { return read() | rhs.read(); }
    value_type operator|(const value_type &rhs) const { return read() | rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator|(Integral rhs) const {
        return read() | value_type(rhs);
    }

    value_type operator^(const member &rhs) const { return read() ^ rhs.read(); }
    value_type operator^(const value_type &rhs) const { return read() ^ rhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    value_type operator^(Integral rhs) const {
        return read() ^ value_type(rhs);
    }

    value_type operator~() const { return ~read(); }

    // shifts (match p5::uint signature: shift is size_t)
    value_type operator<<(std::size_t shift) const { return read() << shift; }
    value_type operator>>(std::size_t shift) const { return read() >> shift; }

    // compound assignments (read-modify-write)
    member &operator+=(const member &rhs) { return (*this += rhs.read()); }
    member &operator+=(const value_type &rhs) {
        auto tmp = read();
        tmp += rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator+=(Integral rhs) { return (*this += value_type(rhs)); }

    member &operator-=(const member &rhs) { return (*this -= rhs.read()); }
    member &operator-=(const value_type &rhs) {
        auto tmp = read();
        tmp -= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator-=(Integral rhs) { return (*this -= value_type(rhs)); }

    member &operator*=(const member &rhs) { return (*this *= rhs.read()); }
    member &operator*=(const value_type &rhs) {
        auto tmp = read();
        tmp *= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator*=(Integral rhs) { return (*this *= value_type(rhs)); }

    member &operator/=(const member &rhs) { return (*this /= rhs.read()); }
    member &operator/=(const value_type &rhs) {
        auto tmp = read();
        tmp /= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator/=(Integral rhs) { return (*this /= value_type(rhs)); }

    member &operator%=(const member &rhs) { return (*this %= rhs.read()); }
    member &operator%=(const value_type &rhs) {
        auto tmp = read();
        tmp %= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator%=(Integral rhs) { return (*this %= value_type(rhs)); }

    member &operator&=(const member &rhs) { return (*this &= rhs.read()); }
    member &operator&=(const value_type &rhs) {
        auto tmp = read();
        tmp &= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator&=(Integral rhs) { return (*this &= value_type(rhs)); }

    member &operator|=(const member &rhs) { return (*this |= rhs.read()); }
    member &operator|=(const value_type &rhs) {
        auto tmp = read();
        tmp |= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator|=(Integral rhs) { return (*this |= value_type(rhs)); }

    member &operator^=(const member &rhs) { return (*this ^= rhs.read()); }
    member &operator^=(const value_type &rhs) {
        auto tmp = read();
        tmp ^= rhs;
        *this = tmp;
        return *this;
    }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    member &operator^=(Integral rhs) { return (*this ^= value_type(rhs)); }

    member &operator<<=(std::size_t shift) {
        auto tmp = read();
        tmp <<= shift;
        *this = tmp;
        return *this;
    }

    member &operator>>=(std::size_t shift) {
        auto tmp = read();
        tmp >>= shift;
        *this = tmp;
        return *this;
    }

    // ++/--
    member &operator++() {
        auto tmp = read();
        ++tmp;
        *this = tmp;
        return *this;
    }
    value_type operator++(int) {
        auto old = read();
        ++(*this);
        return old;
    }
    member &operator--() {
        auto tmp = read();
        --tmp;
        *this = tmp;
        return *this;
    }
    value_type operator--(int) {
        auto old = read();
        --(*this);
        return old;
    }

    // integral-lhs convenience (ADL via friend)
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend bool operator==(Integral lhs, const member &rhs) { return rhs == lhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend bool operator!=(Integral lhs, const member &rhs) { return rhs != lhs; }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend bool operator<(Integral lhs, const member &rhs) { return value_type(lhs) < rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend bool operator<=(Integral lhs, const member &rhs) { return value_type(lhs) <= rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend bool operator>(Integral lhs, const member &rhs) { return value_type(lhs) > rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend bool operator>=(Integral lhs, const member &rhs) { return value_type(lhs) >= rhs.read(); }

    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend value_type operator+(Integral lhs, const member &rhs) { return value_type(lhs) + rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend value_type operator-(Integral lhs, const member &rhs) { return value_type(lhs) - rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend value_type operator&(Integral lhs, const member &rhs) { return value_type(lhs) & rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend value_type operator|(Integral lhs, const member &rhs) { return value_type(lhs) | rhs.read(); }
    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<std::decay_t<Integral>> && !std::is_same_v<std::decay_t<Integral>, bool>>>
    friend value_type operator^(Integral lhs, const member &rhs) { return value_type(lhs) ^ rhs.read(); }

private:
    detail_p5_union::bit_access access_{};
    std::size_t offset_{0};

    template <std::size_t StorageBits>
    void bind(p5::uint<StorageBits> &storage, std::size_t offset) {
        static_assert(StorageBits > 0, "StorageBits must be > 0");
        static_assert(offset + width() <= StorageBits, "member out of bound");
        access_ = detail_p5_union::make_access(storage);
        offset_ = offset;
    }

    void bind_view(detail_p5_union::bit_access access, std::size_t offset) {
        access_ = access;
        offset_ = offset;
    }

    value_type read() const {
        // Unbound members read as zero.
        value_type out{};
        if (!access_.get) return out;
        for (std::size_t i = 0; i < width(); ++i) {
            out[i] = access_.get(access_.ctx, offset_ + i);
        }
        return out;
    }

    template <std::size_t M>
    void write_from(const p5::uint<M> &rhs) {
        if (!access_.set) return; // silently ignore if unbound
        constexpr std::size_t copy_width = (M < width()) ? M : width();
        for (std::size_t i = 0; i < copy_width; ++i) {
            access_.set(access_.ctx, offset_ + i, rhs[i]);
        }
        if constexpr (width() > copy_width) {
            for (std::size_t i = copy_width; i < width(); ++i) {
                access_.set(access_.ctx, offset_ + i, false);
            }
        }
    }

    void write_from(uint64_t rhs) {
        if (!access_.set) return;
        for (std::size_t i = 0; i < width(); ++i) {
            access_.set(access_.ctx, offset_ + i, (rhs >> i) & 1ULL);
        }
    }

    friend struct detail_p5_union::detail_union_binder;
    template <typename Layout>
    friend class Union;
};

template <typename UIntT>
struct bit_width<p5::member<UIntT>, void> : std::integral_constant<std::size_t, p5::member<UIntT>::width()> {};

// Forward declaration
template <typename Layout>
class Union;

namespace detail_p5_union {

template <typename T>
constexpr std::size_t aggregate_width();

template <typename T, std::size_t... I>
constexpr std::size_t aggregate_width_impl(std::index_sequence<I...>) {
    return (p5::bit_width_v<typename boost::pfr::tuple_element_t<I, T>> + ... + 0);
}

template <typename T>
constexpr std::size_t aggregate_width() {
    constexpr std::size_t fields = boost::pfr::tuple_size_v<T>;
    return aggregate_width_impl<T>(std::make_index_sequence<fields>{});
}

template <typename Layout, std::size_t... I>
constexpr std::size_t union_width_impl(std::index_sequence<I...>) {
    std::size_t m = 0;
    ((m = (p5::bit_width_v<typename boost::pfr::tuple_element_t<I, Layout>> > m
               ? p5::bit_width_v<typename boost::pfr::tuple_element_t<I, Layout>>
               : m)),
     ...);
    return m;
}

template <typename Layout>
constexpr std::size_t union_width() {
    constexpr std::size_t fields = boost::pfr::tuple_size_v<Layout>;
    static_assert(fields > 0, "p5::Union<Layout> requires Layout to have at least one field");
    return union_width_impl<Layout>(std::make_index_sequence<fields>{});
}

// ---- binding (offset assignment) ----
struct detail_union_binder {
    // Leaf member<uint<N>>
    template <typename UIntT>
    static void bind_any(p5::member<UIntT> &m, bit_access access, std::size_t offset) {
        m.bind_view(access, offset);
    }

    // Nested Union<Layout>
    template <typename Layout>
    static void bind_any(p5::Union<Layout> &u, bit_access access, std::size_t offset) {
        u.bind_view(access, offset);
    }

    // Aggregate struct: bind its fields sequentially starting from offset
    template <typename Agg>
    static void bind_any(Agg &agg, bit_access access, std::size_t offset) {
        static_assert(std::is_aggregate_v<Agg>,
                      "Union member must be p5::member<p5::uint<N>>, p5::Union<...>, or an aggregate thereof.");
        bind_aggregate(agg, access, offset);
    }

    template <typename Agg, std::size_t... I>
    static void bind_aggregate_impl(Agg &agg, bit_access access, std::size_t base, std::index_sequence<I...>) {
        // Compute per-field offsets as prefix sums.
        std::size_t cur = base;
        auto bind_one = [&](auto &field) {
            bind_any(field, access, cur);
            using FieldT = std::decay_t<decltype(field)>;
            cur += p5::bit_width_v<FieldT>;
        };
        (bind_one(boost::pfr::get<I>(agg)), ...);
    }

    template <typename Agg>
    static void bind_aggregate(Agg &agg, bit_access access, std::size_t base) {
        constexpr std::size_t fields = boost::pfr::tuple_size_v<Agg>;
        bind_aggregate_impl(agg, access, base, std::make_index_sequence<fields>{});
    }
};

}  // namespace detail_p5_union

template <typename T>
struct bit_width<T, std::enable_if_t<std::is_aggregate_v<std::decay_t<T>>>> : std::integral_constant<std::size_t, detail_p5_union::aggregate_width<std::decay_t<T>>()> {};

template <typename Layout>
class Union : public Layout {
public:
    static constexpr std::size_t width() { return detail_p5_union::union_width<Layout>(); }
    using storage_type = p5::uint<width()>;

    Union() : Layout{} {
        access_ = detail_p5_union::make_access(storage_);
        base_offset_ = 0;
        bind_members();
    }

    // Copy: copy bits, then re-bind all views to this.storage_
    Union(const Union &other) : Layout{} {
        access_ = detail_p5_union::make_access(storage_);
        base_offset_ = 0;
        copy_bits_from(other);
        bind_members();
    }

    Union &operator=(const Union &other) {
        if (this == &other) return *this;
        // keep bound to our own storage_
        copy_bits_from(other);
        bind_members();
        return *this;
    }

    // Convert to raw uint<width>
    operator storage_type() const { return to_uint(); }

    Union &operator=(const storage_type &rhs) {
        set_from_uint(rhs);
        return *this;
    }

    template <std::size_t M>
    Union &operator=(const p5::uint<M> &rhs) {
        set_from_uint(rhs);
        return *this;
    }

    template <typename Integral,
              typename = std::enable_if_t<std::is_integral_v<Integral> && !std::is_same_v<Integral, bool>>>
    Union &operator=(Integral rhs) {
        storage_ = static_cast<uint64_t>(rhs);
        return *this;
    }

    storage_type to_uint() const {
        storage_type out{};
        for (std::size_t i = 0; i < width(); ++i) {
            out[i] = access_.get(access_.ctx, base_offset_ + i);
        }
        return out;
    }

    uint64_t to_ullong() const { return to_uint().to_ullong(); }

private:
    storage_type storage_{};
    detail_p5_union::bit_access access_{};
    std::size_t base_offset_{0};

    void bind_members() {
        // Top-level union fields all start at base_offset_
        constexpr std::size_t fields = boost::pfr::tuple_size_v<Layout>;
        bind_members_impl(std::make_index_sequence<fields>{});
    }

    template <std::size_t... I>
    void bind_members_impl(std::index_sequence<I...>) {
        auto &layout = static_cast<Layout &>(*this);
        (detail_p5_union::detail_union_binder::bind_any(boost::pfr::get<I>(layout), access_, base_offset_), ...);
    }

    template <std::size_t M>
    void set_from_uint(const p5::uint<M> &rhs) {
        constexpr std::size_t copy_width = (M < width()) ? M : width();
        for (std::size_t i = 0; i < copy_width; ++i) {
            storage_[i] = rhs[i];
        }
        if constexpr (width() > copy_width) {
            for (std::size_t i = copy_width; i < width(); ++i) {
                storage_[i] = false;
            }
        }
    }

    void copy_bits_from(const Union &other) {
        // Copy bits via view (works even if other is view-bound in future extensions).
        auto v = other.to_uint();
        set_from_uint(v);
    }

    // Bind this union object as a view into an external storage.
    void bind_view(detail_p5_union::bit_access access, std::size_t base_offset) {
        access_ = access;
        base_offset_ = base_offset;
        bind_members();
    }

    friend struct detail_p5_union::detail_union_binder;
};

template <typename Layout>
struct bit_width<p5::Union<Layout>, void> : std::integral_constant<std::size_t, p5::Union<Layout>::width()> {};

// ---- factory helpers (for "anonymous layout") ----
namespace detail_p5_union {
template <typename Factory>
using layout_from_factory_t = std::decay_t<decltype(std::declval<Factory &>()())>;
}  // namespace detail_p5_union

/**
 * @brief Create a p5::Union whose Layout type is deduced from a factory callable.
 *
 * The callable is never evaluated; it's only used for type deduction via decltype.
 *
 * Example:
 *   auto u = p5::make_union([]{
 *     struct Layout { p5::member<p5::uint<10>> a; p5::member<p5::uint<2>> b; };
 *     return Layout{};
 *   });
 */
template <typename Factory>
inline auto make_union(Factory &&) {
    using Layout = detail_p5_union::layout_from_factory_t<Factory>;
    return p5::Union<Layout>{};
}

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

// =========================
//  Convenience macros
// =========================
//
// These macros provide a "factory-like" way to define an unnamed Layout (via a local struct)
// and immediately obtain a p5::Union<Layout> object.
//
// Usage:
//   auto u = P5_MAKE_UNION({
//       p5::member<p5::uint<10>> long_;
//       p5::member<p5::uint<2>>  short_;
//       struct { p5::member<p5::uint<3>> a; p5::member<p5::uint<3>> b; } st;
//   });
//
// Or declare a named variable:
//   P5_DECLARE_UNION(U, {
//       p5::member<p5::uint<10>> long_;
//       // ...
//   });
//
#define P5_DETAIL_CONCAT_INNER(a, b) a##b
#define P5_DETAIL_CONCAT(a, b) P5_DETAIL_CONCAT_INNER(a, b)

// Unified macro: can be used to declare a p5::Union variable (in function/global scope)
// or a nested p5::Union member (inside another Layout/struct).
//
// Usage:
//   P5_UNION(u, { p5::member<p5::uint<10>> a; });
//   struct L { P5_UNION(alt, { p5::member<p5::uint<6>> x; }); };
#define P5_UNION(name, layout_body) P5_UNION_IMPL(__COUNTER__, name, layout_body)
#define P5_UNION_IMPL(id, name, layout_body)                                           \
    struct P5_DETAIL_CONCAT(_p5_union_layout_decl_, id) layout_body;                   \
    ::p5::Union<P5_DETAIL_CONCAT(_p5_union_layout_decl_, id)> name

// Backward-compatible alias (kept for existing code)
#define P5_UNION_MEMBER(name, layout_body) P5_UNION(name, layout_body)

#define P5_MAKE_UNION(layout_body) P5_MAKE_UNION_IMPL(__COUNTER__, layout_body)
#define P5_MAKE_UNION_IMPL(id, layout_body)                                            \
    ::p5::make_union([&]() {                                                           \
        struct P5_DETAIL_CONCAT(_p5_union_layout_, id) layout_body;                    \
        return P5_DETAIL_CONCAT(_p5_union_layout_, id){};                              \
    })

// Backward-compatible alias. Prefer P5_UNION(name, { ... }) for a single-macro style.
#define P5_DECLARE_UNION(var_name, layout_body) P5_UNION(var_name, layout_body)

// 为了兼容 P5 代码，可以使用全局命名空间
// 注释掉以避免与系统 uint 冲突
// using p5::uint;

#endif // P5_TYPES_HPP

