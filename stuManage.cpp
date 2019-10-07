#include "stuManage.h"

stuManage::stuManage()
{
}

stuManage::stuManage(string name, string tel, string addr, string id)
{
	this->name = name;
	this->tel = tel;
	this->addr = addr;
	this->id = id;
}

student::student()
{
}

student::student(string name, string tel, string addr, string id, string code, double math, double chinese, double english)
{
	this->name = name;
	this->tel = tel;
	this->addr = addr;
	this->id = id;
	this->code = code;
	this->math = math;
	this->chinese = chinese;
	this->english = english;
}

double student::getsum()
{return chinese+math+english;}

double student::getaver()
{return (chinese + math + english)/3;}

control::control()
{
}

void control::find(vector<student>& ver)
{
	cout << "请输入需要查询学生的学号和姓名:" << endl;
	string name,code;
	cin >> name >> code;
	vector<student>::iterator stu=ver.begin();
	for (stu; stu != ver.end(); stu++) 
	{
		if ((*stu).name == name && (*stu).code == code)
		{
			cout << "查询结果为：" << endl;
			cout << (*stu).name << " " << (*stu).tel << " " << (*stu).addr 
				<< " " << (*stu).id << " " << (*stu).code << " " << (*stu).math << " "
				<< (*stu).chinese << " " << (*stu).english << endl;
			char sql[2048];
			sprintf_s(sql, "select * from student where name=\"%s\" and code=\"%s\"", name.c_str(), code.c_str());
			smsm.query(sql);
			smsm.freeMysql();
		}
		else
			cout << "查询失败！" << endl;
	}
	
}

void control::edit(vector<student>& ver)
{
	string name, code;
	cout << "请输入需要编辑的学生姓名和学号:" << endl;
	cin >> name >> code;
	vector<student>::iterator stu = ver.begin();
	for (stu; stu != ver.end(); stu++)
	{
		if ((*stu).name == name && (*stu).code == code)
		{
			cout << "旧数据为：" << endl;
			cout << (*stu).name << " " << (*stu).tel << " " << (*stu).addr
				<< " " << (*stu).id << " " << (*stu).code << " " << (*stu).math << " "
				<< (*stu).chinese << " " << (*stu).english << endl;
			cout << "请输入新数据：" << endl;
			cout << "请输入姓名：" << endl;
			cin >> (*stu).name;
			cout << "请输入电话：" << endl;
			cin >> (*stu).tel;
			cout << "请输入地址：" << endl;
			cin >> (*stu).addr;
			cout << "请输入身份证号：" << endl;
			cin >> (*stu).id;
			cout << "请输入学号：" << endl;
			cin >> (*stu).code;
			cout << "请输入数学成绩：" << endl;
			cin >> (*stu).math;
			cout << "请输入语文成绩：" << endl;
			cin >> (*stu).chinese;
			cout << "请输入英语成绩：" << endl;
			cin >> (*stu).english;

			(*stu).getsum();
			(*stu).getaver();

			cout << "修改成功！" << endl;
			cout << "新数据为:" << endl;
			cout << (*stu).name << " " << (*stu).tel << " " << (*stu).addr
				<< " " << (*stu).id << " " << (*stu).code << " " << (*stu).math << " "
				<< (*stu).chinese << " " << (*stu).english << endl;
			char sql[2048];
			sprintf_s(sql,
				"update student set name=\"%s\", tel=\"%s\", addr=\"%s\",id=\"%s\", code=\"%s\", math=\"%lf\",chinese=\"%lf\", english=\"%lf\" where name=\"%s\" and code=\"%s\""
				, (*stu).name.c_str()
				, (*stu).tel.c_str()
				, (*stu).addr.c_str()
				, (*stu).id.c_str()
				, (*stu).code.c_str()
				, (*stu).math
				, (*stu).chinese
				, (*stu).english
				, name.c_str()
				, code.c_str()

			);
			cout << sql << endl;
			smsm.query(sql);
		}
		else
			cout << "修改失败!" << endl;
	}
}

