# 转换逻辑
## P5Table -> Class
* 将table定义转为父类为Table（public Table）的class定义。
* 将table内所有声明的内容作为class的公开成员，只进行声明，初始化内容留到后续apply方法中。
* 将table的输入参数（其他table）作为指向该类型的指针成员，生成对应的构造函数，其成员调用由“.”改为“->”。
* 将table中所有的初始化，赋值，函数调用，switch case逻辑放在class的apply方法中
* table中key的构建改为在class的apply方法中使用g_key.buildKey({KeyPart{key_element0, bit_width_of_type<decltype(key_element0)>()}，...});
* _apply(tb)转为tb.apply();

## 类型与内置函数
* 将_compressed_type这种类型名改为_inflate<type>
* 对_key()添加输入参数，var = _key<decltype(var)>();
* _status()的使用，删除不含输入参数的使用，只保留含输入参数的使用
* _lookup的调用处添加模板类型_lookup<type>，var = _lookup<typename std::remove_reference_t<decltype(var)>::value_type>(...)