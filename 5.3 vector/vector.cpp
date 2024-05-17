// vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
/*
std::vector 提供了动态数组的功能，可以在运行时根据需要自动调整大小

1.访问   某一个，遍历
2.增删改
3.易错点 
3.1.迭代器失效 
3.2.混淆元素大小‘空间大小
3.2.1 元素大小  size()  可以通过 resize() 改变
3.2.2 空间大小  capacity()  可以通过reserve 改变空间大小
*/

int main()
{

    std::vector<int>  l_vec;

	for (size_t i = 0; i < 10; i++)
	{
		l_vec.push_back(i);
		std::cout << "内存空间的大小是:" << l_vec.capacity() << " 元素的数量是:" << l_vec.size() << std::endl;
	}

	

	for (std::vector<int>::iterator iter = l_vec.begin(); iter != l_vec.end();   )
	{
		if (*iter == 3)
			iter = l_vec.erase(iter);
		else
			++iter;

	}



    std::cout << "Hello World!\n";
}

