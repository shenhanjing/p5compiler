struct CsumDecKey_S
{
 union {
  struct {
   uint<16> UdpLength;
   uint<16> PseudoHdrL4Lengh;
   uint<32> Ifa2MetadataHdr;
  } ifa2;
  struct {
   uint<16> TimeStampS;
   uint<32> TimeStampNs;
   uint<16> Rsrv;
  } ifit;
 };

};

typedef _inflate<CsumDecKey_S> CsumDecFetchKey_S;


struct CsumDecFetchKeyResDeflate_S
{
	CsumDecFetchKey_S Res;
};
