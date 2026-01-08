#pragma once
#include <iostream>

#include "ir/ir.h"

namespace P4 {

typedef std::pair<const IR::Expression *, const IR::Constant *> CaseValue;

inline std::ostream &operator<<(std::ostream &out, const CaseValue &caseValue) {
    out << "CaseValue(" << caseValue.first << ',' << caseValue.second << ')';
    return out;
}

}  // namespace P4
