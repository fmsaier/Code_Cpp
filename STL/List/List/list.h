#pragma once
#include <iostream>
#include "ReverseIterator.h"
using namespace std;

namespace fmsaier
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_val(val)
            ,_pPre(this)
            ,_pNext(this)
        {}

        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };

    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}
        ListIterator(const Self& l)
            :_pNode(l._pNode)
        {}
        Ref operator*() 
        {
            return _pNode->_val;
        }
        Ptr operator->()
        {
            return &(_pNode->_val);
        }
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp = *this;
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self& operator--(int)
        {
            Self tmp = *this;
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return (_pNode != l._pNode);
        }
        bool operator==(const Self& l)
        {
            return (_pNode == l._pNode);
        }
    private:
        PNode _pNode;
    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
        typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
        typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            _pHead = new Node();
        }
        list(int n, const T& value = T())
        {
            _pHead = new Node();
            while (n--)
            {
                push_back(value);
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            _pHead = new Node();
            Iterator cur = first;
            while (cur != last)
            {
                push_back(*cur);
            }
        }
        list(const list<T>& l)
        {
            _pHead = new Node();
            PNode cur = l._pHead->_pNext;
            while (cur != l._pHead)
            {
                push_back(cur->_val);
                cur = cur->_pNext;
            }
        }
        list<T>& operator=(const list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            PNode cur = _pHead->_pNext;
            while (cur != _pHead)
            {
                pop_back();
                cur = cur->_pNext;
            }
            delete _pHead;
        }

        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }
        iterator end()
        {
            return _pHead;
        }
        const_iterator begin() const
        {
            return _pHead->_pNext;
        }
        const_iterator end() const
        {
            return _pHead;
        }
        reverse_iterator rbegin()
        {
            return (end());
        }
        reverse_iterator rend()
        {
            return (begin());
        }
        const_reverse_iterator crbegin() const
        {
            return (end());
        }
        const_reverse_iterator crend() const
        {
            return (begin());
        }
        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            int count = 0;
            PNode cur = _pHead->_pNext;
            while (cur != _pHead)
            {
                count++;
                cur = cur->_pNext;
            }
            return count;
        }
        bool empty()const
        {
            return (_pHead->_pNext == _pHead);
        }

        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }
        const T& front()const
        {
            return _pHead->_pNext->_val;
        }
        T& back()
        {
            return _pHead->_pPre->_val;
        }
        const T& back()const
        {
            return _pHead->_pPre->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) 
        { 
            insert(end(), val); 
        }
        void pop_back() 
        { 
            erase(--end()); 
        }
        void push_front(const T& val) 
        { 
            insert(begin(), val); 
        }
        void pop_front() 
        { 
            erase(begin()); 
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            PNode cur = _pHead;
            while (pos != cur)
            {
                cur = cur->_pNext;
            }
            PNode pre = cur->_pPre;
            PNode newNode = new Node(val);
            pre->_pNext = newNode;
            newNode->_pPre = pre;
            newNode->_pNext = cur;
            cur->_pPre = newNode;
            return pos;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            PNode cur = _pHead->_pNext;
            while (pos != cur)
            {
                cur = cur->_pNext;
            }
            PNode pre = cur->_pPre;
            pre->_pNext = cur->_pNext;
            cur->_pNext->_pPre = pre;
            delete cur;
            return pre->_pNext;
        }
        void clear()
        {
            while (!empty())
            {
                pop_back();
            }
        }
        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
        }
    private:

        PNode _pHead;
    };
};
