#pragma once
#include<iostream>
#include<vector>

using namespace std;

namespace fmsaier
{
	namespace hash_bucket
	{
		template<class T>
		struct HashNode
		{
			T _data;
			HashNode<T>* _next;

			HashNode(const T& data)
				:_data(data)
				, _next(nullptr)
			{
			}
		};

		template<class K, class T, class KeyOfValue, class HashFunc>
		class HashTable;

		template<class K, class T, class KeyOfValue, class HashFunc>
		class HashTableIterator
		{
			typedef HashNode<T> Node;
			typedef HashTable<K, T, KeyOfValue, HashFunc> Table;
			typedef HashTableIterator<K, T, KeyOfValue, HashFunc> Self;
		public:
			HashTableIterator(Node* node, Table* ht)
				:_node(node)
				,_ht(ht)
			{}
			Self& operator++()
			{
				if (_node->_next)
					_node = _node->_next;
				else
				{
					KeyOfValue kov;
					HashFunc hf;
					size_t hashi = hf(kov(_node->_data)) % _ht->_table.size();
					// 找下一个桶
					hashi++;
					while (hashi < _ht->_table.size())
					{
						if (_ht->_table[hashi])
						{
							_node = _ht->_table[hashi];
							break;
						}
						hashi++;
					}
					// 后面没有桶了
					if (hashi == _ht->_table.size())
					{
						_node = nullptr;
					}
				}
				return *this;
			}
			T& operator*()
			{
				return _node->_data;
			}
			T* operator->()
			{
				return &(_node->_data);
			}
			bool operator==(const Self& s)
			{
				return _node == s._node;
			}
			bool operator!=(const Self& s)
			{
				return _node != s._node;
			}
		private:
			Node* _node;
			Table* _ht;
		};

		template<class K, class T, class KeyOfValue, class HashFunc>
		class HashTable
		{
			typedef HashNode<T> Node;
			template<class K, class T, class KeyOfValue, class HashFunc>
			friend class HashTableIterator;
		public:
			typedef HashTableIterator<K, T, KeyOfValue, HashFunc> Iterator;

			HashTable()
			{
				_table.resize(10, nullptr);
				_size = 0;
			}
			~HashTable()
			{
				for (int i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* pre = cur;
						cur = cur->_next;
						delete pre;
					}
					_table[i] = nullptr;
				}
				_size = 0;
			}
			Iterator begin()
			{
				for (int i = 0; i < _table.size(); i++)
				{
					if (_table[i])
						return Iterator(_table[i], this);
				}
				return end();
			}
			Iterator end()
			{
				return Iterator(nullptr, this);
			}
			pair<Iterator, bool> Insert(const T& data)
			{
				HashFunc hf;
				KeyOfValue kov;
				if (Find(kov(data)) != end())
					return make_pair(Find(kov(data)), false);
				if (_size >= _table.size())
				{
					vector<Node*> newTable(2 * _table.size(), nullptr);
					_table.swap(newTable);
					for (int i = 0; i < newTable.size(); i++)
					{
						Node* cur = newTable[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = hf(kov(cur->_data)) % _table.size();
							newTable[i] = cur->_next;
							cur->_next = _table[index];
							_table[index] = cur;

							cur = next;
						}
						newTable[i] = nullptr;
					}
				}
				Node* newNode = new Node(data);
				size_t index = hf(kov(data)) % _table.size();
				newNode->_next = _table[index];
				_table[index] = newNode;
				_size++;

				return make_pair(Iterator(newNode, this), true);
			}
			Iterator Find(const K& key)
			{
				HashFunc hf;
				size_t index = hf(key) % _table.size();
				Node* cur = _table[index];
				while (cur)
				{
					if (cur->_data.first == key)
						return Iterator(cur, this);
					cur = cur->_next;
				}
				return Iterator(nullptr, this);
			}
			bool Erase(const K& key)
			{
				HashFunc hf;
				size_t index = hf(key) % _table.size();
				Node* cur = _table[index];
				Node* pre = nullptr;
				while (cur)
				{
					if (cur->_data.first == key)
					{
						if (pre)
							pre->_next = cur->_next;
						else
							_table[index] = cur->_next;
						delete cur;
						_size--;
						return true;
					}
					pre = cur;
					cur = cur->_next;
				}

				return false;
			}

		private:
			vector<Node*> _table;
			size_t _size;
		};
	}
}
