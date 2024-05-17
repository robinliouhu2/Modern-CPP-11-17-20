#include <iostream> 
#include <thread> 
#include <mutex>
#include <condition_variable>

/*
条件变量
用于多线程中，其作用是在多线程间实现线程的等待、唤醒和通知机制，
常配合互斥锁（std::mutex）一起使用。
*/
std::condition_variable cv;
std::mutex mtx; // 全局互斥锁
int fish_for_cook = 0; 

void work_catch_fish()
{
	std::unique_lock<std::mutex> lck(mtx); //RAII 
	fish_for_cook += 1;
	cv.notify_one();
}
void work_cook_fish()
{
	std::unique_lock<std::mutex> lck(mtx); //RAII 

	while(fish_for_cook <= 0)
		cv.wait(lck); //等待状态会自动释放锁，唤醒时会自动获取锁

	fish_for_cook -= 1;
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