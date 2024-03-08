//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//int GetChNum(int a, int b)
//{
//	int c = a;
//	while (a % c != 0 || b % c != 0)
//	{
//		if (c == a)
//		{
//			c = a / 2;
//			continue;
//		}
//		c--;
//	}
//	return c;
//}
//
//int main() 
//{
//	int count = 0;
//	int a = 0;
//	vector<int> v;
//	vector<int> ret;
//	while (cin >> count >> a)
//	{
//		v.resize(count);
//		int i = 0;
//		while (i < count)
//		{
//			cin >> v[i++];
//		}
//		for (auto b : v)
//		{
//			if (b <= a)
//			{
//				a += b;
//			}
//			else
//			{
//				a += GetChNum(a, b);
//			}
//		}
//		ret.push_back(a);
//		//cout << a << endl;
//		v.clear();
//	}
//	for (auto tmp : ret)
//	{
//		cout << tmp << endl;
//	}
//	return 0;
//}
//// 64 位输出请用 printf("%lld")


//hash
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;
	getline(cin, s);
	for (auto ch : s)
	{
		int index1 = s.find(ch);
		int index2 = s.rfind(ch);
		if (index1 == index2)
		{
			cout << s[index1] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
// 64 位输出请用 printf("%lld")