#include<iostream>

#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

WorkerManager::WorkerManager()
{
	//初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager()
{
	//释放开辟在堆区的数据
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::show_Menu()
{
	cout << "******************************************" << endl;
	cout << "***********欢迎使用职工管理系统***********" << endl;
	cout << "**************0.退出管理程序**************" << endl;
	cout << "**************1.增加职工信息**************" << endl;
	cout << "**************2.显示职工信息**************" << endl;
	cout << "**************3.删除职工信息**************" << endl;
	cout << "**************4.修改职工信息**************" << endl;
	cout << "**************5.查找职工信息**************" << endl;
	cout << "**************6.排序职工信息**************" << endl;
	cout << "**************7.清空职工信息**************" << endl;
	cout << "******************************************" << endl;
}

void WorkerManager::exit_System()
{
	cout << "已退出，欢迎下次使用~\n";
	system("pause");
	exit(0);
}

//添加职工的实现
void WorkerManager::addEmp()
{
	cout << "请输入要添加的职工个数：" << endl;
	//保存7用户的输入数量
	int addEmpNum = 0;
	cin >> addEmpNum;
	if (addEmpNum > 0)
	{
		//添加
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + addEmpNum;	//新空间的大小=原空间大小+添加的人数
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原空间的数据拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addEmpNum; i++)
		{
			int id;	//编号
			string name;	//姓名
			int dSelect;	//部门选择

			cout << "请输入第" << i + 1 << "位员工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "位员工的姓名：" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "位员工的岗位：" << endl;
			cout << "请选择该员工的岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新人数
		this->m_EmpNum = newSize;
		//提示添加成功
		cout << "成功添加" << addEmpNum << "名员工" << endl;
		//保存到文件
		this->save();
	}
	else
	{
		//添加数有误
		cout << "输入数据有误" << endl;
	}

	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs(FILENAME, ios::out|ios::app);	//用输出的方式打开
	//写入数据
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}