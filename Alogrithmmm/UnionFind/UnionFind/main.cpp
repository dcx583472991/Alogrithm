#include <iostream>
#include "UnionFindTestHelper.h"
#include"UnionFind2.h"

using namespace std;

// 测试UF1
int main() {

	
	int n = 1000000;

	// 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
	// 总体测试过程的算法复杂度是O(n^2)的
	//UnionFindTestHelper::testUF2(n);
	UnionFindTestHelper::testUF3(n);
	UnionFindTestHelper::testUF4(n);
	UnionFindTestHelper::testUF5(n);
	
	

	return 0;
}