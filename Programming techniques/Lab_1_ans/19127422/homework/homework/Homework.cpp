#include"Function.h"

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}
int sum_of_digit(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}
void homework_2()
{
	int n, F;

	cout << "Insert n: " << endl;
	cin >> n;
	while (n < 1)
	{
		cout << "n must be >=1, please insert n again: " << endl;
		cin >> n;
	}
	n = factorial(n);
	if (n <= 9)
		F = n;
	else
		F = sum_of_digit(n);
	cout << "F(x) = " << F << endl;
}

void day_after()
{
	int day, month, year;

	cout << "Insert day: " << endl;
	cin >> day;
	cout << "Insert month: " << endl;
	cin >> month;
	cout << "Insert year: " << endl;
	cin >> year;

	if (day == 31 && month == 12)
		cout << 1 << " " << 1 << " " << ++year;
	else {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day == 31)
				cout << 1 << " " << ++month << " " << year;
			else
				cout << ++day << " " << month << " " << year;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day == 30)
				cout << 1 << " " << ++month << " " << year;
			else
				cout << ++day << " " << month << " " << year;
		}
		else {
			if (day == 28)
				cout << 1 << " " << ++month << " " << year;
			else
				cout << ++day << " " << month << " " << year;
		}
	}
	cout << endl;
}
bool check_year_leap(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return true;
	else
		return false;
}
void day_before()
{
	int day, month, year;

	cout << "Insert day: " << endl;
	cin >> day;
	cout << "Insert month: " << endl;
	cin >> month;
	cout << "Insert year: " << endl;
	cin >> year;

	if (month == 1)
	{
		if (day == 1)
			cout << "day before is: " << 31 << "/" << 12 << "/" << year - 1;
		else
			cout << "day before is: " << --day << "/" << 12 << "/" << year;
	}
	if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
	{
		if (day == 1)
			cout << "day before is: " << 31 << "/" << --month << "/" << year ;
		else
			cout << "day before is: " << --day << "/" << month << "/" << year;
	}
	if (month == 5 || month == 7 || month == 10 || month == 12)
	{
		if (day == 1)
			cout << "day before is: " << 30 << "/" << --month << "/" << year;
		else
			cout << "day before is: " << --day << "/" << month << "/" << year;
	}
	if (month == 3)
	{
		if (check_year_leap(year) == true)
		{
			if (day == 1)
				cout << "day before is: " << 29 << "/" << --month << "/" << year;
			else
				cout << "day before is: " << --day << "/" << month << "/" << year;
		}
		else
			if (day == 1)
				cout << "day before is: " << 28 << "/" << --month << "/" << year;
			else
				cout << "day before is: " << --day << "/" << month << "/" << year;
	}
	cout << endl;
}