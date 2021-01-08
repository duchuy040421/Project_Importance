#include"Function.h"
#define MAX 999

string State::toString(string separator = " ") {
	stringstream writer;

	for (int i = 0; i < this->list.size(); i++)
		writer << list[i] << separator;

	return writer.str();
}

void Store::generateRandomNumbers(int n = 10, int Max = MAX) {
	for (int i = 0; i < n; i++) {
		int x = this->_rng.next(0, Max);
		this->_state.push_back(x);
	}
}
void Store::showCurrentNumbers() {
	if (this->_state.list.empty())
	{
		cout << "Khong co phan tu nao trong mang\n";
	}
	else {
		cout << this->_state.toString();
	}	
}
void Store::getNumbersFromKeyboard() {
	this->_state.clear();
	cout << "\nNhap chuoi so: \n";

	string haystack;
	getline(cin, haystack);

	if (haystack[0] == NULL)
		return;
	this->_state.list = Convert::find(haystack);
}

