//Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.
#include <iostream>
#include <time.h>
#include <iostream>
#include <time.h>
using namespace std;
void givemem(int *&A, int N);
void clearmem(int *&A);
void initArr(int* A, int N);
void printArr(int* A, int N);
void calc(int* A, int N);
void sortSimple(int* A, int i, int t, int count, int N);
void countSimple(int*A, int count, int N);


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
		exit(1);
	}
}

void initArr(int* A, int N) {
	srand(time(0));
	const int M = 10;
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % M;
	}
}

void printArr(int* A, int N) {
	for (int i = 0; i < N; ++i)
		cout << *(A + i) << " ";
}

void calc(int* A, int N) {
	int t = 1, count = 0;
	countSimple(A, count, N);
	for (int i = 0; i < N - 1; ++i) {
		sortSimple(A, i, t, count, N);
		t = 1 + i;
	}
	for (int k = N - count; k < N - 1; ++k) {
			if (*(A + k) < *(A + k + 1))
				swap(*(A + k), *(A + k + 1));
		}
		printArr(A, N);
}

void sortSimple(int* A, int i, int t, int count, int N) {
	int k = 2, p = 2, temp_1 = 0, temp_2 = 0;
	for (; t < N; ++t) {
		for (; k <= *(A + i) / 2; ++k) {
			if (*(A + i) % k == 0)
				++temp_1;
		}
		for (; p <= *(A + t) / 2; ++p) {
			if (*(A + t) % p == 0)
				++temp_2;
		}
		if (temp_1 == 0 && temp_2 != 0) {
			swap(*(A + i), *(A + t));
			break;
		}
		k = 2;
		p = 2;
	}
}

void countSimple(int*A, int count, int N) {
	int temp = 0, k = 2;
	for (int i = 0; i < N; ++i) {
		for (; k <= *(A + i) / 2; ++k) {
			if (*(A + i) % k == 0)
				++temp;
		}
		if (temp == 0)
			++count;
	}
}
