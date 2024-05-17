/*
* 
* ### **拷贝构造（Copy Constructor）：**
拷贝构造函数是一种特殊的构造函数，它接受一个同类对象的引用作为参数，并使用该对象的值来初始化新创建的对象

### **拷贝赋值（Copy Assignment）：**

拷贝赋值是通过赋值运算符 =`实现的对象复制操作。接受一个同类对象的引用作为参数，并使用该对象的值来初始化新创建的对象

*/

#include <iostream>

class person
{
private:
    int m_age;
    char* m_pName;
    bool m_isHandSome;
public:

    person()
    {
        m_pName = new char[100];
        m_age = 0;
        m_isHandSome = 0;
        memset(m_pName, 0, 100);
    }
 
    person(int age,const char* pName,bool isHandSome) //普通构造
    {
        m_pName = new char[100];
        m_age = age;
        m_isHandSome = isHandSome;
        memcpy(m_pName, pName, strlen(pName) + 1);
    }
    
    person(const person& other) //拷贝构造
    {
        //
        
        m_age = other.m_age;
        m_isHandSome = other.m_isHandSome;

        //正确的写法
        m_pName = new char[100];
        memcpy(m_pName, other.m_pName, 100);

        //错误的写法
        //m_pName = other.m_pName; 
    }

    person& operator = (const person& other) //拷贝赋值
    {
        m_age = other.m_age;
        m_isHandSome = other.m_isHandSome;

        //正确的写法
        m_pName = new char[100];
        memcpy(m_pName, other.m_pName, 100);
        return *this;
    }

    ~person()
    {
        delete[] m_pName;
    }
};

int main()
{
    const char* pName = "xiao_hua";
    person  xiao_hua_0;
    person  xiao_hua_1(18, pName,false);

    person xiao_hua_2(xiao_hua_1); 

    person xiao_hua_mao;
    xiao_hua_mao = xiao_hua_2;

    std::cout << "Hello World!\n";
}

