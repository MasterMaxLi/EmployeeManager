#pragma once
#include<iostream>

using namespace std;

class Worker 
{
public:
	//ְ��id
	int m_Id;
	//����
	string m_Name;
	//���ű��
	int m_DeptId;	

	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;
};