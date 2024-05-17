//线程的创建  std::thread 

#include <iostream>
#include <thread>

void work()
{
    
    std::cout << "work thread running\n";
    while (true)
    {

    }
    std::cout << "work thread end\n";
}

//主线程
int main()
{
    std::cout << "main thread running \n";

    std::thread t1(work);
    t1.join();

    std::cout << "main thread end \n";

}

