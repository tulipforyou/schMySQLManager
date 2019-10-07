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
	const char host[50] = "localhost";    //MySQL������IP��ַ�����Ǳ��ؿ���д��localhost����127.0.0.1  
	const char user[50] = "root";         //MySQL���û���  
	const char pswd[50] = "hgdsch217679";         //����  
	const char table[50] = "test";        //���ݿ�����  
	unsigned int port = 3306;           //MySQL����˿ںţ�Ĭ����3306    
public:
	MYSQL myCont;//����MYSQL���󣬶������ݿ����Ӿ��  
	MYSQL_RES* result = NULL;//��ѯ���������Ų�ѯ���  
	MYSQL_ROW sql_row;//���һ�в�ѯ������ַ�������  
	MYSQL_FIELD* fd; // �����ֶ���Ϣ�Ľṹ
	char column[32][32];
	int res;
public:
	void init();
	void query(const char * sql);
	void freeMysql();
};

#endif