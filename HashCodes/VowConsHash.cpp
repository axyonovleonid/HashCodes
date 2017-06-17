#include "VowConsHash.h"

unsigned VowConsHash::hashLetter(string str)
{
	divisor = 13;
	unsigned count = 0; //������� �������
	string abc = "���������"; //�������
	unsigned len = str.size(); //������ ����� ������, ��� ��� ����������
	for (int i = 0; i != len; i++) {
		for (int j = 0; j < 10; j++)
			if (str[i] == abc[j]) {
				count++; //���� ��������� �������, ����������� �������
				break;
			}
	}

	return count%this->divisor; //���������� ������� �� ������ ������� �������
}
void VowConsHash::show() {
	ofstream f("VowConsOutput.txt"); //��������� ���� ��� ������
	for (auto i = table.begin(); i != table.end(); i++) {
		f << i->first << "vowels :\t"; //������� ���������� �������
		for (auto t = i->second.begin(); t != i->second.end(); t++) {
			if (!t->second.empty()) {
				f << "\t" << t->first << "consonants :\t"; //������� ���-�� ���������
				for (auto a = t->second.begin(); a != t->second.end(); a++) {
					f << *a << " "; //������ ����� � ����
				}
				f << endl;
			}
		}
		f << endl;
	}
	f.close();//��������� ����
}
VowConsHash::VowConsHash()
{
	divisor = 13;
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, map<unsigned, list<string>>> p; //������� ���� ����-�������� ��� ���-�������
		p.first = i; //�������� � ���� ���-�� �������
		map<unsigned, list<string>> *tmp = new map<unsigned, list<string>>;
		p.second = *tmp; //�������� � ���� ������ ����������
		for (unsigned j = 0; j < divisor; j++) {
			pair<unsigned, list<string>> q; //������� ���� ����-������ �������� ��� ����������
			q.first = j; //�������� � ���������� ���-�� ���������
			list<string> *tmp2 = new list<string>;
			q.second = *tmp2; //�������� � ���������� ������ ������ ��������
			p.second.insert(q);
		}
		table.insert(p); //�������� ���� ����-�������� � �������� �������
	}
}

void VowConsHash::insert(string str)
{
	unsigned tmp = hashLetter(str) % divisor; //������� ���-�� �������
	unsigned tmp2 = (str.length() - tmp) % 13;
	table.at(tmp).at(tmp2).push_back(str); //��������� � ������� ����� � ���-��� �������, ���������� ����,
														 //� ���-��� ���������, ������ ����� ����� ����� ���-�� �������
}

bool VowConsHash::search(string str)
{
	unsigned w = hashLetter(str); //�������� ���� ��� �����
	list<string> tmp = table.at(w).at((str.length() - w) % 13); //���������� � ������, � ������� ������ ���������� �����
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		if (*i == str) return true; //���������� ������, ���� �� ����� �����
	}
	return false;
}

int VowConsHash::findAnagramms(string str) {
	int count = 0; //���-�� ��������
	unsigned w = hashLetter(str); //������� ��� ��� �����
	string tmp = str;
	sort(tmp.begin(), tmp.end()); // ������������ ����� � ���� ��� ����, ���������� � ���������� �������
	list<string> tmpList = table.at(w).at((str.length() - w) % 13); //���������� � ������, � ������� ������ ���������� ����� � ����� �� ���-��� ������� � ���������
	for (auto i = tmpList.begin(); i != tmpList.end(); i++) {
		string tmp2 = *i;
		sort(tmp2.begin(), tmp2.end()); // ������������ ����� � ���� ��� ����, ���������� � ���������� �������
		if (tmp == tmp2) count++; //���� ��� ���������, ����������� �������
	}
	return count;
}

VowConsHash::~VowConsHash()
{
}