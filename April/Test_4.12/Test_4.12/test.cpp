#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int tribonacci(int n)
//    {
//        //状态表示
//        //状态转移方程
//        //初始化
//        //填表顺序
//        //返回值
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//        vector<int> dp(n + 1, 0);
//        dp[0] = 0;
//        dp[1] = dp[2] = 1;
//
//        for (size_t i = 3; i < n + 1; i++)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//        }
//        return dp[n];
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.tribonacci(0);
//}
//


//class Solution {
//public:
//    int waysToStep(int n)
//    {
//        if (n == 1)
//            return 1;
//        else if (n == 2)
//            return 2;
//        else if (n == 3)
//            return 4;
//        vector<long long> dp(n + 1, 0);
//        dp[1] = 1;
//        dp[2] = 2;
//        dp[3] = 4;
//        for (long long i = 4; i <= n; i++)
//        {
//            dp[i] = (((dp[i - 1] + dp[i - 2]) % 1000000007) + dp[i - 3]) % 1000000007;
//        }
//        return (dp[n] % 1000000007);
//    }
//};
//
//
//
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost)
//    {
//        vector<int> dp(cost.size()) + 1, 0);
//        dp[0] = 0;
//        dp[1] = 0;
//        for (int i = 2; i < dp.size(); i++)
//        {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//        return dp[cost.size()];
//    }
//};


#include <string>


//
//class Solution {
//public:
//    int numDecodings(string s) 
//    {
//        stoi(s);
//    }
//};




int main()
{
	int* p = new int(1);
	delete p;
	delete p;
	return 0;
}