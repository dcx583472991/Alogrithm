#ifndef UNIONFIND2_H_
#define UNIONFIND2_H_
#include <cassert>

using namespace std;

// �ڶ���Union-Find
namespace UF2 
{

	class UnionFind 
	{

	private:
		// ���ǵĵڶ���Union-Find, ʹ��һ�����鹹��һ��ָ�򸸽ڵ����
		// parent[i]��ʾ��һ��Ԫ����ָ��ĸ��ڵ�
		int* parent;
		int count;  // ���ݸ���

	public:
		// ���캯��
		UnionFind(int count)
		{
			parent = new int[count];
			this->count = count;
			// ��ʼ��, ÿһ��parent[i]ָ���Լ�, ��ʾÿһ��Ԫ���Լ��Գ�һ������
			for (int i = 0; i < count; i++)
				parent[i] = i;
		}

		// ��������
		~UnionFind() 
		{
			delete[] parent;
		}

		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
		int find(int p) 
		{
			assert(p >= 0 && p < count);
			// ����ȥ��ѯ�Լ��ĸ��׽ڵ�, ֱ��������ڵ�
			// ���ڵ���ص�: parent[p] == p
			while (p != parent[p])
				p = parent[p];
			return p;
		}

		// �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
		// O(h)���Ӷ�, hΪ���ĸ߶�
		bool isConnected(int p, int q)
		{
			return find(p) == find(q);
		}

		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
		// O(h)���Ӷ�, hΪ���ĸ߶�
		void unionElements(int p, int q) 
		{

			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;

			parent[pRoot] = qRoot;
		}
	};
}
#endif // !UNIONFIND2_H_