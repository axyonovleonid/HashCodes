// HashCodes.cpp: определяет точку входа для консольного приложения.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Hash.h"
#include <ctime>
#include <vector>
#include "VowelHash.h"
#include "ConsonantHash.h"
#include "VowConsHash.h"
#include "AutorityHash.h"
#include <locale>
#include <Windows.h>

#define DICTIONARY_SIZE 14000

using namespace std;
void quickSortR(string *, long); //функция для быстрой сортировки
void sortAndPrint(string* words, long N); //функция для сортировки словаря и его вывода в файл
int search(string* words, string word, long N); //функция для поиска слова в словаре
int findAnagramms(string* words, string word, long N); //функция для поиска анаграмм
bool operator > (string &str1, string &str2); //перегруженные операторы сравнения для строк
bool operator == (string & str1, string & str2); //перегруженные операторы сравнения для строк
bool operator < (string & str1, string & str2); //перегруженные операторы сравнения для строк

int compare(string s1, string s2);

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	system("color F0"); //F - белый цвет консоли, 0 - черный цвет текста
	setlocale(0, "");//поддержка русского языка
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода, поддержка русского языка
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода, поддержка русского языка
	ifstream f("input.txt"); //открытие файла для чтения слов
	ofstream f2("arrayTime.txt");
	ofstream f3("letterTime.txt");
	ofstream f4("vowelconsTime.txt");
	ofstream f5("polyTime.txt");

	map<int, int> arrTimes;
	map<int, int> letterTimes;
	map<int, int> vowelTimes;
	map<int, int> polyTimes;

	string words[DICTIONARY_SIZE]; //массив со словами
	Hash h;
	VowConsHash h4;
	AutorityHash h5;
	if (!f.is_open())
		return -1;
	for (int i = 0; i < DICTIONARY_SIZE; ) { //считывание слов из файла и их помещение в массив и хеши
		string tmp;
		f >> tmp;
		if (f.eof()) {
			cout << "End of file";
			return -1;
		}
		if (tmp.size() > 0) {
			words[i] = tmp;//добавляе слово в массив
			h.insert(words[i]);//добавляе слово в хеш
			h4.insert(words[i]);//добавляе слово в хеш
			h5.insert(words[i]);//добавляе слово в хеш
			i++;
		}
	}
	string searchWord;
	//	cout << "Input the word:" << endl;
	//	std::cin >> searchWord;
	sortAndPrint(words, DICTIONARY_SIZE);
	for (int i = 0; i < 500; i++) {
		searchWord = words[i];
		//		cout << "Looking for the " << searchWord << endl;
		//		h.show(); //запись хеша в файл в удобочитаемом виде
		//		h4.show(); //запись хеша в файл в удобочитаемом виде
		//		h5.show(); //запись хеша в файл в удобочитаемом виде

		clock_t start = clock(); //замер времени выполнения поиска в словаре
		clock_t time;
		//		cout << "Index in array: " << search(words, searchWord, DICTIONARY_SIZE) << endl;
		findAnagramms(words, searchWord, DICTIONARY_SIZE);//ищем анаграммы
		time = clock() - start; //считаем время выполнения как кол-во времени прошедшее между текущим моментом и моментом запуска таймера
		arrTimes[time]++; //увеличиваем количество слов, у которых время выполнения = time
		//		cout << "Time array = " << clock() - start << endl;

		start = clock();//запускаем таймер
		h.findAnagramms(searchWord);//ищем анаграммы
		//		cout << "Anagramms count: " << h.findAnagramms(searchWord) << endl;
		time = clock() - start;//считаем время выполнения как кол-во времени прошедшее между текущим моментом и моментом запуска таймера
		letterTimes[time]++;//увеличиваем количество слов, у которых время выполнения = time
		//		cout << "Time letterHash = " << clock() - start << endl; //замер времени выполнения поиска в хеше

		start = clock();//запускаем таймер
		h4.findAnagramms(searchWord);//ищем анаграммы
		//		cout << "Anagramms count: " << h4.findAnagramms(searchWord) << endl;
		time = clock() - start;//считаем время выполнения как кол-во времени прошедшее между текущим моментом и моментом запуска таймера
		vowelTimes[time]++;//увеличиваем количество слов, у которых время выполнения = time
		//		cout << "Time vowel-consonantHash = " << clock() - start << endl; //замер времени выполнения поиска в хеше

		start = clock();//запускаем таймер
		h5.findAnagramms(searchWord); //ищем анаграммы
		time = clock() - start; //считаем время выполнения как кол-во времени прошедшее между текущим моментом и моментом запуска таймера
		polyTimes[time]++;//увеличиваем количество слов, у которых время выполнения = time
		//		cout << "Time polyHash = " << clock() - start << endl; //замер времени выполнения поиска в хеше
		cout << i << endl;
	}

	for (auto i = arrTimes.begin(); i != arrTimes.end(); i++) {
		f2 << i->first << " " << i->second << endl; //записываем в файл время поиска
	}
	for (auto i = letterTimes.begin(); i != letterTimes.end(); i++) {
		f3 << i->first << " " << i->second << endl;//записываем в файл время поиска
	}
	for (auto i = vowelTimes.begin(); i != vowelTimes.end(); i++) {
		f4 << i->first << " " << i->second << endl;//записываем в файл время поиска
	}
	for (auto i = polyTimes.begin(); i != polyTimes.end(); i++) {
		f5 << i->first << " " << i->second << endl;//записываем в файл время поиска
	}
	f2.close(); //закрываем файл
	f3.close();//закрываем файл
	f4.close();//закрываем файл
	f5.close();//закрываем файл
	system("pause");
	return 0;
}

