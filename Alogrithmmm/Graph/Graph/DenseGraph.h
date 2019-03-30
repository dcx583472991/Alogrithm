#ifndef  DENSEGRAPH_H_
#define DENSEGRAPH_H_

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//稠密图 - 邻接矩阵
class DenseGraph
{
private:
	int n, m;		//存储图的顶点和边
	bool directed;	//表示有向图还是无向图
	vector<vector<bool>> g;

public:
	DenseGraph(int n, bool directed)
	{
		this->n = n;	//n表示图的点数
		this->m = 0;	//初始化时边数为0
		this->directed = directed;

		for (int i = 0; i < n; i++)
			//在vector数组中添加vector，每个vector中有n个元素，每个元素的初始值为false
			g.push_back(vector<bool>(n, false));	
	}

	~DenseGraph()
	{

	}

	//返回图的顶点数
	int V()
	{
		return n;
	}

	//返回图的边
	int E()
	{
		return m;
	}

	void addEdge(int v, int w)	//v,w为两个顶点之间相对应的索引
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w))
			return;

		g[v][w] = true;
		if (!directed)	//若该图是无向图，则对应在g[w][v]也要加一条边
			g[w][v] = true;
		m++;
	}

	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}


	class adjIterator
	{
	private:
		DenseGraph &G;
		int v;
		int index;

	public:
		adjIterator(DenseGraph &graph, int v) :G(graph)
		{
			this->v = v;
			this->index = -1;
		}

		int begin()
		{
			index = -1;
			return next();
		}

		int next()
		{
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])	//检查这个元素是否为true,为true直接返回索引为index的元素回去
					return index;
			return -1;
		}

		bool end()
		{
			return index >= G.V();
		}
	};
};

#endif // ! DENSEGRAPH_H_
