#pragma once
#include<iostream>

using namespace std;

class Worker 
{
public:
	//职工id
	int m_Id;
	//姓名
	string m_Name;
	//部门编号
	int m_DeptId;	

	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
};