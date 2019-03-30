#ifndef BST_H_
#define BST_H_
#include<iostream>
#include<queue>
#include<cassert>
using namespace std;

template<typename Key, typename Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

		//复制构造函数
		Node(Node *node)
		{
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};

	Node *root;
	int count;

public:
	BST() 
	{
		roo = NULL;
		count = 0;
	}

	~BST() 
	{
		destory(root);
	}

	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	//二分搜索树插入算法
	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}


	bool contain(Key key)
	{
		return contain(root, key);
	}

	Value* search(Key key)
	{
		return search(root, key);
	}


	//前序遍历
	void preOrder() 
	{
		preOrder(root);
	}


	//中序遍历
	void inOrder()
	{
		inOrder(root);
	}


	//后序遍历
	void postOrder()
	{
		postOrder(root);
	}


	//二分搜索树层序遍历
	void levelOrder()
	{
		queue<Node*> q;
		q.push(root);

		//队列为空的时候循环才结束
		while (!q, empty())
		{
			Node *node = q.front();
			q.pop();

			cout << node->key << endl;

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->rigth);
			
		}
	}


	//寻找最小的键值
	Key minimum()
	{
		assert(count != 0);

		Node *minNode = minium(root);
		return minNode->key;
	}

	//寻找最大的键值
	Key maximum() 
	{
		assert(count != 0);
		Node *maxNode = maximun(root);
		return maxNode->key;
	}

	//从二叉树中删除最小值所在的节点
	void removeMin()
	{
		if (root)
		{
			root = removeMin(root);
		}
	}


	//从二叉树中删除最大值所在的节点
	void removeMax()
	{
		if (root)
		{
			root = removeMax(root);
		}
	}


	//从二叉树中删除键值为key的节点
	void remove(Key key)
	{
		root = remove(root, key);
	}

private:

	//向以node为根的二叉搜索树中，插入节点(key,value)
	//返回插入新节点后的二叉搜索树的根
	Node* insert(Node *node, Key, Value value)
	{
		//递归到底的处理
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}

		if（key == node->key)
			node->value = value;
		else if (key == node->key)
			node->left = insert(node->left, key, value);
		else 
			node->right = inser(node->right, key, value);
	}

	//查看以node为根的二叉搜索数中是否包含键值为key的节点
	bool contain(Node* node, Key key)
	{
		if (node == NULL)
			return false;

		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->lefy, key);
		else
			//key > node->key
			retun contain(node->right, key);
	}


	Value *serach(Node* node, Key key)
	{
		if (node == NULL)
			return NULL;

		if (key == node->key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	//前序遍历
	void preOrder(Node *node)
	{
		if (node != NULL) 
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}


	//中序遍历
	void inOrder(Nodde *node)
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	//后序遍历
	void postOrder(Node *node)
	{
		if (node != NULL)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	//析构函数调用后序遍历各个节点
	void destory()
	{
		if (node != NULL)
		{
			destory(node->left);
			destory(node->right);

			delete node;
			count--;
		}
	}


	//以node 为根的二叉搜索树中，返回最小键值的节点
	Node *minium(Node *node)
	{
		if (node->left == NULL)
			return node;

		return minimum（node->left);
	}

	//以node为根的二叉搜索树中，返回最大键值的节点
	Node *maximum(Node *node)
	{
		if (node->right == NULL)
			return node;

		return maximum(node->right);
	}


	//删除掉以node为根的二分搜索树中的最小节点
	//返回删除节点后新的二分搜索树的根
	Node *removeMin(Node *node)
	{
		if (node->left == NULL)
		{
			Node *rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}


	//删除掉以node为根的二分搜索树中的最大节点
	//返回删除节点后新的二分搜索树的根
	Node *removeMax(Node *node)
	{
		if (node->right == null)
		{
			Node *leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		node->right = removeMax(node->right);
		return node;

	}


	//删除以node为根的二分搜索树中键值为key的节点
	//返回删除节点后新的二分搜索树的根
	Node *remove(Node*, Key key)
	{
		if (node == NULL)
			return NULL;
		if (key < node->key)
		{
			node->left = remove(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = remove(node->right, key);
			return node;
		}
		else 
		{	//key==node->key
			if (node->left == NULL)
			{
				Node *rightNode = node->right;
				delete node;
				count--;
				return rightNode
			}
			
			if (node->right == NULL)
			{
				Node *leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}

			//node->left != NULL && node->right != NULL
			Node *delNode = node;
			Node *successor = new Node(minimum(node->right));
			count++;
			successor->right = removeMin(node->right);
			successor->left = node->left;
			delete delNode;
			cout--;
			return successor;
		}
	}

};


#endif // !BST_H_
