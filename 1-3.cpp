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
void FindSimpleNumbers(int *A, int N);
int CountSimpleNumbers(int *&A, int &count, int N);
bool PrimeOrNo(int valueofarr);


int main() {
	setlocale(LC_ALL, "Russian");

	int N;
	int *A = nullptr, *B = nullptr;

	cout << "Введите размерность массива: ";
	N = 5;

	givemem(A, N);
	initArr(A, N);
	printArr(A, N);
	cout << endl;
	FindSimpleNumbers(A, N);
	printArr(A, N);
	clearmem(A);

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
		system("pause");
	}
}

void initArr(int* A, int N) {
	srand(time(0));
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % 10 + 3;
	}
}

void printArr(int* A, int N) {
	for (int i = 0; i < N; ++i)
		cout << *(A + i) << " ";
}

void FindSimpleNumbers(int *A, int N) {
	int count = 0, i;
	CountSimpleNumbers(A, count, N);
	for (int i = 0; i < N - 1; ++i)
		if (PrimeOrNo(*(A + i))) {
			for (int j = i+1; j < N; ++j)
				if (PrimeOrNo(*(A + j)) && *(A + i) > *(A + j)) {
					swap(*(A + i), *(A + j));
					printArr(A, N);
					cout << endl;
				}
		}
}

int CountSimpleNumbers(int *&A, int &count, int N) {
	for (int i = 0; i < N; ++i)
		if (PrimeOrNo(*(A+i))) ++count;
	return count;
}

bool PrimeOrNo(int valueofarr) {
	int k = 2;
	const int value = valueofarr / 2;
	while (k <= value) {
		if (valueofarr % k == 0) { return true; }
		++k;
	}
	return false;
}
