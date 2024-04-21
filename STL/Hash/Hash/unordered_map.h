#pragma once

#include "OpenHash.h"

using namespace OpenHash;

namespace fmsaier
{
	// 为了实现简单，在哈希桶的迭代器类中需要用到hashBucket本身，
	template<class K, class V, class KeyOfValue, class HF>
	class HashBucket;

	// 注意：因为哈希桶在底层是单链表结构，所以哈希桶的迭代器不需要--操作
	template <class K, class V, class KeyOfValue, class HF>
	struct HBIterator
	{
		typedef HashBucket<K, V, KeyOfValue, HF> HashBucket;
		typedef HashBucketNode<V>* PNode;
		typedef HBIterator<K, V, KeyOfValue, HF> Self;

		HBIterator()
		{
			PNode _pNode = nullptr;
			HashBucket* _pHt = nullptr;
		}
		Self& operator++()
		{
			// 当前迭代器所指节点后还有节点时直接取其下一个节点
			if (_pNode->_pNext)
				_pNode = _pNode->_pNext;
			else
			{
				// 找下一个不空的桶，返回该桶中第一个节点
				size_t bucketNo = _pHt->HashFunc(KeyOfValue()(_pNode->_data)) + 1;
				for (; bucketNo < _pHt->BucketCount(); ++bucketNo)
				{
					if (_pNode = _pHt->_ht[bucketNo])
						break;
				}
			}

			return *this;
		}
		Self operator++(int)
		{
			PNode tmp = _pNode;
			// 当前迭代器所指节点后还有节点时直接取其下一个节点
			if (_pNode->_pNext)
				_pNode = _pNode->_pNext;
			else
			{
				// 找下一个不空的桶，返回该桶中第一个节点
				size_t bucketNo = _pHt->HashFunc(KeyOfValue()(_pNode->_data)) + 1;
				for (; bucketNo < _pHt->BucketCount(); ++bucketNo)
				{
					if (_pNode = _pHt->_ht[bucketNo])
						break;
				}
			}

			return tmp;
		}
		V& operator*()
		{
			return *_pNode;
		}
		V* operator->()
		{
			return _pNode;
		}
		bool operator==(const Self& it) const
		{
			return _pNode == it._pNode;
		}
		bool operator!=(const Self& it) const
		{
			return _pNode != it._pNode;
		}
		PNode _pNode;             // 当前迭代器关联的节点
		HashBucket* _pHt;         // 哈希桶--主要是为了找下一个空桶时候方便
	};
	template<class T>
	class HashFunc
	{
	public:
		size_t operator()(const T& val)
		{
			return val;
		}
	};
	// unordered_map中存储的是pair<K, V>的键值对，K为key的类型，V为value的类型，HF哈希函数类型
	// unordered_map在实现时，只需将hashbucket中的接口重新封装即可
	template<class K, class V, class HF = HashFunc<K>>
	class unordered_map
	{	
		// 通过key获取value的操作
		struct KeyOfValue
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
		typedef HashBucket<K, pair<K, V>, KeyOfValue, HF> HT;
	public:
		typedef typename HashBucket<K, pair<K, V>, KeyOfValue, HF>::Iterator iterator;
	public:
		unordered_map() 
			: _ht()
		{}
		////////////////////////////////////////////////////
		iterator begin() 
		{
			return _ht.begin(); 
		}
		iterator end() 
		{
			return _ht.end();
		}
		////////////////////////////////////////////////////////////
		// capacity
		size_t size()const 
		{
			return _ht.size();
		}
		bool empty()const 
		{
			return _ht.empty();
		}
		///////////////////////////////////////////////////////////
		// Acess
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.InsertUnique(pair<K, V>(key, V()));
			return ret.fisrt->second;
		}
		const V& operator[](const K& key)const;
		//////////////////////////////////////////////////////////
		// lookup
		iterator find(const K& key) 
		{
			return _ht.Find(key);
		}
		size_t count(const K& key)
		{ 
			return _ht.Count(key); 
		}
		/////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const pair<K, V>& valye)
		{
			return _ht.Insert(valye);
		}

		iterator erase(iterator position)
		{
			return _ht.Erase(position);
		}
		////////////////////////////////////////////////////////////
		// bucket
		size_t bucket_count()
		{ 
			return _ht.BucketCount();
		}
		size_t bucket_size(const K& key) 
		{ 
			return _ht.BucketSize(key); 
		}
	private:
		HT _ht;
	};
}
