//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int a = 0;
//	int b = 5;
//	swap(a, b);
//	vector<int> v, v1;
//	string s("ssss");
//	string s1("ssssss");
//	int c[] = { 1,2,3,5,6,4 };
//	reverse(c, c + 6);
//	reverse(s.begin(), s.end());
//	getline(cin, s);
//	s.swap(s1);
//	v.swap(v1);
//	return 0;
//}



#include <iostream>
#include <vector>

using namespace std;

int main() {
	int W, H, i, j, counts = 0;
	cin >> W >> H;
	if (W % 4 == 0 || H % 4 == 0) {
		counts = W * H / 2;
	}
	else if (W % 2 == 0 && H % 2 == 0) {
		counts = (W * H / 4 + 1) * 2;
	}
	else {
		counts = W * H / 2 + 1;
	}
	cout << counts << endl;
	return 0;
}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int StrToInt(string str) {
//		int s = 0;
//		if (str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
//		{
//			int flag = 1;
//			if (str[0] == '-')
//				flag = -1;
//			if (str[0] >= '0' && str[0] <= '9')
//				s = (str[0] - '0') * pow(10, str.size() - 1);
//			for (int i = 1; i <= str.size() - 1; i++)
//			{
//				if (str[i] >= '0' && str[i] <= '9')
//				{
//					s += (str[i] - '0') * pow(10, str.size() - 1 - i);
//				}
//				else
//					return 0;
//			}
//			return flag * s;
//		}
//		return 0;
//	}
//};
//
//int main()
//{
//	Solution s;
//	string str;
//	cin >> str;
//	int ret = s.StrToInt(str);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}