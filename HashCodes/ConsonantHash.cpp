#include "stdafx.h"
#include "ConsonantHash.h"

ConsonantHash::ConsonantHash()
{
	divisor = 17;
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, list<string>> p;
		p.first = i;
		list<string> *tmp = new list<string>;
		p.second = *tmp;
		table.insert(p);
	}
}

long long ConsonantHash::hashLetter(string str) {
	long long count = 0;
	string abc = "יצךםדרשחץתפגןנכהזקסלעüב"; //סמדכאסםûו
	long long len = str.size();
	for (int i = 0; i != len; i++) {
		//		str[i] = tolower(str[i]);
		for (int j = 0; j < 24; j++)
			if (str[i] == abc[j]) {
				count++; break;
			}
	}

	return count%divisor;
}

ConsonantHash::~ConsonantHash()
{
}