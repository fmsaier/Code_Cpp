////#include <iostream>
////#include <vector>
////#include <algorithm>
////
////using namespace std;
//
////class Gift {
////public:
////    int getValue(vector<int> gifts, int n) 
////    {
////        sort(gifts.begin(), gifts.end());
////        if (gifts[n / 2] == gifts[n / 2 - 1])
////            return gifts[n / 2];
////        else
////            return 0;
////    }
////};
//
//
//////dp
////#include <iostream>
////#include <vector>
////#include <string>
////using namespace std;
////
////int minDistance(const string& s1, const string& s2)
////{
////    if (s1.empty() || s2.empty())
////        return max(s1.size(), s2.size());
////
////    int len1 = s1.size();
////    int len2 = s2.size();
////
////    vector<vector<int >> f(len1 + 1, vector<int>(len2 + 1, 0));
////    //初始化距离
////    for (int i = 0; i <= len1; i++)
////        f[i][0] = i;
////    for (int j = 0; j <= len2; ++j)
////        f[0][j] = j;
////
////    for (int i = 1; i <= len1; ++i)
////    {
////        for (int j = 1; j <= len2; ++j)
////        {
////            if (s2[j - 1] == s1[i - 1])
////            {
////                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
////                //由于字符相同，距离不发生变化
////                f[i][j] = min(f[i - 1][j - 1], f[i][j]);
////            }
////            else
////            {
////                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
////                //由于字符不相同，距离+1
////                f[i][j] = min(f[i - 1][j - 1] + 1, f[i][j]);
////            }
////        }
////    }
////    return f[len1][len2];
////}
////
////int main()
////{
////    string s1, s2;
////    while (cin >> s1 >> s2)
////    {
////        cout << minDistance(s1, s2) << endl;
////    }
////    return 0;
////}
////
////// 64 位输出请用 printf("%lld")
//////abefgasd
//////abcdef
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
////class Solution {
////public:
////    int lengthOfLongestSubstring(string s)
////    {
////        int len = 1;
////        int left = 0;
////        int right = 0;
////		if (s == "")
////			return 0;
////		while (right < s.size())
////		{
////			string::iterator it = find(s.begin() + left, s.begin() + right + 1, s[right + 1]);
////			if (it == s.begin() + right + 1 && it != s.end())
////			{
////				right++;
////				len = max(len, right - left + 1);
////			}
////			else
////			{
////				left = it - s.begin() + 1;
////				right++;
////
////			}
////		}
////		return len;
////    }
////};
////
////int main()
////{
////	Solution s;
////	string str = "aaa";
////	cout << s.lengthOfLongestSubstring(str);
////	return 0;
////}
//
//
////class Solution {
////public:
////    int longestOnes(vector<int>& nums, int k)
////    {
////        int len = 0;
////        int left = 0;
////        int right = 0;
////        int count = 1;
////        int n = k;
////        while (right < nums.size())
////        {
////            if (nums[right] == 0 && n > 0)
////            {
////                right++;
////                if (right >= nums.size())
////                    continue;
////                count++;
////                n--;
////            }
////            else if (nums[right] != 0)
////            {
////                right++;
////                if (right >= nums.size())
////                    continue;
////                count++;
////            }
////            else
////            {
////                n = k;
////                len = max(len, count);
////                int tmp = right;
////                while (nums[tmp] == 0 && tmp > left)
////                {
////                    tmp--;
////                    n--;
////                }
////                while (nums[tmp] == 1 && tmp > left)
////                {
////                    tmp--;
////                }
////                if (tmp != left)
////                    left = tmp + 1;
////                else
////                    left = right + 1;
////                count = right - left + 1;
////                right++;
////            }
////
////        }
////        len = max(len, count);
////        if (right == nums.size() && left == right && nums[left - 1] == 0)
////            return 0;
////        return len;
////    }
////};
////
////int main()
////{
////    Solution s;
////    vector<int> v = { 0,0,0,0 };
////    cout << s.longestOnes(v, 0);
////    return 0;
////}
//
//
//
//
//
////class A 
////{ 
////public: 
////	void test(float a) 
////	{ 
////		cout << a; 
////	} 
////}; 
////class B :public A 
////{
////public: 
////	void test(int b) 
////	{
////		cout << b;
////	} 
////};
////void main() 
////{
////	A* a = new A;
////	B* b = new B;
////	a = b; 
////	a->test(1.1);
////}
//
//
//
////class A
////{
////
////public:
////
////  void f1() { cout << "A::f1()" << endl; }
////
////  virtual void f2() { cout << "A::f2()" << endl; }
////
////  virtual void f3() { cout << "A::f3()" << endl; }
////
////};
////
////
////
////class B : public A
////
////{
////
////public:
////
////	virtual void f1() { cout << "B::f1()" << endl; }
////
////	virtual void f2() { cout << "B::f2()" << endl; }
////
////	void f3() { cout << "B::f3()" << endl; }
////
////};
////
////int main()
////{
////	B b;
////	A& a = b;
////	a.f2();
////}
//
//
//
////class A
////{
////	virtual void test() = 0
////	{
////		int a;
////	}
////};
////class B : public A
////{
////public:
////	void test()
////	{
////
////	}
////};
////
////int main()
////{
////	A* o;
////}
//
//
//
//
////
////class A
////{
////public:
////	virtual void f()
////	{
////		cout << "A::f()" << endl;
////	}
////};
////
////class B : public A
////{
////private:
////	virtual void f()
////	{
////		cout << "B::f()" << endl;
////	}
////};
////
////int main()
////{
////	A* pa = (A*)new B;
////	pa->f();
////}
////
//
//
//
//﻿
//
//
//
//class B : public A
//{
//public:
//	B()
//	{
//		test();
//	}
// 
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << " ";
//    }
//};
//
//
//
//int main(int argc, char* argv[])
//{
//    A* p = new B;
//    p->test();
//    return 0;
//}

#include <iostream>

using namespace std;


class A
{
public:
  A() 
      :m_iVal(0) 
  { 
      test(); 
  }
  virtual void func() 
  { 
      cout << m_iVal << " "; 
  }
  void test() 
  { 
      func(); 
  }

public:
  int m_iVal;
};


class B : public A
{
public:
    B() 
    { 
        test(); 
    }
    virtual void func()
    {
        ++m_iVal;
        cout << m_iVal << " " ;
    }
};

int test()
{
    cout << "test()" << endl;
    return 1;
}

int main(int argc, char* argv[])

{

   /* A* p = new B;

    p->test();*/

    //1 && 1;

    test() && test() || test();

    return 0;

}