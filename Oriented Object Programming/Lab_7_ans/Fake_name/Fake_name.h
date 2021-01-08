#pragma once

#include<iostream>
#include<sstream>
#include<ctime>
using namespace std;

class Fullname {
private:
	string _firstName;
	string _middleName;
	string _lastName;
public:
	Fullname() {
		_firstName="";
		_middleName="";
		_lastName="";
	}
	~Fullname() {
		_firstName = "";
		_middleName = "";
		_lastName = "";
	}
	void show() {
		cout << _firstName << " " << _middleName << " " << _lastName;
	}
	friend class Fakename;
};
class Fakename {
public:
	Fullname temp;
	static string firstName[];
	static string middleName[];
	static string lastName[];
	static Fullname next();
};
