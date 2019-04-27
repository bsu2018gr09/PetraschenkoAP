#include <iostream>
#include <ctime>
using namespace std;

class Matrixs {
public:
	Matrixs() { cout << "Конструктор работает" << endl; }
	~Matrixs() { cout << "Деструктор работает" << endl; }

	void GetMatrix() {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j)
				cout << Arr[i][j] << " ";
			cout << endl;
		}
	}

	void InitMatrix() {
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
			Arr[i][j] = rand() % 4;
	}
	
	friend ostream& operator<< (ostream &out, const Matrixs &mat) { //вывод
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				out << mat.Arr[i][j] << " ";
			out << endl;
		}
		return out;
	}

	friend istream& operator >> (istream &in, Matrixs &mat) { //ввод
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				cout << "Enter element of " << i << " stroki i " << j << " stolbtsa: ";
				in >> mat.Arr[i][j];
				cout << endl;
			}
		}
		return in;
	}

	Matrixs operator=(Matrixs &mat) { //присвоить
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				Arr[i][j] = mat.Arr[i][j];
		return *this;
	}

	Matrixs operator+(Matrixs &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				Arr[i][j] += mat.Arr[i][j];
		return *this;
	}

	Matrixs operator-(Matrixs &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				Arr[i][j] -= mat.Arr[i][j];
		return *this;
	}

private:
	const int M=2, N=2; //стороны матрицы
	int Arr[2][2];
};

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "1 Матрица" << endl;
	Matrixs matrix_1;
	matrix_1.InitMatrix();
	matrix_1.GetMatrix();
	cout << endl;

	cout << "2 Матрица" << endl;
	Matrixs matrix_2;
	matrix_2.InitMatrix();
	matrix_2.GetMatrix();
	cout << endl;

	cout << "Сложили 1 со 2" << endl;
	matrix_2 = matrix_2 + matrix_1;
	cout << matrix_2 << endl;

	cout << "Отняли 1 от 2" << endl;
	matrix_2 = matrix_1 - matrix_2;
	cout << matrix_2 << endl;
	
	cout << "2 Матрице присвоили 1 матрицу" << endl;
	matrix_2 = matrix_1;
	cout << matrix_2 << endl;
	
	cin >> matrix_2;
	cout << matrix_2 << endl;

	system("pause");
	return 0;
}
