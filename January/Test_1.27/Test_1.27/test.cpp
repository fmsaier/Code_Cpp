//#include <iostream>
//
//class Test
//{
//private:
//	int a;
//	int b;
//public:
//	Test(int x, int y)
//	{
//		a = x;
//		b = y;
//	}
//	Test(Test& t)
//	{
//		
//	}
//};
//
//int main()
//{
//	//隐式类型转换（）会变成逗号表达式
//	//Test t1 = (1, 2);
//	Test t2 = { 1,2 };
//	//new的时候可以用（）构造一个对象传多个参数
//	Test* t = new Test(1, 2);
//	//Test* tarr = new Test[5]{ {1,2} };
//	int* p = new int[5] {1, 2, 1, 2};
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//bool isRight(string s, string& scr, int index);
//
//int main() {
//    string a,b;
//    getline(cin, a);
//    getline(cin, b);
//    string c(a);
//    int count = 0;
//    for (int i = 0; i < a.size() + 1; i++)
//    {
//        if (isRight(c, b, i))
//            count++;
//    }
//    cout << count;
//}
//bool isRight(string s,string& scr,int index)
//{
//    s.insert(index, scr.c_str());
//    string s1(s);
//    reverse(s.begin(), s.end());
//    return strcmp(s.c_str(), s1.c_str()) == 0;
//}
//// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	vector<int> v(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	long long max = v[0];
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = v[i]  > sum + v[i] ? v[i] : v[i] + sum;
		max = sum > max ? sum : max;
	}
	cout << max;
	return 0;
}