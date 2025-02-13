#pragma once
#include "RBTree.h"

namespace fmsaier
{
	template<class K>
	struct Less
	{
		bool operator()(const K& a, const K& b)
		{
			return a < b;
		}
	};

	template<class K, class V, class Compare = Less<K>>
	class Map
	{
		struct KeyOfValue
		{
			const K& operator()(const pair<const K, V>& value)
			{
				return value.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, KeyOfValue, Compare>::Iterator iterator;
		typedef typename RBTree<K, const pair<const K, V>, KeyOfValue, Compare>::Const_Iterator const_iterator;
		iterator begin()
		{
			return _rb.begin();
		}

		iterator end()
		{
			return _rb.end();
		}

		bool insert(const pair<const K, V>& kv)
		{
			return _rb.Insert(kv);
		}


	private:
		RBTree<K, pair<const K, V>, KeyOfValue, Compare> _rb;
	};

	void test_map1()
	{
		Map<int, int> m;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			m.insert(make_pair(e, e));
		}

		Map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			//it->first += 100;
			it->second += 100;

			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
