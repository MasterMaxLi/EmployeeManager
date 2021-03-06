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
	bool m_FileIsEmpty;

	//统计文件中的人数
	int getEmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void show_Emp();

	//删除员工
	void Del_Emp();

	//判断员工是否存在
	int IsExit(int id);

	//修改职工信息
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按升序排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();
};