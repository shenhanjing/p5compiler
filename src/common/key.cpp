#include "key.hpp"

KeyManager g_key;

std::unique_ptr<KeyManager::BaseSlot> KeyManager::makeSlot(std::size_t bits) {
    if (bits == 0 || bits > 256) return nullptr;
    return makeSlotRec<1>(bits);
}

template <std::size_t Cur>
std::unique_ptr<KeyManager::BaseSlot> KeyManager::makeSlotRec(std::size_t bits) {
    if (bits == Cur) return std::make_unique<KeyManager::Slot<Cur>>();
    if constexpr (Cur < 256) {
        return makeSlotRec<Cur + 1>(bits);
    } else {
        return nullptr;
    }
}

void KeyManager::initKey(std::initializer_list<std::size_t> bitWidths) {
    initKey(std::vector<std::size_t>(bitWidths));
}

void KeyManager::initKey(const std::vector<std::size_t> &bitWidths) {
    slots_.clear();
    slots_.reserve(bitWidths.size());
    for (auto b : bitWidths) {
        if (auto slot = makeSlot(b)) {
            slots_.push_back(std::move(slot));
        }
    }
}

int KeyManager::findSlotByBits(std::size_t bits) const {
    for (std::size_t i = 0; i < slots_.size(); ++i) {
        if (slots_[i] && slots_[i]->bits() == bits) return static_cast<int>(i);
    }
    return -1;
}

void KeyManager::buildKey(std::initializer_list<KeyPart> parts) {
    buildKey(std::vector<KeyPart>(parts));
}

void KeyManager::buildKey(const std::vector<KeyPart> &parts) {
    std::vector<bool> bitsVec;
    for (const auto &p : parts) {
        append_bits(p, bitsVec);
    }
    std::size_t totalBits = bitsVec.size();

    int idx = findSlotByBits(totalBits);
    if (idx < 0) return;  // no matching slot; ignore

    slots_[idx]->setBits(bitsVec);
}

std::optional<std::vector<bool>> KeyManager::getKeyBits(std::size_t bits) const {
    int idx = findSlotByBits(bits);
    if (idx < 0) return std::nullopt;
    return slots_[idx]->dumpBits();
}
