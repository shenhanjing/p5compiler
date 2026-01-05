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
struct _inU_PHI_S {
    p5::member<p5::uint<4>> PortType;
    p5::member<p5::uint<2>> L2Type;
    p5::member<p5::uint<2>> TagType;
    p5::member<p5::uint<2>> L3Type;
    p5::member<p5::uint<8>> L4Type;
};

struct ETHER_TYPE_S {
    p5::uint<16> Type;
};
struct _inU_ETHER_TYPE_S {
    p5::member<p5::uint<16>> Type;
};

struct ETHER_S {
    p5::uint<48> Dmac;
    p5::uint<48> Smac;
    ETHER_TYPE_S ETHER_TYPE;
};
struct _inU_ETHER_S {
    p5::member<p5::uint<48>> Dmac;
    p5::member<p5::uint<48>> Smac;
    _inU_ETHER_TYPE_S ETHER_TYPE;
};

struct VlanInfo_S {
    P5_UNION(_noname_u_0, {
        p5::member<p5::uint<4>> PriCfi;
        struct {
            p5::member<p5::uint<3>> Pri;
            p5::member<p5::uint<1>> Dei;
        } _noname_st_0;
    });
    p5::uint<12> VlanID;
};
struct _inU_VlanInfo_S {
    P5_UNION(_noname_u_0, {
        p5::member<p5::uint<4>> PriCfi;
        struct {
            p5::member<p5::uint<3>> Pri;
            p5::member<p5::uint<1>> Dei;
        } _noname_st_0;
    });
    p5::member<p5::uint<12>> VlanID;
};

struct VLAN_TAG_S {
    p5::uint<16> Tpid;
    VlanInfo_S VlanInfo;
    ETHER_TYPE_S ETHER_TYPE;
};
struct _inU_VLAN_TAG_S {
    p5::member<p5::uint<16>> Tpid;
    _inU_VlanInfo_S VlanInfo;
    _inU_ETHER_TYPE_S ETHER_TYPE;
};

