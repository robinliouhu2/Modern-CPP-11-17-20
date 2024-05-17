/*
std::shared_ptr  智能指针
作用：用于管理动态内存，会在不需要使用动态内存时，自动进行释放，避免“忘记释放内存而导致的内存泄漏”
原理：采用RAII，在智能指针构造函数中对管理内存的引用计数+1，在智能指析构对引用计数减1. 当为零时，自动释放管理的内存
*/

#include <iostream>
#include <memory>

class Data
{
public:
	int m_a;
	void test() {}
public:
	Data()
	{
		std::cout << "constructed Data" << std::endl;
	}

	Data(int a)
	{
		std::cout << "constructed Data wit parameter" << std::endl;
	}

	~Data()
	{
		std::cout << "delete Data" << std::endl;
	}
};

int main()
{
	//Data* pObj = new Data();
	//delete pObj; // 如果忘记了，就发生内存泄漏

	std::shared_ptr<Data>  sh_prt_1(new Data());
	
	sh_prt_1->m_a = 1;
	sh_prt_1->test();
	Data& ref_obj = *sh_prt_1;

	int a = sh_prt_1.use_count();
	
	{
		std::shared_ptr<Data> sh_ptr_2 = sh_prt_1;
		a = sh_prt_1.use_count();
	}

	a = sh_prt_1.use_count();

	//make_shared 性能更高，减少内存分配次数
	//不会直接使用new
	std::shared_ptr<Data>  sh_prt_3 = std::make_shared<Data>(1);
	std::shared_ptr<Data>  sh_prt_4;

	if (sh_prt_4)
	{
		//never run inside. because sh_ptr_4 did not assign a memeory/object
	}

	if (sh_prt_3) // valid true
	{
		sh_prt_3->test();
	}

	sh_prt_3.reset(); // sh_ptr_3 did not pointer to any object after called reset
	sh_prt_3.reset(new Data()); // replace .  1.  old object counter - 1    2. mgr new object


}
