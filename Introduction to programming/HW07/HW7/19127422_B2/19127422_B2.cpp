#include<iostream>
using namespace std;
void xuatmang2(int a[][100], int n,int m)
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
void nhap2chieu(int a[][100], int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
void inphantu2duongcheo(int a[][100], int n, int m)
{
	cout << "phan tu duong cheo chinh la: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i][i]<<" ";
	cout << endl;
	cout << "phan tu duong cheo phu la: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i][n - i - 1] << " ";
	cout << endl;
}
void timphantumaxvamin(int a[][100], int n)
{
	int max = a[0][0], min = a[0][0];
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < min)
				min = a[i][j];
		}
	cout << "phan tu cuc dai cua ma tran la: " << max << endl;
	cout << "phan tu cuc tieu cua ma tran la: " << min << endl;
}
void giatritrungbinh(int a[][100], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += a[i][j];
	cout << "gia tri trung binh cua ma tran la: " << sum * 1.0 / n * n << endl;
}
int main()
{
	int n, m, a[100][100];
	cout << "nhap dong :" << endl;
	cin >> n;
	cout << "nhap cot: :" << endl;
	cin >> m;
	nhap2chieu(a, n, m);
	xuatmang2(a, n, m);
	if (n != m)
	{
		cout << "khong phai ma tran vuong" << endl;
		return 0;
	}
	else
	{
		inphantu2duongcheo(a, n, m);
		timphantumaxvamin(a, n);
		giatritrungbinh(a, n);
	}
}