// HashCodes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Hash.h"
#include <ctime>
#include "VowelHash.h"
#include "ConsonantHash.h"
#include "VowConsHash.h"
#include "AutorityHash.h"
//#include <ofstream>

#define DICTIONARY_SIZE 3000

using namespace std;
void quickSortR(string *, long);
void sortAndPrint(string* words, long N);
int search(string* words, string word, long N);
bool operator > (string &str1, string &str2);
bool operator == (string & str1, string & str2);
bool operator < (string & str1, string & str2);

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	ifstream f("input.txt");

	string words[DICTIONARY_SIZE];
	Hash h;
	VowelHash h2;
	ConsonantHash h3;
	VowConsHash h4;
	AutorityHash h5;

	for (int i = 0; i < DICTIONARY_SIZE; ) {
		string tmp;
		f >> tmp;
		if (tmp.size() > 5) {
			words[i] = tmp;
			h.insert(words[i]);
			h2.insert(words[i]);
			h3.insert(words[i]);
			h4.insert(words[i]);
			h5.insert(words[i]);
			i++;
		}
	}
	string searchWord = words[rand() % DICTIONARY_SIZE];
	//	string searchWord = "конхоида";
	sortAndPrint(words, DICTIONARY_SIZE);
	cout << endl << searchWord << endl;
	clock_t start = clock();
	cout << "Index in array: " << search(words, searchWord, DICTIONARY_SIZE) << endl;
	cout << "Time array = " << clock() - start << endl;
	start = clock();
	h.search(searchWord);
	cout << "Time letterHash = " << clock() - start << endl;

	start = clock();
	h2.search(searchWord);
	cout << "Time vowelHash = " << clock() - start << endl;

	start = clock();
	h3.search(searchWord);
	cout << "Time consonantHash = " << clock() - start << endl;

	start = clock();
	h4.search(searchWord);
	cout << "Time vowel-consonantHash = " << clock() - start << endl;

	start = clock();
	h5.search(searchWord);
	cout << "Time polyHash = " << clock() - start << endl;

	system("pause");
	return 0;
}

void sortAndPrint(string* words, long N) {
	quickSortR(words, N);
	ofstream out("output.txt");
	for (int i = 0; i < N; i++)
		out << words[i] << endl;
}

void quickSortR(string* words, long N) {
	long i = 0, j = N - 1;
	string temp, p;

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

int search(string* words, string word, long N) {
	for (int i = 0; i < N; i++)
		if (word == words[i]) return i;
	return -1;
}

bool operator>(string & str1, string & str2)
{
	return (str1.compare(str2) == 1);
}
bool operator<(string & str1, string & str2)
{
	return (str1.compare(str2) == -1);
}
bool operator == (string & str1, string & str2)
{
	return (str1.compare(str2) == 0);
}