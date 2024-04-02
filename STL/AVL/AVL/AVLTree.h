#pragma once

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
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
	bool Insert(const T& data);

	// AVL树的验证
	bool IsAVLTree()
	{
		return _IsAVLTree(_pRoot);
	}

private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot);
	size_t _Height(Node* pRoot);
	// 右单旋
	void RotateR(Node* pParent);
	// 左单旋
	void RotateL(Node* pParent);
	// 右左双旋
	void RotateRL(Node* pParent);
	// 左右双旋
	void RotateLR(Node* pParent);

private:
	Node* _pRoot;
};

