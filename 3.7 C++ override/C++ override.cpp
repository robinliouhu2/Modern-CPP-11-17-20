/*
* 重载 - 狗蛋他爹有情趣，送花总是如人意
*
*重载是指当前作用域中允许定义多个名称相同的函数，但是它们的参数不同(类型或数量不相同)

调用函数或运算符时，编译器会根据参数进行匹配，调用正确的函数或运算符
*/

#include <iostream>
#include "song_langman.h"

int main()
{
    Father  gou_bu_li("gou_bu_li", 58, 100000, true);
    Father cui_hua("wang lao liu", 59, 100000, true);

    rose l_rose;
    you_cai_hua l_youcai_hua;

    //重载
    gou_bu_li.send_gift();
    gou_bu_li.send_gift(l_rose);
    gou_bu_li.send_gift(l_youcai_hua);
}

