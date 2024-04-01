#include <iostream>
#include <string>
#include <list>

using namespace std;

////A
//class Person
//{
//public:
//	Person()
//	{
//		_a = 0;
//		cout << "A()" << endl;
//	}
//	~Person()
//	{
//
//		cout << "~A()" << endl;
//	}
//public:
//	int _a = 0;
//	//int* _aa = new int(10);
//public:
//	void Test(double x)
//	{
//		cout << "void TestA()" << endl;
//	}
//};
//
////B
//class Student : virtual public Person 
//{
//public:
//	Student()
//	{
//		_b = 0;
//		cout << "B()" << endl;
//	}
//	~Student()
//	{
//
//		cout << "~B()" << endl;
//	}
//public:
//	int _b = 0;
//public:
//
//	//隐藏 / 重定义
//	void Test(int y)
//	{
//		cout << "void TestB()" << endl;
//	}
//	
//};
//
////C
//class Teacher : virtual public Person
//{
//public:
//	int _c = 0;
//
//};
//
////D
//class Assistant : public Student , public Teacher
//{
//public:
//	int _d = 0;
//};
//
////void Test(int a)
////{
////	cout << a;
////}
////void Test(double b)
////{
////	cout << b;
////}
//
//int main()
//{
//	//A a;
//	//B b;
//	//a = b;
//	//A& aa = b;
//	////b = a;
//	//int c = 10;
//	//double f = c;
//	//int& d = c;
//	////const float& e = c;
//	//const double& e = c;
// //	cout << b._b;
//	////string s = "hello,world";
//	///*for (int i = 0; i < s.size(); i++)
//	//{
//	//	cout << s[i] << " ";
//	//}*/
//
//	//string::iterator sit = s.begin();
//	//for (char ch : s)
//	//{
//	//	cout << *sit << " ";
//	//	sit++;
//	//}
//	//
//	//list<int> l(10);
//	//l.push_back(9);
//	//l.push_back(8);
//	//l.push_back(7);
//	//l.push_back(6);
//	//l.push_back(5);
//	//l.push_back(4);
//	//l.push_back(3);
//
//	//list<int>::iterator lit = l.begin();
//	//for (int ch : l)
//	//{
//	//	cout << *lit << " ";
//	//	lit++;
//	//}
//
//
//
//
//
//
//
//	//B b;
//	//b.A::Test(10.1f);
//
//
//	Assistant d;
//	cout << d._d;
//	d._a;
//	//cout << d.Student::_a;
//
//	return 0;
//}

//class C
//{
//	//int c;
//};
//class D : public C
//{
//
//};
//class A
//{
//public:
//	A()
//	{
//		int _a = 0;
//	}
//	int _a = 0;
//	virtual void Test()
//	{
//		cout << "virtual void TestA()" << endl;
//		//return nullptr;
//	}
//	~A()
//	{
//		cout << "virtual ~A()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	B()
//	{
//		int _b = 0;
//	}
//	int _b;
//	
//	~B()
//	{
//		cout << "virtual ~B()" << endl;
//	}
//};

//class E
//{
//	virtual void Test() = 0;
//};

class A
{
public:
	int _a = 0;
	virtual void TestA()
	{

	}
};
class B
{
public:
	virtual void TestB()
	{

	}
};
class C : public A , public B
{
	virtual void TestC()
	{

	}
};
class D : public C
{

};

int main()
{
	//B b;
	//A* p = &b;
	////A& pa = b;
	//p->Test();
	//pa.Test();
	//cout << sizeof(C) << endl;

	//A* p = new B();


	////p->~A();
	//delete p;


	//cout << sizeof(A);

	//A a;
	//B b;
	//cout << a._a;

	C c;
	cout << c._a;
	D d;
	d._a;
	return 0;
}