#pragma once
#include<iostream>
#include<ctime>
using namespace std;

class Random {
public:
	int next();
	int next(int);
	int next(int, int);
};
