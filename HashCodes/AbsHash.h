#pragma once
#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class AbsHash
{
protected:
	map<long long, list<string>> table; //значения будут храниться в контейнере map с ключами - значениями хеш функции.
	//Для работы с коллизиями ключу будут соответствовать списки слов с одинаковым значением.
	long long divisor;
	virtual long long hashLetter(string) = 0;
	string className;
public:
	AbsHash();
	void insert(string);
	bool search(string);
	void show();
	~AbsHash();
};
