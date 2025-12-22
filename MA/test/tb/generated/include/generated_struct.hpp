#ifndef GENERATED_STRUCT_HPP
#define GENERATED_STRUCT_HPP

#include "table.hpp"
#include "SE.hpp"
#include "key.hpp"
#include "BuiltIn.hpp"
#include "p5_types.hpp"
#include "model_intf_1027.h"

#include "generated_enum.hpp"

struct PHI_S {
    p5::uint<4> PortType;
    p5::uint<2> L2Type;
    p5::uint<2> TagType;
    p5::uint<2> L3Type;
    p5::uint<8> L4Type;
};

struct ETHER_S {
    p5::uint<48> Dmac;
    p5::uint<48> Smac;
};

struct VlanInfo_S {
    p5::uint<3> Pri;
    p5::uint<1> Dei;
    p5::uint<12> VlanID;
};

struct VLAN_TAG_S {
    p5::uint<16> Tpid;
    VlanInfo_S VlanInfo;
};

struct ETHER_TYPE_S {
    p5::uint<16> Type;
};

struct IPv4_S {
    p5::uint<4> Version;
    p5::uint<4> Ihl;
    p5::uint<8> TOS;
    p5::uint<16> TotalLen;
    p5::uint<16> Iden;
    p5::uint<1> R;
    p5::uint<1> DF;
    p5::uint<1> MF;
    p5::uint<13> FragOffset;
    p5::uint<8> TTL;
    p5::uint<8> Protocol;
    p5::uint<16> Checksum;
    p5::uint<32> SIP;
    p5::uint<32> DIP;
};

struct IPv6_S {
    p5::uint<4> Version;
    p5::uint<8> TC;
    p5::uint<20> FlowLabel;
    p5::uint<16> PayloadLen;
    p5::uint<8> NextProtocol;
    p5::uint<8> HopLmt;
    p5::uint<128> SIP;
    p5::uint<128> DIP;
};

struct UDP_S {
    p5::uint<16> SrcPort;
    p5::uint<16> DstPort;
    p5::uint<16> Length;
    p5::uint<16> Checksum;
};

struct FlagCtrl_S {
    p5::uint<1> Urg;
    p5::uint<1> Ack;
    p5::uint<1> Psh;
    p5::uint<1> Rst;
    p5::uint<1> Syn;
    p5::uint<1> Fin;
};

struct DataCtrl_S {
    p5::uint<4> DataOffset;
    p5::uint<3> Res;
    p5::uint<3> Ecn;
    FlagCtrl_S Ctrl;
};

struct TCP_S {
    p5::uint<16> SrcPort;
    p5::uint<16> DstPort;
    p5::uint<32> SeqNo;
    p5::uint<32> AckNo;
    DataCtrl_S DataCtrl;
    p5::uint<16> Window;
    p5::uint<16> Checksum;
    p5::uint<16> UrgentPtr;
};

struct IPATRSP_S {
    p5::uint<1> Valid;
    p5::uint<1> RouterIntf;
    p5::uint<1> QinQ;
    p5::uint<8> VrfId;
    VlanInfo_S Pvid;
};

using IPATFull_S = _inflate<IPATRSP_S>;

struct FIBRSP_S {
    p5::uint<10> Port;
    p5::uint<8> EncapIndex;
};

using FIBFull_S = _inflate<FIBRSP_S>;

#endif // GENERATED_STRUCT_HPP