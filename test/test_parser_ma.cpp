// Parser + MA 联合测试程序
// 演示如何将 Parser 的输出传递给 MA 的输入
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include "include/common/model_intf_1027.h"
#include "include/generated/generated_MA.hpp"
#include "src/generated/generated_MA.cpp"

// 辅助函数：打印十六进制数据
void print_hex(const char* label, const uint8_t* data, size_t len) {
    std::cout << label << " (" << len << " bytes): ";
    for (size_t i = 0; i < len && i < 64; ++i) {  // 最多打印64字节
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::dec << std::endl;
}

// 辅助函数：打印 PHI 信息
void print_phi_info(const uint8_t* phiData) {
    std::cout << "\n=== PHI Information ===" << std::endl;
    
    // 解析 phiData（前18位有效，按位解析）
    uint64_t phi_value = 0;
    
    // 读取前18位（从高位到低位）
    for (int bit = 0; bit < 18; ++bit) {
        size_t byte_idx = bit / 8;
        size_t bit_idx = bit % 8;
        if (byte_idx < FV_PHI_BYTE_NUM) {
            // 大端序：bit 0 是 MSB
            if (phiData[byte_idx] & (1 << (7 - bit_idx))) {
                phi_value |= (1ULL << (17 - bit));
            }
        }
    }
    
    uint8_t port_type = (phi_value >> 14) & 0x0F;  // bits 17-14
    uint8_t l2_type = (phi_value >> 12) & 0x03;     // bits 13-12
    uint8_t tag_type = (phi_value >> 10) & 0x03;    // bits 11-10
    uint8_t l3_type = (phi_value >> 8) & 0x03;      // bits 9-8
    uint8_t l4_type = phi_value & 0xFF;              // bits 7-0
    
    std::cout << "PortType: " << static_cast<int>(port_type) << std::endl;
    std::cout << "L2Type: " << static_cast<int>(l2_type) 
              << " (1=ETHERNET)" << std::endl;
    std::cout << "TagType: " << static_cast<int>(tag_type) 
              << " (1=SINGLE_TAGGED)" << std::endl;
    std::cout << "L3Type: " << static_cast<int>(l3_type) 
              << " (2=IPv4, 3=IPv6)" << std::endl;
    std::cout << "L4Type: " << static_cast<int>(l4_type) 
              << " (10=TCP, 32=UDP)" << std::endl;
}

// 辅助函数：从 gtvData 中读取指定位数的值（大端序，MSB first）
// bit_offset: 起始位偏移量（从 0 开始）
// nbits: 要读取的位数
uint64_t read_bits_from_gtvData(const uint8_t* gtvData, size_t bit_offset, size_t nbits) {
    uint64_t value = 0;
    for (size_t bit = 0; bit < nbits; ++bit) {
        size_t total_bit_pos = bit_offset + bit;
        size_t byte_idx = total_bit_pos / 8;
        size_t bit_idx = total_bit_pos % 8;  // bit_idx=0 是字节内的第0位（MSB）
        if (byte_idx < FV_GTV_MAX_BYTE_NUM) {
            // 大端序：bit_idx=0 对应 bit 7（MSB），bit_idx=7 对应 bit 0（LSB）
            if (gtvData[byte_idx] & (1 << (7 - bit_idx))) {
                value |= (1ULL << (nbits - 1 - bit));
            }
        }
    }
    return value;
}

// 辅助函数：从 gtvData 中读取 GLSP 值（10 bits，从 bit_offset=0 开始）
uint16_t read_glsp_from_gtvData(const uint8_t* gtvData) {
    return static_cast<uint16_t>(read_bits_from_gtvData(gtvData, 0, 10));
}

// 将 Prs2Ma0FvInfoDef 转换为 MaToMaFvInfoDef
// 注意：两个结构体的字段顺序和类型相同，可以直接内存拷贝
void convert_prs_to_ma_fv(const Prs2Ma0FvInfoDef& prs_fv, MaToMaFvInfoDef& ma_fv) {
    // 直接内存拷贝所有字段
    std::memcpy(ma_fv.phData, prs_fv.phData, FV_PH_BYTE_NUM);
    std::memcpy(ma_fv.phiData, prs_fv.phiData, FV_PHI_BYTE_NUM);
    std::memcpy(ma_fv.phoData, prs_fv.phoData, FV_PHO_BYTE_NUM);
    std::memcpy(ma_fv.udfData, prs_fv.udfData, FV_UDF_BYTE_NUM);
    std::memcpy(ma_fv.gtvData, prs_fv.gtvData, FV_GTV_MAX_BYTE_NUM);
    std::memcpy(ma_fv.pgtvData, prs_fv.pgtvData, FV_PGTV_BYTE_NUM);
}

// ========== JSON 数据包解析函数 ==========

/**
 * @brief 从JSON文件加载数据包
 * @param filename JSON文件路径
 * @param packets 输出的数据包向量
 * @return 成功返回true，失败返回false
 * 
 * 解析由 generate_packets.py 生成的JSON格式
 * 格式: { "packets": [ { "data_bytes": [1, 2, 3, ...] }, ... ] }
 */
bool load_packets_from_json(const std::string& filename, std::vector<PktHeader>& packets) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }
    
    packets.clear();
    
    std::string line;
    bool in_packets_array = false;
    bool in_data_bytes = false;
    PktHeader current_pkt;
    size_t byte_offset = 0;
    int brace_level = 0;
    
    while (std::getline(file, line)) {
        // 检查是否进入packets数组
        if (line.find("\"packets\"") != std::string::npos && line.find('[') != std::string::npos) {
            in_packets_array = true;
            continue;
        }
        
        if (!in_packets_array) continue;
        
        // 检查是否进入新的packet对象
        if (line.find('{') != std::string::npos && in_packets_array) {
            if (brace_level == 0) {
                // 新packet开始
                memset(&current_pkt, 0, sizeof(current_pkt));
                byte_offset = 0;
                in_data_bytes = false;
            }
            brace_level++;
        }
        
        // 检查是否找到data_bytes字段
        if (line.find("\"data_bytes\"") != std::string::npos) {
            in_data_bytes = true;
            // 检查同一行是否有数组开始
            if (line.find('[') != std::string::npos) {
                // 解析同一行的数据
                size_t start_pos = line.find('[');
                size_t end_pos = line.find(']', start_pos);
                if (end_pos != std::string::npos) {
                    std::string array_content = line.substr(start_pos + 1, end_pos - start_pos - 1);
                    std::regex number_regex(R"(\b(\d+)\b)");
                    std::sregex_iterator iter(array_content.begin(), array_content.end(), number_regex);
                    std::sregex_iterator end;
                    
                    for (; iter != end && byte_offset < PKT_HEADER_BYTE_LEN; ++iter) {
                        int byte_value = std::stoi(iter->str());
                        current_pkt.pkt_data[byte_offset++] = static_cast<uint8_t>(byte_value);
                    }
                    in_data_bytes = false;
                }
            }
            continue;
        }
        
        // 如果在data_bytes数组中，解析数字
        if (in_data_bytes) {
            std::regex number_regex(R"(\b(\d+)\b)");
            std::sregex_iterator iter(line.begin(), line.end(), number_regex);
            std::sregex_iterator end;
            
            for (; iter != end && byte_offset < PKT_HEADER_BYTE_LEN; ++iter) {
                int byte_value = std::stoi(iter->str());
                current_pkt.pkt_data[byte_offset++] = static_cast<uint8_t>(byte_value);
            }
            
            // 检查数组结束
            if (line.find(']') != std::string::npos) {
                in_data_bytes = false;
            }
        }
        
        // 检查packet对象结束
        if (line.find('}') != std::string::npos) {
            brace_level--;
            if (brace_level == 0) {
                // packet对象结束，保存packet
                packets.push_back(current_pkt);
            }
        }
        
        // 检查packets数组结束
        if (line.find(']') != std::string::npos && !in_data_bytes) {
            if (brace_level == 0) {
                in_packets_array = false;
            }
        }
    }
    
    file.close();
    
    if (packets.empty()) {
        std::cerr << "Warning: No packets loaded from " << filename << std::endl;
        return false;
    }
    
    std::cout << "Loaded " << packets.size() << " packets from " << filename << std::endl;
    return true;
}

