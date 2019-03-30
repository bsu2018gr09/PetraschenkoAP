//В каждой строке удалить слова, в которых буквы упорядочены в алфавитном порядке и которые начинаются на большую букву.
//Отсортировать строки по количеству удалённых слов.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>
#include <cstring>
using namespace std;
void giveMemory(char *&str);
void clearmem(char *&A);
void deletewords(char *str, char*buff, char *check);
char* readingstring(char *&str, char *&buff);
void print(char *buff, char *str);

ifstream in("d:\\text.txt");
ofstream out("d:\\result.txt");

const int N = 200;

int main() {
	setlocale(LC_ALL, "Russian");

	if (!in) { cout << "No file d:\\text.txt. Can't open\n"; exit(1); }
	if (!out) { cout << "   file d:\\result.txt. Can't create\n"; exit(1); }

	char *buff = nullptr;
	char *str = nullptr;
	char *check = " ,.-;:";

	giveMemory(str);
	giveMemory(buff);
	deletewords(str, buff, check);
	clearmem(str);
	clearmem(buff);

	cout << endl;

	system("pause");
	return 0;
}

void clearmem(char *&A) {
	delete[] A;
}

void giveMemory(char *&str) {
	str = new(nothrow) char[N];
	if (!str) {
		cout << "error" << "\n";
	}
}

void deletewords(char *str, char*buff, char *check) {
	char *tmp;
	int begin, end, i = 0, k = 0;

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
				if (i == end - 2)
					strcpy(tmp, tmp + end);
				i = 0;
			}
			else str = tmp + end;
		}

		print(buff, str);
		if (in.eof()) break;

	}
	in.close();//закрыли файл
	out.close();//закрыли файл}
}

char* readingstring(char *&str, char *&buff) {
	in.getline(buff, N - 1);
	str = buff;
	return str;
}

void print(char *buff, char *str) {
	cout << buff << endl;
	out << buff << endl;
}

void sortdeletestrings(char *str, char *buff) {

}
