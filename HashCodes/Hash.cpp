#include "Hash.h"

Hash::Hash()
{
	className = "LetterHash";
	divisor = 37; //����� ���� 33 �����. �� ��� ����� �� 30 ����� ���������� �����. ������� ������� �� 37 �������
	//��� 7 ������� ����� �������������� ��� ����, ������������ �� � ����
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, list<string>> p;
		p.first = i;
		list<string> *tmp = new list<string>; //��������� ������� ������� ��������, � ������� ����� ����� �������� �����
		p.second = *tmp;
		table.insert(p);
	}
}

long long Hash::hashLetter(string str) {
	return (abs(str[0]) % divisor); //���� ������ ����� �� ������ 37. ��� �������� ���� ��� ������ �����
}
Hash::~Hash()
{
}