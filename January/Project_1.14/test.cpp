#include <iostream>

using namespace std;

template<long long N = 10>
class A
{
public:
	A()
	{
		cout << N << endl;
	}
};
////ÏÔÊ½ÊµÀý»¯
//template int Test<int>();

template<class T>
T Test()
{
	T a = new T();
	return a;
}

//template class Data<int>;

template<class T>
class Data
{

};

//template<>
//class Data<int>
//{
//
//};
//
//template<class T>
//class Data<T*>
//{
//
//};

class Person
{
public:
	int _a;

	Person()
	{
		cout << "Person() " << endl;
	}

	Person(const Person& p)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator= (const Person& p)
	{
		cout << "Person& operator= (const Person& p)" << endl;
		return *this;
	}
};

class Student : public Person
{
public:
	int _b;

	Student()
	{}

	Student(const Student& s)
	{
	}

	void Test()
	{
		/*_a;*/
	}

	//Student& operator= (const Student& p)
	//{
	//	cout << "Student& operator= (const Student& p)" << endl;
	//	return *this;
	//}
};

int main()
{

	A<1> a;
	Student s1;
	Student s2 = s1;
	return 0;
}