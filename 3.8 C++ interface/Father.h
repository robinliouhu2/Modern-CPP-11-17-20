#pragma once
#include "IDatingInterface.h"


class rose
{

};

class you_cai_hua
{

};

class xy
{
	
};

class Father : public IDatingInterface
{
protected:
	char m_name[100];
	int  m_age;
	int  m_money;
	bool m_is_have_house;
public:
	Father(const char* pName, int age, int money, bool is_have_house) :m_age(age)
	{
		memcpy(m_name, pName, strlen(pName) + 1);
		//m_age = age;
		m_money = money;
		m_is_have_house = is_have_house;

		std::cout<< " in father  class" << m_name << " is constructed \n";
	}

	virtual~Father()
	{
		std::cout << " in father  class " << m_name << "is person destructed \n";
	}

	char* getName()
	{
		return  m_name;
	}

	virtual int   getMoney()
	{
		return m_money;
	}

	 void watch_movie(IDatingInterface* pOther)
	{
		this->m_money -= 1;
		m_money -= 1;

		std::cout << m_name << " and " << pOther->getName() << " is watch movie \n";
	}

	virtual void talk() { }
	  void walk() { };

	virtual void send_gift() 
	{
		std::cout << "father 送了一朵无名花" << "\n";
	}

	bool operator > (const xy& other)
	{
		return false;
	}

	bool operator > (const Father& other)
	{
		return m_age > other.m_age;
	}

	virtual void send_gift(rose inrose)
	{
		std::cout << "father 送了一朵玫瑰花" << "\n";
	}

	virtual void send_gift(you_cai_hua inyoucaihua)
	{
		std::cout << "father 送了一朵油菜花花" << "\n";
	}




};