struct IpSecInfo_S
{
  uint<1> AH;
  uint<1> ESP;
  uint<1> WESP;
};

struct IPv4Info_S
{
  IpSecInfo_S IpSecInfo;
  uint<1> Options;
  uint<2> Frag;
  uint<1> Reserved1;
  uint<7> Protocol;
};

table NEXT_HEADER_OUTER_TBL()
{
  key =
  {
    switch()
    {
        case (Part2or4_S){L3_TYPE_IPv4 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_IFA2 ,(Ifa2Info_S)0}} &&& (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_MASK ,(Ifa2Info_S)0}}: { IFA2_BASE.Protocol; } 
        case (Part2or4_S){L3_TYPE_IPv4 , (IpInfo_S){0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S) {L3_TYPE_MASK , (IpInfo_S){0 , L4_PROTOCOL_NONE }}, 0 &&& 0, (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_IFIT_DT ,(IfitInfo_S){0 , 0 }}} &&& (Part6_S){(TelemetryInfo_S){TELEMETRY_TYPE_MASK-1 ,(IfitInfo_S){0 , 4 }}}: { _hdr_ref(PHO[PHO_OUTER_POST_L3_TELEMETRY_IFIT_V4_START], sizeof(IFIT_BASIC_HEADER_S.DtFlowid) + sizeof(IFIT_BASIC_HEADER_S.DtFlags), sizeof(IFIT_BASIC_HEADER_S.NextHeader)); } 
        case (Part2or4_S){L3_TYPE_IPv4 , (IPv4Info_S){{0 ,0 , 1 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }} &&& (Part2or4_S){L3_TYPE_MASK , (IPv4Info_S){{0 ,0 , 1 }, 0 , 0 , 0 , L4_PROTOCOL_NONE }}, 0 &&& 0, 0 &&& 0: { (uint<8>)0x8D; } 
        default: { (uint<8>)0; }
    }
  }
  uint<8> NextHeader = _key();
}
