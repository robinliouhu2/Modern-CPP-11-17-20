// 
//

#include "student.h"

int main()
{
    student la;
    la.print();

    student lb;
    student lc;

    //可以通过类名直接访问类成员函数和方法。 静态成员函数和方法属于所有类实例共享
    int number = student::m_studentInstanceNumber;
    student::print();


    std::cout << "Hello World!\n";
}

