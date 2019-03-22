//Даны точки плоскости своими координатами в виде двух одномерных массивов (случайные числа).
//Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include <iostream>
#include <time.h>
using namespace std;
void givemem(int *&A, int N);
void clearmem(int *&A);
void initArr(int* A, int N);
void printArr(int x);
void Scan(int* A, int* B, int N);
void calc(int* A, int* B, int N);

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Дана прямая: 2x+3y+1=0" << endl;

	int N;
	int *A = nullptr, *B = nullptr;

	cout << "Введите размерность массива: ";
	cin >> N;

	givemem(A, N);
	initArr(A, N);
	givemem(B, N);
	initArr(B, N);
	Scan(A, B, N);
	calc(A, B, N);
	clearmem(A);
	clearmem(B);

	cout << endl;

	system("pause");
	return 0;
}

void clearmem(int *&A) {
	delete[] A;
	A = nullptr;
}

void givemem(int *&A, int N) {
	A = new (nothrow) int[N];
	if (!A) {
		cout << "Error" << endl;
		system("pause");
		exit(1);
	}
}

void initArr(int* A, int N) {
	const int M = 10;
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % M;
	}
}

void printArr(int x) {
	cout << x << " ";
}

void Scan(int* A, int* B, int N) {
	int j = 1;
	int temp_1, temp_2;
	for (int i = 0; i < N - 1; ++i) {
		for (; j < N; ++j) {
			temp_1 = abs(2 * *(A + i) + 3 * *(B + i) + 1);
			temp_2 = abs(2 * *(A + j) + 3 * *(B + j) + 1);
			if (temp_1 > temp_2) {
				swap(*(A + i), *(A + j));
				swap(*(B + i), *(B + j));
			}
		}
		j = i + 1;
	}
}

void calc(int* A, int* B, int N) {
	int x;
	for (int i = 0; i < N; ++i) {
		x = abs(2 * *(A + i) + 3 * *(B + i) + 1);
		printArr(x);
	}
}
