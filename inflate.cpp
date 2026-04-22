解压缩表和非解压缩表都是通过_inflate来标记的，表示有扩展属性（需要展开@valid），主要区别在于是否会对顶层union里的成员进行展开；
当前编译器只通过顶层union是否匿名来区分是解压缩结构和非解压缩结构；
pure结构对象则是没有_inflate标记的结构，也不做@valid的展开；
非解压缩表里的顶层union里的st会被当做一个field，不做展开，每个st都有一个valid位，st里的子field都指向（继承）该st的valid位；
非解压缩表的顶层union没有位置上的限制（不需要固定在结构体的最后）

// demo: 3种rsp变量的类型区别
struct st_0 {    uint<8> ss0; };
struct st_1 {    uint<8> ss1;};
struct T0_S
{
    @valid uint<8> f0;
    union{
        st_0 s0;
        st_1 s1;
    }u_0;  // named
};
struct T1_S
{
    uint<8> f0;
    union{
        st_0 s0;
        st_1 s1;
    };  // anonymous
    uint<8> f1;
};
typedef _inflate<T0_S> T0Full_S;
typedef _inflate<T1_S> T1Full_S;
T0Full_S rsp0;  // rsp0是解压缩结构实例，不能访问rsp0.s0.ss0，只能访问rsp0.ss0
T1Full_S rsp1;  // rsp1是非解压缩结构实例，能访问rsp1.s0.ss0，不能访问rsp1.ss0
T0_S  rsp2;      // rsp2是原始结构实例，不能访问到rsp2.f0的valid位
