#include<iostream>
using namespace std;
void xuatmang2(int a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "day la ma tran " << n << "*" << m;
	cout << endl;
}
void nhap2chieu(int a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
int main()
{
	int a[100][100], n,m;
	cin >> n;
	cin >> m;
	nhap2chieu(a, n, m);
	xuatmang2(a, n, m);
}