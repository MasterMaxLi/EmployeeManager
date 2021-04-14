#include<iostream>

#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

WorkerManager::WorkerManager()
{
	//��ʼ������
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager()
{
	//�ͷſ����ڶ���������
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::show_Menu()
{
	cout << "******************************************" << endl;
	cout << "***********��ӭʹ��ְ������ϵͳ***********" << endl;
	cout << "**************0.�˳��������**************" << endl;
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

//���ְ����ʵ��
void WorkerManager::addEmp()
{
	cout << "������Ҫ��ӵ�ְ��������" << endl;
	//����7�û�����������
	int addEmpNum = 0;
	cin >> addEmpNum;
	if (addEmpNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addEmpNum;	//�¿ռ�Ĵ�С=ԭ�ռ��С+��ӵ�����
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ�ռ�����ݿ������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addEmpNum; i++)
		{
			int id;	//���
			string name;	//����
			int dSelect;	//����ѡ��

			cout << "�������" << i + 1 << "λԱ���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "λԱ����������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "λԱ���ĸ�λ��" << endl;
			cout << "��ѡ���Ա���ĸ�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//��������
		this->m_EmpNum = newSize;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addEmpNum << "��Ա��" << endl;
		//���浽�ļ�
		this->save();
	}
	else
	{
		//���������
		cout << "������������" << endl;
	}

	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs(FILENAME, ios::out|ios::app);	//������ķ�ʽ��
	//д������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}