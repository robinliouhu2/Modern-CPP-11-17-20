// example_list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>

/*
易错点
1.修改元素之前，确保元素存在
2.遍历过程中删除元素，迭代器会失效，要注意
*/


int main()
{
    std::list<int> l_list;

    l_list.push_back(1);
    l_list.push_back(2);
    l_list.push_back(3);

  

    for (std::list<int>::iterator iter = l_list.begin(); iter!= l_list.end();)
    {
        if (*iter == 2)
            iter = l_list.erase(iter);
        else
            ++iter;
    }

    if (l_list.size() > 0)
    {
        std::list<int>::iterator iter2 = l_list.begin();
        *iter2 = 3;
    }




    std::cout << "Hello World!\n";
}


