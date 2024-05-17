#include <iostream>

/*
* 生死看淡就是干，世事无常少扯蛋
*
* 构造函数 - 创建对象时被自动调用
* 析构函数 - 删除对象时被自动调用
*/

class person
{
private:
    char m_name[100];
    int m_age;
    int m_money;
    bool m_is_have_house;

public:
    person() { std::cout << " empty constructed \n"; }
    person(const char* pName, int age, int money, bool is_have_house) :m_age(age)
    {
        memcpy(m_name, pName, strlen(pName) + 1);
        //m_age = age;
        m_money = money;
        m_is_have_house = is_have_house;
        std::cout << m_name << " is constructed \n";

    }

    ~person()
    {
        std::cout << m_name << " is destructed \n";
    }

    void watch_movie(person* pOther)
    {
        //this 代表当前实例对象的指针，不同实例调用进来，this指针不一样。
        this->m_money -= 1;
        m_money -= 1;

        std::cout << m_name << " and " << pOther->m_name << "is watch movie \n";
    }

};


int main()
{
    //person gou_dan = { "gou_dan",28,10000,false };
    //person cui_hua = { "cui_hua",21,10000,false };

    person* pWangLaoWu = new person("gou_dan", 28, 10000, false);
    delete pWangLaoWu;

    //数组需要通过delete[] 删除，这样每个person类的析构函数才都会被调用
    person* pArray = new person[10];
    delete[] pArray;
}

