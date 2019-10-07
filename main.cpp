#include<iostream>
#include"test.h"
#include"timeSch.h"
#include"stuManage.h"
using namespace std;

int stuManage_main()  //学生信息管理系统启动函数
{
	control ct;
	ct.smsm.init();
	vector<student> ver;
	int cho;
	while (1)
	{
		ct.gui();
		cin >> cho;
		switch (cho)
		{
		case 0:exit(0); break;
		case 1:ct.insert(ver); break;
		case 2:ct.del(ver); break;
		case 3:ct.edit(ver); break;
		case 4:ct.find(ver); break;
		case 5:ct.list(ver); break;
		case 6:ct.st(ver); break;
		default:exit(0); break;
		}
	}
	return 0;
}

int main()
{
	timeSch ts;
	ts.remindMe();

	stuManage_main();
	
	return 0;
}
