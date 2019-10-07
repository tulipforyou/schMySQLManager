#include "schMySQLManager.h"

void schMySQLManager::init()
{
	mysql_library_init(0, NULL, NULL);//初始化MySQL库  
	mysql_init(&myCont);//初始化连接处理程序 
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{//通过调用mysql_real_connect()连接到服务器 
		cout << "MySQL connect succeed!" << endl;
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文  
	}
	else
		cout << "MySQL connect failed!" << endl;
}

void schMySQLManager::query(const char *sql)
{
	res = mysql_query(&myCont, sql);//执行查询语句，mysql_query如果查询成功，零；如果出现一个错误，非零。  
	if (res == 0)
	{
		cout << "当前语句：   " << sql << "   执行成功！" << endl;
	}
	if (!res)
	{
		result = mysql_store_result(&myCont);//保存查询到的数据到result  
		if (result)
		{
			int i, j;
			cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
			for (i = 0; fd = mysql_fetch_field(result); i++)//获取列名  
			{
				strcpy_s(column[i], fd->name);
			}
			j = mysql_num_fields(result);
			for (i = 0; i < j; i++)
			{
				printf("%s\t", column[i]);
			}
			printf("\n");
			while (sql_row = mysql_fetch_row(result))//获取具体的数据  
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
	if (result != NULL) mysql_free_result(result);//释放结果资源  
	mysql_close(&myCont);//关闭MySQL连接  
	mysql_library_end();//关闭MySQL库  */
}
