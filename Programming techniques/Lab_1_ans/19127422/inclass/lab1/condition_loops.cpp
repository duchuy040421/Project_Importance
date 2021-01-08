#include"Function.h"

void Solve_Quadratic_Equation()
{
	float a, b, c, delta, x1, x2;

	cout << "insert a:" << endl;
	cin >> a;
	cout << "insert b:" << endl;
	cin >> b;
	cout << "insert c:" << endl;
	cin >> c;
	delta = b * b - 4 * a * c;

	if (delta > 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else {
		if (delta == 0) {
			cout << "Roots are real and same." << endl;
			x1 = (-b + sqrt(delta)) / (2 * a);
			cout << "x1 = x2 =" << x1 << endl;
		}
		else {
			cout << "Roots are complex and different." << endl;
			cout << "x1 = " << -b / (2 * a) << "+" << sqrt(-delta) / (2 * a) << "i" << endl;
			cout << "x2 = " << -b / (2 * a) << "-" << sqrt(-delta) / (2 * a) << "i" << endl;
		}
	}
}

void sum_ofdigit()
{
	int a, sum = 0;

	cout << "insert digit: " << endl;
	cin >> a;
	while (a > 0)
	{
		sum += a % 10;
		a /= 10;
	}
	cout << "sum of digit: " << sum << endl;
}

void define_isprime()
{
	int count = 0, n;

	cout << "insert integer" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			count++;
	}
	if (count == 2)
		cout << "Number is a prime" << endl;
	else
		cout << "Number is not a prime" << endl;
}

void integer_to_binary()
{
	int n, i = 1, sum = 0;
	long r;
	
	cout << "insert integer" << endl;
	cin >> n;
	while (n > 0)
	{
		r = n % 2;
		sum += i * r;
		n /= 2;
		i *= 10;
	}
	cout << "The binary of the given number is:" << sum << endl;
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

void LCM_GCD_of_twodigit()
{
	int a, b;
	cout << "insert a:" << endl;
	cin >> a;
	cout << "insert b:" << endl;
	cin >> b;
	cout << "greatest common divisor of two number is: " << GCD(a, b) << endl;
	cout << "least common multiple of two number is: " << (a * b) / GCD(a, b) << endl;
}