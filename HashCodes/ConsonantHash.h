#pragma once
#include "AbsHash.h"
class ConsonantHash :
	public AbsHash
{
public:
	ConsonantHash();
	long long hashLetter(string str);
	~ConsonantHash();
};
