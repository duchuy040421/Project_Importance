#include<iostream>
#include<string>
using namespace std;
bool checkpalindrome(string n)
{
	for (int i = 0; i < (n.length() - 1) / 2; i++)
	{
		if (n[i] != n[n.length() - 1 - i])
			return false;
	}
	return true;
}
void palindrome(string n)
{
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	for (int i = 0; i <= n.length() - 1; i++)
		if (n[i] == ' ')
			n.erase(i, 1);
	if (checkpalindrome(n) == true)
		cout << "True";
	else
		cout << "False";
}
int main()
{
	string n;
	palindrome(n);
}