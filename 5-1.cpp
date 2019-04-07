//Горизонтальный и вертикальный градиенты
#include <fstream>
#include <iostream>
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream in("d:\\1.bmp", ios::binary);
	ofstream out("d:\\result.bmp", ios::binary);
	if (!in) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!out) { cout << "No file d:\\result.bmp. Can't create\n"; exit(1); }

	char buf[30];
	unsigned int w, h;
	int count, k;
	float tmp;

	in.read((char *)&buf, 18);
	out.write((char *)&buf, 18);
	in.read((char *)&w, 4);
	in.read((char *)&h, 4);
	out.write((char *)&w, 4);
	out.write((char *)&h, 4);
	in.read((char *)&buf, 28);
	out.write((char *)&buf, 28);

	c.r = c.g = c.b = 0;
	cout << "Какой градиент вы хотите?" << endl;
	cout << "Горизонтальный (слева-направо) - 1" << endl;
	cout << "Горизонтальный (справа-налево) - 2" << endl;
	cout << "Вертикальный (сверху-вниз) - 3" << endl;
	cout << "Вертикальный (снизу-вверх) - 4" << endl;
	cin >> count;
	switch (count) {
	case 1: {
		//горизонтальный градиент (слева-направо)
		tmp = (float) w / 255 + 1;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				c.g = j / tmp;
				c.b = j / tmp;
				c.r = j / tmp;
				out.write((char *)&c, 3);
			}
		}
		break;
	}
	case 2: {
		tmp = w / 255 + 1;
		//горизонтальный градиент (справа-налево)
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				c.g = 255 - j / tmp;
				c.b = 255 - j / tmp;
				c.r = 255 - j / tmp;
				out.write((char *)&c, 3);
			}
		}
		break;
	}

	case 3: {
		//вертикальный градиент (снизу-вверх)
		k = 255;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				c.g = k;
				c.b = k;
				c.r = k;
				out.write((char *)&c, 3);
			}
			--k;
		}
		break;
	}

	in.close();
	out.close();
	return 0;
}
