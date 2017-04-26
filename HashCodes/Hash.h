#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>
#include "AbsHash.h"
using namespace std;

class Hash :
	public AbsHash
{
protected:
	long long hashLetter(string);
public:
	Hash();
	~Hash();
};
