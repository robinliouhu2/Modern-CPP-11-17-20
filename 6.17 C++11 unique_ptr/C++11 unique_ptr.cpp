// C++11 unique_ptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
unique_ptr 与 shared_ptr 指针最大的不同之处在于，
unique_ptr 指针指向的堆内存无法同其它 unique_ptr 共享，
也就是说，每个 unique_ptr 指针都独自拥有对其所指堆内存空间的所有权。
*/
#include <iostream>
#include <memory>

class Data
{
public:
	int m_a;
	void func() {};
};

int main()
{
	std::shared_ptr<Data> sh_ptr_1 = std::make_shared<Data>();
	std::shared_ptr<Data>  sh_ptr_2 = sh_ptr_1;

	std::unique_ptr<Data> un_ptr_1(new Data());
	un_ptr_1->m_a;
	un_ptr_1->func();
	//std::unique_ptr<Data> un_ptr_2 = un_ptr_1;  error 不允许多个智能指针指向同一个实例
	//std::shared_ptr<Data>  sh_ptr_3 = un_ptr_1; error

	std::unique_ptr<Data> un_ptr_5 = std::move(un_ptr_1); // 允许转移

}


