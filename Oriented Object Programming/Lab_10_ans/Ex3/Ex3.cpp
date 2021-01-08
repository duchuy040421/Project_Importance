#include<iostream>
#include<ctime>
#include<vector>
#include<string>
using namespace std;

class Robot {
public:
	virtual string name() = 0;
public:
	static string result;
	static void generate(vector<Robot*>&r);
};

class Alpha :public Robot {
public:
	string name() {
		return "Alpha";
	}
};

class Beta :public Robot {
public:
	string name() {
		return "Beta";
	}
};

class Gamma :public Robot {
public:
	string name() {
		return "Gamma";
	}
};
void Robot::generate(vector<Robot*>&r) {
	int a = 0, b = 0, g = 0;
	for (int i = 1; i <= 3; i++) {
		int num = 1 + rand() % 3;
		switch (num)
		{
		case 1:
			r.push_back(new Alpha);
			a = 1;
			break;
		case 2:
			r.push_back(new Beta);
			b = 1;
			break;
		case 3:
			r.push_back(new Gamma);
			g = 1;
			break;
		default:
			break;
		}
	}
	if (a == 1 && b == 1 && g == 1)
		result= " Megatron with HP, ATK, DEF x7";
	else if (a == 1 && b == 1)
		result =" Megatron with HPx3 & DEFx1.2";
	else if (a == 1 && g == 1)
		result =" Megatron with HPx2 & ATKx2";
	else if (b == 1 && g == 1)
		result =" Megatron with ATKx1.5 & DEFx2";
	else
		result=" No Combination";
}
string Robot::result = "";
int main() {
	vector<Robot*>r;

	Robot::generate(r);
	for (Robot* temp : r) {
		cout << temp->name() << ",";
	}

	cout << Robot::result;
}