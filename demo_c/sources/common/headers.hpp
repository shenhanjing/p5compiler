#ifndef HEADERS_HPP
#define HEADERS_HPP

#include "../../p5_types.hpp"
#include <cstdint>
#include <cstring>
// 不使用 using namespace p5; 避免与系统 uint 冲突
// 使用 p5::uint<N> 显式指定命名空间

//=========Header Struct Instantiation============

enum PHO_OFFSETS_E 
{
  PHO_OUTER_L2_START                    = 0,
  PHO_OUTER_VLANS_START                 = 1,
  PHO_OUTER_L3_START                    = 2,
  PHO_OUTER_L4_START                    = 3
};

enum L2_TYPE_E
{
  L2_TYPE_INVALID  = 0,
  L2_TYPE_ETHERNET = 1,
  L2_TYPE_OTHER    = 2,
  L2_TYPE_RES      = 3
};

enum VLAN_TYPE_E
{
  VLAN_UNTAGGED = 0,
  VLAN_SINGLE_TAGGED = 1,
  VLAN_DOUBLE_TAGGED = 2,
  VLAN_TRIPLE_TAGGED = 3
};

enum L3_TYPE_E
{
  L3_TYPE_INVALID = 0,
  L3_TYPE_NON_IP = 1,
  L3_TYPE_IPv4 = 2,
  L3_TYPE_IPv6 = 3
};

enum L4_PROTOCOL_E
{
  L4_PROTOCOL_NONE             = 0,
  L4_PROTOCOL_TCP              = 10,
  L4_PROTOCOL_UDP              = 32
};

// 协议常量
#define PG_OUTER_L2  0
#define PG_OUTER_L3  1
#define PG_OUTER_L4  2

#define IP_PROTOCOL_TCP      0x06
#define IP_PROTOCOL_UDP      0x11

struct PHI_S
{
  p5::uint<4> PortType;
  p5::uint<2> L2Type;
  p5::uint<2> TagType;
  p5::uint<2> L3Type;
  p5::uint<8> L4Type;
};

struct ETHER_S
{
  p5::uint<48> Dmac;
  p5::uint<48> Smac;
};

struct VlanInfo_S {
    union {
        p5::uint<4> PriCfi;  // 4 bits,
        struct {
            p5::uint<3> Pri;  // 3 bits,
            p5::uint<1> Dei;  // 1 bit,
        } pri_dei;
    };
    p5::uint<12> VlanID;
};

struct VLAN_TAG_S
{
  p5::uint<16>     Tpid;
  VlanInfo_S   VlanInfo;
};

struct ETHER_TYPE_S
{
  p5::uint<16>    Type;
};

struct IPv4_S
{
  p5::uint<4>    Version;
  p5::uint<4>    Ihl;
  union
  {
    p5::uint<8>    TOS;      // 8 bits,
    p5::uint<6>    DSCP;      // 6 bits,
    p5::uint<3>    Precedence;  // 3 bits,
  } u_0;
  p5::uint<16>    TotalLen;
  p5::uint<16>    Iden;
  p5::uint<1>     R;
  p5::uint<1>     DF;
  p5::uint<1>     MF;
  p5::uint<13>    FragOffset;
  p5::uint<8>       TTL;
  p5::uint<8>       Protocol;
  p5::uint<16>      Checksum;
  p5::uint<32>      SIP;
  p5::uint<32>      DIP;
};

struct IPv6_S
{
  p5::uint<4>   Version;
  union
  {
    p5::uint<8>   TC;              /*Traffic Class,*/
    p5::uint<6>   DSCP;            /*Differentiated services code point,*/
    p5::uint<3>   Precedence;      /*IP Precedence,*/
  } tc_union;
  p5::uint<20>  FlowLabel;            /*Flow Label*/
  p5::uint<16>  PayloadLen;           /*Length of packet after IPv6 header*/
  p5::uint<8>   NextProtocol;         /*Type of next header after this one*/
  p5::uint<8>   HopLmt;               /*Hop limit*/
  p5::uint<128>  SIP;                 /*Source address */
  p5::uint<128>  DIP;                 /*Destination address  */
  
};

struct UDP_S
{
  p5::uint<16>    SrcPort;
  p5::uint<16>    DstPort;
  p5::uint<16>    Length;
  p5::uint<16>    Checksum;
};

struct FlagCtrl_S
{
  p5::uint<1>    Urg;
  p5::uint<1>    Ack;
  p5::uint<1>    Psh;
  p5::uint<1>    Rst;
  p5::uint<1>    Syn;
  p5::uint<1>    Fin;
};

struct DataCtrl_S
{
  p5::uint<4>    DataOffset;
  union {
    struct {
      p5::uint<3>    Res;   // 3 bits,
      p5::uint<3>    Ecn;   // 3 bits,
    } res_ecn;
    struct {
      p5::uint<4>    Hr3n;  // Private usage, 8 bits
      p5::uint<2>    Ecn1;  // 8 bits
    } hr2n_ecn1;
  } data_union;
  FlagCtrl_S Ctrl;
};

struct TCP_S
{
  p5::uint<16>    SrcPort;
  p5::uint<16>    DstPort;
  p5::uint<32>    SeqNo;
  p5::uint<32>    AckNo;
  DataCtrl_S  DataCtrl;
  p5::uint<16>    Window;
  p5::uint<16>    Checksum;
  p5::uint<16>    UrgentPtr;
};

/****************************        Outer Headers           *********************************/
// Header 变量作为全局变量定义（使用 inline 避免多重定义）
inline ETHER_S ether{};
inline VLAN_TAG_S vlan_tag0{};
inline ETHER_TYPE_S ether_type{};
inline IPv4_S ipv4{};
inline IPv6_S ipv6{};
inline UDP_S udp{};
inline TCP_S tcp{};

#endif // HEADERS_HPP

