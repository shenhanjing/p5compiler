#ifndef GENERATED_ENUM_HPP
#define GENERATED_ENUM_HPP

#include "table.hpp"
#include "SE.hpp"
#include "key.hpp"
#include "BuiltIn.hpp"
#include "p5_types.hpp"
#include "model_intf_1027.h"

enum RSP_STATUS_E {
    RSP_STATUS_MATCH = 0,
    RSP_STATUS_NO_MATCH = 1,
    RSP_STATUS_LOOKUP_SKIPPED = 2,
    RSP_STATUS_ERROR = 3
};

enum TLB_LKUP_TYPE_E {
    TBL_LKUP_TYPE_INDEX = 0,
    TBL_LKUP_TYPE_EM = 1,
    TBL_LKUP_TYPE_LPM = 3,
    TBL_LKUP_TYPE_TCAM = 4
};

enum SE_TID_E {
    SE_TID_IPAT = 0,
    SE_TID_FIB = 1,
    SE_TID_EPAT = 2,
    SE_TID_ENCAP = 3
};

enum PORT_TYPE_E {
    PORT_TYPE_ETH = 0,
    PORT_TYPE_CPU = 1,
    PORT_TYPE_STACK = 2
};

enum PHO_OFFSETS_E {
    PHO_OUTER_L2_START = 0,
    PHO_OUTER_VLANS_START = 1,
    PHO_OUTER_L3_START = 2,
    PHO_OUTER_L4_START = 3
};

enum L4_PROTOCOL_E {
    L4_PROTOCOL_NONE = 0,
    L4_PROTOCOL_TCP = 10,
    L4_PROTOCOL_UDP = 32
};

enum L2_TYPE_E {
    L2_TYPE_INVALID = 0,
    L2_TYPE_ETHERNET = 1,
    L2_TYPE_OTHER = 2,
    L2_TYPE_RES = 3
};

enum VLAN_TYPE_E {
    VLAN_UNTAGGED = 0,
    VLAN_SINGLE_TAGGED = 1,
    VLAN_DOUBLE_TAGGED = 2,
    VLAN_TRIPLE_TAGGED = 3
};

enum L3_TYPE_E {
    L3_TYPE_INVALID = 0,
    L3_TYPE_NON_IP = 1,
    L3_TYPE_IPv4 = 2,
    L3_TYPE_IPv6 = 3
};

#endif // GENERATED_ENUM_HPP
