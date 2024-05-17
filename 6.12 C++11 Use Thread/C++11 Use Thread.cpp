#include <iostream>
#include <thread>

/*线程的使用*/

void work_catch_fish()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "fish catched " << std::endl;
}

void work_cook_fish()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "fish cooked " << std::endl;
}

void work_all()
{
	work_catch_fish();
	work_cook_fish();
}

int main()
{
	auto t_work_start = std::chrono::steady_clock::now();

	//	work_catch_fish();
	//	work_cook_fish();

	//一个人抓鱼 煮鱼
	//std::thread  thread_A(work_all);
	//thread_A.join();
	
	std::thread  thread_A(work_catch_fish);
	std::thread  thread_B(work_cook_fish);

	thread_A.join();
	thread_B.join();

	auto t_work_end = std::chrono::steady_clock::now();
	auto interval = std::chrono::duration_cast<std::chrono::seconds>(t_work_end - t_work_start).count();

	std::cout << "code running use total time " << interval << " seconds" << std::endl;

	return 0;
}