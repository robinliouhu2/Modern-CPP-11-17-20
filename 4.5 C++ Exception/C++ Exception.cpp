#include <iostream>

void b();
void c();

namespace my
{
    class exception
    {
    public:
        int number;
        std::string info;
    };
}

void a() 
{
    b();
}

void b()
{
    c();
    std::cout << "b is over" << std::endl;
}

void c()
{
    throw my::exception{ 1,"chu cuo la" };
}

int main()
{
    try
    {
        a();
    }
    catch (const char* p)
    {
        std::cout << "const char* exception happend" << std::endl;
    }
    catch (const my::exception& v)
    {
        std::cout << "my::exception happend" << v.number << std::endl;
    }
    catch (...)
    {
        std::cout << "... exception happend" << std::endl;
    }
}

