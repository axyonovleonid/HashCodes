#pragma once
#include "AbsHash.h"
class VowConsHash
{
private:
	map<unsigned, map<unsigned, list<string>>> table;
	unsigned hashLetter(string);
	unsigned divisor;
public:
	VowConsHash();
	void insert(string);
	bool search(string);
	~VowConsHash();
};
