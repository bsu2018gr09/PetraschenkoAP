// В массиве А(N,М) часть строк состоит из нулей. удалить нулевые строки.
#include <iostream> 
#include <iomanip> 
#include <math.h> 
using namespace std;

void give_memory(int**& A, int M, int N);
void free_array(int**& A, int N);
void init_array(int **A, int N, int M);
void print_array(int **A, int N, int M);
void calc(int **A, int N, int M);
void print_arr_res(int **A, int *B, int M, int k);

int main() {
	setlocale(LC_ALL, "Russian");

	int N, M;

	cout << "Введмте Количество строк: ";
	cin >> N;
	cout << "Введмте Количество столбцов: ";
	cin >> M;
	cout << endl;

	int** A;

	give_memory(A, N, M);
	init_array(A, N, M);
	calc(A, N, M);
	free_array(A, N);

	system("pause");
	return 0;
}

void give_memory(int**& A, int N, int M) {
	A = new int*[N];
	if (!A) {
		cout << "Error!";
		system("pause");
	}
	for (int i = 0; i < N; ++i)
		A[i] = new (nothrow) int[M];
}

void free_array(int**& A, int N) {
	for (int i = 0; i < N; ++i) {
		delete[]A[i];
		A[i] = nullptr;
	}
	delete[]A;
	A = nullptr;
}

void init_array(int **A, int N, int M) {
	srand(time(0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			A[i][j] = rand() % 5;

}

void print_array(int **A, int N, int M) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void print_arr_res(int **A, int *B, int M, int k) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << A[B[i]][j] << " ";
		}
		cout << endl;
	}
}

void calc(int **A, int N, int M) {
	int *arr = new (nothrow) int[N];
	int tmp = 0, k = 0;

	for (int i = 0; i < N; ++i) {
		tmp = 0;
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != 0)
				++tmp; // слежка - есть ли нули
		}
		if (tmp == M) { // отдаём строку без нелей массиву
			arr[k] = i;
			++k;
		}
		else {
			delete[]A[i]; // удаляем строку с нулями
			A[i] = nullptr;
		}
	}
	print_arr_res(A, arr, M, k);
}
