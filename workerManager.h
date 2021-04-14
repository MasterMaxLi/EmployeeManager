#pragma once	//防止头文件重复包含
#include<iostream>
#include<fstream>

#include"worker.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void show_Menu();

	//退出系统
	void exit_System();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void addEmp();

	//保存到文件中
	void save();

	//判断文件是否为空

	//析构函数
	~WorkerManager();
};