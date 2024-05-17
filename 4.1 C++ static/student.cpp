#include "student.h"

int student::m_studentInstanceNumber = 0;

student::student() 
{
	++m_studentInstanceNumber;
}

student::~student() {}
