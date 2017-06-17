#pragma once
#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class AbsHash
{
protected:
	map<long long, list<string>> table; //�������� ����� ��������� � ���������� map � ������� - ���������� ��� �������.
	//��� ������ � ���������� ����� ����� ��������������� ������ ���� � ���������� ���������.
	long long divisor;
	virtual long long hashLetter(string) = 0; //����������� ������� ��� ��������� ���-����� �� �����. 
	//��� ������� ���������������� � �������-�����������
	
	string className; //��� ������ ��� ������ � ����
public:
	AbsHash();
	void insert(string); //����� ��� ������� ����� � ���
	bool search(string); //����� ��� ������ ����� � ����
	void show(); //����� ��� ������ ���� � ����
	int findAnagramms(string); //����� ��� ������ ���������� ��������
	~AbsHash();
};
