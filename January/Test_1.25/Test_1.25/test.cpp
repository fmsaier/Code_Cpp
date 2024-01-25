////class Test
////{
////public:
////	bool operator==(Test &t)
////	{
////		return false;
////	}
////	static Test& operator++(Test& t)
////	{
////
////	}
////};
////static bool operator==(Test& t1, Test& t2)
////{
////
////}
//class Statci
//{
//public:
//	Statci()
//	{
//
//	}
//	~Statci()
//	{
//
//	}
//};
//class MyGo
//{
//private:
//	Statci s;
//public:
//	MyGo(int i)
//	{
//
//	}
//	~MyGo()
//	{
//
//	}
//};
//int main()
//{
//	MyGo myGo(1);
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    int count = 0;
//    bool isDigit = false;
//    bool isOK = false;
//    bool isChange = false;
//    string::iterator it = s.begin();
//    vector<int> v1,v2;
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (isdigit(s[i]))
//        {
//            isDigit = true;
//            if(!isOK)
//                v2.push_back(i);
//            isOK = true;
//            count++;
//        }
//        if (!isdigit(s[i]) && isDigit)
//        {
//            isDigit = false;
//            v1.push_back(count);
//            count = 0;
//            isOK = false;
//        }
//    }
//    int j = 0;
//    for (int i = 0; i < v1.size(); i++)
//    {
//        if (v1[i] > count)
//        {
//            count = v1[i];
//            j = i;
//            isChange = true;
//        }
//    }
//    if (!isChange)
//    {
//        printf("%s", s.c_str() + v2[v2.size() - 1]);
//    }
//    else
//    {
//        string str(it + v2[j], it + v2[j] + count);
//        printf("%s", str.c_str());
//    }
//}
//// 64 位输出请用 printf("%lld")



class Solution {
public:

    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        vector<int> v1;
        v1.resize(10000);
        for (int i : numbers)
        {
            v1[i]++;
        }
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] >= numbers.size() / (float)2)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    /*v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);*/
    v.push_back(2);
    //[3, 3, 3, 3, 2, 2, 2]
    cout << s.MoreThanHalfNum_Solution(v);
}