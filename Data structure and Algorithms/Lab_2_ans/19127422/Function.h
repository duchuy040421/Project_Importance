#include<iostream>
#include<ctime>
#include<fstream>
#include<string>

using namespace std;

//Additional function
void swap(int& a, int& b);
int get_max(int* a, int n);
void show(int* a, int n);

//Generate number structure
template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);

//Sort
void BubbleSort(int* a, int n);
void InsertionSort(int* a, int n);
void SelectionSort(int* a, int n);
void Merge(int* a, int left, int right, int middle);
void MergeSort(int* a, int left, int right);
void Heapify(int* a, int n, int i);
void HeapSort(int* a, int n);
int Partition(int arr[], int low, int high);
void QuickSort(int* a, int low, int high);
void CountingSort_For_Radix(int* a, int n, int exp);
void RadixSort(int* a, int n);
void CountingSort(int a[], int n);
int BinarySearch(int a[], int key, int low, int high);
void  BinaryInsertionSort(int a[], int n);
void ShakerSort(int a[], int n);
void ShellSort(int a[], int n);

// addition support for calculate runtime
int* get_generate_type(int type, int number);
int get_data(int data);
void sort_list(int type_sort, int* a, int data, int type);
void sort();