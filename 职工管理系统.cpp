#include<iostream>

#include"workerManager.h"
#include"employee.h"

using namespace std;

int main()
{
	//实例化管理者对象
	WorkerManager wm;

	//Employee e(1, "张三", 1);
	//e.showInfo();

	//选项
	int choice = 0;

	while (true)
	{
		wm.show_Menu();
		cout << "请输入您的操作：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_System();	//退出程序
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