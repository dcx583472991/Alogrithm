#ifndef SORT_H_
#define SORT_H_
#include<iostream>
using namespace std;

namespace Sort {
	//选择排序算法
	template<typename T>
	void selectionSort(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] < arr[minIndex])
					minIndex = j;
			}
			swap(arr[i], arr[minIndex]);
		}
	}


	//插入排序算法1
	template<typename T>
	void insertSort(T arr[], int n) 
	{
		for (int i = 1; i < n; i++)
		{
			T e = arr[i];
			int j;
			for (j = i; j > 0 && arr[j - 1] > e; j--)
				arr[j] = arr[j - 1];
			arr[j] = e;
		}
	}


	//插入排序算法2
	//对arr[l..r]范围的数组进行插入排序
	template<typename T>
	void insertSort2(T arr[], int l, int r)
	{
		for (int i = l + 1; i <= r; i++)
		{
			T e = arr[i];
			int j;
			for (j = i; j > l && arr[j - 1] > e; j--)
				arr[j] = arr[j - 1];
			arr[j] = e;
		}
		//因为要被调用，所以需要返回调用函数
		return;
	}


	//归并排序
	template<typename T>
	void mergeSort(T arr[], int n)
	{
		__mergeSort(arr, 0, n - 1);
	}

	//递归使用规避给排序，对[l...r]的范围进行排序
	template<typename T>
	void __mergeSort(T arr[], int l, int r)
	{
		/*if (l >= r)
			return;*/

		if (r - l <= 15)
		{
			insertSort2(arr, l, r);
			return;
		}

		int mid = (l + r) / 2;
		__mergeSort(arr, l, mid);
		__mergeSort(arr, mid + 1, r);
		if (arr[mid] > arr[mid + 1])	//优化归并排序算法
			__merge(arr, l, mid, r);
	}

	//将arr[l...mid]和arr[mid+1...r]两部分进行归并
	template<typename T>
	void __merge(T arr[], int l, int mid, int r)
	{
		//VS不支持动态长度数组, 不能使用 T aux[r-l+1]的方式申请aux的空间
		T *aux = new T[r - l + 1];

		for (int i = l; i <= r; i++)
			aux[i - l] = arr[i];
		int i = l, j = mid + 1;
		for (int k = l; k <= r; k++)
		{
			if (i > mid)
			{
				arr[k] = aux[j - l];
				j++;
			}
			else if(j > r)
			{
				arr[k] = aux[i - l];
				i++;
			}
			else if (aux[i - l] < aux[j - l])
			{
				arr[k] = aux[i - l];
				i++;
			}
			else 
			{
				arr[k] = aux[j - l];
				j++;
			}
		}
		delete[] aux;
	}



	//随机快速排序
	template <typename T>
	void quickSort(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort(arr, 0, n - 1);
	}


	// 对arr[l...r]部分进行快速排序
	template <typename T>
	void __quickSort(T arr[], int l, int r)
	{
		/*if (l >= r)
		return;*/

		if (r - l <= 15) {
			insertSort2(arr, l, r);
			return;
		}

		int p = __partition(arr, l, r);
		__quickSort(arr, l, p - 1);
		__quickSort(arr, p + 1, r);
	}


	template <typename T>
	int __partition(T arr[], int l, int r) 
	{
		swap(arr[l], arr[rand() % (r - l + 1) + l]);

		T v = arr[l];

		// arr[l+1...j] < v ; arr[j+1...i) > v
		int j = l; 
		for (int i = l + 1; i <= r; i++)
			if (arr[i] < v) {
				j++;
				swap(arr[j], arr[i]);
			}

		swap(arr[l], arr[j]);

		return j;
	}


	//双路快速排序
	template <typename T>
	void quickSort2(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort2(arr, 0, n - 1);
	}


	// 对arr[l...r]部分进行快速排序
	template <typename T>
	void __quickSort2(T arr[], int l, int r)
	{
		/*if (l >= r)
		return;*/

		if (r - l <= 15) {
			insertSort2(arr, l, r);
			return;
		}

		int p = __partition2(arr, l, r);
		__quickSort2(arr, l, p - 1);
		__quickSort2(arr, p + 1, r);
	}


	//双路随机快速排序的partition方法
	template <typename T>
	int __partition2(T arr[], int l, int r)
	{
		swap(arr[l], arr[rand() % (r - l + 1) + l]);
		T v = arr[l];

		//arr[l+1...i)<=v 且 arr(j...r}>=v
		int i = l + 1, j = r;
		while (true) 
		{
			while (i <= r && arr[i] < v)
				i++;
			while (j >= l + 1 && arr[j] > v)
				j--;
			if (i > j)
				break;
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		swap(arr[l], arr[j]);

		return j;
	}



	//三路随机快速排序
	template <typename T>
	void quickSort3Ways(T arr[], int n) {

		srand(time(NULL));
		__quickSort3Ways(arr, 0, n - 1);
	}


	//三路快速排序处理arr[l...r]
	//将arr[l...r]分为 < v , == v , > v 三部分
	//递归对 < v , > v 两部分进行三鹿快速排序
	template <typename T>
	void __quickSort3Ways(T arr[], int l, int r) {

		// 对于小规模数组, 使用插入排序进行优化
		if (r - l <= 15) {
			insertSort2(arr, l, r);
			return;
		}

		// 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
		swap(arr[l], arr[rand() % (r - l + 1) + l]);

		T v = arr[l];

		int lt = l;     // arr[l+1...lt] < v
		int gt = r + 1; // arr[gt...r] > v
		int i = l + 1;    // arr[lt+1...i) == v
		while (i < gt) {
			if (arr[i] < v) {
				swap(arr[i], arr[lt + 1]);
				i++;
				lt++;
			}
			else if (arr[i] > v) {
				swap(arr[i], arr[gt - 1]);
				gt--;
			}
			else { // arr[i] == v
				i++;
			}
		}

		swap(arr[l], arr[lt]);

		__quickSort3Ways(arr, l, lt - 1);
		__quickSort3Ways(arr, gt, r);
	}

}


#endif SORT_H_