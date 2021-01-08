#include<iostream>
#include<string>
using namespace std;
bool check(string n)
{
	for (int i = 0; i <= n.length() - 1; i++)
		if ((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z'))
			return false;
	return true;
}
int stringtodecimal(string n)
{
	int decimal = 0, c = 0;
	for (int i = n.length() - 1; i >= 0; i--)
	{
		decimal += (n[i] - '0') * pow(10, c);
		c++;
	}
	return decimal;
}
void checkstring(string n)
{
	if (check(n) == true)
	{
		cout << "True, " << stringtodecimal(n);
	}
	else
		cout << "False";
}
int main()
{
	string n;
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	checkstring(n);
}