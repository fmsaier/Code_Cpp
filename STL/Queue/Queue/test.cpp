#include "queue.h"

int main()
{
	fmsaier::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}