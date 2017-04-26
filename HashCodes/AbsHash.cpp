#include "stdafx.h"
#include "AbsHash.h"

AbsHash::AbsHash()
{
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, list<string>> p;
		p.first = i;
		list<string> *tmp = new list<string>;
		p.second = *tmp;
		table.insert(p);
	}
}

void AbsHash::insert(string str) {
	unsigned tmp = hashLetter(str);
	table.at(tmp).push_back(str);
}
bool AbsHash::search(string str) {
	list<string> tmp = table.at(hashLetter(str));
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		if (*i == str) return true;
	}
	return false;
}
void AbsHash::show() {
	for (auto i = table.begin(); i != table.end(); i++) {
		cout << i->first << " :\t";
		for (auto t = i->second.begin(); t != i->second.end(); t++) {
			cout << *t << " ";
		}
		cout << endl;
	}
}
AbsHash::~AbsHash()
{
}