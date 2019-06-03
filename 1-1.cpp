//Даны точки плоскости своими координатами в виде двух одномерных массивов (случайные числа).
//Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include <iostream>
#include <time.h>
using namespace std;
void givemem(int *&A, int N);
void clearmem(int *&A);
void initArr(int* A, int N);
void printArr(int *A, int N);
void Sort(int *A, int *B, int* D, int N);
void length(int *A, int *B, int *C, int N);

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Дана прямая: 2x+3y+1=0" << endl;

	int N;
	int *A = nullptr, *B = nullptr, *C=nullptr;

	cout << "Введите размерность массива: ";
	cin >> N;

	givemem(A, N);
	initArr(A, N);
	givemem(B, N);
	initArr(B, N);
	givemem(C, N);
	length(A, B, C, N);
	Sort(A, B, C, N);
	cout << "Координата Х: ";
	printArr(A, N);
	cout << endl;
	cout << "Координата Y: ";
	printArr(B, N);
	clearmem(A);
	clearmem(B);
	clearmem(C);

	cout << endl;

	system("pause");
	return 0;
}

void clearmem(int *&A) {
	delete[] A;
}

void givemem(int *&A, int N) {
	A = new (nothrow) int[N];
	if (!A) {
		cout << "Error" << endl;
		exit(1);
	}
}

void initArr(int* A, int N) {
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % 10;
	}
}

void printArr(int *A, int N) {
	for (int i = 0; i < N; ++i)
		cout << *(A + i) << " ";
}

void length(int *A, int *B, int *C, int N) {
		for (int i = 0; i < N; i++)
			*(C + i) = abs(*(A + i) + *(B + i) + 1) / sqrt(2 * 2 + 3 * 3);
	}

void Sort(int *A, int *B, int* C, int N) {
		for (int i = 0; i < N - 1; ++i) {
			for (int j = 0; j < N - i - 1; ++j) {
				if (*(C + j) > *(C + j+1)) {
					swap(*(A + j), *(A + j + 1));
						swap(*(B + j), *(B + j + 1));
				}
			}
		}
	}
