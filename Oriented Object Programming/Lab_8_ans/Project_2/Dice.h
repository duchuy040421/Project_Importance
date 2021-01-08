#pragma comment(lib, "Project_1.lib")
#include<iostream>
#include"Random.h"
using namespace std;

class Dice {
private:
	Random rng;
	int rollCount;
	int value[7] = { 0 };
	int sum ;
public:
	Dice();
	void getRollCount();
	int RollCount();
	float averageRollCount();
};
