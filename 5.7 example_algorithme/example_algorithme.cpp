
#include <iostream>
#include <vector>
#include <list>

#include <algorithm>



int main()
{
	std::vector<int> ves = { 1,0,9,8,2,3 };
	std::list<int> lists = { 1,0,9,8,2,3 };

	lists.sort();


	std::vector<int>::iterator iter = std::find(ves.begin(), ves.end(), 9);


	if (iter != ves.end())
	{
		//std::cout << *iter;
	}
	else
	{
		//std::cout << "not found ";
	}

	std::sort(ves.begin(),ves.end());

	for (std::vector<int>::iterator iter1 = ves.begin();iter1!=ves.end();++iter1)
	{
		std::cout << *iter1 << std::endl;
	}


   
}

