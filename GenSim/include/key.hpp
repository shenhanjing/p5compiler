#ifndef KEY_HPP
#define KEY_HPP

#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <memory>
#include <optional>
#include <type_traits>
#include <utility>
#include <vector>

#include <boost/pfr.hpp>

#include "p5_types.hpp"

struct KeyPart {
    uint64_t value;
    std::size_t bits;
};

// KeyManager holds multiple key slots of different bitwidths.
// At init time the bitwidths are fixed; buildKey picks the slot whose
// bitwidth equals the sum of input parts. getKey retrieves by specifying
// the desired bitwidth explicitly.
class KeyManager {
public:
    // Incremental key construction helper:
    // - Call append(...) across multiple control branches/switches
    // - Call commit() once before lookup to write into the matching key slot
    class KeyBuilder {
    public:
        explicit KeyBuilder(KeyManager &km) : km_(km) {}

        void reset() { bits_.clear(); }
        std::size_t bits() const { return bits_.size(); }

        template <typename Part>
        void append(const Part &part) {
            // Reuse KeyManager's bit extraction rules (p5::uint, p5::member, KeyPart)
            KeyManager::append_bits(part, bits_);
        }

        template <typename... Parts>
        void appendMany(const Parts &...parts) {
            (append(parts), ...);
        }

        // Commit the accumulated bits into the slot whose bitwidth matches.
        // Returns true if a slot matched and was updated.
        bool commit() {
            const std::size_t totalBits = bits_.size();
            int idx = km_.findSlotByBits(totalBits);
            if (idx < 0) return false;
            km_.slots_[idx]->setBits(bits_);
            return true;
        }

    private:
        KeyManager &km_;
        std::vector<bool> bits_;
    };

    void initKey(std::initializer_list<std::size_t> bitWidths);
    void initKey(const std::vector<std::size_t> &bitWidths);

    void buildKey(std::initializer_list<KeyPart> parts);
    void buildKey(const std::vector<KeyPart> &parts);

    template <typename... Parts>
    void buildKey(const Parts &...parts);

    template <typename T>
    T getKey(std::size_t bits) const;
    std::optional<std::vector<bool>> getKeyBits(std::size_t bits) const;

    // Assign current key bits into an output variable.
    // Supports:
    // - p5::uint<N>
    // - p5::member<p5::uint<N>> (must be view-bound to storage, e.g. inside p5::Union)
    // - p5::Union<Layout>
    // - aggregate structs composed of the above (can be nested)
    // Returns true if a matching key slot exists and assignment is performed.
    template <typename T>
    bool tryAssignKey(T &out) const;

    // Assign and return the output variable itself so callers can write:
    //   out = _key(out);
    // If no matching slot exists, out is left unchanged and returned.
    template <typename T>
    T &assignKey(T &out) const;

    // Create a builder for incremental key construction.
    KeyBuilder keyBuilder() { return KeyBuilder(*this); }

private:
    friend class KeyBuilder;
    struct BaseSlot {
        virtual ~BaseSlot() = default;
        virtual std::size_t bits() const = 0;
        virtual void setBits(const std::vector<bool> &bits) = 0;
        virtual std::vector<bool> dumpBits() const = 0;
    };

    template <std::size_t Bits>
    struct Slot : BaseSlot {
        std::size_t bits() const override { return Bits; }
        void setBits(const std::vector<bool> &bitsVec) override {
            value_ = p5::uint<Bits>::from_bits(bitsVec);
        }
        std::vector<bool> dumpBits() const override {
            std::vector<bool> out;
            out.reserve(Bits);
            for (std::size_t i = 0; i < Bits; ++i) {
                out.push_back(value_[Bits - 1 - i]);
            }
            return out;
        }
        p5::uint<Bits> value_{};
    };

    std::vector<std::unique_ptr<BaseSlot>> slots_;

    int findSlotByBits(std::size_t bits) const;
    static std::unique_ptr<BaseSlot> makeSlot(std::size_t bits);
    template <std::size_t Cur>
    static std::unique_ptr<BaseSlot> makeSlotRec(std::size_t bits);

    // ---- helpers for bit extraction/packing ----
    template <typename T>
    struct is_p5_uint_type : std::false_type {};
    template <std::size_t N>
    struct is_p5_uint_type<p5::uint<N>> : std::true_type {};

    template <typename T>
    struct is_p5_member_type : std::false_type {};
    template <typename UIntT>
    struct is_p5_member_type<p5::member<UIntT>> : std::true_type {};

    template <typename T>
    static constexpr bool is_p5_uint() {
        return is_p5_uint_type<std::decay_t<T>>::value;
    }

    template <typename T>
    static constexpr bool is_p5_member() {
        return is_p5_member_type<std::decay_t<T>>::value;
    }

    template <typename T>
    static constexpr std::size_t bit_width_of();

    template <typename T>
    static std::size_t part_width(const T &value);

    template <typename T>
    static void append_bits(const T &value, std::vector<bool> &out);

    template <typename... Parts>
    static std::vector<bool> collect_bits(const Parts &...parts);

