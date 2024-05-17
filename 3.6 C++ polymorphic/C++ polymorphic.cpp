/*
# 多态(虚函数) - 儿子恋爱有主意，老子松口没脾气

1.定义:
虚函数 - 是使用关键字 virtual 声明的函数(虚函数)。
多态 - 在派生类中重新实现基类中的虚函数时，会根据指针或引用所指向
实际对象的类型来调用相应的函数

2.虚析构函数

3.什么是纯虚函数和抽象类
*/

#include <iostream>
#include "song_langman.h"

int main()
{
    son_langman gou_dan("gou_dan", 28, 10000, true);
    son_langman cui_hua("cui_hua", 21, 20000, false);

    gou_dan.watch_movie(&cui_hua);
    gou_dan.send_gift();

    //用父类指针或引用执行不同的实例，调用时会根据所指向对象，调用对于父类或子类的方法。叫多态
    Father* pFather = NULL;

    pFather = &gou_dan;
    pFather->send_gift(); // 根据指向的实际对象，调用的时子类的方法


    Father gou_bu_li("gou bu li", 58, 10000, true);
    pFather = &gou_bu_li;
    pFather->send_gift(); // 根据指向的实际对象，调用的时父类的方法
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

