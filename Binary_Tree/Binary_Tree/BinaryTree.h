#pragma once
#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
public:
	BSTreeNode(const K& key)
		:_right(nullptr),_left(nullptr),_key(key)
	{	}
public:
	BSTreeNode<K>* _right;
	BSTreeNode<K>* _left;
	K _key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		Node* newnode = new Node(key);
		if (_root == nullptr)
		{
			_root = newnode;
			return true;
		}
		else
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key > key)		
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)	
				{
					parent = cur;
					cur = cur->_right;
				}
				else						
					return false;
			}			
			cur = newnode;
			if (parent->_key > key)
				parent->_left = cur;
			else if (parent->_key < key)
				parent->_right = cur;

			return true;
		}
	}
	void _InOrder(Node* root)
	{
		if (root != nullptr)
		{
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		else
		{
			return;
		}
	}
	void InOrder()
	{
		_InOrder(_root);
	}

	bool Erase(K key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				// 找到要删除的节点
				if (cur->_left == nullptr)
				{
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;

					delete cur;
				}
				else
				{
					Node* MinRight = cur->_right;
					Node* MinParent = cur;
					while (MinRight->_left)
					{
						MinParent = MinRight;
						MinRight = MinRight->_left;
					}
					cur->_key = MinRight->_key;

					MinParent->_right = MinRight->_right;
					delete MinRight;

				}
				return true;
			}
		}
		return false;
	}
private:
	Node* _root = nullptr;
};

void TestBSTree()
{
	BSTree<int> BT;
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	for (auto e : a)
	{
		BT.Insert(e);
	}
	BT.InOrder();

	cout << endl;
	BT.Erase(5);
	BT.InOrder();
}

