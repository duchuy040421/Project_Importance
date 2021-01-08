#pragma comment(lib, "Project_3.lib")
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
#include"Tokenizer.h"
using namespace std;

class Client {
public:
	static string separator;
private:
	string _id, _fullname;
	int _balance;
public:
	string id() { return _id; }
	string fullname() { return _fullname; }
	int balance() { return _balance; }
	void setId(string value) { _id = value; }
	void setFullname(string value) { _fullname = value; }
	void setBalance(int value) { _balance = value; }
public:
	Client() {
		_id = "";
		_fullname = "";
		_balance = 0;
	}
	Client(string id, string fullname, int balance) {
		_id = id;
		_fullname = fullname;
		_balance = balance;
	}
public:
	string toString() {
		stringstream writer;
		writer << _id << separator << _fullname << separator << _balance;
		return writer.str();
	}
public:
	static Client parse(string line) {
		Client result;

		auto tokens = Tokenizer::split(line,separator);
		result._id = tokens[0];
		result._fullname = tokens[1];
		result._balance = stoi(tokens[2]);

		return result;
	}
};


void writeFile();
void readFile();
