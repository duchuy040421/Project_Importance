#include<iostream>
#include<string>
using namespace std;
void daonguockytuchuoi(string n)
{
	int dem = 0;
	int l = n.length();
	for (int i = l - 1; i >= 0; i--)
	{
		dem++;
		if (n[i] == ' ')
		{
			for (int j = i + 1; j <= dem + i; j++)
			{
				cout << n[j];
			}
			cout << " ";
			dem = 0;
		}
		if (i == 0)
		{
			for (int j = 0; j <= dem; j++)
			{
				cout << n[j];
			}
		}
	}
}
int main()
{
	string n;
	cout << "nhap chuoi:" << endl;
	getline(cin, n);
	cout << "chuoi vua nhap la:" << n << endl;
	cout << "chuoi sau khi dao nguoc cac tu la:" << endl;
	daonguockytuchuoi(n);

}