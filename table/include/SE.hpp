#pragma once

#include <any>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <utility>


// Supported match types for search tables.
// Ensure numeric values align with TLB_LKUP_TYPE_E in tests (INDEX=0, EXACT=1, LPM=3, TCAM=4).
enum class MatchType {
    INDEX = 0,
    EXACT = 1,
    LPM = 3,
    TCAM = 4
};

// SearchEngine provides a simple in-memory lookup facility keyed by table ID.
// Different tables can carry different key/response types; type consistency is
// enforced per table ID at runtime via dynamic dispatch per match type.
class SearchEngine {
public:
    enum class Status : uint8_t {
        MATCH = 0,
        NO_MATCH = 1,
        LOOKUP_SKIPPED = 2,
        ERROR = 3
    };

    template <typename Key, typename Value>
    void initTable(int tableId, MatchType matchType);

    template <typename Key, typename Value>
    void config(int tableId, const Key &key, const Value &value);

    template <typename Key, typename Value>
    std::optional<Value> lookup(int tableId, MatchType matchType, const Key &key);

    Status status(int tableId) const;

private:
    struct BaseTable {
        virtual ~BaseTable() = default;
        virtual MatchType matchType() const = 0;
        virtual std::type_index keyType() const = 0;
        virtual std::type_index valueType() const = 0;
        virtual void setStatus(Status s) = 0;
        virtual Status lastStatus() const = 0;
        virtual void reset() = 0;
        virtual void configAny(const void *key, const void *value) = 0;
        virtual std::optional<std::any> lookupAny(const void *key) = 0;
    };

    template <typename Key>
    static std::string toBytes(const Key &key);

    template <typename Key, typename Value>
    class IndexTable : public BaseTable {
    public:
        explicit IndexTable(MatchType mt) : mt_(mt) {}

        MatchType matchType() const override { return mt_; }
        std::type_index keyType() const override { return std::type_index(typeid(Key)); }
        std::type_index valueType() const override { return std::type_index(typeid(Value)); }
        void setStatus(Status s) override { status_ = s; }
        Status lastStatus() const override { return status_; }
        void reset() override { entries_.clear(); status_ = Status::LOOKUP_SKIPPED; }

        void configAny(const void *key, const void *value) override {
            const Key &k = *reinterpret_cast<const Key *>(key);
            const Value &v = *reinterpret_cast<const Value *>(value);
            entries_[toBytes(k)] = v;
            status_ = Status::MATCH;
        }

        std::optional<std::any> lookupAny(const void *key) override {
            const Key &k = *reinterpret_cast<const Key *>(key);
            auto it = entries_.find(toBytes(k));
            if (it == entries_.end()) {
                status_ = Status::NO_MATCH;
                return std::nullopt;
            }
            status_ = Status::MATCH;
            return it->second;
        }

    private:
        MatchType mt_;
        Status status_{Status::LOOKUP_SKIPPED};
        std::unordered_map<std::string, Value> entries_;
    };

    // Placeholders for future match types; can be specialized later.
    template <typename Key, typename Value>
    using ExactTable = IndexTable<Key, Value>;
    template <typename Key, typename Value>
    using LpmTable = IndexTable<Key, Value>;
    template <typename Key, typename Value>
    using TcamTable = IndexTable<Key, Value>;

    template <typename Key, typename Value>
    std::unique_ptr<BaseTable> makeTable(MatchType matchType);

    std::unordered_map<int, std::unique_ptr<BaseTable>> tables_;
};

extern SearchEngine g_se;

// -------- Template definitions --------

template <typename Key>
std::string SearchEngine::toBytes(const Key &key) {
    static_assert(std::is_trivially_copyable<Key>::value, "Key must be trivially copyable");
    const char *ptr = reinterpret_cast<const char *>(&key);
    return std::string(ptr, ptr + sizeof(Key));
}

template <typename Key, typename Value>
void SearchEngine::initTable(int tableId, MatchType matchType) {
    tables_[tableId] = makeTable<Key, Value>(matchType);
}

template <typename Key, typename Value>
void SearchEngine::config(int tableId, const Key &key, const Value &value) {
    if (!tables_.count(tableId)) {
        initTable<Key, Value>(tableId, MatchType::INDEX);
    }
    auto *tbl = tables_[tableId].get();
    if (tbl->keyType() != std::type_index(typeid(Key)) || tbl->valueType() != std::type_index(typeid(Value))) {
        tbl->setStatus(Status::ERROR);
        return;
    }
    tbl->configAny(&key, &value);
}

template <typename Key, typename Value>
std::optional<Value> SearchEngine::lookup(int tableId, MatchType matchType, const Key &key) {
    auto it = tables_.find(tableId);
    if (it == tables_.end()) {
        return std::nullopt;
    }
    auto *tbl = it->second.get();
    if (tbl->matchType() != matchType || tbl->keyType() != std::type_index(typeid(Key)) ||
        tbl->valueType() != std::type_index(typeid(Value))) {
        tbl->setStatus(Status::ERROR);
        return std::nullopt;
    }

    auto result = tbl->lookupAny(&key);
    if (!result) return std::nullopt;
    return std::any_cast<Value>(*result);
}

inline SearchEngine::Status SearchEngine::status(int tableId) const {
    auto it = tables_.find(tableId);
    if (it == tables_.end()) {
        return Status::LOOKUP_SKIPPED;
    }
    return it->second->lastStatus();
}

template <typename Key, typename Value>
std::unique_ptr<SearchEngine::BaseTable> SearchEngine::makeTable(MatchType matchType) {
    switch (matchType) {
        case MatchType::INDEX:
            return std::make_unique<IndexTable<Key, Value>>(matchType);
        case MatchType::EXACT:
            return std::make_unique<ExactTable<Key, Value>>(matchType);
        case MatchType::LPM:
            return std::make_unique<LpmTable<Key, Value>>(matchType);
        case MatchType::TCAM:
            return std::make_unique<TcamTable<Key, Value>>(matchType);
        default:
            return std::make_unique<IndexTable<Key, Value>>(MatchType::INDEX);
    }
}
