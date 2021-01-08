#include<iostream>
#include<ctime>
#include<vector>
#include<string>
using namespace std;

class Animal {
public:
	virtual string name() = 0;
	virtual int milk() = 0;
};
class Farm {
public:
	vector<Animal*>a;
	int sum_milk() {
		int result = 0;
		for (int i = 0; i < a.size(); i++)
			result += a[i]->milk();

		return result;
	}
	void generate(int n);
	void named_count(int day);
};


class Cow :public Animal {
public:
	static vector<int>days;
	string name() {
		return "Cow";
	}
	int milk() {
		int result = 0;
		for (int i = 0; i < days.size(); i++)
			result += days[i];

		return result;
	}
};

class Sheep :public Animal {
public:
	string name() {
		return "Sheep";
	}
	static vector<int>days;
	int milk() {
		int result = 0;
		for (int i = 0; i < days.size(); i++)
			result += days[i];

		return result;
	}
};

class Goat :public Animal {
public:
	string name() {
		return "Goat";
	}
	static vector<int>days;
	int milk() {
		int result = 0;
		for (int i = 0; i < days.size(); i++)
			result += days[i];

		return result;
	}

};

void Farm::generate(int n) {
	for (int i = 1; i <= n; i++) {
		int num = 1 + rand() % 3;

		switch (num)
		{
		case 1:
			a.push_back(new Cow);
			break;
		case 2:
			a.push_back(new Sheep);
			break;
		case 3:
			a.push_back(new Goat);
			break;
		default:
			break;
		}
	}
}

void Farm::named_count(int day) {
	vector<int>cows, sheeps, goats;
	for (int i = 0; i < day; i++) {
		int cow = 6 + rand() % 5;
		int sheep = 1 + rand() % 2;
		int goat = 3 + rand() % 3;

		cout << "Day " << i + 1 << endl;
		cout << "Cow " << cow << " litres\n";
		cout << "Sheep " << sheep << " litres\n";
		cout << "Goat " << goat << " litres";

		cows.push_back(cow);
		sheeps.push_back(sheep);
		goats.push_back(goat);

		cout << "\n------------------------------------\n";
	}

	Cow::days = cows;
	Sheep::days = sheeps;
	Goat::days = goats;
}

vector<int>Cow::days = { 0 };
vector<int>Sheep::days = { 0 };
vector<int>Goat::days = { 0 };
int main() {
	srand(time(NULL));
	Farm f;

	int num = 10 + rand() % 11;
	f.generate(num);

	cout << "Animal: " << num << endl;
	for (int i = 0; i < num; i++) {
		cout << f.a[i]->name() << endl;
	}
	cout << "\n------------------------------------\n";
	f.named_count(num);
	cout << "How much milk you will get in " << num << " days from these animals in the farm ";
	cout << f.sum_milk();
	
}