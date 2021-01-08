#include<iostream>
#include<string>
using namespace std;


//1. Phone directory:
void input(string **contact,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Contact: [" << i + 1 << "]" << endl;
		getline(cin, contact[i][0]);
		getline(cin, contact[i][1]);
	}
}

void output(string **contact, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << contact[i][0] << ", " << contact[i][1] << endl;
	}
}

void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

void sort_contact(string** contact, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (contact[i][0].compare(contact[j][0]) > 0)
			{
				swap(contact[i][0], contact[j][0]);
				swap(contact[i][1], contact[j][1]);
			}
	}
}

void find_contact(string x, int n,string**contact)
{
	cout << "Enter contact do you want to find: " << endl;
	getline(cin, x);

	for(int i=0;i<n;i++)
		if (x == contact[i][0])
		{
			cout << contact[i][0] << ", " << contact[i][1] << endl;
			break;
		}
}

//2. Password and Password Encoding:

bool check_character(string n)
{
	int count = 0;

	for (int i = 0; i < n.length(); i++)
		if ((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z'))
			count++;

	if (count >= 9 && count <= 20)
		return true;

	return false;
}

bool check_lower_upper(string n)
{
	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < n.length(); i++)
	{
		if ((n[i] >= 'a' && n[i] <= 'z'))
			count1++;
		if ((n[i] >= 'A' && n[i] <= 'Z'))
			count2++;
	}

	if (count1 != 0 && count2 != 0)
		return true;

	return false;
}

bool check_num(string n)
{
	int count = 0;

	for (int i = 0; i < n.length(); i++)
		if (n[i] >= '1' && n[i] <= '9')
			count++;

	if (count >= 1)
		return true;

	return false;
}

bool check_special(string n)
{
	int count = 0;

	for (int i = 0; i < n.length(); i++)
		if ((n[i] < 'a' || n[i] > 'z') && (n[i] < 'A' || n[i] > 'Z') && (n[i] < '1' || n[i]>'9'))
			count++;

	if (count >= 1)
		return true;

	return false;
}

void verify_pass(string n)
{
	if (check_character(n) == true && check_lower_upper(n) == true && check_num(n) == true && check_special(n) == true)
		cout << "That's strong password." << endl;
	else
		cout << "That's not strong password." << endl;
}

void encrypted_pass(string& n, int k)
{
	for (int i = 0; i < n.length(); i++)
		n[i] = n[i] + k;
}
int main()
{
	int n;
	cin >> n;
	//1. Phone directory :
	string** contact = new string* [n];
	for (int i = 0; i < n; i++)
		contact[i] = new string[2];
	cin.ignore();
	input(contact, n);
	sort_contact(contact, n);
	output(contact, n);
	string x;
	find_contact(x, n, contact);
	//2. Password and Password Encoding:
	string n1;
	int k;
	do{
		cout << "Enter k to encrypted" << endl;
		cin >> k;
	} while (k < 21 || k>126);

	cin.ignore();
	cout << "Enter password: " << endl;

	getline(cin, n1);
	verify_pass(n1);
	cout << "Password after erypted: " << endl;
	encrypted_pass(n1, k);

	cout << n1;

}