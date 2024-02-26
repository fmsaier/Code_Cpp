//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main() 
//{
//	bool isStr = false;
//	bool isFin = false;
//	string s;
//	vector<string> v;
//	getline(cin, s);
//	string::iterator start = s.begin();
//	string::iterator end = start;
//	for (auto ch : s)
//	{
//		if (ch == '"' && !isStr)
//		{
//			isStr = true;
//			end++;
//			start = end;
//			continue;
//		}
//		if (ch == '"' && isStr)
//		{
//			v.push_back(string(start, end));
//			start = end + 1;
//			end = start;
//			isStr = false;
//			if (end == s.end())
//				isFin = true;
//			continue;
//		}
//		if (ch == ' ' && !isStr && start != end)
//		{
//			string str(start, end);
//			v.push_back(str);
//			start = end + 1;
//		}
//		if (ch == ' ' && !isStr && start == end)
//		{
//			start++;
//		}
//		end++;
//	}
//	if(!isFin)
//	v.push_back(string(start, end));
//	cout << v.size() << endl;
//	for (auto& str : v)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}
//// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int a, b;
    cin >> a >> b;
    int c = a;
    int count = 0;
    int d = 0;
    while (a < b)
    {
        for (int i = a / 2; i > 1; i--)
        {
            if (a % i == 0)
            {
                d = i;
                break;
            }
        }
        a = d + a;
        count++;
    }
    if (a == b)
    {
        cout << count << endl;
        return 0;
        
    }
    else
    {
        cout << -1 << endl;
        return 0;
    }
}
// 64 位输出请用 printf("%lld")