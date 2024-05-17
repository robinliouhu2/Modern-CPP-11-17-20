#include <iostream>
/*
*接口-狗蛋他爹愁白发，恋爱咱也有章法
接口(纯虚函数)描述了类的行为和功能，而不需要完成类的具体实现。
是一种对外的行为承诺，对内的行为约定
*/

#include "song_langman.h"


int main()
{
	IDatingInterface* p = new Father("gou_bu_li", 59, 100000, true);

	p->talk();
	p->walk();
	//p->watch_movie();

	free(p);

	p = new son_langman("gou dan", 28, 1000000, true);
	p->talk();
	p->send_gift();
	free(p);
}


