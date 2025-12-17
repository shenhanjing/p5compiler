# 转换逻辑
## P5Table -> Class
* 将table定义转为父类为Table（public Table）的class定义。
* 将table内所有声明的内容作为class的公开成员，只进行声明，初始化内容留到后续apply方法中。
* 将table的输入参数（其他table）作为指向该类型的指针成员，生成对应的构造函数，其成员调用由“.”改为“->”。
* 将table中所有的初始化，赋值，函数调用，switch case逻辑放在class的apply方法中
* table中key的构建改为在class的apply方法中使用g_key.buildKey({KeyPart{key_element0, bit_width_of_type<decltype(key_element0)>()}，...});
* _apply(tb)转为tb.apply();

填加对table（P5Table）的obj的C代码生成
1. 首先将所有的table都转为C++的继承Table父类的class，将“table A(){...}”转换为“class A : public Table{...}”
2. 然后对于table的输入参数（可以是一个或多个），将其转为公共的引用类型成员变量，并通过显式构造函数接受输入，比如将“table A(type B){...}”转为“class A : public Table{type &B; explicit A(type &B_in) : B(&B_in) {}}”
3. 对于table内部body的内容，对于所有的变量声明，复用变量声明转换的逻辑，将这些作为成员，但是将初始化的部分记录下来，只留下声明的部分（对于“类型名()”初始化本身就转换为无初始化的样子了所有可以掠过，只对其余初始化行为这么操作），如果初始化的内容为不含参数的_status函数（只针对这个函数），”_status()“这样的形式，则不要这个初始化。将初始化内容改为赋值，与其他body内容按顺序保存起来。
4. 对于table内部body的内的函数调用，保持原始形态不变，对于_apply()函数（只会有一个传入参数）要特殊处理，要将其形式从“_apply(A)”转换为“A.apply()”，然后与其他body内容按顺序保存起来。
5. 对于table内部body的内的KEY的构建，保留其中所有P5KeyElement的PathExpression的path的name，然后根据这些名称生成“g_key.buildKey(name0, name1,...)"这样的语句，然后与其他body内容按顺序保存起来。
6. 对于table内部body的内的其他语句，保持原始形态不变，与其他body内容按顺序保存起来。
7. 添加一个重载（来自Table基类）的apply方法，将body内保存的内容按顺序放在其内部

## 类型与内置函数
* 将_compressed_type这种类型名改为_inflate<type>
* 对_key()添加输入参数，var = _key<decltype(var)>();
* _status()的使用，删除不含输入参数的使用，只保留含输入参数的使用
* _lookup的调用处添加模板类型_lookup<type>，var = _lookup<typename std::remove_reference_t<decltype(var)>::value_type>(...)