/*
 线程同步(对数据而言)：即当有一个线程在对内存进行操作时，其他线程都不可以对这个内存地址进
行操作，直到该线程完成操作，其他线程才能对该内存地址进行操作，而其他线程则处于等待状态
*/

#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>

int fish_for_cook = 0;
std::mutex fish_for_cook_mtx;

void work_catch_fish()
{
	
	for (int i = 0; i < 20000; ++i)
	{
		fish_for_cook_mtx.lock();
		++fish_for_cook;
		fish_for_cook_mtx.unlock();
	}
}

void work_cook_fish()
{
	for (int i = 0; i < 20000; ++i)
	{
		fish_for_cook_mtx.lock();
		--fish_for_cook;
		fish_for_cook_mtx.unlock();
	}
}


int main()
{
	std::thread t1(work_catch_fish);
	std::thread t2(work_cook_fish);
	t1.join();
	t2.join();

	std::cout << "fish_for_cook:" << fish_for_cook << std::endl;

	return 0;
}