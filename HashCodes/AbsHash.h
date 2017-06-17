#pragma once
#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class AbsHash
{
protected:
	map<long long, list<string>> table; //значения будут храниться в контейнере map с ключами - значениями хеш функции.
	//Для работы с коллизиями ключу будут соответствовать списки слов с одинаковым значением.
	long long divisor;
	virtual long long hashLetter(string) = 0; //виртуальная функция для получения хеш-ключа от слова. 
	//Эта функция переопределяется в классах-наследниках
	
	string className; //имя класса для записи в файл
public:
	AbsHash();
	void insert(string); //метод для вставки слова в хеш
	bool search(string); //метод для поиска слова в хеше
	void show(); //метод для печати хеша в файл
	int findAnagramms(string); //метод для поиска количества анаграмм
	~AbsHash();
};
