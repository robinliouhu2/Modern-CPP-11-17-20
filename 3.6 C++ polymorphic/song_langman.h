#pragma once
#include <iostream>
#include "Father.h"
#include "Mother.h"
class son_langman : public Father, public Mother
{
public:
	son_langman(const char* pName, int age, int money, bool is_have_house) :Father(pName, age, money, is_have_house)
	{
		std::cout << " in son class " << m_name << " is constructed \n";
	}

	~son_langman()
	{
		std::cout << " in son class " << m_name << "is son destructed \n";
	}

	void send_gift() { std::cout << "送出一个钻戒\n"; };


};