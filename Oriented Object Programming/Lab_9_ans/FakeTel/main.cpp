#include"FakeTel.h"

int main() {
	srand(time(NULL));
	cout << "Danh sach 20 so dien thoai ngau nhien:\n";
	for (int i = 0; i < 20; i++) {
		string temp_1;
		for (int i = 0; i < 7; i++) {
			string temp_2 = to_string(rand() % 10);
			temp_1 += temp_2;
		}
		string temp = number[rand() % 33] + temp_1;
		cout << temp << endl;
	}
}