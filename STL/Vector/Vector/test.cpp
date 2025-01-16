#include "vector.h"

using namespace fmsaier;

void Test1()
{
	vector<int> v;
	vector<int>::iterator it = v.begin();
	cout << v.size();
	v.reserve(50);
	cout << v.capacity();
}
void Test2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	vector<int> v1(v);
	vector<int> v2;
	v2 = v;
	for (int i : v1)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i : v2)
	{
		cout << i << " ";
	}
	cout << endl;
}
void Test3()
{
	vector<string> v(10,"1");
	//v.push_back("1");
	//v.push_back("2");
	//v.push_back("23");
	//v.push_back("5");
	//v.push_back("8");
	//v.resize(10);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}
int main()
{
	Test3();
	return 0;
}