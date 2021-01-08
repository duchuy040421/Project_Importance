#include"Tokenizer.h"

int main()
{
	int choose;
	cout << "\n\nMENU: ";
	cout << "\n1. Split the string";
	cout << "\n2. Find smallest and largest number in the string (include number and have space between two number) \n";
	cout << "\n3.";
	cout << "\n  3.1 Sum of list";
	cout << "\n  3.2 Find smalllest number in list";
	cout << "\n  3.3 Find 3 largest in list";
	cout << "\n  3.4 The average number in list";
	cout << "\n  3.5 Show number prime in list";
	cout << "\nChoose...";
	cin >> choose;

	while (choose <= 0 || choose>3) {
		cout << "Please enter number again\n";
		cin >> choose;
	}

	while (choose>=1&&choose<=3) {

		while (choose < 0 || choose>3) {
			cout << "Please enter number again\n";
			cin >> choose;
		}

		switch (choose)
		{
		case 1:
			menu_1();
			break;
		case 2:
			menu_2();
			break;
		case 3:
			menu_3();
			break;
		default:
			break;
		}

		cout << "\nChoose another number except 1 or 2 or 3 to out\n";
		cin >> choose;
		system("cls");
	} 
}