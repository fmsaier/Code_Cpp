#pragma once
#include <iostream>

using namespace std;

template<class K, class V>
struct BSTreeNode
{
	typedef BSTreeNode<K, V>* PNode;

	PNode _left;
	PNode _right;
	K _key;
	V _value;

	BSTreeNode(K key, V value)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
		,_value(value)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;

public:
	bool Insert(const K& key, const V& value)
	{
		Node* cur = _root;
		Node* pre = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				pre = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				pre = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node{ key,value };
		if (pre == nullptr)
		{
			_root = cur;
			return true;
		}
		if (cur->_key > pre->_key)
		{
			pre->_right = cur;
		}
		else
		{
			pre->_left = cur;
		}
		return true;
	}
	Node* Find(const K& key)
	{
		if (_root == nullptr)
			return nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{

	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << ":" << root->_value << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;
};
