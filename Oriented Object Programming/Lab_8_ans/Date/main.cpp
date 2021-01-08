#include"Date.h"

int main() {
	Date d1, d2(21,8,2020);
	cout << d1.toString() << endl;
	cout << d2.toString() << endl;
	Date t3 = Date::parse("07/06/2020");
	cout << t3.toString() << endl;
	cout << Date::isValid("29/02/2020") << endl;
	cout << Date::isLeapYear(2020);
}