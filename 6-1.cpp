//Матрица 2х2
#include <iostream>
#include <ctime>
using namespace std;

class Matrixs {
public:
	Matrixs() : Arr{ 0 } { ; };
	Matrixs(int A) { //иницилизируем в промежутке от 0 до А-1
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				Arr[i][j] = rand() % A;
	};
	Matrixs operator=(Matrixs &mat) { //присвоить
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				Arr[i][j] = mat.Arr[i][j];
		return *this;
	};
	Matrixs operator=(int value) { //присвоить
		Matrixs result;
		result.Arr[0][0] = value;
		return result;
	};
	~Matrixs() { ; };

	Matrixs(int a, int b, int c, int d) {
		Arr[0][0] = a; Arr[0][1] = b; Arr[1][0] = c; Arr[1][1] = d;
	};

	friend ostream& operator<< (ostream &out, const Matrixs &mat) { //вывод
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				out << mat.Arr[i][j] << " ";
			out << endl;
		}
		return out;
	};

	friend istream& operator >> (istream &in, Matrixs &mat) { //ввод
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				cout << "Enter element of " << i << " stroki i " << j << " stolbtsa: ";
				in >> mat.Arr[i][j];
				cout << endl;
			}
		}
		return in;
	};

	Matrixs operator()(Matrixs &mat) {
		;
	}

	Matrixs operator+=(Matrixs &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				Arr[i][j] = Arr[i][j] + mat.Arr[i][j];
			}
		return *this;
	};

	Matrixs operator-=(Matrixs &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				Arr[i][j] = Arr[i][j] - mat.Arr[i][j];
			}
	};

	Matrixs operator-(Matrixs &mat) {
		Matrixs result;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				result.Arr[i][j] = this->Arr[i][j] - mat.Arr[i][j];
		return result;
	};

	Matrixs operator+(Matrixs &mat) {
		Matrixs result;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				result.Arr[i][j] = this->Arr[i][j] + mat.Arr[i][j];
		return result;
	};

	Matrixs operator*(Matrixs &mat) {
		Matrixs result(0, 0, 0, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < M; ++k) {
					result.Arr[i][j] += this->Arr[i][k] * mat.Arr[k][j];
				}
			}
		}
		return result;
	};

	Matrixs operator*=(Matrixs &mat) {
		Matrixs result(0, 0, 0, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < M; ++k) {
					this->Arr[i][j] += Arr[i][k] * mat.Arr[k][j];
				}
			}
		}
		return *this;
	};

	Matrixs operator*(int value) {
		Matrixs result;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				result.Arr[i][j] = this->Arr[i][j] * value;
			}
		}
		return result;
	};

	Matrixs operator*=(int value) {
		Matrixs result;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				this->Arr[i][j] = Arr[i][j] * value;
			}
		}
		return *this;
	};

	 operator[](int value) {
		Matrixs mat;
		if (value<0 || value>M){
			cout << "Ошибка\n";
			exit(1);
		}

			return mat[value];
	};

private:
	const int M=2, N=2; //размер матрицы
	int Arr[2][2];
};

int main()
{
	setlocale(LC_ALL, "RUS");

	int M = 2, N = 2;

	Matrixs a; //Иницилизация с дефолт параметрами
	cout << a << endl;

	Matrixs b(1,2,3,4); //Иницилизация с заданными параметрами
	cout << b << endl;

	Matrixs c;
	c = b + b; //пеегруженный оператор сложения
	cout << c << endl;

	c = b - b; //пеегруженный оператор вычитания
	cout << c << endl;


	c = b * b; //пеегруженный оператор умножения
	cout << c << endl;

	c = b * 5; //пеегруженный оператор умножения
	cout << c << endl;

	c = b; //перегруженный оператор присваивания
	cout << c << endl;

	cin >> c; //перегруженный оператор вывода
	cout << c;
	
	cin >> c[0][0];

	system("pause");
	return 0;
}
