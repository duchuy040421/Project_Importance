#include"FakeBirthday.h"

Date FakeBirthday::next() {
	int day, month, year;

	day = (rand() % 31) + 1; month = (rand() % 12) + 1; year = (rand() % 120) + 1900;
	Date temp(day, month, year);

	while (!Date::isValid(temp.toString())) {
		day = (rand() % 31) + 1; month = (rand() % 12) + 1; year = (rand() % 120) + 1;
		temp._day = day; temp._month = month; temp._year = year;
	}

	return temp;
}
Date FakeBirthday::next(int age) {
	Date temp;
	int year = temp._year - age;

	temp = FakeBirthday::next();
	temp._year = year;

	return temp;
}