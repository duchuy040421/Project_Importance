#include<iostream>
using namespace std;
void inFunc(int a[])
{
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
}
int FindMax(int a[])
{
	int Max = a[0];
	for (int i = 1; i < 9; i++)
	{
		if (a[i] > Max)
			Max = a[i];
	}	
	return Max;
}
int FindMin(int a[])
{
	int Min = a[0];
	for (int i = 1; i < 9; i++)
	{
		if (a[i] < Min)
			Min = a[i];
	}
	return Min;
}
int main()
{
	int a[100];
	inFunc(a);
	cout << FindMax(a) << endl;
	cout << FindMin(a) << endl;
}