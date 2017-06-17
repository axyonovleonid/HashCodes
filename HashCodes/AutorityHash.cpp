#include "AutorityHash.h"

AutorityHash::AutorityHash()
{
	className = "AutorityHash";
	divisor = 3; //удобно брать простые числа. ¬ нашем случае число может быть и небольшим.
	for (int i = 0; i < 16; i++) {
		hashDiv[i] = pow(divisor, i); //считаем всего 14 степеней числа. Ќе так уж и много слов, длина которых больше 14 символов
	}
	for (unsigned i = 0; i < 5000; i++) {
		pair<unsigned, list<string>> p; //ключу соответствует список инцидентности (список слов с одинаковыми значени€ми ключа)
		p.first = i;
		list<string> *tmp = new list<string>; //заранее заполн€ем хеш-таблицу пустыми значени€ми
		p.second = *tmp;
		table.insert(p);
	}
}

long long AutorityHash::hashLetter(string str) //метод дл€ получени€ хеш-ключа
{
	long long polyhash = 0;
	for (int i = 0; i < str.length(); i++) {
		polyhash += (tolower(str[i]) + 33)*hashDiv[i]; //считаем значение многочлена
	}
	return polyhash % 5000; //берЄм это значени по модулю 5000 и возвращаем
}

AutorityHash::~AutorityHash()
{
}