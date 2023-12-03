//
//#include "test2.h"
//
////int a = 0;
//int main()
//{
//	//int a = 0;
//	Tets t;
//	cout << t.a << endl;
//	return 0;
//}
#include <iostream>
#include <string>
using namespace std;

//43. 字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
class Solution {
public:
	string addStrings(string num1, string num2) {
		int next = 0;
		int ret = 0;
		auto it1 = num1.rbegin();
		auto it2 = num2.rbegin();
		int ret1 = *it1 - '0';
		int ret2 = *it2 - '0';
		string sum;
		while (it1 != num1.rend() || it2 != num2.rend())
		{
			ret = ret1 + ret2 + next;
			next = ret / 10;
			ret = ret % 10;
			sum += ret + '0';
			if (it1 != num1.rend())
				it1++;
			if (it2 != num2.rend())
				it2++;
			if (it1 == num1.rend())
				ret1 = 0;
			else
			{
				ret1 = *it1 - '0';
			}
			if (it2 == num2.rend())
				ret2 = 0;
			else
			{
				ret2 = *it2 - '0';
			}
		}
		if (next != 0)
			sum += next + '0';
		reverse(sum.begin(), sum.end());
		return sum;
	}
	string multiply(string num1, string num2) {
		string min(num1);
		string max(num2);
		if (!strcmp(min.c_str(), "0") || !strcmp(max.c_str(), "0"))
		{
			return "0";
		}
		if (min.size() > max.size())
			swap(min, max);
		int count = min.size();
		string *str = new string[count];
		while (count--)
		{
			int i = min[count] - '0';
			string ret(max);
			if (i == 0)
			{
				str[count] = "0";
				continue;
			}
			while (--i)
			{	
				 ret = addStrings(max, ret);
			}
			ret.insert(ret.size(), min.size() - count - 1, '0');
			str[count] = ret;
		}
		count = min.size();
		string sum(str[0]);
		for (int i = 1; i < count; i++)
		{
			sum = addStrings(sum, str[i]);
		}
		return sum;
	}
};
int main()
{
	string num1("140");
	string num2("721");
	Solution s;
	string sum(s.multiply(num1, num2));
	cout << sum << endl;
	return 0;
}