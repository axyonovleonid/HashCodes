#pragma once
#include "AbsHash.h"
class VowelHash :
	public AbsHash
{
protected:
public:
	VowelHash();
	long long hashLetter(string str);
	~VowelHash();
};
