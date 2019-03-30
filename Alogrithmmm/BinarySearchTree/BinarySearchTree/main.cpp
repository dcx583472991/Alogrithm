#include<iostream>
using namespace std;

//二分查找算法
template<typename T>
int binarySearch(T arr[], int n, T target)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
			return mid;

		//在arr[l...mid-1]之中查找target
		if (target < arr[mid])
			//在arr[l...mid-1]之中查找target
			r = mid - 1;
		else
			//target>arr[mid[
			//在arr[mid+1...r]之中查找target
			l = mid + 1;
	}
	return -1;
}

int main(void)
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int v = binarySearch(a, 11, 10);
	cout << "v : " << v << endl;

	return 0;
}