    // ---- helpers for assignKey ----
    template <typename T>
    struct is_p5_union_type : std::false_type {};
    template <typename Layout>
    struct is_p5_union_type<p5::Union<Layout>> : std::true_type {};

    template <typename T>
    static constexpr bool is_p5_union() {
        return is_p5_union_type<std::decay_t<T>>::value;
    }

    template <typename Field>
    static void assign_bits_from_vector(const std::vector<bool> &bits, std::size_t &cursor, Field &target) {
        using Decayed = std::decay_t<Field>;
        constexpr std::size_t width = p5::bit_width_v<Decayed>;
        p5::uint<width> tmp{};
        // bits vector is MSB-first; assign tmp[width-1]..tmp[0].
        for (std::size_t i = 0; i < width && cursor < bits.size(); ++i, ++cursor) {
            tmp[width - 1 - i] = bits[cursor];
        }
        // For p5::uint / p5::member / p5::Union: assignment writes to underlying storage/view.
        target = tmp;
    }

    template <typename Field>
    static void decode_any(const std::vector<bool> &bits, std::size_t &cursor, Field &target) {
        using Decayed = std::decay_t<Field>;
        if constexpr (is_p5_uint<Decayed>() || is_p5_member<Decayed>() || is_p5_union<Decayed>()) {
            assign_bits_from_vector(bits, cursor, target);
        } else {
            static_assert(std::is_aggregate_v<Decayed>,
                          "assignKey supports only p5::uint/p5::member/p5::Union or aggregates composed of them.");
            boost::pfr::for_each_field(target, [&](auto &sub) { decode_any(bits, cursor, sub); });
        }
    }
};

extern KeyManager g_key;

// ---- template impl ----
namespace detail_keymgr {
template <typename...>
struct always_false : std::false_type {};

template <std::size_t N>
inline void append_uint_bits(const p5::uint<N> &v, std::vector<bool> &out) {
    for (std::size_t i = 0; i < N; ++i) {
        out.push_back(v[N - 1 - i]);
    }
}

template <typename UIntT>
inline void append_member_bits(const p5::member<UIntT> &m, std::vector<bool> &out) {
    constexpr std::size_t N = p5::member<UIntT>::width();
    for (std::size_t i = 0; i < N; ++i) {
        out.push_back(m[N - 1 - i]);
    }
}
}  // namespace detail_keymgr

template <typename T>
constexpr std::size_t KeyManager::bit_width_of() {
    using Decayed = std::decay_t<T>;
    static_assert(is_p5_uint<Decayed>() || is_p5_member<Decayed>(),
                  "KeyManager only supports p5::uint<N> or p5::member<p5::uint<N>> components");
    if constexpr (is_p5_uint<Decayed>()) {
        return Decayed::width();
    } else {
        return Decayed::width();
    }
}

template <typename T>
std::size_t KeyManager::part_width(const T &value) {
    if constexpr (std::is_same_v<T, KeyPart>) {
        return value.bits;
    } else {
        return bit_width_of<T>();
    }
}

template <typename T>
void KeyManager::append_bits(const T &value, std::vector<bool> &out) {
    if constexpr (is_p5_uint<T>()) {
        detail_keymgr::append_uint_bits(value, out);
    } else if constexpr (is_p5_member<T>()) {
        detail_keymgr::append_member_bits(value, out);
    } else if constexpr (std::is_same_v<T, KeyPart>) {
        // KeyPart.value is interpreted with high bit first over 'bits' width.
        for (std::size_t i = 0; i < value.bits; ++i) {
            std::size_t shift = value.bits - 1 - i;
            out.push_back((value.value >> shift) & 1);
        }
    } else {
        static_assert(detail_keymgr::always_false<T>::value, "Unsupported key component type");
    }
}

template <typename... Parts>
std::vector<bool> KeyManager::collect_bits(const Parts &...parts) {
    std::vector<bool> bits;
    bits.reserve((part_width(parts) + ... + 0));
    (append_bits(parts, bits), ...);
    return bits;
}

template <typename... Parts>
void KeyManager::buildKey(const Parts &...parts) {
    auto bitsVec = collect_bits(parts...);
    std::size_t totalBits = bitsVec.size();
    int idx = findSlotByBits(totalBits);
    if (idx < 0) return;
    slots_[idx]->setBits(bitsVec);
}

template <typename T>
T KeyManager::getKey(std::size_t bits) const {
    auto bitsOpt = getKeyBits(bits);
    if (!bitsOpt) return T{};
    const auto &bv = *bitsOpt;
    static_assert(is_p5_uint<T>(), "KeyManager getKey only supports p5::uint<N>");
    return T::from_bits(bv);
}

template <typename T>
bool KeyManager::tryAssignKey(T &out) const {
    using Decayed = std::decay_t<T>;
    constexpr std::size_t bits = p5::bit_width_v<Decayed>;
    auto bitsOpt = getKeyBits(bits);
    if (!bitsOpt) return false;
    const auto &bv = *bitsOpt; // MSB-first
    std::size_t cursor = 0;
    decode_any(bv, cursor, out);
    return true;
}

template <typename T>
T &KeyManager::assignKey(T &out) const {
    (void)tryAssignKey(out);
    return out;
}

#endif // KEY_HPP