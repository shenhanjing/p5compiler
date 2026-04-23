struct IpInfo_S
{
  uint<7> VerSpecific;
  uint<7> Protocol;
};

struct Part1or3_S
{
  uint<16> value;
}

struct Part2or4_S
{
  uint<2> L3Type;
  union
  {
    IpInfo_S IpInfo;
  };
};

struct Part5_S
{
  uint<8> value;
}

struct Part6_S
{
  uint<8> value;
}

struct PHI_S
{
  union
  {
    Part1or3_S Part1;
    uint<16> Part1Raw;
  };
  union
  {
    Part2or4_S Part2;
 uint<16> Part2Raw;
  };

  union
  {
    Part1or3_S Part3;
    uint<16> Part3Raw;
  };
  union
  {
    Part2or4_S Part4;
 uint<16> Part4Raw;
  };
  union
  {
    Part5_S Part5;
    uint<8> Part5Raw;
  };
  union
  {
    Part6_S Part6;
    uint<8> Part6Raw;
  };

};

table NEXT_HEADER_OUTER_TBL()
{
  key =
  {
    switch(PHI.Part2, PHI.Part5, PHI.Part6)
    {
        case (Part2or4_S){L3_TYPE_IPv4 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_IFA2 ,(Ifa2Info_S)0}} &&& (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_MASK ,(Ifa2Info_S)0}}: { IFA2_BASE.Protocol; } case (Part2or4_S){L3_TYPE_IPv4 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_IFIT_DT ,(IfitInfo_S){0 , 0 }}} &&& (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_MASK-1 ,(IfitInfo_S){0 , 4 }}}: { _hdr_ref(PHO[PHO_OUTER_POST_L3_TELEMETRY_IFIT_V4_START], sizeof(IFIT_BASIC_HEADER_S.DtFlowid) + sizeof(IFIT_BASIC_HEADER_S.DtFlags), sizeof(IFIT_BASIC_HEADER_S.NextHeader)); } case (Part2or4_S){L3_TYPE_IPv4 , (IPv4Info_S){{0 ,0 , 1 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv4Info_S){{0 ,0 , 1 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { (uint<8>)0x8D; } case (Part2or4_S){L3_TYPE_IPv4 , (IPv4Info_S){{0 ,1 , 0 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv4Info_S){{0 ,1 , 0 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { (uint<8>)0x32; } case (Part2or4_S){L3_TYPE_IPv4 , (IPv4Info_S){{1 ,0 , 0 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv4Info_S){{1 ,0 , 0 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { AH.NextHeader; } case (Part2or4_S){L3_TYPE_IPv4 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv4.Protocol; } case (Part2or4_S){L3_TYPE_IPv6 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_IFA2 ,(Ifa2Info_S)0}} &&& (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_MASK ,(Ifa2Info_S)0}}: { IFA2_BASE.Protocol; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{0 ,0 ,0 ,0 ,1 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{0 ,0 ,0 ,0 ,1 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6_EXT_DEST2.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, (Part5_S){0, 0, {{0 , 0 , 1 }}, {{0 , 0 , 0 }}} &&& (Part5_S){0, 0, {{0 , 0 , 1 }}, {{0 , 0 , 0 }}}, 0 &&& 0: { (uint<8>)0x8D; } case (Part2or4_S){L3_TYPE_IPv6 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, (Part5_S){0, 0, {{0 , 1 , 0 }}, {{0 , 0 , 0 }}} &&& (Part5_S){0, 0, {{0 , 1 , 0 }}, {{0 , 0 , 0 }}}, 0 &&& 0: { (uint<8>)0x32; } case (Part2or4_S){L3_TYPE_IPv6 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, (Part5_S){0, 0, {{1 , 0 , 0 }}, {{0 , 0 , 0 }}} &&& (Part5_S){0, 0, {{1 , 0 , 0 }}, {{0 , 0 , 0 }}}, 0 &&& 0: { AH.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{0 ,0 ,0 ,1 ,0 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{0 ,0 ,0 ,3 ,0 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6_EXT_FRAG.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{0 ,0 ,0 ,2 ,0 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{0 ,0 ,0 ,2 ,0 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6_EXT_FRAG.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{0 ,0 ,IPV6_EXT_ROUTING_SRH ,0 ,0 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{0 ,0 ,3 ,0 ,0 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { SRH.NextHdrInfo.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{0 ,0 ,IPV6_EXT_ROUTING_NON_SRH ,0 ,0 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{0 ,0 ,3 ,0 ,0 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6_EXT_ROUTING.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{0 ,1 ,0 ,0 ,0 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{0 ,1 ,0 ,0 ,0 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6_EXT_DEST1.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IPv6Info_S){{1 ,0 ,0 ,0 ,0 }, L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv6Info_S){{1 ,0 ,0 ,0 ,0 }, L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6_EXT_HOPBYHOP.NextHeader; } case (Part2or4_S){L3_TYPE_IPv6 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { IPv6.NextProtocol; }
        default: { (uint<8>)0; }
    }
  }
  uint<8> NextHeader = _key();
}
