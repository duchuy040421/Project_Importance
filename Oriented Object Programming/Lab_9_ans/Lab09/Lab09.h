#pragma comment(lib,"Fake_name")
#pragma comment(lib,"FakeAddress")
#pragma comment(lib,"FakeBirthday")
#pragma comment(lib,"FakeEmail")
#pragma comment(lib,"FakeTel")
#pragma comment(lib,"Date")
#include"Fake_name.h"
#include"FakeAddress.h"
#include"FakeBirthday.h"
#include"FakeEmail.h"
#include"FakeTel.h"
#include"Date.h"
#include<vector>
#include"fstream"

#define EPSILON 0.0001
class Student {
private:
	string _id;
	string _name;
	string _date;
	string _address;
	string _email;
	string _tel;
	float _mark;
public:
	Student(string id, string name, string date, string address, string email, string tel, float mark);
	void show();
	string toString();
	friend class Class;
};

class Class {
private:
	vector<Student>s;
public:
	void next(int);
	void sort();
	vector<Student>top();
	void writeFile();
};


