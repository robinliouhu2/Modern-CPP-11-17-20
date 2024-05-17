#include <iostream>
#include <functional>

/*
1. std::function是一个函数包装器，可包装任何类型的可调用实体
   std::function相比函数指针有如下优点: 
   适用范围更广: 可以存储任意可调用对象(函数指针、函数对象(operator())、Lambda 表达式等)
   更安全： function 有错误检查,出错会抛出异常

2. std::bind 是一个函数适配器，通过预先绑定某个函数中的一个或者多个参数 转换成 另一种签名的函数对象

*/


class schoolA
{
public:
    void report(int money) { std::cout << "学校有钱，欢迎报考。 已收:" << money << std::endl; }
};

class schoolB
{
public:
    void report(int money) { std::cout << "学校里面都是帅哥和美女，就业率第一，凡是不符合前述条件的都已经被开除学籍了, 欢迎报考。 已收:" << money << std::endl; }
};

void g_report(int money) {
    std::cout << "g_report " << money << std::endl;
};

int g_add(int a, int b,int c)
{
    return a + b + c;
}

typedef void (*T_FUNC)(int);

int main() {
    schoolA a1, a2, a3;
    schoolB b1, b2, b3;

    T_FUNC rawFuncPtr = g_report; //ok
    //rawFuncPtr = schoolA::report; // fail
    //rawFuncPtr = schoolB::report; // fail

    // function适用范围更广: 可以存储任意可调用对象(函数指针、函数对象(operator())、Lambda 表达式等)
    std::function<void(int)> Function_Ptr = g_report;
    Function_Ptr(666);

    Function_Ptr = std::bind(&schoolA::report,&a1,std::placeholders::_1);
    Function_Ptr(999);

    Function_Ptr = std::bind(&schoolB::report, &b1, std::placeholders::_1);
    Function_Ptr(888);

    Function_Ptr = [](int money) { std::cout << "lamda " << money << std::endl; };
    Function_Ptr(333);

    std::function<int(int, int,int)>  function_1 = g_add;
    std::cout <<" first " << function_1(6, 6,6) << std::endl;

    //bind 的用法
    std::function<int(int,int)> function_2 = std::bind(&g_add, 10, std::placeholders::_1,std::placeholders::_2);
    std::cout << " second " << function_2(9,9) << std::endl;

    std::function<int()> function_3 = std::bind(&g_add, 100, 100,100);
    std::cout << " three " << function_3() << std::endl;






    return 0;
}
