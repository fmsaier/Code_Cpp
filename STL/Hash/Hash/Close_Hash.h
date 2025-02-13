#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace fmsaier
{
	namespace open_address
	{
		enum State
		{
			EMPTY,
			EXIST,
			DELETE
		};

		template<class T>
		struct HashFunc
		{
			size_t operator()(const T& data)
			{
				return (size_t)data;
			}
		};

		template<class K, class V>
		struct HashData
		{
			State _state = EMPTY;
			pair<K, V> _data;
		};

		template<class K, class V, class HashFunc = HashFunc<K>>
		class HashTable
		{
		public:
			HashTable(size_t size = 10)
			{
				_table.resize(size);
			}

			HashData<K, V>* Find(const K& key)
			{
				HashFunc hs;
				size_t index = hs(key) % _table.size();
				while (_table[index]._state != EMPTY)
				{
					if (key == _table[index]._data.first && _table[index]._state == EXIST)
						return &(_table[index]);
					++index;
					index %= _table.size();
				}
				return nullptr;
			}

			bool Insert(const pair<K, V>& kv)
			{
				if (Find(kv.first))
					return false;

				HashFunc hs;
				if ((float)_size / _table.size() > 0.7)
				{
					vector<HashData<K, V>> newTable(2 * _table.size());
					_table.swap(newTable);
					for (auto& kv : newTable)
					{
						if (kv._state == EXIST)
							Insert(kv._data);
					}
				}

				size_t index = hs(kv.first) % _table.size();
				while (_table[index]._state == EXIST)
				{
					++index;
					index %= _table.size();
				}
				_table[index]._data = kv;
				_table[index]._state = EXIST;
				_size++;

				return true;
			}

			bool Erase(const K& key)
			{
				HashData<K, V>* ret = Find(key);
				if (ret)
				{
					_size--;
					ret->_state = DELETE;
					return true;
				}
				else
				{
					return false;
				}
			}

		private:
			vector<HashData<K, V>> _table;
			size_t _size;
		};

		void TestHT1()
		{
			int a[] = { 1,4,24,34,7,44,17,37 };
			HashTable<int, int> ht;
			for (auto e : a)
			{
				ht.Insert(make_pair(e, e));
			}

			for (auto e : a)
			{
				auto ret = ht.Find(e);
				if (ret)
				{
					cout << ret->_data.first << ":E" << endl;
				}
				else
				{
					cout << ret->_data.first << ":D" << endl;
				}
			}
			cout << endl;

			ht.Erase(34);
			ht.Erase(4);

			for (auto e : a)
			{
				auto ret = ht.Find(e);
				if (ret)
				{
					cout << ret->_data.first << ":E" << endl;
				}
				else
				{
					cout << e << ":D" << endl;
				}
			}
			cout << endl;
		}
	}	
}