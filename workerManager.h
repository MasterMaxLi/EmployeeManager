#pragma once	//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<fstream>

#include"worker.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exit_System();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void addEmp();

	//���浽�ļ���
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int getEmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void show_Emp();

	//ɾ��Ա��
	void Del_Emp();

	//�ж�Ա���Ƿ����
	int IsExit(int id);

	//��������
	~WorkerManager();
};