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




#include <iostream>
#include <string>

using namespace std;

bool isHuiWen(string& s, int left, int right)
{
	int tmp = right;
	while()
}

int main()
{
	string s;
	cin >> s;
	if (s.size() == 0)
		cout << 0 << endl;
	int left = 0;
	int right = 0;
	while (left < s.size())
	{
		while (right < s.size())
		{

		}
	}
	if (s.size() == 0)
	{
		cout << 0 << endl;
	}
	else
		cout << s << endl;
	return 0;
}
