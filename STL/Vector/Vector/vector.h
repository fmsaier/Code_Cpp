#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

namespace fmsaier
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;

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

		// construct and destroy
		vector()
		{ }

		vector(int n, const T& value = T())
		{
			resize(n,value);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		vector(const vector<T>& v)
		{
			for (int i = 0; i < v.size(); i++)
			{
				push_back(v[i]);
			}
			
		}

		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr; 
			_endOfStorage = nullptr; 
		}

		// capacity
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int old = size();
				T* newStart = new T[n];
				if (_start)
				{
					for (int i = 0; i < old; i++)
					{
						newStart[i] = _start[i];
					}
					delete[] _start;
				}
				_start = newStart;
				_finish = _start + old;
				_endOfStorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish != _endOfStorage)
				{
					push_back(value);
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		///////////////access///////////////////////////////
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return *(_start + pos);
		}

		///////////////modify/////////////////////////////
		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(size() > 0);
			_finish--;
		}

		void swap(vector<T>& v)
		{
			std::swap(v._start, _start);
			std::swap(v._finish, _finish);
			std::swap(v._endOfStorage, _endOfStorage);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endOfStorage)
			{
				int n = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + n;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
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

	private:
		iterator _start = nullptr; // 指向数据块的开始
		iterator _finish = nullptr; // 指向有效数据的尾
		iterator _endOfStorage = nullptr; // 指向存储容量的尾

	};
};