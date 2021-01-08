#include<iostream>
#include<string>
using namespace std;
void rightstring(string n)
{
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	for (int i = 0; i <= n.length() - 1; i++)
	{
		if (n[i] == ' ' && n[i + 1] == ' ')
		{
			for (int j = i + 1; n[j] == ' '; j++)
				n.erase(j,1);
		}
	}
	cout << n; 
}
int main()
{
	string n;
	rightstring(n);
}