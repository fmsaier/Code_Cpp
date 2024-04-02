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
		Node* pre = nullptr;
		Node* cur = _root;
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
				//找到了

				//左边为空 给父亲
				if (!cur->_left)
				{
					//根的特殊情况
					if (pre == nullptr)
					{
						_root = cur->_right;
						delete(cur);
						return true;
					}
					//cur是p的左
					if (cur == pre->_left)
					{
						pre->_left = cur->_right;
					}
					else
					{
						pre->_right = cur->_right;
					}
					delete(cur);
					return true;
				}
				//右为空
				else if (!cur->_right)
				{
					//根的特殊情况
					if (pre == nullptr)
					{
						_root = cur->_left;
						delete(cur);
						return true;
					}
					//cur是p的左
					if (cur == pre->_left)
					{
						pre->_left = cur->_left;
					}
					else
					{
						pre->_right = cur->_left;
					}
					delete(cur);
					return true;
				}
				//左右都不为空
				else
				{
					Node* minRight = cur->_right;
					Node* minPreRight = cur;
					while (minRight->_left)
					{
						minPreRight = minRight;
						minRight = minRight->_left;
					}
					cur->_key = minRight->_key;
					cur->_value = minRight->_value;
					if (minRight = minPreRight->_left)
					{
						minPreRight->_left = minRight->_right;
					}
					else
					{
						minPreRight->_right = minRight->_right;
					}
					delete minRight;
					return true;
				}
			}
		}
		//没找到
		return false;
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
