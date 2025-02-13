#pragma once

#include "OpenHash.h"
#include <string>

namespace fmsaier
{
	template<class T>
	struct HashFunc
	{
		size_t operator()(const T& data)
		{
			return (size_t)data;
		}
	};

	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& data)
		{
			size_t ret = 0;
			for (auto& ch : data)
			{
				ret += ch * 131;
			}
			return ret;
		}
	};

	template<class K, class HashFunc = HashFunc<K>>
	class Unordered_Set
	{
		struct KeyOfValue
		{
			const K& operator()(const K& data)
			{
				return data;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, const K, KeyOfValue, HashFunc>::Iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const K& data)
		{
			return _ht.Insert(data);
		}
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}
		bool erase(const K& key)
		{
			_ht.Erase(key);
		}
	private:
		hash_bucket::HashTable<K, const K, KeyOfValue, HashFunc> _ht;
	};
}