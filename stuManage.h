#pragma once
#ifndef _STUMANAGE_H
#define _STUMANAGE_H


#include "schMySQLManager.h"
#include<vector>
#include<algorithm>

class stuManage  //����
{
public:
	string name;  //����
	string tel;	  //�绰��
	string addr;  //��ַ
	string id;	  //���֤
	stuManage();  //
	stuManage(string name, string tel, string addr, string id);
};
class student :public stuManage  //ѧ����
{
public:
	string code;     //ѧ��
	double math;	 //��ѧ
	double chinese;	 //����
	double english;	 //Ӣ��
	student();
	student(string name, string tel, string addr, string id, string code, double math, double chinese, double english);
	double getsum();  //�����ܷ�
	double getaver();  //����ƽ����
};		
class control  //������
{
public:
	control();
	schMySQLManager smsm;
	void find(vector<student>& ver);		//��ѯѧ����Ϣ
	void edit(vector<student>& ver);		//�༭ѧ����Ϣ
	void del(vector<student>& ver);			//ɾ��ѧ����Ϣ
	void insert(vector<student>& ver);		//���ѧ����Ϣ
	void st(vector<student>& ver);			//���ɼ���ѯ����
	void list(vector<student>& ver);		//���ѧ����Ϣ
	void gui();     						//����
};
#endif