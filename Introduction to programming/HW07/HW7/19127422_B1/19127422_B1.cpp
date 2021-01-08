#include<iostream>
using namespace std;
void nhap1chieu(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuatmang1(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void xuatmang2(int b[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void nhap2chieu(int b[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}
}
void convert2to1(int a[], int b[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << b[i][j] << " ";
	}
}
void convert1to2(int a[], int b[][100], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		dem++;
		if (dem == sqrt(n))
		{
			dem = 0;
			cout << endl;
		}
	}
}
int main()
{
	int a[100], n1,n2, b[100][100];
	cout << "nhap phan tu mang 1 chieu " << endl;
	cin >> n1;
	nhap1chieu(a, n1);
	cout << endl;
	xuatmang1(a, n1);
	convert1to2(a, b, n1);
	cout << endl;
	cout << "nhap phan tu mang 2 chieu: " << endl;
	cin >> n2;
	nhap2chieu(b, n2);
	xuatmang2(b, n2);
	cout << endl;
	convert2to1(a, b, n2);
}