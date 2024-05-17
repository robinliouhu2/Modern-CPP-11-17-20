// 命名空间用于将全局作用域在划分成不同的逻辑空间，
// 不同的命名空间可以定义同名的函数或变量，互不冲突
//

#include <iostream>

namespace first_grade
{
    int xiaoming = 1;
}

namespace second_grade
{
    int xiaoming = 2;
}


int main()
{
    //用命名空间进行访问
    std::cout << "first grade" << first_grade::xiaoming << std::endl;
    std::cout << "second grade" << second_grade::xiaoming << std::endl;

    //通过using 导入命名空间所有符号后，可以直接访问
    using namespace first_grade;
    std::cout << "first grade" << xiaoming << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

