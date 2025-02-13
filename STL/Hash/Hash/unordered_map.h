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

	template<class K, class V, class HashFunc = HashFunc<K>>
	class Unordered_Map
	{
		struct KeyOfValue
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, KeyOfValue, HashFunc>::Iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		V& operator[](const K& key)
		{
			auto kv = insert(make_pair(key, V()));
			return kv.first->second;
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
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
		hash_bucket::HashTable<K, pair<const K, V>, KeyOfValue, HashFunc> _ht;
	};

	void test_map1()
	{
		Unordered_Map<string, string> dict;
		dict["sort"];
		dict.insert(make_pair("left", "左边"));
		dict.insert(make_pair("right", "右边"));

		for (auto& kv : dict)
		{
			//kv.first += 'x';
			//kv.second += 'y';

			cout << kv.first << ":" << kv.second << endl;
		}
	}
}
