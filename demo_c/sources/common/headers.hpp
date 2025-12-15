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
        uint8_t PriCfi_raw;  // 4 bits, stored as uint8_t
        struct {
            uint8_t Pri_raw;  // 3 bits, stored as uint8_t
            uint8_t Dei_raw;  // 1 bit, stored as uint8_t
        } pri_dei;
    };
    p5::uint<12> VlanID;
    
    // 访问器方法
    p5::uint<4> PriCfi() const { return p5::uint<4>(PriCfi_raw & 0x0F); }
    void PriCfi(p5::uint<4> val) { PriCfi_raw = static_cast<uint8_t>(val.to_ullong() & 0x0F); }
    
    p5::uint<3> Pri() const { return p5::uint<3>(pri_dei.Pri_raw & 0x07); }
    void Pri(p5::uint<3> val) { pri_dei.Pri_raw = static_cast<uint8_t>(val.to_ullong() & 0x07); }
    
    p5::uint<1> Dei() const { return p5::uint<1>(pri_dei.Dei_raw & 0x01); }
    void Dei(p5::uint<1> val) { pri_dei.Dei_raw = static_cast<uint8_t>(val.to_ullong() & 0x01); }
    
    // 默认构造函数
    VlanInfo_S() : VlanID(0) {
        PriCfi_raw = 0;
    }
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
    uint8_t    TOS_raw;      // 8 bits, stored as uint8_t
    uint8_t    DSCP_raw;      // 6 bits, but stored as uint8_t
    uint8_t    Precedence_raw;  // 3 bits, but stored as uint8_t
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
  
  // 访问器方法
  p5::uint<8> TOS() const { return p5::uint<8>(u_0.TOS_raw); }
  void TOS(p5::uint<8> val) { u_0.TOS_raw = static_cast<uint8_t>(val.to_ullong() & 0xFF); }
  
  p5::uint<6> DSCP() const { return p5::uint<6>(u_0.DSCP_raw & 0x3F); }
  void DSCP(p5::uint<6> val) { u_0.DSCP_raw = static_cast<uint8_t>(val.to_ullong() & 0x3F); }
  
  p5::uint<3> Precedence() const { return p5::uint<3>(u_0.Precedence_raw & 0x07); }
  void Precedence(p5::uint<3> val) { u_0.Precedence_raw = static_cast<uint8_t>(val.to_ullong() & 0x07); }
  
  // 默认构造函数
  IPv4_S() : Version(0), Ihl(0), TotalLen(0), Iden(0), R(0), DF(0), MF(0), 
             FragOffset(0), TTL(0), Protocol(0), Checksum(0), SIP(0), DIP(0) {
    u_0.TOS_raw = 0;
  }
};

struct IPv6_S
{
  p5::uint<4>   Version;
  union
  {
    uint8_t   TC_raw;              /*Traffic Class, stored as uint8_t*/
    uint8_t   DSCP_raw;            /*Differentiated services code point, stored as uint8_t*/
    uint8_t   Precedence_raw;      /*IP Precedence, stored as uint8_t*/
  } tc_union;
  p5::uint<20>  FlowLabel;            /*Flow Label*/
  p5::uint<16>  PayloadLen;           /*Length of packet after IPv6 header*/
  p5::uint<8>   NextProtocol;         /*Type of next header after this one*/
  p5::uint<8>   HopLmt;               /*Hop limit*/
  p5::uint<128>  SIP;                 /*Source address */
  p5::uint<128>  DIP;                 /*Destination address  */
  
  // 访问器方法
  p5::uint<8> TC() const { return p5::uint<8>(tc_union.TC_raw); }
  void TC(p5::uint<8> val) { tc_union.TC_raw = static_cast<uint8_t>(val.to_ullong() & 0xFF); }
  
  p5::uint<6> DSCP() const { return p5::uint<6>(tc_union.DSCP_raw & 0x3F); }
  void DSCP(p5::uint<6> val) { tc_union.DSCP_raw = static_cast<uint8_t>(val.to_ullong() & 0x3F); }
  
  p5::uint<3> Precedence() const { return p5::uint<3>(tc_union.Precedence_raw & 0x07); }
  void Precedence(p5::uint<3> val) { tc_union.Precedence_raw = static_cast<uint8_t>(val.to_ullong() & 0x07); }
  
  // 默认构造函数
  IPv6_S() : Version(0), FlowLabel(0), PayloadLen(0), NextProtocol(0), 
             HopLmt(0), SIP(0), DIP(0) {
    tc_union.TC_raw = 0;
  }
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
      uint8_t    Res_raw;   // 3 bits, stored as uint8_t
      uint8_t    Ecn_raw;   // 3 bits, stored as uint8_t
    } res_ecn;
    struct {
      uint8_t    Hr3n_raw;  // Private usage, 8 bits
      uint8_t    Ecn1_raw;  // 8 bits
    } hr2n_ecn1;
  } data_union;
  FlagCtrl_S Ctrl;
  
  // 访问器方法
  p5::uint<3> Res() const { return p5::uint<3>(data_union.res_ecn.Res_raw & 0x07); }
  void Res(p5::uint<3> val) { data_union.res_ecn.Res_raw = static_cast<uint8_t>(val.to_ullong() & 0x07); }
  
  p5::uint<3> Ecn() const { return p5::uint<3>(data_union.res_ecn.Ecn_raw & 0x07); }
  void Ecn(p5::uint<3> val) { data_union.res_ecn.Ecn_raw = static_cast<uint8_t>(val.to_ullong() & 0x07); }
  
  p5::uint<4> Hr2n() const { return p5::uint<4>(data_union.hr2n_ecn1.Hr3n_raw & 0x0F); }
  void Hr2n(p5::uint<4> val) { data_union.hr2n_ecn1.Hr3n_raw = static_cast<uint8_t>(val.to_ullong() & 0x0F); }
  
  p5::uint<2> Ecn1() const { return p5::uint<2>(data_union.hr2n_ecn1.Ecn1_raw & 0x03); }
  void Ecn1(p5::uint<2> val) { data_union.hr2n_ecn1.Ecn1_raw = static_cast<uint8_t>(val.to_ullong() & 0x03); }
  
  // 默认构造函数
  DataCtrl_S() : DataOffset(0), Ctrl() {
    data_union.res_ecn.Res_raw = 0;
    data_union.res_ecn.Ecn_raw = 0;
  }
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