void sortAndPrint(string* words, long N) {
	quickSortR(words, N); //запуск алгоритма быстрой сортировки
	ofstream out("output.txt");
	for (int i = 0; i < N; i++)
		out << words[i] << endl; //запись отсортированного массива в файл
}

void quickSortR(string* words, long N) {
	long i = 0, j = N - 1;
	string temp, p;

	/*
	Выбрать из массива элемент, называемый опорным. Это может быть любой из элементов массива.
	От выбора опорного элемента не зависит корректность алгоритма, но в отдельных случаях может сильно зависеть его эффективность.
	Сравнить все остальные элементы с опорным и переставить их в массиве так,
	чтобы разбить массив на три непрерывных отрезка, следующие друг за другом:
	«меньшие опорного», «равные» и «большие».
	Для отрезков «меньших» и «больших» значений выполнить рекурсивно ту же последовательность операций,
	если длина отрезка больше единицы.
	*/

	p = words[N >> 1];

	do {
		while (words[i] < p) i++;
		while (words[j] > p) j--;

		if (i <= j) {
			temp = words[i]; words[i] = words[j]; words[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (j > 0) quickSortR(words, j);
	if (N > i) quickSortR(words + i, N - i);
}

int findAnagramms(string* words, string word, long N) {
	int count = 0;
	string tmp = word;
	sort(tmp.begin(), tmp.end()); //представляем слово в виде алфавитной последовательности его букв
	for (int i = 0; i < N; i++) {//перебираем массив
		string tmp2 = words[i];
		sort(tmp2.begin(), tmp2.end()); //представляем слово в виде алфавитной последовательности его букв
		if (tmp == tmp2) count++; //если слова в таком виде идентичны, увеличиваем счётчик
	}
	return count;
}

int search(string* words, string word, long N) {
	for (int i = 0; i < N; i++)
		if (word == words[i]) return i; //перебираем массив, пока не натолкнёмся на нужное слово
	return -1;
}

int compare(string str1, string str2) {
	for (int i = 0; i < max(str1.length(), str2.length()); i++) {
		if (i > str2.length()) return -1;
		if (i > str1.length()) return 1;
		if (str1[i] != str2[i]) {
			if (str1[i] > str2[i]) return 1;
			else return -1;
		}
	}
	return 0;
}

bool operator>(string & str1, string & str2)
{
	return (compare(str1, str2) == 1); //для сравнения строк вызываем стандартную функцию compare()
}
bool operator<(string & str1, string & str2)
{
	return (compare(str1, str2) == -1); //для сравнения строк вызываем стандартную функцию compare()
}
bool operator == (string & str1, string & str2)
{
	return (compare(str1, str2) == 0); //для сравнения строк вызываем стандартную функцию compare()
}