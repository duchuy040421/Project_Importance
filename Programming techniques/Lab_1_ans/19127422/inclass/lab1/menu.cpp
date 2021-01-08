#include"Function.h"

//menu all task in lab1:
void Introduction()
{
	cout << "MENU:" << endl;
	cout << "SECTION:" << endl;
	cout << "1:Condittion and Loops:" << endl;
	cout << "Function 1: Solving a quadratic equation." << endl;
	cout << "Function 2: Sum of digits of a given integer." << endl;
	cout << "Function 3: Determine if a given integer is a prime." << endl;
	cout << "Function 4: Indicate the binary form of a given integer." << endl;
	cout << "Function 5: Indicate LCM and GCD of 2 given integer." << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "2:Array:" << endl;
	cout << "Function 1: Indicate the positions of Max and Min values of the array." << endl;
	cout << "Function 2: Indicate the maximum value of sum of the absolute value of 2 elements from the array." << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "3:Matrix:" << endl;
	cout << "Function 1: Calculate the sum of 2 matrices." << endl;
	cout << "Function 2: Determine if your input matrix is a magic square." << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "4:String:" << endl;
	cout << "Function 1: Input and output a string." << endl;
	cout << "Function 2: Formalize a fullname-string." << endl;
	cout << "----------------------------------------------------------------------" << endl;
}
void menu1(int& n1)
{
	int n2;

	cout << "insert number of function do you want: " << endl;
	cin >> n2;

	switch (n2)
	{
	case 1:
		Solve_Quadratic_Equation();
		break;
	case 2:
		sum_ofdigit();
		break;
	case 3:
		define_isprime();
		break;
	case 4:
		integer_to_binary();
		break;
	case 5:
		LCM_GCD_of_twodigit();
		break;
	default:
		break;
	}
	cout << "insert Section of function do you want or insert number 5 to out: " << endl;
	cin >> n1;
}
void menu2(int& n1)
{
	int a[100], n, n2;
	cout << "Insert amount of the array: " << endl;
	cin >> n;
	Input(a, n);
	Output(a, n);

	cout << "insert number of function do you want: " << endl;
	cin >> n2;

	switch (n2)
	{
	case 1:
		Position_Max_Min(a, n);
		break;
	case 2:
		Maximun_twoValue(a, n);
		break;
	default:
		break;
	}
	cout << "insert Section of function do you want or insert number 5 to out: " << endl;
	cin >> n1;
}
void menu3(int& n1)
{
	int a[100][100], n, m, b[100][100], n2;
	cout << "Insert rows of the array: " << endl;
	cin >> m;
	cout << "Insert columns of the array: " << endl;
	cin >> n;
	Input_Matrix(a, m, n);
	Output_Matrix(a, m, n);

	cout << "insert number of function do you want: " << endl;
	cin >> n2;
	switch (n2)
	{
	case 1:
		Sum_two_Matrices(a, b);
		break;
	case 2:
		Matrix_square(a, m, n);
		break;
	default:
		break;
	}
	cout << "insert Section of function do you want or insert number 5 to out: " << endl;
	cin >> n1;
}
void menu4(int& n1)
{
	int n2;

	cout << "insert number of function do you want: " << endl;
	cin >> n2;

	cin.ignore();
	switch (n2)
	{
	case 1:
		Input_Output_String();
		break;
	case 2:
		Fomalize_Fullname();
		break;
	default:
		break;
	}
	cout << "insert Section of function do you want or insert number 5 to out: " << endl;
	cin >> n1;
}
void menu()
{
	int n1;

	Introduction();
	cout << "insert number of Section do you want: " << endl;
	cin >> n1;
	while (n1 > 0 && n1 <= 4)
	{
		switch (n1)
		{
		case 1:
		{
			menu1(n1);
			break;
		}
		case 2:
		{
			menu2(n1);
			break;
		}
		case 3:
		{
			menu3(n1);
			break;
		}
		case 4:
		{
			menu4(n1);
			break;
		}
		}
	}
}