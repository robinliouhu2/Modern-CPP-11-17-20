#include <iostream>
#include <map>
/*
1.访问： 迭代器 []
2.增删改
3.易错点
3.1 注意迭代器失效的问题，特别是在遍历过程中删除元素
3.2 通过下标访问操作符访问一个不存在的key，容器会以该key值自动创建一个元素
*/


int main()
{
	std::map<uint32_t, std::string> mapInstance;
	mapInstance.insert(std::pair<uint32_t, std::string>(1, "xiao hua"));
	mapInstance.insert(std::pair<uint32_t, std::string>(9, " wang ma zi"));
	mapInstance.insert(std::pair<uint32_t, std::string>(2, " hua xiao"));
	mapInstance.insert(std::pair<uint32_t, std::string>(6, " wang ma zi"));
	mapInstance.insert(std::pair<uint32_t, std::string>(3, " wang ma zi"));


	
	for (std::map<uint32_t, std::string>::iterator iter = mapInstance.begin();iter!=mapInstance.end();)
	{
		iter->second += " hello";
		std::cout << " item ID is: " << iter->first << " value is: " << iter->second << std::endl;

		if (iter->first == 2)
			iter = mapInstance.erase(iter); //目前代码有问题
		else
			++iter;
	}

	std::cout << "access not exist key, value is:" << mapInstance[10] << std::endl;


}