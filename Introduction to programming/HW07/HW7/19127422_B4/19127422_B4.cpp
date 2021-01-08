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
bool commonarray(int a[][100], int n1,int m1, int b[][100])
{
	for(int i=0;i<n1;i++)
		for (int j = 0; j < m1; j++)
		{
			if (a[j][i] != b[i][j])
				return false;
		}
	return true;
}
int main()
{
	int n1, m1, n2, m2, a[100][100], b[100][100];
	cout << "nhap dong 1: " << endl;
	cin >> n1;
	cout << "nhap cot 1: " << endl;
	cin >> m1;
	cout << "nhap dong 2: " << endl;
	cin >> n2;
	cout << "nhap cot 2: " << endl;
	cin >> m2;
	nhap2chieu(a, n1, m1);
	xuatmang2(a, n1, m1);
	nhap2chieu(b, n2, m2);
	xuatmang2(b, n2, m2);
	if (n1 == n2 & m1 == m2)
	{
		if (commonarray(a, n1, m1, b) == true)
			cout << "common array " << endl;
		else
			cout << "no common array" << endl;
	}
	else
		cout << "2 mang khong cung kich thuoc " << endl;

}