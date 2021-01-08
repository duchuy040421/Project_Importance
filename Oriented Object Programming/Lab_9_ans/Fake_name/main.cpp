#include"Fake_name.h"

int main() {
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		Fullname temp = Fakename::next();
		temp.show();
		cout << endl;
	}
}