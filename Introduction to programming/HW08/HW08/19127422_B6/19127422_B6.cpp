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
void sortstring(string a[])
{
	string n;
	cout << "nhap chuoi: " << endl;
	getline(cin, n);
	tachtutrong1chuoi(n, a);
	int count[100], dem = 0;
	for (int i = 0; i <= n.length() - 1; i++)
		if (n[i] == ' ')
			dem++;
	for (int i = 0; i < dem + 1; i++)
	{
		count[i] = a[i].length() - 1;
	}
	for (int i = 0; i < dem ; i++)
	{
		for (int j = i + 1; j < dem + 1; j++)
		{
			if (count[i] < count[j])
			{
				string temp=a[i];
				a[i] = a[j];
				a[j] = temp;
				int temps = count[i];
				count[i] = count[j];
				count[j] = temps;
			}
			if (count[i] == count[j])
			{
				if (a[i].compare(a[j]) == 1)
				{
					string temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < dem + 1; i++)
		cout << a[i] << " ";
}
int main()
{
	string a[100];
	sortstring(a);
}