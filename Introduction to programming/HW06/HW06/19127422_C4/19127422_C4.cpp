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
void thesame(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				dem++;
			}
		}
		if (dem + 1 == n)
		{
			cout << "tat ca cac phan tu deu bang nhau " << endl;
			return;
		}
		else
			return;
	}
}
void increasingarray(int a[], int n)
{
	int dem = 0, dem1 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] <= a[i+1])
		{
			dem++;
			if (a[i] < a[i + 1])
				dem1++;
		}
	}
	if (dem + 1 == n && dem1 > 0)
		cout << "tang dan tat cac phan tu cua mang" << endl;
	else
		return;
}
void decreasingarray(int a[], int n)
{
	int dem = 0, dem1 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] >= a[i + 1])
		{
			dem++;
			if (a[i] > a[i + 1])
				dem1++;
		}
	}
	if (dem + 1 == n && dem1 > 0)
		cout << "giam dan tat cac phan tu cua mang" << endl;
	else
		return;
}
void C4e(int a[], int n)                                  //cau4e
{
	int dem1=0, dem2=0;
	for (int i = 0; i < n-2; i = i + 2)
	{
		if (a[i] < a[i + 2])
		{
			dem1++;
		}
	}
	for (int i = 1; i < n - 2; i = 2*i + 1)
	{
		if (a[i] > a[i + 2])
		{
			dem2++;
		}
	}
	if (dem1 + dem2 + 2 == n)
		cout << "thoa yeu cau phan tu tai vi tri chan tang va vi tri le giam" << endl;
	else
		return;
}
void C4d(int a[], int n)                                 //cau 4d:
{
	int dem1 = 0, dem2 = 0, vitri;
	for (int i = 0;; i++)
	{
		if (a[i] < a[i + 1])
		{
			dem1++;
			vitri = i + 2;
		}
		else
			break;
	}
	for (int i = vitri; i < n; i++)
	{
		if (a[i] < a[i + 1])
			dem2++;
	}
	if (dem1 + dem2 + 2 == n)
		cout << "thoa yeu cau 2 mang con trong do mang dau tang mang sau giam:" << endl;
}
int main()
{
	int a[100], n;
	nhapmang(a, n);
	thesame(a, n);
	increasingarray(a, n);
	decreasingarray(a, n);
	C4d(a,n);
	C4e(a, n);
}