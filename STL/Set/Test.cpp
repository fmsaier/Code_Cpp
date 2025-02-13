#include "Set.h"

class B
{
public:
	void Test()
	{
		cout << "void Test()" << endl;
	}
	void Test() const
	{
		cout << "void Test() const" << endl;
	}
};

class A
{
public:
	operator int()
	{
		return 1;
	}

	void Test() const
	{
		cout << "void Test() const" << endl;
		_b.Test();
	}

	B _b;
};

int main()
{
	//fmsaier::RBTree<int, int> rb;
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	pair<int, int> kv = make_pair(rand() + i, rand() + i);
	//	rb.Insert(kv);
	//}

	//rb.InOrder();

	fmsaier::test_set1();

	//A a;
	//a.Test();
	//cout << (int)a << endl;
	return 0;
}