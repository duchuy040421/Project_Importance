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
void separateandcount(string a[])
{
	int count[100], dem = 0, vitri=-1;
	string n;
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	for (int i = 0; i <= n.length() - 1; i++)
		if (n[i] == ' ')
			dem++;
	for (int i = 0; i < dem + 1; i++)
		count[i] = 1;
	tachtutrong1chuoi(n, a);
	for (int i = 0; i < dem; i++)
	{
		for (int j = i+1; j < dem + 1; j++)
		{
			if (a[i] == a[j])
				count[i]++;
		}
	}
	for (int i = 0; i < dem + 1; i++)
	{
		if (count[i] > 1)
		{
			vitri = i;
		}
		if (count[i] > 1)
			cout << a[i] << " " << count[i] << endl;
		if (count[i] == 1 && a[i] != a[vitri])
			cout << a[i] << " " << count[i] << endl;
	}
}
int main()
{
	string n[100];
	separateandcount(n);
}