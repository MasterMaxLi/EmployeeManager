#pragma once
#include<iostream>

#include"worker.h"

using namespace std;

class Employee :public Worker
{
public:
	//¹¹Ôìº¯Êý
	Employee(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDeptName();
};
