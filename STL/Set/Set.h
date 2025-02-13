#pragma once
#include "RBTree.h"

namespace fmsaier
{
	template<class T>
	struct Less
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};

	template<class K, class Compare = Less<K>>
	class Set
	{
		struct KeyOfValue
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, const K, KeyOfValue, Compare>::Iterator iterator;
		typedef typename RBTree<K, const K, KeyOfValue, Compare>::Const_Iterator const_iterator;
		iterator begin()
		{
			return _rb.begin();
		}

		iterator end()
		{
			return _rb.end();
		}

		bool insert(const K& key)
		{
			return _rb.Insert(key);
		}

	private:
		RBTree<K, const K, KeyOfValue, Compare> _rb;
	};


	void test_set1()
	{
		Set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			s.insert(e);
		}

		Set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//if(*it % 2 == 0)
			//	*it += 100;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}