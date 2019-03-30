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

		//���ƹ��캯��
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

	//���������������㷨
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


	//ǰ�����
	void preOrder() 
	{
		preOrder(root);
	}


	//�������
	void inOrder()
	{
		inOrder(root);
	}


	//�������
	void postOrder()
	{
		postOrder(root);
	}


	//�����������������
	void levelOrder()
	{
		queue<Node*> q;
		q.push(root);

		//����Ϊ�յ�ʱ��ѭ���Ž���
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


	//Ѱ����С�ļ�ֵ
	Key minimum()
	{
		assert(count != 0);

		Node *minNode = minium(root);
		return minNode->key;
	}

	//Ѱ�����ļ�ֵ
	Key maximum() 
	{
		assert(count != 0);
		Node *maxNode = maximun(root);
		return maxNode->key;
	}

	//�Ӷ�������ɾ����Сֵ���ڵĽڵ�
	void removeMin()
	{
		if (root)
		{
			root = removeMin(root);
		}
	}


	//�Ӷ�������ɾ�����ֵ���ڵĽڵ�
	void removeMax()
	{
		if (root)
		{
			root = removeMax(root);
		}
	}


	//�Ӷ�������ɾ����ֵΪkey�Ľڵ�
	void remove(Key key)
	{
		root = remove(root, key);
	}

private:

	//����nodeΪ���Ķ����������У�����ڵ�(key,value)
	//���ز����½ڵ��Ķ����������ĸ�
	Node* insert(Node *node, Key, Value value)
	{
		//�ݹ鵽�׵Ĵ���
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}

		if��key == node->key)
			node->value = value;
		else if (key == node->key)
			node->left = insert(node->left, key, value);
		else 
			node->right = inser(node->right, key, value);
	}

	//�鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�
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

	//ǰ�����
	void preOrder(Node *node)
	{
		if (node != NULL) 
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}


	//�������
	void inOrder(Nodde *node)
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	//�������
	void postOrder(Node *node)
	{
		if (node != NULL)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	//�����������ú�����������ڵ�
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


	//��node Ϊ���Ķ����������У�������С��ֵ�Ľڵ�
	Node *minium(Node *node)
	{
		if (node->left == NULL)
			return node;

		return minimum��node->left);
	}

	//��nodeΪ���Ķ����������У���������ֵ�Ľڵ�
	Node *maximum(Node *node)
	{
		if (node->right == NULL)
			return node;

		return maximum(node->right);
	}


	//ɾ������nodeΪ���Ķ����������е���С�ڵ�
	//����ɾ���ڵ���µĶ����������ĸ�
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


	//ɾ������nodeΪ���Ķ����������е����ڵ�
	//����ɾ���ڵ���µĶ����������ĸ�
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


	//ɾ����nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�
	//����ɾ���ڵ���µĶ����������ĸ�
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