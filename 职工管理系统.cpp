#include<iostream>

#include"workerManager.h"
//#include"worker.h"
//#include"employee.h"
//#include"manager.h"
//#include"boss.h"

using namespace std;

int main()
{

	//���Դ���
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 3);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 2);
	worker->showInfo();
	delete worker;*/
	//ʵ���������߶���
	WorkerManager wm;

	//Employee e(1, "����", 1);
	//e.showInfo();

	//ѡ��
	int choice = 0;

	while (true)
	{
		wm.show_Menu();
		cout << "���������Ĳ�����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_System();	//�˳�����
			break;
		case 1:
			wm.addEmp();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}