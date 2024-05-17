/*
重定义（隐藏） - 老子节俭爱送花，儿子有钱不随他

子类继承父类后，在子类中实现了和父类同名的函数，父类的同名函数会被隐藏，默认访问的是子类的函数。
*/


#include <iostream>
#include "song_langman.h"

int main()
{
    son_langman gou_dan("gou_dan", 28, 10000, true);
    son_langman cui_hua("cui_hua", 21, 20000, false);

    gou_dan.watch_movie(&cui_hua);
    gou_dan.send_gift();

    //用父类指向gou_dan 的实例，执行的是父类的方法，实践中不符合预期和理解，会在讲多态时解决该问题
    Father* pFather = &gou_dan;
    pFather->send_gift();
}

