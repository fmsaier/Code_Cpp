#pragma once
#include<assert.h>
#include<iostream>
#include<algorithm>
using namespace std;

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
		{}

		/*vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			memcpy(_start, v._start, v.size()* sizeof(T));
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}*/

		// v2(v1)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}

		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		// 21:06
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		// v1 = v3
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		// 20: 10继续
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, old * sizeof(T));
					for (size_t i = 0; i < old; i++)
					{
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
				_finish = _start + old;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, T val = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			//memmove(pos + 1, pos, sizeof(T) * (_finish - pos));
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;

			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			_finish--;

			return pos;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};

	void print_vector(const vector<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v[0]++;
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		v.insert(v.begin(), 100);
		print_vector(v);

		v.insert(v.begin(), 100);
		print_vector(v);

		int i = 0;
		int j = int();
		int k = int(10);
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);

		vector<int> v1 = v;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2;
		v2.push_back(11);
		v2.push_back(21);
		v2.push_back(31);
		v2.push_back(411);
		v2.push_back(41);
		v2.push_back(41);

		v1 = v2;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_vector3()
	{
		vector<int> v;
		v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(8);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(15, 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(3);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_vector4()
	{
		vector<string> v;
		v.reserve(10);
		v.push_back("xxxx");
		v.push_back("xxxx");
		v.push_back("xxxx");
		v.push_back("xxxx");
		v.push_back("xxxx");
		v.push_back("xxxx");

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(8);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(15, "yyyy");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(3);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 3);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	// 迭代器失效
	void test_vector6()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		//v.push_back(7);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// 要求删除所有的偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector7()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		v.push_back(9);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;


		vector<string> vstr;
		vstr.push_back("1111");
		vstr.push_back("1111");
		vstr.push_back("1111");
		vstr.push_back("1111");
		vstr.push_back("1111");

		for (auto e : vstr)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector8()
	{
		/*vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2(v1.begin(), v1.end());
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt;
		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		lt.push_back(40);
		vector<int> v3(lt.begin(), lt.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		int a[] = { 100, 200, 300 };
		vector<int> v4(a, a+3);
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}

	void test_vector9()
	{
		vector<string> v1(5, "1111");
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(5, 1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}