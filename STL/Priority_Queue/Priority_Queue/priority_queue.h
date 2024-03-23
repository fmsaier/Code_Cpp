#pragma once
#include <iostream>
#include<vector>
#include<functional>

using namespace std;

namespace fmsaier
{
    template<class T>
    class less
    {
    public:
        bool operator()(const T& a, const T& b)
        {
            return a < b;
        }
    };
    template<class T>
    class less<T*>
    {
    public:
        bool operator()(const T* const & a, const T* const & b)
        {
            return *a < *b;
        }
    };

    template <class T, class Container = vector<T>, class Compare = less<T> >
    class priority_queue
    {
    public:
        priority_queue()
            :c()
        {}
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            InputIterator cur = first;
            while (cur != last)
            {
                push(*cur);
                cur++;
            }

        }
        bool empty() const
        {
            return c.empty();
        }
        size_t size() const
        {
            return c.size();
        }
        const T& top() const
        {
            return c[0];
        }
        void push(const T& x)
        {
            c.push_back(x);
            AdjustUp(c.size() - 1);
        }
        void pop()
        {
            swap(c[0], c[c.size() - 1]);
            c.pop_back();
            AdjustDown(0);
        }

    private:
        void AdjustUp(int child)
        {
            int parent = (child - 1) / 2;
            while (child > 0)
			{
				if (comp(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
                else
                {
                    break;
                }
            }
        }
        void AdjustDown(int parent)
        {
            int child = (parent + 1) * 2;
            while (child < c.size())
            {
                if (c[child - 1] > c[child])
                {
                    child--;
                }
                if (comp(c[parent], c[child]))
                {
                    swap(c[child], c[parent]);
                    parent = child;
                    child = (parent + 1) * 2;
                }
                else
                {
                    break;
                }
            }
        }
        Container c;
        Compare comp;
    };

};