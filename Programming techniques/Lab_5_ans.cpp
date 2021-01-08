#include<iostream>
#include<ctime>
using namespace std;

int** input_matrix_1(int** a, int n, int m)
{
	srand(time(0));
	int** b = new int* [n];

	for (int i = 0; i < n; i++)
		b[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			b[i][j] = rand() % 99;
		}
	return b;
}
void output_matrix(int** a, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int check_num_center(int i, int j, int n, int m)
{
	int count = 0;
	int pos1 = i, pos2 = i, pos3 = j, pos4 = j;

	if (pos1 > 0 && pos2 < n - 1 && pos3 > 0 && pos4 < m - 1)
	{
		while (pos1 > 0 && pos2 < n - 1 && pos3 > 0 && pos4 < m - 1)
		{
			pos1--, pos2++, pos3--, pos4++;
			count++;
		}
	}
	return count * 2 + 1;
}
void check_maxtrix(int** a, int n, int m, int p)
{
	int flag = 0, max = 0, dong, cot;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == p)
			{
				if (check_num_center(i, j, n, m) > max)
				{
					max = check_num_center(i, j, n, m);
					dong = i - ((max - 1) / 2);
					cot = j - ((max - 1) / 2);
				}
				flag = 1;
			}
		}

	if (flag == 0 || max == 1)
	{
		cout << -1;
		return;
	}

	for (int i = dong; i < max + dong; i++)
	{
		for (int j = cot; j < max + cot; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

int main()
{
	int n, m, ** a, p;
	cin >> n >> m >> p;
	a = new int* [n];

	a = input_matrix_1(a, n, m);
	output_matrix(a, n, m);
	check_maxtrix(a, n, m, p);

}