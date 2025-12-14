#include "key.h"

#include <algorithm>

KeyManager g_key;

void KeyManager::initKey(std::initializer_list<std::size_t> bitWidths) {
    initKey(std::vector<std::size_t>(bitWidths));
}

void KeyManager::initKey(const std::vector<std::size_t> &bitWidths) {
    slots_.clear();
    slots_.reserve(bitWidths.size());
    for (auto b : bitWidths) {
        slots_.push_back(Slot{b, 0});
    }
}

uint64_t KeyManager::packParts(const std::vector<KeyPart> &parts) {
    uint64_t result = 0;
    for (const auto &p : parts) {
        if (p.bits >= 64) {
            // For simplicity, only support up to 64 bits per part in this demo.
            uint64_t masked = p.value;
            result = (result << 63) | (masked & ((uint64_t{1} << 63) - 1));
        } else {
            uint64_t mask = (p.bits == 64) ? ~uint64_t{0} : ((uint64_t{1} << p.bits) - 1);
            uint64_t masked = p.value & mask;
            result = (result << p.bits) | masked;
        }
    }
    return result;
}

int KeyManager::findSlotByBits(std::size_t bits) const {
    for (std::size_t i = 0; i < slots_.size(); ++i) {
        if (slots_[i].bits == bits) return static_cast<int>(i);
    }
    return -1;
}

void KeyManager::buildKey(std::initializer_list<KeyPart> parts) {
    buildKey(std::vector<KeyPart>(parts));
}

void KeyManager::buildKey(const std::vector<KeyPart> &parts) {
    std::size_t totalBits = 0;
    for (const auto &p : parts) totalBits += p.bits;

    int idx = findSlotByBits(totalBits);
    if (idx < 0) return;  // no matching slot; ignore

    uint64_t packed = packParts(parts);
    slots_[idx].value = packed;
}

std::optional<uint64_t> KeyManager::getKeyRaw(std::size_t bits) const {
    int idx = findSlotByBits(bits);
    if (idx < 0) return std::nullopt;
    return slots_[idx].value;
}
