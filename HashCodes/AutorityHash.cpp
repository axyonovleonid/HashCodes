#include "stdafx.h"
#include "AutorityHash.h"

AutorityHash::AutorityHash()
{
	divisor = 3;
	for (int i = 0; i < 15; i++) {
		hashDiv[i] = pow(divisor, i);
	}
	for (unsigned i = 0; i < 5000; i++) {
		pair<unsigned, list<string>> p;
		p.first = i;
		list<string> *tmp = new list<string>;
		p.second = *tmp;
		table.insert(p);
	}
}

long long AutorityHash::hashLetter(string str)
{
	long long polyhash = 0;
	for (int i = 0; i < str.length(); i++) {
		polyhash += (tolower(str[i]) + 33)*hashDiv[i];
	}
	return polyhash % 5000;
}

AutorityHash::~AutorityHash()
{
}