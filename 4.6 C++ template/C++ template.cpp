#include <iostream>
#include <vector>

template<typename T>
T add(T a)
{
    return a;
}

template<typename T,typename... Args>
T add(T a,Args... args)
{
    return a + add<T>(args...);
}

struct A
{

};

int main()
{
    add(1, 2, 3);
 
    return 0;
}

