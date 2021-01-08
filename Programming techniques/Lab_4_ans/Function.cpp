#include"Function.h"

int** generateMatrix(int n, int m)
{
	int** a = new int* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	return a;
}

void output(int** a, int n, int m)
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

int** tranposeMatrix(int** a, int n, int m)
{
	int** b = new int* [m];

	for (int i = 0; i < m; i++)
	{
		b[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[j][i];
		}
	}

	return b;
}

int** sumMatrices(int** a, int** b, int n, int m)
{
	int** c = new int* [n];

	for (int i = 0; i < n; i++)
		c[i] = new int[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	return c;
}
int sum_row(int** a, int n, int m)
{
	int sum = 0;

	for (int i = 0; i < m; i++)
	{
		sum += a[n][i];
	}
	return sum;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap_row(int** a, int m, int i, int j)
{
	for (int l = 0; l < m; l++)
	{
		swap(a[i][l], a[j][l]);
	}
}
int** rowAscendingMatrix(int** a, int n, int m)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sum_row(a, i, m) > sum_row(a, j, m))
				swap_row(a, m, i, j);
		}
	}

	return a;
}

int** removeColumn(int** a, int i, int n, int m)
{
	i = i - 1;

	for (int k = 0; k < n; k++)
	{
		for (int j = i; j < m; j++)
		{
			a[k][j] = a[k][j + 1];
		}
	}
	return a;
}