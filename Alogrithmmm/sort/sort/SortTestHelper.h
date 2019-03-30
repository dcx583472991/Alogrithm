#ifndef SORTTSTHELPER_H_
#define SORTTSTHELPER_H_


#include<iostream>
#include<ctime>
#include<cassert>
#include<string>
//#include"sort.h"
using namespace std;

namespace SortTestHelper
{
	//生成有n个元素的随机数组，每个元素的随机范围为[rangL,rangR]
	int* generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

		return arr;
	}

	//打印数组
	template <typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	//测试排序算法的时间
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {

		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

		return;
	}


	//验证数组是否有序
	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}


	//复制数组
	template<typename T>
	T * copyArray(T a[], int n)
	{
		T *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

	//生成近乎有序的数组
	int *generateNearlyOrderedArray(int n,int swapTimes)
	{
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;
		srand(time(NULL));
		for (int i=0; i < swapTimes; i++)
		{
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}




}

#endif SORTTSTHELPER_H_