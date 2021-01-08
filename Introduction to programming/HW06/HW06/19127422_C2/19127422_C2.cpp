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
void Findappearsalot(int a[], int n)
{
	int b[100], vitri = 0, songuyen;
	int dem = 0, Maxdem = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				dem++;
			}
		}
		if (dem > Maxdem)
		{
			Maxdem = dem;
			songuyen = a[i];
		}
		dem = 0;
	}
	dem = 0;
	b[vitri] = songuyen;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				dem++;
			}
		}
		if (dem == Maxdem&&a[i]!=songuyen)
		{
			b[vitri+1] = a[i];
			vitri++;
		}
		dem = 0;
	}
	cout << "so nguyen xuat hien nhieu nhat la: ";
	xuatmang(b, vitri+1);
	cout << endl;
	cout << "xuat hien " << Maxdem+1 << " lan";
}
int main()
{
	int a[100], n;
	nhapmang(a, n);
	Findappearsalot(a, n);
}