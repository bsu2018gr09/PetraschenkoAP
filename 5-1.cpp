#include<iostream>
#include<fstream>  //где условие задачи? Какой градиент ты делаешь???
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream in("d:\\1.bmp", ios::binary);
	ofstream out("d:\\result.bmp", ios::binary);
	if (!in) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!out) { cout << "No file d:\\result.bmp. Can't create\n"; exit(1); }
// и что? даже заголовок не прочитаем-не запишем ? 
	char buf[30];
	unsigned int w, h;
	int tmp;

	c.r=c.g=c.b=0;

	tmp = w / 255 + 1;

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			out.write((char *)&c, 3);
			c.g =j / tmp;
			c.b = j / tmp;
			c.r = j / tmp;
		}
	}

	in.close();
	out.close();
	return 0;
}
