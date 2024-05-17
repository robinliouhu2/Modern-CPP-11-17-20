#pragma once
#include <iostream>
#include "Father.h"
#include "Mother.h"

class son_wushi : public Father, public Mother
{
public:
	son_wushi(const char* pName, int age, int money, bool is_have_house) :Father(pName, age, money, is_have_house)
	{
		std::cout << " in son class " << m_name << " is constructed \n";
	}

	~son_wushi()
	{
		std::cout << " in son class " << m_name << "is son destructed \n";
	}
};
