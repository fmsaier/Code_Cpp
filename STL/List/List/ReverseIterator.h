#pragma once
namespace fmsaier
{
	// 适配器 -- 复用
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
        typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		Iterator _it;
        Reverse_iterator(Iterator it)
            :_it(it)
        {}
        Ref operator*() 
        {
            Iterator tmp = _it;
            tmp--;
            return *tmp;
        }
        Ptr operator->()
        {
            return &(operator*());
        }
        Self& operator++()
        {
            _it--;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp = *this;
            _it--;
            return tmp;
        }
        Self& operator--()
        {
            _it++;
            return *this;
        }
        Self& operator--(int)
        {
            Self tmp = *this;
            _it++;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return (_it != l._it);
        }
        bool operator==(const Self& l)
        {
            return (_it == l._it);
        }
	};
	// vector和list反向迭代器实现
}
