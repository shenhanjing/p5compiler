#!/usr/bin/env python3
"""
数据包生成脚本
根据 Parser 支持的包头类型生成所有可能的数据包组合
输出为 JSON 格式，供 C++ 测试程序使用
"""

import json
import random
import argparse
import struct
from typing import List, Dict, Any

# 协议常量
ETHER_TYPE_IPV4 = 0x0800
ETHER_TYPE_IPV6 = 0x86DD
ETHER_TYPE_VLAN = 0x8100
IP_PROTOCOL_TCP = 0x06
IP_PROTOCOL_UDP = 0x11

# 包头大小
ETHER_HEADER_SIZE = 14
VLAN_TAG_SIZE = 4
IPV4_HEADER_SIZE = 20
IPV6_HEADER_SIZE = 40
TCP_HEADER_SIZE = 20
UDP_HEADER_SIZE = 8

# PKT_HEADER_BYTE_LEN = 192
MAX_PKT_SIZE = 192


def generate_mac() -> bytes:
    """生成随机MAC地址"""
    return bytes([random.randint(0, 255) for _ in range(6)])


def ip_to_bytes(ip_str: str) -> bytes:
    """将IP地址字符串转换为字节"""
    parts = ip_str.split('.')
    return bytes([int(p) for p in parts])


def ipv6_to_bytes(ipv6_str: str) -> bytes:
    """将IPv6地址字符串转换为字节（简化版，使用压缩格式）"""
    # 简化处理：使用常见的IPv6地址格式
    if '::' in ipv6_str:
        parts = ipv6_str.split('::')
        left = parts[0].split(':') if parts[0] else []
        right = parts[1].split(':') if len(parts) > 1 and parts[1] else []
        # 填充到8个16位段
        segments = []
        for p in left:
            segments.append(int(p, 16) if p else 0)
        zeros_needed = 8 - len(left) - len(right)
        segments.extend([0] * zeros_needed)
        for p in right:
            segments.append(int(p, 16) if p else 0)
    else:
        segments = [int(p, 16) for p in ipv6_str.split(':')]
    
    result = b''
    for seg in segments:
        result += struct.pack('>H', seg)
    return result


def generate_ethernet_header(dst_mac: bytes = None, src_mac: bytes = None, ether_type: int = ETHER_TYPE_IPV4) -> bytes:
    """生成以太网头"""
    if dst_mac is None:
        dst_mac = generate_mac()
    if src_mac is None:
        src_mac = generate_mac()
    return dst_mac + src_mac + struct.pack('>H', ether_type)


def generate_vlan_tag(vlan_id: int = 1, priority: int = 0, ether_type: int = ETHER_TYPE_IPV4) -> bytes:
    """生成VLAN标签"""
    tpid = 0x8100
    pcp_dei = (priority & 0x7) << 13
    cfi = 0
    vlan_info = pcp_dei | (vlan_id & 0xFFF)
    return struct.pack('>HH', tpid, vlan_info) + struct.pack('>H', ether_type)


def generate_ipv4_header(
    src_ip: str = "192.168.1.1",
    dst_ip: str = "192.168.1.2",
    protocol: int = IP_PROTOCOL_TCP,
    total_len: int = None
) -> bytes:
    """生成IPv4头"""
    if total_len is None:
        total_len = IPV4_HEADER_SIZE + (TCP_HEADER_SIZE if protocol == IP_PROTOCOL_TCP else UDP_HEADER_SIZE)
    
    version_ihl = 0x45  # Version=4, IHL=5
    tos = 0x00
    identification = random.randint(0, 0xFFFF)
    flags_frag = 0x4000  # Don't fragment
    ttl = 64
    checksum = 0  # 简化，不计算校验和
    
    header = struct.pack('>BBHHHBBH',
                        version_ihl, tos, total_len,
                        identification, flags_frag,
                        ttl, protocol, checksum)
    header += ip_to_bytes(src_ip)
    header += ip_to_bytes(dst_ip)
    
    return header


def generate_ipv6_header(
    src_ip: str = "2001:db8::1",
    dst_ip: str = "2001:db8::2",
    next_header: int = IP_PROTOCOL_TCP,
    payload_len: int = None
) -> bytes:
    """生成IPv6头"""
    if payload_len is None:
        payload_len = TCP_HEADER_SIZE if next_header == IP_PROTOCOL_TCP else UDP_HEADER_SIZE
    
    version_tc_flow = 0x60000000  # Version=6, TC=0, FlowLabel=0
    payload_len_bytes = struct.pack('>H', payload_len)
    next_header_byte = next_header
    hop_limit = 64
    
    header = struct.pack('>I', version_tc_flow)
    header += payload_len_bytes
    header += bytes([next_header_byte, hop_limit])
    header += ipv6_to_bytes(src_ip)
    header += ipv6_to_bytes(dst_ip)
    
    return header


def generate_tcp_header(src_port: int = 12345, dst_port: int = 80, seq_no: int = None, flags: int = 0x02) -> bytes:
    """生成TCP头"""
    if seq_no is None:
        seq_no = random.randint(0, 0xFFFFFFFF)
    
    ack_no = 0
    data_offset_res_flags = (5 << 12) | (flags & 0x3FF)  # DataOffset=5, flags
    window = 8192
    checksum = 0
    urgent_ptr = 0
    
    return struct.pack('>HHIIHHHH',
                      src_port, dst_port,
                      seq_no, ack_no,
                      data_offset_res_flags, window,
                      checksum, urgent_ptr)


