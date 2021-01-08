#pragma comment(lib,"Date.lib")
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class FakeBirthday {
public:
	static Date next();
	static Date next(int);
};