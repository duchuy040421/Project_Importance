#include<iostream>
#include<string>
using namespace std;
void lowercasestring(string &n)
{
	for (int i = 0; i <= n.length() - 1; i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
			n[i] = n[i] + 32;
	}
}
void chekpangram(string n)
{
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	lowercasestring(n);
	for (int i = 0; i <= n.length() - 1; i++)
		if (n[i] == ' ')
			n.erase(i,1);
	for (int i = 0; i < n.length()-1 ; i++)
	{
		for (int j = i + 1; j < n.length() ; j++)
			if (n[i] == n[j])
				n.erase(j,1);
	}
	if (n.length() == 26)
		cout << "True";
	else
		cout << "False";

}
int main()
{
	string n;
	chekpangram(n);
}