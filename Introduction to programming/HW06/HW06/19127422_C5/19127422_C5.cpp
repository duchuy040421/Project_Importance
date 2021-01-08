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
void ascendingarray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	int a[100], n;
	nhapmang(a, n);
	ascendingarray(a, n);
	xuatmang(a, n);
}