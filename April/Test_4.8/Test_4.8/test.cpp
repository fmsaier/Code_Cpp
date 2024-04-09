//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	long long n, q, l, r;
//	cin >> n >> q;
//	vector<long long> v;
//	v.resize(n);
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cin >> v[i];
//	}
//	vector<long long> dp;
//	dp.resize(v.size());
//	long long sum = 0;
//	for (size_t i = 0; i < dp.size(); i++)
//	{
//		sum += v[i];
//		dp[i] = sum;
//	}
//	while (q--)
//	{
//		cin >> l >> r;
//		if ((l - 2) < 0)
//			cout << (dp[r - 1]) << endl;
//		else
//			cout << (dp[r - 1] - dp[l - 2]) << endl;
//	}
//	return 0;
//}




//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() 
//{
//    size_t n, m, q;
//    cin >> n >> m >> q;
//    vector<vector<long long>> vv, dp;
//    vv.resize(n + 1);
//    dp.resize(n + 1);
//    vv[0].resize(m + 1, 0);
//    dp[0].resize(m + 1, 0);
//    for (size_t i = 1; i <= n; i++)
//    {
//        vv[i].resize(m + 1, 0);
//        for (size_t j = 1; j <= m; j++) 
//        {
//            cin >> vv[i][j];
//        }
//    }
//    for (size_t i = 1; i <= n; i++)
//    {
//        dp[i].resize(m + 1, 0);
//        for (size_t j = 1; j <= m; j++)
//        {
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + vv[i][j] - dp[i - 1][j - 1];
//        }
//    }
//    size_t x1, y1, x2, y2;
//    while (q--)
//    {
//        cin >> x1 >> y1 >> x2 >> y2;
//        long long ret = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
//        cout << ret << endl;
//    }
//    return 0;
//}


#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int pivotIndex(vector<int>& nums)
//    {
//        vector<int> dp(nums.size() + 1, 0);
//        for (size_t i = 1; i <= nums.size(); i++)
//        {
//            dp[i] = nums[i - 1] + dp[i - 1];
//        }
//        if (dp[nums.size()] - dp[1] == 0)
//            return 0;
//        for (size_t i = 2; i <= nums.size(); i++)
//        {
//            if (dp[nums.size()] - dp[i] == dp[i - 1])
//                return i - 1;
//        }
//        if (dp[nums.size() - 1] == 0)
//            return nums.size() - 1;
//        return -1;
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    vector<int> v = { 1,7,3,6,5,6 };
//    cout << s.pivotIndex(v);
//    return 0;
//}




//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums)
//    {
//        vector<int> ret(nums.size(), 1);
//        vector<int> dpFront(nums.size() + 1, 1);
//        vector<int> dpBack(nums.size() + 1, 1);
//        for (size_t i = 1; i <= nums.size(); i++)
//        {
//            dpFront[i] = nums[i - 1] * dpFront[i - 1];
//            dpBack[nums.size() - i] = nums[nums.size() - i] * dpBack[nums.size() - i + 1];
//        }
//        //for (size_t i = nums.size(); i > 0; i--)
//        //{
//        //    dpBack[i - 1] = nums[i - 1] * dpBack[i];
//        //}
//        for (size_t i = 0; i < nums.size(); i++)
//        {
//            ret[i] = dpFront[i] * dpBack[i + 1];
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> nums = { 1,2,3,4 };
//    vector<int> ret = s.productExceptSelf(nums);
//    for (int i : ret)
//    {
//        cout << i << " ";
//    }
//    return 0;
//}



//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k)
//    {
//        vector<int> dp(nums.size() + 1, 0);
//        for (size_t i = 1; i <= nums.size(); i++)
//        {
//            dp[i] = nums[i - 1] + dp[i - 1];
//        }
//        int ret = 0;
//        for (size_t i = 1; i < dp.size(); i++)
//        {
//            for (size_t j = 0; j < i; j++) 
//            {
//                if (dp[i] - dp[j] == k)
//                    ret++;
//            }
//        }
//        return ret;
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    vector<int> v = { 1 };
//     cout <<s.subarraySum(v, 0);
//    return 0;
//}



class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k)
	{
		vector<int> dp(nums.size() + 1, 0);
		for (size_t i = 1; i <= nums.size(); i++)
		{
			dp[i] = nums[i - 1] + dp[i - 1];
		}
		int ret = 0;
		for (size_t i = 1; i < dp.size(); i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if ((dp[i] - dp[j]) % k == 0)
					ret++;
			}
		}
		return ret;
	}
};