#pragma once
#ifndef _STUMANAGE_H
#define _STUMANAGE_H


#include "schMySQLManager.h"
#include<vector>
#include<algorithm>

class stuManage  //基类
{
public:
	string name;  //姓名
	string tel;	  //电话号
	string addr;  //地址
	string id;	  //身份证
	stuManage();  //
	stuManage(string name, string tel, string addr, string id);
};
class student :public stuManage  //学生类
{
public:
	string code;     //学号
	double math;	 //数学
	double chinese;	 //语文
	double english;	 //英语
	student();
	student(string name, string tel, string addr, string id, string code, double math, double chinese, double english);
	double getsum();  //计算总分
	double getaver();  //计算平均分
};		
class control  //操作类
{
public:
	control();
	schMySQLManager smsm;
	void find(vector<student>& ver);		//查询学生信息
	void edit(vector<student>& ver);		//编辑学生信息
	void del(vector<student>& ver);			//删除学生信息
	void insert(vector<student>& ver);		//添加学生信息
	void st(vector<student>& ver);			//按成绩查询排名
	void list(vector<student>& ver);		//浏览学生信息
	void gui();     						//界面
};
#endif