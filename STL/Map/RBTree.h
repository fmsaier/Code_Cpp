#pragma once
#include <iostream>

using namespace std;

namespace fmsaier
{
	enum Color
	{
		RED,
		BLACK
	};

	template <class T>
	struct RBTreeNode
	{
		Color _color;
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;

		RBTreeNode(const T& data)
			:_color(RED)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(data)
		{}
	};

	template <class T, class Ref, class Ptr>
	struct RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef RBTreeIterator<T, Ref, Ptr> Self;

		RBTreeIterator(Node* node)
			:_node(node)
		{ }

		Self& operator++()
		{
			if (_node->_right)
			{
				_node = _node->_right;
				while (_node->_left)
				{
					_node = _node->_left;
				}
			}
			else
			{
				while (_node->_parent && _node != _node->_parent->_left)
				{
					_node = _node->_parent;
				}
				_node = _node->_parent;
			}
			return *this;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		Node* _node;
	};

	template <class K, class T, class KeyOfValue, class Compare>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		typedef RBTreeIterator<T, T&, T*> Iterator;
		typedef RBTreeIterator<T, const T&, const T*> Const_Iterator;

		Iterator begin()
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			return cur;
		}
		Const_Iterator begin()const
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			return cur;
		}

		Iterator end()
		{
			return nullptr;
		}
		Const_Iterator end()const
		{
			return nullptr;
		}

		Iterator Find(const K& key)
		{
			if (!_root) return nullptr;
			Node* cur = _root;
			KeyOfValue kov;
			Compare com;
			while (cur)
			{
				if (com(kov(cur->_data), key))
					cur = cur->_right;
				else if (com(key, kov(cur->_data)))
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}

		bool Insert(const T& data)
		{
			if (!_root)
			{
				Node* newNode = new Node(data);
				_root = newNode;
				_root->_color = BLACK;
				return true;
			}
			KeyOfValue kov;
			Compare com;
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (com(kov(data), kov(cur->_data)))
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (com(kov(cur->_data), kov(data)))
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					return true;
			}

			cur = new Node(data);
			if (com(kov(cur->_data), kov(parent->_data)))
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			
			while (parent && parent->_color == RED)
			{
				Node* grandparent = parent->_parent;
				if (parent == grandparent->_left)
				{
					Node* uncle = grandparent->_right;
					if (uncle && uncle->_color == RED)
					{
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandparent->_color = RED;
						cur = grandparent;
						parent = grandparent->_parent;
					}
					else
					{
						if (cur = parent->_left)
						{
							RotateR(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else if (cur = parent->_right)
						{
							RotateL(parent);
							RotateR(grandparent);
							cur->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}
				else if (parent == grandparent->_right)
				{
					Node* uncle = grandparent->_left;
					if (uncle && uncle->_color == RED)
					{
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandparent->_color = RED;
						cur = grandparent;
						parent = grandparent->_parent;
					}
					else
					{
						if (cur = parent->_left)
						{
							RotateR(parent);
							RotateL(grandparent);
							cur->_color = BLACK;
							grandparent->_color = RED;
						}
						else if (cur = parent->_right)
						{
							RotateL(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}
			}

			//¸ùÖÃºÚ
			_root->_color = BLACK;

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
		}

	private:
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			subR->_left = parent;
			Node* ppnode = parent->_parent;
			parent->_parent = subR;

			if (parent == _root)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = subR;
				}
				else
				{
					ppnode->_right = subR;
				}
				subR->_parent = ppnode;
			}
		}

		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			subL->_right = parent;

			Node* ppnode = parent->_parent;
			parent->_parent = subL;

			if (parent == _root)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = subL;
				}
				else
				{
					ppnode->_right = subL;
				}
				subL->_parent = ppnode;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr) return;
			_InOrder(root->_left);
			cout << root->_data.first << " ";
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};
}