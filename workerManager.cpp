#include<iostream>

#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

WorkerManager::WorkerManager()
{
	ifstream ifs(FILENAME, ios::in);	//���ļ�
	//�ļ���ʼ��
	//1.�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ��ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ��ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����ݲ�Ϊ��
	int num = this->getEmpNum();
	//cout << "ְ��������" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��
	this->init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "��ţ�" << this->m_EmpArray[i]->m_Id << "\t"
			<< "������" << this->m_EmpArray[i]->m_Name << "\t"
			<< "��λ��" << this->m_EmpArray[i]->getDeptName() << endl;
	}*/
	 
	//��ʼ������
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
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
		//���浽�ļ�
		this->save();
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addEmpNum << "��Ա��" << endl;
		//�ļ���Ϊ��
		this->m_FileIsEmpty = false;
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
		if (dId == 1)	//��ְͨ��
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");	//����
}

//ɾ��Ա��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��!\n";
	}
	else
	{
		cout << "������Ҫɾ����Ա��id��" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)
		{
			//ְ������
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ���\n";
			
		}
		else
		{
			//Ա��������
			cout << "δ�ҵ���Ա��������id�Ƿ�������ȷ��\n";
		}
	}
	system("pause");
	system("cls");
}

//�ж�Ա���Ƿ����
int WorkerManager::IsExit(int id)
{
	//Ĭ�ϲ�����Ϊ-1
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

//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��!\n";
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա��id��" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			//�ҵ���Ա��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string name = "";
			int dSelect = 0;
			cout << "���ҵ�idΪ" << id << "��Ա�����������µ�id��\n";
			cin >> newId;
			cout << "�������µ�������\n";
			cin >> name;
			cout << "�������µĸ�λ��\n";
			cout << "1.��ͨԱ��\n" << "2.����\n" << "3.�ϰ�\n";
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
			cout << "���³ɹ���\n";
			this->save();
		}
		else
		{
			cout << "���޴��ˣ�����id�Ƿ�������ȷ��\n";
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�\n";
	}
	else
	{
		cout << "��������ҷ�ʽ��\n";
		cout << "1.��id����\n";
		cout << "2.����������\n";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ���ҵ�id��\n";
			int id = 0;
			cin >> id;
			int ret = this->IsExit(id);
			if (ret != -1)
			{
				cout << "��Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "�����id�д���������������룡\n";
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ���ҵ�������\n";
			string name = "";
			cin >> name;
			bool b = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҵ���Ա������Ϣ���£�\n";
					b = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (!b)
			{
				cout << "δ���ҵ�����Ϊ" << name << "��Ա����������Ϣ���������룡\n";
			}
		}
		else
		{
			cout << "����Ĳ��ҷ�ʽ�������������룺\n";
			system("pause");
			system("cls");
			this->Find_Emp();
		}
	}
	system("pause");
	system("cls");
}

//����������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�����զ��Ϊ�գ�\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ��\n";
		cout << "1.id����\n";
		cout << "2.id����\n";
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)	//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					//����
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
		cout << "����ɹ����������Ϊ��\n";
		this->save();
		this->show_Emp();
	}
}