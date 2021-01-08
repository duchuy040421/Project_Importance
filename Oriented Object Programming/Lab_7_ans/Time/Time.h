#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>
using namespace std;

class Time {
private:
	int _hour, _min, _sec;
public:
	Time();
	Time(int, int, int);
	string toString();
	static Time parse(string);
	static bool tryParse(string, Time&);
	static bool isValid(string);
};
