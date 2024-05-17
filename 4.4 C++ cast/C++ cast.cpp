// C++ cast.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
class Base {
	virtual void add() {};
};
class Derived : public Base {
};

int main()
{
	/*
	* reinterpret_cast：对类型进行重新解释，最普遍的用法就是在函数指针类型之间进行转换
	*/
	bool b1 = 1;
	int a = 196;
	bool b2 = *reinterpret_cast<bool*>(&a);

	/*
	const_cast：这用于修改类型的 const 或 volatile 属性。
	*/
	const int ci = 10;
	int* pi = const_cast<int*>(&ci);  // 去掉 const 属性


   /*
   static_cast：这是最常用的 cast，可以用于基本数据类型之间的转换，例如 int 转换为 float，或者指针之间的转换。
   */
	int i = 10;
	float f = static_cast<float>(i);  // int 转 float

	/*
	dynamic_cast：这主要用于类层次结构中基类和派生类之间的类型转换。如果类型转换不安全，那么该 cast 会返回 NULL。
	*/
	Base* base = new Derived();
	Derived* derived = dynamic_cast<Derived*>(base);  // 基类转派生类
}
