#include "Date.h"

void Test()
{
	Date d1(2021, 10, 20);
	Date d2;
	d2 = d1 + 50;
	d2.Print();
	d1 += 50;
	d1.Print();
}

int main()
{
	Test();
	return 0;
}