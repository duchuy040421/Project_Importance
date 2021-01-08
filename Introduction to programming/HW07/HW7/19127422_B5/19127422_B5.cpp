#include<iostream>
using namespace std;
void xuatmang2(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void inmang(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				a[i][j] = 0;
			if (j > i)
				a[i][j] = 1;
			if (j < i)
				a[i][j] = -1;
		}
	}
	xuatmang2(a, n);
}
int main()
{
	int a[100][100],n;
	cout << "nhap so luong cua ma tran: " << endl;
	cin >> n;
	inmang(a, n);
}