#include <iostream>

/*
继承 - 文明上下五千年，子承父业还给钱

在C++中，继承是一个类从另一个类获取其特性（数据成员和方法）的方式
继承代表了  is a 关系。例如，哺乳动物是动物，狗是哺乳动物。
多继承即一个子类可以有多个基类，它继承了多个基类的特性
*/


class Father
{
protected:
    char m_name[100];
    int m_age;
    int m_money;
    bool m_is_have_house;

public:
    Father() { std::cout << " empty constructed \n"; }
    Father(const char* pName,int age,int money,bool is_have_house):m_age(age)
    {
        memcpy(m_name,pName,strlen(pName) + 1);
        //m_age = age;
        m_money = money;
        m_is_have_house = is_have_house;
        std::cout <<" in father class" << m_name << " is constructed \n";

    }

    ~Father()
    {
        std::cout <<"in father class" << m_name << " is destructed \n";
    }

    void watch_movie(Father* pOther)
    {
        //this 代表当前实例对象的指针，不同实例调用进来，this指针不一样。
        this->m_money -= 1;
        m_money -= 1;

        std::cout << m_name << " and " << pOther->m_name << "is watch movie \n";
    }

};

class Monther
{
public:
    void sing_song() 
    {
        std::cout << " sing a song \n";
    }
};

class son_wushi : public Father,public Monther
{
public:
    son_wushi(const char* pName, int age, int money, bool is_have_house) :Father(pName,age,money,is_have_house)
    {
        std::cout << " in son class" << m_name << " is constructed \n";
    }

    ~son_wushi()
    {
        std::cout << " in son class" << m_name << " is son destructed \n";
    }
};

class son_langman : public Father, public Monther
{
public:
    son_langman(const char* pName, int age, int money, bool is_have_house) :Father(pName, age, money, is_have_house)
    {
        std::cout << " in son class" << m_name << " is constructed \n";
    }

    ~son_langman()
    {
        std::cout << " in son class" << m_name << " is son destructed \n";
    }
};


int main()
{
    son_langman gou_dan = { "gou_dan",28,10000,false };
    son_langman cui_hua = { "cui_hua",21,10000,false };

    gou_dan.watch_movie(&cui_hua);
    gou_dan.sing_song();

 
}

