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
	cout << "***********��ӭʹ��ְ������ϵͳ***********" << endl;
	cout << "**************0.�˳���������**************" << endl;
	cout << "**************1.����ְ����Ϣ**************" << endl;
	cout << "**************2.��ʾְ����Ϣ**************" << endl;
	cout << "**************3.ɾ��ְ����Ϣ**************" << endl;
	cout << "**************4.�޸�ְ����Ϣ**************" << endl;
	cout << "**************5.����ְ����Ϣ**************" << endl;
	cout << "**************6.����ְ����Ϣ**************" << endl;
	cout << "**************7.���ְ����Ϣ**************" << endl;
	cout << "******************************************" << endl;
}

void WorkerManager::exit_System()
{
	cout << "���˳�����ӭ�´�ʹ��~\n";
	system("pause");
	exit(0);
}