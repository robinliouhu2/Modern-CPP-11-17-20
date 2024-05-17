/*
C++ 17 structured binding 结构化绑定
结构化绑定（Structured Binding）允许一次性地将聚合类型（如数组、结构体、元组等）中的
多个值解包到不同的变量中
*/

#include <iostream>
#include <map>

struct person
{
    int m_age;
    std::string m_name;
    int m_money;
};

int main()
{
    person lao_liu = { 1,"laoliu",100 };

    /*
    int age = lao_liu.m_age;
    std::string name = lao_liu.m_name;
    int m_money = lao_liu.m_money;
    */

    //等价于上方注释的代码
    auto [age, name, money] = lao_liu;

    std::map<int, person> map_conainter;
    map_conainter.insert(std::pair<int,person>(666, lao_liu));

    //普通版本
    for (auto kv : map_conainter)
    {
        std::cout <<" ID is " << kv.first << " value is " << kv.second.m_name << std::endl;
    }

    //结构化绑定的版本
    for (auto [k, v] : map_conainter)
    {
        std::cout << " ID is " << k << " value is " << v.m_name << std::endl;
    }



    
}
