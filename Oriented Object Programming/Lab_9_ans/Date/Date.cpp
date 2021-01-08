#include"Date.h"

Date::Date() {
	time_t info = time(NULL);
	tm* now = std::localtime(&info);
	this->_year = now->tm_year + 1900; this->_month = now->tm_mon + 1; this->_day = now->tm_mday;
}
Date::Date(int day, int month, int year) {
	this->_year = year;
	this->_month = month;
	this->_day = day;
}
string Date::toString() {
	string temp;
	temp = to_string(this->_day) + '/' + to_string(this->_month) + '/' + to_string(this->_year);
	return temp;
}
Date Date::parse(string n){
	Date temp;
	temp._year = 0; temp._month = 0; temp._day = 0;
	temp._day = atoi(n.substr(0, 2).c_str());
	temp._month = atoi(n.substr(3, 2).c_str());
	temp._year = atoi(n.substr(6, 4).c_str());
	return temp;
}
bool Date::isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}
bool Date::tryParse(string n, Date& d) {
	Date temp = parse(n);
	if (temp._day == d._day && temp._month == d._month && temp._year == d._year)
		return true;
	return false;
}
bool Date::isValid(string n) {
	Date temp;
	temp = Date::parse(n);
	if (temp._month == 1 || temp._month == 3 || temp._month == 5 || temp._month == 7 || temp._month == 8 || temp._month == 10 || temp._month == 12)
	{
		if (temp._day <= 0 || temp._day > 31)
			return false;
	}
	else if (temp._month == 4 || temp._month == 6 || temp._month == 9 || temp._month == 11)
	{
		if (temp._day <= 0 || temp._day > 30)
			return false;
	}
	else if (temp._month == 2)
	{
		if (Date::isLeapYear(temp._year)) {
			if (temp._day <= 0 || temp._day > 29)
				return false;
		}
		else
			if (temp._day <= 0 || temp._day > 28)
				return false;
	}
	return true;
}

