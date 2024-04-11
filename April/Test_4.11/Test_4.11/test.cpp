#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    bool isUnique(string astr)
//    {
//        int ch = 0;
//        for (auto& c : astr)
//        {
//            if (ch & 1 << (c - 'a'))
//                return false;
//            ch |= 1 << (c - 'a');
//        }
//        return true;
//    }
//};



//class Solution {
//public:
//    int missingNumber(vector<int>& nums) 
//    {
//        int ret = 0;
//        for (size_t i = 0; i < nums.size(); i++)
//        {
//            ret ^= i;
//            ret ^= nums[i];
//        }
//        ret ^= nums.size();
//        return ret;
//    }
//};



//class Solution {
//public:
//    int getSum(int a, int b) 
//    {
//        if(a < b)
//            return (a ^ b) | (a << 1);
//        return (a ^ b) | (b << 1);
//    }
//};


//class Solution {
//public:
//    int singleNumber(vector<int>& nums) 
//    {
//        unordered_map<int, int> hash;
//        for (auto& i : nums)
//        {
//            hash[i]++;
//        }
//        for (auto& p : hash)
//        {
//            if (p.second == 1)
//                return p.first;
//        }
//        return 0;
//    }
//};
//
//int main()
//{
//    return 0;
//}



//class Solution {
//public:
//    int hammingWeight(int n)
//    {
//        int cnt = 0;
//        //获取最右端的1 n&(-n)
//        while (n & (-n))
//        {
//            cnt++;
//            //最右端1置为0
//            n &= (n - 1);
//        }
//        return cnt;
//    }
//};


//class Solution {
//public:
//    vector<int> countBits(int n)
//    {
//
//		vector<int> ret;
//		for (int i = 0; i <= n; i++)
//		{
//			int cnt = 0;
//			int j = i;
//			//获取最右端的1 n&(-n)
//			while (j & (-j))
//			{
//				cnt++;
//				//最右端1置为0
//				j &= (j - 1);
//			}
//			ret.push_back(cnt);
//		}
//
//		return ret;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	s.countBits(2);
//	return 0;
//}



//class Solution {
//public:
//    int hammingDistance(int x, int y)
//    {
//        int ret = 0;
//        while ((x & (-x)) && (y & (-y)))
//        {
//            if ((x & (-x)) < (y & (-y)))
//            {
//                ret++;
//                x&= (x - 1);
//            }
//            else if ((x & (-x)) > (y & (-y)))
//            {
//                ret++;
//                y&= (y - 1);
//            }
//            else
//            {
//                x&= (x - 1);
//                y&= (y - 1);
//            }
//        }
//        //x不为0
//        if ((x & (-x)))
//        {
//            while ((x & (-x)))
//            {
//                ret++;
//                x&= (x - 1);
//            }
//        }
//        else
//        {
//            while ((y & (-y)))
//            {
//                ret++;
//                y&= (y - 1);
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.hammingDistance(1, 3);
//    return 0;
//}



