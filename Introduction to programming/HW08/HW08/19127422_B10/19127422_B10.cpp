#include<iostream>
#include<string>
using namespace std;
void tachtutrong1chuoi(string n, string a[])
{
	int j = 0, dem = 0;
	for (int i = 0;; i++)
	{
		dem++;
		if (n[i] == '\0')
		{
			a[j] = n.substr(0, dem - 1);
			break;
		}
		if (n[i] == ' ')
		{
			a[j] = n.substr(0, dem - 1);
			n.erase(0, dem);
			j++;
			dem = 0;
			i = -1;
		}
	}
}
void eraseword(string a[],int pos,int length)
{
	for (int i = pos; i < length; i++)
		a[i] = a[i + 1];
}
void patternstring(string a[])
{
	int dem = 0;
	string n;
	cout << "nhap chuoi:" << endl;
	getline(cin, n);
	for (int i = 0; i <= n.length() - 1; i++)
		if (n[i] == ' ')
			dem++;
	dem = dem + 1;
	tachtutrong1chuoi(n, a);
	for(int i=0;i<dem-1;i++)
		for (int j = i + 1; j < dem ; j++)
		{
			if (a[i] == a[j])
			{
				eraseword(a, j, dem );
				--dem;
				j--;
			}
		}
	for (int i = 0; i < dem ; i++)
		cout << a[i] << " ";
}
int main()
{
	string a[100];
	patternstring(a);
}