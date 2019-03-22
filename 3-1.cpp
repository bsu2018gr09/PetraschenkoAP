//Найти и удалить все слова строки, состоящие только из цифр.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <iomanip> 
#include <cstring>
#include <clocale>
using namespace std;

void checkStr(char *str);
void giveMemory(char *&str);
void deleteMemory(char *&str);

const int MAX = 255;

int main() {
	setlocale(LC_ALL, "Russian");

	char *str = nullptr;

	giveMemory(str);
	cin.getline(str, MAX);
	checkStr(str);

	system("pause");
	return 0;
}

void giveMemory(char *&str) {
	str = new(nothrow) char[MAX];
	if (!str) {
		cout << "error" << "\n";
	}
}

void checkStr(char *str) {
	char *p = str;
	while (*str) {
		int k = 0, begin, end;
		char *check = " ";
		begin = strspn(str, check);
		str += begin;
		end = strcspn(str, check);
		for (int i = 0; i < end; ++i) {
			if (str[i] >= '0' && str[i] <= '9')
				++k;
		}
		if (k == end)
			for (int j = end; j <= strlen(str); ++j)
				str[j - end] = str[j];
		else str += end;
	}
	cout << p;
	deleteMemory(p);
}

void deleteMemory(char *&str) {
	delete[] str;
	str = nullptr;
}
