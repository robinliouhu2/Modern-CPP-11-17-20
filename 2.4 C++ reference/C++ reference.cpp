#include <iostream>
/*
引用是一个变量的别名，定义引用时，必须同时完成初始化
*/
typedef struct _A
{
    int a[1000];
    int b;
}A;

//引用只是变量的别名，所以和指针一样，不会拷贝数据的内容
void func(A& in_a)
{
    in_a.b = 10;
}

int main()
{
    A l_a;

    //引用只是变量的别名，所以和指针一样，不会拷贝数据的内容
    A& ref_a = l_a;

    func(l_a);
}

