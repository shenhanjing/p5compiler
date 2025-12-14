#pragma once

#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <optional>
#include <vector>

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
    void initKey(std::initializer_list<std::size_t> bitWidths);
    void initKey(const std::vector<std::size_t> &bitWidths);

    void buildKey(std::initializer_list<KeyPart> parts);
    void buildKey(const std::vector<KeyPart> &parts);

    template <typename T>
    T getKey(std::size_t bits) const;
    std::optional<uint64_t> getKeyRaw(std::size_t bits) const;

private:
    struct Slot {
        std::size_t bits = 0;
        uint64_t value = 0;
    };

    std::vector<Slot> slots_;

    static uint64_t packParts(const std::vector<KeyPart> &parts);
    int findSlotByBits(std::size_t bits) const;
};

extern KeyManager g_key;

// ---- template impl ----
template <typename T>
T KeyManager::getKey(std::size_t bits) const {
    auto rawOpt = getKeyRaw(bits);
    auto raw = rawOpt.value_or(0);
    return static_cast<T>(raw);
}


