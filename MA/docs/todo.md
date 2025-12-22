# 待完成内容
## 生成C++（业务相关）
* 将所有全局变量提取出来，并`自动`生成解包和打包的函数，全部放在一个struct/class中。为了实现解包和打包，需要对所有结构体添加拼接变量成员的函数（？），使得可以递归计算一个类型的位数；

* 将每个MAU/Control作为独立的对象，继承全局变量基类，每个对象内部维护私有原全局变量同名成员，通过解包和打包函数实现这些成员的输入与输出；MAU类型内置所有MAU功能，通过ma_id选取 vs 每个MAU有自己的类型：MAU的划分；将每个对象的声明与使用与接口函数对接上，自动生成接口函数内容；

* 提取lookup table的ID，匹配类型，键值类型，返回类型，自动生成搜索引擎初始化代码以及键管理器初始化代码；

## 仿真器功能（业务无关）
* 结构体（包含union）类型的key值构建，获取，与查表使用。结构体键值获取时自动切片赋值给结构体，获取结构体键值的结构体成员信息，自动生成展开宏； 

* exact，lpm以及TCAM匹配类型的查表功能实现；优化查表算法；

* P5Table中switch case的规范转换逻辑；key值构建中的switch case与control parameters的规范转换逻辑；_control_info函数的实现；

* 对uint<n>的特定位数读取与修改 (a[0:1]这种用法)；
* _inflate常量赋值{}

* switch case的多变量表达式以及DON'T CARE
* #define的测试
* key内多switch case的构建，多case共用，无类型声明的单独数字
* _hdr_ref
* control parameters（key？）: table_id（sub & one），control_info（sub），command，decomp_profile（sub & one），header_access
* control parameters（table？）: instance，size，ma_id，physical_location，cluster_id，port_id，table_id
* _profile_id()，_lps()，_command()，_table_id()；
* table中的常量声明
* 硬件信息
* programming model

# 优先实现
1. key值构建中的switch case的规范转换逻辑；switch的判断变量做类型转换，加“.to_ullong()”后缀
2. 结构体（包含union）类型的key值获取，包含结构体成员的键值构建，查表使用。

# 已完成
* _compressed_*类型的声明转换
* table声明语句

* P5Table转换逻辑
* _apply函数调用 /*可以改为用宏替换*/
* 调用_key的赋值
* 调用_lookup的赋值