#include<iostream>

#include"workerManager.h"
//#include"worker.h"
//#include"employee.h"
//#include"manager.h"
//#include"boss.h"

using namespace std;

int main()
{

	//测试代码
	/*Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李明", 3);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 2);
	worker->showInfo();
	delete worker;*/

	//Employee e(1, "张三", 1);
	//e.showInfo();

	//实例化管理者对象
	WorkerManager wm;

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
			wm.addEmp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:	
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
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