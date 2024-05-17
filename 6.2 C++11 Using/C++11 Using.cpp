#include <iostream>

/*
* using C++ 11的新用法
using语法和typedef一样，只是给某些类型定义了新的别名。
using和typedef相比，更直观。
*/

namespace XYZ
{
    namespace ZYX
    {
        int ma;
    }
}

using namespace XYZ::ZYX;

typedef int myint;

using intmy = int;

void add(int a, int b)
{

}

typedef void (*TADD)(int a, int b);

using  UTADD = void(*)(int a, int b);

int main()
{
    ma = 0;

    myint  v1 = 0;
    intmy  v2 = 3;

    TADD pfunc = add;
    pfunc(1,1);

    UTADD pfunc2 = add;
    pfunc2(2, 2);



    std::cout << "Hello World!\n";
}


