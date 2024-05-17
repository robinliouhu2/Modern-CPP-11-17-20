#include <iostream>

/*  封装
*
C++ 面向对象的三个特性 封装 继承 多态
访问权限控制符 public protected private
friend
*/

class person
{
public:
    char name[100];
    int age;
    int money;
    bool is_have_house;

    void watch_movie(person* pOther)
    {
        //this 代表当前实例对象的指针，不同实例调用进来，this指针不一样。
        this->money -= 1;
        money -= 1;

        std::cout << name << " and " << pOther->name << "is watch movie \n";
    }

};

class person_2
{
private:
    int money;
    void watch_movie(person* pOther)
    {

    }
  
    friend class bank;
};

class bank
{
public:
    void add_money(person_2* pPerson)
    {
        pPerson->money += 10000;
    }
};
int main()
{
    person gou_dan = { "gou_dan",28,10000,false };
    person cui_hua = { "cui_hua",21,10000,false };

    gou_dan.money += 1;
    gou_dan.watch_movie(&cui_hua);

    person_2 gou_dan_2;

    //bank 声明为 gou_dan_2  friend 友元类，所以可以在bank类中操作 person_2 的私有成员
    //gou_dan_2.money += 1;
    bank l_bank;
    l_bank.add_money(&gou_dan_2);
}

