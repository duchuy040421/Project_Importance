#include"FakeBirthday.h"

int main() {
	srand(time(NULL));
	Date d1 = FakeBirthday::next();
	cout << d1.toString() << endl;
	Date d2 = FakeBirthday::next(18);
	cout << d2.toString() << endl;
	return 0;
}