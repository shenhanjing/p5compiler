union SID_ARRAY_U
{
    SRID_S  SRID[7];
    uint<32> CSID32[7][4];
    uint<16> CSID16[7][8];
};
