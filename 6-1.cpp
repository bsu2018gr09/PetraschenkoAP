//Матрица 2х2
#include <iostream>
#include <ctime>
using namespace std;

class Matrix2 {
public:
	Matrix2() : Arr{ 0 } { ; };
	Matrix2(int A) { //иницилизируем в промежутке от 0 до А-1
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				Arr[i][j] = rand() % A;
	};
	Matrix2 operator=(Matrix2 &mat) { //присвоить
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				Arr[i][j] = mat.Arr[i][j];
		return *this;
	};
	const Matrix2 operator=(const Matrix2 &mat) { //присвоить
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				Arr[i][j] = mat.Arr[i][j];
		return *this;
	};
	Matrix2 operator=(int value) { //присвоить
		Matrix2 result;
		result.Arr[0][0] = value;
		return result;
	};
	~Matrix2() { ; };

	Matrix2(int a, int b, int c, int d) {
		Arr[0][0] = a; Arr[0][1] = b; Arr[1][0] = c; Arr[1][1] = d;
	};

	friend ostream& operator<< (ostream &out, const Matrix2 &mat) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				out << mat.Arr[i][j] << " ";
			out << endl;
		}
		return out;
	};

	friend istream& operator >> (istream &in, Matrix2 &mat) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				cout << "Enter element of " << i << " stroki i " << j << " stolbtsa: ";
				in >> mat.Arr[i][j];
				cout << endl;
			}
		}
		return in;
	};

	Matrix2 operator+=(Matrix2 &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				Arr[i][j] = Arr[i][j] + mat.Arr[i][j];
			}
		return *this;
	};

	const Matrix2 operator+=(const Matrix2 &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				Arr[i][j] = Arr[i][j] + mat.Arr[i][j];
			}
		return *this;
	};

	Matrix2 operator-=(Matrix2 &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				Arr[i][j] = Arr[i][j] - mat.Arr[i][j];
			}
	};

	const Matrix2 operator-=(const Matrix2 &mat) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				Arr[i][j] = Arr[i][j] - mat.Arr[i][j];
			}
	};

	Matrix2 operator-(Matrix2 &mat) {
		Matrix2 result;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				result.Arr[i][j] = this->Arr[i][j] - mat.Arr[i][j];
		return result;
	};

	const Matrix2 operator-(const Matrix2 &mat) {
		Matrix2 result;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				result.Arr[i][j] = this->Arr[i][j] - mat.Arr[i][j];
		return result;
	};

	Matrix2 operator+(Matrix2 &mat) {
		Matrix2 result;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				result.Arr[i][j] = this->Arr[i][j] + mat.Arr[i][j];
		return result;
	};

	const Matrix2 operator+(const Matrix2 &mat) {
		Matrix2 result;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				result.Arr[i][j] = this->Arr[i][j] + mat.Arr[i][j];
		return result;
	};

	Matrix2 operator*(Matrix2 &mat) {
		Matrix2 result(0, 0, 0, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < M; ++k) {
					result.Arr[i][j] += this->Arr[i][k] * mat.Arr[k][j];
				}
			}
		}
		return result;
	};

	const Matrix2 operator*(const Matrix2 &mat) {
		Matrix2 result(0, 0, 0, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < M; ++k) {
					result.Arr[i][j] += this->Arr[i][k] * mat.Arr[k][j];
				}
			}
		}
		return result;
	};

	Matrix2 operator*=(Matrix2 &mat) {
		Matrix2 result(0, 0, 0, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < M; ++k) {
					this->Arr[i][j] += Arr[i][k] * mat.Arr[k][j];
				}
			}
		}
		return *this;
	};

	const Matrix2 operator*=(const Matrix2 &mat) {
		Matrix2 result(0, 0, 0, 0);
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < M; ++k) {
					this->Arr[i][j] += Arr[i][k] * mat.Arr[k][j];
				}
			}
		}
		return *this;
	};

	Matrix2 operator*(int value) {
		Matrix2 result;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				result.Arr[i][j] = this->Arr[i][j] * value;
			}
		}
		return result;
	};

	Matrix2 operator*=(int value) {
		Matrix2 result;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				this->Arr[i][j] = Arr[i][j] * value;
			}
		}
		return *this;
	};

	bool operator==(Matrix2 &mat) {
		if (mat.Arr == Arr) {
			return 1;
		} 
		return 0;
	};

	int& operator[](int index) { //нумерация идёт с 0
		Matrix2 mat;
		if (index<0 || index>2*M) {
			cout << "Ошибка\n";
			return Arr[M][N];
			exit(1);
		}
		int i, j;
		if (index % M != 0) {
			i = 0; j = index;
		}
		else {
			i = M / index;
			j = index - M;
		}
		return Arr[i][j];
	};

	void OutElemOfMatrix(int index, int elem) { //1-какой эллемент заменяем. 2-на какой заменяем
		int i, j;
		if (index % M != 0) {
			i = 0; j = index;
		}
		else {
			i = M / index;
			j = index - M;
		}
		Arr[i][j] = elem;
		cout << Arr[i][j];
	}

private:
	const int M=2, N=2; //размер матрицы
	int Arr[2][2];
};

int main()
{
	setlocale(LC_ALL, "RUS");

	int M = 2, N = 2;

	const Matrix2 E{1,0,0,1}; //иницилизация константной матрицы
	cout << E << endl;

	Matrix2 a; //Иницилизация с дефолт параметрами
	cout << a << endl; //перегруженные оператор вывода

	Matrix2 b(1,2,3,4); //Иницилизация с заданными параметрами
	cout << b << endl;

	Matrix2 c;
	c = b + E; //пеегруженный оператор сложения
	cout << c << endl;

	c = b - b; //пеегруженный оператор вычитания
	cout << c << endl;


	c = b * E; //пеегруженный оператор умножения
	cout << c << endl;

	c = b * 5; //пеегруженный оператор умножения
	cout << c << endl;

	c = b; //перегруженный оператор присваивания
	cout << c << endl;

	cin >> c; //перегруженный оператор ввода
	cout << c << endl;
	
	c[3] = 5; 
	cout << c << endl;

	if (a == a) cout << "Матрицы равны" << endl; else cout << "Матрицы неравны" << endl; //перегруженный оператор сравнения
	if (a == b) cout << "Матрицы равны" << endl; else cout << "Матрицы неравны" << endl; //перегруженный оператор сравнения

	c.OutElemOfMatrix(3, 5);
	cout << endl;

	system("pause");
	return 0;
}
