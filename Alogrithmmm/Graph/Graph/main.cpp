#include<iostream>
#include<vector>
#include<ctime>
#include"SparseGraph.h"
#include"DenseGraph.h"
#include"ReadGraph.h"
#include"Component.h"
#include"Path.h"

using namespace std;

int main(void)
{
	/*vector<int> arr({ 1,2,3,4,5 });
	vector<int>::iterator iter;
	for (iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << endl;*/

	//int N = 20;		//20个结点
	//int M = 100;	//100条边

	//srand(time(NULL));

	//SparseGraph g1(N, false);
	//for (int i = 0; i < M; i++)
	//{
	//	int a = rand() % N;
	//	int b = rand() % N;
	//	g1.addEdge(a, b);
	//}

	////O(E)复杂度
	//for (int v = 0; v < N; v++)
	//{
	//	cout << v << " :  ";
	//	SparseGraph::adjIterator adj(g1, v);
	//	for (int w = adj.begin(); !adj.end(); w = adj.next())
	//		cout << w << " ";
	//	cout << endl;
	//}
	//cout << endl;


	//DenseGraph g2(N, false);
	//for (int i = 0; i < M; i++) {
	//	int a = rand() % N;
	//	int b = rand() % N;
	//	g2.addEdge(a, b);
	//}

	//// O(V^2)
	//for (int v = 0; v < N; v++) {
	//	cout << v << " : ";
	//	DenseGraph::adjIterator adj(g2, v);
	//	for (int w = adj.begin(); !adj.end(); w = adj.next())
	//		cout << w << " ";
	//	cout << endl;
	//}


	// TestG1.txt - g1 and g2
	//string filename1 = "testG1.txt";
	//SparseGraph g1 = SparseGraph(13, false);
	//ReadGraph<SparseGraph> readGraph1(g1, filename1);
	//Component<SparseGraph> component1(g1);
	//cout << "TestG1.txt, Using Sparse Graph, Component Count: " << component1.count() << endl;

	//DenseGraph g2 = DenseGraph(13, false);
	//ReadGraph<DenseGraph> readGraph2(g2, filename1);
	//Component<DenseGraph> component2(g2);
	//cout << "TestG1.txt, Using Dense Graph, Component Count: " << component2.count() << endl;

	//cout << endl;

	//// TestG2.txt - g3 and g4
	//string filename2 = "testG2.txt";
	//SparseGraph g3 = SparseGraph(7, false);
	//ReadGraph<SparseGraph> readGraph3(g3, filename2);
	//Component<SparseGraph> component3(g3);
	//cout << "TestG2.txt, Using Sparse Graph, Component Count: " << component3.count() << endl;

	//DenseGraph g4 = DenseGraph(7, false);
	//ReadGraph<DenseGraph> readGraph4(g4, filename2);
	//Component<DenseGraph> component4(g4);
	//cout << "TestG2.txt, Using Dense Graph, Component Count: " << component4.count() << endl;

	string filename = "testG.txt";
	SparseGraph g = SparseGraph(7, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.show();
	cout << endl;

	Path<SparseGraph> path(g, 0);
	cout << "Path from 0 to 6 : " << endl;
	path.showPath(6);


	return 0;

}