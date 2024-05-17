/* C++11
* nullptr 代表空指针
* 宏定义NULL 是整形数字0，只是理解或者使用上当作"空指针"
*/

#include <iostream>

void func(int a)
{
    a += 1;
}

void func(int* pa)
{
    *pa += 1;
}


int main()
{
    int* pa1 = NULL;
    int* pa2 = nullptr;


    func(NULL);
    func(nullptr);

    std::cout << "Hello World!\n";
}

