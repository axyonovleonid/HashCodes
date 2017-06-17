#pragma once
#include "AbsHash.h"
class AutorityHash :
	public AbsHash
{
private:
	long long hashLetter(string str); //метод для получения хеш-ключа
	unsigned hashDiv[16]; //массив с заранее подсчитанными коэффициентами полиномов.
public:
	AutorityHash();
	~AutorityHash();
};
