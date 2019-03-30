#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "SortTestHelper.h"

using namespace std;


// heapSort1, 将所有的元素依次添加到堆中, 在将所有元素从堆中依次取出来, 即完成了排序
// 无论是创建堆的过程, 还是从堆中依次取出元素的过程, 时间复杂度均为O(nlogn)
// 整个堆排序的整体时间复杂度为O(nlogn)
template<typename T>
void heapSort1(T arr[], int n) {

	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();

}


// heapSort2, 借助我们的heapify过程创建堆
// 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
template<typename T>
void heapSort2(T arr[], int n) {

	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();

}

//原地堆排序中的shiftDown操作
template<typename T>
void __shiftDown(T arr[], int n, int k)
{
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;		//此轮循环中，arr[k] 和 arr[j] 交换位置

		if (j + 1 < n  && arr[j + 1] > arr[j])
			j++;

		if (arr[k] >= arr[j])
			break;

		swap(arr[k], arr[j]);
		k = j;
	}
}


//原地堆排序
template<typename T>
void heapSort(T arr, int n)
{
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		__shiftDown(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}




// 比较 Merge Sort, 三种 Quick Sort 和本节介绍的两种 Heap Sort 的性能效率
// 这几种排序算法都是 O(nlogn) 级别的排序算法
int main() {

	int n = 1000000;

	//测试1：一般性测试
	cout << "Test for Random Array , size=" << n << ", random range [ 0 ," << n << " ]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyArray(arr1, n);
	int *arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);

	delete[] arr1, arr2, arr3;

	cout << endl;

	//测试近乎有序的数组
	int swapTimes = 1000;
	cout << "Test for Random Nearly Ordered Array, size = " << n << " , swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyArray(arr1, n);
	arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);

	delete[] arr1, arr2, arr3;

	cout << endl;

	//测试3 测试存在包含大量相同元素的数组
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyArray(arr1, n);
	arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);


	delete[] arr1, arr2, arr3;

	cout << endl;

	return 0;
}