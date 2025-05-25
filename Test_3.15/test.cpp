#pragma pack(1)
#include <iostream>

using namespace std;

struct A
{
	char _c;
	int _a;
	
};

void Test()
{
	cout << "Hello" << endl;
}

int main()
{
	auto i = 10;

	cout << sizeof(A) << endl;
	return 0;
}