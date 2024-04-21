#pragma once

#include <string>
#include <vector>

using namespace std;

// 注意：假如实现的哈希表中元素唯一，即key相同的元素不再进行插入
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
namespace Close_Hash
{
	enum State 
	{ 
		EMPTY, 
		EXIST,
		DELETE 
	};

	template<class K, class V>
	class HashTable
	{
		struct Elem
		{
			pair<K, V> _val;
			State _state;
		};

	public:
		HashTable(size_t capacity = 5)
			: _ht(capacity)
			,_size(0)
			, _totalSize(0)
		{
			for (size_t i = 0; i < capacity; ++i)
				_ht[i]._state = EMPTY;
		}

		// 插入
		bool Insert(const pair<K, V>& val)
		{
			if (Find(val.first))
				return false;
			//扩容
			if ((float)_size / _ht.size() > 0.7f)
			{
				//定义vector的话size会一直++
				HashTable<K, V> newht(_ht.size() * 2);
				Swap(newht);
				for (auto& elem : newht._ht)
				{
					if (elem._state == EXIST)
					{
						Insert(elem._val);
					}
				}
			}
			size_t index = HashFunc(val.first);
			while (_ht[index]._state != EMPTY)
			{
				index = ++index % _ht.size();
			}
			_ht[index]._val = val;
			_ht[index]._state = EXIST;
			_size++;
			_totalSize++;
			return true;
		}

		// 查找
		Elem* Find(const K& key)
		{
			size_t index = HashFunc(key);
			while (_ht[index]._state != EMPTY)
			{
				if (_ht[index]._state == EXIST && _ht[index]._val.first == key)
				{
					return &_ht[index];
				}
				index = (index + 1) % _ht.size();
			}
			return nullptr;
		}

		// 删除
		bool Erase(const K& key)
		{
			Elem* target = nullptr;
			if (target = Find(key))
			{
				target->_state == DELETE;
				_size--;
				return true;
			}
			return false;
		}

		size_t Size()const
		{
			return _size;
		}

		bool Empty() const
		{
			return _size == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			swap(_totalSize, ht._totalSize);
			_ht.swap(ht._ht);
		}

	private:
		size_t HashFunc(const K& key)
		{
			return key % _ht.capacity();
		}

	private:
		vector<Elem> _ht;
		size_t _size;
		size_t _totalSize;  // 哈希表中的所有元素：有效和已删除, 扩容时候要用到
	};
}