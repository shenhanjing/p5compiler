# 待完成内容
* key中的switch case与control parameters的规范转换逻辑
* P5Table中switch case的规范转换逻辑
* exact，lpm以及TCAM匹配类型search engine逻辑
* key值构建中能否输入结构体（包含union）

* 结构体键值获取时自动切片赋值给结构体，获取结构体键值的结构体成员信息，自动生成展开宏
* 提取所有table的总量，ID，匹配类型，键值类型，返回类型，自动生成search engine初始化代码
* 提取所有全局变量，每个组件的对象中都添加这些作为成员，然后每个组件都加上传入和传出的逻辑，再把这个逻辑和接口的信息做对应

# 待完成
* P5Table转换逻辑

* 调用_key的赋值
* 调用_lookup的赋值
* _compressed_*类型的声明转换
* table声明语句
* _apply函数调用

* 全局变量与类型