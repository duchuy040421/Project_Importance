#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Address {
private:
	string _number, _street, _ward, _district;
public:
	friend class FakeHcmAddress;
	void show();
};

class FakeHcmAddress {
private:
	static string number[], street[], ward[], district[];
public:
	static Address next();
};
