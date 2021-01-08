#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Date {
private:
	int _day, _month, _year;
public:
	Date();
	Date(int, int, int);
	string toString();
	static Date parse(string);
	static bool tryParse(string, Date&);
	static bool isValid(string);
	static bool isLeapYear(int);
	friend class FakeBirthday;
};
