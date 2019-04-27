//начало великого
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
	
	friend ostream& operator<< (ostream &out, const Matrixs &point);

private:
	const int M=2, N=2; //стороны матрицы
	int Arr[2][2];
};

ostream& operator<< (ostream &out, const Matrixs &mat)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			out << mat.Arr[i][j] << " ";
	cout << endl;

	return out;
}


int main()
{
	setlocale(LC_ALL, "RUS");

	Matrixs matrix_1;
	matrix_1.InitMatrix();
	matrix_1.GetMatrix();
	cout << endl;

	Matrixs matrix_2;
	matrix_2.InitMatrix();
	matrix_2.GetMatrix();
	cout << endl;

	cout << matrix_2;
	
	system("pause");
	return 0;
}
