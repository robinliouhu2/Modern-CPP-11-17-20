/*
C++ 调试方法
BUG 就是问题，调试是分析解决问题的方法。
*/
//1.基本调试
/*
1.1 设置断点并调试(监视窗口、堆栈窗口)
1.2 单步跨过 单步进入 跳出
*/

//2.复杂调试
/*
2.1 条件断点
2.2 数据断点
2.3 内存查看
2.4 线程查看
*/

#include "iostream"

void func()
{
    std::cout << "123" << std::endl;

}

uint64_t add(uint8_t* pArray, uint8_t num)
{
    func();
    uint64_t rtn = 0;
    for (uint8_t i = 0; i < num; i++)
    {
        rtn = rtn + pArray[i];
    }
    return rtn;
}

int main()
{
    uint8_t array[5] = {255,9,2,8,1};
    uint64_t accmulate = add(array, 5);
    std::cout << "累加之和为:" << accmulate << std::endl;
}

