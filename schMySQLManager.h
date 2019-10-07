#pragma once
#ifndef _SCHMYSQLMANAGER_H
#define _SCHMYSQLMANAGER_H

#include<iostream>
using namespace std;
#include "winsock2.h"
#include "windows.h" 
#include "include/mysql.h"
#include"stdio.h"
#pragma comment(lib,"libmySQL.lib")

class schMySQLManager
{
private:
	const char host[50] = "localhost";    //MySQL服务器IP地址；若是本地可填写“localhost”或127.0.0.1  
	const char user[50] = "root";         //MySQL的用户名  
	const char pswd[50] = "hgdsch217679";         //密码  
	const char table[50] = "test";        //数据库名称  
	unsigned int port = 3306;           //MySQL服务端口号，默认是3306    
public:
	MYSQL myCont;//创建MYSQL对象，定义数据库连接句柄  
	MYSQL_RES* result = NULL;//查询结果集，存放查询结果  
	MYSQL_ROW sql_row;//存放一行查询结果的字符串数组  
	MYSQL_FIELD* fd; // 包含字段信息的结构
	char column[32][32];
	int res;
public:
	void init();
	void query(const char * sql);
	void freeMysql();
};

#endif