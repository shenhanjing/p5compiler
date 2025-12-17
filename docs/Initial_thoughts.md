# Table
## P5语法内容
* 输入参数(optional)：可以是任意数量变量，指针，对象。。。
* KEY(optional)：直接或者switch case
* control parameters(optional)
* 变量/常量声明(optional)
* table声明与使用(optional)

* 赋值(optional)
* 函数调用(optional)
* switch case语句(optional)

* 当前table的apply方法

## 成员
* 输入参数(optional)
* KEY(optional)，多成员拼接
* control parameters(optional)
* 当前table的apply方法
* 声明的变量/常量(optional)
* status，control_info，rsp三个特殊变量的声明
* 声明的table(optional)

## 声明时执行（构造函数）
* 保存传入参数到成员中，可以先假设只有一个table类型对象

## apply时执行

## 基类
* KEY(optional)，能否任意位数？
* apply方法

## 子类
* 输入参数(optional)
* KEY(optional)的具体内容
* control parameters(optional)
* 声明的变量/常量(optional)
* status，control_info，rsp三个特殊变量的声明
* 声明的table(optional)
* apply方法具体实现，变量的初始化，赋值，key的构建，switch case语句

# Lookup函数
* typedef _inflate<RSP_S> Full_S;
* /_compressed_/RSP_S
* _key
* _lookup
* _status
* _memcpy

# SE类
查表功能的中心化实现，配置表项，键值查询，清空，内部含有多个表

* 有多个可以用ID选择的表格
* 每个表格都含有表项，每个表格都是固定的匹配类型
* 表格的初始化，init方法，输入指定ID以及匹配类型，获得空的特定匹配类型的表格
* 可以根据输入配置表项，config方法以及table ID和匹配值以及返回值
* 可以根据键值查询表，使用_lookup方法，输入ID和键，获得查询结果
* 匹配时，返回匹配结果，未匹配时返回空，rsp的valid函数返回false
* 查询结果可以分为匹配，未匹配，将表格的最近一次的匹配状态记录下来，使用status方法与特定ID获取