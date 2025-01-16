#include "priority_queue.h"

void Test1()
{
	fmsaier::priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(6);
	pq.push(7);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}

int main()
{
	Test1();
	int b = 1;
	const int* pb = &b;
	const int* & a = pb;
	a++;
	return 0;
}