#include"workerManager.h"

WorkerManager::WorkerManager()
{

}

WorkerManager::~WorkerManager()
{

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