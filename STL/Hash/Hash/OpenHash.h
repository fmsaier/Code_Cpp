#pragma once

#include <string>
#include <vector>

using namespace std;

namespace OpenHash
{

	template<class T>
	class HashFunc
	{
	public:
		size_t operator()(const T& val)
		{
			return val;
		}
	};

	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& s)
		{
			const char* str = s.c_str();
			unsigned int seed = 131; // 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}

			return hash;
		}
	};

	template<class V>
	struct HashBucketNode
	{
		HashBucketNode(const V& data)
			: _pNext(nullptr)
			, _data(data)
		{}
		HashBucketNode<V>* _pNext;
		V _data;
	};

	// 本文所实现的哈希桶中key是唯一的
	//template<class V, class HF = HashFunc<V>>
	template<class K, class V, class KeyOfValue, class HF = HashFunc<V>>
	class HashBucket
	{
		typedef HashBucketNode<V> Node;
		typedef Node* PNode;

		typedef HashBucket<K, V, KeyOfValue, HF> Self;

	public:
		HashBucket(size_t capacity = 5)
			: _table(capacity, nullptr)
			, _size(0)
		{}

		~HashBucket()
		{
			Clear();
		}

		// 哈希桶中的元素不能重复
		Node* Insert(const V& data)
		{
			Node* ret = nullptr;
			KeyOfValue kof;
			if (ret = Find(kof(data)))
				return ret;
			//扩容
			if (_size == _table.size())
			{
				vector<Node*> newtable(2 * _table.size(), nullptr);
				_table.swap(newtable);
				for (size_t i = 0; i < newtable.size(); i++)
				{
					Node* cur = newtable[i];
					while (cur)
					{
						Node* next = cur->_pNext;
						size_t index = HashFunc(cur->_data);
						cur->_pNext = _table[index];
						_table[index] = cur;
						cur = next;
					}
				}
			}
			size_t index = HashFunc(data);
			Node* newNode = new Node(data);
			newNode->_pNext = _table[index];
			_table[index] = newNode;
			_size++;
			return newNode;
		}

		// 删除哈希桶中为data的元素(data不会重复)
		bool Erase(const K& data)
		{
			KeyOfValue kof;
			size_t index = HashFunc(data);
			PNode cur = _table[index];
			if (!cur)
				return false;
			if (kof(cur->_data) == data)
			{
				_table[index] = cur->_pNext;
				delete cur;
				return true;
			}
			PNode pre = _table[index];
			cur = cur->_pNext;
			while (cur)
			{
				if (kof(cur->_data) == data)
				{
					pre->_pNext = cur->_pNext;
					delete cur;
					return true;
				}
				cur = cur->_pNext;
				pre = cur;
			}
			return false;
		}

		Node* Find(const K& data)
		{
			KeyOfValue kof;
			size_t index = HashFunc(data);
			PNode cur = _table[index];
			while (cur)
			{
				if (kof(cur->_data) == data)
				{
					return cur;
				}
				cur = cur->_pNext;
			}
			return nullptr;
		}
		size_t Size()const
		{
			return _size;
		}

		bool Empty()const
		{
			return 0 == _size;
		}

		void Clear()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_pNext;
					delete cur;
					cur = next;
				}
			}
		}

		size_t BucketCount()const
		{
			return _table.capacity();
		}

		void Swap(Self& ht)
		{
			_table.swap(ht._table);
			swap(_size, ht._size);
		}

	private:
		size_t HashFunc(const V& data)
		{
			KeyOfValue kof;
			return HF()(kof(data)) % _table.capacity();
		}
		size_t HashFunc(const K& data)
		{
			return data % _table.capacity();
		}

	private:
		vector<Node*> _table;
		size_t _size;      // 哈希表中有效元素的个数
	};
}
