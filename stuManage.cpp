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
	cout << "��������Ҫ��ѯѧ����ѧ�ź�����:" << endl;
	string name,code;
	cin >> name >> code;
	vector<student>::iterator stu=ver.begin();
	for (stu; stu != ver.end(); stu++) 
	{
		if ((*stu).name == name && (*stu).code == code)
		{
			cout << "��ѯ���Ϊ��" << endl;
			cout << (*stu).name << " " << (*stu).tel << " " << (*stu).addr 
				<< " " << (*stu).id << " " << (*stu).code << " " << (*stu).math << " "
				<< (*stu).chinese << " " << (*stu).english << endl;
			char sql[2048];
			sprintf_s(sql, "select * from student where name=\"%s\" and code=\"%s\"", name.c_str(), code.c_str());
			smsm.query(sql);
			smsm.freeMysql();
		}
		else
			cout << "��ѯʧ�ܣ�" << endl;
	}
	
}

void control::edit(vector<student>& ver)
{
	string name, code;
	cout << "��������Ҫ�༭��ѧ��������ѧ��:" << endl;
	cin >> name >> code;
	vector<student>::iterator stu = ver.begin();
	for (stu; stu != ver.end(); stu++)
	{
		if ((*stu).name == name && (*stu).code == code)
		{
			cout << "������Ϊ��" << endl;
			cout << (*stu).name << " " << (*stu).tel << " " << (*stu).addr
				<< " " << (*stu).id << " " << (*stu).code << " " << (*stu).math << " "
				<< (*stu).chinese << " " << (*stu).english << endl;
			cout << "�����������ݣ�" << endl;
			cout << "������������" << endl;
			cin >> (*stu).name;
			cout << "������绰��" << endl;
			cin >> (*stu).tel;
			cout << "�������ַ��" << endl;
			cin >> (*stu).addr;
			cout << "���������֤�ţ�" << endl;
			cin >> (*stu).id;
			cout << "������ѧ�ţ�" << endl;
			cin >> (*stu).code;
			cout << "��������ѧ�ɼ���" << endl;
			cin >> (*stu).math;
			cout << "���������ĳɼ���" << endl;
			cin >> (*stu).chinese;
			cout << "������Ӣ��ɼ���" << endl;
			cin >> (*stu).english;

			(*stu).getsum();
			(*stu).getaver();

			cout << "�޸ĳɹ���" << endl;
			cout << "������Ϊ:" << endl;
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
			cout << "�޸�ʧ��!" << endl;
	}
}

void control::del(vector<student>& ver)
{
	cout << "������Ҫɾ��ѧ����������ѧ�ţ�" << endl;
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
			cout << "ɾ��ʧ�ܣ�" << endl;
	}
}

void control::insert(vector<student>& ver)
{
	student stu;
	cout << "������ѧ����Ϣ��" << endl;
	cout << "������������" << endl;
	cin >> stu.name;
	cout << "������绰��" << endl;
	cin >> stu.tel;
	cout << "�������ַ��" << endl;
	cin >> stu.addr;
	cout << "���������֤�ţ�" << endl;
	cin >> stu.id;
	cout << "������ѧ�ţ�" << endl;
	cin >> stu.code;
	cout << "��������ѧ�ɼ���" << endl;
	cin >> stu.math;
	cout << "���������ĳɼ���" << endl;
	cin >> stu.chinese;
	cout << "������Ӣ��ɼ���" << endl;
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
	cout << "��Ϣ����ɹ���" << endl;
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
	cout << "��ѡ�����ֳɼ������� " << endl;
	cout << "**** (1)���ܷ����� ****" << endl;
	cout << "**** (2)���������� ****" << endl;
	cout << "**** (3)����ѧ���� ****" << endl;
	cout << "**** (4)���������� ****" << endl;
	cout << "**** (5)��Ӣ������ ****" << endl;
	cout << "**** (0)������һ�� ****" << endl;
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
	cout << "*                    ��ѡ����Ҫ�Ĳ���!                    *" << endl;
	cout << "*                    (1)������Ա                          *" << endl;
	cout << "*                    (2)ɾ����Ա                          *" << endl;
	cout << "*                    (3)�޸�����                          *" << endl;
	cout << "*                    (4)��ѯ                              *" << endl;
	cout << "*                    (5)�������ѧ������                  *" << endl;
	cout << "*                    (6)���ɼ�����                        *" << endl;
	cout << "*                    (0)�˳�                              *" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}
