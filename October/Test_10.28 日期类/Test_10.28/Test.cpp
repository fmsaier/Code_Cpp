#include "Date.h"

void Test1()
{
	Date d1(2021, 10, 20);
	Date d2;
	d2 = d1 + 50;
	d2.Print();
	d1 += 50;
	d1.Print();
	d2 = d1 - 50;
	d2.Print();
	d1 -= 50;
	d1.Print();
}

void Test2()
{
	Date d1(2022, 10, 20);
	Date d2(2022, 10, 21);
	bool isGreater = d2 > d1;
	cout << isGreater << endl;
}

void Test3()
{
	Date d1(2022, 10, 5);
	Date d2(2022, 10, 20);
	int a = d1 - d2;
	int b = d2 - d1;
	cout << a << endl << b << endl;
}
int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}