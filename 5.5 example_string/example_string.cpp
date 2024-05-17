// example_string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>


/*
# string

底层使用动态数据

字符串是表示字符序列的对象
*/

int main()
{
	std::string  name = "zhang san";
	name = name + " zai mo yu";

	std::string lstr = name.substr(1,3);
	std::string replaced = name.replace(name.begin() + 2 ,name.end()," replaced");

	//name[0];
	//std::string::iterator iter;
	//*iter




	std::cout << name << std::endl;
	std::cout << lstr << std::endl;
	std::cout << replaced << std::endl;
	std::cout << name.erase(1, 1) << std::endl;




 
}

