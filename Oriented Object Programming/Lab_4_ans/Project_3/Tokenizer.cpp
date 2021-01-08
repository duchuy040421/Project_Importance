#include"Tokenizer.h"

//additional function implement:
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void sort(vector<int>&temp) {
	for (int i = 0; i < temp.size() - 1; i++)
		for (int j = i + 1; j < temp.size(); j++)
			if (temp[i] < temp[j])
				swap(temp[i], temp[j]);
}
bool Isprime(int a) {
	int count = 0;
	for (int i = 1; i <= a; i++)
		if (a % i == 0)
			count++;
	if (count == 2)
		return true;
	return false;
}

//class implement:
vector<int>Convert::find(string haystack) {
	vector<int> result;
	string separator = " ";
	int startPos = 0;
	while (true)
	{
		size_t found_pos = haystack.find(separator, startPos);

		if (found_pos != string::npos) {
			string token = haystack.substr(startPos, found_pos - startPos);

			result.push_back(atoi(token.c_str()));
			startPos = found_pos + separator.length();
		}
		else {
			int last = haystack.length() - startPos;

			string temp = haystack.substr(startPos, last);
			result.push_back(atoi(temp.c_str()));
			break;
		}
	}
	return result;
}
int Convert::smallest() {
	sort(this->list);
	return list[list.size() - 1];
}
int Convert::sum_list() {
	int sum = 0;
	for (int i = 0; i < this->list.size(); i++)
		sum += list[i];
	return sum;
}
void Convert::largest() {
	sort(this->list);
	cout << "\nThe first 3 biggest number in the vector: ";
	for (int i = 0; i < 3; i++)
		cout << list[i] << " ";
}
float Convert::average() {
	return (float)(this->sum_list())/ this->list.size();
}
void Convert::show_isprime() {
	cout << "\nNumber prime in list: ";
	for (int i = 0; i < this->list.size(); i++)
		if (Isprime(list[i]))
			cout << list[i] << " ";
}
Convert::Convert(string haystack) {
	this->list = Convert::find(haystack);
}

//menu each lab:
void menu_1()
{
		cin.ignore();
		cout << "\nEnter haystack: ";
		string temp;
		getline(cin, temp);
		cout << "\nEnter seedle: ";
		string temp_1;
		getline(cin, temp_1);
		vector <string>tokens = Tokenizer::split(temp, temp_1);

		int n = tokens.size();

		for (int i = 0; i < n; i++)
			cout << tokens[i] << endl;

		cout << "There are " << tokens.size() << " element in vector\n";
}
void menu_2()
{
	cin.ignore();
	cout << "\nEnter list number: ";
	string temp_3;
	getline(cin, temp_3);
	vector<int>convert = Convert::find(temp_3);

	int n_1 = convert.size();
	sort(convert);
	cout << "The smallest number in the vector: " << convert[n_1 - 1] << endl;
	cout << "The first 3 biggest number in the vector: ";
	for (int i = 0; i < 3; i++)
		cout << convert[i] << " ";
}
void menu_3() {
	cin.ignore();
	cout << "\nEnter list number: ";
	string temp_4;
	getline(cin, temp_4);
	
	Convert temp(temp_4);
	cout << "\nSum of list: " << temp.sum_list();
	cout << "\nThe smallest number in list: " << temp.smallest();
	temp.largest();
	cout << "\nThe average number in list: " << temp.average();
	temp.show_isprime();
}
