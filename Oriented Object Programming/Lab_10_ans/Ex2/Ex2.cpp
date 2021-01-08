#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

int random() {
	return 10 + rand() % 11;
}

class Employee {
public:
	virtual float paid() = 0;
	virtual string name() = 0;
};
class Company {
private:
	string name = "EzLife";
public:
	vector <Employee*> e;
	float paid() {
		double result = 0;
		for (int i=0;i<e.size();i++)
			result += e[i]->paid();
		return result;
	}
	void generate(int n);
};



class Daily:public Employee {
private:
	int day;
public:
	Daily(int d) {
		day = d;
	}
	float paid() {
		return day * 200;
	}
	string name() { return "Daily employee"; }
};

class Manager:public Employee {
private:
	int year;
public:
	Manager(int y) {
		year = y;
	}
	float paid() { return 3000 * pow(1 + 0.15, year); }
	string name() { return "Manager"; }
};

class Worker :public Employee {
private:
	int product;
public:
	Worker(int p) {
		product = p;
	}

	float paid() {
		if (product <= 20)
			return product * 3000;
		else {
			return 20 * 3000 + (product - 20) * (3000 + 250);
		}
	}
	string name() { return "Worker employee"; }
};

void writeFile(Company c) {
	fstream w;
	w.open("Ex2.txt", ios::out);
	if (!w)
		cout << "Can't open file\n";
	else {
		w << "Employee: " << c.e.size() << endl;
		for (int i = 0;i<c.e.size();i++) {
			w << c.e[i]->name() << " " << c.e[i]->paid() << endl;
		}
	}
	w.close();

}
void Company::generate(int n) {
	for (int i = 0; i < n; i++)
	{
		int num = 1 + rand() % 3;

		switch (num)
		{
		case 1:
			e.push_back(new Daily(1 + rand() % 31));
			break;
		case 2:
			e.push_back(new Manager(rand() % 21));
			break;
		case 3:
			e.push_back(new Worker(rand() % 100));
			break;
		default:
			break;
		}
	}
};
int main() {
	srand(time(NULL));
	int num = random();
	cout << "Gererate number (10<=n<=20): " << num << endl;
	cout << "---------------------------------------------------\n";

	Company c;
	c.generate(num);
	for (int i=0;i<c.e.size();i++)
	{
		cout << c.e[i]->name() << " \t\t\t|Salary:" << c.e[i]->paid() << endl;
	}

	cout << "---------------------------------------------------\n";
	cout << "The total salary the owner of the company have to pay for all the employees in this month: ";
	cout << c.paid();
	writeFile(c);
}