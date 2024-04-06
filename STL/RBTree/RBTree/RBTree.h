#pragma once
#include <iostream>

using namespace std;

// 请模拟实现红黑树的插入--注意：为了后序封装map和set，本文在实现时给红黑树多增加了一个头结点
enum Color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	typedef RBTreeNode<T> Node;
	Node* _pLeft;
	Node* _pRight;
	Node* _pParent;
	T _data;
	Color _color;
	RBTreeNode(const T& data = T())
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(RED)
	{}
};


template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node();
		_pHead->_pLeft = nullptr;//begin
		_pHead->_pRight = nullptr;//root
	}

	// 在红黑树中插入值为data的节点，插入成功返回true，否则返回false
	// 注意：为了简单起见，本次实现红黑树不存储重复性元素
	bool Insert(const T& data)
	{
		Node* child = _pHead->_pRight;
		Node* parent = _pHead;
		Node* grandparent = nullptr;
		Node* uncle = nullptr;
		//有了就返回
		while (child)
		{
			if (child->_data < data)
			{
				parent = child;
				child = child->_pRight;
			}
			else if (child->_data > data)
			{
				parent = child;
				child = child->_pLeft;
			}
			else
			{
				return false;
			}
		}
		child = new Node(data);
		//根
		if (parent == _pHead)
		{
			_pHead->_pRight = child;
			child->_color = BLACK;
			child->_pParent = _pHead;
			return true;
		}
		//正常插入
		if (child->_data > parent->_data)
		{
			parent->_pRight = child;
			child->_pParent = parent;
		}
		else
		{
			parent->_pLeft = child;
			child->_pParent = parent;
		}
		//平衡调整
		//g是根就结束
		//根一定是黑的
		//child == root 跟 child 是第二层都不用跑了 
		// rb是两层两层调整所以要child不是第一二层
		//只要parent是黑也不用跑了 bf == 0
		while (parent != _pHead && parent->_color == RED)
		{
			//设置g跟u
			grandparent = parent->_pParent;
			//p是g的左
			if (parent == grandparent->_pLeft)
			{
				uncle = grandparent->_pRight;
				//u是红 调颜色就行 c位置无所谓
				if (uncle && uncle->_color == RED)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandparent->_color = RED;
					//注意！！！！
					//这个时候已经把p跟c都调过了，所以c直接调到g
					//avl是一层一层往上调整 rb是两层两层调整
					child = grandparent;
					parent = grandparent->_pParent;
				}
				//u是黑/不存在 分c在p的左还是右
				else if (!uncle || uncle->_color == BLACK)
				{
					//c在p的左
					//    g
					//  p    u
					//c
					//右旋
					if (child == parent->_pLeft)
					{
						////调整根位置
						// 有头节点，根的p也有人所以不用特意调整
						//if (grandparent == _pHead->_pRight)
						//{

						//}
						RotateR(grandparent);
					}
					//c在p的右
					//    g
					//  p    u
					//    c
					//左右双旋
					else if (child == parent->_pRight)
					{
						RotateLR(grandparent);
					}
					break;
				}
			}
			//p是g的右
			else if (parent == grandparent->_pRight)
			{
				uncle = grandparent->_pLeft;
				//u是红 改颜色
				if (uncle && uncle->_color == RED)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandparent->_color = RED;
					child = grandparent;
					parent = grandparent->_pParent;
				}
				//u是黑或者不存在 旋转
				else if (!uncle || uncle->_color == BLACK)
				{
					//c在p的左
					//    g
					// u    p    
					//    c
					//右左双旋
					if (child == parent->_pLeft)
					{
						RotateRL(grandparent);
					}
					//c在p的右
					//    g
					//  u   p 
					//        c
					//左旋
					else if (child == parent->_pRight)
					{
						RotateL(grandparent);
					}
					break;
				}
			}
			_pHead->_pRight->_color = BLACK;
			////////p是黑直接退//条件有这个判断了
			//if (parent->_color == BLACK)
			//	break;
		}

		_pHead->_pRight->_color = BLACK;
		Node* cur = _pHead->_pRight;
		while (cur->_pLeft)
		{
			cur = cur->_pLeft;
		}
		_pHead->_pLeft = cur;
	}

	// 检测红黑树中是否存在值为data的节点，存在返回该节点的地址，否则返回nullptr
	Node* Find(const T& data)
	{
		Node* cur = _pHead->_pRight;
		if (cur == nullptr)
			return nullptr;
		while (cur)
		{
			if (data < cur->_data)
			{
				cur = cur->_pLeft;
			}
			else if (data > cur->_data)
			{
				cur = cur->_pRight;
			}
			else
			{
				return cur;
			}
		}	
		return nullptr;
	}

	// 获取红黑树最左侧节点
	Node* LeftMost()
	{
		return _pHead->_pLeft;
	}

	// 获取红黑树最右侧节点
	Node* RightMost()
	{
		Node* cur = _pHead->_pRight;
		while (cur->_pRight)
		{
			cur = cur->_pRight;
		}
		return cur;
	}

	// 检测红黑树是否为有效的红黑树，注意：其内部主要依靠_IsValidRBTRee函数检测
	bool IsValidRBTRee()
	{
		Node* cur = _pHead->_pRight;
		size_t blackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
				blackCount++;
			cur = cur->_pLeft;
		}
		if (_pHead->_pRight && _pHead->_pRight->_color != BLACK)
		{
			cout << "根不为黑" << endl;
			return false;
		}
		return _IsValidRBTRee(GetRoot(), blackCount, 0);
	}
	void InOrder()
	{
		_InOrder(_pHead->_pRight);
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_pLeft);
		cout << root->_data << ":" << root->_color << endl;
		_InOrder(root->_pRight);
	}
	bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (pRoot == nullptr)
			return true;
		if (pRoot->_color == BLACK)
			pathBlack++;
		if (!pRoot->_pLeft && !pRoot->_pRight)
		{
			if (blackCount == pathBlack)
				return true;
			else
			{
				cout << "黑色数不对" << endl;
		
				return false;
			}
		}
		if (pRoot->_color == RED && pRoot->_pParent->_color == RED)
		{
			cout << "红色连续" << endl;
			return false;
		}
		if (!_IsValidRBTRee(pRoot->_pLeft, blackCount, pathBlack) ||
			!_IsValidRBTRee(pRoot->_pRight, blackCount, pathBlack))
			return false;
		return true;
	}
	// 左单旋
	void RotateL(Node* pParent)
	{
		Node* childR = pParent->_pRight;
		Node* childRL = childR->_pLeft;
		pParent->_pRight = childRL;
		childR->_pLeft = pParent;
		childR->_pParent = pParent->_pParent;
		//有头节点根的上面有东西不考虑
		//根为空
		if (pParent == pParent->_pParent->_pLeft)
			pParent->_pParent->_pLeft = childR;
		if (pParent == pParent->_pParent->_pRight)
			pParent->_pParent->_pRight = childR;

		pParent->_pParent = childR;
		//childRL为空
		if (childRL)
			childRL->_pParent = pParent;
		pParent->_color = RED;
		childR->_color = BLACK;
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
		//有头节点不用特别考虑根
		if (pParent == pParent->_pParent->_pLeft)
			pParent->_pParent->_pLeft = childL;
		if (pParent == pParent->_pParent->_pRight)
			pParent->_pParent->_pRight = childL;

		pParent->_pParent = childL;
		//childLR为空
		if (childLR)
			childLR->_pParent = pParent;
		pParent->_color = RED;
		childL->_color = BLACK;
	}
	// 右左双旋
	void RotateRL(Node* pParent)
	{
		Node* childR = pParent->_pRight;
		Node* childRL = childR->_pLeft;
		RotateR(pParent->_pRight);
		RotateL(pParent);
		pParent->_color = RED;
		childRL->_color = BLACK;
	}
	// 左右双旋
	void RotateLR(Node* pParent)
	{
		Node* childL = pParent->_pLeft;
		Node* childLR = childL->_pRight;
		RotateL(pParent->_pLeft);
		RotateR(pParent);
		pParent->_color = RED;
		childLR->_color = BLACK;
	}
	// 为了操作树简单起见：获取根节点
	Node*& GetRoot()
	{
		return _pHead->_pRight;
	}
private:
	Node* _pHead;
};

