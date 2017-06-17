#include "AbsHash.h"

AbsHash::AbsHash()
{
//	for (unsigned i = 0; i < divisor; i++) {
//		pair<unsigned, list<string>> p;
//		p.first = i;
//		list<string> *tmp = new list<string>;
//		p.second = *tmp;
//		table.insert(p);
//	}
}

void AbsHash::insert(string str) {
	unsigned tmp = hashLetter(str);
	//���� �� ���������� ������ ���� � ����� �� ������, �� ������� �������� ������ ������ 
	if (table.find(tmp) == table.end()) {
		pair<unsigned, list<string>> p;
		p.first = tmp;
		list<string> *tmpL = new list<string>;
		p.second = *tmpL;
		//� �������� � ���� ������ �����
		//������ ������� �� ��� "�����, ������ ��������"
		table.insert(p);
	}
	else table.at(tmp).push_back(str);
	//���� ������ ��� ����������, �� ������ ��������� � ���� �����
}
bool AbsHash::search(string str) {
	list<string> tmp = table.at(hashLetter(str)); //��������� ������ ���� � ����� �� ������, ��� � �������� �����
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		if (*i == str) return true; //���������� ������, ���� �� �������� �� �����
	}
	return false;
}
void AbsHash::show() {
	ofstream f(className + "Output.txt"); //��������� ���� ��� ������
	for (auto i = table.begin(); i != table.end(); i++) {
		if (i->second.size() > 0) {
			f << i->first << " :\t"; //��������
			for (auto t = i->second.begin(); t != i->second.end() && !i->second.empty(); t++) {
				f << *t << " ";
			}
			f << endl;
		}
	}
	f.close();
}
int AbsHash::findAnagramms(string str)
{	
	int count = 0; //���-�� ��������
	string tmp = str; 
	sort(tmp.begin(), tmp.end()); //��������� ����� � �����,�������� ������ ���� "����". ������ ��������� ����� �����,
	//������ ������� ��� ����� � ������ ������ � ����� �� �������������
	for (auto i = table.begin(); i != table.end(); i++) { //���������� ���-�������
		for (auto s = i->second.begin(); s != i->second.end(); s++) {
			string tmp2 = *s; //����� ����� �� �������
			if (tmp2.length() == tmp.length()) { //���� ����� �� ����� �����, ��� ������ � ���� ��������
				sort(tmp2.begin(), tmp2.end()); // ������������ ����� � ���� ���������� ������������������ ���� "����"(��������)
				if (tmp == tmp2) count++; //���� ��� ���������, ����������� �������
			}
		}
	}
	return count;
}
AbsHash::~AbsHash()
{
}