#ifndef FV_HPP
#define FV_HPP

#include "headers.hpp"
#include "../../p5_types.hpp"
using namespace p5;

// P5: @segment("PHI") @volatile("PHI", "in", "in") PHI_S PHI;
// C++: 转换为全局变量，注解保留为注释
// @segment("PHI") @volatile("PHI", "in", "in")
PHI_S PHI;

// P5: @segment("PHO") @volatile("PHO", "in", "inout") uint<7> PHO[5];
// @segment("PHO") @volatile("PHO", "in", "inout")
uint<7> PHO[5];

uint<8> NGSFBuffer[64];
uint<10> GLSP;
uint<10> GLTP;
uint<6> LLTP;
uint<8> Vrf;
uint<6> FQID;
uint<14> PktLength;
uint<1> DropFlag;
uint<1> IsUc;
uint<12> Mgid;
uint<8> SB;
uint<8> SP;
uint<8> TB;
uint<8> TP;
uint<16> HashValue;
uint<8> TOS;
uint<8> TTL;
uint<8> EncapIndex;
uint<3> HubSpkGrp;
uint<2> EncapProfile;

#endif // FV_HPP

