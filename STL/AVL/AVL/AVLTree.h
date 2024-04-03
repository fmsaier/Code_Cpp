#pragma once
#include <iostream>
#include <assert.h>
using namespace std;


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		//右减左
		, _bf(0)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		Node* cur = _pRoot;
		Node* pre = nullptr;
		//有了就返回
		while (cur)
		{
			if (cur->_data < data)
			{
				pre = cur;
				cur = cur->_pRight;
			}
			else if (cur->_data > data)
			{
				pre = cur;
				cur = cur->_pLeft;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(data);
		//根
		if (pre == nullptr)
		{
			_pRoot = cur;
			return true;
		}
		//正常插入
		if (cur->_data > pre->_data)
		{
			pre->_pRight = cur;
			cur->_pParent = pre;
		}
		else
		{
			pre->_pLeft = cur;
			cur->_pParent = pre;
		}
		while (cur != _pRoot)
		{
			//bf调整
			if (cur == pre->_pLeft)
				pre->_bf--;
			if (cur == pre->_pRight)
				pre->_bf++;
			//bf == 0
			//跳出
			if (pre->_bf == 0)
				break;
			//bf == 1 /-1
			//向上调整
			else if (pre->_bf == 1 || pre->_bf == -1)
			{
				cur = pre;
				pre = pre->_pParent;
			}
			//bf == 2 /-2
			//旋转
			else if (pre->_bf == 2 || pre->_bf == -2)
			{
				if (pre->_bf == 2)
				{
					//左旋
					if (cur->_bf == 1)
					{
						//带着根旋转需要改一下根
						if (pre == _pRoot)
						{
							_pRoot = pre->_pRight;
						}
						RotateL(pre);
					}
					//右左双旋
					else if(cur->_bf == -1)
					{
						if (pre == _pRoot)
						{
							_pRoot = pre->_pRight->_pLeft;
						}
						RotateRL(pre);
					}
				}
				else if (pre->_bf == -2)
				{
					//右旋
					if (cur->_bf == -1)
					{
						if (pre == _pRoot)
						{
							_pRoot = pre->_pLeft;
						}
						RotateR(pre);
					}
					//左右双旋
					else if (cur->_bf == 1)
					{
						if (pre == _pRoot)
						{
							_pRoot = pre->_pLeft->_pRight;
						}
						RotateLR(pre);
					}
				}
				break;
			}
			else
			{
				int a;
				cin >> a;
				//assert(false);
			}
		}
		return true;
	}

	// AVL树的验证
	bool IsAVLTree()
	{
		size_t height = 0;
		return _IsAVLTree(_pRoot, height);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_pLeft);
		cout << root->_data << ":" << root->_bf << endl;
		_InOrder(root->_pRight);
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot, size_t& height)
	{
		if (pRoot == nullptr)
		{
			height = 0;
			return true;
		}
		size_t leftHeight = 0;
		size_t rightHeight = 0;
		if (!_IsAVLTree(pRoot->_pLeft, leftHeight) ||
			!_IsAVLTree(pRoot->_pRight, rightHeight))
		{
			cout << "左右子树不平衡" << endl;
			return false;
		}
		height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		if (rightHeight - leftHeight == pRoot->_bf)
			return true;
		if (abs((int)rightHeight - (int)leftHeight) > 2)
		{
			cout << "不平衡" << endl;
			return false;
		}
		return false;
	}
	size_t _Height(Node* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	// 右单旋
	void RotateR(Node* pParent)
	{
		Node* childL = pParent->_pLeft;
		Node* childLR = childL->_pRight;
		pParent->_pLeft = childLR;
		childL->_pRight = pParent;
		childL->_pParent = pParent->_pParent;
		//根为空
		if (pParent->_pParent)
		{
			if (pParent == pParent->_pParent->_pLeft)
				pParent->_pParent->_pLeft = childL;
			if (pParent == pParent->_pParent->_pRight)
				pParent->_pParent->_pRight = childL;
		}
		pParent->_pParent = childL;
		//childLR为空
		if (childLR)
			childLR->_pParent = pParent;
		pParent->_bf = 0;
		childL->_bf = 0;
	}
	// 左单旋
	void RotateL(Node* pParent)
	{
		Node* childR = pParent->_pRight;
		Node* childRL = childR->_pLeft;
		pParent->_pRight = childRL;
		childR->_pLeft = pParent;
		childR->_pParent = pParent->_pParent;
		//根为空
		if (pParent->_pParent)
		{
			if (pParent == pParent->_pParent->_pLeft)
				pParent->_pParent->_pLeft = childR;
			if (pParent == pParent->_pParent->_pRight)
				pParent->_pParent->_pRight = childR;
		}
		pParent->_pParent = childR;
		//childRL为空
		if (childRL)
			childRL->_pParent = pParent;	
		pParent->_bf = 0;
		childR->_bf = 0;
	}
	// 右左双旋
	void RotateRL(Node* pParent)
	{
		Node* childR = pParent->_pRight;
		Node* childRL = childR->_pLeft;
		int bf = childRL->_bf;
		RotateR(pParent->_pRight);
		RotateL(pParent);
		//childRL下面没东西
		if (bf == 0)
		{
			pParent->_bf = 0;
			childR->_bf = 0;
			childRL->_bf = 0;
		}
		//childRL右下插入
		else if (bf == 1)
		{
			pParent->_bf = -1;
			childR->_bf = 0;
			childRL->_bf = 0;
		}
		//childRL左下插入
		else if (bf == -1)
		{
			pParent->_bf = 0;
			childR->_bf = 1;
			childRL->_bf = 0;
		}
	}
	// 左右双旋
	void RotateLR(Node* pParent)
	{
		Node* childL = pParent->_pLeft;
		Node* childLR = childL->_pRight;
		int bf = childLR->_bf;
		RotateL(pParent->_pLeft);
		RotateR(pParent);
		//childLR下面没东西
		if (bf == 0)
		{
			pParent->_bf = 0;
			childL->_bf = 0;
			childLR->_bf = 0;
		}
		//childLR右下插入
		else if (bf == 1)
		{
			pParent->_bf = 0;
			childL->_bf = -1;
			childLR->_bf = 0;
		}
		//childLR左下插入
		else if (bf == -1)
		{
			pParent->_bf = 1;
			childL->_bf = 0;
			childLR->_bf = 0;
		}
	}

private:
	Node* _pRoot;
};

