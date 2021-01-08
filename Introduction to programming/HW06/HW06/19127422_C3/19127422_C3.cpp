#include<iostream>
using namespace std;
void nhapmang(int a[], int& n)
{
	cout << "nhap n " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a " << i << endl;
		cin >> a[i];
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
void chenvaomang(int a[], int &n, int &x, int &pos)
{
	cout << "nhap so can chen " << endl;
	cin >> x;
	cout << "chen vao vi tri nao " << endl;
	cin >> pos;
	for (int i = n - 1; i >= pos; i--)
	{
		a[i + 1] = a[i];
	}
	++n;
	a[pos] = x;
}
int main()
{
	int a[100], n, x, pos;
	nhapmang(a, n);
	chenvaomang(a, n, x, pos);
	xuatmang(a, n);
}