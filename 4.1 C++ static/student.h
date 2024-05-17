#pragma once
#include <iostream>

class student
{
public:
	int m_age;
	static int m_studentInstanceNumber;
	student();
	~student();
public:
	static void print()
	{
		//静态成员函数中不能访问类的非静态成员
		//m_age = 3;
		//std::cout << m_age << std::endl;

		std::cout << "static function get called m_studentInstanceNumber:" << m_studentInstanceNumber << std::endl;
	}
};
