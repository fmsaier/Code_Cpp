//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	pair<int, int> p = make_pair(1, 2);
//	cout << p.first << ":" << p.second << endl;
//
//	return 0;
//}

#include <iostream>
#include <set>
#include "AVLTree.h"

using namespace std;

//void TestSet()
//{
//	// 用数组array中的元素构造set
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4,
//6, 8, 0 };
//	set<int> s(array, array + sizeof(array) / sizeof(int));
//	cout << s.size() << endl;
//	// 正向打印set中的元素，从打印结果中可以看出：set可去重
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// 使用迭代器逆向打印set中的元素
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	// set中值为3的元素出现了几次
//	cout << s.count(3) << endl;
//}
//
//
//
//class A
//{
//public:
//	typedef char test;
//};
//
//class B
//{
//public:
//	typedef typename A::test wow;
//};
//
//template<class T>
//class Test
//{
//public:
//	T a;
//
//	Test(T data = T())
//		:a(data)
//	{}
//
//	Test(const Test<T>& t)
//	{
//		a = t.a;
//		cout << "Test(const Test<T>& t)" << endl;
//	}
//
//
//	Test(Test<T>&& t)
//	{
//		a = t.a;
//		cout << "Test<T>&& t" << endl;
//	}
//};
//
//template<class T>
//Test<T> func()
//{
//	Test<T> t;
//	return t;
//}

class A
{
private:
	int _a;

public:
	void Test()
	{
		Func();
		[this] {_a = 0; };
	}

	static void Func()
	{
		A a;
		a.Test();
	}
};

int main()
{
	int b = 1;
	int* p = &b;
	cout << p << endl;

	return 0;
}