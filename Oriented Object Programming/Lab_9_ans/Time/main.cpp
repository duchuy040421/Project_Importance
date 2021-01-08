#include"Time.h"

int main() {
	Time t1, t2(05, 26, 32);
	cout << t1.toString() << endl;
	cout << t2.toString() << endl;
	Time t3 = Time::parse("16:18:20");
	cout << t3.toString() << endl;
	cout << Time::isValid("25:18:20");
}