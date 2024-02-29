#include "stack.h"

int main()
{
	fmsaier::stack<int> s;
	s.push(1);
	s.push(5);
	s.push(6);
	s.push(4);
	s.push(3);
	s.push(2);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}