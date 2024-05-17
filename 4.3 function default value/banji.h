#pragma once

#include <iostream>

typedef enum {SWEET,KU_DE}TASTE;

class  banji
{
	TASTE m_choose;
public:
	//缺省参数
	 banji(TASTE choose = SWEET);
	 ~banji() {};
	
	 
	 //inline 内联函数需放在头文件中定义，否则会报编译错误 "无法解析的外部符号"
	 inline void eat()
	 {
		 if (m_choose == SWEET)
			 std::cout << "choose sweet" << std::endl;
		 else
			 std::cout << "choose cude" << std::endl;
	 }
};

