#include "Hash.h"

Hash::Hash()
{
	className = "LetterHash";
	divisor = 37; //всего есть 33 буквы. Из них всего на 30 могут начинаться слова. Создаем таблицу на 37 списков
	//Эти 7 списков могут использоваться для слов, начинающихся не с букв
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, list<string>> p;
		p.first = i;
		list<string> *tmp = new list<string>; //заполняем таблицу пустыми списками, в которые потом будем помещать слова
		p.second = *tmp;
		table.insert(p);
	}
}

long long Hash::hashLetter(string str) {
	return (abs(str[0]) % divisor); //берём первую букву по модулю 37. Это значение хеша для нашего слова
}
Hash::~Hash()
{
}