#include<iostream>
#include"SortTestHelper.h"
#include"sort.h"
using namespace std;
using namespace Sort;

int main(void)
{
	int n = 1000000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyArray(arr, n);
	int *arr3 = SortTestHelper::copyArray(arr, n);
	int *arr4 = SortTestHelper::copyArray(arr, n);

	int *arr5 = SortTestHelper::generateNearlyOrderedArray(n, 10);
	int *arr6 = SortTestHelper::copyArray(arr4, n);
	int *arr7 = SortTestHelper::copyArray(arr4, n);
	int *arr8 = SortTestHelper::copyArray(arr4, n);


	SortTestHelper::testSort("Quick Sort ", quickSort, arr, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
	SortTestHelper::testSort("Quick Sort3", quickSort3Ways, arr3, n);
	SortTestHelper::testSort("Merge Sort ", mergeSort, arr4, n);

	cout << endl;

	SortTestHelper::testSort("Quick Sort ", quickSort, arr5, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2, arr6, n);
	SortTestHelper::testSort("Quick Sort3", quickSort3Ways, arr7, n);
	SortTestHelper::testSort("Merge Sort ", mergeSort, arr8, n);
	
	delete[] arr, arr2, arr3, arr4, arr5, arr6;

	return 0;

}