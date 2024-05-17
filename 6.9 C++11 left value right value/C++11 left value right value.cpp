﻿//C++ 11 左值和右值

//1.为什么需要左值/右值-转移语义(将亡值)
/*
左值引用：引用一个对象
右值引用：实现“移动语义",重用将亡值的资源
*/

//2.什么是左值和右值
/*
1.1 =号左边是左值，右边是右值 (不准确)
1.2 左值是可寻址的变量,可被修改.右值一般是不可寻址的变量,不能被修改 （不准确）
1.3 推荐理解：
所有对象都具备左值或右值，你用不用它就在那。 
我们修改它时，它是左值。我们用它转移赋值给其它对象时，它是右值(将亡值)。
*/


//3.右值引用（转移语义）对标准库中的使用和辅助函数
/*
*
3.1 emplace_back
3.2 std::move 

易错点：
通过右值引用转移赋值给另一个对象时，右值引用的对象也可叫”将亡值“。
所以请在某个对象要挂或不会被使用的时候，
才通过右值引用将它的装备(如:内存)转给别人
*/
#include "Data.h"
#include <vector>
#include <list>
#include <map>


int main()
{
	//std::map<int, Data> maps;
	//maps.emplace();

	//std::list<Data> lists;
	//lists.emplace_back();

	std::vector<Data> vecs;
	
	Data obj1;
	obj1.set_first_item(6);
	//vecs.push_back(obj1);
	
	vecs.emplace_back(std::move(obj1));

	//obj1.get_first_item();  //will throw  exception 
	

}


