//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include <iostream>
#include <time.h>
using namespace std;
void givemem(int *&A, int N);
void clearmem(int *&A);
void initArr(int* A, int N);
void printArr(int* A, int N);
void calc(int* A, int N);

int main() {
	setlocale(LC_ALL, "Russian");

	int N;
	int *A = nullptr, *B = nullptr;

	cout << "Введите размерность массива: ";
	cin >> N;

	givemem(A, N);
	initArr(A, N);
	printArr(A, N);
	cout << endl;
	calc(A, N);
	clearmem(A);

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
	}
}

void initArr(int* A, int N) {
	const int M = 3;
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % M;
	}
}

void printArr(int* A, int N) {
	for (int i = 0; i < N; ++i)
		cout << *(A + i) << " ";
}

void calc(int* A, int N) {
	int j = 1;
	for (int i = 0; i < N - 1; ++i) {
		for (; j < N; ++j) {
			if (*(A + i) < 0 && *(A + j) >= 0) {
				swap(*(A + i), *(A + j));
			}
		}
		j = i + 1;
	}
	for (int k = 0; k < N - 1; ++k) {
		if (*(A + k) < 0 && *(A + k) > *(A + k + 1))
			swap(*(A + k), *(A + k + 1));
	}
	printArr(A, N);
}
