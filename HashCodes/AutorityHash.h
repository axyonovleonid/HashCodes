#pragma once
#include "AbsHash.h"
class AutorityHash :
	public AbsHash
{
private:
	long long hashLetter(string str); //����� ��� ��������� ���-�����
	unsigned hashDiv[16]; //������ � ������� ������������� �������������� ���������.
public:
	AutorityHash();
	~AutorityHash();
};
