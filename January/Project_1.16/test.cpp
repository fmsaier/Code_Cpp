#include <iostream>

using namespace std;

class A
{
public:
	void Test()
	{
		cout << typeid(*this).name() << endl;
	}
};

class B : protected A
{

};

int main()
{
	A a;
	a.Test();

	B b;
}