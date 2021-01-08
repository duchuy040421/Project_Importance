#include<iostream>
#include<string>
using namespace std;

void swap_string(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

void reverse_string(string n)
{
	cout << "Insert string: " << endl;
	getline(cin, n);

	for (int i = 0; i < n.length() / 2; i++)
		swap(n[i], n[n.length() - i - 1]);

	cout << n;
}

void number_spell(int n)
{
	int so = n;
	do {
		cout << so;
		if (so < 0)
			cout<<"\n So nhap khong hop le";
	} while (so < 0);
	int soluong = 0;
	int temp = so;
	while (temp != 0)
	{
		temp = temp / 10;
		soluong = soluong + 1;
	}
	int sodao = 0;
	int temp2 = so;
	while (temp2 != 0)
	{
		sodao = sodao * 10 + temp2 % 10;
		temp2 /= 10;
	}
	int sotmp = 0;
	int slg2 = log10((double)sodao) + 1;
	int slg3 = soluong;
	while (sodao != 0)
	{

		sotmp = sodao % 10;
		if (sotmp == 1)
			cout << "\n Mot";
		else if (sotmp == 2)
			cout << " Hai";
		else if (sotmp == 3)
			cout << " Ba";
		else if (sotmp == 4)
			cout<<" Bon";
		else if (sotmp == 5)
			cout<<" Nam";
		else if (sotmp == 6)
			cout<<" Sau";
		else if (sotmp == 7)
			cout<<" Bay";
		else if (sotmp == 8)
			cout<<" Tam";
		else if (sotmp == 9)
			cout<<" Chin";
		else if (sotmp == 0)
			cout<<" Khong";
		if (soluong == 10)
			cout<<" Ty";
		else if (soluong == 9)
			cout<<" Tram";
		else if (soluong == 8)
			cout<<" Muoi";
		else if (soluong == 7)
			cout<<" Trieu";
		else if (soluong == 6)
			cout<<" Tram";
		else if (soluong == 5)
			cout<<" Muoi";
		else if (soluong == 4)
			cout<<" Nghin";
		else if (soluong == 3)
			cout<<" Tram";
		else if (soluong == 2)
			cout<<" Muoi";
		soluong--;
		sodao /= 10;
	}
	if (slg2 < slg3)
	{
		int hieu = slg3 - slg2;
		if (hieu == 8 || hieu == 7)
			cout << " Trieu";
		else if (hieu == 5 || hieu == 4)
			cout << " Nghin";
	}
}
void split_string(string n, string a[])
{
	int j = 0, dem = 0;
	for (int i = 0;; i++)
	{
		dem++;
		if (n[i] == '\0')
		{
			a[j] = n.substr(0, dem - 1);
			break;
		}
		if (n[i] == ' ')
		{
			a[j] = n.substr(0, dem - 1);
			n.erase(0, dem);
			j++;
			dem = 0;
			i = -1;
		}
	}
}

void task3(string n)
{
	int count = 0;

	cout << "Insert string: " << endl;
	getline(cin, n);

	for (int i = 0; n[i] != NULL; i++)
		if (n[i] == ' ')
			count++;

	cout << "\nThere are " << count + 1 << " word in string" << endl;

	string a[100];
	int pos = -1, count1 = 0, max = 0;
	split_string(n, a);

	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count + 1; j++)
		{
			if (a[i] == a[j])
			{
				count1++;
			}
		}

		if (count1 > max)
		{
			max = count1;
			pos = i;
		}

		count1 = 0;
	}

	if (pos == -1)
		cout << "There are no word appear in string " << endl;
	else
		cout << "The word occurences highest is: " << a[pos] << " and appears " << max + 1 << " time in string" << endl;

	count1 = 0;
	string temp = n;

	for (int i = 0; i < temp.length() - 1; i++)
	{
		for (int j = i + 1; j < temp.length(); j++)
		{
			if (temp[i] == temp[j])                                 
			{
				count1++;
				temp.erase(j, 1);
			}
		}
		if (temp[i] != ' ')
			cout << "The character " << temp[i] << " appears " << count1 + 1 << " in string" << endl;
		if (i == temp.length() - 2)
			cout << "The character " << temp[i + 1] << " appears " << count1 + 1 << " in string" << endl;
		count1 = 0;
	}
}
void task4(string str1,string str2,string str3)
{
	string temp = str1;

	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == 'f')
		{
			string temp1 = temp.substr(i, 6);

			if (temp1 == str2)
				temp.replace(i, 6, str3);
		}
	}

	cout << temp;
}
void task5(string str1, string str2)
{
	if (str1.length()<str2.length())
	{
		cout << -1;
		return;
	}

	int count1 = 0;

	string temp = str1;

	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == str2[0])
		{
			string temp1 = temp.substr(i, str2.length());

			if (temp1 == str2 && temp[i + str2.length()] != 's')
				count1++;
		}
	}

	cout << "the number of occurrences of string 2 in str1 is " << count1;
}
int main()
{
	string n;
	number_spell(12355);
	//reverse_string(n);
	//task3(n);
	//string str1, str2, str3;
	//getline(cin, str1);
	//getline(cin, str2);
	//getline(cin, str3);
	//task4(str1, str2, str3);
	//task5(str1, str2);
}