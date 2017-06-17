#include "AbsHash.h"

AbsHash::AbsHash()
{
//	for (unsigned i = 0; i < divisor; i++) {
//		pair<unsigned, list<string>> p;
//		p.first = i;
//		list<string> *tmp = new list<string>;
//		p.second = *tmp;
//		table.insert(p);
//	}
}

void AbsHash::insert(string str) {
	unsigned tmp = hashLetter(str);
	//если не существует списка слов с таким же ключом, то сначала создадим пустой список 
	if (table.find(tmp) == table.end()) {
		pair<unsigned, list<string>> p;
		p.first = tmp;
		list<string> *tmpL = new list<string>;
		p.second = *tmpL;
		//и поместим в этот список слово
		//список состоит из пар "число, список значений"
		table.insert(p);
	}
	else table.at(tmp).push_back(str);
	//если список уже существует, то просто добавляем в него слово
}
bool AbsHash::search(string str) {
	list<string> tmp = table.at(hashLetter(str)); //открываем список слов с таким же ключом, как у искомого слова
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		if (*i == str) return true; //перебираем список, пока не наткнёмся на слово
	}
	return false;
}
void AbsHash::show() {
	ofstream f(className + "Output.txt"); //открываем файл для записи
	for (auto i = table.begin(); i != table.end(); i++) {
		if (i->second.size() > 0) {
			f << i->first << " :\t"; //печатаем
			for (auto t = i->second.begin(); t != i->second.end() && !i->second.empty(); t++) {
				f << *t << " ";
			}
			f << endl;
		}
	}
	f.close();
}
int AbsHash::findAnagramms(string str)
{	
	int count = 0; //кол-во анаграмм
	string tmp = str; 
	sort(tmp.begin(), tmp.end()); //сортируем буквы в слове,получаем строку вида "аабб". Теперь анаграмму можно найти,
	//просто сравнив это слово с другим словом в таком же представлении
	for (auto i = table.begin(); i != table.end(); i++) { //перебираем хеш-таблицу
		for (auto s = i->second.begin(); s != i->second.end(); s++) {
			string tmp2 = *s; //берем слово из таблицы
			if (tmp2.length() == tmp.length()) { //если слова не одной длины, нет смысла с ними работать
				sort(tmp2.begin(), tmp2.end()); // представляем слово в виде алфавитной последовательности букв "аабб"(например)
				if (tmp == tmp2) count++; //если они идентичны, увеличиваем счётчик
			}
		}
	}
	return count;
}
AbsHash::~AbsHash()
{
}