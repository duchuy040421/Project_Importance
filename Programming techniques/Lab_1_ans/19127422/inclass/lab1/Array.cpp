#include"Function.h""

void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " :";
		cin >> a[i];
		cout << endl;
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Position_Max_Min(int a[], int n)
{
	int Max = a[0], Min = a[0];
	int pos1 = 0, pos2 = 0;

	for (int i = 1; i < n; i++)
	{
		if (a[i] > Max)
		{
			Max = a[i];
			pos1 = i;
		}
		else
			if (a[i] < Min)
			{
				Min = a[i];
				pos2 = i;
			}
	}
	cout << "Position of value Max: " << pos1 << endl;
	cout << "Position of value Min: " << pos2 << endl;
}

void Maximun_twoValue(int a[], int n)
{
	int Max = a[0] + a[1], pos1, pos2;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i] + a[j]) > Max)
			{
				Max = a[i] + a[j];
				pos1 = i;
				pos2 = j;
			}
		}
	}
	cout << "Two element in the array have maximum sum are: " << a[pos1] << " and " << a[pos2] << endl;
}