//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <set>
//
//using namespace std;

//int main()
//{
//	int l, r;
//	cin >> l >> r;
//	size_t cnt = 0;
//	for (size_t i = l; i <= r; i++)
//	{
//		size_t tmp = i;
//		while (tmp > 1)
//		{
//			if (tmp % 10 == 2)
//				cnt++;
//			tmp /= 10;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}



//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param nums1 int整型vector
//     * @param nums2 int整型vector
//     * @return int整型vector
//     */
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_map<int, int> hash;
//        set<int> s;
//        for (size_t i = 0; i < nums1.size(); i++)
//        {
//            hash[nums1[i]]++;
//        }
//        for (size_t i = 0; i < nums2.size(); i++)
//        {
//            if (hash.count(nums2[i]))
//            {
//                s.insert(nums2[i]);
//            }
//        }
//        vector<int> ret(s.begin(), s.end());
//        return ret;
//    }
//};




//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool isHuiWen(string& s, int left, int right)
//{
//	int tmp = right;
//	while()
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	if (s.size() == 0)
//		cout << 0 << endl;
//	int left = 0;
//	int right = 0;
//	while (left < s.size())
//	{
//		while (right < s.size())
//		{
//
//		}
//	}
//	if (s.size() == 0)
//	{
//		cout << 0 << endl;
//	}
//	else
//		cout << s << endl;
//	return 0;
//}




#include <iostream>
using namespace std;

int main() 
{
	float a;
	char b;
	cin >> a >> b;
	int c = a;

	int cost = 0;
	cost += 20;
	if (a > 1)
	{
		cost += (int)(a / 1);
		if (c * 1000 == a * 1000)
		{
			cost--;
		}
	}

	if (b == 'y')
		cost += 5;
	cout << cost << endl;
	return 0;
}
// 64 位输出请用 printf("%lld")


//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() 
//{
//	int n;
//	cin >> n;
//	vector<int> dp(n + 1, 0),nums(n + 1,0);
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//	}
//	if (n == 1)
//		return nums[0];
//	if (n == 2)
//		return nums[0] > nums[1] ? nums[1] : nums[0];
//	dp[0] = nums[0];
//	dp[1] = nums[1];
//	for (size_t i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] > dp[i - 2] ? dp[i - 2] + nums[i] : dp[i - 1] + nums[i];
//	}
//	cout << dp[n];
//}
//// 64 位输出请用 printf("%lld")




//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main() 
//{
//    string str1, str2;
//    int n = 0;
//    cin >> n;
//    cin >> str1 >> str2;
//
//    vector<string> strs(n);
//    for (size_t i = 0; i < n; i++)
//    {
//        cin >> strs[i];
//    }
//    if (n <= 1)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    size_t len = INT_MAX;
//    int str1index = -1;
//    int str2index = -1;
//    for (size_t i = 0; i < n; i++)
//    {
//        if (strs[i] == str1)
//        {
//            str1index = i;
//            if (str2index != -1)
//            {
//                len = min(len, (size_t)abs(str1index - str2index));
//            }
//        }
//        if (strs[i] == str2)
//        {
//            str2index = i;
//            if (str1index != -1)
//            {
//                len = min(len, (size_t)abs(str1index - str2index));
//            }
//        }
//    }
//    if (str2index != -1 && str1index != -1)
//        cout << len << endl;
//    else
//        cout << -1 << endl;
//}
//// 64 位输出请用 printf("%lld")
