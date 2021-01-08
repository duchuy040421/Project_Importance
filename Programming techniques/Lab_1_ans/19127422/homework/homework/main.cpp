#include"Function.h"

int main()
{
	int n, n1;
	cout << "Insert function do you want or press number 3 to out:" << endl;
	cin >> n1;
	while (n1 == 1 || n1 == 2)
	{
		switch (n1)
		{
		case 1:
			//homework_1();
			day_after();
			day_before();
			break;
		case 2:
			//homework 2:
			homework_2();
			break;
		default:
			break;
		}
		cout << "Insert function do you want or press number 3 to out:" << endl;
		cin >> n1;
	}
}