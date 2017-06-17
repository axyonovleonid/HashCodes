#pragma once
#include "AbsHash.h"
#include <fstream>
class VowConsHash
{
private:
	map<unsigned, map<unsigned, list<string>>> table;
	//����� ������������� ������ ������������� (������ ���� � ����������� ���������� �����)
	unsigned hashLetter(string); //����� ��� ��������� ���-�����
	unsigned divisor = 13; //������ �������. ����� ���� ���� ����� ������ 13 ���������.
	//� ���� ����� ����� � ����, �� ��� ����������� ����� ����� � �� ����� ��������� � ������ ������.
public:
	VowConsHash();
	void insert(string); //����� ��� ������� ����� � ���
	bool search(string); //����� ��� ������ ����� � ����
	void show(); //����� ��� ������ ���� � ����
	int findAnagramms(string); //����� ��� ������ ���-�� ��������
	~VowConsHash();
};
