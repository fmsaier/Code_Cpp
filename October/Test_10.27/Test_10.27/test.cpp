#include <iostream>
#include "inline.h"
using namespace std;

inline int Add(int x, int y)
{
	return x + y;
}
inline int Add(double x, double y)
{
	return x + y;
}
int main()
{
	float a =Add(1.2f, 2.2f);
	int b = Add(1, 2);
	return 0;
}