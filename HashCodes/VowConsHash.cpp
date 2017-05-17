#include "VowConsHash.h"

unsigned VowConsHash::hashLetter(string str)
{
	unsigned count = 0;
	string abc = "аеЄиоуыэю€"; //гласные
	unsigned len = str.size();
	for (int i = 0; i != len; i++) {
		//		str[i] = tolower(str[i]);
		for (int j = 0; j < 10; j++)
			if (str[i] == abc[j]) {
				count++; 
				break;
			}
	}

	return count%this->divisor;
}
void VowConsHash::show() {
	string a(typeid(this).name());
	ofstream f("VowConsOutput.txt");
	for (auto i = table.begin(); i != table.end(); i++) {
		f << i->first << "vowels :\t";
		for (auto t = i->second.begin(); t != i->second.end(); t++) {
			if (!t->second.empty()) {
				f << "\t" << t->first << "consonants :\t";
				for (auto a = t->second.begin(); a != t->second.end(); a++) {
					f << *a << " ";
				}
				f << endl;
			}
		}
		f << endl;
	}
	f.close();
}
VowConsHash::VowConsHash()
{
	divisor = 13;
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, map<unsigned, list<string>>> p;
		p.first = i;
		map<unsigned, list<string>> *tmp = new map<unsigned, list<string>>;
		p.second = *tmp;
		for (unsigned j = 0; j < divisor; j++) {
			pair<unsigned, list<string>> q;
			q.first = j;
			list<string> *tmp2 = new list<string>;
			q.second = *tmp2;
			p.second.insert(q);
		}
		table.insert(p);
	}
}

void VowConsHash::insert(string str)
{
	unsigned tmp = hashLetter(str);
	table.at(tmp).at(str.length() - tmp).push_back(str);
}

bool VowConsHash::search(string str)
{
	unsigned w = hashLetter(str);
	list<string> tmp = table.at(w).at(str.length() - w);
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		if (*i == str) return true;
	}
	return false;
}

VowConsHash::~VowConsHash()
{
}