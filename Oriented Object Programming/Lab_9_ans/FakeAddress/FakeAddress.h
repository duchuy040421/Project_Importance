#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<sstream>
using namespace std;

class Address {
private:
	string _number, _street, _ward, _district;
public:
	friend class FakeHcmAddress;
	string toString() {
		stringstream writer;
		writer << _number << " " << _street << " " << _ward << " " << _district;
		return writer.str();
	}
	void show();
};

class FakeHcmAddress {
private:
	static string number[], street[], ward[], district[];
public:
	static Address next();
};
