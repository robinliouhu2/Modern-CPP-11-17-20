#include <vector>
#include <iostream> 

/*
* C++标准库可以简单理解为是从面向对象的角度实现的一批容器和算法的集合
1.容器（Containers）	容器是用来管理某一类对象的集合。C++ 提供了各种不同类型的容器，比如 vector、 list、map 等。
2.算法（Algorithms）	算法作用于容器。比如查找、排序、搜索和转换等操作。
3.迭代器（iterators）	迭代器用于遍历容器中元素。  .
相对于指针的好处
1.更统一  
2.安全性
*/



bool find(std::vector<int>& container, int target)
{
    for (std::vector<int>::iterator iter = container.begin(); iter != container.end(); ++iter)
    {
        if ( (*iter) == target)
        return true;
    }

    return false;

}

int main()
{
    int a[10];


    std::vector<int> container; //动态数组
    

    for (int i = 0; i < 10; ++i)
    {
        container.push_back(0);
    }

    find(container, 1);

    return 0;
}
