#include<iostream>
#include<string>
using namespace std;
void lowercasestring(string& n, int l)
{
	for (int i = 0; i <= l - 1; i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
			n[i] = n[i] + 32;
	}
}
void upcase(char& n)
{
	n = n - 32;
}
void chuanhoachuoidauvao(string n)
{
	int l = n.length();
	lowercasestring(n, l);
	if (n[0] == ' ')
		n.erase(0, 1);
	if (n[l - 1] == ' ')
		n.erase(l - 1, l);
	upcase(n[0]);
	l = n.length();
	for (int i = 1; i <= l - 1; i++)
	{
		if (n[i] == ' ')
			upcase(n[i + 1]);
	}
	cout << n;
}
int main()
{
	string n;
	cout << "nhap chuoi:" << endl;
	getline(cin, n);
	cout << "chuoi vua nhap la:" << n << endl;
	cout << "chuoi sau khi chuan hoa la: " << endl;
	chuanhoachuoidauvao(n);
}