void Ingress::iprs() {
    return parse_ETHER();
}

void Ingress::eprs() {
    return parse_ETHER();
}

void Ingress::parse_ETHER() {
    PHI.L2Type = L2_TYPE_ETHERNET;
    
    PHO[PHO_OUTER_L2_START] = _extract(ETHER);

    switch(ETHER.ETHER_TYPE.Type.to_ullong()) {
        case 0x8100: return parse_VlanTag();
        case 0x0800: return parse_IPv4(); 
        case 0x86dd: return parse_IPv6(); 
        default: return _parser_next(0, 0); 
    }
}

void Ingress::parse_VlanTag() {
    PHI.TagType = VLAN_SINGLE_TAGGED;
    PHO[PHO_OUTER_VLANS_START] = _extract(VLAN_TAG0);

    switch(VLAN_TAG0.ETHER_TYPE.Type.to_ullong()) {
        case 0x0800: return parse_IPv4(); 
        case 0x86dd: return parse_IPv6(); 
        default: return _parser_next(0, 0); 
    }
}

void Ingress::parse_IPv4() {
    PHI.L3Type = L3_TYPE_IPv4;

    PHO[PHO_OUTER_L3_START] = _extract(IPv4);
    
    switch(IPv4.Protocol.to_ullong()) {
        case IP_PROTOCOL_UDP: return parse_UDP(); 
        case IP_PROTOCOL_TCP: return parse_TCP(); 
        default: return _parser_next(0, 0); 
    }
}

void Ingress::parse_IPv6() {
    PHI.L3Type = L3_TYPE_IPv6;
    PHO[PHO_OUTER_L3_START] = _extract(IPv6);

    switch(IPv6.NextProtocol.to_ullong()) {
        case IP_PROTOCOL_UDP: return parse_UDP();
        case IP_PROTOCOL_TCP: return parse_TCP();
        default: return _parser_next(0, 0);
    }
}

void Ingress::parse_TCP() {
    PHI.L4Type = L4_PROTOCOL_TCP;

    PHO[PHO_OUTER_L4_START] = _extract(TCP);

    return _parser_next(0, 0);
}

void Ingress::parse_UDP() {
    PHI.L4Type = L4_PROTOCOL_UDP;

    PHO[PHO_OUTER_L4_START] = _extract(UDP);

    return _parser_next(0, 0);
}

class IPRS_TBL : public Table {
private:
    Ingress &ctx;
public:
    explicit IPRS_TBL(Ingress &ctx_in) : ctx(ctx_in) {}

    void apply() override {
        ctx.iprs();
    }
};

void Ingress::pre_iMAControl()
{
  IPRS_TBL tbIprs = IPRS_TBL(*this);
  tbIprs.apply();
}