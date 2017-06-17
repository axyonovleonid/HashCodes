#include "VowConsHash.h"

unsigned VowConsHash::hashLetter(string str)
{
	divisor = 13;
	unsigned count = 0; //счЄтчик гласных
	string abc = "аеЄиоуыэю€"; //гласные
	unsigned len = str.size(); //возьмЄм длину строки, она ещЄ пригодитс€
	for (int i = 0; i != len; i++) {
		for (int j = 0; j < 10; j++)
			if (str[i] == abc[j]) {
				count++; //если встречаем гласную, увеличиваем счЄтчик
				break;
			}
	}

	return count%this->divisor; //возвращаем счЄтчик по модулю размера таблицы
}
void VowConsHash::show() {
	ofstream f("VowConsOutput.txt"); //открываем файл дл€ записи
	for (auto i = table.begin(); i != table.end(); i++) {
		f << i->first << "vowels :\t"; //выводим количество гласных
		for (auto t = i->second.begin(); t != i->second.end(); t++) {
			if (!t->second.empty()) {
				f << "\t" << t->first << "consonants :\t"; //выводим кол-во согласных
				for (auto a = t->second.begin(); a != t->second.end(); a++) {
					f << *a << " "; //выводи слова в файл
				}
				f << endl;
			}
		}
		f << endl;
	}
	f.close();//закрываем файл
}
VowConsHash::VowConsHash()
{
	divisor = 13;
	for (unsigned i = 0; i < divisor; i++) {
		pair<unsigned, map<unsigned, list<string>>> p; //создаем пары ключ-значение дл€ хеш-таблицы
		p.first = i; //помещаем в пару кол-во гласных
		map<unsigned, list<string>> *tmp = new map<unsigned, list<string>>;
		p.second = *tmp; //помещаем в пару пустую подтаблицу
		for (unsigned j = 0; j < divisor; j++) {
			pair<unsigned, list<string>> q; //создаем пару ключ-список значений дл€ подтаблицы
			q.first = j; //помещаем в подтаблицу кол-во согласных
			list<string> *tmp2 = new list<string>;
			q.second = *tmp2; //помещаем в подтаблицу пустой список значений
			p.second.insert(q);
		}
		table.insert(p); //помещаем пару ключ-значение в основную таблицу
	}
}

void VowConsHash::insert(string str)
{
	unsigned tmp = hashLetter(str) % divisor; //считаем кол-во гласных
	unsigned tmp2 = (str.length() - tmp) % 13;
	table.at(tmp).at(tmp2).push_back(str); //добавл€ем в таблицу слово с кол-вом гласных, полученным выше,
														 //и кол-вом согласных, равным длине слова минус кол-во гласных
}

bool VowConsHash::search(string str)
{
	unsigned w = hashLetter(str); //получаем ключ дл€ слова
	list<string> tmp = table.at(w).at((str.length() - w) % 13); //обращаемс€ к списку, в котором должно находитьс€ слово
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		if (*i == str) return true; //перебираем список, пока не найдЄм слово
	}
	return false;
}

int VowConsHash::findAnagramms(string str) {
	int count = 0; //кол-во анаграмм
	unsigned w = hashLetter(str); //считаем хеш дл€ слова
	string tmp = str;
	sort(tmp.begin(), tmp.end()); // представл€ем слово в виде его букв, записанных в алфавитном пор€дке
	list<string> tmpList = table.at(w).at((str.length() - w) % 13); //обращаемс€ к списку, в котором должны находитьс€ слова с таким же кол-вом гласных и согласных
	for (auto i = tmpList.begin(); i != tmpList.end(); i++) {
		string tmp2 = *i;
		sort(tmp2.begin(), tmp2.end()); // представл€ем слово в виде его букв, записанных в алфавитном пор€дке
		if (tmp == tmp2) count++; //если они идентичны, увеличиваем счЄтчик
	}
	return count;
}

VowConsHash::~VowConsHash()
{
}