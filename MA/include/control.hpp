#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "BuiltIn.hpp"
#include "generated_gtv.hpp"

// control 基类：同时持有 GTV 字段与 search engine/key 的访问能力
class Control : public GtvContext, public BuiltInContext {
public:
    Control(SearchEngine &se, KeyManager &key) : BuiltInContext(se, key) {}
    virtual ~Control() = default;
};

#endif // CONTROL_HPP

