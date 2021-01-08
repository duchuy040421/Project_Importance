#include<iostream>
#include<string>
using namespace std;
void shorten()
{
	int a;
	string n, n1;
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	cout << "nhap n: " << endl;
	cin >> a;
	n1 = n.substr(0, a);
	cout << n1;
}
int main()
{
	shorten();
}