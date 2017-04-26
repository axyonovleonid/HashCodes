#pragma once
#include "AbsHash.h"
class AutorityHash :
	public AbsHash
{
private:
	long long hashLetter(string str);
	unsigned hashDiv[15];
public:
	AutorityHash();
	~AutorityHash();
};
