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
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
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
		//保存到文件
		this->save();
		//提示添加成功
		cout << "成功添加" << addEmpNum << "名员工" << endl;
		//文件不为空
		this->m_FileIsEmpty = false;
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

//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空!\n";
	}
	else
	{
		cout << "请输入要修改的员工id：" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			//找到该员工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string name = "";
			int dSelect = 0;
			cout << "查找到id为" << id << "的员工，请输入新的id：\n";
			cin >> newId;
			cout << "请输入新的姓名：\n";
			cin >> name;
			cout << "请输入新的岗位：\n";
			cout << "1.普通员工\n" << "2.经理\n" << "3.老板\n";
			cin >> dSelect;

			Worker* worker = NULL;
			switch(dSelect)
			{
			case 1:
				worker = new Employee(newId, name, dSelect);
				break;
			case 2:
				worker = new Manager(newId, name, dSelect);
				break;
			case 3:
				worker = new Boss(newId, name, dSelect);
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "更新成功！\n";
			this->save();
		}
		else
		{
			cout << "查无此人，请检查id是否输入正确！\n";
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！\n";
	}
	else
	{
		cout << "请输入查找方式：\n";
		cout << "1.按id查找\n";
		cout << "2.按姓名查找\n";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入要查找的id：\n";
			int id = 0;
			cin >> id;
			int ret = this->IsExit(id);
			if (ret != -1)
			{
				cout << "该员工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "输入的id有错误，请检查后重新输入！\n";
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的姓名：\n";
			string name = "";
			cin >> name;
			bool b = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找到该员工的信息如下：\n";
					b = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (!b)
			{
				cout << "未查找到名字为" << name << "的员工，请检查信息后重新输入！\n";
			}
		}
		else
		{
			cout << "输入的查找方式错误！请重新输入：\n";
			system("pause");
			system("cls");
			this->Find_Emp();
		}
	}
	system("pause");
	system("cls");
}

//按升序排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存咋或为空！\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式：\n";
		cout << "1.id升序\n";
		cout << "2.id降序\n";
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)	//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					//降序
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功！排序后结果为：\n";
		this->save();
		this->show_Emp();
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空？\n";
	cout << "1.确认\n";
	cout << "2.返回\n";
	
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);	//删除文件后重建
		ofs.close();

		for (int i = 0; i < m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}
		//删除堆区数据指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		cout << "清空成功！\n";
	}
	system("pause");
	system("cls");
}