#include<iostream>

#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

WorkerManager::WorkerManager()
{
	ifstream ifs(FILENAME, ios::in);	//读文件
	//文件初始化
	//1.文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化人数
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		//初始化人数
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，数据不为空
	int num = this->getEmpNum();
	//cout << "职工人数：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化
	this->init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "编号：" << this->m_EmpArray[i]->m_Id << "\t"
			<< "姓名：" << this->m_EmpArray[i]->m_Name << "\t"
			<< "岗位：" << this->m_EmpArray[i]->getDeptName() << endl;
	}*/
	 
	//初始化属性
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
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
		//文件不为空
		this->m_FileIsEmpty = false;
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

int WorkerManager::getEmpNum()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)	//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

void WorkerManager::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");	//清屏
}

//删除员工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空!\n";
	}
	else
	{
		cout << "请输入要删除的员工id：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)
		{
			//职工存在
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！\n";
			
		}
		else
		{
			//员工不存在
			cout << "未找到该员工，请检查id是否输入正确！\n";
		}
	}
	system("pause");
	system("cls");
}

//判断员工是否存在
int WorkerManager::IsExit(int id)
{
	//默认不存在为-1
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}