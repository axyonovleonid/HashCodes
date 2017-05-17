#pragma once
#include "AbsHash.h"
#include <fstream>
class VowConsHash
{
private:
	map<unsigned, map<unsigned, list<string>>> table;
	unsigned hashLetter(string);
	unsigned divisor = 11;
public:
	VowConsHash();
	void show();
	void insert(string);
	bool search(string);
	~VowConsHash();
};
