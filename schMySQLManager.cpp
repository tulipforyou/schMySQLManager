#include "schMySQLManager.h"

void schMySQLManager::init()
{
	mysql_library_init(0, NULL, NULL);//��ʼ��MySQL��  
	mysql_init(&myCont);//��ʼ�����Ӵ������ 
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{//ͨ������mysql_real_connect()���ӵ������� 
		cout << "MySQL connect succeed!" << endl;
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����  
	}
	else
		cout << "MySQL connect failed!" << endl;
}

void schMySQLManager::query(const char *sql)
{
	res = mysql_query(&myCont, sql);//ִ�в�ѯ��䣬mysql_query�����ѯ�ɹ����㣻�������һ�����󣬷��㡣  
	if (res == 0)
	{
		cout << "��ǰ��䣺   " << sql << "   ִ�гɹ���" << endl;
	}
	if (!res)
	{
		result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result  
		if (result)
		{
			int i, j;
			cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
			for (i = 0; fd = mysql_fetch_field(result); i++)//��ȡ����  
			{
				strcpy_s(column[i], fd->name);
			}
			j = mysql_num_fields(result);
			for (i = 0; i < j; i++)
			{
				printf("%s\t", column[i]);
			}
			printf("\n");
			while (sql_row = mysql_fetch_row(result))//��ȡ���������  
			{
				for (i = 0; i < j; i++)
				{
					printf("%s\t", sql_row[i]);
				}
				printf("\n");
			}
		}
	}
	else
	{
		cout << "query sql failed!" << endl;
	}
}

void schMySQLManager::freeMysql()
{
	if (result != NULL) mysql_free_result(result);//�ͷŽ����Դ  
	mysql_close(&myCont);//�ر�MySQL����  
	mysql_library_end();//�ر�MySQL��  */
}
