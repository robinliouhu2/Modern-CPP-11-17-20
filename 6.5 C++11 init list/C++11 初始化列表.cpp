/*
* 初始化列表
C++11 引入了统一的初始化语法，即使用大括号 {} 进行初始化(= 号可加可不加)。
对与类来说，性能更高（少调用一次默认构造函数)

推荐使用初始化列表-更统一，更高效
*/
#include <iostream>

class person
{
private:
    int m_a;
public:
    person(int a):m_a(a)
    {

    }
};

struct data
{
    int m_a;
};

int main()
{
    //传统方法初始化方式不一样
    int a = 0; 
    int b(0);

    person ins(1);

    data s_ins = { 2 };

    //初始化列表
    int a2 = { 0 };
    person ins_2 = { 1 };
    data s_ins_2 = { 2 };

    //可以不使用=号
    int aa { 0 };
    person ains_2 { 1 };
    data as_ins_2 { 2 };







    std::cout << "Hello World!\n";
}


