#pragma comment(lib, "Project_1.lib")
#pragma comment(lib, "Project_3.lib")
#include"Random.h"
#include"Tokenizer.h"
#include<sstream>
using namespace std;

class State {
private:
	vector<int>list;
	void clear() {
		list.clear();
	}
	void push_back(int x) {
		list.push_back(x);
	}
public:
	string toString(string );
	friend class Store;
};
class Store {
private:
	State _state;
	Random _rng;
public:
	void generateRandomNumbers(int, int);
	void showCurrentNumbers();
	void getNumbersFromKeyboard();
};
