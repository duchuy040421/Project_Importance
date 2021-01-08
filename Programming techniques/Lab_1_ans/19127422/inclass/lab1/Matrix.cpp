#include"Function.h"

void Input_Matrix(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}

void Output_Matrix(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void Sum_two_Matrices(int a[][100], int b[][100])
{
	int m, n;
	cout << "Insert row: " << endl;
	cin >> m;
	cout << "Insert column" << endl;
	cin >> n;
	cout << "Insert element to matrix 1: " << endl;
	Input_Matrix(a, m, n);
	Output_Matrix(a, m, n);
	cout << endl;
	Input_Matrix(b, m, n);
	Output_Matrix(b, m, n);
	cout << endl;
	int c[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	Input_Matrix(c, m, n);
	cout << endl;
}

void Matrix_square(int a[][100], int m, int n)
{
	int sum1 = 0, sum2 = 0, sum3 = 0, flag = 0, sum4 = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				sum1 += a[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum2 += a[i][j];
		}
		if (sum2 != sum1)
			flag = 0;
		else
			flag = 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum3 += a[j][i];
		}
		if (sum3 != sum1)
			flag = 0;
		else
			flag = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int k = m - 1;
		sum4 += a[i][k];
		k--;
	}
	if (sum4 != sum1)
		flag = 0;
	else
		flag = 1;

	if (flag == 1)
		cout << "The Matrix is a magic sqaure" << endl;
	else
		cout << "The Matrix is not a magic sqaure" << endl;
}