#include "stdafx.h"
#include "VowConsHash.h"

unsigned VowConsHash::hashLetter(string str)
{
	unsigned count = 0;
	string abc = "àå¸èîóûışÿ";
	unsigned len = str.size();
	for (int i = 0; i != len; i++) {
		//		str[i] = tolower(str[i]);
		for (int j = 0; j < 10; j++)
			if (str[i] == abc[j]) {
				count++; break;
			}
	}

	return count%divisor;
}

VowConsHash::VowConsHash()
{
	divisor = 29;
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