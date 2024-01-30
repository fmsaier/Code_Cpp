#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//N 100 0000
vector<int> CreateFv()
{
	vector<int> v(1,0);
	int a = 0;
	int b = 1;
	int c = 0;
	while (c <= 1000000)
	{
		c = a + b;
		a = b;
		b = c;
		v.push_back(c);
	}
	return v;
}
int main() 
{
	vector<int> v = CreateFv();
	int n = 0;
	cin >> n;
	int step = abs(v[0] - n);
	for (int i : v)
	{
		if (step > abs(i - n))
		{
			step = abs(i - n);
		}
	}
	cout << step;
	return 0;
}

// 64 位输出请用 printf("%lld")


//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		cin >> A >> n;
//		stack<char> s;
//		for (auto ch : A)
//		{
//			if (ch == '(')
//			{
//				s.push(ch);
//			}
//			else if (ch == ')')
//			{
//				if (s.empty())
//					return false;
//				else
//				{
//					s.pop();
//				}
//			}
//			else
//				return false;
//		}
//		if (!s.empty())
//			return false;
//		else
//			return true;
//	}
//};