def generate_udp_header(src_port: int = 5000, dst_port: int = 53, length: int = None) -> bytes:
    """生成UDP头"""
    if length is None:
        length = UDP_HEADER_SIZE
    
    checksum = 0  # 简化，不计算校验和
    
    return struct.pack('>HHHH', src_port, dst_port, length, checksum)


def generate_packet(packet_type: str) -> Dict[str, Any]:
    """
    根据类型生成数据包
    
    支持的packet_type:
    - ether_ipv4_tcp
    - ether_ipv4_udp
    - ether_vlan_ipv4_tcp
    - ether_vlan_ipv4_udp
    - ether_vlan_ipv6_tcp
    - ether_vlan_ipv6_udp
    - ether_ipv6_tcp
    - ether_ipv6_udp
    """
    pkt_data = bytearray(MAX_PKT_SIZE)
    offset = 0
    
    # 解析类型
    parts = packet_type.split('_')
    has_vlan = 'vlan' in parts
    is_ipv6 = 'ipv6' in parts
    is_udp = 'udp' in parts
    
    # 生成以太网头
    ether_type = ETHER_TYPE_VLAN if has_vlan else (ETHER_TYPE_IPV6 if is_ipv6 else ETHER_TYPE_IPV4)
    ether_header = generate_ethernet_header(ether_type=ether_type)
    pkt_data[offset:offset+len(ether_header)] = ether_header
    offset += len(ether_header)
    
    # 生成VLAN标签（如果需要）
    if has_vlan:
        inner_ether_type = ETHER_TYPE_IPV6 if is_ipv6 else ETHER_TYPE_IPV4
        vlan_tag = generate_vlan_tag(vlan_id=random.randint(1, 4094), ether_type=inner_ether_type)
        pkt_data[offset:offset+len(vlan_tag)] = vlan_tag
        offset += len(vlan_tag)
    
    # 生成IP头
    if is_ipv6:
        protocol = IP_PROTOCOL_UDP if is_udp else IP_PROTOCOL_TCP
        ip_header = generate_ipv6_header(next_header=protocol)
    else:
        protocol = IP_PROTOCOL_UDP if is_udp else IP_PROTOCOL_TCP
        ip_header = generate_ipv4_header(protocol=protocol)
    pkt_data[offset:offset+len(ip_header)] = ip_header
    offset += len(ip_header)
    
    # 生成传输层头
    if is_udp:
        l4_header = generate_udp_header()
    else:
        l4_header = generate_tcp_header()
    pkt_data[offset:offset+len(l4_header)] = l4_header
    offset += len(l4_header)
    
    # 转换为十六进制字符串数组（用于JSON）
    pkt_hex = [hex(b) for b in pkt_data[:offset]]
    
    return {
        "type": packet_type,
        "size": offset,
        "data": pkt_hex,
        "data_bytes": list(pkt_data[:offset])  # 也提供字节数组格式，方便C++使用
    }


def generate_all_packet_types() -> List[str]:
    """返回所有支持的数据包类型"""
    return [
        "ether_ipv4_tcp",
        "ether_ipv4_udp",
        "ether_vlan_ipv4_tcp",
        "ether_vlan_ipv4_udp",
        "ether_vlan_ipv6_tcp",
        "ether_vlan_ipv6_udp",
        "ether_ipv6_tcp",
        "ether_ipv6_udp"
    ]


def main():
    parser = argparse.ArgumentParser(description='生成测试数据包JSON文件')
    parser.add_argument('-n', '--num-packets', type=int, default=10000,
                       help='生成的数据包数量（默认：10000）')
    parser.add_argument('-o', '--output', type=str, default='packets.json',
                       help='输出JSON文件名（默认：packets.json）')
    parser.add_argument('--types', nargs='+', choices=generate_all_packet_types(),
                       help='指定要生成的数据包类型（默认：所有类型）')
    parser.add_argument('--equal-distribution', action='store_true',
                       help='均匀分布所有类型（默认：随机分布）')
    
    args = parser.parse_args()
    
    # 确定要使用的类型
    packet_types = args.types if args.types else generate_all_packet_types()
    
    # 生成数据包
    packets = []
    
    if args.equal_distribution:
        # 均匀分布
        packets_per_type = args.num_packets // len(packet_types)
        remainder = args.num_packets % len(packet_types)
        
        for i, pkt_type in enumerate(packet_types):
            count = packets_per_type + (1 if i < remainder else 0)
            for _ in range(count):
                packets.append(generate_packet(pkt_type))
    else:
        # 随机分布
        for _ in range(args.num_packets):
            pkt_type = random.choice(packet_types)
            packets.append(generate_packet(pkt_type))
    
    # 输出统计信息
    type_counts = {}
    for pkt in packets:
        pkt_type = pkt['type']
        type_counts[pkt_type] = type_counts.get(pkt_type, 0) + 1
    
    print(f"Generated {len(packets)} packets:")
    for pkt_type, count in sorted(type_counts.items()):
        print(f"  {pkt_type}: {count}")
    
    # 保存为JSON
    output_data = {
        "metadata": {
            "total_packets": len(packets),
            "packet_types": packet_types,
            "type_distribution": type_counts,
            "max_packet_size": MAX_PKT_SIZE
        },
        "packets": packets
    }
    
    with open(args.output, 'w') as f:
        json.dump(output_data, f, indent=2)
    
    print(f"\nPackets saved to {args.output}")


if __name__ == '__main__':
    main()
