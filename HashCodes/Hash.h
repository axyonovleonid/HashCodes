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
	long long hashLetter(string); //метод для получения хеш-ключа
public:
	Hash();
	~Hash();
};
