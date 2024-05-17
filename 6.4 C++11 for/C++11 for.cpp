/*
 C++ 11范围for 可以在遍历容器时，每次循环都会将序列中的下一个元素，赋值给声明的变量，直到循环结束；
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ins = {1, 2,6,9,8};

    //c++11之前的普通for
    for (std::vector<int>::iterator iter = ins.begin(); iter != ins.end();++iter)
    {
        std::cout << *iter << std::endl;
    }

    //范围for
    std::cout << "\n\n rang for !\n";

    //可以通过引用去修改容器中元素的值
    for (auto& item : ins)
    {
        item += 1;
    }

    for (auto& item : ins)
    {
        std::cout << item << std::endl;
    }
    
   
}

