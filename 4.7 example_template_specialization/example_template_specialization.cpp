/*
模板特化是指我们可以为模板中特定的类型或参数提供一个专门的实现。
模板特化分为全特化，和偏特化
*/

template<typename T1,class T2>
class A
{
public:
    A()
    {

    }
    T1 m_1;
    T2 m_2;
};

template<>
class A<double,float>
{
public:
    A()
    {

    }
    double m_1;
    float m_2;
};


template<typename T1, class T2>
T1 add(T1 a,T2 b)
{
    return (T1)(a + b);
}

template<>
double add(double a, float b)
{
    return a + (double)b;
}

template<typename T1>
T1 add(T1 a, float b)
{
    return (T1)(a + (double)b);
}



#include <iostream>

int main()
{
    int a = 1;
    float b = 2.0f;
    double c = 3.0f;

    std::cout << add(a, a) << std::endl;
    std::cout << add(c, b) << std::endl;
    
    add(a, b);

    A<int, int>  class_instance1;
    A<double, float>  class_instance2;


   
}

