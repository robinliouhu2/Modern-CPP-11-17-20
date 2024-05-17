#include <iostream>

/*
+对象  class(类)
-属性  变量
-行为  函数
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

    void see_this()
    {
        std::cout << std::hex<<"this address: 0x" << this << std::endl;
    }
};
int main()
{
    person gou_dan = { "gou_dan",28,10000,false };
    gou_dan.money += 1;

    //下行中的 gou_dan_2 实例和 gou_dan实例调用进入同一个成员函数时,this 指针值是不一样的。 
    person gou_dan_2 = { "gou_dan_2",28,10000,false };
    std::cout << std::hex << "gou_dan address: 0x" << &gou_dan << std::endl;
    gou_dan.see_this();

    std::cout << std::hex << "\n\ngou_dan_2 address: 0x" << &gou_dan_2 << std::endl;
    gou_dan_2.see_this();

}

