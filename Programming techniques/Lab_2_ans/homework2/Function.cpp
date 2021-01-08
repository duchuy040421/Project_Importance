#include"Header.h"
void read_file(long long a[])
{
	fstream read;
	int i = 0;

	read.open("Tickets.txt", ios::in);
	while (!read.eof())
	{
		read >> a[i];
		cout << a[i];
		i++;
		cout << endl;
	}
	read.close();

	cout << endl;
}
int check(long long n, long long x)
{
	int count = 0;

	while (n > 0 && x > 0)
	{
		int r1 = n % 10, r2 = x % 10;
		n /= 10;
		x /= 10;
		if (r1 == r2)
		{
			count++;
		}
		else
			count = 0;
	}

	if (n == 0 && x == 0)
		count++;

	return count;
}
void output(long long a[])
{
	for (int i = 1; i <= a[0]; i++)
	{
		cout << a[i] << endl;
	}
	cout << endl;
}
void tickets_bought(long long a[])
{
	for (int i = 1; i <= a[0]; i++)
	{
		long long key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > a[i])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

	cout << "ALL the tickets is sorted :" << endl;

	output(a);
}
void result_lottery(long long a[])
{
	long long n, money = 0;
	int prizes = 0;

	cout << "Insert the lottery result: " << endl;
	cin >> n;

	for (int i = 1; i <= a[0]; i++)
	{
		switch (check(n,a[i]))
		{
		case 6:
			money += 500000;
			prizes++;
			break;
		case 7:
			money += 1000000;
			prizes++;
			break;
		case 8:
			money += 2000000;
			prizes++;
			break;
		case 9:
			money += 5000000;
			prizes++;
			break;
		case 10:
			money += 10000000;
			prizes++;
			break;
		default:
			break;
		}
	}

	cout << "there are " << prizes << " prizes that you won and you won " << money << " $";
}