struct IPv4_S {
    p5::uint<4> Version;
    p5::uint<4> Ihl;
    P5_UNION(u_0, {
        p5::member<p5::uint<8>> TOS;
        p5::member<p5::uint<6>> DSCP;
        p5::member<p5::uint<3>> Precedence;
    });
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
struct _inU_IPv4_S {
    p5::member<p5::uint<4>> Version;
    p5::member<p5::uint<4>> Ihl;
    P5_UNION(u_0, {
        p5::member<p5::uint<8>> TOS;
        p5::member<p5::uint<6>> DSCP;
        p5::member<p5::uint<3>> Precedence;
    });
    p5::member<p5::uint<16>> TotalLen;
    p5::member<p5::uint<16>> Iden;
    p5::member<p5::uint<1>> R;
    p5::member<p5::uint<1>> DF;
    p5::member<p5::uint<1>> MF;
    p5::member<p5::uint<13>> FragOffset;
    p5::member<p5::uint<8>> TTL;
    p5::member<p5::uint<8>> Protocol;
    p5::member<p5::uint<16>> Checksum;
    p5::member<p5::uint<32>> SIP;
    p5::member<p5::uint<32>> DIP;
};

struct IPv6_S {
    p5::uint<4> Version;
    P5_UNION(_noname_u_0, {
        p5::member<p5::uint<8>> TC;
        p5::member<p5::uint<6>> DSCP;
        p5::member<p5::uint<3>> Precedence;
    });
    p5::uint<20> FlowLabel;
    p5::uint<16> PayloadLen;
    p5::uint<8> NextProtocol;
    p5::uint<8> HopLmt;
    p5::uint<128> SIP;
    p5::uint<128> DIP;
};
struct _inU_IPv6_S {
    p5::member<p5::uint<4>> Version;
    P5_UNION(_noname_u_0, {
        p5::member<p5::uint<8>> TC;
        p5::member<p5::uint<6>> DSCP;
        p5::member<p5::uint<3>> Precedence;
    });
    p5::member<p5::uint<20>> FlowLabel;
    p5::member<p5::uint<16>> PayloadLen;
    p5::member<p5::uint<8>> NextProtocol;
    p5::member<p5::uint<8>> HopLmt;
    p5::member<p5::uint<128>> SIP;
    p5::member<p5::uint<128>> DIP;
};

struct UDP_S {
    p5::uint<16> SrcPort;
    p5::uint<16> DstPort;
    p5::uint<16> Length;
    p5::uint<16> Checksum;
};
struct _inU_UDP_S {
    p5::member<p5::uint<16>> SrcPort;
    p5::member<p5::uint<16>> DstPort;
    p5::member<p5::uint<16>> Length;
    p5::member<p5::uint<16>> Checksum;
};

struct FlagCtrl_S {
    p5::uint<1> Urg;
    p5::uint<1> Ack;
    p5::uint<1> Psh;
    p5::uint<1> Rst;
    p5::uint<1> Syn;
    p5::uint<1> Fin;
};
struct _inU_FlagCtrl_S {
    p5::member<p5::uint<1>> Urg;
    p5::member<p5::uint<1>> Ack;
    p5::member<p5::uint<1>> Psh;
    p5::member<p5::uint<1>> Rst;
    p5::member<p5::uint<1>> Syn;
    p5::member<p5::uint<1>> Fin;
};

struct DataCtrl_S {
    p5::uint<4> DataOffset;
    P5_UNION(_noname_u_0, {
        struct {
            p5::member<p5::uint<3>> Res;
            p5::member<p5::uint<3>> Ecn;
        } _noname_st_0;
        struct {
            p5::member<p5::uint<4>> Hr2n;
            p5::member<p5::uint<2>> Ecn1;
        } _noname_st_1;
    });
    FlagCtrl_S Ctrl;
};
struct _inU_DataCtrl_S {
    p5::member<p5::uint<4>> DataOffset;
    P5_UNION(_noname_u_0, {
        struct {
            p5::member<p5::uint<3>> Res;
            p5::member<p5::uint<3>> Ecn;
        } _noname_st_0;
        struct {
            p5::member<p5::uint<4>> Hr2n;
            p5::member<p5::uint<2>> Ecn1;
        } _noname_st_1;
    });
    _inU_FlagCtrl_S Ctrl;
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
struct _inU_TCP_S {
    p5::member<p5::uint<16>> SrcPort;
    p5::member<p5::uint<16>> DstPort;
    p5::member<p5::uint<32>> SeqNo;
    p5::member<p5::uint<32>> AckNo;
    _inU_DataCtrl_S DataCtrl;
    p5::member<p5::uint<16>> Window;
    p5::member<p5::uint<16>> Checksum;
    p5::member<p5::uint<16>> UrgentPtr;
};

struct IpatCtrlInfo_S
{
    p5::uint<1> ForwardEn;
};
struct _inU_IpatCtrlInfo_S {
    p5::member<p5::uint<1>> ForwardEn;
};

struct IPATRSP_S {
    p5::uint<1> Valid;
    p5::uint<1> RouterIntf;
    p5::uint<1> QinQ;
    p5::uint<8> VrfId;
    VlanInfo_S Pvid;
};
struct _inU_IPATRSP_S {
    p5::member<p5::uint<1>> Valid;
    p5::member<p5::uint<1>> RouterIntf;
    p5::member<p5::uint<1>> QinQ;
    p5::member<p5::uint<8>> VrfId;
    _inU_VlanInfo_S Pvid;
};

using IPATFull_S = _inflate<IPATRSP_S>;

struct FIBRSP_S {
    p5::uint<10> Port;
    p5::uint<8> EncapIndex;
};
struct _inU_FIBRSP_S {
    p5::member<p5::uint<10>> Port;
    p5::member<p5::uint<8>> EncapIndex;
};

using FIBFull_S = _inflate<FIBRSP_S>;

struct FIBKEY_S {
    p5::uint<8> VrfId;
    p5::uint<128> DIP;
};
struct _inU_FIBKEY_S {
    p5::member<p5::uint<8>> VrfId;
    p5::member<p5::uint<128>> DIP;
};

struct ENCAP_LOCAL_ADDR_S {
    p5::uint<48> SMAC;
};
struct _inU_ENCAP_LOCAL_ADDR_S {
    p5::member<p5::uint<48>> SMAC;
};

struct EPATRSP_S {
    p5::uint<1> Valid;
    p5::uint<31> Rsvd;
    P5_UNION(Dma, {
        _inU_ENCAP_LOCAL_ADDR_S Addr;
    });
};
struct _inU_EPATRSP_S {
    p5::member<p5::uint<1>> Valid;
    p5::member<p5::uint<31>> Rsvd;
    P5_UNION(Dma, {
        _inU_ENCAP_LOCAL_ADDR_S Addr;
    });
};

using EPATFull_S = _inflate<EPATRSP_S>;

struct ENCAP_ARP_S {
    p5::uint<48> DMAC;
};
struct _inU_ENCAP_ARP_S {
    p5::member<p5::uint<48>> DMAC;
};

struct ENCAPRSP_S {
    p5::uint<1> Valid;
    p5::uint<31> Rsvd;
    P5_UNION(Dma, {
        _inU_ENCAP_ARP_S Arp;
    });
};
struct _inU_ENCAPRSP_S {
    p5::member<p5::uint<1>> Valid;
    p5::member<p5::uint<31>> Rsvd;
    P5_UNION(Dma, {
        _inU_ENCAP_ARP_S Arp;
    });
};

using ENCAPFull_S = _inflate<ENCAPRSP_S>;

#endif // GENERATED_STRUCT_HPP