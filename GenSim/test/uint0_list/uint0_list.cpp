#include <vector>

template <typename T0, typename T1, typename T2, typename T3>
void func(T0 var0, std::initializer_list<T1> _InitList_list0, T2 &var1, std::vector<T3> &list1) {
    std::vector<T1> list0(_InitList_list0); 
    auto TempVAR = var0;
    decltype(list0) TempLIST(list0.size());
}
