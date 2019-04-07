//Горизонтальный градиент
#include<iostream>
#include<fstream>  
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream in("d:\\1.bmp", ios::binary);
	ofstream out("d:\\result.bmp", ios::binary);
	if (!in) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!out) { cout << "No file d:\\result.bmp. Can't create\n"; exit(1); }

	char buf[30];
	unsigned int w, h;
	int tmp;

	in.read((char *)&buf, 18);
	out.write((char *)&buf, 18);
	in.read((char *)&w, 4);
	in.read((char *)&h, 4);
	out.write((char *)&w, 4);
	out.write((char *)&h, 4);
	in.read((char *)&buf, 28); 
	out.write((char *)&buf, 28);

	tmp = w / 255;

	c.r=c.g=c.b=0;
	//горизонтальный градиент (слева-направо)
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			c.g =j / tmp;
			c.b = j / tmp;
			c.r = j / tmp;
			out.write((char *)&c, 3);
		}
	}

	//горизонтальный градиент (справа-налево)
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			c.g = 255 - j / tmp;
			c.b = 255 - j / tmp;
			c.r = 255 - j / tmp;
			out.write((char *)&c, 3);
		}
	}

	in.close();
	out.close();
	return 0;
}
