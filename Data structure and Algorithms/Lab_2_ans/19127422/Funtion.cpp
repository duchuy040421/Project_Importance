#include"Function.h"


//Additional function
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int get_max(int* a, int n) {
	int max = a[0];

	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	return max;
}
void show(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

//Generate number structure
template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

//Sort
void BubbleSort(int* a, int n) {
	bool swapped = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}
void InsertionSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int pos = i - 1, value = a[i];

		while (pos >= 0 && a[pos] > value) {
			a[pos + 1] = a[pos];
			pos--;
		}

		a[pos + 1] = value;
	}
}
void SelectionSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;

		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}

		swap(a[min], a[i]);
	}
}
void Merge(int* a, int left, int right, int middle) {
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int* array_1 = new int[n1], * array_2 = new int[n2];

	for (int i = 0; i < n1; i++)
		array_1[i] = a[left + i];
	for (int i = 0; i < n2; i++)
		array_2[i] = a[middle + i + 1];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (array_1[i] < array_2[j])
			a[k++] = array_1[i++];
		else
			a[k++] = array_2[j++];
	}

	while (i < n1)
		a[k++] = array_1[i++];
	while (j < n2)
		a[k++] = array_2[j++];
}
void MergeSort(int* a, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;

		MergeSort(a, left, middle);
		MergeSort(a, middle + 1, right);

		Merge(a, left, right, middle);
	}
}
void Heapify(int* a, int n, int i) {
	int left = 2 * i + 1, right = 2 * i + 2, max = i;

	if (left < n && a[left] > a[max])
		max = left;
	if (right < n && a[right] > a[max])
		max = right;

	if (max != i)
	{
		swap(a[max], a[i]);
		Heapify(a, n, max);
	}
}
void HeapSort(int* a, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--)
		Heapify(a, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		Heapify(a, i, 0);
	}
}
int Partition(int arr[], int low, int high)
{
	swap(arr[high], arr[(low + high) / 2]);
	int pivot = arr[high];
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}
void QuickSort(int* a, int low, int high) {
	if (low < high) {
		int pivot = Partition(a, low, high);

		QuickSort(a, low, pivot - 1);
		QuickSort(a, pivot + 1, high);
	}
}
void CountingSort_For_Radix(int* a, int n, int exp) {
	int c[10] = { 0 };
	int* b = new int[n];

	for (int i = 0; i < n; i++)
		c[(a[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++)
		c[i] = c[i] + c[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		b[c[(a[i] / exp) % 10] - 1] = a[i];
		c[(a[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
void RadixSort(int* a, int n) {
	int max = get_max(a, n);

	for (int exp = 1; (max / exp) > 0; exp *= 10) {
		CountingSort_For_Radix(a, n, exp);
	}
}
void CountingSort(int a[], int n) {
	int n_count = get_max(a, n) + 1;
	int* c = new int[n_count];
	int* b = new int[n];

	for (int i = 0; i < n_count; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		c[a[i]]++;
	for (int i = 1; i < n_count; i++)
		c[i] = c[i] + c[i - 1];
	for (int i = 0; i < n; i++) {
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
int BinarySearch(int a[], int key, int low, int high)
{
	if (high <= low)
		return (key > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (key == a[mid])
		return mid + 1;

	if (key > a[mid])
		return BinarySearch(a, key, mid + 1, high);
	return BinarySearch(a, key, low, mid - 1);
}
void  BinaryInsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int pos = i - 1;
		int key = a[i];
		int right_pos = BinarySearch(a, key, 0, i);

		while (pos >= right_pos) {
			a[pos + 1] = a[pos];
			pos--;
		}

		a[pos + 1] = key;
	}
}
void ShakerSort(int a[], int n) {
	int left = 0, right = n - 1, k = 0;

	while (left < right) {
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}

		right = k;

		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				k = i;
			}
		}

		left = k;

	}
}
void ShellSort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {

		for (int i = gap; i < n; i += 1) {

			int temp = a[i];
			int j;

			for (j = i; j >= gap && a[j - gap] > a[j]; j -= gap)
				a[j] = a[j - gap];

			a[j] = temp;
		}
	}
}
void FlashSort(int a[], int n) {
	int m = n / 20;
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;

	int i = 0, j = 0, k = 0;
	int anmin = a[0];
	int nmax = 1;

	for (i = 1; i < n; i++) {
		if (a[i] < anmin)
			anmin = a[i];
		else if (a[i] > a[nmax])
			nmax = i;
	}

	if (anmin == a[nmax])
		return;

	double c1 = ((double)m - 1) / (a[nmax] - anmin);

	for (i = 0; i < n; i++) {
		k = (int)(c1 * (a[i] - anmin));
		l[k]++;
	}

	for (k = 1; k < m; k++) {
		l[k] += l[k - 1];
	}

	int hold = a[nmax];
	a[nmax] = a[0];
	a[0] = hold;

	int nmove = 0;
	int flash;
	j = 0;
	k = m - 1;

	while (nmove < n - 1) {
		while (j > (l[k] - 1)) {
			j++;
			k = (int)(c1 * (a[j] - anmin));
		}

		flash = a[j];

		while (!(j == l[k])) {
			k = (int)(c1 * (flash - anmin));

			hold = a[l[k] - 1];
			a[l[k] - 1] = flash;
			flash = hold;

			l[k]--;
			nmove++;
		}
	}
}


// addition support for calculate runtime
int* get_generate_type(int type,int number) {
	int* a = new int[number];
	switch (type)
	{
	case 1:
		GenerateRandomData(a, number);
		break;
	case 2:
		GenerateSortedData(a, number);
		break;
	case 3:
		GenerateReverseData(a, number);
		break;
	case 4:
		GenerateNearlySortedData(a, number);
		break;
	default:
		break;
	}

	return a;
}
int get_data(int data) {
	int result = 0;

	switch (data)
	{
	case 1:
		result = 3000;
		break;
	case 2:
		result = 10000;
		break;
	case 3:
		result = 30000;
		break;
	case 4:
		result = 100000;
		break;
	case 5:
		result = 150000;
		break;
	case 6:
		result = 200000;
		break;
	case 7:
		result = 250000;
		break;
	case 8:
		result = 300000;
		break;
	default:
		break;
	}

	return result;
}
int* copy_array(int* b,int number) {
	int* a = new int[number];

	for (int i = 0; i < number; i++)
		a[i] = b[i];
	return a;
}
void sort_list(int type_sort,int *a,int data, int type) {
	fstream out;
	out.open("output.txt", ios::app);

	int* temp = copy_array(a, data);
	clock_t start, end;
	double duration;
	
	out << "Type: " << type << endl;
	out << "Data: " << data << endl;
	switch (type_sort) {
	case 1:
		start = clock();
		QuickSort(temp, 0, data - 1);
		temp = copy_array(a, data);
		end = clock();
		duration = double(end - start)/CLOCKS_PER_SEC;
		out << "Quick sort: " << duration << endl;
		break;
	case 2:
		start = clock();
		MergeSort(temp, 0, data - 1);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Merge sort: " << duration << endl;
		break;
	case 3:
		start = clock();
		HeapSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Heap sort: " << duration << endl;
		break;
	case 4:
		start = clock();
		CountingSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Counting sort: " << duration << endl;
		break;
	case 5:
		start = clock();
		RadixSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Radix sort: " << duration << endl;
		break;
	case 6:
		start = clock();
		InsertionSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Insertion sort: " << duration << endl;
		break;
	case 7:
		start = clock();
		BinaryInsertionSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Binary Insertion sort: " << duration << endl;
		break;
	case 8:
		start = clock();
		SelectionSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Selection sort: " << duration << endl;
		break;
	case 9:
		start = clock();
		ShellSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Shell sort: " << duration << endl;
		break;
	case 10:
		start = clock();
		ShakerSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Shaker sort: " << duration << endl;
		break;
	case 11:
		start = clock();
		BubbleSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Bubble sort: " << duration << endl;
		break;
	case 12:
		start = clock();
		FlashSort(temp, data);
		end = clock();
		temp = copy_array(a, data);
		duration = double(end - start) / CLOCKS_PER_SEC;
		out << "Flash sort: " << duration << endl;
		break;
	default:
		break;
	}

	out << "---------------------------------------------------------";
	out.close();
}

void sort() {
	int* arr, number = 0;
	for (int type = 1; type <= 4; type++) {
		for (int data = 1; data <= 8; data++) {
			number = get_data(data);
			cout << data;
			arr = get_generate_type(type, number);
			for (int i = 1; i <= 12; i++) {
				sort_list(i, arr, number, type);
			}
		}
	}
}