## 单独使用
ma_id: 物理ma id，全量中最大为5的常数
_header_access：表示packet访问模式，芯片强相关，软件仿真阶段可以不关注，全量中没有

## 成对使用，主要用于传递一些带外信息：
control_info与_control_info()：MATCH到ACTION的带外信号，全量中可以是任意类型

table_id与_table_id()： MA到SE的带外信号，全量中最大五位的常数
command与_command()：MA到SE的带外信号，全量中赋值给最多八位的uint，值最大为0x8000，其他取值有0x0，1<<0，1<<1，1<<2

decomp_profile与_profile_id()：？全量中赋值给最多三位的uint，值最大为11

## 已废弃:
Instance
physical_location
Cluster_id 
Port_id 
_lps
