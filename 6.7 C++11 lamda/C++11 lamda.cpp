/* C++11 lamda 匿名函数

lamda是一种定义匿名函数的方式

lamda语法：

[外部变量捕获方式] (参数) -> 返回值类型(可以有编译器自动推导，可以省略)
{
函数体;
};

外部变量捕获方式(外部变量的捕获方式，捕获后lamda函数才能使用)：
总结：下面的组合都是说明一件事情: 哪个变量以什么方式（传值还是传引用） 传递给lamda函数使用

外部变量格式	        功能
[]	        	        空方括号表示当前 lambda 匿名函数中不导入任何外部变量。
[=]	        	        只有一个 = 等号，表示以值传递的方式导入所有外部变量；
[&]	        	        只有一个 & 符号，表示以引用传递的方式导入所有外部变量；
[val1,val2,...]	        表示以值传递的方式导入 val1、val2 等指定的外部变量，同时多个变量之间没有先后次序；
[&val1,&val2,...]	    表示以引用传递的方式导入 val1、val2等指定的外部变量，多个变量之间没有前后次序；
[val,&val2,...]	        以上 2 种方式还可以混合使用，变量之间没有前后次序。
[=,&val1,...]	        表示除 val1 以引用传递的方式导入外，其它外部变量都以值传递的方式导入。
[this]	                表示以值传递的方式导入当前的 this 指针。

*/

#include <iostream>
#include <vector>
#include <algorithm>

struct cat
{
    std::string name;
    int age;
    int wight;
    int price;
};

bool sort_by_age(cat& cat1,cat& cat2)
{
    return cat1.age < cat2.age;
}

class A
{
    int m_a;
public:
    void add()
    {
        //在类中的非静态成员函数才能捕获this
        auto fn = [this]() { this->m_a += 1; };
    }
};


int main()
{
    std::vector<cat> vecs = { {"cat1",1,2,3},{"cat2",3,2,1},{"cat3",2,1,3} };

    for (auto& item : vecs)
    {
        std::cout << item.name << std::endl;
    }

    //对于只需要使用一次的函数，我们可以直接在代码实现部分定义匿名函数，不用在重新定义一个传统的函数
    int g_age = 10;

    float price = 11;

    std::sort(vecs.begin(), vecs.end(), 
        [&] //外部变量捕获方式，捕获后匿名函数实现时才能使用
        (cat& cat1, cat& cat2)
        {
            return cat1.age < cat2.age;
        }
    );

    std::cout << "after sort" << std::endl;
    for (auto& item : vecs)
    {
        std::cout << item.name << std::endl ;
    }

    
}

