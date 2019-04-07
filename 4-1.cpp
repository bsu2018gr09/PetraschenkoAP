//В каждой строке удалить слова, в которых буквы упорядочены в алфавитном порядке и которые начинаются на большую букву.
//Отсортировать строки по количеству удалённых слов.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>
#include <cstring>
using namespace std;

const int N = 200;
const int M = 7;

void giveMemoryChar(char *&str);
void giveMemoryInt(int *&Arr);

void clearMemoryChar(char *&str);
void clearMemoryInt(int *&Arr);

void deletewords(char *str, char*buff, char check[M]);
char* readingstring(char *&str, char *&buff);
void print(char *buff);

ifstream in("d:\\text.txt");
ofstream out("d:\\result.txt");


int main() {
	setlocale(LC_ALL, "Russian");

	if (!in) { cout << "No file d:\\text.txt. Can't open\n"; exit(1); }
	if (!out) { cout << "   file d:\\result.txt. Can't create\n"; exit(1); }

	char *buff = nullptr;
	char *str = nullptr;
	char check[M] = " ,.-;:";

	deletewords(str, buff, check);
	clearMemoryChar(str);
	clearMemoryChar(buff);

	cout << endl;

	system("pause");
	return 0;
}

void clearMemoryChar(char *&str) {
	delete[] str;
}

void clearMemoryInt(int *&Arr) {
	delete[] Arr;
}

void giveMemoryChar(char *&str) {
	str = new(nothrow) char[N];
	if (!str) {
		cout << "error" << "\n";
	}
}

void giveMemoryInt(int *&Arr) {
	Arr = new(nothrow) int[N];
	if (!Arr) {
		cout << "error" << "\n";
	}
}

char* readingstring(char *&str, char *&buff) {
	giveMemoryChar(buff);
	in.getline(buff, N - 1);
	str = buff;
	return str;
}

void deletewords(char *str, char *buff, char check[M]) {
	char *tmp = nullptr;
	int begin, end, i = 0;

	giveMemoryInt(CountDeleteWords);
	giveMemoryChar(tmp);

	while (1) {

		
		readingstring(str, buff);

		if (in.fail()) in.clear();

		while (*str) {
			begin = strspn(str, check);
			str += begin;
			end = strcspn(str, check);
			tmp = str;

			if (*str >= -67 && *str <= -33 && *(str + 1) > *(str)+32) { //+32 потому что разница по АСКИ, между заглавной и той же маленькой 32.
				str += 1;
				while (i < end - 2) {
					if (*(str + 1) > *(str)) {
						++i;
						str += 1;
					}
					else { str = tmp + end; break; }
				}
				if (i == end - 2) {
					strcpy(tmp, tmp + end);
				}
				i = 0;
			}
			else str = tmp + end;
		}
		print(buff);
		if (in.eof()) break;
	}
	in.close();
	out.close();
	clearMemoryChar(tmp);
	clearMemoryInt(CountDeleteWords);
}

void print(char *buff) {
	cout << buff << endl;
	out << buff << endl;
}
