#include "test.h"

void test::test1()
{
	smsm.init();
	
	int deptno;
	string dname;
	string loc;
	cout << "�����������Ϣ��" << endl;
	cin >> deptno >> dname >> loc;
	char sql[256];
	sprintf_s(sql,"insert into dept values(\"%d\",\"%s\",\"%s\")",deptno,dname.c_str(),loc.c_str());
	smsm.query(sql);
	cout << "Ӱ��������" << mysql_affected_rows(&smsm.myCont) << endl;
	smsm.freeMysql();
}
