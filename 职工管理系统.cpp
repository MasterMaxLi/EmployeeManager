#include<iostream>

#include"workerManager.h"
#include"employee.h"

using namespace std;

int main()
{
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