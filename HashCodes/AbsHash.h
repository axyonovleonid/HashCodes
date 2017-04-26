#pragma once
#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>
using namespace std;

class AbsHash
{
protected:
	map<long long, list<string>> table;
	long long divisor;
	virtual long long hashLetter(string) = 0;
public:
	AbsHash();
	void insert(string);
	bool search(string);
	void show();
	~AbsHash();
};
