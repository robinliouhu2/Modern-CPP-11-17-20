#pragma once

class IDatingInterface
{
public:
	virtual char* getName() = 0;
	virtual int   getMoney() = 0;
	virtual void watch_movie(IDatingInterface* pOther) = 0;
	virtual void talk() = 0;
	virtual void walk() = 0;
	virtual void send_gift() = 0;
};
