/*
* # auto、decltype  (delare type)
* 
* 

atuo 编译器根据初始值进行类型的自动推导
decltype 编译器根据表达式进行类型的自动推导


区别: 
1.decltype不会像auto一样忽略引用、const
2.auto的使用必须马上初始化，否则无法推导出类型,decltype 则不用
*/


#include <iostream>
#include <vector>



int main()
{
    int a = 0;
    auto a1 = 0;
    const int& ref_a = a;

    std::vector<std::vector<int>> ins;
    std::vector<std::vector<int>>::iterator iter = ins.begin();
    auto iter1 = ins.begin();

    auto q0 = ref_a;        // q0 is int not const int&
    decltype(ref_a) q1 = a; //q1 is const int& type

    decltype(int()) v1;
    decltype(a) v2;
    decltype(1.0+2.0) v3;
    decltype(ins)::iterator iter = ins.begin();



    


    std::cout << "Hello World!\n";
}


