#include "list.h"


void Test1()
{
	fmsaier::list<int> l(10, 5);
	l.push_back(1);
	l.push_back(2);
	fmsaier::list<int> l2(l);
	for (auto& i : l2)
	{
		cout << i << " ";
	}
}
void Test2()
{
	fmsaier::list<int> l(10, 5);
	l.pop_back();
	l.pop_front();
	l.clear();
	l.push_back(5);
	l.push_front(3);
	for (auto& i : l)
	{
		cout << i << " ";
	}
}
void Test3()
{
	fmsaier::list<int> l(10, 5);
	fmsaier::list<int>::reverse_iterator it = l.rbegin();
	for (int i = 0; i < l.size(); i++)
	{
		cout << *it << " ";
		it++;
	}
}
//int main()
//{
//	int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };
//	int n = sizeof(ar) / sizeof(int);
//	fmsaier::list<int> mylist(ar, ar + n);
//
//	fmsaier::list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
//
//	reverse(mylist.begin(), pos);
//
//	reverse(pos, mylist.end());
//
//	fmsaier::list<int>::const_reverse_iterator crit = mylist.crbegin();
//
//	while (crit != mylist.crend())
//
//	{
//
//		cout << *crit << " ";
//
//		++crit;
//
//	}
//
//	cout << endl;
//
//}

#include "list.h"
#include <vector>

class A
{
public:
	int a;
};

int main()
{
	static int a = 0;
	//typedef a b;
	fmsaier::list<A> l;
	fmsaier::list<A>::iterator it = l.begin();
	cout << it->a << endl;
	vector<int> v;
	vector<int>::const_iterator vit = v.begin();
	v.push_back(1);
	return 0;
}