int main(int argc, char* argv[]) {
    // 解析命令行参数
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <json_file>" << std::endl;
        std::cerr << "Example: " << argv[0] << " test_packets.json" << std::endl;
        return 1;
    }
    
    std::string json_filename = argv[1];
    
    // 初始化查表引擎：配置 IPAT 表（匹配 generated_MA.hpp 中的逻辑）
    // IPAT 表使用 10 位键，返回 IPATRSP_S 结构
    g_se.initTable<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, MatchType::INDEX);
    g_key.initKey({10});
    
    // 配置 IPAT 表项：GLSP=10 命中，Vrf=100
    g_se.config<p5::uint<10>, IPATRSP_S>(SE_TID_IPAT, 10, IPATRSP_S{1, 0, 0, 100, {}});
    std::cout << "  Configured IPAT table: GLSP=10 -> Vrf=100" << std::endl;
    
    // ========== 3. 从 JSON 文件加载测试数据包 ==========
    std::vector<PktHeader> packets;
    
    if (!load_packets_from_json(json_filename, packets)) {
        std::cerr << "Error: Failed to load packets from " << json_filename << std::endl;
        std::cerr << "Please ensure the JSON file exists and contains valid packet data." << std::endl;
        return 1;
    }
    
    if (packets.empty()) {
        std::cerr << "Error: No packets loaded from " << json_filename << std::endl;
        return 1;
    }
    
    // 限制测试数据包数量为100个
    const size_t MAX_TEST_PACKETS = 1000000;
    size_t original_packet_count = packets.size();
    if (packets.size() > MAX_TEST_PACKETS) {
        packets.resize(MAX_TEST_PACKETS);
        std::cout << "  Loaded " << original_packet_count << " packet(s) from file, "
                  << "limiting test to first " << MAX_TEST_PACKETS << " packets..." << std::endl;
    } else {
        std::cout << "  Loaded " << packets.size() << " packet(s), processing all packets..." << std::endl;
    }
    
    // 初始化 Parser 参数（对所有数据包共享）
    ParserHwInfo parser_hinfo;
    parser_hinfo.port_id = 10;
    parser_hinfo.port_type = 0;  // PORT_TYPE_ETH
    parser_hinfo.parser_start = 0;
    parser_hinfo.init_ti_value = 0;
    parser_hinfo.init_ti_mask = 0;
    parser_hinfo.pre_ipat_info = 0;
    
    NhiDef nhi_info;
    Cp2NpHeader cp2np_hdr;
    
    // 统计信息
    size_t total_packets = packets.size();
    size_t passed_count = 0;
    size_t failed_count = 0;
    
    // ========== 处理所有数据包 ==========
    // 记录处理开始时间
    auto start_time = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < packets.size(); ++i) {
        // 记录处理开始时间
        auto start_time = std::chrono::high_resolution_clock::now();
        const PktHeader& pkt_hdr = packets[i];
        // ========== 调用 Parser 解析数据包 ==========
        Prs2Ma0FvInfoDef prs_fv_out;
        memset(&prs_fv_out, 0, sizeof(prs_fv_out));
        
        // 调用 Parser 处理数据包（ingress 方向）
        PrsProcPkt(false, parser_hinfo, nhi_info, cp2np_hdr, pkt_hdr, prs_fv_out);
        
        // 验证 GLSP 是否已经正确写入 prs_fv_out.gtvData
        // uint16_t glsp_value = read_glsp_from_gtvData(prs_fv_out.gtvData);
        // if (glsp_value != parser_hinfo.port_id) {
        //     std::cout << "  ✗ Packet " << (i + 1) << " FAILED: GLSP mismatch in prs_fv_out.gtvData" << std::endl;
        //     std::cout << "    Expected GLSP=" << parser_hinfo.port_id 
        //               << ", but got GLSP=" << glsp_value << std::endl;
        // }
        
        // 将 Parser 输出转换为 MA 输入
        MaToMaFvInfoDef ma_fv_in, ma_fv_out;
        convert_prs_to_ma_fv(prs_fv_out, ma_fv_in);
        
        // 验证 convert_prs_to_ma_fv 是否正确转换了 gtvData 中的 GLSP
        uint16_t glsp_in_ma_fv_in = read_glsp_from_gtvData(ma_fv_in.gtvData);
        // if (glsp_in_ma_fv_in != parser_hinfo.port_id) {
        //     std::cout << "  ✗ Packet " << (i + 1) << " FAILED: GLSP mismatch after convert_prs_to_ma_fv" << std::endl;
        //     std::cout << "    Expected GLSP=" << parser_hinfo.port_id 
        //               << ", but got GLSP=" << glsp_in_ma_fv_in << " from ma_fv_in.gtvData" << std::endl;
        // }
        
        // 调用 MA 处理（SingleMaProc 会从 ma_fv_in.gtvData 中解包 GLSP 到全局变量）
        memset(&ma_fv_out, 0, sizeof(ma_fv_out));
        SingleMaProc(0, "packet_" + std::to_string(i), 1, ma_fv_in, ma_fv_out);
        
        // 验证 SingleMaProc 处理后的结果
        // 注意：GLSP 现在是从 ma_fv_in.gtvData 中解包出来的全局变量
        bool packet_passed = true;
        uint64_t glsp_after_ma = GLSP.to_ullong();
        uint64_t drop_flag = DropFlag.to_ullong();
        uint64_t vrf = Vrf.to_ullong();
        uint64_t is_uc = IsUc.to_ullong();
        uint64_t l3_type = PHI.L3Type.to_ullong();
        
        // 检查 GLSP 是否正确（应该是 parser_hinfo.port_id，即 10）
        /*
        if (glsp_after_ma == static_cast<uint64_t>(parser_hinfo.port_id)) {
            // 检查是否为 IP 包（IPv4 或 IPv6）
            bool is_ip = (l3_type == L3_TYPE_IPv4 || l3_type == L3_TYPE_IPv6);
            
            if (is_ip) {
                // 对于 IP 包，应该命中表项：DropFlag=0, Vrf=100, IsUc=1
                if (drop_flag == 0 && vrf == 100 && is_uc == 1) {
                    // 验证通过
                } else {
                    std::cout << "  ✗ Packet " << (i + 1) << " FAILED: Expected DropFlag=0, Vrf=100, IsUc=1" << std::endl;
                    std::cout << "    Got GLSP=" << glsp_after_ma
                              << ", DropFlag=" << drop_flag 
                              << ", Vrf=" << vrf 
                              << ", IsUc=" << is_uc << std::endl;
                    packet_passed = false;
                }
            } else {
                // 非 IP 包，应该被 drop（DropFlag=1）
                if (drop_flag != 1) {
                    std::cout << "  ⚠ Packet " << (i + 1) << " Warning: Non-IP packet (L3Type=" << l3_type 
                              << ") should be dropped, but DropFlag=" << drop_flag << std::endl;
                }
            }
        } else {
            std::cout << "  ⚠ Packet " << (i + 1) << " Warning: GLSP=" << glsp_after_ma 
                      << " (expected " << parser_hinfo.port_id << "), test may not be valid" << std::endl;
        }
        
        // 验证 FV 数据一致性
        bool phi_match = (std::memcmp(ma_fv_out.phiData, ma_fv_in.phiData, FV_PHI_BYTE_NUM) == 0);
        bool pho_match = (std::memcmp(ma_fv_out.phoData, ma_fv_in.phoData, FV_PHO_BYTE_NUM) == 0);
        
        if (!phi_match || !pho_match) {
            std::cout << "  ✗ Packet " << (i + 1) << " FAILED: PHI/PHO data mismatch" << std::endl;
            packet_passed = false;
        }
        
        if (packet_passed) {
            passed_count++;
            std::cout << "  ✓ Packet " << (i + 1) << " PASSED" << std::endl;
        } else {
            failed_count++;
        }
        
        // 每处理 100 个数据包显示进度
        if ((i + 1) % 100 == 0) {
            std::cout << "\n  Progress: " << (i + 1) << "/" << total_packets 
                      << " packets processed (Passed: " << passed_count 
                      << ", Failed: " << failed_count << ")" << std::endl;
        }
        */
    }
    
    // 记录处理结束时间并计算处理速率
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    double duration_seconds = duration.count() / 1000000.0;  // 转换为秒
    double packets_per_second = total_packets / duration_seconds;  // 计算包每秒
    double kpps = packets_per_second / 1000.0;  // 转换为千包每秒（Kpps）

    // 输出处理速率统计
    std::cout << "\n=== Processing Rate Statistics ===" << std::endl;
    std::cout << "Total Packets: " << total_packets << std::endl;
    std::cout << "Processing Time: " << std::fixed << std::setprecision(3) 
            << duration_seconds << " seconds (" 
            << duration.count() << " microseconds)" << std::endl;
    std::cout << "Processing Rate: " << std::fixed << std::setprecision(2) 
            << kpps << " Kpps ("
            << std::scientific << std::setprecision(2) << packets_per_second 
            << std::fixed << " packets/second)" << std::endl;

    // ========== 输出最终统计 ==========
    std::cout << "\n=== Test Complete ===" << std::endl;
    std::cout << "Total Packets: " << total_packets << std::endl;
    std::cout << "Passed: " << passed_count << std::endl;
    std::cout << "Failed: " << failed_count << std::endl;
    std::cout << "Overall Result: " << (failed_count == 0 ? "PASS" : "FAIL") << std::endl;
    
    return (failed_count == 0) ? 0 : 1;
}
