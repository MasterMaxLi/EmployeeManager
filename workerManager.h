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

	//��������
	~WorkerManager();
};