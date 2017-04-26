#include "stdafx.h"
#include "VowelHash.h"

VowelHash::VowelHash()
{
	divisor = 11;
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, list<string>> p;
		p.first = i;
		list<string> *tmp = new list<string>;
		p.second = *tmp;
		table.insert(p);
	}
}

long long VowelHash::hashLetter(string str) {
	long long count = 0;
	string abc = "àå¸èîóûýþÿ";
	long long len = str.size();
	for (int i = 0; i != len; i++) {
		//		str[i] = tolower(str[i]);
		for (int j = 0; j < 10; j++)
			if (str[i] == abc[j]) {
				count++; break;
			}
	}

	return count%divisor;
}

VowelHash::~VowelHash()
{
}