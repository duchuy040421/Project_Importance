#include"Function.h"
void InputArray(int*& a, int& n)
{

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand() % 50 + 1;
	}
}
void DellocateArray(int*& a)
{
	delete a;
	a = NULL;
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
}
int FindMin(int* a, int n)
{
	int min = *(a + 0);
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) < min)
			min = *(a + i);
	}
	return min;
}
int FindMaxModulus(int* a, int n)
{
	int max = abs(*(a + 0)), pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(*(a + i)) > max)
		{
			max = abs(*(a + i));
			pos = i;
		}
	}
	return *(a + pos);
}

bool IsAscending(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (*(a + i) > * (a + i + 1))
			return false;
	}
	return true;
}

int SumOfArray(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *(a + i);
	}
	return sum;
}

bool check_prime(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}

int CountPrime(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (check_prime(*(a + i)) == true)
			count++;
	}
	return count;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void ReverseArray(int*& a, int* b, int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(*(a + i), *(a + (n - i - 1)));
	}
	for (int i = 0; i < n; i++)
	{
		*(b + i) = *(a + i);
	}
}

int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == key)
		{
			return i;
			break;
		}
	}
	return -1;
}

int SentinelLinearSearch(int* a, int n, int key)
{
	*(a + n) = key;
	int i;

	for (i = 0; ; i++)
	{
		if (*(a + i) == key)
		{
			return i;
			break;
		}
	}

	if (i == n)
		return -1;
	else
		return i;
}

void interchange_sort(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	}
}

int BinarySearch(int* &a, int n, int key)
{
	int mid, l = 0, r = n - 1;

	while (l <= r) 
	{
		mid = (l + r) / 2;

		if (*(a + mid) == key)
			return mid;
		else 
			if (*(a + mid) > key)
				r = mid - 1;
			else                     
				l = mid + 1;
	}
	return - 1;
}

void menu(int *&a)
{
	int func, n, key;
	int* b = new int[100];
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "FUNCTION:" << endl;
	cout << "1. Input a n-element integer array with int *a is the pointer point to the allocated dynamic memory:" << endl;
	cout << "2. Remove allocated dynamic memory :" << endl;	cout << "3. Output all elements of the array:" << endl;	cout << "4. Find the smallest value from the array:" << endl;	cout << "5. Find the greatest absolute value from the array:" << endl;	cout << "6. Check if the array is ascending:" << endl;	cout << "7. Find the total value of all elements of the array:" << endl;	cout << "8. Count the number of prime numbers in the array:" << endl;	cout << "9. Create a new dynamic array which is the reverse of the given array:" << endl;	cout << "From Ex 10. to Ex 12. are Searching Algorithms. Return the first position found, else, return −1" << endl;	cout << "10. Sequential Search:" << endl;	cout << "11. Sequential Search (using flag):" << endl;	cout << "12. Binary Search:" << endl;	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "Insert Function do you want: " << endl;
	cin >> func;
	while (func > 0 && func < 13)
	{
		switch (func)
		{
		case 1:
			cout << "Insert n: " << endl;
			cin >> n;
			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << endl;
			break;
		case 2:
			DellocateArray(a);
			break;
		case 3:
			cout << "Insert n: " << endl;
			cin >> n;
			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			break;
		case 4:
			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];
			InputArray(a, n);
			PrintArray(a, n);

			cout << " the smallest value from the array: " << FindMin(a, n);
			cout << endl;

			break;
		case 5:
			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << "the greatest absolute value from the array: " << FindMaxModulus(a, n);
			cout << endl;
			break;
		case 6:
			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			if (IsAscending(a, n) == true)
				cout << " the array is ascending: " << endl;
			else
				cout << " the array is not ascending: " << endl;
			break;
		case 7:
			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << "the total value of all elements of the array: " << SumOfArray(a, n) << endl;

			break;
		case 8:
			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << "the number of prime numbers in the array: " << CountPrime(a, n) << endl;

			break;
		case 9:
			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << endl;

			ReverseArray(a, b, n);
			PrintArray(b, n);
			break;
		case 10:

			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << "Insert key:" << endl;
			cin >> key;
			cout << "the first position found: " << LinearSearch(a, n, key) << endl;
			break;
		case 11:

			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			PrintArray(a, n);

			cout << "Insert key:" << endl;
			cin >> key;
			cout << "the first position found: " << SentinelLinearSearch(a, n, key) << endl;
			break;
		case 12:

			cout << "Insert n: " << endl;
			cin >> n;

			a = new int[n];

			InputArray(a, n);
			interchange_sort(a, n);
			PrintArray(a, n);

			cout << "Insert key:" << endl;
			cin >> key;
			cout << "the first position found: " << BinarySearch(a, n, key) << endl;
			break;
		default:
			break;
		}
		cout << "Insert Function do you want or press 13 to out: " << endl;
		cin >> func;
	}
}


