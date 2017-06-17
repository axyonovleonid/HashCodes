#pragma once
#include "AbsHash.h"
#include <fstream>
class VowConsHash
{
private:
	map<unsigned, map<unsigned, list<string>>> table;
	//ключу соответствует список инцидентности (список слов с одинаковыми значениями ключа)
	unsigned hashLetter(string); //метод для получения хеш-ключа
	unsigned divisor = 13; //размер таблицы. Очень мало слов имеют больше 13 согласных.
	//А если такие слова и есть, то они встречаются очень редко и их можно поместить к другим словам.
public:
	VowConsHash();
	void insert(string); //метод для вставки слова в хеш
	bool search(string); //метод для поиска слова в хеше
	void show(); //метод для печати хеша в файл
	int findAnagramms(string); //метод для поиска кол-ва анаграмм
	~VowConsHash();
};
