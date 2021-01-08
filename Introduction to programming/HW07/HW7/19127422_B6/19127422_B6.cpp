#include<iostream>
using namespace std;
void xuatmang2(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void nhap2chieu(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}
void rotatematrix90(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j >= 0; j--)
		{
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int a[100][100], n;
	cout << "nhap n: " << endl;
	cin >> n;
	nhap2chieu(a, n);
	xuatmang2(a, n);
	rotatematrix90(a, n);
}