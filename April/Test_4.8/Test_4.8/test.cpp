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
#include <unordered_map>

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



//class Solution {
//public:
//	int subarraysDivByK(vector<int>& nums, int k)
//	{
//		vector<int> dp(nums.size() + 1, 0);
//		for (size_t i = 1; i <= nums.size(); i++)
//		{
//			dp[i] = nums[i - 1] + dp[i - 1];
//		}
//		int ret = 0;
//		for (size_t i = 1; i < dp.size(); i++)
//		{
//			for (size_t j = 0; j < i; j++)
//			{
//				if ((dp[i] - dp[j]) % k == 0)
//					ret++;
//			}
//		}
//		return ret;
//	}
//};


//class Solution {
//public:
//    int tribonacci(int n)
//    {
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//        int a = 0, b = 1, c = 1;
//        int d = 0;
//        for (size_t i = 0; i < n - 2; i++)
//        {
//            d = a + b + c;
//            a = b;
//            b = c;
//            c = d;
//        }
//        return d;
//    }
//};
//
//
////int main()
////{
////    static int a;
////    a = 10;
////    return 0;
////}



//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k)
//    {
//        size_t sum = 0;
//        unordered_map<int, int> hash;
//        hash[0] = 1;
//        size_t ret = 0;
//        for (size_t i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//            ret += hash[sum - k];
//            hash[sum]++;
//        }
//        return ret;
//    }
//};



//class Solution {
//public:
//    int subarraysDivByK(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;
//        int sum = 0;
//        size_t ret = 0;
//        hash[0] = 1;
//        for (size_t i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i];
//            int n = (sum % k + k) % k;
//            if (hash.count(n))
//            {
//                ret += hash[n];
//            }
//            hash[n]++;
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> nums = { 2,-2,2,-4 };
//    cout << s.subarraysDivByK(nums, 6);
//    //cout << (-1 % 4) << endl;
//
//    return 0;
//}



//class Solution {
//public:
//    int findMaxLength(vector<int>& nums) 
//    {
//        unordered_map<int, int> hash;
//        hash[0] = -1;
//        int sum = 0;
//        int len = 0;
//        for (size_t i = 0; i < nums.size(); i++)
//        {
//            sum += nums[i] == 0 ? -1 : 1;
//            if (hash.count(sum))
//                len = max(len, (int)(i - hash[sum]));
//            else
//                hash[sum] = i;
//        }
//        return len;
//    }
//};




class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        vector<vector<int>> dp(mat.size() + 2 * k + 1, vector<int>(mat[0].size() + 2 * k + 1, 0));
        vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size(), 0));
        for (size_t i = k + 1; i < dp.size(); i++)
        {
            for (size_t j = k + 1; j < dp[0].size(); j++)
            {
                if (j < dp[0].size() - k && i < dp.size() - k)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - k - 1][j - k - 1];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

            }
        }
        for (size_t i = 0; i < ret.size(); i++)
        {
            for (size_t j = 0; j < ret[0].size(); j++)
            {
                ret[i][j] = dp[i + 2 * k + 1][j + 2 * k + 1] - dp[i][j + 2 * k + 1] - dp[i + 2 * k + 1][j] + dp[i][j];
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> mat = { {67, 64, 78},{99, 98, 38},{82, 46, 46},{6, 52, 55},{55, 99, 45} };
    s.matrixBlockSum(mat, 3);
}