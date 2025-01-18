#pragma once
#include <iostream>

using namespace std;

template<class T>
struct AVLNode
{
	typedef struct AVLNode<T>* pNode;

	AVLNode(const T& data = T())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		//右减左
		,_bf(0)
	{}

	pNode _left;
	pNode _right;
	pNode _parent;
	T _data;
	int _bf;
};

template<class T>
class AVLTree
{
	typedef struct AVLNode<T>* pNode;
	typedef struct AVLNode<T> Node;

public:
	AVLTree()
		:_root(nullptr)
	{ }

	bool Insert(const T& data)
	{
		pNode pre = nullptr;
		pNode cur = _root;
		while (cur)
		{
			if (data < cur->_data)
			{
				pre = cur;
				cur = cur->_left;
			}
			else if (data > cur->_data)
			{
				pre = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(data);
		if (pre == nullptr)
		{
			_root = cur;
			return true;
		}
		if (cur->_data < pre->_data)
		{
			pre->_left = cur;
			cur->_parent = pre;
		}
		else
		{
			pre->_right = cur;
			cur->_parent = pre;
		}
		while (cur != _root)
		{
			if (cur == pre->_left)
				pre->_bf--;
			if (cur == pre->_right)
				pre->_bf++;

			if (pre->_bf == 0)
				return true;
			else if (pre->_bf == 2 || pre->_bf == -2)
			{
				//旋转
				if (pre->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						//左旋

						//是根的特殊情况
						if (pre == _root)
							_root = pre->_right;
						
						RotateL(pre);
					}
					else if (cur->_bf == -1)
					{
						//右左旋
						if (pre == _root)
							_root = pre->_right->_left;

						RotateRL(pre);
					}
				}
				else if (pre->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//右旋
						if (pre == _root)
							_root = pre->_left;

						RotateR(pre);
					}
					else if (cur->_bf == 1)
					{
						//左右旋
						if (pre == _root)
							_root = pre->_left->_right;

						RotateLR(pre);
					}
				}
				return true;
			}

			cur = pre;
			pre = pre->_parent;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	// 右单旋
	void RotateR(pNode parent)
	{
		pNode childL = parent->_left;
		pNode childLR = childL->_right;
		childL->_right = parent;
		parent->_left = childLR;
		childL->_parent = parent->_parent;
		//根是空
		if (parent->_parent)
		{
			if (parent == parent->_parent->_left)
				parent->_parent->_left = childL;
			else
				parent->_parent->_right = childL;
		}
		parent->_parent = childL;
		//childLR为空
		if (childLR)
			childLR->_parent = parent;

		parent->_bf = 0;
		childL->_bf = 0;
	}
	// 左单旋
	void RotateL(pNode parent)
	{
		pNode childR = parent->_right;
		pNode childRL = childR->_left;
		childR->_left = parent;
		parent->_right = childRL;
		childR->_parent = parent->_parent;

		//根是空
		if (parent->_parent)
		{
			if (parent == parent->_parent->_left)
				parent->_parent->_left = childR;
			else
				parent->_parent->_right = childR;
		}
		parent->_parent = childR;
		//childRL是空
		if (childRL)
			childRL->_parent = parent;
		parent->_bf = 0;
		childR->_bf = 0;
	}
	// 右左双旋
	void RotateRL(pNode parent)
	{
		pNode childR = parent->_right;
		pNode childRL = childR->_left;
		int bf = childRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		//childRL下面没东西
		if (bf == 0)
		{
			parent->_bf = 0;
			childR->_bf = 0;
			childRL->_bf = 0;
		}
		//childRL右下插入
		else if (bf == 1)
		{
			parent->_bf = -1;
			childR->_bf = 0;
			childRL->_bf = 0;
		}
		//childRL左下插入
		else if (bf == -1)
		{
			parent->_bf = 0;
			childR->_bf = 1;
			childRL->_bf = 0;
		}
	}
	// 左右双旋
	void RotateLR(pNode parent)
	{
		Node* childL = parent->_left;
		Node* childLR = childL->_right;
		int bf = childLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		//childLR下面没东西
		if (bf == 0)
		{
			parent->_bf = 0;
			childL->_bf = 0;
			childLR->_bf = 0;
		}
		//childLR右下插入
		else if (bf == 1)
		{
			parent->_bf = 0;
			childL->_bf = -1;
			childLR->_bf = 0;
		}
		//childLR左下插入
		else if (bf == -1)
		{
			parent->_bf = 1;
			childL->_bf = 0;
			childLR->_bf = 0;
		}
	}

	void _InOrder(const pNode& root)
	{
		if (!root) return;
		_InOrder(root->_left);
		cout << root->_data << endl;
		_InOrder(root->_right);
	}

	pNode _root;
};