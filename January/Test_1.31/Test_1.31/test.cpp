////#include <iostream>
////#include <vector>
////#include <string>
////#include <string.h>
////using namespace std;
////
////int main() 
////{
////	//字典排序
////	bool lex = true;
////	//长度排序
////	bool length = true;
////	int n;
////	cin >> n;
////	vector<string> v(n, "");
////	for (int i = 0; i < n; i++)
////	{
////		cin >> v[i];
////	}
////	for (int i = 0; i < n - 1; i++)
////	{
////		if (strcmp(v[i].c_str(), v[i + 1].c_str()) > 0)
////		{
////			lex = false;
////			break;
////		}
////	}
////	for (int i = 0; i < n - 1; i++)
////	{
////		if (v[i].size()>v[i+1].size())
////		{
////			length = false;
////			break;
////		}
////	}
////	if (length && lex)
////		cout << "both";
////	else if (length)
////		cout << "lengths";
////	else if (lex)
////		cout << "lexicographically";
////	else
////		cout << "none";
////	return 0;
////}
////// 64 位输出请用 printf("%lld")
//
//
//
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    int a, b;
//    cin >> a >> b;
//    int k = 1;
//    while ((a * k) % b != 0)
//    {
//        k++;
//    }
//    cout << (a*k);
//    return 0;
//}
//// 64 位输出请用 printf("%lld")

#include "vector.h"
#include <list>
#include <vector>
int main()
{
	int a[] = { 100,111,222 };
	bit::vector<int> v(a,a+3);
	list<int> lt;
	lt.push_back(100);
	lt.push_back(200);
	lt.push_back(300);
	lt.push_back(400);
	reverse(lt.begin(), lt.end());
	lt.reverse();
	for (auto& i : lt)
	{
		cout << i << " ";
	}
	//bit::vector<int> v1(lt.begin(), lt.end());
	std::vector<int> v2(3,5);
	bit::vector<int> v1(v2.begin(), v2.end());
	for (auto& i : v)
	{
		cout << i;
	}
	return 0;
}