void control::del(vector<student>& ver)
{
	cout << "请输入要删除学生的姓名和学号：" << endl;
	string name, code;
	cin >> name >> code;
	vector<student>::iterator stu = ver.begin();
	for (stu; stu != ver.end(); stu++)
	{
		if (((*stu).name == name && (*stu).code == code))
		{
			ver.erase(stu);
			char sql[2048];
			sprintf_s(sql,"delete from student where name=\"%s\" and code=\"%s\"",name.c_str(),code.c_str());
			smsm.query(sql);
	
		}
		else
			cout << "删除失败！" << endl;
	}
}

void control::insert(vector<student>& ver)
{
	student stu;
	cout << "请输入学生信息：" << endl;
	cout << "请输入姓名：" << endl;
	cin >> stu.name;
	cout << "请输入电话：" << endl;
	cin >> stu.tel;
	cout << "请输入地址：" << endl;
	cin >> stu.addr;
	cout << "请输入身份证号：" << endl;
	cin >> stu.id;
	cout << "请输入学号：" << endl;
	cin >> stu.code;
	cout << "请输入数学成绩：" << endl;
	cin >> stu.math;
	cout << "请输入语文成绩：" << endl;
	cin >> stu.chinese;
	cout << "请输入英语成绩：" << endl;
	cin >> stu.english;

	stu.getsum();
	stu.getaver();
	ver.push_back(stu);

	char sql[2048];
	sprintf_s(sql, 
		"insert into student values(\"%s\", \"%s\", \"%s\",\"%s\", \"%s\", \"%lf\",\"%lf\", \"%lf\")"
		, stu.name.c_str()
		, stu.tel.c_str()
		, stu.addr.c_str()
		, stu.id.c_str()
		, stu.code.c_str()
		, stu.math
		, stu.chinese
		, stu.english
	);
	smsm.query(sql);
	cout << "信息插入成功！" << endl;
}

double greatesum(student s1,student s2)
{
	return s1.getsum() > s2.getsum() ? true : false;
}
double greateaver(student s1, student s2)
{
	return s1.getaver() > s2.getaver() ? true : false;
}
double greatemath(student s1, student s2)
{
	return s1.math > s2.math ? true : false;
}
double greatechinese(student s1, student s2)
{
	return s1.chinese > s2.chinese ? true : false;
}
double greateenglish(student s1, student s2)
{
	return s1.english > s2.english ? true : false;
}

void control::st(vector<student>& ver)
{
	cout << "请选择按那种成绩排名： " << endl;
	cout << "**** (1)按总分排名 ****" << endl;
	cout << "**** (2)按均分排名 ****" << endl;
	cout << "**** (3)按数学排名 ****" << endl;
	cout << "**** (4)按语文排名 ****" << endl;
	cout << "**** (5)按英语排名 ****" << endl;
	cout << "**** (0)返回上一级 ****" << endl;
	int fg;
	cin >> fg;
	if (fg == 0)return;
	if (fg == 1)
	{
		sort(ver.begin(), ver.end(), greatesum);
		list(ver);
	}
	if (fg == 2)
	{
		sort(ver.begin(), ver.end(), greateaver);
		list(ver);
	}
	if (fg == 3)
	{
		sort(ver.begin(), ver.end(), greatemath);
		list(ver);
	}
	if (fg == 4)
	{
		sort(ver.begin(), ver.end(), greatechinese);
		list(ver);
	}
	if (fg == 5)
	{
		sort(ver.begin(), ver.end(), greateenglish);
		list(ver);
	}
}

void control::list(vector<student>& ver)
{
	vector<student>::iterator stu=ver.begin();
	for (stu; stu != ver.end(); stu++)
	{
		cout << (*stu).name << " " << (*stu).tel << " " << (*stu).addr
			<< " " << (*stu).id << " " << (*stu).code << " " << (*stu).math << " "
			<< (*stu).chinese << " " << (*stu).english << endl;
	}
}

void control::gui()
{
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "*                    请选择需要的操作!                    *" << endl;
	cout << "*                    (1)增加人员                          *" << endl;
	cout << "*                    (2)删除人员                          *" << endl;
	cout << "*                    (3)修改数据                          *" << endl;
	cout << "*                    (4)查询                              *" << endl;
	cout << "*                    (5)输出所有学生数据                  *" << endl;
	cout << "*                    (6)按成绩排序                        *" << endl;
	cout << "*                    (0)退出                              *" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}
