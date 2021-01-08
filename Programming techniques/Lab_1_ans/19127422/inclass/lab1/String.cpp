#include"Function.h"

void Input_Output_String()
{
	string n;
	cout << "Insert into String: " << endl;
	getline(cin, n);
	cout << n << endl;
}

void Lowercase_String(string& n, int l)
{
	for (int i = 0; i <= l - 1; i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
			n[i] = n[i] + 32;
	}
}
void Upcase(char& n)
{
	n = n - 32;
}
void Fomalize_Fullname()
{
	string n;

	cout << "Insert fullname into string: " << endl;
	getline(cin, n);

	int l = n.length();
	Lowercase_String(n, l);
	if (n[0] == ' ')
		n.erase(0, 1);
	if (n[l - 1] == ' ')
		n.erase(l - 1, l);
	Upcase(n[0]);
	l = n.length();
	for (int i = 1; i <= l - 1; i++)
	{
		if (n[i] == ' ')
			Upcase(n[i + 1]);
	}
	cout << n << endl;
}